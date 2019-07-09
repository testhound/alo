#include <sstream>
using namespace std;
#include <M480Instructions.h>
using namespace Llir;

#include "M480GenRtlVisitor.h"
#include "M480RtlPrintVisitor.h"
extern "C" {
#include <llir-gcc-connection.h>
#include <insn-constants.h>
}

namespace Alo
{

  M480GenRtlVisitor::M480GenRtlVisitor(OctaveAlo &i)
    : OctaveGenerateRtlVisitor(i),
      m_lastEssState(ESS_CC_MODE),
      m_essRegName("r66")
  {}

  M480GenRtlVisitor::M480GenRtlVisitor(const M480GenRtlVisitor& rhs)
    : OctaveGenerateRtlVisitor(rhs),
      m_lastEssState(rhs.m_lastEssState),
      m_essRegName(rhs.m_essRegName)
  {}

  const M480GenRtlVisitor&
  M480GenRtlVisitor::operator=(const M480GenRtlVisitor& rhs)
  {
    if(this == &rhs)
      {
	return *this;
      }

    OctaveGenerateRtlVisitor::operator=(rhs);
    m_lastEssState = rhs.m_lastEssState;
    m_essRegName = rhs.m_essRegName;

    return *this;
  }

  void 
  M480GenRtlVisitor::visit(const M480AddInstruction &i)
  {
    if(inFunction())
      {
	//found this insn within a .evh/.entry

	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    //generate RTL for the insn

	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	

	    //if all the registers set in this insn are subsequently unused
	    //and this insn has no implicit writes to memory, generate
	    //a warning to the user specifying that this insn might be
	    //deleted during optimization
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    if(!i.getModFlag()->isNullOperand())
	      {

		//helps in determining whether to generate
		//add insn with a clobber of ESS or set of ESS bits
		//during RTL generation
		bool isEssLive = i.isRegisterLive(REG_ESS);

		//store the affect on flags.
		m_lastEssState = ESS_CCUNS_MODE; 

		gcc_emit_add_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_add_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }

	  }
	else
	  {
	    // **** FIXME : this feature needs to be completed **** //

	    //found this insn in .noopt and .endnopt section of code
	    //emit this insn as an 'asm' to restrict its free movement
	    //in the RTL stream during optimization.
	    //the plan is to still be able to do register allocation.
	    genAsmRtlForInstruction(i);
	  }
      }
    else
      {
	//this is a dangling insn outside a .evh/.entry
	//no need to generate real RTL, no optimization will be
	//done on this insn. just emit it as text in the RTL stream
	//to printed as is to the .s2 file
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480Add4xInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_add4x_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_add4x_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddcInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_addc_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_addc_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddciInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_addci_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_addci_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	    
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_addi_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_addi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480AddlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addl with branch, Use pseudo Op Jaddl",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    // Addli sets all 5 condition code bits
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_MODE;
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    gcc_emit_addl_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480JaddlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	genOperandRtl(i);
	
	// Addl sets all 5 condition code bits
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_MODE;
	
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
	
	gcc_emit_addl_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480AddliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addli instruction with branch, Use pseudo Op Jaddli",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	    
	    // Addli sets all 5 condition code bits
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_MODE;
	  
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
  
	    gcc_emit_addli_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JaddliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	genOperandRtl(i);
	
	// Addli sets all 5 condition code bits
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
	
	gcc_emit_addli_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480AddneInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
    
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	  
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
  
	    gcc_emit_addne_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddneiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    gcc_emit_addnei_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddwhInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addwh instruction with branch, Use pseudo Op Jaddwh",
			       i.getSrcLineNum(), i.getSrcFile());
	    
