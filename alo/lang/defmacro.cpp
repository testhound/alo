/* Macro definition and expansion. */
#include "defmacro.h"
#include "aloutil.h"
#include <stdarg.h>		/* vfprintf() */
#include <map>
#include <cctype>
#include <cstring>

using namespace std;
using namespace Alo;

extern int alo_debug;

/* From http://www.sgi.com/tech/stl/Map.html */
struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

static map<const char *, MacroDefinition *, ltstr> macro_collection;
typedef map<const char *, MacroDefinition *, ltstr>::iterator macro_collection_iterator;

MacroDefinition *macro_under_construction = NULL;


/* Debug printf, only prints (to stderr) if alo_debug is set. */
static void d_printf(const char *fmt, ...)
{
  va_list ap;
  if (alo_debug)
    {
      fprintf(stderr, "defmacro: ");
      va_start(ap, fmt);
      vfprintf(stderr, fmt, ap);
      va_end(ap);  
    }
}

void defmacro_begin()
{
  assert(macro_under_construction == NULL);
  macro_under_construction = new MacroDefinition();
}


void defmacro_add_param(const char *name)
{
  list<string>::iterator iter;
  for (iter = macro_under_construction->arguments.begin();
       iter != macro_under_construction->arguments.end();
       iter++)
    {
      if (!strcmp(name, iter->c_str()))
	{
	  char msg[128];
	  sprintf(msg, "duplicate parameter name: %s", name);
	  parseAlo->logException(shared_ptr<ParseError>(new ParseError(msg,
								       get_src_line(), 
								       get_src_file(), 
								       __LINE__, __FILE__)));
	}
    }
  macro_under_construction->arguments.push_back(string(name));
}


void defmacro_add_body_text(const char *text)
{
  macro_under_construction->body.append(text);
}


void defmacro_identifier(const char *name)
{
  macro_under_construction->name = string(name);
}


void defmacro_complete()
{
  macro_under_construction->nargs = macro_under_construction->arguments.size();
  if (macro_under_construction->nargs == 0)
    {
      macro_under_construction->nargs = 1;
      macro_under_construction->must_be_empty = 1;
    }
  macro_collection[macro_under_construction->name.c_str()] = macro_under_construction;
  macro_under_construction = NULL;
}


int defmacro_check_name(const char *name)
{
  macro_collection_iterator iter;
  
  iter = macro_collection.find(name);
  if (iter != macro_collection.end())
    {
      return 1;
    }
  return  0;
}


int defmacro_in_use(const char *name)
{
  macro_collection_iterator iter;
  
  iter = macro_collection.find(name);
  return (*iter).second->in_use;
}


void defmacro_report()
{
  int i = 1;
  map<const char *, MacroDefinition *, ltstr>::iterator mapiter;
  printf("Defined macros:\n");
  for (mapiter = macro_collection.begin();
       mapiter != macro_collection.end();
       mapiter++)
    {
      printf("%d: %s(", i++,(*mapiter).second->name.c_str());
      list<string>::iterator iter;
      int seen_arg = 0;
      for (iter = (*mapiter).second->arguments.begin();
	   iter != (*mapiter).second->arguments.end();
	   iter++)
	{
	  if (seen_arg)
	    {
	      printf(", ");
	    }
	  else
	    {
	      seen_arg = 1;
	    }
	  printf("%s", iter->c_str());
	}
      printf(")\n");
      printf("%s\n", (*mapiter).second->body.c_str());
    }
}


/* MacroDefinition class members */
MacroDefinition::MacroDefinition()
{
  nargs = 0;
  must_be_empty = 0;
  in_use = 0;
}


/* Invocation handling... */
static MacroInvocation *current_invocation = NULL;
static MacroInvocation *most_recent_invocation = NULL;
static string current_invocation_arg = "";

void macro_invocation_begin(const char *name)
{
  assert(current_invocation == NULL);
  current_invocation = new MacroInvocation(name);
}

