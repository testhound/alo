#ifndef _ALO_ERROR_WARNING_VISITOR_H_
#define _ALO_ERROR_WARNING_VISITOR_H_

#include "Visitor.h"
#include "LlirVisitor.h"
#include "AloExceptionVisitor.h"

using namespace Llir;
namespace Alo
{
 
  class Alo;

  class AloErrorWarningVisitor : public Visitor,
				 public AloExceptionVisitor,
				 public LlirExceptionVisitor
  {
  public:
    AloErrorWarningVisitor(Alo &o);
    ~AloErrorWarningVisitor();

    void visit(const IllegalExpression &);
    void visit(const IllegalInsn &);
    void visit(const RtlGenerationException &);
    void visit(const AloFatalError &);
    void visit(const AloInternalException &);
    void visit(const WarningDirectiveException &);
    void visit(const ErrorDirectiveException &);
    void visit(const IllegalRegisterOperand& v);
    void visit(const IllegalLabelOperand& v);
    void visit(const IllegalSymbolOperand& v);
    void visit(const IllegalMappingOperand& v);
    void visit(const IllegalBitopOperand& v);
    void visit(const OutOfRangeOperand& v);
    void visit(const DuplicateOperand& v);
    void visit(const MissingRequiredOperand& v);
    void visit(const IllegalFlag& v);
    void visit(const ParseError& v);
    void visit(const IllegalDelaySlotInsn& v);
    void visit(const IllegalDestWordLength& v);
    void visit(const LlirInternalException& v);
    void visit(const LlirTypeException& v);
    void visit(const InvalidInstructionException& v);
    void visit(const EnvVarNotSet &);
    void visit(const NoInputFileSpecified &);
    void visit(const InvalidFileName &);
    void visit(const CmdGeneralFailure &);
    void visit(const CmdStartFailure &);
    void visit(const CmdEndFailure &);
    void visit(const CppPathNotFound &);
    void visit(const LlirDirectiveException& v);
    void visit(const LabelNotDeclaredException &e);
  private:
    Alo &m_alo;
  };

  
}

#endif
