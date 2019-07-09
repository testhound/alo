#ifndef _M480_DFA_ANALYZER_
#define _M480_DFA_ANALYZER_

#include <iostream>
#include <deque>
#include <string>
using namespace std;


#include <LlirNode.h>
#include <OctaveNode.h>
#include <BasicBlock.h>
#include <ControlFlowGraph.h>
#include <OctaveNode.h>
#include <OctaveDFAnalyzer.h>
#include <OctaveOperand.h>
#include <OctaveInstructions.h>

namespace Llir
{
  class BasicBlockQueue;

  class M480DataFlowAnalyzer : public OctaveDataFlowAnalyzer
    {
    public:
      
      M480DataFlowAnalyzer(shared_ptr<AltEntryFunction> f, 
			   shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg);
      ~M480DataFlowAnalyzer();
      M480DataFlowAnalyzer(const M480DataFlowAnalyzer& rhs);
      M480DataFlowAnalyzer& operator=(const M480DataFlowAnalyzer& rhs);

      shared_ptr<AltEntryFunction> getCurrentFunction();
      void updateBasicBlockLiveNess();

    private:

      void updateBasicBlockLiveNess(shared_ptr<BasicBlock<LlirNode, BitVector> >);

      shared_ptr<BasicBlockQueue> getBasicBlockQueue();
      void initBasicBlockQueue();
      void updateBasicBlockQueue();

      void updateLiveRegsAtExitBB();
      void computeLiveRegsAtBegin(shared_ptr<BasicBlock<LlirNode, BitVector> >);
      void computeLiveRegsAtEnd(shared_ptr<BasicBlock<LlirNode, BitVector> >);
      
      void markSetRegsDead(shared_ptr<BitVector> bv, shared_ptr<LlirNode> node);
      void markUsedRegsLive(shared_ptr<BitVector> bv, shared_ptr<LlirNode> node);
      void markCallReturnRegsDead(shared_ptr<BitVector> bv, shared_ptr<LlirNode> node);
      void markCallArgRegsLive(shared_ptr<BitVector> bv, shared_ptr<LlirNode> node);
      void markCallClobberedRegsDead(shared_ptr<BitVector> bv);

      void markDstRegLiveNess(shared_ptr<LlirNode> node, shared_ptr<BitVector> bv);
      void markSrcRegLiveNess(shared_ptr<LlirNode> node, shared_ptr<BitVector> bv);

      shared_ptr<const PrototypeDirective> searchForPrototype(unsigned int line, const char* file, const char* name);
      const string& getCalledFnName(shared_ptr<LlirNode>);

    private:

      shared_ptr<AltEntryFunction> m_f;
      shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > m_cfg;  
      shared_ptr<BasicBlockQueue> m_bbQueue;

    };


  class BasicBlockQueue
    {
    public:

      BasicBlockQueue();
      ~BasicBlockQueue();
      BasicBlockQueue(const BasicBlockQueue& rhs);
      BasicBlockQueue& operator=(const BasicBlockQueue& rhs);
      
      void addBasicBlock(shared_ptr<BasicBlock<LlirNode, BitVector> > blk);
      bool findBasicBlock(unsigned int idx);

      bool isEmpty() const;
      shared_ptr<BasicBlock<LlirNode, BitVector> > getFrontBB();
      void removeFrontBB();

      typedef deque<shared_ptr<BasicBlock<LlirNode, BitVector> > >::iterator BBQIterator;
      typedef deque<shared_ptr<BasicBlock<LlirNode, BitVector> > >::const_iterator BBQConstIterator;
      BBQIterator begin();
      BBQIterator end();
      BBQConstIterator begin() const;
      BBQConstIterator end() const;

    private:
      deque<shared_ptr<BasicBlock<LlirNode, BitVector> > > m_bbQueue;
      
    };
}


#endif
