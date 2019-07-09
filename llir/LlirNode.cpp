#include <typeinfo>
#include <iostream>
using namespace std;

#include "LlirNode.h"
#include "LlirVisitor.h"
#include "LlirException.h"

//using namespace Llir;

namespace Llir 
{


  //Global Functions
  //----------------

  bool 
  operator==(const LlirNode &lhs, const LlirNode &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const LlirNode &lhs, const LlirNode &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }

  bool 
  operator==(const LlirNodeIterator &lhs, const LlirNodeIterator &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const LlirNodeIterator &lhs, const LlirNodeIterator &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }

  bool 
  operator==(const LlirNodeConstIterator &lhs, const LlirNodeConstIterator &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const LlirNodeConstIterator &lhs, const LlirNodeConstIterator &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }

  //---------------------
  //LlirNode Class
  //---------------------

  LlirNode:: LlirNode(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName) 
    : m_lineNum(lineNum),
      m_srcLineNum(srcLineNum),
      m_srcFile(srcFileName),
      m_visited(false)
  {
    int tempLine = lineNum;

    if (tempLine < 0)
      {
	throw LLIR_INTERNAL_EXCEPTION("Line number out of range");
      }
  }

  LlirNode::LlirNode(const LlirNode& rhs) 
    : m_lineNum(rhs.m_lineNum),
      m_srcLineNum(rhs.m_srcLineNum),
      m_srcFile(rhs.m_srcFile),
      m_visited(rhs.m_visited)
  {}

  LlirNode& 
  LlirNode::operator=(const LlirNode &rhs)
  {
    if (this == &rhs)
      return *this;

    m_lineNum = rhs.m_lineNum;
    m_srcLineNum = rhs.m_srcLineNum;
    m_srcFile = rhs.m_srcFile;
    m_visited = rhs.m_visited;
    return *this;
  }

  unsigned int
  LlirNode::getLineNum() const
  {
    return m_lineNum;
  }

  unsigned int
  LlirNode::getSrcLineNum() const
  {
    return m_srcLineNum;
  }

  const string&
  LlirNode::getSrcFile() const
  {
    return m_srcFile;
  }

  bool
  LlirNode::isNodeVisited() const
  {
    return m_visited;
  }

  void
  LlirNode::visitedNode(bool v)
  {
    m_visited = v;
  }

  bool 
  LlirNode::equal(const LlirNode& rhs) const
  {
    if (typeid(*this) == typeid(rhs))
      return equalTo(rhs);
    else
      return false;
  }

  bool
  LlirNode::isBlock() const
  {
    return false;
  }

  bool
  LlirNode::isLabel() const
  {
    return false;
  }

  bool
  LlirNode::isInsn() const
  {
    return false;
  }

  bool
  LlirNode::isBranchInsn() const
  {
    return false;
  }

  bool
  LlirNode::isCallInsn() const
  {
    return false;
  }

  bool
  LlirNode::isReturnInsn() const
  {
    return false;
  }

  //---------------------
  // LlirFunction
  //---------------------

