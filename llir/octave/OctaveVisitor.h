#ifndef _LLIR_OCTAVE_VISITOR_H
#define _LLIR_OCTAVE_VISITOR_H

#include <LlirVisitor.h>

namespace Llir
{
  
  // Forward Declarations
  
  class NullInstruction;

  class   OctaveBlock;
  class   OctaveMacroBlock;
  class   OctaveImplicitBlock;

  class   TrafficScheduleFlags;
  class   RegIndirect;
  class   Base2PlusOffset;
  class   Base3PlusOffset;
  class   RegPlusOffsetIndirect ;
  class   ImpliedBase2Offset;
  class   Lo17Op;
  class   Hi16Op;
  class   Lo16Op;
  class   WordOp;
  class   Mod2Flag;
  class   Mod4Flag;
  class   Mod8Flag;
  class   Mod16Flag;
  class   Mod32Flag;
  class   Mod64Flag;
  class   Mod128Flag;
  class   Mod256Flag;
  class   Mod512Flag;
  class   Mod1KFlag;
  class   Mod2KFlag;
  class   Mod4KFlag;
  class   Mod8KFlag;
  class   Mod16KFlag;
  class   Mod32KFlag;
  class   Mod64KFlag;
  class   Mod128KFlag;
  class   Mod256KFlag;
  class   Mod512KFlag;
  class   Mod1MFlag;
  class   Mod2MFlag;
  class   Mod4MFlag;
  class   Mod8MFlag;
  class   Mod16MFlag;
  class   Mod32MFlag;
  class   Mod64MFlag;
  class   Mod128MFlag;
  class   Mod256MFlag;
  class   Mod512MFlag;
  class   Mod1GFlag;
  class   Mod2GFlag;
  class   BZFlag;
  class   BNCFlag;
  class   BNOFlag;
  class   BGEZFlag;
  class   BLZFlag;
  class   BNZFlag;
  class   BLEZFlag;
  class   BALBFlag;
  class   BAEBFlag;
  class   BAGBFlag;
  class   BANEBFlag;
  class   BAGEBFlag;
  class   BALEBFlag;
  class   C0Flag;
  class   C1Flag;
  class   C2Flag;
  class   C3Flag;
  class   C4Flag;
  class   C5Flag;
  class   C6Flag;
  class   C7Flag;
  class   C8Flag;
  class   C9Flag;
  class   C10Flag;
  class   C11Flag;
  class   C12Flag;
  class   C13Flag;
  class   C14Flag;
  class   C15Flag;
  class   Ess0Flag;
  class   Ess1Flag;
  class   Ess2Flag;
  class   Ess3Flag;
  class   Ess4Flag;
  class   Ess5Flag;
  class   Ess6Flag;
  class   Ess7Flag;
  class   Ess8Flag;
  class   Ess9Flag;
  class   Ess10Flag;
  class   Ess11Flag;
  class   Ess12Flag;
  class   Ess13Flag;
  class   Ess14Flag;
  class   Ess15Flag;
  class   Ess16Flag;
  class   Ess17Flag;
  class   Ess18Flag;
  class   Ess19Flag;
  class   Ess20Flag;
  class   Ess21Flag;
  class   Ess22Flag;
  class   Ess23Flag;
  class   Ess24Flag;
  class   Ess25Flag;
  class   Ess26Flag;
  class   Ess27Flag;
  class   Ess28Flag;
  class   Ess29Flag;
  class   Ess30Flag;
  class   Ess31Flag;
  class   SXFlag;
  class   FindFlag;
  class   CumeFlag;
  class   SignFlag;
  class   CDFlag;
  class   DepbFlag;
  class   DIFlag;
  class   LNK1Flag;
  class   LNK2Flag;
  class   LNK3Flag;
  class   GC1AFlag;
  class   GC1OFlag;
  class   GC1BFlag;
  class   GC2AFlag;
  class   GC2OFlag;
  class   GC2BFlag;
  class   GPAFlag;
  class   GPUFlag;
  class   GPBFlag;
  class   GTAFlag;
  class   GTBFlag;
  class   GTOFlag;
  class   FPFlag;
  class   NG2Flag;
  class   GZFlag;
  class   OAMFlag;
  class   RPFlag;
  class   LOGFlag;
  class   FPBFlag;
  class   CSBFlag;
  class   DELETEFlag;
  class   NBFlag;
  class   NCFlag;
  class   GWFlag;
  class   GRFlag;
  class   AFlag;
  class   RFlag;
  class   GUFlag;
  class   TFlag;
  class   RBFlag;
  class   FBFlag;
  class   NTFlag;
  class   SFlag;
  class   IFlag;
  class   FRFlag;
  class   RSCHFlag;
  class   CLOSEFlag;
  class   NEFlag;
  class   TrafficScheduleFlags;
  class   UNLNKFlag;
  class   PREFlag;
  class   DLNKFlag;
  class   FLUSHFlag;
  class   BrslFlags;
  class   CbranchFlags;
  class   CFlag;
  class   BFFlag;
  
