#ifndef _CFG_DUMPER_H_
#define _CFG_DUMPER_H_

#include <sstream>
#include <ostream>
using namespace std;


#include <BasicBlock.h>
#include <LlirNode.h>
#include <ControlFlowGraph.h>

#include "M480PrintVisitor.h"

namespace Llir
{
  //control flow graph and data flow info dumper class.

  class M480CfgDfInfoDumper 
    {
    public:

      M480CfgDfInfoDumper(ostream& outputStream,
			  shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg);

      ~M480CfgDfInfoDumper();
      M480CfgDfInfoDumper(const M480CfgDfInfoDumper& rhs);
      M480CfgDfInfoDumper& operator=(const M480CfgDfInfoDumper& rhs);
      
      void printControlAndDataFlowInfo();

    private:

      void printGeneralInfo();
      void printBasicBlockInfo();
      void printBasicBlockInfo(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void printBasicBlockInsnList(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void printRegsLiveOnEntry(shared_ptr<BitVector>);
      void printRegsLiveOnExit(shared_ptr<BitVector>);
      void printSuccList(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void printPredList(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void printBitVector(shared_ptr<BitVector>);
      void printDeadRegInfo(shared_ptr<LlirNode> node, ostream& outStream);
      void printUnusedRegInfo(shared_ptr<LlirNode> node, ostream& outStream);

      ostream& getOutputStream() const;
      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > getControlFlowGraph() const;
    
    private:
      ostream& m_os;
      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > m_cfg;
};
}

#endif
