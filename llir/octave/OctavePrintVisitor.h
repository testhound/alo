#ifndef _OCTAVE_PRINT_VISITOR_H_
#define _OCTAVE_PRINT_VISITOR_H_

#include "OctaveVisitor.h"
#include "OctaveOperand.h"

namespace Llir
{
  class AllocMemoryDirective;
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

  class OctavePrintVisitor : public Visitor, public LlirOctaveVisitor
    {
    public:
      OctavePrintVisitor(ostream& outputStream);
      ~OctavePrintVisitor();

      void visit(const LlirFile& v);
      void visit(const NullNode& v);
      void visit(const NewLineNode& v);
      void visit(const LlirLineControlDirective& v);
      void visit(const LlirSequence& v);
      void visit(const NullRegister &r);
      void visit(const HardRegister &r);
      void visit(const MultiHardRegister &r);
      void visit(const PseudoRegister &r);
      void visit(const MultiPseudoRegister &r);
      void visit(const UnsignedImmediate &i);
      void visit(const SignedImmediate &i);
      void visit(const OpndLabel &l);
      void visit(const OpndNull &l){}
      void visit(const TrafficScheduleFlags &f);

      void visit(const PlusOp &l);
      void visit(const MinusOp &l);
      void visit(const MultiplyOp &l);
      void visit(const DivOp &l);
      void visit(const ModulusOp &l);
      void visit(const LeftShiftOp &l);
      void visit(const RightShiftOp &l);

      void visit(const ParenthesesOp &l);
      void visit(const UnaryMinusOp &l);

      void visit(const BitWiseAndOp &l);
      void visit(const BitWiseOrOp &l);
      void visit(const BitWiseXorOp &l);

      void visit(const NullInstruction& v);
      void visit(const OctaveBlock &);
      void visit(const OctaveMacroBlock &);
      void visit(const OctaveImplicitBlock &);

