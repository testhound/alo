#ifndef _LLIR_OCTAVE_FACTORY_H
#define _LLIR_OCTAVE_FACTORY_H

#include <LlirNode.h>
#include <LlirOperand.h>

#include "OctaveInstructions.h"
#include "OctaveOperand.h"
#include "OctaveNode.h"
#include "OctaveSymbol.h"


namespace Llir
{

  class OctaveInstruction;

  class OctaveFactory
    {
    public:
      enum Mod
      { MOD2 = 0, MOD4, MOD8, MOD16, MOD32, MOD64, MOD128, MOD256, MOD512,
	MOD1K, MOD2K, MOD4K, MOD8K, MOD16K,MOD32K, MOD64K, MOD128K, MOD256K, MOD512K,
	MOD1M, MOD2M, MOD4M, MOD8M, MOD16M, MOD32M, MOD64M, MOD128M, MOD256M, MOD512M,
	MOD1G, MOD2G, 
	LAST_MOD
      };

      enum Ess
      { ESS0 = 0, ESS1, ESS2, ESS3, ESS4, ESS5, ESS6, ESS7, 
	ESS8, ESS9, ESS10, ESS11, ESS12, ESS13, ESS14, ESS15, 
	ESS16, ESS17, ESS18, ESS19, ESS20, ESS21, ESS22, ESS23, 
	ESS24, ESS25, ESS26, ESS27, ESS28, ESS29, ESS30, ESS31,
	LAST_ESS
      };

      enum Mvh
      {
	C0 = 0, C1, C2, C3, C4, C5, C6, C7, 
	C8, C9, C10, C11, C12, C13, C14, C15,
	LAST_MVH
      };

      enum Brsl
      {
	UNLNK = 0, 
	PRE, 
	DLNK, 
	FLUSH,
	LAST_BRSL
      };

      enum Cbranch
      {
	C = 0,
	BF,
	LAST_CBRANCH
      };

      enum Abc
      {
	BZ = 0, BNC, BNO, BGEZ, BLZ, BNZ, BLEZ, LAST_ABC
      };

      enum AbcCompare
      {
	BALB = 0, BAEB, BAGB, BANEB, BAGEB, BALEB, LAST_ABC_COMPARE
      };

      enum Tss
      {
	GC1A = 0, GC1O, GC1B, GSTICK, NUL, GC2A, GC2B, GC2O, GPA, GPU, GPB, GTA, GTO, GTB,
	FP, NG2, GZ, NB, NC, GW, GR, A, R, GU, T, RB, FB, NT, S, RSCH, I, FR, CLOSE, NE,
	OAM, RP, LOG, FPB, CSB, DELETE, LAST_TSS
      };

      enum Lnk
      { 
	LNK1 = 0, LNK2, LNK3,
	LAST_LNK
      };

      OctaveFactory();
      virtual ~OctaveFactory();

      virtual shared_ptr<const NullRegister> 
	createNullReg();

      virtual HardRegisterPtr 
	createHardReg(unsigned int regno);

      virtual PseudoRegisterPtr 
	createPseudoReg(unsigned int regno, const char *name);

      virtual MultiHardRegisterPtr 
	createMultiHardReg(unsigned int numRegs, 
			   unsigned int firstRegNo);

      virtual MultiPseudoRegisterPtr 
	createMultiPseudoReg(unsigned int numRegs, 
			     unsigned int firstRegNo,
			     const char *name);

      virtual shared_ptr<AbstractSymReg> 
	createSymReg(const char *name, OctaveSymbol::ScopeQualifier,
		     shared_ptr<const SingleRegister>,
		     AbstractSymReg::SymRegConstraint,
		     shared_ptr<const Register>);
    
      virtual shared_ptr<AbstractSymReg> 
	createMultiSymReg(const char *name, OctaveSymbol::ScopeQualifier,
			  shared_ptr<const MultiRegister>,
			  AbstractSymReg::SymRegConstraint,
			  shared_ptr<const Register>);

      virtual shared_ptr<LabelSymbol> 
	createLabelSymbol(const char* name, 
			  OctaveSymbol::ScopeQualifier scope);

      virtual shared_ptr<BlockSymbol> 
	createBlockSymbol(const char* name);

      virtual MapToHardRegPtr 
	createMapToHardReg(const char* mapName, 
			   OctaveSymbol::ScopeQualifier s,  
			   shared_ptr<const Struct> tp, 
			   shared_ptr<const HardRegister> hreg);

      virtual MapToPseudoRegPtr 
	createMapToPseudoReg(const char* mapName, 
			     OctaveSymbol::ScopeQualifier s,  
			     shared_ptr<const Struct> tp, 
			     shared_ptr<const PseudoRegister> sreg);

      virtual MapToMultiHardRegPtr 
	createMapToMultiHardReg(const char* mapName, 
				OctaveSymbol::ScopeQualifier s,  
				shared_ptr<const Struct> tp, 
				shared_ptr<const MultiHardRegister> mhreg);

