#ifndef _LLIR_OPERAND_H_
#define _LLIR_OPERAND_H_

#include <string>
#include <vector>
#include <list>
#include <boost/shared_ptr.hpp>
using namespace boost;

namespace Llir
{
  class Visitor;
  class LabelSym;



  class LlirOperand
  {
  public:
    virtual ~LlirOperand();

    bool equal(const LlirOperand &rhs) const;
    virtual bool isNullOperand() const = 0;
    virtual void accept(Visitor &) const = 0;

  protected:
    LlirOperand();
    LlirOperand(const LlirOperand &rhs);
    LlirOperand& operator=(const LlirOperand &rhs);
    virtual bool equalTo(const LlirOperand &rhs) const = 0;
  };


  inline LlirOperand::~LlirOperand()
  {}

  inline
  bool operator==(const LlirOperand &lhs, const LlirOperand &rhs)
  {
    return lhs.equal(rhs);
  }

  inline
  bool operator!=(const LlirOperand &lhs, const LlirOperand &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }

  class Register : public LlirOperand
  {
  public:
    Register();
    virtual ~Register();
    Register(const Register &rhs);
    Register& operator=(const Register &rhs);
    virtual unsigned int getRegNum(unsigned int regIndex = 0) const = 0;
    virtual unsigned int getNumRegs() const = 0;
    virtual shared_ptr<const Register> getRegister(unsigned int regNum = 0) const = 0;
    virtual const std::string &getRegName() const = 0;

    virtual bool isPseudo() const = 0;
  };

  inline Register::~Register()
  {}

  bool isPseudoReg(shared_ptr<const Register> reg);
  bool isMultiReg(shared_ptr<const Register> reg);
  bool isNullReg(shared_ptr<const Register> reg);

  class NullRegister : public Register
  {
  public:
    NullRegister();
    virtual ~NullRegister();
    NullRegister(const NullRegister &rhs);
    NullRegister& operator=(const NullRegister &rhs);
    void accept(Visitor &) const;
    bool isNullOperand() const;
    shared_ptr<const Register> getRegister(unsigned int regNum = 0) const;
    const std::string &getRegName() const;
    unsigned int getRegNum(unsigned int regIndex = 0) const;
    unsigned int getNumRegs() const;

    bool isPseudo() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;


  };

  inline NullRegister::~NullRegister()
  {}

  inline bool NullRegister::isPseudo() const
    {
      return false;
    }

  inline bool NullRegister::isNullOperand() const
    {
      return false;
    }

  class SingleRegister : public Register
  {
  public:
    SingleRegister(unsigned int regNum);
    virtual ~SingleRegister();
    SingleRegister(const SingleRegister &rhs);
    SingleRegister& operator=(const SingleRegister &rhs);
    bool isNullOperand() const;
    unsigned int getNumRegs() const;
    unsigned int getRegNum (unsigned int regIndex = 0) const;

  private:
    unsigned int m_regNum;
  };


  inline SingleRegister::~SingleRegister()
  {}

  inline bool SingleRegister::isNullOperand() const
    {
      return false;
    }

  class HardRegister : public SingleRegister
  {
  public:
    HardRegister(unsigned int regNum);
    ~HardRegister();

    HardRegister(const HardRegister &rhs);
    HardRegister& operator=(const HardRegister &rhs);
    void accept(Visitor &) const;
    shared_ptr<const Register> getRegister(unsigned int regNum = 0) const;
    const std::string &getRegName() const;

    virtual bool isPseudo() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline HardRegister::~HardRegister()
  {}

  inline bool HardRegister::isPseudo() const
    {
      return false;
    }


  class PseudoRegister : public SingleRegister
  {
  public:
    PseudoRegister(unsigned int regNum, const char *name);
    ~PseudoRegister();

    PseudoRegister(const PseudoRegister &rhs);
    PseudoRegister& operator=(const PseudoRegister &rhs);

    shared_ptr<const Register> getRegister(unsigned int regNum = 0) const;
    const std::string & getRegName() const;
    void accept(Visitor &) const;

    bool isPseudo() const;

  private:
    std::string m_pseudoRegName;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline PseudoRegister::~PseudoRegister()
  {}

  inline bool PseudoRegister::isPseudo() const
    {
      return true;
    }


  class MultiRegister : public Register
  {
  public:
    virtual ~MultiRegister();
    unsigned int getNumRegs() const;
    unsigned int getFirstRegNum() const;
    bool isNullOperand() const;
	
