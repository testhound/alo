#ifndef _LLIR_OCTAVE_OPERAND_H_
#define _LLIR_OCTAVE_OPERAND_H_

#include <LlirOperand.h>

namespace Llir
{
  class Visitor;

  class OctaveMemory : public OpndMemory
  {
  public:

    enum MemType_t 
    {  
      MEMTYPE_SRAM=0,
      MEMTYPE_SDRAM,
      MEMTYPE_SIO,
      MEMTYPE_SPRAM,
      MEMTYPE_SPRAM_LOCKED,
      MEMTYPE_CCRAM,
      MEMTYPE_CCRAM_LOCKED,
      MEMTYPE_ANY
    };
  
    virtual ~OctaveMemory();
    shared_ptr<const LlirOperand> getOffset() const;

  protected:
    OctaveMemory(shared_ptr<const LlirOperand> offset );
    OctaveMemory(const OctaveMemory &rhs);
    OctaveMemory& operator=(const OctaveMemory &rhs);

  private:

    shared_ptr<const LlirOperand> m_offset;
    // long m_offset;
    // offset can be a label too...

  };

  inline OctaveMemory::~OctaveMemory()
  {}

  class BasePlusOffset : public OctaveMemory
  {
  public:
    BasePlusOffset(shared_ptr<const LlirOperand> offset);
    virtual ~BasePlusOffset();
    BasePlusOffset(const BasePlusOffset &rhs);
    BasePlusOffset& operator=(const BasePlusOffset &rhs);
  };

  inline
  BasePlusOffset::~BasePlusOffset()
  {}

  class Base2PlusOffset : public BasePlusOffset
  {
  public:
    Base2PlusOffset(shared_ptr<const LlirOperand> offset);
    ~Base2PlusOffset();
    Base2PlusOffset(const Base2PlusOffset &rhs);
    Base2PlusOffset& operator=(const Base2PlusOffset &rhs);

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  Base2PlusOffset::~Base2PlusOffset()
  {}

  class Base3PlusOffset : public BasePlusOffset
  {
  public:
    Base3PlusOffset(shared_ptr<const LlirOperand> offset);
    ~Base3PlusOffset();
    Base3PlusOffset(const Base3PlusOffset &rhs);
    Base3PlusOffset& operator=(const Base3PlusOffset &rhs);

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  Base3PlusOffset::~Base3PlusOffset()
  {}

  class RegPlusOffsetIndirect : public OctaveMemory
  {
  public:
    RegPlusOffsetIndirect(shared_ptr<const Register>, shared_ptr<const LlirOperand> offset);
    ~RegPlusOffsetIndirect();
    RegPlusOffsetIndirect(const RegPlusOffsetIndirect &rhs);
    RegPlusOffsetIndirect& operator=(const RegPlusOffsetIndirect &rhs);

    void accept(Visitor &) const;
    shared_ptr<const Register> getBaseRegister() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    shared_ptr<const Register> m_baseRegister;
  };

  inline
  RegPlusOffsetIndirect::~RegPlusOffsetIndirect()
  {}

  class ImpliedBase2Offset : public OctaveMemory
  {
  public:
    ImpliedBase2Offset(shared_ptr<const LlirOperand> offset);
    ~ImpliedBase2Offset();
    ImpliedBase2Offset(const ImpliedBase2Offset &rhs);
    ImpliedBase2Offset& operator=(const ImpliedBase2Offset &rhs);

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  ImpliedBase2Offset::~ImpliedBase2Offset()
  {}

  class OctaveUnaryExpr : public UnaryExpr
  {
    public:
      virtual ~OctaveUnaryExpr();

    protected:
      OctaveUnaryExpr(shared_ptr<const LlirOperand> op);
      OctaveUnaryExpr(const OctaveUnaryExpr &rhs);
      OctaveUnaryExpr& operator=(const OctaveUnaryExpr &rhs);
  };

  inline
  OctaveUnaryExpr::~OctaveUnaryExpr()
  {}

