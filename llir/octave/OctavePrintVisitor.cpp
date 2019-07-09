#include <LlirFile.h>
#include <LlirException.h>

#include "OctaveNode.h"
#include "OctaveOperand.h"
#include "OctaveSymbol.h"
#include "OctaveInstructions.h"
#include "OctavePrintVisitor.h"
#include <iostream>

namespace Llir
{
  OctavePrintVisitor::OctavePrintVisitor(ostream &o) : 
    Visitor(), 
    LlirOctaveVisitor(),
    m_macroDepth(0),
    m_inMacroBlock(false),
    m_outputStream(o),
    m_lineNum(1)
  {}

  OctavePrintVisitor::~OctavePrintVisitor()
  {}

  std::ostream&
  OctavePrintVisitor::getOutputStream() const
  {
    return m_outputStream;
  }

  void
  OctavePrintVisitor::endOfLine()
  {
    if (m_inMacroBlock == false)
      {
	m_outputStream << "\n";
	m_lineNum++;
      }
    else
      {
	m_outputStream << " ";
      }
  }


  void
  OctavePrintVisitor::printAlu2OpBranch(const Alu2OpBranchInstruction &i, const char *mneumonic)
  {
    shared_ptr<const LlirOperand> src = i.getSrc1();
    shared_ptr<const Register> dst = i.getDst();
    shared_ptr<const LlirOperand> target = i.getBranchTarget();
    
    getOutputStream() << mneumonic << " ";
    src->accept(*this);
    getOutputStream() << " ";
    dst->accept(*this);
    
    OpndNull null;
    if (*target != null) 
      getOutputStream() << " br = ";
    target->accept(*this);
  }
  
