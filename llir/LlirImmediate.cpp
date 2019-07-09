#include <typeinfo>
#include <cassert>
#include <iostream>
using namespace std;

#include "LlirVisitor.h"
#include "LlirOperand.h"
#include "LlirException.h"

namespace Llir
{
  //
  UnsignedImmediate::UnsignedImmediate(unsigned long val, unsigned int numBits) : 
    LlirExpr(), m_value(val), m_numBits(numBits), m_min(0), m_max((1 << numBits) - 1)
  {}

  UnsignedImmediate::UnsignedImmediate(unsigned long val, unsigned long min, unsigned long max, 
				       unsigned int numBits) : 
    LlirExpr(), m_value(val), m_numBits(numBits),
    m_min(min), m_max(max)
  {}

  UnsignedImmediate::UnsignedImmediate(const UnsignedImmediate &rhs) : 
    LlirExpr(rhs), m_value(rhs.m_value), m_numBits(rhs.m_numBits),
    m_min(rhs.m_min), m_max(rhs.m_max)
  {}

  UnsignedImmediate &
  UnsignedImmediate::operator=(const UnsignedImmediate &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirExpr::operator=(rhs);
    m_value = rhs.m_value; 
    m_numBits = rhs.m_numBits;
    m_min = rhs.m_min;
    m_max = rhs.m_max;
    return *this;
  }

  unsigned long
  UnsignedImmediate::getValue() const
  {
    return m_value;
  }

  unsigned long
  UnsignedImmediate::getMinValue() const
  {
    return m_min;
  }

  unsigned long
  UnsignedImmediate::getMaxValue() const
  {
    return m_max;
  }

  unsigned int
  UnsignedImmediate::getNumBits() const
  {
    return m_numBits;
  }

  void
  UnsignedImmediate::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v)) 
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("UnsignedImmediate::accept - Visit error");
    }       
  }


  bool
  UnsignedImmediate::equalTo(const LlirOperand &rhs) const
  {
    const UnsignedImmediate temp = dynamic_cast<const UnsignedImmediate &> (rhs);

    return ((m_value == temp.getValue()) && (m_numBits == temp.getNumBits())
	    && (m_min == temp.getMinValue()) && (m_max == temp.getMaxValue()));
  }

  //

  SignedImmediate::SignedImmediate(long val, unsigned int numBits) : 
    LlirExpr(), m_value(val), m_min(0), m_max((1 << numBits) - 1), m_numBits(numBits)
  {}

  SignedImmediate::SignedImmediate(long val, long min, long max, 
				   unsigned int numBits) : 
    LlirExpr(), m_value(val), m_min(min), m_max(max), m_numBits(numBits)
  {}

  SignedImmediate::SignedImmediate(const SignedImmediate &rhs) : 
    LlirExpr(rhs), m_value(rhs.m_value), m_min(rhs.m_min), m_max(rhs.m_max),
    m_numBits(rhs.m_numBits)
  {}

  SignedImmediate &
  SignedImmediate::operator=(const SignedImmediate &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirExpr::operator=(rhs);
    m_value = rhs.m_value; 
    m_numBits = rhs.m_numBits;
    m_min = rhs.m_min;
    m_max = rhs.m_max;
    return *this;
  }

  long
  SignedImmediate::getValue() const
  {
    return m_value;
  }

  long
  SignedImmediate::getMinValue() const
  {
    return m_min;
  }

  long
  SignedImmediate::getMaxValue() const
  {
    return m_max;
  }

  unsigned int
  SignedImmediate::getNumBits() const
  {
    return m_numBits;
  }

  void
  SignedImmediate::accept(Visitor &v) const
  {
    if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v)) 
    {
      lv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("SignedImmediate::accept - Visit error");
    }       
  }


  bool
  SignedImmediate::equalTo(const LlirOperand &rhs) const
  {
    const SignedImmediate temp = dynamic_cast<const SignedImmediate &> (rhs);

    return ((m_value == temp.getValue()) && (m_numBits == temp.getNumBits())
	    && (m_min == temp.getMinValue()) && (m_max == temp.getMaxValue()));
  }
} // namespace Llir
