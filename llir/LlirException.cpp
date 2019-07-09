#include "LlirException.h"
#include "LlirVisitor.h"

namespace Llir
{
  LlirException::LlirException(const char *msg, unsigned int lineNum, const char *fileName) :
    std::exception(),
	 m_exceptionString(msg),
	 m_exceptionLineNum(lineNum),
	 m_exceptionFileName(fileName)
  {}

  LlirException::LlirException(const LlirException &rhs) : 
    std::exception(rhs),
	 m_exceptionString(rhs.m_exceptionString),
	 m_exceptionLineNum(rhs.m_exceptionLineNum),
	 m_exceptionFileName(rhs.m_exceptionFileName)
  {}

  LlirException&
  LlirException::operator=(const LlirException &rhs)
  {
    if (this == &rhs)
      return *this;

    std::exception::operator=(rhs);
    m_exceptionString = rhs.m_exceptionString;
    m_exceptionLineNum = rhs.m_exceptionLineNum;
    m_exceptionFileName = rhs.m_exceptionFileName;
    return *this;
  }

  LlirException::~LlirException() throw()
  {}

  const char *
  LlirException::what() const throw()
  {
    return m_exceptionString.c_str();
  }

  const std::string&
  LlirException::getFileName() const
  {
    return m_exceptionFileName;
  }

  unsigned int
  LlirException::getLineNum() const
  {
    return m_exceptionLineNum;
  }

  //

  LlirInternalException::LlirInternalException(const char *msg, unsigned int lineNum,
					       const char *fileName) :
    LlirException(msg, lineNum, fileName)
  {}

  LlirInternalException::LlirInternalException(const LlirInternalException &rhs) : 
    LlirException(rhs)
  {}

  LlirInternalException&
  LlirInternalException::operator=(const LlirInternalException &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirException::operator=(rhs);
    return *this;
  }

  LlirInternalException::~LlirInternalException() throw()
  {}

