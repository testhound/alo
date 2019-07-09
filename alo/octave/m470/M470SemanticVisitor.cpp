#include <string>
#include <exception>
#include <cassert>

#include <Alo.h>
#include <LlirException.h>
#include <M470Instructions.h>

#include "M470SemanticVisitor.h"


using namespace Llir;

namespace Alo
{
  


  //////////////////////////////////////////
  //
  // M470SemanticAnalysisVisitor functions
  //
  //////////////////////////////////////////
 
  M470SemanticAnalysisVisitor::M470SemanticAnalysisVisitor(OctaveAlo &o) :
    OctaveSemanticAnalysisVisitor(o)
  {}
 

  M470SemanticAnalysisVisitor::~M470SemanticAnalysisVisitor()
  {}
  
  //////////////////////////////////////////
  //private utility functions
  //////////////////////////////////////////

  void
  M470SemanticAnalysisVisitor::
  checkForValidLabel(OctaveAlo &alo,
		    shared_ptr<const LlirOperand> opnd, 
		    unsigned int excLine,
		    const string &excFile) const
  {
    // This test is now a no-op.  We *have* to allow "label+const_offset" in 
    // non-optimizing mode (which is always the case for m470).
  }
  

  void
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
	if (!(val < max))
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
  M470SemanticAnalysisVisitor::
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
  