void macro_invocation_complete()
{
  int nargs;
  MacroInvocation *mi = current_invocation;

  current_invocation = NULL;
  most_recent_invocation = mi;

  /* First, check that the number of arguments is correct. */
  nargs = mi->arguments.size();
  if (nargs != mi->md->nargs)
    {
      char msg[128];
      sprintf(msg,  "wrong number of arguments to macro (got %d wanted %d)\n",
	      nargs, mi->md->nargs);
      parseAlo->logException(shared_ptr<ParseError>(new ParseError(msg,
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
      return;
    }

  /* Check special case of macro with empty arglist */
  if (mi->md->nargs == 1 && mi->md->must_be_empty)
    {
      /* Macro invocation should be empty or contain only whitespace. */
      const char *p;
      p = mi->arguments.front().c_str();
      while (*p)
	{
	  if (!isspace(*p))
	    {
	      char msg[128];
	      sprintf(msg,  "macro %s does not accept arguments\n", mi->name.c_str());
	      parseAlo->logException(shared_ptr<ParseError>(new ParseError(msg,
									   get_src_line(), 
									   get_src_file(), 
									   __LINE__, __FILE__)));
	      return;
	    }
	}
    }

  /* Expand macro body and leave string for lexer to pick up. 
   * For each macro argument, replace every instance of,
   *   <non-alphabetic-char>PARAM<non-alphanumeric-char>
   * in the macro body with the replacement ARG text. 
   * 
   * To avoid unexpected results, this must be done atomically, 
   * that is, all replacements should be done without affecting
   * other replacements.  This implies a two-step algorithm,
   *
   *   for each macro parameter:
   *     locate and store the bounds of every instance of,
   *       "<non-alphabetic-char>PARAM<non-alphanumeric-char>"
   *   for each macro argument:
   *     replace every instance of the associated parameter
   *     in the body with the argument text
   *
   * Implementation - store the bounds of the PARAMs, sort
   * them, then use them to guide through a replacement pass.
   *
   * At some point, must also replace "##" with "" while absorbing
   * adjacent whitespace.  Should be fairly easy to do this by 
   * walking the string list, or checking as each string is added.
   * Keep in mind that a chunk may contain multiple ##'s.
   */

  mi->setup_patch_list();
  mi->apply_patch_list();

#if 0
  printf("macro invocation complete:\n");
  printf("%s(", mi->name.c_str());
  list<string>::iterator iter;
  int seen_arg = 0;
  for (iter = mi->arguments.begin();
       iter != mi->arguments.end();
       iter++)
    {
      if (seen_arg)
	{
	  printf(",  ");
	}
      else
	{
	  seen_arg = 1;
	}
      printf("%s", iter->c_str());
    }
  printf(")\n");
#endif
  
}

MacroInvocation *macro_invocation_most_recent()
{
  return most_recent_invocation;
}

void macro_invocation_arg_append(const char *text)
{
  current_invocation_arg.append(text);
}

void macro_invocation_arg_complete()
{
  /* Strip any leading and trailing whitespace, then add the argument to the
   * current invocation. */
  string::size_type front, back;

  front = current_invocation_arg.find_first_not_of(" \t");
  d_printf("arg complete: %s\n", current_invocation_arg.c_str());

  if (front == string::npos)
    {
      current_invocation_arg = "";
    }
  else
    {
      back = current_invocation_arg.find_last_not_of(" \t");
      current_invocation_arg = current_invocation_arg.substr(front, (back - front + 1));
      d_printf("arg reworked: %s\n", current_invocation_arg.c_str());      
    }

  current_invocation->arguments.push_back(current_invocation_arg);  
  current_invocation_arg = "";
}



PatchEntry::PatchEntry(int _first, int _last, const char *_text)
{
  first = _first;
  last = _last;
  patch_text = _text;
}

/* This operator must be defined in order for patch_list.sort() to work below. */
bool PatchEntry::operator<(const PatchEntry &rhs)
{
  if (this->first < rhs.first)
    return true;
  else
    return false;
}

inline int is_letter(char ch)
{
  if (isalpha(ch) || ch == '$' || ch == '_')
      return 1;
  else
      return 0;
}

inline int is_letter_or_digit(char ch)
{
  if (isalnum(ch) || ch == '$' || ch == '_')
      return 1;
  else
      return 0;
}

inline int is_tab_or_space(char ch)
{
  if (ch == ' ' || ch == '\t')
      return 1;
  else
      return 0;
}


MacroInvocation::MacroInvocation(const char *def_name)
{
  name = def_name;
  md = macro_collection[def_name];
  md->in_use = 1;
}


MacroInvocation::~MacroInvocation()
{
  md->in_use = 0;
}

void MacroInvocation::setup_patch_list()
{
  list<string>::iterator arg_iter;
  list<string>::iterator value_iter;
  const char *body;
  const char *arg;
  const char *value;
  const char *p;
  int arg_len;

  for (arg_iter = md->arguments.begin(), value_iter = this->arguments.begin();
       arg_iter != md->arguments.end();
       arg_iter++, value_iter++)
    {
      body = md->body.c_str();
      arg = arg_iter->c_str();
      value = value_iter->c_str();
      arg_len = strlen(arg);

      p = body;
      while (1)
	{
	  p = strstr(p, arg);
	  if (!p)
	    {
	      break;
	    }
	  else
	    {
	      if (p == body || (p != body && !is_letter(p[-1])))
		{
		  if (!is_letter_or_digit(p[arg_len]))
		    {
		      this->patch_list.push_back(PatchEntry(p - body, p - body + arg_len, value));
		      d_printf("replacing '%s' with '%s' at offset %d\n",
			     arg, value, p - body);
		    }
		}
	    }
	  p += arg_len;
	}
    }

  /* Add whitespace absorber "##" to the patch list.  This is similar
   * to the above loop, but with enough special-case difference to
   * warrant a separate pass. */
  body = md->body.c_str();
  arg = "##";
  value = "";
  arg_len = strlen(arg);

  p = body;
  while (1)
    {
      p = strstr(p, arg);
      if (!p)
	{
	  break;
	}
      else
	{
	  const char *a;
	  const char *b;

	  a = p-1; 
	  while (a > body && is_tab_or_space(*a))
	    {
	      a--;
	    }
	  a++;

	  b = p + arg_len;
	  while (b > body && is_tab_or_space(*b)) // FIXME: Will this catch the '\0' at end of body?
	    {
	      b++;
	    }

	  this->patch_list.push_back(PatchEntry(a - body, b - body, value));
	  d_printf("replacing '%s' with '%s' at offset %d\n", arg, value, a - body);
	}
      p += arg_len;
    }


  /* Ok, one more time.  Replace newlines with backslashes, which I think
   * we need to keep line numbering straight.  */
  body = md->body.c_str();
  arg = "\n";
  value = "\\";
  arg_len = strlen(arg);

  p = body;
  while (1)
    {
      p = strstr(p, arg);
      if (!p)
	{
	  break;
	}
      else
	{
	  this->patch_list.push_back(PatchEntry(p - body, p - body + arg_len, value));
	  d_printf("replacing newline with backslash at offset %d\n", p - body);
	}
      p += arg_len;
    }

  /* Finally, sort the patch list. */
  this->patch_list.sort();
}


void MacroInvocation::apply_patch_list()
{
  list<PatchEntry>::iterator pl_iter;
  int index = 0;

  this->patched_body = ".macro";

  for (pl_iter = this->patch_list.begin();
       pl_iter !=  this->patch_list.end();
       pl_iter++)
    {
      /* Copy substring from index up to this patch entry. */
      this->patched_body.append(md->body.c_str()+index, pl_iter->first - index);
      /* Copy this patch entry. */
      this->patched_body.append(pl_iter->patch_text);
      index = pl_iter->last;
    }

  /* Copy remaining text after last patch. */
  this->patched_body.append(md->body.c_str() + index);

  this->patched_body.append(".endm");
}

const char *MacroInvocation::get_patched_body()
{
  return this->patched_body.c_str();
}
