#include "BranchVisitor.h"
#include <LlirOperand.h>
#include <AloException.h>

namespace Alo
{
  //
  // set state in OpndLabel if it was
  // used in a call insn indicating that 
  // it was used as a call target.
  //

  void
  BranchIsCallVisitor::storeLabelOpnd(const char* name)
  {
    m_currentFn->storeBranchTarget(name);
  }

  void
  BranchIsCallVisitor::visit(const LlirFile& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void 
  BranchIsCallVisitor::visit(const LlirSequence &)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const NullNode& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const NewLineNode& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const LlirLineControlDirective& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const SignedImmediate& v)
  {}

  void BranchIsCallVisitor::visit(const UnsignedImmediate& v)
  {}

  void BranchIsCallVisitor::visit(const OpndLabel& v)
  {
    //store all the label operands seen in an event handler/function
    //for future reference.
    storeLabelOpnd(v.getMangledName().c_str());

    v.setCallTarget();
  }
   
  void BranchIsCallVisitor::visit(const OpndNull& v)
  {}

  void BranchIsCallVisitor::visit(const PlusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
  }

  void BranchIsCallVisitor::visit(const MinusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
  }

  void BranchIsCallVisitor::visit(const MultiplyOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const DivOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const ModulusOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const LeftShiftOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const RightShiftOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const BitWiseAndOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const BitWiseOrOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const BitWiseXorOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }


  void BranchIsCallVisitor::visit(const ParenthesesOp& v)
  {
    v.getOpnd()->accept(*this);
  }

  void BranchIsCallVisitor::visit(const UnaryMinusOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const NullRegister& v)
  {
  }

  void BranchIsCallVisitor::visit(const HardRegister& v)
  {}

  void BranchIsCallVisitor::visit(const PseudoRegister& v)
  {}

  void BranchIsCallVisitor::visit(const MultiHardRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsCallVisitor::visit(const MultiPseudoRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }
     
  //
  // set state in OpndLabel if it was
  // used in a branch insn indicating that 
  // it was used as a jump target.
  //

  void
  BranchIsJumpVisitor::storeLabelOpnd(const char* name)
  {
    m_currentFn->storeBranchTarget(name);
  }


  void
  BranchIsJumpVisitor::visit(const LlirFile& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void 
  BranchIsJumpVisitor::visit(const LlirSequence &)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const NullNode& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const NewLineNode& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const LlirLineControlDirective& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const SignedImmediate& v)
  {}

  void BranchIsJumpVisitor::visit(const UnsignedImmediate& v)
  {}

  void BranchIsJumpVisitor::visit(const OpndLabel& v)
  {
    //store all the label operands seen in an event handler/function
    //for future reference.
    storeLabelOpnd(v.getMangledName().c_str());

    v.setBranchTarget();
  }
   
  void BranchIsJumpVisitor::visit(const OpndNull& v)
  {}

  void BranchIsJumpVisitor::visit(const PlusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
  }

  void BranchIsJumpVisitor::visit(const MinusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
  }

  void BranchIsJumpVisitor::visit(const MultiplyOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const DivOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const ModulusOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const LeftShiftOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const RightShiftOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const BitWiseAndOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const BitWiseOrOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const BitWiseXorOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }


  void BranchIsJumpVisitor::visit(const ParenthesesOp& v)
  {
    v.getOpnd()->accept(*this);
  }

  void BranchIsJumpVisitor::visit(const UnaryMinusOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const NullRegister& v)
  {
  }

  void BranchIsJumpVisitor::visit(const HardRegister& v)
  {}

  void BranchIsJumpVisitor::visit(const PseudoRegister& v)
  {}

  void BranchIsJumpVisitor::visit(const MultiHardRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void BranchIsJumpVisitor::visit(const MultiPseudoRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }
     
}
