extern "C"
{
#include "llir-gcc-connection.h"
}

#include <cmath>
#include <sstream>
using namespace std;
#include <OctaveNode.h>
#include <OctaveOperand.h>
#include "OctaveRtlPrintVisitor.h"

#include "OctaveGenRtlVisitor.h"

using namespace Llir;
using namespace Alo;
 

namespace Alo
{

  OctaveGenerateRtlVisitor::OctaveGenerateRtlVisitor(OctaveAlo &o)    
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(o),
      m_inSequence(false),
      m_inFunction(false)
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

  OctaveGenerateRtlVisitor::OctaveGenerateRtlVisitor(const OctaveGenerateRtlVisitor& rhs)
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(rhs.m_alo),
      m_currentFunction(rhs.m_currentFunction),
      m_inSequence(rhs.m_inSequence),
      m_inFunction(rhs.m_inFunction),
      m_regLinksList(rhs.m_regLinksList),
      m_regMemLinkTypeList(rhs.m_regMemLinkTypeList)
  {}
  
  const OctaveGenerateRtlVisitor&
  OctaveGenerateRtlVisitor::operator=(const OctaveGenerateRtlVisitor& rhs)
  {
    if(this == &rhs)
      return *this;

    Visitor::operator=(rhs);
    LlirOctaveVisitor::operator=(rhs);
    
    m_alo = rhs.m_alo;
    m_currentFunction = rhs.m_currentFunction;
    m_inSequence = rhs.m_inSequence;
    m_inFunction = rhs.m_inFunction;
    m_regLinksList = rhs.m_regLinksList;
    m_regMemLinkTypeList = rhs.m_regMemLinkTypeList;

    return *this;
  }

  OctaveAlo&
  OctaveGenerateRtlVisitor::getAlo() const
  {
    return m_alo;
  }

  bool
  OctaveGenerateRtlVisitor::isInSequence() const
  {
    return m_inSequence;
  }

  void
  OctaveGenerateRtlVisitor::generatingRtlForFunction(bool isInFunction)
  {
    m_inFunction = isInFunction;
  }

  
  bool
  OctaveGenerateRtlVisitor::inFunction() const
  {
    return m_inFunction;
  }

  shared_ptr<AltEntryFunction>
  OctaveGenerateRtlVisitor::getCurrentFunction()
  {
    return m_currentFunction;
  }
  
  void
  OctaveGenerateRtlVisitor::setCurrentFunction(shared_ptr<AltEntryFunction> fn)
  {
    m_currentFunction = fn;
  }

  void
  OctaveGenerateRtlVisitor::visit(const LlirSequence& seq)
  {
    m_inSequence = true;

    LlirNode::ConstIterator it = seq.begin();

    for (; it != seq.end(); it++)
      {
	shared_ptr<LlirNode> n = *it;

	if(! isNodeVisited(n))
	  {
	    n->accept(*this);
	    
	    n->visitedNode(true);
	  }
      }

    m_inSequence = false;
  }

  void
  OctaveGenerateRtlVisitor::visit(const OctaveBlock& block)
  {
    if(! inFunction())
      {
	if(! block.isNodeVisited())
	  {
	    gcc_emit_global_asm_directive(".block");
	  }
      }

    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      {
	shared_ptr<LlirNode> n = *it;

	if(! isNodeVisited(n))
	  {
	    n->accept(*this);
	    
	    n->visitedNode(true);
	  }
      }
  }

  void
  OctaveGenerateRtlVisitor::visit(const UnNamedEndBlock& block)
  {   
    if(! inFunction())
      {
	genRtlForAsmDirective(block);
      }
  }

  void
  OctaveGenerateRtlVisitor::visit(const NamedEndBlock& block)
  {  
    if(! inFunction())
      {
	genRtlForAsmDirective(block);
      }
  }

  void
  OctaveGenerateRtlVisitor::visit(const OctaveMacroBlock &macroBlk)
  {
    if(! inFunction())
      {
	if(! macroBlk.isNodeVisited())
	  {
	    gcc_emit_global_asm_directive(".block");
	  }
      }

    LlirNode::ConstIterator it = macroBlk.begin();

    for (; it != macroBlk.end(); it++)
      {
	shared_ptr<LlirNode> n = *it;
	
	if(! isNodeVisited(n))
	  {
	    n->accept(*this);
	    
	    n->visitedNode(true);
	  }
      }
  }


