#include <iostream>
using namespace std;

#include <OctaveNode.h>

#include "M470PrintVisitor.h"
#include "M470Instructions.h"

namespace Llir 
{
  M470PrintVisitor::M470PrintVisitor(ostream &o) : 
    OctavePrintVisitor(o),
    M470Visitor()
  {}

  M470PrintVisitor::~M470PrintVisitor()
  {}

  void
  M470PrintVisitor::visit(const M470AddwhInstruction &i)
  {
    printAlu2OpBranch(i, "addwh");
  }

  void
  M470PrintVisitor::visit(const M470AddwlInstruction &i)
  {
    printAlu2OpBranch(i, "addwl");
  }

  void
  M470PrintVisitor::visit(const M470AddwwInstruction &i)
  {
    printAlu2OpBranch(i, "addww");
  }

  void
  M470PrintVisitor::visit(const M470AddlInstruction &i)
  {
    printAlu2OpBranch(i, "addl");
  }

  void
  M470PrintVisitor::visit(const M470SubwhInstruction &i)
  {
    printAlu2OpBranch(i, "subwh");
  }

  void
  M470PrintVisitor::visit(const M470SubwlInstruction &i)
  {
    printAlu2OpBranch(i, "subwl");
  }

  void
  M470PrintVisitor::visit(const M470SubwwInstruction &i)
  {
    printAlu2OpBranch(i, "subww");
  }

  void
  M470PrintVisitor::visit(const M470SublInstruction &i)
  {
    printAlu2OpBranch(i, "subl");
  }

  void
  M470PrintVisitor::visit(const M470AddwhiInstruction &i)
  {
    printAlu2OpBranch(i, "addwhi");
  }

  void
  M470PrintVisitor::visit(const M470AddwliInstruction &i)
  {
    printAlu2OpBranch(i, "addwli");
  }

  void
  M470PrintVisitor::visit(const M470AddwwiInstruction &i)
  {
    printAlu2OpBranch(i, "addwwi");
  }

  void
  M470PrintVisitor::visit(const M470AddliInstruction &i)
  {
    printAlu2OpBranch(i, "addli");
  }

  //

  void
  M470PrintVisitor::visit(const M470SubwhiInstruction &i)
  {
    printAlu2OpBranch(i, "subwhi");
  }

  void
  M470PrintVisitor::visit(const M470SubwliInstruction &i)
  {
    printAlu2OpBranch(i, "subwli");
  }

  void
  M470PrintVisitor::visit(const M470SubwwiInstruction &i)
  {
    printAlu2OpBranch(i, "subwwi");
  }

  void
  M470PrintVisitor::visit(const M470SubliInstruction &i)
  {
    printAlu2OpBranch(i, "subli");
  }

  void
  M470PrintVisitor::visit(const M470FfsInstruction &i)
  {
    printAlu2OpFind(i, "ffs");
  }

  void
  M470PrintVisitor::visit(const M470FlsInstruction &i)
  {
    printAlu2OpFind(i, "fls");
  }

  void
  M470PrintVisitor::visit(const M470ParInstruction &i)
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
  M470PrintVisitor::visit(const M470AddInstruction &i)
  {
    printAlu3OpAbcMod(i,"add");
  }

  void
  M470PrintVisitor::visit(const M470AddiInstruction &i)
  {
    printAlu3OpAbcMod(i,"addi");
  }

  void
  M470PrintVisitor::visit(const M470Add4xInstruction &i)
  {
    printAlu3OpAbcMod(i,"add4x");
  }

  void
  M470PrintVisitor::visit(const M470AddcInstruction &i)
  {
    printAlu3OpAbcMod(i,"addc");
  }

  void
  M470PrintVisitor::visit(const M470AddciInstruction &i)
  {
    printAlu3OpAbcMod(i,"addci");
  }

  void
  M470PrintVisitor::visit(const M470SubInstruction &i)
  {
    printAlu3OpAbcMod(i,"sub");
  }

  void
  M470PrintVisitor::visit(const M470SubiInstruction &i)
  {
    printAlu3OpAbcMod(i,"subi");
  }

  void
  M470PrintVisitor::visit(const M470SubbInstruction &i)
  {
    printAlu3OpAbcMod(i,"subb");
  }

  void
  M470PrintVisitor::visit(const M470SubbiInstruction &i)
  {
    printAlu3OpAbcMod(i,"subbi");
  }

