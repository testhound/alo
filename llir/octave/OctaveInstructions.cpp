#include <iostream>
using namespace std;


#include <LlirVisitor.h>
#include <LlirException.h>

#include "OctaveVisitor.h"
#include "OctaveInstructions.h"

namespace Llir {
  


  
  //---------------------------------------------
  // OctaveInstruction
  //---------------------------------------------
  
  OctaveInstruction& 
  OctaveInstruction::operator=(const OctaveInstruction& rhs) 
  {
    if(this == &rhs)
      return *this;
    
    LlirInstruction::operator=(rhs);
    m_inInstructionSequence = rhs.m_inInstructionSequence;
    return *this;
    
  }

  void
  OctaveInstruction::setInInstructionSequence()
  {
    m_inInstructionSequence = true;
  }

  bool
  OctaveInstruction::inInstructionSequence() const
  {
    return m_inInstructionSequence;
  }

  bool
  OctaveInstruction::setRegistersLive() const
  {
    if(isSetRegListEmpty())
      return true;

    bool foundLiveRegs = false;

    RegOpndConstIterator iter = beginSetRegList();

    for(; iter != endSetRegList(); iter++)
      {
	shared_ptr<const Register> reg = *iter;

	if(isRegisterLive(reg->getRegNum()))
	  {    
	    //Not all all set registers are dead.
	    //Found atleast one destination register
	    //being used subsequently.

	    foundLiveRegs = true;
	    break;
	  }
      }

    return foundLiveRegs;
  }

  bool
  OctaveInstruction::isRegisterLive(unsigned int regNum) const
  {
    bool live = true;

    RegOpndConstIterator iter = beginUnusedRegList();

    for(; iter != endUnusedRegList(); iter++)
      {
	shared_ptr<const Register> reg = *iter;
	if(reg->getRegNum() == regNum)
	  {
	    live = false;
	    break;
	  }
      }

    return live;
  }
  
  bool
  OctaveInstruction::isSetRegListEmpty() const
  {
    return m_setRegList.empty();
  }

  bool
  OctaveInstruction::isUsedRegListEmpty() const
  {
    return m_usedRegList.empty();
  }

  bool
  OctaveInstruction::isUnusedRegListEmpty() const
  {
    return m_unusedRegList.empty();
  }

  bool
  OctaveInstruction::isDeadRegListEmpty() const
  {
    return m_deadRegList.empty();
  }

  //iterators to access the set of
  //registers operand which are 'set' in
  //the current insn

  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::beginSetRegList() const
  {
    return m_setRegList.begin();
  }
  
  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::endSetRegList() const
  {
    return m_setRegList.end();
  }

  //iterators to access the set of
  //registers operand which are 'used' in
  //the current insn

  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::beginUsedRegList() const
  {
    return m_usedRegList.begin();
  }
  
  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::endUsedRegList() const
  {
    return m_usedRegList.end();
  }

  //iterators to access the set of
  //registers operand which are 'used' in
  //the current insn and 'unused' later in
  //the chain

  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::beginUnusedRegList() const
  {
    return m_unusedRegList.begin();
  }
  
  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::endUnusedRegList() const
  {
    return m_unusedRegList.end();
  }


  //iterators to access the set of
  //registers operand which are 'used/set' in
  //the current insn and are dead later in
  //the chain

  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::beginDeadRegList() const
  {
    return m_deadRegList.begin();
  }
  
  OctaveInstruction::RegOpndConstIterator
  OctaveInstruction::endDeadRegList() const
  {
    return m_deadRegList.end();
  }

  void
  OctaveInstruction::addSetRegister(shared_ptr<const LlirOperand> opnd) const
  {
    shared_ptr<const SingleRegister> reg = shared_dynamic_cast<const SingleRegister>(opnd);
    shared_ptr<const MultiHardRegister> mhreg = shared_dynamic_cast<const MultiHardRegister>(opnd);
    shared_ptr<const MultiPseudoRegister> mpreg = shared_dynamic_cast<const MultiPseudoRegister>(opnd);

    if(reg)
      {
	m_setRegList.push_back(reg);
      }
    else if(mhreg)
      {
	MultiHardRegister::ConstIterator iter = mhreg->begin();
	for(; iter != mhreg->end(); iter++)
	  {
	    m_setRegList.push_back(*iter);
	  }
      }
    else if(mpreg)
      {
	MultiPseudoRegister::ConstIterator iter = mpreg->begin();
	for(; iter != mpreg->end(); iter++)
	  {
	    m_setRegList.push_back(*iter);
	  }
      }
  }