  void
  OctaveGenerateRtlVisitor::visit(const EndMacro& block)
  {
    if(! inFunction())
      {
	gcc_emit_global_asm_directive(".endblock");
      }
  }

  void
  OctaveGenerateRtlVisitor::visit(const OctaveImplicitBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      {
	shared_ptr<LlirNode> n = *it;
	
	if(! isNodeVisited(n))
	  {
	    n->accept(*this);
	    
	    n->visitedNode(true);
	  }
      }
  }

  // Even though a block is visited during
  // earlier calls to this visitor some nodes
  // might get added to the block in the subsequent
  // parsing of the input. This function
  // makes sure that all nodes blocks in the blocks
  // get visited irrespective of the block is visited
  // or not.
  bool
  OctaveGenerateRtlVisitor::isNodeVisited(shared_ptr<LlirNode> n)
  {
    shared_ptr<LlirOctaveBlock> blk = shared_dynamic_cast<LlirOctaveBlock>(n);
    if(blk)
      {
	return false;
      }

    return n->isNodeVisited();
  }

  void
  OctaveGenerateRtlVisitor::visit(const LlirLineControlDirective& v)
  {
    //nothing needs to be done here.
  }

  void OctaveGenerateRtlVisitor::visit(const LocalLabel &d)
  {
    if(! inFunction() ||
       d.isInSequence())
      {
	genRtlForAsmDirective(d);
	return;
      }

    unsigned int excLine = d.getSrcLineNum();
    const string &excFile = d.getSrcFile();

    gcc_emit_label(excLine, excFile.c_str(), d.getMangledName().c_str(), LOCAL);
  }

  void OctaveGenerateRtlVisitor::visit(const GlobalLabel &d)
  {
    if(! inFunction() ||
       d.isInSequence())
      {
        genRtlForAsmDirective(d);
        return;
      }

    unsigned int excLine = d.getSrcLineNum();
    const string &excFile = d.getSrcFile();

    const char* name = d.getLabelName().c_str();
    shared_ptr<AltEntryFunction> fn = getCurrentFunction();

    if(fn)
      {
	if(fn->isEntryPointLabel(name))
	  {
	    gcc_emit_label(excLine, excFile.c_str(), name, GLOBAL_ENTRY);
	  }
	else
	  {
	    gcc_emit_label(excLine, excFile.c_str(), name, GLOBAL);
	  }
      }
    else
      {
        char *excStr = new char[128];

        sprintf(excStr, "%s Function not found", name);

        throw ALO_INTERNAL_EXCEPTION(excStr);

        delete excStr;
      }
  }

  void OctaveGenerateRtlVisitor::visit(const FileScopeLabel &d)
  {
    if(! inFunction() ||
       d.isInSequence())
      {
	genRtlForAsmDirective(d);
	return;
      }

    unsigned int excLine = d.getSrcLineNum();
    const string &excFile = d.getSrcFile();

    gcc_emit_label(excLine, excFile.c_str(), d.getLabelName().c_str(), FILESCOPE);
  }

  void
  OctaveGenerateRtlVisitor::visit(const MultipleEntryEvh &d)
  {
    generatingRtlForFunction(true);

    setCurrentFunction(shared_ptr<AltEntryFunction>(new MultipleEntryEvh(d)));

    gcc_emit_note_beg_entry();

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

    d.getImplicitBlock()->accept(*this);

    generatingRtlForFunction(false);
  }

  void
  OctaveGenerateRtlVisitor::visit(const MultipleEntryFunction &d)
  {
    generatingRtlForFunction(true);

    setCurrentFunction(shared_ptr<AltEntryFunction>(new MultipleEntryFunction(d)));

    gcc_emit_note_beg_entry();

    // .entry directive comes with annotations (derived
    // from .prototype directive) about
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

    d.getImplicitBlock()->accept(*this);

    generatingRtlForFunction(false);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const EndEntryDirective &d)
  {
    emitEpilogue(getCurrentFunction());
  }

  void 
  OctaveGenerateRtlVisitor::visit(const EndEvhDirective &d)
  {
    emitEpilogue(getCurrentFunction());
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Ascii &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const List &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const NoList &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Align &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Ref &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Text &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Data &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Comm &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Lcomm &d)
  {
    genRtlForAsmDirective(d);
  }
  
