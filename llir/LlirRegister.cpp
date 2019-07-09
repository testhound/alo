#include <typeinfo>
#include <cassert>
#include <iostream>
using namespace std;

#include "LlirVisitor.h"
#include "LlirOperand.h"
#include "LlirException.h"

namespace Llir
{

  bool
  isPseudoReg(shared_ptr<const Register> reg)
  {
    shared_ptr<const PseudoRegister> pr;

    if ((pr = shared_dynamic_cast<const PseudoRegister>(reg)))
      return true;
    else
      return false;
  }

  bool
  isMultiReg(shared_ptr<const Register> reg)
  {
    shared_ptr<const MultiRegister> mr;

    if (( mr = shared_dynamic_cast<const MultiRegister>(reg)))
      return true;
    else
      return false;
  }
  
  bool
  isNullReg(shared_ptr<const Register> reg)
  {
    NullRegister temp;
    
    if (*reg == temp)
      return true;
    else
      return false;
  }

  // Register class
  std::string m_emptyRegName("");

  Register::Register() : LlirOperand()
  {}

  Register::Register(const Register &rhs) : LlirOperand(rhs)
  {}

  Register &
  Register::operator=(const Register &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirOperand::operator=(rhs);
    return *this;
  }


  // SingleRegister

  SingleRegister::SingleRegister(unsigned int regNum) : Register(), m_regNum(regNum)
  {}

  SingleRegister::SingleRegister(const SingleRegister &rhs) : Register(rhs), m_regNum(rhs.m_regNum)
  {}

  SingleRegister &
  SingleRegister::operator=(const SingleRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    Register::operator=(rhs);
    m_regNum = rhs.m_regNum;
    return *this;
  }

  unsigned int
  SingleRegister::getNumRegs() const
  {
    return 1;
  };

  unsigned int
  SingleRegister::getRegNum(unsigned int regIndex) const
  {
    if (regIndex > 0)
	throw LLIR_INTERNAL_EXCEPTION("Reg Index cannot be > 0");

    return m_regNum;
  }


  // HardRegister

  HardRegister::HardRegister(unsigned int regNum) : SingleRegister(regNum)
  {}

  HardRegister::HardRegister(const HardRegister &rhs) : SingleRegister(rhs)
  {}

  HardRegister &
  HardRegister::operator=(const HardRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    SingleRegister::operator=(rhs);
    return *this;
  }

