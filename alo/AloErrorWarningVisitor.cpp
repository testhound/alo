#include <iostream>
using namespace std;

#include <LlirVisitor.h>
#include <LlirException.h>

#include "Alo.h"
#include "AloException.h"
#include "AloExceptionVisitor.h"
#include "AloErrorWarningVisitor.h"

namespace Alo
{

  AloErrorWarningVisitor::AloErrorWarningVisitor(Alo &o):
    Visitor(),
    AloExceptionVisitor(),
    LlirExceptionVisitor(),
    m_alo(o)
  {}

  AloErrorWarningVisitor::~AloErrorWarningVisitor()
  {}

  void
  AloErrorWarningVisitor::visit(const InvalidInstructionException &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalExpression &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalInsn &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const RtlGenerationException &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const ErrorDirectiveException &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const WarningDirectiveException &e)
  {
    m_alo.printWarning(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const AloFatalError &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("AloFatalError logged");
  }

  void
  AloErrorWarningVisitor::visit(const LlirInternalException &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const LlirTypeException &e)
  {
    //FIXME: remove this line
    cout << e.what();

    throw LLIR_INTERNAL_EXCEPTION("Type Exception should not be logged, but caught and converted to ParseError");
  }

  void
  AloErrorWarningVisitor::visit(const AloInternalException &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const EnvVarNotSet &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const NoInputFileSpecified &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const InvalidFileName &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const CmdGeneralFailure &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const CmdStartFailure &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const CmdEndFailure &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const CppPathNotFound &e)
  {
    throw LLIR_INTERNAL_EXCEPTION("Internal Exception should not be logged");
  }

  void
  AloErrorWarningVisitor::visit(const IllegalRegisterOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }


  void
  AloErrorWarningVisitor::visit(const IllegalLabelOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalSymbolOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalMappingOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalBitopOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const OutOfRangeOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const DuplicateOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const MissingRequiredOperand &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }
  
  void
  AloErrorWarningVisitor::visit(const IllegalFlag &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const ParseError &e)
  {
    m_alo.printError(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalDelaySlotInsn &e)
  {
    m_alo.printWarning(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }

  void
  AloErrorWarningVisitor::visit(const IllegalDestWordLength &e)
  {
    m_alo.printWarning(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
  }


   void
   AloErrorWarningVisitor::visit(const LlirDirectiveException &e)
   {
     m_alo.printError(e.getFileName().c_str(), e.getLineNum(), e.what());
   }

   void
   AloErrorWarningVisitor::visit(const LabelNotDeclaredException &e)
   {
     m_alo.printWarning(e.getInputSrcFileName().c_str(), e.getInputSrcLineNum(), e.what());
   }

}
