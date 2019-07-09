#include "OctaveDelaySlotAnalyzer.h"

namespace Alo
{


  OctaveDelaySlotAnalyzer::OctaveDelaySlotAnalyzer(OctaveAlo& alo)
    : m_alo(alo)
  {}

  OctaveDelaySlotAnalyzer::~OctaveDelaySlotAnalyzer()
  {}

  OctaveDelaySlotAnalyzer::OctaveDelaySlotAnalyzer(const OctaveDelaySlotAnalyzer& rhs)
    : m_alo(rhs.m_alo),
      m_dslotNode(rhs.m_dslotNode)
  {}

  OctaveDelaySlotAnalyzer& 
  OctaveDelaySlotAnalyzer::operator=(const OctaveDelaySlotAnalyzer& rhs)
  {
    if(this == &rhs)
      return *this;

    m_alo = rhs.m_alo;
    m_dslotNode = rhs.m_dslotNode;
    return *this;
  }

  void
  OctaveDelaySlotAnalyzer::checkDelaySlots(shared_ptr<LlirFile> file)
  {

    LlirFile::Iterator iter = file->begin();

    for(; iter != file->end(); iter++)
      {
	//file should contain implicit block only

	shared_ptr<LlirOctaveBlock> octBlk = shared_dynamic_cast<LlirOctaveBlock>(*iter);

	if(octBlk)
	  {
	    checkDelaySlots(octBlk);
	  }
      }
  }


