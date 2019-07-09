#ifndef _M480_GEN_RTL_VISITOR_H
#define _M480_GEN_RTL_VISITOR_H


#include <map>


#include <OctaveAlo.h>

#include <LlirOperand.h>
#include <OctaveOperand.h>

#include <Visitor.h>
#include <LlirVisitor.h>
#include <OctaveVisitor.h>
#include <OctaveGenRtlVisitor.h>
#include "M480Visitor.h"
#include <string>

using namespace Llir;

namespace Alo
{




  class M480GenRtlVisitor : 
    public OctaveGenerateRtlVisitor,
    public M480Visitor
    {
    public:

      M480GenRtlVisitor(OctaveAlo &i);

      M480GenRtlVisitor(const M480GenRtlVisitor& rhs);
      const M480GenRtlVisitor& operator=(const M480GenRtlVisitor&);

      ~M480GenRtlVisitor(){}

      void visit(const M480AddInstruction &);
      void visit(const M480Add4xInstruction &);
      void visit(const M480AddcInstruction &);
      void visit(const M480AddciInstruction &);
      void visit(const M480AddiInstruction &);
      void visit(const M480AddlInstruction &);

      void visit(const M480AddliInstruction &);

      void visit(const M480AddneInstruction &);
      void visit(const M480AddneiInstruction &);
      void visit(const M480AddwhInstruction &);
      void visit(const M480AddwhiInstruction &);
      void visit(const M480AddwlInstruction &);
      void visit(const M480AddwliInstruction &);
      void visit(const M480AddwwInstruction &);
      void visit(const M480AddwwiInstruction &);
      void visit(const M480AndInstruction &);
      void visit(const M480AndiInstruction &);
      void visit(const M480BcdiInstruction &);
      void visit(const M480BcdrInstruction &);
      void visit(const M480BciInstruction &);
      void visit(const M480BcrInstruction &);
      void visit(const M480BiInstruction &);
      void visit(const M480BnzrInstruction &);
      void visit(const M480BnziInstruction &);
      void visit(const M480BrInstruction &);
      void visit(const M480JtablebrInstruction &);
      void visit(const M480JtableRelativebrInstruction &);
      void visit(const M480BrsInstruction &);
      void visit(const M480BrslInstruction &);
      void visit(const M480BrspreInstruction &);
      void visit(const M480ByteswInstruction &);
      void visit(const M480BzrInstruction &);
      void visit(const M480BziInstruction &);
      void visit(const M480ClrbInstruction &);
      void visit(const M480ClrbiInstruction &);
      void visit(const M480CmovInstruction &);
      void visit(const M480CmoviInstruction &);
      void visit(const M480CmpInstruction &);
      void visit(const M480CmpiInstruction &);
      void visit(const M480CmprInstruction &);
      void visit(const M480CmpriInstruction &);
      void visit(const M480DepbInstruction &);
      void visit(const M480DepbiInstruction &);
      void visit(const M480DmapInstruction &);
      void visit(const M480DmasrInstruction &);
      void visit(const M480Dmau0Instruction &);
      void visit(const M480Dmau1Instruction &);
      void visit(const M480ExtbInstruction &);
      void visit(const M480FlsInstruction &);
      void visit(const M480FfsInstruction &);
      void visit(const M480GetInstruction &);
      void visit(const M480Hec5Instruction &);
      void visit(const M480JHec5Instruction &);
      void visit(const M480LaihInstruction &);
      void visit(const M480LailInstruction &);
      void visit(const M480LihInstruction &);
      void visit(const M480LilInstruction &);
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
      void visit(const M480LmmsInstruction &);
      void visit(const M480LspInstruction &);
      void visit(const M480LwihInstruction &);
      void visit(const M480LwilInstruction &);
      void visit(const M480MaxiInstruction &);
      void visit(const M480MiniInstruction &);
      void visit(const M480MulInstruction &);
      void visit(const M480MulhInstruction &);
      void visit(const M480MuliInstruction &);
      void visit(const M480MulhiInstruction &);
      void visit(const M480MaxInstruction &);
      void visit(const M480MinInstruction &);
      void visit(const M480MvInstruction &);
      void visit(const M480MvrhInstruction &);
      void visit(const M480MvhrInstruction &);
      void visit(const M480UnlinkInstruction &);
      void visit(const M480NopInstruction &);
      void visit(const M480OriInstruction &);
      void visit(const M480OrInstruction &);
      void visit(const M480ParInstruction &);
      void visit(const M480PutcInstruction &);
      void visit(const M480PutmInstruction &);
      void visit(const M480PutpInstruction &);
      void visit(const M480PutdInstruction &);
      void visit(const M480RandInstruction &);
      void visit(const M480RotlInstruction &);
      void visit(const M480RotrInstruction &);
      void visit(const M480RnmiInstruction &);
      void visit(const M480RintInstruction &);
      void visit(const M480RandiInstruction &);
      void visit(const M480RotliInstruction &);
      void visit(const M480RotriInstruction &);
      void visit(const M480SubwhInstruction &);
      void visit(const M480SubwlInstruction &);
      void visit(const M480SubwwInstruction &);
      void visit(const M480SublInstruction &);
      void visit(const M480SubwhiInstruction &);
      void visit(const M480SubwliInstruction &);
      void visit(const M480SubwwiInstruction &);
      void visit(const M480SubliInstruction &);
      void visit(const M480SubInstruction &);
      void visit(const M480SubbInstruction &);
      void visit(const M480SubiInstruction &);
      void visit(const M480SubbiInstruction &);  
      void visit(const M480SetbInstruction &);
      void visit(const M480ShftInstruction &);
      void visit(const M480ShftaInstruction &);
      void visit(const M480ShlInstruction &);
      void visit(const M480ShrInstruction &);
      void visit(const M480ShraInstruction &);
      void visit(const M480SetbiInstruction &);
      void visit(const M480ShliInstruction &);
      void visit(const M480ShriInstruction &);
      void visit(const M480ShraiInstruction &);
      void visit(const M480SmmInstruction &);
      void visit(const M480SmmsInstruction &);
      void visit(const M480SspInstruction &);
      void visit(const M480TsetbInstruction &);
      void visit(const M480TclrbInstruction &);
      void visit(const M480XorInstruction &);
      void visit(const M480XoriInstruction &);
      void visit(const InvalidOctaveInstruction& v){}

      //pseudo ops...

      void visit(const M480LmmspInstruction &);
      void visit(const M480LmmsplInstruction &);
      void visit(const M480LmmsrInstruction &);
      void visit(const M480LmmsdInstruction &);
      void visit(const M480LmmccInstruction &);
      void visit(const M480LmmcclInstruction &);
      void visit(const M480LmmsiInstruction &);

      void visit(const M480SmmspInstruction &);
      void visit(const M480SmmsplInstruction &);
      void visit(const M480SmmsrInstruction &);
      void visit(const M480SmmsdInstruction &);
      void visit(const M480SmmccInstruction &);
      void visit(const M480SmmcclInstruction &);
      void visit(const M480SmmsiInstruction &);

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
      void genOperandRtl(const MvhOpInstruction &i);
      void genOperandRtl(const M480AddneInstruction &i);
      void genOperandRtl(const M480AddneiInstruction &i);
      void genOperandRtl(const Alu3OpSxInstruction &i);
      void genOperandRtl(const Alu3OpAbcInstruction &i);
      void genOperandRtl(const Alu3OpAbcModInstruction &i);
      void genOperandRtl(const Alu2OpBranchInstruction &i);
      void genOperandRtl(const Alu2OpFindInstruction &i);
      void genOperandRtl(const CondBranchImmedInstruction &i);
      void genOperandRtl(const DmaOpInstruction &i);
      void genOperandRtl(const TestBitBranchInstruction &i);
      void genOperandRtl(const ZeroBranchImmedInstruction &i);
      void genOperandRtl(const ZeroBranchInstruction &i);
      void genOperandRtl(const CmovOpInstruction &i);
      void genOperandRtl(const CompareOpSignInstruction &i);
      void genOperandRtl(const CompareOpBranchInstruction &i);
      void genOperandRtl(const MultiRegLinkInstruction &i);
      void genOperandRtl(const MultiRegLoadInstruction &i);
      void genOperandRtl(const MultiRegStoreInstruction &i);
      void genOperandRtl(const BitOpInstruction &i);
      void genOperandRtl(const BitOpImmInstruction &i);
      void genOperandRtl(const LoadImmediateInstruction &i);
      void genOperandRtl(const LoadHalfwordInstruction &i);
      void genOperandRtl(const M480UnlinkInstruction &i);

      void genAsmRtlForInstruction(const Alu2OpBranchInstruction &i);
      void genAsmRtlForInstruction(const M480AddneInstruction &i);
      void genAsmRtlForInstruction(const M480AddneiInstruction &i);
      void genAsmRtlForInstruction(const Alu2OpFindInstruction &i);
      void genAsmRtlForInstruction(const Alu3OpAbcInstruction &i);
      void genAsmRtlForInstruction(const Alu3OpAbcModInstruction &i);
      void genAsmRtlForInstruction(const Alu3OpSxInstruction &i);
      void genAsmRtlForInstruction(const M480JbrsInstruction &i);
      void genAsmRtlForInstruction(const M480JbrslInstruction &i);
      void genAsmRtlForInstruction(const M480BrspreInstruction &i);
      void genAsmRtlForInstruction(const M480ByteswInstruction &i);
      void genAsmRtlForInstruction(const M480ParInstruction &i);
      void genAsmRtlForInstruction(const M480NopInstruction &i);
      void genAsmRtlForInstruction(const M480JrintInstruction &i);
      void genAsmRtlForInstruction(const M480JrnmiInstruction &i);
      void genAsmRtlForInstruction(const M480MvInstruction &i);
      void genAsmRtlForInstruction(const DmaOpInstruction &i);
      void genAsmRtlForInstruction(const BitOpInstruction &i);
      void genAsmRtlForInstruction(const BitOpImmInstruction &i);
      void genAsmRtlForInstruction(const CompareOpBranchInstruction &i);
      void genAsmRtlForInstruction(const CompareOpSignInstruction &i);
      void genAsmRtlForInstruction(const MultiRegLoadInstruction &i);
      void genAsmRtlForInstruction(const MultiRegStoreInstruction &i);
      void genAsmRtlForInstruction(const MultiRegLinkInstruction &i);
      void genAsmRtlForInstruction(const M480UnlinkInstruction &i);
      void genAsmRtlForInstruction(const M480PutcInstruction &i);
      void genAsmRtlForInstruction(const M480PutmInstruction &i);
      void genAsmRtlForInstruction(const M480PutpInstruction &i);
      void genAsmRtlForInstruction(const M480PutdInstruction &i);
      void genAsmRtlForInstruction(const M480GetInstruction &i);
      void genAsmRtlForInstruction(const M480MvrhInstruction &i);
      void genAsmRtlForInstruction(const M480MvhrInstruction &i);
      void genAsmRtlForInstruction(const CmovOpInstruction &i);
      void genAsmRtlForInstruction(const LoadImmediateInstruction &i);
      void genAsmRtlForInstruction(const LoadHalfwordInstruction &i);

      void genRtlForGlobalInsn(const LlirInstruction&);

      void storeReturnReg(shared_ptr<const Register>, unsigned int, const char*);

      void logSeqOperandException(unsigned int line,
			      const string& excFile);

      void insnRaiseException(const char *error, 
			      unsigned int excLine,
			      const string& excFile);

      void insnRaiseWarning(const char *warning, 
			    unsigned int warningLine,
			    const string& warningFile);

      bool isSigned(const Alu3OpSxInstruction &i);

      // Any changes to RTL_INSN will reflect the same enum in alo-parse.c
      enum RTL_INSN { LINK, LINKS, LINKSP, LINKSPL, LINKCC, LINKCCL, LINKSR, LINKSD, LINKSIO,
		      LMM, LMMS, LMMSL, LSP, LMMSP, LMMSPL, LMMSR, LMMSD, LMMCC, LMMCCL, LMMSIO,
		      SMM, SMMS, SMMSL, SSP, SMMSP, SMMSPL, SMMSR, SMMSD, SMMCC, SMMCCL, SMMSIO };

      enum ESS_Mode { ESS_CC_MODE, 
		      ESS_CCUNS_MODE,
		      ESS_CC_CY_MODE,
		      ESS_NOOV_MODE,
		      ESS_GENERIC };

      enum EXPR_Type { LO16_EXPR,
		       HI16_EXPR,
		       LO17_EXPR,
                       GENERIC_EXPR };

      void updateLinkInfo(unsigned int excLine,
			  const char* excFile,
			  OctaveMemory::MemType_t,
			  LinkFlag::Link_Flag_t lnk,
			  shared_ptr<const MultiRegister> mRegs);

      void genInsn(unsigned int line,
		   const char* file,
		   RTL_INSN,
		   shared_ptr<const OctaveMemory>,
		   LinkFlag::Link_Flag_t,
		   unsigned int);

      void genLinkInsn(unsigned int line,
		       const char* file,
		       RTL_INSN,
		       shared_ptr<const OctaveMemory>,
		       LinkFlag::Link_Flag_t,
		       unsigned int);

      void checkAbcFlag(OctaveAlo &alo,
			shared_ptr<const LlirOperand> opnd, 
			unsigned int excLine,
			const string &excFile) const;

      void checkCFlag(OctaveAlo &alo,
		      shared_ptr<const LlirOperand> opnd, 
		      unsigned int excLine,
		      const string &excFile) const;

      bool checkBFFlag(shared_ptr<const LlirOperand> opnd) const;


    private:
      
      ESS_Mode m_lastEssState;
      string m_essRegName;
    };


