#ifndef _LLIR_NODE_H_
#define _LLIR_NODE_H_


#include <string>
#include <list>
#include <map>
using namespace std;

#include <boost/shared_ptr.hpp>
using namespace boost;

#include "LlirException.h"

namespace Llir 
{

 
  template <class S, class T> class StlBidirectionalIterator;
  template <class S, class T> class StlBidirectionalConstIterator;
  class LlirNode;
  class LlirNodeIterator;
  class LlirNodeConstIterator;
  class LlirOperand;
  class Visitor;
  class LlirVisitor;
  class LlirNullIterator;

  bool operator==(const LlirNode &lhs, const LlirNode &rhs);
  bool operator!=(const LlirNode &lhs, const LlirNode &rhs);
  bool operator==(const LlirNodeIterator &lhs, const LlirNodeIterator &rhs);
  bool operator!=(const LlirNodeIterator &lhs, const LlirNodeIterator &rhs);
  bool operator==(const LlirNodeConstIterator &lhs, const LlirNodeConstIterator &rhs);
  bool operator!=(const LlirNodeConstIterator &lhs, const LlirNodeConstIterator &rhs);

  class LlirNode
    {
    public:

      typedef StlBidirectionalIterator<LlirNode, LlirNodeIterator> Iterator;

      typedef StlBidirectionalConstIterator<LlirNode, LlirNodeConstIterator> ConstIterator;

      virtual ~LlirNode()
	{}

      bool equal(const LlirNode& rhs) const;

      virtual void addLlirNode(shared_ptr<LlirNode>, shared_ptr<LlirNode>) = 0;

      virtual Iterator begin() = 0;

      virtual Iterator end() = 0;

      virtual ConstIterator begin() const = 0;

      virtual ConstIterator end() const = 0;

      unsigned int getLineNum() const;

      unsigned int getSrcLineNum() const;

      const string& getSrcFile() const;

      virtual void accept(Visitor& v) const =0;

      bool isNodeVisited() const;
      
      void visitedNode(bool v);

      virtual bool isBlock() const;
      
      virtual bool isLabel() const;

      virtual bool isInsn() const;

      virtual bool isBranchInsn() const;

      virtual bool isReturnInsn() const;

      virtual bool isCallInsn() const;

    protected:

      LlirNode(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName);

      LlirNode(const LlirNode& rhs);
   
      LlirNode& operator=(const LlirNode&);

      virtual bool equalTo(const LlirNode &rhs) const = 0;

    private:

      // line number in the include file 
      // on which this node was seen
      unsigned int m_lineNum;

      // the source file line num
      unsigned int m_srcLineNum;

      // the source file name
      string m_srcFile;

      //
      bool m_visited;
    };


  class LlirSequence : public LlirNode
    {
    public:
      typedef std::list<shared_ptr<LlirNode> >::iterator SeqIterator;
      typedef std::list<shared_ptr<LlirNode> >::const_iterator SeqConstIterator;

      LlirSequence(unsigned int linenum,
		   unsigned int srcLineNum,
		   const char* srcFileName);

      virtual ~LlirSequence()
	{}
      LlirSequence(const LlirSequence& rhs);
      LlirSequence& operator=(const LlirSequence& rhs);

      void addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child);
      void addLlirNode(shared_ptr<LlirNode>);
      LlirNode::Iterator begin();
      LlirNode::Iterator end();
      LlirNode::ConstIterator begin() const;
      LlirNode::ConstIterator end() const;

      virtual void accept(Visitor& v) const;

    protected:
      virtual bool equalTo(const LlirNode &rhs) const;

