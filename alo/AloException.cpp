
#include <LlirException.h>

#include "AloExceptionVisitor.h"
#include "AloException.h"


namespace Alo
{
  AloExceptionLogger::AloExceptionLogger()
  {}

  AloExceptionLogger::~AloExceptionLogger()
  {}

  void
  AloExceptionLogger::logException(shared_ptr<std::exception> exc)
  {
    m_exceptionList.push_back(exc);
  }

  AloExceptionLogger::Iterator
  AloExceptionLogger::begin()
  {
    return m_exceptionList.begin();
  }

  AloExceptionLogger::Iterator
  AloExceptionLogger::end()
  {
    return m_exceptionList.end();
  }

  AloExceptionLogger::ConstIterator
  AloExceptionLogger::begin() const
  {
    return m_exceptionList.begin();
  }

  AloExceptionLogger::ConstIterator
  AloExceptionLogger::end() const
  {
    return m_exceptionList.end();
  }

  void
  AloExceptionLogger::clear()
  {
    m_exceptionList.erase(m_exceptionList.begin(), m_exceptionList.end());
  }


  //

  AloException::AloException(const char *msg, unsigned int lineNum, const char *fileName) :
    std::exception(),
	 m_exceptionString(msg),
	 m_exceptionLineNum(lineNum),
	 m_exceptionFileName(fileName)
  {}

  AloException::AloException(const AloException &rhs) : 
    std::exception(rhs),
	 m_exceptionString(rhs.m_exceptionString),
	 m_exceptionLineNum(rhs.m_exceptionLineNum),
	 m_exceptionFileName(rhs.m_exceptionFileName)
  {}

  AloException&
  AloException::operator=(const AloException &rhs)
  {
    if (this == &rhs)
      return *this;

    std::exception::operator=(rhs);
    m_exceptionString = rhs.m_exceptionString;
    m_exceptionLineNum = rhs.m_exceptionLineNum;
    m_exceptionFileName = rhs.m_exceptionFileName;
    return *this;
  }

  AloException::~AloException() throw()
  {}

  const char *
  AloException::what() const throw()
  {
    return m_exceptionString.c_str();
  }

  const std::string&
  AloException::getFileName() const
  {
    return m_exceptionFileName;
  }

  unsigned int
  AloException::getLineNum() const
  {
    return m_exceptionLineNum;
  }

  //

  AloInternalException::AloInternalException(const char *msg, unsigned int lineNum,
					     const char *fileName) :
    AloException(msg, lineNum, fileName)
  {}

  AloInternalException::AloInternalException(const AloInternalException &rhs) : 
    AloException(rhs)
  {}

  AloInternalException&
  AloInternalException::operator=(const AloInternalException &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    return *this;
  }

  AloInternalException::~AloInternalException() throw()
  {}

