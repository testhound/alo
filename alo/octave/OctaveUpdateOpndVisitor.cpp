#include <cmath>
#include <sstream>
using namespace std;
#include <OctaveNode.h>
#include <OctaveOperand.h>
#include <OctavePrintVisitor.h>

#include "OctaveUpdateOpndVisitor.h"

using namespace Llir;
using namespace Alo;
 

namespace Alo
{

  OctaveUpdateOpndVisitor::OctaveUpdateOpndVisitor(OctaveAlo &o)    
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(o)
  {
    //genRtl visitor is called once per function/evh.
    //reset the following variables for each instantiation.
    //   m_regLinksList, 
    //   m_regMemLinkTypeList

    for(unsigned int reg=0; reg <= 63; reg++)
      {
	setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_ANY);
	setRegLink(reg, LinkFlag::NOLINK);
      }
  }

  OctaveUpdateOpndVisitor::OctaveUpdateOpndVisitor(const OctaveUpdateOpndVisitor& rhs)
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(rhs.m_alo)
  {
    
  }
  
  const OctaveUpdateOpndVisitor&
  OctaveUpdateOpndVisitor::operator=(const OctaveUpdateOpndVisitor& rhs)
  {
    if(this == &rhs)
      return *this;

    Visitor::operator=(rhs);
    LlirOctaveVisitor::operator=(rhs);
    
    m_alo = rhs.m_alo;

    return *this;
  }

  OctaveAlo&
  OctaveUpdateOpndVisitor::getAlo() const
  {
    return m_alo;
  }

  void
  OctaveUpdateOpndVisitor::setRegLink(unsigned int regNum, 
				       LinkFlag::Link_Flag_t memLink)
  {
    //remove the std::map element if already exists
    //with the same key

    RegLinksListIterator iter = m_regLinksList.find(regNum);
    if(iter != m_regLinksList.end())
      {
	m_regLinksList.erase(iter);
      }

    //now associate the new memory link to the register

    m_regLinksList[regNum] = memLink;

  }
 
  LinkFlag::Link_Flag_t
  OctaveUpdateOpndVisitor::getRegLink(unsigned int regNum)
  {
    return m_regLinksList[regNum];
  }
 
  bool 
  OctaveUpdateOpndVisitor::isLinkedReg(unsigned int regNum)
  {
    if(m_regLinksList[regNum] !=  LinkFlag::NOLINK)
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  void
  OctaveUpdateOpndVisitor::setRegisterLinkedMemoryType(unsigned int regNum, 
							OctaveMemory::MemType_t memType)
  {

    //if there exists a map element with the same key
    //remove it.

    RegLinkMemTypeIterator iter = m_regMemLinkTypeList.find(regNum);
    if(iter != m_regMemLinkTypeList.end())
      {
	m_regMemLinkTypeList.erase(iter);
      }

    //now associate the new memory link to the register

    m_regMemLinkTypeList[regNum] = memType;
  }
 
  OctaveMemory::MemType_t
  OctaveUpdateOpndVisitor::getRegisterLinkedMemoryType(unsigned int regNum)
  {
    return m_regMemLinkTypeList[regNum];
  }


  void
  OctaveUpdateOpndVisitor::visit(const LlirSequence& seq)
  {
    LlirNode::ConstIterator it = seq.begin();

    for (; it != seq.end(); it++)
      (*it)->accept(*this);

  }

  void
  OctaveUpdateOpndVisitor::visit(const OctaveBlock& block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveUpdateOpndVisitor::visit(const OctaveMacroBlock &macroBlk)
  {
    LlirNode::ConstIterator it = macroBlk.begin();

    for (; it != macroBlk.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveUpdateOpndVisitor::visit(const OctaveImplicitBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveUpdateOpndVisitor::visit(const LlirLineControlDirective& v)
  {}

  void
  OctaveUpdateOpndVisitor::visit(const MultipleEntryEvh &d)
  {
    // .evh directive comes with annotations about
    // which HARD registers are linked to memory.
    // update gen rtl visitor related
    //   m_regMemLinkTypeList
    //   m_regLinksList
    // lists to correctly reflect that information.
    // this info is used by all instructions which
    // cause implicity memory updates.

    d.getRegLnksListToSPRAM()->accept(*this);
    d.getRegLnksListToLockedSPRAM()->accept(*this);
    d.getRegLnksListToSRAM()->accept(*this);
    d.getRegLnksListToSDRAM()->accept(*this);
    d.getRegLnksListToCCRAM()->accept(*this);
    d.getRegLnksListToLockedCCRAM()->accept(*this);
    d.getRegLnksListToSIO()->accept(*this);

    //visit nodes within evh
    d.getImplicitBlock()->accept(*this);
  }

  void
  OctaveUpdateOpndVisitor::visit(const MultipleEntryFunction &d)
  {
    // .entry directive comes with annotations about
    // which HARD registers are linked to memory.
    // update gen rtl visitor related
    //   m_regMemLinkTypeList
    //   m_regLinksList
    // lists to correctly reflect that information.
    // this info is used by all instructions which
    // cause implicity memory updates.

    d.getRegLnksListToSPRAM()->accept(*this);
    d.getRegLnksListToLockedSPRAM()->accept(*this);
    d.getRegLnksListToSRAM()->accept(*this);
    d.getRegLnksListToSDRAM()->accept(*this);
    d.getRegLnksListToCCRAM()->accept(*this);
    d.getRegLnksListToLockedCCRAM()->accept(*this);
    d.getRegLnksListToSIO()->accept(*this);

    //visit nodes within entry
    d.getImplicitBlock()->accept(*this);

  }


  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToSPRAM &regList)
  {

    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SPRAM);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SPRAM);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SPRAM);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }
  }

  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToLockedSPRAM &regList)
  {   
    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SPRAM_LOCKED);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SPRAM_LOCKED);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SPRAM_LOCKED);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }
  }

  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToSRAM &regList)
  {   
    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SRAM);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SRAM);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SRAM);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }
  }

  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToSDRAM &regList)
  {   
    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SDRAM);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SDRAM);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SDRAM);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }

  }

  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToCCRAM &regList)
  {   
    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_CCRAM);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_CCRAM);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_CCRAM);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }

  }

  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToLockedCCRAM &regList)
  {       
    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_CCRAM_LOCKED);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_CCRAM_LOCKED);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_CCRAM_LOCKED);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }

 
  }

  void 
  OctaveUpdateOpndVisitor::visit(const RegLnksListToSIO &regList)
  {
    for(unsigned int reg=0; reg <= 63; reg++)
      {
	if(regList.getRegListLnk1()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SIO);
	    setRegLink(reg, LinkFlag::LNK1);
	  }

	else if(regList.getRegListLnk2()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SIO);
	    setRegLink(reg, LinkFlag::LNK2);
	  }

	else if(regList.getRegListLnk3()->isInList(reg))
	  {
	    setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_SIO);
	    setRegLink(reg, LinkFlag::LNK3);
	  }
	//else leave the default values as they are...
      }

  }
  

  void
  OctaveUpdateOpndVisitor::visit(const JtableRelativeBegin& d)
  {
    d.getLabelList()->accept(*this);
  }

  void
  OctaveUpdateOpndVisitor::visit(const JtableBegin& d)
  {
    d.getLabelList()->accept(*this);
  }

  void
  OctaveUpdateOpndVisitor::visit(const LabelList &l)
  {
    LabelList::ConstIterator iter = l.begin();
    for(; iter != l.end(); iter++)
      {
	(*iter)->setBranchTarget();
      }
  }

}








