#ifndef _LLIR_OCTAVE_NODE_H_
#define _LLIR_OCTAVE_NODE_H_

#include <string>
#include <list>
#include <set>
using namespace std;

#include <LlirNode.h>
#include <LlirOperand.h>
#include "OctaveSymbol.h"

namespace Llir
{
  class Visitor;
  class MapSymbol;
  class Element;

  class LabelList;
  class GlobalRegisterList;
  class ArgList;
  class ResultList;
  class ScratchList;
  class RegLnksListToSPRAM;
  class RegLnksListToLockedSPRAM;
  class RegLnksListToSRAM;
  class RegLnksListToSDRAM;
  class RegLnksListToCCRAM;
  class RegLnksListToLockedCCRAM;
  class RegLnksListToSIO;
  class GlobalLabel;

  class LlirOctaveBlock : public LlirBlock<OctaveSymbol>
    {

    public:

      typedef std::list<shared_ptr<LlirNode> >::iterator BlkIterator;

      typedef std::list<shared_ptr<LlirNode> >::const_iterator BlkConstIterator;

      typedef std::map<unsigned int, shared_ptr<LlirOctaveBlock> >::iterator ParentListIterator;

      typedef std::map<unsigned int, shared_ptr<LlirOctaveBlock> >::const_iterator ParentListConstIterator;

      typedef std::list<shared_ptr<OpndLabel> >::iterator FixupListIterator;

      typedef std::list<shared_ptr<OpndLabel> >::const_iterator FixupListConstIterator;

      typedef std::list<shared_ptr<const MultiHardRegister> >::iterator SmapRegistersIterator;

      typedef std::list<shared_ptr<const MultiHardRegister> >::const_iterator SmapRegistersConstIterator;

      virtual ~LlirOctaveBlock(){}

      virtual ParentListIterator getParent() =0;

      ParentListIterator parentListBegin();

      ParentListConstIterator parentListBegin() const;
      
      ParentListIterator parentListEnd();

      ParentListConstIterator parentListEnd() const;

      SmapRegistersIterator smapRegistersBegin();

      SmapRegistersConstIterator smapRegistersBegin() const;
      
      SmapRegistersIterator smapRegistersEnd();

      SmapRegistersConstIterator smapRegistersEnd() const;

      void addLlirNode(shared_ptr<LlirNode> parent, shared_ptr<LlirNode> child);

      void addSymbol(shared_ptr<OctaveSymbol> sym);

      void removeSymbol(shared_ptr<OctaveSymbol> sym);

      SymbolTable<OctaveSymbol>::Iterator lookupSymbol(const char* name);

      SymbolTable<OctaveSymbol>::ConstIterator lookupSymbol(const char* name) const;

      LlirNode::Iterator begin();

      LlirNode::Iterator end();

      LlirNode::ConstIterator begin() const;

      LlirNode::ConstIterator end() const;

      SymbolTable<OctaveSymbol>::Iterator symTableBegin();

      SymbolTable<OctaveSymbol>::Iterator symTableEnd();

      SymbolTable<OctaveSymbol>::ConstIterator symTableBegin() const;

      SymbolTable<OctaveSymbol>::ConstIterator symTableEnd() const;

      FixupListIterator fixupListBegin();

      FixupListConstIterator fixupListBegin() const;

      FixupListIterator fixupListEnd();

      FixupListConstIterator fixupListEnd() const;

      void storeLabelOpnd(shared_ptr<OpndLabel> label);

      void addSmapRegister(shared_ptr<const MultiHardRegister> r);

      bool isBlock() const;

    protected:   

      LlirOctaveBlock(const char *name, 
		      unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName); 

      LlirOctaveBlock(const LlirOctaveBlock& rhs); 

      LlirOctaveBlock& operator=(const LlirOctaveBlock& rhs);

      ParentListIterator getParentList(unsigned int blkId);

      void setParentList(unsigned int blkId, shared_ptr<LlirOctaveBlock> parent);

    private:

      std::list<shared_ptr<LlirNode> > m_nodeList;

      std::list<shared_ptr<OpndLabel> > m_opndLabelList;

      SymbolTable<OctaveSymbol> m_symTable;

      static std::map<unsigned int, shared_ptr<LlirOctaveBlock> > m_parentList;

      std::list<shared_ptr<const MultiHardRegister> > m_smapHardRegisters;

      void setParent(shared_ptr<LlirOctaveBlock> parent, 
		     shared_ptr<LlirOctaveBlock> child);

    };



  class OctaveBlock : public LlirOctaveBlock
    {
    public:
	
      OctaveBlock(unsigned int lineNum,
		  unsigned int srcLineNum,
		  const char* srcFileName);

      OctaveBlock(const char *name, 
		  unsigned int lineNum,
		  unsigned int srcLineNum,
		  const char* srcFileName);

      OctaveBlock(const OctaveBlock& rhs);

      ~OctaveBlock(){}

      OctaveBlock& operator=(const OctaveBlock&);

      ParentListIterator getParent();

      bool equalTo(const LlirNode &n) const;

      void accept(Visitor &v) const;

    };

  class OctaveMacroBlock : public LlirOctaveBlock
    {
    public:

      OctaveMacroBlock(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName);

      OctaveMacroBlock(const OctaveMacroBlock& rhs);

      ~OctaveMacroBlock() {}

      OctaveMacroBlock& operator=(const OctaveMacroBlock& rhs);

      ParentListIterator getParent();

      bool equalTo(const LlirNode &n) const;

      void accept(Visitor &v) const;
	
    };

  class OctaveImplicitBlock : public LlirOctaveBlock
    {
    public:

