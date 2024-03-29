#ifndef _M480_VISITOR_H
#define _M480_VISITOR_H

#include <OctaveVisitor.h>

namespace Llir
{

  class M480AddneInstruction;
  class M480AddneiInstruction;
  class M480AddwhInstruction;
  class M480AddwlInstruction;
  class M480AddwwInstruction;
  class M480AddlInstruction;
  class M480SubwhInstruction;
  class M480SubwlInstruction;
  class M480SubwwInstruction;
  class M480SublInstruction;
  class M480AddwhiInstruction;
  class M480AddwliInstruction;
  class M480AddwwiInstruction;
  class M480AddliInstruction;
  class M480SubwhiInstruction;
  class M480SubwliInstruction;
  class M480SubwwiInstruction;
  class M480SubliInstruction;
  class M480FfsInstruction;
  class M480FlsInstruction;
  class M480ParInstruction;
  class M480AddInstruction;
  class M480Add4xInstruction;
  class M480AddcInstruction;
  class M480AndInstruction;
  class M480MaxInstruction;
  class M480MinInstruction;
  class M480OrInstruction;
  class M480SubInstruction;
  class M480SubbInstruction;
  class M480XorInstruction;
  class M480AddiInstruction;
  class M480AddciInstruction;
  class M480SubiInstruction;
  class M480SubbiInstruction;
  class M480RandInstruction;
  class M480RotlInstruction;
  class M480RotrInstruction;
  class M480ClrbInstruction;
  class M480SetbInstruction;
  class M480ShftInstruction;
  class M480ShftaInstruction;
  class M480ShlInstruction;
  class M480ShrInstruction;
  class M480ShraInstruction;
  class M480RandiInstruction;
  class M480RotliInstruction;
  class M480RotriInstruction;
  class M480SetbiInstruction;
  class M480ClrbiInstruction;
  class M480ShliInstruction;
  class M480ShriInstruction;
  class M480ShraiInstruction;
  class M480MaxiInstruction;
  class M480MiniInstruction;
  class M480AndiInstruction;
  class M480OriInstruction;
  class M480XoriInstruction;
  class M480MulInstruction;
  class M480MulhInstruction;
  class M480MuliInstruction;
  class M480MulhiInstruction;
  class M480AddneInstruction;
  class M480AddneiInstruction;
  class M480ByteswInstruction;
  class M480BcdrInstruction;
  class M480BcrInstruction;
  class M480BcdiInstruction;
  class M480BciInstruction;
  class M480BnzrInstruction;
  class M480BzrInstruction;
  class M480BnziInstruction;
  class M480BziInstruction;
  class M480TsetbInstruction;
  class M480TclrbInstruction;
  class M480RnmiInstruction;
  class M480RintInstruction;
  class M480BrsInstruction;
  class M480BrslInstruction;
  class M480BrspreInstruction;
  class M480CmpInstruction;
  class M480CmpiInstruction;
  class M480JcmpInstruction;
  class M480JcmpiInstruction;
  class M480CmprInstruction;
  class M480CmpriInstruction;
  class M480BiInstruction;
  class M480BrInstruction;
  class M480JtablebrInstruction;
  class M480JtableRelativebrInstruction;
  class M480DepbInstruction;
  class M480DepbiInstruction;
  class M480ExtbInstruction;
  class M480CmovInstruction;
  class M480CmoviInstruction;
  class M480DmapInstruction;
  class M480DmasrInstruction;
  class M480Dmau0Instruction;
  class M480Dmau1Instruction;
  class M480LihInstruction;
  class M480LilInstruction;
  class M480LwihInstruction;
  class M480LwilInstruction;
  class M480LaihInstruction;
  class M480LailInstruction;
  class M480NopInstruction;
  class M480Hec5Instruction;
  class M480JHec5Instruction;
  class M480MvInstruction;
  class M480MvhrInstruction;
  class M480MvrhInstruction;
  class M480UnlinkInstruction;
  class M480LinkInstruction;
  class M480LinksInstruction;
  class M480LinkspInstruction;
  class M480LinksplInstruction;
  class M480LinksrInstruction;
  class M480LinksdInstruction;
  class M480LinkccInstruction;
  class M480LinkcclInstruction;
  class M480LinksioInstruction;
  class M480LmmInstruction;
  class M480LmmspInstruction;
  class M480LmmsplInstruction;
  class M480LmmsrInstruction;
  class M480LmmsdInstruction;
  class M480LmmccInstruction;
  class M480LmmcclInstruction;
  class M480LmmsiInstruction;
  class M480LmmsInstruction;
  class M480LspInstruction;
  class M480SmmInstruction;
  class M480SmmspInstruction;
  class M480SmmsplInstruction;
  class M480SmmsrInstruction;
  class M480SmmsdInstruction;
  class M480SmmccInstruction;
  class M480SmmcclInstruction;
  class M480SmmsiInstruction;
  class M480SmmsInstruction;
  class M480SspInstruction;
  class M480GetInstruction;
  class M480PutcInstruction;
  class M480PutmInstruction;
  class M480PutpInstruction;
  class M480PutdInstruction;
  class M480GetcInstruction;


