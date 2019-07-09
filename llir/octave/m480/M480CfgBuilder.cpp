#include <LlirNode.h>
#include <LlirException.h>
#include "M480CfgBuilder.h"
#include "M480Instructions.h"
#include <iostream>

namespace Llir
{

  M480CFGBuilder::M480CFGBuilder(shared_ptr<AltEntryFunction> f)
    : OctaveCFGBuilder(f),
      m_cfg(new ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>(f->getName().c_str()))
  {}

  M480CFGBuilder::~M480CFGBuilder() 
  {}

  M480CFGBuilder& 
  M480CFGBuilder::operator=(const M480CFGBuilder& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveCFGBuilder::operator=(rhs);
    m_cfg = rhs.m_cfg;

    return *this;
  }

  M480CFGBuilder::M480CFGBuilder(const M480CFGBuilder& rhs)
    : OctaveCFGBuilder(rhs),
      m_cfg(rhs.m_cfg)
  {}

  //public interface functions

  void 
  M480CFGBuilder::buildFlowGraph()
  {
    identifyValidLlirNodes();

    findBasicBlocks();

    makeEdges();
  }

  shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> >
  M480CFGBuilder::getControlFlowGraph()
  {
    return m_cfg;
  }

  //private helper functions

  void
  M480CFGBuilder::findBasicBlocks()
  {
    shared_ptr<AltEntryFunction> f;
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;

    f = getCurrentFunction();
    cfg = getControlFlowGraph(); 

    shared_ptr<BasicBlock<LlirNode, BitVector> > entryBB;
    shared_ptr<BasicBlock<LlirNode, BitVector> > exitBB;
    shared_ptr<BasicBlock<LlirNode, BitVector> > currentBB;


    //always create pseudo entry basic block
    entryBB = cfg->createBasicBlock(); //bb0
    cfg->addBasicBlock(entryBB);

    currentBB = cfg->createBasicBlock();
    cfg->addBasicBlock(currentBB);

    // loop untill the nodeList is empty
    InsnListIterator iter = insnListBegin();
    for(; iter != insnListEnd(); iter++)
      {

	shared_ptr<LlirNode> node = *iter;

	bool isJtableHdrLabel = false;
	if(node->isLabel())
	  {
	    //make sure next next node is not
	    //a .jtablebegin directive to
	    //assert that the current node 
	    //is a pure code label

	    InsnListIterator nextIter;
	    nextIter = ++iter; //iter+1;
	    
	    if(nextIter != insnListEnd())
	      {
		if(isJtableBegin(*nextIter))
		  isJtableHdrLabel = true;
	      }

	    --iter;
	  }

	
	//code label terminates the current bb 
	//and creates a new bb

	if(node->isLabel() && ! isJtableHdrLabel)
	  {
	    if(!currentBB->isEmpty())
	      {
		currentBB = cfg->createBasicBlock();
		cfg->addBasicBlock(currentBB);
	      }
	  }

	//add the node to current bb

	if((node->isLabel() && ! isJtableHdrLabel) ||
	   node->isInsn())
	  {
	    currentBB->addNode(node);
	  }

	//branch insn terminates the current bb 
	//and creates a new bb

 	if(node->isBranchInsn() && ! node->isCallInsn())
 	  {
	    //Note: calls are not treated as 
	    //branches for CFG construction

	    if(! isLastNode(node))
	      {
		//still have more insns
		currentBB = cfg->createBasicBlock();
		cfg->addBasicBlock(currentBB);
	      }
 	  }
      }

    //always create pseudo exit basic block
    exitBB = cfg->createBasicBlock(); //bbN-1
    cfg->addBasicBlock(exitBB);
  }

  void
  M480CFGBuilder::makeEdges()
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;
    cfg = getControlFlowGraph(); 

    shared_ptr<AltEntryFunction> f;
    f = getCurrentFunction();

    shared_ptr<BasicBlock<LlirNode, BitVector> > entryBB;
    shared_ptr<BasicBlock<LlirNode, BitVector> > exitBB;
    shared_ptr<BasicBlock<LlirNode, BitVector> > currentBB;

