#ifndef _YYSTYPES_H_
#define _YYSTYPES_H_

/* This stuff is certainly dancing on the dizzy edge of hackdom, but
 * it solves a major problem we had when Yacc met C++ and shared_ptr.
 * Yacc parsers,
 *    a) do their own memory management for the parse stack, with
 *       no opportunity to call new/delete
 *    b) use a union for YYSTYPE

 * But C++,
 *    a) requires either delete or loss-of-scope to trigger shared_ptr
 *       reference management
 *    b) does not allow class objects with a constructor or destructor
 *       to be part of a union
 * 
 * So in order to return shared_ptr objects on the parser stack, we
 * concluded that we had to invent a container class for just about 
 * every nonterminal, keep track of them, and clean them up.
 *
 * This file implements the container classes, a flat hierarchy
 * rooted at YystypeContainer, which is needed so that we can
 * delete objects any of the container classes through a common
 * pointer.
 */


/* Certain rules do not return anything useful on the parser stack.
   But since we're using %type, we have to assign a type to them,
   hence this simple typedef. */
typedef int ParseConstruct;


/* Llir object interface. */
#include <OctaveSymbol.h>
#include <OctaveFactory.h>


/* 
   Name conflicts 

   since we are using bison in alo
   which is also used in gcc we get
   all types of name conflicts when we 
   try to link both of them.
   To avoid this problem I used 

    -P alo_ option with flex
    -p alo_ option with bison to

   which automatically renames all yy* 
   variables in alolang.tab.c to alo_* .
*/

using namespace Llir;

class YystypeContainer {
public:
  virtual ~YystypeContainer()=0;
};

inline
YystypeContainer::~YystypeContainer()
{}

class StructContainer: public YystypeContainer 
{
 public:
  shared_ptr<Struct> st;
  ~StructContainer() { }
};


class TypeContainer: public YystypeContainer 
{
 public:
  shared_ptr<const Type> ty;
  string name;
  ~TypeContainer() { }
};

class OptionalRegConstraints: public YystypeContainer {
 public:
  AbstractSymReg::SymRegConstraint reg_constraint;
  shared_ptr<const Register> constraint_reg_range;
};

class OptionalModAbcContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> mod_flag;
  shared_ptr<const LlirOperand> abc_flag;
  ~OptionalModAbcContainer() { }
};

class ImmedBranchArgsContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> rd;
  shared_ptr<const LlirOperand> cd_flag;  
  ~ImmedBranchArgsContainer() { }
};

class OptionalModAbcCompareContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> mod_flag;
  shared_ptr<const LlirOperand> abc_compare_flag;
  ~OptionalModAbcCompareContainer() { }
};

class OptionalAbcContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> abc_flag;
  ~OptionalAbcContainer() { }
};

class OptionalSignFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> sign_flag;
  ~OptionalSignFlagContainer() { }
};

class OptionalZContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> z_flag;
  ~OptionalZContainer() { }
};

class OptionalPipeDepthContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> pipe_depth;
  ~OptionalPipeDepthContainer() { }
};

class OptionalRegContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> reg;
  ~OptionalRegContainer() { }
};


class OptionalBranchDispContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> branch_disp;
  ~OptionalBranchDispContainer() { }
};

class OptionalBranchDispWithAbcContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> branch_disp;
  shared_ptr<const LlirOperand> abc_flag;
  ~OptionalBranchDispWithAbcContainer() { }
};

class OptionalAbcCompareSignContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> abc_compare_flag;
  shared_ptr<const LlirOperand> sign_flag;
  ~OptionalAbcCompareSignContainer() { }
};

class OptionalAbcZbitContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> abc_flag;
  shared_ptr<const LlirOperand> zbit;
  ~OptionalAbcZbitContainer() { }
};


class OptionalDepbFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> zbit;
  ~OptionalDepbFlagContainer() { }
};

class OptionalCycsFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> cycs;
  ~OptionalCycsFlagContainer() { }
};

class OptionalHecFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> cume;
  ~OptionalHecFlagContainer() { }
};

class OptionalSxFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> sx_flag;
  ~OptionalSxFlagContainer() { }
};

class OptionalDiFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> di_flag;
  ~OptionalDiFlagContainer() { }
};

