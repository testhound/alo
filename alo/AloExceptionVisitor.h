#ifndef _ALO_EXCEPTION_VISITOR_H_
#define _ALO_EXCEPTION_VISITOR_H_

#include <Visitor.h>
#include <LlirVisitor.h>

using namespace Llir;
namespace Alo
{
  class Alo;

  class IllegalExpression;
  class IllegalInsn;
  class RtlGenerationException;
  class AloInternalException;
  class AloFatalError;
  class EnvVarNotSet;
  class NoInputFileSpecified;
  class InvalidFileName;
  class CmdGeneralFailure;
  class CmdStartFailure;
  class CmdEndFailure;
  class CppPathNotFound;
  class WarningDirectiveException;
  class ErrorDirectiveException;

  class AloExceptionVisitor
  {
  public:
    AloExceptionVisitor() {}
    virtual ~AloExceptionVisitor() {}

    virtual void visit(const IllegalExpression &) = 0;
    virtual void visit(const IllegalInsn &) = 0;
    virtual void visit(const RtlGenerationException &) = 0;
    virtual void visit(const AloFatalError &) = 0;
    virtual void visit(const AloInternalException &) = 0;
    virtual void visit(const WarningDirectiveException &) = 0;
    virtual void visit(const ErrorDirectiveException &) = 0;
    virtual void visit(const EnvVarNotSet &) = 0;
    virtual void visit(const NoInputFileSpecified &) = 0;
    virtual void visit(const InvalidFileName &) = 0;
    virtual void visit(const CmdGeneralFailure &) = 0;
    virtual void visit(const CmdStartFailure &) = 0;
    virtual void visit(const CmdEndFailure &) = 0;
    virtual void visit(const CppPathNotFound &) = 0;
  };



  
}

#endif