  void
  M470PrintVisitor::visit(const M470AndInstruction &i)
  {
    printAlu3OpAbcMod(i,"and");
  }

  void
  M470PrintVisitor::visit(const M470OrInstruction &i)
  {
    printAlu3OpAbcMod(i,"or");
  }

  void
  M470PrintVisitor::visit(const M470XorInstruction &i)
  {
    printAlu3OpAbcMod(i,"xor");
  }

  void
  M470PrintVisitor::visit(const M470MaxInstruction &i)
  {
    printAlu3OpAbcMod(i,"max");
  }

  void
  M470PrintVisitor::visit(const M470MinInstruction &i)
  {
    printAlu3OpAbcMod(i,"min");
  }

  void
  M470PrintVisitor::visit(const M470RandInstruction &i)
  {
    printAlu3OpAbc(i,"rand");
  }

  void
  M470PrintVisitor::visit(const M470RotlInstruction &i)
  {
    printAlu3OpAbc(i,"rotl");
  }

  void
  M470PrintVisitor::visit(const M470RotrInstruction &i)
  {
    printAlu3OpAbc(i,"rotr");
  }

  void
  M470PrintVisitor::visit(const M470ClrbInstruction &i)
  {
    printAlu3OpAbc(i,"clrb");
  }

  void
  M470PrintVisitor::visit(const M470SetbInstruction &i)
  {
    printAlu3OpAbc(i,"setb");
  }

  void
  M470PrintVisitor::visit(const M470ShftInstruction &i)
  {
    printAlu3OpAbc(i,"shft");
  }

  void
  M470PrintVisitor::visit(const M470ShftaInstruction &i)
  {
    printAlu3OpAbc(i,"shfta");
  }

  void
  M470PrintVisitor::visit(const M470ShlInstruction &i)
  {
    printAlu3OpAbc(i,"shl");
  }

  void
  M470PrintVisitor::visit(const M470ShrInstruction &i)
  {
    printAlu3OpAbc(i,"shr");
  }

  void
  M470PrintVisitor::visit(const M470ShraInstruction &i)
  {
    printAlu3OpAbc(i,"shra");
  }

  void
  M470PrintVisitor::visit(const M470RandiInstruction &i)
  {
    printAlu3OpAbc(i,"randi");
  }

  void
  M470PrintVisitor::visit(const M470RotliInstruction &i)
  {
    printAlu3OpAbc(i,"rotli");
  }

  void
  M470PrintVisitor::visit(const M470RotriInstruction &i)
  {
    printAlu3OpAbc(i,"rotri");
  }

  void
  M470PrintVisitor::visit(const M470SetbiInstruction &i)
  {
    printAlu3OpAbc(i,"setbi");
  }

  void
  M470PrintVisitor::visit(const M470ClrbiInstruction &i)
  {
    printAlu3OpAbc(i,"clrbi");
  }


  void
  M470PrintVisitor::visit(const M470ShliInstruction &i)
  {
    printAlu3OpAbc(i,"shli");
  }

  void
  M470PrintVisitor::visit(const M470ShriInstruction &i)
  {
    printAlu3OpAbc(i,"shri");
  }

  void
  M470PrintVisitor::visit(const M470ShraiInstruction &i)
  {
    printAlu3OpAbc(i,"shrai");
  }

  void
  M470PrintVisitor::visit(const M470MaxiInstruction &i)
  {
    printAlu3OpAbc(i,"maxi");
  }

  void
  M470PrintVisitor::visit(const M470MiniInstruction &i)
  {
    printAlu3OpAbc(i,"mini");
  }

  void
  M470PrintVisitor::visit(const M470AndiInstruction &i)
  {
    printAlu3OpAbc(i,"andi");
  }

  void
  M470PrintVisitor::visit(const M470OriInstruction &i)
  {
    printAlu3OpAbc(i,"ori");
  }

  void
  M470PrintVisitor::visit(const M470XoriInstruction &i)
  {
    printAlu3OpAbc(i,"xori");
  }

  void
  M470PrintVisitor::visit(const M470MulInstruction &i)
  {
    printAlu3OpSx(i,"mul");
  }

  void
  M470PrintVisitor::visit(const M470MulhInstruction &i)
  {
    printAlu3OpSx(i,"mulh");
  }

  void
  M470PrintVisitor::visit(const M470DivInstruction &i)
  {
    printAlu3OpSx(i,"div");
  }