  void 
  OctaveGenerateRtlVisitor::visit(const NamedSection &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Byte &d)
  {
    genRtlForAsmDirective(d);
  }
  void 
  OctaveGenerateRtlVisitor::visit(const Word &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const HalfWord &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const Org &d)
  {
    genRtlForAsmDirective(d);
  }
  void 
  OctaveGenerateRtlVisitor::visit(const OrgWithFillValue &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const StructEndDirective &d)
  {
    genRtlForAsmDirective(d);
  }
  void 
  OctaveGenerateRtlVisitor::visit(const StructBeginDirective &d)
  {
    genRtlForAsmDirective(d);
  }
  
  void 
  OctaveGenerateRtlVisitor::visit(const MapDirective &d)
  {
    ;genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const ScopedMapDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const UnmapDirective &d)
  {
    ;genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const ElementDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const MeetsDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const AssertDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const WarningDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const ErrorDirective &d)
  {
    genRtlForAsmDirective(d);
  }
  void 
  OctaveGenerateRtlVisitor::visit(const SregisterDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const GlobalDirective &d)
  {
    genRtlForAsmDirective(d);
  }

  void
  OctaveGenerateRtlVisitor::visit(const LabelList &l)
  {
    LabelList::ConstIterator iter = l.begin();
    for(; iter != l.end(); iter++)
      {
	(*iter)->accept(*this);
      }
  }

  void 
  OctaveGenerateRtlVisitor::visit(const RegLnksListToSPRAM &regList)
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
  OctaveGenerateRtlVisitor::visit(const RegLnksListToLockedSPRAM &regList)
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
  OctaveGenerateRtlVisitor::visit(const RegLnksListToSRAM &regList)
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
  OctaveGenerateRtlVisitor::visit(const RegLnksListToSDRAM &regList)
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
  OctaveGenerateRtlVisitor::visit(const RegLnksListToCCRAM &regList)
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
  OctaveGenerateRtlVisitor::visit(const RegLnksListToLockedCCRAM &regList)
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
  OctaveGenerateRtlVisitor::visit(const RegLnksListToSIO &regList)
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
  OctaveGenerateRtlVisitor::visit(const PrototypeDirective &d)
  {
    // genRtlForAsmDirective(d);

    // .prototype directive comes with annotations about
    // which HARD registers are linked to memory.
    // update gen rtl visitor specific
    //   m_regMemLinkTypeList
    //   m_regLinksList
    // lists to correctly reflect that information.

    // it is assumed that same registers are not repeated
    // in the different @linked annotations.
    // semantic visitor should ensure that this
    // assumption is correct.

    d.getRegLnksListToSPRAM()->accept(*this);
    d.getRegLnksListToLockedSPRAM()->accept(*this);
    d.getRegLnksListToSRAM()->accept(*this);
    d.getRegLnksListToSDRAM()->accept(*this);
    d.getRegLnksListToCCRAM()->accept(*this);
    d.getRegLnksListToLockedCCRAM()->accept(*this);
    d.getRegLnksListToSIO()->accept(*this);

  }