  protected:
    MultiRegister(unsigned int numReg, unsigned int firstRegNum);
    MultiRegister(const MultiRegister &rhs);
    MultiRegister& operator=(const MultiRegister &rhs);

  private:
    unsigned int m_numRegs;
    unsigned int m_firstRegNum;
  };

  inline MultiRegister::~MultiRegister()
  {}

  inline bool MultiRegister::isNullOperand() const
    {
      return false;
    }

  class MultiHardRegister : public MultiRegister
  {
  public:
    typedef std::vector<shared_ptr<HardRegister> >::iterator Iterator;
    typedef std::vector<shared_ptr<HardRegister> >::const_iterator ConstIterator;

    MultiHardRegister(unsigned int numReg, unsigned int firstRegNum);
    ~MultiHardRegister();
    MultiHardRegister(const MultiHardRegister &rhs);
    MultiHardRegister& operator=(const MultiHardRegister &rhs);

    shared_ptr<const Register> getRegister(unsigned int regNum = 0) const;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
    void accept(Visitor &) const;
    unsigned int getRegNum (unsigned int regIndex = 0) const;
    const std::string &getRegName() const;
    void addRegister(shared_ptr<HardRegister>);

    bool isPseudo() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;

    std::vector<shared_ptr<HardRegister> > m_multiHardRegs; 
  };

  inline MultiHardRegister::~MultiHardRegister()
  {}

  inline bool MultiHardRegister::isPseudo() const
    {
      return false;
    }

  class MultiPseudoRegister : public MultiRegister
  {
  public:
    typedef std::vector<shared_ptr<PseudoRegister> >::iterator Iterator;
    typedef std::vector<shared_ptr<PseudoRegister> >::const_iterator ConstIterator;

    MultiPseudoRegister(const char *name, unsigned int numReg, unsigned int firstRegNum);
    ~MultiPseudoRegister();
    MultiPseudoRegister(const MultiPseudoRegister &rhs);
    MultiPseudoRegister& operator=(const MultiPseudoRegister &rhs);

    shared_ptr<const Register> getRegister(unsigned int regNum = 0) const;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;
    void accept(Visitor &) const;
    unsigned int getRegNum (unsigned int regIndex = 0) const;
    const std::string &getRegName() const;
    void addRegister(shared_ptr<PseudoRegister>);

    bool isPseudo() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;

    std::vector<shared_ptr<PseudoRegister> > m_multiPseudoRegs;
    std::string m_pseudoName;
  };

  inline MultiPseudoRegister::~MultiPseudoRegister()
  {}

  inline bool MultiPseudoRegister::isPseudo() const
    {
      return true;
    }

  class OpndMemory : public LlirOperand
  {
  public:
    virtual ~OpndMemory();
    bool isNullOperand() const;

  protected:
    OpndMemory();
    OpndMemory(const OpndMemory &rhs);
    OpndMemory& operator=(const OpndMemory &rhs);
  };

  inline OpndMemory::~OpndMemory()
  {}

  inline bool OpndMemory::isNullOperand() const
    {
      return false;
    }

  class OpndNull : public LlirOperand
  {
  public:
    OpndNull();
    OpndNull(const OpndNull &rhs);
    OpndNull& operator=(const OpndNull &rhs);
    ~OpndNull();

    bool isNullOperand() const;
    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  OpndNull::~OpndNull()
  {}

  inline bool OpndNull::isNullOperand() const
    {
      return true;
    }

  class LlirExpr : public LlirOperand
  {
  public:
    ~LlirExpr();
    virtual unsigned long getConstantValue() const = 0;
    virtual bool isConstantExpr() const = 0;

    bool isNullOperand() const;

  protected:
    LlirExpr();
    LlirExpr(const LlirExpr &rhs);
    LlirExpr& operator=(const LlirExpr &rhs);
  };

  inline
  LlirExpr::~LlirExpr()
  {}

  inline bool LlirExpr::isNullOperand() const
    {
      return false;
    }

  class UnsignedImmediate : public LlirExpr
  {
  public:
    UnsignedImmediate(unsigned long val, unsigned int numBits = 32);
    UnsignedImmediate(unsigned long val, unsigned long min, 
		      unsigned long max, unsigned int numBits);
    UnsignedImmediate(const UnsignedImmediate &rhs);
    UnsignedImmediate& operator=(const UnsignedImmediate &rhs);

    ~UnsignedImmediate();

