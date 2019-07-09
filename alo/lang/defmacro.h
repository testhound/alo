#ifndef _DEFMACRO_H_
#define _DEFMACRO_H_

#include <string>
#include <list>

/* Interface */
void defmacro_begin();
void defmacro_add_param(const char *name);
void defmacro_add_body_text(const char *text);
void defmacro_identifier(const char *name);
int defmacro_check_name(const char *name);
int defmacro_in_use(const char *name);
void defmacro_complete();
void defmacro_report();

/* Macro definition object */
class MacroDefinition {
 public:
  std::string name;
  MacroDefinition();
  std::list<std::string> arguments;
  std::string body;
  int nargs;
  int must_be_empty;
  int in_use;
};


/* Patch entry object */
class PatchEntry
{
public:
  int first;
  int last;
  const char *patch_text;
  PatchEntry(int _first, int _last, const char *_text);
  bool operator<(const PatchEntry &rhs);
};


/* Macro invocation object */
class MacroInvocation {
 public:
  MacroInvocation(const char *def_name);
  ~MacroInvocation();
  std::string name;
  std::list<std::string> arguments;
  std::list<PatchEntry> patch_list;
  void setup_patch_list();
  void apply_patch_list();
  const char *get_patched_body();
  MacroDefinition *md;
 private:
  std::string patched_body;
};


/* More interface */
void macro_invocation_begin(const char *name);
void macro_invocation_complete();
MacroInvocation *macro_invocation_most_recent();
void macro_invocation_arg_append(const char *text);
void macro_invocation_arg_complete();


#endif