  void 
  OctaveGenerateRtlVisitor::visit(const JtableBegin &d)
  {
    //Plase Note:
    // There should be nothing between a addr_vec and
    // its prceding jump table label.. not even a 
    // line note....

    //genRtlForAsmDirective(d);

    shared_ptr<LabelList> labelList = d.getLabelList();

    labelList->reverse();

    LabelList::ConstIterator iter = labelList->begin();

    for(; iter != labelList->end(); iter++)
      {
	(*iter)->accept(*this);
      }

    unsigned int num_labels = labelList->getNumLabels();
    gcc_emit_jumptable(num_labels);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const JtableEnd &d)
  {
    //genRtlForAsmDirective(d);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const JtableRelativeBegin &d)
  {
    //Plase Note:
    // There should be nothing between a addr_vec and
    // its prceding jump table label.. not even a 
    // line note....

    //genRtlForAsmDirective(d);

    shared_ptr<LabelList> labelList = d.getLabelList();

    labelList->reverse();

    LabelList::ConstIterator iter = labelList->begin();

    for(; iter != labelList->end(); iter++)
      {
	(*iter)->accept(*this);
      }

    unsigned int num_labels = labelList->getNumLabels();
    gcc_emit_jumptable_relative(num_labels);
  }

  void 
  OctaveGenerateRtlVisitor::visit(const JtableRelativeEnd &d)
  {
    //genRtlForAsmDirective(d);
  }

  
  void
  OctaveGenerateRtlVisitor::emitEpilogue(shared_ptr<AltEntryFunction> fn)
  {
    
    //emit the extra __exit_evh__ label	
    const char* exitLabel = fn->getExitLabel().c_str();
    gcc_emit_exit_label(exitLabel);
    
    shared_ptr<const Register> retReg = fn->getReturnReg();
    
    shared_ptr<const NullRegister> nullReg =
      shared_dynamic_cast<const NullRegister>(retReg);
    
    if(!nullReg)
      gcc_emit_return_insn(retReg->getRegNum(), 0);
  }

  void 
  OctaveGenerateRtlVisitor::genRtlForAsmDirective(const LlirNode &d)
  {

    //FIXME:

    //just tried instantiating octave print visitor.
    //and it worked...

    //this is a bad thing...
    //never derive from a concrete class,
    //that means any base class except leaf class
    //should not be instantiable....

    //move all this directive handling into m480...
    //and maek OctavePrintVisitor destructor virtual
    //so that this sort of code gives compile time
    //error in the future...

    ostringstream d_stream;
    OctaveRtlPrintVisitor opv(d_stream);
    d.accept(opv);

    if(inFunction())
      {
        unsigned int excLine = d.getSrcLineNum();
        const string &excFile = d.getSrcFile();

	gcc_emit_local_asm_directive(excLine, excFile.c_str(), (d_stream.str()).c_str());
      }
    else
      gcc_emit_global_asm_directive((d_stream.str()).c_str());
  }



  void
  OctaveGenerateRtlVisitor::setRegLink(unsigned int regNum, 
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
  OctaveGenerateRtlVisitor::getRegLink(unsigned int regNum)
  {
    return m_regLinksList[regNum];
  }
 
  bool 
  OctaveGenerateRtlVisitor::isLinkedReg(unsigned int regNum)
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
  OctaveGenerateRtlVisitor::setRegisterLinkedMemoryType(unsigned int regNum, 
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
  OctaveGenerateRtlVisitor::getRegisterLinkedMemoryType(unsigned int regNum)
  {
    return m_regMemLinkTypeList[regNum];
  }

  shared_ptr<const PrototypeDirective>
  OctaveGenerateRtlVisitor::searchForPrototype(unsigned int line,
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

        throw ALO_INTERNAL_EXCEPTION(excStr);

        delete excStr;
      }
  }

  void 
  OctaveGenerateRtlVisitor::computeCallUseRegSet(shared_ptr<const PrototypeDirective> proto, unsigned int *regArray)
  {
    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(proto->getArgList()->getRegList()->isInList(regNum))
	  {
	    regArray[regNum] = 1;
	  }
      }
  }

  void 
  OctaveGenerateRtlVisitor::computeCallReturnRegSet(shared_ptr<const PrototypeDirective> proto, unsigned int *regArray)
  {
    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(proto->getResultList()->getRegList()->isInList(regNum))
	  {
	    regArray[regNum] = 1 ;
	  }
      }
  }

  unsigned int
  OctaveGenerateRtlVisitor::computeNumOfArgRegs(shared_ptr<const PrototypeDirective> proto)
  {
    unsigned int count=0;
    
    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {

	if(proto->getArgList()->getRegList()->isInList(regNum))
	  {
	    ++count;
	  }
      }

    return count;
  }


  //Expression Operand handling.


  void 
  OctaveGenerateRtlVisitor::visit(const SignedImmediate& v)
  {
    int value = v.getConstantValue();
    gcc_push_signed_immediate(value);
  }

  void OctaveGenerateRtlVisitor::visit(const UnsignedImmediate& v)
  {
    unsigned int value = v.getConstantValue();
    gcc_push_unsigned_immediate(value);
  }

  void OctaveGenerateRtlVisitor::visit(const OpndLabel& v)
  {
    const char* name = v.getMangledName().c_str();
    shared_ptr<AltEntryFunction> fn = getCurrentFunction();
	
    if((v.isCallTarget()))
      {
	//looking at a label object in a call insn
	gcc_push_symbol(name);
      }
    else if (v.isBranchTarget())
      {
	//looking at a label object in a jump insn
	gcc_push_label(name);
      }
    else if(fn->isCodeLabel(name))
      {
	//looking at a label operand in an insn
	//which is a code label
	gcc_push_label(name);
      }
    else
      {
	//looking at a label operand in an insn
	//which is a data label
	gcc_push_symbol(name);
      }
  }

  void OctaveGenerateRtlVisitor::visit(const PlusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
    gcc_pop_opnds_push_plus_expr();
  }

