#include <LlirFile.h>
#include <LlirException.h>

#include <iostream>

#include <OctaveNode.h>
#include <OctaveOperand.h>
#include <OctaveSymbol.h>
#include <OctaveInstructions.h>
#include "OctaveRtlPrintVisitor.h"

namespace Llir
{
  OctaveRtlPrintVisitor::OctaveRtlPrintVisitor(ostream &o) : 
    Visitor(), 
    LlirOctaveVisitor(),
    m_macroDepth(0),
    m_inMacroBlock(false),
    m_outputStream(o),
    m_lineNum(1)
  {}

  OctaveRtlPrintVisitor::~OctaveRtlPrintVisitor()
  {}

  std::ostream&
  OctaveRtlPrintVisitor::getOutputStream() const
  {
    return m_outputStream;
  }

  void
  OctaveRtlPrintVisitor::endOfLine()
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
  OctaveRtlPrintVisitor::printAlu2OpBranch(const Alu2OpBranchInstruction &i, const char *mneumonic)
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
  OctaveRtlPrintVisitor::printAlu2OpFind(const Alu2OpFindInstruction &i, const char *mneumonic)
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
  OctaveRtlPrintVisitor::printAlu3OpAbcMod(const Alu3OpAbcModInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printAlu3OpAbc(const Alu3OpAbcInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printAlu3OpSx(const Alu3OpSxInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printAlu3Op(const Alu3OpInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printCondBranch(const CondBranchInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printCondBranchImmed(const CondBranchImmedInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printZeroBranch(const ZeroBranchInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);
    getOutputStream() << " ";
    i.getCmpReg()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::printZeroBranchImmed(const ZeroBranchImmedInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);
    getOutputStream() << " ";
    i.getCmpReg()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::printTestBitBranch(const TestBitBranchInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printReturn(const ReturnOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    i.getDiFlag()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::printCompareBranch(const CompareOpBranchInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printCompareSign(const CompareOpSignInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printCmov(const CmovOpInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printDma(const DmaOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRegs()->accept(*this);
    getOutputStream() << " ";
    i.getDmaFlags()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::printLoadImmediate(const LoadImmediateInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getSrc()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::printLoadHalfword(const LoadHalfwordInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getSrc()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::printLink(const MultiRegLinkInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printLoad(const MultiRegLoadInstruction &i, const char *mnemonic)
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
  OctaveRtlPrintVisitor::printStore(const MultiRegStoreInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRegs()->accept(*this);
    getOutputStream() << " ";
    i.getMem()->accept(*this);
  }
  
  void
  OctaveRtlPrintVisitor::visit(const LlirFile &f)
  {
    LlirFile::ConstIterator iter = f.begin();

    for(; iter != f.end(); iter++)
      {
	(*iter)->accept(*this);
      }
  }
  
  void
  OctaveRtlPrintVisitor::visit(const HardRegister &reg)
  {
    m_outputStream << "r" << reg.getRegNum();
  }

  void
  OctaveRtlPrintVisitor::visit(const MultiHardRegister &reg)
  {
    shared_ptr<const Register> firstReg = reg.getRegister(0);
    shared_ptr<const Register> lastReg = reg.getRegister(reg.getNumRegs() - 1);

    firstReg->accept(*this);
    m_outputStream << "-";
    lastReg->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const UnsignedImmediate &i)
  {
    m_outputStream << i.getValue();
  }

  void
  OctaveRtlPrintVisitor::visit(const SignedImmediate &i)
  {
    m_outputStream << i.getValue();
  }

  void
  OctaveRtlPrintVisitor::visit(const OpndLabel &l)
  {
    m_outputStream << l.getMangledName();
  }

  void
  OctaveRtlPrintVisitor::visit(const PlusOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " + ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const MinusOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " - ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const MultiplyOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " * ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const DivOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " / ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const ModulusOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " % ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const LeftShiftOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " << ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const RightShiftOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " >> ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const BitWiseAndOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " & ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const BitWiseOrOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " | ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const BitWiseXorOp &expr)
  {
    shared_ptr<const LlirOperand> left = expr.getLeftOpnd();
    shared_ptr<const LlirOperand> right = expr.getRightOpnd();
    left->accept(*this);
    m_outputStream << " ^ ";
    right->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const ParenthesesOp &expr)
  {
    shared_ptr<const LlirOperand> opnd = expr.getOpnd();
    m_outputStream << " ( ";
    opnd->accept(*this);
    m_outputStream << " ) ";
  }

  void
  OctaveRtlPrintVisitor::visit(const UnaryMinusOp &expr)
  {
    shared_ptr<const LlirOperand> opnd = expr.getOpnd();
    m_outputStream << "-";
    opnd->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const ImpliedBase2Offset &mem)
  {
    mem.getOffset()->accept(*this); 
  }

  void
  OctaveRtlPrintVisitor::visit(const RegPlusOffsetIndirect &mem)
  {
    mem.getOffset()->accept(*this); 
    m_outputStream << " (";
    mem.getBaseRegister()->accept(*this);
    m_outputStream << ')';
  }

  void
  OctaveRtlPrintVisitor::visit(const Base2PlusOffset &mem)
  {
    m_outputStream << "BASE2 ";
    mem.getOffset()->accept(*this);;
  }

  void
  OctaveRtlPrintVisitor::visit(const Base3PlusOffset &mem)
  {
    m_outputStream << "BASE3 ";
    mem.getOffset()->accept(*this);;
  }

  void
  OctaveRtlPrintVisitor::visit(const LlirSequence &sequence)
  {
    m_outputStream << "; sequence" << "\n";
  }

  void
  OctaveRtlPrintVisitor::visit(const NewLineNode  &nl)
  {
    m_outputStream << nl.getNewLineString();
  }

  void
  OctaveRtlPrintVisitor::visit(const OctaveBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();
    for (; it != block.end(); it++)
      {
	int lineNum = (*it)->getLineNum();

	if ((lineNum - m_lineNum) >= 0)
	  {
	    printBlankLines(lineNum - m_lineNum);
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Print Visitor Line number mismatch") ;
	  }

	(*it)->accept(*this);

      }
  }

  void
  OctaveRtlPrintVisitor::visit(const OctaveMacroBlock &macroBlk)
  {
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

      }
  }

  void
  OctaveRtlPrintVisitor::visit(const OctaveImplicitBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      {
	int lineNum = (*it)->getLineNum();

	if ((lineNum - m_lineNum) >= 0)
	  {
	    printBlankLines(lineNum - m_lineNum);
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Print Visitor Line number mismatch") ;
	  }

	(*it)->accept(*this);

      }

    endOfLine(); // needed, end of whole source input.
  }

  void
  OctaveRtlPrintVisitor::printBlankLines(unsigned int numBlankLines)
  {
    for (unsigned int i = 0; i < numBlankLines; i++)
      {
	endOfLine();
      }
  }

  void
  OctaveRtlPrintVisitor::visit(const UnNamedEndBlock &directive)
  {
    m_outputStream << ".endblock";
  }

  void
  OctaveRtlPrintVisitor::visit(const NamedEndBlock &directive)
  {
#if 0
    m_outputStream << ".endblock " << directive.getName();
#else
    m_outputStream << ".endblock"; // The back-end assembler does not support named endblocks at the moment
#endif
  }

  void
  OctaveRtlPrintVisitor::visit(const StructBeginDirective &directive)
  {
    m_outputStream << ".structure " << directive.getName();
  }

  void
  OctaveRtlPrintVisitor::visit(const StructEndDirective &directive)
  {
    m_outputStream << ".ends";
  }

  void
  OctaveRtlPrintVisitor::visit(const MapDirective &directive)
  {
    m_outputStream << ".map " << directive.getMapPath() << " " << directive.getMapName() << " ";
    shared_ptr<const Register> mappedReg = directive.getMappedSymbol()->getRegister();

    //the mappedReg could be multi or single reg.
    //but existing mxtas cannot handle multi reg.
    //so - print only single regsiter
    mappedReg->getRegister(0)->accept(*this);
  }

  void
  OctaveRtlPrintVisitor::visit(const UnmapDirective &directive)
  {
    m_outputStream << ".unmap " << directive.getName();
  }

  void
  OctaveRtlPrintVisitor::visit(const ElementDirective &directive)
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
  OctaveRtlPrintVisitor::visit(const Field &fld)
  {
    m_outputStream << fld.getName();
  }

  void
  OctaveRtlPrintVisitor::visit(const BitField &fld)
  {
    m_outputStream << fld.getName() << '(' << fld.getMSBitPosition() << ':' << fld.getLSBitPosition() << ')';
  }

  void
  OctaveRtlPrintVisitor::visit(const Lo17Op &expr)
  {
    m_outputStream << "lo17(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctaveRtlPrintVisitor::visit(const Hi16Op &expr)
  {
    m_outputStream << "hi16(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctaveRtlPrintVisitor::visit(const Lo16Op &expr)
  {
    m_outputStream << "lo16(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctaveRtlPrintVisitor::visit(const WordOp &expr)
  {
    m_outputStream << "word(";
    (expr.getOpnd())->accept(*this);
    m_outputStream << ")";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod2Flag&)
  {
    m_outputStream << "MOD2";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod4Flag&)
  {
    m_outputStream << "MOD4";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod8Flag&)
  {
    m_outputStream << "MOD8";
  }
  void
  OctaveRtlPrintVisitor::visit(const Mod16Flag&)
  {
    m_outputStream << "MOD16";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod32Flag&)
  {
    m_outputStream << "MOD32";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod64Flag&)
  {
    m_outputStream << "MOD64";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod128Flag&)
  {
    m_outputStream << "MOD128";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod256Flag&)
  {
    m_outputStream << "MOD256";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod512Flag&)
  {
    m_outputStream << "MOD512";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod1KFlag&)
  {
    m_outputStream << "MOD1K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod2KFlag&)
  {
    m_outputStream << "MOD2K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod4KFlag&)
  {
    m_outputStream << "MOD4K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod8KFlag&)
  {
    m_outputStream << "MOD8K";
  }
  void
  OctaveRtlPrintVisitor::visit(const Mod16KFlag&)
  {
    m_outputStream << "MOD16K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod32KFlag&)
  {
    m_outputStream << "MOD32K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod64KFlag&)
  {
    m_outputStream << "MOD64K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod128KFlag&)
  {
    m_outputStream << "MOD128K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod256KFlag&)
  {
    m_outputStream << "MOD256K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod512KFlag&)
  {
    m_outputStream << "MOD512K";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod1MFlag&)
  {
    m_outputStream << "MOD1M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod2MFlag&)
  {
    m_outputStream << "MOD2M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod4MFlag&)
  {
    m_outputStream << "MOD4M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod8MFlag&)
  {
    m_outputStream << "MOD8M";
  }
  void
  OctaveRtlPrintVisitor::visit(const Mod16MFlag&)
  {
    m_outputStream << "MOD16M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod32MFlag&)
  {
    m_outputStream << "MOD32M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod64MFlag&)
  {
    m_outputStream << "MOD64M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod128MFlag&)
  {
    m_outputStream << "MOD128M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod256MFlag&)
  {
    m_outputStream << "MOD256M";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod512MFlag&)
  {
    m_outputStream << "MOD512M";
  }


  void
  OctaveRtlPrintVisitor::visit(const Mod1GFlag&)
  {
    m_outputStream << "MOD1G";
  }

  void
  OctaveRtlPrintVisitor::visit(const Mod2GFlag&)
  {
    m_outputStream << "MOD2G";
  }

  void
  OctaveRtlPrintVisitor::visit(const BZFlag&)
  {
    m_outputStream << "BZ";
  }

  void
  OctaveRtlPrintVisitor::visit(const BNCFlag&)
  {
    m_outputStream << "BNC";
  }

  void
  OctaveRtlPrintVisitor::visit(const BNOFlag&)
  {
    m_outputStream << "BNO";
  }

  void
  OctaveRtlPrintVisitor::visit(const BGEZFlag&)
  {
    m_outputStream << "BGEZ";
  }

  void
  OctaveRtlPrintVisitor::visit(const BLZFlag&)
  {
    m_outputStream << "BLZ";
  }

  void
  OctaveRtlPrintVisitor::visit(const BNZFlag&)
  {
    m_outputStream << "BNZ";
  }

  void
  OctaveRtlPrintVisitor::visit(const BLEZFlag&)
  {
    m_outputStream << "BLEZ";
  }

  void
  OctaveRtlPrintVisitor::visit(const BALBFlag&)
  {
    m_outputStream << "BALB";
  }

  void
  OctaveRtlPrintVisitor::visit(const BAEBFlag&)
  {
    m_outputStream << "BAEB";
  }

  void
  OctaveRtlPrintVisitor::visit(const BAGBFlag&)
  {
    m_outputStream << "BAGB";
  }

  void
  OctaveRtlPrintVisitor::visit(const BANEBFlag&)
  {
    m_outputStream << "BANEB";
  }

  void
  OctaveRtlPrintVisitor::visit(const BAGEBFlag&)
  {
    m_outputStream << "BAGEB";
  }

  void
  OctaveRtlPrintVisitor::visit(const BALEBFlag&)
  {
    m_outputStream << "BALEB";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess0Flag &flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS0";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess1Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS1";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess2Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS2";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess3Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS3";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess4Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS4";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess5Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS5";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess6Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS6";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess7Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS7";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess8Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS8";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess9Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS9";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess10Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS10";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess11Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS11";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess12Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS12";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess13Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS13";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess14Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS14";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess15Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS15";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess16Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS16";
  }


  void
  OctaveRtlPrintVisitor::visit(const Ess17Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS17";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess18Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS18";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess19Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS19";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess20Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS20";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess21Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS21";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess22Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS22";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess23Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS23";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess24Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS24";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess25Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS25";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess26Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS26";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess27Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS27";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess28Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS28";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess29Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS29";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess30Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS30";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ess31Flag& flag)
  {
    m_outputStream << (flag.isNegated() ? "!" : "") << "ESS31";
  }

  void
  OctaveRtlPrintVisitor::visit(const C0Flag&)
  {
    m_outputStream << "C0";
  }

  void
  OctaveRtlPrintVisitor::visit(const C1Flag&)
  {
    m_outputStream << "C1";
  }

  void
  OctaveRtlPrintVisitor::visit(const C2Flag&)
  {
    m_outputStream << "C2";
  }

  void
  OctaveRtlPrintVisitor::visit(const C3Flag&)
  {
    m_outputStream << "C3";
  }

  void
  OctaveRtlPrintVisitor::visit(const C4Flag&)
  {
    m_outputStream << "C4";
  }

  void
  OctaveRtlPrintVisitor::visit(const C5Flag&)
  {
    m_outputStream << "C5";
  }

  void
  OctaveRtlPrintVisitor::visit(const C6Flag&)
  {
    m_outputStream << "C6";
  }

  void
  OctaveRtlPrintVisitor::visit(const C7Flag&)
  {
    m_outputStream << "C7";
  }

  void
  OctaveRtlPrintVisitor::visit(const C8Flag&)
  {
    m_outputStream << "C8";
  }

  void
  OctaveRtlPrintVisitor::visit(const C9Flag&)
  {
    m_outputStream << "C9";
  }

  void
  OctaveRtlPrintVisitor::visit(const C10Flag&)
  {
    m_outputStream << "C10";
  }

  void
  OctaveRtlPrintVisitor::visit(const C11Flag&)
  {
    m_outputStream << "C11";
  }

  void
  OctaveRtlPrintVisitor::visit(const C12Flag&)
  {
    m_outputStream << "C12";
  }

  void
  OctaveRtlPrintVisitor::visit(const C13Flag&)
  {
    m_outputStream << "C13";
  }

  void
  OctaveRtlPrintVisitor::visit(const C14Flag&)
  {
    m_outputStream << "C14";
  }

  void
  OctaveRtlPrintVisitor::visit(const C15Flag&)
  {
    m_outputStream << "C15";
  }

  void
  OctaveRtlPrintVisitor::visit(const LNK1Flag &)
  {
    m_outputStream << "LNK1";
  }

  void
  OctaveRtlPrintVisitor::visit(const LNK2Flag &)
  {
    m_outputStream << "LNK2";
  }

  void
  OctaveRtlPrintVisitor::visit(const LNK3Flag &)
  {
    m_outputStream << "LNK3";
  }

  void
  OctaveRtlPrintVisitor::visit(const UNLNKFlag &)
  {
    m_outputStream << "UNLNK";
  }

  void
  OctaveRtlPrintVisitor::visit(const DLNKFlag &)
  {
    m_outputStream << "DLNK";
  }

  void
  OctaveRtlPrintVisitor::visit(const PREFlag &)
  {
    m_outputStream << "PRE";
  }

  void
  OctaveRtlPrintVisitor::visit(const FLUSHFlag &)
  {
    m_outputStream << "FLUSH";
  }

  void
  OctaveRtlPrintVisitor::visit(const BFFlag &)
  {
    m_outputStream << "BF";
  }

  void
  OctaveRtlPrintVisitor::visit(const CFlag &)
  {
    m_outputStream << "C";
  }

  void
  OctaveRtlPrintVisitor::visit(const Ascii &directive)
  {
    m_outputStream << ".ascii " << directive.getAsciiString();
  }

  void
  OctaveRtlPrintVisitor::visit(const List &directive)
  {
    m_outputStream << ".list";
  }

  void
  OctaveRtlPrintVisitor::visit(const NoList &directive)
  {
    m_outputStream << ".nolist";
  }

  void
  OctaveRtlPrintVisitor::visit(const Text &directive)
  {
    m_outputStream << ".text";
  }

  void
  OctaveRtlPrintVisitor::visit(const Data &directive)
  {
    m_outputStream << ".data";
  }

  void
  OctaveRtlPrintVisitor::visit(const Comm &directive)
  {
    m_outputStream << ".comm " << directive.getName() << "," << directive.getSize();
  }

  void
  OctaveRtlPrintVisitor::visit(const Lcomm &directive)
  {
    m_outputStream << ".lcomm " << directive.getName() << "," << directive.getSize();
  }

  void
  OctaveRtlPrintVisitor::visit(const NamedSection &directive)
  {
    m_outputStream << ".section " << directive.getName();
  }

  void
  OctaveRtlPrintVisitor::visit(const EndMacro &directive)
  {
    m_macroDepth -= 1;

    if(m_macroDepth == 0)
      {
	m_inMacroBlock = false;
      }
  }

  void
  OctaveRtlPrintVisitor::visit(const Align &directive)
  {
    m_outputStream << ".align " << directive.getSize();
  }

  void
  OctaveRtlPrintVisitor::visit(const Ref &directive)
  {
    m_outputStream << ".ref " << directive.getLabel();
  }

  void
  OctaveRtlPrintVisitor::visit(const Org &directive)
  {
    m_outputStream << ".org " << directive.getNumBytes();
  }

  void
  OctaveRtlPrintVisitor::visit(const OrgWithFillValue &directive)
  {
    m_outputStream << ".org " << directive.getNumBytes() << " " << directive.getFillValue();
  }

  void 
  OctaveRtlPrintVisitor::printDatumList(const AllocMemoryDirective &directive)
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
  OctaveRtlPrintVisitor::visit(const LocalLabel &label)
  {
    m_outputStream << label.getMangledName() << ':';
  }

  void
  OctaveRtlPrintVisitor::visit(const GlobalLabel &label)
  {
    m_outputStream << label.getMangledName() << "::";
  }

  void
  OctaveRtlPrintVisitor::visit(const FileScopeLabel &label)
  {
    m_outputStream << label.getMangledName() << ":=";
  }

  void
  OctaveRtlPrintVisitor::visit(const JtableBegin &directive)
  {
    m_outputStream << ";.jtable begin ";
  }

  void
  OctaveRtlPrintVisitor::visit(const JtableEnd &directive)
  {
    m_outputStream << ";.jtable end ";
  }

  void
  OctaveRtlPrintVisitor::visit(const JtableRelativeBegin &directive)
  {
    m_outputStream << ";.jtable_r begin ";
  }

  void
  OctaveRtlPrintVisitor::visit(const JtableRelativeEnd &directive)
  {
    m_outputStream << ";.jtable_r end ";
  }

  void
  OctaveRtlPrintVisitor::visit(const Byte &directive)
  {
    m_outputStream << ".byte ";
    printDatumList(directive);
  }

  void
  OctaveRtlPrintVisitor::visit(const Word &directive)
  {
    m_outputStream << ".word ";
    printDatumList(directive);
  }

  void
  OctaveRtlPrintVisitor::visit(const HalfWord &directive)
  {
    m_outputStream << ".halfword ";
    printDatumList(directive);
  }

  void
  OctaveRtlPrintVisitor::visit(const CbranchFlags &cbranch)
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
  OctaveRtlPrintVisitor::visit(const BrslFlags &brsl)
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
  OctaveRtlPrintVisitor::printTSSFlags(const TrafficScheduleFlags &tssflags)
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
  OctaveRtlPrintVisitor::visit(const TrafficScheduleFlags &tssFlags)
  {
    printTSSFlags(tssFlags);  
  }

  void
  OctaveRtlPrintVisitor::visit(const PolFlags &pol)
  {
    printTSSFlags(pol);
  }

  void
  OctaveRtlPrintVisitor::visit(const PutFlags &put)
  {
    printTSSFlags(put);
  }

  void
  OctaveRtlPrintVisitor::visit(const GetFlags &get)
  {
    printTSSFlags(get);
  }

  void
  OctaveRtlPrintVisitor::visit(const SXFlag &)
  {
    m_outputStream << "SX";
  }

  void
  OctaveRtlPrintVisitor::visit(const FindFlag &)
  {
    m_outputStream << "ZB";
  }

  void
  OctaveRtlPrintVisitor::visit(const CumeFlag &)
  {
    m_outputStream << "CUME";
  }

  void
  OctaveRtlPrintVisitor::visit(const DepbFlag &)
  {
    m_outputStream << "Z";
  }

  void
  OctaveRtlPrintVisitor::visit(const DIFlag &)
  {
    m_outputStream << "DI";
  }

  void
  OctaveRtlPrintVisitor::visit(const SignFlag &)
  {
    m_outputStream << "SIGN";
  }

  void
  OctaveRtlPrintVisitor::visit(const CDFlag &)
  {
    m_outputStream << "CD";
  }

  void
  OctaveRtlPrintVisitor::visit(const GC1AFlag &)
  {
    m_outputStream << "GC1A";
  }

  void
  OctaveRtlPrintVisitor::visit(const GC1BFlag &)
  {
     m_outputStream << "GC1B";
  }

  void
  OctaveRtlPrintVisitor::visit(const GSTICKFlag &)
  {
     m_outputStream << "GSTICK";
  }

  void
  OctaveRtlPrintVisitor::visit(const NULFlag &)
  {
     m_outputStream << "NUL";
  }

  void
  OctaveRtlPrintVisitor::visit(const GC1OFlag &)
  {
     m_outputStream << "GC1O";
  }

  void
  OctaveRtlPrintVisitor::visit(const GC2AFlag &)
  {
     m_outputStream << "GC2A";
  }

  void
  OctaveRtlPrintVisitor::visit(const GC2BFlag &)
  {
     m_outputStream << "GC2B";
  }

  void
  OctaveRtlPrintVisitor::visit(const GC2OFlag &)
  {
     m_outputStream << "GC2O";
  }

  void
  OctaveRtlPrintVisitor::visit(const GPAFlag &)
  {
     m_outputStream << "GPA";
  }

  void
  OctaveRtlPrintVisitor::visit(const GPUFlag &)
  {
     m_outputStream << "GPU";
  }

  void
  OctaveRtlPrintVisitor::visit(const GPBFlag &)
  {
     m_outputStream << "GPB";
  }

  void
  OctaveRtlPrintVisitor::visit(const GTAFlag &)
  {
     m_outputStream << "GTA";
  }

  void
  OctaveRtlPrintVisitor::visit(const GTOFlag &)
  {
     m_outputStream << "GTO";
  }

  void
  OctaveRtlPrintVisitor::visit(const GTBFlag &)
  {
     m_outputStream << "GTB";
  }

  void
  OctaveRtlPrintVisitor::visit(const FPFlag &)
  {
     m_outputStream << "FP";
  }

  void
  OctaveRtlPrintVisitor::visit(const NG2Flag &)
  {
     m_outputStream << "NG2";
  }

  void
  OctaveRtlPrintVisitor::visit(const GZFlag &)
  {
     m_outputStream << "GZ";
  }

  void
  OctaveRtlPrintVisitor::visit(const OAMFlag &)
  {
     m_outputStream << "OAM";
  }

  void
  OctaveRtlPrintVisitor::visit(const RPFlag &)
  {
     m_outputStream << "RP";
  }

  void
  OctaveRtlPrintVisitor::visit(const LOGFlag &)
  {
     m_outputStream << "LOG";
  }

  void
  OctaveRtlPrintVisitor::visit(const FPBFlag &)
  {
     m_outputStream << "FPB";
  }

  void
  OctaveRtlPrintVisitor::visit(const CSBFlag &)
  {
     m_outputStream << "CSB";
  }

  void
  OctaveRtlPrintVisitor::visit(const DELETEFlag &)
  {
     m_outputStream << "DELETE";
  }

  void
  OctaveRtlPrintVisitor::visit(const NBFlag &)
  {
     m_outputStream << "NB";
  }

  void
  OctaveRtlPrintVisitor::visit(const NCFlag &)
  {
     m_outputStream << "NC";
  }

  void
  OctaveRtlPrintVisitor::visit(const GWFlag &)
  {
     m_outputStream << "GW";
  }

  void
  OctaveRtlPrintVisitor::visit(const GRFlag &)
  {
     m_outputStream << "GR";
  }

  void
  OctaveRtlPrintVisitor::visit(const AFlag &)
  {
     m_outputStream << "A";
  }

  void
  OctaveRtlPrintVisitor::visit(const RFlag &)
  {
     m_outputStream << "R";
  }

  void
  OctaveRtlPrintVisitor::visit(const GUFlag &)
  {
     m_outputStream << "GU";
  }

  void
  OctaveRtlPrintVisitor::visit(const TFlag &)
  {
     m_outputStream << "T";
  }

  void
  OctaveRtlPrintVisitor::visit(const RBFlag &)
  {
     m_outputStream << "RB";
  }

  void
  OctaveRtlPrintVisitor::visit(const FBFlag &)
  {
     m_outputStream << "FB";
  }

  void
  OctaveRtlPrintVisitor::visit(const SFlag &)
  {
     m_outputStream << "S";
  }

  void
  OctaveRtlPrintVisitor::visit(const NTFlag &)
  {
     m_outputStream << "NT";
  }

  void
  OctaveRtlPrintVisitor::visit(const IFlag &)
  {
     m_outputStream << "I";
  }

  void
  OctaveRtlPrintVisitor::visit(const FRFlag &)
  {
     m_outputStream << "FR";
  }

  void
  OctaveRtlPrintVisitor::visit(const RSCHFlag &)
  {
     m_outputStream << "RSCH";
  }

  void
  OctaveRtlPrintVisitor::visit(const CLOSEFlag &)
  {
     m_outputStream << "CLOSE";
  }

  void
  OctaveRtlPrintVisitor::visit(const NEFlag &)
  {
     m_outputStream << "NE";
  }

  void
  OctaveRtlPrintVisitor::printNops(unsigned int num)
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