  void
  HardRegister::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("HardRegister::accept - Visit error");
    }       
  }


  bool
  HardRegister::equalTo(const LlirOperand &rhs) const
  {
    return (getRegNum() == (dynamic_cast<const HardRegister &> (rhs)).getRegNum());
  }


  shared_ptr<const Register>
  HardRegister::getRegister(unsigned int regNum) const
  {
    if (regNum > 0)
	throw LLIR_INTERNAL_EXCEPTION("Register cannot be > 0");

    shared_ptr<const Register> hReg (new HardRegister(getRegNum()));

    return hReg;
  }


  const std::string &
  HardRegister::getRegName() const
  {
    throw LLIR_INTERNAL_EXCEPTION("HardRegister has no name");

    return m_emptyRegName;
  }


  // NullRegister

  NullRegister::NullRegister() : Register()
  {}

  NullRegister::NullRegister(const NullRegister &rhs) : Register(rhs)
  {}

  NullRegister &
  NullRegister::operator=(const NullRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    Register::operator=(rhs);
    return *this;
  }

  void
  NullRegister::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("NullRegister::accept - Visit error");
    }       
  }

  bool
  NullRegister::equalTo(const LlirOperand &rhs) const
  {
    return (getRegNum() == (dynamic_cast<const NullRegister &> (rhs)).getRegNum());
  }

  const std::string &
  NullRegister::getRegName() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullRegister has no name");

    return m_emptyRegName;
  }

  unsigned int
  NullRegister::getNumRegs() const
  {
    return 0;
  };

  unsigned int
  NullRegister::getRegNum(unsigned int regIndex) const
  {
    return 0;
  }


  shared_ptr<const Register>
  NullRegister::getRegister(unsigned int regNum) const
  {
    throw LLIR_INTERNAL_EXCEPTION("Register cannot be > 0");

    return shared_ptr<const Register>(this);
  }


  // Pseudo Register

  PseudoRegister::PseudoRegister(unsigned int regNum, const char *name) 
    : SingleRegister(regNum), m_pseudoRegName(name)
  {}

  PseudoRegister::PseudoRegister(const PseudoRegister &rhs) 
    : SingleRegister(rhs), m_pseudoRegName(rhs.m_pseudoRegName)
  {}

  PseudoRegister &
  PseudoRegister::operator=(const PseudoRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    SingleRegister::operator=(rhs);
    m_pseudoRegName = rhs.m_pseudoRegName;
    return *this;
  }

  shared_ptr<const Register>
  PseudoRegister::getRegister(unsigned int regNum) const
  {
    if (regNum > 0)
	throw LLIR_INTERNAL_EXCEPTION("Register cannot be > 0");

    shared_ptr<const Register> pReg (new PseudoRegister(getRegNum(), getRegName().c_str()));

    return pReg;
  }


  const std::string&
  PseudoRegister::getRegName() const
  {
    return m_pseudoRegName;
  }

  void
  PseudoRegister::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("PseudoRegister::accept - Visit error");
    }       
  }


  bool
  PseudoRegister::equalTo(const LlirOperand &rhs) const
  {
    PseudoRegister temp = dynamic_cast<const PseudoRegister &> (rhs);

    return ((getRegNum() == temp.getRegNum()) && 
	    (m_pseudoRegName == temp.m_pseudoRegName));
  }

  // MultiRegister

  MultiRegister::MultiRegister(unsigned int numRegs, unsigned int firstRegNum) : 
    Register(), m_numRegs(numRegs), m_firstRegNum(firstRegNum)
  {}

  MultiRegister::MultiRegister(const MultiRegister &rhs) : Register(rhs),
							   m_numRegs(rhs.m_numRegs),
							   m_firstRegNum(rhs.m_firstRegNum)
  {}

  MultiRegister &
  MultiRegister::operator=(const MultiRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    Register::operator=(rhs);
    m_numRegs = rhs.m_numRegs;
    m_firstRegNum = rhs.m_firstRegNum;
    return *this;
  }

  unsigned int
  MultiRegister::getNumRegs() const
  {
    return m_numRegs;
  };

  unsigned int
  MultiRegister::getFirstRegNum() const
  {
    return m_firstRegNum;
  };

  // MultiHardRegister

  MultiHardRegister::MultiHardRegister(unsigned int numRegs, unsigned int firstRegNum) : 
    MultiRegister(numRegs,firstRegNum)
  {
    m_multiHardRegs.reserve(numRegs);
  }

  MultiHardRegister::MultiHardRegister(const MultiHardRegister &rhs) : 
    MultiRegister(rhs), m_multiHardRegs(rhs.m_multiHardRegs)
  {}

  void
  MultiHardRegister::addRegister(HardRegisterPtr reg)
  {
    if (reg->getRegNum() < getFirstRegNum())
      throw LLIR_INTERNAL_EXCEPTION("Register out of range");

    if (m_multiHardRegs.size() >= getNumRegs())
      throw LLIR_INTERNAL_EXCEPTION("Register out of range");

    m_multiHardRegs.push_back(reg);
  }

  MultiHardRegister &
  MultiHardRegister::operator=(const MultiHardRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    MultiRegister::operator=(rhs);
    m_multiHardRegs = rhs.m_multiHardRegs;
    return *this;
  }

  MultiHardRegister::Iterator
  MultiHardRegister::begin()
  {
    return m_multiHardRegs.begin();
  }

  MultiHardRegister::Iterator
  MultiHardRegister::end()
  {
    return m_multiHardRegs.end();
  }


  MultiHardRegister::ConstIterator
  MultiHardRegister::begin() const
  {
    return m_multiHardRegs.begin();
  }

  MultiHardRegister::ConstIterator
  MultiHardRegister::end() const
  {
    return m_multiHardRegs.end();
  }


  shared_ptr<const Register> 
  MultiHardRegister::getRegister(unsigned int regNum) const
  {
    if (regNum < getNumRegs())
      {
	return m_multiHardRegs[regNum];
      }
    else
      throw LLIR_INTERNAL_EXCEPTION("Register index out of range");
  }

  unsigned int
  MultiHardRegister::getRegNum(unsigned int regNum) const
  {
    if (regNum < getNumRegs())
      return (m_multiHardRegs[regNum])->getRegNum();
    else
      throw LLIR_INTERNAL_EXCEPTION("Register index out of range");
  }

  const std::string&
  MultiHardRegister::getRegName() const
  {
    throw LLIR_INTERNAL_EXCEPTION("Register has no name");

    return m_emptyRegName;
  }

  bool
  MultiHardRegister::equalTo(const LlirOperand &rhs) const
  {
    const MultiHardRegister rhsMultiReg = (dynamic_cast<const MultiHardRegister &> (rhs));

    if (this->getNumRegs() != rhsMultiReg.getNumRegs())
      return false;

    if (this->getFirstRegNum() != rhsMultiReg.getFirstRegNum())
      return false;

    MultiHardRegister::ConstIterator thisIterator = this->begin();
    MultiHardRegister::ConstIterator rhsIterator = rhsMultiReg.begin();

    for (; thisIterator != m_multiHardRegs.end(); thisIterator++, rhsIterator++)
      {
	if (*(*thisIterator) != *(*rhsIterator))
	  return false;
      }

    return true;
  }

  void
  MultiHardRegister::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v)) 
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("Visit error");
    }       
  }


  ////// MultiPseudoRegister 



  MultiPseudoRegister::MultiPseudoRegister(const char *name, unsigned int numRegs, 
					   unsigned int firstRegNum) : 
    MultiRegister(numRegs, firstRegNum), m_pseudoName(name)
  {
    m_multiPseudoRegs.reserve(numRegs);
  }

  MultiPseudoRegister::MultiPseudoRegister(const MultiPseudoRegister &rhs) : 
    MultiRegister(rhs), m_multiPseudoRegs(rhs.m_multiPseudoRegs), m_pseudoName(rhs.m_pseudoName)
  {}

  MultiPseudoRegister &
  MultiPseudoRegister::operator=(const MultiPseudoRegister &rhs)
  {
    if (this == &rhs)
      return *this;

    MultiRegister::operator=(rhs);
    m_multiPseudoRegs = rhs.m_multiPseudoRegs;
    m_pseudoName = rhs.m_pseudoName;
    return *this;
  }

  void
  MultiPseudoRegister::addRegister(PseudoRegisterPtr reg)
  {
    if (reg->getRegNum() < getFirstRegNum())
      throw LLIR_INTERNAL_EXCEPTION("Register out of range");

    if (m_multiPseudoRegs.size() >= getNumRegs())
      throw LLIR_INTERNAL_EXCEPTION("Register out of range");

    m_multiPseudoRegs.push_back(reg);
  }

  MultiPseudoRegister::Iterator
  MultiPseudoRegister::begin()
  {
    return m_multiPseudoRegs.begin();
  }

  MultiPseudoRegister::Iterator
  MultiPseudoRegister::end()
  {
    return m_multiPseudoRegs.end();
  }


  MultiPseudoRegister::ConstIterator
  MultiPseudoRegister::begin() const
  {
    return m_multiPseudoRegs.begin();
  }

  MultiPseudoRegister::ConstIterator
  MultiPseudoRegister::end() const
  {
    return m_multiPseudoRegs.end();
  }


  shared_ptr<const Register> 
  MultiPseudoRegister::getRegister(unsigned int regNum) const
  {
    if (regNum < getNumRegs())
      return m_multiPseudoRegs[regNum];
    else
      throw LLIR_INTERNAL_EXCEPTION("Register index out of range");
  }

  unsigned int
  MultiPseudoRegister::getRegNum(unsigned int regNum) const
  {
    if (regNum < getNumRegs())
      return (m_multiPseudoRegs[regNum])->getRegNum();
    else
      throw LLIR_INTERNAL_EXCEPTION("Register index out of range");
  }

  const std::string&
  MultiPseudoRegister::getRegName() const
  {
    return m_pseudoName;
  }

  bool
  MultiPseudoRegister::equalTo(const LlirOperand &rhs) const
  {
    const MultiPseudoRegister rhsMultiReg = (dynamic_cast<const MultiPseudoRegister &> (rhs));

    if (this->getNumRegs() != rhsMultiReg.getNumRegs())
      return false;

    if (this->getFirstRegNum() != rhsMultiReg.getFirstRegNum())
      return false;

    if (getRegName() != rhsMultiReg.getRegName())
      return false;

    MultiPseudoRegister::ConstIterator thisIterator = this->begin();
    MultiPseudoRegister::ConstIterator rhsIterator = rhsMultiReg.begin();

    for (; thisIterator != m_multiPseudoRegs.end(); thisIterator++, rhsIterator++)
      {
	if (*(*thisIterator) != *(*rhsIterator))
	  return false;
      }

    return true;
  }

  void
  MultiPseudoRegister::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v)) 
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("Visit error");
    }       
  }


} // namespace Llir
