#ifndef _M470_ALO_H_
#define _M470_ALO_H_

#include <string>
using namespace std;

#include <OctaveAlo.h>
#include <LlirFile.h>
#include <OctaveFactory.h>
#include "M470Driver.h"
using namespace Llir;

namespace Alo
{

  class M470Driver;

  class M470Alo : public OctaveAlo
  {
  public:
    M470Alo();
    ~M470Alo();

    void assemble(int argc, char *argv[]);
    shared_ptr<OctaveFactory> getFactory() const;


  private:
    
    void parseCommandLine(int argc, char *argv[]);
    void preprocessAsmFile(const char *asmFileName);
    void parseAsmFile(shared_ptr<LlirFile>);
    //    void analyzeSemantics(shared_ptr<LlirFile>);
    void analyzeSemantics(shared_ptr<LlirNode>);

    void analyzeCurrentFunction(shared_ptr<LlirNode>);

    void checkDelaySlots(shared_ptr<LlirFile>);

    void displayUsage();
    void printAssemblyFile(shared_ptr<LlirFile>);
    void generateObjectCode(const char* asmFileName);

    void markSequenceInsns(shared_ptr<LlirOctaveBlock>);

    void generateRTL(shared_ptr<LlirNode>);

    void identifyBranchTargets(shared_ptr<AltEntryFunction>);
    void identifyCallTargets(shared_ptr<AltEntryFunction>);
    void identifyLiveEssRegisters(shared_ptr<AltEntryFunction>);

    M470Driver m_asm;
    shared_ptr<Llir::OctaveFactory> m_M470Factory;    
    std::string m_preprocessedFileName;
    std::string m_aloGeneratedAsmFileName;
  };

}

#endif
