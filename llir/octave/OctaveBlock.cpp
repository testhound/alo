#include <list>
#include <map>
#include <iostream>
using namespace std;

#include <LlirVisitor.h>
#include <LlirException.h>

#include "OctaveNode.h"
#include "OctaveVisitor.h"
#include "OctaveOperand.h"

#include <boost/shared_ptr.hpp>
using namespace boost;

namespace Llir 
{



  

  //static vars
  unsigned int LlirBlock<OctaveSymbol>::m_currentBlkId=0;
  std::map<unsigned int, shared_ptr<LlirOctaveBlock> > LlirOctaveBlock::m_parentList;

  //--------------------------------
  //LlirOctaveBlock class
  //--------------------------------

  LlirOctaveBlock::LlirOctaveBlock(const char *name, 
				   unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName) 
    : LlirBlock<OctaveSymbol>(name, 
			      lineNum,
			      srcLineNum,
			      srcFileName)
  {}

  LlirOctaveBlock::LlirOctaveBlock(const LlirOctaveBlock& rhs) 
    : LlirBlock<OctaveSymbol>(rhs),
    m_nodeList(rhs.m_nodeList),
    m_opndLabelList(rhs.m_opndLabelList),
    m_symTable(rhs.m_symTable)
  {}

  LlirOctaveBlock& 
  LlirOctaveBlock::operator=(const LlirOctaveBlock& rhs)
  {
    if (this == &rhs)
      return *this;

    LlirBlock<OctaveSymbol>::operator=(rhs);

    m_nodeList = rhs.m_nodeList;
    m_opndLabelList = rhs.m_opndLabelList;
    m_symTable = rhs.m_symTable;

    return *this;
  }

  LlirOctaveBlock::ParentListIterator
  LlirOctaveBlock::getParentList(unsigned int blkId)
  {
    return m_parentList.find(blkId);
  }

