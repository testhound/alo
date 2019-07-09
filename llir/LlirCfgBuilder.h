#ifndef _LLIR_CFG_BUILDER_H_
#define _LLIR_CFG_BUILDER_H_

#include "ControlFlowGraph.h"

namespace Llir
{

  using namespace boost;

  template <class B, class E>
    class LlirCFGBuilder
    {
    public:
      
      virtual void buildFlowGraph() =0;

      virtual shared_ptr<ControlFlowGraph<B,E> > getControlFlowGraph() =0;

    protected:

      LlirCFGBuilder() {}

      virtual ~LlirCFGBuilder() {}
	
    };
}

#endif