  void
  M470PrintVisitor::visit(const M470MuliInstruction &i)
  {
    printAlu3OpSx(i,"muli");
  }

  void
  M470PrintVisitor::visit(const M470MulhiInstruction &i)
  {
    printAlu3OpSx(i,"mulhi");
  }

  void
  M470PrintVisitor::visit(const M470DiviInstruction &i)
  {
    printAlu3OpSx(i,"divi");
  }

  void
  M470PrintVisitor::visit(const M470AddneInstruction &i)
  {
    printAlu3Op(i, "addne");
  }

  void
  M470PrintVisitor::visit(const M470AddneiInstruction &i)
  {
    printAlu3Op(i, "addnei");
  }

  void
  M470PrintVisitor::visit(const M470ByteswInstruction &i)
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
  M470PrintVisitor::visit(const M470BcdrInstruction &i)
  {
    printCondBranch(i,"bcdr");
  }

  void
  M470PrintVisitor::visit(const M470BcrInstruction &i)
  {
    printCondBranch(i,"bcr");
  }
	    
  void
  M470PrintVisitor::visit(const M470BiInstruction &i)
  {
    getOutputStream() << "bi" << " ";

    i.getSrc1()->accept(*this); 
    getOutputStream() << " ";

    i.getDst()->accept(*this); 
    getOutputStream() << " ";

    i.getCdFlag()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470BrInstruction &i)
  {
    getOutputStream() << "br ";

    i.getSrc1()->accept(*this); 
    getOutputStream() << " ";

    i.getDst()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470BcdiInstruction &i)
  {
    printCondBranchImmed(i,"bcdi");
  }

  void
  M470PrintVisitor::visit(const M470BciInstruction &i)
  {
    printCondBranchImmed(i,"bci");
  }

  void
  M470PrintVisitor::visit(const M470BnzrInstruction &i)
  {
    printZeroBranch(i,"bnzr");
  }

  void
  M470PrintVisitor::visit(const M470BzrInstruction &i)
  {
    printZeroBranch(i,"bzr");
  }

  void
  M470PrintVisitor::visit(const M470BnziInstruction &i)
  {
    printZeroBranchImmed(i,"bnzi");
  }

  void
  M470PrintVisitor::visit(const M470BziInstruction &i)
  {
    printZeroBranchImmed(i,"bzi");
  }

  void
  M470PrintVisitor::visit(const M470TsetbInstruction &i)
  {
    printTestBitBranch(i,"tsetb");
  }

  void
  M470PrintVisitor::visit(const M470TclrbInstruction &i)
  {
    printTestBitBranch(i,"tclrb");
  }

  void
  M470PrintVisitor::visit(const M470RnmiInstruction &i)
  {
    printReturn(i,"rnmi");
  }

  void
  M470PrintVisitor::visit(const M470RintInstruction &i)
  {
    printReturn(i,"rint");
  }

  void
  M470PrintVisitor::visit(const M470BrsInstruction &i)
  {
    getOutputStream() << "brs ";
    i.getDst()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470BrslInstruction &i)
  {
    getOutputStream() << "brsl ";
    i.getBrslFlags()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470BrspreInstruction &i)
  {
    getOutputStream() << "brspre";
  }

  void
  M470PrintVisitor::visit(const M470CmpInstruction &i)
  {
    printCompareBranch(i,"cmp");
  }

  void
  M470PrintVisitor::visit(const M470CmpiInstruction &i)
  {
    printCompareBranch(i,"cmpi");
  }

  void
  M470PrintVisitor::visit(const M470CmprInstruction &i)
  {
    printCompareSign(i,"cmpr");
  }

  void
  M470PrintVisitor::visit(const M470CmpriInstruction &i)
  {
    printCompareSign(i,"cmpri");
  }

  void
  M470PrintVisitor::visit(const M470DepbInstruction &i)
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
  M470PrintVisitor::visit(const M470DepbiInstruction &i)
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
  M470PrintVisitor::visit(const M470ExtbInstruction &i)
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
  M470PrintVisitor::visit(const M470CmovInstruction &i)
  {
    printCmov(i,"cmov");
  }

  void
  M470PrintVisitor::visit(const M470CmoviInstruction &i)
  {
    printCmov(i,"cmovi");
  }

  void
  M470PrintVisitor::visit(const M470DmapInstruction &i)
  {
    printDma(i,"dmap");
  }

  void
  M470PrintVisitor::visit(const M470DmasrInstruction &i)
  {
    printDma(i,"dmasr");
  }

