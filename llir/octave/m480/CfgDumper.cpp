#include <sstream>
#include <ostream>
#include <fstream>
using namespace std;

#include "CfgDumper.h"
#include <OctaveInstructions.h>

namespace Llir
{
  M480CfgDfInfoDumper::M480CfgDfInfoDumper(ostream& os,
		    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg)
    : m_os(os),
      m_cfg(cfg)
  {}
 
  M480CfgDfInfoDumper::~M480CfgDfInfoDumper()
  {}

  M480CfgDfInfoDumper::M480CfgDfInfoDumper(const M480CfgDfInfoDumper& rhs)
    : m_os(rhs.m_os),
      m_cfg(rhs.m_cfg)
  {}

  ostream&
  M480CfgDfInfoDumper::getOutputStream() const
  {
    return m_os;
  }
  
  shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> >
  M480CfgDfInfoDumper::getControlFlowGraph() const
  {
    return m_cfg;
  }

  void
  M480CfgDfInfoDumper::printControlAndDataFlowInfo()
  {
    printGeneralInfo();
    printBasicBlockInfo();
  }

  void
  M480CfgDfInfoDumper::printGeneralInfo()
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;
    cfg = getControlFlowGraph();

    getOutputStream() << "=======================================================" << endl;
    getOutputStream() << " *** CFG and DFA Info *** " << endl << endl;
    getOutputStream() << "=======================================================" << endl;
    getOutputStream() << "Function         : "        << cfg->getName() << endl;
    getOutputStream() << "=======================================================" << endl;
    getOutputStream() << "ENTRY            : BB" << cfg->getPseudoEntryBB()->getIndex() << " Function pseudo entry" << endl;
    getOutputStream() << "EXIT             : BB" << cfg->getPseudoExitBB()->getIndex() << " Function pseudo exit" << endl;
    getOutputStream() << "# of BasicBlocks : "   << cfg->getNumVertices() << endl;
    getOutputStream() << "# of Edges       : "   << cfg->getNumEdges() << endl;
    getOutputStream() << "=======================================================" << endl;

    getOutputStream() << endl;
  }

  void
  M480CfgDfInfoDumper::printBasicBlockInfo()
  {
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;
    cfg = getControlFlowGraph();

    ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>::BasicBlockIterator bbIter;

    bbIter = cfg->basicBlockListBegin();

    for(; bbIter != cfg->basicBlockListEnd(); bbIter++)
      {
	shared_ptr<BasicBlock<LlirNode, BitVector> > bb = cfg->getBasicBlock(bbIter);

	getOutputStream() << "=======================================================" << endl;
	printBasicBlockInfo(bb);
	getOutputStream() << "=======================================================" << endl;
      }
  }

  void
  M480CfgDfInfoDumper::printBasicBlockInfo(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    shared_ptr<BitVector> liveOnEntry = bb->getRegsLiveOnEntry();
    shared_ptr<BitVector> liveOnExit = bb->getRegsLiveOnExit();

    getOutputStream() << "Basic Block        : BB" << bb->getIndex() << endl;

    printPredList(bb);
    getOutputStream() << endl;

    printSuccList(bb);
    getOutputStream() << endl;

    printRegsLiveOnEntry(liveOnEntry);
    getOutputStream() << endl;

    printRegsLiveOnExit(liveOnExit);
    getOutputStream() << endl;

    getOutputStream() << endl;
    printBasicBlockInsnList(bb);
    getOutputStream() << endl;
  }

  void
  M480CfgDfInfoDumper::printRegsLiveOnEntry(shared_ptr<BitVector> bv)
  {
    getOutputStream() << "Live Regs On Entry : ";
    printBitVector(bv);
  }
  

  void
  M480CfgDfInfoDumper::printRegsLiveOnExit(shared_ptr<BitVector> bv)
  {
    getOutputStream() << "Live Regs On Exit  : ";
    printBitVector(bv);
  }

  void
  M480CfgDfInfoDumper::printPredList(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    getOutputStream() << "Predecessor List   : ";
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;
    
    cfg = getControlFlowGraph();
      
    ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>::PredEdgeListIter iter;

    iter = cfg->getPredListBegin(bb);

    for(; iter != cfg->getPredListEnd(bb); iter++)
      {
	shared_ptr<BasicBlock<LlirNode, BitVector> > pbb = cfg->getSrcBlkAtPredEdge(iter);
	getOutputStream() << "BB" << pbb->getIndex() << " ";
      }
  }
  
  void
  M480CfgDfInfoDumper::printSuccList(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    getOutputStream() << "Successor List     : ";
    shared_ptr<ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge> > cfg;
    
    cfg = getControlFlowGraph();
      
    ControlFlowGraph<BasicBlock<LlirNode, BitVector>, Edge>::SuccEdgeListIter iter;

    iter = cfg->getSuccListBegin(bb);

    for(; iter != cfg->getSuccListEnd(bb); iter++)
      {
	shared_ptr<BasicBlock<LlirNode, BitVector> > sbb = cfg->getDstBlkAtSuccEdge(iter);
	getOutputStream() << "BB" << sbb->getIndex() << " ";
      }
  }

  void
  M480CfgDfInfoDumper::printBitVector(shared_ptr<BitVector> bv)
  {
    unsigned int sz = bv->getSize();
    unsigned int i;

    for(i=0; i < sz; i++)
      {
	if(bv->isBitSet(i))
	  {
	    getOutputStream() << i << " ";
	  }
      }
  }

  void
  M480CfgDfInfoDumper::printBasicBlockInsnList(shared_ptr<BasicBlock<LlirNode, BitVector> > bb)
  {
    ostringstream strStream;

    M480PrintVisitor mpv(strStream);

    BasicBlock<LlirNode, BitVector>::InsnListIterator iter = bb->InsnListBegin();

    for(; iter != bb->InsnListEnd(); iter++)
      {
	shared_ptr<LlirNode> node = *iter;
	node->accept(mpv);

	if(node->isInsn())
	  {
	    printUnusedRegInfo(node, strStream);
	    printDeadRegInfo(node, strStream);
	  }

	strStream << endl;

      }

    getOutputStream() << strStream.str();
    getOutputStream() << endl;
  }

  void 
  M480CfgDfInfoDumper::printUnusedRegInfo(shared_ptr<LlirNode> node, ostream& outStream)
  {
    if(node->isInsn())
      {
	shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);

	if(insn)
	  {
	    if(! insn->isUnusedRegListEmpty())
	      {
		outStream << "\t\t\t{ Unused Registers : ";

		OctaveInstruction::RegOpndConstIterator iter = insn->beginUnusedRegList();
		for(; iter != insn->endUnusedRegList(); iter++)
		  {
		    shared_ptr<const Register> reg = *iter;
		    outStream << reg->getRegNum() << " ";
		  }

		outStream << " }";
	      }
	    else
	      {
		outStream << "\t\t\t";
	      }
	  }
      }
  }


  void 
  M480CfgDfInfoDumper::printDeadRegInfo(shared_ptr<LlirNode> node, ostream& outStream)
  {
    if(node->isInsn())
      {
	shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);

	if(insn)
	  {
	    if(! insn->isDeadRegListEmpty())
	      {
		outStream << "{ Dead Registers : ";
		
		OctaveInstruction::RegOpndConstIterator iter = insn->beginDeadRegList();
		for(; iter != insn->endDeadRegList(); iter++)
		  {
		    shared_ptr<const Register> reg = *iter;
		    outStream << reg->getRegNum() << " ";
		  }
		
		outStream << " }";
	      }
	  }
      }
  }
}
