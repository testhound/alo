#include <typeinfo>
#include <cassert>
#include <iostream>
using namespace std;

#include <LlirVisitor.h>
#include <LlirException.h>

#include "OctaveOperand.h"
#include "OctaveVisitor.h"


namespace Llir
{
  // OctaveMemory

  OctaveMemory::OctaveMemory(shared_ptr<const LlirOperand> offset) : 
    OpndMemory(), m_offset(offset)
  {}
    
  OctaveMemory::OctaveMemory(const OctaveMemory &rhs) : 
    OpndMemory(rhs), m_offset(rhs.m_offset)
  {}

  OctaveMemory &
  OctaveMemory::operator=(const OctaveMemory &rhs)
  {
    if (this == &rhs)
      return *this;

    OpndMemory::operator=(rhs);
    m_offset = rhs.m_offset;
    return *this;
  }

  shared_ptr<const LlirOperand>
  OctaveMemory::getOffset() const
  {
    return m_offset;
  }



  // BasePlusOffset

  BasePlusOffset::BasePlusOffset(shared_ptr<const LlirOperand> offset) : 
    OctaveMemory(offset)
  {}
    
  BasePlusOffset::BasePlusOffset(const BasePlusOffset &rhs) : OctaveMemory(rhs)
  {}

  BasePlusOffset &
  BasePlusOffset::operator=(const BasePlusOffset &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveMemory::operator=(rhs);
    return *this;
  }

  // Base2PlusOffset

  Base2PlusOffset::Base2PlusOffset(shared_ptr<const LlirOperand> offset) : 
    BasePlusOffset(offset)
  {}
    
  Base2PlusOffset::Base2PlusOffset(const Base2PlusOffset &rhs) : BasePlusOffset(rhs)
  {}

  Base2PlusOffset &
  Base2PlusOffset::operator=(const Base2PlusOffset &rhs)
  {
    if (this == &rhs)
      return *this;

    BasePlusOffset::operator=(rhs);
    return *this;
  }

  void
  Base2PlusOffset::accept(Visitor &v) const
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
  Base2PlusOffset::equalTo(const LlirOperand &rhs) const
  {
    const Base2PlusOffset &temp = dynamic_cast<const Base2PlusOffset &> (rhs);
    
    return (getOffset() == temp.getOffset());
  }

  // Base3PlusOffset

  Base3PlusOffset::Base3PlusOffset(shared_ptr<const LlirOperand> offset) : 
    BasePlusOffset(offset)
  {}
    
  Base3PlusOffset::Base3PlusOffset(const Base3PlusOffset &rhs) : BasePlusOffset(rhs)
  {}

  Base3PlusOffset &
  Base3PlusOffset::operator=(const Base3PlusOffset &rhs)
  {
    if (this == &rhs)
      return *this;

    BasePlusOffset::operator=(rhs);
    return *this;
  }

  void
  Base3PlusOffset::accept(Visitor &v) const
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
  Base3PlusOffset::equalTo(const LlirOperand &rhs) const
  {
    const Base3PlusOffset &temp = dynamic_cast<const Base3PlusOffset &> (rhs);
    
    return (getOffset() == temp.getOffset());
  }


  // RegPlusOffsetIndirect

  RegPlusOffsetIndirect::RegPlusOffsetIndirect(shared_ptr<const Register> baseReg, shared_ptr<const LlirOperand> offset) : 
    OctaveMemory(offset), m_baseRegister(baseReg)
  {}
    
  RegPlusOffsetIndirect::RegPlusOffsetIndirect(const RegPlusOffsetIndirect &rhs) : 
    OctaveMemory(rhs), m_baseRegister(rhs.m_baseRegister)
  {}

  RegPlusOffsetIndirect &
  RegPlusOffsetIndirect::operator=(const RegPlusOffsetIndirect &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveMemory::operator=(rhs);
    m_baseRegister = rhs.m_baseRegister;
    return *this;
  }