      virtual MapToMultiPseudoRegPtr 
	createMapToMultiPseudoReg(const char* mapName, 
				  OctaveSymbol::ScopeQualifier s,  
				  shared_ptr<const Struct> tp, 
				  shared_ptr<const MultiPseudoRegister> msreg);
    

      virtual UnsignedImmediatePtr 
	createUnsignedImmediate(unsigned long value, 
				unsigned int numBits = 32);
    
      virtual UnsignedImmediatePtr 
	createUnsignedImmediate(unsigned long value, 
				unsigned long min,
				unsigned long max, 
				unsigned int numBits = 32);

      virtual SignedImmediatePtr 
	createSignedImmediate(long value, 
			      unsigned int numBits = 32);

      virtual SignedImmediatePtr 
	createSignedImmediate(long value, 
			      long min,
			      long max, 
			      unsigned int numBits = 32);

      virtual shared_ptr<Base2PlusOffset> 
	createBase2PlusOffsetMemory(shared_ptr<const LlirOperand> offset);

      virtual shared_ptr<Base3PlusOffset> 
	createBase3PlusOffsetMemory(shared_ptr<const LlirOperand> offset);

      virtual shared_ptr<RegPlusOffsetIndirect> 
	createRegPlusOffsetMemory(shared_ptr<const Register>, 
				  shared_ptr<const LlirOperand> offset);

      virtual shared_ptr<ImpliedBase2Offset> 
	createImpliedBase2OffsetMemory(shared_ptr<const LlirOperand> offset);

      virtual shared_ptr<OpndLabel> 
	createLabel(const char *name);

      virtual shared_ptr<PlusOp>  
	createPlusExpr(shared_ptr<const LlirOperand>, 
		       shared_ptr<const LlirOperand>); 

      virtual shared_ptr<MinusOp> 
	createMinusExpr(shared_ptr<const LlirOperand>, 
			shared_ptr<const LlirOperand>); 

      virtual shared_ptr<MultiplyOp> 
	createMultiplyExpr(shared_ptr<const LlirOperand>, 
			   shared_ptr<const LlirOperand>); 

      virtual shared_ptr<DivOp> 
	createDivExpr(shared_ptr<const LlirOperand>, 
		      shared_ptr<const LlirOperand>); 

      virtual shared_ptr<ModulusOp> 
	createModulusExpr(shared_ptr<const LlirOperand>, 
			  shared_ptr<const LlirOperand>); 

      virtual shared_ptr<LeftShiftOp> 
	createLeftShiftExpr(shared_ptr<const LlirOperand>, 
			    shared_ptr<const LlirOperand>); 

      virtual shared_ptr<RightShiftOp> 
	createRightShiftExpr(shared_ptr<const LlirOperand>, 
			     shared_ptr<const LlirOperand>); 

      virtual shared_ptr<BitWiseAndOp> 
	createBitWiseAndExpr(shared_ptr<const LlirOperand>, 
			     shared_ptr<const LlirOperand>); 

      virtual shared_ptr<BitWiseOrOp> 
	createBitWiseOrExpr(shared_ptr<const LlirOperand>, 
			    shared_ptr<const LlirOperand>); 

      virtual shared_ptr<BitWiseXorOp> 
	createBitWiseXorExpr(shared_ptr<const LlirOperand>, 
			     shared_ptr<const LlirOperand>); 

      virtual shared_ptr<ParenthesesOp> 
	createParenthesesExpr(shared_ptr<const LlirOperand>);

      virtual shared_ptr<UnaryMinusOp> 
	createUnaryMinusExpr(shared_ptr<const LlirOperand>);

      virtual shared_ptr<Lo17Op> 
	createLo17Expr(shared_ptr<const LlirOperand>);

      virtual shared_ptr<Hi16Op> 
	createHi16Expr(shared_ptr<const LlirOperand>);

      virtual shared_ptr<Lo16Op> 
	createLo16Expr(shared_ptr<const LlirOperand>);

      virtual shared_ptr<WordOp> 
	createWordExpr(shared_ptr<const LlirOperand>);

      virtual shared_ptr<ModFlag> 
	createModFlag(OctaveFactory::Mod);

      virtual shared_ptr<EssFlag> 
	createEssFlag(OctaveFactory::Ess, bool negate = false);

      virtual shared_ptr<MvhFlag> 
	createMvhFlag(OctaveFactory::Mvh);

      virtual shared_ptr<BrslFlag> 
	createBrslFlag(OctaveFactory::Brsl);

      virtual shared_ptr<BrslFlags> 
	createBrslFlags(shared_ptr<BrslFlag> f1);

      virtual shared_ptr<BrslFlags> 
	createBrslFlags(shared_ptr<BrslFlag> f1, 
			shared_ptr<BrslFlag> f2);

      virtual shared_ptr<BrslFlags> 
	createBrslFlags(shared_ptr<BrslFlag> f1, 
			shared_ptr<BrslFlag> f2, 
			shared_ptr<BrslFlag> f3);
    