  LlirFunction::LlirFunction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName,
			     const char* name)
    : LlirNode(lineNum, 
	       srcLineNum, 
	       srcFileName),
      m_funName(name)
  {}

  LlirFunction::LlirFunction(const LlirFunction& rhs)
    : LlirNode(rhs),
      m_funName(rhs.m_funName)
  {}

  LlirFunction&
  LlirFunction::operator=(const LlirFunction& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirNode::operator=(rhs);
    return *this;
  }

  void 
  LlirFunction::setFunctionName(const char* name)
  {
    m_funName = name;
  }

  const string& 
  LlirFunction::getFunctionName() const
  {
    return m_funName;
  }

  //---------------------
  //LlirSequence Class
  //---------------------

  LlirSequence::LlirSequence(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName) 
    : LlirNode(lineNum,
	       srcLineNum,
	       srcFileName)
  {}

  LlirSequence::LlirSequence(const LlirSequence& rhs)
    : LlirNode(rhs),
      m_nodeList(rhs.m_nodeList)
  {}

  LlirSequence&
  LlirSequence::operator=(const LlirSequence& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirNode::operator=(rhs);
    m_nodeList = rhs.m_nodeList;
    return *this; 
  }

  void
  LlirSequence::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirSequence::addLlirNode(parent, child)  illegal oepration");
  }

  void
  LlirSequence::addLlirNode(shared_ptr<LlirNode> node)
  {
    m_nodeList.push_back(node);
  }

  void
  LlirSequence::accept(Visitor &v) const
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

  LlirNode::Iterator 
  LlirSequence::begin()
  {
    return LlirNode::Iterator(new LlirSequenceIterator(m_nodeList.begin()));
  }

  LlirNode::Iterator 
  LlirSequence::end()
  {
    return LlirNode::Iterator(new LlirSequenceIterator(m_nodeList.end()));
  }

  LlirNode::ConstIterator 
  LlirSequence::begin() const
  {
    return LlirNode::ConstIterator(new LlirSequenceConstIterator(m_nodeList.begin()));
  }

  LlirNode::ConstIterator 
  LlirSequence::end() const
  {
    return LlirNode::ConstIterator(new LlirSequenceConstIterator(m_nodeList.end()));
  }

  bool
  LlirSequence::equalTo(const LlirNode &rhs) const
  {
    const LlirSequence rhsSequence = (dynamic_cast<const LlirSequence &> (rhs));

    if (m_nodeList.size() != rhsSequence.m_nodeList.size())
      return false;

    LlirNode::ConstIterator thisIterator = this->begin();
    LlirNode::ConstIterator rhsIterator = rhsSequence.begin();
    LlirNode::ConstIterator endIterator = this->end();

    for (; thisIterator != endIterator; thisIterator++, rhsIterator++)
      {
	if (*(*thisIterator) != *(*rhsIterator))
	  return false;
      }

    return true;
  }

  //---------------------
  //LlirInstruction Class
  //---------------------

  LlirInstruction::LlirInstruction(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName) 
    : LlirNode(lineNum,
	       srcLineNum,
	       srcFileName)
  {}

  LlirInstruction::LlirInstruction(const LlirInstruction& rhs)
    : LlirNode(rhs)
  {}

  LlirInstruction&
  LlirInstruction::operator=(const LlirInstruction& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirNode::operator=(rhs);
    return *this; 
  }

  void 
  LlirInstruction::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirInstruction::addLlirNode not implemented");
  }


  void 
  LlirInstruction::addOperand(shared_ptr<const LlirOperand> op)
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirInstruction::addOperand not implemented");
  }


  LlirNode::Iterator
  LlirInstruction::begin() 
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirInstruction is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::Iterator
  LlirInstruction::end() 
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirInstruction is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::ConstIterator
  LlirInstruction::begin() const
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirInstruction is a non-aggregate node");
    LlirNode::ConstIterator iter(new LlirNullConstIterator());
    return iter; 
  }

  LlirNode::ConstIterator
  LlirInstruction::end() const
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirInstruction is a non-aggregate node");
    LlirNode::ConstIterator iter(new LlirNullConstIterator());
    return iter; 
  }

  bool
  LlirInstruction::isInsn() const
  {
    return true;
  }


  //------------------------------
  //LlirLineControlDirective Class
  //------------------------------

  //Note: line control directives do not
  //have source file origins, they are
  //generated by the preprocessor.


  LlirLineControlDirective::LlirLineControlDirective(unsigned int lineNum, 
						     unsigned int lineCntrlNum, 
						     const char *asmFileName, 
						     LineCntrlFlagType flag)
    : LlirNode(lineNum,0,""), 
      m_lineCntrlNum(lineCntrlNum),
      m_asmFileName(asmFileName),
      m_flag(flag)
  {}

  LlirLineControlDirective::LlirLineControlDirective(const LlirLineControlDirective& rhs)
    : LlirNode(rhs),
      m_lineCntrlNum(rhs.m_lineCntrlNum),
      m_asmFileName(rhs.m_asmFileName),
      m_flag(rhs.m_flag)
  {}


  unsigned int 
  LlirLineControlDirective::getLineCntrlNum() const
  { 
    return m_lineCntrlNum; 
  }

  const string& 
  LlirLineControlDirective::getAsmFileName() const
  { 
    return m_asmFileName; 
  }

  LlirLineControlDirective::LineCntrlFlagType 
  LlirLineControlDirective::getLineCntrlFlagType() const
  { 
    return m_flag; 
  }

  LlirLineControlDirective& 
  LlirLineControlDirective::operator=(const LlirLineControlDirective &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirNode::operator=(rhs);
    m_lineCntrlNum = rhs.m_lineCntrlNum; 
    m_asmFileName = rhs.m_asmFileName; 
    m_flag = rhs.m_flag;

    return *this;
  }

  void 
  LlirLineControlDirective::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirLineControlDirective is a non-aggregate node");
  }


  void
  LlirLineControlDirective::accept(Visitor &v) const
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


  LlirNode::Iterator
  LlirLineControlDirective::begin()
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirLineControlDirective is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::Iterator
  LlirLineControlDirective::end()
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirLineControlDirective is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }



  LlirNode::ConstIterator
  LlirLineControlDirective::begin() const
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirLineControlDirective is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }


  LlirNode::ConstIterator
  LlirLineControlDirective::end() const
  {
    throw LLIR_INTERNAL_EXCEPTION("LlirLineControlDirective is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }


  bool
  LlirLineControlDirective::equalTo(const LlirNode &rhs) const
  {
    const LlirLineControlDirective &lcdRhs = dynamic_cast<const LlirLineControlDirective&> (rhs);

    if(getLineNum() == lcdRhs.getLineNum() &&
       getAsmFileName() == lcdRhs.getAsmFileName() &&
       getLineCntrlFlagType() == lcdRhs.getLineCntrlFlagType())
      {
	return true; 
      }
    else
      {
	return false;
      }
  }



  //------------------------------
  //NewLineNode Class
  //------------------------------

  NewLineNode::NewLineNode(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName,
			   const char* newLineString)
    : LlirNode(lineNum, 
	       srcLineNum, 
	       srcFileName),
      m_newLineString(newLineString)
  {}

  NewLineNode::NewLineNode(const NewLineNode& rhs)
    : LlirNode(rhs),
      m_newLineString(rhs.m_newLineString)
  {}


  NewLineNode& 
  NewLineNode::operator=(const NewLineNode &rhs)
  {
    if (this == &rhs)
      return *this;

    m_newLineString = rhs.m_newLineString;
    LlirNode::operator=(rhs);
    return *this;
  }


  const string&
  NewLineNode::getNewLineString() const
  {
    return m_newLineString;
  }

  void 
  NewLineNode::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    throw LLIR_INTERNAL_EXCEPTION("NewLineNode is a non-aggregate node");
  }

  void
  NewLineNode::accept(Visitor &v) const
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

  LlirNode::Iterator
  NewLineNode::begin()
  {
    throw LLIR_INTERNAL_EXCEPTION("NewLineNode is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::Iterator
  NewLineNode::end()
  {
    throw LLIR_INTERNAL_EXCEPTION("NewLineNode is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::ConstIterator
  NewLineNode::begin() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NewLineNode is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }

  LlirNode::ConstIterator
  NewLineNode::end() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NewLineNode is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }

  bool
  NewLineNode::equalTo(const LlirNode &rhs) const
  {
    const NewLineNode &r = dynamic_cast<const NewLineNode&> (rhs);

    if(getLineNum() == r.getLineNum() &&
       m_newLineString == r.getNewLineString())
      {
	return true; 
      }
    else
      {
	return false;
      }
  }






  //------------------------------
  //NullNode Class
  //------------------------------

  NullNode::NullNode()
    : LlirNode(0, 0, "")
  {}

  NullNode::NullNode(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName)
    : LlirNode(lineNum,
	       srcLineNum,
	       srcFileName)
  {}

  NullNode::NullNode(const NullNode& rhs)
    : LlirNode(rhs)
  {}


  NullNode& 
  NullNode::operator=(const NullNode &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirNode::operator=(rhs);
    return *this;
  }

  void 
  NullNode::addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child)
  {
    throw LLIR_INTERNAL_EXCEPTION("NullNode is a non-aggregate node");
  }


  void
  NullNode::accept(Visitor &v) const
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


  LlirNode::Iterator
  NullNode::begin()
  {
    throw LLIR_INTERNAL_EXCEPTION("NullNode is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }

  LlirNode::Iterator
  NullNode::end()
  {
    throw LLIR_INTERNAL_EXCEPTION("NullNode is a non-aggregate node");
    LlirNode::Iterator iter(new LlirNullIterator());
    return iter; 
  }



  LlirNode::ConstIterator
  NullNode::begin() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullNode is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }


  LlirNode::ConstIterator
  NullNode::end() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullNode is a non-aggregate node");
    LlirNode::ConstIterator citer(new LlirNullConstIterator());
    return citer; 
  }


  bool
  NullNode::equalTo(const LlirNode &rhs) const
  {
    const NullNode &r = dynamic_cast<const NullNode&> (rhs);

    if(getLineNum() == r.getLineNum())
      {
	return true; 
      }
    else
      {
	return false;
      }
  }









  //--------------------
  // LlirAsmDirective
  //--------------------

  LlirAsmDirective::LlirAsmDirective(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName) 
    : LlirNode(lineNum,
	       srcLineNum,
	       srcFileName)
  {}


  LlirAsmDirective::LlirAsmDirective(const LlirAsmDirective& rhs) : LlirNode(rhs)
  {}

  LlirAsmDirective&
  LlirAsmDirective::operator=(const LlirAsmDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirNode::operator=(rhs);
    return *this; 
  }

  //---------------------
  //LlirNodeIterator Class
  //----------------------

  bool
  LlirNodeIterator::equal(const LlirNodeIterator &rhs) const
  {
    if (typeid(*this) == typeid(rhs))
      return equalTo(rhs);
    else
      return false;
  }

  //---------------------
  //LlirNodeConstIterator Class
  //----------------------

  bool
  LlirNodeConstIterator::equal(const LlirNodeConstIterator &rhs) const
  {
    if (typeid(*this) == typeid(rhs))
      return equalTo(rhs);
    else
      return false;
  }

  //---------------------
  //LlirSequenceIterator Class
  //----------------------

  LlirSequenceIterator::LlirSequenceIterator()
  {}

  LlirSequenceIterator::LlirSequenceIterator(LlirSequence::SeqIterator i)
    : m_iterator(i)
  {}

  LlirSequenceIterator::LlirSequenceIterator(const LlirSequenceIterator &rhs)
    : LlirNodeIterator(rhs),
      m_iterator(rhs.m_iterator)
  {}

  LlirSequenceIterator&
  LlirSequenceIterator::operator=(const LlirSequenceIterator &rhs)
  {
    if (this == &rhs)
      return *this;

    this->LlirNodeIterator::operator=(rhs);
    m_iterator = rhs.m_iterator;
    return *this;
  }

  bool
  LlirSequenceIterator::equalTo(const LlirNodeIterator &rhs) const
  {
    return (m_iterator == (dynamic_cast<const LlirSequenceIterator &> (rhs)).m_iterator);
  }

  LlirNodeIterator* 
  LlirSequenceIterator::postInc()
  {
    LlirNodeIterator* old( new LlirSequenceIterator(m_iterator) );
    m_iterator++;
    return old;
  }

  void
  LlirSequenceIterator::preInc()
  {
    ++m_iterator;
  }

  LlirNodeIterator*
  LlirSequenceIterator::postDec()
  {
    LlirNodeIterator* old( new LlirSequenceIterator(m_iterator) );
    m_iterator--;
    return old;
  }

  void
  LlirSequenceIterator::preDec()
  {
    --m_iterator;
  }

  shared_ptr<LlirNode>&
  LlirSequenceIterator::operator*()
  {
    return *m_iterator;
  }

  shared_ptr<LlirNode>*
  LlirSequenceIterator::operator->()
  {
    return &(*m_iterator);
  }


  //----------------------------------
  // LlirSequenceConstIterator class
  //----------------------------------

  LlirSequenceConstIterator::LlirSequenceConstIterator()
  {}

  LlirSequenceConstIterator::LlirSequenceConstIterator(LlirSequence::SeqConstIterator i)
    : m_iterator(i)
  {}

  LlirSequenceConstIterator::LlirSequenceConstIterator(const LlirSequenceConstIterator &rhs)
    : LlirNodeConstIterator(rhs),
      m_iterator(rhs.m_iterator)
  {}

  LlirSequenceConstIterator&
  LlirSequenceConstIterator::operator=(const LlirSequenceConstIterator &rhs)
  {
    if (this == &rhs)
      return *this;

    this->LlirNodeConstIterator::operator=(rhs);
    m_iterator = rhs.m_iterator;
    return *this;
  }

  bool
  LlirSequenceConstIterator::equalTo(const LlirNodeConstIterator &rhs) const
  {
    return (m_iterator == (dynamic_cast<const LlirSequenceConstIterator &> (rhs)).m_iterator);
  }

  LlirNodeConstIterator*
  LlirSequenceConstIterator::postInc()
  {
    LlirNodeConstIterator* old( new LlirSequenceConstIterator(m_iterator) );
    m_iterator++;
    return old;
  }

  void
  LlirSequenceConstIterator::preInc()
  {
    ++m_iterator;
  }

  LlirNodeConstIterator*
  LlirSequenceConstIterator::postDec()
  {
    LlirNodeConstIterator* old( new LlirSequenceConstIterator(m_iterator) );
    m_iterator--;
    return old;
  }

  void
  LlirSequenceConstIterator::preDec()
  {
    --m_iterator;
  }

  const shared_ptr<LlirNode>&
  LlirSequenceConstIterator::operator*()
  {
    return *m_iterator;
  }

  const shared_ptr<LlirNode>*
  LlirSequenceConstIterator::operator->()
  {
    return &(*m_iterator);
  }

}  // namespace Llir