  class M480JaddlInstruction ;
  class M480JaddliInstruction ;
  class M480JaddwhInstruction ;
  class M480JaddwhiInstruction ;
  class M480JaddwlInstruction ;
  class M480JaddwliInstruction ;
  class M480JaddwwInstruction ;
  class M480JaddwwiInstruction ;
  class M480JsublInstruction ;
  class M480JsubliInstruction ;
  class M480JsubwhInstruction ;
  class M480JsubwhiInstruction ;
  class M480JsubwlInstruction ;
  class M480JsubwliInstruction ;
  class M480JsubwwInstruction ;
  class M480JsubwwiInstruction ;
  class M480JbciInstruction ;
  class M480JbcrInstruction ;  
  class M480JbcdiInstruction ;
  class M480JbcdrInstruction ;
  class M480JrnmiInstruction ;
  class M480JrintInstruction ;
  class M480JbiInstruction ;
  class M480JbnzrInstruction ;
  class M480JbnziInstruction ;
  class M480JbrInstruction ;
  class M480JbrsInstruction ;
  class M480JbrslInstruction ;
  class M480JbzrInstruction ;
  class M480JbziInstruction ;
  class M480JtsetbInstruction ;
  class M480JtclrbInstruction ;




  class M480Visitor
    {

    public:

