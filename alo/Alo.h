#ifndef _ALO_H_
#define _ALO_H_

namespace Alo
{
  class Alo
  {
  public:
    
    Alo() 
      {}

    virtual ~Alo()
      {}

    virtual void assemble(int argc, 
			  char *argv[]) = 0;

    virtual void printFatalInternalError(const char *errorMsg) = 0;

    virtual void printFatalInternalError(const char *errorMsg, 
					 const char *fileName, 
					 unsigned int lineNum) = 0;

    virtual void printFatalError(const char *errorMsg, 
				 const char *fileName, 
				 unsigned int lineNum) = 0;

    virtual void printFatalError(const char *errorMsg) = 0;

    virtual void printError(const char *fileName, 
			    unsigned int lineNum, 
			    const char *errorMsg) = 0;

    virtual void printWarning(const char *fileName, 
			      unsigned int lineNum, 
			      const char *warnMsg) = 0;

    virtual void printWarning(const char *errorMsg) = 0;

    virtual unsigned int getNumErrors() const = 0;

    virtual unsigned int getNumWarnings() const = 0;
  };
}

#endif