  shared_ptr<const Register>
  RegPlusOffsetIndirect::getBaseRegister() const
  {
    return m_baseRegister;
  }

  bool
  RegPlusOffsetIndirect::equalTo(const LlirOperand &rhs) const
  {
    const RegPlusOffsetIndirect &temp = dynamic_cast<const RegPlusOffsetIndirect &> (rhs);
    
    return ((getOffset() == temp.getOffset()) &&
	    (*(getBaseRegister()) == *(temp.getBaseRegister())));
  }

  void
  RegPlusOffsetIndirect::accept(Visitor &v) const
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


  // ImpliedBase2Offset

  ImpliedBase2Offset::ImpliedBase2Offset(shared_ptr<const LlirOperand> offset) : 
    OctaveMemory(offset)
  {}
    
  ImpliedBase2Offset::ImpliedBase2Offset(const ImpliedBase2Offset &rhs) : 
    OctaveMemory(rhs)
  {}

  ImpliedBase2Offset &
  ImpliedBase2Offset::operator=(const ImpliedBase2Offset &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveMemory::operator=(rhs);
    return *this;
  }

  bool
  ImpliedBase2Offset::equalTo(const LlirOperand &rhs) const
  {
    const ImpliedBase2Offset &temp = dynamic_cast<const ImpliedBase2Offset &> (rhs);
    
    return ((getOffset() == temp.getOffset()));
  }

  void
  ImpliedBase2Offset::accept(Visitor &v) const
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

  // OctaveUnaryExpr

  OctaveUnaryExpr::OctaveUnaryExpr(shared_ptr<const LlirOperand> op) : 
    UnaryExpr(op)
  {}

  OctaveUnaryExpr::OctaveUnaryExpr(const OctaveUnaryExpr &rhs) : 
    UnaryExpr(rhs)
  {}

  OctaveUnaryExpr &
  OctaveUnaryExpr::operator=(const OctaveUnaryExpr &rhs)
  {
    if (this == &rhs)
      return *this;

    UnaryExpr::operator=(rhs);
    return *this;
  }


  // Lo17Op
  Lo17Op::Lo17Op(shared_ptr<const LlirOperand> op) : 
    OctaveUnaryExpr(op)
  {}

  Lo17Op::Lo17Op(const Lo17Op &rhs) : 
    OctaveUnaryExpr(rhs)
  {}

  Lo17Op &
  Lo17Op::operator=(const Lo17Op &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveUnaryExpr::operator=(rhs);
    return *this;
  }

  void
  Lo17Op::accept(Visitor &v) const
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
  Lo17Op::equalTo(const LlirOperand &rhs) const
  {
    const Lo17Op temp = dynamic_cast<const Lo17Op &> (rhs);
    
    return (*(getOpnd()) == *(temp.getOpnd()));
  }


  // Hi16Op
  Hi16Op::Hi16Op(shared_ptr<const LlirOperand> op) : 
    OctaveUnaryExpr(op)
  {}

  Hi16Op::Hi16Op(const Hi16Op &rhs) : 
    OctaveUnaryExpr(rhs)
  {}

  Hi16Op &
  Hi16Op::operator=(const Hi16Op &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveUnaryExpr::operator=(rhs);
    return *this;
  }

  void
  Hi16Op::accept(Visitor &v) const
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
  Hi16Op::equalTo(const LlirOperand &rhs) const
  {
    const Hi16Op temp = dynamic_cast<const Hi16Op &> (rhs);
    
    return (*(getOpnd()) == *(temp.getOpnd()));
  }

  // Lo16Op
  Lo16Op::Lo16Op(shared_ptr<const LlirOperand> op) : 
    OctaveUnaryExpr(op)
  {}

  Lo16Op::Lo16Op(const Lo16Op &rhs) : 
    OctaveUnaryExpr(rhs)
  {}

  Lo16Op &
  Lo16Op::operator=(const Lo16Op &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveUnaryExpr::operator=(rhs);
    return *this;
  }