  void OctaveGenerateRtlVisitor::visit(const MinusOp& v)
  {
    v.getLeftOpnd()->accept(*this);
    v.getRightOpnd()->accept(*this);
    gcc_pop_opnds_push_minus_expr();
  }

  void OctaveGenerateRtlVisitor::visit(const HardRegister& v)
  {
    gcc_push_single_register(v.getRegNum());
  }

  void OctaveGenerateRtlVisitor::visit(const PseudoRegister& v)
  {
    gcc_push_single_register(v.getRegNum());    
  }

  void OctaveGenerateRtlVisitor::visit(const MultiHardRegister& v)
  {
    v.getRegister(0)->accept(*this);
    v.getRegister(v.getNumRegs() - 1)->accept(*this);
  }

  void OctaveGenerateRtlVisitor::visit(const MultiPseudoRegister& v)
  {
    v.getRegister(0)->accept(*this);
    v.getRegister(v.getNumRegs() - 1)->accept(*this);
  }

  void OctaveGenerateRtlVisitor::visit(const Base2PlusOffset &mem)
  {
    mem.getOffset()->accept(*this);
  }

  void OctaveGenerateRtlVisitor::visit(const Base3PlusOffset &mem)
  {
    mem.getOffset()->accept(*this);
  }

  void OctaveGenerateRtlVisitor::visit(const RegPlusOffsetIndirect &mem)
  {
    mem.getBaseRegister()->accept(*this);
    mem.getOffset()->accept(*this);
  }

  void OctaveGenerateRtlVisitor::visit(const ImpliedBase2Offset &mem)
  {
    mem.getOffset()->accept(*this);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod2Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod4Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod8Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod16Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod32Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod64Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod128Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod256Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod512Flag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod1KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod2KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod4KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod8KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod16KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod32KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod64KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod128KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod256KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod512KFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod1MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod2MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod4MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod8MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod16MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod32MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod64MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod128MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod256MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod512MFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod1GFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Mod2GFlag &v)
  {
    unsigned int mod = (unsigned int)pow(2, (double)v.getModuloWidth());    
    gcc_push_unsigned_immediate(mod-1);
  }

  void OctaveGenerateRtlVisitor::visit(const Ess0Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess1Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess2Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess3Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess4Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess5Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess6Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess7Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess8Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess9Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess10Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess11Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess12Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess13Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess14Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess15Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess16Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess17Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess18Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess19Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess20Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess21Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess22Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess23Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess24Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess25Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess26Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess27Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }
  void OctaveGenerateRtlVisitor::visit(const Ess28Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }
  void OctaveGenerateRtlVisitor::visit(const Ess29Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess30Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const Ess31Flag &o)
  {
    gcc_push_compare_ess_flag(o.getFlagNum(), o.isNegated());
  }

  void OctaveGenerateRtlVisitor::visit(const BALBFlag &o)
  {
    gcc_push_compare_abc_flag(o.getABCFlagType());
  }

  void OctaveGenerateRtlVisitor::visit(const BAEBFlag &o)
  {
    gcc_push_compare_abc_flag(o.getABCFlagType());
  }

  void OctaveGenerateRtlVisitor::visit(const BAGBFlag &o)
  {
    gcc_push_compare_abc_flag(o.getABCFlagType());
  }

  void OctaveGenerateRtlVisitor::visit(const BANEBFlag &o)
  {
    gcc_push_compare_abc_flag(o.getABCFlagType());
  }

  void OctaveGenerateRtlVisitor::visit(const BAGEBFlag &o)
  {
    gcc_push_compare_abc_flag(o.getABCFlagType());
  }

  void OctaveGenerateRtlVisitor::visit(const BALEBFlag &o)
  {
    gcc_push_compare_abc_flag(o.getABCFlagType());
  }

  void OctaveGenerateRtlVisitor::visit(const Lo17Op &o)
  {
    o.getOpnd()->accept(*this);
    gcc_push_lo17();
  }

  void OctaveGenerateRtlVisitor::visit(const Lo16Op &o)
  {
    o.getOpnd()->accept(*this);
    gcc_push_lo16();
  }

  void OctaveGenerateRtlVisitor::visit(const Hi16Op &o)
  {
    o.getOpnd()->accept(*this);
    gcc_push_hi16();
  }

  void OctaveGenerateRtlVisitor::visit(const ParenthesesOp &o)
  {
    o.getOpnd()->accept(*this);
  }
}