  void
  OctaveInstruction::addUsedRegister(shared_ptr<const LlirOperand> opnd) const
  {
    shared_ptr<const SingleRegister> reg = shared_dynamic_cast<const SingleRegister>(opnd);
    shared_ptr<const MultiHardRegister> mhreg = shared_dynamic_cast<const MultiHardRegister>(opnd);
    shared_ptr<const MultiPseudoRegister> mpreg = shared_dynamic_cast<const MultiPseudoRegister>(opnd);

    if(reg)
      {
	m_usedRegList.push_back(reg);
      }
    else if(mhreg)
      {
	MultiHardRegister::ConstIterator iter = mhreg->begin();
	for(; iter != mhreg->end(); iter++)
	  {
	    m_usedRegList.push_back(*iter);
	  }
      }
    else if(mpreg)
      {
	MultiPseudoRegister::ConstIterator iter = mpreg->begin();
	for(; iter != mpreg->end(); iter++)
	  {
	    m_usedRegList.push_back(*iter);
	  }
      }
  }

  void
  OctaveInstruction::addDeadRegister(shared_ptr<const LlirOperand> opnd) const
  {
    shared_ptr<const SingleRegister> reg = shared_dynamic_cast<const SingleRegister>(opnd);
    shared_ptr<const MultiHardRegister> mhreg = shared_dynamic_cast<const MultiHardRegister>(opnd);
    shared_ptr<const MultiPseudoRegister> mpreg = shared_dynamic_cast<const MultiPseudoRegister>(opnd);

    if(reg)
      {
	m_deadRegList.push_back(reg);
      }
    else if(mhreg)
      {
	MultiHardRegister::ConstIterator iter = mhreg->begin();
	for(; iter != mhreg->end(); iter++)
	  {
	    m_deadRegList.push_back(*iter);
	  }
      }
    else if(mpreg)
      {
	MultiPseudoRegister::ConstIterator iter = mpreg->begin();
	for(; iter != mpreg->end(); iter++)
	  {
	    m_deadRegList.push_back(*iter);
	  }
      }
  }

  void
  OctaveInstruction::addUnusedRegister(shared_ptr<const LlirOperand> opnd) const
  {
    shared_ptr<const SingleRegister> reg = shared_dynamic_cast<const SingleRegister>(opnd);
    shared_ptr<const MultiHardRegister> mhreg = shared_dynamic_cast<const MultiHardRegister>(opnd); 
    shared_ptr<const MultiPseudoRegister> mpreg = shared_dynamic_cast<const MultiPseudoRegister>(opnd);
    if(reg)
      {
	m_unusedRegList.push_back(reg);
      }
    else if(mhreg)
      {
	MultiHardRegister::ConstIterator iter = mhreg->begin();
	for(; iter != mhreg->end(); iter++)
	  {
	    m_unusedRegList.push_back(*iter);
	  }
      }
    else if(mpreg)
      {
	MultiPseudoRegister::ConstIterator iter = mpreg->begin();
	for(; iter != mpreg->end(); iter++)
	  {
	    m_unusedRegList.push_back(*iter);
	  }
      }
  }

  //--------------------------------------------------
  // NullInstruction
  //--------------------------------------------------

  NullInstruction::NullInstruction(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName) 
    : OctaveInstruction(lineNum, srcLineNum, srcFileName)
  {}
			       
  NullInstruction::NullInstruction(const NullInstruction& rhs)
    : OctaveInstruction(rhs)
  {}

  NullInstruction::~NullInstruction()
  {}

  NullInstruction& 
  NullInstruction::operator=(const NullInstruction& n)
  {
    return *this;
  }

  unsigned int 
  NullInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  NullInstruction::isPseudoInsn() const
  {
    return false;
  }

  bool 
  NullInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  NullInstruction::isValidDslotInsn() const
  {
    return false;
  }

  OctaveInstruction::BranchProbability 
  NullInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  void 
  NullInstruction::accept(Visitor& v) const
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

  bool 
  NullInstruction::equalTo(const LlirNode& n) const
  {
    if(getLineNum() == n.getLineNum())
      return true;
    else
      return false;
  }

  //------------------------------
  //InvalidOctaveInstruction Class
  //------------------------------

  InvalidOctaveInstruction::InvalidOctaveInstruction(unsigned int lineNum,
						     unsigned int srcLineNum,
						     const char* srcFileName)
    : OctaveInstruction(lineNum, srcLineNum, srcFileName)
  {}

  InvalidOctaveInstruction::InvalidOctaveInstruction(const InvalidOctaveInstruction& rhs)
    : OctaveInstruction(rhs)
  {}


  InvalidOctaveInstruction& 
  InvalidOctaveInstruction::operator=(const InvalidOctaveInstruction &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveInstruction::operator=(rhs);
    return *this;
  }

  bool 
  InvalidOctaveInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  InvalidOctaveInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  InvalidOctaveInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  InvalidOctaveInstruction::isValidDslotInsn() const
  {
    return false;
  }

