#ifndef _OCTAVE_GEN_RTL_VISITOR_H
#define _OCTAVE_GEN_RTL_VISITOR_H

#include <Visitor.h>
#include <LlirVisitor.h>
#include <OctaveVisitor.h>

#include "OctaveAlo.h"

using namespace Llir;
extern std::map<string, shared_ptr<const PrototypeDirective> > g_prototypeDirList;

namespace Alo
{
  class OctaveGenerateRtlVisitor :
    public Visitor,
    public LlirOctaveVisitor
    {
    public:
      
      typedef std::map<unsigned int, LinkFlag::Link_Flag_t>::iterator  RegLinksListIterator;
      typedef std::map<unsigned int, LinkFlag::Link_Flag_t>::const_iterator  RegLinksListConstIterator;
      typedef std::map<unsigned int, OctaveMemory::MemType_t>::iterator RegLinkMemTypeIterator;
      typedef std::map<unsigned int, OctaveMemory::MemType_t>::const_iterator RegLinkMemTypeConstIterator;

      OctaveGenerateRtlVisitor(OctaveAlo &o);
				          
      OctaveGenerateRtlVisitor(const OctaveGenerateRtlVisitor& rhs);
      
      const OctaveGenerateRtlVisitor& operator=(const OctaveGenerateRtlVisitor& rhs);
       
      virtual ~OctaveGenerateRtlVisitor()  {}

      // Llir Operands
      
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
      void visit(const BZFlag &o){}
      void visit(const BNCFlag &o){}
      void visit(const BNOFlag &o){}
      void visit(const BGEZFlag &o){}
      void visit(const BLZFlag &o){}
      void visit(const BNZFlag &o){}
      void visit(const BLEZFlag &o){}
      void visit(const BALBFlag &o);
      void visit(const BAEBFlag &o);
      void visit(const BAGBFlag &o);
      void visit(const BANEBFlag &o);
      void visit(const BAGEBFlag &o);
      void visit(const BALEBFlag &o);
      void visit(const C0Flag &o){}
      void visit(const C1Flag &o){}
      void visit(const C2Flag &o){}
      void visit(const C3Flag &o){}
      void visit(const C4Flag &o){}
      void visit(const C5Flag &o){}
      void visit(const C6Flag &o){}
      void visit(const C7Flag &o){}
      void visit(const C8Flag &o){}
      void visit(const C9Flag &o){}
      void visit(const C10Flag &o){}
      void visit(const C11Flag &o){}
      void visit(const C12Flag &o){}
      void visit(const C13Flag &o){}
      void visit(const C14Flag &o){}
      void visit(const C15Flag &o){}
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
      void visit(const SXFlag &o){}
      void visit(const FindFlag &o){}
      void visit(const CumeFlag &o){}
      void visit(const SignFlag &o){}
      void visit(const CDFlag &o){}
      void visit(const DepbFlag &o){}
      void visit(const DIFlag &o){}
      void visit(const LNK1Flag &o){}
      void visit(const LNK2Flag &o){}
      void visit(const LNK3Flag &o){}
      void visit(const GC1AFlag &o){}
      void visit(const GC1OFlag &o){}
      void visit(const GC1BFlag &o){}
      void visit(const GC2AFlag &o){}
      void visit(const GC2OFlag &o){}
      void visit(const GC2BFlag &o){}
      void visit(const GPAFlag &o){}
      void visit(const GPUFlag &o){}
      void visit(const GPBFlag &o){}
      void visit(const GTAFlag &o){}
      void visit(const GTBFlag &o){}
      void visit(const GTOFlag &o){}
      void visit(const FPFlag &o){}
      void visit(const NG2Flag &o){}
      void visit(const GZFlag &o){}
      void visit(const OAMFlag &o){}
      void visit(const RPFlag &o){}
      void visit(const LOGFlag &o){}
      void visit(const FPBFlag &o){}
      void visit(const CSBFlag &o){}
      void visit(const DELETEFlag &o){}
      void visit(const NBFlag &o){}
      void visit(const NCFlag &o){}
      void visit(const GWFlag &o){}
      void visit(const GRFlag &o){}
      void visit(const AFlag &o){}
      void visit(const RFlag &o){}
      void visit(const GUFlag &o){}
      void visit(const TFlag &o){}
      void visit(const RBFlag &o){}
      void visit(const FBFlag &o){}
      void visit(const NTFlag &o){}
      void visit(const SFlag &o){}
      void visit(const IFlag &o) {}
      void visit(const RSCHFlag &o) {}
      void visit(const FRFlag &o) {}
      void visit(const CLOSEFlag &o) {}
      void visit(const NEFlag &o) {}
      void visit(const UNLNKFlag &o){}
      void visit(const PREFlag &o){}
      void visit(const DLNKFlag &o){}
      void visit(const FLUSHFlag &o){}
      void visit(const BFFlag &o){}
      void visit(const CFlag &o){}
      void visit(const GSTICKFlag &o){}
      void visit(const NULFlag &o){}


      //llir specific visit methods...
      void visit(const InvalidOctaveInstruction& v){}
      void visit(const LlirFile& v){} 
      void visit(const LlirSequence& v); 
      void visit(const NullNode& v){} 
      void visit(const NewLineNode& v){}
      void visit(const NullInstruction& v){} 

      //operands that can be part of 
      //valid expressions during rtl 
      //generation.
      void visit(const SignedImmediate& v);
      void visit(const UnsignedImmediate& v);
      void visit(const OpndLabel& v);
      void visit(const PlusOp& v);
      void visit(const MinusOp& v);

      void visit(const ParenthesesOp& v);
      void visit(const Lo17Op &);
      void visit(const Hi16Op &);
      void visit(const Lo16Op &);
      void visit(const MultiplyOp& v){}
      void visit(const DivOp& v){}
      void visit(const ModulusOp& v){}
      void visit(const LeftShiftOp& v){} 
      void visit(const RightShiftOp& v){} 
      void visit(const BitWiseAndOp& v){}
      void visit(const BitWiseOrOp& v){} 
      void visit(const BitWiseXorOp& v){} 
      void visit(const UnaryMinusOp& v){}
      void visit(const OpndNull& v){}
      void visit(const NullRegister& v){}
      void visit(const HardRegister& v);
      void visit(const PseudoRegister& v);
      void visit(const MultiHardRegister& v);
      void visit(const MultiPseudoRegister& v);

      void visit(const LlirLineControlDirective& v);     

      //octave specific visit methods...
      void visit(const OctaveBlock &);
      void visit(const OctaveMacroBlock &);
      void visit(const OctaveImplicitBlock &);
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
      void visit(const MeetsDirective&); 
      void visit(const AssertDirective&); 
      void visit(const WarningDirective&); 
      void visit(const ErrorDirective&);
      void visit(const SregisterDirective&);
      void visit(const GlobalDirective &);
      void visit(const MultipleEntryEvh &);
      void visit(const EndEvhDirective &);
      void visit(const MultipleEntryFunction &);
      void visit(const EndEntryDirective &);
      void visit(const PrototypeDirective &);
      void visit(const JtableBegin &);
      void visit(const JtableEnd &);
      void visit(const JtableRelativeBegin &);
      void visit(const JtableRelativeEnd &);

      void visit(const Base2PlusOffset &);
      void visit(const Base3PlusOffset &); 
      void visit(const RegPlusOffsetIndirect &);
      void visit(const ImpliedBase2Offset &);

      void visit(const WordOp &){} 
      void visit(const Field &){} 
      void visit(const BitField &){} 
      void visit(const BrslFlags &){}
      void visit(const CbranchFlags &){}
      void visit(const TrafficScheduleFlags &){}
      void visit(const PutFlags &){}
      void visit(const PolFlags &){}
      void visit(const GetFlags &){}
      void visit(const GlobalRegisterList &){}
      void visit(const ArgList &){}
      void visit(const ResultList &){}
      void visit(const ScratchList &){}
      void visit(const IndirectCallTargetList &){}
      void visit(const LabelList &);
      void visit(const RegLnksListToSPRAM &);
      void visit(const RegLnksListToLockedSPRAM &);
      void visit(const RegLnksListToSRAM &);
      void visit(const RegLnksListToSDRAM &);
      void visit(const RegLnksListToCCRAM &);
      void visit(const RegLnksListToLockedCCRAM &);
      void visit(const RegLnksListToSIO &);

      void generatingRtlForFunction(bool isInFunction);
      bool inFunction() const;
      shared_ptr<AltEntryFunction>  getCurrentFunction();
      void setCurrentFunction(shared_ptr<AltEntryFunction> fn);

    protected:
      OctaveAlo& getAlo() const;

      bool isInSequence() const;

      void setRegLink(unsigned int, LinkFlag::Link_Flag_t);
      LinkFlag::Link_Flag_t getRegLink(unsigned int);
      bool isLinkedReg(unsigned int);

      void setRegisterLinkedMemoryType(unsigned int, OctaveMemory::MemType_t);
      OctaveMemory::MemType_t getRegisterLinkedMemoryType(unsigned int);

      shared_ptr<const PrototypeDirective> searchForPrototype(unsigned int line, const char *file, const char* name);
      void computeCallUseRegSet(shared_ptr<const PrototypeDirective> proto, unsigned int *regArray);
      void computeCallReturnRegSet(shared_ptr<const PrototypeDirective> proto, unsigned int *regArray);
      unsigned int computeNumOfArgRegs(shared_ptr<const PrototypeDirective> proto);

    private:

      enum Label_Scope { LOCAL, GLOBAL, GLOBAL_ENTRY, FILESCOPE };
      void genRtlForAsmDirective(const LlirNode &d);
      
      void emitEpilogue(shared_ptr<AltEntryFunction>);
      bool isNodeVisited(shared_ptr<LlirNode> n);

      OctaveAlo& m_alo;
      shared_ptr<AltEntryFunction> m_currentFunction;

      bool m_inSequence;
      bool m_inFunction;
      std::map<unsigned int, LinkFlag::Link_Flag_t> m_regLinksList;
      std::map<unsigned int, OctaveMemory::MemType_t> m_regMemLinkTypeList;
      
    };



}

#endif
