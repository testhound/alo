#include <iostream>
using namespace std;

#include <LlirVisitor.h>
#include <LlirException.h>

#include "OctaveNode.h"
#include "OctaveVisitor.h"
#include "OctaveSymbol.h"
#include "OctaveOperand.h"

namespace Llir
{
  //--------------------
  // LlirOctaveAsmDirective
  //--------------------

  LlirOctaveAsmDirective::LlirOctaveAsmDirective(unsigned int lineNum,
						 unsigned int srcLineNum,
						 const char* srcFileName) 
    : LlirAsmDirective(lineNum,
		       srcLineNum,
		       srcFileName)
  {}


  LlirOctaveAsmDirective::LlirOctaveAsmDirective(const LlirOctaveAsmDirective& rhs) : 
    LlirAsmDirective(rhs)
  {}

  LlirOctaveAsmDirective&
  LlirOctaveAsmDirective::operator=(const LlirOctaveAsmDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirAsmDirective::operator=(rhs);
    return *this; 
  }

  void
  LlirOctaveAsmDirective::addLlirNode(shared_ptr<LlirNode>, shared_ptr<LlirNode>)
  {
    throw LLIR_INTERNAL_EXCEPTION("accept error");
  }

  LlirNode::Iterator
  LlirOctaveAsmDirective::begin()
  {
    return (LlirNode::Iterator(new LlirNullIterator()));
  }

  LlirNode::Iterator
  LlirOctaveAsmDirective::end()
  {
    return (LlirNode::Iterator(new LlirNullIterator()));
  }

  LlirNode::ConstIterator
  LlirOctaveAsmDirective::begin() const
  {
    return (LlirNode::ConstIterator(new LlirNullConstIterator()));
  }


  LlirNode::ConstIterator
  LlirOctaveAsmDirective::end() const
  {
    return (LlirNode::ConstIterator(new LlirNullConstIterator()));
  }

  //--------------------
  // Align Directive
  //--------------------

