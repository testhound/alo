#ifndef _OCTAVE_INSTRUCTIONS_H
#define _OCTAVE_INSTRUCTIONS_H

#include <LlirNode.h>
#include <LlirOperand.h>
#include <LlirException.h>

#include "OctaveOperand.h"



namespace Llir {

  //typedefs
  typedef shared_ptr<const LlirOperand> OpndPtr;
  typedef shared_ptr<const Register> RegPtr;
  typedef shared_ptr<const MultiRegister> MultiRegPtr;
  typedef shared_ptr<const UnsignedImmediate> UImmPtr;
  typedef shared_ptr<const SignedImmediate> SImmPtr;
  typedef shared_ptr<const OctaveMemory> MemPtr;
  typedef shared_ptr<const AbcGenericFlag> AbcGenPtr;
  typedef shared_ptr<const ModFlag> ModPtr;
  typedef shared_ptr<const SXFlag> SxPtr;
  typedef shared_ptr<const EssFlag> EssPtr;
  typedef shared_ptr<const LinkFlag> LinkPtr;
  
  //---------------------------------------------
  // OctaveInstruction
  //---------------------------------------------
  
  class OctaveInstruction : public LlirInstruction
    {
    public:
      
      virtual ~OctaveInstruction()
	{}
      
      void addOperand(OpndPtr opnd)
	{
	  throw LLIR_INTERNAL_EXCEPTION("OctaveInstruction::addOperand not implemented");
	}

      virtual unsigned int getNumDelaySlots() const =0;

      virtual bool isPseudoInsn() const =0;

      virtual bool isAbcInsn() const =0;

      virtual bool isValidDslotInsn() const =0;

      bool inInstructionSequence() const;

      void setInInstructionSequence();

      enum BranchProbability { NOT_TAKEN=0, TAKEN, NONE, };
      
      virtual BranchProbability getBranchProbability() const =0;

      typedef std::list<shared_ptr<const Register> >::iterator RegOpndConstIterator;

      bool setRegistersLive() const;
      bool isRegisterLive(unsigned int regNum) const;

      bool isSetRegListEmpty() const;
      bool isUsedRegListEmpty() const;
      bool isUnusedRegListEmpty() const;
      bool isDeadRegListEmpty() const;
      
      RegOpndConstIterator beginSetRegList() const;
      RegOpndConstIterator endSetRegList() const;

      RegOpndConstIterator beginUsedRegList() const;
      RegOpndConstIterator endUsedRegList() const;

      RegOpndConstIterator beginDeadRegList() const;
      RegOpndConstIterator endDeadRegList() const;

      RegOpndConstIterator beginUnusedRegList() const;
      RegOpndConstIterator endUnusedRegList() const;

      void addSetRegister(shared_ptr<const LlirOperand> opnd) const;
      void addUsedRegister(shared_ptr<const LlirOperand> opnd) const;
      void addDeadRegister(shared_ptr<const LlirOperand> opnd) const;
      void addUnusedRegister(shared_ptr<const LlirOperand> opnd) const;
      
    protected:
      OctaveInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName) : 
	LlirInstruction(lineNum, 
			srcLineNum, 
			srcFileName),
	m_inInstructionSequence(false)
	{}
      
      OctaveInstruction(const OctaveInstruction& rhs) : 
	LlirInstruction(rhs),
	m_inInstructionSequence(rhs.m_inInstructionSequence)
	{}
      
      OctaveInstruction& operator=(const OctaveInstruction& rhs);

    private:
      // used to group instructions together that should stay together 
      //(e.g. following a mvhr with Cn or insns in a .noopt and .endnoopt bdry)
      bool m_inInstructionSequence; 

      //set of destination registers
      mutable std::list<shared_ptr<const Register> > m_setRegList;

      //set of used registers
      mutable std::list<shared_ptr<const Register> > m_usedRegList;

      //set of dead registers
      mutable std::list<shared_ptr<const Register> > m_deadRegList;

