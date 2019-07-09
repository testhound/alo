#ifndef _LLIR_EXCEPTION_H_
#define _LLIR_EXCEPTION_H_

#include <string>
#include <exception>

namespace Llir
{
  class Visitor;

  class LlirException : public std::exception
    {
    public:
      virtual ~LlirException() throw();
      
      const char *what() const throw();
      const std::string& getFileName() const;
      unsigned int getLineNum() const;
      virtual void accept(Visitor &v) const = 0;

    protected:
      LlirException(const char *msg, unsigned int lineNum, const char *fileName);
      LlirException(const LlirException &rhs);
      LlirException& operator=(const LlirException &rhs);

    private:
      std::string m_exceptionString;
      unsigned int m_exceptionLineNum;
      std::string m_exceptionFileName;
    };

  class LlirInternalException : public LlirException
    {
    public:
      LlirInternalException(const char *msg, unsigned int lineNum, const char *filename);
      LlirInternalException(const LlirInternalException &rhs);
      LlirInternalException& operator=(const LlirInternalException &rhs);
      virtual ~LlirInternalException() throw();
      virtual void accept(Visitor &v) const;
    };

  class LlirTypeException : public LlirException
    {
    public:
      LlirTypeException(const char *msg, unsigned int internalLineNum, const char *internalFilename);
      LlirTypeException(const LlirTypeException &rhs);
      LlirTypeException& operator=(const LlirTypeException &rhs);
      virtual ~LlirTypeException() throw();
      virtual void accept(Visitor &v) const;
    };

  class LlirDirectiveException : public LlirException
    {
    public:
      LlirDirectiveException(const char *msg, unsigned int internalLineNum, const char *internalFilename);
      LlirDirectiveException(const LlirDirectiveException &rhs);
      LlirDirectiveException& operator=(const LlirDirectiveException &rhs);
      virtual ~LlirDirectiveException() throw();
      virtual void accept(Visitor &v) const;
    };

  class LlirSemanticException : public LlirException
  {
  public:
    LlirSemanticException(const char *msg, unsigned int inputSrcLineNum, 
			 const char *inputFileName, unsigned int internalLineNum, 
			 const char *internalFilename);
    LlirSemanticException(const LlirSemanticException &rhs);
    LlirSemanticException& operator=(const LlirSemanticException &rhs);
    virtual ~LlirSemanticException() throw();
    
    unsigned int getInputSrcLineNum() const;
    const std::string& getInputSrcFileName() const;

  private:
    unsigned int m_inputSrcLineNum;
    std::string m_inputSrcFileName;
  };

  class ParseError : public LlirSemanticException
    {
    public:
      ParseError(const char *msg, unsigned int inputSrcLineNum, 
		  const char *inputFileName, unsigned int internalLineNum, 
		  const char *internalFilename);
      ParseError(const ParseError &rhs);
      ParseError& operator=(const ParseError &rhs);
      ~ParseError() throw();
      virtual void accept(Visitor &v) const;
    };


  class IllegalDelaySlotInsn : public LlirSemanticException
    {
    public:
      IllegalDelaySlotInsn(const char *msg, unsigned int inputSrcLineNum, 
		  const char *inputFileName, unsigned int internalLineNum, 
		  const char *internalFilename);
      IllegalDelaySlotInsn(const IllegalDelaySlotInsn &rhs);
      IllegalDelaySlotInsn& operator=(const IllegalDelaySlotInsn &rhs);
      ~IllegalDelaySlotInsn() throw();
      virtual void accept(Visitor &v) const;
    };


  
  class IllegalFlag : public LlirSemanticException
    {
    public:
      IllegalFlag(const char *msg, unsigned int inputSrcLineNum, 
		  const char *inputFileName, unsigned int internalLineNum, 
		  const char *internalFilename);
      IllegalFlag(const IllegalFlag &rhs);
      IllegalFlag& operator=(const IllegalFlag &rhs);
      ~IllegalFlag() throw();
      virtual void accept(Visitor &v) const;
    };
  
  class IllegalOperand : public LlirSemanticException
    {
    public:
      IllegalOperand(const char *msg, unsigned int inputSrcLineNum, 
		     const char *inputFileName, unsigned int internalLineNum, 
		     const char *internalFilename);
      IllegalOperand(const IllegalOperand &rhs);
      IllegalOperand& operator=(const IllegalOperand &rhs);
      virtual ~IllegalOperand() throw();
    };


  class IllegalRegisterOperand : public IllegalOperand
    {
    public:
      IllegalRegisterOperand(const char *msg, unsigned int inputSrcLineNum, 
			     const char *inputFileName, unsigned int internalLineNum, 
			     const char *internalFilename);
      IllegalRegisterOperand(const IllegalRegisterOperand &rhs);
      IllegalRegisterOperand& operator=(const IllegalRegisterOperand &rhs);
      ~IllegalRegisterOperand() throw();
      virtual void accept(Visitor &v) const;
    };