      void visit(const Base2PlusOffset &o);
      void visit(const Base3PlusOffset &o);
      void visit(const RegPlusOffsetIndirect &o);
      void visit(const ImpliedBase2Offset &o);
      void visit(const Lo17Op &o);
      void visit(const Hi16Op &o);
      void visit(const Lo16Op &o);
      void visit(const WordOp &o);
      void visit(const Mod2Flag &o);
      void visit(const Mod4Flag &o);
      void visit(const Mod8Flag &o);
      void visit(const Mod16Flag &o);
      void visit(const Mod32Flag &o);
      void visit(const Mod64Flag &o);
      void visit(const Mod128Flag &o);
      void visit(const Mod256Flag &o);
      void visit(const Mod512Flag &o);
      void visit(const Mod1KFlag &o);
      void visit(const Mod2KFlag &o);
      void visit(const Mod4KFlag &o);
      void visit(const Mod8KFlag &o);
      void visit(const Mod16KFlag &o);
      void visit(const Mod32KFlag &o);
      void visit(const Mod64KFlag &o);
      void visit(const Mod128KFlag &o);
      void visit(const Mod256KFlag &o);
      void visit(const Mod512KFlag &o);
      void visit(const Mod1MFlag &o);
      void visit(const Mod2MFlag &o);
      void visit(const Mod4MFlag &o);
      void visit(const Mod8MFlag &o);
      void visit(const Mod16MFlag &o);
      void visit(const Mod32MFlag &o);
      void visit(const Mod64MFlag &o);
      void visit(const Mod128MFlag &o);
      void visit(const Mod256MFlag &o);
      void visit(const Mod512MFlag &o);
      void visit(const Mod1GFlag &o);
      void visit(const Mod2GFlag &o);
      void visit(const BZFlag &o);
      void visit(const BNCFlag &o);
      void visit(const BNOFlag &o);
      void visit(const BGEZFlag &o);
      void visit(const BLZFlag &o);
      void visit(const BNZFlag &o);
      void visit(const BLEZFlag &o);
      void visit(const BALBFlag &o);
      void visit(const BAEBFlag &o);
      void visit(const BAGBFlag &o);
      void visit(const BANEBFlag &o);
      void visit(const BAGEBFlag &o);
      void visit(const BALEBFlag &o);
      void visit(const C0Flag &o);
      void visit(const C1Flag &o);
      void visit(const C2Flag &o);
      void visit(const C3Flag &o);
      void visit(const C4Flag &o);
      void visit(const C5Flag &o);
      void visit(const C6Flag &o);
      void visit(const C7Flag &o);
      void visit(const C8Flag &o);
      void visit(const C9Flag &o);
      void visit(const C10Flag &o);
      void visit(const C11Flag &o);
      void visit(const C12Flag &o);
      void visit(const C13Flag &o);
      void visit(const C14Flag &o);
      void visit(const C15Flag &o);
      void visit(const Ess0Flag &o);
      void visit(const Ess1Flag &o);
      void visit(const Ess2Flag &o);
      void visit(const Ess3Flag &o);
      void visit(const Ess4Flag &o);
      void visit(const Ess5Flag &o);
      void visit(const Ess6Flag &o);
      void visit(const Ess7Flag &o);
      void visit(const Ess8Flag &o);
      void visit(const Ess9Flag &o);
      void visit(const Ess10Flag &o);
      void visit(const Ess11Flag &o);
      void visit(const Ess12Flag &o);
      void visit(const Ess13Flag &o);
      void visit(const Ess14Flag &o);
      void visit(const Ess15Flag &o);
      void visit(const Ess16Flag &o);
      void visit(const Ess17Flag &o);
      void visit(const Ess18Flag &o);
      void visit(const Ess19Flag &o);
      void visit(const Ess20Flag &o);
      void visit(const Ess21Flag &o);
      void visit(const Ess22Flag &o);
      void visit(const Ess23Flag &o);
      void visit(const Ess24Flag &o);
      void visit(const Ess25Flag &o);
      void visit(const Ess26Flag &o);
      void visit(const Ess27Flag &o);
      void visit(const Ess28Flag &o);
      void visit(const Ess29Flag &o);
      void visit(const Ess30Flag &o);
      void visit(const Ess31Flag &o);
      void visit(const SXFlag &o);
      void visit(const FindFlag &o);
      void visit(const CumeFlag &o);
      void visit(const SignFlag &o);
      void visit(const CDFlag &o);
      void visit(const DepbFlag &o);
      void visit(const DIFlag &o);
      void visit(const LNK1Flag &o);
      void visit(const LNK2Flag &o);
      void visit(const LNK3Flag &o);
      void visit(const GC1AFlag &o);
      void visit(const GC1OFlag &o);
      void visit(const GC1BFlag &o);
      void visit(const GC2AFlag &o);
      void visit(const GC2OFlag &o);
      void visit(const GC2BFlag &o);
      void visit(const GPAFlag &o);
      void visit(const GPUFlag &o);
      void visit(const GPBFlag &o);
      void visit(const GTAFlag &o);
      void visit(const GTBFlag &o);
      void visit(const GTOFlag &o);
      void visit(const FPFlag &o);
      void visit(const NG2Flag &o);
      void visit(const GZFlag &o);
      void visit(const OAMFlag &o);
      void visit(const RPFlag &o);
      void visit(const LOGFlag &o);
      void visit(const FPBFlag &o);
      void visit(const CSBFlag &o);
      void visit(const DELETEFlag &o);
      void visit(const NBFlag &o);
      void visit(const NCFlag &o);
      void visit(const GWFlag &o);
      void visit(const GRFlag &o);
      void visit(const AFlag &o);
      void visit(const RFlag &o);
      void visit(const GUFlag &o);
      void visit(const TFlag &o);
      void visit(const RBFlag &o);
      void visit(const FBFlag &o);
      void visit(const NTFlag &o);
      void visit(const SFlag &o);
      void visit(const IFlag &o);
      void visit(const FRFlag &o);
      void visit(const RSCHFlag &o);
      void visit(const CLOSEFlag &o);
      void visit(const NEFlag &o);
      void visit(const UNLNKFlag &o);
      void visit(const PREFlag &o);
      void visit(const DLNKFlag &o);
      void visit(const FLUSHFlag &o);
      void visit(const BFFlag &o);
      void visit(const CFlag &o);
      void visit(const BrslFlags &o);
      void visit(const CbranchFlags &o);
      void visit(const GSTICKFlag &o);
      void visit(const NULFlag &o);
      void visit(const PolFlags &o); 
      void visit(const PutFlags &o); 
      void visit(const GetFlags &o); 

      void visit(const Ascii &);
      void visit(const LocalLabel &);
      void visit(const GlobalLabel &);
      void visit(const FileScopeLabel &);
      void visit(const List &);
      void visit(const NoList &);
      void visit(const EndMacro &);
      void visit(const Align &);
      void visit(const Ref &);
      void visit(const UnNamedEndBlock &);
      void visit(const NamedEndBlock &);

