#include <iostream>
using namespace std;

#include <OctaveNode.h>
#include <M480Instructions.h>

#include "M480RtlPrintVisitor.h"

 
namespace Llir 
{
  M480RtlPrintVisitor::M480RtlPrintVisitor(ostream &o) : 
    OctaveRtlPrintVisitor(o),
    M480Visitor()
  {}

  M480RtlPrintVisitor::~M480RtlPrintVisitor()
  {}
  
  void
  M480RtlPrintVisitor::visit(const M480AddwhInstruction &i)
  {
    printAlu2OpBranch(i, "addwh");
  }

  
  void
  M480RtlPrintVisitor::visit(const M480JaddwhInstruction &i)
  {
    printAlu2OpBranch(i, "addwh");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480AddwlInstruction &i)
  {
    printAlu2OpBranch(i, "addwl");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JaddwlInstruction &i)
  {
    printAlu2OpBranch(i, "addwl");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480AddwwInstruction &i)
  {
    printAlu2OpBranch(i, "addww");
  }

  void
  M480RtlPrintVisitor::visit(const M480JaddwwInstruction &i)
  {
    printAlu2OpBranch(i, "addww");
    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480AddlInstruction &i)
  {
    printAlu2OpBranch(i, "addl");
  }

  void
  M480RtlPrintVisitor::visit(const M480JaddlInstruction &i)
  {
    printAlu2OpBranch(i, "addl");
    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480SubwhInstruction &i)
  {
    printAlu2OpBranch(i, "subwh");
  }

  void
  M480RtlPrintVisitor::visit(const M480JsubwhInstruction &i)
  {
    printAlu2OpBranch(i, "subwh");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480SubwlInstruction &i)
  {
    printAlu2OpBranch(i, "subwl");
  }

  void
  M480RtlPrintVisitor::visit(const M480JsubwlInstruction &i)
  {
    printAlu2OpBranch(i, "subwl");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480SubwwInstruction &i)
  {
    printAlu2OpBranch(i, "subww");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JsubwwInstruction &i)
  {
    printAlu2OpBranch(i, "subww");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480SublInstruction &i)
  {
    printAlu2OpBranch(i, "subl");
  }

  void
  M480RtlPrintVisitor::visit(const M480JsublInstruction &i)
  {
    printAlu2OpBranch(i, "subl");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480AddwhiInstruction &i)
  {
    printAlu2OpBranch(i, "addwhi");
  }

  void
  M480RtlPrintVisitor::visit(const M480JaddwhiInstruction &i)
  {
    printAlu2OpBranch(i, "addwhi");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480AddwliInstruction &i)
  {
    printAlu2OpBranch(i, "addwli");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JaddwliInstruction &i)
  {
    printAlu2OpBranch(i, "addwli");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480AddwwiInstruction &i)
  {
    printAlu2OpBranch(i, "addwwi");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JaddwwiInstruction &i)
  {
    printAlu2OpBranch(i, "addwwi");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480AddliInstruction &i)
  {
    printAlu2OpBranch(i, "addli");
  }

  void
  M480RtlPrintVisitor::visit(const M480JaddliInstruction &i)
  {
    printAlu2OpBranch(i, "addli");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480SubwhiInstruction &i)
  {
    printAlu2OpBranch(i, "subwhi");
  }
  void
  M480RtlPrintVisitor::visit(const M480JsubwhiInstruction &i)
  {
    printAlu2OpBranch(i, "subwhi");
    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480SubwliInstruction &i)
  {
    printAlu2OpBranch(i, "subwli");
  }


  void
  M480RtlPrintVisitor::visit(const M480JsubwliInstruction &i)
  {
    printAlu2OpBranch(i, "subwli");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480SubwwiInstruction &i)
  {
    printAlu2OpBranch(i, "subwwi");
  }

  void
  M480RtlPrintVisitor::visit(const M480JsubwwiInstruction &i)
  {
    printAlu2OpBranch(i, "subwwi");
    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480SubliInstruction &i)
  {
    printAlu2OpBranch(i, "subli");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JsubliInstruction &i)
  {
    printAlu2OpBranch(i, "subli");
    printNops(i.getNumDelaySlots());
  }
  
  void
  M480RtlPrintVisitor::visit(const M480FfsInstruction &i)
  {
    printAlu2OpFind(i, "ffs");
  }

