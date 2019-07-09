#ifndef _M480_PRINT_VISITOR_H
#define _M480_PRINT_VISITOR_H

#include <LlirVisitor.h>
#include <OctavePrintVisitor.h>

#include "M480Visitor.h"
#include <ostream>

using std::ostream;

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

  class M480PrintVisitor : public OctavePrintVisitor, 
			   public M480Visitor
    {
    public:
      M480PrintVisitor(ostream& outputStream);
      ~M480PrintVisitor();
      
      void visit(const M480AddwhInstruction &);
      void visit(const M480AddwlInstruction &);
      void visit(const M480AddwwInstruction &);
      void visit(const M480AddlInstruction &);
      void visit(const M480SubwhInstruction &);
      void visit(const M480SubwlInstruction &);
      void visit(const M480SubwwInstruction &);
      void visit(const M480SublInstruction &);
      void visit(const M480AddwhiInstruction &);
      void visit(const M480AddwliInstruction &);
      void visit(const M480AddwwiInstruction &);
      void visit(const M480AddliInstruction &);
      void visit(const M480SubwhiInstruction &);
      void visit(const M480SubwliInstruction &);
      void visit(const M480SubwwiInstruction &);
      void visit(const M480SubliInstruction &);
      void visit(const M480FfsInstruction &);
      void visit(const M480FlsInstruction &);
      void visit(const M480ParInstruction &);
      void visit(const M480AddInstruction &);
      void visit(const M480Add4xInstruction &);
      void visit(const M480AddcInstruction &);
      void visit(const M480AndInstruction &);
      void visit(const M480MaxInstruction &);
      void visit(const M480MinInstruction &);
      void visit(const M480OrInstruction &);
      void visit(const M480SubInstruction &);
      void visit(const M480SubbInstruction &);
      void visit(const M480XorInstruction &);
      void visit(const M480AddiInstruction &);
      void visit(const M480AddciInstruction &);
      void visit(const M480SubiInstruction &);
      void visit(const M480SubbiInstruction &);  
      void visit(const M480RandInstruction &);
      void visit(const M480RotlInstruction &);
      void visit(const M480RotrInstruction &);
      void visit(const M480ClrbInstruction &);
      void visit(const M480SetbInstruction &);
      void visit(const M480ShftInstruction &);
      void visit(const M480ShftaInstruction &);
      void visit(const M480ShlInstruction &);
      void visit(const M480ShrInstruction &);
      void visit(const M480ShraInstruction &);
      void visit(const M480RandiInstruction &);
      void visit(const M480RotliInstruction &);
      void visit(const M480RotriInstruction &);
      void visit(const M480SetbiInstruction &);
      void visit(const M480ClrbiInstruction &);
      void visit(const M480ShliInstruction &);
      void visit(const M480ShriInstruction &);
      void visit(const M480ShraiInstruction &);
      void visit(const M480MaxiInstruction &);
      void visit(const M480MiniInstruction &);
      void visit(const M480AndiInstruction &);
      void visit(const M480OriInstruction &);
      void visit(const M480XoriInstruction &);
      void visit(const M480MulInstruction &);
      void visit(const M480MulhInstruction &);
      void visit(const M480MuliInstruction &);
      void visit(const M480MulhiInstruction &);
      void visit(const M480AddneInstruction &);
      void visit(const M480AddneiInstruction &);
      void visit(const M480ByteswInstruction &);
      void visit(const M480BcdrInstruction &);
      void visit(const M480BcrInstruction &);
      void visit(const M480BcdiInstruction &);
      void visit(const M480BciInstruction &);
      void visit(const M480BnzrInstruction &);
      void visit(const M480BzrInstruction &);
      void visit(const M480BnziInstruction &);
      void visit(const M480BziInstruction &);
      void visit(const M480TsetbInstruction &);
      void visit(const M480TclrbInstruction &);
      void visit(const M480RnmiInstruction &);
      void visit(const M480RintInstruction &);
      void visit(const M480BrsInstruction &);
      void visit(const M480BrslInstruction &);
      void visit(const M480BrspreInstruction &);
      void visit(const M480CmpInstruction &);
      void visit(const M480CmpiInstruction &);
      void visit(const M480CmprInstruction &);
      void visit(const M480CmpriInstruction &);
      void visit(const M480BiInstruction &);
      void visit(const M480BrInstruction &);
      void visit(const M480JtablebrInstruction &);
      void visit(const M480JtableRelativebrInstruction &);
      void visit(const M480DepbInstruction &);
      void visit(const M480DepbiInstruction &);
      void visit(const M480ExtbInstruction &);
      void visit(const M480CmovInstruction &);
      void visit(const M480CmoviInstruction &);
      void visit(const M480DmapInstruction &);
      void visit(const M480DmasrInstruction &);
      void visit(const M480Dmau0Instruction &);
      void visit(const M480Dmau1Instruction &);
      void visit(const M480LihInstruction &);
      void visit(const M480LilInstruction &);
      void visit(const M480LwihInstruction &);
      void visit(const M480LwilInstruction &);
      void visit(const M480LaihInstruction &);
      void visit(const M480LailInstruction &);
      void visit(const M480NopInstruction &);
      void visit(const M480Hec5Instruction &);
      void visit(const M480JHec5Instruction &);
      void visit(const M480MvInstruction &);
      void visit(const M480MvrhInstruction &);
      void visit(const M480MvhrInstruction &);
      void visit(const M480UnlinkInstruction &);
      void visit(const M480LinkInstruction &);
      void visit(const M480LinksInstruction &);
      void visit(const M480LinkspInstruction &);
      void visit(const M480LinksplInstruction &);
      void visit(const M480LinksrInstruction &);
      void visit(const M480LinksdInstruction &);
      void visit(const M480LinkccInstruction &);
      void visit(const M480LinkcclInstruction &);
      void visit(const M480LinksioInstruction &);
      void visit(const M480LmmInstruction &);
      void visit(const M480LmmspInstruction &);
      void visit(const M480LmmsplInstruction &);
      void visit(const M480LmmsrInstruction &);
      void visit(const M480LmmsdInstruction &);
      void visit(const M480LmmccInstruction &);
      void visit(const M480LmmcclInstruction &);
      void visit(const M480LmmsiInstruction &);
      void visit(const M480LmmsInstruction &);
      void visit(const M480LspInstruction &);
      void visit(const M480SmmInstruction &);
      void visit(const M480SmmspInstruction &);
      void visit(const M480SmmsplInstruction &);
      void visit(const M480SmmsrInstruction &);
      void visit(const M480SmmsdInstruction &);
      void visit(const M480SmmccInstruction &);
      void visit(const M480SmmcclInstruction &);
      void visit(const M480SmmsiInstruction &);
      void visit(const M480SmmsInstruction &);
      void visit(const M480SspInstruction &);
      void visit(const M480GetInstruction &);
      void visit(const M480PutcInstruction &);
      void visit(const M480PutmInstruction &);
      void visit(const M480PutpInstruction &);
      void visit(const M480PutdInstruction &);

      void visit(const M480JaddlInstruction &);
      void visit(const M480JaddliInstruction &);
      void visit(const M480JaddwhInstruction &);
      void visit(const M480JaddwhiInstruction &);
      void visit(const M480JaddwlInstruction &);
      void visit(const M480JaddwliInstruction &);
      void visit(const M480JaddwwInstruction &);
      void visit(const M480JaddwwiInstruction &);
      void visit(const M480JsublInstruction &);
      void visit(const M480JsubliInstruction &);
      void visit(const M480JsubwhInstruction &);
      void visit(const M480JsubwhiInstruction &);
      void visit(const M480JsubwlInstruction &);
      void visit(const M480JsubwliInstruction &);
      void visit(const M480JsubwwInstruction &);
      void visit(const M480JsubwwiInstruction &);
      void visit(const M480JbcdiInstruction &);
      void visit(const M480JbcdrInstruction &);
      void visit(const M480JbciInstruction &);
      void visit(const M480JbcrInstruction &);
      void visit(const M480JrnmiInstruction &);
      void visit(const M480JrintInstruction &);
      void visit(const M480JbiInstruction &);
      void visit(const M480JbnzrInstruction &);
      void visit(const M480JbnziInstruction &);
      void visit(const M480JbrInstruction &);
      void visit(const M480JbrsInstruction &);
      void visit(const M480JbrslInstruction &);
      void visit(const M480JbzrInstruction &);
      void visit(const M480JbziInstruction &);
      void visit(const M480JcmpInstruction &);
      void visit(const M480JcmpiInstruction &);
      void visit(const M480JtsetbInstruction &);
      void visit(const M480JtclrbInstruction &);


    private:

      void printTssRc(const TssRcOpInstruction &i, const char *mnemonic);
      void printTssNoRc(const TssNoRcOpInstruction &i, const char *mnemonic);
    };
}
#endif