class OptionalLnkFlagContainer: public YystypeContainer {
 public:
  shared_ptr<const LlirOperand> linkFlag;
  ~OptionalLnkFlagContainer() { }
};


class RegContainer: public YystypeContainer {
 public:
  RegContainer() { isfield = 0; baseregSet = 0; }
  shared_ptr<const Register> regPtr;
  int isfield;
  shared_ptr<const BitField> bitfield;
  shared_ptr<const Register> baseregPtr;
  int baseregSet;
  ~RegContainer() { }
};

class OptionalIndirectCallTargetList : public YystypeContainer {
 public:
   OptionalIndirectCallTargetList() {}
  ~OptionalIndirectCallTargetList() {}
  shared_ptr<const LlirOperand> callList;
};

class OptionalBranchProbability : public YystypeContainer {
 public:
   OptionalBranchProbability() {}
  ~OptionalBranchProbability() {}
  enum OctaveInstruction::BranchProbability probability;
};

/*  class SingleRegContainer: public YystypeContainer { */
/*   public: */
/*    SingleRegisterPtr regPtr; */
/*    ~SingleRegContainer() { } */
/*  }; */

/*  class MultiRegContainer: public YystypeContainer { */
/*   public: */
/*    MultiRegisterPtr regPtr; */
/*    ~MultiRegContainer() { } */
/*  }; */

class OctaveInsnContainer: public YystypeContainer {
 public:
  shared_ptr<OctaveInstruction> insnPtr;
  ~OctaveInsnContainer() { }
};

class CondBranchFlagsContainer: public YystypeContainer
{
 public:
  CondBranchFlagsContainer();
  void finalize();
  shared_ptr<EssFlag> ess;
  int c_bit;
  int bf_bit;
  shared_ptr<const LlirOperand> flags;
  shared_ptr<const LlirOperand> rd;  
  ~CondBranchFlagsContainer()  { }
};

class TrafficSchedFlagsContainer: public YystypeContainer {
 public:
  shared_ptr<TrafficScheduleFlags> flags;
  ~TrafficSchedFlagsContainer() { }
};
  


class BrslArgsContainer: public YystypeContainer
{
 public:
  BrslArgsContainer();
  void finalize();
  int ul;
  int dlnk;
  int fl;
  int pr;
  shared_ptr<const LlirOperand> flags;
  ~BrslArgsContainer()  { }
};

class EssContainer: public YystypeContainer
{
 public:
  shared_ptr<EssFlag> ess;  
};

class MultiRegArgsContainer: public YystypeContainer
{
 public:
  MultiRegArgsContainer() { convert = 0; }
  shared_ptr<const Register> regs;
  shared_ptr<OctaveMemory> mem;
  shared_ptr<const LlirOperand> linkFlag;
  int convert;
};

class SmmArgsContainer: public YystypeContainer
{
 public:
  shared_ptr<const Register> regs;
  shared_ptr<OctaveMemory> mem;
};

class BitopArgsContainer: public YystypeContainer
{
 public:
  shared_ptr<const Register> src;
  shared_ptr<const UnsignedImmediate> srcBitNum;
  shared_ptr<const Register> dst;  
  shared_ptr<const UnsignedImmediate> dstBitNum;
  shared_ptr<const UnsignedImmediate> numBits;
};

class DepbiArgsContainer: public YystypeContainer
{
 public:
  shared_ptr<const UnsignedImmediate> src;
  shared_ptr<const Register> dst;  
  shared_ptr<const UnsignedImmediate> dstBitNum;
  shared_ptr<const UnsignedImmediate> numBits;
/*    shared_ptr<const LlirOperand> flag; */
};

class TestArgsContainer: public YystypeContainer
{
 public:
  shared_ptr<const Register> reg;
  shared_ptr<const UnsignedImmediate> bitnum;
};


class OptionalNumBitsContainer: public YystypeContainer
{
 public:
  shared_ptr<const UnsignedImmediate> value;
  int isset;
};

class OptionalBitPosContainer: public YystypeContainer
{
 public:
  shared_ptr<const UnsignedImmediate> bitpos;
  int isset;
};

/* Expression wrapper classes.  One for each kind of expression-node,
 * or for each "expr" production (should be a 1:1 correspondence(?)) */