      virtual shared_ptr<BrslFlags> 
	createBrslFlags(shared_ptr<BrslFlag> f1, 
			shared_ptr<BrslFlag> f2, 
			shared_ptr<BrslFlag> f3, 
			shared_ptr<BrslFlag> f4);

      virtual shared_ptr<CbranchFlag> 
	createCbranchFlag(OctaveFactory::Cbranch);

      virtual shared_ptr<CbranchFlags> 
	createCbranchFlags(shared_ptr<CbranchFlag>);

      virtual shared_ptr<CbranchFlags> 
	createCbranchFlags(shared_ptr<CbranchFlag>, 
			   shared_ptr<CbranchFlag>);

      virtual shared_ptr<TrafficScheduleFlags> 
	createTrafficScheduleFlags();

      virtual shared_ptr<FindFlag> 
	createFindFlag();

      virtual shared_ptr<DIFlag> 
	createDIFlag();

      virtual shared_ptr<SignFlag> 
	createSignFlag();

      virtual shared_ptr<CumeFlag> 
	createCumeFlag();

      virtual shared_ptr<CDFlag> 
	createCDFlag();

      virtual shared_ptr<DepbFlag> 
	createDepbFlag();

      virtual shared_ptr<SXFlag> 
	createSXFlag();

      virtual shared_ptr<AbcGenericFlag> 
	createAbcFlag(OctaveFactory::Abc);

      virtual shared_ptr<AbcCompareFlag> 
	createAbcCompareFlag(OctaveFactory::AbcCompare);

      virtual shared_ptr<TSSFlag> 
	createTssFlag(OctaveFactory::Tss);

      virtual shared_ptr<LinkFlag> 
	createLnkFlag(OctaveFactory::Lnk);

      shared_ptr<OpndNull> 
	createNullOperand();

      shared_ptr<NullSymbol> 
	createNullSymbol();

      shared_ptr<NullType> 
	createNullType();

      shared_ptr<NullNode> 
	createNullNode(unsigned int lineNum,
		       unsigned int srcLineNum,
		       const char* srcFileName);

      shared_ptr<NewLineNode> 
	createNewLineNode(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName,
			  const char* newLineStr);

      shared_ptr<SregisterDirective> 
	createSregisterDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName,
				 const char *name,
				 shared_ptr<const Register> reg,
				 AbstractSymReg::SymRegConstraint symRegConstraint,
				 shared_ptr<const Register> constraintRegRange);

      shared_ptr<LlirLineControlDirective> 
	createLineCtrlDirective(unsigned int lineNum,
				unsigned int lineCntrlNum, 
				const char *asmFileName,
				LlirLineControlDirective::LineCntrlFlagType);

      shared_ptr<LlirOctaveBlock> 
	createBlock(unsigned int lineNum,
		    unsigned int srcLineNum,
		    const char* srcFileName);

      shared_ptr<LlirOctaveBlock> 
	createBlock(const char *blockName, 
		    unsigned int lineNum,
		    unsigned int srcLineNum,
		    const char* srcFileName);

      shared_ptr<LlirOctaveBlock> 
	createMacroBlock(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName);

      shared_ptr<LlirOctaveBlock> 
	createGlobalBlock();

      shared_ptr<Struct> 
	createStruct(const char *name);

