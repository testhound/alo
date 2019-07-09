#ifndef _M470_PRINT_VISITOR_H
#define _M470_PRINT_VISITOR_H

#include <ostream>
using std::ostream;


#include <LlirVisitor.h>
#include <OctavePrintVisitor.h>
#include "M470Visitor.h"



namespace Llir
{

  class Alu2OpBranchInstruction;
  class Alu2OpFindInstruction;
  class Alu3OpAbcModInstruction;
  class Alu3OpAbcInstruction;
  class Alu3OpSxInstruction;
  class Alu3OpInstruction;
  class CondBranchInstruction;
  class CondBranchImmedInstruction;
  class ZeroBranchInstruction;
  class ZeroBranchImmedInstruction;
  class TestBitBranchInstruction;
  class ReturnOpInstruction;
  class CompareOpSignInstruction;
  class CompareOpBranchInstruction;
  class CmovOpInstruction;
  class DmaOpInstruction;
  class LoadImmediateInstruction;
  class LoadHalfwordInstruction;
  class MultiRegLinkInstruction;
  class MultiRegLoadInstruction;
  class MultiRegStoreInstruction;
  class TssRcOpInstruction;
  class TssNoRcOpInstruction;

  class M470PrintVisitor : public OctavePrintVisitor, 
			   public M470Visitor
    {
    public:
      M470PrintVisitor(ostream& outputStream);
      ~M470PrintVisitor();

      void visit(const M470AddwhInstruction &);
      void visit(const M470AddwlInstruction &);
      void visit(const M470AddwwInstruction &);
      void visit(const M470AddlInstruction &);
      void visit(const M470SubwhInstruction &);
      void visit(const M470SubwlInstruction &);
      void visit(const M470SubwwInstruction &);
      void visit(const M470SublInstruction &);
      void visit(const M470AddwhiInstruction &);
      void visit(const M470AddwliInstruction &);
      void visit(const M470AddwwiInstruction &);
      void visit(const M470AddliInstruction &);
      void visit(const M470SubwhiInstruction &);
      void visit(const M470SubwliInstruction &);
      void visit(const M470SubwwiInstruction &);
      void visit(const M470SubliInstruction &);
      void visit(const M470FfsInstruction &);
      void visit(const M470FlsInstruction &);
      void visit(const M470ParInstruction &);
      void visit(const M470AddInstruction &);
      void visit(const M470Add4xInstruction &);
      void visit(const M470AddcInstruction &);
      void visit(const M470AndInstruction &);
      void visit(const M470MaxInstruction &);
      void visit(const M470MinInstruction &);
      void visit(const M470OrInstruction &);
      void visit(const M470SubInstruction &);
      void visit(const M470SubbInstruction &);
      void visit(const M470XorInstruction &);
      void visit(const M470AddiInstruction &);
      void visit(const M470AddciInstruction &);
      void visit(const M470SubiInstruction &);
      void visit(const M470SubbiInstruction &);  
      void visit(const M470RandInstruction &);
      void visit(const M470RotlInstruction &);
      void visit(const M470RotrInstruction &);
      void visit(const M470ClrbInstruction &);
      void visit(const M470SetbInstruction &);
      void visit(const M470ShftInstruction &);
      void visit(const M470ShftaInstruction &);
      void visit(const M470ShlInstruction &);
      void visit(const M470ShrInstruction &);
      void visit(const M470ShraInstruction &);
      void visit(const M470RandiInstruction &);
      void visit(const M470RotliInstruction &);
      void visit(const M470RotriInstruction &);
      void visit(const M470SetbiInstruction &);
      void visit(const M470ClrbiInstruction &);
      void visit(const M470ShliInstruction &);
      void visit(const M470ShriInstruction &);
      void visit(const M470ShraiInstruction &);
      void visit(const M470MaxiInstruction &);
      void visit(const M470MiniInstruction &);
      void visit(const M470AndiInstruction &);
      void visit(const M470OriInstruction &);
      void visit(const M470XoriInstruction &);
      void visit(const M470MulInstruction &);
      void visit(const M470MulhInstruction &);
      void visit(const M470DivInstruction &);
      void visit(const M470MuliInstruction &);
      void visit(const M470MulhiInstruction &);
      void visit(const M470DiviInstruction &);
      void visit(const M470AddneInstruction &);
      void visit(const M470AddneiInstruction &);
      void visit(const M470ByteswInstruction &);
      void visit(const M470BcdrInstruction &);
      void visit(const M470BcrInstruction &);
      void visit(const M470BcdiInstruction &);
      void visit(const M470BciInstruction &);
      void visit(const M470BnzrInstruction &);
      void visit(const M470BzrInstruction &);
      void visit(const M470BnziInstruction &);
      void visit(const M470BziInstruction &);
      void visit(const M470TsetbInstruction &);
      void visit(const M470TclrbInstruction &);
      void visit(const M470RnmiInstruction &);
      void visit(const M470RintInstruction &);
      void visit(const M470BrsInstruction &);
      void visit(const M470BrslInstruction &);
      void visit(const M470BrspreInstruction &);
      void visit(const M470CmpInstruction &);
      void visit(const M470CmpiInstruction &);
      void visit(const M470CmprInstruction &);
      void visit(const M470CmpriInstruction &);
      void visit(const M470BiInstruction &);
      void visit(const M470BrInstruction &);
      void visit(const M470DepbInstruction &);
      void visit(const M470DepbiInstruction &);
      void visit(const M470ExtbInstruction &);
      void visit(const M470CmovInstruction &);
      void visit(const M470CmoviInstruction &);
      void visit(const M470DmapInstruction &);
      void visit(const M470DmasrInstruction &);
      void visit(const M470Dmau0Instruction &);
      void visit(const M470Dmau1Instruction &);
      void visit(const M470LihInstruction &);
      void visit(const M470LilInstruction &);
      void visit(const M470LwihInstruction &);
      void visit(const M470LwilInstruction &);
      void visit(const M470LaihInstruction &);
      void visit(const M470LailInstruction &);
      void visit(const M470NopInstruction &);
      void visit(const M470Hec5Instruction &);
      void visit(const M470MvInstruction &);
      void visit(const M470MvrhInstruction &);
      void visit(const M470MvhrInstruction &);
      void visit(const M470UnlinkInstruction &);
      void visit(const M470LinkInstruction &);
      void visit(const M470LinksInstruction &);

      void visit(const M470LmmInstruction &);
      void visit(const M470LmmsInstruction &);
      void visit(const M470LspInstruction &);

      void visit(const M470SmmInstruction &);
      void visit(const M470SmmsInstruction &);
      void visit(const M470SspInstruction &);

      void visit(const M470PutInstruction &);
      void visit(const M470GetInstruction &);
      void visit(const M470PolInstruction &);
      void visit(const M470PutcInstruction &);
      void visit(const M470GetcInstruction &);
      void visit(const M470PolcInstruction &);

    private:
      void printTssRc(const TssRcOpInstruction &i, const char *mnemonic);
      void printTssNoRc(const TssNoRcOpInstruction &i, const char *mnemonic);
    };
}
#endif
