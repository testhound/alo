#include <string>
#include <exception>
#include <sstream>
#include <Alo.h>
#include <LlirException.h>

#include "OctaveSemanticVisitor.h"


using namespace Llir;

namespace Alo
{

  OctaveSemanticAnalysisVisitor::OctaveSemanticAnalysisVisitor(OctaveAlo &o)
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(o)
  {}


  OctaveAlo&
  OctaveSemanticAnalysisVisitor::getAlo() const
  {
    return m_alo;
  }

  void
  OctaveSemanticAnalysisVisitor::visit(const OctaveBlock& block)
  {
    LlirNode::ConstIterator it = block.begin();
    for (; it != block.end(); it++)
      (*it)->accept(*this);
  }


  void
  OctaveSemanticAnalysisVisitor::visit(const OctaveMacroBlock &macroBlk)
  {
    LlirNode::ConstIterator it = macroBlk.begin();

    for (; it != macroBlk.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveSemanticAnalysisVisitor::visit(const OctaveImplicitBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveSemanticAnalysisVisitor::visit(const LlirLineControlDirective& v)
  {
    //checking done by the parser.
    //nothing to be done here.
  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const  SregisterDirective &d) 
  {
    shared_ptr<std::exception> exc; 
    unsigned int excLine = d.getSrcLineNum();
    const string &excFile = d.getSrcFile();

    OctaveAlo& alo = getAlo();


    AbstractSymReg::SymRegConstraint srConstraint = d.getBeginRegConstraint();

    shared_ptr<const Register> reg = d.getRegister();

    unsigned int firstRegNum = reg->getRegister(0)->getRegNum();

    if(srConstraint == AbstractSymReg::SRC_BEGIN_AT_EVEN_REG)
      {
	//check to see the first register number is even
	if(firstRegNum % 2)
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "illegal first register number %d for @even constraint", firstRegNum); 

	    exc = shared_ptr<IllegalExpression> 
	      (new IllegalExpression(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		
	    alo.logException(exc);	    

	    delete excStr;
	  }
      }
    else if(srConstraint == AbstractSymReg::SRC_BEGIN_AT_ODD_REG)
      {
	//check to see the first register number is odd
	if((firstRegNum+1) % 2)
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "illegal first register number %d for @odd constraint", firstRegNum); 

	    exc = shared_ptr<IllegalExpression> 
	      (new IllegalExpression(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		
	    alo.logException(exc);	    

	    delete excStr;
	  }
      }
  }

  void
  OctaveSemanticAnalysisVisitor::visit(const Align &d)
  {
    shared_ptr<std::exception> exc; 

    unsigned int excLine = d.getSrcLineNum();
    const string &excFile = d.getSrcFile();

    OctaveAlo& alo = getAlo();

    unsigned int alignSize = d.getSize();

    if (alignSize != 0)
      {
	while((alignSize & 1) == 0)
	  {
	    alignSize >>= 1;
	  }
	
	if (alignSize != 1)
	  {
	    char *excStr = new char[128];
	    sprintf(excStr, "Alignment %d is not a power of 2", d.getSize()); 

	    exc = shared_ptr<IllegalExpression> 
	      (new IllegalExpression(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
	  
	    alo.logException(exc);	    
	  
	    delete excStr;
	  }
      }
  }
  
  void 
  OctaveSemanticAnalysisVisitor::visit(const PutFlags &o)
  {
    //check for valid combination of flags
    //in the put flags container
  }


  
 void 
 OctaveSemanticAnalysisVisitor::visit(const StructBeginDirective &d)
 {
   string name = d.getName();

 }


  void 
  OctaveSemanticAnalysisVisitor::visit(const Byte &b) 
  {
    // Checks to be done:

    // parser enforces the check that
    // repetion factor should always be constant 

    // byte datum cannot be a  symbol or an expression.
    // byte datum value should be less than 0xFF


    shared_ptr<std::exception> exc; 
    unsigned int excLine = b.getSrcLineNum();
    const string &excFile = b.getSrcFile();

    OctaveAlo& alo = getAlo();

    AllocMemoryDirective::ConstIterator iter = b.datumBegin();

    for(; iter != b.datumEnd(); iter++)
      {
	shared_ptr<const LlirExpr> exp = (*iter)->getDatum();

	if(exp->isConstantExpr())
	  {
	    unsigned long val = exp->getConstantValue();

	    if((val > 0xFF) && (val & 0xFFFFFF00))
	      {

		char *excStr = new char[128];
		sprintf(excStr, "illegal datum operand value %ld", val); 

		exc = shared_ptr<IllegalExpression> 
		  (new IllegalExpression(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		
		alo.logException(exc);	    

		delete excStr;
	      }
	  }
	else
	  {
	    exc = shared_ptr<IllegalExpression> 
	      (new IllegalExpression("byte datum can only be constant", excLine, excFile.c_str(), __LINE__, __FILE__));

	    alo.logException(exc);	    
	  }
      }
  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const HalfWord &hw) 
  {
    //FIXME:
    // repetion factor should always be constant.

    // value must be 16 bit +ve or -ve number

    // The value must be 0 between 0xFFFF if +ve, 
    // or 0xFFFFXXXX if -ve 

    shared_ptr<std::exception> exc; 
    unsigned int excLine = hw.getSrcLineNum();
    const string &excFile = hw.getSrcFile();

    OctaveAlo& alo = getAlo();

    AllocMemoryDirective::ConstIterator iter = hw.datumBegin();

    for(; iter != hw.datumEnd(); iter++)
      {
	shared_ptr<const LlirExpr> exp = (*iter)->getDatum();

	if(exp->isConstantExpr())
	  {
	    unsigned long val = exp->getConstantValue();

	    if((val > 0xFFFF) &&
	       ((val & 0xFFFF0000) != 0xFFFF0000))
	      {

		char *excStr = new char[128];
		sprintf(excStr, "illegal datum operand %ld", val); 

		exc = shared_ptr<IllegalExpression> 
		  (new IllegalExpression(excStr, excLine, excFile.c_str(), __LINE__, __FILE__));
		
		alo.logException(exc);	    

		delete excStr;
	      }
	    //else it is an expr
	    //and parser enforces all the checks..
	  }
      }
  }


  void 
  OctaveSemanticAnalysisVisitor::visit(const Word &w) 
  {	
    //parser does all the checks...
  }



  void 
  OctaveSemanticAnalysisVisitor::visit(const  LabelList &d) 
  {}
  
  void 
  OctaveSemanticAnalysisVisitor::visit(const  GlobalRegisterList &d) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const ArgList &) 
  {}
 
  void 
  OctaveSemanticAnalysisVisitor::visit(const ResultList &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const ScratchList &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToSPRAM &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToLockedSPRAM &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToSRAM &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToSDRAM &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToCCRAM &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToLockedCCRAM &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const RegLnksListToSIO &) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const  GlobalDirective &d) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const  MultipleEntryEvh &d) 
  {
    
    //checks to verify 
    // - registers are not repeated in @linked specs
    // - registers in scratch not repeated in any of @linked specs

    checkRegLists(d.getSrcLineNum(),
		  d.getSrcFile().c_str(),
		  d.getScratchList(),
		  d.getRegLnksListToSPRAM(),
		  d.getRegLnksListToLockedSPRAM(),
		  d.getRegLnksListToSRAM(),
		  d.getRegLnksListToSDRAM(),
		  d.getRegLnksListToCCRAM(),
		  d.getRegLnksListToLockedCCRAM(),
		  d.getRegLnksListToSIO());

    checkEntryPoints(d);

    // Evh can return results...
    //checkResultRegs(d);

    checkOnlyLinkedCC(d);

    checkLinkedCCRegs(d);

    checkLinkedInArgs(d);

    //analyze all nodes in the implicit block
    LlirNode::Iterator it = d.getImplicitBlock()->begin();

    for (; it != d.getImplicitBlock()->end(); it++)
      (*it)->accept(*this);

  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const  EndEvhDirective &d) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const  MultipleEntryFunction &d) 
  {   

    //checks to verify 
    // - registers are not repeated in @linked specs
    // - registers in scratch not repeated in any of @linked specs

    checkRegLists(d.getSrcLineNum(),
		  d.getSrcFile().c_str(),
		  d.getScratchList(),
		  d.getRegLnksListToSPRAM(),
		  d.getRegLnksListToLockedSPRAM(),
		  d.getRegLnksListToSRAM(),
		  d.getRegLnksListToSDRAM(),
		  d.getRegLnksListToCCRAM(),
		  d.getRegLnksListToLockedCCRAM(),
		  d.getRegLnksListToSIO());

    checkEntryPoints(d);

    checkLinkedInArgs(d);

    //analyze all nodes in the implicit block
    LlirNode::Iterator it = d.getImplicitBlock()->begin();

    for (; it != d.getImplicitBlock()->end(); it++)
      (*it)->accept(*this);

  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const  EndEntryDirective &d) 
  {
    
  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const  PrototypeDirective &d) 
  {
    
    //checks to verify 
    // - registers are not repeated in @linked specs
    // - registers in scratch not repeated in any of @linked specs

    checkRegLists(d.getSrcLineNum(),
		  d.getSrcFile().c_str(),
		  d.getScratchList(),
		  d.getRegLnksListToSPRAM(),
		  d.getRegLnksListToLockedSPRAM(),
		  d.getRegLnksListToSRAM(),
		  d.getRegLnksListToSDRAM(),
		  d.getRegLnksListToCCRAM(),
		  d.getRegLnksListToLockedCCRAM(),
		  d.getRegLnksListToSIO());
  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const  IndirectCallTargetList &d) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const JtableBegin &d) 
  {
    shared_ptr<const LabelList> declaredJtableLabelList = d.getLabelList();
    LabelList::ConstIterator labelIt = declaredJtableLabelList->begin();
    shared_ptr<std::exception> exc;

    if (labelIt == declaredJtableLabelList->end())
      {
	// No entry points declared

	ostringstream excStr;

	excStr << "No jump table entry points declared";
	exc = shared_ptr<LlirDirectiveException> 
	  (new LlirDirectiveException(excStr.str().c_str(), d.getSrcLineNum(), d.getSrcFile().c_str()));

	OctaveAlo& alo = getAlo();
	alo.logException(exc);	    
      }
    else
      {
	bool foundJtableLabel = false;
	shared_ptr<const OpndLabel> declaredLabel;
	JtableBegin::JtableLabelConstIterator definedLabelIt;
	shared_ptr<Label> jtLabel;

	for ( ; labelIt != declaredJtableLabelList->end(); labelIt++)
	  {
	    declaredLabel = *labelIt;
	    definedLabelIt = d.jtableLabelBegin();
	    foundJtableLabel = false;
	    for ( ; definedLabelIt != d.jtableLabelEnd(); definedLabelIt++)
	      {
		jtLabel = *definedLabelIt;
		if (declaredLabel->getName() == jtLabel->getLabelName())
		  {
		    foundJtableLabel = true;
		    break;
		  }
	      }
	    if (foundJtableLabel == false)
	      {
		ostringstream excStr;

		excStr << "No label defined for .jtable entry point \'" << declaredLabel->getName() << "\'";
		exc = shared_ptr<LlirDirectiveException> 
		  (new LlirDirectiveException(excStr.str().c_str(), d.getSrcLineNum(), d.getSrcFile().c_str()));

		OctaveAlo& alo = getAlo();
		alo.logException(exc);
	      }
	  }
      }
  }

  void 
  OctaveSemanticAnalysisVisitor::visit(const  JtableEnd &d) 
  {}


  void 
  OctaveSemanticAnalysisVisitor::visit(const  JtableRelativeBegin &d) 
  {}

  void 
  OctaveSemanticAnalysisVisitor::visit(const  JtableRelativeEnd &d) 
  {}


  void
  OctaveSemanticAnalysisVisitor::checkResultRegs(const AltEntryFunction &f)
  {
    unsigned int excLine = f.getSrcLineNum();
    const string &excFile = f.getSrcFile();

    OctaveAlo& alo = getAlo();
    shared_ptr<std::exception> exc;

    shared_ptr<const ResultList> resultsRegList = f.getResultList();

    if(! resultsRegList->isEmpty())
      {
	//result register list for AltEntryEvh is not empty.

	ostringstream excStr;

	excStr << "@results list should be empty for an Event Handler";
	exc = shared_ptr<LlirDirectiveException> 
	  (new LlirDirectiveException(excStr.str().c_str(), excLine, excFile.c_str()));
	
	alo.logException(exc);	    
      }
  }

  void
  OctaveSemanticAnalysisVisitor::checkOnlyLinkedCC(const AltEntryFunction &f)
  {
    unsigned int excLine = f.getSrcLineNum();
    const string &excFile = f.getSrcFile();

    OctaveAlo& alo = getAlo();

    shared_ptr<std::exception> exc;
    ostringstream linkedMsg;

    // Check all the @linked specifications.  The only one that
    // should contain anything is CCRAM.
    if (!f.getRegLnksListToSPRAM()->isEmpty()) 
      {
	linkedMsg << " @linkedsp"; 
      }
    if (!f.getRegLnksListToLockedSPRAM()->isEmpty())
      {
	linkedMsg << " @linkedspl"; 
      }
    if (!f.getRegLnksListToSRAM()->isEmpty())
      {
	linkedMsg << " @linkedsr"; 
      }
    if (!f.getRegLnksListToSDRAM()->isEmpty())
      {
	linkedMsg << " @linkedsd"; 
      }
    if (!f.getRegLnksListToLockedCCRAM()->isEmpty())
      {
	linkedMsg << " @linkedccl"; 
      }
    if (!f.getRegLnksListToSIO()->isEmpty())
      {
	linkedMsg << " @linkedsio"; 
      }

    if (linkedMsg.rdbuf()->str().length() != 0)
      {
	ostringstream excStr;	
	excStr << "illegal @linked specification(s):" << linkedMsg.rdbuf()->str() << " (only @linkedcc is allowed for Event Handler)";
	exc = shared_ptr<LlirDirectiveException> 
	  (new LlirDirectiveException(excStr.str().c_str(), excLine, excFile.c_str()));
	
	alo.logException(exc);	    
      }
  }


  void
  OctaveSemanticAnalysisVisitor::checkLinkedCCRegs(const AltEntryFunction &f)
  {
    unsigned int excLine = f.getSrcLineNum();
    const string &excFile = f.getSrcFile();

    OctaveAlo& alo = getAlo();

    shared_ptr<std::exception> exc;
    shared_ptr<const RegLnksListToCCRAM> lnkCCRAMList = f.getRegLnksListToCCRAM();

    if (!lnkCCRAMList->isEmpty())
      {
	// Only registers r28..r59 may be linked.
	shared_ptr<const RegList> regLists[3];
	regLists[0] = lnkCCRAMList->getRegListLnk1();
	regLists[1] = lnkCCRAMList->getRegListLnk2();
	regLists[2] = lnkCCRAMList->getRegListLnk3();
	bool logException = false;
	unsigned int regno;

	// Iterate over the register lists...
	for (int i=0; i < 3; i++)
	  {
	    for (regno=0; regno < 28; regno++)
	      {
		if (regLists[i]->isInList(regno))
		  {
		    logException = true;
		    break;
		  }
	      }
	    // Stop here if logException set, we want current value of "regno".
	    if (logException)
	      {
		break;
	      }

	    for (regno=60; regno <= 63; regno++)
	      {
		if (regLists[i]->isInList(regno))
		  {
		    logException = true;
		    break;
		  }
	      }
	    // Again, stop if logException set, we want current value of "regno".
	    if (logException)
	      {
		break;
	      }
	  }

	if (logException)
	  {
	    ostringstream excStr;
	    excStr << "illegal @linkedcc register: r" << regno << " (allowed range is r28..r59)";
	    exc = shared_ptr<LlirDirectiveException> 
	      (new LlirDirectiveException(excStr.str().c_str(), excLine, excFile.c_str()));
	    alo.logException(exc);	    
	  }
      }
    
  }

  void 
  OctaveSemanticAnalysisVisitor::checkLinkedInArgs(const AltEntryFunction &f)
  {
    // Enforce that all registers mentioned in @linked* are present in @args.
    unsigned int excLine = f.getSrcLineNum();
    const string &excFile = f.getSrcFile();
    OctaveAlo& alo = getAlo();

    shared_ptr<std::exception> exc;
    RegList::ConstIterator iter;

    shared_ptr<const ArgList> argList = f.getArgList();
    
    struct {
      shared_ptr<const LinkedRegisterList> lst;
      // FIXME: Do things like "@linkesp" have a method to get the directive name?
      // That would make the "name" field here unnecessarry.
      const char *name;		
    } linkedRegisterLists[] = {
      { f.getRegLnksListToSPRAM(), "@linkedsp" }, 
      { f.getRegLnksListToLockedSPRAM(), "@linkedspl" },
      { f.getRegLnksListToSRAM(), "@linkedsr" },
      { f.getRegLnksListToSDRAM(), "@linkedsd" },
      { f.getRegLnksListToCCRAM(), "@linkedcc" },
      { f.getRegLnksListToLockedCCRAM(), "@linkedccl" },
      { f.getRegLnksListToSIO(), "@linkedsio" },
    };

    int n_lists = sizeof(linkedRegisterLists)/sizeof(linkedRegisterLists[0]);

    for (int i = 0; i < n_lists; i++)
      {
	shared_ptr<const RegList> regLists[3];
	regLists[0] = linkedRegisterLists[i].lst->getRegListLnk1();
	regLists[1] = linkedRegisterLists[i].lst->getRegListLnk2();
	regLists[2] = linkedRegisterLists[i].lst->getRegListLnk3();

	// Iterate over the register lists...
	for (int l = 0; l < 3; l++)
	  {
	    for (iter = regLists[l]->begin(); iter != regLists[l]->end(); iter++)
	      {
		if (! argList->isInList(iter->second->getRegNum()))
		  {
		    ostringstream excStr;
		    excStr << "register r" << iter->second->getRegNum() << " is linked in " << linkedRegisterLists[i].name << " but not in @args";
		    // FIXME: Make this a warning, not an error?
		    exc = shared_ptr<LlirDirectiveException> 
		      (new LlirDirectiveException(excStr.str().c_str(), excLine, excFile.c_str()));
		    alo.logException(exc);
		    // return;
		  }
	      }
	  }
      }
  }

  void
  OctaveSemanticAnalysisVisitor::checkEntryPoints(const AltEntryFunction &f)
  {
    unsigned int excLine = f.getSrcLineNum();
    const string &excFile = f.getSrcFile();

    OctaveAlo& alo = getAlo();

    shared_ptr<std::exception> exc;

    shared_ptr<const LabelList> declaredLabelList = f.getEntryPtList();
    LabelList::ConstIterator labelIt = declaredLabelList->begin();

    AltEntryFunction::EntryLabelConstIterator entryLabelIt;
    shared_ptr<GlobalLabel> globalLabel;
    shared_ptr<const OpndLabel> declaredLabel;
    bool foundDeclaredLabel;

    if (labelIt == declaredLabelList->end())
      {
	// No entry points declared

	ostringstream excStr;

	excStr << "No entry points declared";
	exc = shared_ptr<LlirDirectiveException> 
	  (new LlirDirectiveException(excStr.str().c_str(), excLine, excFile.c_str()));
	
	alo.logException(exc);	    
      }
    else
      {
	// Make sure that every declared entry point has an associated label.
	// It is an error if not.
	bool foundEntryLabel = false;
	for ( ; labelIt != declaredLabelList->end(); labelIt++)
	  {
	    declaredLabel = *labelIt;
	    entryLabelIt = f.entryLabelBegin();

	    foundEntryLabel = false;
	    for (; entryLabelIt != f.entryLabelEnd(); entryLabelIt++)
	      {
		globalLabel = *entryLabelIt;
		if (declaredLabel->getName() == globalLabel->getLabelName())
		  {
		    foundEntryLabel = true;
		    break;
		  }
	      }

	    if (foundEntryLabel == false)
	      {
		ostringstream excStr;

		excStr << "No label defined for entry point \'" << declaredLabel->getName() << "\'";
		exc = shared_ptr<LlirDirectiveException> 
		  (new LlirDirectiveException(excStr.str().c_str(), excLine, excFile.c_str()));
	
		alo.logException(exc);	    
	      }
	  }
      }

    // Now do the inverse test - make sure that every label is actually declared as
    // an entry point.
    for (entryLabelIt = f.entryLabelBegin(); entryLabelIt != f.entryLabelEnd(); entryLabelIt++)
      {
	foundDeclaredLabel = false;
	globalLabel = *entryLabelIt;
	for (labelIt = declaredLabelList->begin(); labelIt != declaredLabelList->end(); labelIt++)
	  {
	    declaredLabel = *labelIt;
	    if (declaredLabel->getName() == globalLabel->getLabelName())
	      {
		foundDeclaredLabel = true;
		break;
	      }
	  }
	if (foundDeclaredLabel)
	  {
	    continue;
	  }
	else
	  {
	    ostringstream excStr;

	    excStr << "Label '" << globalLabel->getLabelName() << "\' is not declared as an entry point";
	    exc = shared_ptr<LabelNotDeclaredException> 
	      (new LabelNotDeclaredException(excStr.str().c_str(), excLine, excFile.c_str(), __LINE__, __FILE__));
	    
	    alo.logException(exc);	    	    
	  }
      }
  }

  void
  OctaveSemanticAnalysisVisitor::checkRegLists(unsigned int excLine,
					       const char* excFile,
					       shared_ptr<const ScratchList> scratchList,
					       shared_ptr<const RegLnksListToSPRAM> lnkSPRAMList,
					       shared_ptr<const RegLnksListToLockedSPRAM> lnkLockedSPRAMList,
					       shared_ptr<const RegLnksListToSRAM> lnkSRAMList,
					       shared_ptr<const RegLnksListToSDRAM> lnkSDRAMList,
					       shared_ptr<const RegLnksListToCCRAM> lnkCCRAMList,
					       shared_ptr<const RegLnksListToLockedCCRAM> lnkLockedCCRAMList,
					       shared_ptr<const RegLnksListToSIO> lnkSIOList)
  {
    shared_ptr<std::exception> exc; 
    OctaveAlo& alo = getAlo();


    unsigned int linkRegSet[64];

    for(unsigned int i=0; i<=63; i++)
      {
	linkRegSet[i] = 0;
      }

    bool logException = false;

    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkSPRAMList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }



    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkLockedSPRAMList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }



    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkCCRAMList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }



    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkLockedCCRAMList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }


    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkSRAMList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }



    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkSDRAMList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }


    for(unsigned int regNum = 0; regNum <= 63; regNum++)
      {
	if(lnkSIOList->isInList(regNum))
	  {
	    if(linkRegSet[regNum])
	      {
		//if bit already set
		logException = true;
	      }
	    else
	      {
		linkRegSet[regNum] = 1;
	      }
	  }

      }

    if(logException)
      {
	char *excStr = new char[128];
	sprintf(excStr, "registers repeated in the @linked specification"); 
	
	exc = shared_ptr<LlirDirectiveException> 
	  (new LlirDirectiveException(excStr, excLine, excFile));
	
	alo.logException(exc);	    
	
	delete excStr;
      }

    logException = false;

    // if scratch list is not empty make sure that
    // registers in the scratch list are not present
    // @linked spec register lists.

    if(! scratchList->isEmpty())
      {
	for(unsigned int i=0; i <= 63; i++)
	  {
	    if(scratchList->isInList(i) && linkRegSet[i])
	      {
		logException = true;
	      }
	  }
      }

    if(logException)
      {
	char *excStr = new char[128];
	sprintf(excStr, "registers in the @scratch list repeated in @linked lists"); 
	
	exc = shared_ptr<LlirDirectiveException> 
	  (new LlirDirectiveException(excStr, excLine, excFile));
	
	alo.logException(exc);	    
	
	delete excStr;
      }
  }

  
  ////////////////////////////////////////////
  //
  // OctaveFlagIdentificationVisitor functions
  //
  ////////////////////////////////////////////
  
  
  OctaveFlagIdentificationVisitor::
  OctaveFlagIdentificationVisitor() 
    : Visitor()
  {
    int i;
    for (i = 0; i < END_OF_FLAGS; i++)
      {
	m_flagPresent[i] = false;
      }
  }

  bool
  OctaveFlagIdentificationVisitor::isFlagPresent(FlagId fl)
  {
    return m_flagPresent[fl];
  }

  

  void
  OctaveFlagIdentificationVisitor::visit(const Mod2Flag &i) 
  {
    m_flagPresent[Mod2] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod4Flag &i) 
  {
    m_flagPresent[Mod4] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod8Flag &i) 
  {
    m_flagPresent[Mod8] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod16Flag &i)
  {
    m_flagPresent[Mod16] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod32Flag &i) 
  {
    m_flagPresent[Mod32] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod64Flag &i) 
  {
    m_flagPresent[Mod64] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod128Flag &i) 
  {
    m_flagPresent[Mod128] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod256Flag &i) 
  {
    m_flagPresent[Mod256] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod512Flag &i) 
  {
    m_flagPresent[Mod512] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod1KFlag &i) 
  {
    m_flagPresent[Mod1K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod2KFlag &i) 
  {
    m_flagPresent[Mod2K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod4KFlag &i) 
  {
    m_flagPresent[Mod4K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod8KFlag &i) 
  {
    m_flagPresent[Mod8K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod16KFlag &i) 
  {
    m_flagPresent[Mod16K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod32KFlag &i) 
  {
    m_flagPresent[Mod32K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod64KFlag &i) 
  {
    m_flagPresent[Mod64K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod128KFlag &i) 
  {
    m_flagPresent[Mod128K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod256KFlag &i) 
  {
    m_flagPresent[Mod256K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod512KFlag &i) 
  {
    m_flagPresent[Mod512K] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod1MFlag &i) 
  {
    m_flagPresent[Mod1M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod2MFlag &i) 
  {
    m_flagPresent[Mod2M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod4MFlag &i) 
  {
    m_flagPresent[Mod4M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod8MFlag &i) 
  {
    m_flagPresent[Mod8M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod16MFlag &i) 
  {
    m_flagPresent[Mod16M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod32MFlag &i) 
  {
    m_flagPresent[Mod32M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod64MFlag &i) 
  {
    m_flagPresent[Mod64M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod128MFlag &i) 
  {
    m_flagPresent[Mod128M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod256MFlag &i) 
  {
    m_flagPresent[Mod256M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod512MFlag &i) 
  {
    m_flagPresent[Mod512M] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod1GFlag &i) 
  {
    m_flagPresent[Mod1G] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Mod2GFlag &i) 
  {
    m_flagPresent[Mod2G] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BZFlag &i) 
  {
    m_flagPresent[BZ] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BNCFlag &i) 
  {
    m_flagPresent[BNC] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BNOFlag &i) 
  {
    m_flagPresent[BNO] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BGEZFlag &i) 
  {
    m_flagPresent[BGEZ] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BLZFlag &i) 
  {
    m_flagPresent[BLZ] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BNZFlag &i) 
  {
    m_flagPresent[BNZ] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BLEZFlag &i) 
  {
    m_flagPresent[BLEZ] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BALBFlag &i) 
  {
    m_flagPresent[BALB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BAEBFlag &i) 
  {
    m_flagPresent[BAEB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BAGBFlag &i) 
  {
    m_flagPresent[BAGB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BANEBFlag &i) 
  {
    m_flagPresent[BANEB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BAGEBFlag &i) 
  {
    m_flagPresent[BAGEB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BALEBFlag &i) 
  {
    m_flagPresent[BALEB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C0Flag &i) 
  {
    m_flagPresent[C0] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C1Flag &i) 
  {
    m_flagPresent[C1] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C2Flag &i) 
  {
    m_flagPresent[C2] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C3Flag &i) 
  {
    m_flagPresent[C3] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C4Flag &i) 
  {
    m_flagPresent[C4] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C5Flag &i) 
  {
    m_flagPresent[C5] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C6Flag &i) 
  {
    m_flagPresent[C6] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C7Flag &i) 
  {
    m_flagPresent[C7] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C8Flag &i) 
  {
    m_flagPresent[C8] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C9Flag &i) 
  {
    m_flagPresent[C9] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C10Flag &i) 
  {
    m_flagPresent[C10] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C11Flag &i) 
  {
    m_flagPresent[C11] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C12Flag &i) 
  {
    m_flagPresent[C12] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C13Flag &i) 
  {
    m_flagPresent[C13] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C14Flag &i) 
  {
    m_flagPresent[C14] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const C15Flag &i) 
  {
    m_flagPresent[C15] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess0Flag &i) 
  {
    m_flagPresent[Ess0] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess1Flag &i) 
  {
    m_flagPresent[Ess1] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess2Flag &i) 
  {
    m_flagPresent[Ess2] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess3Flag &i) 
  {
    m_flagPresent[Ess3] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess4Flag &i) 
  {
    m_flagPresent[Ess4] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess5Flag &i) 
  {
    m_flagPresent[Ess5] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess6Flag &i) 
  {
    m_flagPresent[Ess6] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess7Flag &i) 
  {
    m_flagPresent[Ess7] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess8Flag &i) 
  {
    m_flagPresent[Ess8] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess9Flag &i) 
  {
    m_flagPresent[Ess9] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess10Flag &i) 
  {
    m_flagPresent[Ess10] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess11Flag &i) 
  {
    m_flagPresent[Ess11] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess12Flag &i) 
  {
    m_flagPresent[Ess12] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess13Flag &i) 
  {
    m_flagPresent[Ess13] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess14Flag &i) 
  {
    m_flagPresent[Ess14] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess15Flag &i) 
  {
    m_flagPresent[Ess15] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess16Flag &i) 
  {
    m_flagPresent[Ess16] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess17Flag &i) 
  {
    m_flagPresent[Ess17] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess18Flag &i) 
  {
    m_flagPresent[Ess18] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess19Flag &i) 
  {
    m_flagPresent[Ess19] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess20Flag &i) 
  {
    m_flagPresent[Ess20] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess21Flag &i) 
  {
    m_flagPresent[Ess21] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess22Flag &i) 
  {
    m_flagPresent[Ess22] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess23Flag &i) 
  {
    m_flagPresent[Ess23] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess24Flag &i) 
  {
    m_flagPresent[Ess24] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess25Flag &i) 
  {
    m_flagPresent[Ess25] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess26Flag &i) 
  {
    m_flagPresent[Ess26] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess27Flag &i) 
  {
    m_flagPresent[Ess27] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess28Flag &i) 
  {
    m_flagPresent[Ess28] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess29Flag &i) 
  {
    m_flagPresent[Ess29] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess30Flag &i) 
  {
    m_flagPresent[Ess30] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const Ess31Flag &i) 
  {
    m_flagPresent[Ess31] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const SXFlag &i) 
  {
    m_flagPresent[SX] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const FindFlag &i) 
  {
    m_flagPresent[Find] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const CumeFlag &i) 
  {
    m_flagPresent[CUME] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const SignFlag &i) 
  {
    m_flagPresent[Sign] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const CDFlag &i) 
  {
    m_flagPresent[CD] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const DepbFlag &i) 
  {
    m_flagPresent[Depb] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const DIFlag &i) 
  {
    m_flagPresent[DI] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const LNK1Flag &i) 
  {
    m_flagPresent[LNK1] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const LNK2Flag &i) 
  {
    m_flagPresent[LNK2] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const LNK3Flag &i) 
  {
    m_flagPresent[LNK3] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GC1AFlag &i) 
  {
    m_flagPresent[GC1A] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GC1OFlag &i) 
  {
    m_flagPresent[GC1O] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GC1BFlag &i) 
  {
    m_flagPresent[GC1B] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GC2AFlag &i) 
  {
    m_flagPresent[GC2A] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GC2OFlag &i) 
  {
    m_flagPresent[GC2O] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GC2BFlag &i) 
  {
    m_flagPresent[GC2B] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GPAFlag &i) 
  {
    m_flagPresent[GPA] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GPUFlag &i) 
  {
    m_flagPresent[GPU] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GPBFlag &i) 
  {
    m_flagPresent[GPB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GTAFlag &i) 
  {
    m_flagPresent[GTA] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GTBFlag &i) 
  {
    m_flagPresent[GTB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GTOFlag &i) 
  {
    m_flagPresent[GTO] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const FPFlag &i) 
  {
    m_flagPresent[FP] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const NG2Flag &i) 
  {
    m_flagPresent[NG2] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GZFlag &i) 
  {
    m_flagPresent[GZ] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const OAMFlag &i) 
  {
    m_flagPresent[OAM] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const RPFlag &i) 
  {
    m_flagPresent[RP] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const LOGFlag &i) 
  {
    m_flagPresent[LOG] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const FPBFlag &i) 
  {
    m_flagPresent[FPB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const CSBFlag &i) 
  {
    m_flagPresent[CSB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const DELETEFlag &i) 
  {
    m_flagPresent[DELETE] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const NBFlag &i) 
  {
    m_flagPresent[NB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const NCFlag &i) 
  {
    m_flagPresent[NC] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GWFlag &i) 
  {
    m_flagPresent[GW] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GRFlag &i) 
  {
    m_flagPresent[GR] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const AFlag &i) 
  {
    m_flagPresent[A] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const RFlag &i) 
  {
    m_flagPresent[R] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GUFlag &i) 
  {
    m_flagPresent[GU] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const TFlag &i) 
  {
    m_flagPresent[T] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const RBFlag &i) 
  {
    m_flagPresent[RB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const FBFlag &i) 
  {
    m_flagPresent[FB] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const NTFlag &i) 
  {
    m_flagPresent[NT] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const SFlag &i) 
  {
    m_flagPresent[S] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const UNLNKFlag &i) 
  {
    m_flagPresent[UNLNK] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const PREFlag &i) 
  {
    m_flagPresent[PRE] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const DLNKFlag &i) 
  {
    m_flagPresent[DLNK] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const FLUSHFlag &i) 
  {
    m_flagPresent[FLUSH] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const BFFlag &i) 
  {
    m_flagPresent[BF] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const CFlag &i) 
  {
    m_flagPresent[C] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const GSTICKFlag &i) 
  {
    m_flagPresent[GSTICK] = true;
  }
  void
  OctaveFlagIdentificationVisitor::visit(const NULFlag &i) 
  {
    m_flagPresent[NUL] = true;
  }
  
  ////////////////////////////////////////////
  ////////////////////////////////////////////



}