	    return;
	  }
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    gcc_emit_addwh_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JaddwhInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	genOperandRtl(i);
	
	//store the affect on flags...
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
	
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
	
	gcc_emit_addwh_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    

  void 
  M480GenRtlVisitor::visit(const M480AddwhiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addwhi instruction with branch, Use pseudo Op Jaddwhi",
			       i.getSrcLineNum(), i.getSrcFile());
	    
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    // Addli sets all 5 condition code bits
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_addwhi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480JaddwhiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
	
	//store the affect on flags...
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
	
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_addwhi_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddwlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addwl instruction with branch, Use pseudo Op Jaddwl",
			       i.getSrcLineNum(), i.getSrcFile());

	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    gcc_emit_addwl_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480JaddwlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	genOperandRtl(i);
	
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
	
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
	
	gcc_emit_addwl_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480AddwliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addwli instruction with branch, Use pseudo Op Jaddwli",
			       i.getSrcLineNum(), i.getSrcFile());
	    
	    return;
	  }
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    // Addli sets all 5 condition code bits
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	  
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
  
	    gcc_emit_addwli_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480JaddwliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	
	genOperandRtl(i);
	
	//store the affect on flags...
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
	
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_addwli_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AddwwInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addww instruction with branch, Use pseudo Op Jaddww",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	    
	    gcc_emit_addww_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480JaddwwInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
	
	genOperandRtl(i);
	
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
	
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
        
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
	
	gcc_emit_addww_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    

  void 
  M480GenRtlVisitor::visit(const M480AddwwiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Addwwi instruction, Use pseudo Op Jaddwwi",
			       i.getSrcLineNum(), i.getSrcFile());
	  }

	if (!i.inInstructionSequence())
	  { 
	    genOperandRtl(i);
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    // Addli sets all 5 condition code bits
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	
	    gcc_emit_addwwi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JaddwwiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
   
	genOperandRtl(i);

	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_addwwi_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480AndInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      gcc_emit_and_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	    else
	      gcc_emit_and_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480AndiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_andi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BciInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bci instruction, Use pseudo Op Jbci",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BcrInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bcr instruction, Use pseudo Op Jbcr",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BcdiInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bcdi instruction, Use pseudo Op Jbcdi",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BcdrInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bcdr instruction, Use pseudo Op Jbcdr",
			   i.getSrcLineNum(), i.getSrcFile());
      }

    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbcdiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	genOperandRtl(i);

	checkCFlag(getAlo(), i.getFlags(), i.getSrcLineNum(), i.getSrcFile());

	unsigned int ess = i.getEss()->getFlagNum();
	bool bf_flag = checkBFFlag(i.getFlags());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	if(!i.getDst()->isNullOperand())
	  {
	    unsigned int call_use_regs[64];
	    unsigned int call_return_regs[64];

	    for(unsigned int reg=0; reg <= 63; reg++)
	      {
		call_use_regs[reg]=0;		
		call_return_regs[reg]=0;
	      }

	    FindBranchLabelVisitor v;
	    i.getSrc1()->accept(v);

	    string labelName = v.getBranchTarget();

	    shared_ptr<const PrototypeDirective> proto = 
	      searchForPrototype(i.getSrcLineNum(),
				 i.getSrcFile().c_str(),
				 labelName.c_str());

	    computeCallUseRegSet(proto, call_use_regs);
	    computeCallReturnRegSet(proto, call_return_regs);

	    unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

	    gcc_emit_cond_call_immediate(line,
					 file,
					 ess, 
					 bf_flag, 
					 m_lastEssState, 
					 argNum, 
					 call_use_regs, 
					 call_return_regs, 
					 pr, 
					 i.inInstructionSequence());
	  }
	else
	  {
	    gcc_emit_cbr_immediate(line, 
				   file, 
				   ess, 
				   bf_flag, 
				   m_lastEssState, 
				   pr, 
				   i.inInstructionSequence());				   
	  }

      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbcdrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	//bcdr rsb ESS rpc <- call insn
	//bcdr rpc ESS     <- return insn
	//bcdr rsb ESS     <- jump insn

	i.getSrc1()->accept(*this); // rsb

	if (!i.getDst()->isNullOperand())
	  i.getDst()->accept(*this);  // rpc

	checkCFlag(getAlo(), i.getFlags(), i.getSrcLineNum(), i.getSrcFile());

	shared_ptr<const EssFlag> essFlag = i.getEss();
      
	bool bf_flag = checkBFFlag(i.getFlags());
	unsigned int rsb = i.getSrc1()->getRegNum();
	unsigned int ess = essFlag->getFlagNum();
	bool isNegated = essFlag->isNegated();

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	if (rsb == 60 ||
	    rsb == 61 ||
	    rsb == 62)
	  {
	    // conditional return insn

	    // Make all return insns to branch to a common exit point;
	    const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
	    gcc_push_label(exitLabel);

	    storeReturnReg(i.getSrc1(), line, file);

	    gcc_emit_cond_return_indirect(line,
					  file,
					  ess,
					  m_lastEssState,
					  pr,
					  i.inInstructionSequence());
	  }
	else if (i.getDst()->isNullOperand()) 
	  {
	    // conditional indirect branch insn.

	    gcc_emit_cbr_indirect(line, 
				  file,
				  isNegated, 
				  ess, 
				  bf_flag, 
				  m_lastEssState, 
				  pr,
				  i.inInstructionSequence());				   
	  }
	else 
	  {
	    // RPC specified hence an indirect call insn.

	    shared_ptr<const IndirectCallTargetList> targetList =
	      shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	    if(targetList)
	      {
		unsigned int call_use_regs[64];
		unsigned int call_return_regs[64];

		for(unsigned int reg=0; reg <= 63; reg++)
		  {
		    call_use_regs[reg]=0;
		    call_return_regs[reg]=0;
		  }
	    
		shared_ptr<const LabelList> labelList = targetList->getLabelList();

		//get the first target label name.
		const char* name = labelList->getLabel(0)->getName().c_str();

		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(),
				     i.getSrcFile().c_str(),
				     name);

		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);

		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

		gcc_emit_cond_call_indirect(line,
					    file,
					    isNegated, 
					    ess, 
					    bf_flag, 
					    m_lastEssState, 
					    argNum, 
					    call_use_regs, 
					    call_return_regs,
					    pr,
					    i.inInstructionSequence());
	      }
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbciInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	genOperandRtl(i);

	checkCFlag(getAlo(), i.getFlags(), i.getSrcLineNum(), i.getSrcFile());

	unsigned int ess = i.getEss()->getFlagNum();
	bool bf_flag = checkBFFlag(i.getFlags());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	if(!i.getDst()->isNullOperand())
	  {
	    unsigned int call_use_regs[64];
	    unsigned int call_return_regs[64];

	    for(unsigned int reg=0; reg <= 63; reg++)
	      {
		call_use_regs[reg]=0;		
		call_return_regs[reg]=0;
	      }

	    FindBranchLabelVisitor v;
	    i.getSrc1()->accept(v);

	    string labelName = v.getBranchTarget();

	    shared_ptr<const PrototypeDirective> proto = 
	      searchForPrototype(i.getSrcLineNum(), 
				 i.getSrcFile().c_str(),
				 labelName.c_str());

	    computeCallUseRegSet(proto, call_use_regs);
	    computeCallReturnRegSet(proto, call_return_regs);

	    unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

	    gcc_emit_cond_call_immediate(line,
					 file,
					 ess, 
					 bf_flag, 
					 m_lastEssState, 
					 argNum, 
					 call_use_regs, 
					 call_return_regs, 
					 pr,
					 i.inInstructionSequence());
	  }
	else
	  {
	    gcc_emit_cbr_immediate(line, 
				   file, 
				   ess, 
				   bf_flag, 
				   m_lastEssState,
				   pr,
				   i.inInstructionSequence());				   
	  }

      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void
  M480GenRtlVisitor::visit(const M480JbcrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	//bcr rsb ESS rpc <- call insn
	//bcr rpc ESS     <- return insn
	//bcr rsb ESS     <- jump insn

	i.getSrc1()->accept(*this); // rsb

	if(!i.getDst()->isNullOperand())
	  i.getDst()->accept(*this);  // rpc

	checkCFlag(getAlo(), i.getFlags(), i.getSrcLineNum(), i.getSrcFile());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	shared_ptr<const EssFlag> essFlag =
	  i.getEss();
      
	shared_ptr<const CbranchFlags> cbf =
	  shared_dynamic_cast<const CbranchFlags>(i.getFlags());
        
	bool bf_flag = checkBFFlag(i.getFlags());

	unsigned int rsb = i.getSrc1()->getRegNum();
	unsigned int ess = essFlag->getFlagNum();
	bool isNegated = essFlag->isNegated();

	if (rsb == 60 ||
	    rsb == 61 ||
	    rsb == 62)
	  {

	    // Make all return insns to branch to a common exit point;
	    const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
	    gcc_push_label(exitLabel);

	    storeReturnReg(i.getSrc1(), line, file);

	    gcc_emit_cond_return_indirect(line,
					  file,
					  ess,
					  m_lastEssState,
					  pr,
					  i.inInstructionSequence());
	  }
	else if (i.getDst()->isNullOperand()) 
	  {
	    gcc_emit_cbr_indirect(line,
				  file,
				  isNegated, 
				  ess, 
				  bf_flag, 
				  m_lastEssState, 
				  pr,
				  i.inInstructionSequence());				   
	  }
	else 
	  {
	    // RPC specified hence an indirect call.

	    shared_ptr<const IndirectCallTargetList> targetList =
	      shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());
	
	    if(targetList)
	      {
		unsigned int call_use_regs[64];
		unsigned int call_return_regs[64];
	    
		for(unsigned int reg=0; reg <= 63; reg++)
		  {
		    call_use_regs[reg]=0;
		    call_return_regs[reg]=0;
		  }
	    
		shared_ptr<const LabelList> labelList = targetList->getLabelList();

		//get the first entry label name.
		const char* name = labelList->getLabel(0)->getName().c_str();

		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(), 
				     i.getSrcFile().c_str(),
				     name);

		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);

		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

		gcc_emit_cond_call_indirect(line,
					    file,
					    isNegated, 
					    ess, 
					    bf_flag, 
					    m_lastEssState, 
					    argNum, 
					    call_use_regs, 
					    call_return_regs, 
					    pr,
					    i.inInstructionSequence());
	      }
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BiInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bi instruction, Use pseudo Op Jbi",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	i.getSrc1()->accept(*this);
	i.getDst()->accept(*this);

	bool cd;
	if(!i.getCdFlag()->isNullOperand())
	  cd = true;
	else
	  cd = false;

	if (!i.getDst()->isNullOperand())
	  {
	    unsigned int call_use_regs[64];
	    unsigned int call_return_regs[64];

	    for(unsigned int reg=0; reg <= 63; reg++)
	      {
		call_use_regs[reg]=0;
		call_return_regs[reg]=0;
	      }

	    FindBranchLabelVisitor v;
	    i.getSrc1()->accept(v);

	    string labelName = v.getBranchTarget();
	    if (labelName != "")
	      {
		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getLineNum(), 
				     i.getSrcFile().c_str(),
				     labelName.c_str());

		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);

		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

		gcc_emit_call_insn(line,
				   file,
				   cd, 
				   argNum, 
				   call_use_regs, 
				   call_return_regs, 
				   i.inInstructionSequence());
	      }
	  }
	else
	  {
	    gcc_emit_jump_insn(line, file, cd, i.inInstructionSequence());
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BnziInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bnzi instruction, Use pseudo Op Jbnzi",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void
  M480GenRtlVisitor::visit(const M480JbnziInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	genOperandRtl(i);

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
    

	if(!i.getCmpReg()->isNullOperand())
	  {	
	    unsigned int call_use_regs[64];
	    unsigned int call_return_regs[64];
	
	    for(unsigned int reg=0; reg <= 63; reg++)
	      {
		call_use_regs[reg]=0;		
		call_return_regs[reg]=0;
	      }
	
	    FindBranchLabelVisitor v;
	    i.getSrc2()->accept(v);
	
	    string labelName = v.getBranchTarget();
	    if (labelName != "")
	      {
		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(), 
				     i.getSrcFile().c_str(),
				     labelName.c_str());
	    
		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);
	    
		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.
	    
		gcc_emit_bnzi_call_insn(line, 
					file, 
					argNum, 
					call_use_regs, 
					call_return_regs, 
					pr,
					i.inInstructionSequence());
	      }
	  }
	else
	  {
	    gcc_emit_bnzi_jump_insn(line, file, pr, i.inInstructionSequence());
	  }
      }

    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BnzrInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bnzr instruction, Use pseudo Op Jbnzr",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbnzrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

 
	//bnzr rsa rsb rpc <- call insn
	//bnzr rsa rpc     <- return insn
	//bnzr rsa rsb     <- conditional jump insn
    
	genOperandRtl(i);

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	if(!i.getCmpReg()->isNullOperand())
	  {	
	    // RPC specified hence an indirect call.

	    shared_ptr<const IndirectCallTargetList> targetList =
	      shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	    if(targetList)
	      {
		unsigned int call_use_regs[64];
		unsigned int call_return_regs[64];

		for(unsigned int reg=0; reg <= 63; reg++)
		  {
		    call_use_regs[reg]=0;		
		    call_return_regs[reg]=0;
		  }
	    
		shared_ptr<const LabelList> labelList = targetList->getLabelList();

		//get the first entry label name.
		const char* name = labelList->getLabel(0)->getName().c_str();

		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(), 
				     i.getSrcFile().c_str(),
				     name);

		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);

		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

		gcc_emit_bnzr_call_insn(line, 
					file, 
					argNum, 
					call_use_regs, 
					call_return_regs, 
					pr,
					i.inInstructionSequence());
	      }
	  }
	else
	  {
	    unsigned int rsb = i.getSrc2()->getRegNum();

	    if (rsb == 60 ||
		rsb == 61 ||
		rsb == 62)
	      {
		// Make all return insns to branch to a common exit point;
		const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
		gcc_push_label(exitLabel);

		storeReturnReg(i.getSrc2(), line, file);

		gcc_emit_bnzr_return_insn(line, file, pr, i.inInstructionSequence());
	      }
	    else
	      {
		gcc_emit_bnzr_jump_insn(line, file, pr, i.inInstructionSequence());
	      }
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BrInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Br instruction, Use pseudo Op Jbr",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void
  M480GenRtlVisitor::visit(const M480JtablebrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }


	i.getSrc1()->accept(*this);
	i.getDst()->accept(*this);
    
	gcc_emit_jtablebr(line, file, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void
  M480GenRtlVisitor::visit(const M480JtableRelativebrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }


	i.getSrc1()->accept(*this);
	i.getDst()->accept(*this);
    
	gcc_emit_jtable_relative_br(line, file, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void
  M480GenRtlVisitor::visit(const M480JbrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	i.getSrc1()->accept(*this);

	if (!i.getDst()->isNullOperand())
	  i.getDst()->accept(*this);

	if (i.getDst()->isNullOperand())
	  {
	    // Make all return insns to branch to a common exit point;
	    const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
	    gcc_push_label(exitLabel);

	    unsigned int rpc;
	    shared_ptr<const Register> rpcReg = i.getSrc1();

	    if(rpcReg)
	      {
		rpc = rpcReg->getRegNum();
	    
		if(rpc == 60 ||
		   rpc == 61 ||
		   rpc == 62)
		  {
		    storeReturnReg(i.getSrc1(), line, file);
		  }
	      }

	    gcc_emit_indirect_jump_insn(line, file, i.inInstructionSequence());
	  }
	else
	  {	

	    // RPC specified hence an indirect call.

	    shared_ptr<const IndirectCallTargetList> targetList =
	      shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	    if(targetList)
	      {
		unsigned int call_use_regs[64];
		unsigned int call_return_regs[64];
	
		for(unsigned int reg=0; reg <= 63; reg++)
		  {
		    call_use_regs[reg]=0;		
		    call_return_regs[reg]=0;
		  }
	    
		shared_ptr<const LabelList> labelList = targetList->getLabelList();

		//get the first entry label name.
		const char* name = labelList->getLabel(0)->getName().c_str();

		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(), 
				     i.getSrcFile().c_str(),
				     name);

		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);

		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.

		gcc_emit_indirect_call_insn(line, file, argNum, 
					    call_use_regs, 
					    call_return_regs, 
					    i.inInstructionSequence());
	      }
	
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BrsInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Brs instruction, Use pseudo Op Jbrs",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbrsInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    i.getDst()->accept(*this);  // rpc
	
	    if (i.getDst()->isNullOperand()) 
	      {
		gcc_emit_brs_insn(line, file, i.inInstructionSequence());
	      }
	    else
	      {
		gcc_emit_brs_rpc_insn(line, file, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BrslInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Brsl instruction, Use pseudo Op Jbrsl",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbrslInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    shared_ptr<const BrslFlags> brslFlags =
	      shared_dynamic_cast<const BrslFlags>(i.getBrslFlags());
    
	    bool unlink = false;
	    bool dlink = false;
	    bool flush = false;
	    bool pre = false;

	    if(brslFlags)
	      {
		BrslFlags::ConstIterator citer = brslFlags->begin();

		for(; citer != brslFlags->end(); citer++)
		  {
		    shared_ptr<const UNLNKFlag> unlink_flag =
		      shared_dynamic_cast<const UNLNKFlag>(*citer);
		    if(unlink_flag)
		      {
			unlink = true;
		      }

		    shared_ptr<const DLNKFlag> dlink_flag =
		      shared_dynamic_cast<const DLNKFlag>(*citer);
		    if(dlink_flag)
		      {
			dlink = true;
		      }

		    shared_ptr<const FLUSHFlag> flush_flag =
		      shared_dynamic_cast<const FLUSHFlag>(*citer);
		    if(flush_flag)
		      {
			flush = true;
		      }

		    shared_ptr<const PREFlag> pre_flag =
		      shared_dynamic_cast<const PREFlag>(*citer);
		    if(pre_flag)
		      {
			pre = true;
		      }
		  }
	      }	


	    //now emit brsl as an unspec
	    gcc_emit_brsl_insn(line, file, unlink, dlink, flush, pre, i.inInstructionSequence());

	  }
	else
	  genAsmRtlForInstruction(i);

    
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480BrspreInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    gcc_emit_brspre_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ByteswInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    i.getB3()->accept(*this);
	    i.getB2()->accept(*this);
	    i.getB1()->accept(*this);
	    i.getB0()->accept(*this);
	    i.getDst()->accept(*this);
	    i.getSrc1()->accept(*this);
    
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_bytesw_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }    
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BziInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bzi instruction, Use pseudo Op Jbzi",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbziInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	genOperandRtl(i);
	
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();
	
	if(!i.getCmpReg()->isNullOperand())
	  {
	    unsigned int call_use_regs[64];
	    unsigned int call_return_regs[64];
	    
	    for(unsigned int reg=0; reg <= 63; reg++)
	      {
		call_use_regs[reg]=0;		
		call_return_regs[reg]=0;
	      }
	
	    FindBranchLabelVisitor v;
	    i.getSrc2()->accept(v);
	
	    string labelName = v.getBranchTarget();
	    if (labelName != "")
	      {
		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(), 
				     i.getSrcFile().c_str(),
				     labelName.c_str());
	    
		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);
	    
		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.
	    
		gcc_emit_bzi_call_insn(line, file, argNum, 
				       call_use_regs, 
				       call_return_regs, 
				       pr,
				       i.inInstructionSequence());
	      } 
	  }
	else
	  {
	    gcc_emit_bzi_jump_insn(line, file, pr,i.inInstructionSequence());
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480BzrInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Bzr instruction, Use pseudo Op Jbzr",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480JbzrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

 
	//bzr rsa rsb rpc <- call insn
	//bzr rsa rpc     <- return insn
	//bzr rsa rsb     <- conditional jump insn
    
	genOperandRtl(i);

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	if(!i.getCmpReg()->isNullOperand())
	  {

	    // RPC specified hence an indirect call.

	    shared_ptr<const IndirectCallTargetList> targetList =
	      shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	    if(targetList)
	      {
		unsigned int call_use_regs[64];
		unsigned int call_return_regs[64];
	
		for(unsigned int reg=0; reg <= 63; reg++)
		  {
		    call_use_regs[reg]=0;		
		    call_return_regs[reg]=0;
		  }
	    
		shared_ptr<const LabelList> labelList = targetList->getLabelList();

		//get the first entry label name.
		const char* name = labelList->getLabel(0)->getName().c_str();

		shared_ptr<const PrototypeDirective> proto = 
		  searchForPrototype(i.getSrcLineNum(), 
				     i.getSrcFile().c_str(),
				     name);

		computeCallUseRegSet(proto, call_use_regs);
		computeCallReturnRegSet(proto, call_return_regs);

		unsigned int argNum = computeNumOfArgRegs(proto) * 4; //in bytes.
	    
		gcc_emit_bzr_call_insn(line, file, argNum, 
				       call_use_regs, 
				       call_return_regs, 
				       pr,
				       i.inInstructionSequence());
	      }
	  }
	else
	  {
	    unsigned int rsb = i.getSrc2()->getRegNum();

	    if (rsb == 60 ||
		rsb == 61 ||
		rsb == 62)
	      {
		// Make all return insns to branch to a common exit point;
		const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
		gcc_push_label(exitLabel);

		storeReturnReg(i.getSrc1(), line, file);

		gcc_emit_bzr_return_insn(line, file, pr, i.inInstructionSequence());
	      }
	    else
	      {
		gcc_emit_bzr_jump_insn(line, file, pr, i.inInstructionSequence());
	      }
	  }
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ClrbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_clrb_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

 
  void 
  M480GenRtlVisitor::visit(const M480ClrbiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_clrbi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480CmovInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    unsigned int ess = i.getEssFlag()->getFlagNum();
	    bool isNegated = i.getEssFlag()->isNegated();
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_cmov_insn(line, file, isNegated, ess, m_lastEssState, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480CmoviInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    unsigned int ess = i.getEssFlag()->getFlagNum();
	    bool isNegated = i.getEssFlag()->isNegated();
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_cmovi_insn(line, file, isNegated, ess, m_lastEssState, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480JcmpInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.getAbcFlag()->isNullOperand())
	  {	
	    insnRaiseException("ABC flag not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
	
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CCUNS_MODE;

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();  

	gcc_emit_cmp_branch_insn(line, file, isEssLive, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480CmpInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Cmp with branch target, Use Jcmp", 
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.getAbcFlag()->isNullOperand())
	  {	
	    insnRaiseException("Cannot generate code for Cmp with ABC specified, Use Jcmp",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    m_lastEssState = ESS_CCUNS_MODE;

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Flags set by this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_cmp_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480JcmpiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.getAbcFlag()->isNullOperand())
	  {	
	    insnRaiseException("ABC flag not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);

	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CCUNS_MODE;

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_cmpi_branch_insn(line, file, isEssLive, pr,i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480CmpiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Cmpi with branch target, Use Jcmpi", 
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.getAbcFlag()->isNullOperand())
	  {	
	    insnRaiseException("Cannot generate code for Cmpi with ABC specified, Use Jcmpi",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }
    
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    m_lastEssState = ESS_CCUNS_MODE;
	    
	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Flags set by this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_cmpi_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  
  void 
  M480GenRtlVisitor::visit(const M480CmprInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	//abc is not real ABC it is a type of compare flag...
    
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const AbcCompareFlag> abcFlag = 
	      shared_dynamic_cast<const AbcCompareFlag>(i.getAbcFlag());
	
	    shared_ptr<const SignFlag> signFlag =
	      shared_dynamic_cast<const SignFlag>(i.getSign());
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
    
	    bool sign = false;
	
	    if(signFlag)
	      sign = true;

	    AbcCompareFlag::Abc_Compare_t abc;

	    if(abcFlag)
	      {
		abc = abcFlag->getABCFlagType();
	      }
	    else
	      {
		abc = AbcCompareFlag::BAEB;
	      }


	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_cmpr_insn(line, file, isEssLive, abc, sign, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480CmpriInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	//abc is not real ABC it is a type of compare flag...

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    shared_ptr<const AbcCompareFlag> abcFlag = 
	      shared_dynamic_cast<const AbcCompareFlag>(i.getAbcFlag());

	
	    shared_ptr<const SignFlag> signFlag =
	      shared_dynamic_cast<const SignFlag>(i.getSign());
	
	    //store the affect on flags...
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	
	    bool sign = false;

	    if(signFlag)
	      sign = true;

	    AbcCompareFlag::Abc_Compare_t abc;

	    if(abcFlag)
	      {
		abc = abcFlag->getABCFlagType();
	      }
	    else
	      {
		abc = AbcCompareFlag::BAEB;
	      }
	    gcc_emit_cmpri_insn(line, file, isEssLive, abc, sign, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
    
  void 
  M480GenRtlVisitor::visit(const M480DepbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool Z;

	    genOperandRtl(i);
	
	    if (i.getDepbFlag()->isNullOperand())
	      Z = false;
	    else
	      Z = true;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_depb_insn(line, file, Z, lnk, mem, i.inInstructionSequence());
	
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
   
  void 
  M480GenRtlVisitor::visit(const M480DepbiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool Z;

	    genOperandRtl(i);

	    if (i.getDepbFlag()->isNullOperand())
	      Z = false;
	    else
	      Z = true;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
    
	    gcc_emit_depbi_insn(line, file, Z, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480DmapInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    gcc_emit_dmap_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480DmasrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    gcc_emit_dmasr_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480Dmau0Instruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    gcc_emit_dmau0_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480Dmau1Instruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	    
	    gcc_emit_dmau1_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ExtbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool SIGN_flag;

	    genOperandRtl(i);

	    if (i.getSignFlag()->isNullOperand())
	      SIGN_flag = false;
	    else
	      SIGN_flag = true;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_extb_insn(line, file, SIGN_flag, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480FfsInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool ZB;

	    genOperandRtl(i);

	    checkAbcFlag(getAlo(), i.getAbcFlag(), i.getSrcLineNum(), i.getSrcFile());
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	
	    if (i.getFindFlag()->isNullOperand())
	      ZB = false;
	    else
	      ZB = true;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_ffs_insn(line, file, isEssLive, ZB, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480FlsInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();
	
	if (!i.inInstructionSequence())
	  {
	    bool ZB;

	    genOperandRtl(i);

	    checkAbcFlag(getAlo(), i.getAbcFlag(), i.getSrcLineNum(), i.getSrcFile());
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	
	    if (i.getFindFlag()->isNullOperand())
	      ZB = false;
	    else
	      ZB = true;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_fls_insn(line, file, isEssLive, ZB, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480GetInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool RSCH_flag = false;
	    bool CLOSE_flag = false;
	    bool A_flag = false;
	    bool FPB_flag = false;
	    bool NT_flag = false;
	    bool NB_flag = false;
	    bool NC_flag = false;
	    bool S_flag = false;
	    bool CSB_flag = false;
	    bool DELETE_flag = false;
	    bool T_flag = false;

	    i.getRsa()->accept(*this);

	    shared_ptr<const TrafficScheduleFlags> tssFlags =
	      shared_dynamic_cast<const TrafficScheduleFlags>(i.getTssFlags());
	
	    if (tssFlags)
	      {
		TrafficScheduleFlags::ConstIterator citer = tssFlags->begin();
	
		for (; citer != tssFlags->end(); citer++)
		  {
		    if (shared_dynamic_cast<const RSCHFlag>(*citer))
		      RSCH_flag = true;

		    if (shared_dynamic_cast<const CLOSEFlag>(*citer))
		      CLOSE_flag = true;

		    if (shared_dynamic_cast<const AFlag>(*citer))
		      A_flag = true;
		
		    if (shared_dynamic_cast<const FPBFlag>(*citer))
		      FPB_flag = true;

		    if (shared_dynamic_cast<const NTFlag>(*citer))
		      NT_flag = true;
		
		    if (shared_dynamic_cast<const NBFlag>(*citer))
		      NB_flag = true;
		
		    if (shared_dynamic_cast<const NCFlag>(*citer))
		      NC_flag = true;
		
		    if (shared_dynamic_cast<const SFlag>(*citer))
		      S_flag = true;

		    if (shared_dynamic_cast<const CSBFlag>(*citer))
		      CSB_flag = true;
		
		    if (shared_dynamic_cast<const DELETEFlag>(*citer))
		      DELETE_flag = true;

		    if (shared_dynamic_cast<const TFlag>(*citer))
		      T_flag = true;
		  }
	      }

	    gcc_emit_get_insn_v4(line, file, 
				 RSCH_flag, CLOSE_flag, A_flag, FPB_flag, NT_flag, 
				 NB_flag, NC_flag, S_flag, CSB_flag, DELETE_flag, T_flag,
				 i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480Hec5Instruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

 
	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Hec5 instruction with branch, Use pseudo Op Jhec5",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    bool CUME_flag;

	    i.getBranchTarget()->accept(*this);
	    i.getBytes()->accept(*this);
	    i.getSrc1()->accept(*this);
	    i.getDst()->accept(*this);
	
	    if (i.getCumeFlag()->isNullOperand())
	      CUME_flag = false;
	    else
	      CUME_flag = true;
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }	
	
	    if(i.getBranchTarget()->isNullOperand())
	      {
		gcc_emit_hec5_insn(line, file, isEssLive, CUME_flag, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JHec5Instruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

 
	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch Target Not Provided",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    bool CUME_flag;
	  
	    i.getBranchTarget()->accept(*this);
	    i.getBytes()->accept(*this);
	    i.getSrc1()->accept(*this);
	    i.getDst()->accept(*this);
	  
	    if (i.getCumeFlag()->isNullOperand())
	      CUME_flag = false;
	    else
	      CUME_flag = true;
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	  	
	    gcc_emit_hec5_br_insn(line, file, isEssLive, CUME_flag, lnk, mem, i.inInstructionSequence());
	  
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  //laih,lail,lih,lil insns can accept expns as src operands
  //  insn rN hi16(expN) (or)
  //  insn rN lo16(expN) (or)
  //  insn rN lo17(expN) (or)
  //  insn rN expN
  //in each case expN can be made of +/- operators
  //and label, signed and unsigned immediate operands.

  //calling accept method on src operand
  //pushes source expr rtx onto stack top which is
  //used in alo-parse.c

  void 
  M480GenRtlVisitor::visit(const M480LaihInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    unsigned int rd = i.getDst()->getRegNum();
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(rd);
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd);
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_laih_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }  
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LailInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    unsigned int rd = i.getDst()->getRegNum();
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(rd);
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd);

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_lail_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LihInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    unsigned int rd = i.getDst()->getRegNum();
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(rd);
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd);

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_lih_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LilInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    unsigned int rd = i.getDst()->getRegNum();
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(rd);
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd);

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_lil_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinkInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_ANY, lnk, i.getRegs());
	
	    genLinkInsn(excLine, excFile, LINK, i.getMem(), lnk, i.inInstructionSequence());
	  } 
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinksInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());
	
	    genLinkInsn(excLine, excFile, LINKS, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinkspInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());
    
	    genLinkInsn(excLine, excFile, LINKSP, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480LinksplInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();

	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM_LOCKED, lnk, i.getRegs());

	    genLinkInsn(excLine, excFile, LINKSPL, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinksrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SRAM, lnk, i.getRegs());
	
	    genLinkInsn(excLine, excFile, LINKSR, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinksdInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SDRAM, lnk, i.getRegs());

	    genLinkInsn(excLine, excFile, LINKSD, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinkccInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_CCRAM, lnk, i.getRegs());

	    genLinkInsn(excLine, excFile, LINKCC, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480LinkcclInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
    
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();

	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_CCRAM_LOCKED, lnk, i.getRegs());

	    genLinkInsn(excLine, excFile, LINKCCL, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LinksioInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
	    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
	
	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SIO, lnk, i.getRegs());
    
	    genLinkInsn(excLine, excFile, LINKSIO, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmInstruction &i)
  {
    if(inFunction())
      {
	if (!i.inInstructionSequence())
	  {
	    unsigned int excLine = i.getSrcLineNum();
	    const char* excFile = i.getSrcFile().c_str();

	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());

	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }


	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", excLine, excFile);
	      }

	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_ANY, lnk, i.getRegs());

	    genInsn(excLine, excFile, LMM, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmspInstruction &i)
  {
    if(inFunction())
      {
	unsigned int excLine = i.getSrcLineNum();
	const char* excFile = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }


	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", excLine, excFile);
	      }

	    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());

	    genInsn(excLine, excFile, LMMSP, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmsplInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {    
	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());

	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }


	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_SPRAM_LOCKED, lnk, i.getRegs());

	    genInsn(line, file, LMMSPL, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmsrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }
	

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_SRAM, lnk, i.getRegs());

	    genInsn(line, file, LMMSR, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmsdInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }


	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_SDRAM, lnk, i.getRegs());
	
	    genInsn(line, file, LMMSD, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmccInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());

	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }
	

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_CCRAM, lnk, i.getRegs());
    
	    genInsn(line, file, LMMCC, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmcclInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }
	

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_CCRAM_LOCKED, lnk, i.getRegs());

	    genInsn(line, file, LMMCCL, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480LmmsiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }
	

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_SIO, lnk, i.getRegs());

	    genInsn(line, file, LMMSIO, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480LmmsInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;
	
	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }
	

	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());
	
	    genInsn(line, file, LMMS, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

 
  void 
  M480GenRtlVisitor::visit(const M480LspInstruction &i)
  {   
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    shared_ptr<const LinkFlag> linkFlag = 
	      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
	
	    LinkFlag::Link_Flag_t lnk;

	    if(linkFlag)
	      {
		lnk = linkFlag->getLinkFlagType();
	      }
	    else
	      {
		lnk = LinkFlag::CLEARLINK;
	      }


	    if(! i.setRegistersLive())
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    updateLinkInfo(line, file, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());

	    genInsn(line, file, LSP, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void
  M480GenRtlVisitor::visit(const M480LwihInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    i.getDst()->accept(*this);
	    i.getSrc()->accept(*this);

	    unsigned int rd = i.getDst()->getRegNum();

	    LinkFlag::Link_Flag_t lnk = getRegLink(rd);
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd);


	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_lwih_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void
  M480GenRtlVisitor::visit(const M480LwilInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    i.getDst()->accept(*this);
	    i.getSrc()->accept(*this);

	    unsigned int rd = i.getDst()->getRegNum();

	    LinkFlag::Link_Flag_t lnk = getRegLink(rd);
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd);

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_lwil_insn(line, file, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MaxInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());


	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE; 
		gcc_emit_max_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;   
		gcc_emit_max_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MaxiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
    

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_maxi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MinInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());


	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_min_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_min_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MiniInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_mini_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MulInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool sx = isSigned(i);

	    genOperandRtl(i);

	    gcc_emit_mul_insn(line, file, sx, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MuliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool sx = isSigned(i);
	
	    genOperandRtl(i);
	
	    gcc_emit_muli_insn(line, file, sx, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MulhInstruction &i)
  {   
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool sx = isSigned(i);

	    genOperandRtl(i);

	    gcc_emit_mulh_insn(line, file, sx, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MulhiInstruction &i)
  {   
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    bool sx = isSigned(i);

	    genOperandRtl(i);

	    gcc_emit_mulhi_insn(line, file, sx, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MvInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    i.getSrc()->accept(*this);
	    i.getDst()->accept(*this);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_mv_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MvhrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
    
	    shared_ptr<const MvhFlag> cNFlag =
	      shared_dynamic_cast<const MvhFlag>(i.getMvhFlag());

	    unsigned int cN = 0;
		
	    if(cNFlag)
	      {
		cN = cNFlag->getCNValue();
	      }
		
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
		
	    gcc_emit_mvhr_insn(line, file, cN, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480MvrhInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
		
	    shared_ptr<const MvhFlag> cNFlag =
	      shared_dynamic_cast<const MvhFlag>(i.getMvhFlag());
		
	    unsigned int cN = 0;
		
	    if(cNFlag)
	      {
		cN = cNFlag->getCNValue();
	      }
    
	    gcc_emit_mvrh_insn(line, file, cN, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480NopInstruction &i)
  {    
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    gcc_emit_nop_insn(line, file, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480OrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
		
	    //store the affect on flags...
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
		
	    if(!i.getModFlag()->isNullOperand())
	      gcc_emit_or_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	    else
	      gcc_emit_or_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480OriInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_ori_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ParInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {    
	    i.getSrc1()->accept(*this);
	    i.getDst()->accept(*this);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_par_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480PutcInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  { 
	    bool GZ_flag = false;
	    bool A_flag = false;
	    bool FP_flag = false;
	    bool OAM_flag = false;
	    bool NB_flag = false;
	    bool RP_flag = false;
	    bool I_flag = false;
	    bool FR_flag = false;
	    bool GR_flag = false;
	    bool GU_flag = false;
	    bool LOG_flag = false;

	    i.getRsa()->accept(*this);
	    i.getRsb()->accept(*this);
	
	    shared_ptr<const TrafficScheduleFlags> tssFlags =
	      shared_dynamic_cast<const TrafficScheduleFlags>(i.getTssFlags());

	    if (tssFlags)
	      {
		TrafficScheduleFlags::ConstIterator citer = tssFlags->begin();
	    
		for (; citer != tssFlags->end(); citer++)
		  {
		    if (shared_dynamic_cast<const GZFlag>(*citer))
		      GZ_flag = true;
		
		    if (shared_dynamic_cast<const AFlag>(*citer))
		      A_flag = true;
		
		    if (shared_dynamic_cast<const FPFlag>(*citer))
		      FP_flag = true;
		
		    if (shared_dynamic_cast<const OAMFlag>(*citer))
		      OAM_flag = true;
		
		    if (shared_dynamic_cast<const NBFlag>(*citer))
		      NB_flag = true;

		    if (shared_dynamic_cast<const RPFlag>(*citer))
		      RP_flag = true;

		    if (shared_dynamic_cast<const IFlag>(*citer))
		      I_flag = true;

		    if (shared_dynamic_cast<const FRFlag>(*citer))
		      FR_flag = true;

		    if (shared_dynamic_cast<const GRFlag>(*citer))
		      GR_flag = true;

		    if (shared_dynamic_cast<const GUFlag>(*citer))
		      GU_flag = true;

		    shared_ptr<const LOGFlag> log =
		      shared_dynamic_cast<const LOGFlag>(*citer);

		    if (shared_dynamic_cast<const LOGFlag>(*citer))
		      LOG_flag = true;
		  }

		gcc_emit_putc_insn_v4(line, file,
				      GZ_flag, A_flag, FP_flag, OAM_flag, NB_flag, RP_flag, 
				      I_flag, FR_flag, GR_flag, GU_flag, LOG_flag,
				      i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480PutmInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  { 
	    bool FP_flag = false;
	    bool FR_flag = false;
	    bool GR_flag = false;
	    bool GU_flag = false;
	    bool GW_flag = false;
	    bool GZ_flag = false;
	    bool NB_flag = false;
	    bool NC_flag = false;
	    bool R_flag = false;
	    bool I_flag = false;

	    i.getRsa()->accept(*this);
	    i.getRsb()->accept(*this);
	
	    shared_ptr<const TrafficScheduleFlags> tssFlags =
	      shared_dynamic_cast<const TrafficScheduleFlags>(i.getTssFlags());
	
	    if (tssFlags)
	      {
		TrafficScheduleFlags::ConstIterator citer = tssFlags->begin();
	    
		for (; citer != tssFlags->end(); citer++)
		  {
		    if (shared_dynamic_cast<const FPFlag>(*citer))
		      FP_flag = true;
		
		    if (shared_dynamic_cast<const FRFlag>(*citer))
		      FR_flag = true;
		
		    if (shared_dynamic_cast<const GRFlag>(*citer))
		      GR_flag = true;
		
		    if (shared_dynamic_cast<const GUFlag>(*citer))
		      GU_flag = true;
		
		    if (shared_dynamic_cast<const GWFlag>(*citer))
		      GW_flag = true;
		
		    if (shared_dynamic_cast<const GZFlag>(*citer))
		      GZ_flag = true;
		
		    if (shared_dynamic_cast<const NBFlag>(*citer))
		      NB_flag = true;
		
		    if (shared_dynamic_cast<const NCFlag>(*citer))
		      NC_flag = true;
		
		    if (shared_dynamic_cast<const RFlag>(*citer))
		      R_flag = true;
		
		    if (shared_dynamic_cast<const IFlag>(*citer))
		      I_flag = true;
		  }
	    
		gcc_emit_putm_insn(line, file, FP_flag, FR_flag, GR_flag, GU_flag, GW_flag, 
				   GZ_flag, NB_flag, NC_flag, R_flag, I_flag,
				   i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480PutpInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  { 
	    bool GZ_flag = false;
	    bool A_flag = false;
	    bool FP_flag = false;
	    bool OAM_flag = false;
	    bool NB_flag = false;
	    bool RP_flag = false;
	    bool I_flag = false;
	    bool FR_flag = false;
	    bool GR_flag = false;
	    bool GU_flag = false;
	    bool LOG_flag = false;
	
	    i.getRsa()->accept(*this);
	    i.getRsb()->accept(*this);
	
	    shared_ptr<const TrafficScheduleFlags> tssFlags =
	      shared_dynamic_cast<const TrafficScheduleFlags>(i.getTssFlags());
	
	    if (tssFlags)
	      {
		TrafficScheduleFlags::ConstIterator citer = tssFlags->begin();
	    
		for (; citer != tssFlags->end(); citer++)
		  {
		    if (shared_dynamic_cast<const GZFlag>(*citer))
		      GZ_flag = true;
		
		    if (shared_dynamic_cast<const AFlag>(*citer))
		      A_flag = true;
		
		    if (shared_dynamic_cast<const FPFlag>(*citer))
		      FP_flag = true;
		
		    if (shared_dynamic_cast<const OAMFlag>(*citer))
		      OAM_flag = true;
		
		    if (shared_dynamic_cast<const NBFlag>(*citer))
		      NB_flag = true;

		    if (shared_dynamic_cast<const RPFlag>(*citer))
		      RP_flag = true;

		    if (shared_dynamic_cast<const IFlag>(*citer))
		      I_flag = true;

		    if (shared_dynamic_cast<const FRFlag>(*citer))
		      FR_flag = true;

		    if (shared_dynamic_cast<const GRFlag>(*citer))
		      GR_flag = true;

		    if (shared_dynamic_cast<const GUFlag>(*citer))
		      GU_flag = true;

		    shared_ptr<const LOGFlag> log =
		      shared_dynamic_cast<const LOGFlag>(*citer);
		
		    if (shared_dynamic_cast<const LOGFlag>(*citer))
		      LOG_flag = true;
		  }

		gcc_emit_putp_insn(line, file, GZ_flag, A_flag, FP_flag, OAM_flag, NB_flag, RP_flag, 
				   I_flag, FR_flag, GR_flag, GU_flag, LOG_flag,
				   i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480PutdInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  { 
	    bool GZ_flag = false;
	    bool A_flag = false;
	    bool FP_flag = false;
	    bool OAM_flag = false;
	    bool NB_flag = false;
	    bool RP_flag = false;
	    bool I_flag = false;
	    bool FR_flag = false;
	    bool GR_flag = false;
	    bool GU_flag = false;
	    bool LOG_flag = false;
	
	    i.getRsa()->accept(*this);
	    i.getRsb()->accept(*this);
	
	    shared_ptr<const TrafficScheduleFlags> tssFlags =
	      shared_dynamic_cast<const TrafficScheduleFlags>(i.getTssFlags());
	
	    if (tssFlags)
	      {
		TrafficScheduleFlags::ConstIterator citer = tssFlags->begin();
	    
		for (; citer != tssFlags->end(); citer++)
		  {
		    if (shared_dynamic_cast<const GZFlag>(*citer))
		      GZ_flag = true;
		
		    if (shared_dynamic_cast<const AFlag>(*citer))
		      A_flag = true;
		
		    if (shared_dynamic_cast<const FPFlag>(*citer))
		      FP_flag = true;
		
		    if (shared_dynamic_cast<const OAMFlag>(*citer))
		      OAM_flag = true;
		
		    if (shared_dynamic_cast<const NBFlag>(*citer))
		      NB_flag = true;

		    if (shared_dynamic_cast<const RPFlag>(*citer))
		      RP_flag = true;

		    if (shared_dynamic_cast<const IFlag>(*citer))
		      I_flag = true;

		    if (shared_dynamic_cast<const FRFlag>(*citer))
		      FR_flag = true;

		    if (shared_dynamic_cast<const GRFlag>(*citer))
		      GR_flag = true;

		    if (shared_dynamic_cast<const GUFlag>(*citer))
		      GU_flag = true;

		    shared_ptr<const LOGFlag> log =
		      shared_dynamic_cast<const LOGFlag>(*citer);
		
		    if (shared_dynamic_cast<const LOGFlag>(*citer))
		      LOG_flag = true;
		  }

		// FIXME: Add PUTD to GCC, fix this call.
		gcc_emit_putp_insn(line, file, GZ_flag, A_flag, FP_flag, OAM_flag, NB_flag, RP_flag, 
				   I_flag, FR_flag, GR_flag, GU_flag, LOG_flag,
				   i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RandInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_rand_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RandiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_randi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RintInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Rint instruction, Use pseudo Op Jrint",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JrintInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	// Make all return insns to branch to a common exit point;
	const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
	gcc_push_label(exitLabel);


	if (!i.inInstructionSequence())
	  {
   
	    shared_ptr<const DIFlag> diFlag =
	      shared_dynamic_cast<const DIFlag>(i.getDiFlag());
	
	    bool DI = false;
	
	    if(diFlag)
	      DI = true;
	
	    gcc_emit_rint_insn(line, file, DI, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RnmiInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Rnmi instruction, Use pseudo Op Jrnmi",
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JrnmiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	// Make all return insns to branch to a common exit point;
	const char* exitLabel = getCurrentFunction()->getExitLabel().c_str();
	gcc_push_label(exitLabel);

	if (!i.inInstructionSequence())
	  {
	    shared_ptr<const DIFlag> diFlag =
	      shared_dynamic_cast<const DIFlag>(i.getDiFlag());

	    bool DI = false;

	    if(diFlag)
	      DI = true;

	    gcc_emit_rnmi_insn(line, file, DI, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RotlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
   
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_rotl_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RotliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
   
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_rotli_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RotrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_rotr_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480RotriInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_rotri_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }    
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SetbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_setb_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }

    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  void 
  M480GenRtlVisitor::visit(const M480SetbiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
 
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_setbi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShftInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shft_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShftaInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
    
	    gcc_emit_shfta_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shl_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shli_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
 
  void 
  M480GenRtlVisitor::visit(const M480ShrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shr_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShriInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shri_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShraInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shra_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480ShraiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;
  
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_shrai_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;
	
	    genInsn(line, file, SMM, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmsInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;

	    genInsn(line, file, SMMS, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmspInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;

	    genInsn(line, file, SMMSP, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmsplInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;
    
	    genInsn(line, file, SMMSPL, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmsrInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;

	    genInsn(line, file, SMMSR, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmsdInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;

	    genInsn(line, file, SMMSD, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmccInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;

	    genInsn(line, file, SMMCC, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmcclInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;
    
	    genInsn(line, file, SMMCCL, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
  
  void 
  M480GenRtlVisitor::visit(const M480SmmsiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;
	
	    genInsn(line, file, SMMSIO, i.getMem(), lnk, i.inInstructionSequence());
	  } 
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SspInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk;
	    lnk = LinkFlag::NOLINK;
	
	    genInsn(line, file, SSP, i.getMem(), lnk, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_sub_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_sub_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {     
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());


	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_subb_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_subb_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubbiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {     
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_subbi_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_subbi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());


	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CCUNS_MODE;
		gcc_emit_subi_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	    else
	      {
		bool isEssLive = i.isRegisterLive(REG_ESS);
		m_lastEssState = ESS_CC_MODE;
		gcc_emit_subi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	      }
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SublInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subl instruction with branch, Use pseudo Op Jsubl",
			       i.getSrcLineNum(), i.getSrcFile());
	
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());


	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }
	
	    gcc_emit_subl_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsublInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_MODE;

	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subl_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subli instruction with branch, Use pseudo Op Jsubli",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subli_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_MODE;

	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
 
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subli_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubwhInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subwh instruction with branch, Use pseudo Op Jsubwh",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subwh_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubwhInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subwh_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }


  void 
  M480GenRtlVisitor::visit(const M480SubwhiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subwhi instruction with branch, Use pseudo Op Jsubwhi",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

       
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subwhi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubwhiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
        
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subwhi_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubwlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subwl instruction, Use pseudo Op Jsubwl",
			       i.getSrcLineNum(), i.getSrcFile());
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	       
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subwl_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubwlInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
    
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subwl_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubwliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subwli instruction, Use pseudo Op Jsubwli",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }


	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	       
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subwli_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubwliInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);

	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;

	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
        
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subwli_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubwwInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subww instruction, Use pseudo Op Jsubww",
			       i.getSrcLineNum(), i.getSrcFile());

	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	       
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subww_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubwwInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
        
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subww_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480SubwwiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(!i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Cannot generate code for Subwwi instruction, Use pseudo Op Jsubwwi",
			       i.getSrcLineNum(), i.getSrcFile());

	    return;
	  }

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);
	
	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CC_CY_MODE;
	
	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	       
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_subwwi_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JsubwwiInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if(i.getBranchTarget()->isNullOperand())
	  {
	    insnRaiseException("Branch target not specified",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);
    
	bool isEssLive = i.isRegisterLive(REG_ESS);
	m_lastEssState = ESS_CC_CY_MODE;
    
	LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
        
	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	gcc_emit_subwwi_br_insn(line, file, isEssLive, lnk, mem, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480TclrbInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Tclrb instruction, Use pseudo Op Jclrb", 
			   i.getSrcLineNum(), i.getSrcFile());
      } 
    else
      {
	genRtlForGlobalInsn(i);
      }
  }
 
  void 
  M480GenRtlVisitor::visit(const M480JtclrbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);

	bool isEssLive = i.isRegisterLive(REG_ESS);

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	m_lastEssState = ESS_CCUNS_MODE;

	gcc_emit_tclrb_br_insn(line, file, isEssLive, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480TsetbInstruction &i)
  {
    if(inFunction())
      {
	insnRaiseException("Cannot generate code for Tsetb instruction, Use pseudo Op Jtsetb", 
			   i.getSrcLineNum(), i.getSrcFile());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480JtsetbInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (i.inInstructionSequence())
	  {
	    insnRaiseException("Cannot place branch insns in the noreorder region",
			       i.getSrcLineNum(), i.getSrcFile());
	    return;
	  }

	genOperandRtl(i);    

	OctaveInstruction::BranchProbability pr = i.getBranchProbability();

	bool isEssLive = i.isRegisterLive(REG_ESS);

	m_lastEssState = ESS_CCUNS_MODE;

	gcc_emit_tsetb_br_insn(line, file, isEssLive, pr, i.inInstructionSequence());
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480UnlinkInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    shared_ptr<const MultiRegister> mRegs = i.getRegs();

	    unsigned int count = mRegs->getNumRegs();

	    unsigned int rd1 = mRegs->getFirstRegNum();
	    unsigned int rdN = rd1 + count - 1;

	    unsigned int reg;
	    for(reg = rd1; reg <= rdN; reg++)
	      {
		setRegLink(reg, LinkFlag::NOLINK);
	      }
	
	    gcc_emit_unlink_insn(line, file, count, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480XorInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    if(!i.getModFlag()->isNullOperand())
	      gcc_emit_xor_modx_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	    else
	      gcc_emit_xor_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::visit(const M480XoriInstruction &i)
  {
    if(inFunction())
      {
	unsigned int line = i.getSrcLineNum();
	const char* file = i.getSrcFile().c_str();

	if (!i.inInstructionSequence())
	  {
	    genOperandRtl(i);

	    bool isEssLive = i.isRegisterLive(REG_ESS);
	    m_lastEssState = ESS_CCUNS_MODE;

	    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
	    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
       
	    if(! i.setRegistersLive() && lnk == LinkFlag::NOLINK)
	      {
		insnRaiseWarning("Destination operands of this insn are unused subsequently, insn might get deleted", line, file);
	      }

	    gcc_emit_xori_insn(line, file, isEssLive, lnk, mem, i.inInstructionSequence());
	  }
	else
	  genAsmRtlForInstruction(i);
      }
    else
      {
	genRtlForGlobalInsn(i);
      }
  }

  void 
  M480GenRtlVisitor::genRtlForGlobalInsn(const LlirInstruction &insn)
  {
    ostringstream d_stream;
    M480RtlPrintVisitor pv(d_stream);
    insn.accept(pv);

    gcc_emit_global_asm_directive((d_stream.str()).c_str());
  }

  void 
  M480GenRtlVisitor::updateLinkInfo(unsigned int excLine,
				    const char* excFile,
				    OctaveMemory::MemType_t  mem,
				    LinkFlag::Link_Flag_t lnk,
				    shared_ptr<const MultiRegister> mRegs)
  {
    unsigned int rd1 = mRegs->getFirstRegNum();
    unsigned int rdN = rd1 + mRegs->getNumRegs() - 1;


    if(rdN > 63)
      {
	//Note: links can only be set between hard registers and memory

	//generating rtl for lmm/smm instruction containing
	//pseudo registers... make sure that lnk flag is 
	//not specified in such instructions

	if(lnk == LinkFlag::LNK1 || 
	   lnk == LinkFlag::LNK2 ||
	   lnk == LinkFlag::LNK3)
	  {
	    OctaveAlo& alo = getAlo();
	    char *excStr = new char[128];
	    shared_ptr<std::exception> exc; 
	    
	    sprintf(excStr, "Cannot associate memory links to pseudo registers");
	    exc = shared_ptr<IllegalInsn> 
	      (new IllegalInsn(excStr, excLine, excFile, __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      }

    if(lnk != LinkFlag::NOLINK)
      {
	if(lnk == LinkFlag::CLEARLINK)
	  {
	    for(unsigned int reg = rd1; reg <= rdN; reg++)
	      {
		setRegLink(reg, LinkFlag::NOLINK);
		setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_ANY);
	      }
	  }
	else 
	  {
	    //set links...
	    for(unsigned int reg = rd1; reg <= rdN; reg++)
	      {
		setRegLink(reg, lnk);
		setRegisterLinkedMemoryType(reg, mem);
	      }
	  }
      }
  }



  void
  M480GenRtlVisitor::genInsn(unsigned int line,
			     const char* file, 
			     RTL_INSN insn,
			     shared_ptr<const OctaveMemory> mem,
			     LinkFlag::Link_Flag_t lnk,
			     unsigned int inSequence)
  {

    //This is needed to access correct index gen fn
    if(lnk == LinkFlag::CLEARLINK)
      lnk = LinkFlag::NOLINK;

    shared_ptr<const RegPlusOffsetIndirect> regOffset =
      shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);

    shared_ptr<const Base2PlusOffset> base2Offset =
      shared_dynamic_cast<const Base2PlusOffset>(mem);

    shared_ptr<const Base3PlusOffset> base3Offset =
      shared_dynamic_cast<const Base3PlusOffset>(mem);

    shared_ptr<const ImpliedBase2Offset> impOffset = 
      shared_dynamic_cast<const ImpliedBase2Offset>(mem);

    if (impOffset)
      {
	// This is a "plain" offset argument that will become a BASE2 in the backend assembler.
	// convert it to a Base2PlusOffset.  Similar hack used in M4?0SemanticVisitor.cpp .
	assert(!base2Offset);
	base2Offset = shared_ptr<Base2PlusOffset>  (new Base2PlusOffset(impOffset->getOffset()));
      }

    if(regOffset)
      {
	if(insn == LMM || insn == SMM)
	  {
	    insnRaiseWarning("Unknown memory region for smm. Please use smm pseudo-op indicating memory region.",
			     line, file);
	  }

	gcc_emit_reg_offset_insn(line, file, insn, lnk, inSequence);
      }
    else if(base2Offset)
      {
	gcc_emit_base2_offset_insn(line, file, insn, lnk, inSequence);
      }
    else if(base3Offset)
      {
	gcc_emit_base3_offset_insn(line, file, insn, lnk, inSequence);
      }
  }


  void
  M480GenRtlVisitor::genLinkInsn(unsigned int line,
				 const char* file,
				 RTL_INSN insn,
				 shared_ptr<const OctaveMemory> mem,
				 LinkFlag::Link_Flag_t lnk,
				 unsigned int inSequence)
  {
    shared_ptr<const RegPlusOffsetIndirect> regOffset =
      shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);
    
    shared_ptr<const Base2PlusOffset> base2Offset =
      shared_dynamic_cast<const Base2PlusOffset>(mem);

    shared_ptr<const Base3PlusOffset> base3Offset =
      shared_dynamic_cast<const Base3PlusOffset>(mem);


    if(regOffset)
      {
	if(insn == LINKS)
	  gcc_emit_links_reg_offset_insn(line, file, insn, lnk, inSequence);
	else
	  gcc_emit_link_reg_offset_insn(line, file, insn, lnk, inSequence);
      }
    else if(base2Offset)
      {
	gcc_emit_link_base2_offset_insn(line, file, insn, lnk, inSequence);
      }
    else if(base3Offset)
      {
	gcc_emit_link_base3_offset_insn(line, file, insn, lnk, inSequence);
      }
  }

  void
  M480GenRtlVisitor::checkAbcFlag(OctaveAlo &alo,
				  shared_ptr<const LlirOperand> opnd, 
				  unsigned int excLine,
				  const string &excFile) const
  {
    shared_ptr<std::exception> exc; 

    shared_ptr<const AbcFlag> abcFlag = 
      shared_dynamic_cast<const AbcFlag>(opnd);
   
    if(abcFlag)
      {    
	char *excStr = new char[128];
	sprintf(excStr, "Cannot generate code for ABC Instructions");
	exc = shared_ptr<IllegalInsn> 
	  (new IllegalInsn(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }

  void
  M480GenRtlVisitor::checkCFlag(OctaveAlo &alo,
				shared_ptr<const LlirOperand> opnd, 
				unsigned int excLine,
				const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
      
    shared_ptr<const CbranchFlags> cbf =
      shared_dynamic_cast<const CbranchFlags> (opnd);

    bool cFlag = false;

    if(cbf)
      {

	CbranchFlags::ConstIterator cbfIter = cbf->begin();
	
	for(; cbfIter != cbf->end(); cbfIter++)
	  {
	    shared_ptr<const CFlag> cflag = shared_dynamic_cast<const CFlag>(*cbfIter);
	    if(cflag)
	      {
		cFlag = true;
	      }
	  }
      }
   
    if(cFlag)
      {    
	char *excStr = new char[128];
	sprintf(excStr, "Cannot generate code for branch instructions with C flag");
	exc = shared_ptr<IllegalInsn> 
	  (new IllegalInsn(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }

  bool
  M480GenRtlVisitor::checkBFFlag(shared_ptr<const LlirOperand> opnd) const
  {
    shared_ptr<std::exception> exc; 
      
    shared_ptr<const CbranchFlags> cbf =
      shared_dynamic_cast<const CbranchFlags> (opnd);

    if(cbf)
      {

	CbranchFlags::ConstIterator cbfIter = cbf->begin();
	
	for(; cbfIter != cbf->end(); cbfIter++)
	  {
	    shared_ptr<const BFFlag> bf_flag = shared_dynamic_cast<const BFFlag>(*cbfIter);
	    if(bf_flag)
	      {
		return true;
	      }
	  }
      }

    return false;
  }

  bool 
  M480GenRtlVisitor::isSigned(const Alu3OpSxInstruction &i)
  {
    if(i.getSxFlag()->isNullOperand())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  void
  M480GenRtlVisitor::genOperandRtl(const MvhOpInstruction &i)
  {
    i.getSrc()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const M480AddneInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const M480AddneiInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const Alu3OpSxInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const Alu3OpAbcInstruction &i)
  {
    checkAbcFlag(getAlo(), i.getAbcFlag(), i.getSrcLineNum(), i.getSrcFile());
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const Alu3OpAbcModInstruction &i)
  {
    checkAbcFlag(getAlo(), i.getAbcFlag(), i.getSrcLineNum(), i.getSrcFile());
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
    i.getModFlag()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const Alu2OpBranchInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getDst()->accept(*this);
    i.getBranchTarget()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const Alu2OpFindInstruction &i)
  {	
    i.getSrc1()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const TestBitBranchInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getBitpos()->accept(*this);
    i.getDisp()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const ZeroBranchImmedInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getCmpReg()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const ZeroBranchInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getCmpReg()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const CmovOpInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const CompareOpSignInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const CompareOpBranchInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getSrc2()->accept(*this);
    i.getBranchTarget()->accept(*this);
    i.getAbcFlag()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const MultiRegLinkInstruction &i)
  {
    i.getRegs()->accept(*this);
    i.getMem()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const MultiRegLoadInstruction &i)
  {
    i.getRegs()->accept(*this);
    i.getMem()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const MultiRegStoreInstruction &i)
  {
    i.getRegs()->accept(*this);
    i.getMem()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const CondBranchImmedInstruction &i)
  {
    i.getSrc1()->accept(*this);
    i.getEss()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const DmaOpInstruction &i)
  {
    i.getRegs()->getRegister(0)->accept(*this);
    i.getDmaFlags()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const BitOpInstruction &i)
  {
    i.getNumBits()->accept(*this);
    i.getSrcBitNum()->accept(*this);
    i.getSrc1()->accept(*this);
    i.getDstBitNum()->accept(*this);
    i.getDst()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const BitOpImmInstruction &i)
  {
    i.getNumBits()->accept(*this);    
    i.getSrc1()->accept(*this);       
    i.getDstBitNum()->accept(*this);  
    i.getDst()->accept(*this);        
  }

  void
  M480GenRtlVisitor::genOperandRtl(const LoadImmediateInstruction &i)
  {
    i.getDst()->accept(*this);
    i.getSrc()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const LoadHalfwordInstruction &i)
  {
    i.getDst()->accept(*this);
    i.getSrc()->accept(*this);
  }

  void
  M480GenRtlVisitor::genOperandRtl(const M480UnlinkInstruction &i)
  {
    unsigned int reg;

    unsigned int count = i.getRegs()->getNumRegs();

    for(reg=0; reg < count; reg++)
      {
	i.getRegs()->getRegister(reg)->accept(*this);
      }
  }

  void
  M480GenRtlVisitor::storeReturnReg(shared_ptr<const Register> reg, unsigned int line, const char* file)
  {
    shared_ptr<const Register> retReg = getCurrentFunction()->getReturnReg();

    shared_ptr<const NullRegister> nullReg = 
      shared_dynamic_cast<const NullRegister>(retReg);

    if(!nullReg)
      {
	if(retReg->getRegNum() != reg->getRegNum())
	  {
	    insnRaiseException("Multiple Return Registers used in the current function", line, file);
	    return;
	  }
      }

    getCurrentFunction()->storeReturnReg(reg);
  }


  void
  M480GenRtlVisitor::insnRaiseException(const char *error, unsigned int excLine, const string& excFile)
  {
    OctaveAlo& alo = getAlo();
    shared_ptr<std::exception> exc; 
	
    ostringstream excStr;
    excStr << error;
    exc = shared_ptr<IllegalInsn> 
      (new IllegalInsn(excStr.str().c_str(), excLine, excFile.c_str(), __LINE__, __FILE__));
    alo.logException(exc);
  }

  void
  M480GenRtlVisitor::insnRaiseWarning(const char *warning_str, unsigned int warningLine, const string& warningFile)
  {
    OctaveAlo& alo = getAlo();
    shared_ptr<std::exception> warnException; 
	
    ostringstream warningStr;
    warningStr << warning_str;
    warnException = shared_ptr<WarningDirectiveException> 
      (new WarningDirectiveException(warningStr.str().c_str(), warningLine, warningFile.c_str(), __LINE__, __FILE__));
    alo.logException(warnException);
  }

  void
  M480GenRtlVisitor::logSeqOperandException(unsigned int excLine, const string& excFile)
  {
    ostringstream excStr;
    shared_ptr<std::exception> exc;

    excStr << "Symbolic register is illegal for instructions in restricted or committed slot regions";
    exc = shared_ptr<IllegalInsn> 
      (new IllegalInsn(excStr.str().c_str(), excLine, excFile.c_str(), __LINE__, __FILE__));
    getAlo().logException(exc);
  }


  //////////////////////////////////////
  //
  // Asm RTL Generation
  //
  /////////////////////////////////////

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const Alu2OpBranchInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_alu2op_arith_asm_insn (i_stream.str().c_str(), 
				    lnk, 
				    mem,
				    i.getSrcFile().c_str(),
				    i.getSrcLineNum());
  }



  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const Alu2OpFindInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_alu2op_find_asm_insn (i_stream.str().c_str(), 
				   lnk, 
				   mem,
				   i.getSrcFile().c_str(),
				   i.getSrcLineNum());
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const Alu3OpAbcInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    genOperandRtl(i);
    
    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_alu3op_abc_asm_insn (i_stream.str().c_str(), 
				  lnk, 
				  mem,
				  i.getSrcFile().c_str(),
				  i.getSrcLineNum()); 
  }
			
  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const Alu3OpAbcModInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
   
    genOperandRtl(i);
    
    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_alu3op_abc_mod_asm_insn (i_stream.str().c_str(), 
				      lnk, 
				      mem,
				      i.getSrcFile().c_str(),
				      i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const Alu3OpSxInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    genOperandRtl(i);
    
    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_alu3op_sx_asm_insn (i_stream.str().c_str(), 
				 lnk, 
				 mem,
				 i.getSrcFile().c_str(),
				 i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const DmaOpInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    gcc_emit_dmaop_asm_insn (i_stream.str().c_str(),
			     i.getSrcFile().c_str(),
			     i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const BitOpInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    gcc_emit_bitop_asm_insn(i_stream.str().c_str(),
			    i.getSrcFile().c_str(),
			    i.getSrcLineNum()); 
  }


  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const BitOpImmInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    gcc_emit_bitop_imm_asm_insn(i_stream.str().c_str(),
				i.getSrcFile().c_str(),
				i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const CompareOpBranchInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    gcc_emit_cmp_asm_insn(i_stream.str().c_str(),
			  i.getSrcFile().c_str(),
			  i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const CompareOpSignInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    gcc_emit_cmpr_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const MultiRegLoadInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());

    //if no link flag is specified it implies to clear
    //existing links to registers
    LinkFlag::Link_Flag_t lnk = LinkFlag::CLEARLINK;
    
    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    
    updateLinkInfo(i.getSrcLineNum(), i.getSrcFile().c_str(), OctaveMemory::MEMTYPE_ANY, lnk, i.getRegs());

    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const RegPlusOffsetIndirect> regOffset =
      shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);

    shared_ptr<const Base2PlusOffset> base2Offset =
      shared_dynamic_cast<const Base2PlusOffset>(mem);

    shared_ptr<const Base3PlusOffset> base3Offset =
      shared_dynamic_cast<const Base3PlusOffset>(mem);

    shared_ptr<const ImpliedBase2Offset> impOffset = 
      shared_dynamic_cast<const ImpliedBase2Offset>(mem);

    if (impOffset)
      {
	// This is a "plain" offset argument that will become a BASE2 in the backend assembler.
	// convert it to a Base2PlusOffset.  Similar hack used in M4?0SemanticVisitor.cpp .
	assert(!base2Offset);
	base2Offset = shared_ptr<Base2PlusOffset>  (new Base2PlusOffset(impOffset->getOffset()));
      }

    if(regOffset)
      {
	gcc_emit_load_reg_offset_asm_insn(lnk, 
					  i_stream.str().c_str(),
					  i.getSrcFile().c_str(),
					  i.getSrcLineNum());
      }
    else if(base2Offset)
      {
	gcc_emit_load_base2_offset_asm_insn(lnk, 
					    i_stream.str().c_str(),
					    i.getSrcFile().c_str(),
					    i.getSrcLineNum());
      }
    else if(base3Offset)
      {
	gcc_emit_load_base3_offset_asm_insn(lnk, 
					    i_stream.str().c_str(),
					    i.getSrcFile().c_str(),
					    i.getSrcLineNum());
      }
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const MultiRegStoreInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const RegPlusOffsetIndirect> regOffset =
      shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);

    shared_ptr<const Base2PlusOffset> base2Offset =
      shared_dynamic_cast<const Base2PlusOffset>(mem);

    shared_ptr<const Base3PlusOffset> base3Offset =
      shared_dynamic_cast<const Base3PlusOffset>(mem);

    shared_ptr<const ImpliedBase2Offset> impOffset = 
      shared_dynamic_cast<const ImpliedBase2Offset>(mem);

    if (impOffset)
      {
	// This is a "plain" offset argument that will become a BASE2 in the backend assembler.
	// convert it to a Base2PlusOffset.  Similar hack used in M4?0SemanticVisitor.cpp .
	assert(!base2Offset);
	base2Offset = shared_ptr<Base2PlusOffset>  (new Base2PlusOffset(impOffset->getOffset()));
      }

    if(regOffset)
      {
	gcc_emit_store_reg_offset_asm_insn(i_stream.str().c_str(),
					   i.getSrcFile().c_str(),
					   i.getSrcLineNum());
      }
    else if(base2Offset)
      {
	gcc_emit_store_base2_offset_asm_insn(i_stream.str().c_str(),
					     i.getSrcFile().c_str(),
					     i.getSrcLineNum());
      }
    else if(base3Offset)
      {
	gcc_emit_store_base3_offset_asm_insn(i_stream.str().c_str(),
					     i.getSrcFile().c_str(),
					     i.getSrcLineNum());
      }
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const MultiRegLinkInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    shared_ptr<const OctaveMemory> mem = i.getMem();

	
    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    
    updateLinkInfo(i.getSrcLineNum(), i.getSrcFile().c_str(), OctaveMemory::MEMTYPE_ANY, lnk, i.getRegs());

    shared_ptr<const RegPlusOffsetIndirect> regOffset =
      shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);
    
    shared_ptr<const Base2PlusOffset> base2Offset =
      shared_dynamic_cast<const Base2PlusOffset>(mem);

    shared_ptr<const Base3PlusOffset> base3Offset =
      shared_dynamic_cast<const Base3PlusOffset>(mem);

    if(regOffset)
      {
	gcc_emit_link_reg_offset_asm_insn(lnk,   
					  i_stream.str().c_str(),
					  i.getSrcFile().c_str(),
					  i.getSrcLineNum());
      }
    else if(base2Offset)
      {
	gcc_emit_link_base2_offset_asm_insn(lnk,   
					    i_stream.str().c_str(),
					    i.getSrcFile().c_str(),
					    i.getSrcLineNum());
      }
    else if(base3Offset)
      {
	gcc_emit_link_base3_offset_asm_insn(lnk,   
					    i_stream.str().c_str(),
					    i.getSrcFile().c_str(),
					    i.getSrcLineNum());
      }
  }


  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const LoadImmediateInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    genOperandRtl(i);
    
    gcc_emit_load_op_imm_asm_insn(i_stream.str().c_str(),
				  i.getSrcFile().c_str(),
				  i.getSrcLineNum());
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const LoadHalfwordInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    genOperandRtl(i);
    
    gcc_emit_load_op_hword_asm_insn(i_stream.str().c_str(),
				    i.getSrcFile().c_str(),
				    i.getSrcLineNum());
  }


  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const CmovOpInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    genOperandRtl(i);
    
    gcc_emit_cmov_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480AddneInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_addne_asm_insn (i_stream.str().c_str(), 
			     lnk, 
			     mem,
			     i.getSrcFile().c_str(),
			     i.getSrcLineNum());
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480AddneiInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    genOperandRtl(i);

    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_addnei_asm_insn (i_stream.str().c_str(), 
			      lnk, 
			      mem,
			      i.getSrcFile().c_str(),
			      i.getSrcLineNum());
  }
	
  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480JbrsInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getDst()->accept(*this);  // rpc

    gcc_emit_jbrs_asm_insn (i_stream.str().c_str(), 
			    i.getSrcFile().c_str(),
			    i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480NopInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    gcc_emit_nop_asm_insn (i_stream.str().c_str(), 
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480ParInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getSrc1()->accept(*this);
    i.getDst()->accept(*this);
	
    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());
	
    gcc_emit_par_asm_insn (i_stream.str().c_str(), 
			   lnk,
			   mem,
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480JbrslInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    gcc_emit_jbrsl_asm_insn (i_stream.str().c_str(), 
			     i.getSrcFile().c_str(),
			     i.getSrcLineNum()); 

  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480BrspreInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    gcc_emit_brspre_asm_insn (i_stream.str().c_str(), 
			      i.getSrcFile().c_str(),
			      i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480ByteswInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    i.getB3()->accept(*this);
    i.getB2()->accept(*this);
    i.getB1()->accept(*this);
    i.getB0()->accept(*this);
    i.getDst()->accept(*this);
    i.getSrc1()->accept(*this);

    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_bytesw_asm_insn (i_stream.str().c_str(), 
			      lnk,
			      mem,
			      i.getSrcFile().c_str(),
			      i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480JrnmiInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    gcc_emit_jrnmi_asm_insn (i_stream.str().c_str(), 
			     i.getSrcFile().c_str(),
			     i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480JrintInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    gcc_emit_jrint_asm_insn (i_stream.str().c_str(), 
			     i.getSrcFile().c_str(),
			     i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480MvInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    // Mv is really Ori rsa 0 rd. 
    // We simulate this by pushing const_int 0 on stack

    i.getSrc()->accept(*this);
    gcc_push_unsigned_immediate (0);
    i.getDst()->accept(*this);

    LinkFlag::Link_Flag_t lnk = getRegLink(i.getDst()->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(i.getDst()->getRegNum());

    gcc_emit_alu3op_abc_asm_insn (i_stream.str().c_str(), 
				  lnk, 
				  mem,
				  i.getSrcFile().c_str(),
				  i.getSrcLineNum()); 
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480PutmInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getRsa()->accept(*this);
    i.getRsb()->accept(*this);

    gcc_emit_putm_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());

  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480UnlinkInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    genOperandRtl(i);

    gcc_emit_unlink_asm_insn(i_stream.str().c_str(),
			     i.getSrcFile().c_str(),
			     i.getSrcLineNum());
  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480PutcInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getRsa()->accept(*this);
    i.getRsb()->accept(*this);

    gcc_emit_putc_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());

  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480PutpInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getRsa()->accept(*this);
    i.getRsb()->accept(*this);

    gcc_emit_putp_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());

  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480PutdInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getRsa()->accept(*this);
    i.getRsb()->accept(*this);

    // FIXME: Implement putd in GCC, fix this call.
    gcc_emit_putp_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());

  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480GetInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);

    i.getRsa()->accept(*this);

    gcc_emit_get_asm_insn(i_stream.str().c_str(),
			  i.getSrcFile().c_str(),
			  i.getSrcLineNum());
  }


  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480MvrhInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    i.getSrc()->accept(*this);
    i.getDst()->accept(*this);
    
    gcc_emit_mvrh_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());

  }

  void
  M480GenRtlVisitor::genAsmRtlForInstruction(const M480MvhrInstruction &i)
  {
    ostringstream i_stream;
    M480RtlPrintVisitor iv(i_stream);
    i.accept(iv);
    
    i.getSrc()->accept(*this);
    i.getDst()->accept(*this);
    
    gcc_emit_mvhr_asm_insn(i_stream.str().c_str(),
			   i.getSrcFile().c_str(),
			   i.getSrcLineNum());
  }


}

																											