  void
  M480RtlPrintVisitor::visit(const M480FlsInstruction &i)
  {
    printAlu2OpFind(i, "fls");
  }

  void
  M480RtlPrintVisitor::visit(const M480ParInstruction &i)
  {
    shared_ptr<const LlirOperand> src = i.getSrc1();
    shared_ptr<const Register> dst = i.getDst();

    getOutputStream() << "par ";
    src->accept(*this);
    getOutputStream() << " ";
    dst->accept(*this);
    getOutputStream() << " ";

    i.getAbcFlag()->accept(*this);
  }
  
  void
  M480RtlPrintVisitor::visit(const M480AddInstruction &i)
  {
    printAlu3OpAbcMod(i,"add");
  }

  void
  M480RtlPrintVisitor::visit(const M480AddiInstruction &i)
  {
    printAlu3OpAbcMod(i,"addi");
  }

  void
  M480RtlPrintVisitor::visit(const M480Add4xInstruction &i)
  {
    printAlu3OpAbcMod(i,"add4x");
  }

  void
  M480RtlPrintVisitor::visit(const M480AddcInstruction &i)
  {
    printAlu3OpAbcMod(i,"addc");
  }

  void
  M480RtlPrintVisitor::visit(const M480AddciInstruction &i)
  {
    printAlu3OpAbcMod(i,"addci");
  }

  void
  M480RtlPrintVisitor::visit(const M480SubInstruction &i)
  {
    printAlu3OpAbcMod(i,"sub");
  }

  void
  M480RtlPrintVisitor::visit(const M480SubiInstruction &i)
  {
    printAlu3OpAbcMod(i,"subi");
  }

  void
  M480RtlPrintVisitor::visit(const M480SubbInstruction &i)
  {
    printAlu3OpAbcMod(i,"subb");
  }

  void
  M480RtlPrintVisitor::visit(const M480SubbiInstruction &i)
  {
    printAlu3OpAbcMod(i,"subbi");
  }

  void
  M480RtlPrintVisitor::visit(const M480AndInstruction &i)
  {
    printAlu3OpAbcMod(i,"and");
  }

  void
  M480RtlPrintVisitor::visit(const M480OrInstruction &i)
  {
    printAlu3OpAbcMod(i,"or");
  }

  void
  M480RtlPrintVisitor::visit(const M480XorInstruction &i)
  {
    printAlu3OpAbcMod(i,"xor");
  }

  void
  M480RtlPrintVisitor::visit(const M480MaxInstruction &i)
  {
    printAlu3OpAbcMod(i,"max");
  }

  void
  M480RtlPrintVisitor::visit(const M480MinInstruction &i)
  {
    printAlu3OpAbcMod(i,"min");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480RandInstruction &i)
  {
    printAlu3OpAbc(i,"rand");
  }

  void
  M480RtlPrintVisitor::visit(const M480RotlInstruction &i)
  {
    printAlu3OpAbc(i,"rotl");
  }

  void
  M480RtlPrintVisitor::visit(const M480RotrInstruction &i)
  {
    printAlu3OpAbc(i,"rotr");
  }

  void
  M480RtlPrintVisitor::visit(const M480ClrbInstruction &i)
  {
    printAlu3OpAbc(i,"clrb");
  }

  void
  M480RtlPrintVisitor::visit(const M480SetbInstruction &i)
  {
    printAlu3OpAbc(i,"setb");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShftInstruction &i)
  {
    printAlu3OpAbc(i,"shft");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShftaInstruction &i)
  {
    printAlu3OpAbc(i,"shfta");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShlInstruction &i)
  {
    printAlu3OpAbc(i,"shl");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShrInstruction &i)
  {
    printAlu3OpAbc(i,"shr");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShraInstruction &i)
  {
    printAlu3OpAbc(i,"shra");
  }

  void
  M480RtlPrintVisitor::visit(const M480RandiInstruction &i)
  {
    printAlu3OpAbc(i,"randi");
  }

  void
  M480RtlPrintVisitor::visit(const M480RotliInstruction &i)
  {
    printAlu3OpAbc(i,"rotli");
  }

  void
  M480RtlPrintVisitor::visit(const M480RotriInstruction &i)
  {
    printAlu3OpAbc(i,"rotri");
  }

  void
  M480RtlPrintVisitor::visit(const M480SetbiInstruction &i)
  {
    printAlu3OpAbc(i,"setbi");
  }

