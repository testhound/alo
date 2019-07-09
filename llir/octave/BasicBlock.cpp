#include "BasicBlock.h"

using namespace boost;

namespace Llir
{

  // Edge

  Edge::Edge(Edge::EdgeType edgeType)
    : m_edgeType(edgeType)
  {}

  Edge::~Edge()
  {}

  Edge::Edge(const Edge& rhs)
   : m_edgeType(rhs.m_edgeType)
  {}

  Edge& 
  Edge::operator=(const Edge& rhs)
  {
    if(this == &rhs)
      return *this;

    m_edgeType = rhs.m_edgeType;
    return *this;
  }

  Edge::EdgeType
  Edge::getEdgeType() const
  {
    return m_edgeType;
  }


  // BitVector

  bool 
  operator==(const BitVector& lhs, const BitVector& rhs)
  {
    return lhs.equalTo(rhs);
  }

  bool
  operator!=(const BitVector& lhs, const BitVector& rhs)
  {
    return ! Llir::operator==(lhs,rhs);
  }

  const BitVector&
  operator|=(const BitVector& lhs, const BitVector& rhs)
  {
    return lhs.orBitSet(rhs);
  }

  BitVector::BitVector()
    : m_bitv(new dynamic_bitset<>())
  {}

  BitVector::BitVector(unsigned int length)
    : m_bitv(new dynamic_bitset<>(length))
  {}

  BitVector::~BitVector()
  {}

  BitVector::BitVector(const BitVector& rhs)
    : m_bitv(rhs.m_bitv)
  {}

  BitVector& 
  BitVector::operator=(const BitVector& rhs)
  {
    if(this == &rhs)
      return *this;

    m_bitv = rhs.m_bitv;
    return *this;
  }

  unsigned int
  BitVector::getSize() const
  {
    return m_bitv->size();
  }

  void
  BitVector::setBit(unsigned int pos)
  {
    m_bitv->set(pos, true);
  }

  bool
  BitVector::isBitSet(unsigned int bitpos)
  {
    return m_bitv->test(bitpos);
  }

  void
  BitVector::clearBit(unsigned int pos)
  {
    m_bitv->set(pos, false);
  }

  bool
  BitVector::isEmpty()
  {
    if(m_bitv->size())
      return false;
    else
      return true;
  }

  void 
  BitVector::toString(string& s)
  {
    boost::to_string(*m_bitv, s);
  }

  bool
  BitVector::equalTo(const BitVector& rhs) const
  {
    return *m_bitv == *rhs.m_bitv;
  }

  const BitVector&
  BitVector::orBitSet(const BitVector& rhs) const
  {
    *m_bitv |= *rhs.m_bitv;
    return *this;
  }

  void 
  BitVector::copyBitSet(shared_ptr<BitVector> bv)
  {
    unsigned int sz = bv->getSize();
    unsigned int i;
    for(i=0; i < sz; i++)
      {
	m_bitv->set(i, bv->isBitSet(i));
      }
  }



}
