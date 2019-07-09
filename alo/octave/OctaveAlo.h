#ifndef _OCTAVE_ALO_H
#define _OCTAVE_ALO_H

#include <exception>
#include <string>
#include <list>


#include <AloException.h>
#include <LlirFile.h>
#include <OctaveFactory.h>
#include <AloDriver.h>
#include <Alo.h>

using namespace Llir;

namespace Alo
{

  //FIXME

  class M470AsmDriver;

  class OctaveAlo : public Alo
  {
  public:
    typedef std::list<shared_ptr<Llir::LlirFile> >::iterator Iterator;
    typedef std::list<shared_ptr<Llir::LlirFile> >::const_iterator ConstIterator;

    OctaveAlo();
    virtual ~OctaveAlo();

    virtual void handleLoggedExceptions();
    virtual void printFatalInternalError(const char *errorMsg);
    virtual void printFatalInternalError(const char *errorMsg, const char *fileName, unsigned int lineNum);
    virtual void printFatalError(const char *errorMsg, const char *srcfileName, unsigned int srclineNum);
    virtual void printFatalError(const char *errorMsg);
    virtual void printError(const char *fileName, unsigned int lineNum, const char *errorMsg);
    virtual void printWarning(const char *fileName, unsigned int lineNum, const char *warnMsg);
    virtual void printWarning(const char *errorMsg);
    void disableWarnings();
    void setMaxErrors(unsigned int maxErrors);
    void setObjectFileName(const char *name);
    const std::string& getObjectFileName() const;
    virtual void logException(shared_ptr<std::exception> exc);
    virtual unsigned int getNumErrors() const;
    virtual unsigned int getNumWarnings() const;
    virtual shared_ptr<OctaveFactory> getFactory() const = 0;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

    void createLlirFile(const char *name);
  
    virtual void printAssemblyFile(shared_ptr<LlirFile>)=0;

/*     virtual void analyzeSemantics(shared_ptr<LlirFile>)=0; */
    virtual void analyzeSemantics(shared_ptr<LlirNode>)=0;
    
    virtual void analyzeCurrentFunction(shared_ptr<LlirNode>)=0;

    virtual void markSequenceInsns(shared_ptr<LlirOctaveBlock>)=0;


    virtual void checkDelaySlots(shared_ptr<LlirFile>)=0;

    virtual void generateRTL(shared_ptr<LlirNode>)=0;

    virtual void identifyBranchTargets(shared_ptr<AltEntryFunction>)=0;
    virtual void identifyCallTargets(shared_ptr<AltEntryFunction>)=0;

    virtual void identifyLiveEssRegisters(shared_ptr<AltEntryFunction>)=0;

  private:
    AloExceptionLogger m_loggedExceptions;
    unsigned int m_numErrors;
    unsigned int m_numWarnings;
    unsigned int m_maxNumErrors;
    std::list<shared_ptr<Llir::LlirFile> > m_fileList;
    bool m_disableWarnings;

    std::string m_objectFileName;
    

  };


}












#endif