  void
  OctaveDelaySlotAnalyzer::checkDelaySlots(shared_ptr<LlirOctaveBlock> block)
  {

    LlirNode::Iterator iter = block->begin();
    
    for(; iter != block->end(); iter++)
      {

	shared_ptr<LlirNode> node = *iter;

	shared_ptr<LlirOctaveBlock> child = shared_dynamic_cast<LlirOctaveBlock>(node);
	
	if(child)
	  {
	    checkDelaySlots(child);
	  }
	else
	  {
	    shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);
	    
	    if(insn)
	      {
		if(! insn->isPseudoInsn())
		  {
		    unsigned int numSlots = insn->getNumDelaySlots();
		    
		    if(numSlots)
		      {
			checkDelaySlots(block, node, numSlots);
		      }
		  }
	      }
	  }
      }
  }


  /**
   * since it is not known in which block
   * the next insn could be found and this
   * routine needs that knowledge as it
   * has to find the consecutive instruction,
   * in that block
   * ..hence the need for m_nextDslotBlock, which is
   * set to by getNextInsn method.
   */

  void
  OctaveDelaySlotAnalyzer::checkDelaySlots(shared_ptr<LlirOctaveBlock> blk, 
					 shared_ptr<LlirNode> node, 
					 unsigned int numSlots)
  {

    m_dslotNode = node;

    std::vector<shared_ptr<OctaveInstruction> > dslotInsns(numSlots);

    shared_ptr<LlirNode> nextNode = node;

    m_nextDslotBlock = blk;

    bool foundDslotInsns = true;

    for(unsigned int i=0; i < numSlots; i++)
      {
	nextNode  = getNextInsn(m_nextDslotBlock, nextNode);

	
	if(! shared_dynamic_cast<NullInstruction>(nextNode))
	  {
	    dslotInsns[i] = shared_dynamic_cast<OctaveInstruction>(nextNode);
	  }
	else
	  {
	    //could not find enough dslots...
	    foundDslotInsns = false;
	    break;
	  }
      }


    shared_ptr<OctaveInstruction> insn = shared_dynamic_cast<OctaveInstruction>(node);

    if(foundDslotInsns)
      {
	checkDelaySlots(insn, dslotInsns);
      }
  }


  
  /**
   * This routine is little tricky,
   * the next sequential insn may not be in
   * the same block as that of current
   * insn. 
   */
  
  shared_ptr<OctaveInstruction> 
  OctaveDelaySlotAnalyzer::getNextInsn(shared_ptr<LlirOctaveBlock> blk, 
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
    //see if there still some nodes left to
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
		m_nextDslotBlock = block;

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

	// *iter is not an 
	//   insn, or 
	//   non-empty block or 
	//   end of the current block,
	// must be some directive, so skip it 
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

	    unsigned int excLine = m_dslotNode->getSrcLineNum();
	    const string &excFile = m_dslotNode->getSrcFile();

	    m_alo.logException(shared_ptr<IllegalDelaySlotInsn>(new IllegalDelaySlotInsn
								("Insufficient number of delay slots",
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
	    m_nextDslotBlock = parentBlk;
	    
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
  OctaveDelaySlotAnalyzer::checkDelaySlots(shared_ptr<OctaveInstruction> insn, std::vector<shared_ptr<OctaveInstruction> > delayInsns)
  {
    std::exception exc;

    // abc insns have 3 delay slots
    // - first two slots cannot be anytype of 
    //   branches including abc insns
    // - third slot can be a branch insn but 
    //   cannot be another abc insn

    if(insn->isAbcInsn())
      {

	if(! delayInsns[0]->isValidDslotInsn())
	  {

	    unsigned int excLine = m_dslotNode->getSrcLineNum();
	    const string &excFile = m_dslotNode->getSrcFile();

	    char *excStr = new char[127];
	    sprintf(excStr, "Illegal Delay Slot Insn found on line %d", delayInsns[0]->getSrcLineNum());
	    m_alo.logException(shared_ptr<IllegalDelaySlotInsn>(new IllegalDelaySlotInsn
								(excStr,
								 excLine,
								 excFile.c_str(), 
								 __LINE__, __FILE__)));
	    delete excStr;
	  }

	if(! delayInsns[1]->isValidDslotInsn())
	  {

	    unsigned int excLine = m_dslotNode->getSrcLineNum();
	    const string &excFile = m_dslotNode->getSrcFile();

	    char *excStr = new char[127];
	    sprintf(excStr, "Illegal Delay Slot Insn found on line %d", delayInsns[1]->getSrcLineNum());
	    m_alo.logException(shared_ptr<IllegalDelaySlotInsn>(new IllegalDelaySlotInsn
								(excStr,
								 excLine,
								 excFile.c_str(), 
								 __LINE__, __FILE__)));
	    delete excStr;

	  }

	if(delayInsns[2]->isAbcInsn())
	  {

	    unsigned int excLine = m_dslotNode->getSrcLineNum();
	    const string &excFile = m_dslotNode->getSrcFile();

	    char *excStr = new char[127];
	    sprintf(excStr, "Illegal Delay Slot Insn found on line %d", delayInsns[2]->getSrcLineNum());
	    m_alo.logException(shared_ptr<IllegalDelaySlotInsn>(new IllegalDelaySlotInsn
								(excStr,
								 excLine,
								 excFile.c_str(), 
								 __LINE__, __FILE__)));
	    delete excStr;
	  }
      }
    else if(insn->isBranchInsn() &&
	    (! insn->isAbcInsn()))
      {
	// if 'insn' is a branch insn with a valid
	// branch target and if it is not a abc insn
	// then none of its delay slots should be
	// be another branch insn or an abc insn

	for(unsigned int i=0; i < insn->getNumDelaySlots(); i++)
	  {
	    if(! delayInsns[i]->isValidDslotInsn())
	      {

		unsigned int excLine = m_dslotNode->getSrcLineNum();
		const string &excFile = m_dslotNode->getSrcFile();

		char *excStr = new char[127];
		sprintf(excStr, "Illegal Delay Slot Insn found on line %d", delayInsns[i]->getSrcLineNum());
		m_alo.logException(shared_ptr<IllegalDelaySlotInsn>(new IllegalDelaySlotInsn
								    (excStr,
								     excLine,
								     excFile.c_str(), 
								     __LINE__, __FILE__)));
		delete excStr;
	      }
	  }
	
      }
    
  }


  
}