      virtual void visit(const M480AddwhInstruction &) = 0;
      virtual void visit(const M480AddwlInstruction &) = 0;
      virtual void visit(const M480AddwwInstruction &) = 0;
      virtual void visit(const M480AddlInstruction &) = 0;
      virtual void visit(const M480SubwhInstruction &) = 0;
      virtual void visit(const M480SubwlInstruction &) = 0;
      virtual void visit(const M480SubwwInstruction &) = 0;
      virtual void visit(const M480SublInstruction &) = 0;
      virtual void visit(const M480AddwhiInstruction &) = 0;
      virtual void visit(const M480AddwliInstruction &) = 0;
      virtual void visit(const M480AddwwiInstruction &) = 0;
      virtual void visit(const M480AddliInstruction &) = 0;
      virtual void visit(const M480SubwhiInstruction &) = 0;
      virtual void visit(const M480SubwliInstruction &) = 0;
      virtual void visit(const M480SubwwiInstruction &) = 0;
      virtual void visit(const M480SubliInstruction &) = 0;
      virtual void visit(const M480FfsInstruction &) = 0;
      virtual void visit(const M480FlsInstruction &) = 0;
      virtual void visit(const M480ParInstruction &) = 0;
      virtual void visit(const M480AddInstruction &) = 0;
      virtual void visit(const M480Add4xInstruction &) = 0;
      virtual void visit(const M480AddcInstruction &) = 0;
      virtual void visit(const M480AndInstruction &) = 0;
      virtual void visit(const M480MaxInstruction &) = 0;
      virtual void visit(const M480MinInstruction &) = 0;
      virtual void visit(const M480OrInstruction &) = 0;
      virtual void visit(const M480SubInstruction &) = 0;
      virtual void visit(const M480SubbInstruction &) = 0;
      virtual void visit(const M480XorInstruction &) = 0;
      virtual void visit(const M480AddiInstruction &) = 0;
      virtual void visit(const M480AddciInstruction &) = 0;
      virtual void visit(const M480SubiInstruction &) = 0;
      virtual void visit(const M480SubbiInstruction &) = 0;  
      virtual void visit(const M480RandInstruction &) = 0;
      virtual void visit(const M480RotlInstruction &) = 0;
      virtual void visit(const M480RotrInstruction &) = 0;
      virtual void visit(const M480ClrbInstruction &) = 0;
      virtual void visit(const M480SetbInstruction &) = 0;
      virtual void visit(const M480ShftInstruction &) = 0;
      virtual void visit(const M480ShftaInstruction &) = 0;
      virtual void visit(const M480ShlInstruction &) = 0;
      virtual void visit(const M480ShrInstruction &) = 0;
      virtual void visit(const M480ShraInstruction &) = 0;
      virtual void visit(const M480RandiInstruction &) = 0;
      virtual void visit(const M480RotliInstruction &) = 0;
      virtual void visit(const M480RotriInstruction &) = 0;
      virtual void visit(const M480SetbiInstruction &) = 0;
      virtual void visit(const M480ClrbiInstruction &) = 0;
      virtual void visit(const M480ShliInstruction &) = 0;
      virtual void visit(const M480ShriInstruction &) = 0;
      virtual void visit(const M480ShraiInstruction &) = 0;
      virtual void visit(const M480MaxiInstruction &) = 0;
      virtual void visit(const M480MiniInstruction &) = 0;
      virtual void visit(const M480AndiInstruction &) = 0;
      virtual void visit(const M480OriInstruction &) = 0;
      virtual void visit(const M480XoriInstruction &) = 0;
      virtual void visit(const M480MulInstruction &) = 0;
      virtual void visit(const M480MulhInstruction &) = 0;
      virtual void visit(const M480MuliInstruction &) = 0;
      virtual void visit(const M480MulhiInstruction &) = 0;
      virtual void visit(const M480AddneInstruction &) = 0;
      virtual void visit(const M480AddneiInstruction &) = 0;
      virtual void visit(const M480ByteswInstruction &) = 0;
      virtual void visit(const M480BcdrInstruction &) = 0;
      virtual void visit(const M480BcrInstruction &) = 0;
      virtual void visit(const M480BcdiInstruction &) = 0;
      virtual void visit(const M480BciInstruction &) = 0;
      virtual void visit(const M480BnzrInstruction &) = 0;
      virtual void visit(const M480BzrInstruction &) = 0;
      virtual void visit(const M480BnziInstruction &) = 0;
      virtual void visit(const M480BziInstruction &) = 0;
      virtual void visit(const M480TsetbInstruction &) = 0;
      virtual void visit(const M480TclrbInstruction &) = 0;
      virtual void visit(const M480RnmiInstruction &) = 0;
      virtual void visit(const M480RintInstruction &) = 0;
      virtual void visit(const M480BrsInstruction &) = 0;
      virtual void visit(const M480BrslInstruction &) = 0;
      virtual void visit(const M480BrspreInstruction &) = 0;
      virtual void visit(const M480CmpInstruction &) = 0;
      virtual void visit(const M480CmpiInstruction &) = 0;
      virtual void visit(const M480CmprInstruction &) = 0;
      virtual void visit(const M480CmpriInstruction &) = 0;
      virtual void visit(const M480BiInstruction &) = 0;
      virtual void visit(const M480BrInstruction &) = 0;
      virtual void visit(const M480JtablebrInstruction &) = 0;
      virtual void visit(const M480JtableRelativebrInstruction &) = 0;
      virtual void visit(const M480DepbInstruction &) = 0;
      virtual void visit(const M480DepbiInstruction &) = 0;
      virtual void visit(const M480ExtbInstruction &) = 0;
      virtual void visit(const M480CmovInstruction &) = 0;
      virtual void visit(const M480CmoviInstruction &) = 0;
      virtual void visit(const M480DmapInstruction &) = 0;
      virtual void visit(const M480DmasrInstruction &) = 0;
      virtual void visit(const M480Dmau0Instruction &) = 0;
      virtual void visit(const M480Dmau1Instruction &) = 0;
      virtual void visit(const M480LihInstruction &) = 0;
      virtual void visit(const M480LilInstruction &) = 0;
      virtual void visit(const M480LwihInstruction &) = 0;
      virtual void visit(const M480LwilInstruction &) = 0;
      virtual void visit(const M480LaihInstruction &) = 0;
      virtual void visit(const M480LailInstruction &) = 0;
      virtual void visit(const M480NopInstruction &) = 0;
      virtual void visit(const M480Hec5Instruction &) = 0;
      virtual void visit(const M480JHec5Instruction &) = 0;
      virtual void visit(const M480MvInstruction &) = 0;
      virtual void visit(const M480MvhrInstruction &) = 0;
      virtual void visit(const M480MvrhInstruction &) = 0;
      virtual void visit(const M480UnlinkInstruction &) = 0;
      virtual void visit(const M480LinkInstruction &) = 0;
      virtual void visit(const M480LinksInstruction &) = 0;
      virtual void visit(const M480LinkspInstruction &) = 0;
      virtual void visit(const M480LinksplInstruction &) = 0;
      virtual void visit(const M480LinksrInstruction &) = 0;
      virtual void visit(const M480LinksdInstruction &) = 0;
      virtual void visit(const M480LinkccInstruction &) = 0;
      virtual void visit(const M480LinkcclInstruction &) = 0;
      virtual void visit(const M480LinksioInstruction &) = 0;
      virtual void visit(const M480LmmInstruction &) = 0;
      virtual void visit(const M480LmmspInstruction &) = 0;
      virtual void visit(const M480LmmsplInstruction &) = 0;
      virtual void visit(const M480LmmsrInstruction &) = 0;
      virtual void visit(const M480LmmsdInstruction &) = 0;
      virtual void visit(const M480LmmccInstruction &) = 0;
      virtual void visit(const M480LmmcclInstruction &) = 0;
      virtual void visit(const M480LmmsiInstruction &) = 0;
      virtual void visit(const M480LmmsInstruction &) = 0;
      virtual void visit(const M480LspInstruction &) = 0;
      virtual void visit(const M480SmmInstruction &) = 0;
      virtual void visit(const M480SmmspInstruction &) = 0;
      virtual void visit(const M480SmmsplInstruction &) = 0;
      virtual void visit(const M480SmmsrInstruction &) = 0;
      virtual void visit(const M480SmmsdInstruction &) = 0;
      virtual void visit(const M480SmmccInstruction &) = 0;
      virtual void visit(const M480SmmcclInstruction &) = 0;
      virtual void visit(const M480SmmsiInstruction &) = 0;
      virtual void visit(const M480SmmsInstruction &) = 0;
      virtual void visit(const M480SspInstruction &) = 0;
      virtual void visit(const M480GetInstruction &) = 0;
      virtual void visit(const M480PutcInstruction &) = 0;
      virtual void visit(const M480PutmInstruction &) = 0;
      virtual void visit(const M480PutpInstruction &) = 0;
      virtual void visit(const M480PutdInstruction &) = 0;

