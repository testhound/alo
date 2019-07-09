#include "M480Instructions.h"
#include "M480DFAnalyzer.h"

using namespace Llir;
extern std::map<string, shared_ptr<const PrototypeDirective> > g_prototypeDirList;


namespace Llir
{
  M480DataFlowAnalyzer::M480DataFlowAnalyzer(shared_ptr<AltEntryFunction> f,
					     shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg)
    : OctaveDataFlowAnalyzer(cfg),
      m_f(f),
      m_bbQueue(new BasicBlockQueue())
  {}

  M480DataFlowAnalyzer::~M480DataFlowAnalyzer()
  {}

  M480DataFlowAnalyzer::M480DataFlowAnalyzer(const M480DataFlowAnalyzer& rhs)
    : OctaveDataFlowAnalyzer(rhs),
      m_f(rhs.m_f),
      m_bbQueue(rhs.m_bbQueue)
  {}

  M480DataFlowAnalyzer& 
  M480DataFlowAnalyzer::operator=(const M480DataFlowAnalyzer& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveDataFlowAnalyzer::operator=(rhs);
    m_f = rhs.m_f;
    m_bbQueue = rhs.m_bbQueue;
    return *this;
  }

  shared_ptr<AltEntryFunction>
  M480DataFlowAnalyzer::getCurrentFunction()
  {
    return m_f;
  }

  shared_ptr<BasicBlockQueue>
  M480DataFlowAnalyzer::getBasicBlockQueue()
  {
    return m_bbQueue;
  }

  void
  M480DataFlowAnalyzer::updateBasicBlockLiveNess()
  {
    shared_ptr<BasicBlockQueue> bbq = getBasicBlockQueue();

    // form basic block queue
    initBasicBlockQueue();

    // compute live_at_begin and live_at_end
    // on all the basic blocks
    while(! bbq->isEmpty())
      {
	updateBasicBlockLiveNess(bbq->getFrontBB());
      }
  }


  // initialization point of the algorithm.
  // initialize the set of registers live at exitBB.

  // in ALO runtime the set of live regs at the exit point
  // are the set of result regs in @results specification
  // (for a C compiler with runtime stack it would also include FP,SP,AP etc.,)

  void
  M480DataFlowAnalyzer::updateLiveRegsAtExitBB()
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;

    cfg = getControlFlowGraph();

    shared_ptr<BasicBlock<LlirNode, BitVector> > exitBB = cfg->getPseudoExitBB();

    shared_ptr<AltEntryFunction> f = getCurrentFunction();

    unsigned int numRegs = f->getNumRegs();

    shared_ptr<BitVector> bv (new BitVector(numRegs));

    // FIXME: reglist in .global directive also need to be updated
 
    // set @results <reg-list> to be live at exit.

    shared_ptr<const RegList> resultList = f->getResultList()->getRegList();

    RegList::ConstIterator iter = resultList->begin();

    for(; iter != resultList->end(); iter++)
      {
	shared_ptr<const Register> reg = iter->second;
	bv->setBit(reg->getRegNum());
      }