  void
  OctavePrintVisitor::printAlu2OpFind(const Alu2OpFindInstruction &i, const char *mneumonic)
  {
    shared_ptr<const LlirOperand> src = i.getSrc1();
    shared_ptr<const Register> dst = i.getDst();

    getOutputStream() << mneumonic << " ";
    src->accept(*this);
    getOutputStream() << " ";
    dst->accept(*this);
    getOutputStream() << " ";

    i.getAbcFlag()->accept(*this);
    getOutputStream() << " ";
    i.getFindFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printAlu3OpAbcMod(const Alu3OpAbcModInstruction &i, const char *mnemonic)
  {
    shared_ptr<const Register> reg1 = i.getSrc1();
    shared_ptr<const LlirOperand> opnd2 = i.getSrc2();
    shared_ptr<const Register> dst = i.getDst();
    shared_ptr<const LlirOperand> abc = i.getAbcFlag(); 
    shared_ptr<const LlirOperand> mod = i.getModFlag();
    
    getOutputStream() << mnemonic << " ";
    reg1->accept(*this); 
    getOutputStream() << " ";
    opnd2->accept(*this); 
    getOutputStream() << " ";
    dst->accept(*this); 
    getOutputStream() << " ";
    abc->accept(*this); 
    getOutputStream() << " ";
    mod->accept(*this);
  }
  
  void
  OctavePrintVisitor::printAlu3OpAbc(const Alu3OpAbcInstruction &i, const char *mnemonic)
  {
    shared_ptr<const Register> reg1 = i.getSrc1();
    shared_ptr<const LlirOperand> opnd2 = i.getSrc2();
    shared_ptr<const Register> dst = i.getDst();
    shared_ptr<const LlirOperand> abc = i.getAbcFlag(); 
    
    getOutputStream() << mnemonic << " ";
    reg1->accept(*this); 
    getOutputStream() << " ";
    opnd2->accept(*this); 
    getOutputStream() << " ";
    dst->accept(*this); 
    getOutputStream() << " ";
    abc->accept(*this); 
  }
  
  void
  OctavePrintVisitor::printAlu3OpSx(const Alu3OpSxInstruction &i, const char *mnemonic)
  {
    shared_ptr<const Register> reg1 = i.getSrc1();
    shared_ptr<const LlirOperand> opnd2 = i.getSrc2();
    shared_ptr<const Register> dst = i.getDst();
    
    getOutputStream() << mnemonic << " ";
    reg1->accept(*this); 
    getOutputStream() << " ";
    opnd2->accept(*this); 
    getOutputStream() << " ";
    dst->accept(*this); 
    getOutputStream() << " ";    
    i.getSxFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printAlu3Op(const Alu3OpInstruction &i, const char *mnemonic)
  {
    shared_ptr<const Register> reg1 = i.getSrc1();
    shared_ptr<const LlirOperand> opnd2 = i.getSrc2();
    shared_ptr<const Register> dst = i.getDst();
    
    getOutputStream() << mnemonic << " ";
    reg1->accept(*this); 
    getOutputStream() << " ";
    opnd2->accept(*this); 
    getOutputStream() << " ";
    dst->accept(*this); 
  }
  
  void
  OctavePrintVisitor::printCondBranch(const CondBranchInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getEss()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getFlags()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printCondBranchImmed(const CondBranchImmedInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getEss()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getFlags()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printZeroBranch(const ZeroBranchInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);
    getOutputStream() << " ";
    i.getCmpReg()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printZeroBranchImmed(const ZeroBranchImmedInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);
    getOutputStream() << " ";
    i.getCmpReg()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printTestBitBranch(const TestBitBranchInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getBitpos()->accept(*this);

    shared_ptr<const LlirOperand> target = i.getDisp();    
    getOutputStream() << " br = ";
    target->accept(*this);
  }
  
  void
  OctavePrintVisitor::printReturn(const ReturnOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getDiFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printCompareBranch(const CompareOpBranchInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);

    shared_ptr<const LlirOperand> target = i.getBranchTarget();

    OpndNull null;
    if (*target != null) 
      getOutputStream() << " br = ";
    target->accept(*this);

    getOutputStream() << " ";
    i.getAbcFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printCompareSign(const CompareOpSignInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";

    i.getSrc1()->accept(*this);
    getOutputStream() << " ";

    i.getSrc2()->accept(*this);
    getOutputStream() << " ";

    i.getDst()->accept(*this);
    getOutputStream() << " ";

    i.getAbcFlag()->accept(*this);
    getOutputStream() << " ";

    i.getSign()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printCmov(const CmovOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";

    i.getSrc1()->accept(*this);
    getOutputStream() << " ";

    i.getSrc2()->accept(*this);
    getOutputStream() << " ";

    i.getDst()->accept(*this);
    getOutputStream() << " ";

    i.getEssFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printDma(const DmaOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRegs()->accept(*this);
    getOutputStream() << " ";
    i.getDmaFlags()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printLoadImmediate(const LoadImmediateInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getSrc()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printLoadHalfword(const LoadHalfwordInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getSrc()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printLink(const MultiRegLinkInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRegs()->accept(*this);
    getOutputStream() << " ";
    i.getMem()->accept(*this);
    getOutputStream() << " ";
    i.getLinkFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printLoad(const MultiRegLoadInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRegs()->accept(*this);
    getOutputStream() << " ";
    i.getMem()->accept(*this);
    getOutputStream() << " ";
    i.getLinkFlag()->accept(*this);
  }
  
  void
  OctavePrintVisitor::printStore(const MultiRegStoreInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRegs()->accept(*this);
    getOutputStream() << " ";
    i.getMem()->accept(*this);
  }
  
  void
  OctavePrintVisitor::visit(const LlirFile &f)
  {
    LlirFile::ConstIterator iter = f.begin();

    for(; iter != f.end(); iter++)
      {
	(*iter)->accept(*this);
      }
  }
  
  void
  OctavePrintVisitor::visit(const NullRegister &reg)
  {
  }

  void
  OctavePrintVisitor::visit(const HardRegister &reg)
  {
    m_outputStream << "r" << reg.getRegNum();
  }

  void
  OctavePrintVisitor::visit(const MultiHardRegister &reg)
  {
    shared_ptr<const Register> firstReg = reg.getRegister(0);
    shared_ptr<const Register> lastReg = reg.getRegister(reg.getNumRegs() - 1);

    firstReg->accept(*this);
    m_outputStream << "-";
    lastReg->accept(*this);
  }


  void
  OctavePrintVisitor::visit(const PseudoRegister &reg)
  {

    /* 
       FIXME.... 

       A pseudo register should not be printed out 
       when we are not-optimizing... 
       (because back end assembler cannot handle pseudo 
       registers...)

       Use of directives .sreg and .smap (which
       are the only means by which a pseudo register 
       would have been created is allowed only when
       alo is optimizing the code. 

       Thus in case of 
       optimizing ALO we would never come to this        routine as after conversion from .s to .llir 
       we would directly go to .rtl and would not 
       print intermediate .i2 file....
    */

    // FIXME:
    //put a ifdef / switch to check to see if we are
    //in debug mode and if so print the pseudo
    //register being used in an instruction....

    string name = reg.getRegName();
    char *buffer = new(char[name.size() + 64]);
    sprintf(buffer, "%s[%d]", name.c_str(), reg.getRegNum());

    m_outputStream << buffer; 
  }

  void
  OctavePrintVisitor::visit(const MultiPseudoRegister &reg)
  {
    shared_ptr<const Register> firstReg = reg.getRegister(0);
    shared_ptr<const Register> lastReg = reg.getRegister(reg.getNumRegs() - 1);

    firstReg->accept(*this);
    m_outputStream << "-";
    lastReg->accept(*this);
  }



  void
  OctavePrintVisitor::visit(const UnsignedImmediate &i)
  {
    m_outputStream << i.getValue();
  }


  void
  OctavePrintVisitor::visit(const SignedImmediate &i)
  {
    m_outputStream << i.getValue();
  }

  void
  OctavePrintVisitor::visit(const OpndLabel &l)
  {
    m_outputStream << l.getName();
  }

  void
  OctavePrintVisitor::visit(const PlusOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " + ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const MinusOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " - ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const MultiplyOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " * ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const DivOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " / ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const ModulusOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " % ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const LeftShiftOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " << ";
    right->accept(*this);
  }


  void
  OctavePrintVisitor::visit(const RightShiftOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " >> ";
    right->accept(*this);
  }


  void
  OctavePrintVisitor::visit(const BitWiseAndOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " & ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const BitWiseOrOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " | ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const BitWiseXorOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " ^ ";
    right->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const ParenthesesOp &expr)
  {
    shared_ptr<const LlirOperand> opnd = expr.getOpnd();
    m_outputStream << " ( ";
    opnd->accept(*this);
    m_outputStream << " ) ";
  }

  void
  OctavePrintVisitor::visit(const UnaryMinusOp &expr)
  {
    shared_ptr<const LlirOperand> opnd = expr.getOpnd();
    m_outputStream << "-";
    opnd->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const ImpliedBase2Offset &mem)
  {
    mem.getOffset()->accept(*this); 
  }

  void
  OctavePrintVisitor::visit(const RegPlusOffsetIndirect &mem)
  {
    mem.getOffset()->accept(*this); 
    m_outputStream << " (";
    mem.getBaseRegister()->accept(*this);
    m_outputStream << ')';
  }

  void
  OctavePrintVisitor::visit(const Base2PlusOffset &mem)
  {
    m_outputStream << "BASE2 ";
    mem.getOffset()->accept(*this);;
  }

  void
  OctavePrintVisitor::visit(const Base3PlusOffset &mem)
  {
    m_outputStream << "BASE3 ";
    mem.getOffset()->accept(*this);;
  }

  void
  OctavePrintVisitor::visit(const LlirSequence &sequence)
  {
    m_outputStream << "; sequence" << "\n";
  }

  void
  OctavePrintVisitor::visit(const LlirLineControlDirective &lineCtrl)
  {
    m_outputStream << "# " << lineCtrl.getLineCntrlNum() << " ";
    m_outputStream << string("\"");
    m_outputStream << lineCtrl.getAsmFileName();
    m_outputStream << string("\"");

    if (lineCtrl.getLineCntrlFlagType() != LlirLineControlDirective::LCD_NONE)
      m_outputStream << " " << (int) lineCtrl.getLineCntrlFlagType();
   
    //m_outputStream << "\n";
  }

  void
  OctavePrintVisitor::visit(const NullNode  &null)
  {
    m_outputStream << null.getLineNum() << "NULL_NODE";
  }


  void
  OctavePrintVisitor::visit(const NewLineNode  &nl)
  {
    m_outputStream << nl.getNewLineString();
  }


  void
  OctavePrintVisitor::visit(const NullInstruction  &null)
  {
    m_outputStream << null.getLineNum() << "NULL_INSTRUCTION_NODE";
  }


  void
  OctavePrintVisitor::visit(const OctaveBlock &block)
  {
    m_outputStream << ".block";
    if (block.getName().empty() == false)
      m_outputStream << " " << block.getName();

    //    endOfLine(); <-- not needed

    LlirNode::ConstIterator it = block.begin();
    for (; it != block.end(); it++)
      {
	unsigned int lineNum = (*it)->getLineNum();

	if (lineNum >= m_lineNum)
	  {
	    printBlankLines(lineNum - m_lineNum);
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Print Visitor Line number mismatch") ;
	  }

	(*it)->accept(*this);

	//endOfLine(); <-- not needed
      }
  }

  void
  OctavePrintVisitor::visit(const OctaveMacroBlock &macroBlk)
  {

    m_outputStream << ".macro";

    ++m_macroDepth;
    m_inMacroBlock = true;

    LlirNode::ConstIterator it = macroBlk.begin();

    for (; it != macroBlk.end(); it++)
      {
	unsigned int lineNum = (*it)->getLineNum();

	//all the nodes in a .macro will have the
	//same line numbers as that of .macro

	assert(lineNum == m_lineNum);

	printBlankLines(1);

	(*it)->accept(*this);

	//endOfLine();  <-- not needed
      }

  }

  void
  OctavePrintVisitor::visit(const OctaveImplicitBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      {
	unsigned int lineNum = (*it)->getLineNum();

	if (lineNum >= m_lineNum)
	  {
	    printBlankLines(lineNum - m_lineNum);
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Print Visitor Line number mismatch") ;
	  }

	(*it)->accept(*this);

	//endOfLine(); <<-- not needed

      }

    endOfLine(); // needed, end of whole source input.

  }

  void
  OctavePrintVisitor::printBlankLines(unsigned int numBlankLines)
  {
    for (unsigned int i = 0; i < numBlankLines; i++)
      {
	// m_outputStream << '\n';
	// m_lineNum++;

	endOfLine();
      }
  }

  void
  OctavePrintVisitor::visit(const Lo17Op &expr)
  {
    m_outputStream << "lo17(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctavePrintVisitor::visit(const Hi16Op &expr)
  {
    m_outputStream << "hi16(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctavePrintVisitor::visit(const Lo16Op &expr)
  {
    m_outputStream << "lo16(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctavePrintVisitor::visit(const WordOp &expr)
  {
    m_outputStream << "word(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctavePrintVisitor::visit(const Mod2Flag&)
  {
    m_outputStream << "MOD2";
  }

  void
  OctavePrintVisitor::visit(const Mod4Flag&)
  {
    m_outputStream << "MOD4";
  }

  void
  OctavePrintVisitor::visit(const Mod8Flag&)
  {
    m_outputStream << "MOD8";
  }
  void
  OctavePrintVisitor::visit(const Mod16Flag&)
  {
    m_outputStream << "MOD16";
  }

  void
  OctavePrintVisitor::visit(const Mod32Flag&)
  {
    m_outputStream << "MOD32";
  }

  void
  OctavePrintVisitor::visit(const Mod64Flag&)
  {
    m_outputStream << "MOD64";
  }

  void
  OctavePrintVisitor::visit(const Mod128Flag&)
  {
    m_outputStream << "MOD128";
  }

  void
  OctavePrintVisitor::visit(const Mod256Flag&)
  {
    m_outputStream << "MOD256";
  }

  void
  OctavePrintVisitor::visit(const Mod512Flag&)
  {
    m_outputStream << "MOD512";
  }

  void
  OctavePrintVisitor::visit(const Mod1KFlag&)
  {
    m_outputStream << "MOD1K";
  }

  void
  OctavePrintVisitor::visit(const Mod2KFlag&)
  {
    m_outputStream << "MOD2K";
  }

  void
  OctavePrintVisitor::visit(const Mod4KFlag&)
  {
    m_outputStream << "MOD4K";
  }

  void
  OctavePrintVisitor::visit(const Mod8KFlag&)
  {
    m_outputStream << "MOD8K";
  }
  void
  OctavePrintVisitor::visit(const Mod16KFlag&)
  {
    m_outputStream << "MOD16K";
  }

  void
  OctavePrintVisitor::visit(const Mod32KFlag&)
  {
    m_outputStream << "MOD32K";
  }

  void
  OctavePrintVisitor::visit(const Mod64KFlag&)
  {
    m_outputStream << "MOD64K";
  }

  void
  OctavePrintVisitor::visit(const Mod128KFlag&)
  {
    m_outputStream << "MOD128K";
  }

  void
  OctavePrintVisitor::visit(const Mod256KFlag&)
  {
    m_outputStream << "MOD256K";
  }

  void
  OctavePrintVisitor::visit(const Mod512KFlag&)
  {
    m_outputStream << "MOD512K";
  }

  void
  OctavePrintVisitor::visit(const Mod1MFlag&)
  {
    m_outputStream << "MOD1M";
  }

  void
  OctavePrintVisitor::visit(const Mod2MFlag&)
  {
    m_outputStream << "MOD2M";
  }

  void
  OctavePrintVisitor::visit(const Mod4MFlag&)
  {
    m_outputStream << "MOD4M";
  }

  void
  OctavePrintVisitor::visit(const Mod8MFlag&)
  {
    m_outputStream << "MOD8M";
  }
  void
  OctavePrintVisitor::visit(const Mod16MFlag&)
  {
    m_outputStream << "MOD16M";
  }

  void
  OctavePrintVisitor::visit(const Mod32MFlag&)
  {
    m_outputStream << "MOD32M";
  }

  void
  OctavePrintVisitor::visit(const Mod64MFlag&)
  {
    m_outputStream << "MOD64M";
  }

  void
  OctavePrintVisitor::visit(const Mod128MFlag&)
  {
    m_outputStream << "MOD128M";
  }

  void
  OctavePrintVisitor::visit(const Mod256MFlag&)
  {
    m_outputStream << "MOD256M";
  }

  void
  OctavePrintVisitor::visit(const Mod512MFlag&)
  {
    m_outputStream << "MOD512M";
  }


  void
  OctavePrintVisitor::visit(const Mod1GFlag&)
  {
    m_outputStream << "MOD1G";
  }

  void
  OctavePrintVisitor::visit(const Mod2GFlag&)
  {
    m_outputStream << "MOD2G";
  }

  void
  OctavePrintVisitor::visit(const BZFlag&)
  {
    m_outputStream << "BZ";
  }

  void
  OctavePrintVisitor::visit(const BNCFlag&)
  {
    m_outputStream << "BNC";
  }

  void
  OctavePrintVisitor::visit(const BNOFlag&)
  {
    m_outputStream << "BNO";
  }

  void
  OctavePrintVisitor::visit(const BGEZFlag&)
  {
    m_outputStream << "BGEZ";
  }

  void
  OctavePrintVisitor::visit(const BLZFlag&)
  {
    m_outputStream << "BLZ";
  }

  void
  OctavePrintVisitor::visit(const BNZFlag&)
  {
    m_outputStream << "BNZ";
  }

  void
  OctavePrintVisitor::visit(const BLEZFlag&)
  {
    m_outputStream << "BLEZ";
  }

  void
  OctavePrintVisitor::visit(const BALBFlag&)
  {
    m_outputStream << "BALB";
  }

  void
  OctavePrintVisitor::visit(const BAEBFlag&)
  {
    m_outputStream << "BAEB";
  }

  void
  OctavePrintVisitor::visit(const BAGBFlag&)
  {
    m_outputStream << "BAGB";
  }

  void
  OctavePrintVisitor::visit(const BANEBFlag&)
  {
    m_outputStream << "BANEB";
  }

  void
  OctavePrintVisitor::visit(const BAGEBFlag&)
  {
    m_outputStream << "BAGEB";
  }

  void
  OctavePrintVisitor::visit(const BALEBFlag&)
  {
    m_outputStream << "BALEB";
  }

  void
  OctavePrintVisitor::visit(const Ess0Flag &flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS0";
  }

  void
  OctavePrintVisitor::visit(const Ess1Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS1";
  }

  void
  OctavePrintVisitor::visit(const Ess2Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS2";
  }

  void
  OctavePrintVisitor::visit(const Ess3Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS3";
  }

  void
  OctavePrintVisitor::visit(const Ess4Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS4";
  }

  void
  OctavePrintVisitor::visit(const Ess5Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS5";
  }

  void
  OctavePrintVisitor::visit(const Ess6Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS6";
  }

  void
  OctavePrintVisitor::visit(const Ess7Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS7";
  }

  void
  OctavePrintVisitor::visit(const Ess8Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS8";
  }

  void
  OctavePrintVisitor::visit(const Ess9Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS9";
  }

  void
  OctavePrintVisitor::visit(const Ess10Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS10";
  }

  void
  OctavePrintVisitor::visit(const Ess11Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS11";
  }

  void
  OctavePrintVisitor::visit(const Ess12Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS12";
  }

  void
  OctavePrintVisitor::visit(const Ess13Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS13";
  }

  void
  OctavePrintVisitor::visit(const Ess14Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS14";
  }

  void
  OctavePrintVisitor::visit(const Ess15Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS15";
  }

  void
  OctavePrintVisitor::visit(const Ess16Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS16";
  }


  void
  OctavePrintVisitor::visit(const Ess17Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS17";
  }

  void
  OctavePrintVisitor::visit(const Ess18Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS18";
  }

  void
  OctavePrintVisitor::visit(const Ess19Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS19";
  }

  void
  OctavePrintVisitor::visit(const Ess20Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS20";
  }

  void
  OctavePrintVisitor::visit(const Ess21Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS21";
  }

  void
  OctavePrintVisitor::visit(const Ess22Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS22";
  }

  void
  OctavePrintVisitor::visit(const Ess23Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS23";
  }

  void
  OctavePrintVisitor::visit(const Ess24Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS24";
  }

  void
  OctavePrintVisitor::visit(const Ess25Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS25";
  }

  void
  OctavePrintVisitor::visit(const Ess26Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS26";
  }

  void
  OctavePrintVisitor::visit(const Ess27Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS27";
  }

  void
  OctavePrintVisitor::visit(const Ess28Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS28";
  }

  void
  OctavePrintVisitor::visit(const Ess29Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS29";
  }

  void
  OctavePrintVisitor::visit(const Ess30Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS30";
  }

  void
  OctavePrintVisitor::visit(const Ess31Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS31";
  }

  //

  void
  OctavePrintVisitor::visit(const C0Flag&)
  {
    m_outputStream << "C0";
  }

  void
  OctavePrintVisitor::visit(const C1Flag&)
  {
    m_outputStream << "C1";
  }

  void
  OctavePrintVisitor::visit(const C2Flag&)
  {
    m_outputStream << "C2";
  }

  void
  OctavePrintVisitor::visit(const C3Flag&)
  {
    m_outputStream << "C3";
  }

  void
  OctavePrintVisitor::visit(const C4Flag&)
  {
    m_outputStream << "C4";
  }

  void
  OctavePrintVisitor::visit(const C5Flag&)
  {
    m_outputStream << "C5";
  }

  void
  OctavePrintVisitor::visit(const C6Flag&)
  {
    m_outputStream << "C6";
  }

  void
  OctavePrintVisitor::visit(const C7Flag&)
  {
    m_outputStream << "C7";
  }

  void
  OctavePrintVisitor::visit(const C8Flag&)
  {
    m_outputStream << "C8";
  }

  void
  OctavePrintVisitor::visit(const C9Flag&)
  {
    m_outputStream << "C9";
  }

  void
  OctavePrintVisitor::visit(const C10Flag&)
  {
    m_outputStream << "C10";
  }

  void
  OctavePrintVisitor::visit(const C11Flag&)
  {
    m_outputStream << "C11";
  }

  void
  OctavePrintVisitor::visit(const C12Flag&)
  {
    m_outputStream << "C12";
  }

  void
  OctavePrintVisitor::visit(const C13Flag&)
  {
    m_outputStream << "C13";
  }

  void
  OctavePrintVisitor::visit(const C14Flag&)
  {
    m_outputStream << "C14";
  }

  void
  OctavePrintVisitor::visit(const C15Flag&)
  {
    m_outputStream << "C15";
  }

  void
  OctavePrintVisitor::visit(const LNK1Flag &)
  {
    m_outputStream << "LNK1";
  }

  void
  OctavePrintVisitor::visit(const LNK2Flag &)
  {
    m_outputStream << "LNK2";
  }

  void
  OctavePrintVisitor::visit(const LNK3Flag &)
  {
    m_outputStream << "LNK3";
  }

  void
  OctavePrintVisitor::visit(const UNLNKFlag &)
  {
    m_outputStream << "UNLNK";
  }

  void
  OctavePrintVisitor::visit(const DLNKFlag &)
  {
    m_outputStream << "DLNK";
  }

  void
  OctavePrintVisitor::visit(const PREFlag &)
  {
    m_outputStream << "PRE";
  }

  void
  OctavePrintVisitor::visit(const FLUSHFlag &)
  {
    m_outputStream << "FLUSH";
  }

  void
  OctavePrintVisitor::visit(const BFFlag &)
  {
    m_outputStream << "BF";
  }

  void
  OctavePrintVisitor::visit(const CFlag &)
  {
    m_outputStream << "C";
  }

  void
  OctavePrintVisitor::visit(const Ascii &directive)
  {
    m_outputStream << ".ascii " << directive.getAsciiString();
  }

  void
  OctavePrintVisitor::visit(const List &directive)
  {
    m_outputStream << ".list";
  }

  void
  OctavePrintVisitor::visit(const NoList &directive)
  {
    m_outputStream << ".nolist";
  }

  void
  OctavePrintVisitor::visit(const Text &directive)
  {
    m_outputStream << ".text";
  }

  void
  OctavePrintVisitor::visit(const Data &directive)
  {
    m_outputStream << ".data";
  }

  void
  OctavePrintVisitor::visit(const Comm &directive)
  {
    m_outputStream << ".comm " << directive.getName() << "," << directive.getSize();
  }

  void
  OctavePrintVisitor::visit(const Lcomm &directive)
  {
    m_outputStream << ".lcomm " << directive.getName() << "," << directive.getSize();
  }

  void
  OctavePrintVisitor::visit(const NamedSection &directive)
  {
    m_outputStream << ".section " << directive.getName();
  }

  void
  OctavePrintVisitor::visit(const EndMacro &directive)
  {
    m_outputStream << ".endm ";  // Don't get rid of that space, the backend assembler depends on it (not joking)

    m_macroDepth -= 1;

    if(m_macroDepth == 0)
      {
	m_inMacroBlock = false;
      }

  }

  void
  OctavePrintVisitor::visit(const Align &directive)
  {
    m_outputStream << ".align " << directive.getSize();
  }

  void
  OctavePrintVisitor::visit(const Ref &directive)
  {
    m_outputStream << ".ref " << directive.getLabel();
  }

  void
  OctavePrintVisitor::visit(const UnNamedEndBlock &directive)
  {
    m_outputStream << ".endblock";
  }

  void
  OctavePrintVisitor::visit(const NamedEndBlock &directive)
  {
#if 0
    m_outputStream << ".endblock " << directive.getName();
#else
    m_outputStream << ".endblock"; // The back-end assembler does not support named endblocks at the moment
#endif
  }

  void
  OctavePrintVisitor::visit(const Org &directive)
  {
    m_outputStream << ".org " << directive.getNumBytes();
  }

  void
  OctavePrintVisitor::visit(const OrgWithFillValue &directive)
  {
    m_outputStream << ".org " << directive.getNumBytes() << " " << directive.getFillValue();
  }

  void
  OctavePrintVisitor::visit(const StructBeginDirective &directive)
  {
    m_outputStream << ".structure " << directive.getName();
  }

  void
  OctavePrintVisitor::visit(const StructEndDirective &directive)
  {
    m_outputStream << ".ends";
  }

  void
  OctavePrintVisitor::visit(const MapDirective &directive)
  {
    m_outputStream << ".map " << directive.getMapPath() << " " << directive.getMapName() << " ";
    shared_ptr<const Register> mappedReg = directive.getMappedSymbol()->getRegister();

    //the mappedReg could be multi or single reg.
    //but existing mxtas cannot handle multi reg.
    //so - print only single regsiter
    mappedReg->getRegister(0)->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const ScopedMapDirective &directive)
  {
    m_outputStream << ";.smap " << directive.getMapPath() << " " << directive.getMapName() << " ";
//     shared_ptr<const Register> mappedReg = directive.getMappedSymbol()->getRegister();
//     mappedReg->accept(*this);
  }

  void
  OctavePrintVisitor::visit(const UnmapDirective &directive)
  {
    m_outputStream << ".unmap " << directive.getName();
  }

  void
  OctavePrintVisitor::visit(const Field &fld)
  {
    m_outputStream << fld.getName();
  }

  void
  OctavePrintVisitor::visit(const BitField &fld)
  {
    m_outputStream << fld.getName() << '(' << fld.getMSBitPosition() << ':' << fld.getLSBitPosition() << ')';
  }

  void
  OctavePrintVisitor::visit(const ElementDirective &directive)
  {
    m_outputStream << ".element ";

    shared_ptr<const Element> el = directive.getElementDecl();
   
    Type::ConstIterator iter = el->begin(); 

    //print first AbstractField
   
    shared_ptr<const Field> fld;
    shared_ptr<const BitField> bfld;

    fld = shared_dynamic_cast<const Field>(*iter);
   
    if(fld) 
      {
	fld->accept(*this);
      }
    else 
      {
        bfld = shared_dynamic_cast<const BitField>(*iter);

        if(bfld)
	  {
	    bfld->accept(*this);
	  }
	else
	  {

	    throw LLIR_INTERNAL_EXCEPTION("Unknown Field Type") ;
	  }
      }

    ++iter;

    //print rest of AbstractFields with comma seperators

    for(; iter != el->end(); iter++)
      {
	fld = shared_dynamic_cast<const Field>(*iter);

	m_outputStream << " , ";
	
	if(fld)
	  {
	    fld->accept(*this);
	  }
	else
	  {
	    bfld = shared_dynamic_cast<const BitField>(*iter);

	    if(bfld)
	      {
		bfld->accept(*this);
	      }
	    else
	      {
		throw LLIR_INTERNAL_EXCEPTION("Unknown Field Type") ;
	      }
	  }

      }
  }

  void 
  OctavePrintVisitor::printDatumList(const AllocMemoryDirective &directive)
  {
    AllocMemoryDirective::ConstIterator it = directive.datumBegin();

    if(it != directive.datumEnd())
      {
	// Get the first datum and print it
	shared_ptr<Datum> d = *it++;
	(d->getDatum())->accept(*this);
	if (d->getRepCount() != 1)
	  m_outputStream << '[' << d->getRepCount() << ']';
	
	for (; it != directive.datumEnd(); it++)
	  {
	    m_outputStream << ',';
	    (*it)->getDatum()->accept(*this);
	    if ((*it)->getRepCount() != 1)
	      m_outputStream << '[' << (*it)->getRepCount() << ']';
	  }
      }
  }
    
  void
  OctavePrintVisitor::visit(const LocalLabel &label)
  {
    m_outputStream << label.getLabelName() << ':';
  }

  void
  OctavePrintVisitor::visit(const GlobalLabel &label)
  {
    m_outputStream << label.getLabelName() << "::";
  }

  void
  OctavePrintVisitor::visit(const FileScopeLabel &label)
  {
    m_outputStream << label.getLabelName() << ":=";
  }

  void
  OctavePrintVisitor::visit(const Byte &directive)
  {
    m_outputStream << ".byte ";
    printDatumList(directive);
  }

  void
  OctavePrintVisitor::visit(const Word &directive)
  {
    m_outputStream << ".word ";
    printDatumList(directive);
  }

  void
  OctavePrintVisitor::visit(const HalfWord &directive)
  {
    m_outputStream << ".halfword ";
    printDatumList(directive);
  }

  void
  OctavePrintVisitor::visit(const CbranchFlags &cbranch)
  {
    CbranchFlags::ConstIterator it = cbranch.begin();
    CbranchFlags::ConstIterator end = cbranch.end();

    for (; it != end; it++)
      {
	(*it)->accept(*this);
	m_outputStream << " ";
      }
  }

  void
  OctavePrintVisitor::visit(const BrslFlags &brsl)
  {
    BrslFlags::ConstIterator it = brsl.begin();
    BrslFlags::ConstIterator end = brsl.end();

    for (; it != end; it++)
      {
	(*it)->accept(*this);
	m_outputStream << " ";
      }
  }

  void
  OctavePrintVisitor::printTSSFlags(const TrafficScheduleFlags &tssflags)
  {
    TrafficScheduleFlags::ConstIterator it = tssflags.begin();
    TrafficScheduleFlags::ConstIterator end = tssflags.end();

    for (; it != end; it++)
      {
	(*it)->accept(*this);
	m_outputStream << " ";
      }
  }

  void 
  OctavePrintVisitor::visit(const TrafficScheduleFlags &tssFlags)
  {
    printTSSFlags(tssFlags);  //FIXME : cleanup
  }

  void
  OctavePrintVisitor::visit(const PolFlags &pol)
  {
    printTSSFlags(pol);
  }

  void
  OctavePrintVisitor::visit(const PutFlags &put)
  {
    printTSSFlags(put);
  }

  void
  OctavePrintVisitor::visit(const GetFlags &get)
  {
    printTSSFlags(get);
  }

  void
  OctavePrintVisitor::visit(const SXFlag &)
  {
    m_outputStream << "SX";
  }

  void
  OctavePrintVisitor::visit(const FindFlag &)
  {
    m_outputStream << "ZB";
  }

  void
  OctavePrintVisitor::visit(const CumeFlag &)
  {
    m_outputStream << "CUME";
  }

  void
  OctavePrintVisitor::visit(const DepbFlag &)
  {
    m_outputStream << "Z";
  }

  void
  OctavePrintVisitor::visit(const DIFlag &)
  {
    m_outputStream << "DI";
  }

  void
  OctavePrintVisitor::visit(const SignFlag &)
  {
    m_outputStream << "SIGN";
  }

  void
  OctavePrintVisitor::visit(const CDFlag &)
  {
    m_outputStream << "CD";
  }

  void
  OctavePrintVisitor::visit(const GC1AFlag &)
  {
    m_outputStream << "GC1A";
  }

  void
  OctavePrintVisitor::visit(const GC1BFlag &)
  {
     m_outputStream << "GC1B";
  }

  void
  OctavePrintVisitor::visit(const GSTICKFlag &)
  {
     m_outputStream << "GSTICK";
  }

  void
  OctavePrintVisitor::visit(const NULFlag &)
  {
     m_outputStream << "NUL";
  }

  void
  OctavePrintVisitor::visit(const GC1OFlag &)
  {
     m_outputStream << "GC1O";
  }

  void
  OctavePrintVisitor::visit(const GC2AFlag &)
  {
     m_outputStream << "GC2A";
  }

  void
  OctavePrintVisitor::visit(const GC2BFlag &)
  {
     m_outputStream << "GC2B";
  }

  void
  OctavePrintVisitor::visit(const GC2OFlag &)
  {
     m_outputStream << "GC2O";
  }

  void
  OctavePrintVisitor::visit(const GPAFlag &)
  {
     m_outputStream << "GPA";
  }

  void
  OctavePrintVisitor::visit(const GPUFlag &)
  {
     m_outputStream << "GPU";
  }

  void
  OctavePrintVisitor::visit(const GPBFlag &)
  {
     m_outputStream << "GPB";
  }

  void
  OctavePrintVisitor::visit(const GTAFlag &)
  {
     m_outputStream << "GTA";
  }

  void
  OctavePrintVisitor::visit(const GTOFlag &)
  {
     m_outputStream << "GTO";
  }

  void
  OctavePrintVisitor::visit(const GTBFlag &)
  {
     m_outputStream << "GTB";
  }

  void
  OctavePrintVisitor::visit(const FPFlag &)
  {
     m_outputStream << "FP";
  }

  void
  OctavePrintVisitor::visit(const NG2Flag &)
  {
     m_outputStream << "NG2";
  }

  void
  OctavePrintVisitor::visit(const GZFlag &)
  {
     m_outputStream << "GZ";
  }


  void
  OctavePrintVisitor::visit(const OAMFlag &)
  {
     m_outputStream << "OAM";
  }

  void
  OctavePrintVisitor::visit(const RPFlag &)
  {
     m_outputStream << "RP";
  }

  void
  OctavePrintVisitor::visit(const LOGFlag &)
  {
     m_outputStream << "LOG";
  }

  void
  OctavePrintVisitor::visit(const FPBFlag &)
  {
     m_outputStream << "FPB";
  }

  void
  OctavePrintVisitor::visit(const CSBFlag &)
  {
     m_outputStream << "CSB";
  }

  void
  OctavePrintVisitor::visit(const DELETEFlag &)
  {
     m_outputStream << "DELETE";
  }

  void
  OctavePrintVisitor::visit(const NBFlag &)
  {
     m_outputStream << "NB";
  }

  void
  OctavePrintVisitor::visit(const NCFlag &)
  {
     m_outputStream << "NC";
  }

  void
  OctavePrintVisitor::visit(const GWFlag &)
  {
     m_outputStream << "GW";
  }

  void
  OctavePrintVisitor::visit(const GRFlag &)
  {
     m_outputStream << "GR";
  }

  void
  OctavePrintVisitor::visit(const AFlag &)
  {
     m_outputStream << "A";
  }

  void
  OctavePrintVisitor::visit(const RFlag &)
  {
     m_outputStream << "R";
  }

  void
  OctavePrintVisitor::visit(const GUFlag &)
  {
     m_outputStream << "GU";
  }

  void
  OctavePrintVisitor::visit(const TFlag &)
  {
     m_outputStream << "T";
  }

  void
  OctavePrintVisitor::visit(const RBFlag &)
  {
     m_outputStream << "RB";
  }

  void
  OctavePrintVisitor::visit(const FBFlag &)
  {
     m_outputStream << "FB";
  }

  void
  OctavePrintVisitor::visit(const SFlag &)
  {
     m_outputStream << "S";
  }

  void
  OctavePrintVisitor::visit(const NTFlag &)
  {
     m_outputStream << "NT";
  }

  void
  OctavePrintVisitor::visit(const IFlag &)
  {
     m_outputStream << "I";
  }

  void
  OctavePrintVisitor::visit(const FRFlag &)
  {
     m_outputStream << "FR";
  }

  void
  OctavePrintVisitor::visit(const RSCHFlag &)
  {
     m_outputStream << "RSCH";
  }

  void
  OctavePrintVisitor::visit(const CLOSEFlag &)
  {
     m_outputStream << "CLOSE";
  }

  void
  OctavePrintVisitor::visit(const NEFlag &)
  {
     m_outputStream << "NE";
  }

  void
  OctavePrintVisitor::visit(const MeetsDirective  &d)
  {
    //should be blank line in the output
    m_outputStream << ";.meets" << " " << d.getTestedPath() << " " << d.getReferencePath();
  }

  void
  OctavePrintVisitor::visit(const AssertDirective  &d)
  {
    //should be blank line in the output
    m_outputStream << ";.assert" << " ";
    d.getExpr()->accept(*this); m_outputStream << " ";
    m_outputStream << d.getAssertMsg();
  }

  void
  OctavePrintVisitor::visit(const WarningDirective  &d)
  {
    //should be blank line in the output
    m_outputStream << ";.warning" << " ";
    m_outputStream << d.getWarningMsg();
  }

  void
  OctavePrintVisitor::visit(const ErrorDirective  &d)
  {
    //should be blank line in the output
    m_outputStream << ";.error" << " ";
    m_outputStream << d.getErrorMsg();
  }

  void
  OctavePrintVisitor::visit(const SregisterDirective  &s)
  {
//     // The backend assembler does not support .sregister, 
//     // so we print the .sreg as a comment

    m_outputStream << ";.sreg ";
    m_outputStream << s.getSymRegName() << " ";
//     m_outputStream << " ="; s.getRegister()->accept(*this);
//     m_outputStream << " ";

//     /* I need to change this...

//        as per Michael's design methodology...
//        we need to have Contraint flag class and
//        call accept on that object...
//      */
//     if(s.getBeginRegConstraint() != AbstractSymReg::SRC_NONE)
//       {
// 	if(s.getBeginRegConstraint() == AbstractSymReg::SRC_BEGIN_AT_EVEN_REG)
// 	  {
// 	    m_outputStream << "@even ";
// 	  }
// 	else if(s.getBeginRegConstraint() == AbstractSymReg::SRC_BEGIN_AT_ODD_REG)
// 	  {
// 	    m_outputStream << "@odd ";
// 	  }
// 	else
// 	  {
// 	    //throw internal error...
// 	    //unknown reg constraint flag...
// 	  }
//       }

//     if(! shared_dynamic_cast<const NullRegister>(s.getConstraintRegRange()))
//       {
// 	m_outputStream << "@from( ";
// 	s.getConstraintRegRange()->accept(*this);
// 	m_outputStream << " )";
//       }
  }

  void
  OctavePrintVisitor::visit(const InvalidOctaveInstruction  &i)
  {
    throw LLIR_INTERNAL_EXCEPTION("Cannot print a InvalidOctaveInstruction") ;
  }


  void 
  OctavePrintVisitor::visit(const  LabelList &d) 
  {
    if(d.begin() == d.end())
      {
	throw LLIR_INTERNAL_EXCEPTION("empty label list created") ;
	return;
      }

    LabelList::ConstIterator iter = d.begin();
    m_outputStream << d.getLabel(0)->getName();
    ++iter;

    for(; iter != d.end(); iter++)
      {
	m_outputStream << ",";
	m_outputStream << (*iter)->getName();
      }
    
	      
    m_outputStream << " ";

    //NOTE: not calling accept on the LabelSymbol because
    //it would print the scope qualifier too...
  }
  

  void 
  OctavePrintVisitor::printRegList(shared_ptr<const RegList> d)
  {
    if(!d->isEmpty())
      {
	RegList::ConstIterator iter = d->begin();
    
	shared_ptr<const HardRegister> reg = shared_dynamic_cast<const HardRegister>(iter->second);

	bool printComma = false;

	if(reg)
	  {
	    m_outputStream << " ";
	    reg->accept(*this);
	    ++iter;
	    printComma = true;
	  }

	for(; iter != d->end(); iter++)
	  {

	    shared_ptr<const HardRegister> reg = shared_dynamic_cast<const HardRegister>(iter->second);

	    if(reg)
	      {
		if(printComma)
		  {
		    m_outputStream << ",";
		  }
		else
		  {
		    m_outputStream << " ";
		    printComma = true;
		  }

		iter->second->accept(*this);
	      }
	  }

	m_outputStream << " ";
      }
  }

  void 
  OctavePrintVisitor::visit(const  GlobalRegisterList &d) 
  {
    printRegList(d.getRegList());
  }

  void 
  OctavePrintVisitor::visit(const ArgList &d)
  {
    m_outputStream << "@args(";
    printRegList(d.getRegList());
    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const ResultList &d)
  {
    m_outputStream << "@results(";
    printRegList(d.getRegList());
    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const ScratchList &d)
  {
    m_outputStream << "@scratch(";
    printRegList(d.getRegList());
    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const RegLnksListToSPRAM &d)
  {
    m_outputStream << "@linkedsp( ";

    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }


    m_outputStream << " ) ";
  }

  void 
  OctavePrintVisitor::visit(const RegLnksListToLockedSPRAM &d)
  {
    m_outputStream << "@linkedspl(";
 
    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }

    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const RegLnksListToSRAM &d)
  {
    m_outputStream << "@linkedsr(";
  

    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }

    m_outputStream << ") ";
  }
  
  void 
  OctavePrintVisitor::visit(const RegLnksListToSDRAM &d)
  {
    m_outputStream << "@linkedsd(";

    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }
    
    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const RegLnksListToCCRAM &d)
  {
    m_outputStream << "@linkedcc(";
  
    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }

    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const RegLnksListToLockedCCRAM &d)
  {
    m_outputStream << "@linkedccl(";
 
    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }


    m_outputStream << ") ";
  }

  void 
  OctavePrintVisitor::visit(const RegLnksListToSIO &d) 
  {
    m_outputStream << "@linkedsio(";
  
    if(! d.getRegListLnk1()->isEmpty())
      {
	m_outputStream << "@lnk1( ";
	printRegList(d.getRegListLnk1());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk2()->isEmpty())
      {
	m_outputStream << "@lnk2( ";
	printRegList(d.getRegListLnk2());
	m_outputStream << " ) ";
      }

    if(! d.getRegListLnk3()->isEmpty())
      {
	m_outputStream << "@lnk3( ";
	printRegList(d.getRegListLnk3());
	m_outputStream << " ) ";
      }

    m_outputStream << ") ";
  }



  void 
  OctavePrintVisitor::visit(const  GlobalDirective &d) 
  {
    m_outputStream << ";.global ";
    d.getGlobalRegList()->accept(*this);

    if(! d.getRegLnksListToSPRAM()->isEmpty())
      d.getRegLnksListToSPRAM()->accept(*this);

    if(! d.getRegLnksListToLockedSPRAM()->isEmpty())
      d.getRegLnksListToLockedSPRAM()->accept(*this);

    if(! d.getRegLnksListToSRAM()->isEmpty())
      d.getRegLnksListToSRAM()->accept(*this);

    if(! d.getRegLnksListToSDRAM()->isEmpty())
      d.getRegLnksListToSDRAM()->accept(*this);

    if(! d.getRegLnksListToCCRAM()->isEmpty())
      d.getRegLnksListToCCRAM()->accept(*this);

    if(! d.getRegLnksListToLockedCCRAM()->isEmpty())
      d.getRegLnksListToLockedCCRAM()->accept(*this);

    if(! d.getRegLnksListToSIO()->isEmpty())
      d.getRegLnksListToSIO()->accept(*this);
  }

  void 
  OctavePrintVisitor::visit(const  MultipleEntryEvh &d) 
  {
    m_outputStream << ".block ;.evh ";

    d.getEntryPtList()->accept(*this);
    m_outputStream << " ";

    d.getArgList()->accept(*this);
    d.getResultList()->accept(*this);
    d.getScratchList()->accept(*this);



    if(! d.getRegLnksListToSPRAM()->isEmpty())
      d.getRegLnksListToSPRAM()->accept(*this);

    if(! d.getRegLnksListToLockedSPRAM()->isEmpty())
      d.getRegLnksListToLockedSPRAM()->accept(*this);

    if(! d.getRegLnksListToSRAM()->isEmpty())
      d.getRegLnksListToSRAM()->accept(*this);

    if(! d.getRegLnksListToSDRAM()->isEmpty())
      d.getRegLnksListToSDRAM()->accept(*this);

    if(! d.getRegLnksListToCCRAM()->isEmpty())
      d.getRegLnksListToCCRAM()->accept(*this);

    if(! d.getRegLnksListToLockedCCRAM()->isEmpty())
      d.getRegLnksListToLockedCCRAM()->accept(*this);

    if(! d.getRegLnksListToSIO()->isEmpty())
      d.getRegLnksListToSIO()->accept(*this);


    d.getImplicitBlock()->accept(*this);

  }

  void 
  OctavePrintVisitor::visit(const  EndEvhDirective &d) 
  {
    m_outputStream << ".endblock ;.endevh ";
    m_outputStream << d.getFirstEntryPtLabel()->getName();

  }

  void 
  OctavePrintVisitor::visit(const  MultipleEntryFunction &d) 
  {
    m_outputStream << ".block ;.entry ";
    m_outputStream << d.getEntryPtList()->getLabel(0)->getName();

    m_outputStream << "   ;; TOD ;;";

    //TOD........
    d.getArgList()->accept(*this);
    d.getResultList()->accept(*this);
    d.getScratchList()->accept(*this);
    d.getRegLnksListToSPRAM()->accept(*this);
    d.getRegLnksListToLockedSPRAM()->accept(*this);
    d.getRegLnksListToSRAM()->accept(*this);
    d.getRegLnksListToSDRAM()->accept(*this);
    d.getRegLnksListToCCRAM()->accept(*this);
    d.getRegLnksListToLockedCCRAM()->accept(*this);
    d.getRegLnksListToSIO()->accept(*this);
    //-------------

    d.getImplicitBlock()->accept(*this);



  }

  void 
  OctavePrintVisitor::visit(const  EndEntryDirective &d) 
  {
    m_outputStream << ".endblock ;.endentry ";
    m_outputStream << d.getEvhLabel()->getName();
  }

  void 
  OctavePrintVisitor::visit(const  PrototypeDirective &d) 
  {
    m_outputStream << ";.prototype ";

    d.getEntryPtList()->accept(*this);
    m_outputStream << " ";

    d.getArgList()->accept(*this);
    d.getResultList()->accept(*this);
    d.getScratchList()->accept(*this);


    if(! d.getRegLnksListToSPRAM()->isEmpty())
      d.getRegLnksListToSPRAM()->accept(*this);

    if(! d.getRegLnksListToLockedSPRAM()->isEmpty())
      d.getRegLnksListToLockedSPRAM()->accept(*this);

    if(! d.getRegLnksListToSRAM()->isEmpty())
      d.getRegLnksListToSRAM()->accept(*this);

    if(! d.getRegLnksListToSDRAM()->isEmpty())
      d.getRegLnksListToSDRAM()->accept(*this);

    if(! d.getRegLnksListToCCRAM()->isEmpty())
      d.getRegLnksListToCCRAM()->accept(*this);

    if(! d.getRegLnksListToLockedCCRAM()->isEmpty())
      d.getRegLnksListToLockedCCRAM()->accept(*this);

    if(! d.getRegLnksListToSIO()->isEmpty())
      d.getRegLnksListToSIO()->accept(*this);

  }

  void 
  OctavePrintVisitor::visit(const  IndirectCallTargetList &d) 
  {
    m_outputStream << ";@indcall "; 
    d.getLabelList()->accept(*this);
  }

  void 
  OctavePrintVisitor::visit(const  JtableBegin &d) 
  {
    m_outputStream << ";.jtablebegin "; 
    d.getLabelList()->accept(*this);
  }

  void 
  OctavePrintVisitor::visit(const  JtableEnd &d) 
  {
    m_outputStream << ";.jtableend "; 
  }

  void 
  OctavePrintVisitor::visit(const  JtableRelativeBegin &d) 
  {
    m_outputStream << ";.jtablebegin "; 
    d.getLabelList()->accept(*this);
  }

  void 
  OctavePrintVisitor::visit(const  JtableRelativeEnd &d) 
  {
    m_outputStream << ";.jtableend "; 
  }

  void
  OctavePrintVisitor::printNops(unsigned int num)
  {
    m_outputStream << endl;

    while(num)
      {
	m_outputStream << "\tnop";
	
	//do not print new line for the last nop
	if(num-1)
	  m_outputStream << endl;

	--num;
      }
  }

}




