#ifndef _BRANCH_VISITOR_H_
#define  _BRANCH_VISITOR_H_

#include <Visitor.h>
#include <LlirVisitor.h>
#include <OctaveNode.h>


using namespace Llir;

namespace Alo
{
  class BranchIsCallVisitor :
    public Visitor,
    public LlirVisitor
    {
    public:
	BranchIsCallVisitor(shared_ptr<AltEntryFunction> fn)  
	  : Visitor(), 
	  LlirVisitor(),
	  m_currentFn(fn)
	{}

	~BranchIsCallVisitor()
	  {}

      virtual void visit(const LlirFile& v);
      virtual void visit(const LlirSequence &);
      virtual void visit(const NullNode& v);
      virtual void visit(const NewLineNode& v);
      virtual void visit(const LlirLineControlDirective& v);
      virtual void visit(const SignedImmediate& v);
      virtual void visit(const UnsignedImmediate& v);
      virtual void visit(const OpndLabel& v);
      virtual void visit(const OpndNull& v);

      virtual void visit(const PlusOp& v);
      virtual void visit(const MinusOp& v);
      virtual void visit(const MultiplyOp& v);
      virtual void visit(const DivOp& v);
      virtual void visit(const ModulusOp& v);
      virtual void visit(const LeftShiftOp& v);
      virtual void visit(const RightShiftOp& v);
      virtual void visit(const BitWiseAndOp& v);
      virtual void visit(const BitWiseOrOp& v);
      virtual void visit(const BitWiseXorOp& v);

      virtual void visit(const ParenthesesOp& v);
      virtual void visit(const UnaryMinusOp& v);

      virtual void visit(const NullRegister& v);
      virtual void visit(const HardRegister& v);
      virtual void visit(const PseudoRegister& v);
      virtual void visit(const MultiHardRegister& v);
      virtual void visit(const MultiPseudoRegister& v);
     
    protected:
      void storeLabelOpnd(const char* name);

    private:
      shared_ptr<AltEntryFunction> m_currentFn;

    };



  class BranchIsJumpVisitor :
    public Visitor,
    public LlirVisitor
    {
    public:
	BranchIsJumpVisitor(shared_ptr<AltEntryFunction> fn)  
	  : Visitor(), 
	  LlirVisitor(),
	  m_currentFn(fn)
	{}

	~BranchIsJumpVisitor()
	  {}

      virtual void visit(const LlirFile& v);
      virtual void visit(const LlirSequence &);
      virtual void visit(const NullNode& v);
      virtual void visit(const NewLineNode& v);
      virtual void visit(const LlirLineControlDirective& v);
      virtual void visit(const SignedImmediate& v);
      virtual void visit(const UnsignedImmediate& v);
      virtual void visit(const OpndLabel& v);
      virtual void visit(const OpndNull& v);

      virtual void visit(const PlusOp& v);
      virtual void visit(const MinusOp& v);
      virtual void visit(const MultiplyOp& v);
      virtual void visit(const DivOp& v);
      virtual void visit(const ModulusOp& v);
      virtual void visit(const LeftShiftOp& v);
      virtual void visit(const RightShiftOp& v);
      virtual void visit(const BitWiseAndOp& v);
      virtual void visit(const BitWiseOrOp& v);
      virtual void visit(const BitWiseXorOp& v);

      virtual void visit(const ParenthesesOp& v);
      virtual void visit(const UnaryMinusOp& v);

      virtual void visit(const NullRegister& v);
      virtual void visit(const HardRegister& v);
      virtual void visit(const PseudoRegister& v);
      virtual void visit(const MultiHardRegister& v);
      virtual void visit(const MultiPseudoRegister& v);
     
    protected:
      void storeLabelOpnd(const char* name);

    private:
      shared_ptr<AltEntryFunction> m_currentFn;
    };


}

#endif