  void
  M480RtlPrintVisitor::visit(const M480ClrbiInstruction &i)
  {
    printAlu3OpAbc(i,"clrbi");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShliInstruction &i)
  {
    printAlu3OpAbc(i,"shli");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShriInstruction &i)
  {
    printAlu3OpAbc(i,"shri");
  }

  void
  M480RtlPrintVisitor::visit(const M480ShraiInstruction &i)
  {
    printAlu3OpAbc(i,"shrai");
  }

  void
  M480RtlPrintVisitor::visit(const M480MaxiInstruction &i)
  {
    printAlu3OpAbc(i,"maxi");
  }

  void
  M480RtlPrintVisitor::visit(const M480MiniInstruction &i)
  {
    printAlu3OpAbc(i,"mini");
  }

  void
  M480RtlPrintVisitor::visit(const M480AndiInstruction &i)
  {
    printAlu3OpAbc(i,"andi");
  }

  void
  M480RtlPrintVisitor::visit(const M480OriInstruction &i)
  {
    printAlu3OpAbc(i,"ori");
  }

  void
  M480RtlPrintVisitor::visit(const M480XoriInstruction &i)
  {
    printAlu3OpAbc(i,"xori");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480MulInstruction &i)
  {
    printAlu3OpSx(i,"mul");
  }

  void
  M480RtlPrintVisitor::visit(const M480MulhInstruction &i)
  {
    printAlu3OpSx(i,"mulh");
  }

  void
  M480RtlPrintVisitor::visit(const M480MuliInstruction &i)
  {
    printAlu3OpSx(i,"muli");
  }

  void
  M480RtlPrintVisitor::visit(const M480MulhiInstruction &i)
  {
    printAlu3OpSx(i,"mulhi");
  }

  void
  M480RtlPrintVisitor::visit(const M480AddneInstruction &i)
  {
    printAlu3Op(i, "addne");
  }

  void
  M480RtlPrintVisitor::visit(const M480AddneiInstruction &i)
  {
    printAlu3Op(i, "addnei");
  }

  void
  M480RtlPrintVisitor::visit(const M480ByteswInstruction &i)
  {
    getOutputStream() << "bytesw ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getB0()->accept(*this);
    getOutputStream() << " ";
    i.getB1()->accept(*this);
    getOutputStream() << " ";
    i.getB2()->accept(*this);
    getOutputStream() << " ";
    i.getB3()->accept(*this);
    getOutputStream() << " ";
    i.getAbcFlag()->accept(*this);
  }
  
  void
  M480RtlPrintVisitor::visit(const M480BcdrInstruction &i)
  {
    printCondBranch(i,"bcdr");
  }

  void
  M480RtlPrintVisitor::visit(const M480BcrInstruction &i)
  {
    printCondBranch(i,"bcr");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JbcrInstruction &i)
  {
    printCondBranch(i,"bcr");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480JbcdrInstruction &i)
  {
    printCondBranch(i,"bcdr");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480BiInstruction &i)
  {
    getOutputStream() << "bi" << " ";

    i.getSrc1()->accept(*this); 
    getOutputStream() << " ";

    i.getDst()->accept(*this); 
    getOutputStream() << " ";

    i.getCdFlag()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480JbiInstruction &i)
  {
    getOutputStream() << "bi" << " ";

    i.getSrc1()->accept(*this); 
    getOutputStream() << " ";

    i.getDst()->accept(*this); 
    getOutputStream() << " ";

    i.getCdFlag()->accept(*this);

    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480BrInstruction &i)
  {
    getOutputStream() << "br ";

    i.getSrc1()->accept(*this); 
    getOutputStream() << " ";

    i.getDst()->accept(*this);
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JtablebrInstruction &i)
  {
    getOutputStream() << "br ";

    i.getSrc1()->accept(*this); 

    // Don't print dst, which is a label that is only used as a hint to 
    // the compiler.
  }
    
  void
  M480RtlPrintVisitor::visit(const M480JtableRelativebrInstruction &i)
  {
    getOutputStream() << "br ";

    i.getSrc1()->accept(*this); 

    // Don't print dst, which is a label that is only used as a hint to 
    // the compiler.
  }

  void
  M480RtlPrintVisitor::visit(const M480JbrInstruction &i)
  {
    getOutputStream() << "br ";

    i.getSrc1()->accept(*this); 
    getOutputStream() << " ";

    i.getDst()->accept(*this);

    printNops(i.getNumDelaySlots());
  }
  

