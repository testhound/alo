#ifndef _LLIR_DFA_ANALYZER_
#define _LLIR_DFA_ANALYZER_

namespace Llir
{
  class LlirDataFlowAnalyzer
    {
    public:
      virtual void updateBasicBlockLiveNess() =0;

    protected:
      LlirDataFlowAnalyzer();
      virtual ~LlirDataFlowAnalyzer();
      LlirDataFlowAnalyzer(const LlirDataFlowAnalyzer& rhs);
      LlirDataFlowAnalyzer& operator=(const LlirDataFlowAnalyzer& rhs);
    };
}


#endif