class ExpContainer: public YystypeContainer 
{
 public:
  ExpContainer() { }
  ExpContainer(const char *name) : name(name) { labelCount = 0; }
  shared_ptr<const LlirExpr> exprPtr;
  int getLabelCount();
  void incLabelCount() { labelCount += 1; }
  void updateLabelCount(ExpContainer *lhs, ExpContainer *rhs);
  void updateLabelCount(ExpContainer *e);
  virtual ~ExpContainer() { }
 private:
  const char *name;
  int labelCount;
};

class ErrorContainer :  public ExpContainer
{
 public:
  ErrorContainer():  ExpContainer("error") { }
};


class ConstantContainer :  public ExpContainer
{
 public:
  ConstantContainer():  ExpContainer("constant") { }
};

class LabelContainer :  public ExpContainer
{
 public:
  LabelContainer():  ExpContainer("label") { incLabelCount(); }
};


class PlusContainer:  public ExpContainer 
{
 public:
  PlusContainer() : ExpContainer("+") { }
};


class MinusContainer:  public ExpContainer 
{
 public:
  MinusContainer() : ExpContainer("-") { }
};


class MultiplyContainer:  public ExpContainer 
{
 public:
  MultiplyContainer() : ExpContainer("*") { }
};


class DivContainer:  public ExpContainer 
{
 public:
  DivContainer() : ExpContainer("/") { }
};


class ModulusContainer:  public ExpContainer 
{
 public:
  ModulusContainer() : ExpContainer("%") { }
};


class BitWiseOrContainer:  public ExpContainer 
{
 public:
  BitWiseOrContainer() : ExpContainer("|") { }
};


class BitWiseAndContainer:  public ExpContainer 
{
 public:
  BitWiseAndContainer() : ExpContainer("&") { }
};


class BitWiseXorContainer:  public ExpContainer 
{
 public:
  BitWiseXorContainer() : ExpContainer("^") { }
};


class LeftShiftContainer:  public ExpContainer 
{
 public:
  LeftShiftContainer() : ExpContainer("<<") { }
};


class RightShiftContainer:  public ExpContainer 
{
 public:
  RightShiftContainer() : ExpContainer(">>") { }
};

class ParensContainer:  public ExpContainer
{
 public:
  ParensContainer() : ExpContainer("( ... )") { }
};

class UnaryMinusContainer:  public ExpContainer
{
 public:
  UnaryMinusContainer() : ExpContainer("unary -") { }
};

class AssertOpContainer:  public ExpContainer
{
 public:
  AssertOpContainer() : ExpContainer("assert") { }
};

class RegListContainer: public YystypeContainer
{
 public:
  RegListContainer() {}
  ~RegListContainer() {}
  shared_ptr<RegList> regList;
};

class LabelListContainer: public YystypeContainer
{
 public:
  LabelListContainer() {}
  ~LabelListContainer() {}
  shared_ptr<LabelList> labelList;
};

class MemoryLinksListContainer: public YystypeContainer
{
 public:
  MemoryLinksListContainer() {}
  ~MemoryLinksListContainer() {}

  shared_ptr<RegList> lnkSPList1;
  shared_ptr<RegList> lnkSPList2;
  shared_ptr<RegList> lnkSPList3;

  shared_ptr<RegList> lnkLockedSPList1;
  shared_ptr<RegList> lnkLockedSPList2;
  shared_ptr<RegList> lnkLockedSPList3;

  shared_ptr<RegList> lnkSRList1;
  shared_ptr<RegList> lnkSRList2;
  shared_ptr<RegList> lnkSRList3;

  shared_ptr<RegList> lnkSDList1;
  shared_ptr<RegList> lnkSDList2;
  shared_ptr<RegList> lnkSDList3;

  shared_ptr<RegList> lnkCCList1;
  shared_ptr<RegList> lnkCCList2;
  shared_ptr<RegList> lnkCCList3;

  shared_ptr<RegList> lnkLockedCCList1;
  shared_ptr<RegList> lnkLockedCCList2;
  shared_ptr<RegList> lnkLockedCCList3;

  shared_ptr<RegList> lnkSIOList1;
  shared_ptr<RegList> lnkSIOList2;
  shared_ptr<RegList> lnkSIOList3;

};

class LinksListContainer: public YystypeContainer
{
 public:
  LinksListContainer() {}
  ~LinksListContainer() {}

  shared_ptr<RegList> lnk1List;
  shared_ptr<RegList> lnk2List;
  shared_ptr<RegList> lnk3List;
};

#endif















