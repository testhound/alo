#ifndef _M480_ALO_H_
#define _M480_ALO_H_

#include <string>
using namespace std;

#include <OctaveAlo.h>
#include <LlirFile.h>
#include <OctaveFactory.h>
#include "M480Driver.h"
#include <BasicBlock.h>
#include <ControlFlowGraph.h>

using namespace Llir;

namespace Alo
{

  class M480Driver;

  class M480Alo : public OctaveAlo
  {
  public:
    M480Alo();
    ~M480Alo();
    M480Alo(const M480Alo& rhs);
    M480Alo& operator=(const M480Alo& rhs);

    void assemble(int argc, char *argv[]);
    shared_ptr<OctaveFactory> getFactory() const;


  private:
    
    void parseCommandLine(int argc, char *argv[]);
    void preprocessAsmFile(const char *asmFileName);
    void parseAsmFile(shared_ptr<LlirFile>);

    void analyzeSemantics(shared_ptr<LlirNode>);

    void analyzeCurrentFunction(shared_ptr<LlirNode>);

    void markSequenceInsns(shared_ptr<LlirOctaveBlock>);

    void checkDelaySlots(shared_ptr<LlirFile>);

    void generateRTL(shared_ptr<LlirNode>);

    void identifyBranchTargets(shared_ptr<AltEntryFunction>);
    void identifyCallTargets(shared_ptr<AltEntryFunction>);
    
    void identifyLiveEssRegisters(shared_ptr<AltEntryFunction>);

    void displayUsage();
    void printAssemblyFile(shared_ptr<LlirFile>);
    void generateObjectCode(const char* asmFileName);

    void printControlAndDataFlowInfo(shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg);

    bool checkForReturnInsn(shared_ptr<LlirOctaveBlock>);

    M480Driver m_asm;
    shared_ptr<Llir::OctaveFactory> m_M480Factory;    
    std::string m_preprocessedFileName;
    std::string m_aloGeneratedAsmFileName;
    std::string m_cfgDumpFileName;
  };

}

#endif
