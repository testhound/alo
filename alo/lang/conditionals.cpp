/* Code to keep track of conditional blocks. */
#include "conditionals.h"
#include "aloutil.h"

using namespace Alo;

/* ConditionalBlock class methods. */
ConditionalBlock::ConditionalBlock(int parent_active)
{
  _active = 0;
  _seen_else = 0;
  _active_for_conditional_expr = 0;
  _resolved = 0;

  /*
   * If the parent block is inactive, this one should never become active.
   */
  if (!parent_active)
    {
      _resolved = 1;
    }
}


/* This is global. */
std::stack<ConditionalBlock *>  conditional_block_stack;

void ConditionalBlock::toggle(int value)
{
  /* Assume the block will be inactive. */
  _active = 0;

  /* Only make the block active under the right conditions. */
  if (!_resolved && value)
    {
      _active = 1;
      _resolved = 1;
    }
}

void ConditionalBlock::pre_conditional_expr()
{
  /* 
   * Change state to active, this is required when a conditional directive token
   * is encountered so that the directive itself isn't ignored (don't want to lose
   * ".else" for example).  Should only be called by the lexer.
   */
  _active_for_conditional_expr = 1;
}

void ConditionalBlock::post_conditional_expr()
{
  _active_for_conditional_expr = 0;
}

void ConditionalBlock::set_seen_else()
{
  _seen_else = 1;
}

int ConditionalBlock::seen_else()
{
  return _seen_else;
}

int ConditionalBlock::lex_active()
{
  return (_active || _active_for_conditional_expr);
}

int ConditionalBlock::block_active()
{
  return (_active);
}

int ConditionalBlock::resolved()
{
  return _resolved;
}


/* Interface functions. */
void conditional_if(int value)
{
  int parent_active;
  ConditionalBlock *cb;

  if (conditional_block_stack.empty())
    {
      parent_active = 1;
    }
  else
    {
      parent_active = conditional_block_stack.top()->block_active();
    }

  cb = new ConditionalBlock(parent_active);
  conditional_block_stack.push(cb);
  conditional_block_stack.top()->toggle(value);
  conditional_block_stack.top()->post_conditional_expr();
}

void conditional_elseif(int value)
{
  if (conditional_block_stack.empty())
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError("stray .elseif",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
      return;
    }
  if (conditional_block_stack.top()->seen_else())
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError(".elseif cannot follow .else",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
    }
  conditional_block_stack.top()->toggle(value);
  conditional_block_stack.top()->post_conditional_expr();
}


void conditional_else()
{
  if (conditional_block_stack.empty())
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError("stray .else",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
      return;
    }
  if (conditional_block_stack.top()->seen_else())
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError("cannot have multiple .else clauses",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
    }
  conditional_block_stack.top()->toggle(1);
  conditional_block_stack.top()->set_seen_else();
  conditional_block_stack.top()->post_conditional_expr();
}

void conditional_endif()
{
  if (conditional_block_stack.empty())
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError("stray .endif",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
      return;
    }
  delete conditional_block_stack.top();
  conditional_block_stack.pop();
  if (!conditional_block_stack.empty())
    {
      conditional_block_stack.top()->post_conditional_expr();
    }
}

void conditional_check_finished()
{
  if (!conditional_block_stack.empty())
    {
      char msg[128];
      sprintf(msg, "%d unterminated .if(s) at end of file", conditional_block_stack.size());
      parseAlo->logException(shared_ptr<ParseError>(new ParseError(msg,
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
    }
}