  void
  LlirOctaveBlock::setParentList(unsigned int blkId, shared_ptr<LlirOctaveBlock> parent)
  {
    if(m_parentList.find(blkId) == m_parentList.end())
      { 
	m_parentList[blkId] = parent;
      }
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("Parent Already set for the child Node");
      }
  }

  LlirOctaveBlock::ParentListIterator
  LlirOctaveBlock::parentListBegin()
  {
    return m_parentList.begin();
  }

  LlirOctaveBlock::ParentListIterator
  LlirOctaveBlock::parentListEnd()
  {
    return m_parentList.end();
  }

  LlirOctaveBlock::ParentListConstIterator
  LlirOctaveBlock::parentListBegin() const
  {
    return m_parentList.begin();
  }

  LlirOctaveBlock::ParentListConstIterator
  LlirOctaveBlock::parentListEnd() const
  {
    return m_parentList.end();
  }

  void
  LlirOctaveBlock::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    //add child
    m_nodeList.push_back(child);

    shared_ptr<LlirOctaveBlock> parentBlk = shared_dynamic_cast< LlirOctaveBlock >(parent);

    if(!parentBlk)
      {
	throw LLIR_INTERNAL_EXCEPTION("adding nodes to a non-block");
      }

    shared_ptr<LlirOctaveBlock> childBlk = shared_dynamic_cast< LlirOctaveBlock >(child);

    //if child node is a block node
    if(childBlk)
      {
	setParent(parentBlk, childBlk);

	return;
      }
    
    shared_ptr<MultipleEntryEvh> childEvh = shared_dynamic_cast< MultipleEntryEvh >(child);

    //if child node is an evh node
    if(childEvh)
      {
	childBlk = childEvh->getImplicitBlock();

	setParent(parentBlk, childBlk);

	return;

      }
	
    shared_ptr<MultipleEntryFunction> childFun = shared_dynamic_cast< MultipleEntryFunction >(child);
	
    //if child node is a entry node
    if(childFun)
      {
	childBlk = childFun->getImplicitBlock();

	setParent(parentBlk, childBlk);

	return;
      }


    shared_ptr<Label> label = shared_dynamic_cast<Label>(child);

  }

  void
  LlirOctaveBlock::setParent(shared_ptr<LlirOctaveBlock> parentBlk, 
			     shared_ptr<LlirOctaveBlock> childBlk)
  {
    //update the parent list
    
    unsigned int blkId = childBlk->getBlkId();
    
    if(getParentList(blkId) == parentListEnd())
      {
	setParentList(blkId, parentBlk);
      }
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("Parent Already set for the child Node");
      }
  }

  void 
  LlirOctaveBlock::addSymbol(shared_ptr<OctaveSymbol> sym)
  {
    m_symTable.addSymbol(sym);
  }

  void 
  LlirOctaveBlock::removeSymbol(shared_ptr<OctaveSymbol> sym)
  {
    m_symTable.removeSymbol(sym);
  }

  SymbolTable<OctaveSymbol>::Iterator
  LlirOctaveBlock::lookupSymbol(const char* name)
  {
    return m_symTable.lookupSymbol(name);
  }

  SymbolTable<OctaveSymbol>::ConstIterator
  LlirOctaveBlock::lookupSymbol(const char* name) const
  {
    return m_symTable.lookupSymbol(name);
  }

  LlirNode::Iterator 
  LlirOctaveBlock::begin()
  {
    return LlirNode::Iterator(new LlirOctaveBlockIterator(m_nodeList.begin()));
  }

  LlirNode::Iterator 
  LlirOctaveBlock::end()
  {
    return LlirNode::Iterator(new LlirOctaveBlockIterator(m_nodeList.end()));
  }

  LlirNode::ConstIterator 
  LlirOctaveBlock::begin() const
  {
    return LlirNode::ConstIterator(new LlirOctaveBlockConstIterator(m_nodeList.begin()));
  }

  LlirNode::ConstIterator 
  LlirOctaveBlock::end() const
  {
    return LlirNode::ConstIterator(new LlirOctaveBlockConstIterator(m_nodeList.end()));
  }

  SymbolTable<OctaveSymbol>::Iterator 
  LlirOctaveBlock::symTableBegin()
  {
    return m_symTable.begin();
  }

  SymbolTable<OctaveSymbol>::Iterator 
  LlirOctaveBlock::symTableEnd()
  {
    return m_symTable.end();
  }

  SymbolTable<OctaveSymbol>::ConstIterator 
  LlirOctaveBlock::symTableBegin() const
  {
    return m_symTable.begin();
  }

  SymbolTable<OctaveSymbol>::ConstIterator 
  LlirOctaveBlock::symTableEnd() const
  {
    return m_symTable.end();
  }

  void 
  LlirOctaveBlock::storeLabelOpnd(shared_ptr<OpndLabel> label)
  {
    m_opndLabelList.push_back(label);
  }

  LlirOctaveBlock::FixupListIterator
  LlirOctaveBlock::fixupListBegin()
  {
    return m_opndLabelList.begin();
  }

  LlirOctaveBlock::FixupListIterator
  LlirOctaveBlock::fixupListEnd()
  {
    return m_opndLabelList.end();
  }

  LlirOctaveBlock::FixupListConstIterator
  LlirOctaveBlock::fixupListBegin() const
  {
    return m_opndLabelList.begin();
  }

  LlirOctaveBlock::FixupListConstIterator
  LlirOctaveBlock::fixupListEnd() const
  {
    return m_opndLabelList.end();
  }

  void
  LlirOctaveBlock::addSmapRegister(shared_ptr<const MultiHardRegister> r)
  {
    m_smapHardRegisters.push_back(r);
  }

  LlirOctaveBlock::SmapRegistersIterator
  LlirOctaveBlock::smapRegistersBegin()
  {
    return m_smapHardRegisters.begin();
  }

  LlirOctaveBlock::SmapRegistersConstIterator
  LlirOctaveBlock::smapRegistersBegin() const
  {
    return m_smapHardRegisters.begin();
  }

  LlirOctaveBlock::SmapRegistersIterator
  LlirOctaveBlock::smapRegistersEnd()
  {
    return m_smapHardRegisters.end();
  }

  LlirOctaveBlock::SmapRegistersConstIterator
  LlirOctaveBlock::smapRegistersEnd() const
  {
    return m_smapHardRegisters.end();
  }

  bool
  LlirOctaveBlock::isBlock() const
  {
    return true;
  }

  //--------------------------------
  //OctaveBlock class
  //--------------------------------


  OctaveBlock::OctaveBlock(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName)
    : LlirOctaveBlock("", 
		      lineNum,
		      srcLineNum,
		      srcFileName)
  {}

  OctaveBlock::OctaveBlock(const char *name, 
			   unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName)
    : LlirOctaveBlock(name, 
		      lineNum,
		      srcLineNum,
		      srcFileName)
  {}

  OctaveBlock::OctaveBlock(const OctaveBlock &rhs)
    : LlirOctaveBlock(rhs) 
  {}

  OctaveBlock&
  OctaveBlock::operator=(const OctaveBlock& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveBlock::operator=(rhs);
    return *this;	
  }

  void OctaveBlock::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
  }

  LlirOctaveBlock::ParentListIterator
  OctaveBlock::getParent() 
  {
    return getParentList(this->getBlkId());
  }

  bool
  OctaveBlock::equalTo(const LlirNode &rhs) const
  {
    if(getLineNum() == dynamic_cast<const OctaveBlock&>(rhs).getLineNum())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  //--------------------------------
  //OctaveMacroBlock class
  //--------------------------------

  OctaveMacroBlock::OctaveMacroBlock(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName)
    : LlirOctaveBlock("", 
		      lineNum,
		      srcLineNum,
		      srcFileName)
  {}

  OctaveMacroBlock::OctaveMacroBlock(const OctaveMacroBlock& rhs)
    : LlirOctaveBlock(rhs)
  {}

  OctaveMacroBlock&
  OctaveMacroBlock::operator=(const OctaveMacroBlock& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveBlock::operator=(rhs);
    return *this;
  }

  void OctaveMacroBlock::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
  }

  LlirOctaveBlock::ParentListIterator
  OctaveMacroBlock::getParent() 
  {
    return getParentList(this->getBlkId());
  }

  bool
  OctaveMacroBlock::equalTo(const LlirNode &rhs) const
  {
    if(getLineNum() == dynamic_cast<const OctaveMacroBlock&>(rhs).getLineNum())
      {
	return true;
      }
    else
      {
	return false;
      }
 }

  //--------------------------------
  //OctaveImplicitBlock class
  //--------------------------------

  OctaveImplicitBlock::OctaveImplicitBlock()
    : LlirOctaveBlock("", 0, 0, "")
  {}

  OctaveImplicitBlock::OctaveImplicitBlock(const OctaveImplicitBlock& rhs)
    : LlirOctaveBlock(rhs)
  {}

  OctaveImplicitBlock&
  OctaveImplicitBlock::operator=(const OctaveImplicitBlock &rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveBlock::operator=(rhs);
    return *this;
  }

  void OctaveImplicitBlock::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
  }

  LlirOctaveBlock::ParentListIterator
  OctaveImplicitBlock::getParent() 
  {
    if(this->getBlkId() == 0)
      {
	//if it is the root implicit block it will
	//have block id as zero...
	return parentListEnd();	
      }

    return getParentList(this->getBlkId());
  }

  bool
  OctaveImplicitBlock::equalTo(const LlirNode &rhs) const
  {
    if(getLineNum() == (dynamic_cast<const OctaveImplicitBlock&> (rhs)).getLineNum() ) 
      return true;
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("OctaveImplicitBlock has non-zero Line Number");
      }
  }







  //--------------------
  // AltEntryFunction
  //--------------------


  AltEntryFunction::AltEntryFunction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName,				     
				     unsigned int numHardRegs,
				     unsigned int numPseudoRegs,
				     shared_ptr<const LabelList> labelList,
				     shared_ptr<const ArgList> argList,
				     shared_ptr<const ResultList> resultList,
				     shared_ptr<const ScratchList> scratchList,
				     shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
				     shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
				     shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
				     shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
				     shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
				     shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
				     shared_ptr<const RegLnksListToSIO> lnkToSIO_List) 
    : LlirFunction(lineNum, 
		   srcLineNum,
		   srcFileName,
		   labelList->getLabel(0)->getName().c_str()),
      m_numHardRegs(numHardRegs),
      m_numPseudoRegs(numPseudoRegs),
      m_implBlock(new OctaveImplicitBlock()),
      m_EntryPtList(labelList),
      m_argList(argList),
      m_resultList(resultList),
      m_scratchList(scratchList),
      m_lnkToSPRAM_List(lnkToSPRAM_List),
      m_lnkToLocked_SPRAM_List(lnkToLocked_SPRAM_List),
      m_lnkToSRAM_List(lnkToSRAM_List),
      m_lnkToSDRAM_List(lnkToSDRAM_List),
      m_lnkToCCRAM_List(lnkToCCRAM_List),
      m_lnkToLocked_CCRAM_List(lnkToLocked_CCRAM_List),
      m_lnkToSIO_List(lnkToSIO_List),
      m_exitLabel(string("_") + labelList->getLabel(0)->getName() + string("_exit_")),
      m_returnReg(new NullRegister())
  {}
  
  AltEntryFunction::AltEntryFunction(const AltEntryFunction& rhs) 
    : LlirFunction(rhs),
      m_numHardRegs(rhs.m_numHardRegs),
      m_numPseudoRegs(rhs.m_numPseudoRegs),
      m_implBlock(rhs.m_implBlock),
      m_EntryPtList(rhs.m_EntryPtList),
      m_argList(rhs.m_argList),
      m_resultList(rhs.m_resultList),
      m_scratchList(rhs.m_scratchList),
      m_lnkToSPRAM_List(rhs.m_lnkToSPRAM_List),
      m_lnkToLocked_SPRAM_List(rhs.m_lnkToLocked_SPRAM_List),
      m_lnkToSRAM_List(rhs.m_lnkToSRAM_List),
      m_lnkToSDRAM_List(rhs.m_lnkToSDRAM_List),
      m_lnkToCCRAM_List(rhs.m_lnkToCCRAM_List),
      m_lnkToLocked_CCRAM_List(rhs.m_lnkToLocked_CCRAM_List),
      m_lnkToSIO_List(rhs.m_lnkToSIO_List),
      m_exitLabel(rhs.m_exitLabel),
      m_returnReg(rhs.m_returnReg),
      m_entryLabelList(rhs.m_entryLabelList),
      m_codeLabelList(rhs.m_codeLabelList)
  {}

  AltEntryFunction::AltEntryFunction& 
  AltEntryFunction::operator=(const AltEntryFunction& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirFunction::operator=(rhs);

    m_numHardRegs = rhs.m_numHardRegs;
    m_numPseudoRegs = rhs.m_numPseudoRegs;
    m_implBlock = rhs.m_implBlock;
    m_EntryPtList = rhs.m_EntryPtList;
    m_argList = rhs.m_argList;
    m_resultList = rhs.m_resultList;
    m_scratchList = rhs.m_scratchList;
    m_lnkToSPRAM_List = rhs.m_lnkToSPRAM_List;
    m_lnkToLocked_SPRAM_List = rhs.m_lnkToLocked_SPRAM_List;
    m_lnkToSRAM_List = rhs.m_lnkToSRAM_List;
    m_lnkToSDRAM_List = rhs.m_lnkToSDRAM_List;
    m_lnkToCCRAM_List = rhs.m_lnkToCCRAM_List;
    m_lnkToLocked_CCRAM_List = rhs.m_lnkToLocked_CCRAM_List;
    m_lnkToSIO_List = rhs.m_lnkToSIO_List;
    m_exitLabel = rhs.m_exitLabel;
    m_returnReg = rhs.m_returnReg;
    m_entryLabelList = rhs.m_entryLabelList;
    m_codeLabelList = rhs.m_codeLabelList;

    return *this; 

  }
  
  AltEntryFunction::~AltEntryFunction()
  {}

  const string&
  AltEntryFunction::getName() const
  {
    //name of the evh/entry is same as the
    //name of the first entry point label

    return getEntryPtList()->getLabel(0)->getName();
  }

  unsigned int 
  AltEntryFunction::getNumRegs() const
  {
    //Total Num of registers = hard + pseudo regs

    // last hard reg num 155, total 156
    // first pseudo reg num begins at reg_rtx_no    

    //why +5?

    //LAST_REGNUM = 155 (see m480.h)
    //FIRST_PSEUDO_REGISTER = LAST_REGNUM + 1 (see m480.h)
    //FIRST_VIRTUAL_REGISTER = FIRST_PSEUDO_REGISTER
    //LAST_VIRTUAL_REGISTER = FIRST_VIRTUAL_REGISTER + 4
    //reg_rtx_no = LAST_VIRTUAL_REGISTER + 1;
    
    return getNumHardRegs() + 5 + getNumPseudoRegs();

  }

  unsigned int
  AltEntryFunction::getNumHardRegs() const
  {
    return m_numHardRegs;
  }

  unsigned int
  AltEntryFunction::getNumPseudoRegs() const
  {
    return m_numPseudoRegs;
  }

  void
  AltEntryFunction::updateNumOfPseudoRegs(unsigned int num)
  {
    m_numPseudoRegs += num;
  }

  const string&
  AltEntryFunction::getExitLabel() const
  {
    return m_exitLabel;
  }

  shared_ptr<const Register>
  AltEntryFunction::getReturnReg() const
  {
    return m_returnReg;
  }

  void
  AltEntryFunction::storeReturnReg(shared_ptr<const Register> reg)
  {
    m_returnReg = reg;
  }

  bool
  AltEntryFunction::isEntryPointLabel(const char* label) const
  {
    return m_EntryPtList->isInList(label);
  }

  bool
  AltEntryFunction::isFirstEntryPointLabel(const char* label) const
  {
    return (m_EntryPtList->getLabel(0)->getName() == label);
  }

  bool 
  AltEntryFunction::hasLinkToSPRAM(unsigned int regNum) const
  { 
   shared_ptr<const Register> reg;

    reg = m_lnkToSPRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSPRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSPRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  AltEntryFunction::hasLinkToLockedSPRAM(unsigned int regNum) const
  { 
    shared_ptr<const Register> reg;

    reg = m_lnkToLocked_SPRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_SPRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_SPRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  AltEntryFunction::hasLinkToSRAM(unsigned int regNum) const
  {

    shared_ptr<const Register> reg;

    reg = m_lnkToSRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  AltEntryFunction::hasLinkToSDRAM(unsigned int regNum) const
  { 
     shared_ptr<const Register> reg;

    reg = m_lnkToSDRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSDRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSDRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  AltEntryFunction::hasLinkToCCRAM(unsigned int regNum) const
  {
     shared_ptr<const Register> reg;

    reg = m_lnkToCCRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToCCRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToCCRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;

  }

  bool 
  AltEntryFunction::hasLinkToLockedCCRAM(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToLocked_CCRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_CCRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_CCRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  AltEntryFunction::hasLinkToSIO(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToSIO_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSIO_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSIO_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }


  shared_ptr<OctaveImplicitBlock>
  AltEntryFunction::getImplicitBlock() const
  {
    return m_implBlock;
  }

  shared_ptr<const LabelList> 
  AltEntryFunction::getEntryPtList() const
  {
    return m_EntryPtList;
  }


  shared_ptr<const ArgList> 
  AltEntryFunction::getArgList() const
  {
    return m_argList;
  }

  shared_ptr<const ResultList> 
  AltEntryFunction::getResultList() const
  {
    return m_resultList;
  }

  shared_ptr<const ScratchList> 
  AltEntryFunction::getScratchList() const
  {
    return m_scratchList;
  }

  shared_ptr<const RegLnksListToSPRAM> 
  AltEntryFunction::getRegLnksListToSPRAM() const
  {
    return m_lnkToSPRAM_List;
  }
      
  shared_ptr<const RegLnksListToLockedSPRAM> 
  AltEntryFunction::getRegLnksListToLockedSPRAM() const
  {
    return m_lnkToLocked_SPRAM_List;
  }
  
  shared_ptr<const RegLnksListToSRAM> 
  AltEntryFunction::getRegLnksListToSRAM() const
  {
    return m_lnkToSRAM_List;
  }
  
  shared_ptr<const RegLnksListToSDRAM> 
  AltEntryFunction::getRegLnksListToSDRAM() const
  {
    return m_lnkToSDRAM_List;
  }
  
  shared_ptr<const RegLnksListToCCRAM> 
  AltEntryFunction::getRegLnksListToCCRAM() const
  {
    return m_lnkToCCRAM_List;
  }
  
  shared_ptr<const RegLnksListToLockedCCRAM> 
  AltEntryFunction::getRegLnksListToLockedCCRAM() const
  {
    return m_lnkToLocked_CCRAM_List;
  }
  
  shared_ptr<const RegLnksListToSIO> 
  AltEntryFunction::getRegLnksListToSIO() const
  {
    return m_lnkToSIO_List;
  }

  void
  AltEntryFunction::addLlirNode(shared_ptr<LlirNode> currentBlk, shared_ptr<LlirNode> childNode)
  {
    m_implBlock->addLlirNode(currentBlk, childNode);
  }

  LlirNode::Iterator 
  AltEntryFunction::begin()
  {
    return LlirNode::Iterator(new FunctionIterator(m_implBlock->begin()));
  }

  LlirNode::Iterator 
  AltEntryFunction::end()
  {

    return LlirNode::Iterator(new FunctionIterator(m_implBlock->end()));
  }


  LlirNode::ConstIterator 
  AltEntryFunction::begin() const
  {
    return LlirNode::ConstIterator(new FunctionConstIterator(m_implBlock->begin()));
  }

  LlirNode::ConstIterator 
  AltEntryFunction::end() const
  {
    return LlirNode::ConstIterator(new FunctionConstIterator(m_implBlock->end()));
  }


  void 
  AltEntryFunction::addSymbol(shared_ptr<OctaveSymbol> sym)
  {
    m_implBlock->addSymbol(sym);
  }

  void 
  AltEntryFunction::addLabelEntry(shared_ptr<GlobalLabel> label)
  {
    m_entryLabelList.push_back(label);
  }

  AltEntryFunction::EntryLabelIterator
  AltEntryFunction::entryLabelBegin()
  {
    return m_entryLabelList.begin();
  }

  AltEntryFunction::EntryLabelIterator
  AltEntryFunction::entryLabelEnd()
  {
    return m_entryLabelList.end();
  }

  AltEntryFunction::EntryLabelConstIterator
  AltEntryFunction::entryLabelBegin() const
  {
    return m_entryLabelList.begin();
  }

  AltEntryFunction::EntryLabelConstIterator
  AltEntryFunction::entryLabelEnd() const
  {
    return m_entryLabelList.end();
  }

  void 
  AltEntryFunction::removeSymbol(shared_ptr<OctaveSymbol> sym)
  {
    m_implBlock->removeSymbol(sym);
  }

  SymbolTable<OctaveSymbol>::Iterator 
  AltEntryFunction::lookupSymbol(const char* name)
  {
    return m_implBlock->lookupSymbol(name);
  }
  
  SymbolTable<OctaveSymbol>::ConstIterator 
  AltEntryFunction::lookupSymbol(const char* name) const
  {
    return m_implBlock->lookupSymbol(name);
  }
  
  SymbolTable<OctaveSymbol>::Iterator 
  AltEntryFunction::symTableBegin()
  {
    return m_implBlock->symTableBegin();
  }
  
  SymbolTable<OctaveSymbol>::Iterator 
  AltEntryFunction::symTableEnd()
  {
    return m_implBlock->symTableEnd();
  }
  
  SymbolTable<OctaveSymbol>::ConstIterator 
  AltEntryFunction::symTableBegin() const
  {
    return m_implBlock->symTableBegin();
  }
  
  SymbolTable<OctaveSymbol>::ConstIterator 
  AltEntryFunction::symTableEnd() const
  {
    return m_implBlock->symTableEnd();
  }

  void 
  AltEntryFunction::storeBranchTarget(const char* mName)
  {
    //mangled_name is the unique name in case of a local label.
    //globals and file scope labels are unique anyway...

    if(m_codeLabelList.find(mName) == m_codeLabelList.end())
      {
	//store all unique instances of label operands
	//ever found in any jump/call insn in the current evh/function.

	m_codeLabelList.insert(mName);
      }
  }

  bool
  AltEntryFunction::isCodeLabel(const char* mName) const
  {
    if(m_codeLabelList.find(mName) != m_codeLabelList.end())
      return true;
    else
      return false;
  }
  


  //--------------------------
  // Multiple Entry Evh
  //--------------------------


 MultipleEntryEvh::MultipleEntryEvh(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,				     
				    unsigned int numHardRegs,
				    unsigned int numPseudoRegs,
				    shared_ptr<const LabelList> labelList,
				    shared_ptr<const ArgList> argList,
				    shared_ptr<const ResultList> resultList,
				    shared_ptr<const ScratchList> scratchList,
				    shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
				    shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
				    shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
				    shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
				    shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
				    shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
				    shared_ptr<const RegLnksListToSIO> lnkToSIO_List) 
   :  AltEntryFunction(lineNum, 
		       srcLineNum,
		       srcFileName,
		       numHardRegs,
		       numPseudoRegs,
		       labelList, 
		       argList, 
		       resultList,
		       scratchList,
		       lnkToSPRAM_List,
		       lnkToLocked_SPRAM_List,
		       lnkToSRAM_List,
		       lnkToSDRAM_List,
		       lnkToCCRAM_List,
		       lnkToLocked_CCRAM_List,
		       lnkToSIO_List)
 {}

  MultipleEntryEvh::MultipleEntryEvh(const MultipleEntryEvh& rhs) :
    AltEntryFunction(rhs)
  {}

  MultipleEntryEvh& 
  MultipleEntryEvh::operator=(const MultipleEntryEvh& rhs)
  {
    if(this == &rhs)
      return *this;

    AltEntryFunction::operator=(rhs);
    return *this; 
  }

  bool 
  MultipleEntryEvh::equalTo(const LlirNode &rhs) const
  { 
    MultipleEntryEvh rhsDir = dynamic_cast<const MultipleEntryEvh &> (rhs);


    if(*getEntryPtList() == *rhsDir.getEntryPtList() &&
       *getArgList() == *rhsDir.getArgList() &&
       *getResultList() == *rhsDir.getResultList() &&
       *getScratchList() == *rhsDir.getScratchList() &&
       *getRegLnksListToSPRAM() == *rhsDir.getRegLnksListToSPRAM() &&
       *getRegLnksListToLockedSPRAM() == *rhsDir.getRegLnksListToLockedSPRAM() &&
       *getRegLnksListToSRAM() == *rhsDir.getRegLnksListToSRAM() &&
       *getRegLnksListToSDRAM() == *rhsDir.getRegLnksListToSDRAM() &&
       *getRegLnksListToCCRAM() == *rhsDir.getRegLnksListToCCRAM() &&
       *getRegLnksListToLockedCCRAM() == *rhsDir.getRegLnksListToLockedCCRAM() &&
       *getRegLnksListToSIO() == *rhsDir.getRegLnksListToSIO())
      {
	return true;
      }
    else
      {
	return false;
      }

    return false;
  }

  void 
  MultipleEntryEvh::accept(Visitor& v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }
  }


  //--------------------------
  // MultipleEntryFunction
  //--------------------------

  MultipleEntryFunction::MultipleEntryFunction(unsigned int lineNum,
					       unsigned int srcLineNum,
					       const char* srcFileName,				     
					       unsigned int numHardRegs,
					       unsigned int numPseudoRegs,
					       shared_ptr<const LabelList> labelList,
					       shared_ptr<const ArgList> argList,
					       shared_ptr<const ResultList> resultList,
					       shared_ptr<const ScratchList> scratchList,
					       shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
					       shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
					       shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
					       shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
					       shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
					       shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
					       shared_ptr<const RegLnksListToSIO> lnkToSIO_List) 
    : AltEntryFunction(lineNum, 		       
		       srcLineNum,
		       srcFileName,
		       numHardRegs,
		       numPseudoRegs,
		       labelList, 
		       argList, 
		       resultList,
		       scratchList,
		       lnkToSPRAM_List,
		       lnkToLocked_SPRAM_List,
		       lnkToSRAM_List,
		       lnkToSDRAM_List,
		       lnkToCCRAM_List,
		       lnkToLocked_CCRAM_List,
		       lnkToSIO_List)
  {}
  
  MultipleEntryFunction::MultipleEntryFunction(const MultipleEntryFunction& rhs) 
    : AltEntryFunction(rhs)
  {}

  MultipleEntryFunction& 
  MultipleEntryFunction::operator=(const MultipleEntryFunction& rhs)
  {
    if(this == &rhs)
      return *this;

    AltEntryFunction::operator=(rhs);
    return *this; 
  }
  
  bool 
  MultipleEntryFunction::equalTo(const LlirNode &rhs) const
  { 
    MultipleEntryFunction rhsDir = dynamic_cast<const MultipleEntryFunction &> (rhs);


    if(*getEntryPtList() == *rhsDir.getEntryPtList() &&
       *getArgList() == *rhsDir.getArgList() &&
       *getResultList() == *rhsDir.getResultList() &&
       *getScratchList() == *rhsDir.getScratchList() &&
       *getRegLnksListToSPRAM() == *rhsDir.getRegLnksListToSPRAM() &&
       *getRegLnksListToLockedSPRAM()  == *rhsDir.getRegLnksListToLockedSPRAM() &&
       *getRegLnksListToSRAM() == *rhsDir.getRegLnksListToSRAM() &&
       *getRegLnksListToSDRAM() == *rhsDir.getRegLnksListToSDRAM() &&
       *getRegLnksListToCCRAM() == *rhsDir.getRegLnksListToCCRAM() &&
       *getRegLnksListToLockedCCRAM() == *rhsDir.getRegLnksListToLockedCCRAM() &&
       *getRegLnksListToSIO() == *rhsDir.getRegLnksListToSIO())
      {
	return true;
      }
    else
      {
	return false;
      }

    return false;
  }

  void 
  MultipleEntryFunction::accept(Visitor& v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }
  }


  //-----------------------------
  //LlirOctaveBlockIterator class
  //-----------------------------

  LlirOctaveBlockIterator::LlirOctaveBlockIterator()
  {}

  LlirOctaveBlockIterator::LlirOctaveBlockIterator(LlirOctaveBlock::BlkIterator i)
    : m_iterator(i)
  {}

  LlirOctaveBlockIterator::LlirOctaveBlockIterator(const LlirOctaveBlockIterator &rhs)
    : LlirNodeIterator(rhs),
      m_iterator(rhs.m_iterator)
  {}

  LlirOctaveBlockIterator&
  LlirOctaveBlockIterator::operator=(const LlirOctaveBlockIterator &rhs)
  {
    if (this == &rhs)
      return *this;

    this->LlirNodeIterator::operator=(rhs);
    m_iterator = rhs.m_iterator;
    return *this;
  }

  bool
  LlirOctaveBlockIterator::equalTo(const LlirNodeIterator &rhs) const
  {
    return (m_iterator == (dynamic_cast<const LlirOctaveBlockIterator &> (rhs)).m_iterator);
  }

  LlirNodeIterator* 
  LlirOctaveBlockIterator::postInc()
  {
    LlirNodeIterator* old( new LlirOctaveBlockIterator(m_iterator) );
    m_iterator++;
    return old;
  }

  void
  LlirOctaveBlockIterator::preInc()
  {
    ++m_iterator;
  }

  LlirNodeIterator*
  LlirOctaveBlockIterator::postDec()
  {
    LlirNodeIterator* old( new LlirOctaveBlockIterator(m_iterator) );
    m_iterator--;
    return old;
  }

  void
  LlirOctaveBlockIterator::preDec()
  {
    --m_iterator;
  }

  shared_ptr<LlirNode>&
  LlirOctaveBlockIterator::operator*()
  {
    return *m_iterator;
  }

  shared_ptr<LlirNode>*
  LlirOctaveBlockIterator::operator->()
  {
    return &(*m_iterator);
  }




  //LlirOctaveBlockConstIterator class
  //----------------------------------

  LlirOctaveBlockConstIterator::LlirOctaveBlockConstIterator()
  {}

  LlirOctaveBlockConstIterator::LlirOctaveBlockConstIterator(LlirOctaveBlock::BlkConstIterator i)
    : m_iterator(i)
  {}

  LlirOctaveBlockConstIterator::LlirOctaveBlockConstIterator(const LlirOctaveBlockConstIterator &rhs)
    : LlirNodeConstIterator(rhs),
      m_iterator(rhs.m_iterator)
  {}

  LlirOctaveBlockConstIterator&
  LlirOctaveBlockConstIterator::operator=(const LlirOctaveBlockConstIterator &rhs)
  {
    if (this == &rhs)
      return *this;

    this->LlirNodeConstIterator::operator=(rhs);
    m_iterator = rhs.m_iterator;
    return *this;
  }

  bool
  LlirOctaveBlockConstIterator::equalTo(const LlirNodeConstIterator &rhs) const
  {
    return (m_iterator == (dynamic_cast<const LlirOctaveBlockConstIterator &> (rhs)).m_iterator);
  }

  LlirNodeConstIterator*
  LlirOctaveBlockConstIterator::postInc()
  {
    LlirNodeConstIterator* old( new LlirOctaveBlockConstIterator(m_iterator) );
    m_iterator++;
    return old;
  }

  void
  LlirOctaveBlockConstIterator::preInc()
  {
    ++m_iterator;
  }

  LlirNodeConstIterator*
  LlirOctaveBlockConstIterator::postDec()
  {
    LlirNodeConstIterator* old( new LlirOctaveBlockConstIterator(m_iterator) );
    m_iterator--;
    return old;
  }

  void
  LlirOctaveBlockConstIterator::preDec()
  {
    --m_iterator;
  }

  const shared_ptr<LlirNode>&
  LlirOctaveBlockConstIterator::operator*()
  {
    return *m_iterator;
  }

  const shared_ptr<LlirNode>*
  LlirOctaveBlockConstIterator::operator->()
  {
    return &(*m_iterator);
  }





  //-----------------------------
  //FunctionIterator class
  //-----------------------------

  FunctionIterator::FunctionIterator()
  {}

  FunctionIterator::FunctionIterator(LlirNode::Iterator i)
    : m_iterator(i)
  {}

  FunctionIterator::FunctionIterator(const FunctionIterator &rhs)
    : LlirNodeIterator(rhs),
      m_iterator(rhs.m_iterator)
  {}

  FunctionIterator&
  FunctionIterator::operator=(const FunctionIterator &rhs)
  {
    if (this == &rhs)
      return *this;

    this->LlirNodeIterator::operator=(rhs);
    m_iterator = rhs.m_iterator;
    return *this;
  }

  bool
  FunctionIterator::equalTo(const LlirNodeIterator &rhs) const
  {
    return (m_iterator == (dynamic_cast<const FunctionIterator &> (rhs)).m_iterator);
  }

  LlirNodeIterator* 
  FunctionIterator::postInc()
  {
    LlirNodeIterator* old( new FunctionIterator(m_iterator) );
    m_iterator++;
    return old;
  }

  void
  FunctionIterator::preInc()
  {
    ++m_iterator;
  }

  LlirNodeIterator*
  FunctionIterator::postDec()
  {
    LlirNodeIterator* old( new FunctionIterator(m_iterator) );
    m_iterator--;
    return old;
  }

  void
  FunctionIterator::preDec()
  {
    --m_iterator;
  }

  shared_ptr<LlirNode>&
  FunctionIterator::operator*()
  {
    return *m_iterator;
  }

  shared_ptr<LlirNode>*
  FunctionIterator::operator->()
  {
    return &(*m_iterator);
  }



  //----------------------------------
  //FunctionConstIterator class
  //----------------------------------

  FunctionConstIterator::FunctionConstIterator()
  {}

  FunctionConstIterator::FunctionConstIterator(LlirNode::Iterator i)
    : m_iterator(i)
  {}

  FunctionConstIterator::FunctionConstIterator(const FunctionConstIterator &rhs)
    : LlirNodeConstIterator(rhs),
      m_iterator(rhs.m_iterator)
  {}

  FunctionConstIterator&
  FunctionConstIterator::operator=(const FunctionConstIterator &rhs)
  {
    if (this == &rhs)
      return *this;

    this->LlirNodeConstIterator::operator=(rhs);
    m_iterator = rhs.m_iterator;
    return *this;
  }

  bool
  FunctionConstIterator::equalTo(const LlirNodeConstIterator &rhs) const
  {
    return (m_iterator == (dynamic_cast<const FunctionConstIterator &> (rhs)).m_iterator);
  }

  LlirNodeConstIterator*
  FunctionConstIterator::postInc()
  {
    LlirNodeConstIterator* old( new FunctionConstIterator(m_iterator) );
    m_iterator++;
    return old;
  }

  void
  FunctionConstIterator::preInc()
  {
    ++m_iterator;
  }

  LlirNodeConstIterator*
  FunctionConstIterator::postDec()
  {
    LlirNodeConstIterator* old( new FunctionConstIterator(m_iterator) );
    m_iterator--;
    return old;
  }

  void
  FunctionConstIterator::preDec()
  {
    --m_iterator;
  }

  const shared_ptr<LlirNode>&
  FunctionConstIterator::operator*()
  {
    return *m_iterator;
  }

  const shared_ptr<LlirNode>*
  FunctionConstIterator::operator->()
  {
    return &(*m_iterator);
  }




}  // namespace Llir