      //set of subsequently unsed registers
      mutable std::list<shared_ptr<const Register> > m_unusedRegList;

    };  


  //--------------------------------------------------
  // NullInstruction
  //--------------------------------------------------

  class NullInstruction : public OctaveInstruction
    {

    public:

      NullInstruction(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName);

      NullInstruction(const NullInstruction& rhs);

      ~NullInstruction();

      NullInstruction& operator=(const NullInstruction& n);

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      void accept(Visitor& v) const;

    private:

      bool equalTo(const LlirNode& n) const;

    };

  //--------------------------------------------------
  // InvalidInstruction
  //--------------------------------------------------

  class InvalidOctaveInstruction : public OctaveInstruction
    {

    public:

      InvalidOctaveInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName);
			       
      InvalidOctaveInstruction(const InvalidOctaveInstruction& rhs);

      ~InvalidOctaveInstruction()
	{}

      InvalidOctaveInstruction& operator=(const InvalidOctaveInstruction& rhs);

      void addLlirNode(shared_ptr<LlirNode> , shared_ptr<LlirNode>);

      void addOperand(shared_ptr<const LlirOperand> op);

      void accept(Visitor& v) const;

      LlirNode::Iterator begin();

      LlirNode::Iterator end();

      LlirNode::ConstIterator begin() const;

      LlirNode::ConstIterator end() const;


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    private:

      bool equalTo(const LlirNode& n) const;

    };
  
  //---------------------------------------------
  // AluOpInstruction 
  //---------------------------------------------
  
  
  class AluOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~AluOpInstruction()
	{}

      virtual BranchProbability getBranchProbability() const;

    protected:
      
      AluOpInstruction(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName) {}
      
      AluOpInstruction(const AluOpInstruction& rhs) 
	: OctaveInstruction(rhs) {}
      
      AluOpInstruction& operator=(const AluOpInstruction& rhs);
      
    };
  
  
  //---------------------------------------------
  // Alu2OpInstruction 
  //---------------------------------------------
  
  class Alu2OpInstruction : public AluOpInstruction
    {
    public:
      
      virtual ~Alu2OpInstruction()
	{}
      
      OpndPtr getSrc1() const;
      
      RegPtr getDst() const;
      
      virtual BranchProbability getBranchProbability() const;
      
    protected:
      
      Alu2OpInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			OpndPtr src1, RegPtr dst) 
	: AluOpInstruction(lineNum, 
			   srcLineNum, 
			   srcFileName),
	m_src1(src1),
	m_dst(dst)	
	{}
      
      Alu2OpInstruction(const Alu2OpInstruction& rhs) 
	: AluOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst)	
	{}
      
      Alu2OpInstruction& operator=(const Alu2OpInstruction& rhs);
      
      
    private:
      
      OpndPtr m_src1;
      
      RegPtr m_dst;
      
    };
  
  
  //---------------------------------------------
  // Alu2OpBranchInstruction 
  //---------------------------------------------
  
  
  class Alu2OpBranchInstruction : public Alu2OpInstruction
    {
    public:
      
      virtual ~Alu2OpBranchInstruction()
	{}
      
      OpndPtr getBranchTarget() const;
      

      virtual unsigned int getNumDelaySlots() const;

      virtual bool isPseudoInsn() const;

      bool isAbcInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      bool hasValidBranchTarget() const;
      

    protected:
      
      Alu2OpBranchInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      OpndPtr src1, 
			      RegPtr dst, 
			      OpndPtr target)
        : Alu2OpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    src1, 
			    dst),
	m_target(target),
	m_probability(OctaveInstruction::NONE)
	{}

      Alu2OpBranchInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      OpndPtr src1, 
			      RegPtr dst, 
			      OpndPtr target,
			      BranchProbability probability)
        : Alu2OpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    src1, 
			    dst),
	m_target(target),
	m_probability(probability)
	{}
      
      Alu2OpBranchInstruction(const Alu2OpBranchInstruction& rhs)
	: Alu2OpInstruction(rhs),
	m_target(rhs.m_target),
	m_probability(rhs.m_probability)
	{}	 
      
      Alu2OpBranchInstruction& operator=(const Alu2OpBranchInstruction& rhs); 
      
    private:
      
      OpndPtr m_target;
      
      BranchProbability m_probability;
    };
  
  
  //---------------------------------------------
  // Alu2OpFindInstruction 
  //---------------------------------------------
  
  
  class Alu2OpFindInstruction : public Alu2OpInstruction
    {
    public:
      
      virtual ~Alu2OpFindInstruction()
	{}
      
      OpndPtr getAbcFlag() const;
      
      OpndPtr getFindFlag() const;
      
      unsigned int getNumDelaySlots() const;

      bool isPseudoInsn() const;

      bool isAbcInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool hasValidAbcFlag() const;

    protected:
      
      
      Alu2OpFindInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr 
			    abcFlag, 
			    OpndPtr findFlag)
        : Alu2OpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    src1, 
			    dst),
	m_abcFlag(abcFlag),
	m_findFlag(findFlag)
	{}
      
      Alu2OpFindInstruction(const Alu2OpFindInstruction& rhs)
	: Alu2OpInstruction(rhs),
	m_abcFlag(rhs.m_abcFlag),
	m_findFlag(rhs.m_findFlag)
	{}	 
      
      Alu2OpFindInstruction& operator=(const Alu2OpFindInstruction& rhs); 
      
    private:
      
      OpndPtr m_abcFlag;
      OpndPtr m_findFlag;
      
    };
  
  
  //---------------------------------------------
  // Alu3OpInstruction 
  //---------------------------------------------
  
  class Alu3OpInstruction : public AluOpInstruction
    {
    public:
      
      virtual ~Alu3OpInstruction()
	{}
      
      RegPtr getSrc1() const;      
      
      OpndPtr getSrc2() const;
      
      RegPtr getDst() const;

      virtual BranchProbability getBranchProbability() const;

    protected:
      
      Alu3OpInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			RegPtr src1, 
			OpndPtr src2, 
			RegPtr dst) 
	: AluOpInstruction(lineNum, 
			   srcLineNum, 
			   srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_dst(dst)	
	{}
      
      Alu3OpInstruction(const Alu3OpInstruction& rhs) 
	: AluOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_src2(rhs.m_src2),
	m_dst(rhs.m_dst)	
	{}
      
      Alu3OpInstruction& operator=(const Alu3OpInstruction& rhs);
      
      
    private:
      
      RegPtr m_src1;
      
      OpndPtr m_src2;
      
      RegPtr m_dst;
      
    };
  
  
  //---------------------------------------------
  // Alu3OpAbcModInstruction 
  //---------------------------------------------
  
  
  class Alu3OpAbcModInstruction : public Alu3OpInstruction
    {
    public:
      
      virtual ~Alu3OpAbcModInstruction()
	{}
      
      OpndPtr getAbcFlag() const;
      
      OpndPtr getModFlag() const;
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool hasValidAbcFlag() const;

    protected:
      
      
      Alu3OpAbcModInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      RegPtr src1, 
			      OpndPtr src2, 
			      RegPtr dst, 
			      OpndPtr abcFlag, 
			      OpndPtr modFlag)
        : Alu3OpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    src1, 
			    src2, 
			    dst),
	m_abcFlag(abcFlag),
	m_modFlag(modFlag)
	{}
      
      Alu3OpAbcModInstruction(const Alu3OpAbcModInstruction& rhs)
	: Alu3OpInstruction(rhs),
	m_abcFlag(rhs.m_abcFlag),
	m_modFlag(rhs.m_modFlag)
	{}	 
      
      Alu3OpAbcModInstruction& operator=(const Alu3OpAbcModInstruction& rhs); 
      
    private:
      
      OpndPtr m_abcFlag;
      
      OpndPtr m_modFlag;
      
      
    };
  
  
  //---------------------------------------------
  // Alu3OpAbcInstruction 
  //---------------------------------------------
  
  
  class Alu3OpAbcInstruction : public Alu3OpInstruction
    {
    public:
      
      virtual ~Alu3OpAbcInstruction()
	{}
      
      OpndPtr getAbcFlag() const;


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool hasValidAbcFlag() const;
      
    protected:
      
      Alu3OpAbcInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   OpndPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    src1, 
			    src2, 
			    dst),
	m_abcFlag(abcFlag)
	{}
      
      Alu3OpAbcInstruction(const Alu3OpAbcInstruction& rhs)
	: Alu3OpInstruction(rhs),
	m_abcFlag(rhs.m_abcFlag)
	{}	 
      
      Alu3OpAbcInstruction& operator=(const Alu3OpAbcInstruction& rhs); 
      
    private:
      
      OpndPtr m_abcFlag;
      
    };
  
  
  //---------------------------------------------
  // Alu3OpSxInstruction 
  //---------------------------------------------
  
  
  class Alu3OpSxInstruction : public Alu3OpInstruction
    {
    public:
      
      virtual ~Alu3OpSxInstruction()
	{}
      
      OpndPtr getSxFlag() const;

      bool isPseudoInsn() const;
      
      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

    protected:
      
      
      Alu3OpSxInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  OpndPtr src2, 
			  RegPtr dst, 
			  OpndPtr sxFlag)
        : Alu3OpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    src1, 
			    src2, 
			    dst),
	m_sxFlag(sxFlag)
	{}
      
      Alu3OpSxInstruction(const Alu3OpSxInstruction& rhs)
	: Alu3OpInstruction(rhs),
	m_sxFlag(rhs.m_sxFlag)
	{}	 
      
      Alu3OpSxInstruction& operator=(const Alu3OpSxInstruction& rhs); 
      
    private:
      
      OpndPtr m_sxFlag;
      
    };
  
  
  //---------------------------------------------
  // BranchOpInstruction 
  //---------------------------------------------
  
  
  class BranchOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~BranchOpInstruction()
	{}
      
      bool isAbcInsn() const;

      virtual BranchProbability getBranchProbability() const;

    protected:
      
      BranchOpInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName)
	{}
      
      BranchOpInstruction(const BranchOpInstruction& rhs) 
	: OctaveInstruction(rhs)
	{}
      
      BranchOpInstruction& operator=(const BranchOpInstruction& rhs);
      
    };
  
  
  //---------------------------------------------
  // CondBranchInstruction 
  //---------------------------------------------
  
  class CondBranchInstruction : public BranchOpInstruction
    {
    public:
      
      virtual ~CondBranchInstruction()
	{}

      bool isBranchInsn() const;

      bool isReturnInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      BranchProbability getBranchProbability() const;

      RegPtr getSrc1() const;

      EssPtr getEss() const;
      
      OpndPtr getDst() const;
      
      OpndPtr getFlags() const;

    private:

      bool hasReturnReg() const;
      
    protected:

      bool hasValidCFlag() const;

      CondBranchInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    EssPtr ess, 
			    OpndPtr dst, 
			    OpndPtr flags) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_ess(ess),
	m_dst(dst),
	m_flags(flags),
	m_probability(OctaveInstruction::NONE)
	{}
      
      CondBranchInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    EssPtr ess, 
			    OpndPtr dst, 
			    OpndPtr flags,      
			    BranchProbability probability) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_ess(ess),
	m_dst(dst),
	m_flags(flags),
	m_probability(probability)
	{}
      
      CondBranchInstruction(const CondBranchInstruction& rhs) 
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_ess(rhs.m_ess),
	m_dst(rhs.m_dst),
	m_flags(rhs.m_flags),
	m_probability(rhs.m_probability)
	{}
      
      CondBranchInstruction& operator=(const CondBranchInstruction& rhs);
      
      
    private:
      
      RegPtr m_src1;
      EssPtr m_ess;
      OpndPtr m_dst;
      OpndPtr m_flags;
      BranchProbability m_probability;
    };
  
  
  //---------------------------------------------
  // CondBranchImmedInstruction 
  //---------------------------------------------
  
  class CondBranchImmedInstruction : public BranchOpInstruction
    {
    public:
      
      virtual ~CondBranchImmedInstruction()
	{}

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      BranchProbability getBranchProbability() const;

      OpndPtr getSrc1() const;

      EssPtr getEss() const;
      
      OpndPtr getDst() const;
      
      OpndPtr getFlags() const;

    private:

      bool hasReturnReg() const;
      
    protected:
      
      bool hasValidCFlag() const;
            
      CondBranchImmedInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 OpndPtr src1, 
				 EssPtr ess, 
				 OpndPtr dst, 
				 OpndPtr flags)
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_ess(ess),
	m_dst(dst),
	m_flags(flags),
	m_probability(OctaveInstruction::NONE)
	{}

      CondBranchImmedInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 OpndPtr src1, 
				 EssPtr ess, 
				 OpndPtr dst, 
				 OpndPtr flags,      
				 BranchProbability probability) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_ess(ess),
	m_dst(dst),
	m_flags(flags),
	m_probability(probability)
	{}
      
      CondBranchImmedInstruction(const CondBranchImmedInstruction& rhs) 
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_ess(rhs.m_ess),
	m_dst(rhs.m_dst),
	m_flags(rhs.m_flags),
	m_probability(rhs.m_probability)
	{}
      
      CondBranchImmedInstruction& operator=
	(const CondBranchImmedInstruction& rhs);
      
      
    private:
      
      OpndPtr m_src1;
      EssPtr m_ess;
      OpndPtr m_dst;
      OpndPtr m_flags;
      BranchProbability m_probability;      
    };
  
  
  //---------------------------------------------
  // ZeroBranchInstruction 
  //---------------------------------------------
  
  class ZeroBranchInstruction : public BranchOpInstruction
    {
    public:
      
      virtual ~ZeroBranchInstruction()
	{}
      
      RegPtr getSrc1() const;

      RegPtr getSrc2() const;

      OpndPtr getCmpReg() const;

      bool isBranchInsn() const;

      bool isReturnInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      BranchProbability getBranchProbability() const;
 
    private:

      bool hasReturnReg() const;

    protected:

      ZeroBranchInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr src2, 
			    OpndPtr cmpReg) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_cmpReg(cmpReg),
	m_probability(OctaveInstruction::NONE)
	{}
      
      ZeroBranchInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr src2, 
			    OpndPtr cmpReg,      
			    BranchProbability probability) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_cmpReg(cmpReg),
	m_probability(probability)
	{}
      
      ZeroBranchInstruction(const ZeroBranchInstruction& rhs) 
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_src2(rhs.m_src2),
	m_cmpReg(rhs.m_cmpReg),
	m_probability(rhs.m_probability)
	{}
      
      ZeroBranchInstruction& operator= (const ZeroBranchInstruction& rhs);
      
      
    private:
      
      RegPtr m_src1;
      RegPtr m_src2;
      OpndPtr m_cmpReg;
      BranchProbability m_probability;
    };
  
  
  //---------------------------------------------
  // ZeroBranchImmedInstruction 
  //---------------------------------------------
  
  class ZeroBranchImmedInstruction : public BranchOpInstruction
    {
    public:
      
      virtual ~ZeroBranchImmedInstruction()
	{}
      
      RegPtr getSrc1() const;

      OpndPtr getSrc2() const;

      OpndPtr getCmpReg() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      BranchProbability getBranchProbability() const;

    private:

      bool hasReturnReg() const;

    protected:
            
      ZeroBranchImmedInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 RegPtr src1, 
				 OpndPtr src2, 
				 OpndPtr cmpReg) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_cmpReg(cmpReg),
	m_probability(OctaveInstruction::NONE)
	{}
      
      ZeroBranchImmedInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 RegPtr src1, 
				 OpndPtr src2, 
				 OpndPtr cmpReg,      
				 BranchProbability probability) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_cmpReg(cmpReg),
	m_probability(probability)
	{}
      
      ZeroBranchImmedInstruction(const ZeroBranchImmedInstruction& rhs) 
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_src2(rhs.m_src2),
	m_cmpReg(rhs.m_cmpReg),
	m_probability(rhs.m_probability)
	{}
      
      ZeroBranchImmedInstruction& operator= 
	(const ZeroBranchImmedInstruction& rhs);
      
      
    private:
      
      RegPtr  m_src1;
      OpndPtr m_src2;
      OpndPtr  m_cmpReg;
      BranchProbability m_probability;   
    };
  
  
  //---------------------------------------------
  // TestBitBranchInstruction 
  //---------------------------------------------
  
  class TestBitBranchInstruction : public BranchOpInstruction
    {
    public:
      
      virtual ~TestBitBranchInstruction()
	{}
      
      RegPtr  getSrc1() const;
      
      UImmPtr getBitpos() const;
      
      OpndPtr getDisp() const;
      
      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      virtual bool isPseudoInsn() const;

      virtual unsigned int getNumDelaySlots() const;

    protected:
            
      TestBitBranchInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       RegPtr src1, 
			       UImmPtr bitpos, 
			       OpndPtr disp) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_bitpos(bitpos),
	m_disp(disp),
	m_probability(OctaveInstruction::NONE)
	{}
      
      TestBitBranchInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       RegPtr src1, 
			       UImmPtr bitpos, 
			       OpndPtr disp,      
			       BranchProbability probability) 
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_src1(src1),
	m_bitpos(bitpos),
	m_disp(disp),
	m_probability(probability)
	{}
      
      TestBitBranchInstruction(const TestBitBranchInstruction& rhs) 
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_bitpos(rhs.m_bitpos),
	m_disp(rhs.m_disp),
	m_probability(rhs.m_probability)
	{}
      
      TestBitBranchInstruction& operator= 
	(const TestBitBranchInstruction& rhs);
      
      
    private:
      
      RegPtr  m_src1;
      UImmPtr m_bitpos;
      OpndPtr m_disp;
      BranchProbability m_probability;   
    };
  
  
  //---------------------------------------------
  // ReturnOpInstruction 
  //---------------------------------------------
  
  class ReturnOpInstruction : public BranchOpInstruction
    {
    public:
      
      virtual ~ReturnOpInstruction()
	{}
      
      OpndPtr getDiFlag() const;
      
      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isReturnInsn() const;

    protected:
      
      ReturnOpInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, OpndPtr diFlag)
	: BranchOpInstruction(lineNum, 
			      srcLineNum, 
			      srcFileName),
	m_diFlag(diFlag)
	{}
      
      ReturnOpInstruction(const ReturnOpInstruction& rhs) 
	: BranchOpInstruction(rhs),
	m_diFlag(rhs.m_diFlag)
	{}
      
      ReturnOpInstruction& operator= (const ReturnOpInstruction& rhs);
      
      
    private:
      
      OpndPtr m_diFlag;
      
    };
  
  
  //---------------------------------------------
  // CompareOpInstruction 
  //---------------------------------------------
  
  
  class CompareOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~CompareOpInstruction()
	{}
      
      RegPtr getSrc1() const;

      OpndPtr getSrc2() const;
      
      OpndPtr getAbcFlag() const;
      
      virtual BranchProbability getBranchProbability() const;

    protected:
      
      CompareOpInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1,
			   OpndPtr src2, 
			   OpndPtr abcFlag) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_abcFlag(abcFlag)
	{}
      
      CompareOpInstruction(const CompareOpInstruction& rhs) 
	: OctaveInstruction(rhs),
	m_src1(rhs.m_src1),
	m_src2(rhs.m_src2),
	m_abcFlag(rhs.m_abcFlag)
	{}
      
      CompareOpInstruction& operator=(const CompareOpInstruction& rhs);
      
    private:
      
      RegPtr m_src1;
      OpndPtr m_src2;
      OpndPtr m_abcFlag;
      
    };
  
  
  //---------------------------------------------
  // CompareOpBranchInstruction 
  //---------------------------------------------
  
  class CompareOpBranchInstruction : public CompareOpInstruction
    {
    public:
      
      virtual ~CompareOpBranchInstruction()
	{}


      bool isAbcInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      bool hasValidAbcFlag() const;


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      OpndPtr getBranchTarget() const;
      
    protected:
            
      CompareOpBranchInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 RegPtr src1, 
				 OpndPtr src2, 
				 OpndPtr abcFlag, 
				 OpndPtr branchTarget) 
	: CompareOpInstruction(lineNum, 
			       srcLineNum, 
			       srcFileName, 
			       src1, 
			       src2, 
			       abcFlag),
	m_branchTarget(branchTarget),
	m_probability(OctaveInstruction::NONE)
	{}
      
      CompareOpBranchInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 RegPtr src1, 
				 OpndPtr src2, 
				 OpndPtr abcFlag, 
				 OpndPtr branchTarget,      
				 BranchProbability probability) 
	: CompareOpInstruction(lineNum, 
			       srcLineNum, 
			       srcFileName, 
			       src1, 
			       src2, 
			       abcFlag),
	m_branchTarget(branchTarget),
	m_probability(probability)
	{}
      
      CompareOpBranchInstruction(const CompareOpBranchInstruction& rhs) 
	: CompareOpInstruction(rhs),
	m_branchTarget(rhs.m_branchTarget),
	m_probability(rhs.m_probability)
	{}
      
      CompareOpBranchInstruction& operator=(const CompareOpBranchInstruction& rhs);
      
      
    private:
      
      OpndPtr m_branchTarget;
      BranchProbability m_probability;
    };
  
  
  //---------------------------------------------
  // CompareOpSignInstruction 
  //---------------------------------------------
  
  class CompareOpSignInstruction : public CompareOpInstruction
    {
    public:
      
      virtual ~CompareOpSignInstruction()
	{}

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool hasValidAbcFlag() const;


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      RegPtr getDst() const;
      
      OpndPtr getSign() const;
      
    protected:
      
      CompareOpSignInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       RegPtr src1, 
			       OpndPtr src2, 
			       RegPtr dst, 
			       OpndPtr abcFlag, 
			       OpndPtr sign) 
	: CompareOpInstruction(lineNum, 
			       srcLineNum, 
			       srcFileName, 
			       src1, 
			       src2, 
			       abcFlag),
	m_dst(dst),
	m_sign(sign)
	{}
      
      CompareOpSignInstruction(const CompareOpSignInstruction& rhs) 
	: CompareOpInstruction(rhs),
	m_dst(rhs.m_dst),
	m_sign(rhs.m_sign)
	{}
      
      CompareOpSignInstruction& operator=(const CompareOpSignInstruction& rhs);
      
    private:
      
      RegPtr m_dst;
      OpndPtr m_sign;
      
    };
  
  
  //---------------------------------------------
  // BitOpInstruction 
  //---------------------------------------------
  
  
  class BitOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~BitOpInstruction()
	{}
      
      OpndPtr getSrc1() const;
      
      UImmPtr getSrcBitNum() const;
      
      RegPtr  getDst() const;
      
      UImmPtr getDstBitNum() const;
      
      UImmPtr getNumBits() const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    protected:
      
      BitOpInstruction(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName, 
		       OpndPtr src,
		       UImmPtr srcBitNum, 
		       RegPtr dst,
		       UImmPtr dstBitNum, 
		       UImmPtr numBits) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_src1(src),
	m_srcBitNum(srcBitNum),
	m_dst(dst),
	m_dstBitNum(dstBitNum),
	m_numBits(numBits)
	{}
      
      BitOpInstruction(const BitOpInstruction& rhs) 
	: OctaveInstruction(rhs),
	m_src1(rhs.m_src1),
	m_srcBitNum(rhs.m_srcBitNum),
	m_dst(rhs.m_dst),
	m_dstBitNum(rhs.m_dstBitNum),
	m_numBits(rhs.m_numBits)
	{}
      
      BitOpInstruction& operator=(const BitOpInstruction& rhs);
      
    private:
      
      OpndPtr m_src1;
      
      UImmPtr m_srcBitNum;
      
      RegPtr  m_dst;
      
      UImmPtr m_dstBitNum;
      
      UImmPtr m_numBits;
      
    };
  
  
  //---------------------------------------------
  // BitOpImmInstruction 
  //---------------------------------------------
  
  
  class BitOpImmInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~BitOpImmInstruction()
	{}
      
      UImmPtr getSrc1() const;
      
      RegPtr  getDst() const;
      
      UImmPtr getDstBitNum() const;
      
      UImmPtr getNumBits() const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;
      
      BranchProbability getBranchProbability() const;

    protected:
      
      BitOpImmInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  UImmPtr src, 
			  RegPtr dst,
			  UImmPtr dstBitNum, 
			  UImmPtr numBits) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_src1(src),
	m_dst(dst),
	m_dstBitNum(dstBitNum),
	m_numBits(numBits)
	{}
      
      BitOpImmInstruction(const BitOpImmInstruction& rhs) 
	: OctaveInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_dstBitNum(rhs.m_dstBitNum),
	m_numBits(rhs.m_numBits)
	{}
      
      BitOpImmInstruction& operator=(const BitOpImmInstruction& rhs);
      
    private:
      
      UImmPtr m_src1;
      
      RegPtr  m_dst;
      
      UImmPtr m_dstBitNum;
      
      UImmPtr m_numBits;
      
    };
  
  
  //---------------------------------------------
  // CmovOpInstruction 
  //---------------------------------------------
  
  
  class CmovOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~CmovOpInstruction()
	{}
      
      RegPtr  getSrc1() const;
      
      OpndPtr getSrc2() const;
      
      RegPtr  getDst() const;
      
      EssPtr  getEssFlag() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    protected:
      
      CmovOpInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, RegPtr src1,
			OpndPtr src2, 
			RegPtr dst, 
			EssPtr essFlag)
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_src1(src1),
	m_src2(src2),
	m_dst(dst),
	m_essFlag(essFlag)
	{}
      
      CmovOpInstruction(const CmovOpInstruction& rhs) 
	: OctaveInstruction(rhs),
	m_src1(rhs.m_src1),
	m_src2(rhs.m_src2),
	m_dst(rhs.m_dst),
	m_essFlag(rhs.m_essFlag)
	{}
      
      CmovOpInstruction& operator=(const CmovOpInstruction& rhs);
      
    private:
      
      RegPtr  m_src1;
      
      OpndPtr m_src2;
      
      RegPtr  m_dst;
      
      EssPtr  m_essFlag;
      
    };
  
  
  //---------------------------------------------
  // DmaOpInstruction 
  //---------------------------------------------
  
  
  class DmaOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~DmaOpInstruction()
	{}
      
      MultiRegPtr getRegs() const;
      
      UImmPtr getDmaFlags() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    protected:
      
      DmaOpInstruction(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName, 
		       MultiRegPtr regs, 
		       UImmPtr flags) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_regs(regs),
	m_flags(flags)
	{}
      
      DmaOpInstruction(const DmaOpInstruction& rhs) 
	: OctaveInstruction(rhs),
	m_regs(rhs.m_regs),
	m_flags(rhs.m_flags)
	{}
      
      DmaOpInstruction& operator=(const DmaOpInstruction& rhs);
      
    private:
      
      MultiRegPtr m_regs;
      
      UImmPtr m_flags;
      
    };
  
  
  //---------------------------------------------
  // LoadOpInstruction 
  //---------------------------------------------
  
  
  class LoadOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~LoadOpInstruction()
	{}
      
      RegPtr getDst() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    protected:
      
      LoadOpInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			RegPtr dst) 
	: OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_dst(dst)
	{}
      
      LoadOpInstruction(const LoadOpInstruction& rhs) 
	: OctaveInstruction(rhs),
	m_dst(rhs.m_dst)
	{}
      
      LoadOpInstruction& operator=(const LoadOpInstruction& rhs);
      
    private:
      
      RegPtr m_dst;
      
    };
  
  
  //---------------------------------------------
  // LoadImmediateInstruction 
  //---------------------------------------------
  
  
  class LoadImmediateInstruction : public LoadOpInstruction
    {
    public:
      
      virtual ~LoadImmediateInstruction()
	{}
      
      OpndPtr getSrc() const;
      
    protected:
      
      LoadImmediateInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       RegPtr dst, 
			       OpndPtr src) 
	: LoadOpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    dst),
	m_src(src)
	{}
      
      LoadImmediateInstruction(const LoadImmediateInstruction& rhs) 
	: LoadOpInstruction(rhs),
	m_src(rhs.m_src)
	{}
      
      LoadImmediateInstruction& operator=(const LoadImmediateInstruction& rhs);
      
    private:
      
      OpndPtr m_src;
      
    };
  
  
  //---------------------------------------------
  // LoadHalfwordInstruction 
  //---------------------------------------------
  
  
  class LoadHalfwordInstruction : public LoadOpInstruction
    {
    public:
      
      virtual ~LoadHalfwordInstruction()
	{}
      
      OpndPtr getSrc() const;
      
    protected:
      
      LoadHalfwordInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      RegPtr dst, 
			      OpndPtr src) 
	: LoadOpInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName, 
			    dst),
	m_src(src)
	{}
      
      LoadHalfwordInstruction(const LoadHalfwordInstruction& rhs) 
	: LoadOpInstruction(rhs),
	m_src(rhs.m_src)
	{}
      
      LoadHalfwordInstruction& operator=(const LoadHalfwordInstruction& rhs);
      
    private:
      
      OpndPtr m_src;
      
    };
  
  
  //---------------------------------------------
  // MvhOpInstruction 
  //---------------------------------------------
  
  class MvhOpInstruction : public OctaveInstruction
    {
    public: 
      
      ~MvhOpInstruction()
	{}
      
      RegPtr getSrc() const;
      
      RegPtr getDst() const;
      
      OpndPtr getMvhFlag () const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    protected:
      
      MvhOpInstruction(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName, 
		       RegPtr src, 
		       RegPtr dst, 
		       OpndPtr mvhFlag)
        : OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_src(src),
	m_dst(dst),
	m_mvhFlag(mvhFlag)
	{}
      
      MvhOpInstruction(const MvhOpInstruction& rhs)
	: OctaveInstruction(rhs),
	m_src(rhs.m_src),
	m_dst(rhs.m_dst),
	m_mvhFlag(rhs.m_mvhFlag)

	{}
      
      MvhOpInstruction& operator=(const MvhOpInstruction& rhs);
      
    private:
      
      RegPtr  m_src;
      
      RegPtr  m_dst;
      
      OpndPtr m_mvhFlag;
      
    };
  
  
  //---------------------------------------------
  // MultiRegOpInstruction 
  //---------------------------------------------
  
  
  class MultiRegOpInstruction : public OctaveInstruction
    {
    public:
      
      virtual ~MultiRegOpInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      MultiRegPtr getRegs() const;

    protected:
      
      MultiRegOpInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName,
			    MultiRegPtr regs) : 
	OctaveInstruction(lineNum, 
			  srcLineNum, 
			  srcFileName),
	m_regs(regs)
	{}
      
      MultiRegOpInstruction(const MultiRegOpInstruction& rhs) 
	: OctaveInstruction(rhs)
	{}
      
      MultiRegOpInstruction& operator=(const MultiRegOpInstruction& rhs);
      
    private:
      
      MultiRegPtr m_regs;

    };
  
  
  //---------------------------------------------
  // MultiRegLinkInstruction 
  //---------------------------------------------
  
  
  class MultiRegLinkInstruction : public MultiRegOpInstruction
    {
    public:
      
      virtual ~MultiRegLinkInstruction()
	{}
      
      MemPtr getMem() const;
      
      LinkPtr getLinkFlag() const;
      
    protected:
      
      MultiRegLinkInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, MultiRegPtr regs,
			      MemPtr mem, 
			      LinkPtr linkFlag) 
	: MultiRegOpInstruction(lineNum, 
				srcLineNum, 
				srcFileName, 
				regs),
	m_mem(mem),
	m_linkFlag(linkFlag)
	{}
      
      MultiRegLinkInstruction(const MultiRegLinkInstruction& rhs) 
	: MultiRegOpInstruction(rhs),
	m_mem(rhs.m_mem),
	m_linkFlag(rhs.m_linkFlag)
	{}
      
      MultiRegLinkInstruction& operator=(const MultiRegLinkInstruction& rhs);
      
    private:
      
      //      MultiRegPtr m_regs;
      
      MemPtr m_mem;
      
      LinkPtr m_linkFlag;
      
    };
  
  
  //---------------------------------------------
  // MultiRegLoadInstruction 
  //---------------------------------------------
  
  
  class MultiRegLoadInstruction : public MultiRegOpInstruction
    {
    public:
      
      virtual ~MultiRegLoadInstruction()
	{}
      
      MemPtr getMem() const;
      
      OpndPtr getLinkFlag() const;
      
    protected:
      
      MultiRegLoadInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      MultiRegPtr regs,
			      MemPtr mem, 
			      OpndPtr linkFlag) 
	: MultiRegOpInstruction(lineNum, 
				srcLineNum, 
				srcFileName, 
				regs),
	m_mem(mem),
	m_linkFlag(linkFlag)
	{}
      
      MultiRegLoadInstruction(const MultiRegLoadInstruction& rhs) 
	: MultiRegOpInstruction(rhs),
	m_mem(rhs.m_mem),
	m_linkFlag(rhs.m_linkFlag)
	{}
      
      MultiRegLoadInstruction& operator=(const MultiRegLoadInstruction& rhs);
      
    private:
      
      MemPtr m_mem;
      
      OpndPtr m_linkFlag;
      
    };
  
  
  //---------------------------------------------
  // MultiRegStoreInstruction 
  //---------------------------------------------
  
  
  class MultiRegStoreInstruction : public MultiRegOpInstruction
    {
    public:
      
      virtual ~MultiRegStoreInstruction()
	{}
      
      MemPtr getMem() const;
      
    protected:
      
      MultiRegStoreInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       MultiRegPtr regs,
			       MemPtr mem) 
	: MultiRegOpInstruction(lineNum, 
				srcLineNum, 
				srcFileName, 
				regs),
	m_mem(mem)
	{}
      
      MultiRegStoreInstruction(const MultiRegStoreInstruction& rhs) 
	: MultiRegOpInstruction(rhs),
	m_mem(rhs.m_mem)
	{}
      
      MultiRegStoreInstruction& operator=(const MultiRegStoreInstruction& rhs);
      
    private:
      
      MemPtr m_mem;
      
    };
  

  
  //---------------------------------------------
  // TssOpInstruction 
  //---------------------------------------------
  
  class TssOpInstruction : public OctaveInstruction
    {
    public: 
      
      ~TssOpInstruction()
	{}
      
      OpndPtr getTssFlags() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

    protected:
      
      TssOpInstruction(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName, 
		       OpndPtr flags)
        : OctaveInstruction(lineNum, 
			    srcLineNum, 
			    srcFileName),
	m_flags(flags)
	{}
      
      TssOpInstruction(const TssOpInstruction& rhs)
	: OctaveInstruction(rhs),
	m_flags(rhs.m_flags)
	{}
      
      TssOpInstruction& operator=(const TssOpInstruction& rhs);
      
    private:
      
      OpndPtr m_flags;
      
    };
  
  
  //---------------------------------------------
  // TssRcOpInstruction 
  //---------------------------------------------
  
  class TssRcOpInstruction : public TssOpInstruction
    {
    public: 
      
      ~TssRcOpInstruction()
	{}
      
      RegPtr getRsa() const;
      
    protected:
      
      TssRcOpInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr rsa, 
			 OpndPtr flags)
        : TssOpInstruction(lineNum, 
			   srcLineNum, 
			   srcFileName, 
			   flags),
	m_rsa(rsa)
	{}
      
      TssRcOpInstruction(const TssRcOpInstruction& rhs)
	: TssOpInstruction(rhs),
	m_rsa(rhs.m_rsa)
	{}
      
      TssRcOpInstruction& operator=(const TssRcOpInstruction& rhs);
      
    private:
      
      RegPtr m_rsa;
      
    };


  
  //---------------------------------------------
  // TssNoRcOpInstruction 
  //---------------------------------------------
  
  class TssNoRcOpInstruction : public TssOpInstruction
    {
    public: 
      
      ~TssNoRcOpInstruction()
	{}
      
      UImmPtr getParOffset() const;
      
      UImmPtr getPosOffset() const;
      
    protected:
      
      TssNoRcOpInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   UImmPtr parOffset, 
			   UImmPtr posOffset, 
			   OpndPtr flags)
        : TssOpInstruction(lineNum, 
			   srcLineNum, 
			   srcFileName, 
			   flags),
	m_parOffset(parOffset),
	m_posOffset(posOffset)
	{}
      
      TssNoRcOpInstruction(const TssNoRcOpInstruction& rhs)
	: TssOpInstruction(rhs),
	m_parOffset(rhs.m_parOffset),
	m_posOffset(rhs.m_posOffset)
	{}
      
      TssNoRcOpInstruction& operator=(const TssNoRcOpInstruction& rhs);
      
    private:
      
      UImmPtr m_parOffset;
      
      UImmPtr m_posOffset;
      
    };

  
  //---------------------------------------------
  //---------------------------------------------
  
} // end namespace Llir
  
#endif