    private:
      std::list<shared_ptr<LlirNode> > m_nodeList;
    };

  class LlirInstruction : public LlirNode
    {
    public:

      virtual ~LlirInstruction()
	{}

      LlirNode::Iterator begin();

      LlirNode::Iterator end();

      LlirNode::ConstIterator begin() const;

      LlirNode::ConstIterator end() const;

      void addLlirNode(shared_ptr<LlirNode>, shared_ptr<LlirNode>);

      virtual void addOperand(shared_ptr<const LlirOperand> op)=0;
 
      bool isInsn() const;

    protected:
 
      LlirInstruction(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName);

      LlirInstruction(const LlirInstruction& rhs);

      LlirInstruction& operator=(const LlirInstruction& rhs);

    };

  template<class T>
    class SymbolTable
    {
    public: 

      typedef typename std::map<string, shared_ptr<T> >::iterator Iterator;

      typedef typename std::map<string, shared_ptr<T> >::const_iterator ConstIterator;     

      SymbolTable() {}

      ~SymbolTable() {} 

      SymbolTable(const SymbolTable& rhs) : m_symList(rhs.m_symList) {}

      SymbolTable& operator=(const SymbolTable& rhs)
      {
	if(this == &rhs)
          return *this;

	m_symList = rhs.m_symList;
	return *this;

      }   

      void addSymbol(shared_ptr<T> sym) 
	{
	  string name = sym->getName();

	  if(m_symList.find(name) == m_symList.end()) 
	    {
	      m_symList[name] = sym;  
	    }
	  //else
	  // whoever is adding the symbol should
	  // take care of this else case, by doing a 
	  // lookup first...
	}

      void removeSymbol(shared_ptr<T> sym)
	{
	  string name = sym->getName();
	  Iterator iter = m_symList.find(name);
          if(iter != m_symList.end())
	  {
	    m_symList.erase(iter);	
	  }
	}	

      Iterator lookupSymbol(const char *name)
	{
	  return m_symList.find(name);
	}  

      ConstIterator lookupSymbol(const char *name) const
	{
	  return m_symList.find(name);
	}  

      Iterator begin() 
	{
	  return m_symList.begin();
	}

      Iterator end()
	{
	  return m_symList.end();
	}

      ConstIterator begin() const
	{
	  return m_symList.begin();
	}

      ConstIterator end() const
	{
	  return m_symList.end();
	}

      void accept(Visitor &v) const
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

    private:

      std::map<string, shared_ptr<T> > m_symList;

    };


  //--------------------------------------------------
  // LlirBlock
  //--------------------------------------------------

  template<class SymbolTp>
    class LlirBlock : public LlirNode
    {

    public: 

      virtual ~LlirBlock(){}

      virtual void addSymbol(shared_ptr<SymbolTp> sym)=0; 

      virtual typename SymbolTable<SymbolTp>::Iterator lookupSymbol(const char *name) =0;

      virtual typename SymbolTable<SymbolTp>::ConstIterator lookupSymbol(const char *name) const =0;

      const std::string& getName() const { return m_blkName; }

    protected:

      LlirBlock(unsigned int lineNum,
		unsigned int srcLineNum,
		const char* srcFileName) 
	: LlirNode(lineNum, srcLineNum, srcFileName), 
	m_blkName("BlockWithNoName"),
	m_blkId(m_currentBlkId++) {} 

      LlirBlock(const char *name, 
		unsigned int lineNum,
		unsigned int srcLineNum,
		const char* srcFileName) 
	: LlirNode(lineNum, srcLineNum, srcFileName), 
	m_blkName(name), 
	m_blkId(m_currentBlkId++) {} 


      LlirBlock(const LlirBlock& rhs) 
	: LlirNode(rhs), 
	m_blkName(rhs.m_blkName),
	m_blkId(rhs.m_blkId) {}


      LlirBlock& operator=(const LlirBlock& rhs)
      {
	if (this == &rhs)
	  return *this;

	LlirNode::operator=(rhs); 
	m_blkName = rhs.m_blkName;
	m_blkId = rhs.m_blkId;
	return *this;
      }

    protected:

      unsigned int getBlkId() const
        {
          return m_blkId;
        }

    private:

      std::string m_blkName;

      unsigned int m_blkId;

      static unsigned int m_currentBlkId;


    };



  class LlirFunction : public LlirNode
    {
    public:
      
      LlirFunction(unsigned int lineNum,
		   unsigned int srcLineNum,
		   const char* srcFileName, 
		   const char* name);

      LlirFunction(const LlirFunction& rhs);

      ~LlirFunction()
	{}

      LlirFunction& operator=(const LlirFunction& rhs);

      void setFunctionName(const char* name);

      const string& getFunctionName() const;

    private:
      
      string m_funName;
      
    };




  //--------------------------------------------------
  // LlirLineControlDirective
  //--------------------------------------------------

  class LlirLineControlDirective : public LlirNode
    {

    public:

      enum LineCntrlFlagType { LCD_NONE=0, 
			       LCD_NEWFILE=1, 
			       LCD_RETURN, 
			       LCD_SYSHDR, 
			       LCD_CTEXT };

      LlirLineControlDirective(unsigned int lineNum, 
			       unsigned int lineCntrlNum, 
			       const char *asmFileName, 
			       LineCntrlFlagType flag);

      LlirLineControlDirective(const LlirLineControlDirective& rhs);

      ~LlirLineControlDirective()
	{}

      LlirLineControlDirective& operator=(const LlirLineControlDirective& rhs);

      unsigned int getLineCntrlNum() const;

      const string& getAsmFileName() const;

      LineCntrlFlagType getLineCntrlFlagType() const;

      void addLlirNode(shared_ptr<LlirNode> , shared_ptr<LlirNode>);

      void accept(Visitor& v) const;

      LlirNode::Iterator begin();

      LlirNode::Iterator end();

      LlirNode::ConstIterator begin() const;

      LlirNode::ConstIterator end() const;

    private:

      unsigned int m_lineCntrlNum;

      string m_asmFileName;

      LineCntrlFlagType m_flag;

      bool equalTo(const LlirNode& n) const;

    };



  //--------------------------------------------------
  // NewLineNode
  //--------------------------------------------------

  class NewLineNode : public LlirNode
    {

    public:

      NewLineNode(unsigned int lineNum,
		  unsigned int srcLineNum,
		  const char* srcFileName, 
		  const char *newLineStr);
			       
      NewLineNode(const NewLineNode& rhs);

      ~NewLineNode()
	{}

      NewLineNode& operator=(const NewLineNode& rhs);

      const string& getNewLineString() const;

      void addLlirNode(shared_ptr<LlirNode> , shared_ptr<LlirNode>);

      void accept(Visitor& v) const;

      LlirNode::Iterator begin();

      LlirNode::Iterator end();

      LlirNode::ConstIterator begin() const;

      LlirNode::ConstIterator end() const;

    private:

      bool equalTo(const LlirNode& n) const;

      string m_newLineString;

    };




  //--------------------------------------------------
  // NullNode
  //--------------------------------------------------

  class NullNode : public LlirNode
    {

    public:

      NullNode();

      NullNode(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName);
			       
      NullNode(const NullNode& rhs);

      ~NullNode()
	{}

      NullNode& operator=(const NullNode& rhs);

      void addLlirNode(shared_ptr<LlirNode> , shared_ptr<LlirNode>);

      void accept(Visitor& v) const;

      LlirNode::Iterator begin();

      LlirNode::Iterator end();

      LlirNode::ConstIterator begin() const;

      LlirNode::ConstIterator end() const;

    private:

      bool equalTo(const LlirNode& n) const;

    };




  class LlirAsmDirective : public LlirNode
    {

    public:

      virtual ~LlirAsmDirective();

    protected:

      LlirAsmDirective(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName);

      LlirAsmDirective(const LlirAsmDirective& rhs);

      LlirAsmDirective& operator=(const LlirAsmDirective& rhs);

    };

  inline
    LlirAsmDirective::~LlirAsmDirective()
    {}

  //--------------------------------------------------
  // StlBidirectionalIterator
  //--------------------------------------------------

  template <class S, class T>
    class StlBidirectionalIterator : public std::iterator<std::bidirectional_iterator_tag, shared_ptr<S> >
    {
    public:
      //StlBidirectionalIterator() : m_p( static_cast<shared_ptr<T> >(0) ) {}

      StlBidirectionalIterator() : m_p( new LlirNullIterator() ) {}

      StlBidirectionalIterator(T *p) : m_p(p) {}

      StlBidirectionalIterator(const StlBidirectionalIterator &rhs) : m_p(rhs.m_p) {}

      const StlBidirectionalIterator& operator=(const StlBidirectionalIterator &rhs)
      {
	if (this == &rhs)
	  return *this;

	m_p = rhs.m_p;
	return *this;
      }

      ~StlBidirectionalIterator() {}

      StlBidirectionalIterator& operator++()
	{
	  m_p->preInc();
	  return *this;
	}

      StlBidirectionalIterator operator++(int)   // postincrement
	{
	  T *old = m_p->postInc();
	  return StlBidirectionalIterator(old);
	}

      StlBidirectionalIterator& operator--()
	{
	  m_p->preDec();
	  return *this;
	}

      StlBidirectionalIterator  operator--(int)  // postdecrement
	{
	  T *old = m_p->postDec();
	  return StlBidirectionalIterator(old);
	}

      friend bool operator==(const StlBidirectionalIterator &lhs, const StlBidirectionalIterator &rhs)
      {
	return (*(lhs.m_p) == *(rhs.m_p));
      }

      friend bool operator!=(const StlBidirectionalIterator &lhs, const StlBidirectionalIterator &rhs)
      {
	return !(Llir::operator==(lhs,rhs));
      }

      shared_ptr<S>& operator*() const
	{
	  return m_p->operator*();
	}

      shared_ptr<S>* operator->() const
	{
	  return m_p->operator->();
	}

    private:
      shared_ptr<T> m_p;

    };


  //--------------------------------------------------
  // StlBidirectionalConstIterator
  //--------------------------------------------------

  template <class S, class T>
    class StlBidirectionalConstIterator : public std::iterator<std::bidirectional_iterator_tag, shared_ptr<S> >
    {
    public:
      StlBidirectionalConstIterator() : m_p( static_cast<shared_ptr<const T> >(0) ) {}

      StlBidirectionalConstIterator(T *p) : m_p(p) {}

      StlBidirectionalConstIterator(const StlBidirectionalConstIterator &rhs) : m_p(rhs.m_p) {}

      const StlBidirectionalConstIterator& operator=(const StlBidirectionalConstIterator &rhs)
      {
	if (this == &rhs)
	  return *this;

	m_p = rhs.m_p;
	return *this;
      }

      ~StlBidirectionalConstIterator() {}

      StlBidirectionalConstIterator& operator++()
	{
	  m_p->preInc();
	  return *this;
	}

      StlBidirectionalConstIterator operator++(int)   // postincrement
	{
	  T *old = m_p->postInc();
	  return StlBidirectionalConstIterator(old);
	}

      StlBidirectionalConstIterator& operator--()
	{
	  m_p->preDec();
	  return *this;
	}

      StlBidirectionalConstIterator operator--(int)  // postdecrement
	{
	  T *old = m_p->postDec();
	  return StlBidirectionalConstIterator(old);
	}

      friend bool operator==(const StlBidirectionalConstIterator &lhs, const StlBidirectionalConstIterator &rhs)
      {
	return (*(lhs.m_p) == *(rhs.m_p));
      }

      friend bool operator!=(const StlBidirectionalConstIterator &lhs, const StlBidirectionalConstIterator &rhs)
      {
	return !(Llir::operator==(lhs,rhs));
      }

      const shared_ptr<S>& operator*() const
	{
	  return m_p->operator*();
	}

      const shared_ptr<S>* operator->() const
	{
	  return m_p->operator->();
	}

    private:
      shared_ptr<T> m_p;

    };




  //----------------------------------------
  // LlirNodeIterator class
  //----------------------------------------

  class LlirNodeIterator
    {
    public:
      virtual ~LlirNodeIterator()
	{}

      virtual LlirNodeIterator* postInc() = 0;

      virtual void preInc() = 0;

      virtual LlirNodeIterator* postDec() = 0;

      virtual void preDec() = 0;

      virtual shared_ptr<LlirNode>& operator*() = 0;

      virtual shared_ptr<LlirNode> *operator->() = 0;

      bool equal(const LlirNodeIterator &rhs) const;
  
    protected:

      LlirNodeIterator()
	{}

      LlirNodeIterator(const LlirNodeIterator &)
	{}

      //FIXME : check this method
      LlirNodeIterator& operator=(const LlirNodeIterator &)
      { return *this; }

      virtual bool equalTo(const LlirNodeIterator &rhs) const = 0;
  
    };


  //----------------------------------------
  // LlirNodeConstIterator
  //----------------------------------------

  class LlirNodeConstIterator
    {

    public:

      virtual ~LlirNodeConstIterator()
	{}

      virtual LlirNodeConstIterator* postInc() = 0;

      virtual void preInc() = 0;

      virtual LlirNodeConstIterator* postDec() = 0;

      virtual void preDec() = 0;

      virtual const shared_ptr<LlirNode>& operator*() = 0;

      virtual const shared_ptr<LlirNode> *operator->() = 0;

      bool equal(const LlirNodeConstIterator &rhs) const;
  
    protected:

      LlirNodeConstIterator()
	{}

      LlirNodeConstIterator(const LlirNodeConstIterator& rhs)
	{}

      LlirNodeConstIterator& operator=(const LlirNodeConstIterator &)
      { return *this; }

      virtual bool equalTo(const LlirNodeConstIterator &rhs) const = 0;
  
    };


  //--------------------------------------------------
  // LlirSequenceIterator
  //--------------------------------------------------

  class LlirSequenceIterator : public LlirNodeIterator
    {
    public:
      LlirSequenceIterator();
      LlirSequenceIterator(LlirSequence::SeqIterator);
      LlirSequenceIterator(const LlirSequenceIterator &rhs);
      LlirSequenceIterator& operator=(const LlirSequenceIterator &);
      ~LlirSequenceIterator(){}

      bool equalTo(const LlirNodeIterator &rhs) const;

      LlirNodeIterator*  postInc();

      void preInc();

      LlirNodeIterator*  postDec();

      void preDec();

      shared_ptr<LlirNode>& operator*();

      shared_ptr<LlirNode> *operator->();

    private:
      LlirSequence::SeqIterator m_iterator;
    };


  class LlirSequenceConstIterator : public LlirNodeConstIterator
    {
    public:
      LlirSequenceConstIterator();
      LlirSequenceConstIterator(LlirSequence::SeqConstIterator);
      LlirSequenceConstIterator(const LlirSequenceConstIterator &rhs);
      LlirSequenceConstIterator& operator=(const LlirSequenceConstIterator &);
      ~LlirSequenceConstIterator(){}

      bool equalTo(const LlirNodeConstIterator &rhs) const;

      LlirNodeConstIterator*  postInc();

      void preInc();

      LlirNodeConstIterator*  postDec();

      void preDec();

      const shared_ptr<LlirNode>& operator*();

      const shared_ptr<LlirNode> *operator->();

    private:
      LlirSequence::SeqConstIterator m_iterator;
    };


  //--------------------------------------------------
  //Null Iterator
  //--------------------------------------------------

  // To be used in the following non-aggregate nodes
  // LlirInstruction, LlirLineControlDirective 
  // and LlirAsmDirective

  class LlirNullIterator : public LlirNodeIterator
    {
    public:

      LlirNullIterator() : LlirNodeIterator()
	{}

      LlirNullIterator(const LlirNullIterator &rhs)
	: LlirNodeIterator(rhs)
	{}

      LlirNullIterator& operator=(const LlirNullIterator &)
      { return *this; }

      ~LlirNullIterator()
	{}


      LlirNodeIterator* postInc()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return m_dummyIter;
	}

      void preInc()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	}

      LlirNodeIterator* postDec()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return m_dummyIter;
	}

      void preDec()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	}

      shared_ptr<LlirNode>& operator*()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return m_dummy;
	}

      shared_ptr<LlirNode> *operator->()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return &m_dummy;
	}

    private:

      shared_ptr<LlirNode> m_dummy;
      LlirNodeIterator* m_dummyIter;

      bool equalTo(const LlirNodeIterator &rhs) const
	{
	  return true;
	}

    };

  //--------------------------------------------------
  //Null Const Iterator
  //--------------------------------------------------

  class LlirNullConstIterator : public LlirNodeConstIterator
    {

    public:

      LlirNullConstIterator()
	: LlirNodeConstIterator()
	{}

      LlirNullConstIterator(const LlirNullConstIterator &rhs)
	: LlirNodeConstIterator(rhs)
        {}

      LlirNullConstIterator& operator=(const LlirNullConstIterator &)
      { return *this; }

      ~LlirNullConstIterator()
	{}

      void preInc()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	}

      LlirNodeConstIterator* postInc()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return m_dummyCIter;
	}

      void preDec()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	}

      LlirNodeConstIterator* postDec()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return m_dummyCIter;
	}

      const shared_ptr<LlirNode>& operator*()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return m_dummy;
	}
      const shared_ptr<LlirNode> *operator->()
	{
	  throw LLIR_INTERNAL_EXCEPTION("Operation on Null Iterator");
	  return &m_dummy;
	}


    private:

      const shared_ptr<LlirNode> m_dummy;
      LlirNodeConstIterator* m_dummyCIter;

      bool equalTo(const LlirNodeConstIterator &rhs) const
	{
	  return true;
	}
    };




}  // namespace Llir



#endif