  class   GSTICKFlag;
  class   NULFlag;
  class   PutFlags;
  class   PolFlags;
  class   GetFlags;
  
  
  class Ascii;
  class LocalLabel;
  class GlobalLabel;
  class FileScopeLabel;
  class List;
  class NoList;
  class EndMacro;
  class Align;
  class Ref;
  class UnNamedEndBlock;
  class NamedEndBlock;
  class Text;
  class Data;
  class Comm;
  class Lcomm;
  class NamedSection;
  class Byte;
  class Word;
  class HalfWord;
  class Org;
  class OrgWithFillValue;
  class StructBeginDirective;
  class StructEndDirective;
  class MapDirective;
  class ScopedMapDirective;
  class UnmapDirective;
  class ElementDirective;
  class BitField;
  class Field;
  class MeetsDirective;
  class AssertDirective;
  class WarningDirective;
  class ErrorDirective;
  class SregisterDirective;
  class LabelList;

  class GlobalRegisterList;
  class ArgList;
  class ResultList;
  class ScratchList;
  class RegLnksListToSPRAM;
  class RegLnksListToLockedSPRAM;
  class RegLnksListToSRAM;
  class RegLnksListToSDRAM;
  class RegLnksListToCCRAM;
  class RegLnksListToLockedCCRAM;
  class RegLnksListToSIO;

  class GlobalDirective;
  class MultipleEntryEvh;
  class EndEvhDirective;
  class MultipleEntryFunction;
  class EndEntryDirective;
  class PrototypeDirective;
  class IndirectCallTargetList;
  class JtableBegin;
  class JtableEnd;
  class JtableRelativeBegin;
  class JtableRelativeEnd;

  class InvalidOctaveInstruction;

  class LlirOctaveVisitor : public LlirVisitor
  {
  public:
    
    virtual void visit(const NullInstruction &) = 0;
    virtual void visit(const OctaveBlock &) = 0;
    virtual void visit(const OctaveMacroBlock &) = 0;
    virtual void visit(const OctaveImplicitBlock &) = 0;
    