      OctaveImplicitBlock();

      OctaveImplicitBlock(const OctaveImplicitBlock& rhs);

      ~OctaveImplicitBlock() {}

      OctaveImplicitBlock& operator=(const OctaveImplicitBlock& rhs);

      ParentListIterator getParent();

      bool equalTo(const LlirNode &n) const;

      void accept(Visitor &v) const;
    };



  //----------------------------
  // Alternate Entry Functions
  //----------------------------

  class AltEntryFunction : public LlirFunction
    {
    protected:
      AltEntryFunction(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName,
		       unsigned int numHardRegs,
		       unsigned int numPseudoRegs,
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
		       shared_ptr<const RegLnksListToSIO> lnkToSIO_List);

      ~AltEntryFunction();
      AltEntryFunction(const AltEntryFunction& rhs);
      AltEntryFunction& operator=(const AltEntryFunction& rhs);

    public:

      const string& getName() const;
      bool isEntryPointLabel(const char* label) const;
      bool isFirstEntryPointLabel(const char* label) const;
      bool isArgRegister(unsigned int regNum) const;
      bool isResultRegister(unsigned int regNum) const;
      bool isScratchRegister(unsigned int regNum) const;
      bool hasLinkToSPRAM(unsigned int regNum) const;
      bool hasLinkToLockedSPRAM(unsigned int regNum) const;
      bool hasLinkToSRAM(unsigned int regNum) const;
      bool hasLinkToSDRAM(unsigned int regNum) const;
      bool hasLinkToCCRAM(unsigned int regNum) const;
      bool hasLinkToLockedCCRAM(unsigned int regNum) const;
      bool hasLinkToSIO(unsigned int regNum) const;

      shared_ptr<OctaveImplicitBlock> getImplicitBlock() const;
      shared_ptr<const LabelList> getEntryPtList() const;
      shared_ptr<const ArgList> getArgList() const;
      shared_ptr<const ResultList> getResultList() const;
      shared_ptr<const ScratchList> getScratchList() const;
      shared_ptr<const RegLnksListToSPRAM> getRegLnksListToSPRAM() const;
      shared_ptr<const RegLnksListToLockedSPRAM> getRegLnksListToLockedSPRAM() const;
      shared_ptr<const RegLnksListToSRAM> getRegLnksListToSRAM() const;
      shared_ptr<const RegLnksListToSDRAM> getRegLnksListToSDRAM() const;
      shared_ptr<const RegLnksListToCCRAM> getRegLnksListToCCRAM() const;
      shared_ptr<const RegLnksListToLockedCCRAM> getRegLnksListToLockedCCRAM() const;
      shared_ptr<const RegLnksListToSIO> getRegLnksListToSIO() const;

      const string& getExitLabel() const;
      shared_ptr<const Register> getReturnReg() const;
      void storeReturnReg(shared_ptr<const Register>);

      void addLlirNode(shared_ptr<LlirNode> , shared_ptr<LlirNode>);
      LlirNode::Iterator begin();
      LlirNode::Iterator end();
      LlirNode::ConstIterator begin() const;
      LlirNode::ConstIterator end() const;

      void addSymbol(shared_ptr<OctaveSymbol> sym);
      void removeSymbol(shared_ptr<OctaveSymbol> sym);
      void addLabelEntry(shared_ptr<GlobalLabel> label);
      SymbolTable<OctaveSymbol>::Iterator lookupSymbol(const char* name);
      SymbolTable<OctaveSymbol>::ConstIterator lookupSymbol(const char* name) const;
      SymbolTable<OctaveSymbol>::Iterator symTableBegin();
      SymbolTable<OctaveSymbol>::Iterator symTableEnd();
      SymbolTable<OctaveSymbol>::ConstIterator symTableBegin() const;
      SymbolTable<OctaveSymbol>::ConstIterator symTableEnd() const;

      typedef vector<shared_ptr<GlobalLabel> >::iterator EntryLabelIterator;
      typedef vector<shared_ptr<GlobalLabel> >::const_iterator EntryLabelConstIterator;

      EntryLabelIterator entryLabelBegin();
      EntryLabelIterator entryLabelEnd();
      EntryLabelConstIterator entryLabelBegin() const;
      EntryLabelConstIterator entryLabelEnd() const;

      //list of all code label operands.
      void storeBranchTarget(const char* name);
      bool isCodeLabel(const char* name) const;

      unsigned getNumRegs() const;
      unsigned getNumHardRegs() const;
      unsigned getNumPseudoRegs() const;
      void updateNumOfPseudoRegs(unsigned int);

    private:
      unsigned int m_numHardRegs;
      unsigned int m_numPseudoRegs;
      shared_ptr<OctaveImplicitBlock> m_implBlock;
      shared_ptr<const LabelList> m_EntryPtList;
      shared_ptr<const ArgList> m_argList;
      shared_ptr<const ResultList> m_resultList;
      shared_ptr<const ScratchList> m_scratchList;
      shared_ptr<const RegLnksListToSPRAM> m_lnkToSPRAM_List;
      shared_ptr<const RegLnksListToLockedSPRAM> m_lnkToLocked_SPRAM_List;
      shared_ptr<const RegLnksListToSRAM> m_lnkToSRAM_List;
      shared_ptr<const RegLnksListToSDRAM> m_lnkToSDRAM_List;
      shared_ptr<const RegLnksListToCCRAM> m_lnkToCCRAM_List;
      shared_ptr<const RegLnksListToLockedCCRAM> m_lnkToLocked_CCRAM_List;
      shared_ptr<const RegLnksListToSIO> m_lnkToSIO_List;

