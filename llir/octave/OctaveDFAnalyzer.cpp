#include "OctaveDFAnalyzer.h"

namespace Llir
{
  OctaveDataFlowAnalyzer::OctaveDataFlowAnalyzer(shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg)
    : LlirDataFlowAnalyzer(),
      m_cfg(cfg)
  {}

  OctaveDataFlowAnalyzer::~OctaveDataFlowAnalyzer()
  {}

  OctaveDataFlowAnalyzer::OctaveDataFlowAnalyzer(const OctaveDataFlowAnalyzer& rhs)
    : LlirDataFlowAnalyzer(),
      m_cfg(rhs.m_cfg)
  {}

  OctaveDataFlowAnalyzer& 
  OctaveDataFlowAnalyzer::operator=(const OctaveDataFlowAnalyzer& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirDataFlowAnalyzer::operator=(rhs);
    m_cfg = rhs.m_cfg;
    return *this;
  }

  shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> >
  OctaveDataFlowAnalyzer::getControlFlowGraph()
  {
    return m_cfg;
  }

}
