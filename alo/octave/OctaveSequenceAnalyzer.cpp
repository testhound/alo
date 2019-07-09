#include "OctaveSequenceAnalyzer.h"

namespace Alo
{

  OctaveSequenceAnalyzer::OctaveSequenceAnalyzer(OctaveAlo& alo)
    : m_alo(alo)
  {}

  OctaveSequenceAnalyzer::~OctaveSequenceAnalyzer()
  {}

  OctaveSequenceAnalyzer::OctaveSequenceAnalyzer(const OctaveSequenceAnalyzer& rhs)
    : m_alo(rhs.m_alo),
      m_seqNode(rhs.m_seqNode)
  {}

  OctaveSequenceAnalyzer& 
  OctaveSequenceAnalyzer::operator=(const OctaveSequenceAnalyzer& rhs)
  {
    if(this == &rhs)
      return *this;

    m_alo = rhs.m_alo;
    m_seqNode = rhs.m_seqNode;

    return *this;
  }

  void
  OctaveSequenceAnalyzer::makeSequences(shared_ptr<LlirFile> file)
  {

    LlirFile::Iterator iter = file->begin();

    for(; iter != file->end(); iter++)
      {
	//file should contain implicit block only

	shared_ptr<LlirOctaveBlock> octBlk = shared_dynamic_cast<LlirOctaveBlock>(*iter);

	if(octBlk)
	  {
	    makeSequences(octBlk);
	  }
      }
  }


  void
  OctaveSequenceAnalyzer::makeSequences(shared_ptr<LlirOctaveBlock> block)
  {

    LlirNode::Iterator iter = block->begin();
    
    for(; iter != block->end(); iter++)
      {

	shared_ptr<LlirNode> node = *iter;

	shared_ptr<LlirOctaveBlock> child = shared_dynamic_cast<LlirOctaveBlock>(node);
	
	if(child)
	  {
	    makeSequences(child);
	  }
	else
	  {
	    shared_ptr<MvhOpInstruction> insn = shared_dynamic_cast<MvhOpInstruction>(node);
	    
	    if(insn)
	      {
		shared_ptr<const MvhFlag> flag = shared_dynamic_cast<const MvhFlag>(insn->getMvhFlag());

		if(flag)
		  {
		    unsigned int numSeqInsns = flag->getCNValue();
		    
		    if(numSeqInsns)
		      {
			makeSequences(block, node, numSeqInsns);
		      }
		  }
	      }
	  }
      }
  }


  /*
   * since it is not known in which block
   * the next insn could be found and this
   * routine needs that knowledge as it
   * has to continue finding the consecutive instructions
   * in that block
   *
   * ..hence the need for m_nextSequenceBlock, which is
   * updated by getNextInsn method wherever next insn
   * is found.
   */

  void
  OctaveSequenceAnalyzer::makeSequences(shared_ptr<LlirOctaveBlock> blk, 
					    shared_ptr<LlirNode> node, 
					    unsigned int numInsns)
  {

    m_seqNode = node;

    shared_ptr<LlirNode> nextNode = node;

    m_nextSequenceBlock = blk;

    bool foundSequenceInsns = true;

    shared_dynamic_cast<OctaveInstruction>(node)->setInInstructionSequence();
    for(unsigned int i=0; i < numInsns; i++)
      {
	nextNode  = getNextInsn(m_nextSequenceBlock, nextNode);

	
	if(! shared_dynamic_cast<NullInstruction>(nextNode))
	  {
	    shared_dynamic_cast<OctaveInstruction>(nextNode)->setInInstructionSequence();
	  }
	else
	  {
	    //could not find enough sequence insns...
	    foundSequenceInsns = false;
	    break;
	  }
      }
  }


  
  /*
   * This routine is little tricky,
   * the next sequential insn may not be in
   * the same block as that of current
   * insn. 
   */
  
  shared_ptr<OctaveInstruction> 
  OctaveSequenceAnalyzer::getNextInsn(shared_ptr<LlirOctaveBlock> blk, 
				     shared_ptr<LlirNode> node)
  {
    LlirNode::Iterator iter = blk->begin();

    shared_ptr<OctaveInstruction> insn;

    //search till you find the node
    //under consideration 
    //(whose next insn is to be found)

    while(iter++ != blk->end())
      {
	if(*iter == node)
	  {
	    break;
	  }
      }

    //increment *iter so that it 
    //points to next node
    ++iter;

    //this loop starts with a check to
    //see if there are still some nodes left to
    //be searched in 'blk'.

    while(iter != blk->end())
      {

	shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(*iter);

	// is instruction?
	if(insn)
	  {
	    return insn;
	  }

	// no! is block?
	shared_ptr<LlirOctaveBlock> block = shared_dynamic_cast<LlirOctaveBlock>(*iter);

	if(block)
	  {
	    
	    if(block->begin() != block->end())
	      {
	        //block is not empty...
		//so it is safe to access block->begin()

		//store the new block for a later search
		m_nextSequenceBlock = block;

		shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(*(block->begin()));
	    
		if(insn)
		  {
		    return insn;
		  }
		else
		  {
		    //this call basically starts a recursive search
		    //for all inner blocks in search of an insn...
		    return getNextInsn(block, *(block->begin()));
		  }
	      }
	  }

	// *iter is none of the above
	// must be some directive, so skip it,
	// and continue search.

	++iter;
      }


    //visited all inner blocks
    //reached end of current block
    //now visit parent blocks 
    
    if(iter == blk->end())
      {
	LlirOctaveBlock::ParentListIterator pIter = blk->getParent();
	
	shared_ptr<LlirOctaveBlock> parentBlk;
	
	if(pIter == blk->parentListEnd())
	  {

	    unsigned int excLine = m_seqNode->getSrcLineNum();
	    const string &excFile = m_seqNode->getSrcFile();

	    m_alo.logException(shared_ptr<IllegalDelaySlotInsn>(new IllegalDelaySlotInsn
								("Insufficient number of cN slots for mvh insn",
								 excLine,
								 excFile.c_str(), 
								 __LINE__, __FILE__)));

	    //to supress compiler warning...
	    return shared_ptr<NullInstruction>(new NullInstruction(0,0,"")); 
	  }
	else
	  {

	    parentBlk = pIter->second;
	    
	    //store the new block for a later search
	    m_nextSequenceBlock = parentBlk;
	    
	    return getNextInsn(parentBlk, blk);
	  }
      }
    else
      {
	//internal error
	//to supress compiler warning...
	return shared_ptr<NullInstruction>(new NullInstruction(0,0,"")); 
      }
  }



  void 
  OctaveSequenceAnalyzer::updateLlirNodeList(shared_ptr<OctaveInstruction> mvhInsn, 
					     std::vector<shared_ptr<OctaveInstruction> > cNInsns)
  {
    //FIXME:
    //code to be filled by Mike.
  }


  
}
















