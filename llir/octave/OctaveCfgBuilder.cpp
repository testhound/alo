#include <boost/shared_ptr.hpp>
#include "OctaveNode.h"

#include "OctaveCfgBuilder.h"

namespace Llir
{
  OctaveCFGBuilder::OctaveCFGBuilder(shared_ptr<AltEntryFunction> f)
    : m_f(f)
  {}

  OctaveCFGBuilder::~OctaveCFGBuilder() 
  {}

  OctaveCFGBuilder& 
  OctaveCFGBuilder::operator=(const OctaveCFGBuilder& rhs)
  {
    if(this == &rhs)
      return *this;

    m_f = rhs.m_f;
    m_nodeList = rhs.m_nodeList;
    return *this;
  }

  OctaveCFGBuilder::OctaveCFGBuilder(const OctaveCFGBuilder& rhs)
    : m_f(rhs.m_f),
      m_nodeList(rhs.m_nodeList)
  {}

  OctaveCFGBuilder::InsnListIterator
  OctaveCFGBuilder::insnListBegin()
  {
    return m_nodeList.begin();
  }

  OctaveCFGBuilder::InsnListIterator
  OctaveCFGBuilder::insnListEnd()
  {
    return m_nodeList.end();
  }

  OctaveCFGBuilder::InsnListConstIterator
  OctaveCFGBuilder::insnListBegin() const
  {
    return m_nodeList.begin();
  }

  OctaveCFGBuilder::InsnListConstIterator
  OctaveCFGBuilder::insnListEnd() const
  {
    return m_nodeList.end();
  }

  void
  OctaveCFGBuilder::identifyValidLlirNodes()
  {
    shared_ptr<LlirOctaveBlock> blk = m_f->getImplicitBlock();

    identifyValidLlirNodes(blk);
  }

  void
  OctaveCFGBuilder::identifyValidLlirNodes(shared_ptr<LlirNode> blk)
  {
    LlirNode::Iterator iter = blk->begin();

    for(; iter != blk->end(); iter++)
      {
	shared_ptr<LlirNode> node = *iter;

	if(node->isBlock())
	  {
	    identifyValidLlirNodes(node);
	  }
	else
	  {
	    if(node->isLabel())
	      m_nodeList.push_back(node);

	    if(node->isInsn())
	      m_nodeList.push_back(node);

	    if(isJtableBegin(node))
	      m_nodeList.push_back(node);
	  }
      }
  }
  
  bool
  OctaveCFGBuilder::isJtableBegin(shared_ptr<LlirNode> node) const
  {
    shared_ptr<JtableBegin> jtb = shared_dynamic_cast<JtableBegin>(node);

    if(jtb)
      return true;

    shared_ptr<JtableRelativeBegin> jtrb = shared_dynamic_cast<JtableRelativeBegin>(node);

    if(jtrb)
      return true;

    return false;
  }

  shared_ptr<AltEntryFunction> 
  OctaveCFGBuilder::getCurrentFunction() const
  {
    return m_f;
  }

  bool
  OctaveCFGBuilder::isEntryPointLabel(shared_ptr<AltEntryFunction> f, 
				      shared_ptr<LlirNode> head) const
  {
    shared_ptr<Label> label = shared_dynamic_cast<Label>(head);

    if(label)
      {
	const char* name = label->getMangledName().c_str();
	
	return f->isEntryPointLabel(name);
      }

    return false;
  }

  bool
  OctaveCFGBuilder::isLastNode(shared_ptr<LlirNode> node) const
  {
    InsnListConstIterator begin = insnListBegin();
    InsnListConstIterator end = insnListEnd();
    if(begin != end)
      return **(--end) == *node;

    return false;
  }
}
