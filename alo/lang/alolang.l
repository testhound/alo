%{
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "conditionals.h"
#include "defmacro.h"
#include <stack>
#include <string>
#include <list>

extern int errno;

#include <Alo.h>

#include "yystypes.h"

#undef yystype
#define yystype alolang_stype
#include "alolang.tab.h"
#undef YYSTYPE

#undef yystype
#define yystype defmacro_lang_stype
#include "defmacro_lang.tab.h"
#undef YYSTYPE

#include "aloutil.h"

using namespace Alo;


/* The following declaration MUST be synchronized with the .gperf
   file.  There's no nice way to include it in there, so we just
   duplicate it here. */
struct keyword { char *name; int   token; unsigned long ul_value; };

typedef struct keyword keyword_t;

extern struct keyword *in_word_set(register const char *str,  register unsigned int len);

extern int defmacro_parse();

LlirLineControlDirective::LineCntrlFlagType flag_to_flagtype(int flag);
void process_line_control_directive(char *text);
int directive_token(char *text);
int identifier_or_keyword_token(char *text);
int dotted_path_thing(char *text); 
int quoted_string_token(char *text);
int constant_token(char *number_text, int base);
int text_to_ul(char *number_text, int base, unsigned long *number_ptr);

void token_error();
extern void alo_error(const char *msg);

/* Support for conditional directives. */
static int filter(int value);

/* Support for defmacro. */
static int in_defmacro_body = 0;
void lex_enter_defmacro_body();

class input_stack_item
{
 public:
  YY_BUFFER_STATE buffer;
  MacroInvocation *mi;
  input_stack_item(YY_BUFFER_STATE b, MacroInvocation *m) { buffer = b; mi = m; }
  ~input_stack_item() { if (mi) { delete mi; } } /* MacroInvocation's are destroyed here. */
};

static stack<input_stack_item *> input_stack;

/* Keep track of tokens for error reporting. */
static void track_token(const char *token);
static list<string> buffered_tokens;


/*
 * Comments on the Rules Below:
 *
 * For the MACRO_LINE_DELIMITER rule, I am guessing that we need the
 * {whitespace}* at the end of it to eat up any preceding whitespace
 * for the next line of macro text.
 * For example:
 *
 * .macro \add r0 r1 r2 \	add r1 r2 r3 \ .endm
 *
 * The rule would match the first '\', '\	' (note the
 * whitespace), and '\ '. This is apparently to have lines line up
 * properly when we create listing files.
 */

%}

letter		[a-zA-Z_$]
digit		[0-9]
letter_or_digit [a-zA-Z_$0-9]
hexdigit	[a-fA-F0-9]
octdigit	[0-7]
hexprefix	0x|OX
decprefix	0d|0D
binprefix	0b|0B

comment		;[^\\\n]*
whitespace	[ \t]

%option yylineno
%option noyywrap

%x defmacro_body
%x defmacro_invocation

%%

^#{whitespace}*{digit}+{whitespace}*\"[^"\n]*\".*\n  process_line_control_directive(yytext);
  /* The above line messes up syntax highlighting in emacs, so here's a matching quote: " */
\\			return filter(MACRO_LINE_DELIMITER_TOKEN);


{decprefix}{digit}+	return filter(constant_token(yytext + 2, 10));
0{octdigit}+		return filter(constant_token(yytext + 1, 8));
{hexprefix}{hexdigit}+	return filter(constant_token(yytext + 2, 16));
{binprefix}[01]+	return filter(constant_token(yytext + 2, 2));
{digit}+		return filter(constant_token(yytext, 10));


\.{letter}+		return filter(directive_token(yytext));

{letter}{letter_or_digit}* return filter(identifier_or_keyword_token(yytext));

@{letter}{letter_or_digit}* return filter(identifier_or_keyword_token(yytext));

{letter}{letter_or_digit}*({whitespace}*\.{whitespace}*{letter}{letter_or_digit}*)* return filter(dotted_path_thing(yytext));

\"[^\n"]*\"		return filter(quoted_string_token(yytext));
  /* This is just to balance the above doublequote: " */

{comment}		{ /* FIXME: do anything here? */ }

^{whitespace}*\n	{ track_token("\n"); }

{whitespace}		{ track_token(" "); }