      virtual void visit(const M480JaddlInstruction &) = 0;
      virtual void visit(const M480JaddliInstruction &) = 0;
      virtual void visit(const M480JaddwhInstruction &) = 0;
      virtual void visit(const M480JaddwhiInstruction &) = 0;
      virtual void visit(const M480JaddwlInstruction &) = 0;
      virtual void visit(const M480JaddwliInstruction &) = 0;
      virtual void visit(const M480JaddwwInstruction &) = 0;
      virtual void visit(const M480JaddwwiInstruction &) = 0;
      virtual void visit(const M480JsublInstruction &) = 0;
      virtual void visit(const M480JsubliInstruction &) = 0;
      virtual void visit(const M480JsubwhInstruction &) = 0;
      virtual void visit(const M480JsubwhiInstruction &) = 0;
      virtual void visit(const M480JsubwlInstruction &) = 0;
      virtual void visit(const M480JsubwliInstruction &) = 0;
      virtual void visit(const M480JsubwwInstruction &) = 0;
      virtual void visit(const M480JsubwwiInstruction &) = 0;
      virtual void visit(const M480JbcdiInstruction &) = 0;
      virtual void visit(const M480JbcdrInstruction &) = 0;
      virtual void visit(const M480JbciInstruction &) = 0;
      virtual void visit(const M480JbcrInstruction &) = 0;
      virtual void visit(const M480JrnmiInstruction &) = 0;
      virtual void visit(const M480JrintInstruction &) = 0;
      virtual void visit(const M480JbiInstruction &) = 0;
      virtual void visit(const M480JbnzrInstruction &) = 0;
      virtual void visit(const M480JbnziInstruction &) = 0;
      virtual void visit(const M480JbrInstruction &) = 0;
      virtual void visit(const M480JbrsInstruction &) = 0;
      virtual void visit(const M480JbrslInstruction &) = 0;
      virtual void visit(const M480JbzrInstruction &) = 0;
      virtual void visit(const M480JbziInstruction &) = 0;
      virtual void visit(const M480JcmpInstruction &) = 0;
      virtual void visit(const M480JcmpiInstruction &) = 0;
      virtual void visit(const M480JtsetbInstruction &) = 0;
      virtual void visit(const M480JtclrbInstruction &) = 0;



    };
  
}
#endif