  void
  LlirInternalException::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("LlirInternalException::accept - Visit error");
    }       
  }

  // Type Exception
  LlirTypeException::LlirTypeException(const char *msg,
				       unsigned int internalLineNum, 
				       const char *internalFilename) :
    LlirException(msg, internalLineNum, internalFilename)
  {}

  LlirTypeException::LlirTypeException(const LlirTypeException &rhs) :
    LlirException(rhs)
  {}

  LlirTypeException&
  LlirTypeException::operator=(const LlirTypeException &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirException::operator=(rhs);
    return *this;
  }

  LlirTypeException::~LlirTypeException() throw()
  {}

  void
  LlirTypeException::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("LlirTypeException::accept - Visit error");
    }       
  }
  

  // Directive Exception
  LlirDirectiveException::LlirDirectiveException(const char *msg,
				       unsigned int internalLineNum, 
				       const char *internalFilename) :
    LlirException(msg, internalLineNum, internalFilename)
  {}

  LlirDirectiveException::LlirDirectiveException(const LlirDirectiveException &rhs) :
    LlirException(rhs)
  {}

  LlirDirectiveException&
  LlirDirectiveException::operator=(const LlirDirectiveException &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirException::operator=(rhs);
    return *this;
  }

  LlirDirectiveException::~LlirDirectiveException() throw()
  {}

  void
  LlirDirectiveException::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("LlirDirectiveException::accept - Visit error");
    }       
  }
  

  //

  LlirSemanticException::LlirSemanticException(const char *msg, 
					     unsigned int inputSrcLineNum,
					     const char *inputSrcFileName,
					     unsigned int lineNum,
					     const char *fileName) :
    LlirException(msg, lineNum, fileName), 
    m_inputSrcLineNum(inputSrcLineNum),
    m_inputSrcFileName(inputSrcFileName)
  {}

  LlirSemanticException::LlirSemanticException(const LlirSemanticException &rhs) : 
    LlirException(rhs),
    m_inputSrcLineNum(rhs.m_inputSrcLineNum),
    m_inputSrcFileName(rhs.m_inputSrcFileName)
  {}

  LlirSemanticException&
  LlirSemanticException::operator=(const LlirSemanticException &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirException::operator=(rhs);
    m_inputSrcLineNum = rhs.m_inputSrcLineNum;
    m_inputSrcFileName = rhs.m_inputSrcFileName;
    return *this;
  }

  LlirSemanticException::~LlirSemanticException() throw()
  {}

  unsigned int
  LlirSemanticException::getInputSrcLineNum() const
  {
    return m_inputSrcLineNum;
  }

  const std::string&
  LlirSemanticException::getInputSrcFileName() const
  {
    return m_inputSrcFileName;
  }

  // Illegal Operand
  
  IllegalOperand::IllegalOperand(const char *msg, 
				 unsigned int inputSrcLineNum,
				 const char *inputSrcFileName,
				 unsigned int lineNum,
				 const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalOperand::IllegalOperand(const IllegalOperand &rhs) : 
    LlirSemanticException(rhs)
  {}

  IllegalOperand&
  IllegalOperand::operator=(const IllegalOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }

  IllegalOperand::~IllegalOperand() throw()
  {}
  
  // Parse Error
  
  ParseError::ParseError(const char *msg, 
			   unsigned int inputSrcLineNum,
			   const char *inputSrcFileName,
			   unsigned int lineNum,
			   const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  ParseError::ParseError(const ParseError &rhs) : 
    LlirSemanticException(rhs)
  {}

  ParseError&
  ParseError::operator=(const ParseError &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }
  
  ParseError::~ParseError() throw()
  {}
  
  void
  ParseError::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("ParseError::accept - Visit error");
    }       
  }



  //  Illegal Delay Slot Instruction
  
  IllegalDelaySlotInsn::IllegalDelaySlotInsn(const char *msg, 
			   unsigned int inputSrcLineNum,
			   const char *inputSrcFileName,
			   unsigned int lineNum,
			   const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalDelaySlotInsn::IllegalDelaySlotInsn(const IllegalDelaySlotInsn &rhs) : 
    LlirSemanticException(rhs)
  {}

  IllegalDelaySlotInsn&
  IllegalDelaySlotInsn::operator=(const IllegalDelaySlotInsn &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }
  
  IllegalDelaySlotInsn::~IllegalDelaySlotInsn() throw()
  {}
  
  void
  IllegalDelaySlotInsn::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalDelaySlotInsn::accept - Visit error");
    }       
  }






  
  // Illegal Flag
  
  IllegalFlag::IllegalFlag(const char *msg, 
			   unsigned int inputSrcLineNum,
			   const char *inputSrcFileName,
			   unsigned int lineNum,
			   const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalFlag::IllegalFlag(const IllegalFlag &rhs) : 
    LlirSemanticException(rhs)
  {}

  IllegalFlag&
  IllegalFlag::operator=(const IllegalFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }
  
  IllegalFlag::~IllegalFlag() throw()
  {}
  
  void
  IllegalFlag::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalFlag::accept - Visit error");
    }       
  }
  
  // Illegal Register

  IllegalRegisterOperand::IllegalRegisterOperand(const char *msg, 
						 unsigned int inputSrcLineNum,
						 const char *inputSrcFileName,
						 unsigned int lineNum,
						 const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalRegisterOperand::IllegalRegisterOperand(const IllegalRegisterOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  IllegalRegisterOperand&
  IllegalRegisterOperand::operator=(const IllegalRegisterOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  IllegalRegisterOperand::~IllegalRegisterOperand() throw()
  {}
  
  void
  IllegalRegisterOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalRegisterOperand::accept - Visit error");
    }       
  }
  
  // Illegal Label

  IllegalLabelOperand::IllegalLabelOperand(const char *msg, 
						 unsigned int inputSrcLineNum,
						 const char *inputSrcFileName,
						 unsigned int lineNum,
						 const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalLabelOperand::IllegalLabelOperand(const IllegalLabelOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  IllegalLabelOperand&
  IllegalLabelOperand::operator=(const IllegalLabelOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  IllegalLabelOperand::~IllegalLabelOperand() throw()
  {}

  void
  IllegalLabelOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalLabelOperand::accept - Visit error");
    }       
  }
  
  // Illegal Symbol

  IllegalSymbolOperand::IllegalSymbolOperand(const char *msg, 
						 unsigned int inputSrcLineNum,
						 const char *inputSrcFileName,
						 unsigned int lineNum,
						 const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalSymbolOperand::IllegalSymbolOperand(const IllegalSymbolOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  IllegalSymbolOperand&
  IllegalSymbolOperand::operator=(const IllegalSymbolOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  IllegalSymbolOperand::~IllegalSymbolOperand() throw()
  {}

  void
  IllegalSymbolOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalSymbolOperand::accept - Visit error");
    }       
  }



  // Illegal Mapping

  IllegalMappingOperand::IllegalMappingOperand(const char *msg, 
						 unsigned int inputSrcLineNum,
						 const char *inputSrcFileName,
						 unsigned int lineNum,
						 const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalMappingOperand::IllegalMappingOperand(const IllegalMappingOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  IllegalMappingOperand&
  IllegalMappingOperand::operator=(const IllegalMappingOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  IllegalMappingOperand::~IllegalMappingOperand() throw()
  {}

  void
  IllegalMappingOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalMappingOperand::accept - Visit error");
    }       
  }



  // Illegal Bit number or position

  IllegalBitopOperand::IllegalBitopOperand(const char *msg, 
						 unsigned int inputSrcLineNum,
						 const char *inputSrcFileName,
						 unsigned int lineNum,
						 const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalBitopOperand::IllegalBitopOperand(const IllegalBitopOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  IllegalBitopOperand&
  IllegalBitopOperand::operator=(const IllegalBitopOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  IllegalBitopOperand::~IllegalBitopOperand() throw()
  {}

  void
  IllegalBitopOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalBitopOperand::accept - Visit error");
    }       
  }


  // Duplicate Operand

  DuplicateOperand::DuplicateOperand(const char *msg, 
				     unsigned int inputSrcLineNum,
				     const char *inputSrcFileName,
				     unsigned int lineNum,
				     const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  DuplicateOperand::DuplicateOperand(const DuplicateOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  DuplicateOperand&
  DuplicateOperand::operator=(const DuplicateOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  DuplicateOperand::~DuplicateOperand() throw()
  {}

  void
  DuplicateOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("DuplicateOperand::accept - Visit error");
      }       
  }


  // Missing Required Operand

  MissingRequiredOperand::MissingRequiredOperand(const char *msg, 
				     unsigned int inputSrcLineNum,
				     const char *inputSrcFileName,
				     unsigned int lineNum,
				     const char *fileName) :
    IllegalOperand(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  MissingRequiredOperand::MissingRequiredOperand(const MissingRequiredOperand &rhs) : 
    IllegalOperand(rhs)
  {}

  MissingRequiredOperand&
  MissingRequiredOperand::operator=(const MissingRequiredOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    IllegalOperand::operator=(rhs);
    return *this;
  }

  MissingRequiredOperand::~MissingRequiredOperand() throw()
  {}

  void
  MissingRequiredOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("MissingRequiredOperand::accept - Visit error");
      }       
  }
  
  //

  OutOfRangeOperand::OutOfRangeOperand(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  OutOfRangeOperand::OutOfRangeOperand(const OutOfRangeOperand &rhs) : 
    LlirSemanticException(rhs)
  {}

  OutOfRangeOperand&
  OutOfRangeOperand::operator=(const OutOfRangeOperand &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }

  OutOfRangeOperand::~OutOfRangeOperand() throw()
  {}

  void
  OutOfRangeOperand::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("OutOfRangeOperand::accept - Visit error");
    }       
  }


  //

  InvalidInstructionException::InvalidInstructionException(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  InvalidInstructionException::InvalidInstructionException(const InvalidInstructionException &rhs) : 
    LlirSemanticException(rhs)
  {}

  InvalidInstructionException&
  InvalidInstructionException::operator=(const InvalidInstructionException &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }

  InvalidInstructionException::~InvalidInstructionException() throw()
  {}

  void
  InvalidInstructionException::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("InvalidInstructionException::accept - Visit error");
    }       
  }


  // IllegalDestWordLength
  IllegalDestWordLength::IllegalDestWordLength(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  IllegalDestWordLength::IllegalDestWordLength(const IllegalDestWordLength &rhs) : 
    LlirSemanticException(rhs)
  {}

  IllegalDestWordLength&
  IllegalDestWordLength::operator=(const IllegalDestWordLength &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }

  IllegalDestWordLength::~IllegalDestWordLength() throw()
  {}

  void
  IllegalDestWordLength::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("IllegalDestWordLength::accept - Visit error");
    }       
  }

  // LabelNotDeclaredException
  LabelNotDeclaredException::LabelNotDeclaredException(const char *msg, 
				       unsigned int inputSrcLineNum,
				       const char *inputSrcFileName,
				       unsigned int lineNum,
				       const char *fileName) :
    LlirSemanticException(msg, inputSrcLineNum, inputSrcFileName, lineNum, fileName)
  {}

  LabelNotDeclaredException::LabelNotDeclaredException(const LabelNotDeclaredException &rhs) : 
    LlirSemanticException(rhs)
  {}

  LabelNotDeclaredException&
  LabelNotDeclaredException::operator=(const LabelNotDeclaredException &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirSemanticException::operator=(rhs);
    return *this;
  }

  LabelNotDeclaredException::~LabelNotDeclaredException() throw()
  {}

  void
  LabelNotDeclaredException::accept(Visitor &v) const
  {
    if(LlirExceptionVisitor *lv = dynamic_cast<LlirExceptionVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("LabelNotDeclaredException::accept - Visit error");
    }       
  }

}