  void
  AloInternalException::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("AloInternalException::accept - Visit error");
    }       
  }

  // AloExceptionWithSourceInfo

  AloExceptionWithSourceInfo::AloExceptionWithSourceInfo(const char *msg, 
					     unsigned int inputSrcLineNum,
					     const char *inputSrcFileName,
					     unsigned int lineNum,
					     const char *fileName) :
    AloException(msg, lineNum, fileName), 
    m_inputSrcLineNum(inputSrcLineNum),
    m_inputSrcFileName(inputSrcFileName)
  {}

  AloExceptionWithSourceInfo::AloExceptionWithSourceInfo(const AloExceptionWithSourceInfo &rhs) : 
    AloException(rhs),
    m_inputSrcLineNum(rhs.m_inputSrcLineNum),
    m_inputSrcFileName(rhs.m_inputSrcFileName)
  {}

  AloExceptionWithSourceInfo&
  AloExceptionWithSourceInfo::operator=(const AloExceptionWithSourceInfo &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    m_inputSrcLineNum = rhs.m_inputSrcLineNum;
    m_inputSrcFileName = rhs.m_inputSrcFileName;
    return *this;
  }

  AloExceptionWithSourceInfo::~AloExceptionWithSourceInfo() throw()
  {}

  unsigned int
  AloExceptionWithSourceInfo::getInputSrcLineNum() const
  {
    return m_inputSrcLineNum;
  }

  const std::string&
  AloExceptionWithSourceInfo::getInputSrcFileName() const
  {
    return m_inputSrcFileName;
  }

  //

  AloFatalError::AloFatalError(const char *msg, 
			       unsigned int inputSrcLineNum,
			       const char *inputSrcFileName,
			       unsigned int lineNum,
			       const char *fileName) :
    AloExceptionWithSourceInfo(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  AloFatalError::AloFatalError(const AloFatalError &rhs) : 
    AloExceptionWithSourceInfo(rhs)
  {}

  AloFatalError&
  AloFatalError::operator=(const AloFatalError &rhs)
  {
    if (this == &rhs)
      return *this;

    AloExceptionWithSourceInfo::operator=(rhs);
    return *this;
  }

  AloFatalError::~AloFatalError() throw()
  {}


  void
  AloFatalError::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("AloFatalError::accept - Visit error");
    }       
  }

  //

  AloSemanticException::AloSemanticException(const char *msg, 
					     unsigned int inputSrcLineNum,
					     const char *inputSrcFileName,
					     unsigned int lineNum,
					     const char *fileName) :
    AloException(msg, lineNum, fileName), 
    m_inputSrcLineNum(inputSrcLineNum),
    m_inputSrcFileName(inputSrcFileName)
  {}

  AloSemanticException::AloSemanticException(const AloSemanticException &rhs) : 
    AloException(rhs),
    m_inputSrcLineNum(rhs.m_inputSrcLineNum),
    m_inputSrcFileName(rhs.m_inputSrcFileName)
  {}

  AloSemanticException&
  AloSemanticException::operator=(const AloSemanticException &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    m_inputSrcLineNum = rhs.m_inputSrcLineNum;
    m_inputSrcFileName = rhs.m_inputSrcFileName;
    return *this;
  }

  AloSemanticException::~AloSemanticException() throw()
  {}

  unsigned int
  AloSemanticException::getInputSrcLineNum() const
  {
    return m_inputSrcLineNum;
  }

  const std::string&
  AloSemanticException::getInputSrcFileName() const
  {
    return m_inputSrcFileName;
  }

  //

  IllegalExpression::IllegalExpression(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    AloSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalExpression::IllegalExpression(const IllegalExpression &rhs) : 
    AloSemanticException(rhs)
  {}

  IllegalExpression&
  IllegalExpression::operator=(const IllegalExpression &rhs)
  {
    if (this == &rhs)
      return *this;

    AloSemanticException::operator=(rhs);
    return *this;
  }

  IllegalExpression::~IllegalExpression() throw()
  {}


  void
  IllegalExpression::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("IllegalExpression::accept - Visit error");
    }       
  }

 // IllegalInsn

  IllegalInsn::IllegalInsn(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    AloSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalInsn::IllegalInsn(const IllegalInsn &rhs) : 
    AloSemanticException(rhs)
  {}

  IllegalInsn&
  IllegalInsn::operator=(const IllegalInsn &rhs)
  {
    if (this == &rhs)
      return *this;

    AloSemanticException::operator=(rhs);
    return *this;
  }

  IllegalInsn::~IllegalInsn() throw()
  {}


  void
  IllegalInsn::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("IllegalInsn::accept - Visit error");
    }       
  }

  // RtlGenerationException

  RtlGenerationException::RtlGenerationException(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    AloSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  RtlGenerationException::RtlGenerationException(const RtlGenerationException &rhs) : 
    AloSemanticException(rhs)
  {}

  RtlGenerationException&
  RtlGenerationException::operator=(const RtlGenerationException &rhs)
  {
    if (this == &rhs)
      return *this;

    AloSemanticException::operator=(rhs);
    return *this;
  }

  RtlGenerationException::~RtlGenerationException() throw()
  {}


  void
  RtlGenerationException::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("RtlGenerationException::accept - Visit error");
    }       
  }

  // EnvVarNotSet

  EnvVarNotSet::EnvVarNotSet(const char *msg, unsigned int lineNum, const char *fileName)
    : AloException(msg, lineNum, fileName)
  {
  }
  
  EnvVarNotSet::~EnvVarNotSet() throw()
  {
  }

  EnvVarNotSet::EnvVarNotSet(const EnvVarNotSet &rhs) : 
    AloException(rhs)
  {}

  EnvVarNotSet&
  EnvVarNotSet::operator=(const EnvVarNotSet &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    return *this;
  }

  void
  EnvVarNotSet::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("EnvVarNotSet::accept - Visit error");
    }       
  }

  // NoInputFileSpecified


  NoInputFileSpecified::NoInputFileSpecified(const char *msg, unsigned int lineNum, const char *fileName)
    : AloException(msg, lineNum, fileName)
  {
  }
  
  NoInputFileSpecified::~NoInputFileSpecified() throw()
  {
  }

  NoInputFileSpecified::NoInputFileSpecified(const NoInputFileSpecified &rhs) : 
    AloException(rhs)
  {}

  NoInputFileSpecified&
  NoInputFileSpecified::operator=(const NoInputFileSpecified &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    return *this;
  }

  void
  NoInputFileSpecified::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("NoInputFileSpecified::accept - Visit error");
    }       
  }

  //

  InvalidFileName::InvalidFileName(const char *msg, unsigned int lineNum, const char *fileName)
    : AloException(msg, lineNum, fileName)
  {
  }
  
  InvalidFileName::~InvalidFileName() throw()
  {
  }

  InvalidFileName::InvalidFileName(const InvalidFileName &rhs) : 
    AloException(rhs)
  {}

  InvalidFileName&
  InvalidFileName::operator=(const InvalidFileName &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    return *this;
  }

  void
  InvalidFileName::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("InvalidFileName::accept - Visit error");
    }       
  }

  //

  CmdFailure::CmdFailure(const char *msg, unsigned int lineNum, const char *fileName)
    : AloException(msg, lineNum, fileName)
  {
  }
  
  CmdFailure::~CmdFailure() throw()
  {
  }

  CmdFailure::CmdFailure(const CmdFailure &rhs) : 
    AloException(rhs)
  {}

  CmdFailure&
  CmdFailure::operator=(const CmdFailure &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    return *this;
  }

  //

  CmdGeneralFailure::CmdGeneralFailure(const char *msg, unsigned int lineNum, const char *fileName)
    : CmdFailure(msg, lineNum, fileName)
  {
  }
  
  CmdGeneralFailure::~CmdGeneralFailure() throw()
  {
  }

  CmdGeneralFailure::CmdGeneralFailure(const CmdGeneralFailure &rhs) : 
    CmdFailure(rhs)
  {}

  CmdGeneralFailure&
  CmdGeneralFailure::operator=(const CmdGeneralFailure &rhs)
  {
    if (this == &rhs)
      return *this;

    CmdFailure::operator=(rhs);
    return *this;
  }

  void
  CmdGeneralFailure::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("CmdGeneralFailure::accept - Visit error");
    }       
  }

  //

  CmdStartFailure::CmdStartFailure(const char *msg, unsigned int lineNum, const char *fileName)
    : CmdFailure(msg, lineNum, fileName)
  {
  }
  
  CmdStartFailure::~CmdStartFailure() throw()
  {
  }

  CmdStartFailure::CmdStartFailure(const CmdStartFailure &rhs) : 
    CmdFailure(rhs)
  {}

  CmdStartFailure&
  CmdStartFailure::operator=(const CmdStartFailure &rhs)
  {
    if (this == &rhs)
      return *this;

    CmdFailure::operator=(rhs);
    return *this;
  }

  void
  CmdStartFailure::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("CmdStartFailure::accept - Visit error");
    }       
  }

  //

  CmdEndFailure::CmdEndFailure(const char *msg, unsigned int lineNum, const char *fileName)
    : CmdFailure(msg, lineNum, fileName)
  {
  }
  
  CmdEndFailure::~CmdEndFailure() throw()
  {
  }

  CmdEndFailure::CmdEndFailure(const CmdEndFailure &rhs) : 
    CmdFailure(rhs)
  {}

  CmdEndFailure&
  CmdEndFailure::operator=(const CmdEndFailure &rhs)
  {
    if (this == &rhs)
      return *this;

    CmdFailure::operator=(rhs);
    return *this;
  }

  void
  CmdEndFailure::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("CmdEndFailure::accept - Visit error");
    }       
  }

  //

  CppPathNotFound::CppPathNotFound(const char *msg, unsigned int lineNum, const char *fileName)
    : AloException(msg, lineNum, fileName)
  {
  }
  
  CppPathNotFound::~CppPathNotFound() throw()
  {
  }

  CppPathNotFound::CppPathNotFound(const CppPathNotFound &rhs) : 
    AloException(rhs)
  {}

  CppPathNotFound&
  CppPathNotFound::operator=(const CppPathNotFound &rhs)
  {
    if (this == &rhs)
      return *this;

    AloException::operator=(rhs);
    return *this;
  }

  void
  CppPathNotFound::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("CppPathNotFound::accept - Visit error");
    }       
  }


  //

  ErrorDirectiveException::ErrorDirectiveException(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    AloSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  ErrorDirectiveException::ErrorDirectiveException(const ErrorDirectiveException &rhs) : 
    AloSemanticException(rhs)
  {}

  ErrorDirectiveException&
  ErrorDirectiveException::operator=(const ErrorDirectiveException &rhs)
  {
    if (this == &rhs)
      return *this;

    AloSemanticException::operator=(rhs);
    return *this;
  }

  ErrorDirectiveException::~ErrorDirectiveException() throw()
  {}


  void
  ErrorDirectiveException::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("ErrorDirectiveException::accept - Visit error");
    }       
  }

  //

  WarningDirectiveException::WarningDirectiveException(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    AloSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  WarningDirectiveException::WarningDirectiveException(const WarningDirectiveException &rhs) : 
    AloSemanticException(rhs)
  {}

  WarningDirectiveException&
  WarningDirectiveException::operator=(const WarningDirectiveException &rhs)
  {
    if (this == &rhs)
      return *this;

    AloSemanticException::operator=(rhs);
    return *this;
  }

  WarningDirectiveException::~WarningDirectiveException() throw()
  {}


  void
  WarningDirectiveException::accept(Visitor &v) const
  {
    if(AloExceptionVisitor *lv = dynamic_cast<AloExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw ALO_INTERNAL_EXCEPTION("WarningDirectiveException::accept - Visit error");
    }       
  }



}

