#ifndef _CONDITIONALS_H_
#define  _CONDITIONALS_H_

#include <stack>

class ConditionalBlock
{
 public:
  ConditionalBlock(int parent_active);
  void toggle(int value);
  void pre_conditional_expr();
  void post_conditional_expr();
  void set_seen_else();
  int seen_else();
  int lex_active();
  int block_active();
  int resolved();
 private:
  int _active;
  int _active_for_conditional_expr;
  int _seen_else;
  int _resolved;
};

extern std::stack<ConditionalBlock *>  conditional_block_stack;

void conditional_if(int value);
void conditional_elseif(int value);
void conditional_else();
void conditional_endif();
void conditional_check_finished();

#endif