      void visit(const Text &);
      void visit(const Data &);
      void visit(const Comm &);
      void visit(const Lcomm &);
      void visit(const NamedSection &);
      void visit(const Byte &);
      void visit(const Word &);
      void visit(const HalfWord &);
      void visit(const Org &);
      void visit(const OrgWithFillValue &);
      void visit(const StructEndDirective &);
      void visit(const StructBeginDirective &);
      void visit(const MapDirective &);
      void visit(const ScopedMapDirective &);
      void visit(const UnmapDirective &);
      void visit(const ElementDirective &);
      void visit(const Field &);
      void visit(const BitField &);


      void visit(const  MeetsDirective&);
      void visit(const  AssertDirective&);
      void visit(const  WarningDirective&);
      void visit(const  ErrorDirective&);
      void visit(const  SregisterDirective&);
      void visit(const InvalidOctaveInstruction &);


      void visit(const LabelList &) ;
      void visit(const GlobalRegisterList &) ;
      void visit(const ArgList &) ;
      void visit(const ResultList &) ;
      void visit(const ScratchList &) ;
      void visit(const RegLnksListToSPRAM &) ;
      void visit(const RegLnksListToLockedSPRAM &) ;
      void visit(const RegLnksListToSRAM &) ;
      void visit(const RegLnksListToSDRAM &) ;
      void visit(const RegLnksListToCCRAM &) ;
      void visit(const RegLnksListToLockedCCRAM &) ;
      void visit(const RegLnksListToSIO &) ;

      void visit(const  GlobalDirective &) ;
      void visit(const  MultipleEntryEvh &) ;
      void visit(const  EndEvhDirective &) ;
      void visit(const  MultipleEntryFunction &) ;
      void visit(const  EndEntryDirective &) ;
      void visit(const  PrototypeDirective &) ;
      void visit(const  IndirectCallTargetList &) ;
      void visit(const  JtableBegin &) ;
      void visit(const  JtableEnd &) ;
      void visit(const  JtableRelativeBegin &) ;
      void visit(const  JtableRelativeEnd &) ;


    protected:
      void endOfLine();
      ostream& getOutputStream() const;
      void printNops(unsigned int num);
      
      void printAlu2OpBranch(const Alu2OpBranchInstruction &i, const char *mnemonic);
      void printAlu2OpFind(const Alu2OpFindInstruction &i, const char *mnemonic);
      void printAlu3OpAbcMod(const Alu3OpAbcModInstruction &i, const char *mnemonic);
      void printAlu3OpAbc(const Alu3OpAbcInstruction &i, const char *mnemonic);
      void printAlu3OpSx(const Alu3OpSxInstruction &i, const char *mnemonic);
      void printAlu3Op(const Alu3OpInstruction &i, const char *mnemonic);
      void printCondBranch(const CondBranchInstruction &i, const char *mnemonic);
      void printCondBranchImmed(const CondBranchImmedInstruction &i, const char *mnemonic);
      void printZeroBranch(const ZeroBranchInstruction &i, const char *mnemonic);
      void printZeroBranchImmed(const ZeroBranchImmedInstruction &i, const char *mnemonic);
      void printTestBitBranch(const TestBitBranchInstruction &i, const char *mnemonic);
      void printReturn(const ReturnOpInstruction &i, const char *mnemonic);
      void printCompareBranch(const CompareOpBranchInstruction &i, const char *mnemonic);
      void printCompareSign(const CompareOpSignInstruction &i, const char *mnemonic);
      void printCmov(const CmovOpInstruction &i, const char *mnemonic);
      void printDma(const DmaOpInstruction &i, const char *mnemonic);
      void printLoadImmediate(const LoadImmediateInstruction &i, const char *mnemonic);
      void printLoadHalfword(const LoadHalfwordInstruction &i, const char *mnemonic);
      void printLink(const MultiRegLinkInstruction &i, const char *mnemonic);
      void printLoad(const MultiRegLoadInstruction &i, const char *mnemonic);
      void printStore(const MultiRegStoreInstruction &i, const char *mnemonic);

    private:
      void printDatumList(const AllocMemoryDirective &directive);
      void printTSSFlags(const TrafficScheduleFlags &tssflags);
      void printBlankLines(unsigned int numBlankLine);
      void printRegList(shared_ptr<const RegList> d);

      unsigned int m_macroDepth;
      bool m_inMacroBlock;
      ostream& m_outputStream;
      unsigned int m_lineNum;
    };
} // namespace Llir
    
#endif