\n			return filter(NEWLINE_TOKEN);
!			return filter(NOT_TOKEN);
,			return filter(COMMA_TOKEN);

\&\&                    return filter(ANDAND_TOKEN);
\|\|                    return filter(OROR_TOKEN);
\>\=                    return filter(GEQ_TOKEN);
\<\=                    return filter(LEQ_TOKEN);
\=\=                    return filter(EQ_TOKEN);
\!\=                    return filter(NEQ_TOKEN);

\<\<                    return filter(LEFT_SHIFT_TOKEN);
\>\>                    return filter(RIGHT_SHIFT_TOKEN);

\=			return filter(yytext[0]);
\(			return filter(yytext[0]);
\)			return filter(yytext[0]);
\:			return filter(yytext[0]);
\+			return filter(yytext[0]);
\-			return filter(yytext[0]);
\~			return filter(yytext[0]);
\[			return filter(yytext[0]);
\]			return filter(yytext[0]);
\*			return filter(yytext[0]);
\/			return filter(yytext[0]);
\%			return filter(yytext[0]);
\|			return filter(yytext[0]);
\^			return filter(yytext[0]);
\&			return filter(yytext[0]);
\>			return filter(yytext[0]);
\<			return filter(yytext[0]);
\.			return filter(DOT_TOKEN);

<<EOF>>                 { 
                          /* The EOF rule matches for end-of-yyin, and ALSO for the end of
			   * macro expansion bodies passed to yy_scan_string(). */
                          /* fprintf(stderr, "LEX buffer emptied, popping stack\n"); */
                          yy_delete_buffer( YY_CURRENT_BUFFER ); 

			  /* We have to do this first check - the stack will only contain something if
			   * a macro was invoked. */
			  if (!input_stack.empty())
			      {
				input_stack_item *item = input_stack.top();
				input_stack.pop();
				delete item;
			      }
			  /* Now check again if the stack is empty. */
			  if (input_stack.empty())
			    {
			      yyterminate();
			    }
			  else
			    {
			      yy_switch_to_buffer(input_stack.top()->buffer);
			    }
                        }

.			{ alo_error("unknown token"); }

  /* This following of rules goes into effect when BEGIN(defmacro_body) has been called. */
<defmacro_body>".enddef"   { BEGIN(INITIAL); return filter(ENDDEF_TOKEN); }
<defmacro_body>{letter}({letter_or_digit}*{whitespace}*)*  { defmacro_add_body_text(yytext); return IGNORED_TOKEN; }
<defmacro_body>\n          { defmacro_add_body_text(yytext); return IGNORED_TOKEN; }
<defmacro_body>.           { defmacro_add_body_text(yytext); return IGNORED_TOKEN; }

 /* These rules are used while parsing macro invocation arguments. */
<defmacro_invocation>{whitespace}  { /* ignore plain whitespace */ }
<defmacro_invocation>[^\(\)\,\n]+  { defmacro_lval.text = strdup(yytext); return COMMALESS_GLOB; }
<defmacro_invocation>[\(\)\,]      { return yytext[0]; }
<defmacro_invocation>.             { return yytext[0]; }

%%

#if 0
[=():+-[\]*/%|^&]	return filter(yytext[0]);
#endif

int directive_token(char *text)
{
  keyword_t *keyword_ptr = in_word_set(text, strlen(text));

  if (keyword_ptr)
    {
      alo_lval.ul_value = keyword_ptr->ul_value;
      if ((keyword_ptr->token == IF_TOKEN) ||
	  (keyword_ptr->token == ELSEIF_TOKEN) ||
	  (keyword_ptr->token == ELSE_TOKEN) ||
	  (keyword_ptr->token == ENDIF_TOKEN))
	{
	  /* Handle conditional. */
	  if (!conditional_block_stack.empty())
	    {
	      /* Allow parsing conditional directives and expressions. */
	      conditional_block_stack.top()->pre_conditional_expr();
	    }
	}
      return keyword_ptr->token;
    }

  else
    {
      return INVALID_DIRECTIVE_TOKEN;
    }
}


int alo_yylex()
{
  return yylex();
}


void alolang_yyerror(const char *msg)
{
  alo_error(msg);
}

