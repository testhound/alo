#include <typeinfo>
#include <cassert>
#include <iostream>
using namespace std;

#include "LlirOperand.h"
#include "LlirVisitor.h"
#include "LlirException.h"

using namespace Llir;

namespace Llir
{
  LlirOperand::LlirOperand()
  {}

  LlirOperand::LlirOperand(const LlirOperand &rhs)
  {}

  LlirOperand &
  LlirOperand::operator=(const LlirOperand &rhs)
  {
    return *this;
  }

  bool
  LlirOperand::equal(const LlirOperand &rhs) const
  {
    if (typeid(*this) == typeid(rhs))
      return equalTo(rhs);
    else
      return false;
  }


  // OpndMemory

  OpndMemory::OpndMemory()
  {}

  OpndMemory::OpndMemory(const OpndMemory &rhs)
  {}

  OpndMemory &
  OpndMemory::operator=(const OpndMemory &rhs)
  {
      return *this;
  }


  // OpndLabel

  OpndLabel::OpndLabel(const char *label) : 
    LlirExpr(), 
    m_label(label),
    m_mangledLabel(""),
    m_callTarget(false),
    m_branchTarget(false)
  {}
    
  OpndLabel::OpndLabel(const OpndLabel &rhs) : 
    LlirExpr(rhs), 
    m_label(rhs.m_label),
    m_mangledLabel(rhs.m_mangledLabel),
    m_callTarget(rhs.m_callTarget),
    m_branchTarget(rhs.m_branchTarget)
  {}

  OpndLabel &
  OpndLabel::operator=(const OpndLabel &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirExpr::operator=(rhs);
    m_label = rhs.m_label;
    m_mangledLabel = rhs.m_mangledLabel;
    m_callTarget = rhs.m_callTarget;
    m_branchTarget = rhs.m_branchTarget;
    return *this;
  }

  const std::string&
  OpndLabel::getName() const
  {
    return m_label;
  }


  const std::string&
  OpndLabel::getMangledName() const
  {
    return m_mangledLabel;
  }

  void
  OpndLabel::setMangledName(string name)
  {
    m_mangledLabel = name;
  }

  void
  OpndLabel::setCallTarget() const
  {
    m_callTarget = true;
  }
  void
  OpndLabel::setBranchTarget() const
  {
    m_branchTarget = true;
  }

  bool
  OpndLabel::isCallTarget() const
  {
    return m_callTarget;
  }

  bool
  OpndLabel::isBranchTarget() const
  {
    return m_branchTarget;
  }

  inline unsigned long 
  OpndLabel::getConstantValue() const
  {
    throw LlirInternalException("Illegal call to OpndLabel::getConstantValue()", __LINE__, __FILE__);
    return 0;
  }