  class IllegalLabelOperand : public IllegalOperand
    {
    public:
      IllegalLabelOperand(const char *msg, unsigned int inputSrcLineNum, 
			  const char *inputFileName, unsigned int internalLineNum, 
			  const char *internalFilename);
      IllegalLabelOperand(const IllegalLabelOperand &rhs);
      IllegalLabelOperand& operator=(const IllegalLabelOperand &rhs);
      ~IllegalLabelOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class IllegalSymbolOperand : public IllegalOperand
    {
    public:
      IllegalSymbolOperand(const char *msg, unsigned int inputSrcLineNum, 
			   const char *inputFileName, unsigned int internalLineNum, 
			   const char *internalFilename);
      IllegalSymbolOperand(const IllegalSymbolOperand &rhs);
      IllegalSymbolOperand& operator=(const IllegalSymbolOperand &rhs);
      ~IllegalSymbolOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class IllegalMappingOperand : public IllegalOperand
    {
    public:
      IllegalMappingOperand(const char *msg, unsigned int inputSrcLineNum, 
			   const char *inputFileName, unsigned int internalLineNum, 
			   const char *internalFilename);
      IllegalMappingOperand(const IllegalMappingOperand &rhs);
      IllegalMappingOperand& operator=(const IllegalMappingOperand &rhs);
      ~IllegalMappingOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class IllegalBitopOperand : public IllegalOperand
    {
    public:
      IllegalBitopOperand(const char *msg, unsigned int inputSrcLineNum, 
			   const char *inputFileName, unsigned int internalLineNum, 
			   const char *internalFilename);
      IllegalBitopOperand(const IllegalBitopOperand &rhs);
      IllegalBitopOperand& operator=(const IllegalBitopOperand &rhs);
      ~IllegalBitopOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class DuplicateOperand : public IllegalOperand
    {
    public:
      DuplicateOperand(const char *msg, unsigned int inputSrcLineNum, 
		       const char *inputFileName, unsigned int internalLineNum, 
		       const char *internalFilename);
      DuplicateOperand(const DuplicateOperand &rhs);
      DuplicateOperand& operator=(const DuplicateOperand &rhs);
      ~DuplicateOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class MissingRequiredOperand : public IllegalOperand
    {
    public:
      MissingRequiredOperand(const char *msg, unsigned int inputSrcLineNum, 
			     const char *inputFileName, unsigned int internalLineNum, 
			     const char *internalFilename);
      MissingRequiredOperand(const MissingRequiredOperand &rhs);
      MissingRequiredOperand& operator=(const MissingRequiredOperand &rhs);
      ~MissingRequiredOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class OutOfRangeOperand : public LlirSemanticException
    {
    public:
      OutOfRangeOperand(const char *msg, unsigned int inputSrcLineNum, 
			const char *inputFileName, unsigned int internalLineNum, 
			const char *internalFilename);
      OutOfRangeOperand(const OutOfRangeOperand &rhs);
      OutOfRangeOperand& operator=(const OutOfRangeOperand &rhs);
      ~OutOfRangeOperand() throw();
      virtual void accept(Visitor &v) const;
    };


  class InvalidInstructionException : public LlirSemanticException
    {
    public:
      InvalidInstructionException(const char *msg, unsigned int inputSrcLineNum, 
			const char *inputFileName, unsigned int internalLineNum, 
			const char *internalFilename);
      InvalidInstructionException(const InvalidInstructionException &rhs);
      InvalidInstructionException& operator=(const InvalidInstructionException &rhs);
      ~InvalidInstructionException() throw();
      virtual void accept(Visitor &v) const;
    };


  class IllegalDestWordLength : public LlirSemanticException
    {
    public:
      IllegalDestWordLength(const char *msg, unsigned int inputSrcLineNum, 
			const char *inputFileName, unsigned int internalLineNum, 
			const char *internalFilename);
      IllegalDestWordLength(const IllegalDestWordLength &rhs);
      IllegalDestWordLength& operator=(const IllegalDestWordLength &rhs);
      ~IllegalDestWordLength() throw();
      virtual void accept(Visitor &v) const;
    };


  class LabelNotDeclaredException : public LlirSemanticException
    {
    public:
      LabelNotDeclaredException(const char *msg, unsigned int inputSrcLineNum, 
			const char *inputFileName, unsigned int internalLineNum, 
			const char *internalFilename);
      LabelNotDeclaredException(const LabelNotDeclaredException &rhs);
      LabelNotDeclaredException& operator=(const LabelNotDeclaredException &rhs);
      ~LabelNotDeclaredException() throw();
      virtual void accept(Visitor &v) const;
    };

#define LLIR_INTERNAL_EXCEPTION(MSG) LlirInternalException(MSG, __LINE__, __FILE__)
#define LLIR_TYPE_EXCEPTION(MSG) LlirTypeException(MSG, __LINE__, __FILE__)
#define LLIR_DIRECTIVE_EXCEPTION(MSG) LlirDirectiveException(MSG, __LINE__, __FILE__)
}
#endif