    unsigned long getValue() const;
    unsigned long getConstantValue() const;
    unsigned int getNumBits() const;
    unsigned long getMinValue() const;
    unsigned long getMaxValue() const;
    bool isConstantExpr() const;

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    unsigned long m_value;
    unsigned int m_numBits;
    unsigned long m_min;
    unsigned long m_max;
  };

  inline UnsignedImmediate::~UnsignedImmediate()
  {}

  inline bool 
  UnsignedImmediate::isConstantExpr() const
  {
    return true;
  }

  inline unsigned long 
  UnsignedImmediate::getConstantValue() const
  {
    return m_value;
  }

  class SignedImmediate : public LlirExpr
  {
  public:
    SignedImmediate(long val, unsigned int numBits = 32);
    SignedImmediate(long val, long min, long max, unsigned int numBits);
    SignedImmediate(const SignedImmediate &rhs);
    SignedImmediate& operator=(const SignedImmediate &rhs);

    ~SignedImmediate();

    long getValue() const;
    unsigned long getConstantValue() const;
    unsigned int getNumBits() const;
    long getMinValue() const;
    long getMaxValue() const;
    
    void accept(Visitor &) const;
    bool isConstantExpr() const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    long m_value;
    long m_min;
    long m_max;
    unsigned int m_numBits;
  };

  inline SignedImmediate::~SignedImmediate()
  {}

  inline 
  bool SignedImmediate::isConstantExpr() const
  {
    return true;
  }

  inline unsigned long 
  SignedImmediate::getConstantValue() const
  {
    return static_cast<unsigned long>(m_value);
  }

  class OpndLabel : public LlirExpr
  {
  public:
    OpndLabel(const char *label);
    ~OpndLabel();
    OpndLabel(const OpndLabel &rhs);
    OpndLabel& operator=(const OpndLabel &rhs);

    const std::string& getName() const;
    const std::string& getMangledName() const;
    void setMangledName(string name);
    void setCallTarget() const;
    void setBranchTarget() const;
    bool isConstantExpr() const;
    bool isCallTarget() const;
    bool isBranchTarget() const;
    unsigned long getConstantValue() const;

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
    std::string m_label;
    std::string m_mangledLabel;
    mutable bool m_callTarget;
    mutable bool m_branchTarget;
  };

  inline
  OpndLabel::~OpndLabel()
  {}

  inline 
  bool OpndLabel::isConstantExpr() const
  {
    return false;
  }

  class BinaryExpr : public LlirExpr
  {
  public:
    ~BinaryExpr();
    shared_ptr<const LlirOperand> getLeftOpnd() const;
    shared_ptr<const LlirOperand> getRightOpnd() const;
    bool isConstantExpr() const;
    unsigned long getConstantValue() const;

  protected:
    BinaryExpr(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    BinaryExpr(const BinaryExpr &rhs);
    BinaryExpr& operator=(const BinaryExpr &rhs);
      
  private:
    shared_ptr<const LlirOperand> m_op1;
    shared_ptr<const LlirOperand> m_op2;
  };

  inline 
  bool BinaryExpr::isConstantExpr() const
  {
    return false;
  }

  inline
  BinaryExpr::~BinaryExpr()
  {}

  class PlusOp : public BinaryExpr
  {
  public:
    PlusOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    PlusOp(const PlusOp &rhs);
    PlusOp& operator=(const PlusOp &rhs);
    ~PlusOp();

    void accept(Visitor &) const;

  private:
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  PlusOp::~PlusOp()
  {}

  class MinusOp : public BinaryExpr
  {
  public:
    MinusOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    MinusOp(const MinusOp &rhs);
    MinusOp& operator=(const MinusOp &rhs);
    ~MinusOp();
    
    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  MinusOp::~MinusOp()
  {}

  class MultiplyOp : public BinaryExpr
  {
  public:
    MultiplyOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    MultiplyOp(const MultiplyOp &rhs);
    MultiplyOp& operator=(const MultiplyOp &rhs);
    ~MultiplyOp();
    
    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  MultiplyOp::~MultiplyOp()
  {}

  class DivOp : public BinaryExpr
  {
  public:
    DivOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    DivOp(const DivOp &rhs);
    DivOp& operator=(const DivOp &rhs);
    ~DivOp();
    
    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  DivOp::~DivOp()
  {}

  class ModulusOp : public BinaryExpr
  {
  public:
    ModulusOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    ModulusOp(const ModulusOp &rhs);
    ModulusOp& operator=(const ModulusOp &rhs);
    ~ModulusOp();
    
    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  ModulusOp::~ModulusOp()
  {}