    virtual void visit(const Base2PlusOffset &) = 0;
    virtual void visit(const Base3PlusOffset &) = 0;
    virtual void visit(const RegPlusOffsetIndirect &) = 0;
    virtual void visit(const ImpliedBase2Offset &) = 0;
    virtual void visit(const Lo17Op &) = 0;
    virtual void visit(const Hi16Op &) = 0;
    virtual void visit(const Lo16Op &) = 0;
    virtual void visit(const WordOp &) = 0;
    virtual void visit(const Mod2Flag &) = 0;
    virtual void visit(const Mod4Flag &) = 0;
    virtual void visit(const Mod8Flag &) = 0;
    virtual void visit(const Mod16Flag &) = 0;
    virtual void visit(const Mod32Flag &) = 0;
    virtual void visit(const Mod64Flag &) = 0;
    virtual void visit(const Mod128Flag &) = 0;
    virtual void visit(const Mod256Flag &) = 0;
    virtual void visit(const Mod512Flag &) = 0;
    virtual void visit(const Mod1KFlag &) = 0;
    virtual void visit(const Mod2KFlag &) = 0;
    virtual void visit(const Mod4KFlag &) = 0;
    virtual void visit(const Mod8KFlag &) = 0;
    virtual void visit(const Mod16KFlag &) = 0;
    virtual void visit(const Mod32KFlag &) = 0;
    virtual void visit(const Mod64KFlag &) = 0;
    virtual void visit(const Mod128KFlag &) = 0;
    virtual void visit(const Mod256KFlag &) = 0;
    virtual void visit(const Mod512KFlag &) = 0;
    virtual void visit(const Mod1MFlag &) = 0;
    virtual void visit(const Mod2MFlag &) = 0;
    virtual void visit(const Mod4MFlag &) = 0;
    virtual void visit(const Mod8MFlag &) = 0;
    virtual void visit(const Mod16MFlag &) = 0;
    virtual void visit(const Mod32MFlag &) = 0;
    virtual void visit(const Mod64MFlag &) = 0;
    virtual void visit(const Mod128MFlag &) = 0;
    virtual void visit(const Mod256MFlag &) = 0;
    virtual void visit(const Mod512MFlag &) = 0;
    virtual void visit(const Mod1GFlag &) = 0;
    virtual void visit(const Mod2GFlag &) = 0;
    virtual void visit(const BZFlag &) = 0;
    virtual void visit(const BNCFlag &) = 0;
    virtual void visit(const BNOFlag &) = 0;
    virtual void visit(const BGEZFlag &) = 0;
    virtual void visit(const BLZFlag &) = 0;
    virtual void visit(const BNZFlag &) = 0;
    virtual void visit(const BLEZFlag &) = 0;
    virtual void visit(const BALBFlag &) = 0;
    virtual void visit(const BAEBFlag &) = 0;
    virtual void visit(const BAGBFlag &) = 0;
    virtual void visit(const BANEBFlag &) = 0;
    virtual void visit(const BAGEBFlag &) = 0;
    virtual void visit(const BALEBFlag &) = 0;
    virtual void visit(const C0Flag &) = 0;
    virtual void visit(const C1Flag &) = 0;
    virtual void visit(const C2Flag &) = 0;
    virtual void visit(const C3Flag &) = 0;
    virtual void visit(const C4Flag &) = 0;
    virtual void visit(const C5Flag &) = 0;
    virtual void visit(const C6Flag &) = 0;
    virtual void visit(const C7Flag &) = 0;
    virtual void visit(const C8Flag &) = 0;
    virtual void visit(const C9Flag &) = 0;
    virtual void visit(const C10Flag &) = 0;
    virtual void visit(const C11Flag &) = 0;
    virtual void visit(const C12Flag &) = 0;
    virtual void visit(const C13Flag &) = 0;
    virtual void visit(const C14Flag &) = 0;
    virtual void visit(const C15Flag &) = 0;
    virtual void visit(const Ess0Flag &) = 0;
    virtual void visit(const Ess1Flag &) = 0;
    virtual void visit(const Ess2Flag &) = 0;
    virtual void visit(const Ess3Flag &) = 0;
    virtual void visit(const Ess4Flag &) = 0;
    virtual void visit(const Ess5Flag &) = 0;
    virtual void visit(const Ess6Flag &) = 0;
    virtual void visit(const Ess7Flag &) = 0;
    virtual void visit(const Ess8Flag &) = 0;
    virtual void visit(const Ess9Flag &) = 0;
    virtual void visit(const Ess10Flag &) = 0;
    virtual void visit(const Ess11Flag &) = 0;
    virtual void visit(const Ess12Flag &) = 0;
    virtual void visit(const Ess13Flag &) = 0;
    virtual void visit(const Ess14Flag &) = 0;
    virtual void visit(const Ess15Flag &) = 0;
    virtual void visit(const Ess16Flag &) = 0;
    virtual void visit(const Ess17Flag &) = 0;
    virtual void visit(const Ess18Flag &) = 0;
    virtual void visit(const Ess19Flag &) = 0;
    virtual void visit(const Ess20Flag &) = 0;
    virtual void visit(const Ess21Flag &) = 0;
    virtual void visit(const Ess22Flag &) = 0;
    virtual void visit(const Ess23Flag &) = 0;
    virtual void visit(const Ess24Flag &) = 0;
    virtual void visit(const Ess25Flag &) = 0;
    virtual void visit(const Ess26Flag &) = 0;
    virtual void visit(const Ess27Flag &) = 0;
    virtual void visit(const Ess28Flag &) = 0;
    virtual void visit(const Ess29Flag &) = 0;
    virtual void visit(const Ess30Flag &) = 0;
    virtual void visit(const Ess31Flag &) = 0;
    virtual void visit(const SXFlag &) = 0;
    virtual void visit(const FindFlag &) = 0;
    virtual void visit(const CumeFlag &) = 0;
    virtual void visit(const SignFlag &) = 0;
    virtual void visit(const CDFlag &) = 0;
    virtual void visit(const DepbFlag &) = 0;
    virtual void visit(const DIFlag &) = 0;
    virtual void visit(const LNK1Flag &) = 0;
    virtual void visit(const LNK2Flag &) = 0;
    virtual void visit(const LNK3Flag &) = 0;
    virtual void visit(const GC1AFlag &) = 0;
    virtual void visit(const GC1OFlag &) = 0;
    virtual void visit(const GC1BFlag &) = 0;
    virtual void visit(const GC2AFlag &) = 0;
    virtual void visit(const GC2OFlag &) = 0;
    virtual void visit(const GC2BFlag &) = 0;
    virtual void visit(const GPAFlag &) = 0;
    virtual void visit(const GPUFlag &) = 0;
    virtual void visit(const GPBFlag &) = 0;
    virtual void visit(const GTAFlag &) = 0;
    virtual void visit(const GTBFlag &) = 0;
    virtual void visit(const GTOFlag &) = 0;
    virtual void visit(const FPFlag &) = 0;
    virtual void visit(const NG2Flag &) = 0;
    virtual void visit(const GZFlag &) = 0;
    virtual void visit(const OAMFlag &) = 0;
    virtual void visit(const RPFlag &) = 0;
    virtual void visit(const LOGFlag &) = 0;
    virtual void visit(const FPBFlag &) = 0;
    virtual void visit(const CSBFlag &) = 0;
    virtual void visit(const DELETEFlag &) = 0;
    virtual void visit(const NBFlag &) = 0;
    virtual void visit(const NCFlag &) = 0;
    virtual void visit(const GWFlag &) = 0;
    virtual void visit(const GRFlag &) = 0;
    virtual void visit(const AFlag &) = 0;
    virtual void visit(const RFlag &) = 0;
    virtual void visit(const GUFlag &) = 0;
    virtual void visit(const TFlag &) = 0;
    virtual void visit(const RBFlag &) = 0;
    virtual void visit(const FBFlag &) = 0;
    virtual void visit(const NTFlag &) = 0;
    virtual void visit(const SFlag &) = 0;
    virtual void visit(const IFlag &) = 0;
    virtual void visit(const FRFlag &) = 0;
    virtual void visit(const RSCHFlag &) = 0;
    virtual void visit(const CLOSEFlag &) = 0;
    virtual void visit(const NEFlag &) = 0;
    virtual void visit(const UNLNKFlag &) = 0;
    virtual void visit(const PREFlag &) = 0;
    virtual void visit(const DLNKFlag &) = 0;
    virtual void visit(const FLUSHFlag &) = 0;
    virtual void visit(const CFlag &) = 0;
    virtual void visit(const BFFlag &) = 0;
    virtual void visit(const BrslFlags &) = 0;
    virtual void visit(const CbranchFlags &) = 0;
    virtual void visit(const TrafficScheduleFlags &) =0;