    exitBB->setRegsLiveOnExit(bv);
  }

  void
  M480DataFlowAnalyzer::initBasicBlockQueue()
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;

    cfg = getControlFlowGraph();

    unsigned int numVertices = cfg->getNumVertices();

    shared_ptr<BasicBlockQueue> bbq = getBasicBlockQueue();

    // store the set of basic blocks to be processed in reverse order.

    shared_ptr<BasicBlock<LlirNode, BitVector> > bb;

    for(unsigned int i = 0; i < numVertices; i++)
      {
	bb = cfg->getBasicBlock(i);

	bbq->addBasicBlock(bb);
      }
  }

  void
  M480DataFlowAnalyzer::updateBasicBlockLiveNess(shared_ptr<BasicBlock<LlirNode, BitVector> > blk)
  {
    // compute live_at_end for 'blk'
    computeLiveRegsAtEnd(blk);

    // compute live_at_begin for 'blk'
    computeLiveRegsAtBegin(blk);

    // if live_at_begin has changed add all the predecessors
    // of the current block to the queue for reexamination of
    // their live_at_end
    updateBasicBlockQueue();
  }
  
  // live_at_end of current basic block is 
  // union of live_at_begin of all the successor
  // basic blocks

  void
  M480DataFlowAnalyzer::computeLiveRegsAtEnd(shared_ptr<BasicBlock<LlirNode, BitVector> > blk)
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;

    cfg = getControlFlowGraph();

    if(cfg->isPseudoExitBB(blk))
      {
	// update live_at_end of EXIT bb
	updateLiveRegsAtExitBB();

	return;
      }

    unsigned int numRegs = m_f->getNumRegs();
 
    shared_ptr<BitVector> bv (new BitVector(numRegs));

    ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>::SuccEdgeListIter iter;

    iter = cfg->getSuccListBegin(blk);
 
    for(; iter != cfg->getSuccListEnd(blk); iter++)
      {
	shared_ptr<BasicBlock<LlirNode, BitVector> > bb = cfg->getDstBlkAtSuccEdge(iter);

	shared_ptr<BitVector> sbv = bb->getRegsLiveOnEntry();

	if(! sbv->isEmpty())
	  {
	    *bv |= *sbv;
	  }
      }
    
    blk->setRegsLiveOnExit(bv);
  }

  // live_at_entry of current basic block is computed
  // based on the register usage within the block

  void
  M480DataFlowAnalyzer::computeLiveRegsAtBegin(shared_ptr<BasicBlock<LlirNode, BitVector> > blk)
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;

    cfg = getControlFlowGraph();

    if(cfg->isPseudoEntryBB(blk))
      {
	//no need to compute live_at_begin for 
	//pseudo entry bb
	return;
      }

    shared_ptr<BitVector> liveAtEnd = blk->getRegsLiveOnExit();

    unsigned int numRegs = m_f->getNumRegs();
 
    shared_ptr<BitVector> currLiveAtBegin (new BitVector(numRegs));

    // initialize curret_live_at_begin
    // start with the live_at_end for the current blk

    currLiveAtBegin->copyBitSet(liveAtEnd);

    // iterate over all insns in the current block 
    // in the reverse order
    BasicBlock<LlirNode, BitVector>::InsnListRIterator iter = blk->InsnListRBegin();

    for(; iter != blk->InsnListREnd(); ++iter)
      {
	shared_ptr<LlirNode> node = *iter;

	if(node->isInsn())
	  {	    
	    // update dst reg UNUSED info on an "insn"
	    markDstRegLiveNess(node, currLiveAtBegin);
	    
	    // update live_at_begin with 'dst' opnd info.
	    //   for each insn identify all the regs set
	    //   and mark them as dead in "current_live_at_begin"
	    markSetRegsDead(currLiveAtBegin, node);

	    // update current_live_at_begin with call clobbered regs
	    if(node->isCallInsn())
	      {
		// call clobbered regs are
		// 1. global_regs and 
		// 2. every hard register which is not part of current fn scratch
		markCallClobberedRegsDead(currLiveAtBegin);
	      }

	    // update src reg DEAD info on an "insn"
	    markSrcRegLiveNess(node, currLiveAtBegin);

	    // update current_live_at_begin with 'src' opnd info.
	    //   for each insn identify all the regs used
	    //   and mark them live in "current_live_at_begin"
	    markUsedRegsLive(currLiveAtBegin, node);
	  }
      }

    // finally set the updated currLiveAtBegin as 
    // the final live_at_begin for the basic block
    blk->setRegsLiveOnEntry(currLiveAtBegin);
  }

  // check if the live_at_begin & live_at_end match
  // otherwise live_at_begin has changed, which forces
  // us to reexamine live_at_end of all its predecessors
  // this is done by adding the predecessors to basic block
  // queue if they are not already in there to be examined.

  void
  M480DataFlowAnalyzer::updateBasicBlockQueue()
  {
    shared_ptr<BasicBlockQueue> bbq = getBasicBlockQueue();
    shared_ptr<BasicBlock<LlirNode, BitVector> > blk = bbq->getFrontBB();
    shared_ptr<BitVector> liveAtBegin = blk->getRegsLiveOnEntry();
    shared_ptr<BitVector> liveAtEnd = blk->getRegsLiveOnExit();

    //remove the front bb as it is already processed

    if(! bbq->isEmpty())
      {
	bbq->removeFrontBB();
      }

    //now update bbq with predecessors of 'blk'

    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;
    cfg = getControlFlowGraph();

    if(*liveAtBegin != *liveAtEnd)
      {
	ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>::PredEdgeListIter iter;

	iter = cfg->getPredListBegin(blk);

	for(; iter != cfg->getPredListEnd(blk); iter++)
	  {
	    shared_ptr<BasicBlock<LlirNode, BitVector> > b = cfg->getSrcBlkAtPredEdge(iter);

	    bbq->addBasicBlock(b);
	  }
      }
  }

  // all registers which appear in the destination operands of insns
  // should marked as dead after that point and should be accordingly
  // notified in the live_at_begin of the basic block

  void
  M480DataFlowAnalyzer::markSetRegsDead(shared_ptr<BitVector> bv, shared_ptr<LlirNode> node)
  {
    shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);
    if(insn)
      {
	OctaveInstruction::RegOpndConstIterator opndIter = insn->beginSetRegList();
	for(; opndIter != insn->endSetRegList(); opndIter++)
	  {
	    shared_ptr<const Register> reg = shared_dynamic_cast<const Register>(*opndIter);
	    if(reg)
	      {
		bv->clearBit(reg->getRegNum());
	      }
	  }
      }
  }

  // all registers which appear in the source operands of insns
  // should be marked live.

  void
  M480DataFlowAnalyzer::markUsedRegsLive(shared_ptr<BitVector> bv, shared_ptr<LlirNode> node)
  {
    shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);
    
    if(insn)
      {
	OctaveInstruction::RegOpndConstIterator opndIter = insn->beginUsedRegList();
	for(; opndIter != insn->endUsedRegList(); opndIter++)
	  {
	    shared_ptr<const Register> reg = shared_dynamic_cast<const Register>(*opndIter);
	    if(reg)
	      {
		bv->setBit(reg->getRegNum());
	      }
	  }
      }
  }

  // all scratch registers and call_clobbered_registers 
  // get clobbered after a call and hence are not live any more
  // all regs except those in scratch list are considered clobbered

  void  
  M480DataFlowAnalyzer::markCallClobberedRegsDead(shared_ptr<BitVector> bv)
  {
    shared_ptr<AltEntryFunction> fn = getCurrentFunction();
    
    shared_ptr<const RegList> scratchList = fn->getScratchList()->getRegList();

    unsigned int regNum;

    for(regNum = 0; regNum < fn->getNumHardRegs(); regNum++)
      {
	if(! scratchList->isInList(regNum))
	  {
	    bv->clearBit(regNum);
	  }
      }
  }

  // all argument registers to the call insn should be marked live

  void
  M480DataFlowAnalyzer::markCallArgRegsLive(shared_ptr<BitVector> bv,
					    shared_ptr<LlirNode> node)
  {
    if(node->isCallInsn())
      {
	const char* name = getCalledFnName(node).c_str();
	
	shared_ptr<const PrototypeDirective> proto = searchForPrototype(node->getLineNum(), 
									node->getSrcFile().c_str(),
									name);
	
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	RegList::ConstIterator iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    bv->setBit(reg->getRegNum());
	  }
      }
  }

  // all result registers return my call insn are clobbered hence are marked dead

  void
  M480DataFlowAnalyzer::markCallReturnRegsDead(shared_ptr<BitVector> bv,
						 shared_ptr<LlirNode> node)
  {
    if(node->isCallInsn())
      {
	const char* name = getCalledFnName(node).c_str();
	
	shared_ptr<const PrototypeDirective> proto = searchForPrototype(node->getLineNum(), 
									node->getSrcFile().c_str(),
									name);
	
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	RegList::ConstIterator iter = resultList->begin();

	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    bv->clearBit(reg->getRegNum());
	  }
      }
  }

  // various call insns possible in M480
  // jbi, jbr, jbci, jbcr, jbcdi, jbcdr, jbzr, jbzi, jbnzr, jbnzi

  //FIXME : 
  //The instruction heirarchy and operand types in LLIR
  //has to be rearchitected in a way
  //to remove exploding number of dynamic casts.

  const string&
  M480DataFlowAnalyzer::getCalledFnName(shared_ptr<LlirNode> node)
  {
    shared_ptr<M480JbiInstruction> jbi = shared_dynamic_cast<M480JbiInstruction>(node);

    if(jbi)
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(jbi->getSrc1());
	
	if(l)
	  return l->getName();
      }

    shared_ptr<M480JbrInstruction> jbr = shared_dynamic_cast<M480JbrInstruction>(node);
    
    if(jbr)
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(jbr->getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	if(l)
	  return l->getName();
      }
    
    shared_ptr<M480JbciInstruction> jbci = shared_dynamic_cast<M480JbciInstruction>(node);

    if(jbci)
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(jbci->getSrc1());

	if(l)
	  return l->getName();
      }
    
    shared_ptr<M480JbcrInstruction> jbcr = shared_dynamic_cast<M480JbcrInstruction>(node);

    if(jbcr)
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(jbcr->getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	if(l)
	  return l->getName();
      }

    
    shared_ptr<M480JbcdiInstruction> jbcdi = shared_dynamic_cast<M480JbcdiInstruction>(node);

    if(jbcdi)
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(jbcdi->getSrc1());

	if(l)
	  return l->getName();
      }
    
    shared_ptr<M480JbcdrInstruction> jbcdr = shared_dynamic_cast<M480JbcdrInstruction>(node);

    if(jbcdr)
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(jbcdr->getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	if(l)
	  return l->getName();
      }

    shared_ptr<M480JbziInstruction> jbzi = shared_dynamic_cast<M480JbziInstruction>(node);
    
    if(jbzi)
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(jbzi->getSrc2());
	
	if(l)
	  return l->getName();
      }
    
    
    shared_ptr<M480JbzrInstruction> jbzr = shared_dynamic_cast<M480JbzrInstruction>(node);
    
    if(jbzr)
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(jbzr->getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));
	
	if(l)
	  return l->getName();
      }
    
    shared_ptr<M480JbnziInstruction> jbnzi = shared_dynamic_cast<M480JbnziInstruction>(node);
    
    if(jbnzi)
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(jbnzi->getSrc2());
	
	if(l)
	  return l->getName();
      }
    
    
    shared_ptr<M480JbnzrInstruction> jbnzr = shared_dynamic_cast<M480JbnzrInstruction>(node);
    
    if(jbnzr)
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(jbnzr->getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));
	
	if(l)
	  return l->getName();
      }

    //dummy return
    static string dummyStr("");
    return dummyStr;
    throw LLIR_INTERNAL_EXCEPTION("Unknown call insn found");

  }

  shared_ptr<const PrototypeDirective>
  M480DataFlowAnalyzer::searchForPrototype(unsigned int line,
					     const char* file,
					     const char* name)
  {
    std::map<string, shared_ptr<const PrototypeDirective> >::const_iterator iter;

    iter = g_prototypeDirList.find(name);

    if(iter != g_prototypeDirList.end())
      {
        return iter->second;
      }
    else
      {
        shared_ptr<std::exception> exc;

        char *excStr = new char[128];

        sprintf(excStr, "%s:%d: Valid prototype not found for Call label : %s", file, line, name);

        throw LLIR_INTERNAL_EXCEPTION(excStr);

        delete excStr;
      }
  }

  void
  M480DataFlowAnalyzer::markDstRegLiveNess(shared_ptr<LlirNode> node, shared_ptr<BitVector> bv)
  {
    shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);
    
    if(insn)
      {
	OctaveInstruction::RegOpndConstIterator iter;

	iter = insn->beginSetRegList();

	for(; iter != insn->endSetRegList(); iter++)
	  {
	    shared_ptr<const Register> reg = *iter;
	    
	    if(! bv->isBitSet(reg->getRegNum()))
	      {
		//the dst register is set in this insn
		//but subsequently unused, mark it as unused.
		
		insn->addUnusedRegister(reg);
	      }
	  }
      }
  }

  void
  M480DataFlowAnalyzer::markSrcRegLiveNess(shared_ptr<LlirNode> node, shared_ptr<BitVector> bv)
  {
    shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);
    
    if(insn)
      {
	OctaveInstruction::RegOpndConstIterator iter;

	iter = insn->beginUsedRegList();

	for(; iter != insn->endUsedRegList(); iter++)
	  {
	    shared_ptr<const Register> reg = *iter;
	    
	    if(! bv->isBitSet(reg->getRegNum()))
	      {
		//the dst register is used in this insn
		//but subsequently unused, mark it as daed.
		
		insn->addDeadRegister(reg);
	      }
	  }
      }
  }

  //////////////////////////
  // basic block queue class
  //////////////////////////

  BasicBlockQueue::BasicBlockQueue()
  {}

  BasicBlockQueue::~BasicBlockQueue()
  {}
  
  BasicBlockQueue::BasicBlockQueue(const BasicBlockQueue& rhs)
    : m_bbQueue(rhs.m_bbQueue)
  {}

  BasicBlockQueue& 
  BasicBlockQueue::operator=(const BasicBlockQueue& rhs)
  {
    if(this == &rhs)
      return *this;

    m_bbQueue = rhs.m_bbQueue;
    return *this;
  }

  BasicBlockQueue::BBQIterator 
  BasicBlockQueue::begin()
  {
    return m_bbQueue.begin();
  }
  
  
  BasicBlockQueue::BBQConstIterator 
  BasicBlockQueue::begin() const 
  {
    return m_bbQueue.begin();
  }
  

  BasicBlockQueue::BBQIterator 
  BasicBlockQueue::end()
  {
    return m_bbQueue.end();
  }
  
  BasicBlockQueue::BBQConstIterator 
  BasicBlockQueue::end() const
  {
    return m_bbQueue.end();
  }
  
  // add a basic block to the queue if it is
  // not already in there

  void
  BasicBlockQueue::addBasicBlock(shared_ptr<BasicBlock<LlirNode, BitVector> >  blk)
  {
    unsigned int idx = blk->getIndex();
    
    bool found = findBasicBlock(idx);

    if(!found)
      {
	m_bbQueue.push_front(blk);
      }
  }

  // find out if the basic block with index 'idx'
  // already exists in the queue to be examined

  bool
  BasicBlockQueue::findBasicBlock(unsigned int idx)
  {
    bool found = false;

    BasicBlockQueue::BBQIterator iter = begin();

    for(; iter != end(); iter++)
      {
	if((*iter)->getIndex() == idx)
	  {
	    found = true;
	    break;
	  }
      }

    return found;
  }

  bool
  BasicBlockQueue::isEmpty() const
  {
    return m_bbQueue.empty();
  }
  
  shared_ptr<BasicBlock<LlirNode, BitVector> > 
  BasicBlockQueue::getFrontBB()
  {
    if(! isEmpty())
      {
	return m_bbQueue.front();
      }
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("basic block queue is empty");
	//dummy return;
	return shared_ptr<BasicBlock<LlirNode, BitVector> > (new BasicBlock<LlirNode, BitVector>(0));
      }
  }
  
  void
  BasicBlockQueue::removeFrontBB()
  {
    m_bbQueue.pop_front();
  }

  
}