  class Lo17Op : public OctaveUnaryExpr
  {
  public:
    Lo17Op(shared_ptr<const LlirOperand> op);
    ~Lo17Op();
    Lo17Op(const Lo17Op &rhs);
    Lo17Op& operator=(const Lo17Op &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  Lo17Op::~Lo17Op()
  {}


  class Hi16Op : public OctaveUnaryExpr
  {
  public:
    Hi16Op(shared_ptr<const LlirOperand> op);
    ~Hi16Op();
    Hi16Op(const Hi16Op &rhs);
    Hi16Op& operator=(const Hi16Op &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  Hi16Op::~Hi16Op()
  {}

  class Lo16Op : public OctaveUnaryExpr
  {
  public:
    Lo16Op(shared_ptr<const LlirOperand> op);
    ~Lo16Op();
    Lo16Op(const Lo16Op &rhs);
    Lo16Op& operator=(const Lo16Op &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  Lo16Op::~Lo16Op()
  {}

  class WordOp : public OctaveUnaryExpr
  {
  public:
    WordOp(shared_ptr<const LlirOperand> op);
    ~WordOp();
    WordOp(const WordOp &rhs);
    WordOp& operator=(const WordOp &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  WordOp::~WordOp()
  {}



  class OctaveFlag : public LlirOperand
  {
  public:
    virtual ~OctaveFlag() = 0;
    virtual bool isNullOperand() const;
  protected:
    OctaveFlag();
    OctaveFlag(const OctaveFlag &rhs);
    OctaveFlag& operator=(const OctaveFlag &rhs);
  };

  inline
  OctaveFlag::~OctaveFlag()
  {}

  inline bool OctaveFlag::isNullOperand() const
    {
      return false;
    }

  class ModFlag : public OctaveFlag
  {
  public:

    enum ModuloWidth
    {         MOD2=1, MOD4,  MOD8,  MOD16,  MOD32,  MOD64,  MOD128,  MOD256,   MOD512,
      MOD1K,  MOD2K,  MOD4K, MOD8K, MOD16K, MOD32K, MOD64K, MOD128K, MOD256K,  MOD512K,
      MOD1M,  MOD2M,  MOD4M, MOD8M, MOD16M, MOD32M, MOD64M, MOD128M, MOD256M,  MOD512M,
      MOD1G,  MOD2G
    };

    virtual ~ModFlag() = 0;
    virtual ModuloWidth getModuloWidth() const=0;

  protected:
    ModFlag();
    ModFlag(const ModFlag &rhs);
    ModFlag& operator=(const ModFlag &rhs);


  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  ModFlag::~ModFlag()
  {}




class Mod2Flag : public ModFlag
  {
  public:
    Mod2Flag();
    Mod2Flag(const Mod2Flag &rhs);
    Mod2Flag& operator=(const Mod2Flag &rhs);
    ~Mod2Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod4Flag : public ModFlag
  {
  public:
    Mod4Flag();
    Mod4Flag(const Mod4Flag &rhs);
    Mod4Flag& operator=(const Mod4Flag &rhs);
    ~Mod4Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod8Flag : public ModFlag
  {
  public:
    Mod8Flag();
    Mod8Flag(const Mod8Flag &rhs);
    Mod8Flag& operator=(const Mod8Flag &rhs);
    ~Mod8Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod16Flag : public ModFlag
  {
  public:
    Mod16Flag();
    Mod16Flag(const Mod16Flag &rhs);
    Mod16Flag& operator=(const Mod16Flag &rhs);
    ~Mod16Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod32Flag : public ModFlag
  {
  public:
    Mod32Flag();
    Mod32Flag(const Mod32Flag &rhs);
    Mod32Flag& operator=(const Mod32Flag &rhs);
    ~Mod32Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod64Flag : public ModFlag
  {
  public:
    Mod64Flag();
    Mod64Flag(const Mod64Flag &rhs);
    Mod64Flag& operator=(const Mod64Flag &rhs);
    ~Mod64Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod128Flag : public ModFlag
  {
  public:
    Mod128Flag();
    Mod128Flag(const Mod128Flag &rhs);
    Mod128Flag& operator=(const Mod128Flag &rhs);
    ~Mod128Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod256Flag : public ModFlag
  {
  public:
    Mod256Flag();
    Mod256Flag(const Mod256Flag &rhs);
    Mod256Flag& operator=(const Mod256Flag &rhs);
    ~Mod256Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod512Flag : public ModFlag
  {
  public:
    Mod512Flag();
    Mod512Flag(const Mod512Flag &rhs);
    Mod512Flag& operator=(const Mod512Flag &rhs);
    ~Mod512Flag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod1KFlag : public ModFlag
  {
  public:
    Mod1KFlag();
    Mod1KFlag(const Mod1KFlag &rhs);
    Mod1KFlag& operator=(const Mod1KFlag &rhs);
    ~Mod1KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod2KFlag : public ModFlag
  {
  public:
    Mod2KFlag();
    Mod2KFlag(const Mod2KFlag &rhs);
    Mod2KFlag& operator=(const Mod2KFlag &rhs);
    ~Mod2KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod4KFlag : public ModFlag
  {
  public:
    Mod4KFlag();
    Mod4KFlag(const Mod4KFlag &rhs);
    Mod4KFlag& operator=(const Mod4KFlag &rhs);
    ~Mod4KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod8KFlag : public ModFlag
  {
  public:
    Mod8KFlag();
    Mod8KFlag(const Mod8KFlag &rhs);
    Mod8KFlag& operator=(const Mod8KFlag &rhs);
    ~Mod8KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod16KFlag : public ModFlag
  {
  public:
    Mod16KFlag();
    Mod16KFlag(const Mod16KFlag &rhs);
    Mod16KFlag& operator=(const Mod16KFlag &rhs);
    ~Mod16KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod32KFlag : public ModFlag
  {
  public:
    Mod32KFlag();
    Mod32KFlag(const Mod32KFlag &rhs);
    Mod32KFlag& operator=(const Mod32KFlag &rhs);
    ~Mod32KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod64KFlag : public ModFlag
  {
  public:
    Mod64KFlag();
    Mod64KFlag(const Mod64KFlag &rhs);
    Mod64KFlag& operator=(const Mod64KFlag &rhs);
    ~Mod64KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod128KFlag : public ModFlag
  {
  public:
    Mod128KFlag();
    Mod128KFlag(const Mod128KFlag &rhs);
    Mod128KFlag& operator=(const Mod128KFlag &rhs);
    ~Mod128KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod256KFlag : public ModFlag
  {
  public:
    Mod256KFlag();
    Mod256KFlag(const Mod256KFlag &rhs);
    Mod256KFlag& operator=(const Mod256KFlag &rhs);
    ~Mod256KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod512KFlag : public ModFlag
  {
  public:
    Mod512KFlag();
    Mod512KFlag(const Mod512KFlag &rhs);
    Mod512KFlag& operator=(const Mod512KFlag &rhs);
    ~Mod512KFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod1MFlag : public ModFlag
  {
  public:
    Mod1MFlag();
    Mod1MFlag(const Mod1MFlag &rhs);
    Mod1MFlag& operator=(const Mod1MFlag &rhs);
    ~Mod1MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod2MFlag : public ModFlag
  {
  public:
    Mod2MFlag();
    Mod2MFlag(const Mod2MFlag &rhs);
    Mod2MFlag& operator=(const Mod2MFlag &rhs);
    ~Mod2MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod4MFlag : public ModFlag
  {
  public:
    Mod4MFlag();
    Mod4MFlag(const Mod4MFlag &rhs);
    Mod4MFlag& operator=(const Mod4MFlag &rhs);
    ~Mod4MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod8MFlag : public ModFlag
  {
  public:
    Mod8MFlag();
    Mod8MFlag(const Mod8MFlag &rhs);
    Mod8MFlag& operator=(const Mod8MFlag &rhs);
    ~Mod8MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod16MFlag : public ModFlag
  {
  public:
    Mod16MFlag();
    Mod16MFlag(const Mod16MFlag &rhs);
    Mod16MFlag& operator=(const Mod16MFlag &rhs);
    ~Mod16MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod32MFlag : public ModFlag
  {
  public:
    Mod32MFlag();
    Mod32MFlag(const Mod32MFlag &rhs);
    Mod32MFlag& operator=(const Mod32MFlag &rhs);
    ~Mod32MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod64MFlag : public ModFlag
  {
  public:
    Mod64MFlag();
    Mod64MFlag(const Mod64MFlag &rhs);
    Mod64MFlag& operator=(const Mod64MFlag &rhs);
    ~Mod64MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod128MFlag : public ModFlag
  {
  public:
    Mod128MFlag();
    Mod128MFlag(const Mod128MFlag &rhs);
    Mod128MFlag& operator=(const Mod128MFlag &rhs);
    ~Mod128MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod256MFlag : public ModFlag
  {
  public:
    Mod256MFlag();
    Mod256MFlag(const Mod256MFlag &rhs);
    Mod256MFlag& operator=(const Mod256MFlag &rhs);
    ~Mod256MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod512MFlag : public ModFlag
  {
  public:
    Mod512MFlag();
    Mod512MFlag(const Mod512MFlag &rhs);
    Mod512MFlag& operator=(const Mod512MFlag &rhs);
    ~Mod512MFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod1GFlag : public ModFlag
  {
  public:
    Mod1GFlag();
    Mod1GFlag(const Mod1GFlag &rhs);
    Mod1GFlag& operator=(const Mod1GFlag &rhs);
    ~Mod1GFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

class Mod2GFlag : public ModFlag
  {
  public:
    Mod2GFlag();
    Mod2GFlag(const Mod2GFlag &rhs);
    Mod2GFlag& operator=(const Mod2GFlag &rhs);
    ~Mod2GFlag(){}

    enum ModuloWidth getModuloWidth() const;
    void accept(Visitor &) const;
  };

  class AbcFlag : public OctaveFlag
  {
  public: 
    virtual ~AbcFlag() = 0;

  protected:
    AbcFlag();
    AbcFlag(const AbcFlag &rhs);
    AbcFlag& operator=(const AbcFlag &rhs);
  };



  inline
  AbcFlag::~AbcFlag()
  {}

  class AbcGenericFlag : public AbcFlag
  {
  public:
    virtual ~AbcGenericFlag() = 0;

  protected:
    AbcGenericFlag();
    AbcGenericFlag(const AbcGenericFlag &rhs);
    AbcGenericFlag& operator=(const AbcGenericFlag &rhs);

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  AbcGenericFlag::~AbcGenericFlag()
  {}

  class AbcCompareFlag : public AbcFlag
  {
  public:
    enum Abc_Compare_t { BALB=1, BAEB, BAGB, BANEB, BAGEB, BALEB };
    virtual Abc_Compare_t getABCFlagType() const=0;
			 
    virtual ~AbcCompareFlag() = 0;
    

  protected:
    AbcCompareFlag();
    AbcCompareFlag(const AbcCompareFlag &rhs);
    AbcCompareFlag& operator=(const AbcCompareFlag &rhs);

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  AbcCompareFlag::~AbcCompareFlag()
  {}

  class BZFlag : public AbcGenericFlag
  {
  public:
    BZFlag();
    BZFlag(const BZFlag &rhs);
    BZFlag& operator=(const BZFlag &rhs);
    ~BZFlag();

    void accept(Visitor &) const;
  };

  inline
  BZFlag::~BZFlag()
  {}

  class BNCFlag : public AbcGenericFlag
  {
  public:
    BNCFlag();
    BNCFlag(const BNCFlag &rhs);
    BNCFlag& operator=(const BNCFlag &rhs);
    ~BNCFlag();

    void accept(Visitor &) const;
  };

  inline
  BNCFlag::~BNCFlag()
  {}

  class BNOFlag : public AbcGenericFlag
  {
  public:
    BNOFlag();
    BNOFlag(const BNOFlag &rhs);
    BNOFlag& operator=(const BNOFlag &rhs);
    ~BNOFlag();

    void accept(Visitor &) const;
  };

  inline
  BNOFlag::~BNOFlag()
  {}

  class BGEZFlag : public AbcGenericFlag
  {
  public:
    BGEZFlag();
    BGEZFlag(const BGEZFlag &rhs);
    BGEZFlag& operator=(const BGEZFlag &rhs);
    ~BGEZFlag();

    void accept(Visitor &) const;
  };

  inline
  BGEZFlag::~BGEZFlag()
  {}

  class BLZFlag : public AbcGenericFlag
  {
  public:
    BLZFlag();
    BLZFlag(const BLZFlag &rhs);
    BLZFlag& operator=(const BLZFlag &rhs);
    ~BLZFlag();

    void accept(Visitor &) const;
  };

  inline
  BLZFlag::~BLZFlag()
  {}

  class BNZFlag : public AbcGenericFlag
  {
  public:
    BNZFlag();
    BNZFlag(const BNZFlag &rhs);
    BNZFlag& operator=(const BNZFlag &rhs);
    ~BNZFlag();

    void accept(Visitor &) const;
  };

  inline
  BNZFlag::~BNZFlag()
  {}

  class BLEZFlag : public AbcGenericFlag
  {
  public:
    BLEZFlag();
    BLEZFlag(const BLEZFlag &rhs);
    BLEZFlag& operator=(const BLEZFlag &rhs);
    ~BLEZFlag();

    void accept(Visitor &) const;
  };

  inline
  BLEZFlag::~BLEZFlag()
  {}

  class BALBFlag : public AbcCompareFlag
  {
  public:
    BALBFlag();
    BALBFlag(const BALBFlag &rhs);
    BALBFlag& operator=(const BALBFlag &rhs);
    ~BALBFlag();

    Abc_Compare_t getABCFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  BALBFlag::~BALBFlag()
  {}

  class BAEBFlag : public AbcCompareFlag
  {
  public:
    BAEBFlag();
    BAEBFlag(const BAEBFlag &rhs);
    BAEBFlag& operator=(const BAEBFlag &rhs);
    ~BAEBFlag();

    Abc_Compare_t getABCFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  BAEBFlag::~BAEBFlag()
  {}

  class BAGBFlag : public AbcCompareFlag
  {
  public:
    BAGBFlag();
    BAGBFlag(const BAGBFlag &rhs);
    BAGBFlag& operator=(const BAGBFlag &rhs);
    ~BAGBFlag();

    Abc_Compare_t getABCFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  BAGBFlag::~BAGBFlag()
  {}

  class BANEBFlag : public AbcCompareFlag
  {
  public:
    BANEBFlag();
    BANEBFlag(const BANEBFlag &rhs);
    BANEBFlag& operator=(const BANEBFlag &rhs);
    ~BANEBFlag();

    Abc_Compare_t getABCFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  BANEBFlag::~BANEBFlag()
  {}

  class BAGEBFlag : public AbcCompareFlag
  {
  public:
    BAGEBFlag();
    BAGEBFlag(const BAGEBFlag &rhs);
    BAGEBFlag& operator=(const BAGEBFlag &rhs);
    ~BAGEBFlag();

    Abc_Compare_t getABCFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  BAGEBFlag::~BAGEBFlag()
  {}

  class BALEBFlag : public AbcCompareFlag
  {
  public:
    BALEBFlag();
    BALEBFlag(const BALEBFlag &rhs);
    BALEBFlag& operator=(const BALEBFlag &rhs);
    ~BALEBFlag();

    Abc_Compare_t getABCFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  BALEBFlag::~BALEBFlag()
  {}

  class EssFlag : public OctaveFlag
  {
  public:

    enum ESS_Flag_t { ESS0=0,  ESS1,  ESS2,  ESS3,  ESS4,  ESS5,  ESS6,  ESS7,  ESS8,  ESS9, 
		      ESS10, ESS11, ESS12, ESS13, ESS14, ESS15, ESS16, ESS17, ESS18, ESS19, 
		      ESS20, ESS21, ESS22, ESS23, ESS24, ESS25, ESS26, ESS27, ESS28, ESS29, 
		      ESS30, ESS31 };
		      
    virtual ~EssFlag() = 0;
    bool isNegated() const;
    virtual ESS_Flag_t getFlagNum() const=0;

  protected:
    EssFlag(bool negate);
    EssFlag(const EssFlag &rhs);
    EssFlag& operator=(const EssFlag &rhs);

  private:
    bool equalTo(const LlirOperand &rhs) const;
    bool m_negate;
  };

  inline
  EssFlag::~EssFlag()
  {}
  
  class Ess0Flag : public EssFlag
  {
  public:
    Ess0Flag(bool negate);
    Ess0Flag(const Ess0Flag &rhs);
    Ess0Flag& operator=(const Ess0Flag &rhs);
    ~Ess0Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess0Flag::~Ess0Flag()
  {}



  class Ess1Flag : public EssFlag
  {
  public:
    Ess1Flag(bool negate);
    Ess1Flag(const Ess1Flag &rhs);
    Ess1Flag& operator=(const Ess1Flag &rhs);
    ~Ess1Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess1Flag::~Ess1Flag()
  {}

  class Ess2Flag : public EssFlag
  {
  public:
    Ess2Flag(bool negate);
    Ess2Flag(const Ess2Flag &rhs);
    Ess2Flag& operator=(const Ess2Flag &rhs);
    ~Ess2Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess2Flag::~Ess2Flag()
  {}

  class Ess3Flag : public EssFlag
  {
  public:
    Ess3Flag(bool negate);
    Ess3Flag(const Ess3Flag &rhs);
    Ess3Flag& operator=(const Ess3Flag &rhs);
    ~Ess3Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess3Flag::~Ess3Flag()
  {}

  class Ess4Flag : public EssFlag
  {
  public:
    Ess4Flag(bool negate);
    Ess4Flag(const Ess4Flag &rhs);
    Ess4Flag& operator=(const Ess4Flag &rhs);
    ~Ess4Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess4Flag::~Ess4Flag()
  {}

  class Ess5Flag : public EssFlag
  {
  public:
    Ess5Flag(bool negate);
    Ess5Flag(const Ess5Flag &rhs);
    Ess5Flag& operator=(const Ess5Flag &rhs);
    ~Ess5Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess5Flag::~Ess5Flag()
  {}

  class Ess6Flag : public EssFlag
  {
  public:
    Ess6Flag(bool negate);
    Ess6Flag(const Ess6Flag &rhs);
    Ess6Flag& operator=(const Ess6Flag &rhs);
    ~Ess6Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess6Flag::~Ess6Flag()
  {}

  class Ess7Flag : public EssFlag
  {
  public:
    Ess7Flag(bool negate);
    Ess7Flag(const Ess7Flag &rhs);
    Ess7Flag& operator=(const Ess7Flag &rhs);
    ~Ess7Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess7Flag::~Ess7Flag()
  {}

  class Ess8Flag : public EssFlag
  {
  public:
    Ess8Flag(bool negate);
    Ess8Flag(const Ess8Flag &rhs);
    Ess8Flag& operator=(const Ess8Flag &rhs);
    ~Ess8Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess8Flag::~Ess8Flag()
  {}

  class Ess9Flag : public EssFlag
  {
  public:
    Ess9Flag(bool negate);
    Ess9Flag(const Ess9Flag &rhs);
    Ess9Flag& operator=(const Ess9Flag &rhs);
    ~Ess9Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess9Flag::~Ess9Flag()
  {}

  class Ess10Flag : public EssFlag
  {
  public:
    Ess10Flag(bool negate);
    Ess10Flag(const Ess10Flag &rhs);
    Ess10Flag& operator=(const Ess10Flag &rhs);
    ~Ess10Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess10Flag::~Ess10Flag()
  {}

  class Ess11Flag : public EssFlag
  {
  public:
    Ess11Flag(bool negate);
    Ess11Flag(const Ess11Flag &rhs);
    Ess11Flag& operator=(const Ess11Flag &rhs);
    ~Ess11Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess11Flag::~Ess11Flag()
  {}

  class Ess12Flag : public EssFlag
  {
  public:
    Ess12Flag(bool negate);
    Ess12Flag(const Ess12Flag &rhs);
    Ess12Flag& operator=(const Ess12Flag &rhs);
    ~Ess12Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess12Flag::~Ess12Flag()
  {}

  class Ess13Flag : public EssFlag
  {
  public:
    Ess13Flag(bool negate);
    Ess13Flag(const Ess13Flag &rhs);
    Ess13Flag& operator=(const Ess13Flag &rhs);
    ~Ess13Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess13Flag::~Ess13Flag()
  {}

  class Ess14Flag : public EssFlag
  {
  public:
    Ess14Flag(bool negate);
    Ess14Flag(const Ess14Flag &rhs);
    Ess14Flag& operator=(const Ess14Flag &rhs);
    ~Ess14Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess14Flag::~Ess14Flag()
  {}

  class Ess15Flag : public EssFlag
  {
  public:
    Ess15Flag(bool negate);
    Ess15Flag(const Ess15Flag &rhs);
    Ess15Flag& operator=(const Ess15Flag &rhs);
    ~Ess15Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess15Flag::~Ess15Flag()
  {}

  class Ess16Flag : public EssFlag
  {
  public:
    Ess16Flag(bool negate);
    Ess16Flag(const Ess16Flag &rhs);
    Ess16Flag& operator=(const Ess16Flag &rhs);
    ~Ess16Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess16Flag::~Ess16Flag()
  {}

  class Ess17Flag : public EssFlag
  {
  public:
    Ess17Flag(bool negate);
    Ess17Flag(const Ess17Flag &rhs);
    Ess17Flag& operator=(const Ess17Flag &rhs);
    ~Ess17Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess17Flag::~Ess17Flag()
  {}

  class Ess18Flag : public EssFlag
  {
  public:
    Ess18Flag(bool negate);
    Ess18Flag(const Ess18Flag &rhs);
    Ess18Flag& operator=(const Ess18Flag &rhs);
    ~Ess18Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess18Flag::~Ess18Flag()
  {}

  class Ess19Flag : public EssFlag
  {
  public:
    Ess19Flag(bool negate);
    Ess19Flag(const Ess19Flag &rhs);
    Ess19Flag& operator=(const Ess19Flag &rhs);
    ~Ess19Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess19Flag::~Ess19Flag()
  {}

  class Ess20Flag : public EssFlag
  {
  public:
    Ess20Flag(bool negate);
    Ess20Flag(const Ess20Flag &rhs);
    Ess20Flag& operator=(const Ess20Flag &rhs);
    ~Ess20Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess20Flag::~Ess20Flag()
  {}

  class Ess21Flag : public EssFlag
  {
  public:
    Ess21Flag(bool negate);
    Ess21Flag(const Ess21Flag &rhs);
    Ess21Flag& operator=(const Ess21Flag &rhs);
    ~Ess21Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess21Flag::~Ess21Flag()
  {}

  class Ess22Flag : public EssFlag
  {
  public:
    Ess22Flag(bool negate);
    Ess22Flag(const Ess22Flag &rhs);
    Ess22Flag& operator=(const Ess22Flag &rhs);
    ~Ess22Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess22Flag::~Ess22Flag()
  {}

  class Ess23Flag : public EssFlag
  {
  public:
    Ess23Flag(bool negate);
    Ess23Flag(const Ess23Flag &rhs);
    Ess23Flag& operator=(const Ess23Flag &rhs);
    ~Ess23Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess23Flag::~Ess23Flag()
  {}

  class Ess24Flag : public EssFlag
  {
  public:
    Ess24Flag(bool negate);
    Ess24Flag(const Ess24Flag &rhs);
    Ess24Flag& operator=(const Ess24Flag &rhs);
    ~Ess24Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess24Flag::~Ess24Flag()
  {}

  class Ess25Flag : public EssFlag
  {
  public:
    Ess25Flag(bool negate);
    Ess25Flag(const Ess25Flag &rhs);
    Ess25Flag& operator=(const Ess25Flag &rhs);
    ~Ess25Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess25Flag::~Ess25Flag()
  {}

  class Ess26Flag : public EssFlag
  {
  public:
    Ess26Flag(bool negate);
    Ess26Flag(const Ess26Flag &rhs);
    Ess26Flag& operator=(const Ess26Flag &rhs);
    ~Ess26Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess26Flag::~Ess26Flag()
  {}

  class Ess27Flag : public EssFlag
  {
  public:
    Ess27Flag(bool negate);
    Ess27Flag(const Ess27Flag &rhs);
    Ess27Flag& operator=(const Ess27Flag &rhs);
    ~Ess27Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess27Flag::~Ess27Flag()
  {}

  class Ess28Flag : public EssFlag
  {
  public:
    Ess28Flag(bool negate);
    Ess28Flag(const Ess28Flag &rhs);
    Ess28Flag& operator=(const Ess28Flag &rhs);
    ~Ess28Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess28Flag::~Ess28Flag()
  {}

  class Ess29Flag : public EssFlag
  {
  public:
    Ess29Flag(bool negate);
    Ess29Flag(const Ess29Flag &rhs);
    Ess29Flag& operator=(const Ess29Flag &rhs);
    ~Ess29Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess29Flag::~Ess29Flag()
  {}

  class Ess30Flag : public EssFlag
  {
  public:
    Ess30Flag(bool negate);
    Ess30Flag(const Ess30Flag &rhs);
    Ess30Flag& operator=(const Ess30Flag &rhs);
    ~Ess30Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess30Flag::~Ess30Flag()
  {}

  class Ess31Flag : public EssFlag
  {
  public:
    Ess31Flag(bool negate);
    Ess31Flag(const Ess31Flag &rhs);
    Ess31Flag& operator=(const Ess31Flag &rhs);
    ~Ess31Flag();

    ESS_Flag_t getFlagNum() const;
    void accept(Visitor &) const;
  };

  inline
  Ess31Flag::~Ess31Flag()
  {}

  class MvhFlag : public OctaveFlag
  {
  public:
    virtual ~MvhFlag();

    enum CN_Flag { C0=1,C1,C2,C3,C4,
		   C5,C6,C7,C8,C9,C10,
		   C11,C12,C13,C14,C15};

    virtual CN_Flag getCNValue() const =0;
		   
  protected:
    MvhFlag();
    MvhFlag(const MvhFlag &rhs);
    MvhFlag& operator=(const MvhFlag &rhs);

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  MvhFlag::~MvhFlag()
  {}

  class C0Flag : public MvhFlag
  {
  public:
    C0Flag();
    C0Flag(const C0Flag &rhs);
    C0Flag& operator=(const C0Flag &rhs);
    ~C0Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C0Flag::~C0Flag()
  {}

  class C1Flag : public MvhFlag
  {
  public:
    C1Flag();
    C1Flag(const C1Flag &rhs);
    C1Flag& operator=(const C1Flag &rhs);
    ~C1Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C1Flag::~C1Flag()
  {}


  class C2Flag : public MvhFlag
  {
  public:
    C2Flag();
    C2Flag(const C2Flag &rhs);
    C2Flag& operator=(const C2Flag &rhs);
    ~C2Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C2Flag::~C2Flag()
  {}


  class C3Flag : public MvhFlag
  {
  public:
    C3Flag();
    C3Flag(const C3Flag &rhs);
    C3Flag& operator=(const C3Flag &rhs);
    ~C3Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C3Flag::~C3Flag()
  {}


  class C4Flag : public MvhFlag
  {
  public:
    C4Flag();
    C4Flag(const C4Flag &rhs);
    C4Flag& operator=(const C4Flag &rhs);
    ~C4Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C4Flag::~C4Flag()
  {}


  class C5Flag : public MvhFlag
  {
  public:
    C5Flag();
    C5Flag(const C5Flag &rhs);
    C5Flag& operator=(const C5Flag &rhs);
    ~C5Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C5Flag::~C5Flag()
  {}


  class C6Flag : public MvhFlag
  {
  public:
    C6Flag();
    C6Flag(const C6Flag &rhs);
    C6Flag& operator=(const C6Flag &rhs);
    ~C6Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C6Flag::~C6Flag()
  {}


  class C7Flag : public MvhFlag
  {
  public:
    C7Flag();
    C7Flag(const C7Flag &rhs);
    C7Flag& operator=(const C7Flag &rhs);
    ~C7Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C7Flag::~C7Flag()
  {}


  class C8Flag : public MvhFlag
  {
  public:
    C8Flag();
    C8Flag(const C8Flag &rhs);
    C8Flag& operator=(const C8Flag &rhs);
    ~C8Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C8Flag::~C8Flag()
  {}


  class C9Flag : public MvhFlag
  {
  public:
    C9Flag();
    C9Flag(const C9Flag &rhs);
    C9Flag& operator=(const C9Flag &rhs);
    ~C9Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C9Flag::~C9Flag()
  {}


  class C10Flag : public MvhFlag
  {
  public:
    C10Flag();
    C10Flag(const C10Flag &rhs);
    C10Flag& operator=(const C10Flag &rhs);
    ~C10Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C10Flag::~C10Flag()
  {}


  class C11Flag : public MvhFlag
  {
  public:
    C11Flag();
    C11Flag(const C11Flag &rhs);
    C11Flag& operator=(const C11Flag &rhs);
    ~C11Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C11Flag::~C11Flag()
  {}


  class C12Flag : public MvhFlag
  {
  public:
    C12Flag();
    C12Flag(const C12Flag &rhs);
    C12Flag& operator=(const C12Flag &rhs);
    ~C12Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C12Flag::~C12Flag()
  {}


  class C13Flag : public MvhFlag
  {
  public:
    C13Flag();
    C13Flag(const C13Flag &rhs);
    C13Flag& operator=(const C13Flag &rhs);
    ~C13Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C13Flag::~C13Flag()
  {}


  class C14Flag : public MvhFlag
  {
  public:
    C14Flag();
    C14Flag(const C14Flag &rhs);
    C14Flag& operator=(const C14Flag &rhs);
    ~C14Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C14Flag::~C14Flag()
  {}


  class C15Flag : public MvhFlag
  {
  public:
    C15Flag();
    C15Flag(const C15Flag &rhs);
    C15Flag& operator=(const C15Flag &rhs);
    ~C15Flag();

    CN_Flag getCNValue() const;
    void accept(Visitor &) const;
  };

  inline
  C15Flag::~C15Flag()
  {}

  class SXFlag : public OctaveFlag
  {
  public:
    SXFlag();
    SXFlag(const SXFlag &rhs);
    SXFlag& operator=(const SXFlag &rhs);
    virtual ~SXFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  SXFlag::~SXFlag()
  {}

  class FindFlag : public OctaveFlag
  {
  public:
    FindFlag();
    FindFlag(const FindFlag &rhs);
    FindFlag& operator=(const FindFlag &rhs);
    virtual ~FindFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  FindFlag::~FindFlag()
  {}

  class CumeFlag : public OctaveFlag
  {
  public:
    CumeFlag();
    CumeFlag(const CumeFlag &rhs);
    CumeFlag& operator=(const CumeFlag &rhs);
    virtual ~CumeFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  CumeFlag::~CumeFlag()
  {}

  class SignFlag : public OctaveFlag
  {
  public:
    SignFlag();
    SignFlag(const SignFlag &rhs);
    SignFlag& operator=(const SignFlag &rhs);
    virtual ~SignFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  SignFlag::~SignFlag()
  {}

  class CDFlag : public OctaveFlag
  {
  public:
    CDFlag();
    CDFlag(const CDFlag &rhs);
    CDFlag& operator=(const CDFlag &rhs);
    virtual ~CDFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  CDFlag::~CDFlag()
  {}

  class DepbFlag : public OctaveFlag
  {
  public:
    DepbFlag();
    DepbFlag(const DepbFlag &rhs);
    DepbFlag& operator=(const DepbFlag &rhs);
    virtual ~DepbFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  DepbFlag::~DepbFlag()
  {}

  class DIFlag : public OctaveFlag
  {
  public:
    DIFlag();
    DIFlag(const DIFlag &rhs);
    DIFlag& operator=(const DIFlag &rhs);
    virtual ~DIFlag();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  DIFlag::~DIFlag()
  {}

  class LinkFlag : public OctaveFlag
  {
  public:
    enum Link_Flag_t { NOLINK=0, LNK1=1, LNK2, LNK3, CLEARLINK };

    LinkFlag();
    LinkFlag(const LinkFlag &rhs);
    LinkFlag& operator=(const LinkFlag &rhs);
    virtual ~LinkFlag() = 0;

    virtual Link_Flag_t getLinkFlagType() const =0;
  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  LinkFlag::~LinkFlag()
  {}

  class LNK1Flag : public LinkFlag
  {
  public:
    LNK1Flag();
    LNK1Flag(const LNK1Flag &rhs);
    LNK1Flag& operator=(const LNK1Flag &rhs);
    virtual ~LNK1Flag();

    Link_Flag_t getLinkFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  LNK1Flag::~LNK1Flag()
  {}

  class LNK2Flag : public LinkFlag
  {
  public:
    LNK2Flag();
    LNK2Flag(const LNK2Flag &rhs);
    LNK2Flag& operator=(const LNK2Flag &rhs);
    virtual ~LNK2Flag();

    Link_Flag_t getLinkFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  LNK2Flag::~LNK2Flag()
  {}
  
  class LNK3Flag : public LinkFlag
  {
  public:
    LNK3Flag();
    LNK3Flag(const LNK3Flag &rhs);
    LNK3Flag& operator=(const LNK3Flag &rhs);
    virtual ~LNK3Flag();

    Link_Flag_t getLinkFlagType() const;
    void accept(Visitor &) const;
  };

  inline
  LNK3Flag::~LNK3Flag()
  {}

  class TSSFlag : public OctaveFlag
  {
  public:
    TSSFlag();
    TSSFlag(const TSSFlag &rhs);
    TSSFlag& operator=(const TSSFlag &rhs);
    virtual ~TSSFlag() = 0;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  TSSFlag::~TSSFlag()
  {}

  class GC1AFlag : public TSSFlag
  {
  public:
    GC1AFlag();
    GC1AFlag(const GC1AFlag &rhs);
    GC1AFlag& operator=(const GC1AFlag &rhs);
    virtual ~GC1AFlag();

    void accept(Visitor &) const;
  };

  inline
  GC1AFlag::~GC1AFlag()
  {}

  class GC1BFlag : public TSSFlag
  {
  public:
    GC1BFlag();
    GC1BFlag(const GC1BFlag &rhs);
    GC1BFlag& operator=(const GC1BFlag &rhs);
    virtual ~GC1BFlag();

    void accept(Visitor &) const;
  };

  inline
  GC1BFlag::~GC1BFlag()
  {}


  class GC1OFlag : public TSSFlag
  {
  public:
    GC1OFlag();
    GC1OFlag(const GC1OFlag &rhs);
    GC1OFlag& operator=(const GC1OFlag &rhs);
    virtual ~GC1OFlag();

    void accept(Visitor &) const;
  };

  inline
  GC1OFlag::~GC1OFlag()
  {}


  class GC2AFlag : public TSSFlag
  {
  public:
    GC2AFlag();
    GC2AFlag(const GC2AFlag &rhs);
    GC2AFlag& operator=(const GC2AFlag &rhs);
    virtual ~GC2AFlag();

    void accept(Visitor &) const;
  };

  inline
  GC2AFlag::~GC2AFlag()
  {}


  class GC2BFlag : public TSSFlag
  {
  public:
    GC2BFlag();
    GC2BFlag(const GC2BFlag &rhs);
    GC2BFlag& operator=(const GC2BFlag &rhs);
    virtual ~GC2BFlag();

    void accept(Visitor &) const;
  };

  inline
  GC2BFlag::~GC2BFlag()
  {}


  class GC2OFlag : public TSSFlag
  {
  public:
    GC2OFlag();
    GC2OFlag(const GC2OFlag &rhs);
    GC2OFlag& operator=(const GC2OFlag &rhs);
    virtual ~GC2OFlag();

    void accept(Visitor &) const;
  };

  inline
  GC2OFlag::~GC2OFlag()
  {}


  class GPAFlag : public TSSFlag
  {
  public:
    GPAFlag();
    GPAFlag(const GPAFlag &rhs);
    GPAFlag& operator=(const GPAFlag &rhs);
    virtual ~GPAFlag();

    void accept(Visitor &) const;
  };

  inline
  GPAFlag::~GPAFlag()
  {}


  class GPUFlag : public TSSFlag
  {
  public:
    GPUFlag();
    GPUFlag(const GPUFlag &rhs);
    GPUFlag& operator=(const GPUFlag &rhs);
    virtual ~GPUFlag();

    void accept(Visitor &) const;
  };

  inline
  GPUFlag::~GPUFlag()
  {}


  class GPBFlag : public TSSFlag
  {
  public:
    GPBFlag();
    GPBFlag(const GPBFlag &rhs);
    GPBFlag& operator=(const GPBFlag &rhs);
    virtual ~GPBFlag();

    void accept(Visitor &) const;
  };

  inline
  GPBFlag::~GPBFlag()
  {}


  class GTAFlag : public TSSFlag
  {
  public:
    GTAFlag();
    GTAFlag(const GTAFlag &rhs);
    GTAFlag& operator=(const GTAFlag &rhs);
    virtual ~GTAFlag();

    void accept(Visitor &) const;
  };

  inline
  GTAFlag::~GTAFlag()
  {}


  class GTOFlag : public TSSFlag
  {
  public:
    GTOFlag();
    GTOFlag(const GTOFlag &rhs);
    GTOFlag& operator=(const GTOFlag &rhs);
    virtual ~GTOFlag();

    void accept(Visitor &) const;
  };

  inline
  GTOFlag::~GTOFlag()
  {}


  class GTBFlag : public TSSFlag
  {
  public:
    GTBFlag();
    GTBFlag(const GTBFlag &rhs);
    GTBFlag& operator=(const GTBFlag &rhs);
    virtual ~GTBFlag();

    void accept(Visitor &) const;
  };

  inline
  GTBFlag::~GTBFlag()
  {}


  class GSTICKFlag : public TSSFlag
  {
  public:
    GSTICKFlag();
    GSTICKFlag(const GSTICKFlag &rhs);
    GSTICKFlag& operator=(const GSTICKFlag &rhs);
    virtual ~GSTICKFlag();

    void accept(Visitor &) const;
  };

  inline
  GSTICKFlag::~GSTICKFlag()
  {}


  class FPFlag : public TSSFlag
  {
  public:
    FPFlag();
    FPFlag(const FPFlag &rhs);
    FPFlag& operator=(const FPFlag &rhs);
    virtual ~FPFlag();

    void accept(Visitor &) const;
  };

  inline
  FPFlag::~FPFlag()
  {}

  class NULFlag : public TSSFlag
  {
  public:
    NULFlag();
    NULFlag(const NULFlag &rhs);
    NULFlag& operator=(const NULFlag &rhs);
    virtual ~NULFlag();

    void accept(Visitor &) const;
  };

  inline
  NULFlag::~NULFlag()
  {}

  class NG2Flag : public TSSFlag
  {
  public:
    NG2Flag();
    NG2Flag(const NG2Flag &rhs);
    NG2Flag& operator=(const NG2Flag &rhs);
    virtual ~NG2Flag();

    void accept(Visitor &) const;
  };

  inline
  NG2Flag::~NG2Flag()
  {}


  class GZFlag : public TSSFlag
  {
  public:
    GZFlag();
    GZFlag(const GZFlag &rhs);
    GZFlag& operator=(const GZFlag &rhs);
    virtual ~GZFlag();

    void accept(Visitor &) const;
  };

  inline
  GZFlag::~GZFlag()
  {}


  class OAMFlag : public TSSFlag
  {
  public:
    OAMFlag();
    OAMFlag(const OAMFlag &rhs);
    OAMFlag& operator=(const OAMFlag &rhs);
    virtual ~OAMFlag();

    void accept(Visitor &) const;
  };

  inline
  OAMFlag::~OAMFlag()
  {}


  class RPFlag : public TSSFlag
  {
  public:
    RPFlag();
    RPFlag(const RPFlag &rhs);
    RPFlag& operator=(const RPFlag &rhs);
    virtual ~RPFlag();

    void accept(Visitor &) const;
  };

  inline
  RPFlag::~RPFlag()
  {}


  class LOGFlag : public TSSFlag
  {
  public:
    LOGFlag();
    LOGFlag(const LOGFlag &rhs);
    LOGFlag& operator=(const LOGFlag &rhs);
    virtual ~LOGFlag();

    void accept(Visitor &) const;
  };

  inline
  LOGFlag::~LOGFlag()
  {}


  class FPBFlag : public TSSFlag
  {
  public:
    FPBFlag();
    FPBFlag(const FPBFlag &rhs);
    FPBFlag& operator=(const FPBFlag &rhs);
    virtual ~FPBFlag();

    void accept(Visitor &) const;
  };

  inline
  FPBFlag::~FPBFlag()
  {}


  class CSBFlag : public TSSFlag
  {
  public:
    CSBFlag();
    CSBFlag(const CSBFlag &rhs);
    CSBFlag& operator=(const CSBFlag &rhs);
    virtual ~CSBFlag();

    void accept(Visitor &) const;
  };

  inline
  CSBFlag::~CSBFlag()
  {}


  class DELETEFlag : public TSSFlag
  {
  public:
    DELETEFlag();
    DELETEFlag(const DELETEFlag &rhs);
    DELETEFlag& operator=(const DELETEFlag &rhs);
    virtual ~DELETEFlag();

    void accept(Visitor &) const;
  };

  inline
  DELETEFlag::~DELETEFlag()
  {}


  class NBFlag : public TSSFlag
  {
  public:
    NBFlag();
    NBFlag(const NBFlag &rhs);
    NBFlag& operator=(const NBFlag &rhs);
    virtual ~NBFlag();

    void accept(Visitor &) const;
  };

  inline
  NBFlag::~NBFlag()
  {}


  class NCFlag : public TSSFlag
  {
  public:
    NCFlag();
    NCFlag(const NCFlag &rhs);
    NCFlag& operator=(const NCFlag &rhs);
    virtual ~NCFlag();

    void accept(Visitor &) const;
  };

  inline
  NCFlag::~NCFlag()
  {}


  class GWFlag : public TSSFlag
  {
  public:
    GWFlag();
    GWFlag(const GWFlag &rhs);
    GWFlag& operator=(const GWFlag &rhs);
    virtual ~GWFlag();

    void accept(Visitor &) const;
  };

  inline
  GWFlag::~GWFlag()
  {}


  class GRFlag : public TSSFlag
  {
  public:
    GRFlag();
    GRFlag(const GRFlag &rhs);
    GRFlag& operator=(const GRFlag &rhs);
    virtual ~GRFlag();

    void accept(Visitor &) const;
  };

  inline
  GRFlag::~GRFlag()
  {}


  class AFlag : public TSSFlag
  {
  public:
    AFlag();
    AFlag(const AFlag &rhs);
    AFlag& operator=(const AFlag &rhs);
    virtual ~AFlag();

    void accept(Visitor &) const;
  };

  inline
  AFlag::~AFlag()
  {}


  class RFlag : public TSSFlag
  {
  public:
    RFlag();
    RFlag(const RFlag &rhs);
    RFlag& operator=(const RFlag &rhs);
    virtual ~RFlag();

    void accept(Visitor &) const;
  };

  inline
  RFlag::~RFlag()
  {}


  class GUFlag : public TSSFlag
  {
  public:
    GUFlag();
    GUFlag(const GUFlag &rhs);
    GUFlag& operator=(const GUFlag &rhs);
    virtual ~GUFlag();

    void accept(Visitor &) const;
  };

  inline
  GUFlag::~GUFlag()
  {}


  class TFlag : public TSSFlag
  {
  public:
    TFlag();
    TFlag(const TFlag &rhs);
    TFlag& operator=(const TFlag &rhs);
    virtual ~TFlag();

    void accept(Visitor &) const;
  };

  inline
  TFlag::~TFlag()
  {}


  class RBFlag : public TSSFlag
  {
  public:
    RBFlag();
    RBFlag(const RBFlag &rhs);
    RBFlag& operator=(const RBFlag &rhs);
    virtual ~RBFlag();

    void accept(Visitor &) const;
  };

  inline
  RBFlag::~RBFlag()
  {}


  class FBFlag : public TSSFlag
  {
  public:
    FBFlag();
    FBFlag(const FBFlag &rhs);
    FBFlag& operator=(const FBFlag &rhs);
    virtual ~FBFlag();

    void accept(Visitor &) const;
  };

  inline
  FBFlag::~FBFlag()
  {}


  class SFlag : public TSSFlag
  {
  public:
    SFlag();
    SFlag(const SFlag &rhs);
    SFlag& operator=(const SFlag &rhs);
    virtual ~SFlag();

    void accept(Visitor &) const;
  };

  inline
  SFlag::~SFlag()
  {}


  class NTFlag : public TSSFlag
  {
  public:
    NTFlag();
    NTFlag(const NTFlag &rhs);
    NTFlag& operator=(const NTFlag &rhs);
    virtual ~NTFlag();

    void accept(Visitor &) const;
  };

  inline
  NTFlag::~NTFlag()
  {}


  class RSCHFlag : public TSSFlag
  {
  public:
    RSCHFlag();
    RSCHFlag(const RSCHFlag &rhs);
    RSCHFlag& operator=(const RSCHFlag &rhs);
    virtual ~RSCHFlag();

    void accept(Visitor &) const;
  };

  inline
  RSCHFlag::~RSCHFlag()
  {}

  class IFlag : public TSSFlag
  {
  public:
    IFlag();
    IFlag(const IFlag &rhs);
    IFlag& operator=(const IFlag &rhs);
    virtual ~IFlag();

    void accept(Visitor &) const;
  };

  inline
  IFlag::~IFlag()
  {}

  class FRFlag : public TSSFlag
  {
  public:
    FRFlag();
    FRFlag(const FRFlag &rhs);
    FRFlag& operator=(const FRFlag &rhs);
    virtual ~FRFlag();

    void accept(Visitor &) const;
  };

  inline
  FRFlag::~FRFlag()
  {}

  class CLOSEFlag : public TSSFlag
  {
  public:
    CLOSEFlag();
    CLOSEFlag(const CLOSEFlag &rhs);
    CLOSEFlag& operator=(const CLOSEFlag &rhs);
    virtual ~CLOSEFlag();

    void accept(Visitor &) const;
  };

  inline
  CLOSEFlag::~CLOSEFlag()
  {}

  class NEFlag : public TSSFlag
  {
  public:
    NEFlag();
    NEFlag(const NEFlag &rhs);
    NEFlag& operator=(const NEFlag &rhs);
    virtual ~NEFlag();

    void accept(Visitor &) const;
  };

  inline
  NEFlag::~NEFlag()
  {}

  class CbranchFlag : public OctaveFlag
  {
  public:
    CbranchFlag();
    CbranchFlag(const CbranchFlag &rhs);
    CbranchFlag& operator=(const CbranchFlag &rhs);
    virtual ~CbranchFlag();

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  CbranchFlag::~CbranchFlag()
  {}

  class CFlag : public CbranchFlag
  {
  public:
    CFlag();
    CFlag(const CFlag &rhs);
    CFlag& operator=(const CFlag &rhs);
    virtual ~CFlag();

    void accept(Visitor &) const;
  };

  inline
  CFlag::~CFlag()
  {}

  class BFFlag : public CbranchFlag
  {
  public:
    BFFlag();
    BFFlag(const BFFlag &rhs);
    BFFlag& operator=(const BFFlag &rhs);
    virtual ~BFFlag();

    void accept(Visitor &) const;
  };

  inline
  BFFlag::~BFFlag()
  {}

  class BrslFlag : public OctaveFlag
  {
  public:
    BrslFlag();
    BrslFlag(const BrslFlag &rhs);
    BrslFlag& operator=(const BrslFlag &rhs);
    virtual ~BrslFlag();

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  BrslFlag::~BrslFlag()
  {}

  class UNLNKFlag : public BrslFlag
  {
  public:
    UNLNKFlag();
    UNLNKFlag(const UNLNKFlag &rhs);
    UNLNKFlag& operator=(const UNLNKFlag &rhs);
    virtual ~UNLNKFlag();

    void accept(Visitor &) const;
  };

  inline
  UNLNKFlag::~UNLNKFlag()
  {}

  class PREFlag : public BrslFlag
  {
  public:
    PREFlag();
    PREFlag(const PREFlag &rhs);
    PREFlag& operator=(const PREFlag &rhs);
    virtual ~PREFlag();

    void accept(Visitor &) const;
  };

  inline
  PREFlag::~PREFlag()
  {}

  class DLNKFlag : public BrslFlag
  {
  public:
    DLNKFlag();
    DLNKFlag(const DLNKFlag &rhs);
    DLNKFlag& operator=(const DLNKFlag &rhs);
    virtual ~DLNKFlag();

    void accept(Visitor &) const;
  };

  inline
  DLNKFlag::~DLNKFlag()
  {}

  class FLUSHFlag : public BrslFlag
  {
  public:
    FLUSHFlag();
    FLUSHFlag(const FLUSHFlag &rhs);
    FLUSHFlag& operator=(const FLUSHFlag &rhs);
    virtual ~FLUSHFlag();

    void accept(Visitor &) const;
  };

  inline
  FLUSHFlag::~FLUSHFlag()
  {}

  typedef shared_ptr<BrslFlag> BrslPtr;

  class BrslFlags : public OctaveFlag
  {
  public:
    typedef std::list<BrslPtr>::iterator Iterator;
    typedef std::list<BrslPtr>::const_iterator ConstIterator;

    BrslFlags(BrslPtr);
    BrslFlags(BrslPtr, BrslPtr);
    BrslFlags(BrslPtr, BrslPtr, BrslPtr);
    BrslFlags(BrslPtr, BrslPtr, BrslPtr,BrslPtr);
    BrslFlags(const BrslFlags &rhs);
    BrslFlags& operator=(const BrslFlags &rhs);
    ~BrslFlags();

    void accept(Visitor &) const;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
    int getNumBrslFlags() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    std::list<BrslPtr> m_brslFlags;
  };

  inline
  BrslFlags::~BrslFlags()
  {}

  typedef shared_ptr<CbranchFlag> CbranchPtr;

  class CbranchFlags : public OctaveFlag
  {
  public:
    typedef std::list<CbranchPtr>::iterator Iterator;
    typedef std::list<CbranchPtr>::const_iterator ConstIterator;

    CbranchFlags(CbranchPtr);
    CbranchFlags(CbranchPtr, CbranchPtr);
    CbranchFlags(const CbranchFlags &rhs);
    CbranchFlags& operator=(const CbranchFlags &rhs);
    ~CbranchFlags();

    void accept(Visitor &) const;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    std::list<CbranchPtr> m_cbranchFlags;
  };

  inline
  CbranchFlags::~CbranchFlags()
  {}

  typedef shared_ptr<TSSFlag> TssPtr;

  class TrafficScheduleFlags : public OctaveFlag
  {
  public:
    typedef std::list<TssPtr>::iterator Iterator;
    typedef std::list<TssPtr>::const_iterator ConstIterator;

    ~TrafficScheduleFlags();
    void addFlag(TssPtr);

    void accept(Visitor &) const;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

    TrafficScheduleFlags();
    TrafficScheduleFlags(const TrafficScheduleFlags &);
    TrafficScheduleFlags& operator=(const TrafficScheduleFlags &rhs);
    int getNumTssFlags() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    std::list<TssPtr> m_tssFlags;
  };

  inline
  TrafficScheduleFlags::~TrafficScheduleFlags()
  {}

  class GetFlags : public TrafficScheduleFlags
  {
  public:
    GetFlags();
    ~GetFlags();
    GetFlags(const GetFlags &);
    GetFlags& operator=(const GetFlags &rhs);
    void accept(Visitor &) const;
  private:

  };

  inline
  GetFlags::~GetFlags()
  {}

  class PolFlags : public TrafficScheduleFlags
  {
  public:
    PolFlags();
    ~PolFlags();
    PolFlags(const PolFlags &);
    PolFlags& operator=(const PolFlags &rhs);
    void accept(Visitor &) const;

  private:
  };

  inline
  PolFlags::~PolFlags()
  {}

  class PutFlags : public TrafficScheduleFlags
  {
  public:
    PutFlags();
    ~PutFlags();
    PutFlags(const PutFlags &);
    PutFlags& operator=(const PutFlags &rhs);
    void accept(Visitor &) const;

  private:
  };

  inline
  PutFlags::~PutFlags()
  {}



  class LabelList;
  bool operator==(const LabelList &lhs, const LabelList &rhs);
  bool operator!=(const LabelList &lhs, const LabelList &rhs);



  class LabelList 
    {
    public:

      typedef std::list<shared_ptr<const OpndLabel> >::iterator Iterator;
      typedef std::list<shared_ptr<const OpndLabel> >::const_iterator ConstIterator;

      LabelList();
      ~LabelList();
      LabelList(const LabelList& rhs);
      LabelList& operator=(const LabelList& rhs);
      bool isInList(shared_ptr<const OpndLabel>) const;
      bool isInList(const char* name) const;
      void addLabel(shared_ptr<const OpndLabel>);
      shared_ptr<const OpndLabel> getLabel(unsigned int index) const;
      unsigned int getNumLabels() const;

      Iterator begin();
      Iterator end();
      ConstIterator begin() const;
      ConstIterator end() const;

      void reverse();

      bool equalTo(const LabelList &rhs) const;
      void accept(Visitor &v) const;

    private:
      std::list<shared_ptr<const OpndLabel> > m_labelList;

    };

  class RegList;
  bool operator==(const RegList &lhs, const RegList &rhs);
  bool operator!=(const RegList &lhs, const RegList &rhs);

  class RegList 
    {
    public:

      typedef std::map<unsigned int, shared_ptr<const Register> >::iterator Iterator;
      typedef std::map<unsigned int, shared_ptr<const Register> >::const_iterator ConstIterator;

      RegList();
      RegList(const RegList& rhs);
      ~RegList(); 
      RegList& operator=(const RegList& rhs);
      bool isInList(unsigned int regNum) const;
      void addRegister(shared_ptr<const Register> reg);
      shared_ptr<const Register> getRegister(unsigned int regNum) const;

      bool isEmpty() const;
      bool equal(const RegList &rhs) const;

      Iterator begin(); 
      Iterator end();
      ConstIterator begin() const;
      ConstIterator end() const;

    private:
      std::map<unsigned int, shared_ptr<const Register> > m_regList;
    };


  class RegisterList;
  bool operator==(const RegisterList &lhs, const RegisterList &rhs);
  bool operator!=(const RegisterList &lhs, const RegisterList &rhs);

  class RegisterList 
    {
    public:
      RegisterList(shared_ptr<RegList>);
      virtual ~RegisterList();
      RegisterList(const RegisterList& rhs);
      RegisterList& operator=(const RegisterList& rhs);

      shared_ptr<const RegList> getRegList() const;
      bool isEmpty() const;
      bool isInList(unsigned int regNum) const;

      bool equal(const RegisterList &rhs) const;
      virtual bool equalTo(const RegisterList &rhs) const =0;

    private:

      shared_ptr<RegList> m_regList;
    };




  class GlobalRegisterList : public RegisterList
    {
    public:
      GlobalRegisterList(shared_ptr<RegList>);
      ~GlobalRegisterList();
      GlobalRegisterList(const GlobalRegisterList& rhs);
      GlobalRegisterList& operator=(const GlobalRegisterList& rhs);

      bool equalTo(const RegisterList &rhs) const;
      void accept(Visitor &v) const;

    };



  class ArgList : public RegisterList
    {
    public:
      ArgList(shared_ptr<RegList>);
      ~ArgList();
      ArgList(const ArgList& rhs);
      ArgList& operator=(const ArgList& rhs);

      bool equalTo(const RegisterList &rhs) const;
      void accept(Visitor &v) const;

    };

  class ResultList : public RegisterList
    {
    public:
      ResultList(shared_ptr<RegList>);
      ~ResultList();
      ResultList(const ResultList& rhs);
      ResultList& operator=(const ResultList& rhs);

      bool equalTo(const RegisterList &rhs) const;
      void accept(Visitor &v) const;

    };

  class ScratchList : public RegisterList
    {
    public:
      ScratchList(shared_ptr<RegList>);
      ~ScratchList();
      ScratchList(const ScratchList& rhs);
      ScratchList& operator=(const ScratchList& rhs);

      bool equalTo(const RegisterList &rhs) const;
      void accept(Visitor &v) const;

    };



  class LinkedRegisterList;
  bool operator==(const LinkedRegisterList &lhs, const LinkedRegisterList &rhs);
  bool operator!=(const LinkedRegisterList &lhs, const LinkedRegisterList &rhs);


  class LinkedRegisterList 
    {
    public:
      LinkedRegisterList(shared_ptr<RegList>,
			 shared_ptr<RegList>,
			 shared_ptr<RegList>);
      virtual ~LinkedRegisterList();
      LinkedRegisterList(const LinkedRegisterList& rhs);
      LinkedRegisterList& operator=(const LinkedRegisterList& rhs);

      bool isEmpty() const;
      bool isInList(unsigned int regNum) const;

      shared_ptr<const RegList> getRegListLnk1() const;
      shared_ptr<const RegList> getRegListLnk2() const;
      shared_ptr<const RegList> getRegListLnk3() const;

      bool equal(const LinkedRegisterList &rhs) const;
      virtual bool equalTo(const LinkedRegisterList &rhs) const =0;
      
    private:

      shared_ptr<RegList> m_regList_lnk1;
      shared_ptr<RegList> m_regList_lnk2;
      shared_ptr<RegList> m_regList_lnk3;

    };



  class RegLnksListToSPRAM : public LinkedRegisterList
    {
    public:
      RegLnksListToSPRAM(shared_ptr<RegList>,
			 shared_ptr<RegList>,
			 shared_ptr<RegList>);
      ~RegLnksListToSPRAM();
      RegLnksListToSPRAM(const RegLnksListToSPRAM& rhs);
      RegLnksListToSPRAM& operator=(const RegLnksListToSPRAM& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };

  class RegLnksListToLockedSPRAM : public LinkedRegisterList
    {
    public:
      RegLnksListToLockedSPRAM(shared_ptr<RegList>,
			       shared_ptr<RegList>,
			       shared_ptr<RegList>);
      ~RegLnksListToLockedSPRAM();
      RegLnksListToLockedSPRAM(const RegLnksListToLockedSPRAM& rhs);
      RegLnksListToLockedSPRAM& operator=(const RegLnksListToLockedSPRAM& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };


  class RegLnksListToSRAM : public LinkedRegisterList
    {
    public:
      RegLnksListToSRAM(shared_ptr<RegList>,
			 shared_ptr<RegList>,
			 shared_ptr<RegList>);
      ~RegLnksListToSRAM();
      RegLnksListToSRAM(const RegLnksListToSRAM& rhs);
      RegLnksListToSRAM& operator=(const RegLnksListToSRAM& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };


  class RegLnksListToSDRAM : public LinkedRegisterList
    {
    public:
      RegLnksListToSDRAM(shared_ptr<RegList>,
			 shared_ptr<RegList>,
			 shared_ptr<RegList>);
      ~RegLnksListToSDRAM();
      RegLnksListToSDRAM(const RegLnksListToSDRAM& rhs);
      RegLnksListToSDRAM& operator=(const RegLnksListToSDRAM& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };


  class RegLnksListToCCRAM : public LinkedRegisterList
    {
    public:
      RegLnksListToCCRAM(shared_ptr<RegList>,
			 shared_ptr<RegList>,
			 shared_ptr<RegList>);
      ~RegLnksListToCCRAM();

      RegLnksListToCCRAM(const RegLnksListToCCRAM& rhs);
      RegLnksListToCCRAM& operator=(const RegLnksListToCCRAM& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };


  class RegLnksListToLockedCCRAM : public LinkedRegisterList
    {
    public:
      RegLnksListToLockedCCRAM(shared_ptr<RegList>,
			       shared_ptr<RegList>,
			       shared_ptr<RegList>);
      ~RegLnksListToLockedCCRAM();
      RegLnksListToLockedCCRAM(const RegLnksListToLockedCCRAM& rhs);
      RegLnksListToLockedCCRAM& operator=(const RegLnksListToLockedCCRAM& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };


  class RegLnksListToSIO : public LinkedRegisterList
    {
    public:
      RegLnksListToSIO(shared_ptr<RegList>,
		       shared_ptr<RegList>,
		       shared_ptr<RegList>);
      ~RegLnksListToSIO();

      RegLnksListToSIO(const RegLnksListToSIO& rhs);
      RegLnksListToSIO& operator=(const RegLnksListToSIO& rhs);

      bool equalTo(const LinkedRegisterList &rhs) const;
      void accept(Visitor &v) const;

    };


  class IndirectCallTargetList : public LlirOperand
    {
    public:
      IndirectCallTargetList(shared_ptr<const LabelList> entryLabelList);
      IndirectCallTargetList(const IndirectCallTargetList& rhs);
      IndirectCallTargetList& operator=(const IndirectCallTargetList& rhs);
      ~IndirectCallTargetList();

      shared_ptr<const LabelList> getLabelList() const;

      bool equalTo(const LlirOperand &rhs) const;
      void accept(Visitor& v) const;
      bool isNullOperand() const;

    private:
      shared_ptr<const LabelList> m_FcnEntryPtList;
    };

  inline bool IndirectCallTargetList::isNullOperand() const
    {
      return false;
    }


} // namespace Llir

#endif