  class LeftShiftOp : public BinaryExpr
  {
  public:
    LeftShiftOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    LeftShiftOp(const LeftShiftOp &rhs);
    LeftShiftOp& operator=(const LeftShiftOp &rhs);
    ~LeftShiftOp();
    
    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  LeftShiftOp::~LeftShiftOp()
  {}


  class RightShiftOp : public BinaryExpr
  {
  public:
    RightShiftOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    RightShiftOp(const RightShiftOp &rhs);
    RightShiftOp& operator=(const RightShiftOp &rhs);
    ~RightShiftOp();
    
    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
  RightShiftOp::~RightShiftOp()
  {}


  class BitWiseAndOp  : public BinaryExpr
  {
  public:
    BitWiseAndOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    ~BitWiseAndOp();
    BitWiseAndOp(const BitWiseAndOp &rhs);
    BitWiseAndOp& operator=(const BitWiseAndOp &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
    BitWiseAndOp::~BitWiseAndOp()
    {}

  class BitWiseOrOp  : public BinaryExpr
  {
  public:
    BitWiseOrOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    ~BitWiseOrOp();
    BitWiseOrOp(const BitWiseOrOp &rhs);
    BitWiseOrOp& operator=(const BitWiseOrOp &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
    BitWiseOrOp::~BitWiseOrOp()
    {}

  class BitWiseXorOp  : public BinaryExpr
  {
  public:
    BitWiseXorOp(shared_ptr<const LlirOperand> op1, shared_ptr<const LlirOperand> op2);
    ~BitWiseXorOp();
    BitWiseXorOp(const BitWiseXorOp &rhs);
    BitWiseXorOp& operator=(const BitWiseXorOp &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
    BitWiseXorOp::~BitWiseXorOp()
    {}

  class UnaryExpr : public LlirExpr
  {
  public:
    virtual ~UnaryExpr();
    bool isConstantExpr() const;
    shared_ptr<const LlirOperand> getOpnd() const;
    unsigned long getConstantValue() const;

  protected:
    UnaryExpr(shared_ptr<const LlirOperand> op);
    UnaryExpr(const UnaryExpr &rhs);
    UnaryExpr& operator=(const UnaryExpr &rhs);
      
  private:
    shared_ptr<const LlirOperand> m_op;
  };

  inline 
  bool UnaryExpr::isConstantExpr() const
  {
    return false;
  }

  inline
  UnaryExpr::~UnaryExpr()
  {}


  class ParenthesesOp  : public UnaryExpr
  {
  public:
    ParenthesesOp(shared_ptr<const LlirOperand> op);
    ~ParenthesesOp();
    ParenthesesOp(const ParenthesesOp &rhs);
    ParenthesesOp& operator=(const ParenthesesOp &rhs);

    void accept(Visitor &) const;
    bool equalTo(const LlirOperand &rhs) const;
  };

  inline
    ParenthesesOp::~ParenthesesOp()
    {}

  class UnaryMinusOp : public UnaryExpr
    {
    public:
      UnaryMinusOp(shared_ptr<const LlirOperand> op);
      ~UnaryMinusOp();
      UnaryMinusOp(const UnaryMinusOp &rhs);
      UnaryMinusOp& operator=(const UnaryMinusOp &rhs);

      void accept(Visitor &) const;
      bool equalTo(const LlirOperand &rhs) const;
      
    };

  inline
    UnaryMinusOp::~UnaryMinusOp()
    {}

  typedef shared_ptr<LlirOperand> LlirOperandPtr;
  typedef shared_ptr<Register> RegisterPtr;
  typedef shared_ptr<NullRegister> NullRegisterPtr;
  typedef shared_ptr<HardRegister> HardRegisterPtr;
  typedef shared_ptr<PseudoRegister> PseudoRegisterPtr;
  typedef shared_ptr<MultiRegister> MultiRegisterPtr;
  typedef shared_ptr<MultiPseudoRegister> MultiPseudoRegisterPtr;
  typedef shared_ptr<MultiHardRegister> MultiHardRegisterPtr;
  typedef shared_ptr<UnsignedImmediate> UnsignedImmediatePtr;
  typedef shared_ptr<SignedImmediate> SignedImmediatePtr;
  typedef shared_ptr<OpndLabel> OpndLabelPtr;
  typedef shared_ptr<OpndMemory> OpndMemoryPtr;
  typedef shared_ptr<BinaryExpr> BinaryExprPtr;
  typedef shared_ptr<UnaryExpr> UnaryExprPtr;
} // namespace Llir

#endif