  OctaveInstruction::BranchProbability 
  InvalidOctaveInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  void 
  InvalidOctaveInstruction::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    throw LLIR_INTERNAL_EXCEPTION("InvalidOctaveInstruction is a non-aggregate node");
  }

  void 
  InvalidOctaveInstruction::addOperand(shared_ptr<const LlirOperand> op)
  {
    LlirInstruction::addOperand(op);
  }

  void
  InvalidOctaveInstruction::accept(Visitor &v) const
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


  LlirNode::Iterator
  InvalidOctaveInstruction::begin()
  {
    throw LLIR_INTERNAL_EXCEPTION("InvalidOctaveInstruction is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::Iterator
  InvalidOctaveInstruction::end()
  {
    throw LLIR_INTERNAL_EXCEPTION("InvalidOctaveInstruction is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }



  LlirNode::ConstIterator
  InvalidOctaveInstruction::begin() const
  {
    throw LLIR_INTERNAL_EXCEPTION("InvalidOctaveInstruction is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }


  LlirNode::ConstIterator
  InvalidOctaveInstruction::end() const
  {
    throw LLIR_INTERNAL_EXCEPTION("InvalidOctaveInstruction is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }


  bool
  InvalidOctaveInstruction::equalTo(const LlirNode &rhs) const
  {
    const InvalidOctaveInstruction &r = dynamic_cast<const InvalidOctaveInstruction&> (rhs);

    if(getLineNum() == r.getLineNum())
      {
	return true; 
      }
    else
      {
	return false;
      }
  }
  
  //---------------------------------------------
  // AluOpInstruction 
  //---------------------------------------------

  OctaveInstruction::BranchProbability 
  AluOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }
  
  AluOpInstruction& 
  AluOpInstruction::operator=(const AluOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }

  //---------------------------------------------
  // Alu2OpInstruction
  //---------------------------------------------

  OctaveInstruction::BranchProbability 
  Alu2OpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  OpndPtr
  Alu2OpInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  RegPtr
  Alu2OpInstruction::getDst() const
  {
    return m_dst;
  }
  
  Alu2OpInstruction& 
  Alu2OpInstruction::operator=(const Alu2OpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    AluOpInstruction::operator=(rhs);
    m_src1 = rhs.m_src1;
    m_dst  = rhs.m_dst;
    return *this;
    
  }
  
  //---------------------------------------------
  // Alu2OpBranchInstruction
  //---------------------------------------------



  bool 
  Alu2OpBranchInstruction::isPseudoInsn() const
  {
    return false;
  }


  unsigned int 
  Alu2OpBranchInstruction::getNumDelaySlots() const
  {
    if(hasValidBranchTarget())
      {
	return 1;
      }
    else
      {
	return 0;
      }
  }

  bool 
  Alu2OpBranchInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  Alu2OpBranchInstruction::isBranchInsn() const
  {
    if(hasValidBranchTarget())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu2OpBranchInstruction::isValidDslotInsn() const
  {
    if(hasValidBranchTarget())
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  OctaveInstruction::BranchProbability 
  Alu2OpBranchInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  bool
  Alu2OpBranchInstruction::hasValidBranchTarget() const
  {
    shared_ptr<const LlirOperand> opnd = getBranchTarget();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
	return false;
      }
    else
      {
	return true;
      }
  }
  

  OpndPtr
  Alu2OpBranchInstruction::getBranchTarget() const
  {
    return m_target;
  }
  
  Alu2OpBranchInstruction&
  Alu2OpBranchInstruction::operator=(const Alu2OpBranchInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpInstruction::operator=(rhs);
    m_target = rhs.m_target;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // Alu2OpFindInstruction
  //---------------------------------------------
  

  bool 
  Alu2OpFindInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  Alu2OpFindInstruction::getNumDelaySlots() const
  {
    if(hasValidAbcFlag())
      {
	return 3;
      }
    else
      {
	return 0;
      }
  }

  bool 
  Alu2OpFindInstruction::isAbcInsn() const
  {
    if(hasValidAbcFlag())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu2OpFindInstruction::isBranchInsn() const
  {
    if(hasValidAbcFlag())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu2OpFindInstruction::isValidDslotInsn() const
  {
    if(hasValidAbcFlag())
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  bool
  Alu2OpFindInstruction::hasValidAbcFlag() const
  {
    shared_ptr<const LlirOperand> opnd = getAbcFlag();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
	return false;
      }
    else
      {
	return true;
      }
  }



  OpndPtr
  Alu2OpFindInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  OpndPtr
  Alu2OpFindInstruction::getFindFlag() const
  {
    return m_findFlag;
  }
  
  Alu2OpFindInstruction&
  Alu2OpFindInstruction::operator=(const Alu2OpFindInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpInstruction::operator=(rhs);
    m_abcFlag  = rhs.m_abcFlag;
    m_findFlag = rhs.m_findFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // Alu3OpInstruction
  //---------------------------------------------
  
  OctaveInstruction::BranchProbability 
  Alu3OpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  RegPtr
  Alu3OpInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  Alu3OpInstruction::getSrc2() const
  {
    return m_src2;
  }
  
  RegPtr
  Alu3OpInstruction::getDst() const
  {
    return m_dst;
  }
  
  Alu3OpInstruction& 
  Alu3OpInstruction::operator=(const Alu3OpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    AluOpInstruction::operator=(rhs);
    m_src1 = rhs.m_src1;
    m_src2 = rhs.m_src2;
    m_dst  = rhs.m_dst;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // Alu3OpAbcModInstruction
  //---------------------------------------------


  bool 
  Alu3OpAbcModInstruction::isPseudoInsn() const
  {
    return false;
  }

  
  unsigned int 
  Alu3OpAbcModInstruction::getNumDelaySlots() const
  {
    if(hasValidAbcFlag())
      {
	return 3;
      }
    else
      {
	return 0;
      }
  }

  bool 
  Alu3OpAbcModInstruction::isAbcInsn() const
  {
    if(hasValidAbcFlag())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu3OpAbcModInstruction::isBranchInsn() const
  {
    if(hasValidAbcFlag())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu3OpAbcModInstruction::isValidDslotInsn() const
  {
    if(hasValidAbcFlag())
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  bool
  Alu3OpAbcModInstruction::hasValidAbcFlag() const
  {
    shared_ptr<const LlirOperand> opnd = getAbcFlag();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
	return false;
      }
    else
      {
	return true;
      }
  }


  
  OpndPtr
  Alu3OpAbcModInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  OpndPtr
  Alu3OpAbcModInstruction::getModFlag() const
  {
    return m_modFlag;
  }
  
  Alu3OpAbcModInstruction&
  Alu3OpAbcModInstruction::operator=(const Alu3OpAbcModInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    m_abcFlag = rhs.m_abcFlag;
    m_modFlag = rhs.m_modFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // Alu3OpAbcInstruction
  //---------------------------------------------


  bool 
  Alu3OpAbcInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  Alu3OpAbcInstruction::getNumDelaySlots() const
  {
    if(hasValidAbcFlag())
      {
	return 3;
      }
    else
      {
	return 0;
      }
  }

  bool 
  Alu3OpAbcInstruction::isAbcInsn() const
  {
    if(hasValidAbcFlag())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu3OpAbcInstruction::isBranchInsn() const
  {
    if(hasValidAbcFlag())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  Alu3OpAbcInstruction::isValidDslotInsn() const
  {
    if(hasValidAbcFlag())
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  bool
  Alu3OpAbcInstruction::hasValidAbcFlag() const
  {
    shared_ptr<const LlirOperand> opnd = getAbcFlag();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  

  OpndPtr
  Alu3OpAbcInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  Alu3OpAbcInstruction&
  Alu3OpAbcInstruction::operator=(const Alu3OpAbcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    m_abcFlag = rhs.m_abcFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // Alu3OpSxInstruction
  //---------------------------------------------
  
  
  //FIXME : mulX  insns have  3 cycle delay
  //FIXME : divX  insns have 25 cycle delay
  //within those cycles no other mul/div insn should
  //be placed... need to enforce this in delay slot
  //checking phase...


  bool 
  Alu3OpSxInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  Alu3OpSxInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  Alu3OpSxInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  Alu3OpSxInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OpndPtr
  Alu3OpSxInstruction::getSxFlag() const
  {
    return m_sxFlag;
  }
  
  Alu3OpSxInstruction&
  Alu3OpSxInstruction::operator=(const Alu3OpSxInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    m_sxFlag = rhs.m_sxFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // BitOpInstruction
  //---------------------------------------------

  bool 
  BitOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  BitOpInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  BitOpInstruction::isAbcInsn() const
  {
    return false;
  }
   
  bool 
  BitOpInstruction::isValidDslotInsn() const
  {
    return true;
  }
  
  OctaveInstruction::BranchProbability 
  BitOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  OpndPtr
  BitOpInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  UImmPtr
  BitOpInstruction::getSrcBitNum() const
  {
    return m_srcBitNum;
  }
  
  RegPtr
  BitOpInstruction::getDst() const
  {
    return m_dst;
  }
  
  UImmPtr
  BitOpInstruction::getDstBitNum() const
  {
    return m_dstBitNum;
  }
  
  UImmPtr
  BitOpInstruction::getNumBits() const
  {
    return m_numBits;
  }


  
  BitOpInstruction&
  BitOpInstruction::operator=(const BitOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src1      = rhs.m_src1;
    m_srcBitNum = rhs.m_srcBitNum;
    m_dst       = rhs.m_dst;
    m_dstBitNum = rhs.m_dstBitNum;
    m_numBits   = rhs.m_numBits;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // BitOpImmInstruction
  //---------------------------------------------

  bool 
  BitOpImmInstruction::isPseudoInsn() const
  {
    return false;
  }


  unsigned int 
  BitOpImmInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  BitOpImmInstruction::isAbcInsn() const
  {
    return false;
  }
    
  bool 
  BitOpImmInstruction::isValidDslotInsn() const
  {
    return true;
  }
  
  OctaveInstruction::BranchProbability 
  BitOpImmInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  UImmPtr
  BitOpImmInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  RegPtr
  BitOpImmInstruction::getDst() const
  {
    return m_dst;
  }
  
  UImmPtr
  BitOpImmInstruction::getDstBitNum() const
  {
    return m_dstBitNum;
  }
  
  UImmPtr
  BitOpImmInstruction::getNumBits() const
  {
    return m_numBits;
  }
  
  BitOpImmInstruction&
  BitOpImmInstruction::operator=(const BitOpImmInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src1      = rhs.m_src1;
    m_dst       = rhs.m_dst;
    m_dstBitNum = rhs.m_dstBitNum;
    m_numBits   = rhs.m_numBits;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // CmovOpInstruction
  //---------------------------------------------

  bool 
  CmovOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  CmovOpInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  CmovOpInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  CmovOpInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  CmovOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  RegPtr
  CmovOpInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  CmovOpInstruction::getSrc2() const
  {
    return m_src2;
  }
  
  RegPtr
  CmovOpInstruction::getDst() const
  {
    return m_dst;
  }
  
  EssPtr
  CmovOpInstruction::getEssFlag() const
  {
    return m_essFlag;
  }
  
  CmovOpInstruction&
  CmovOpInstruction::operator=(const CmovOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src1    = rhs.m_src1;
    m_src2    = rhs.m_src2;
    m_dst     = rhs.m_dst;
    m_essFlag = rhs.m_essFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // DmaOpInstruction
  //---------------------------------------------

  bool 
  DmaOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  DmaOpInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  DmaOpInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  DmaOpInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  DmaOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  MultiRegPtr
  DmaOpInstruction::getRegs() const
  {
    return m_regs;
  }
  
  UImmPtr
  DmaOpInstruction::getDmaFlags() const
  {
    return m_flags;
  }
  
  DmaOpInstruction&
  DmaOpInstruction::operator=(const DmaOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_regs  = rhs.m_regs;
    m_flags = rhs.m_flags;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // LoadOpInstruction
  //---------------------------------------------

  bool 
  LoadOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  LoadOpInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool 
  LoadOpInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  LoadOpInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  LoadOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  RegPtr
  LoadOpInstruction::getDst() const
  {
    return m_dst;
  }
  
  LoadOpInstruction&
  LoadOpInstruction::operator=(const LoadOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_dst = rhs.m_dst;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // LoadImmediateInstruction
  //---------------------------------------------
  

  OpndPtr
  LoadImmediateInstruction::getSrc() const
  {
    return m_src;
  }
  
  LoadImmediateInstruction&
  LoadImmediateInstruction::operator=(const LoadImmediateInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadOpInstruction::operator=(rhs);
    m_src = rhs.m_src;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // LoadHalfwordInstruction
  //---------------------------------------------
  
  OpndPtr
  LoadHalfwordInstruction::getSrc() const
  {
    return m_src;
  }
  
  LoadHalfwordInstruction&
  LoadHalfwordInstruction::operator=(const LoadHalfwordInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadOpInstruction::operator=(rhs);
    m_src = rhs.m_src;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // MvhOpInstruction
  //---------------------------------------------

  bool 
  MvhOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  MvhOpInstruction::getNumDelaySlots() const
  {
    return 0; 

    //FIXME : Do we need to change this to
    //CN value contained in Mvhflag....
    //are they delay slots?
  }

  bool 
  MvhOpInstruction::isAbcInsn() const
  {
    return false;
  }

  bool 
  MvhOpInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  MvhOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  RegPtr
  MvhOpInstruction::getSrc() const
  {
    return m_src;
  }
  
  RegPtr
  MvhOpInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  MvhOpInstruction::getMvhFlag() const
  {
    return m_mvhFlag;
  }
  
  MvhOpInstruction&
  MvhOpInstruction::operator=(const MvhOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src     = rhs.m_src;
    m_dst     = rhs.m_dst;
    m_mvhFlag = rhs.m_mvhFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // MultiRegOpInstruction
  //---------------------------------------------

  bool 
  MultiRegOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int 
  MultiRegOpInstruction::getNumDelaySlots() const
  {
    return 0;
  }
  
  bool 
  MultiRegOpInstruction::isAbcInsn() const
  {
    return false;
  }
    
  bool 
  MultiRegOpInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  MultiRegOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  MultiRegPtr 
  MultiRegOpInstruction::getRegs() const
  {
    return m_regs;
  }

  MultiRegOpInstruction&
  MultiRegOpInstruction::operator=(const MultiRegOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    m_regs = rhs.m_regs;
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }
  
  //---------------------------------------------
  // MultiRegLinkInstruction
  //---------------------------------------------
  
  MemPtr
  MultiRegLinkInstruction::getMem() const
  {
    return m_mem;
  }
  
  LinkPtr
  MultiRegLinkInstruction::getLinkFlag() const
  {
    return m_linkFlag;
  }
  
  MultiRegLinkInstruction&
  MultiRegLinkInstruction::operator=(const MultiRegLinkInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegOpInstruction::operator=(rhs);
    m_mem      = rhs.m_mem;
    m_linkFlag = rhs.m_linkFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // MultiRegLoadInstruction
  //---------------------------------------------
  
  MemPtr
  MultiRegLoadInstruction::getMem() const
  {
    return m_mem;
  }
  
  OpndPtr
  MultiRegLoadInstruction::getLinkFlag() const
  {
    return m_linkFlag;
  }
  
  MultiRegLoadInstruction&
  MultiRegLoadInstruction::operator=(const MultiRegLoadInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegOpInstruction::operator=(rhs);
    m_mem      = rhs.m_mem;
    m_linkFlag = rhs.m_linkFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // MultiRegStoreInstruction
  //---------------------------------------------
  
  MemPtr
  MultiRegStoreInstruction::getMem() const
  {
    return m_mem;
  }
 
  MultiRegStoreInstruction&
  MultiRegStoreInstruction::operator=(const MultiRegStoreInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegOpInstruction::operator=(rhs);
    m_mem      = rhs.m_mem;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // BranchOpInstruction 
  //---------------------------------------------

  OctaveInstruction::BranchProbability 
  BranchOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  bool
  BranchOpInstruction::isAbcInsn() const
  {
    return false;
  }

  BranchOpInstruction& 
  BranchOpInstruction::operator=(const BranchOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  //---------------------------------------------
  // CondBranchInstruction
  //---------------------------------------------

  bool
  CondBranchInstruction::hasReturnReg() const
  {
    if(! getDst()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getDst());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  bool 
  CondBranchInstruction::isReturnInsn() const
  {

    if(! getSrc1()->isNullOperand())
      {
	shared_ptr<const Register> rpc = getSrc1();

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  RegPtr
  CondBranchInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  EssPtr
  CondBranchInstruction::getEss() const
  {
    return m_ess;
  }
  
  OpndPtr
  CondBranchInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  CondBranchInstruction::getFlags() const
  {
    return m_flags;
  }
  
  CondBranchInstruction& 
  CondBranchInstruction::operator=(const CondBranchInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1  = rhs.m_src1;
    m_ess   = rhs.m_ess;
    m_dst   = rhs.m_dst;
    m_flags = rhs.m_flags;
    return *this;
    
  }

  bool
  CondBranchInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  CondBranchInstruction::isValidDslotInsn() const
  {
    return false;
  }


  bool
  CondBranchInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  OctaveInstruction::BranchProbability 
  CondBranchInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  bool
  CondBranchInstruction::hasValidCFlag() const
  {
    shared_ptr<const LlirOperand> flags = getFlags();

    shared_ptr<const CbranchFlags> cbrFlags = shared_dynamic_cast<const CbranchFlags>(flags);

    if(cbrFlags)
      {
	CbranchFlags::ConstIterator iter = cbrFlags->begin();

	for(; iter != cbrFlags->end(); iter++)
	  {
	    shared_ptr<const CFlag> cflag = shared_dynamic_cast<const CFlag>(*iter);
	    
	    if(cflag)
	      {
		return true;
	      }
	  }

	return false;

      }
    else
      {
	return false;
      }
  }
  
  //---------------------------------------------
  // CondBranchImmedInstruction
  //---------------------------------------------

  OpndPtr
  CondBranchImmedInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  EssPtr
  CondBranchImmedInstruction::getEss() const
  {
    return m_ess;
  }
  
  OpndPtr
  CondBranchImmedInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  CondBranchImmedInstruction::getFlags() const
  {
    return m_flags;
  }
  
  CondBranchImmedInstruction& 
  CondBranchImmedInstruction::operator=(const CondBranchImmedInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1  = rhs.m_src1;
    m_ess   = rhs.m_ess;
    m_dst   = rhs.m_dst;
    m_flags = rhs.m_flags;
    return *this;
    
  }

  bool
  CondBranchImmedInstruction::isBranchInsn() const
  {
    return true;
  }
  
  bool
  CondBranchImmedInstruction::isValidDslotInsn() const
  {
    return false;
  }
  
  bool
  CondBranchImmedInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool
  CondBranchImmedInstruction::hasReturnReg() const
  {
    if(! getDst()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getDst());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  OctaveInstruction::BranchProbability 
  CondBranchImmedInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  bool
  CondBranchImmedInstruction::hasValidCFlag() const
  {
    shared_ptr<const LlirOperand> flags = getFlags();

    shared_ptr<const CbranchFlags> cbrFlags = shared_dynamic_cast<const CbranchFlags>(flags);

    if(cbrFlags)
      {
	CbranchFlags::ConstIterator iter = cbrFlags->begin();

	for(; iter != cbrFlags->end(); iter++)
	  {
	    shared_ptr<const CFlag> cflag = shared_dynamic_cast<const CFlag>(*iter);
	    
	    if(cflag)
	      {
		return true;
	      }
	  }

	return false;

      }
    else
      {
	return false;
      }
  }
  
  
  //---------------------------------------------
  // ZeroBranchInstruction
  //---------------------------------------------

  bool 
  ZeroBranchInstruction::isReturnInsn() const
  {
    // b[n]zr rsa rsb [rpc]

    // 1. b[n]zr rsa rsb      <- jump insn
    // 2. b[n]zr rsa rsb rpc  <- call insn
    // 3. b[n]zr rsa rpc      <- return insn

    // if rpc is not specified and rsb == 60/61/62
    // this insn acts like a return insn.

    if(getCmpReg()->isNullOperand())
      {
	shared_ptr<const Register> rsb = getSrc2();
	unsigned int rsbRegNum = rsb->getRegNum();
	
	if(rsbRegNum == 60 || 
	   rsbRegNum == 61 ||
	   rsbRegNum == 62)
	  return true;
      }
      
    return false;
  }

  bool
  ZeroBranchInstruction::hasReturnReg() const
  {
    if(! getCmpReg()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getCmpReg());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }


  bool
  ZeroBranchInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  ZeroBranchInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  ZeroBranchInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  OctaveInstruction::BranchProbability 
  ZeroBranchInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  RegPtr
  ZeroBranchInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  RegPtr
  ZeroBranchInstruction::getSrc2() const
  {
    return m_src2;
  }

  OpndPtr
  ZeroBranchInstruction::getCmpReg() const
  {
    return m_cmpReg;
  }
  
  ZeroBranchInstruction& 
  ZeroBranchInstruction::operator=(const ZeroBranchInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1  = rhs.m_src1;
    m_src2  = rhs.m_src2;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // ZeroBranchImmedInstruction
  //---------------------------------------------

  bool
  ZeroBranchImmedInstruction::isBranchInsn() const
  {
    return true;
  }
  
  bool
  ZeroBranchImmedInstruction::isValidDslotInsn() const
  {
    return false;
  }
  
  bool
  ZeroBranchImmedInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return true;
      }
    else
      {
	return false;
      }
  }


  bool
  ZeroBranchImmedInstruction::hasReturnReg() const
  {
    if(! getCmpReg()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getCmpReg());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  OctaveInstruction::BranchProbability 
  ZeroBranchImmedInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  RegPtr
  ZeroBranchImmedInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  ZeroBranchImmedInstruction::getSrc2() const
  {
    return m_src2;
  }

  OpndPtr
  ZeroBranchImmedInstruction::getCmpReg() const
  {
    return m_cmpReg;
  }
  
  ZeroBranchImmedInstruction& 
  ZeroBranchImmedInstruction::operator=(const ZeroBranchImmedInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1  = rhs.m_src1;
    m_src2  = rhs.m_src2;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // TestBitBranchInstruction
  //---------------------------------------------

  bool 
  TestBitBranchInstruction::isPseudoInsn() const
  {
    return false;
  }

  bool
  TestBitBranchInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  TestBitBranchInstruction::isValidDslotInsn() const
  {
    return false;
  }

  OctaveInstruction::BranchProbability 
  TestBitBranchInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  unsigned int 
  TestBitBranchInstruction::getNumDelaySlots() const
  {
    return 3;
  }

  
  RegPtr
  TestBitBranchInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  UImmPtr
  TestBitBranchInstruction::getBitpos() const
  {
    return m_bitpos;
  }
   
  OpndPtr
  TestBitBranchInstruction::getDisp() const
  {
    return m_disp;
  }
  
  TestBitBranchInstruction& 
  TestBitBranchInstruction::operator=(const TestBitBranchInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_bitpos = rhs.m_bitpos;
    m_disp   = rhs.m_disp;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // ReturnOpInstruction
  //---------------------------------------------

  bool 
  ReturnOpInstruction::isReturnInsn() const
  {
    return true;
  }

  bool
  ReturnOpInstruction::isBranchInsn() const
  {
    return true;
  }
  
  bool
  ReturnOpInstruction::isValidDslotInsn() const
  {
    return false;
  }
  
  OpndPtr
  ReturnOpInstruction::getDiFlag() const
  {
    return m_diFlag;
  }
  
  ReturnOpInstruction& 
  ReturnOpInstruction::operator=(const ReturnOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_diFlag = rhs.m_diFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // CompareOpInstruction
  //---------------------------------------------

  OctaveInstruction::BranchProbability 
  CompareOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  RegPtr
  CompareOpInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  CompareOpInstruction::getSrc2() const
  {
    return m_src2;
  }
  
  OpndPtr
  CompareOpInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  CompareOpInstruction& 
  CompareOpInstruction::operator=(const CompareOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src1    = rhs.m_src1;
    m_src2    = rhs.m_src2;
    m_abcFlag = rhs.m_abcFlag;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // CompareOpBranchInstruction
  //---------------------------------------------


  bool  
  CompareOpBranchInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  CompareOpBranchInstruction::getNumDelaySlots() const
  {
    if(hasValidAbcFlag())
      {
        return 3;
      }
    else
      {
        return 0;
      }
  }

  bool
  CompareOpBranchInstruction::isAbcInsn() const
  {
    if(hasValidAbcFlag())
      {
        return true;
      }
    else
      {
        return false;
      }
  }

  bool
  CompareOpBranchInstruction::isBranchInsn() const
  {
    if(hasValidAbcFlag())
      {
        return true;
      }
    else
      {
        return false;
      }
  }

  bool
  CompareOpBranchInstruction::isValidDslotInsn() const
  {
    if(hasValidAbcFlag())
      {
        return false;
      }
    else
      {
        return true;
      }
  }

  OctaveInstruction::BranchProbability 
  CompareOpBranchInstruction::getBranchProbability() const
  {
    return m_probability;
  }

  bool
  CompareOpBranchInstruction::hasValidAbcFlag() const
  {
    shared_ptr<const LlirOperand> opnd = getAbcFlag();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
        return false;
      }
    else
      {
        return true;
      }
  }


  
  OpndPtr
  CompareOpBranchInstruction::getBranchTarget() const
  {
    return m_branchTarget;
  }
  
  CompareOpBranchInstruction& 
  CompareOpBranchInstruction::operator=(const CompareOpBranchInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpInstruction::operator=(rhs);
    m_branchTarget = rhs.m_branchTarget;
    return *this;
    
  }
  
  
  //---------------------------------------------
  // CompareOpSignInstruction
  //---------------------------------------------

  bool  
  CompareOpSignInstruction::isPseudoInsn() const
  {
    return false;
  }

  //cmpr/cmpri are not branch insns and
  //do not have delay slots....


  unsigned int
  CompareOpSignInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  CompareOpSignInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  CompareOpSignInstruction::isValidDslotInsn() const
  {
    return true;
  }

  RegPtr
  CompareOpSignInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  CompareOpSignInstruction::getSign() const
  {
    return m_sign;
  }
  
  CompareOpSignInstruction& 
  CompareOpSignInstruction::operator=(const CompareOpSignInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpInstruction::operator=(rhs);
    m_dst  = rhs.m_dst;
    m_sign = rhs.m_sign;
    return *this;
    
  }
  

  
  //---------------------------------------------
  // TssOpInstruction
  //---------------------------------------------

  bool 
  TssOpInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  TssOpInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  TssOpInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  TssOpInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  TssOpInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  OpndPtr
  TssOpInstruction::getTssFlags() const
  {
    return m_flags;
  }
  
  TssOpInstruction&
  TssOpInstruction::operator=(const TssOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_flags = rhs.m_flags; 
    return *this;
    
  }
  
  
  //---------------------------------------------
  // TssRcOpInstruction
  //---------------------------------------------
  
  RegPtr
  TssRcOpInstruction::getRsa() const
  {
    return m_rsa;
  }
  
  TssRcOpInstruction&
  TssRcOpInstruction::operator=(const TssRcOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssOpInstruction::operator=(rhs);
    m_rsa = rhs.m_rsa; 
    return *this;
    
  }
    
  //---------------------------------------------
  // TssNoRcOpInstruction
  //---------------------------------------------

  UImmPtr
  TssNoRcOpInstruction::getParOffset() const
  {
    return m_parOffset;
  }
  
  UImmPtr
  TssNoRcOpInstruction::getPosOffset() const
  {
    return m_posOffset;
  }
  
  TssNoRcOpInstruction&
  TssNoRcOpInstruction::operator=(const TssNoRcOpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssOpInstruction::operator=(rhs);
    m_parOffset = rhs.m_parOffset; 
    m_posOffset = rhs.m_posOffset; 
    return *this;
    
  }


  
  //---------------------------------------------
  //---------------------------------------------

} // end of namespace Llir