static void lex_handle_macro_invocation(char *name)
{
  int n_args = 0;
  int ch;
  MacroInvocation *mi;

  /* Push YY_CURRENT_BUFFER if needed. */
  if (input_stack.empty())
    {
      input_stack.push(new input_stack_item(YY_CURRENT_BUFFER, NULL));
    }

  /* Parse arglist between ()'s. */
  macro_invocation_begin(name);
  BEGIN(defmacro_invocation);
  if (defmacro_parse() == 0)
    {
      /* Create and push a new (expanded) buffer. */
      mi = macro_invocation_most_recent();
      input_stack.push(new input_stack_item(yy_scan_string(mi->get_patched_body()), mi));
    }


  /* Continue lexing with default rule set. */
  BEGIN(INITIAL);
}


int identifier_or_keyword_token(char *text)
{
  keyword_t *keyword_ptr;
  int macro_in_use;

  if (defmacro_check_name(text))
    {
      if (defmacro_in_use(text))
	{
	  char msg[128];
	  sprintf(msg, "recursive use of macro '%s',", text);
	  alo_error(msg);
	}
      else
	{
	  lex_handle_macro_invocation(text);

	  /* Recursively(!) call yylex with the newly set up input buffer.
	   * This is Ok, because we *don't* want to return the macro 
	   * identifier name that got us here (the parser should only see
	   * the expanded text). */
	  return yylex();
	}
    }

  keyword_ptr = in_word_set(text, strlen(text));
  if (keyword_ptr)
    {
      alo_lval.ul_value = keyword_ptr->ul_value;
      return keyword_ptr->token;
    }
  else
    {  
      /* This must be an identifier. */
      /*  puts(text); */
      alo_lval.text = strdup(text);
      return IDENTIFIER_TOKEN;
    }
}


int dotted_path_thing(char *text)
{
  strip_string(text);
  alo_lval.text = strdup(text);
  return STRUCTURE_REFERENCE_TOKEN;
}


int constant_token(char *number_text, int base)
{
  /* Set the token value. */

  if (text_to_ul(number_text, base, &alo_lval.ul_value) == -1)
    {
      alo_error("Unable to convert number"); /* XXX -- error messages suck */
      return 0;
    }

  return CONSTANT_TOKEN;
}



int quoted_string_token(char *text)
{
  alo_lval.text = strdup(yytext);
  return QUOTED_STRING_TOKEN;
}

/* Convert integer value to LineCntrlFlagType */
LlirLineControlDirective::LineCntrlFlagType flag_to_flagtype(int flag)
{
  switch (flag)
    {
    case 0: return LlirLineControlDirective::LCD_NONE;
    case 1: return LlirLineControlDirective::LCD_NEWFILE;
    case 2: return LlirLineControlDirective::LCD_RETURN;
    case 3: return LlirLineControlDirective::LCD_SYSHDR;
    case 4: return LlirLineControlDirective::LCD_CTEXT;
    default: assert(0);
    }
}

void process_line_control_directive(char *text)
{
  char pound_sign;
  char filename[PATH_MAX];
  unsigned int flag = 0;
  int unhandled_flag;
  int n;
  unsigned int lineno;
  shared_ptr<LlirLineControlDirective> lcd;

  n = sscanf(text, "%c %u %s %u %d", &pound_sign, &lineno, filename, &flag, &unhandled_flag);
  if (n == 5)
    {
      /* The CPP docs claim that "after the file name comes zero or more flags".  We
      	 are not likely to see this, but we should assert that we cannot handle it. */
      fprintf(stderr, "internal error: can not handle multiple line number flags\n");
    }

  /*
    remove leading and trailing '"' from the file name
   */

  char *trim_filename = strdup(filename+1);
  trim_filename[strlen(trim_filename)-1] = '\0';

  handle_line_control_directive(lineno, trim_filename, flag);

  lcd = llirFactory->createLineCtrlDirective(get_node_line()-1,
					     lineno,
					     (const char*)trim_filename,
					     flag_to_flagtype(flag));

  g_currentBlock->addLlirNode(g_currentBlock, lcd);

  free(trim_filename);
}


