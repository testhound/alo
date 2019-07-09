#ifndef _ALO_EXCEPTION_H_
#define _ALO_EXCEPTION_H_

#include <string>
#include <list>
#include <exception>
#include <boost/shared_ptr.hpp>
#include <Visitor.h>

using namespace boost;
using namespace Llir;

namespace Alo
{
  class AloException : public std::exception
  {
  public:
    virtual ~AloException() throw() = 0;
      
    const char *what() const throw();
    const std::string& getFileName() const;
    unsigned int getLineNum() const;
    virtual void accept(Visitor &) const = 0;

  protected:
    AloException(const char *msg, unsigned int lineNum, const char *fileName);
    AloException(const AloException &rhs);
    AloException& operator=(const AloException &rhs);

  private:
    std::string m_exceptionString;
    unsigned int m_exceptionLineNum;
    std::string m_exceptionFileName;
  };

  class AloInternalException : public AloException
  {
  public:
    AloInternalException(const char *msg, unsigned int lineNum, const char *filename);
    AloInternalException(const AloInternalException &rhs);
    AloInternalException& operator=(const AloInternalException &rhs);
    ~AloInternalException() throw();

    void accept(Visitor &) const;
  };

  class AloExceptionWithSourceInfo : public AloException
  {
  public:
    AloExceptionWithSourceInfo(const char *msg, unsigned int inputSrcLineNum, 
			       const char *inputFileName, unsigned int internalLineNum, 
			       const char *internalFilename);
    AloExceptionWithSourceInfo(const AloExceptionWithSourceInfo &rhs);
    AloExceptionWithSourceInfo& operator=(const AloExceptionWithSourceInfo &rhs);
    virtual ~AloExceptionWithSourceInfo() throw();
    
    unsigned int getInputSrcLineNum() const;
    const std::string& getInputSrcFileName() const;
    
  private:
    unsigned int m_inputSrcLineNum;
    std::string m_inputSrcFileName;
  };

  class AloFatalError : public AloExceptionWithSourceInfo
  {
  public:
    AloFatalError(const char *msg, unsigned int inputSrcLineNum, 
			 const char *inputFileName, unsigned int internalLineNum, 
			 const char *internalFilename);
    AloFatalError(const AloFatalError &rhs);
    AloFatalError& operator=(const AloFatalError &rhs);
    virtual ~AloFatalError() throw();

    virtual void accept(Visitor &) const;
  };

  class AloSemanticException : public AloException
  {
  public:
    AloSemanticException(const char *msg, unsigned int inputSrcLineNum, 
			 const char *inputFileName, unsigned int internalLineNum, 
			 const char *internalFilename);
    AloSemanticException(const AloSemanticException &rhs);
    AloSemanticException& operator=(const AloSemanticException &rhs);
    virtual ~AloSemanticException() throw();
    
    unsigned int getInputSrcLineNum() const;
    const std::string& getInputSrcFileName() const;

  private:
    unsigned int m_inputSrcLineNum;
    std::string m_inputSrcFileName;
  };

  class IllegalExpression : public AloSemanticException
  {
  public:
    IllegalExpression(const char *msg, unsigned int inputSrcLineNum, 
		      const char *inputFileName, unsigned int internalLineNum, 
		      const char *internalFilename);
    IllegalExpression(const IllegalExpression &rhs);
    IllegalExpression& operator=(const IllegalExpression &rhs);
    virtual ~IllegalExpression() throw();

    virtual void accept(Visitor &) const;
  };

  class IllegalInsn : public AloSemanticException
  {
  public:
    IllegalInsn(const char *msg, unsigned int inputSrcLineNum, 
		      const char *inputFileName, unsigned int internalLineNum, 
		      const char *internalFilename);
    IllegalInsn(const IllegalInsn &rhs);
    IllegalInsn& operator=(const IllegalInsn &rhs);
    virtual ~IllegalInsn() throw();

    virtual void accept(Visitor &) const;
  };