  void
  OpndLabel::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }
  
  bool
  OpndLabel::equalTo(const LlirOperand &rhs) const
  {
    const OpndLabel temp = dynamic_cast<const OpndLabel &> (rhs);

    return (m_label == temp.m_label);
  }

  // OpndNull

  OpndNull::OpndNull() : LlirOperand()
  {}
    
  OpndNull::OpndNull(const OpndNull &rhs) : LlirOperand(rhs)
  {}

  OpndNull &
  OpndNull::operator=(const OpndNull &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirOperand::operator=(rhs);
    return *this;
  }

  void
  OpndNull::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }

  
  bool
  OpndNull::equalTo(const LlirOperand &rhs) const
  {
    const OpndNull temp = dynamic_cast<const OpndNull &> (rhs);

    return true;
  }

  // LlirExpr

  LlirExpr::LlirExpr() : 
    LlirOperand()
  {}

  LlirExpr::LlirExpr(const LlirExpr &rhs) : 
    LlirOperand(rhs)
  {}

  LlirExpr &
  LlirExpr::operator=(const LlirExpr &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirOperand::operator=(rhs);
    return *this;
  }

  // BinaryExpr

  BinaryExpr::BinaryExpr(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
    LlirExpr(), m_op1(op1), m_op2(op2)
  {}

  BinaryExpr::BinaryExpr(const BinaryExpr &rhs) : 
    LlirExpr(rhs), m_op1(rhs.m_op1), m_op2(rhs.m_op2)
  {}

  BinaryExpr &
  BinaryExpr::operator=(const BinaryExpr &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirExpr::operator=(rhs);
    m_op1 = rhs.m_op1;
    m_op2 = rhs.m_op2;
    return *this;
  }

  inline unsigned long 
  BinaryExpr::getConstantValue() const
  {
    throw LlirInternalException("Illegal call to BinaryExpr::getConstantValue()", __LINE__, __FILE__);
    return 0;
  }
    
  shared_ptr<const LlirOperand>
  BinaryExpr::getLeftOpnd() const
  {
    return m_op1;
  }

  shared_ptr<const LlirOperand>
  BinaryExpr::getRightOpnd() const
  {
    return m_op2;
  }

  // PlusOp

  PlusOp::PlusOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  PlusOp::PlusOp(const PlusOp &rhs) : BinaryExpr(rhs)
  {}

  PlusOp &
  PlusOp::operator=(const PlusOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  PlusOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  PlusOp::equalTo(const LlirOperand &rhs) const
  {
    const PlusOp temp = dynamic_cast<const PlusOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // MinusOp

  MinusOp::MinusOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  MinusOp::MinusOp(const MinusOp &rhs) : BinaryExpr(rhs)
  {}

  MinusOp &
  MinusOp::operator=(const MinusOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  MinusOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  MinusOp::equalTo(const LlirOperand &rhs) const
  {
    const MinusOp temp = dynamic_cast<const MinusOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // MultiplyOp

  MultiplyOp::MultiplyOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  MultiplyOp::MultiplyOp(const MultiplyOp &rhs) : BinaryExpr(rhs)
  {}

  MultiplyOp &
  MultiplyOp::operator=(const MultiplyOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  MultiplyOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  MultiplyOp::equalTo(const LlirOperand &rhs) const
  {
    const MultiplyOp temp = dynamic_cast<const MultiplyOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // DivOp

  DivOp::DivOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  DivOp::DivOp(const DivOp &rhs) : BinaryExpr(rhs)
  {}

  DivOp &
  DivOp::operator=(const DivOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  DivOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  DivOp::equalTo(const LlirOperand &rhs) const
  {
    const DivOp temp = dynamic_cast<const DivOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // ModulusOp

  ModulusOp::ModulusOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  ModulusOp::ModulusOp(const ModulusOp &rhs) : BinaryExpr(rhs)
  {}

  ModulusOp &
  ModulusOp::operator=(const ModulusOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  ModulusOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  ModulusOp::equalTo(const LlirOperand &rhs) const
  {
    const ModulusOp temp = dynamic_cast<const ModulusOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // LeftShiftOp

  LeftShiftOp::LeftShiftOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  LeftShiftOp::LeftShiftOp(const LeftShiftOp &rhs) : BinaryExpr(rhs)
  {}

  LeftShiftOp &
  LeftShiftOp::operator=(const LeftShiftOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  LeftShiftOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  LeftShiftOp::equalTo(const LlirOperand &rhs) const
  {
    const LeftShiftOp temp = dynamic_cast<const LeftShiftOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // RightShiftOp

  RightShiftOp::RightShiftOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  RightShiftOp::RightShiftOp(const RightShiftOp &rhs) : BinaryExpr(rhs)
  {}

  RightShiftOp &
  RightShiftOp::operator=(const RightShiftOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  RightShiftOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  RightShiftOp::equalTo(const LlirOperand &rhs) const
  {
    const RightShiftOp temp = dynamic_cast<const RightShiftOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }



  // BitWiseAndOp

  BitWiseAndOp::BitWiseAndOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  BitWiseAndOp::BitWiseAndOp(const BitWiseAndOp &rhs) : BinaryExpr(rhs)
  {}

  BitWiseAndOp &
  BitWiseAndOp::operator=(const BitWiseAndOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  BitWiseAndOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  BitWiseAndOp::equalTo(const LlirOperand &rhs) const
  {
    const BitWiseAndOp temp = dynamic_cast<const BitWiseAndOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }

  // BitWiseOrOp

  BitWiseOrOp::BitWiseOrOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  BitWiseOrOp::BitWiseOrOp(const BitWiseOrOp &rhs) : BinaryExpr(rhs)
  {}

  BitWiseOrOp &
  BitWiseOrOp::operator=(const BitWiseOrOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  BitWiseOrOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  BitWiseOrOp::equalTo(const LlirOperand &rhs) const
  {
    const BitWiseOrOp temp = dynamic_cast<const BitWiseOrOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }



  // BitWiseXorOp

  BitWiseXorOp::BitWiseXorOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2) : 
   BinaryExpr(op1, op2)
  {}

  BitWiseXorOp::BitWiseXorOp(const BitWiseXorOp &rhs) : BinaryExpr(rhs)
  {}

  BitWiseXorOp &
  BitWiseXorOp::operator=(const BitWiseXorOp &rhs)
  {
    if (this == &rhs)
      return *this;

    BinaryExpr::operator=(rhs);
    return *this;
  }

  void
  BitWiseXorOp::accept(Visitor &v) const
  {
   if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
   {
     lv->visit(*this);
   }
   else
   {
     throw LLIR_INTERNAL_EXCEPTION("accept error");
   }
  }


  bool
  BitWiseXorOp::equalTo(const LlirOperand &rhs) const
  {
    const BitWiseXorOp temp = dynamic_cast<const BitWiseXorOp &> (rhs);
    
    return (*(getLeftOpnd()) == *(temp.getLeftOpnd())
	    && *(getRightOpnd()) == *(temp.getRightOpnd()));
  }


  // UnaryExpr

  UnaryExpr::UnaryExpr(shared_ptr<const LlirOperand> op) : 
    LlirExpr(), m_op(op)
  {}

  UnaryExpr::UnaryExpr(const UnaryExpr &rhs) : 
    LlirExpr(rhs), m_op(rhs.m_op)
  {}

  UnaryExpr &
  UnaryExpr::operator=(const UnaryExpr &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirExpr::operator=(rhs);
    m_op = rhs.m_op;
    return *this;
  }

  inline unsigned long 
  UnaryExpr::getConstantValue() const
  {
    throw LlirInternalException("Illegal call to UnaryExpr::getConstantValue()", __LINE__, __FILE__);
    return 0;
  }
    
  shared_ptr<const LlirOperand>
  UnaryExpr::getOpnd() const
  {
    return m_op;
  }


  // ParenthesesOp

  ParenthesesOp::ParenthesesOp(shared_ptr<const LlirOperand> op) : 
    UnaryExpr(op)
  {}

  ParenthesesOp::ParenthesesOp(const ParenthesesOp &rhs) : 
    UnaryExpr(rhs)
  {}

  ParenthesesOp &
  ParenthesesOp::operator=(const ParenthesesOp &rhs)
  {
    if (this == &rhs)
      return *this;

    UnaryExpr::operator=(rhs);
    return *this;
  }

  void
  ParenthesesOp::accept(Visitor &v) const
  {
    if(LlirVisitor *lbv = dynamic_cast<LlirVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  bool
  ParenthesesOp::equalTo(const LlirOperand &rhs) const
  {
    const ParenthesesOp temp = dynamic_cast<const ParenthesesOp &> (rhs);
    
    return (*(getOpnd()) == *(temp.getOpnd()));
  }


  // UnaryMinusOp

  UnaryMinusOp::UnaryMinusOp(shared_ptr<const LlirOperand> op) : 
    UnaryExpr(op)
  {}

  UnaryMinusOp::UnaryMinusOp(const UnaryMinusOp &rhs) : 
    UnaryExpr(rhs)
  {}

  UnaryMinusOp &
  UnaryMinusOp::operator=(const UnaryMinusOp &rhs)
  {
    if (this == &rhs)
      return *this;

    UnaryExpr::operator=(rhs);
    return *this;
  }

  void
  UnaryMinusOp::accept(Visitor &v) const
  {
    if(LlirVisitor *lbv = dynamic_cast<LlirVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  bool
  UnaryMinusOp::equalTo(const LlirOperand &rhs) const
  {
    const UnaryMinusOp temp = dynamic_cast<const UnaryMinusOp &> (rhs);
    
    return (*(getOpnd()) == *(temp.getOpnd()));
  }

} // namespace LLir