  void
  M480RtlPrintVisitor::visit(const M480BcdiInstruction &i)
  {
    printCondBranchImmed(i,"bcdi");
  }

  void
  M480RtlPrintVisitor::visit(const M480BciInstruction &i)
  {
    printCondBranchImmed(i,"bci");
  }
    
  void
  M480RtlPrintVisitor::visit(const M480JbciInstruction &i)
  {
    printCondBranchImmed(i,"bci");
    printNops(i.getNumDelaySlots());
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JbcdiInstruction &i)
  {
    printCondBranchImmed(i,"bcdi");
    printNops(i.getNumDelaySlots());
  }
  

  void
  M480RtlPrintVisitor::visit(const M480BnzrInstruction &i)
  {
    printZeroBranch(i,"bnzr");
  }

  void
  M480RtlPrintVisitor::visit(const M480JbnzrInstruction &i)
  {
    printZeroBranch(i,"bnzr");
    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480BzrInstruction &i)
  {
    printZeroBranch(i,"bzr");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JbzrInstruction &i)
  {
    printZeroBranch(i,"bzr");
    printNops(i.getNumDelaySlots());
  }
  

  void
  M480RtlPrintVisitor::visit(const M480BnziInstruction &i)
  {
    printZeroBranchImmed(i,"bnzi");
  }


  void
  M480RtlPrintVisitor::visit(const M480JbnziInstruction &i)
  {
    printZeroBranchImmed(i,"bnzi");

    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480BziInstruction &i)
  {
    printZeroBranchImmed(i,"bzi");
  }

  void
  M480RtlPrintVisitor::visit(const M480JbziInstruction &i)
  {
    printZeroBranchImmed(i,"bzi");

    printNops(i.getNumDelaySlots());
  }

  
  void
  M480RtlPrintVisitor::visit(const M480TsetbInstruction &i)
  {
    printTestBitBranch(i,"tsetb");
  }

  
  void
  M480RtlPrintVisitor::visit(const M480JtsetbInstruction &i)
  {
    printTestBitBranch(i,"tsetb");

    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480TclrbInstruction &i)
  {
    printTestBitBranch(i,"tclrb");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480JtclrbInstruction &i)
  {
    printTestBitBranch(i,"tclrb");

    printNops(i.getNumDelaySlots());
  }
  

  void
  M480RtlPrintVisitor::visit(const M480RnmiInstruction &i)
  {
    printReturn(i,"rnmi");
  }

  void
  M480RtlPrintVisitor::visit(const M480JrnmiInstruction &i)
  {
    printReturn(i,"rnmi");

    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480RintInstruction &i)
  {
    printReturn(i,"rint");
  }


  void
  M480RtlPrintVisitor::visit(const M480JrintInstruction &i)
  {
    printReturn(i,"rint");

    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480BrsInstruction &i)
  {
    getOutputStream() << "brs ";
    i.getDst()->accept(*this);
  }


  void
  M480RtlPrintVisitor::visit(const M480JbrsInstruction &i)
  {
    getOutputStream() << "brs ";
    i.getDst()->accept(*this);

    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480BrslInstruction &i)
  {
    getOutputStream() << "brsl ";
    i.getBrslFlags()->accept(*this);
  }


  void
  M480RtlPrintVisitor::visit(const M480JbrslInstruction &i)
  {
    getOutputStream() << "brsl ";
    i.getBrslFlags()->accept(*this);

    printNops(i.getNumDelaySlots());
  }


  void
  M480RtlPrintVisitor::visit(const M480BrspreInstruction &i)
  {
    getOutputStream() << "brspre";
  }
  
  void
  M480RtlPrintVisitor::visit(const M480CmpInstruction &i)
  {
    printCompareBranch(i,"cmp");
  }

  void
  M480RtlPrintVisitor::visit(const M480JcmpInstruction &i)
  {
    getOutputStream() << "cmp" << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);

    if (!i.getBranchTarget()->isNullOperand())
      getOutputStream() << " br = ";

    i.getBranchTarget()->accept(*this);

