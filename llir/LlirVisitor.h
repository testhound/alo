#ifndef _LLIR_VISITOR_H
#define _LLIR_VISITOR_H

#include <Visitor.h>
#include "LlirNode.h"

namespace Llir 
{

  class LlirFile;
  class NullNode;
  class NewLineNode;
  class LlirLineControlDirective;

  class SignedImmediate; 
  class UnsignedImmediate;
  class OpndLabel;

  class OpndNull;

  class PlusOp;
  class MinusOp;
  class MultiplyOp;
  class DivOp;
  class ModulusOp;
  class LeftShiftOp;
  class RightShiftOp;

  class ParenthesesOp;
  class UnaryMinusOp;

  class BitWiseAndOp;
  class BitWiseXorOp;
  class BitWiseOrOp;

  class NullRegister;
  class HardRegister;
  class PseudoRegister;
  class MultiHardRegister;
  class MultiPseudoRegister;

  //class SymbolTable<class D>;
  class LabelSymbol;

  class IllegalRegisterOperand;
  class OutOfRangeOperand;
  class LlirInternalException;

  class LlirVisitor
    {
    public:
      virtual void visit(const LlirFile& v)=0;
      virtual void visit(const LlirSequence &) = 0;
      virtual void visit(const NullNode& v)=0;
      virtual void visit(const NewLineNode& v)=0;
      virtual void visit(const LlirLineControlDirective& v)=0;
      virtual void visit(const SignedImmediate& v)=0;
      virtual void visit(const UnsignedImmediate& v)=0;
      virtual void visit(const OpndLabel& v)=0;
      virtual void visit(const OpndNull& v)=0;

      virtual void visit(const PlusOp& v)=0;
      virtual void visit(const MinusOp& v)=0;
      virtual void visit(const MultiplyOp& v)=0;
      virtual void visit(const DivOp& v)=0;
      virtual void visit(const ModulusOp& v)=0;
      virtual void visit(const LeftShiftOp& v)=0;
      virtual void visit(const RightShiftOp& v)=0;
      virtual void visit(const BitWiseAndOp& v)=0;
      virtual void visit(const BitWiseOrOp& v)=0;
      virtual void visit(const BitWiseXorOp& v)=0;

      virtual void visit(const ParenthesesOp& v)=0;
      virtual void visit(const UnaryMinusOp& v)=0;

      virtual void visit(const NullRegister& v)=0;
      virtual void visit(const HardRegister& v)=0;
      virtual void visit(const PseudoRegister& v)=0;
      virtual void visit(const MultiHardRegister& v)=0;
      virtual void visit(const MultiPseudoRegister& v)=0;
     
    };

  class LlirExceptionVisitor
    {
    public:
      virtual void visit(const IllegalRegisterOperand& v) = 0;
      virtual void visit(const IllegalLabelOperand& v) = 0;
      virtual void visit(const IllegalSymbolOperand& v) = 0;
      virtual void visit(const IllegalMappingOperand& v) = 0;
      virtual void visit(const OutOfRangeOperand& v) = 0;
      virtual void visit(const IllegalBitopOperand& v) = 0;
      virtual void visit(const DuplicateOperand& v) = 0;
      virtual void visit(const MissingRequiredOperand& v) = 0;
      virtual void visit(const LlirInternalException& v) = 0;
      virtual void visit(const LlirTypeException& v) = 0;
      virtual void visit(const LlirDirectiveException& v) = 0;
      virtual void visit(const IllegalFlag& v) = 0;
      virtual void visit(const ParseError& v) = 0;
      virtual void visit(const IllegalDelaySlotInsn& v) = 0;
      virtual void visit(const InvalidInstructionException& v) = 0;
      virtual void visit(const IllegalDestWordLength& v) = 0;
      virtual void visit(const LabelNotDeclaredException &e) = 0;
    };
}


#endif







