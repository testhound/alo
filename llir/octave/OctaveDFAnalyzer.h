#ifndef _OCTAVE_DFA_ANALYZER_
#define _OCTAVE_DFA_ANALYZER_

#include <LlirDFAnalyzer.h>
#include <LlirNode.h>
#include "BasicBlock.h"
#include <ControlFlowGraph.h>


namespace Llir
{
  class OctaveDataFlowAnalyzer : public LlirDataFlowAnalyzer
    {
    public:
      
      OctaveDataFlowAnalyzer(shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> >);
      ~OctaveDataFlowAnalyzer();
      OctaveDataFlowAnalyzer(const OctaveDataFlowAnalyzer& rhs);
      OctaveDataFlowAnalyzer& operator=(const OctaveDataFlowAnalyzer& rhs);

    protected:
      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > getControlFlowGraph();

    private:
      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > m_cfg;      
    };
}

#endif