  void
  Lo16Op::accept(Visitor &v) const
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
  Lo16Op::equalTo(const LlirOperand &rhs) const
  {
    const Lo16Op temp = dynamic_cast<const Lo16Op &> (rhs);
    
    return (*(getOpnd()) == *(temp.getOpnd()));
  }


  // WordOp
  WordOp::WordOp(shared_ptr<const LlirOperand> op) : 
    OctaveUnaryExpr(op)
  {}

  WordOp::WordOp(const WordOp &rhs) : 
    OctaveUnaryExpr(rhs)
  {}

  WordOp &
  WordOp::operator=(const WordOp &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveUnaryExpr::operator=(rhs);
    return *this;
  }

  void
  WordOp::accept(Visitor &v) const
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
  WordOp::equalTo(const LlirOperand &rhs) const
  {
    const WordOp temp = dynamic_cast<const WordOp &> (rhs);
    
    return (*(getOpnd()) == *(temp.getOpnd()));
  }




  //--------------------------
  // LabelList
  //--------------------------



  bool 
  operator==(const LabelList &lhs, const LabelList &rhs)
  {
    return lhs.equalTo(rhs);
  }

  bool 
  operator!=(const LabelList &lhs, const LabelList &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }



  LabelList::LabelList()
  {}

  LabelList::~LabelList()
  {}

  LabelList::LabelList(const LabelList& rhs)
    : m_labelList(rhs.m_labelList)
  {}

  LabelList& 
  LabelList::operator=(const LabelList& rhs)
  {
    if(this == &rhs)
      return *this;

    m_labelList = rhs.m_labelList;
    return *this;
  }

  bool 
  LabelList::isInList(shared_ptr<const OpndLabel> label) const
  {
    std::list<shared_ptr<const OpndLabel> >::const_iterator iter = m_labelList.begin();

    for(; iter != m_labelList.end(); iter++)
      {
	if(*label == **iter)
	  return true;
      }

    return false;
  }


  bool 
  LabelList::isInList(const char* name) const
  {
    std::list<shared_ptr<const OpndLabel> >::const_iterator iter = m_labelList.begin();

    for(; iter != m_labelList.end(); iter++)
      {
	if((*iter)->getName() == name)
	  return true;
      }

    return false;
  }


  void 
  LabelList::addLabel(shared_ptr<const OpndLabel> label)
  {
    const char* name = label->getName().c_str();

    if(! isInList(name))
      m_labelList.push_back(label);
    else
       throw LLIR_DIRECTIVE_EXCEPTION("LabelList::addLabel : label with same name already exists");
       
  }

  unsigned int
  LabelList::getNumLabels() const
  {
    return m_labelList.size();
  }

  LabelList::Iterator
  LabelList::begin()
  {
    return m_labelList.begin();
  }
  
  LabelList::Iterator
  LabelList::end()
  {
    return m_labelList.end();
  }


  LabelList::ConstIterator
  LabelList::begin() const
  {
    return m_labelList.begin();
  }
  
  LabelList::ConstIterator
  LabelList::end() const
  {
    return m_labelList.end();
  }

  bool
  LabelList::equalTo(const LabelList &rhs) const
  {
    return ((m_labelList == rhs.m_labelList));
  }

  void 
  LabelList::accept(Visitor &v) const
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

  shared_ptr<const OpndLabel> 
  LabelList::getLabel(unsigned int index) const
  {
    
    if( ! m_labelList.empty()  && index <= m_labelList.size())
      {
	LabelList::ConstIterator iter = m_labelList.begin();

	for(unsigned int i=0; i < index; i++)
	  ++iter;

	if(iter != m_labelList.end())
	  return *iter;
      }
    
    throw LLIR_INTERNAL_EXCEPTION("index into label list out of range");
    
    //to suppress compiler warning...
    return shared_ptr<const OpndLabel>(new OpndLabel("invalid label"));

  }

  void
  LabelList::reverse()
  {
    m_labelList.reverse();
  }