  class RtlGenerationException : public AloSemanticException
  {
  public:
    RtlGenerationException(const char *msg, unsigned int inputSrcLineNum, 
		      const char *inputFileName, unsigned int internalLineNum, 
		      const char *internalFilename);
    RtlGenerationException(const RtlGenerationException &rhs);
    RtlGenerationException& operator=(const RtlGenerationException &rhs);
    virtual ~RtlGenerationException() throw();

    virtual void accept(Visitor &) const;
  };

  class WarningDirectiveException : public AloSemanticException
  {
  public:
    WarningDirectiveException(const char *msg, unsigned int inputSrcLineNum, 
		      const char *inputFileName, unsigned int internalLineNum, 
		      const char *internalFilename);
    WarningDirectiveException(const WarningDirectiveException &rhs);
    WarningDirectiveException& operator=(const WarningDirectiveException &rhs);
    virtual ~WarningDirectiveException() throw();

    virtual void accept(Visitor &) const;
  };

  class ErrorDirectiveException : public AloSemanticException
  {
  public:
    ErrorDirectiveException(const char *msg, unsigned int inputSrcLineNum, 
		      const char *inputFileName, unsigned int internalLineNum, 
		      const char *internalFilename);
    ErrorDirectiveException(const ErrorDirectiveException &rhs);
    ErrorDirectiveException& operator=(const ErrorDirectiveException &rhs);
    virtual ~ErrorDirectiveException() throw();

    virtual void accept(Visitor &) const;
  };

  /// A required environment variable is not set.
  /**
   * An object of this class is thrown when a required environment
   * variable is undefined or blank.
   */
  class EnvVarNotSet : public AloException
  {
  public:
    /// Constructs an EnvVarNotSet object.
    EnvVarNotSet(const char *msg, unsigned int lineNum, const char *filename);
    
    /// Destroys an EnvVarNotSet object.
    ~EnvVarNotSet() throw();
    
    EnvVarNotSet(const EnvVarNotSet &rhs);
    EnvVarNotSet& operator=(const EnvVarNotSet &rhs);
    void accept(Visitor &) const;
  };


  /// No input file was specified at the command line.
  /**
   * An object of this class is thrown when the driver fails to find
   * the name of an assembler source file in the command line arguments list.
   */
  class NoInputFileSpecified : public AloException
  {
  public:
    /**
     * Constructs a NoInputFileSpecified object.
     *
     * The error message created should read:
     * "No input file was specified."
     */
    NoInputFileSpecified(const char *msg, unsigned int lineNum, const char *filename);
    
    /// Destroys a NoInputFileSpecified object.
    ~NoInputFileSpecified() throw();
    
    NoInputFileSpecified(const NoInputFileSpecified &rhs);
    NoInputFileSpecified& operator=(const NoInputFileSpecified &rhs);
    void accept(Visitor &) const;
  };


  /// The input file specified has an incorrect name.
  /**
   * This represents a condition in which the input file specified at
   * the command line has a format other than the <name>.s.
   */
  class InvalidFileName : public AloException
  {
  public:
    /// Constructs an InvalidFileName object.
    /**
     *
     * The error message created should read:
     * File name "<filename>" is invalid. It must have a file
     * extension of ".s".
     */
    InvalidFileName(const char *msg, unsigned int lineNum, const char *filename);
    
    /// Destroys an InvalidFileName object.
    ~InvalidFileName() throw();
    
    InvalidFileName(const InvalidFileName &rhs);
    InvalidFileName& operator=(const InvalidFileName &rhs);
    void accept(Visitor &) const;
  };


  /// A command failed to execute.
  /**
   * This base class should not be instantiated. Use one of
   * the more specific subclasses or the CmdGeneralFailure
   * subclass instead for actual command errors.
   *
   * @note Perhaps the entire CmdFailure hierarchy is overkill.
   */
  class CmdFailure : public AloException
    {
    public:
      /// Constructs a CmdFailure object.
      /**
       * @param msg the error message associated with this object. This will
       *            be what the what() method returns.
       */
      CmdFailure(const char *msg, unsigned int lineNum, const char *filename);