    getOutputStream() << " ";
    i.getAbcFlag()->accept(*this);

    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480CmpiInstruction &i)
  {
    printCompareBranch(i,"cmpi");
  }

  void
  M480RtlPrintVisitor::visit(const M480JcmpiInstruction &i)
  {
    getOutputStream() << "cmpi" << " ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getSrc2()->accept(*this);

    if (!i.getBranchTarget()->isNullOperand())
      getOutputStream() << " br = ";

    i.getBranchTarget()->accept(*this);

    getOutputStream() << " ";
    i.getAbcFlag()->accept(*this);

    printNops(i.getNumDelaySlots());
  }
  
  void
  M480RtlPrintVisitor::visit(const M480CmprInstruction &i)
  {
    printCompareSign(i,"cmpr");
  }

  void
  M480RtlPrintVisitor::visit(const M480CmpriInstruction &i)
  {
    printCompareSign(i,"cmpri");
  }

  void
  M480RtlPrintVisitor::visit(const M480DepbInstruction &i)
  {
    getOutputStream() << "depb ";

    i.getSrc1()->accept(*this);
    getOutputStream() << " ";

    i.getSrcBitNum()->accept(*this);
    getOutputStream() << " ";

    i.getDst()->accept(*this);
    getOutputStream() << " ";

    i.getDstBitNum()->accept(*this);
    getOutputStream() << " ";

    i.getNumBits()->accept(*this);
    getOutputStream() << " ";

    i.getDepbFlag()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480DepbiInstruction &i)
  {
    getOutputStream() << "depbi ";

    i.getSrc1()->accept(*this);
    getOutputStream() << " ";

    i.getDst()->accept(*this);
    getOutputStream() << " ";

    i.getDstBitNum()->accept(*this);
    getOutputStream() << " ";

    i.getNumBits()->accept(*this);
    getOutputStream() << " ";

    i.getDepbFlag()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480ExtbInstruction &i)
  {
    getOutputStream() << "extb ";

    i.getSrc1()->accept(*this);
    getOutputStream() << " ";

    i.getSrcBitNum()->accept(*this);
    getOutputStream() << " ";

    i.getDst()->accept(*this);
    getOutputStream() << " ";

    i.getDstBitNum()->accept(*this);
    getOutputStream() << " ";

    i.getNumBits()->accept(*this);
    getOutputStream() << " ";

    i.getSignFlag()->accept(*this);
  }
  
  void
  M480RtlPrintVisitor::visit(const M480CmovInstruction &i)
  {
    printCmov(i,"cmov");
  }

  void
  M480RtlPrintVisitor::visit(const M480CmoviInstruction &i)
  {
    printCmov(i,"cmovi");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480DmapInstruction &i)
  {
    printDma(i,"dmap");
  }

  void
  M480RtlPrintVisitor::visit(const M480DmasrInstruction &i)
  {
    printDma(i,"dmasr");
  }

  void
  M480RtlPrintVisitor::visit(const M480Dmau0Instruction &i)
  {
    printDma(i,"dmau0");
  }

  void
  M480RtlPrintVisitor::visit(const M480Dmau1Instruction &i)
  {
    printDma(i,"dmau1");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480LihInstruction &i)
  {
    printLoadImmediate(i,"lih");
  }

  void
  M480RtlPrintVisitor::visit(const M480LilInstruction &i)
  {
    printLoadImmediate(i,"lil");
  }

  void
  M480RtlPrintVisitor::visit(const M480LwihInstruction &i)
  {
    printLoadHalfword(i,"lwih");
  }

  void
  M480RtlPrintVisitor::visit(const M480LwilInstruction &i)
  {
    printLoadHalfword(i,"lwil");
  }

  void
  M480RtlPrintVisitor::visit(const M480LaihInstruction &i)
  {
    printLoadImmediate(i,"laih");
  }

  void
  M480RtlPrintVisitor::visit(const M480LailInstruction &i)
  {
    printLoadImmediate(i,"lail");
  }

  void
  M480RtlPrintVisitor::visit(const M480NopInstruction &i)
  {
    getOutputStream() << "nop";
  }

  void
  M480RtlPrintVisitor::visit(const M480Hec5Instruction &i)
  {
    getOutputStream() << "hec5 ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getBytes()->accept(*this);
    getOutputStream() << " ";
    i.getCumeFlag()->accept(*this);

    shared_ptr<const LlirOperand> target = i.getBranchTarget();

    OpndNull null;
    if (*target != null) 
      getOutputStream() << "br = ";
    target->accept(*this);

  }

  void
  M480RtlPrintVisitor::visit(const M480JHec5Instruction &i)
  {
    getOutputStream() << "hec5 ";
    i.getSrc1()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getBytes()->accept(*this);
    getOutputStream() << " ";
    i.getCumeFlag()->accept(*this);

    shared_ptr<const LlirOperand> target = i.getBranchTarget();

    OpndNull null;
    if (*target != null) 
      getOutputStream() << "br = ";
    target->accept(*this);

    printNops(i.getNumDelaySlots());
  }

  void
  M480RtlPrintVisitor::visit(const M480MvInstruction &i)
  {
    getOutputStream() << "mv ";
    i.getSrc()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480MvhrInstruction &i)
  {
    getOutputStream() << "mvhr ";
    i.getSrc()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getMvhFlag()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480MvrhInstruction &i)
  {
    getOutputStream() << "mvrh ";
    i.getSrc()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getMvhFlag()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480UnlinkInstruction &i)
  {
    getOutputStream() << "unlink ";
    i.getRegs()->accept(*this);
  }
  
  void
  M480RtlPrintVisitor::visit(const M480LinkInstruction &i)
  {
    printLink(i,"link");
  }

  void
  M480RtlPrintVisitor::visit(const M480LinksInstruction &i)
  {
    printLink(i,"links");
  }
    
  void
  M480RtlPrintVisitor::visit(const M480LinkspInstruction &i)
  {
    printLink(i,"link");
  }
      
  void
  M480RtlPrintVisitor::visit(const M480LinksplInstruction &i)
  {
    printLink(i,"link");
  }
    
  void
  M480RtlPrintVisitor::visit(const M480LinksrInstruction &i)
  {
    printLink(i,"link");
  }
      
  void
  M480RtlPrintVisitor::visit(const M480LinksdInstruction &i)
  {
    printLink(i,"link");
  }
        
  void
  M480RtlPrintVisitor::visit(const M480LinkccInstruction &i)
  {
    printLink(i,"link");
  }
          
  void
  M480RtlPrintVisitor::visit(const M480LinkcclInstruction &i)
  {
    printLink(i,"link");
  }
          
  void
  M480RtlPrintVisitor::visit(const M480LinksioInstruction &i)
  {
    printLink(i,"link");
  }
       
  void
  M480RtlPrintVisitor::visit(const M480LmmInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmspInstruction &i)
  {
    printLoad(i,"lsp");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmsplInstruction &i)
  {
    printLoad(i,"lsp");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmsrInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmsdInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmccInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmcclInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmsiInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M480RtlPrintVisitor::visit(const M480LmmsInstruction &i)
  {
    printLoad(i,"lmms");
  }


  void
  M480RtlPrintVisitor::visit(const M480LspInstruction &i)
  {
    printLoad(i,"lsp");
  }
  
  void
  M480RtlPrintVisitor::visit(const M480SmmInstruction &i)
  {
    printStore(i,"smm");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmspInstruction &i)
  {
    printStore(i,"ssp");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmsplInstruction &i)
  {
    printStore(i,"ssp");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmsrInstruction &i)
  {
    printStore(i,"smm");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmsdInstruction &i)
  {
    printStore(i,"smm");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmccInstruction &i)
  {
    printStore(i,"smm");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmcclInstruction &i)
  {
    printStore(i,"smm");
  }

  void
  M480RtlPrintVisitor::visit(const M480SmmsiInstruction &i)
  {
    printStore(i,"smm");
  }


  void
  M480RtlPrintVisitor::visit(const M480SmmsInstruction &i)
  {
    printStore(i,"smms");
  }

  void
  M480RtlPrintVisitor::visit(const M480SspInstruction &i)
  {
    printStore(i,"ssp");
  }

  void
  M480RtlPrintVisitor::printTssRc(const TssRcOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480PutcInstruction &i)
  {
    getOutputStream() << "putc ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getRsb()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480PutmInstruction &i)
  {
    getOutputStream() << "putm ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getRsb()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480PutpInstruction &i)
  {
    getOutputStream() << "putp ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getRsb()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480PutdInstruction &i)
  {
    //FIXME: Add PUTD to GCC, fix this call.
    getOutputStream() << "putp ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getRsb()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M480RtlPrintVisitor::visit(const M480GetInstruction &i)
  {
    printTssRc(i,"get");
  }

  void
  M480RtlPrintVisitor::printTssNoRc(const TssNoRcOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getParOffset()->accept(*this);
    getOutputStream() << " ";
    i.getPosOffset()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }
}
