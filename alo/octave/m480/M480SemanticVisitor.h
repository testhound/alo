#ifndef _M480_SEMANTIC_VISITOR_H
#define _M480_SEMANTIC_VISITOR_H

#include <OctaveAlo.h>

#include <LlirOperand.h>
#include <OctaveOperand.h>

#include <Visitor.h>
#include <LlirVisitor.h>
#include <OctaveVisitor.h>
#include <OctaveSemanticVisitor.h>
#include "M480Visitor.h"

using namespace Llir;

namespace Alo
{

  class Visitor;
  class LlirOctaveVisitor;

  class Alo;
  class OctaveSemanticAnalysisVisitor;

  class M480SemanticAnalysisVisitor : 
    public OctaveSemanticAnalysisVisitor,
    public M480Visitor
    {
    private:
      enum TssOp {PUT, GET, POL};
      
      enum MemoryRegion {CCRAM, CCRAM_LOCK, SPRAM, SPRAM_LOCK, SRAM, SDRAM, SIO, ANY};


      void checkForValidLabel(OctaveAlo &alo,
			      shared_ptr<const LlirOperand> opnd, 
			      unsigned int excLine,
			      const string &excFile) const;
      
      void checkForReturnRegister(OctaveAlo &alo,
				  shared_ptr<const LlirOperand> opnd, 
				  unsigned int excLine,
				  const string &excFile) const;

      void checkForValidCDFlag(OctaveAlo &alo,
			       shared_ptr<const LlirOperand> opnd, 
			       unsigned int excLine,
			       const string &excFile) const;

      void checkForValidESSFlag(OctaveAlo &alo,
				shared_ptr<const LlirOperand> opnd, 
				unsigned int excLine,
				const string &excFile) const;
      

      void checkForValidCandBfFlags(OctaveAlo &alo,
				    shared_ptr<const LlirOperand> opnd, 
				    unsigned int excLine,
				    const string &excFile) const;

      
      void checkSImm17Range (OctaveAlo &alo,
			     shared_ptr<const LlirOperand> opnd, 
			     unsigned int excLine,
			     const string &excFile) const;

      void checkSImmRange (shared_ptr<const LlirOperand> opnd, 
			   unsigned int bits,
			   OctaveAlo &alo,
			   unsigned int excLine,
			   const string &excFile) const;

      void checkUImm16Range (OctaveAlo &alo,
			     shared_ptr<const LlirOperand> opnd, 
			     unsigned int excLine,
			     const string &excFile) const;
      
      void checkUImmRange (shared_ptr<const LlirOperand> opnd, 
			   unsigned int bits,
			   OctaveAlo &alo,
			   unsigned int excLine,
			   const string &excFile) const;
	
      void checkAlignment (shared_ptr<const LlirOperand> opnd, 
			   unsigned int unit,
			   OctaveAlo &alo,
			   unsigned int excLine,
			   const string &excFile) const;
      
      void checkOctaveRegister (shared_ptr<const LlirOperand> opnd,
				OctaveAlo &alo,
				unsigned int excLine,
				const string &excFile) const;
      
      void checkRegister (shared_ptr<const LlirOperand> opnd,
			  OctaveAlo &alo,
			  unsigned int excLine,
			  const string &excFile) const;
      
      void checkBranchRegister (shared_ptr<const LlirOperand> opnd,
				OctaveAlo &alo,
				unsigned int excLine,
				const string &excFile) const;
      
      void checkHwRegister (shared_ptr<const LlirOperand> opnd,
			    OctaveAlo &alo,
			    unsigned int excLine,
			    const string &excFile) const;
      
      void checkTssFlags (shared_ptr<const LlirOperand> flags,
			  TssOp op,
			  OctaveAlo &alo,
			  unsigned int excLine,
			  const string &excFile) const;
      
      void checkMultiRegister (shared_ptr<const MultiRegister> regs,
			       OctaveAlo &alo,
			       unsigned int excLine,
			       const string &excFile) const;
      
      void checkRegisterPair (shared_ptr<const MultiRegister> regs,
			      OctaveAlo &alo,
			      unsigned int excLine,
			      const string &excFile) const;
      
      void checkMemory (shared_ptr<const OctaveMemory> mem,
			MemoryRegion memregion,
			unsigned int regOffBits,
			unsigned int basOffBits,
			OctaveAlo &alo,
			unsigned int excLine,
			const string &excFile) const;
      
      void checkMemoryRegion (shared_ptr<const BasePlusOffset> basoff,
			      MemoryRegion memreg,
			      OctaveAlo &alo,
			      unsigned int excLine,
			      const string &excFile) const;
      
      void checkBitField (shared_ptr<const LlirOperand> start,
			  shared_ptr<const LlirOperand> length,
			  OctaveAlo &alo,
			  unsigned int excLine,
			  const string &excFile) const;

      void checkSingleWordDest(shared_ptr<const MultiRegister> regs,
			       OctaveAlo &alo,
			       unsigned int excLine,
			       const string &excFile) const;

      void checkIfCallInsn(shared_ptr<const LlirOperand> dst,
			  shared_ptr<const LlirOperand> labelList,
			  OctaveAlo &alo,
			  unsigned int excLine,
			  const string &excFile) const;

      void checkIndirectEntryLabels(unsigned int excLine,
				    const string &excFile,
				    shared_ptr<const LlirOperand> labelList) const;

    public:

      M480SemanticAnalysisVisitor(OctaveAlo &i);

      ~M480SemanticAnalysisVisitor();

      void visit(const InvalidOctaveInstruction& v);
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


    };



}
#endif