  void
  M470SemanticAnalysisVisitor::
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
	unsigned int regNum = reg->getRegNum(); 
	if (regNum < 0 || regNum > 128)
	  {  
	    char *excStr = new char[128];
	    sprintf(excStr, "register r%d is not a octave register", regNum);
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
  M470SemanticAnalysisVisitor::
  checkRegister (shared_ptr<const LlirOperand> opnd,
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
      } 
    else 
      {
	LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");
      }
  }
  
  
  void
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
	unsigned int regNum = reg->getRegNum(); 
	if (!isNullReg(reg))
	  {
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
      } else {

	LLIR_INTERNAL_EXCEPTION("other operand found where register was expected");

      }
  }
  
  
  void
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
	    if (!(off < max))
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::
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
  M470SemanticAnalysisVisitor::visit(const InvalidOctaveInstruction &i) 
  {
    shared_ptr<InvalidInstructionException> exc = shared_ptr<InvalidInstructionException>
      (new InvalidInstructionException("illegal instruction for 4700 architecture",
				       i.getSrcLineNum(), 
				       i.getSrcFile().c_str(), 
				       __LINE__, __FILE__));
    getAlo().logException(exc);
  }
  
  ///////////////////////////////////////////
  // visit addwh
  ///////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470AddwhInstruction &i)
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
  // visit addwl
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470AddwlInstruction &i)
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
  // visit addww
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470AddwwInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddlInstruction &i)
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
  // visit subwh
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SubwhInstruction &i)
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
  // visit subwl
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SubwlInstruction &i)
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
  // visit subww
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SubwwInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SublInstruction &i)
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
  // visit addwhi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470AddwhiInstruction &i)
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
  // visit addwli
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470AddwliInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddwwiInstruction &i)
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
  // visit addli
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470AddliInstruction &i)
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
  // visit subwhi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SubwhiInstruction &i)
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
  // visit subwli
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SubwliInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SubwwiInstruction &i)
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
  // visit subli
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SubliInstruction &i)
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
  // visit ffs
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470FfsInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470FlsInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ParInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470Add4xInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddcInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddciInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SubInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SubiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SubbInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SubbiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AndInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470OrInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470XorInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MaxInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MinInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470RandInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470RotlInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470RotrInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ClrbInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SetbInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShftInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShftaInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShlInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShrInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShraInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470RandiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470RotliInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470RotriInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SetbiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ClrbiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShliInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShriInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ShraiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MaxiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MiniInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AndiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470OriInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470XoriInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MulInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MulhInstruction &i)
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
  // visit div
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470DivInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MuliInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MulhiInstruction &i)
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
  // visit divi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470DiviInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddneInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470AddneiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ByteswInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470BcdrInstruction &i)
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
  // visit bcr
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470BcrInstruction &i)
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
  // visit bi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470BiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470BrInstruction &i)
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
  // visit bcdi
  ////////////////////////////////////////////

  void
  M470SemanticAnalysisVisitor::visit(const M470BcdiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470BciInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470BnzrInstruction &i)
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
  // visit bzr
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470BzrInstruction &i)
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
  // visit bnzi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470BnziInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470BziInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470TsetbInstruction &i)
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
  // visit tclrb
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470TclrbInstruction &i)
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
  // visit rnmi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470RnmiInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit rint
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470RintInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit brs
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470BrsInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470BrslInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit brspre
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470BrspreInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit cmp
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470CmpInstruction &i)
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
  // visit cmpi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470CmpiInstruction &i)
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
  // visit cmpr
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470CmprInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470CmpriInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470DepbInstruction &i)
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
    checkAlignment(srcbit, 4, alo, excLine, excFile);
    checkUImmRange(dstbit, 5, alo, excLine, excFile);
    checkUImmRange(numbit, 5, alo, excLine, excFile);
    checkBitField(srcbit, numbit, alo, excLine, excFile);
    checkBitField(dstbit, numbit, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit depbi
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470DepbiInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470ExtbInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470CmovInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470CmoviInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470DmapInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470DmasrInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470Dmau0Instruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470Dmau1Instruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LihInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LilInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LwihInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LwilInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LaihInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LailInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470NopInstruction &i)
  {}
  
  ////////////////////////////////////////////
  // visit hec5
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470Hec5Instruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> src = i.getSrc1();
    shared_ptr<const LlirOperand> dst = i.getDst();
    shared_ptr<const LlirOperand> wdt = i.getBytes();
    
    checkRegister(src, alo, excLine, excFile);
    checkRegister(dst, alo, excLine, excFile);
    checkUImmRange(wdt, 3, alo, excLine, excFile);
  }

  ////////////////////////////////////////////
  // visit mv
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470MvInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MvhrInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470MvrhInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470UnlinkInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LinkInstruction &i)
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
  // visit links
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470LinksInstruction &i)
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
  // visit lmm
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470LmmInstruction &i)
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
  // visit lmms
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470LmmsInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470LspInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SmmInstruction &i)
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
  // visit smms
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470SmmsInstruction &i)
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
  M470SemanticAnalysisVisitor::visit(const M470SspInstruction &i)
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
  // visit put
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470PutInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> rsa = i.getRsa();
    shared_ptr<const LlirOperand> rsb = i.getRsb();
    shared_ptr<const LlirOperand> flags = i.getTssFlags();
    
    checkRegister(rsa, alo, excLine, excFile);
    checkRegister(rsb, alo, excLine, excFile);
    checkTssFlags (flags, PUT, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit get
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470GetInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> rsa = i.getRsa();
    shared_ptr<const LlirOperand> flags = i.getTssFlags();
    
    checkRegister(rsa, alo, excLine, excFile);
    checkTssFlags (flags, GET, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit pol
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470PolInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> rsa = i.getRsa();
    shared_ptr<const LlirOperand> flags = i.getTssFlags();
    
    checkRegister(rsa, alo, excLine, excFile);
    checkTssFlags (flags, POL, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit putc
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470PutcInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> par = i.getParOffset();
    shared_ptr<const LlirOperand> pos = i.getPosOffset();
    shared_ptr<const LlirOperand> pdp = i.getPipeDepth();
    shared_ptr<const LlirOperand> flags = i.getTssFlags();
    
    checkUImmRange(par, 4, alo, excLine, excFile);
    checkUImmRange(pos, 4, alo, excLine, excFile);
    checkTssFlags (flags, PUT, alo, excLine, excFile);
    
    shared_ptr<const UnsignedImmediate> pipedepth 
      = shared_dynamic_cast<const UnsignedImmediate>(pdp);
    if(pipedepth)
      {
	checkUImmRange(pipedepth, 3, alo, excLine, excFile);
      }
  }
  
  ////////////////////////////////////////////
  // visit getc
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470GetcInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> par = i.getParOffset();
    shared_ptr<const LlirOperand> pos = i.getPosOffset();
    shared_ptr<const LlirOperand> flags = i.getTssFlags();
    
    checkUImmRange(par, 4, alo, excLine, excFile);
    checkUImmRange(pos, 4, alo, excLine, excFile);
    checkTssFlags (flags, GET, alo, excLine, excFile);
  }
  
  ////////////////////////////////////////////
  // visit polc
  ////////////////////////////////////////////
  
  void
  M470SemanticAnalysisVisitor::visit(const M470PolcInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const string &excFile = i.getSrcFile();
    OctaveAlo& alo = getAlo();
    
    shared_ptr<const LlirOperand> par = i.getParOffset();
    shared_ptr<const LlirOperand> pos = i.getPosOffset();
    shared_ptr<const LlirOperand> flags = i.getTssFlags();
    
    checkUImmRange(par, 4, alo, excLine, excFile);
    checkUImmRange(pos, 4, alo, excLine, excFile);
    checkTssFlags (flags, POL, alo, excLine, excFile);
  }
  
  
}