  void
  M470PrintVisitor::visit(const M470Dmau0Instruction &i)
  {
    printDma(i,"dmau0");
  }

  void
  M470PrintVisitor::visit(const M470Dmau1Instruction &i)
  {
    printDma(i,"dmau1");
  }
  
  void
  M470PrintVisitor::visit(const M470LihInstruction &i)
  {
    printLoadImmediate(i,"lih");
  }

  void
  M470PrintVisitor::visit(const M470LilInstruction &i)
  {
    printLoadImmediate(i,"lil");
  }

  void
  M470PrintVisitor::visit(const M470LwihInstruction &i)
  {
    printLoadHalfword(i,"lwih");
  }

  void
  M470PrintVisitor::visit(const M470LwilInstruction &i)
  {
    printLoadHalfword(i,"lwil");
  }

  void
  M470PrintVisitor::visit(const M470LaihInstruction &i)
  {
    printLoadImmediate(i,"laih");
  }

  void
  M470PrintVisitor::visit(const M470LailInstruction &i)
  {
    printLoadImmediate(i,"lail");
  }

  void
  M470PrintVisitor::visit(const M470NopInstruction &i)
  {
    getOutputStream() << "nop";
  }

  void
  M470PrintVisitor::visit(const M470Hec5Instruction &i)
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
  M470PrintVisitor::visit(const M470MvInstruction &i)
  {
    getOutputStream() << "mv ";
    i.getSrc()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470MvhrInstruction &i)
  {
    getOutputStream() << "mvhr ";
    i.getSrc()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getMvhFlag()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470MvrhInstruction &i)
  {
    getOutputStream() << "mvrh ";
    i.getSrc()->accept(*this);
    getOutputStream() << " ";
    i.getDst()->accept(*this);
    getOutputStream() << " ";
    i.getMvhFlag()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470UnlinkInstruction &i)
  {
    getOutputStream() << "unlink ";
    i.getRegs()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470LinkInstruction &i)
  {
    printLink(i,"link");
  }

  void
  M470PrintVisitor::visit(const M470LinksInstruction &i)
  {
    printLink(i,"links");
  }

  void
  M470PrintVisitor::visit(const M470LmmInstruction &i)
  {
    printLoad(i,"lmm");
  }

  void
  M470PrintVisitor::visit(const M470LmmsInstruction &i)
  {
    printLoad(i,"lmms");
  }

  void
  M470PrintVisitor::visit(const M470LspInstruction &i)
  {
    printLoad(i,"lsp");
  }

  void
  M470PrintVisitor::visit(const M470SmmInstruction &i)
  {
    printStore(i,"smm");
  }

  void
  M470PrintVisitor::visit(const M470SmmsInstruction &i)
  {
    printStore(i,"smms");
  }

  void
  M470PrintVisitor::visit(const M470SspInstruction &i)
  {
    printStore(i,"ssp");
  }

  void
  M470PrintVisitor::printTssRc(const TssRcOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470PutInstruction &i)
  {
    getOutputStream() << "put ";
    i.getRsa()->accept(*this);
    getOutputStream() << " ";
    i.getRsb()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470GetInstruction &i)
  {
    printTssRc(i,"get");
  }

  void
  M470PrintVisitor::visit(const M470PolInstruction &i)
  {
    printTssRc(i,"pol");
  }

  void
  M470PrintVisitor::printTssNoRc(const TssNoRcOpInstruction &i, const char *mnemonic)
  {
    getOutputStream() << mnemonic << " ";
    getOutputStream() << " ";
    i.getParOffset()->accept(*this);
    getOutputStream() << " ";
    i.getPosOffset()->accept(*this);
    getOutputStream() << " ";
    i.getTssFlags()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470PutcInstruction &i)
  {
    getOutputStream() << "putc ";
    getOutputStream() << " ";

    i.getParOffset()->accept(*this);
    getOutputStream() << " ";

    i.getPosOffset()->accept(*this);
    getOutputStream() << " ";

    i.getPipeDepth()->accept(*this);
    getOutputStream() << " ";

    i.getTssFlags()->accept(*this);
  }

  void
  M470PrintVisitor::visit(const M470GetcInstruction &i)
  {
    printTssNoRc(i,"getc");
  }

  void
  M470PrintVisitor::visit(const M470PolcInstruction &i)
  {
    printTssNoRc(i,"polc");
  }

}