      shared_ptr<Align> 
	createAlignDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     unsigned int alignSize);

      shared_ptr<Ref> 
	createRefDirective(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   const char *label);

      shared_ptr<LocalLabel> 
	createLocalLabelDirective(unsigned int lineNum,
				  unsigned int srcLineNum,
				  const char* srcFileName, 
				  const char *label,
				  const char *label);

      shared_ptr<GlobalLabel> 
	createGlobalLabelDirective(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName, 
				   const char *label,
				   const char *label);

      shared_ptr<FileScopeLabel> 
	createFileScopeLabelDirective(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      const char *label,
				      const char *label);

      shared_ptr<List> 
	createListDirective(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName);

      shared_ptr<EndBlock> 
	createEndBlockDirective(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName);

      shared_ptr<EndBlock> 
	createEndBlockDirective(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				const char *name);

      shared_ptr<Ascii> 
	createAsciiDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     const char *string);

      shared_ptr<EndMacro> 
	createEndMacroDirective(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName);

      shared_ptr<NoList> 
	createNoListDirective(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName);

      shared_ptr<Datum> 
	createDatum(shared_ptr<const LlirExpr> d, 
		    unsigned int repeatCount = 1);

      shared_ptr<AllocMemoryDirective> 
	createByteDirective(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName);

      shared_ptr<AllocMemoryDirective> 
	createWordDirective(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName);

      shared_ptr<AllocMemoryDirective> 
	createHalfWordDirective(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName);

      shared_ptr<OrgDirective> 
	createOrgDirective(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName,
			   unsigned int numByte);

      shared_ptr<OrgDirective> 
	createOrgDirective(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   unsigned int numByte, 
			   unsigned int fillValue);
    
      shared_ptr<Section> 
	createDataSection(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName);

      shared_ptr<Section> 
	createTextSection(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName);

      shared_ptr<Section> 
	createCommSection(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  const char *name, 
			  unsigned int size);

      shared_ptr<Section> 
	createLcommSection(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   const char *name, 
			   unsigned int size);

      shared_ptr<Section> 
	createNamedSection(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   const char *name);

      shared_ptr<MapDirective> 
	createMapDirective(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   const char *mapPath, 
			   const char *mapName, 
			   shared_ptr<MapSymbol> symbol);

      shared_ptr<ScopedMapDirective> 
	createScopedMapDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 const char *mapPath, 
				 const char *mapName, 
				 shared_ptr<MapSymbol> symbol);

      shared_ptr<UnmapDirective> 
	createUnmapDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     const char *mapName);

      shared_ptr<StructBeginDirective> 
	createStructBeginDirective(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName, 
				   const char *structName);

      shared_ptr<StructEndDirective> 
	createStructEndDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName);

      shared_ptr<ElementDirective> 
	createElementDirective(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<Element> elemDecl);

      shared_ptr<MeetsDirective> 
	createMeetsDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     const char* testedPath, 
			     const char* referencePath);

      shared_ptr<AssertDirective> 
	createAssertDirective(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> exptr, 
			      const char* assertMsg);

      shared_ptr<WarningDirective> 
	createWarningDirective(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       const char* warningMsg);

      shared_ptr<ErrorDirective> 
	createErrorDirective(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     const char* errorMsg);

      shared_ptr<LabelList> 
	createLabelList();

      shared_ptr<RegList> 
	createRegList();

      shared_ptr<GlobalRegisterList> 
	createGlobalRegisterList(shared_ptr<RegList>);

      shared_ptr<ArgList> 
	createArgList(shared_ptr<RegList>);

      shared_ptr<ResultList> 
	createResultList(shared_ptr<RegList>);

      shared_ptr<ScratchList> 
	createScratchList(shared_ptr<RegList>);

      shared_ptr<RegLnksListToSPRAM> 
	createRegLnksListToSPRAM(shared_ptr<RegList>,
				 shared_ptr<RegList>,
				 shared_ptr<RegList>);

      shared_ptr<RegLnksListToLockedSPRAM> 
	createRegLnksListToLockedSPRAM(shared_ptr<RegList>,
				       shared_ptr<RegList>,
				       shared_ptr<RegList>);

      shared_ptr<RegLnksListToSRAM> 
	createRegLnksListToSRAM(shared_ptr<RegList>,
				shared_ptr<RegList>,
				shared_ptr<RegList>);

      shared_ptr<RegLnksListToSDRAM> 
	createRegLnksListToSDRAM(shared_ptr<RegList>,
				 shared_ptr<RegList>,
				 shared_ptr<RegList>);

      shared_ptr<RegLnksListToCCRAM> 
	createRegLnksListToCCRAM(shared_ptr<RegList>,
				 shared_ptr<RegList>,
				 shared_ptr<RegList>);

      shared_ptr<RegLnksListToLockedCCRAM> 
	createRegLnksListToLockedCCRAM(shared_ptr<RegList>,
				       shared_ptr<RegList>,
				       shared_ptr<RegList>);

      shared_ptr<RegLnksListToSIO> 
	createRegLnksListToSIO(shared_ptr<RegList>,
			       shared_ptr<RegList>,
			       shared_ptr<RegList>);





      shared_ptr<GlobalDirective> 
	createGlobalDirective(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName,
			      shared_ptr<const GlobalRegisterList> globalReg_List,
			      shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
			      shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
			      shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
			      shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
			      shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
			      shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
			      shared_ptr<const RegLnksListToSIO> lnkToSIO_List);
    
      shared_ptr<MultipleEntryEvh> 
	createMultipleEntryEvh(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName,
			       shared_ptr<const LabelList> labelList,
			       shared_ptr<const ArgList> argList,
			       shared_ptr<const ResultList> resultList,
			       shared_ptr<const ScratchList> scratchList,
			       shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
			       shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
			       shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
			       shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
			       shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
			       shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
			       shared_ptr<const RegLnksListToSIO> lnkToSIO_List);
      
      shared_ptr<EndEvhDirective> 
	createEndEvhDirective(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName,
			      const char* label);

      shared_ptr<MultipleEntryFunction> 
	createMultipleEntryFunction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    shared_ptr<const LabelList> labelList,
				    shared_ptr<const ArgList> argList,
				    shared_ptr<const ResultList> resultList,
				    shared_ptr<const ScratchList> scratchList,
				    shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
				    shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
				    shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
				    shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
				    shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
				    shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
				    shared_ptr<const RegLnksListToSIO> lnkToSIO_List);

      shared_ptr<EndEntryDirective> 
	createEndEntryDirective(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName,
				const char* label);

      shared_ptr<PrototypeDirective> 
	createPrototypeDirective(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName,
				 shared_ptr<const LabelList> labelList,
				 shared_ptr<const ArgList> argList,
				 shared_ptr<const ResultList> resultList,
				 shared_ptr<const ScratchList> scratchList,
				 shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
				 shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
				 shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
				 shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
				 shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
				 shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
				 shared_ptr<const RegLnksListToSIO> lnkToSIO_List);
      
	
      shared_ptr<IndirectCallTargetList> 
	createIndirectCallTargetList(shared_ptr<const LabelList>);
    
    	
      shared_ptr<JtableBegin> 
	createJtableBegin(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName,
			  shared_ptr<LabelList>);
    
    	
      shared_ptr<JtableEnd> 
	createJtableEnd(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName);
    
       	
      shared_ptr<JtableRelativeBegin> 
	createJtableRelativeBegin(unsigned int lineNum,
				  unsigned int srcLineNum,
				  const char* srcFileName,
				  shared_ptr<LabelList>);
      
    	
      shared_ptr<JtableRelativeEnd> 
	createJtableRelativeEnd(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName);
      
      shared_ptr<OctaveInstruction> 
	createNullInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName);

      virtual shared_ptr<OctaveInstruction> 
	createAddwhInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;
         
      virtual shared_ptr<OctaveInstruction> 
	createAddwlInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createAddwwInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;
         
      virtual shared_ptr<OctaveInstruction> 
	createAddlInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register>, 
			      shared_ptr<const Register>, 
			      shared_ptr<const LlirOperand>) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createAddwhiInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddwliInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>) = 0;
         

      virtual shared_ptr<OctaveInstruction> 
	createAddwwiInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>) = 0;



      virtual shared_ptr<OctaveInstruction> 
	createAddliInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const UnsignedImmediate>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createSubwhInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createSubwlInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;



      virtual shared_ptr<OctaveInstruction> 
	createSubwwInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSublInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register>, 
			      shared_ptr<const Register>, 
			      shared_ptr<const LlirOperand>) = 0;
         
 

      virtual shared_ptr<OctaveInstruction> 
	createSubwhiInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>) = 0;


 
      virtual shared_ptr<OctaveInstruction> 
	createSubwliInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>) = 0;



      virtual shared_ptr<OctaveInstruction> 
	createSubwwiInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>) = 0;

 

      virtual shared_ptr<OctaveInstruction> 
	createSubliInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const UnsignedImmediate>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>) = 0;



      virtual shared_ptr<OctaveInstruction> 
	createFfsInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> findFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createFlsInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> findFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createParInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAdd4xInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const Register> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag,
			       shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddcInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const UnsignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddciInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag,
			       shared_ptr<const LlirOperand> modFlag) = 0;
    
      virtual shared_ptr<OctaveInstruction> 
	createSubInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSubbInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> modFlag) = 0;
    
      virtual shared_ptr<OctaveInstruction> 
	createSubiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const UnsignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSubbiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag,
			       shared_ptr<const LlirOperand> modFlag) = 0;
    
      virtual shared_ptr<OctaveInstruction> 
	createAndInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAndiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createOrInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    shared_ptr<const Register> src1,
			    shared_ptr<const Register> src2, 
			    shared_ptr<const Register> dst, 
			    shared_ptr<const LlirOperand> abcFlag,
			    shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createOriInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const SignedImmediate> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createXorInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createXoriInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMaxInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMinInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> modFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createRandInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createRotlInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createRotrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createClrbInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSetbInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShftInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShftaInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const Register> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShlInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShrInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShraInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createRandiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createRotliInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createRotriInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSetbiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createClrbiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShliInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const UnsignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShriInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const UnsignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createShraiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMaxiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMiniInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMulInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> sxFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMulhInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> sxFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMuliInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> sxFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMulhiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const SignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> sxFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDivInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const Register> src2, 
			     shared_ptr<const Register> dst, 
			     shared_ptr<const LlirOperand> sxFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDiviInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> sxFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddneInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const Register> src2, 
			       shared_ptr<const Register> dst) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createAddneiInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> src1,
				shared_ptr<const UnsignedImmediate> src2, 
				shared_ptr<const Register> dst) = 0;

      virtual shared_ptr<OctaveInstruction>  
	createByteswInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> src1, 
				shared_ptr<const Register> dst, 
				shared_ptr<const UnsignedImmediate> b0, 
				shared_ptr<const UnsignedImmediate> b1, 
				shared_ptr<const UnsignedImmediate> b2, 
				shared_ptr<const UnsignedImmediate> b3,
				shared_ptr<const LlirOperand> abcFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createBcdrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<EssFlag>, 
			      shared_ptr<const LlirOperand> dst, 
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createBcrInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1, 
			     shared_ptr<EssFlag>, 
			     shared_ptr<const LlirOperand> dst, 
			     shared_ptr<const LlirOperand> flags) = 0;
     
  
      virtual shared_ptr<OctaveInstruction> 
	createBcdiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> src1, 
			      shared_ptr<EssFlag>, 
			      shared_ptr<const LlirOperand> dst, 
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createBciInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const LlirOperand> src1, 
			     shared_ptr<EssFlag>, 
			     shared_ptr<const LlirOperand> dst, 
			     shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createBnzrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const Register> src2, 
			      shared_ptr<const LlirOperand> cmpReg) = 0;
      
 
      virtual shared_ptr<OctaveInstruction> 
	createBzrInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1, 
			     shared_ptr<const Register> src2, 
			     shared_ptr<const LlirOperand> cmpReg) = 0;
     

      virtual shared_ptr<OctaveInstruction> 
	createBnziInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const LlirOperand> src2, 
			      shared_ptr<const LlirOperand> cmpReg) = 0;
 
      virtual shared_ptr<OctaveInstruction> 
	createBziInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1, 
			     shared_ptr<const LlirOperand> src2, 
			     shared_ptr<const LlirOperand> cmpReg) = 0;
      

      virtual shared_ptr<OctaveInstruction> 
	createTsetbInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const UnsignedImmediate> bitpos, 
			       shared_ptr<const LlirOperand> disp) = 0;

 
      virtual shared_ptr<OctaveInstruction> 
	createTclrbInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const UnsignedImmediate> bitpos, 
			       shared_ptr<const LlirOperand> disp) = 0;

 
      virtual shared_ptr<OctaveInstruction> 
	createRnmiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> diFlag) = 0;




      virtual shared_ptr<OctaveInstruction> 
	createRintInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> diFlag) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createBrsInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const LlirOperand> dst) = 0;

 
      virtual shared_ptr<OctaveInstruction> 
	createBrslInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> brslFlags) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createBrspreInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createCmpInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1, 
			     shared_ptr<const Register> src2, 
			     shared_ptr<const LlirOperand> abcFlag,
			     shared_ptr<const LlirOperand> branchTarget) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createCmpiInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const SignedImmediate> src2, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> branchTarget) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createCmprInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> signFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createCmpriInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const SignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<const LlirOperand> abcFlag,
			       shared_ptr<const LlirOperand> signFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createBiInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    shared_ptr<const LlirOperand> src1,
			    shared_ptr<const LlirOperand> dst, 
			    shared_ptr<const LlirOperand> cdFlag) = 0;
     

      virtual shared_ptr<OctaveInstruction> 
	createBrInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    shared_ptr<const Register> src1,
			    shared_ptr<const LlirOperand> dst) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJtablebrInstruction(unsigned int lineNum,
				  unsigned int srcLineNum,
				  const char* srcFileName, 
				  shared_ptr<const Register> src1,
				  shared_ptr<const LlirOperand> dst) = 0;

 
      virtual shared_ptr<OctaveInstruction> 
	createJtableRelativebrInstruction(unsigned int lineNum,
					  unsigned int srcLineNum,
					  const char* srcFileName, 
					  shared_ptr<const Register> src1,
					  shared_ptr<const LlirOperand> dst) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDepbInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src, 
			      shared_ptr<const UnsignedImmediate> srcBitNum,
			      shared_ptr<const Register> dst,
			      shared_ptr<const UnsignedImmediate> dstBitNum, 
			      shared_ptr<const UnsignedImmediate> numBits, 
			      shared_ptr<const LlirOperand> depbFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDepbiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const UnsignedImmediate> src, 
			       shared_ptr<const Register> dst,
			       shared_ptr<const UnsignedImmediate> dstBitNum, 
			       shared_ptr<const UnsignedImmediate> numBits, 
			       shared_ptr<const LlirOperand> depbFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createExtbInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src, 
			      shared_ptr<const UnsignedImmediate> srcBitNum,
			      shared_ptr<const Register> dst,
			      shared_ptr<const UnsignedImmediate> dstBitNum, 
			      shared_ptr<const UnsignedImmediate> numBits, 
			      shared_ptr<const LlirOperand> signFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createCmovInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const Register> src2, 
			      shared_ptr<const Register> dst, 
			      shared_ptr<EssFlag> essFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createCmoviInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> src2, 
			       shared_ptr<const Register> dst, 
			       shared_ptr<EssFlag> essFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDmapInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1,
			      shared_ptr<const UnsignedImmediate> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDmasrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDmau0Instruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createDmau1Instruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1,
			       shared_ptr<const UnsignedImmediate> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLihInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> dst,
			     shared_ptr<const LlirOperand> src) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLilInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> dst,
			     shared_ptr<const LlirOperand> src) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLwihInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> dst,
			      shared_ptr<const LlirOperand> src) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLwilInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> dst,
			      shared_ptr<const LlirOperand> src) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLaihInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> dst,
			      shared_ptr<const LlirOperand> src) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLailInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> dst,
			      shared_ptr<const LlirOperand> src) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createNopInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createHec5Instruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src,
			      shared_ptr<const Register> dst,
			      shared_ptr<const UnsignedImmediate> bytes,
			      shared_ptr<const LlirOperand> cumeFlag,
			      shared_ptr<const LlirOperand> branchTarget) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJHec5Instruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src,
			       shared_ptr<const Register> dst,
			       shared_ptr<const UnsignedImmediate> bytes,
			       shared_ptr<const LlirOperand> cumeFlag,
			       shared_ptr<const LlirOperand> branchTarget,
			       OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMvInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    shared_ptr<const Register> src,
			    shared_ptr<const Register> dst) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMvhrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src,
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> mvhFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createMvrhInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src,
			      shared_ptr<const Register> dst, 
			      shared_ptr<const LlirOperand> mvhFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createUnlinkInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				  const char* srcFileName, 
				shared_ptr<const Register> regs) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLinkInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> regs,
			      shared_ptr<OctaveMemory> mem, 
			      shared_ptr<const LinkFlag> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLinksInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LinkFlag> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLinkspInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LinkFlag> linkFlag) = 0;

     virtual shared_ptr<OctaveInstruction> 
	createLinksplInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const Register> regs,
				 shared_ptr<OctaveMemory> mem, 
				 shared_ptr<const LinkFlag> linkFlag) = 0;

     virtual shared_ptr<OctaveInstruction> 
	createLinksrInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem, 
				shared_ptr<const LinkFlag> linkFlag) = 0;

     virtual shared_ptr<OctaveInstruction> 
	createLinksdInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem, 
				shared_ptr<const LinkFlag> linkFlag) = 0;

     virtual shared_ptr<OctaveInstruction> 
	createLinksioInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const Register> regs,
				 shared_ptr<OctaveMemory> mem, 
				shared_ptr<const LinkFlag> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLinkccInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LinkFlag> linkFlag) = 0;

     virtual shared_ptr<OctaveInstruction> 
	createLinkcclInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const Register> regs,
				 shared_ptr<OctaveMemory> mem, 
				 shared_ptr<const LinkFlag> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> regs,
			     shared_ptr<OctaveMemory> mem, 
			     shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmspInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmsplInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem, 
				shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmsrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmsdInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmccInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmcclInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem, 
				shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmsiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem, 
			       shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createLmmsInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> regs,
			      shared_ptr<OctaveMemory> mem, 
			      shared_ptr<const LlirOperand> linkFlag) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createLspInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> regs,
			     shared_ptr<OctaveMemory> mem, 
			     shared_ptr<const LlirOperand> linkFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> regs,
			     shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmspInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmsplInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmsrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmsdInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmccInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmcclInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> regs,
				shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmsiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> regs,
			       shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSmmsInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> regs,
			      shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createSspInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> regs,
			     shared_ptr<OctaveMemory> mem) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPutInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> rsa,
			     shared_ptr<const Register> rsb, 
			     shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createGetInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> rsa,
			     shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPolInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> rsa,
			     shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPutcInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const UnsignedImmediate> parOffset,
			      shared_ptr<const UnsignedImmediate> posOffset,
			      shared_ptr<const LlirOperand> pipeDepth,
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPutcInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> rsa,
			      shared_ptr<const Register> rsb, 
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPutmInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> rsa,
			      shared_ptr<const Register> rsb, 
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPutpInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> rsa,
			      shared_ptr<const Register> rsb, 
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPutdInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> rsa,
			      shared_ptr<const Register> rsb, 
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createGetcInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const UnsignedImmediate> parOffset,
			      shared_ptr<const UnsignedImmediate> posOffset,
			      shared_ptr<const LlirOperand> flags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createPolcInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const UnsignedImmediate> parOffset,
			      shared_ptr<const UnsignedImmediate> posOffset,
			      shared_ptr<const LlirOperand> flags) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createJaddwhInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;
  
      virtual shared_ptr<OctaveInstruction> 
	createJaddwlInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJaddwwInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;
    
      virtual shared_ptr<OctaveInstruction> 
	createJaddlInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>,
			       OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJaddwhiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJaddwliInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJaddwwiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJaddliInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createJsubwhInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createJsubwlInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJsubwwInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;
    
      virtual shared_ptr<OctaveInstruction> 
	createJsublInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>,
			       OctaveInstruction::BranchProbability) = 0;
    
      virtual shared_ptr<OctaveInstruction> 
	createJsubwhiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability) = 0;

 
      virtual shared_ptr<OctaveInstruction> 
	createJsubwliInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability) = 0;

  
      virtual shared_ptr<OctaveInstruction> 
	createJsubwwiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJsubliInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability) = 0;
  
      virtual shared_ptr<OctaveInstruction> 
	createJbcdrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<EssFlag>, 
			       shared_ptr<const LlirOperand> dst, 
			       shared_ptr<const LlirOperand> flags,
			       shared_ptr<const LlirOperand> targetList,
			       OctaveInstruction::BranchProbability) = 0;

  
      virtual shared_ptr<OctaveInstruction> 
	createJbcrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<EssFlag>, 
			      shared_ptr<const LlirOperand> dst, 
			      shared_ptr<const LlirOperand> flags,
			      shared_ptr<const LlirOperand> targetList,
			      OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbcdiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> src1, 
			       shared_ptr<EssFlag>, 
			       shared_ptr<const LlirOperand> dst, 
			       shared_ptr<const LlirOperand> flags,
			       OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbciInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> src1, 
			      shared_ptr<EssFlag>, 
			      shared_ptr<const LlirOperand> dst, 
			      shared_ptr<const LlirOperand> flags,
			      OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbnzrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const Register> src2, 
			       shared_ptr<const LlirOperand> cmpReg,
			       shared_ptr<const LlirOperand> targetList,
			       OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbzrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const Register> src2, 
			      shared_ptr<const LlirOperand> cmpReg,
			      shared_ptr<const LlirOperand> targetList,
			      OctaveInstruction::BranchProbability) = 0;
 
      virtual shared_ptr<OctaveInstruction> 
	createJbnziInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const LlirOperand> src2, 
			       shared_ptr<const LlirOperand> cmpReg,
			       OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbziInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const LlirOperand> src2, 
			      shared_ptr<const LlirOperand> cmpReg,
			      OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJtsetbInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> src1, 
				shared_ptr<const UnsignedImmediate> bitpos, 
				shared_ptr<const LlirOperand> disp,
				OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJtclrbInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> src1, 
				shared_ptr<const UnsignedImmediate> bitpos, 
				shared_ptr<const LlirOperand> disp,
				OctaveInstruction::BranchProbability) = 0;



      virtual shared_ptr<OctaveInstruction> 
	createJrnmiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> diFlag) = 0;


      virtual shared_ptr<OctaveInstruction> 
	createJrintInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> diFlag) = 0;



      virtual shared_ptr<OctaveInstruction> 
	createJbrsInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> dst) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbrslInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> brslFlags) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbiInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const LlirOperand> src1,
			     shared_ptr<const LlirOperand> dst, 
			     shared_ptr<const LlirOperand> cdFlag) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJbrInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const LlirOperand> dst,
			     shared_ptr<const LlirOperand> targetList) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJcmpInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const Register> src2, 
			      shared_ptr<const LlirOperand> abcFlag,
			      shared_ptr<const LlirOperand> branchTarget,
			      OctaveInstruction::BranchProbability) = 0;

      virtual shared_ptr<OctaveInstruction> 
	createJcmpiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const SignedImmediate> src2, 
			       shared_ptr<const LlirOperand> abcFlag,
			       shared_ptr<const LlirOperand> branchTarget,
			       OctaveInstruction::BranchProbability) = 0;

      shared_ptr<const MultiRegister> convertSingleToMultiReg(shared_ptr<const Register>);
      shared_ptr<const MultiRegister> convertSingleToDmaMultiReg(shared_ptr<const Register>);

    protected:

      // number of hard regs in the target
      unsigned int getNumHardRegs() const;

    private:
      enum {LAST_OCTAVE_REG = 157};
  
      void initModFlags();
      void initAbcFlags();
      void initEssFlags();
      void initMvhFlags();
      void initBrslFlags();
      void initCbranchFlags();
      void initTssFlags();
      void initLinkFlags();

      shared_ptr<OpndNull> m_nullOperand;
      shared_ptr<const NullRegister> m_nullReg;
      shared_ptr<NullSymbol> m_nullSymbol;
      shared_ptr<NullType> m_nullType;
      unsigned int m_numPseudoRegs;

      std::vector<shared_ptr<HardRegister> > m_octaveHardRegs;
      std::vector<shared_ptr<ModFlag> > m_modFlags;
      std::vector<shared_ptr<EssFlag> > m_essFlags;
      std::vector<shared_ptr<EssFlag> > m_negatedEssFlags;
      std::vector<shared_ptr<MvhFlag> > m_mvhFlags;
      std::vector<shared_ptr<BrslFlag> > m_brslFlags;
      std::vector<shared_ptr<CbranchFlag> > m_cbranchFlags;
      shared_ptr<FindFlag> m_findFlag;
      shared_ptr<CumeFlag> m_cumeFlag;
      shared_ptr<DIFlag> m_diFlag;
      shared_ptr<SignFlag> m_signFlag;
      shared_ptr<CDFlag> m_cdFlag;
      shared_ptr<DepbFlag> m_depbFlag;
      shared_ptr<SXFlag> m_sxFlag;
      std::vector<shared_ptr<AbcGenericFlag> > m_abcFlags;
      std::vector<shared_ptr<AbcCompareFlag> > m_abcCompareFlags;
      std::vector<shared_ptr<TSSFlag> > m_tssFlags;
      std::vector<shared_ptr<LinkFlag> > m_linkFlags;

    };



} // namespace Llir

#endif