    virtual void visit(const GSTICKFlag &) = 0;
    virtual void visit(const NULFlag &) = 0;
    virtual void visit(const PolFlags &) = 0;
    virtual void visit(const PutFlags &) = 0;
    virtual void visit(const GetFlags &) = 0;

    virtual void visit(const Ascii &) = 0;
    virtual void visit(const LocalLabel &) = 0;    
    virtual void visit(const GlobalLabel &) = 0;    
    virtual void visit(const FileScopeLabel &) = 0;
    virtual void visit(const List &) = 0;
    virtual void visit(const NoList &) = 0;
    virtual void visit(const EndMacro &) = 0;
    virtual void visit(const Align &) = 0;
    virtual void visit(const Ref &) = 0;
    virtual void visit(const UnNamedEndBlock &) = 0;
    virtual void visit(const NamedEndBlock &) = 0;

    virtual void visit(const Text &) = 0;
    virtual void visit(const Data &) = 0;
    virtual void visit(const Comm &) = 0;
    virtual void visit(const Lcomm &) = 0;
    virtual void visit(const NamedSection &) = 0;
    virtual void visit(const Byte &) = 0;
    virtual void visit(const Word &) = 0;
    virtual void visit(const HalfWord &) = 0;
    virtual void visit(const Org &) = 0;
    virtual void visit(const OrgWithFillValue &) = 0;
    virtual void visit(const StructEndDirective &) = 0;
    virtual void visit(const StructBeginDirective &) = 0;
    virtual void visit(const MapDirective &) = 0;
    virtual void visit(const ScopedMapDirective &) = 0;
    virtual void visit(const UnmapDirective &) = 0;
    virtual void visit(const ElementDirective &) = 0;