  Align::Align(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName,
	       unsigned int alignSize) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName), 
    m_alignSize(alignSize)
  {}

  Align::Align(const Align& rhs) : LlirOctaveAsmDirective(rhs), m_alignSize(rhs.m_alignSize)
  {}

  Align &
  Align::operator=(const Align& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_alignSize = rhs.m_alignSize;
    return *this; 
  }

  unsigned int
  Align::getSize() const
  {
    return m_alignSize;
  }

  void Align::accept(Visitor &v) const
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
  Align::equalTo(const LlirNode &rhs) const
  {
    if(getSize() == (dynamic_cast<const Align &> (rhs)).getSize())
      return true;
    else
      return false;
  }

  //--------------------
  // Ascii Directive
  //--------------------

  Ascii::Ascii(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName,
	       const char *name) 
    : LlirOctaveAsmDirective(lineNum, 
			     srcLineNum, 
			     srcFileName), 
      m_asciiString(name)
  {}

  Ascii::Ascii(const Ascii& rhs) 
    : LlirOctaveAsmDirective(rhs), 
      m_asciiString(rhs.m_asciiString)
  {}

  Ascii &
  Ascii::operator=(const Ascii& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_asciiString = rhs.m_asciiString;
    return *this; 
  }

  const std::string &
  Ascii::getAsciiString() const
  {
    return m_asciiString;
  }

  void Ascii::accept(Visitor &v) const
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
  Ascii::equalTo(const LlirNode &rhs) const
  {
    if(getAsciiString() == (dynamic_cast<const Ascii &> (rhs)).getAsciiString())
      return true;
    else
      return false;
  }

  //--------------------
  // Label Directive
  //--------------------

  Label::Label(unsigned int lineNum,
		unsigned int srcLineNum,
		const char* srcFileName,
	       const char *name, const char* mangledName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName), 
    m_labelName(name),
    m_mangledName(mangledName),
    m_inSequence(false)
  {}

  Label::Label(const Label& rhs) : 
    LlirOctaveAsmDirective(rhs), 
    m_labelName(rhs.m_labelName),
    m_inSequence(rhs.m_inSequence)
  {}

  Label &
  Label::operator=(const Label& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_labelName = rhs.m_labelName;
    m_inSequence = rhs.m_inSequence;
    return *this; 
  }

  const std::string &
  Label::getLabelName() const
  {
    return m_labelName;
  }
  
  const std::string &
  Label::getMangledName() const
  {
    return m_mangledName;
  }

  void
  Label::setInSequence()
  {
    m_inSequence = true;
  }

  bool
  Label::isInSequence() const
  {
    return m_inSequence;
  }

  bool
  Label::isLabel() const
  {
    return true;
  }

  //-------------------
  // Local Label
  //-------------------


  LocalLabel::LocalLabel(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName,
			 const char *name, 
			 const char* mangledName) 
    : Label(lineNum, 
	    srcLineNum, 
	    srcFileName,
	    name, 
	    mangledName)
  {}

  LocalLabel::LocalLabel(const LocalLabel& rhs) : Label(rhs)
  {}

  LocalLabel &
  LocalLabel::operator=(const LocalLabel& rhs)
  {
    if(this == &rhs)
      return *this;

    Label::operator=(rhs);
    return *this; 
  }

  void LocalLabel::accept(Visitor &v) const
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
  LocalLabel::equalTo(const LlirNode &rhs) const
  {
    if(getLabelName() == (dynamic_cast<const LocalLabel &> (rhs)).getLabelName())
      return true;
    else
      return false;
  }

  

  //-------------------
  // FileScope Label
  //-------------------


  FileScopeLabel::FileScopeLabel(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName,
				 const char *name, 
				 const char* mangledName) 
    : Label(lineNum, 
	    srcLineNum,
	    srcFileName,
	    name, 
	    mangledName)
  {}

  FileScopeLabel::FileScopeLabel(const FileScopeLabel& rhs) : Label(rhs)
  {}

  FileScopeLabel &
  FileScopeLabel::operator=(const FileScopeLabel& rhs)
  {
    if(this == &rhs)
      return *this;

    Label::operator=(rhs);
    return *this; 
  }

  void FileScopeLabel::accept(Visitor &v) const
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
  FileScopeLabel::equalTo(const LlirNode &rhs) const
  {
    if(getLabelName() == (dynamic_cast<const FileScopeLabel &> (rhs)).getLabelName())
      return true;
    else
      return false;
  }


  //-------------------
  // Global Label
  //-------------------


  GlobalLabel::GlobalLabel(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName,
			   const char *name, 
			   const char* mangledName) 
    : Label(lineNum, 
	    srcLineNum,
	    srcFileName,
	    name,
	    mangledName)
  {}

  GlobalLabel::GlobalLabel(const GlobalLabel& rhs) 
    : Label(rhs)
  {}

  GlobalLabel &
  GlobalLabel::operator=(const GlobalLabel& rhs)
  {
    if(this == &rhs)
      return *this;

    Label::operator=(rhs);
    return *this; 
  }

  void GlobalLabel::accept(Visitor &v) const
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
  GlobalLabel::equalTo(const LlirNode &rhs) const
  {
    if(getLabelName() == (dynamic_cast<const GlobalLabel &> (rhs)).getLabelName())
      return true;
    else
      return false;
  }


  //--------------------
  // List Directive
  //--------------------

  List::List(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  List::List(const List& rhs) 
    : LlirOctaveAsmDirective(rhs)
  {}

  List &
  List::operator=(const List& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    return *this; 
  }

  void List::accept(Visitor &v) const
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
  List::equalTo(const LlirNode &rhs) const
  {
    return true;
  }

  //--------------------
  // NoList Directive
  //--------------------

  NoList::NoList(unsigned int lineNum,
		 unsigned int srcLineNum,
		 const char* srcFileName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  NoList::NoList(const NoList& rhs) 
    : LlirOctaveAsmDirective(rhs)
  {}

  NoList &
  NoList::operator=(const NoList& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    return *this; 
  }

  void NoList::accept(Visitor &v) const
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
  NoList::equalTo(const LlirNode &rhs) const
  {
    return true;
  }

  //--------------------
  // EndMacro Directive
  //--------------------

  EndMacro::EndMacro(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  EndMacro::EndMacro(const EndMacro& rhs) : LlirOctaveAsmDirective(rhs)
  {}

  EndMacro &
  EndMacro::operator=(const EndMacro& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    return *this; 
  }

  void EndMacro::accept(Visitor &v) const
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
  EndMacro::equalTo(const LlirNode &rhs) const
  {
    return true;
  }

  //--------------------
  // Ref Directive
  //--------------------

  Ref::Ref(unsigned int lineNum,
	   unsigned int srcLineNum,
	   const char* srcFileName,
	   const char *name) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName), 
      m_labelName(name)
  {}

  Ref::Ref(const Ref& rhs) : LlirOctaveAsmDirective(rhs), m_labelName(rhs.m_labelName)
  {}

  Ref &
  Ref::operator=(const Ref& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_labelName = rhs.m_labelName;
    return *this; 
  }

  const std::string &
  Ref::getLabel() const
  {
    return m_labelName;
  }

  void Ref::accept(Visitor &v) const
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
  Ref::equalTo(const LlirNode &rhs) const
  {
    if(getLabel() == (dynamic_cast<const Ref &> (rhs)).getLabel())
      return true;
    else
      return false;
  }

  //--------------------
  // EndBlock Directive
  //--------------------

  EndBlock::EndBlock(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName,
		     const char *name) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName), 
      m_blockName(name)
  {}

  EndBlock::EndBlock(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName), 
    m_blockName("")
  {}

  EndBlock::EndBlock(const EndBlock& rhs) 
    : LlirOctaveAsmDirective(rhs), 
      m_blockName(rhs.m_blockName)
  {}

  EndBlock &
  EndBlock::operator=(const EndBlock& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_blockName = rhs.m_blockName;
    return *this; 
  }

  const std::string &
  EndBlock::getName() const
  {
    return m_blockName;
  }

  //--------------------------
  // UnNamedEndBlock Directive
  //--------------------------

  UnNamedEndBlock::UnNamedEndBlock(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName) 
    : EndBlock(lineNum,
	       srcLineNum,
	       srcFileName)
  {}

  UnNamedEndBlock::UnNamedEndBlock(const UnNamedEndBlock& rhs) 
    : EndBlock(rhs)
  {}

  UnNamedEndBlock &
  UnNamedEndBlock::operator=(const UnNamedEndBlock& rhs)
  {
    if(this == &rhs)
      return *this;

    EndBlock::operator=(rhs);
    return *this; 
  }

  void UnNamedEndBlock::accept(Visitor &v) const
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
  UnNamedEndBlock::equalTo(const LlirNode &rhs) const
  {
    if(getName() == (dynamic_cast<const UnNamedEndBlock &> (rhs)).getName())
      return true;
    else
      return false;
  }

  //--------------------------
  // NamedEndBlock Directive
  //--------------------------

  NamedEndBlock::NamedEndBlock(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       const char *blockName) : 
    EndBlock(lineNum,
	     srcLineNum,
	     srcFileName,
	     blockName)
  {}

  NamedEndBlock::NamedEndBlock(const NamedEndBlock& rhs) 
    : EndBlock(rhs)
  {}

  NamedEndBlock &
  NamedEndBlock::operator=(const NamedEndBlock& rhs)
  {
    if(this == &rhs)
      return *this;

    EndBlock::operator=(rhs);
    return *this; 
  }

  void NamedEndBlock::accept(Visitor &v) const
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
  NamedEndBlock::equalTo(const LlirNode &rhs) const
  {
    if(getName() == (dynamic_cast<const NamedEndBlock &> (rhs)).getName())
      return true;
    else
      return false;
  }

  //--------------------
  // Section Directive
  //--------------------

  Section::Section(unsigned int lineNum, 
		     unsigned int srcLineNum,
		     const char* srcFileName,
		   const char *name, 
		   unsigned int sectionSize) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName), 
      m_sectionName(name), 
      m_sectionSize(sectionSize)
  {}

  Section::Section(const Section& rhs) : 
    LlirOctaveAsmDirective(rhs), 
    m_sectionName(rhs.m_sectionName),
    m_sectionSize(rhs.m_sectionSize)
  {}

  Section &
  Section::operator=(const Section& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_sectionName = rhs.m_sectionName;
    m_sectionSize = rhs.m_sectionSize;
    return *this; 
  }

  const std::string &
  Section::getName() const
  {
    return m_sectionName;
  }

  unsigned int
  Section::getSize() const
  {
    return m_sectionSize;
  }

  //--------------------------
  // Text Directive
  //--------------------------

  Text::Text(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName) 
    : Section(lineNum, 
	      srcLineNum,
	      srcFileName,
	      ".text", 0)
  {}

  Text::Text(const Text& rhs) : Section(rhs)
  {}

  Text &
  Text::operator=(const Text& rhs)
  {
    if(this == &rhs)
      return *this;

    Section::operator=(rhs);
    return *this; 
  }

  void Text::accept(Visitor &v) const
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
  Text::equalTo(const LlirNode &rhs) const
  {
    return true;
  }

  //--------------------------
  // Data Directive
  //--------------------------

  Data::Data(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName) 
    : Section(lineNum, 
	      srcLineNum,
	      srcFileName,
	      ".data", 0)
  {}

  Data::Data(const Data& rhs) : Section(rhs)
  {}

  Data &
  Data::operator=(const Data& rhs)
  {
    if(this == &rhs)
      return *this;

    Section::operator=(rhs);
    return *this; 
  }

  void Data::accept(Visitor &v) const
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
  Data::equalTo(const LlirNode &rhs) const
  {
    return true;
  }

  //--------------------------
  // Comm Directive
  //--------------------------

  Comm::Comm(unsigned int lineNum, 
	     unsigned int srcLineNum,
	     const char* srcFileName,
	     const char *name, 
	     unsigned int size) : 
    Section(lineNum, 
	    srcLineNum,
	    srcFileName, 
	    name,
	    size)
  {}

  Comm::Comm(const Comm& rhs) : Section(rhs)
  {}

  Comm &
  Comm::operator=(const Comm& rhs)
  {
    if(this == &rhs)
      return *this;

    Section::operator=(rhs);
    return *this; 
  }

  void Comm::accept(Visitor &v) const
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
  Comm::equalTo(const LlirNode &rhs) const
  {
    Comm temp = dynamic_cast<const Comm &> (rhs);

    return ((getName() == temp.getName()) 
	    && (getSize() == temp.getSize()));
  }

  //--------------------------
  // Lcomm Directive
  //--------------------------

  Lcomm::Lcomm(unsigned int lineNum, 
	       unsigned int srcLineNum,
	       const char* srcFileName,
	       const char *name, 
	       unsigned int size) : 
    Section(lineNum, 
	    srcLineNum,
	    srcFileName, 
	    name,
	    size)
  {}

  Lcomm::Lcomm(const Lcomm& rhs) : Section(rhs)
  {}

  Lcomm &
  Lcomm::operator=(const Lcomm& rhs)
  {
    if(this == &rhs)
      return *this;

    Section::operator=(rhs);
    return *this; 
  }

  void Lcomm::accept(Visitor &v) const
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
  Lcomm::equalTo(const LlirNode &rhs) const
  {
    Lcomm temp = dynamic_cast<const Lcomm &> (rhs);

    return ((getName() == temp.getName()) 
	    && (getSize() == temp.getSize()));
  }

  //--------------------------
  // NamedSection Directive
  //--------------------------

  NamedSection::NamedSection(unsigned int lineNum, 
			     unsigned int srcLineNum,
			     const char* srcFileName,
			     const char *name) : 
    Section(lineNum, 
	    srcLineNum,
	    srcFileName, 
	    name,
	    0)
  {}

  NamedSection::NamedSection(const NamedSection& rhs) : Section(rhs)
  {}

  NamedSection &
  NamedSection::operator=(const NamedSection& rhs)
  {
    if(this == &rhs)
      return *this;

    Section::operator=(rhs);
    return *this; 
  }

  void NamedSection::accept(Visitor &v) const
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
  NamedSection::equalTo(const LlirNode &rhs) const
  {
    NamedSection temp = dynamic_cast<const NamedSection &> (rhs);

    return ((getName() == temp.getName()) 
	    && (getSize() == temp.getSize()));
  }

  //--------------------------
  // Datum
  //--------------------------

  Datum::Datum(shared_ptr<const LlirExpr> datum, 
	       unsigned int repeatCount) 
    : m_datum(datum), 
      m_repeatCount(repeatCount)
  {}

  Datum::Datum(const Datum& rhs) : m_datum(rhs.m_datum), m_repeatCount(rhs.m_repeatCount)
  {}

  Datum &
  Datum::operator=(const Datum& rhs)
  {
    if(this == &rhs)
      return *this;

    m_datum = rhs.m_datum; 
    m_repeatCount = rhs.m_repeatCount;
    return *this; 
  }

  shared_ptr<const LlirExpr>
  Datum::getDatum() const
  {
    return m_datum;
  }

  unsigned int
  Datum::getRepCount() const
  {
    return m_repeatCount;
  }

  //--------------------------
  // AllocMemoryDirective
  //--------------------------

  AllocMemoryDirective::AllocMemoryDirective(unsigned int lineNum,
					     unsigned int srcLineNum,
					     const char* srcFileName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  AllocMemoryDirective::AllocMemoryDirective(const AllocMemoryDirective& rhs) : 
    LlirOctaveAsmDirective(rhs), 
    m_datumList(rhs.m_datumList)
  {}

  AllocMemoryDirective &
  AllocMemoryDirective::operator=(const AllocMemoryDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_datumList = rhs.m_datumList;
    return *this; 
  }

  void
  AllocMemoryDirective::addDatum(shared_ptr<Datum> d)
  {
    m_datumList.push_back(d);
  }

  AllocMemoryDirective::Iterator
  AllocMemoryDirective::datumBegin()
  {
    return (m_datumList.begin());
  }

  AllocMemoryDirective::Iterator
  AllocMemoryDirective::datumEnd()
  {
    return (m_datumList.end());
  }

  AllocMemoryDirective::ConstIterator
  AllocMemoryDirective::datumBegin() const
  {
    return (m_datumList.begin());
  }


  AllocMemoryDirective::ConstIterator
  AllocMemoryDirective::datumEnd() const
  {
    return (m_datumList.end());
  }

  bool
  AllocMemoryDirective::equalTo(const LlirNode &rhs) const
  {
    const AllocMemoryDirective &rhsDirective = dynamic_cast<const AllocMemoryDirective &> (rhs);

    if (m_datumList.size() != rhsDirective.m_datumList.size())
      return false;

    AllocMemoryDirective::ConstIterator thisIterator = this->datumBegin();
    AllocMemoryDirective::ConstIterator rhsIterator = rhsDirective.datumBegin();

    for (; thisIterator != datumEnd(); thisIterator++, rhsIterator++)
      {
	if (*(*thisIterator) != *(*rhsIterator))
	  return false;
      }


    return true;
  }

  //--------------------------
  // Byte
  //--------------------------

  Byte::Byte(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName) 
    : AllocMemoryDirective(lineNum,
			   srcLineNum,
			   srcFileName)
  {}

  Byte::Byte(const Byte& rhs) : AllocMemoryDirective(rhs)
  {}

  Byte &
  Byte::operator=(const Byte& rhs)
  {
    if(this == &rhs)
      return *this;

    AllocMemoryDirective::operator=(rhs);
    return *this; 
  }

  void Byte::accept(Visitor &v) const
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

  //--------------------------
  // Word
  //--------------------------

  Word::Word(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName) 
    : AllocMemoryDirective(lineNum,
			   srcLineNum,
			   srcFileName)
  {}

  Word::Word(const Word& rhs) : AllocMemoryDirective(rhs)
  {}

  Word &
  Word::operator=(const Word& rhs)
  {
    if(this == &rhs)
      return *this;

    AllocMemoryDirective::operator=(rhs);
    return *this; 
  }

  void Word::accept(Visitor &v) const
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

  //--------------------------
  // HalfWord
  //--------------------------

  HalfWord::HalfWord(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName) 
    : AllocMemoryDirective(lineNum,
			   srcLineNum,
			   srcFileName)
  {}

  HalfWord::HalfWord(const HalfWord& rhs) : AllocMemoryDirective(rhs)
  {}

  HalfWord &
  HalfWord::operator=(const HalfWord& rhs)
  {
    if(this == &rhs)
      return *this;

    AllocMemoryDirective::operator=(rhs);
    return *this; 
  }

  void HalfWord::accept(Visitor &v) const
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

  //--------------------------
  // OrgDirective
  //--------------------------

  OrgDirective::OrgDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName,
			     unsigned int numBytes) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_numBytes(numBytes)
  {}

  OrgDirective::OrgDirective(const OrgDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_numBytes(rhs.m_numBytes)
  {}

  OrgDirective &
  OrgDirective::operator=(const OrgDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_numBytes = rhs.m_numBytes;
    return *this; 
  }

  unsigned int
  OrgDirective::getNumBytes() const
  {
    return (m_numBytes);
  }

  //--------------------------
  // Org
  //--------------------------

  Org::Org(unsigned int lineNum,
	   unsigned int srcLineNum,
	   const char* srcFileName,
	   unsigned int numBytes) 
    : OrgDirective(lineNum, 
		   srcLineNum,
		   srcFileName,
		   numBytes)
  {}

  Org::Org(const Org& rhs) : OrgDirective(rhs)
  {}

  Org &
  Org::operator=(const Org& rhs)
  {
    if(this == &rhs)
      return *this;

    OrgDirective::operator=(rhs);
    return *this; 
  }

  bool
  Org::equalTo(const LlirNode &rhs) const
  {
    Org temp = dynamic_cast<const Org &> (rhs);

    return (getNumBytes() == temp.getNumBytes());
  }

  void Org::accept(Visitor &v) const
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

  //--------------------------
  // Org
  //--------------------------

  OrgWithFillValue::OrgWithFillValue(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName,
				     unsigned int numBytes, 
				     unsigned int fillValue) : 
    OrgDirective(lineNum, 
		 srcLineNum,
		 srcFileName,
		 numBytes),
    m_fillValue(fillValue)
  {}

  OrgWithFillValue::OrgWithFillValue(const OrgWithFillValue& rhs) : 
    OrgDirective(rhs),
    m_fillValue(rhs.m_fillValue)
  {}

  OrgWithFillValue &
  OrgWithFillValue::operator=(const OrgWithFillValue& rhs)
  {
    if(this == &rhs)
      return *this;

    OrgDirective::operator=(rhs);
    m_fillValue = rhs.m_fillValue;
    return *this; 
  }

  bool
  OrgWithFillValue::equalTo(const LlirNode &rhs) const
  {
    OrgWithFillValue temp = dynamic_cast<const OrgWithFillValue &> (rhs);

    return ((getNumBytes() == temp.getNumBytes())
	    && (getFillValue() == temp.getFillValue()));
  }

  void OrgWithFillValue::accept(Visitor &v) const
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

  unsigned int
  OrgWithFillValue::getFillValue() const
  {
    return m_fillValue;
  }

  //--------------------------
  // StructEndDirective
  //--------------------------

  StructEndDirective::StructEndDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char *srcFileName) 
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  StructEndDirective::StructEndDirective(const StructEndDirective& rhs) : 
    LlirOctaveAsmDirective(rhs)
  {}

  StructEndDirective &
  StructEndDirective::operator=(const StructEndDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    return *this; 
  }

  bool
  StructEndDirective::equalTo(const LlirNode &rhs) const
  {
    return true;
  }

  void StructEndDirective::accept(Visitor &v) const
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


  //--------------------------
  // StructBeginDirective
  //--------------------------

  StructBeginDirective::StructBeginDirective(unsigned int lineNum,
					     unsigned int srcLineNum,
					     const char* srcFileName,
					     const char *name) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_structName(name)
  {}

  StructBeginDirective::StructBeginDirective(const StructBeginDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_structName(rhs.m_structName)
  {}

  StructBeginDirective &
  StructBeginDirective::operator=(const StructBeginDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_structName = rhs.m_structName;
    return *this; 
  }

  bool
  StructBeginDirective::equalTo(const LlirNode &rhs) const
  {
    StructBeginDirective temp = dynamic_cast<const StructBeginDirective &> (rhs);

    return (getName() == temp.getName());
  }

  const std::string&
  StructBeginDirective::getName() const
  {
    return m_structName;
  }

  void StructBeginDirective::accept(Visitor &v) const
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

  //--------------------------
  // UnmapDirective
  //--------------------------

  UnmapDirective::UnmapDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName,
				 const char *name) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_mapName(name)
  {}

  UnmapDirective::UnmapDirective(const UnmapDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_mapName(rhs.m_mapName)
  {}

  UnmapDirective &
  UnmapDirective::operator=(const UnmapDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_mapName = rhs.m_mapName;
    return *this; 
  }

  bool
  UnmapDirective::equalTo(const LlirNode &rhs) const
  {
    UnmapDirective temp = dynamic_cast<const UnmapDirective &> (rhs);

    return (getName() == temp.getName());
  }

  const std::string&
  UnmapDirective::getName() const
  {
    return m_mapName;
  }

  void UnmapDirective::accept(Visitor &v) const
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

  //--------------------------
  // MapDirective
  //--------------------------

  MapDirective::MapDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName,
			     const char *mapPath, 
			     const char *mapName,
			     shared_ptr<MapSymbol> mapSymbol) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_mapPath(mapPath),
    m_mapName(mapName),
    m_mapSymbol(mapSymbol)
  {}

  MapDirective::MapDirective(const MapDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_mapPath(m_mapPath),
    m_mapName(m_mapName),
    m_mapSymbol(m_mapSymbol)
  {}

  MapDirective &
  MapDirective::operator=(const MapDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_mapPath = m_mapPath;
    m_mapName = rhs.m_mapName;
    m_mapSymbol = rhs.m_mapSymbol;
    return *this; 
  }

  bool
  MapDirective::equalTo(const LlirNode &rhs) const
  {
    MapDirective temp = dynamic_cast<const MapDirective &> (rhs);

    return ((getMapName() == temp.getMapName())
	    && (getMapPath() == temp.getMapPath())
	    && (*(getMappedSymbol()) == *(temp.getMappedSymbol())));
  }

  const std::string&
  MapDirective::getMapName() const
  {
    return m_mapName;
  }

  const std::string&
  MapDirective::getMapPath() const
  {
    return m_mapPath;
  }

  shared_ptr<const MapSymbol>
  MapDirective::getMappedSymbol() const
  {
    return m_mapSymbol;
  }

  void MapDirective::accept(Visitor &v) const
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




  //--------------------------
  // ScopedMapDirective
  //--------------------------

  ScopedMapDirective::ScopedMapDirective(unsigned int lineNum, 
					 unsigned int srcLineNum,
					 const char* srcFileName,
					 const char *mapPath, 
					 const char *mapName,
					 shared_ptr<MapSymbol> mapSymbol) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_mapPath(mapPath),
    m_mapName(mapName),
    m_mapSymbol(mapSymbol)
  {}

  ScopedMapDirective::ScopedMapDirective(const ScopedMapDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_mapPath(m_mapPath),
    m_mapName(m_mapName),
    m_mapSymbol(m_mapSymbol)
  {}

  ScopedMapDirective &
  ScopedMapDirective::operator=(const ScopedMapDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_mapPath = m_mapPath;
    m_mapName = rhs.m_mapName;
    m_mapSymbol = rhs.m_mapSymbol;
    return *this; 
  }

  bool
  ScopedMapDirective::equalTo(const LlirNode &rhs) const
  {
    ScopedMapDirective temp = dynamic_cast<const ScopedMapDirective &> (rhs);

    return ((getMapName() == temp.getMapName())
	    && (getMapPath() == temp.getMapPath())
	    && (*(getMappedSymbol()) == *(temp.getMappedSymbol())));
  }

  const std::string&
  ScopedMapDirective::getMapName() const
  {
    return m_mapName;
  }

  const std::string&
  ScopedMapDirective::getMapPath() const
  {
    return m_mapPath;
  }

  shared_ptr<const MapSymbol>
  ScopedMapDirective::getMappedSymbol() const
  {
    return m_mapSymbol;
  }

  void ScopedMapDirective::accept(Visitor &v) const
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



  //--------------------------
  // ElementDirective
  //--------------------------

  ElementDirective::ElementDirective(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName,
				     shared_ptr<Element> elemDecl) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_elementDecl(elemDecl)
  {}

  ElementDirective::ElementDirective(const ElementDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_elementDecl(rhs.m_elementDecl)
  {}

  ElementDirective &
  ElementDirective::operator=(const ElementDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_elementDecl = rhs.m_elementDecl;
    return *this; 
  }

  bool
  ElementDirective::equalTo(const LlirNode &rhs) const
  {
    ElementDirective temp = dynamic_cast<const ElementDirective &> (rhs);

    return (*(getElementDecl()) == *(temp.getElementDecl()));
  }

  shared_ptr<const Element>
  ElementDirective::getElementDecl() const
  {
    return m_elementDecl;
  }

  void ElementDirective::accept(Visitor &v) const
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




  //--------------------------
  // MeetsDirective
  //--------------------------

  MeetsDirective::MeetsDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName,
				 const char* testedPath, 
				 const char* referencePath) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_testedPath(testedPath),
    m_referencePath(referencePath)
  {}

  MeetsDirective::MeetsDirective(const MeetsDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_testedPath(rhs.m_testedPath),
    m_referencePath(rhs.m_referencePath)
  {}

  MeetsDirective &
  MeetsDirective::operator=(const MeetsDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);

    m_testedPath = rhs.m_testedPath;
    m_referencePath = rhs.m_referencePath;

    return *this; 
  }

  const string& 
  MeetsDirective::getTestedPath() const
  {
    return m_testedPath;
  }

  const string& 
  MeetsDirective::getReferencePath() const
  {
    return m_referencePath;
  }

  bool
  MeetsDirective::equalTo(const LlirNode &rhs) const
  {
    MeetsDirective temp = dynamic_cast<const MeetsDirective &> (rhs);

    return ((m_testedPath == temp.m_testedPath) &&
	    (m_referencePath == temp.m_referencePath));
  }

  void MeetsDirective::accept(Visitor &v) const
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






  //--------------------------
  // AssertDirective
  //--------------------------

  AssertDirective::AssertDirective(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   shared_ptr<const LlirOperand> expr,
				   const char* assertMsg) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_expr(expr),
    m_assertMessage(assertMsg)
  {}

  AssertDirective::AssertDirective(const AssertDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_expr(rhs.m_expr),
    m_assertMessage(rhs.m_assertMessage)
  {}

  AssertDirective &
  AssertDirective::operator=(const AssertDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);

    m_expr = rhs.m_expr;
    m_assertMessage = rhs.m_assertMessage;

    return *this; 
  }

  shared_ptr<const LlirOperand>
  AssertDirective::getExpr() const
  {
    return m_expr;
  }

  const string& 
  AssertDirective::getAssertMsg() const
  {
    return m_assertMessage;
  }

  bool
  AssertDirective::equalTo(const LlirNode &rhs) const
  {
    AssertDirective temp = dynamic_cast<const AssertDirective &> (rhs);

    return ((*m_expr == *temp.m_expr) &&
	    (m_assertMessage == temp.m_assertMessage));
  }

  void AssertDirective::accept(Visitor &v) const
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




  //--------------------------
  // WarningDirective
  //--------------------------

  WarningDirective::WarningDirective(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName,
				     const char* warningMsg) :
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_warningMessage(warningMsg)
  {}

  WarningDirective::WarningDirective(const WarningDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_warningMessage(rhs.m_warningMessage)
  {}

  WarningDirective &
  WarningDirective::operator=(const WarningDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_warningMessage = rhs.m_warningMessage;
    return *this; 
  }

  const string& 
  WarningDirective::getWarningMsg() const
  {
    return m_warningMessage;
  }

  bool
  WarningDirective::equalTo(const LlirNode &rhs) const
  {
    WarningDirective temp = dynamic_cast<const WarningDirective &> (rhs);

    return (m_warningMessage == temp.m_warningMessage);
	    
  }

  void WarningDirective::accept(Visitor &v) const
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





  //--------------------------
  // ErrorDirective
  //--------------------------

  ErrorDirective::ErrorDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName,
				 const char* msg) : 
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_errorMessage(msg)
  {}

  ErrorDirective::ErrorDirective(const ErrorDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_errorMessage(rhs.m_errorMessage)
  {}

  ErrorDirective &
  ErrorDirective::operator=(const ErrorDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_errorMessage = rhs.m_errorMessage;
    return *this; 
  }

  const string& 
  ErrorDirective::getErrorMsg() const
  {
    return m_errorMessage;
  }

  bool
  ErrorDirective::equalTo(const LlirNode &rhs) const
  {
    ErrorDirective temp = dynamic_cast<const ErrorDirective &> (rhs);

    return (m_errorMessage == temp.m_errorMessage);
  }

  void ErrorDirective::accept(Visitor &v) const
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



  //--------------------------
  // SregisterDirective
  //--------------------------

  SregisterDirective::SregisterDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName,
					 const char *name, 
					 shared_ptr<const Register> reg,
					 AbstractSymReg::SymRegConstraint symRegConstraint,
					 shared_ptr<const Register> constraintRegRange) :
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_symRegName(name),
    m_reg(reg),
    m_symRegConstraint(symRegConstraint),
    m_constraintRegRange(constraintRegRange)
  {}

  SregisterDirective::SregisterDirective(const SregisterDirective& rhs) : 
    LlirOctaveAsmDirective(rhs),
    m_symRegName(rhs.m_symRegName),
    m_reg(rhs.m_reg),
    m_symRegConstraint(rhs.m_symRegConstraint),
    m_constraintRegRange(rhs.m_constraintRegRange)
  {}

  SregisterDirective &
  SregisterDirective::operator=(const SregisterDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_symRegName = rhs.m_symRegName;
    m_reg = rhs.m_reg;
    m_symRegConstraint = rhs.m_symRegConstraint;
    m_constraintRegRange = rhs.m_constraintRegRange;

    return *this; 
  }

  const std::string&
  SregisterDirective::getSymRegName() const
  {
    return m_symRegName;
  }

  shared_ptr<const Register>
  SregisterDirective::getRegister() const
  {
    return m_reg;
  }

  AbstractSymReg::SymRegConstraint 
  SregisterDirective::getBeginRegConstraint() const
  {
    return m_symRegConstraint;
  }

  shared_ptr<const Register>
  SregisterDirective::getConstraintRegRange() const
  {
    return m_constraintRegRange;
  }

  bool
  SregisterDirective::equalTo(const LlirNode &rhs) const
  {
    SregisterDirective temp = dynamic_cast<const SregisterDirective &> (rhs);

    return ((m_symRegName == temp.m_symRegName)
	    && ((*m_reg) == *(temp.m_reg)));
  }

  void SregisterDirective::accept(Visitor &v) const
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



  //--------------------
  // Global Directive
  //--------------------


  GlobalDirective::GlobalDirective(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   shared_ptr<const GlobalRegisterList> globalReg_List,
				   shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
				   shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
				   shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
				   shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
				   shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
				   shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
				   shared_ptr<const RegLnksListToSIO> lnkToSIO_List) :
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_globalReg_List(globalReg_List),
    m_lnkToSPRAM_List(lnkToSPRAM_List),
    m_lnkToLocked_SPRAM_List(lnkToLocked_SPRAM_List),
    m_lnkToSRAM_List(lnkToSRAM_List),
    m_lnkToSDRAM_List(lnkToSDRAM_List),
    m_lnkToCCRAM_List(lnkToCCRAM_List),
    m_lnkToLocked_CCRAM_List(lnkToLocked_CCRAM_List),
    m_lnkToSIO_List(lnkToSIO_List)
  {}
  
  GlobalDirective::GlobalDirective(const GlobalDirective& rhs) :
    LlirOctaveAsmDirective(rhs),
    m_globalReg_List(rhs.m_globalReg_List),
    m_lnkToSPRAM_List(rhs.m_lnkToSPRAM_List),
    m_lnkToLocked_SPRAM_List(rhs.m_lnkToLocked_SPRAM_List),
    m_lnkToSRAM_List(rhs.m_lnkToSRAM_List),
    m_lnkToSDRAM_List(rhs.m_lnkToSDRAM_List),
    m_lnkToCCRAM_List(rhs.m_lnkToCCRAM_List),
    m_lnkToLocked_CCRAM_List(rhs.m_lnkToLocked_CCRAM_List),
    m_lnkToSIO_List(rhs.m_lnkToSIO_List)
  {}

  GlobalDirective::GlobalDirective& 
  GlobalDirective::operator=(const GlobalDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);

    m_globalReg_List = rhs.m_globalReg_List;
    m_lnkToSPRAM_List = rhs.m_lnkToSPRAM_List;
    m_lnkToLocked_SPRAM_List = rhs.m_lnkToLocked_SPRAM_List;
    m_lnkToSRAM_List = rhs.m_lnkToSRAM_List;
    m_lnkToSDRAM_List = rhs.m_lnkToSDRAM_List;
    m_lnkToCCRAM_List = rhs.m_lnkToCCRAM_List;
    m_lnkToLocked_CCRAM_List = rhs.m_lnkToLocked_CCRAM_List;
    m_lnkToSIO_List = rhs.m_lnkToSIO_List;

    return *this; 

  }
  
  GlobalDirective::~GlobalDirective()
  {}

  bool 
  GlobalDirective::isGlobalReg(unsigned int regNum) const
  {
    shared_ptr<const Register> reg = m_globalReg_List->getRegList()->getRegister(regNum);
    
    if(shared_dynamic_cast<const NullRegister>(reg))
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  bool 
  GlobalDirective::hasLinkToSPRAM(unsigned int regNum) const
  { 
    shared_ptr<const Register> reg;

    reg = m_lnkToSPRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSPRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSPRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  GlobalDirective::hasLinkToLockedSPRAM(unsigned int regNum) const
  { 
    shared_ptr<const Register> reg;

    reg = m_lnkToLocked_SPRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_SPRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_SPRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  GlobalDirective::hasLinkToSRAM(unsigned int regNum) const
  {
     shared_ptr<const Register> reg;

    reg = m_lnkToSRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  GlobalDirective::hasLinkToSDRAM(unsigned int regNum) const
  { 
     shared_ptr<const Register> reg;

    reg = m_lnkToSDRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSDRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSDRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  GlobalDirective::hasLinkToCCRAM(unsigned int regNum) const
  {    
    shared_ptr<const Register> reg;

    reg = m_lnkToCCRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToCCRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToCCRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;

  }

  bool 
  GlobalDirective::hasLinkToLockedCCRAM(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToLocked_CCRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_CCRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_CCRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  GlobalDirective::hasLinkToSIO(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToSIO_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSIO_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSIO_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }


  shared_ptr<const GlobalRegisterList> 
  GlobalDirective::getGlobalRegList() const
  {
    return m_globalReg_List;
  }

  shared_ptr<const RegLnksListToSPRAM> 
  GlobalDirective::getRegLnksListToSPRAM() const
  {
    return m_lnkToSPRAM_List;
  }
      
  shared_ptr<const RegLnksListToLockedSPRAM> 
  GlobalDirective::getRegLnksListToLockedSPRAM() const
  {
    return m_lnkToLocked_SPRAM_List;
  }
  
  shared_ptr<const RegLnksListToSRAM> 
  GlobalDirective::getRegLnksListToSRAM() const
  {
    return m_lnkToSRAM_List;
  }
  
  shared_ptr<const RegLnksListToSDRAM> 
  GlobalDirective::getRegLnksListToSDRAM() const
  {
    return m_lnkToSDRAM_List;
  }
  
  shared_ptr<const RegLnksListToCCRAM> 
  GlobalDirective::getRegLnksListToCCRAM() const
  {
    return m_lnkToCCRAM_List;
  }
  
  shared_ptr<const RegLnksListToLockedCCRAM> 
  GlobalDirective::getRegLnksListToLockedCCRAM() const
  {
    return m_lnkToLocked_CCRAM_List;
  }
  
  shared_ptr<const RegLnksListToSIO> 
  GlobalDirective::getRegLnksListToSIO() const
  {
    return m_lnkToSIO_List;
  }

  bool 
  GlobalDirective::equalTo(const LlirNode &rhs) const
  { 
    GlobalDirective rhsDir = dynamic_cast<const GlobalDirective &> (rhs);


    if(*m_globalReg_List         == *rhsDir.m_globalReg_List &&
       *m_lnkToSPRAM_List        == *rhsDir.m_lnkToSPRAM_List &&
       *m_lnkToLocked_SPRAM_List == *rhsDir.m_lnkToLocked_SPRAM_List &&
       *m_lnkToSRAM_List         == *rhsDir.m_lnkToSRAM_List &&
       *m_lnkToSDRAM_List        == *rhsDir.m_lnkToSDRAM_List &&
       *m_lnkToCCRAM_List        == *rhsDir.m_lnkToCCRAM_List &&
       *m_lnkToLocked_CCRAM_List == *rhsDir.m_lnkToLocked_CCRAM_List &&
       *m_lnkToSIO_List          == *rhsDir.m_lnkToSIO_List)
      {
	return true;
      }
    else
      {
	return false;
      }

    return false;
  }

  void 
  GlobalDirective::accept(Visitor& v) const
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



  //--------------------
  // EndEvhDirective
  //--------------------

  EndEvhDirective::EndEvhDirective(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   const char* label)
    : LlirOctaveAsmDirective(lineNum,			     
			     srcLineNum,
			     srcFileName),
      m_firstEntryPointLabel (shared_ptr<const LabelSymbol>
			      (new LabelSymbol(label, OctaveSymbol::GLOBAL)))
  {}

  EndEvhDirective::EndEvhDirective(const EndEvhDirective& rhs) 
    : LlirOctaveAsmDirective(rhs),
      m_firstEntryPointLabel(rhs.m_firstEntryPointLabel)
  {}

  EndEvhDirective&
  EndEvhDirective::operator=(const EndEvhDirective& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LlirOctaveAsmDirective::operator=(rhs);    
    m_firstEntryPointLabel = rhs.m_firstEntryPointLabel;

    return *this;
  }

  EndEvhDirective::~EndEvhDirective()
  {}

  shared_ptr<const LabelSymbol>
  EndEvhDirective::getFirstEntryPtLabel() const
  {
    return m_firstEntryPointLabel;
  }

  bool
  EndEvhDirective::equalTo(const LlirNode& rhs) const
  {
    const EndEvhDirective rhsDir
      = dynamic_cast<const EndEvhDirective&>(rhs);

    return (*m_firstEntryPointLabel == *rhsDir.getFirstEntryPtLabel());
  }

  void
  EndEvhDirective::accept(Visitor& v) const
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


  //--------------------
  // EndEntryDirective
  //--------------------

  EndEntryDirective::EndEntryDirective(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName,
				   const char* label)
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName),
      m_firstEntryPointLabel(shared_ptr<const LabelSymbol>(new LabelSymbol(label, OctaveSymbol::GLOBAL)))
  {}

  EndEntryDirective::EndEntryDirective(const EndEntryDirective& rhs)
    : LlirOctaveAsmDirective(rhs),
      m_firstEntryPointLabel(rhs.m_firstEntryPointLabel)
  {}

  EndEntryDirective&
  EndEntryDirective::operator=(const EndEntryDirective& rhs)
  {

    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_firstEntryPointLabel = rhs.m_firstEntryPointLabel;
    
    return *this;
  }

  EndEntryDirective::~EndEntryDirective()
  {}

  shared_ptr<const LabelSymbol>
  EndEntryDirective::getEvhLabel() const
  {
    return m_firstEntryPointLabel;
  }

  bool
  EndEntryDirective::equalTo(const LlirNode& rhs) const
  {
    const EndEntryDirective rhsDir = dynamic_cast<const EndEntryDirective&>(rhs);

    return (*m_firstEntryPointLabel == *(rhsDir.getEvhLabel()));
  }

  void
  EndEntryDirective::accept(Visitor& v) const
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



  //--------------------
  // PrototypeDirective
  //--------------------


  PrototypeDirective::PrototypeDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName,
					 shared_ptr<const LabelList> labelList,
					 shared_ptr<const ArgList> argList,
					 shared_ptr<const ResultList> resultList,
					 shared_ptr<const ScratchList> scratchList,
					 shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
					 shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
					 shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
					 shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
					 shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
					 shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
					 shared_ptr<const RegLnksListToSIO> lnkToSIO_List) :
    LlirOctaveAsmDirective(lineNum,
			   srcLineNum,
			   srcFileName),
    m_FcnEntryPtList(labelList),
    m_argList(argList),
    m_resultList(resultList),
    m_scratchList(scratchList),
    m_lnkToSPRAM_List(lnkToSPRAM_List),
    m_lnkToLocked_SPRAM_List(lnkToLocked_SPRAM_List),
    m_lnkToSRAM_List(lnkToSRAM_List),
    m_lnkToSDRAM_List(lnkToSDRAM_List),
    m_lnkToCCRAM_List(lnkToCCRAM_List),
    m_lnkToLocked_CCRAM_List(lnkToLocked_CCRAM_List),
    m_lnkToSIO_List(lnkToSIO_List)
  {}
  
  PrototypeDirective::PrototypeDirective(const PrototypeDirective& rhs) :
    LlirOctaveAsmDirective(rhs),
    m_FcnEntryPtList(rhs.m_FcnEntryPtList),
    m_argList(rhs.m_argList),
    m_resultList(rhs.m_resultList),
    m_scratchList(rhs.m_scratchList),
    m_lnkToSPRAM_List(rhs.m_lnkToSPRAM_List),
    m_lnkToLocked_SPRAM_List(rhs.m_lnkToLocked_SPRAM_List),
    m_lnkToSRAM_List(rhs.m_lnkToSRAM_List),
    m_lnkToSDRAM_List(rhs.m_lnkToSDRAM_List),
    m_lnkToCCRAM_List(rhs.m_lnkToCCRAM_List),
    m_lnkToLocked_CCRAM_List(rhs.m_lnkToLocked_CCRAM_List),
    m_lnkToSIO_List(rhs.m_lnkToSIO_List)
  {}

  PrototypeDirective::PrototypeDirective& 
  PrototypeDirective::operator=(const PrototypeDirective& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);

    m_FcnEntryPtList = rhs.m_FcnEntryPtList;
    m_argList = rhs.m_argList;
    m_resultList = rhs.m_resultList;
    m_scratchList = rhs.m_scratchList;
    m_lnkToSPRAM_List = rhs.m_lnkToSPRAM_List;
    m_lnkToLocked_SPRAM_List = rhs.m_lnkToLocked_SPRAM_List;
    m_lnkToSRAM_List = rhs.m_lnkToSRAM_List;
    m_lnkToSDRAM_List = rhs.m_lnkToSDRAM_List;
    m_lnkToCCRAM_List = rhs.m_lnkToCCRAM_List;
    m_lnkToLocked_CCRAM_List = rhs.m_lnkToLocked_CCRAM_List;
    m_lnkToSIO_List = rhs.m_lnkToSIO_List;

    return *this; 

  }
  
  PrototypeDirective::~PrototypeDirective()
  {}


  bool
  PrototypeDirective::isEntryPointLabel(const char* label) const
  {
    return m_FcnEntryPtList->isInList(label);
  }


  bool 
  PrototypeDirective::hasLinkToSPRAM(unsigned int regNum) const
  { 
    shared_ptr<const Register> reg;

    reg = m_lnkToSPRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSPRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSPRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  PrototypeDirective::hasLinkToLockedSPRAM(unsigned int regNum) const
  { 
    shared_ptr<const Register> reg;

    reg = m_lnkToLocked_SPRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_SPRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_SPRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  PrototypeDirective::hasLinkToSRAM(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToSRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  PrototypeDirective::hasLinkToSDRAM(unsigned int regNum) const
  { 
    shared_ptr<const Register> reg;

    reg = m_lnkToSDRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSDRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSDRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  PrototypeDirective::hasLinkToCCRAM(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToCCRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToCCRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToCCRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;

  }

  bool 
  PrototypeDirective::hasLinkToLockedCCRAM(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToLocked_CCRAM_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_CCRAM_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToLocked_CCRAM_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }

  bool 
  PrototypeDirective::hasLinkToSIO(unsigned int regNum) const
  {
    shared_ptr<const Register> reg;

    reg = m_lnkToSIO_List->getRegListLnk1()->getRegister(regNum);
    
    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSIO_List->getRegListLnk2()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }
    
    reg = m_lnkToSIO_List->getRegListLnk3()->getRegister(regNum);

    if(! shared_dynamic_cast<const NullRegister>(reg))
      {
	return true;
      }

    return false;
  }



  shared_ptr<const LabelList> 
  PrototypeDirective::getEntryPtList() const
  {
    return m_FcnEntryPtList;
  }


  shared_ptr<const ArgList> 
  PrototypeDirective::getArgList() const
  {
    return m_argList;
  }

  shared_ptr<const ResultList> 
  PrototypeDirective::getResultList() const
  {
    return m_resultList;
  }

  shared_ptr<const ScratchList> 
  PrototypeDirective::getScratchList() const
  {
    return m_scratchList;
  }

  shared_ptr<const RegLnksListToSPRAM> 
  PrototypeDirective::getRegLnksListToSPRAM() const
  {
    return m_lnkToSPRAM_List;
  }
      
  shared_ptr<const RegLnksListToLockedSPRAM> 
  PrototypeDirective::getRegLnksListToLockedSPRAM() const
  {
    return m_lnkToLocked_SPRAM_List;
  }
  
  shared_ptr<const RegLnksListToSRAM> 
  PrototypeDirective::getRegLnksListToSRAM() const
  {
    return m_lnkToSRAM_List;
  }
  
  shared_ptr<const RegLnksListToSDRAM> 
  PrototypeDirective::getRegLnksListToSDRAM() const
  {
    return m_lnkToSDRAM_List;
  }
  
  shared_ptr<const RegLnksListToCCRAM> 
  PrototypeDirective::getRegLnksListToCCRAM() const
  {
    return m_lnkToCCRAM_List;
  }
  
  shared_ptr<const RegLnksListToLockedCCRAM> 
  PrototypeDirective::getRegLnksListToLockedCCRAM() const
  {
    return m_lnkToLocked_CCRAM_List;
  }
  
  shared_ptr<const RegLnksListToSIO> 
  PrototypeDirective::getRegLnksListToSIO() const
  {
    return m_lnkToSIO_List;
  }



  bool 
  PrototypeDirective::equalTo(const LlirNode &rhs) const
  { 
    PrototypeDirective rhsDir = dynamic_cast<const PrototypeDirective &> (rhs);

    if(*m_argList                == *rhsDir.m_argList &&
       *m_resultList             == *rhsDir.m_resultList &&
       *m_scratchList            == *rhsDir.m_scratchList &&
       *m_lnkToSPRAM_List        == *rhsDir.m_lnkToSPRAM_List &&
       *m_lnkToLocked_SPRAM_List == *rhsDir.m_lnkToLocked_SPRAM_List &&
       *m_lnkToSRAM_List         == *rhsDir.m_lnkToSRAM_List &&
       *m_lnkToSDRAM_List        == *rhsDir.m_lnkToSDRAM_List &&
       *m_lnkToCCRAM_List        == *rhsDir.m_lnkToCCRAM_List &&
       *m_lnkToLocked_CCRAM_List == *rhsDir.m_lnkToLocked_CCRAM_List &&
       *m_lnkToSIO_List          == *rhsDir.m_lnkToSIO_List)
      {
	return true;
      }
    else
      {
	return false;
      }

    return false;
  }

  void 
  PrototypeDirective::accept(Visitor& v) const
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




  //----------------------------
  // Jump Table Begin Directive
  //----------------------------

  JtableBegin::JtableBegin(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName,
			   shared_ptr<LabelList> labelList)
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName),
      m_labelList(labelList)
  {}

  JtableBegin::JtableBegin(const JtableBegin& rhs)
    : LlirOctaveAsmDirective(rhs),
      m_labelList(rhs.m_labelList)
  {}

  JtableBegin&
  JtableBegin::operator=(const JtableBegin& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_labelList = rhs.m_labelList;
    
    return *this;
  }

  JtableBegin::~JtableBegin()
  {}

  shared_ptr<LabelList> 
  JtableBegin::getLabelList() const
  {
    return  m_labelList;
  }

  void 
  JtableBegin::addLabelEntry(shared_ptr<Label> label)
  {
    m_definedLabelList.push_back(label);
  }

  JtableBegin::JtableLabelIterator
  JtableBegin::jtableLabelBegin()
  {
    return m_definedLabelList.begin();
  }

  JtableBegin::JtableLabelIterator
  JtableBegin::jtableLabelEnd()
  {
    return m_definedLabelList.end();
  }

  JtableBegin::JtableLabelConstIterator
  JtableBegin::jtableLabelBegin() const
  {
    return m_definedLabelList.begin();
  }

  JtableBegin::JtableLabelConstIterator
  JtableBegin::jtableLabelEnd() const
  {
    return m_definedLabelList.end();
  }

  bool
  JtableBegin::equalTo(const LlirNode& rhs) const
  {
    const JtableBegin rhsDir
      = dynamic_cast<const JtableBegin &>(rhs);

    return (*m_labelList == *(rhsDir.getLabelList()));
  }

  void
  JtableBegin::accept(Visitor& v) const
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



  //----------------------------
  // Jump Table End Directive
  //----------------------------

  JtableEnd::JtableEnd(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName)
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  JtableEnd::JtableEnd(const JtableEnd& rhs)
    : LlirOctaveAsmDirective(rhs)
  {}

  JtableEnd&
  JtableEnd::operator=(const JtableEnd& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    
    return *this;
  }

  JtableEnd::~JtableEnd()
  {}

  bool
  JtableEnd::equalTo(const LlirNode& rhs) const
  {
    return true;
  }

  void
  JtableEnd::accept(Visitor& v) const
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




  //-------------------------------------
  // Jump Table Relative Begin Directive
  //-------------------------------------

  JtableRelativeBegin::JtableRelativeBegin(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName,
			   shared_ptr<LabelList> labelList)
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName),
      m_labelList(labelList)
  {}

  JtableRelativeBegin::JtableRelativeBegin(const JtableRelativeBegin& rhs)
    : LlirOctaveAsmDirective(rhs),
      m_labelList(rhs.m_labelList)
  {}

  JtableRelativeBegin&
  JtableRelativeBegin::operator=(const JtableRelativeBegin& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    m_labelList = rhs.m_labelList;
    
    return *this;
  }

  JtableRelativeBegin::~JtableRelativeBegin()
  {}

  shared_ptr<LabelList> 
  JtableRelativeBegin::getLabelList() const
  {
    return  m_labelList;
  }

  bool
  JtableRelativeBegin::equalTo(const LlirNode& rhs) const
  {
    const JtableRelativeBegin rhsDir
      = dynamic_cast<const JtableRelativeBegin &>(rhs);

    return (*m_labelList == *(rhsDir.getLabelList()));
  }

  void
  JtableRelativeBegin::accept(Visitor& v) const
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



  //----------------------------------
  // Jump Table Relative End Directive
  //----------------------------------

  JtableRelativeEnd::JtableRelativeEnd(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName)
    : LlirOctaveAsmDirective(lineNum,
			     srcLineNum,
			     srcFileName)
  {}

  JtableRelativeEnd::JtableRelativeEnd(const JtableRelativeEnd& rhs)
    : LlirOctaveAsmDirective(rhs)
  {}

  JtableRelativeEnd&
  JtableRelativeEnd::operator=(const JtableRelativeEnd& rhs)
  {
    if(this == &rhs)
      return *this;

    LlirOctaveAsmDirective::operator=(rhs);
    
    return *this;
  }

  JtableRelativeEnd::~JtableRelativeEnd()
  {}

  bool
  JtableRelativeEnd::equalTo(const LlirNode& rhs) const
  {
    return true;
  }

  void
  JtableRelativeEnd::accept(Visitor& v) const
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



}  