      // generate unique exit name
      std::string m_exitLabel;

      // store return register
      shared_ptr<const Register> m_returnReg;

      // Actual list of global labels we have seen in an event handler or function
      vector<shared_ptr<GlobalLabel> > m_entryLabelList; 

      // List of all Label operands which are seen in any jump/call insn.
      std::set<string> m_codeLabelList;

      
    };


  class MultipleEntryEvh : public AltEntryFunction
    {
    public:
      
      MultipleEntryEvh(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName,
		       unsigned int numHardRegs,
		       unsigned int numPseudoRegs,
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
		       shared_ptr<const RegLnksListToSIO> lnkToSIO_List);

      ~MultipleEntryEvh()
	{}

      MultipleEntryEvh(const MultipleEntryEvh& rhs);
      MultipleEntryEvh& operator=(const MultipleEntryEvh& rhs);
      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor &v) const;
      
    };


  class MultipleEntryFunction : public AltEntryFunction
    {

    public:

      MultipleEntryFunction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName,
			    unsigned int numHardRegs,
			    unsigned int numPseudoRegs,
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
			    shared_ptr<const RegLnksListToSIO> lnkToSIO_List);

      ~MultipleEntryFunction()
	{}

      MultipleEntryFunction(const MultipleEntryFunction& rhs);
      MultipleEntryFunction& operator=(const MultipleEntryFunction& rhs);
      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor &v) const;

    };









	
  //--------------
  //Block Iterator
  //--------------

  class LlirOctaveBlockIterator : public LlirNodeIterator
    {
    public:

      LlirOctaveBlockIterator();

      LlirOctaveBlockIterator(LlirOctaveBlock::BlkIterator);

      LlirOctaveBlockIterator(const LlirOctaveBlockIterator &rhs);

      LlirOctaveBlockIterator& operator=(const LlirOctaveBlockIterator &);

      ~LlirOctaveBlockIterator(){}

      bool equalTo(const LlirNodeIterator &rhs) const;

      LlirNodeIterator*  postInc();

      void preInc();

      LlirNodeIterator*  postDec();

      void preDec();

      shared_ptr<LlirNode>& operator*();

      shared_ptr<LlirNode> *operator->();

    private:

      LlirOctaveBlock::BlkIterator m_iterator;

    };


  class LlirOctaveBlockConstIterator : public LlirNodeConstIterator
    {
    public: 

      LlirOctaveBlockConstIterator();

      LlirOctaveBlockConstIterator(LlirOctaveBlock::BlkConstIterator);

      LlirOctaveBlockConstIterator(const LlirOctaveBlockConstIterator &rhs);
 
      LlirOctaveBlockConstIterator& operator=(const LlirOctaveBlockConstIterator &);
 
      ~LlirOctaveBlockConstIterator(){}
 
      bool equalTo(const LlirNodeConstIterator &rhs) const;
 
      LlirNodeConstIterator*  postInc();

      void preInc();
 
      LlirNodeConstIterator*  postDec();
 
      void preDec();
 
      const shared_ptr<LlirNode>& operator*();
 
      const shared_ptr<LlirNode> *operator->();
 
    private:
 
      LlirOctaveBlock::BlkConstIterator m_iterator;
 
    };


  //--------------
  //FunctionIterator
  //--------------

  class FunctionIterator : public LlirNodeIterator
    {
    public:

      FunctionIterator();

      FunctionIterator(LlirNode::Iterator);

      FunctionIterator(const FunctionIterator &rhs);

      FunctionIterator& operator=(const FunctionIterator &);

      ~FunctionIterator(){}

      bool equalTo(const LlirNodeIterator &rhs) const;

      LlirNodeIterator*  postInc();

      void preInc();

      LlirNodeIterator*  postDec();

      void preDec();

      shared_ptr<LlirNode>& operator*();

      shared_ptr<LlirNode> *operator->();

    private:

      LlirNode::Iterator m_iterator;

    };


  class FunctionConstIterator : public LlirNodeConstIterator
    {
    public: 

      FunctionConstIterator();

      FunctionConstIterator(LlirNode::Iterator);

      FunctionConstIterator(const FunctionConstIterator &rhs);
 
      FunctionConstIterator& operator=(const FunctionConstIterator &);
 
      ~FunctionConstIterator(){}
 
      bool equalTo(const LlirNodeConstIterator &rhs) const;
 
      LlirNodeConstIterator*  postInc();

      void preInc();
 
      LlirNodeConstIterator*  postDec();
 
      void preDec();
 
      const shared_ptr<LlirNode>& operator*();
 
      const shared_ptr<LlirNode> *operator->();
 
    private:
 
      LlirNode::Iterator m_iterator;
 
    };


  class LlirOctaveAsmDirective : public LlirAsmDirective
    {
    public:
      virtual ~LlirOctaveAsmDirective();

      void addLlirNode(shared_ptr<LlirNode>, shared_ptr<LlirNode>);
      LlirNode::Iterator begin();
      LlirNode::Iterator end();
      LlirNode::ConstIterator begin() const;
      LlirNode::ConstIterator end() const;

    protected:
      LlirOctaveAsmDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName);
      LlirOctaveAsmDirective(const LlirOctaveAsmDirective& rhs);
      LlirOctaveAsmDirective& operator=(const LlirOctaveAsmDirective& rhs);
    };

  inline
    LlirOctaveAsmDirective::~LlirOctaveAsmDirective()
    {}

  class Ascii : public LlirOctaveAsmDirective
    {
    public:
      Ascii(unsigned int lineNum,
	    unsigned int srcLineNum,
	    const char* srcFileName, 
	    const char *);
      ~Ascii();
      Ascii(const Ascii& rhs);
      Ascii& operator=(const Ascii& rhs);

      const std::string &getAsciiString() const;
      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
      std::string m_asciiString;
    };

  inline
  Ascii::~Ascii()
  {}

  class Label : public LlirOctaveAsmDirective
    {
    public:
      Label(unsigned int lineNum,
	    unsigned int srcLineNum,
	    const char* srcFileName, 
	    const char *, const char*);

      virtual ~Label() 
	{}

      Label(const Label& rhs);
      Label& operator=(const Label& rhs);

      const std::string &getLabelName() const;
      const std::string &getMangledName() const;

      void setInSequence();
      bool isInSequence() const;
      
      bool isLabel() const;

    private:
      std::string m_labelName;
      std::string m_mangledName;
      bool m_inSequence;

    };

  class LocalLabel : public Label
    {
    public:
      LocalLabel(unsigned int lineNum,
		 unsigned int srcLineNum,
		 const char* srcFileName, 
		 const char *, const char*);
      ~LocalLabel();
      LocalLabel(const LocalLabel& rhs);
      LocalLabel& operator=(const LocalLabel& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  LocalLabel::~LocalLabel()
  {}

  class FileScopeLabel : public Label
    {
    public:
      FileScopeLabel(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName, 
		     const char *, const char*);
      ~FileScopeLabel();
      FileScopeLabel(const FileScopeLabel& rhs);
      FileScopeLabel& operator=(const FileScopeLabel& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  FileScopeLabel::~FileScopeLabel()
  {}

  class GlobalLabel : public Label
    {
    public:
      GlobalLabel(unsigned int lineNum,
		  unsigned int srcLineNum,
		  const char* srcFileName, 
		  const char *, const char*);
      ~GlobalLabel();
      GlobalLabel(const GlobalLabel& rhs);
      GlobalLabel& operator=(const GlobalLabel& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  GlobalLabel::~GlobalLabel()
  {}


  class List : public LlirOctaveAsmDirective
    {
    public:
      List(unsigned int lineNum,
	   unsigned int srcLineNum,
	   const char* srcFileName);
      ~List();
      List(const List& rhs);
      List& operator=(const List& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  List::~List()
  {}

  class NoList : public LlirOctaveAsmDirective
    {
    public:
      NoList(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName);
      ~NoList();
      NoList(const NoList& rhs);
      NoList& operator=(const NoList& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  NoList::~NoList()
  {}

  class EndMacro : public LlirOctaveAsmDirective
    {
    public:
      EndMacro(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName);
      ~EndMacro();
      EndMacro(const EndMacro& rhs);
      EndMacro& operator=(const EndMacro& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  EndMacro::~EndMacro()
  {}

  class Align : public LlirOctaveAsmDirective
    {
    public:
      Align(unsigned int lineNum,
	    unsigned int srcLineNum,
	    const char* srcFileName, 
	    unsigned int alignSize);
      ~Align();
      Align(const Align& rhs);
      Align& operator=(const Align& rhs);

      unsigned int getSize() const;
      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
      unsigned int m_alignSize;
    };

  inline
  Align::~Align()
  {}

  class Ref : public LlirOctaveAsmDirective
    {
    public:
      Ref(unsigned int lineNum,
	  unsigned int srcLineNum,
	  const char* srcFileName, 
	  const char *label);
      ~Ref();
      Ref(const Ref& rhs);
      Ref& operator=(const Ref& rhs);

      const std::string &getLabel() const;
      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
      std::string m_labelName;
    };

  inline
  Ref::~Ref()
  {}

  class EndBlock : public LlirOctaveAsmDirective
    {
    public:
      EndBlock(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName, 
	       const char *blockName);

      EndBlock(unsigned int lineNum,
	       unsigned int srcLineNum,
	       const char* srcFileName);

      ~EndBlock();
      EndBlock(const EndBlock& rhs);
      EndBlock& operator=(const EndBlock& rhs);

      const std::string &getName() const;

    private:
      std::string m_blockName;
    };

  inline
  EndBlock::~EndBlock()
  {}

  class UnNamedEndBlock : public EndBlock
    {
    public:
      UnNamedEndBlock(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName);
      ~UnNamedEndBlock();
      UnNamedEndBlock(const UnNamedEndBlock& rhs);
      UnNamedEndBlock& operator=(const UnNamedEndBlock& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  UnNamedEndBlock::~UnNamedEndBlock()
  {}

  class NamedEndBlock : public EndBlock
    {
    public:
      NamedEndBlock(unsigned int lineNum,
		    unsigned int srcLineNum,
		    const char* srcFileName, 
		    const char *blockName);
      ~NamedEndBlock();
      NamedEndBlock(const NamedEndBlock& rhs);
      NamedEndBlock& operator=(const NamedEndBlock& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  NamedEndBlock::~NamedEndBlock()
  {}


  class Section : public LlirOctaveAsmDirective
    {
    public:
      Section(unsigned int lineNum,
	      unsigned int srcLineNum,
	      const char* srcFileName, 
	      const char *sectionName, 
	      unsigned int sectionSize);
      ~Section();
      Section(const Section& rhs);
      Section& operator=(const Section& rhs);

      const std::string &getName() const;
      unsigned int getSize() const;

    private:
      std::string m_sectionName;
      unsigned int m_sectionSize;
    };

  inline
  Section::~Section()
  {}
  
  class Text : public Section
    {
    public:
      Text(unsigned int lineNum,
	   unsigned int srcLineNum,
	   const char* srcFileName);
      ~Text();
      Text(const Text& rhs);
      Text& operator=(const Text& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  Text::~Text()
  {}

  class Data : public Section
    {
    public:
      Data(unsigned int lineNum,
	   unsigned int srcLineNum,
	   const char* srcFileName);
      ~Data();
      Data(const Data& rhs);
      Data& operator=(const Data& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  Data::~Data()
  {}

  class Comm : public Section
    {
    public:
      Comm(unsigned int lineNum,
	   unsigned int srcLineNum,
	   const char* srcFileName, 
	   const char *name, 
	   unsigned int size);
      ~Comm();
      Comm(const Comm& rhs);
      Comm& operator=(const Comm& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  Comm::~Comm()
  {}


  class Lcomm : public Section
    {
    public:
      Lcomm(unsigned int lineNum,
	    unsigned int srcLineNum,
	    const char* srcFileName, 
	    const char *name, 
	    unsigned int size);
      ~Lcomm();
      Lcomm(const Lcomm& rhs);
      Lcomm& operator=(const Lcomm& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  Lcomm::~Lcomm()
  {}

  class NamedSection : public Section
    {
    public:
      NamedSection(unsigned int lineNum,
		   unsigned int srcLineNum,
		   const char* srcFileName, 
		   const char *name);
      ~NamedSection();
      NamedSection(const NamedSection& rhs);
      NamedSection& operator=(const NamedSection& rhs);

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;
    };

  inline
  NamedSection::~NamedSection()
  {}

  class Datum
  {
  public:
    Datum(shared_ptr<const LlirExpr> d, unsigned repeatCount = 1);
    Datum(const Datum& rhs);
    Datum& operator=(const Datum& rhs);
    ~Datum();
    
    shared_ptr<const LlirExpr> getDatum() const;
    unsigned int getRepCount() const;

  private:
    shared_ptr<const LlirExpr> m_datum;
    unsigned int m_repeatCount;
  };

  inline
  Datum::~Datum()
  {}

  inline
  bool operator==(const Datum &lhs, const Datum &rhs)
  {
    if (*(lhs.getDatum()) == *(rhs.getDatum())
	&& (lhs.getRepCount() == rhs.getRepCount()))
      return true;
    else
      return false;
  }

  inline
  bool operator!=(const Datum &lhs, const Datum &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }

  class AllocMemoryDirective : public LlirOctaveAsmDirective
    {
    public:
      typedef std::list<shared_ptr<Datum> >::iterator Iterator;
      typedef std::list<shared_ptr<Datum> >::const_iterator ConstIterator;

      ~AllocMemoryDirective();
      void addDatum(shared_ptr<Datum> d);
      Iterator datumBegin();
      Iterator datumEnd();
      ConstIterator datumBegin() const;
      ConstIterator datumEnd() const;

    protected:
      AllocMemoryDirective(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName);
      AllocMemoryDirective(const AllocMemoryDirective& rhs);
      AllocMemoryDirective& operator=(const AllocMemoryDirective& rhs);

    private:
      bool equalTo(const LlirNode &) const;
      std::list<shared_ptr<Datum> > m_datumList;
    };

  inline
  AllocMemoryDirective::~AllocMemoryDirective()
  {}

  class Byte : public AllocMemoryDirective
  {
  public:
    Byte(unsigned int lineNum,
	 unsigned int srcLineNum,
	 const char* srcFileName);
    ~Byte();
    Byte(const Byte& rhs);
    Byte& operator=(const Byte& rhs);

    void accept(Visitor &v) const;
  };

  inline
  Byte::~Byte()
  {}

  class Word : public AllocMemoryDirective
  {
  public:
    Word(unsigned int lineNum,
	 unsigned int srcLineNum,
	 const char* srcFileName);
    ~Word();
    Word(const Word& rhs);
    Word& operator=(const Word& rhs);

    void accept(Visitor &v) const;
  };

  inline
  Word::~Word()
  {}

  class HalfWord : public AllocMemoryDirective
  {
  public:
    HalfWord(unsigned int lineNum,
	     unsigned int srcLineNum,
	     const char* srcFileName);
    ~HalfWord();
    HalfWord(const HalfWord& rhs);
    HalfWord& operator=(const HalfWord& rhs);

    void accept(Visitor &v) const;
  };

  inline
  HalfWord::~HalfWord()
  {}

  class OrgDirective : public LlirOctaveAsmDirective
    {
    public:
      ~OrgDirective();
      unsigned int getNumBytes() const;

    protected:
      OrgDirective(unsigned int lineNum,
		   unsigned int srcLineNum,
		   const char* srcFileName, 
		   unsigned int numBytes);
      OrgDirective(const OrgDirective& rhs);
      OrgDirective& operator=(const OrgDirective& rhs);

    private:
      unsigned int m_numBytes;
    };

  inline
  OrgDirective::~OrgDirective()
  {}

  class Org : public OrgDirective
  {
  public:
    Org(unsigned int lineNum,
	unsigned int srcLineNum,
	const char* srcFileName,
	unsigned int numBytes);
    ~Org();
    Org(const Org& rhs);
    Org& operator=(const Org& rhs);

    void accept(Visitor &v) const;

  private:
      bool equalTo(const LlirNode &) const;
  };

  inline
  Org::~Org()
  {}

  class OrgWithFillValue : public OrgDirective
  {
  public:
    OrgWithFillValue(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName, 
		     unsigned int numBytes, 
		     unsigned int fillVal);
    ~OrgWithFillValue();
    OrgWithFillValue(const OrgWithFillValue& rhs);
    OrgWithFillValue& operator=(const OrgWithFillValue& rhs);
    void accept(Visitor &v) const;
    unsigned int getFillValue() const;

  private:
    bool equalTo(const LlirNode &) const;
    unsigned int m_fillValue;
  };

  inline
  OrgWithFillValue::~OrgWithFillValue()
  {}

  class StructBeginDirective : public LlirOctaveAsmDirective
    {
    public:
      StructBeginDirective(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   const char *structName);
      StructBeginDirective(const StructBeginDirective& rhs);
      StructBeginDirective& operator=(const StructBeginDirective& rhs);
      ~StructBeginDirective();
      void accept(Visitor &v) const;

      const std::string& getName() const;

    private:
      std::string m_structName;
      bool equalTo(const LlirNode &) const;
    };

  inline
  StructBeginDirective::~StructBeginDirective()
  {}

  class StructEndDirective : public LlirOctaveAsmDirective
    {
    public:
      StructEndDirective(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName);
      StructEndDirective(const StructEndDirective& rhs);
      StructEndDirective& operator=(const StructEndDirective& rhs);
      ~StructEndDirective();
      void accept(Visitor &v) const;

    protected:

    private:
      bool equalTo(const LlirNode &) const;
    };

  inline
  StructEndDirective::~StructEndDirective()
  {}

  class MapDirective : public LlirOctaveAsmDirective
    {
    public:
      MapDirective(unsigned int lineNum,
		   unsigned int srcLineNum,
		   const char* srcFileName, 
		   const char *mapPath,
		   const char *mapName, shared_ptr<MapSymbol> m);
      MapDirective(const MapDirective& rhs);
      MapDirective& operator=(const MapDirective& rhs);
      ~MapDirective();
      void accept(Visitor &v) const;

      const std::string& getMapName() const;
      const std::string& getMapPath() const;
      shared_ptr<const MapSymbol> getMappedSymbol() const;

    private:
      std::string m_mapPath;
      std::string m_mapName;
      shared_ptr<MapSymbol> m_mapSymbol;

      bool equalTo(const LlirNode &) const;
    };

  inline
  MapDirective::~MapDirective()
  {}

  class UnmapDirective : public LlirOctaveAsmDirective
    {
    public:
      UnmapDirective(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName, 
		     const char *mapName);
      UnmapDirective(const UnmapDirective& rhs);
      UnmapDirective& operator=(const UnmapDirective& rhs);
      ~UnmapDirective();
      void accept(Visitor &v) const;

      const std::string& getName() const;

    private:
      std::string m_mapName;
      bool equalTo(const LlirNode &) const;
    };

  inline
  UnmapDirective::~UnmapDirective()
  {}

  class ScopedMapDirective : public LlirOctaveAsmDirective
    {
    public:
      ScopedMapDirective(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 const char *mapPath,
			 const char *mapName, 
			 shared_ptr<MapSymbol> m);
      ScopedMapDirective(const ScopedMapDirective& rhs);
      ScopedMapDirective& operator=(const ScopedMapDirective& rhs);
      ~ScopedMapDirective();
      void accept(Visitor &v) const;

      const std::string& getMapName() const;
      const std::string& getMapPath() const;
      shared_ptr<const MapSymbol> getMappedSymbol() const;

    private:
      std::string m_mapPath;
      std::string m_mapName;
      shared_ptr<MapSymbol> m_mapSymbol;

      bool equalTo(const LlirNode &) const;
    };

  inline
  ScopedMapDirective::~ScopedMapDirective()
  {}


  class ElementDirective : public LlirOctaveAsmDirective
    {
    public:
      ElementDirective(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName, 
		       shared_ptr<Element> elemDecl);
      ElementDirective(const ElementDirective& rhs);
      ElementDirective& operator=(const ElementDirective& rhs);
      ~ElementDirective();
      void accept(Visitor &v) const;

      shared_ptr<const Element> getElementDecl() const;

    private:
      shared_ptr<Element> m_elementDecl;
      bool equalTo(const LlirNode &) const;
    };

  inline
  ElementDirective::~ElementDirective()
  {}


  class MeetsDirective : public LlirOctaveAsmDirective
    {
    public:
      MeetsDirective(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName, 
		     const char *testedPath,
		     const char *referencePath);
      ~MeetsDirective();
      MeetsDirective(const MeetsDirective& rhs);
      MeetsDirective& operator=(const MeetsDirective& rhs);

      void accept(Visitor &v) const;

      const string& getTestedPath() const;
      const string& getReferencePath() const;

    private:
      bool equalTo(const LlirNode &rhs) const;

      string m_testedPath;
      string m_referencePath;
    };

  inline
  MeetsDirective::~MeetsDirective()
  {}

  class AssertDirective : public LlirOctaveAsmDirective
    {
    public:
      AssertDirective(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName, 
		      shared_ptr<const LlirOperand> expr, 
		      const char *assertMsg);
      ~AssertDirective();
      AssertDirective(const AssertDirective& rhs);
      AssertDirective& operator=(const AssertDirective& rhs);

      shared_ptr<const LlirOperand> getExpr() const;
      const string& getAssertMsg() const;
      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;

      shared_ptr<const LlirOperand> m_expr; //  +ve/-ve?
      string m_assertMessage;
    };

  inline
  AssertDirective::~AssertDirective()
  {}



  class WarningDirective : public LlirOctaveAsmDirective
    {
    public:
      WarningDirective(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName, 
		       const char *warningMsg);
      ~WarningDirective();
      WarningDirective(const WarningDirective& rhs);
      WarningDirective& operator=(const WarningDirective& rhs);

      const string& getWarningMsg() const;

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;

      string m_warningMessage;
    };

  inline
  WarningDirective::~WarningDirective()
  {}


  class ErrorDirective : public LlirOctaveAsmDirective
    {
    public:
      ErrorDirective(unsigned int lineNum,
		     unsigned int srcLineNum,
		     const char* srcFileName, 
		     const char *msg);
      ~ErrorDirective();
      ErrorDirective(const ErrorDirective& rhs);
      ErrorDirective& operator=(const ErrorDirective& rhs);

      const string& getErrorMsg() const;

      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;

      string m_errorMessage;
    };

  inline
  ErrorDirective::~ErrorDirective()
  {}

  class SregisterDirective : public LlirOctaveAsmDirective
    {
    public:

      SregisterDirective(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 const char *name, 
			 shared_ptr<const Register> Reg,
			 AbstractSymReg::SymRegConstraint symRegConstraint,
			 shared_ptr<const Register> constraintRegRange);

      SregisterDirective(const SregisterDirective& rhs);
      SregisterDirective& operator=(const SregisterDirective& rhs);
      ~SregisterDirective();
      const std::string& getSymRegName() const;
      shared_ptr<const Register> getRegister() const;
      AbstractSymReg::SymRegConstraint getBeginRegConstraint() const;
      shared_ptr<const Register> getConstraintRegRange() const;
      void accept(Visitor &v) const;

    private:
      bool equalTo(const LlirNode &rhs) const;

      std::string m_symRegName;
      shared_ptr<const Register> m_reg;
      AbstractSymReg::SymRegConstraint m_symRegConstraint;
      shared_ptr<const Register> m_constraintRegRange;
    };

  inline
  SregisterDirective::~SregisterDirective()
  {}



  class GlobalDirective : public LlirOctaveAsmDirective
    {
    public:

      GlobalDirective(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName,
		      shared_ptr<const GlobalRegisterList> globalReg_List,
		      shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
		      shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
		      shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
		      shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
		      shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
		      shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
		      shared_ptr<const RegLnksListToSIO> lnkToSIO_List);
      
      GlobalDirective(const GlobalDirective& rhs);
      GlobalDirective& operator=(const GlobalDirective& rhs);
      ~GlobalDirective();

      bool isGlobalReg(unsigned int regNum) const;

      bool hasLinkToSPRAM(unsigned int regNum) const;
      bool hasLinkToLockedSPRAM(unsigned int regNum) const;
      bool hasLinkToSRAM(unsigned int regNum) const;
      bool hasLinkToSDRAM(unsigned int regNum) const;
      bool hasLinkToCCRAM(unsigned int regNum) const;
      bool hasLinkToLockedCCRAM(unsigned int regNum) const;
      bool hasLinkToSIO(unsigned int regNum) const;

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor& v) const;
      
      shared_ptr<const GlobalRegisterList> getGlobalRegList() const;
      shared_ptr<const RegLnksListToSPRAM> getRegLnksListToSPRAM() const;
      shared_ptr<const RegLnksListToLockedSPRAM> getRegLnksListToLockedSPRAM() const;
      shared_ptr<const RegLnksListToSRAM> getRegLnksListToSRAM() const;
      shared_ptr<const RegLnksListToSDRAM> getRegLnksListToSDRAM() const;
      shared_ptr<const RegLnksListToCCRAM> getRegLnksListToCCRAM() const;
      shared_ptr<const RegLnksListToLockedCCRAM> getRegLnksListToLockedCCRAM() const;
      shared_ptr<const RegLnksListToSIO> getRegLnksListToSIO() const;

    private:
      shared_ptr<const GlobalRegisterList> m_globalReg_List;
      shared_ptr<const RegLnksListToSPRAM> m_lnkToSPRAM_List;
      shared_ptr<const RegLnksListToLockedSPRAM> m_lnkToLocked_SPRAM_List;
      shared_ptr<const RegLnksListToSRAM> m_lnkToSRAM_List;
      shared_ptr<const RegLnksListToSDRAM> m_lnkToSDRAM_List;
      shared_ptr<const RegLnksListToCCRAM> m_lnkToCCRAM_List;
      shared_ptr<const RegLnksListToLockedCCRAM> m_lnkToLocked_CCRAM_List;
      shared_ptr<const RegLnksListToSIO> m_lnkToSIO_List;

    };


  class EndEvhDirective : public LlirOctaveAsmDirective
    {
    public:
      EndEvhDirective(unsigned int lineNum,
		      unsigned int srcLineNum,
		      const char* srcFileName, 
		      const char* label);
      EndEvhDirective(const EndEvhDirective& rhs);
      EndEvhDirective& operator=(const EndEvhDirective& rhs);
      ~EndEvhDirective();

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor &v) const;

      shared_ptr<const LabelSymbol> getFirstEntryPtLabel() const;

    private:
      shared_ptr<const LabelSymbol> m_firstEntryPointLabel;
    };


  class EndEntryDirective : public LlirOctaveAsmDirective
    {
    public:
      EndEntryDirective(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			const char* label);
      EndEntryDirective(const EndEntryDirective& rhs);
      EndEntryDirective& operator=(const EndEntryDirective& rhs);
      ~EndEntryDirective();

      shared_ptr<const LabelSymbol> getEvhLabel() const;

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor &v) const;

    private:
      shared_ptr<const LabelSymbol> m_firstEntryPointLabel;
    };

  class PrototypeDirective : public LlirOctaveAsmDirective
    {
    public:
      PrototypeDirective(unsigned int lineNum,
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
			 shared_ptr<const RegLnksListToSIO> lnkToSIO_List);

      
      PrototypeDirective(const PrototypeDirective& rhs);
      PrototypeDirective& operator=(const PrototypeDirective& rhs);
      ~PrototypeDirective();

      bool isEntryPointLabel(const char* label) const;
      bool isArgRegister(unsigned int regNum) const;
      bool isResultRegister(unsigned int regNum) const;
      bool isScratchRegister(unsigned int regNum) const;
      bool hasLinkToSPRAM(unsigned int regNum) const;
      bool hasLinkToLockedSPRAM(unsigned int regNum) const;
      bool hasLinkToSRAM(unsigned int regNum) const;
      bool hasLinkToSDRAM(unsigned int regNum) const;
      bool hasLinkToCCRAM(unsigned int regNum) const;
      bool hasLinkToLockedCCRAM(unsigned int regNum) const;
      bool hasLinkToSIO(unsigned int regNum) const;

      bool isFirstEntryPointLabel(const char* label) const;
      
      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor&v) const;

      
      shared_ptr<const LabelList> getEntryPtList() const;


      shared_ptr<const ArgList> getArgList() const;
      shared_ptr<const ResultList> getResultList() const;
      shared_ptr<const ScratchList> getScratchList() const;

      shared_ptr<const RegLnksListToSPRAM> getRegLnksListToSPRAM() const;
      shared_ptr<const RegLnksListToLockedSPRAM> getRegLnksListToLockedSPRAM() const;
      shared_ptr<const RegLnksListToSRAM> getRegLnksListToSRAM() const;
      shared_ptr<const RegLnksListToSDRAM> getRegLnksListToSDRAM() const;
      shared_ptr<const RegLnksListToCCRAM> getRegLnksListToCCRAM() const;
      shared_ptr<const RegLnksListToLockedCCRAM> getRegLnksListToLockedCCRAM() const;
      shared_ptr<const RegLnksListToSIO> getRegLnksListToSIO() const;

    private:
      shared_ptr<const LabelList> m_FcnEntryPtList;

      shared_ptr<const ArgList> m_argList;
      shared_ptr<const ResultList> m_resultList;
      shared_ptr<const ScratchList> m_scratchList;

      shared_ptr<const RegLnksListToSPRAM> m_lnkToSPRAM_List;
      shared_ptr<const RegLnksListToLockedSPRAM> m_lnkToLocked_SPRAM_List;
      shared_ptr<const RegLnksListToSRAM> m_lnkToSRAM_List;
      shared_ptr<const RegLnksListToSDRAM> m_lnkToSDRAM_List;
      shared_ptr<const RegLnksListToCCRAM> m_lnkToCCRAM_List;
      shared_ptr<const RegLnksListToLockedCCRAM> m_lnkToLocked_CCRAM_List;
      shared_ptr<const RegLnksListToSIO> m_lnkToSIO_List;
		   
    };

  //----------------------------
  // Jump Table Begin Directive
  //----------------------------


  class JtableBegin : public LlirOctaveAsmDirective
    {
    public:
      JtableBegin(unsigned int lineNum,
		  unsigned int srcLineNum,
		  const char* srcFileName,
		  shared_ptr<LabelList> labelList);
      JtableBegin(const JtableBegin& rhs);
      JtableBegin& operator=(const JtableBegin& rhs);
      ~JtableBegin();

      typedef vector<shared_ptr<Label> >::iterator JtableLabelIterator;
      typedef vector<shared_ptr<Label> >::const_iterator JtableLabelConstIterator;

      JtableLabelIterator jtableLabelBegin();
      JtableLabelIterator jtableLabelEnd();
      JtableLabelConstIterator jtableLabelBegin() const;
      JtableLabelConstIterator jtableLabelEnd() const;

      shared_ptr<LabelList> getLabelList() const;
      void addLabelEntry(shared_ptr<Label> label);

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor& v) const;

    private:
      shared_ptr<LabelList> m_labelList;
      vector<shared_ptr<Label> > m_definedLabelList;
    };

  //----------------------------
  // Jump Table End Directive
  //----------------------------


  class JtableEnd : public LlirOctaveAsmDirective
    {
    public:
      JtableEnd(unsigned int lineNum,
		unsigned int srcLineNum,
		const char* srcFileName);
      JtableEnd(const JtableEnd& rhs);
      JtableEnd& operator=(const JtableEnd& rhs);
      ~JtableEnd();

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor& v) const;

    };

  //------------------------------------
  // Jump Table Relative Begin Directive
  //------------------------------------


  class JtableRelativeBegin : public LlirOctaveAsmDirective
    {
    public:
      JtableRelativeBegin(unsigned int lineNum,
		  unsigned int srcLineNum,
		  const char* srcFileName,
		  shared_ptr<LabelList> labelList);
      JtableRelativeBegin(const JtableRelativeBegin& rhs);
      JtableRelativeBegin& operator=(const JtableRelativeBegin& rhs);
      ~JtableRelativeBegin();

      shared_ptr<LabelList> getLabelList() const;

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor& v) const;

    private:
      shared_ptr<LabelList> m_labelList;
    };

  //-----------------------------------
  // Jump Table Relative End Directive
  //-----------------------------------


  class JtableRelativeEnd : public LlirOctaveAsmDirective
    {
    public:
      JtableRelativeEnd(unsigned int lineNum,
		unsigned int srcLineNum,
		const char* srcFileName);
      JtableRelativeEnd(const JtableRelativeEnd& rhs);
      JtableRelativeEnd& operator=(const JtableRelativeEnd& rhs);
      ~JtableRelativeEnd();

      bool equalTo(const LlirNode &rhs) const;
      void accept(Visitor& v) const;

    };

}
#endif