    virtual void visit(const  MeetsDirective&) = 0;
    virtual void visit(const  AssertDirective&) = 0;
    virtual void visit(const  WarningDirective&) = 0;
    virtual void visit(const  ErrorDirective&) = 0;
    virtual void visit(const  SregisterDirective&) = 0;

    virtual void visit(const Field &) = 0;
    virtual void visit(const BitField &) = 0;

    virtual void visit(const InvalidOctaveInstruction &) = 0;


    virtual void visit(const LabelList &) = 0; 
    virtual void visit(const GlobalRegisterList &) = 0;
    virtual void visit(const IndirectCallTargetList &) = 0;

    virtual void visit(const ArgList &) =0;
    virtual void visit(const ResultList &) =0;
    virtual void visit(const ScratchList &) =0;
    virtual void visit(const RegLnksListToSPRAM &) =0;
    virtual void visit(const RegLnksListToLockedSPRAM &) =0;
    virtual void visit(const RegLnksListToSRAM &) =0;
    virtual void visit(const RegLnksListToSDRAM &) =0;
    virtual void visit(const RegLnksListToCCRAM &) =0;
    virtual void visit(const RegLnksListToLockedCCRAM &) =0;
    virtual void visit(const RegLnksListToSIO &) =0;
  
    virtual void visit(const GlobalDirective &) = 0;
    virtual void visit(const MultipleEntryEvh &) = 0;
    virtual void visit(const EndEvhDirective &) = 0;
    virtual void visit(const MultipleEntryFunction &) = 0;
    virtual void visit(const EndEntryDirective &) = 0;
    virtual void visit(const PrototypeDirective &) = 0;
    virtual void visit(const JtableBegin &) = 0;
    virtual void visit(const JtableEnd &) = 0;
    virtual void visit(const JtableRelativeBegin &) = 0;
    virtual void visit(const JtableRelativeEnd &) = 0;


  };
  
  
}
#endif