      /// Destroys a CmdFailure object.
      virtual ~CmdFailure() throw();

      CmdFailure(const CmdFailure &rhs);
      CmdFailure& operator=(const CmdFailure &rhs);
    };


  /// A command failed to execute.
  /**
   * Throw an object of this class to indicate the failure of
   * a command that is not covered by the other specific
   * CmdFailure classes.
   *
   * @note "general" failure => lame name
   */
  class CmdGeneralFailure : public CmdFailure
    {
    public:
      /// Constructs a CmdFailure object.
      /**
       *
       * The error message created should read:
       * Command failed: "<cmd_line>".
       */
      CmdGeneralFailure(const char *msg, unsigned int lineNum, const char *filename);

      /// Destroys a CmdGeneralFailure object.
      ~CmdGeneralFailure() throw();

      CmdGeneralFailure(const CmdGeneralFailure &rhs);
      CmdGeneralFailure& operator=(const CmdGeneralFailure &rhs);
      void accept(Visitor &) const;
    };


  /// A command failed to begin.
  /**
   * The CmdStartFailure and CmdEndFailure classes are associated
   * with the do_command method, which opens a process by creating a pipe,
   * forking, and invoking the shell. If opening a file pointer to
   * the process fails, then an object of this class is thrown.
   */
  class CmdStartFailure : public CmdFailure
    {
    public:
      /// Constructs a CmdStartFailure object.
      /**
       *
       * The error message created should read:
       * Failed to start command "<cmd_line>".
       */
      CmdStartFailure(const char *msg, unsigned int lineNum, const char *filename);

      /// Destroys a CmdStartFailure object.
      ~CmdStartFailure() throw();

      CmdStartFailure(const CmdStartFailure &rhs);
      CmdStartFailure& operator=(const CmdStartFailure &rhs);
      void accept(Visitor &) const;
    };


  /// A Command failed to terminate.
  /**
   * The CmdStartFailure and CmdEndFailure classes are associated with
   * the do_command method, which opens a process by creating a pipe,
   * forking, and invoking the shell. Closing the file pointer to the
   * process has the effect of waiting for the process to terminate and
   * then getting its exit status. If the process failed to close, then
   * an object of this class is thrown.
   */
  class CmdEndFailure : public CmdFailure
    {
    public:
      /// Constructs a CmdEndFailure object.
      /**
       * The error message created should read:
       * Problem finishing command "<cmd_line>".
       */
      CmdEndFailure(const char *msg, unsigned int lineNum, const char *filename);

      /// Destroys a CmdEndFailure object.
      ~CmdEndFailure() throw();
      CmdEndFailure(const CmdEndFailure &rhs);
      CmdEndFailure& operator=(const CmdEndFailure &rhs);
      void accept(Visitor &) const;
    };


  /// A preprocessor was not found at a specified path.
  class CppPathNotFound : public AloException
    {
    public:
      /// Constructs a CppPathNotFound object.
      /**
       * The error message created should read:
       * Could not find the preprocessor at "<path>".
       */
      CppPathNotFound(const char *msg, unsigned int lineNum, const char *filename);
      CppPathNotFound(const CppPathNotFound &rhs);
      CppPathNotFound& operator=(const CppPathNotFound &rhs);
      void accept(Visitor &) const;

      /// Destroys a CppPathNotFound object.
      ~CppPathNotFound() throw();
    };

  class AloExceptionLogger
  {
  public:
    typedef std::list<shared_ptr<std::exception> >::iterator Iterator;
    typedef std::list<shared_ptr<std::exception> >::const_iterator ConstIterator;

    AloExceptionLogger();
    ~AloExceptionLogger();

    void logException(shared_ptr<std::exception> exc);
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
    void clear();

  private:
    std::list<shared_ptr<std::exception> > m_exceptionList;
  };

#define ALO_INTERNAL_EXCEPTION(MSG) AloInternalException(MSG, __LINE__, __FILE__)
}

#endif