  //--------------------------
  // RegList
  //--------------------------


  bool 
  operator==(const RegList &lhs, const RegList &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const RegList &lhs, const RegList &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }

  bool
  RegList::equal(const RegList &rhs) const
  {
    bool equal = false;

    if(typeid(*this) == typeid(rhs))
      {
	RegList::ConstIterator iter = rhs.begin();
	RegList::ConstIterator iter1 = this->begin();
	
	for(; iter != rhs.end(), iter1 != this->end(); iter++, iter1++)
	  {
	    if(*iter->second == *iter1->second)
	      continue;
	    else
	      {
		equal = false;
		break;
	      }
	  }

	if(iter == rhs.end() && 
	   iter1 == this->end())
	  {
	    equal = true;
	  }
      }
    else
      {
	equal = false;
      }

    return equal;
  }

  RegList::RegList()
  {}

  RegList::~RegList()
  {}

  RegList::RegList(const RegList& rhs)
    : m_regList(rhs.m_regList)
  {}

  RegList&
  RegList::operator=(const RegList& rhs)
  {
    if(this == &rhs)
      return *this;

    m_regList = rhs.m_regList;
    return *this;
  }

  bool
  RegList::isInList(unsigned int regNum) const
  {
    if(m_regList.find(regNum) == m_regList.end())
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  bool
  RegList::isEmpty() const
  {
    return m_regList.empty();
  }

  void
  RegList::addRegister(shared_ptr<const Register> reg)
  {
    //if single hard register...
    shared_ptr<const HardRegister> hreg = 
      shared_dynamic_cast<const HardRegister>(reg);

    shared_ptr<const MultiHardRegister> mhreg = 
      shared_dynamic_cast<const MultiHardRegister>(reg);

    if(reg->getRegNum() > 63)
      throw LLIR_DIRECTIVE_EXCEPTION("pseudo registers(reg > r63) cannot be specified in the list");

    if(reg->getNumRegs() > 64)
      throw LLIR_DIRECTIVE_EXCEPTION("register list size out of range > 63");

    if(reg->getRegNum() + reg->getNumRegs() > 64)
      throw LLIR_DIRECTIVE_EXCEPTION("register list size out of range > 63");

    if(hreg || mhreg)
      {
	if(isInList(reg->getRegNum()))
	  throw LLIR_DIRECTIVE_EXCEPTION("duplicate register found in the register list");
      }

    if(hreg)
      {
	unsigned int regNum = hreg->getRegNum();

	if(m_regList.find(regNum) == m_regList.end())
	  {
	    m_regList[regNum] = hreg;
	  }
	else
	  {
	    throw LLIR_DIRECTIVE_EXCEPTION("duplicate register found in the register list");
	  }

	return;
      }
    else if(mhreg)
      {
	unsigned int numRegs = mhreg->getNumRegs();
	
	//seperate out the hard registers and store them..
	//for easy retrieval at a later stage...

	for(unsigned int i = 0; i < numRegs; i++)
	  {
	    unsigned int regNum = mhreg->getRegNum(i);

	    if(m_regList.find(regNum) == m_regList.end())
	      {
		m_regList[regNum] = mhreg->getRegister(i);
	      }
	    else
	      {
		throw LLIR_DIRECTIVE_EXCEPTION("duplicate register found in the register list");
	      }
	  }

	return;
      }
    else
      {
	throw LLIR_DIRECTIVE_EXCEPTION("unknown register being added register list");
	return;
      }
  }
  


  shared_ptr<const Register> 
  RegList::getRegister(unsigned int regNum) const
  {
    RegList::ConstIterator iter = m_regList.find(regNum);

    if(iter != m_regList.end())
      {
	return iter->second;
      }
    else
      {
	return shared_ptr<const Register>(new NullRegister());
      }
  }

  RegList::Iterator
  RegList::begin()
  {
    return m_regList.begin();
  }

  RegList::Iterator
  RegList::end()
  {
    return m_regList.end();
  }


  RegList::ConstIterator
  RegList::begin() const
  {
    return m_regList.begin();
  }

  RegList::ConstIterator
  RegList::end() const
  {
    return m_regList.end();
  }


  //////////////////////
  // RegisterList
  //////////////////////


  bool 
  operator==(const RegisterList &lhs, const RegisterList &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const RegisterList &lhs, const RegisterList &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }


  RegisterList::RegisterList(shared_ptr<RegList> regList)
    : m_regList(regList)
  {}

  RegisterList::~RegisterList()
  {}

  RegisterList::RegisterList(const RegisterList& rhs)
    : m_regList(rhs.m_regList)
  {}

  RegisterList& 
  RegisterList::operator=(const RegisterList& rhs)
  {
    if(this == &rhs)
      return *this;
    
    m_regList = rhs.m_regList;
    return *this;
  }


  shared_ptr<const RegList>
  RegisterList::getRegList() const
  {
    return m_regList;
  }

  bool
  RegisterList::isEmpty() const
  {
    for(unsigned int reg=0; reg <=63; reg++)
      {
	//if atleast one register is present 
	//return false
	if(m_regList->isInList(reg))
	  return false;
      }

    return true;
  }

  bool
  RegisterList::isInList(unsigned int regNum) const
  {
    return m_regList->isInList(regNum);
  }

  bool
  RegisterList::equal(const RegisterList &rhs) const
  {
    if(typeid(*this) == typeid(rhs))
      return rhs.equalTo(*this);
    else
      return false;
  }

  //////////////////////
  // GlobalRegisterList
  //////////////////////

  GlobalRegisterList::GlobalRegisterList(shared_ptr<RegList> regList)
    : RegisterList(regList)
  {}

  GlobalRegisterList::~GlobalRegisterList()
  {}

  GlobalRegisterList::GlobalRegisterList(const GlobalRegisterList& rhs)
    : RegisterList(rhs)
  {}

  GlobalRegisterList& 
  GlobalRegisterList::operator=(const GlobalRegisterList& rhs)
  {
    if(this == &rhs)
      return *this;
    
    RegisterList::operator=(rhs);
    return *this;
  }

  bool
  GlobalRegisterList::equalTo(const RegisterList &rhs) const
  {
    return (*getRegList() == *rhs.getRegList());
  }

  void 
  GlobalRegisterList::accept(Visitor &v) const
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



  //////////////////////
  // ArgList
  //////////////////////

  ArgList::ArgList(shared_ptr<RegList> regList)
    : RegisterList(regList)
  {}

  ArgList::~ArgList()
  {}

  ArgList::ArgList(const ArgList& rhs)
    : RegisterList(rhs)
  {}

  ArgList& 
  ArgList::operator=(const ArgList& rhs)
  {
    if(this == &rhs)
      return *this;
    
    RegisterList::operator=(rhs);
    return *this;
  }

  bool
  ArgList::equalTo(const RegisterList &rhs) const
  {
    return (*getRegList() == *rhs.getRegList());
  }

  void 
  ArgList::accept(Visitor &v) const
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



  //////////////////////
  // ScratchList
  //////////////////////

  ScratchList::ScratchList(shared_ptr<RegList> regList)
    : RegisterList(regList)
  {}

  ScratchList::~ScratchList()
  {}

  ScratchList::ScratchList(const ScratchList& rhs)
    : RegisterList(rhs)
  {}

  ScratchList& 
  ScratchList::operator=(const ScratchList& rhs)
  {
    if(this == &rhs)
      return *this;
    
    RegisterList::operator=(rhs);
    return *this;
  }

  bool
  ScratchList::equalTo(const RegisterList &rhs) const
  {
    return (*getRegList() == *rhs.getRegList());
  }

  void 
  ScratchList::accept(Visitor &v) const
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


  //////////////////////
  // ResultList
  //////////////////////

  ResultList::ResultList(shared_ptr<RegList> regList)
    : RegisterList(regList)
  {}

  ResultList::~ResultList()
  {}

  ResultList::ResultList(const ResultList& rhs)
    : RegisterList(rhs)
  {}

  ResultList& 
  ResultList::operator=(const ResultList& rhs)
  {
    if(this == &rhs)
      return *this;
    
    RegisterList::operator=(rhs);
    return *this;
  }

  bool
  ResultList::equalTo(const RegisterList &rhs) const
  {
    return (*getRegList() == *rhs.getRegList());
  }

  void 
  ResultList::accept(Visitor &v) const
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


  //////////////////////
  // LinkedRegisterList
  //////////////////////


  bool 
  operator==(const LinkedRegisterList &lhs, const LinkedRegisterList &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const LinkedRegisterList &lhs, const LinkedRegisterList &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }


  LinkedRegisterList::LinkedRegisterList(shared_ptr<RegList> regListLnk1,
					 shared_ptr<RegList> regListLnk2,
					 shared_ptr<RegList> regListLnk3)
    : m_regList_lnk1(regListLnk1),
      m_regList_lnk2(regListLnk2),
      m_regList_lnk3(regListLnk3)
  {}

  LinkedRegisterList::~LinkedRegisterList()
  {}

  LinkedRegisterList::LinkedRegisterList(const LinkedRegisterList& rhs)
    : m_regList_lnk1(rhs.m_regList_lnk1),
      m_regList_lnk2(rhs.m_regList_lnk2),
      m_regList_lnk3(rhs.m_regList_lnk3)
  {}

  LinkedRegisterList& 
  LinkedRegisterList::operator=(const LinkedRegisterList& rhs)
  {
    if(this == &rhs)
      return *this;
    
    m_regList_lnk1 = rhs.m_regList_lnk1;
    m_regList_lnk2 = rhs.m_regList_lnk2;
    m_regList_lnk3 = rhs.m_regList_lnk3;
    return *this;
  }

  bool
  LinkedRegisterList::isInList(unsigned int regNum) const
  {
    return (m_regList_lnk1->isInList(regNum) ||
	    m_regList_lnk2->isInList(regNum) ||
	    m_regList_lnk3->isInList(regNum));
  }


  bool
  LinkedRegisterList::isEmpty() const
  {
    for(unsigned int reg=0; reg <=63; reg++)
      {
	//if atleast one register is present 
	//return false
	if(m_regList_lnk1->isInList(reg))
	  return false;
      }
    
    for(unsigned int reg=0; reg <=63; reg++)
      {
	//if atleast one register is present 
	//return false
	if(m_regList_lnk2->isInList(reg))
	  return false;
      }
   
    for(unsigned int reg=0; reg <=63; reg++)
      {
	//if atleast one register is present 
	//return false
	if(m_regList_lnk3->isInList(reg))
	  return false;
      }

    return true;
  }

  shared_ptr<const RegList>
  LinkedRegisterList::getRegListLnk1() const
  {
    return m_regList_lnk1;
  }

  shared_ptr<const RegList>
  LinkedRegisterList::getRegListLnk2() const
  {
    return m_regList_lnk2;
  }


  shared_ptr<const RegList>
  LinkedRegisterList::getRegListLnk3() const
  {
    return m_regList_lnk3;
  }


  bool
  LinkedRegisterList::equal(const LinkedRegisterList &rhs) const
  {
    if(typeid(*this) == typeid(rhs))
      return rhs.equalTo(*this);
    else
      return false;
  }

  //////////////////////
  // RegLnksListToSPRAM
  //////////////////////

  RegLnksListToSPRAM::RegLnksListToSPRAM(shared_ptr<RegList> regListLnk1,
					 shared_ptr<RegList> regListLnk2,
					 shared_ptr<RegList> regListLnk3)
    : LinkedRegisterList(regListLnk1, 
			 regListLnk2, 
			 regListLnk3)
  {}

  RegLnksListToSPRAM::~RegLnksListToSPRAM()
  {}

  RegLnksListToSPRAM::RegLnksListToSPRAM(const RegLnksListToSPRAM& rhs)
    : LinkedRegisterList(rhs)
  {}

  RegLnksListToSPRAM& 
  RegLnksListToSPRAM::operator=(const RegLnksListToSPRAM& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }

  void 
  RegLnksListToSPRAM::accept(Visitor &v) const
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
  RegLnksListToSPRAM::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }




  //////////////////////////////
  // RegLnksListToLockedSPRAM
  //////////////////////////////

  RegLnksListToLockedSPRAM::RegLnksListToLockedSPRAM(shared_ptr<RegList> regListLnk1,
						     shared_ptr<RegList> regListLnk2,
						     shared_ptr<RegList> regListLnk3)
    : LinkedRegisterList(regListLnk1, 
			 regListLnk2, 
			 regListLnk3)
  {}

  RegLnksListToLockedSPRAM::~RegLnksListToLockedSPRAM()
  {}

  RegLnksListToLockedSPRAM::RegLnksListToLockedSPRAM(const RegLnksListToLockedSPRAM& rhs)
    : LinkedRegisterList(rhs)
  {}

  RegLnksListToLockedSPRAM& 
  RegLnksListToLockedSPRAM::operator=(const RegLnksListToLockedSPRAM& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }

  void 
  RegLnksListToLockedSPRAM::accept(Visitor &v) const
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
  RegLnksListToLockedSPRAM::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }



  //////////////////////////////
  // RegLnksListToSRAM
  //////////////////////////////

  RegLnksListToSRAM::RegLnksListToSRAM(shared_ptr<RegList> regListLnk1,
				       shared_ptr<RegList> regListLnk2,
				       shared_ptr<RegList> regListLnk3)
    : LinkedRegisterList(regListLnk1, 
			 regListLnk2, 
			 regListLnk3)
  {}

  RegLnksListToSRAM::~RegLnksListToSRAM()
  {}

  RegLnksListToSRAM::RegLnksListToSRAM(const RegLnksListToSRAM& rhs)
    : LinkedRegisterList(rhs)
  {}

  RegLnksListToSRAM& 
  RegLnksListToSRAM::operator=(const RegLnksListToSRAM& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }

  void 
  RegLnksListToSRAM::accept(Visitor &v) const
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
  RegLnksListToSRAM::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }




  //////////////////////////////
  // RegLnksListToSDRAM
  //////////////////////////////

  RegLnksListToSDRAM::RegLnksListToSDRAM(shared_ptr<RegList> regListLnk1,
					 shared_ptr<RegList> regListLnk2,
					 shared_ptr<RegList> regListLnk3)
     : LinkedRegisterList(regListLnk1, 
			  regListLnk2, 
			  regListLnk3)
  {}

  RegLnksListToSDRAM::~RegLnksListToSDRAM()
  {}


  RegLnksListToSDRAM::RegLnksListToSDRAM(const RegLnksListToSDRAM& rhs)
    : LinkedRegisterList(rhs)
  {}

  RegLnksListToSDRAM& 
  RegLnksListToSDRAM::operator=(const RegLnksListToSDRAM& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }


  void 
  RegLnksListToSDRAM::accept(Visitor &v) const
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
  RegLnksListToSDRAM::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }



  //////////////////////////////
  // RegLnksListToCCRAM
  //////////////////////////////

  RegLnksListToCCRAM::RegLnksListToCCRAM(shared_ptr<RegList> regListLnk1,
					 shared_ptr<RegList> regListLnk2,
					 shared_ptr<RegList> regListLnk3)
    : LinkedRegisterList(regListLnk1, 
			 regListLnk2, 
			 regListLnk3)
  {}

  RegLnksListToCCRAM::~RegLnksListToCCRAM()
  {}


  RegLnksListToCCRAM::RegLnksListToCCRAM(const RegLnksListToCCRAM& rhs)
    : LinkedRegisterList(rhs)
  {}


  RegLnksListToCCRAM& 
  RegLnksListToCCRAM::operator=(const RegLnksListToCCRAM& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }

  void 
  RegLnksListToCCRAM::accept(Visitor &v) const
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
  RegLnksListToCCRAM::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }



  //////////////////////////////
  // RegLnksListToLockedCCRAM
  //////////////////////////////

  RegLnksListToLockedCCRAM::RegLnksListToLockedCCRAM(shared_ptr<RegList> regListLnk1,
						     shared_ptr<RegList> regListLnk2,
						     shared_ptr<RegList> regListLnk3)
    : LinkedRegisterList(regListLnk1, 
			 regListLnk2, 
			 regListLnk3)
  {}

  RegLnksListToLockedCCRAM::~RegLnksListToLockedCCRAM()
  {}



  RegLnksListToLockedCCRAM::RegLnksListToLockedCCRAM(const RegLnksListToLockedCCRAM& rhs)
    : LinkedRegisterList(rhs)
  {}


  RegLnksListToLockedCCRAM& 
  RegLnksListToLockedCCRAM::operator=(const RegLnksListToLockedCCRAM& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }


  void 
  RegLnksListToLockedCCRAM::accept(Visitor &v) const
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
  RegLnksListToLockedCCRAM::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }



  //////////////////////////////
  // RegLnksListToSIO
  //////////////////////////////

  RegLnksListToSIO::RegLnksListToSIO(shared_ptr<RegList> regListLnk1,
				     shared_ptr<RegList> regListLnk2,
				     shared_ptr<RegList> regListLnk3)
    : LinkedRegisterList(regListLnk1, 
			 regListLnk2, 
			 regListLnk3)
  {}

  RegLnksListToSIO::~RegLnksListToSIO()
  {}



  RegLnksListToSIO::RegLnksListToSIO(const RegLnksListToSIO& rhs)
    : LinkedRegisterList(rhs)
  {}

  RegLnksListToSIO& 
  RegLnksListToSIO::operator=(const RegLnksListToSIO& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LinkedRegisterList::operator=(rhs);
    return *this;
  }

  void 
  RegLnksListToSIO::accept(Visitor &v) const
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
  RegLnksListToSIO::equalTo(const LinkedRegisterList &rhs) const
  {
    return (*getRegListLnk1() == *rhs.getRegListLnk1() &&
	    *getRegListLnk2() == *rhs.getRegListLnk2() &&
	    *getRegListLnk3() == *rhs.getRegListLnk3() );
  }



  //-------------------------
  // IndirectCallTargetList
  //-------------------------

  IndirectCallTargetList::IndirectCallTargetList(shared_ptr<const LabelList> entryLabelList)
    : LlirOperand(),
      m_FcnEntryPtList(entryLabelList)
  {}

  IndirectCallTargetList::IndirectCallTargetList(const IndirectCallTargetList& rhs)
    : LlirOperand(rhs),
      m_FcnEntryPtList(rhs.m_FcnEntryPtList)
  {}

  IndirectCallTargetList&
  IndirectCallTargetList::operator=(const IndirectCallTargetList& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOperand::operator=(rhs);
    m_FcnEntryPtList = rhs.m_FcnEntryPtList;
    
    return *this;
  }

  IndirectCallTargetList::~IndirectCallTargetList()
  {}

  shared_ptr<const LabelList> 
  IndirectCallTargetList::getLabelList() const
  {
    return  m_FcnEntryPtList;
  }

  bool
  IndirectCallTargetList::equalTo(const LlirOperand& rhs) const
  {
    const IndirectCallTargetList rhsDir
      = dynamic_cast<const IndirectCallTargetList &>(rhs);

    return (*m_FcnEntryPtList == *(rhsDir.getLabelList()));
  }

  void
  IndirectCallTargetList::accept(Visitor& v) const
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


} // namespace LLir
