#include <OctaveCfgBuilder.h>

namespace Llir
{

  class M480CFGBuilder : public OctaveCFGBuilder
    {
    public:
      
      M480CFGBuilder(shared_ptr<AltEntryFunction> f);
      ~M480CFGBuilder();
      M480CFGBuilder& operator=(const M480CFGBuilder& rhs);
      M480CFGBuilder(const M480CFGBuilder& rhs);

      void buildFlowGraph();
      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > getControlFlowGraph();

    private:

      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > m_cfg;

    private:

      void findBasicBlocks();
      void makeEdges();

      void addBranchEdge(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void addFallThroughEdge(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void addConditionalBranchEdges(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void addJumpTableEdges(shared_ptr<BasicBlock<LlirNode, BitVector> > bb);
      void addJumpTableEdges(shared_ptr<BasicBlock<LlirNode, BitVector> > bb,
			     shared_ptr<LlirNode> node);

      bool isTableBranchInsn(shared_ptr<LlirNode> node) const;
      bool isIndirectJumpInsn(shared_ptr<LlirNode> node) const;
      bool isUnConditionalJump(shared_ptr<LlirNode> node) const;
      bool isConditionalJump(shared_ptr<LlirNode> node) const;

      shared_ptr<LlirNode> getJtableBeginDirective(const char* name);
      shared_ptr<BasicBlock<LlirNode, BitVector> > getNextBasicBlock(shared_ptr<BasicBlock<LlirNode, BitVector> >);
      shared_ptr<BasicBlock<LlirNode, BitVector> > getTargetBasicBlock(const char* name);
      shared_ptr<const OpndLabel> getBranchLabel(shared_ptr<LlirNode> node);

      typedef ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>::BasicBlockIterator BBIterator;

    };
}
