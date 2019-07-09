#include <M480Instructions.h>
#include "M480GenRtlVisitor.h"
#include <LlirOperand.h>
#include <AloException.h>

using namespace std;

namespace Alo
{
  void
  FindBranchLabelVisitor::visit(const LlirFile& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void 
  FindBranchLabelVisitor::visit(const LlirSequence &)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const NullNode& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const NewLineNode& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const LlirLineControlDirective& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const SignedImmediate& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const UnsignedImmediate& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const OpndLabel& v)
  {
    m_branchLabel = v.getMangledName();
  }

  const string&
  FindBranchLabelVisitor::getBranchTarget() const
  {
    return m_branchLabel;
  }
  
  void FindBranchLabelVisitor::visit(const OpndNull& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const PlusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
  }

  void FindBranchLabelVisitor::visit(const MinusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
  }

  void FindBranchLabelVisitor::visit(const MultiplyOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const DivOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const ModulusOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const LeftShiftOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const RightShiftOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const BitWiseAndOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const BitWiseOrOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const BitWiseXorOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }


  void FindBranchLabelVisitor::visit(const ParenthesesOp& v)
  {
    v.getOpnd()->accept(*this);
  }

  void FindBranchLabelVisitor::visit(const UnaryMinusOp& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const NullRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const HardRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const PseudoRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const MultiHardRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }

  void FindBranchLabelVisitor::visit(const MultiPseudoRegister& v)
  {
    throw ALO_INTERNAL_EXCEPTION("Illegal branch target");
  }
     
}
