#ifndef _BASIC_BLOCK_H_
#define _BASIC_BLOCK_H_

#include <boost/dynamic_bitset.hpp>
#include <boost/shared_ptr.hpp>
using namespace boost;
#include <list>
using namespace std;

#include "LlirException.h"

namespace Llir
{
  template <class N, class BV>
    class BasicBlock
    {
    public:

      BasicBlock(unsigned int index)
	: m_index(index),
	m_liveOnEntry(new BV()),
	m_liveOnExit(new BV())
	{}

      ~BasicBlock()
	{}

      BasicBlock(const BasicBlock &rhs) : 
	m_index(rhs.m_index),
	m_liveOnEntry(rhs.m_liveOnEntry),
	m_liveOnExit(rhs.m_liveOnExit)
	{}

      BasicBlock& operator=(const BasicBlock& rhs)
	{
	  if(this == &rhs)
	    return *this;

	  m_index = rhs.m_index;
	  m_liveOnEntry = rhs.m_liveOnEntry;
	  m_liveOnExit = rhs.m_liveOnExit;
	}

      unsigned int getIndex() const
	{
	  return m_index;
	}

      bool isEmpty() const
	{
	  return (m_insnList.begin() == m_insnList.end());
	}

      void addNode(shared_ptr<N> node)
	{
	  m_insnList.push_back(node);
	}
      
      shared_ptr<N> getHead()
	{
	  if(!isEmpty())
	    {
	      InsnListIterator begin = m_insnList.begin();
	      return *begin;
	    }

	  throw LLIR_INTERNAL_EXCEPTION("getHead() called on an empty basic block");
	}

      shared_ptr<N> getEnd()
	{
	  if(!isEmpty())
	    {
	      InsnListIterator end = m_insnList.end();
	      --end;
	      return *end;
	    }
	  
	  throw LLIR_INTERNAL_EXCEPTION("getEnd() called on an empty basic block");
	}

      shared_ptr<BV> getRegsLiveOnEntry()
	{
	  return m_liveOnEntry;
	}

      shared_ptr<BV> getRegsLiveOnExit()
      {
	return m_liveOnExit;
      }

      void setRegsLiveOnEntry(shared_ptr<BV> liveOnEntry)
	{
	  m_liveOnEntry = liveOnEntry;
	}

      void setRegsLiveOnExit(shared_ptr<BV> liveOnExit)
	{
	  m_liveOnExit = liveOnExit;
	}


      typedef std::list<shared_ptr<N> >::iterator InsnListIterator;
      typedef std::list<shared_ptr<N> >::const_iterator InsnListConstIterator;

      InsnListIterator InsnListBegin()
      {
	return m_insnList.begin();
      }

      InsnListIterator InsnListEnd()
	{
	  return m_insnList.end();
	}
      
      InsnListConstIterator InsnListBegin() const
	{
	  return m_insnList.begin();
	}
      
      InsnListConstIterator InsnListEnd() const
	{
	  return m_insnList.end();
	}

      
      typedef std::list<shared_ptr<N> >::reverse_iterator InsnListRIterator;
      typedef std::list<shared_ptr<N> >::const_reverse_iterator InsnListConstRIterator;

      InsnListRIterator InsnListRBegin()
      {
	return m_insnList.rbegin();
      }

      InsnListRIterator InsnListREnd()
	{
	  return m_insnList.rend();
	}
      
      InsnListConstRIterator InsnListRBegin() const
	{
	  return m_insnList.rbegin();
	}
      
      InsnListConstRIterator InsnListREnd() const
	{
	  return m_insnList.rend();
	}

      
      
    private:

      unsigned int m_index;
      std::list<shared_ptr<N> > m_insnList;
      shared_ptr<BV> m_liveOnEntry;
      shared_ptr<BV> m_liveOnExit;
    };

  class Edge
    {
    public:

      enum EdgeType { FALLTHROUGH, BRANCH };

      Edge(EdgeType e);
      ~Edge();
      Edge& operator=(const Edge& rhs);
      Edge(const Edge& rhs);

      EdgeType getEdgeType() const;

    private:
      EdgeType m_edgeType;
    };

  class BitVector;

  bool operator==(const BitVector& lhs, const BitVector& rhs);
  bool operator!=(const BitVector& lhs, const BitVector& rhs);
  const BitVector& operator|=(const BitVector& lhs, const BitVector& rhs);

  class BitVector
    {
    public:

      BitVector();
      BitVector(unsigned int length);
      ~BitVector();
      BitVector(const BitVector& rhs);
      BitVector& operator=(const BitVector& rhs);

      unsigned int getSize() const;

      void setBit(unsigned int bitpos);
      void clearBit(unsigned int bitpos);

      bool isBitSet(unsigned int bitpos);
      bool isEmpty();
      void toString(string& s);

      void copyBitSet(shared_ptr<BitVector> bv);
      const BitVector& orBitSet(const BitVector& bv) const;
      bool equalTo(const BitVector& rhs) const;

    private:
      shared_ptr<dynamic_bitset<> > m_bitv;
      
    };
}

#endif
