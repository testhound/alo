/*
 * Tiny parser for macro invocations.  It is harder than one might expect
 * to parse this stuff by hand.
 */

%{
#include <string>
#include <stdlib.h>
#include "defmacro.h"

using namespace std;

void defmacro_error(const char *msg);
int defmacro_lex();
extern int alo_yylex();
extern int alo_error(const char *msg);

%}

%token <text> COMMALESS_GLOB

%type <text> arg_glob
%type <text> comma_allowed_glob

%union
{
  const char *text;
}


%%

/* Parenthesized Macro invocation argument grammar.  Commas separate
 * arguments at the top level, but commas inside parenthesized
 * arguments do not indicate separate arguments.  YYACCEPT at the top
 * level causes the parse to stop and return without consuming any
 * more tokens. */
defmacro_invocation: '(' invocation_args ')' {  macro_invocation_complete(); YYACCEPT; }
                   ;

invocation_args: arg_glob { macro_invocation_arg_append($1); macro_invocation_arg_complete(); }
               | invocation_args ',' arg_glob {  macro_invocation_arg_append($3); macro_invocation_arg_complete(); }
               ;

arg_glob: /* empty */  { $$ = ""; }
        | COMMALESS_GLOB { $$ = $1;  }
        | arg_glob '(' comma_allowed_glob ')' arg_glob
           { 
	     string s = $1;
	     s.append("(");
	     s.append($3);
	     s.append(")");
	     $$ = strdup(s.c_str());
            }
        ;

comma_allowed_glob: /* empty */ { $$ = ""; }
        | COMMALESS_GLOB { $$ = $1; }
        | comma_allowed_glob ',' comma_allowed_glob
           {
	     string s = $1;
	     s.append(",");
	     s.append($3);
	     $$ = strdup(s.c_str());
           }
        | comma_allowed_glob '(' comma_allowed_glob ')' comma_allowed_glob
           { 
	     string s = $1;
	     s.append("(");
	     s.append($3);
	     s.append(")");
	     s.append($5);
	     $$ = strdup(s.c_str());
           }
       ;

%%

/* Macro invocations parse from the same input stream as the regular
 * ALO parse, whether it be the original input file or an expanded
 * invocation buffer from an enclosing macro invocation.  Calling
 * the ALO lexer makes this "just work". */
int defmacro_lex()
{
  return alo_yylex();
}


void defmacro_error(const char *msg)
{
  char text[128];
  sprintf(text, "%s looking at macro arguments", msg);
  /* Use existing ALO function to report parse errors. */
  alo_error(text);
}
