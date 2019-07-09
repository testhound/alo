#include <string>
#include <exception>
#include <cassert>

#include <Alo.h>
#include <LlirException.h>

#include "M480Instructions.h"
#include "M480SemanticVisitor.h"

//externs...
using namespace Llir;
extern int optimize;  // Defined in gcc/gcc/toplev.c 
extern std::map<string, shared_ptr<const PrototypeDirective> > g_prototypeDirList;
typedef std::map<string, shared_ptr<const PrototypeDirective> >::iterator PrototypeListIter;



namespace Alo
{
  //////////////////////////////////////////
  //
  // M480SemanticAnalysisVisitor functions
  //
  //////////////////////////////////////////
 
  M480SemanticAnalysisVisitor::M480SemanticAnalysisVisitor(OctaveAlo &o) 
    : OctaveSemanticAnalysisVisitor(o)
  {}
 
  
  M480SemanticAnalysisVisitor::~M480SemanticAnalysisVisitor()
  {}
  
  //////////////////////////////////////////
  //private utility functions
  //////////////////////////////////////////

  void
  M480SemanticAnalysisVisitor::
  checkForValidLabel(OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const OpndLabel> opndLabel = shared_dynamic_cast<const OpndLabel>(opnd);

    // Only do this check if optimization is on.
    if ((optimize) && (! opndLabel))
      {
	char *excStr = new char[128];
	sprintf(excStr, "illegal label operand");
	    exc = shared_ptr<IllegalLabelOperand> 
	      (new IllegalLabelOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
      }
  }
  

  void
  M480SemanticAnalysisVisitor::
  checkForReturnRegister(OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);
    shared_ptr<const Register> regOpnd = shared_dynamic_cast<const Register>(opnd);

    if(! nullOpnd)
      {
	if(regOpnd)
	  {
	    unsigned int rpc = regOpnd->getRegNum();
	    if((rpc < 60) || (rpc > 62))
	      {
		 char *excStr = new char[128];
		 sprintf(excStr, "illegal RPC Register: r%d", rpc);
		 exc = shared_ptr<IllegalRegisterOperand> 
		   (new IllegalRegisterOperand
		    (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		 alo.logException(exc);
		 delete excStr;
	      }
	  }
	else
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "illegal RPC register operand");
	    exc = shared_ptr<IllegalRegisterOperand> 
	      (new IllegalRegisterOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      }
  }


 void
  M480SemanticAnalysisVisitor::
  checkForValidCDFlag(OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);
    shared_ptr<const CDFlag> cdFlag = shared_dynamic_cast<const CDFlag>(opnd);

    if(! (nullOpnd || cdFlag))
      {
	char *excStr = new char[128];
	sprintf(excStr, "unknown cd flag");
	    exc = shared_ptr<IllegalLabelOperand> 
	      (new IllegalLabelOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
      }
  }

  void
  M480SemanticAnalysisVisitor::
  checkForValidESSFlag(OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);
    shared_ptr<const EssFlag> essFlag = shared_dynamic_cast<const EssFlag>(opnd);

    if(! (nullOpnd || essFlag))
      {
	char *excStr = new char[128];
	sprintf(excStr, "unknown ess flag");
	    exc = shared_ptr<IllegalLabelOperand> 
	      (new IllegalLabelOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
      }
  }
  void
  M480SemanticAnalysisVisitor::
  checkForValidCandBfFlags(OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);
    shared_ptr<const CbranchFlags> cbranchFlags = shared_dynamic_cast<const CbranchFlags>(opnd);


    if(! (nullOpnd || cbranchFlags))
      {
	char *excStr = new char[128];
	sprintf(excStr, "unknown cbranch flag");
	    exc = shared_ptr<IllegalLabelOperand> 
	      (new IllegalLabelOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
      }
  }

  
  void
  M480SemanticAnalysisVisitor::
  checkSImm17Range (OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
    {
      shared_ptr<const Lo16Op> lo16;
      shared_ptr<const Hi16Op> hi16;
      shared_ptr<const Lo17Op> lo17;
      shared_ptr<const SignedImmediate> imm;
      if (lo16 = shared_dynamic_cast<const Lo16Op>(opnd))
	{
	  shared_ptr<const OctaveUnaryExpr> expr 
	    = shared_static_cast<const OctaveUnaryExpr>(opnd);
	  imm = shared_dynamic_cast<const SignedImmediate>(expr->getOpnd());
	  if (imm) 
	    {
	      checkSImmRange(imm, 16, alo, excLine, excFile);
	    }
	}
      else if (hi16 = shared_dynamic_cast<const Hi16Op>(opnd))
	{
	  shared_ptr<const OctaveUnaryExpr> expr 
	    = shared_static_cast<const OctaveUnaryExpr>(opnd);
	  imm = shared_dynamic_cast<const SignedImmediate>(expr->getOpnd());
	  if(imm)
	    {
	      checkSImmRange(imm, 16, alo, excLine, excFile);
	    }
	}
      else if (lo17 = shared_dynamic_cast<const Lo17Op>(opnd))
	{
	  shared_ptr<const OctaveUnaryExpr> 
	    expr = shared_static_cast<const OctaveUnaryExpr>(opnd);
	  imm = shared_dynamic_cast<const SignedImmediate>(expr->getOpnd());
	  if (imm)
	    {
	    checkSImmRange(imm, 17, alo, excLine, excFile);
	    }
	}
      else // No check as we assume the operand is another well formed expression
	;
    }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkSImmRange (shared_ptr<const LlirOperand> opnd, 
		  unsigned int bits,
		  OctaveAlo &alo,
		  unsigned int excLine,
		  const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const SignedImmediate> simm 
      = shared_dynamic_cast<const SignedImmediate>(opnd);
    if(simm)
      {
	unsigned long val = (unsigned long) simm->getValue();
	unsigned long mask1 = 0x1 << (bits - 1);
	unsigned long mask2 = 0xffff << bits;
	if (((val & mask1 == mask1) && (val & mask2 != mask2))
	    ||
	    ((val & mask1 == 0    ) && (val & mask2 != 0    )))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "value %ld exceeeds %d signed bits range", 
		    val, bits); 
	    exc = shared_ptr<OutOfRangeOperand> 
	      (new OutOfRangeOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } 
    else 
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where immediate was expected");
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkUImm16Range (OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
    {
      shared_ptr<const Lo16Op> lo16;
      shared_ptr<const Hi16Op> hi16;
      shared_ptr<const UnsignedImmediate> imm;
      
      if (lo16 = shared_dynamic_cast<const Lo16Op>(opnd))
	{
	  shared_ptr<const OctaveUnaryExpr> expr 
	    = shared_static_cast<const OctaveUnaryExpr>(opnd);
	  imm = shared_dynamic_cast<const UnsignedImmediate>(expr->getOpnd());
	  if (imm)
	    {
	      checkSImmRange(imm, 16, alo, excLine, excFile);
	    }
	}
      else if (hi16 = shared_dynamic_cast<const Hi16Op>(opnd))
	{
	  shared_ptr<const OctaveUnaryExpr> expr 
	    = shared_static_cast<const OctaveUnaryExpr>(opnd);
	  imm = shared_dynamic_cast<const UnsignedImmediate>(expr->getOpnd());
	  if (imm)
	    {
	      checkSImmRange(imm, 16, alo, excLine, excFile);
	    }
	}
      else // No check as we assume the operand is another well formed expression
	;
    }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkUImmRange (shared_ptr<const LlirOperand> opnd, 
		  unsigned int bits,
		  OctaveAlo &alo,
		  unsigned int excLine,
		  const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const UnsignedImmediate> uimm 
      = shared_dynamic_cast<const UnsignedImmediate>(opnd);
    if(uimm)
      {
	unsigned long val = uimm->getValue();
	unsigned long max = 0x1 << bits;
	if (!(val <= max))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "value %ld exceeds %d bits range", val, bits); 
	    exc = shared_ptr<OutOfRangeOperand> 
	      (new OutOfRangeOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } 
    else 
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where immediate was expected");
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkAlignment (shared_ptr<const LlirOperand> opnd, 
		  unsigned int unit,
		  OctaveAlo &alo,
		  unsigned int excLine,
		  const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const UnsignedImmediate> uimm 
      = shared_dynamic_cast<const UnsignedImmediate>(opnd);
    if(uimm)
      {
	unsigned long val = uimm->getValue();
	if (val % unit != 0)
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "value %ld not aligned on %d bit boundary", 
		    val, unit);   
	    exc = shared_ptr<OutOfRangeOperand> 
	      (new OutOfRangeOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } 
    else 
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where immediate was expected");
      }
  }
  
  // Check that the register operand is either a pseudo register or a register in the range r0-127
  void
  M480SemanticAnalysisVisitor::
  checkOctaveRegister (shared_ptr<const LlirOperand> opnd,
		 OctaveAlo &alo,
		 unsigned int excLine,
		 const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const Register> reg 
      = shared_dynamic_cast<const Register>(opnd);
    if(reg)
      {
	if (reg->isPseudo())
	  return;

	unsigned int regNum = reg->getRegNum(); 
	if (regNum < 0 || regNum > 128)
	  {  
	    char *excStr = new char[128];
	    sprintf(excStr, "register r%d is not a octave register (r0-r127)", regNum);
	    exc = shared_ptr<IllegalRegisterOperand> 
	      (new IllegalRegisterOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } 
    else 
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");
      }
  }
  
  // Check that the register operand is either a pseudo register or a software register in the range r0-r63

  void
  M480SemanticAnalysisVisitor::
  checkRegister (shared_ptr<const LlirOperand> opnd,
		 OctaveAlo &alo,
		 unsigned int excLine,
		 const string &excFile) const
  {
    shared_ptr<const Register> reg 
      = shared_dynamic_cast<const Register>(opnd);
    if(reg)
      {
	if (reg->isPseudo())
	  return;

	unsigned int regNum = reg->getRegNum(); 
	if (regNum > 63)
	  {  
	    shared_ptr<std::exception> exc; 
	    char *excStr = new char[128];
	    sprintf(excStr, "register r%d is not a sofware register (r0-r63)", regNum);
	    exc = shared_ptr<IllegalRegisterOperand> 
	      (new IllegalRegisterOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } 
    else 
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkMultiRegister (shared_ptr<const MultiRegister> regs,
		      OctaveAlo &alo,
		      unsigned int excLine,
		      const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    int regFirst = (int)regs->getRegNum(); 
    int regLast = regFirst + (int)regs->getNumRegs() - 1; 

    if (regFirst > 63 && regFirst < 128)
      {  
	char *excStr = new char[128];
	sprintf(excStr, "register range starts illegally at r%d", regFirst);
	exc = shared_ptr<IllegalRegisterOperand> 
	  (new IllegalRegisterOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }

    if (regLast > 63 && regLast < 128)
      {  
	char *excStr = new char[128];
	sprintf(excStr, "register range extends illegally to r%d", regLast);
	exc = shared_ptr<IllegalRegisterOperand> 
	  (new IllegalRegisterOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }

    unsigned int numRegs = regs->getNumRegs();

    if(numRegs > 16)
      {
	char *excStr = new char[128];
	sprintf(excStr, "register range spans more than 16 registers : %d", numRegs);
	exc = shared_ptr<IllegalRegisterOperand> 
	  (new IllegalRegisterOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkRegisterPair (shared_ptr<const MultiRegister> regs,
		     OctaveAlo &alo,
		     unsigned int excLine,
		     const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    unsigned int regFirst = regs->getRegNum(); 
    unsigned int regNum = regs->getNumRegs();

    if (regNum > 2) // Accept a single register as well as a 2 register multi-register
      {  
	char *excStr = new char[128];
	sprintf(excStr, "DMA register range can only be 2 registers, not %d", regNum);
	exc = shared_ptr<IllegalRegisterOperand> 
	  (new IllegalRegisterOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      } 
    if (regFirst > 63 && regFirst < 128)
      {  
	char *excStr = new char[128];
	sprintf(excStr, "register pair starts out of range at r%d", regFirst);
	exc = shared_ptr<IllegalRegisterOperand> 
	  (new IllegalRegisterOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
    if (regFirst % 2 != 0)
      {  
	char *excStr = new char[128];
	sprintf(excStr, "First DMA register must be even - r%d is odd", regFirst);
	exc = shared_ptr<IllegalRegisterOperand> 
	  (new IllegalRegisterOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkBranchRegister (shared_ptr<const LlirOperand> opnd,
		       OctaveAlo &alo,
		       unsigned int excLine,
		       const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const Register> reg 
      = shared_dynamic_cast<const Register>(opnd);
    if(reg)
      {
	if (reg->isPseudo())
	  return;

	if (!isNullReg(reg))
	  {
	    unsigned int regNum = reg->getRegNum(); 
	    if (regNum < 60 || regNum > 62)
	      {   
		char *excStr = new char[128];
		sprintf(excStr, "register r%d should be r60, r61 or r62", regNum);
		exc = shared_ptr<IllegalRegisterOperand> 
		  (new IllegalRegisterOperand
		   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		alo.logException(exc);
		delete excStr;
	      }
	  }
      } 
    else
      LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkHwRegister (shared_ptr<const LlirOperand> opnd,
		   OctaveAlo &alo,
		   unsigned int excLine,
		   const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const Register> reg 
      = shared_dynamic_cast<const Register>(opnd);
    if(reg)
      {
	unsigned int regNum = reg->getRegNum();
	if (regNum < 64 || regNum > 127)
	  {  
	    char *excStr = new char[128];
	    sprintf(excStr, "register r%d is not a h/w register", regNum);
	    exc = shared_ptr<IllegalRegisterOperand> 
	      (new IllegalRegisterOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } else {
	shared_ptr<const OpndNull> nil 
	  = shared_dynamic_cast<const OpndNull>(opnd);
	if (!nil)
	  {

	    LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");

	  }
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkMemory (shared_ptr<const OctaveMemory> mem,
	       MemoryRegion memregion,
	       unsigned int regOffBits,
	       unsigned int basOffBits,
	       OctaveAlo &alo,
	       unsigned int excLine,
	       const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    shared_ptr<const Register> reg;
    shared_ptr<const LlirOperand> offexp = mem->getOffset();
    shared_ptr<const RegPlusOffsetIndirect> regoff
      = shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);
    shared_ptr<const ImpliedBase2Offset> impoff
      = shared_dynamic_cast<const ImpliedBase2Offset>(mem);
    shared_ptr<const BasePlusOffset> basoff
      = shared_dynamic_cast<const BasePlusOffset>(mem);

    if (impoff)
      {
	assert(!basoff);
	// This is a "plain" offset argument that will become a BASE2 in the backend assembler.
	// convert it to a Base2PlusOffset, via a BasePlusOffset ptr, and test it as such for 
	// the remainder of this function.
	basoff = shared_ptr<const BasePlusOffset> (new Base2PlusOffset(impoff->getOffset()));
      }


    if (regoff)
      {
	reg = regoff->getBaseRegister();
	unsigned int regNum = reg->getRegNum(); 
	if (regNum > 63 && regNum < 128)
	  {  
	    char *excStr = new char[128];
	    sprintf(excStr, "register r%d is not a s/w register", regNum);
	    exc = shared_ptr<IllegalRegisterOperand> 
	      (new IllegalRegisterOperand
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
	shared_ptr<const SignedImmediate> 
	  si = shared_dynamic_cast<const SignedImmediate>(offexp);
	if(si)
	  {
	    long off = si->getValue();
	    // mask1 lets through the sign bit alone
	    // mask2 lets through the bits higher the sign bit
	    unsigned long mask1 = 0x1 << (regOffBits - 1);
	    unsigned long mask2 = 0xffff << regOffBits;
	    // if the sign bit is 1, the bits higher than it must be 1
	    // if the sign bit is 0, the bits higher than it must be zero
	    // anything else is an erroneous value
	    if (((off & mask1 == mask1) && (off & mask2 != mask2))
		||
		((off & mask1 == 0    ) && (off & mask2 != 0    )))
	      {
		char *excStr = new char[128];
		sprintf(excStr, "value %ld exceeeds %d signed bits range", 
			off, regOffBits); 
		exc = shared_ptr<OutOfRangeOperand> 
		  (new OutOfRangeOperand
		   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		alo.logException(exc);
		delete excStr;
	      }
	  }
	// no check at compile time if the operand is an expression
      }
    if (basoff)
      {
	// base plus offset memory expressions are allowed only within
	// certain memory regions, and then only for a certain base

	checkMemoryRegion (basoff,
			   memregion,
			   alo,
			   excLine,
			   excFile);
	
	// max is the power of two just above the maximum value 
	// that can be contained in the bit field
	
	long max = 0x1 << basOffBits;
	shared_ptr<const UnsignedImmediate> 
	  usi = shared_dynamic_cast<const UnsignedImmediate>(offexp);
	if(usi)
	  {
	    long off = usi->getValue();
	    if (!(off <= max))
	      {
		char *excStr = new char[128];
		sprintf(excStr, "value %ld exceeds %d bits range", 
			off, basOffBits); 
		exc = shared_ptr<OutOfRangeOperand> 
		  (new OutOfRangeOperand
		   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		alo.logException(exc);
		delete excStr;
	      }
	  }
	// no check at compile time, if the operand is an expression
      }

    if (regoff || basoff)
      {
	checkAlignment(offexp, 4, alo, excLine, excFile);
      }
    else
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkMemoryRegion (shared_ptr<const BasePlusOffset> basoff,
		     MemoryRegion memreg,
		     OctaveAlo &alo,
		     unsigned int excLine,
		     const string &excFile) const
  {
    shared_ptr<std::exception> exc;
    shared_ptr<const Base2PlusOffset> base2 
      = shared_dynamic_cast<const Base2PlusOffset>(basoff);
    shared_ptr<const Base3PlusOffset> base3 
      = shared_dynamic_cast<const Base3PlusOffset>(basoff); 
    if (memreg == SIO || memreg == SRAM || memreg == SDRAM) 
      {
	char *excStr = new char[128];
	sprintf(excStr, "This instruction does not allow Base memory address");
	exc = shared_ptr<IllegalMappingOperand> 
	  (new IllegalMappingOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
    else if (memreg == SPRAM && !base2)
      {
	char *excStr = new char[128];
	sprintf(excStr, "Base3 not allowed with SPRAM instructions");
	exc = shared_ptr<IllegalMappingOperand> 
	  (new IllegalMappingOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
    else if (memreg == CCRAM && !base3)
      {
	char *excStr = new char[128];
	sprintf(excStr, "Base2 not allowed with CCRAM instructions");
	exc = shared_ptr<IllegalMappingOperand> 
	  (new IllegalMappingOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkTssFlags (shared_ptr<const LlirOperand> fl,
		 TssOp op,
		 OctaveAlo &alo,
		 unsigned int excLine,
		 const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    TrafficScheduleFlags::ConstIterator iter;
    shared_ptr<const TSSFlag> flag;
    OctaveFlagIdentificationVisitor idv;

    shared_ptr<const TrafficScheduleFlags> flags = 
      shared_dynamic_cast<const TrafficScheduleFlags>(fl);

    if(flags)
      {
	for (iter = flags->begin();  iter != flags->end(); iter++)
	  {
	    flag = *iter;
	    flag->accept(idv);
	  }
	if(op != POL 
	   && idv.isFlagPresent(OctaveFlagIdentificationVisitor::GW)
	   && !idv.isFlagPresent(OctaveFlagIdentificationVisitor::GR))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "GW flag requires presence of GR flag");
	    exc = shared_ptr<IllegalFlag> 
	      (new IllegalFlag
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  } 
	if(op == POL 
	   && !idv.isFlagPresent(OctaveFlagIdentificationVisitor::GR))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "this operation requires presence of GR flag");
	    exc = shared_ptr<IllegalFlag> 
	      (new IllegalFlag
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  } 
	if(op == POL 
	   && !idv.isFlagPresent(OctaveFlagIdentificationVisitor::NB))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "this operation requires presence of NB flag");
	    exc = shared_ptr<IllegalFlag> 
	      (new IllegalFlag
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  } 
	if(op == GET 
	   && idv.isFlagPresent(OctaveFlagIdentificationVisitor::GU))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "GET instruction disallows presence of GU flag");
	    exc = shared_ptr<IllegalFlag> 
	      (new IllegalFlag
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  } 
	if(op == GET 
	   && idv.isFlagPresent(OctaveFlagIdentificationVisitor::A)
	   && idv.isFlagPresent(OctaveFlagIdentificationVisitor::RB))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "\"A\" flag disallows presence of RB flag");
	    exc = shared_ptr<IllegalFlag> 
	      (new IllegalFlag
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  } 
	if(op == GET 
	   && idv.isFlagPresent(OctaveFlagIdentificationVisitor::A)
	   && !idv.isFlagPresent(OctaveFlagIdentificationVisitor::NC))
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "\"A\" flag requires presence of NC flag");
	    exc = shared_ptr<IllegalFlag> 
	      (new IllegalFlag
	       (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      } else {
	shared_ptr<const OpndNull> nil 
	  = shared_dynamic_cast<const OpndNull>(fl);
	if (!nil)
	  {

	       LLIR_INTERNAL_EXCEPTION("other operand found where TSS flags were expected");

	  }
      } 
  }
  
  
  void
  M480SemanticAnalysisVisitor::
  checkBitField (shared_ptr<const LlirOperand> start,
		 shared_ptr<const LlirOperand> length,
		 OctaveAlo &alo,
		 unsigned int excLine,
		 const string &excFile) const
  {
    shared_ptr<std::exception> exc;
    shared_ptr<const UnsignedImmediate> ustart =
      shared_dynamic_cast<const UnsignedImmediate>(start);
    shared_ptr<const UnsignedImmediate> ulength =
      shared_dynamic_cast<const UnsignedImmediate>(length);
    unsigned long str = ustart->getValue(); 
    unsigned long len = ulength->getValue(); 
    if (str + len > 32)
      {
	char *excStr = new char[128];
	sprintf(excStr, 
		"Field exceeds word length: %ld bits starting at bit %ld", 
		len, str);
	exc = shared_ptr<IllegalBitopOperand> 
	  (new IllegalBitopOperand
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }

  void
  M480SemanticAnalysisVisitor::
  checkSingleWordDest(shared_ptr<const MultiRegister> regs,
		      OctaveAlo &alo,
		      unsigned int excLine,
		      const string &excFile) const
  {
    shared_ptr<std::exception> exc; 
    if (regs->getNumRegs() != 1)
      {
	char *excStr = new char[128];
	sprintf(excStr, "undefined behavior when destination is more than 1 register (%d registers specified)", regs->getNumRegs());
	exc = shared_ptr<IllegalDestWordLength> 
	  (new IllegalDestWordLength
	   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	alo.logException(exc);
	delete excStr;
      }
  }

  extern shared_ptr<const PrototypeDirective>
  searchForValidPrototype(shared_ptr<const LabelList> labelList);

  extern PrototypeListIter searchForValidPrototype(const char* name);

  void
  M480SemanticAnalysisVisitor::checkIfCallInsn(shared_ptr<const LlirOperand> dst,
					       shared_ptr<const LlirOperand> labelList,
					       OctaveAlo &alo,
					       unsigned int excLine,
					       const string &excFile) const
  {
    shared_ptr<const IndirectCallTargetList> targetList = 
      shared_dynamic_cast<const IndirectCallTargetList>(labelList);

    shared_ptr<const Register> rpc =
      shared_dynamic_cast<const Register>(dst);

    if(rpc)
      {
	unsigned int rpcRegNum = rpc->getRegNum();
	bool callInsn = false;
	
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    callInsn = true;
	  }
	
	if(callInsn)
	  {
	    if(targetList)
	      {
		searchForValidPrototype(targetList->getLabelList());
	      }
	    else
	      {
		char *excStr = new char[128];
		sprintf(excStr, "@indcall label_list not specified for indirect call insn");
		shared_ptr<std::exception> exc = shared_ptr<MissingRequiredOperand> 
		  (new MissingRequiredOperand
		   (excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		alo.logException(exc);
		delete excStr;
	      }
	  }
      }
  }


  /*
    Make sure that all labels in @indir
    label list have the same matching 
    prototypes.
  */

  void 
  M480SemanticAnalysisVisitor::checkIndirectEntryLabels(unsigned int excLine,
							const string &file,
							shared_ptr<const LlirOperand> list) const
  {
    shared_ptr<const IndirectCallTargetList> iList = 
      shared_dynamic_cast<const IndirectCallTargetList>(list);

    if(iList)
      {
	shared_ptr<const LabelList> labelList = iList->getLabelList();

	const char* excFile = file.c_str();
	
	shared_ptr<const PrototypeDirective> p;
	
	PrototypeListIter piter;
	
	if(labelList->begin() == labelList->end())
	  {
	    char *excStr = new char[128];
	    
	    sprintf(excStr, "Error:%s:%d: empty indirect label list created", excFile, excLine);
	    
	    throw ALO_INTERNAL_EXCEPTION(excStr);
	    
	    delete excStr;
	  }


	//search for the first label...

	LabelList::ConstIterator iter = labelList->begin();

	const char *pname = (*iter)->getName().c_str();

	piter = searchForValidPrototype(pname);

	if(piter != g_prototypeDirList.end())
	  {
	    p = piter->second;
	  }
	
	//make sure the rest of labels in the list match
	//the with the first
	
	for(; iter != labelList->end(); iter++)
	  {
	    const char *name = (*iter)->getName().c_str();
	    
	    piter = searchForValidPrototype(name);
	
	    if(piter != g_prototypeDirList.end())
	      {
		
		if(*p != *piter->second)
		  {
		    char *excStr = new char[128];
		    
		    sprintf(excStr, "Error:%s:%d: prototype for '%s' does not match '%s' ", excFile, excLine, name, pname);
		    
		    throw ALO_INTERNAL_EXCEPTION(excStr);
		    
		    delete excStr;
		
		    break;
		  }
	      }
	  }
      }
  }

  ///////////////////////////////////////////
  // Invalid instruction visitor.
  ///////////////////////////////////////////

  void 
  M480SemanticAnalysisVisitor::visit(const InvalidOctaveInstruction &i) 
  {
    shared_ptr<InvalidInstructionException> exc = shared_ptr<InvalidInstructionException>
      (new InvalidInstructionException("illegal instruction for 4800 architecture",
				       i.getSrcLineNum(), 
				       i.getSrcFile().c_str(), 
				       __LINE__, __FILE__));
    getAlo().logException(exc);
  }
  
  ///////////////////////////////////////////
  // visit addwh
  ///////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddwhInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ///////////////////////////////////////////
  // visit jaddwh
  ///////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddwhInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addwl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddwlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jaddwl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddwlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addww
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddwwInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jaddww
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddwwInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit subwh
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubwhInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }  

  ////////////////////////////////////////////
  // visit jsubwh
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubwhInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  
  ////////////////////////////////////////////
  // visit subwl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubwlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit jsubwl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubwlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();

    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  

  ////////////////////////////////////////////
  // visit subww
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubwwInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
 
  ////////////////////////////////////////////
  // visit jsubww
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubwwInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  } 

  ////////////////////////////////////////////
  // visit subl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SublInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  

  ////////////////////////////////////////////
  // visit subl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsublInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addwhi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddwhiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }  
  
  ////////////////////////////////////////////
  // visit addwhi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddwhiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  
  ////////////////////////////////////////////
  // visit addwli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddwliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }  
  
  ////////////////////////////////////////////
  // visit jaddwli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddwliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  
  ////////////////////////////////////////////
  // visit addwwi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddwwiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit addwwi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddwwiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jaddli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JaddliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();

    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit subwhi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubwhiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jsubwhi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubwhiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  

  ////////////////////////////////////////////
  // visit subwli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubwliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit jsubwli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubwliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit subwwi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubwwiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
   
  ////////////////////////////////////////////
  // visit subwwi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubwwiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();

    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
   
  ////////////////////////////////////////////
  // visit subli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
     
  ////////////////////////////////////////////
  // visit jsubli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JsubliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();

    checkUImmRange(src1, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit ffs
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480FfsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit fls
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480FlsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit par
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ParInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit add
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit add4x
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480Add4xInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addc
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddcInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addci
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddciInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit sub
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit subi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit subb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit subbi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SubbiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit and
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AndInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit or
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480OrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit xor
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480XorInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit max
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MaxInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit min
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MinInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit rand
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RandInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit rotl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RotlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit rotr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RotrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit clrb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ClrbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit setb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SetbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shft
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShftInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shfta
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShftaInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShlInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shra
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShraInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit randi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RandiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit rotli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RotliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit rotri
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RotriInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit setbi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SetbiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit clrbi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ClrbiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }

  
  ////////////////////////////////////////////
  // visit shli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shri
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShriInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit shrai
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ShraiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 5, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit maxi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MaxiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit mini
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MiniInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit andi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AndiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit ori
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480OriInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit xori
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480XoriInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit mul
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MulInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit mulh
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MulhInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit muli
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MuliInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit mulhi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MulhiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addne
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddneInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit addnei
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480AddneiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit bytesw
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ByteswInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> b0 = i.getB0();
    shared_ptr<const LlirOperand> b1 = i.getB1();
    shared_ptr<const LlirOperand> b2 = i.getB2();
    shared_ptr<const LlirOperand> b3 = i.getB3();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
    checkUImmRange(b0, 2, alo, excLine, excFile);
    checkUImmRange(b1, 2, alo, excLine, excFile);
    checkUImmRange(b2, 2, alo, excLine, excFile);
    checkUImmRange(b3, 2, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit bcdr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BcdrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkBranchRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jbcdr
  ////////////////////////////////////////////


  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbcdrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> targetList = i.getTargetLabelList();

    checkRegister(src1, alo, excLine, excFile);
    checkBranchRegister(dst, alo, excLine, excFile);
    checkIfCallInsn(dst, targetList, alo, excLine, excFile);
    checkIndirectEntryLabels(excLine, excFile, targetList);
  }
  ////////////////////////////////////////////
  // visit bcr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BcrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkBranchRegister(dst, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jbcr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbcrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> targetList = i.getTargetLabelList();

    checkRegister(src1, alo, excLine, excFile);
    checkBranchRegister(dst, alo, excLine, excFile);
    checkIfCallInsn(dst, targetList, alo, excLine, excFile);
    checkIndirectEntryLabels(excLine, excFile, targetList);
  }
  
  ////////////////////////////////////////////
  // visit bi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    checkForValidLabel(alo, src, excLine, excFile);
    
    shared_ptr<const LlirOperand> dst = i.getDst();
    checkForReturnRegister(alo, dst, excLine, excFile);

    shared_ptr<const LlirOperand> cdFlag = i.getCdFlag();
    checkForValidCDFlag(alo, cdFlag, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit jbi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    checkForValidLabel(alo, src, excLine, excFile);
    
    shared_ptr<const LlirOperand> dst = i.getDst();
    checkForReturnRegister(alo, dst, excLine, excFile);

    shared_ptr<const LlirOperand> cdFlag = i.getCdFlag();
    checkForValidCDFlag(alo, cdFlag, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit br
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkBranchRegister(dst, alo, excLine, excFile);
  }


  ////////////////////////////////////////////
  // visit jablebr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JtablebrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    // FIXME: Check label (dst) here?
  }
    
  ////////////////////////////////////////////
  // visit jablebr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JtableRelativebrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    // FIXME: Check label (dst) here?
  }

  ////////////////////////////////////////////
  // visit jbr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> targetList = i.getTargetLabelList();

    checkRegister(src1, alo, excLine, excFile);
    checkBranchRegister(dst, alo, excLine, excFile);  
    checkIfCallInsn(dst, targetList, alo, excLine, excFile);
    checkIndirectEntryLabels(excLine, excFile, targetList);
  }
  
  ////////////////////////////////////////////
  // visit bcdi
  ////////////////////////////////////////////

  void
  M480SemanticAnalysisVisitor::visit(const M480BcdiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    checkForValidLabel(alo, src, excLine, excFile);
    
    shared_ptr<const LlirOperand> ess = i.getEss();
    checkForValidESSFlag(alo, ess, excLine, excFile);

    shared_ptr<const LlirOperand> dst = i.getDst();
    checkForReturnRegister(alo, dst, excLine, excFile);

    shared_ptr<const LlirOperand> cbrFlags = i.getFlags();
    checkForValidCandBfFlags(alo, cbrFlags, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jbcdi
  ////////////////////////////////////////////

  void
  M480SemanticAnalysisVisitor::visit(const M480JbcdiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    

    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    checkForValidLabel(alo, src, excLine, excFile);
    
    shared_ptr<const LlirOperand> ess = i.getEss();
    checkForValidESSFlag(alo, ess, excLine, excFile);

    shared_ptr<const LlirOperand> dst = i.getDst();
    checkForReturnRegister(alo, dst, excLine, excFile);

    shared_ptr<const LlirOperand> cbrFlags = i.getFlags();
    checkForValidCandBfFlags(alo, cbrFlags, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit bci
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BciInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
        
    shared_ptr<const LlirOperand> src = i.getSrc1();
    checkForValidLabel(alo, src, excLine, excFile);
    
    shared_ptr<const LlirOperand> ess = i.getEss();
    checkForValidESSFlag(alo, ess, excLine, excFile);

    shared_ptr<const LlirOperand> dst = i.getDst();
    checkForReturnRegister(alo, dst, excLine, excFile);

    shared_ptr<const LlirOperand> cbrFlags = i.getFlags();
    checkForValidCandBfFlags(alo, cbrFlags, excLine, excFile);

  }

  ////////////////////////////////////////////
  // visit jbci
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbciInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
        
    shared_ptr<const LlirOperand> src = i.getSrc1();
    checkForValidLabel(alo, src, excLine, excFile);
    
    shared_ptr<const LlirOperand> ess = i.getEss();
    checkForValidESSFlag(alo, ess, excLine, excFile);

    shared_ptr<const LlirOperand> dst = i.getDst();
    checkForReturnRegister(alo, dst, excLine, excFile);

    shared_ptr<const LlirOperand> cbrFlags = i.getFlags();
    checkForValidCandBfFlags(alo, cbrFlags, excLine, excFile);

  }
  
  ////////////////////////////////////////////
  // visit bnzr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BnzrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jbnzr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbnzrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    shared_ptr<const LlirOperand> targetList = i.getTargetLabelList();

    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkIfCallInsn(rpc, targetList, alo, excLine, excFile);
    checkIndirectEntryLabels(excLine, excFile, targetList);
 }
  
  ////////////////////////////////////////////
  // visit bzr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BzrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
  }
   
  ////////////////////////////////////////////
  // visit jbzr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbzrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    shared_ptr<const LlirOperand> targetList = i.getTargetLabelList();

    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkIfCallInsn(rpc, targetList, alo, excLine, excFile);
    checkIndirectEntryLabels(excLine, excFile, targetList);
  }
  
  ////////////////////////////////////////////
  // visit bnzi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BnziInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    checkForValidLabel(alo, src2, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jbnzi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbnziInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    checkForValidLabel(alo, src2, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit bzi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BziInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();

    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    checkForValidLabel(alo, src2, excLine, excFile);   
  }
    

  ////////////////////////////////////////////
  // visit bzi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbziInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();

    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    checkForValidLabel(alo, src2, excLine, excFile);   
  }
  
  ////////////////////////////////////////////
  // visit tsetb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480TsetbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> bitp = i.getBitpos();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(bitp, 5, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jtsetb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JtsetbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> bitp = i.getBitpos();
    shared_ptr<const LlirOperand> bt = i.getDisp();

    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(bitp, 5, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit tclrb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480TclrbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> bitp = i.getBitpos();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(bitp, 5, alo, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit jtclrb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JtclrbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> bitp = i.getBitpos();
    shared_ptr<const LlirOperand> bt = i.getDisp();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(bitp, 5, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  

  ////////////////////////////////////////////
  // visit rnmi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RnmiInstruction &i)
  {}

  
  ////////////////////////////////////////////
  // visit jrnmi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JrnmiInstruction &i)
  {}  

  ////////////////////////////////////////////
  // visit rint
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480RintInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit jrint
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JrintInstruction &i)
  {}

  ////////////////////////////////////////////
  // visit brs
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BrsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkBranchRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit jbrs
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbrsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkBranchRegister(dst, alo, excLine, excFile);
  }
  ////////////////////////////////////////////
  // visit brsl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BrslInstruction &i)
  {}
    
  ////////////////////////////////////////////
  // visit brsl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JbrslInstruction &i)
  {}
  

  ////////////////////////////////////////////
  // visit brspre
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480BrspreInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit cmp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480CmpInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit jcmp
  ////////////////////////////////////////////

  void
  M480SemanticAnalysisVisitor::visit(const M480JcmpInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();

    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit cmpi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480CmpiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();

    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit jcmpi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JcmpiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit cmpr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480CmprInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst  = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit cmpri
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480CmpriInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst  = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkSImmRange(src2, 10, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit depb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480DepbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1   = i.getSrc1();
    shared_ptr<const LlirOperand> srcbit = i.getSrcBitNum();
    shared_ptr<const LlirOperand> dst    = i.getDst();
    shared_ptr<const LlirOperand> dstbit = i.getDstBitNum();
    shared_ptr<const LlirOperand> numbit = i.getNumBits();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);

    checkUImmRange(srcbit, 5, alo, excLine, excFile);
    checkUImmRange(dstbit, 5, alo, excLine, excFile);
    checkUImmRange(numbit, 5, alo, excLine, excFile);
    checkBitField(srcbit, numbit, alo, excLine, excFile);
    checkBitField(dstbit, numbit, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit depbi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480DepbiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1   = i.getSrc1();
    shared_ptr<const LlirOperand> dst    = i.getDst();
    shared_ptr<const LlirOperand> dstbit = i.getDstBitNum();
    shared_ptr<const LlirOperand> numbit = i.getNumBits();
    
    checkUImmRange(src1, 9, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);
    checkUImmRange(dstbit, 5, alo, excLine, excFile);
    checkUImmRange(numbit, 5, alo, excLine, excFile);
    checkBitField(dstbit, numbit, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit extb
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480ExtbInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1   = i.getSrc1();
    shared_ptr<const LlirOperand> srcbit = i.getSrcBitNum();
    shared_ptr<const LlirOperand> dst    = i.getDst();
    shared_ptr<const LlirOperand> dstbit = i.getDstBitNum();
    shared_ptr<const LlirOperand> numbit = i.getNumBits();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);
    checkUImmRange(srcbit, 5, alo, excLine, excFile);
    checkAlignment(dstbit, 4, alo, excLine, excFile);
    checkUImmRange(dstbit, 5, alo, excLine, excFile);
    checkUImmRange(numbit, 5, alo, excLine, excFile);
    checkBitField(srcbit, numbit, alo, excLine, excFile);
    checkBitField(dstbit, numbit, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit cmov
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480CmovInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst  = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkRegister(src2, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit cmovi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480CmoviInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src1 = i.getSrc1();
    shared_ptr<const LlirOperand> src2 = i.getSrc2();
    shared_ptr<const LlirOperand> dst  = i.getDst();
    
    checkRegister(src1, alo, excLine, excFile);
    checkUImmRange(src2, 6, alo, excLine, excFile);
    checkRegister(dst , alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit dmap
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480DmapInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    
    checkRegisterPair(regs, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit dmasr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480DmasrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    
    checkRegisterPair(regs, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit dmau0
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480Dmau0Instruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    
    checkRegisterPair(regs, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit dmau1
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480Dmau1Instruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    
    checkRegisterPair(regs, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lih
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LihInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkSImm17Range(alo, src, excLine, excFile);
    checkOctaveRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lil
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LilInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();

    checkSImm17Range(alo, src, excLine, excFile);
    checkOctaveRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lwih
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LwihInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();

    checkUImm16Range(alo, src, excLine, excFile);    
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lwil
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LwilInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkUImm16Range(alo, src, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit laih
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LaihInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkSImm17Range(alo, src, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lail
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LailInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkSImm17Range(alo, src, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit nop
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480NopInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit hec5
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480Hec5Instruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> wdt = i.getBytes();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();
    
    checkRegister(src, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
    checkUImmRange(wdt, 3, alo, excLine, excFile);

   if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }
    
  ////////////////////////////////////////////
  // visit hec5
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480JHec5Instruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> wdt = i.getBytes();
    shared_ptr<const LlirOperand> bt = i.getBranchTarget();

    checkRegister(src, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
    checkUImmRange(wdt, 3, alo, excLine, excFile);

    if(!bt->isNullOperand())
      checkForValidLabel(alo, bt, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit mv
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MvInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit mvhr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MvhrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkHwRegister(src, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit mvrh
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480MvrhInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc();
    shared_ptr<const LlirOperand> dst = i.getDst();
    
    checkRegister(src, alo, excLine, excFile);
    checkHwRegister(dst, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit unlink
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480UnlinkInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    
    checkMultiRegister(regs, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit link
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinkInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, ANY, 10, 14, alo, excLine, excFile);

    //FIXME: nov 25th, 2002
    //check to make sure r63 cannot be linked
    //by means of lmm/link instructions (in both 470/480 SemV)

  }
  
  ////////////////////////////////////////////
  // visit links
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinksInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit linksp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinkspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit linkspl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinksplInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit linksr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinksrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SRAM, 10, 14, alo, excLine, excFile);
  }


  ////////////////////////////////////////////
  // visit linksd
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinksdInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SDRAM, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit linkcc
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinkccInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, CCRAM, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit linkccl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinkcclInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, CCRAM_LOCK, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit linksio
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LinksioInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SIO, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit lmm
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, ANY, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmsp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmspl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmsplInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
    checkSingleWordDest(regs, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmss
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmsrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmsd
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmsdInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SDRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmcc
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmccInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, CCRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmccl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmcclInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, CCRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lmmsi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmsiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SIO, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit lmms
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LmmsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit lsp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480LspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smm
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, ANY, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmsp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmspl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmsplInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmsr
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmsrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmsd
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmsdInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SDRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmcc
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmccInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, CCRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmccl
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmcclInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, CCRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit smmsi
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmsiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SIO, 10, 14, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit smms
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SmmsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  
  ////////////////////////////////////////////
  // visit ssp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480SspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const MultiRegister> regs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    checkMultiRegister(regs, alo, excLine, excFile);
    checkMemory(mem, SPRAM, 10, 14, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit get
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480GetInstruction &i)
  {
    //FIXME:??
  }
  
  ////////////////////////////////////////////
  // visit putc
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480PutcInstruction &i)
  {
    //FIXME:??
  }
  
  ////////////////////////////////////////////
  // visit putm
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480PutmInstruction &i)
  {
    //FIXME:??
  }

  ////////////////////////////////////////////
  // visit putp
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480PutpInstruction &i)
  {
    //FIXME:??
  }

  ////////////////////////////////////////////
  // visit putd
  ////////////////////////////////////////////
  
  void
  M480SemanticAnalysisVisitor::visit(const M480PutdInstruction &i)
  {
    //FIXME:??
  }

}