    entryBB = cfg->getPseudoEntryBB();
    exitBB = cfg->getPseudoExitBB();

    BBIterator iter = m_cfg->basicBlockListBegin();
    BBIterator end = m_cfg->basicBlockListEnd();

    //skip empty pseudo entry bb
    ++iter;
    //skip empty pseudo exit bb
    --end;

    for(; iter != end; iter++)
      {
	currentBB = cfg->getBasicBlock(iter);

	shared_ptr<LlirNode> head = currentBB->getHead();
	shared_ptr<LlirNode> end = currentBB->getEnd();

	if(isEntryPointLabel(f, head))
	  {
	    //add fall through edge from entryBB
	    shared_ptr<Edge> e = m_cfg->createEdge(Edge::FALLTHROUGH);
	    m_cfg->addEdge(entryBB, currentBB, e);
	  }

	if(isTableBranchInsn(end))
	  {
	    //add multiple branch edges
	    addJumpTableEdges(currentBB);
	  }
	   
	else if(isIndirectJumpInsn(end))
	  {
	    //we do not handle these branches
	  }

	else if(end->isReturnInsn())
	  {
	    //add fall through to the exitBB
	    shared_ptr<Edge> e = m_cfg->createEdge(Edge::FALLTHROUGH);
	    m_cfg->addEdge(currentBB, exitBB, e);
	  }

	else if(isUnConditionalJump(end))
	  {
	    //add branch edge
	    addBranchEdge(currentBB);
	  }
	
	else if(isConditionalJump(end))
	  {
	    //add two edges, fall through and branch
	    addConditionalBranchEdges(currentBB);
	  }

	else if(isLastNode(end))
	  {
	    //last node falls through to the exitBB
	    shared_ptr<Edge> e = m_cfg->createEdge(Edge::FALLTHROUGH);
	    cfg->addEdge(currentBB, exitBB, e);
	  }
	else
	  {
	    //add fall through edge to next basic block
	    addFallThroughEdge(currentBB);
	  }
      }
  }

  void
  M480CFGBuilder::addJumpTableEdges(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    shared_ptr<LlirNode> end = bb->getEnd();

    shared_ptr<M480JtablebrInstruction> jtablebr = shared_dynamic_cast<M480JtablebrInstruction>(end);

    shared_ptr<const LlirOperand> dst;

    if(jtablebr)
      {
	dst = jtablebr->getDst();
      }

    shared_ptr<M480JtableRelativebrInstruction> jtablerbr = shared_dynamic_cast<M480JtableRelativebrInstruction>(end);

    if(jtablerbr)
      {
	dst = jtablerbr->getDst();
      }

    if(jtablebr || jtablerbr)
      {
	shared_ptr<const OpndLabel> label = shared_dynamic_cast<const OpndLabel>(dst);

	if(label)
	  {
	    const char* name = label->getMangledName().c_str();

	    shared_ptr<LlirNode> jtb = getJtableBeginDirective(name);

	    addJumpTableEdges(bb, jtb); 
	  }
	
	return;
      }
    
    throw LLIR_INTERNAL_EXCEPTION("Basic block does not end with jtablebr Instruction");
  }

  shared_ptr<LlirNode> 
  M480CFGBuilder::getJtableBeginDirective(const char* name)
  {
    //get .jtablebegin directive node which is 
    //next to the label with name 'name'

    bool found = false;
    InsnListIterator iter = insnListBegin();
    for(; iter != insnListEnd(); iter++)
      {
	shared_ptr<LlirNode> node = *iter;

	if(node->isLabel())
	  {
	    shared_ptr<Label> label = shared_dynamic_cast<Label>(node);
	    
	    if(label)
	      {
		if(label->getMangledName() == name)
		  {
		    found = true;
		    break;
		  }
	      }
	  }
      }

    if(found)
      {
	shared_ptr<LlirNode> next = *(++iter);

	if(isJtableBegin(next))
	   return next;
      }

    char *excStr = new char[128];
    sprintf(excStr, "Could not find matching Jtablebegin header label : %s", name);
    throw LLIR_INTERNAL_EXCEPTION(excStr);
    delete excStr;

    //dummy return
    return shared_ptr<LlirNode>(new NullNode());
  }


  void
  M480CFGBuilder::addJumpTableEdges(shared_ptr<BasicBlock<LlirNode, BitVector> > bb, shared_ptr<LlirNode> node)
  {
    shared_ptr<JtableBegin> jtb = shared_dynamic_cast<JtableBegin>(node);

    LabelList::Iterator iter;

    shared_ptr<LabelList> labelList;

    if(jtb)
      {
	labelList = jtb->getLabelList();
	
	iter = labelList->begin();
      }


    shared_ptr<JtableRelativeBegin> jtrb = shared_dynamic_cast<JtableRelativeBegin>(node);
    
    if(jtrb)
      {
	labelList = jtrb->getLabelList();
	
	iter = labelList->begin();
	
	++iter; //skip the first anchor label.
      }

    if(jtb || jtrb)
      {
	for(; iter != labelList->end(); iter++)
	  {
	    const char* name = (*iter)->getMangledName().c_str();
	    
	    shared_ptr<BasicBlock<LlirNode, BitVector> > tgtBB = getTargetBasicBlock(name);
	    
	    shared_ptr<Edge> e = m_cfg->createEdge(Edge::BRANCH);
	    
	    m_cfg->addEdge(bb, tgtBB, e);
	  }
      }
  }
  
  shared_ptr<BasicBlock<LlirNode, BitVector> >
  M480CFGBuilder::getTargetBasicBlock(const char* name)
  {
    BBIterator begin = m_cfg->basicBlockListBegin();
    BBIterator end = m_cfg->basicBlockListEnd();

    //skip searching empty entry pseudo bb
    ++begin;
    //skip searching empty exit pseudo bb
    --end;

    //iterate over rest of basic blocks
    for(; begin != end; begin++)
      {
	shared_ptr<BasicBlock<LlirNode, BitVector> > bb = m_cfg->getBasicBlock(begin);

	shared_ptr<LlirNode> n = bb->getHead();

	if(n->isLabel())
	  {
	    shared_ptr<Label> l = shared_dynamic_cast<Label>(n);
	  
	    if(l)
	      {
		if(l->getMangledName() == name)
		  return bb;
	      }
	  }
      }
      
    char *excStr = new char[128];
    sprintf(excStr, "Could not find Basic Block Beginning with label : %s", name);
    throw LLIR_INTERNAL_EXCEPTION(excStr);
    delete excStr;

    //return dummy
    return shared_ptr<BasicBlock<LlirNode, BitVector> >(new BasicBlock<LlirNode, BitVector>(0));
  }
  
  shared_ptr<BasicBlock<LlirNode, BitVector> >
  M480CFGBuilder::getNextBasicBlock(shared_ptr<BasicBlock<LlirNode, BitVector> > blk)
  {
    unsigned int idx = blk->getIndex();
    
    return m_cfg->getBasicBlock(idx+1);
  }

  //add branch edge to tgt bb of 'bb'
  void
  M480CFGBuilder::addBranchEdge(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    shared_ptr<LlirNode> end = bb->getEnd();

    shared_ptr<const OpndLabel> label = getBranchLabel(end);
	
    const char *name = label->getMangledName().c_str();
    
    shared_ptr<BasicBlock<LlirNode, BitVector> > tgtBB = getTargetBasicBlock(name);

    shared_ptr<Edge> e = m_cfg->createEdge(Edge::BRANCH);

    m_cfg->addEdge(bb, tgtBB, e);
  }

  //add fall through edge to next bb of 'bb'
  void
  M480CFGBuilder::addFallThroughEdge(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {    
    shared_ptr<BasicBlock<LlirNode, BitVector> > next = getNextBasicBlock(bb);

    shared_ptr<Edge> ft = m_cfg->createEdge(Edge::BRANCH);

    m_cfg->addEdge(bb, next, ft);
  }

  void
  M480CFGBuilder::addConditionalBranchEdges(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    addBranchEdge(bb);

    addFallThroughEdge(bb);
  }


  shared_ptr<const OpndLabel>
  M480CFGBuilder::getBranchLabel(shared_ptr<LlirNode> end)
  {
    shared_ptr<const LlirOperand> opnd;

    shared_ptr<M480BiInstruction> bi =  shared_dynamic_cast<M480BiInstruction>(end);

    if(bi)
      opnd = bi->getSrc1();

    shared_ptr<M480JbiInstruction> jbi =  shared_dynamic_cast<M480JbiInstruction>(end);

    if(jbi)
      opnd = jbi->getSrc1();

    shared_ptr<CondBranchImmedInstruction> cbi = shared_dynamic_cast<CondBranchImmedInstruction>(end);

    if(cbi)
      opnd =cbi->getSrc1();

    shared_ptr<ZeroBranchImmedInstruction> zbi = shared_dynamic_cast<ZeroBranchImmedInstruction>(end);

    if(zbi)
      opnd = zbi->getSrc2();

    shared_ptr<Alu2OpBranchInstruction> alu2opbr = shared_dynamic_cast<Alu2OpBranchInstruction>(end);

    if(alu2opbr)
      opnd = alu2opbr->getBranchTarget();

    shared_ptr<TestBitBranchInstruction> tbbr = shared_dynamic_cast<TestBitBranchInstruction>(end);

    if(tbbr)
      opnd = tbbr->getDisp();

    shared_ptr<CompareOpBranchInstruction> cmpbr = shared_dynamic_cast<CompareOpBranchInstruction>(end);

    if(cmpbr)
      opnd = cmpbr->getBranchTarget();

    shared_ptr<const OpndLabel> label = shared_dynamic_cast<const OpndLabel>(opnd);

    if(label)
      return label;
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("Could not find branch target label"); 
	//dummy return
	return label;
      }
  }
  

  bool
  M480CFGBuilder::isTableBranchInsn(shared_ptr<LlirNode> end) const
  {
    if(end->isCallInsn())
      return false;

    shared_ptr<M480JtablebrInstruction> jtablebr = shared_dynamic_cast<M480JtablebrInstruction>(end);

    if(jtablebr)
      return true;

    shared_ptr<M480JtableRelativebrInstruction> jtablerbr = shared_dynamic_cast<M480JtableRelativebrInstruction>(end);

    if(jtablerbr)
      return true;

    return false;
  }

  bool
  M480CFGBuilder::isIndirectJumpInsn(shared_ptr<LlirNode> end) const
  {
    if(end->isCallInsn())
      return false;

    shared_ptr<M480JbrInstruction> jbr = shared_dynamic_cast<M480JbrInstruction>(end);

    if(jbr)
      return true;

    return false;
  }

  bool
  M480CFGBuilder::isUnConditionalJump(shared_ptr<LlirNode> end) const
  {
    if(end->isCallInsn())
      return false;

    // only one kind of unconditional jump possible

    shared_ptr<M480JbiInstruction> jbi = shared_dynamic_cast<M480JbiInstruction>(end);

    if(jbi)
      return true;

    return false;
  }

  bool
  M480CFGBuilder::isConditionalJump(shared_ptr<LlirNode> end) const
  {
    if(end->isCallInsn())
      return false;

    shared_ptr<CondBranchImmedInstruction> cbri = shared_dynamic_cast<CondBranchImmedInstruction>(end);
    shared_ptr<ZeroBranchImmedInstruction> zbri = shared_dynamic_cast<ZeroBranchImmedInstruction>(end);
    shared_ptr<TestBitBranchInstruction> tbbri = shared_dynamic_cast<TestBitBranchInstruction>(end);
    shared_ptr<CompareOpBranchInstruction> cmpbr = shared_dynamic_cast<CompareOpBranchInstruction>(end);
    shared_ptr<Alu2OpBranchInstruction> alu2opbr = shared_dynamic_cast<Alu2OpBranchInstruction>(end);

    if(cbri || zbri || tbbri || cmpbr || alu2opbr)
      return true;

    return false;
  }




}