int text_to_ul(char *number_text, int base, unsigned long *number_ptr)
{
  unsigned long value; /* numerical value represented by text */

  /* points to first character that is not a valid digit */

  char *end_ptr;       

	
  /* Convert the number text to a numerical value. */

  errno = 0;
  value = strtoul(number_text, &end_ptr, base);
  if (errno != 0) /* errno is set to nonzero if result overflows */
    return -1;

  /*
   * Ensure that the null terminator at the end of the number text is
   * the first invalid character.
   */
  if (end_ptr == number_text || *end_ptr != '\0')
    return -1;

  
  /* Save the number. */

  *number_ptr = value;
  return 0;
}

static int filter(int value)
{
  track_token(yytext);
  /* If conditional block state is inactive, return IGNORED_TOKEN, 
   * else return value. */
  if (!conditional_block_stack.empty()
      && !conditional_block_stack.top()->lex_active())
    {
      return IGNORED_TOKEN;
    }
  return value;
}

void lex_enter_defmacro_body()
{
  BEGIN(defmacro_body);
}


void token_error()
{
  printf("Unknown token\n");
}


#if 0

FIXME: IS THIS NEEDED???  KEEP IF MXTAS CODE USES  0D OR 0d numbers!

unsigned long convert(char *string, int base)
{

  char *error_ptr;
  unsigned long val;

  errno = 0;
  if (base == 2) /* binary digits */
    { 
      string += 2;   /* skip leading 0b */
      if (strlen(string) > sizeof(unsigned long) * 8)
        {
          alo_error("could not convert number"); /* overflow */
          return 0;
        }

      val = 0;
      while (*string != (char) NULL)
        {
          val  = val << 1;
          val |= *string - '0';
          string++;
        }

      return val;
    }

  if (strlen(string) > 2)
    {
      if ((strncmp("0D", string, 2) == 0) ||
          (strncmp("0d", string, 2) == 0))
        {
          string += 2; /* skip over 0d because strtoul cant deal with it */
        }
    }


  val = strtoul(string, &error_ptr, base);
  if (errno != 0) /* would happen if result overflows */
    {
      alo_error("could not convert number"); 
      return(0);
    }

  if (error_ptr != &yytext[yyleng])
    {
      alo_error("could not convert number"); 
      return(0);  /* would happen if a digit is bigger than radix allows */
    }

  return(val);
}
#endif


/* In order to better report syntax errors, it would be useful to show
 * the programmer the tokens leading up to where the error
 * occurred. 
 * 
 * In this function, we buffer tokens and whitespace.  One complete
 * line is buffered.
 */
static void track_token(const char *token)
{
  static int line_count = 0;
  
  if ((strcmp(token, "\n") == 0)
      || (strcmp(token, "\\") == 0))
    {
      line_count++;
      if (line_count == 2)
	{
	  list<string>::iterator it;
	  list<string>::iterator save_it;
	  it = buffered_tokens.begin();
	  while ((*it != "\n") && (*it != "\\"))
	    {
	      save_it = it;
	      it++;
	      buffered_tokens.erase(save_it);
	    } 
	  buffered_tokens.erase(it);
	  line_count--;
	}
    }

  buffered_tokens.push_back(token);
}

/* This can be called when errors are encountered, to provide some 
   information to the user about where his error occurred. */
string buffered_tokens_to_string()
{
  string s("");
  list<string>::iterator it = buffered_tokens.begin();
  list<string>::iterator save_it;
  int column = 0;
  const char *cstr = NULL;

  while (1)
    {
      save_it = it;
      it++;
      if (it == buffered_tokens.end())
	{
	  s.append((*save_it).c_str());
	  s.append("\n");
	  for (int i=0; i < column; i++)
	    {
	      s.append(" ");
	    }
	  s.append("^");
	  break;
	}
      else
	{
	  cstr = (*save_it).c_str();
	  s.append(cstr);
	  column += strlen(cstr);
	  if (!strcmp(cstr, "\n"))
	    {
	      column = 0;
	    }
	  /* When we see a backslash, we want to replicate the original macro 
	     body text as closely as possible, so we make it a double-backslash
	     and wrap the line. */
	  if (!strcmp(cstr, "\\"))
	    {
	      s.append("\\\n");
	      column = 0;
	    }
	}
    }

  return s;
}


/*
 * Local variables: 
 *  mode: c 
 * End:
 */