  class FindBranchLabelVisitor :
    public Visitor,
    public LlirVisitor
    {
    public:
	FindBranchLabelVisitor()  : 
	  Visitor(), 
	  LlirVisitor(),
	  m_branchLabel("")
	{}
	~FindBranchLabelVisitor()
	  {}

      virtual void visit(const LlirFile& v);
      virtual void visit(const LlirSequence &);
      virtual void visit(const NullNode& v);
      virtual void visit(const NewLineNode& v);
      virtual void visit(const LlirLineControlDirective& v);
      virtual void visit(const SignedImmediate& v);
      virtual void visit(const UnsignedImmediate& v);
      virtual void visit(const OpndLabel& v);
      virtual void visit(const OpndNull& v);

      virtual void visit(const PlusOp& v);
      virtual void visit(const MinusOp& v);
      virtual void visit(const MultiplyOp& v);
      virtual void visit(const DivOp& v);
      virtual void visit(const ModulusOp& v);
      virtual void visit(const LeftShiftOp& v);
      virtual void visit(const RightShiftOp& v);
      virtual void visit(const BitWiseAndOp& v);
      virtual void visit(const BitWiseOrOp& v);
      virtual void visit(const BitWiseXorOp& v);

      virtual void visit(const ParenthesesOp& v);
      virtual void visit(const UnaryMinusOp& v);

      virtual void visit(const NullRegister& v);
      virtual void visit(const HardRegister& v);
      virtual void visit(const PseudoRegister& v);
      virtual void visit(const MultiHardRegister& v);
      virtual void visit(const MultiPseudoRegister& v);
     
      const string &getBranchTarget() const;

    private:
      string m_branchLabel;
    };

  void M480GenerateAsmRtlInstruction(const Alu3OpAbcModInstruction &i, M480GenRtlVisitor &v);
}



#endif











