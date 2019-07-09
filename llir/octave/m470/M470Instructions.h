#ifndef _M470_INSTRUCTIONS_H
#define _M470_INSTRUCTIONS_H

#include <LlirNode.h>
#include <LlirOperand.h>
#include <LlirException.h>
#include <OctaveNode.h>
#include <OctaveOperand.h>
#include <OctaveInstructions.h>


namespace Llir {

  class Visitor;

  //typedefs
  typedef shared_ptr<const LlirOperand> OpndPtr;
  typedef shared_ptr<const Register> RegPtr;
  typedef shared_ptr<const MultiRegister> MultiRegPtr;
  typedef shared_ptr<const UnsignedImmediate> UImmPtr;
  typedef shared_ptr<const SignedImmediate> SImmPtr;
  typedef shared_ptr<const OctaveMemory> MemPtr;
  typedef shared_ptr<const AbcGenericFlag> AbcGenPtr;
  typedef shared_ptr<const ModFlag> ModPtr;
  typedef shared_ptr<const SXFlag> SxPtr;
  typedef shared_ptr<const EssFlag> EssPtr;
  typedef shared_ptr<const LinkFlag> LinkPtr;
  
  
  //---------------------------------------------
  // M470AddwhInstruction 
  //---------------------------------------------
  
  // addwh rsb rd [br=disp]
  
  
  class M470AddwhInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddwhInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName,
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddwhInstruction(const M470AddwhInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddwhInstruction& operator=(const M470AddwhInstruction& rhs);
      
      ~M470AddwhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddwlInstruction 
  //---------------------------------------------
  
  // addwl rsb rd [br=disp]
  
  
  class M470AddwlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddwlInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddwlInstruction(const M470AddwlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddwlInstruction& operator=(const M470AddwlInstruction& rhs);
      
      ~M470AddwlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddwwInstruction 
  //---------------------------------------------
  
  // addww rsb rd [br=disp]
  
  
  class M470AddwwInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddwwInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddwwInstruction(const M470AddwwInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddwwInstruction& operator=(const M470AddwwInstruction& rhs);
      
      ~M470AddwwInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddlInstruction 
  //---------------------------------------------
  
  // addl rsb rd [br=disp]
  
  
  class M470AddlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddlInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr dst, 
			  OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddlInstruction(const M470AddlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddlInstruction& operator=(const M470AddlInstruction& rhs);
      
      ~M470AddlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubwhInstruction 
  //---------------------------------------------
  
  // subwh rsb rd [br=disp]
  
  
  class M470SubwhInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubwhInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubwhInstruction(const M470SubwhInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubwhInstruction& operator=(const M470SubwhInstruction& rhs);
      
      ~M470SubwhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubwlInstruction 
  //---------------------------------------------
  
  // subwl rsb rd [br=disp]
  
  
  class M470SubwlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubwlInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubwlInstruction(const M470SubwlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubwlInstruction& operator=(const M470SubwlInstruction& rhs);
      
      ~M470SubwlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubwwInstruction 
  //---------------------------------------------
  
  // subww rsb rd [br=disp]
  
  
  class M470SubwwInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubwwInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubwwInstruction(const M470SubwwInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubwwInstruction& operator=(const M470SubwwInstruction& rhs);
      
      ~M470SubwwInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SublInstruction 
  //---------------------------------------------
  
  // subl rsb rd [br=disp]
  
  
  class M470SublInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SublInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr dst, 
			  OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SublInstruction(const M470SublInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SublInstruction& operator=(const M470SublInstruction& rhs);
      
      ~M470SublInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddwhiInstruction 
  //---------------------------------------------
  
  // addwhi usi rd [br=disp]
  
  
  class M470AddwhiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddwhiInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddwhiInstruction(const M470AddwhiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddwhiInstruction& operator=(const M470AddwhiInstruction& rhs);
      
      ~M470AddwhiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddwliInstruction 
  //---------------------------------------------
  
  // addwli usi rd [br=disp]
  
  
  class M470AddwliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddwliInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddwliInstruction(const M470AddwliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddwliInstruction& operator=(const M470AddwliInstruction& rhs);
      
      ~M470AddwliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddwwiInstruction 
  //---------------------------------------------
  
  // addwwi usi rd [br=disp]
  
  
  class M470AddwwiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddwwiInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddwwiInstruction(const M470AddwwiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddwwiInstruction& operator=(const M470AddwwiInstruction& rhs);
      
      ~M470AddwwiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddliInstruction 
  //---------------------------------------------
  
  // addli usi rd [br=disp]
  
  
  class M470AddliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470AddliInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   UImmPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470AddliInstruction(const M470AddliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470AddliInstruction& operator=(const M470AddliInstruction& rhs);
      
      ~M470AddliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubwhiInstruction 
  //---------------------------------------------
  
  // subwhi usi rd [br=disp]
  
  
  class M470SubwhiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubwhiInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubwhiInstruction(const M470SubwhiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubwhiInstruction& operator=(const M470SubwhiInstruction& rhs);
      
      ~M470SubwhiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubwliInstruction 
  //---------------------------------------------
  
  // subwli usi rd [br=disp]
  
  
  class M470SubwliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubwliInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubwliInstruction(const M470SubwliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubwliInstruction& operator=(const M470SubwliInstruction& rhs);
      
      ~M470SubwliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubwwiInstruction 
  //---------------------------------------------
  
  // subwwi usi rd [br=disp]
  
  
  class M470SubwwiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubwwiInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubwwiInstruction(const M470SubwwiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubwwiInstruction& operator=(const M470SubwwiInstruction& rhs);
      
      ~M470SubwwiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubliInstruction 
  //---------------------------------------------
  
  // subli usi rd [br=disp]
  
  
  class M470SubliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470SubliInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   UImmPtr src1, 
			   RegPtr dst, 
			   OpndPtr target)
        : Alu2OpBranchInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target)
	{}
      
      M470SubliInstruction(const M470SubliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M470SubliInstruction& operator=(const M470SubliInstruction& rhs);
      
      ~M470SubliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470FfsInstruction 
  //---------------------------------------------
  
  // ffs rsa rd [ABC] [ZD]
  
  
  class M470FfsInstruction : public Alu2OpFindInstruction
    {
    public: 
      
      M470FfsInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr findFlag)
        : Alu2OpFindInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				src1, 
				dst, 
				abcFlag, 
				findFlag)
	{}
      
      M470FfsInstruction(const M470FfsInstruction& rhs)
	: Alu2OpFindInstruction(rhs)
	{}
      
      M470FfsInstruction& operator=(const M470FfsInstruction& rhs);
      
      ~M470FfsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470FlsInstruction 
  //---------------------------------------------
  
  // fls rsa rd [ABC] [ZD]
  
  
  class M470FlsInstruction : public Alu2OpFindInstruction
    {
    public: 
      
      M470FlsInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr findFlag)
        : Alu2OpFindInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				src1, 
				dst, 
				abcFlag, 
				findFlag)
	{}
      
      M470FlsInstruction(const M470FlsInstruction& rhs)
	: Alu2OpFindInstruction(rhs)
	{}
      
      M470FlsInstruction& operator=(const M470FlsInstruction& rhs);
      
      ~M470FlsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ParInstruction 
  //---------------------------------------------
  
  // par rsa rd [ABC]
  
  class M470ParInstruction : public Alu2OpInstruction
    {
    public:

      M470ParInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr dst, 
			 OpndPtr abcFlag)
        : Alu2OpInstruction(lineNum, 
			    srcLineNum,
			    srcFileName, 
			    src1, 
			    dst),
	m_abcFlag(abcFlag)
	{}
      
      M470ParInstruction(const M470ParInstruction& rhs)
	: Alu2OpInstruction(rhs),
	m_abcFlag(rhs.m_abcFlag)
	{}	 
      
      M470ParInstruction& operator=(const M470ParInstruction& rhs); 
      
      ~M470ParInstruction()
	{}
      
      OpndPtr getAbcFlag() const;      


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool hasValidAbcFlag() const;

      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_abcFlag;
      
    };
  
  
  //---------------------------------------------
  // M470AddInstruction 
  //---------------------------------------------
  
  // add rsa rsb rd [MODX] [ABC]
  
  
  class M470AddInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470AddInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr modFlag)
        : Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470AddInstruction(const M470AddInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470AddInstruction& operator=(const M470AddInstruction& rhs);
      
      ~M470AddInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Add4xInstruction 
  //---------------------------------------------
  
  // add4x rsa rsb rd [MODX] [ABC]
  
  
  class M470Add4xInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470Add4xInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag, 
			   OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470Add4xInstruction(const M470Add4xInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470Add4xInstruction& operator=(const M470Add4xInstruction& rhs);
      
      ~M470Add4xInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddcInstruction 
  //---------------------------------------------
  
  // addc rsa rsb rd [MODX] [ABC]
  
  
  class M470AddcInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470AddcInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag, 
			  OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470AddcInstruction(const M470AddcInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470AddcInstruction& operator=(const M470AddcInstruction& rhs);
      
      ~M470AddcInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AndInstruction 
  //---------------------------------------------
  
  // and rsa rsb rd [MODX] [ABC]
  
  
  class M470AndInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470AndInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470AndInstruction(const M470AndInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470AndInstruction& operator=(const M470AndInstruction& rhs);
      
      ~M470AndInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MaxInstruction 
  //---------------------------------------------
  
  // max rsa rsb rd [MODX] [ABC]
  
  
  class M470MaxInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470MaxInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470MaxInstruction(const M470MaxInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470MaxInstruction& operator=(const M470MaxInstruction& rhs);
      
      ~M470MaxInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MinInstruction 
  //---------------------------------------------
  
  // min rsa rsb rd [MODX] [ABC]
  
  
  class M470MinInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470MinInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470MinInstruction(const M470MinInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470MinInstruction& operator=(const M470MinInstruction& rhs);
      
      ~M470MinInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470OrInstruction 
  //---------------------------------------------
  
  // or rsa rsb rd [MODX] [ABC]
  
  
  class M470OrInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470OrInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			RegPtr src1, 
			RegPtr src2, 
			RegPtr dst, 
			OpndPtr abcFlag, 
			OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470OrInstruction(const M470OrInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470OrInstruction& operator=(const M470OrInstruction& rhs);
      
      ~M470OrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubInstruction 
  //---------------------------------------------
  
  // and sub rsb rd [MODX] [ABC]
  
  
  class M470SubInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470SubInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470SubInstruction(const M470SubInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470SubInstruction& operator=(const M470SubInstruction& rhs);
      
      ~M470SubInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SubbInstruction 
  //---------------------------------------------
  
  // and subb rsb rd [MODX] [ABC]
  
  
  class M470SubbInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470SubbInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag, 
			  OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470SubbInstruction(const M470SubbInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470SubbInstruction& operator=(const M470SubbInstruction& rhs);
      
      ~M470SubbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470XorInstruction 
  //---------------------------------------------
  
  // xor rsa rsb rd [MODX] [ABC]
  
  
  class M470XorInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470XorInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag, 
			 OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470XorInstruction(const M470XorInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470XorInstruction& operator=(const M470XorInstruction& rhs);
      
      ~M470XorInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddiInstruction 
  //---------------------------------------------
  
  // addi rsa usi rd [MODX] [ABC]
  
  
  class M470AddiInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470AddiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  UImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag, 
			  OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470AddiInstruction(const M470AddiInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470AddiInstruction& operator=(const M470AddiInstruction& rhs);
      
      ~M470AddiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AddciInstruction 
  //---------------------------------------------
  
  // addci rsa usi rd [MODX] [ABC]
  
  
  class M470AddciInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470AddciInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag, 
			   OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470AddciInstruction(const M470AddciInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470AddciInstruction& operator=(const M470AddciInstruction& rhs);
      
      ~M470AddciInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M470SubiInstruction 
  //---------------------------------------------
  
  // subi rsa usi rd [MODX] [ABC]
  
  
  class M470SubiInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470SubiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  UImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag, 
			  OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470SubiInstruction(const M470SubiInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470SubiInstruction& operator=(const M470SubiInstruction& rhs);
      
      ~M470SubiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M470SubbiInstruction 
  //---------------------------------------------
  
  // subbi rsa usi rd [MODX] [ABC]
  
  
  class M470SubbiInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M470SubbiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag, 
			   OpndPtr modFlag)
	: Alu3OpAbcModInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  src2, 
				  dst, 
				  abcFlag, 
				  modFlag)
	{}
      
      M470SubbiInstruction(const M470SubbiInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M470SubbiInstruction& operator=(const M470SubbiInstruction& rhs);
      
      ~M470SubbiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470RandInstruction 
  //---------------------------------------------
  
  // rand rsa rsb rd [ABC]
  
  
  class M470RandInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470RandInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470RandInstruction(const M470RandInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470RandInstruction& operator=(const M470RandInstruction& rhs);
      
      ~M470RandInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470RotlInstruction 
  //---------------------------------------------
  
  // rotl rsa rsb rd [ABC]
  
  
  class M470RotlInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470RotlInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470RotlInstruction(const M470RotlInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470RotlInstruction& operator=(const M470RotlInstruction& rhs);
      
      ~M470RotlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470RotrInstruction 
  //---------------------------------------------
  
  // rotr rsa rsb rd [ABC]
  
  
  class M470RotrInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470RotrInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470RotrInstruction(const M470RotrInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470RotrInstruction& operator=(const M470RotrInstruction& rhs);
      
      ~M470RotrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ClrbInstruction 
  //---------------------------------------------
  
  // clrb rsa rsb rd [ABC]
  
  
  class M470ClrbInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ClrbInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ClrbInstruction(const M470ClrbInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ClrbInstruction& operator=(const M470ClrbInstruction& rhs);
      
      ~M470ClrbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SetbInstruction 
  //---------------------------------------------
  
  // setb rsa rsb rd [ABC]
  
  
  class M470SetbInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470SetbInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470SetbInstruction(const M470SetbInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470SetbInstruction& operator=(const M470SetbInstruction& rhs);
      
      ~M470SetbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShftInstruction 
  //---------------------------------------------
  
  // shft rsa rsb rd [ABC]
  
  
  class M470ShftInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShftInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShftInstruction(const M470ShftInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShftInstruction& operator=(const M470ShftInstruction& rhs);
      
      ~M470ShftInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShftaInstruction 
  //---------------------------------------------
  
  // shfta rsa rsb rd [ABC]
  
  
  class M470ShftaInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShftaInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShftaInstruction(const M470ShftaInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShftaInstruction& operator=(const M470ShftaInstruction& rhs);
      
      ~M470ShftaInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShlInstruction 
  //---------------------------------------------
  
  // shl rsa rsb rd [ABC]
  
  
  class M470ShlInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShlInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShlInstruction(const M470ShlInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShlInstruction& operator=(const M470ShlInstruction& rhs);
      
      ~M470ShlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShrInstruction 
  //---------------------------------------------
  
  // shr rsa rsb rd [ABC]
  
  
  class M470ShrInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShrInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShrInstruction(const M470ShrInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShrInstruction& operator=(const M470ShrInstruction& rhs);
      
      ~M470ShrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShraInstruction 
  //---------------------------------------------
  
  // shra rsa rsb rd [ABC]
  
  
  class M470ShraInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShraInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShraInstruction(const M470ShraInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShraInstruction& operator=(const M470ShraInstruction& rhs);
      
      ~M470ShraInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470RandiInstruction 
  //---------------------------------------------
  
  // randi rsa uimm6 rd [ABC]
  
  
  class M470RandiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470RandiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470RandiInstruction(const M470RandiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470RandiInstruction& operator=(const M470RandiInstruction& rhs);
      
      ~M470RandiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470RotliInstruction 
  //---------------------------------------------
  
  // rotli rsa usa rd [ABC]
  
  
  class M470RotliInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470RotliInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470RotliInstruction(const M470RotliInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470RotliInstruction& operator=(const M470RotliInstruction& rhs);
      
      ~M470RotliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470RotriInstruction 
  //---------------------------------------------
  
  // rotri rsa usa rd [ABC]
  
  
  class M470RotriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470RotriInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470RotriInstruction(const M470RotriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470RotriInstruction& operator=(const M470RotriInstruction& rhs);
      
      ~M470RotriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SetbiInstruction 
  //---------------------------------------------
  
  // setbi rsa uimm5 rd [ABC]
  
  
  class M470SetbiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470SetbiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470SetbiInstruction(const M470SetbiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470SetbiInstruction& operator=(const M470SetbiInstruction& rhs);
      
      ~M470SetbiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };


  
  //---------------------------------------------
  // M470ClrbiInstruction 
  //---------------------------------------------
  
  // clrbi rsa uimm5 rd [ABC]
  
  
  class M470ClrbiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ClrbiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ClrbiInstruction(const M470ClrbiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ClrbiInstruction& operator=(const M470ClrbiInstruction& rhs);
      
      ~M470ClrbiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  
  
  //---------------------------------------------
  // M470ShliInstruction 
  //---------------------------------------------
  
  // shli rsa usa rd [ABC]
  
  
  class M470ShliInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShliInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  UImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShliInstruction(const M470ShliInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShliInstruction& operator=(const M470ShliInstruction& rhs);
      
      ~M470ShliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShriInstruction 
  //---------------------------------------------
  
  // shri rsa usa rd [ABC]
  
  
  class M470ShriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShriInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  UImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShriInstruction(const M470ShriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShriInstruction& operator=(const M470ShriInstruction& rhs);
      
      ~M470ShriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ShraiInstruction 
  //---------------------------------------------
  
  // shrai rsa usa rd [ABC]
  
  
  class M470ShraiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470ShraiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470ShraiInstruction(const M470ShraiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470ShraiInstruction& operator=(const M470ShraiInstruction& rhs);
      
      ~M470ShraiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MaxiInstruction 
  //---------------------------------------------
  
  // shrai rsa simm rd [ABC]
  
  
  class M470MaxiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470MaxiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470MaxiInstruction(const M470MaxiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470MaxiInstruction& operator=(const M470MaxiInstruction& rhs);
      
      ~M470MaxiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MiniInstruction 
  //---------------------------------------------
  
  // shrai rsa simm rd [ABC]
  
  
  class M470MiniInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470MiniInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470MiniInstruction(const M470MiniInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470MiniInstruction& operator=(const M470MiniInstruction& rhs);
      
      ~M470MiniInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470AndiInstruction 
  //---------------------------------------------
  
  // shrai rsa simm rd [ABC]
  
  
  class M470AndiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470AndiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470AndiInstruction(const M470AndiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470AndiInstruction& operator=(const M470AndiInstruction& rhs);
      
      ~M470AndiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470OriInstruction 
  //---------------------------------------------
  
  // shrai rsa si rd [ABC]
  
  
  class M470OriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470OriInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 SImmPtr src2, 
			 RegPtr dst, 
			 OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470OriInstruction(const M470OriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470OriInstruction& operator=(const M470OriInstruction& rhs);
      
      ~M470OriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470XoriInstruction 
  //---------------------------------------------
  
  // shrai rsa si rd [ABC]
  
  
  class M470XoriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M470XoriInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag)
        : Alu3OpAbcInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       src1, 
			       src2, 
			       dst, 
			       abcFlag)
	{}
      
      M470XoriInstruction(const M470XoriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M470XoriInstruction& operator=(const M470XoriInstruction& rhs);
      
      ~M470XoriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MulInstruction 
  //---------------------------------------------
  
  // mul rsa rsb rd [SX]
  
  
  class M470MulInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M470MulInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr sxFlag)
        : Alu3OpSxInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src1, 
			      src2, 
			      dst, 
			      sxFlag)
	{}
      
      M470MulInstruction(const M470MulInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M470MulInstruction& operator=(const M470MulInstruction& rhs);
      
      ~M470MulInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MulhInstruction 
  //---------------------------------------------
  
  // mulh rsa rsb rd [SX]
  
  
  class M470MulhInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M470MulhInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr sxFlag)
        : Alu3OpSxInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src1, 
			      src2, 
			      dst, 
			      sxFlag)
	{}
      
      M470MulhInstruction(const M470MulhInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M470MulhInstruction& operator=(const M470MulhInstruction& rhs);
      
      ~M470MulhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470DivInstruction 
  //---------------------------------------------
  
  // div rsa rsb rd [SX]
  
  
  class M470DivInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M470DivInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 RegPtr dst, 
			 OpndPtr sxFlag)
        : Alu3OpSxInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src1, 
			      src2, 
			      dst, 
			      sxFlag)
	{}
      
      M470DivInstruction(const M470DivInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M470DivInstruction& operator=(const M470DivInstruction& rhs);
      
      ~M470DivInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MuliInstruction 
  //---------------------------------------------
  
  // muli rsa rsb rd [SX]
  
  
  class M470MuliInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M470MuliInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr sxFlag)
        : Alu3OpSxInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src1, 
			      src2, 
			      dst, 
			      sxFlag)
	{}
      
      M470MuliInstruction(const M470MuliInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M470MuliInstruction& operator=(const M470MuliInstruction& rhs);
      
      ~M470MuliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MulhiInstruction 
  //---------------------------------------------
  
  // mulhi rsa rsb rd [SX]
  
  
  class M470MulhiInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M470MulhiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   SImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr sxFlag)
        : Alu3OpSxInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src1, 
			      src2, 
			      dst, 
			      sxFlag)
	{}
      
      M470MulhiInstruction(const M470MulhiInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M470MulhiInstruction& operator=(const M470MulhiInstruction& rhs);
      
      ~M470MulhiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470DiviInstruction 
  //---------------------------------------------
  
  // divi rsa rsb rd [SX]
  
  
  class M470DiviInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M470DiviInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  RegPtr dst, 
			  OpndPtr sxFlag)
        : Alu3OpSxInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src1, 
			      src2, 
			      dst, 
			      sxFlag)
	{}
      
      M470DiviInstruction(const M470DiviInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M470DiviInstruction& operator=(const M470DiviInstruction& rhs);
      
      ~M470DiviInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Addne Instruction
  //---------------------------------------------
  
  // addne rsa rsb rdi
  
  class M470AddneInstruction : public Alu3OpInstruction
    {
    public:
      
      M470AddneInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr src2, 
			   RegPtr dst)
        : Alu3OpInstruction(lineNum, 
			    srcLineNum,
			    srcFileName, 
			    src1, 
			    src2, 
			    dst)
	{}
      
      M470AddneInstruction(const M470AddneInstruction& rhs)
	: Alu3OpInstruction(rhs)
	{}
      
      M470AddneInstruction& operator=(const M470AddneInstruction& rhs);
      
      ~M470AddneInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Addnei Instruction
  //---------------------------------------------
  
  // addnei rsa usi rdi
  
  class M470AddneiInstruction : public Alu3OpInstruction
    {
    public:
      
      M470AddneiInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    UImmPtr src2, 
			    RegPtr dst)
        : Alu3OpInstruction(lineNum, 
			    srcLineNum,
			    srcFileName, 
			    src1, 
			    src2, 
			    dst)
	{}
      
      M470AddneiInstruction(const M470AddneiInstruction& rhs)
	: Alu3OpInstruction(rhs)
	{}
      
      M470AddneiInstruction& operator=(const M470AddneiInstruction& rhs);
      
      ~M470AddneiInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470ByteswInstruction 
  //---------------------------------------------
  
  // bytesw rsa rd b0# b1# b2# b3# [ABC]
  
  class M470ByteswInstruction : public AluOpInstruction
    {
    public:
      
      M470ByteswInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    UImmPtr b0, 
			    UImmPtr b1, 
			    UImmPtr b2, 
			    UImmPtr b3,
			    OpndPtr abcFlag)
        : AluOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName),
	m_src1(src1),
	m_dst(dst),
	m_b0(b0),
	m_b1(b1),
	m_b2(b2),
	m_b3(b3),
	m_abcFlag(abcFlag)
	{}
      
      M470ByteswInstruction(const M470ByteswInstruction& rhs)
	: AluOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_b0(rhs.m_b0),
	m_b1(rhs.m_b1),
	m_b2(rhs.m_b2),
	m_b3(rhs.m_b3),
	m_abcFlag(rhs.m_abcFlag)
	{}	 
      
      M470ByteswInstruction& operator=(const M470ByteswInstruction& rhs); 
      
      ~M470ByteswInstruction()
	{}

      RegPtr getSrc1() const;
      
      RegPtr getDst() const;
      
      UImmPtr getB0() const;
      
      UImmPtr getB1() const;
      
      UImmPtr getB2() const;
      
      UImmPtr getB3() const;
      
      OpndPtr getAbcFlag() const;      

      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool hasValidAbcFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_src1;
      RegPtr m_dst;
      UImmPtr m_b0; 
      UImmPtr m_b1; 
      UImmPtr m_b2; 
      UImmPtr m_b3; 
      OpndPtr m_abcFlag;
      
    };
  
  
  //---------------------------------------------
  // M470Bcdr Instruction
  //---------------------------------------------
  
  // bcdr rsb [!]ess# [rd(60:62)] [BF] [C]
  
  class M470BcdrInstruction : public CondBranchInstruction
    {
    public:
      
      M470BcdrInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  EssPtr ess, 
			  OpndPtr dst, 
			  OpndPtr flags)
        : CondBranchInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				src1, 
				ess, 
				dst, 
				flags)
	{}
      
      M470BcdrInstruction(const M470BcdrInstruction& rhs)
	: CondBranchInstruction(rhs)
	{}
      
      M470BcdrInstruction& operator=(const M470BcdrInstruction& rhs);
      
      ~M470BcdrInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bcr Instruction
  //---------------------------------------------
  
  // bcr rsb [!]ess# [rd(60:62)] [BF] [C]
  
  class M470BcrInstruction : public CondBranchInstruction
    {
    public:
      
      M470BcrInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 EssPtr ess, 
			 OpndPtr dst, 
			 OpndPtr flags)
        : CondBranchInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				src1, 
				ess, 
				dst, 
				flags)
	{}
      
      M470BcrInstruction(const M470BcrInstruction& rhs)
	: CondBranchInstruction(rhs)
	{}
      
      M470BcrInstruction& operator=(const M470BcrInstruction& rhs);
      
      ~M470BcrInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bcdi Instruction
  //---------------------------------------------
  
  // bcdi disp[15:0] [!]ess# [rd(60:62)] [BF] [C]
  
  class M470BcdiInstruction : public CondBranchImmedInstruction
    {
    public:
      
      M470BcdiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr src1, 
			  EssPtr ess, 
			  OpndPtr dst, 
			  OpndPtr flags)
        : CondBranchImmedInstruction(lineNum, 
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     ess, 
				     dst, 
				     flags)
	{}
      
      M470BcdiInstruction(const M470BcdiInstruction& rhs)
	: CondBranchImmedInstruction(rhs)
	{}
      
      M470BcdiInstruction& operator=(const M470BcdiInstruction& rhs);
      
      ~M470BcdiInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bci Instruction
  //---------------------------------------------
  
  // bci disp[15:0] [!]ess# [rd(60:62)] [BF] [C]
  
  class M470BciInstruction : public CondBranchImmedInstruction
    {
    public:
      
      M470BciInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 OpndPtr src1, 
			 EssPtr ess, 
			 OpndPtr dst, 
			 OpndPtr flags)
        : CondBranchImmedInstruction(lineNum, 
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     ess, 
				     dst, 
				     flags)
	{}
      
      M470BciInstruction(const M470BciInstruction& rhs)
	: CondBranchImmedInstruction(rhs)
	{}
      
      M470BciInstruction& operator=(const M470BciInstruction& rhs);
      
      ~M470BciInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bnzr Instruction
  //---------------------------------------------
  
  // bnzr rsa rsb
  
  class M470BnzrInstruction : public ZeroBranchInstruction
    {
    public:
      
      M470BnzrInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  OpndPtr cmpReg) 
        : ZeroBranchInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				src1, 
				src2, 
				cmpReg)
	{}
      
      M470BnzrInstruction(const M470BnzrInstruction& rhs)
	: ZeroBranchInstruction(rhs)
	{}
      
      M470BnzrInstruction& operator=(const M470BnzrInstruction& rhs);
      
      ~M470BnzrInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bzr Instruction
  //---------------------------------------------
  
  // bzr rsa rsb
  
  class M470BzrInstruction : public ZeroBranchInstruction
    {
    public:
      
      M470BzrInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 OpndPtr cmpReg) 
        : ZeroBranchInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				src1, 
				src2, 
				cmpReg)
	{}
      
      M470BzrInstruction(const M470BzrInstruction& rhs)
	: ZeroBranchInstruction(rhs)
	{}
      
      M470BzrInstruction& operator=(const M470BzrInstruction& rhs);
      
      ~M470BzrInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bnzi Instruction
  //---------------------------------------------
  
  // bnzi rsa disp[15:0]
  
  class M470BnziInstruction : public ZeroBranchImmedInstruction
    {
    public:
      
      M470BnziInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  OpndPtr src2, 
			  OpndPtr cmpReg) 
        : ZeroBranchImmedInstruction(lineNum, 
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     cmpReg)
	{}
      
      M470BnziInstruction(const M470BnziInstruction& rhs)
	: ZeroBranchImmedInstruction(rhs)
	{}
      
      M470BnziInstruction& operator=(const M470BnziInstruction& rhs);
      
      ~M470BnziInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bzi Instruction
  //---------------------------------------------
  
  // bzi rsa disp[15:0]
  
  class M470BziInstruction : public ZeroBranchImmedInstruction
    {
    public:
      
      M470BziInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 OpndPtr src2, 
			 OpndPtr cmpReg) 
        : ZeroBranchImmedInstruction(lineNum, 
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     cmpReg)
	{}
      
      M470BziInstruction(const M470BziInstruction& rhs)
	: ZeroBranchImmedInstruction(rhs)
	{}
      
      M470BziInstruction& operator=(const M470BziInstruction& rhs);
      
      ~M470BziInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Tsetb Instruction
  //---------------------------------------------
  
  // tsetb rsa bitpos br=disp
  
  class M470TsetbInstruction : public TestBitBranchInstruction
    {
    public:
      
      M470TsetbInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr bitpos, 
			   OpndPtr disp) 
        : TestBitBranchInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   src1, 
				   bitpos, 
				   disp)
	{}
      
      M470TsetbInstruction(const M470TsetbInstruction& rhs)
	: TestBitBranchInstruction(rhs)
	{}
      
      M470TsetbInstruction& operator=(const M470TsetbInstruction& rhs);
      
      ~M470TsetbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Tclrb Instruction
  //---------------------------------------------
  
  // tclrb rsa bitpos br=disp
  
  class M470TclrbInstruction : public TestBitBranchInstruction
    {
    public:
      
      M470TclrbInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   UImmPtr bitpos, 
			   OpndPtr disp) 
        : TestBitBranchInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   src1, 
				   bitpos, 
				   disp)
	{}
      
      M470TclrbInstruction(const M470TclrbInstruction& rhs)
	: TestBitBranchInstruction(rhs)
	{}
      
      M470TclrbInstruction& operator=(const M470TclrbInstruction& rhs);
      
      ~M470TclrbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Rnmi Instruction
  //---------------------------------------------
  
  // rnmi [DI]
  
  class M470RnmiInstruction : public ReturnOpInstruction
    {
    public:
      
      M470RnmiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr diFlag) 
        : ReturnOpInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      diFlag)
	{}
      
      M470RnmiInstruction(const M470RnmiInstruction& rhs)
	: ReturnOpInstruction(rhs)
	{}
      
      M470RnmiInstruction& operator=(const M470RnmiInstruction& rhs);
      
      ~M470RnmiInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Rint Instruction
  //---------------------------------------------
  
  // rint [DI]
  
  class M470RintInstruction : public ReturnOpInstruction
    {
    public:
      
      M470RintInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr diFlag) 
        : ReturnOpInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      diFlag)
	{}
      
      M470RintInstruction(const M470RintInstruction& rhs)
	: ReturnOpInstruction(rhs)
	{}
      
      M470RintInstruction& operator=(const M470RintInstruction& rhs);
      
      ~M470RintInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  
  //---------------------------------------------
  // M470Brs Instruction
  //---------------------------------------------
  
  // brs [rd(60:62]
  
  class M470BrsInstruction : public BranchOpInstruction
    {
    public:
      
      M470BrsInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 OpndPtr dst)
	: BranchOpInstruction(lineNum, 
			      srcLineNum,
			      srcFileName),
	m_dst(dst) 
	{}
      
      M470BrsInstruction(const M470BrsInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_dst(rhs.m_dst)
	{}
      
      M470BrsInstruction& operator=(const M470BrsInstruction& rhs);
      
      ~M470BrsInstruction()
	{}

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;


      OpndPtr getDst() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;


    private:

      bool hasReturnReg() const;
      
    private:
      
      OpndPtr m_dst;
      
    };
  
  
  //---------------------------------------------
  // M470Brsl Instruction
  //---------------------------------------------
  
  // brsl [UNLNK] [DLNK] [FLUSH] [PRE]
  
  class M470BrslInstruction : public BranchOpInstruction
    {
    public:
      
      M470BrslInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr flags)
	: BranchOpInstruction(lineNum, 
			      srcLineNum,
			      srcFileName),
	m_flags(flags)  
	{}
      
      M470BrslInstruction(const M470BrslInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_flags(rhs.m_flags)
	{}
      
      M470BrslInstruction& operator=(const M470BrslInstruction& rhs);
      
      ~M470BrslInstruction()
	{}
      
      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      OpndPtr getBrslFlags() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_flags;
      
    };
  
  
  //---------------------------------------------
  // M470Brspre Instruction
  //---------------------------------------------
  
  // brspre
  
  class M470BrspreInstruction : public OctaveInstruction
    {
    public:
      
      M470BrspreInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName) 
	: OctaveInstruction(lineNum, 
			    srcLineNum,
			    srcFileName)
	{}
      
      M470BrspreInstruction(const M470BrspreInstruction& rhs)
	: OctaveInstruction(rhs)
	{}
      
      M470BrspreInstruction& operator=(const M470BrspreInstruction& rhs);
      
      ~M470BrspreInstruction()
	{}
      
      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    };
  
  
  //---------------------------------------------
  // M470Cmp Instruction
  //---------------------------------------------
  
  // cmp rsa rsb [br=disp ABC]
  
  class M470CmpInstruction : public CompareOpBranchInstruction
    {
    public:
      
      M470CmpInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 RegPtr src2, 
			 OpndPtr abcFlag, 
			 OpndPtr branchTarget)
        : CompareOpBranchInstruction(lineNum, 
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     abcFlag, 
				     branchTarget)
	{}
      
      M470CmpInstruction(const M470CmpInstruction& rhs)
	: CompareOpBranchInstruction(rhs)
	{}
      
      M470CmpInstruction& operator=(const M470CmpInstruction& rhs);
      
      ~M470CmpInstruction()
	{}

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Cmpi Instruction
  //---------------------------------------------
  
  // cmpi rsa si [br=disp ABC]
  
  class M470CmpiInstruction : public CompareOpBranchInstruction
    {
    public:
      
      M470CmpiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  SImmPtr src2, 
			  OpndPtr abcFlag, 
			  OpndPtr branchTarget)
        : CompareOpBranchInstruction(lineNum, 
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     abcFlag, 
				     branchTarget)
	{}
      
      M470CmpiInstruction(const M470CmpiInstruction& rhs)
	: CompareOpBranchInstruction(rhs)
	{}
      
      M470CmpiInstruction& operator=(const M470CmpiInstruction& rhs);
      
      ~M470CmpiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Cmpr Instruction
  //---------------------------------------------
  
  // cmpr rsa rsb rd [ABC] [SIGN]
  
  class M470CmprInstruction : public CompareOpSignInstruction
    {
    public:
      
      M470CmprInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  RegPtr dst, 
			  OpndPtr abcFlag, 
			  OpndPtr sign)
        : CompareOpSignInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   src1, 
				   src2, 
				   dst, 
				   abcFlag, 
				   sign)
	{}
      
      M470CmprInstruction(const M470CmprInstruction& rhs)
	: CompareOpSignInstruction(rhs)
	{}
      
      M470CmprInstruction& operator=(const M470CmprInstruction& rhs);
      
      ~M470CmprInstruction()
	{}

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Cmpri Instruction
  //---------------------------------------------
  
  // cmpri rsa si rd [ABC] [SIGN]
  
  class M470CmpriInstruction : public CompareOpSignInstruction
    {
    public:
      
      M470CmpriInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   SImmPtr src2, 
			   RegPtr dst, 
			   OpndPtr abcFlag, 
			   OpndPtr sign)
        : CompareOpSignInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   src1, 
				   src2, 
				   dst, 
				   abcFlag, 
				   sign)
	{}
      
      M470CmpriInstruction(const M470CmpriInstruction& rhs)
	: CompareOpSignInstruction(rhs)
	{}
      
      M470CmpriInstruction& operator=(const M470CmpriInstruction& rhs);
      
      ~M470CmpriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470Bi Instruction
  //---------------------------------------------
  
  // bi disp[21:0] [rd(60:62)] [CD]
  
  class M470BiInstruction : public BranchOpInstruction
    {
    public:
      
      M470BiInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			OpndPtr src1, 
			OpndPtr dst, 
			OpndPtr cdFlag)
        : BranchOpInstruction(lineNum, 
			      srcLineNum,
			      srcFileName),
	m_src1(src1),
	m_dst(dst),
	m_cdFlag(cdFlag)
	{}
      
      M470BiInstruction(const M470BiInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_cdFlag(rhs.m_cdFlag)
	{}
      
      M470BiInstruction& operator=(const M470BiInstruction& rhs);
      
      ~M470BiInstruction()
	{}

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      OpndPtr getSrc1() const;
      
      OpndPtr getDst() const;
      
      OpndPtr getCdFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;

    private:

      bool hasReturnReg() const;
      
    private:
      
      OpndPtr m_src1;
      OpndPtr m_dst;
      OpndPtr m_cdFlag;
      
    };
  
  
  //---------------------------------------------
  // M470Br Instruction
  //---------------------------------------------
  
  // br rsb [rd(60:62)]
  
  class M470BrInstruction : public BranchOpInstruction
    {
    public:
      
      M470BrInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			RegPtr src1, 
			OpndPtr dst)
        : BranchOpInstruction(lineNum, 
			      srcLineNum,
			      srcFileName),
	m_src1(src1),
	m_dst(dst)
	{}
      
      M470BrInstruction(const M470BrInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst)
	{}
      
      M470BrInstruction& operator=(const M470BrInstruction& rhs);
      
      ~M470BrInstruction()
	{}

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      RegPtr getSrc1() const;
      
      OpndPtr getDst() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;

    private:

      bool hasReturnReg() const;
      
    private:
      
      RegPtr m_src1;
      OpndPtr m_dst;
      
    };
  
  
  //---------------------------------------------
  // M470DepbInstruction 
  //---------------------------------------------
  
  // depb rsb rsb-bit# rd rd-bit# #bits [Z]
  
  
  class M470DepbInstruction : public BitOpInstruction
    {
    public: 
      
      M470DepbInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src,
			  UImmPtr srcBitNum, 
			  RegPtr dst,
			  UImmPtr dstBitNum, 
			  UImmPtr numBits, 
			  OpndPtr depbFlag) 
        : BitOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   src, 
			   srcBitNum, 
			   dst, 
			   dstBitNum, 
			   numBits),
	m_depbFlag(depbFlag)
	{}
      
      M470DepbInstruction(const M470DepbInstruction& rhs)
	: BitOpInstruction(rhs),
	m_depbFlag(rhs.m_depbFlag)
	{}
      
      M470DepbInstruction& operator=(const M470DepbInstruction& rhs);
      
      ~M470DepbInstruction()
	{}
      
      OpndPtr getDepbFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_depbFlag;
      
    };
  
  
  //---------------------------------------------
  // M470ExtbInstruction 
  //---------------------------------------------
  
  // extb rsb rsb-bit# rd rd-bit# #bits [SIGN]
  
  
  class M470ExtbInstruction : public BitOpInstruction
    {
    public: 
      
      M470ExtbInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src,
			  UImmPtr srcBitNum, 
			  RegPtr dst,
			  UImmPtr dstBitNum, 
			  UImmPtr numBits, 
			  OpndPtr sign) 
        : BitOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   src, 
			   srcBitNum, 
			   dst, 
			   dstBitNum, 
			   numBits),
	m_sign(sign)
	{}
      
      M470ExtbInstruction(const M470ExtbInstruction& rhs)
	: BitOpInstruction(rhs),
	m_sign(rhs.m_sign)
	{}
      
      M470ExtbInstruction& operator=(const M470ExtbInstruction& rhs);
      
      ~M470ExtbInstruction()
	{}
      
      OpndPtr getSignFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_sign;
      
    };
  
  
  //---------------------------------------------
  // M470DepbiInstruction 
  //---------------------------------------------
  
  // depb usi rd rd-bit# #bits [Z]
  
  
  class M470DepbiInstruction : public BitOpImmInstruction
    {
    public: 
      
      M470DepbiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   UImmPtr src, 
			   RegPtr dst, 
			   UImmPtr dstBitNum, 
			   UImmPtr numBits, 
			   OpndPtr depbFlag) 
        : BitOpImmInstruction(lineNum, 
			      srcLineNum,
			      srcFileName, 
			      src, 
			      dst, 
			      dstBitNum, 
			      numBits),
	m_depbFlag(depbFlag)
	{}
      
      M470DepbiInstruction(const M470DepbiInstruction& rhs)
	: BitOpImmInstruction(rhs),
	m_depbFlag(rhs.m_depbFlag)
	{}
      
      M470DepbiInstruction& operator=(const M470DepbiInstruction& rhs);
      
      ~M470DepbiInstruction()
	{}
      
      OpndPtr getDepbFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_depbFlag;
      
    };
  
  
  //---------------------------------------------
  // M470CmovInstruction 
  //---------------------------------------------
  
  // cmov rsa rsb rd [!]ess#
  
  
  class M470CmovInstruction : public CmovOpInstruction
    {
    public: 
      
      M470CmovInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1,
			  RegPtr src2, 
			  RegPtr dst, 
			  EssPtr essFlag)
        : CmovOpInstruction(lineNum, 
			    srcLineNum,
			    srcFileName, 
			    src1, 
			    src2, 
			    dst, 
			    essFlag)
	{}
      
      M470CmovInstruction(const M470CmovInstruction& rhs)
	: CmovOpInstruction(rhs)
	{}
      
      M470CmovInstruction& operator=(const M470CmovInstruction& rhs);
      
      ~M470CmovInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470CmoviInstruction 
  //---------------------------------------------
  
  // cmovi rsa uimm rd [!]ess#
  
  
  class M470CmoviInstruction : public CmovOpInstruction
    {
    public: 
      
      M470CmoviInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1,
			   UImmPtr src2, 
			   RegPtr dst, 
			   EssPtr essFlag)
        : CmovOpInstruction(lineNum, 
			    srcLineNum,
			    srcFileName, 
			    src1, 
			    src2, 
			    dst, 
			    essFlag)
	{}
      
      M470CmoviInstruction(const M470CmoviInstruction& rhs)
	: CmovOpInstruction(rhs)
	{}
      
      M470CmoviInstruction& operator=(const M470CmoviInstruction& rhs);
      
      ~M470CmoviInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470DmapInstruction 
  //---------------------------------------------
  
  // dmap rsa-rsa+1 dmaflags
  
  
  class M470DmapInstruction : public DmaOpInstruction
    {
    public: 
      
      M470DmapInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  MultiRegPtr regs, 
			  UImmPtr flags)
        : DmaOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   regs, 
			   flags)
	{}
      
      M470DmapInstruction(const M470DmapInstruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M470DmapInstruction& operator=(const M470DmapInstruction& rhs);
      
      ~M470DmapInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470DmasrInstruction 
  //---------------------------------------------
  
  // dmasr rsa DMAflags
  
  
  class M470DmasrInstruction : public DmaOpInstruction
    {
    public: 
      
      M470DmasrInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   MultiRegPtr regs, 
			   UImmPtr flags)
        : DmaOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   regs, 
			   flags)
	{}
      
      M470DmasrInstruction(const M470DmasrInstruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M470DmasrInstruction& operator=(const M470DmasrInstruction& rhs);
      
      ~M470DmasrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470Dmau0Instruction 
  //---------------------------------------------
  
  // dmau0 rsa-rsa+1 dmaflags
  
  
  class M470Dmau0Instruction : public DmaOpInstruction
    {
    public: 
      
      M470Dmau0Instruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   MultiRegPtr regs, 
			   UImmPtr flags)
        : DmaOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   regs, 
			   flags)
	{}
      
      M470Dmau0Instruction(const M470Dmau0Instruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M470Dmau0Instruction& operator=(const M470Dmau0Instruction& rhs);
      
      ~M470Dmau0Instruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470Dmau1Instruction 
  //---------------------------------------------
  
  // dmau1 rsa-rsa+1 dmaflags
  
  
  class M470Dmau1Instruction : public DmaOpInstruction
    {
    public: 
      
      M470Dmau1Instruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   MultiRegPtr regs, 
			   UImmPtr flags)
        : DmaOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   regs, 
			   flags)
	{}
      
      M470Dmau1Instruction(const M470Dmau1Instruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M470Dmau1Instruction& operator=(const M470Dmau1Instruction& rhs);
      
      ~M470Dmau1Instruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470LihInstruction 
  //---------------------------------------------
  
  // lih rd[0-127] imm
  
  
  class M470LihInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M470LihInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr dst, 
			 OpndPtr src)
        : LoadImmediateInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   dst, 
				   src)
	{}
      
      M470LihInstruction(const M470LihInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M470LihInstruction& operator=(const M470LihInstruction& rhs);
      
      ~M470LihInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470LilInstruction 
  //---------------------------------------------
  
  // lil rd[0-127] imm
  
  
  class M470LilInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M470LilInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr dst, 
			 OpndPtr src)
        : LoadImmediateInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   dst, 
				   src)
	{}
      
      M470LilInstruction(const M470LilInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M470LilInstruction& operator=(const M470LilInstruction& rhs);
      
      ~M470LilInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470LaihInstruction 
  //---------------------------------------------
  
  // laih rd[0-63] imm
  
  
  class M470LaihInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M470LaihInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr dst, 
			  OpndPtr src)
        : LoadImmediateInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   dst, 
				   src)
	{}
      
      M470LaihInstruction(const M470LaihInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M470LaihInstruction& operator=(const M470LaihInstruction& rhs);
      
      ~M470LaihInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470LailInstruction 
  //---------------------------------------------
  
  // lail rd[0-63] imm
  
  
  class M470LailInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M470LailInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr dst, 
			  OpndPtr src)
        : LoadImmediateInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   dst, 
				   src)
	{}
      
      M470LailInstruction(const M470LailInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M470LailInstruction& operator=(const M470LailInstruction& rhs);
      
      ~M470LailInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470LwihInstruction 
  //---------------------------------------------
  
  // lwih rd[0-63] imm
  
  
  class M470LwihInstruction : public LoadHalfwordInstruction
    {
    public: 
      
      M470LwihInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr dst, 
			  OpndPtr src)
        : LoadHalfwordInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  dst, 
				  src)
	{}
      
      M470LwihInstruction(const M470LwihInstruction& rhs)
	: LoadHalfwordInstruction(rhs)
	{}
      
      M470LwihInstruction& operator=(const M470LwihInstruction& rhs);
      
      ~M470LwihInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470LwilInstruction 
  //---------------------------------------------
  
  // lwil rd[0-63] imm
  
  
  class M470LwilInstruction : public LoadHalfwordInstruction
    {
    public: 
      
      M470LwilInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr dst, 
			  OpndPtr src)
        : LoadHalfwordInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  dst, 
				  src)
	{}
      
      M470LwilInstruction(const M470LwilInstruction& rhs)
	: LoadHalfwordInstruction(rhs)
	{}
      
      M470LwilInstruction& operator=(const M470LwilInstruction& rhs);
      
      ~M470LwilInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470NopInstruction 
  //---------------------------------------------
  
  // nop
  
  
  class M470NopInstruction : public OctaveInstruction
    {
    public: 
      
      M470NopInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName)
        : OctaveInstruction(lineNum, 
			    srcLineNum,
			    srcFileName)
	{}
      
      M470NopInstruction(const M470NopInstruction& rhs)
	: OctaveInstruction(rhs)
	{}
      
      M470NopInstruction& operator=(const M470NopInstruction& rhs);
      
      ~M470NopInstruction()
	{}
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      BranchProbability getBranchProbability() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M470Hec5Instruction 
  //---------------------------------------------
  
  // hec5 rsb rd bytes [CUME] [br=pc]
  
  class M470Hec5Instruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M470Hec5Instruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src, 
			  RegPtr dst,
			  UImmPtr bytes, 
			  OpndPtr branchTarget, 
			  OpndPtr cumeFlag)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName,
				  src,
				  dst,
				  branchTarget),
	m_bytes(bytes),
	m_cumeFlag(cumeFlag)
	{}
      
      M470Hec5Instruction(const M470Hec5Instruction& rhs)
	: Alu2OpBranchInstruction(rhs),
	m_bytes(rhs.m_bytes),
	m_cumeFlag(rhs.m_cumeFlag)
	{}
      
      M470Hec5Instruction& operator=(const M470Hec5Instruction& rhs);
      
      ~M470Hec5Instruction()
	{}
      
      UImmPtr getBytes() const;
      
      OpndPtr getCumeFlag() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    private:
      
      UImmPtr m_bytes;
      
      OpndPtr m_cumeFlag;
      
    };
  
  //---------------------------------------------
  // M470MvInstruction 
  //---------------------------------------------
  
  // mv rsa rd
  
  class M470MvInstruction : public OctaveInstruction
    {
    public: 
      
      M470MvInstruction(unsigned int lineNum,
			unsigned int srcLineNum,
			const char* srcFileName, 
			RegPtr src, 
			RegPtr dst)
        : OctaveInstruction(lineNum, 
			    srcLineNum,
			    srcFileName),
	m_src(src),
	m_dst(dst)
	{}
      
      M470MvInstruction(const M470MvInstruction& rhs)
	: OctaveInstruction(rhs),
	m_src(rhs.m_src),
	m_dst(rhs.m_dst)

	{}
      
      M470MvInstruction& operator=(const M470MvInstruction& rhs);
      
      ~M470MvInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      RegPtr getSrc() const;
      
      RegPtr getDst() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    private:
      
      RegPtr  m_src;
      
      RegPtr  m_dst;
      
    };
  
  
  //---------------------------------------------
  // M470MvhrInstruction 
  //---------------------------------------------
  
  // mvhr rsb rsa [cN]
  
  class M470MvhrInstruction : public MvhOpInstruction
    {
    public: 
      
      M470MvhrInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src, 
			  RegPtr dst, 
			  OpndPtr mvhFlag)
        : MvhOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   src, 
			   dst, 
			   mvhFlag)
	{}
      
      M470MvhrInstruction(const M470MvhrInstruction& rhs)
	: MvhOpInstruction(rhs)
	
	{}
      
      M470MvhrInstruction& operator=(const M470MvhrInstruction& rhs);
      
      ~M470MvhrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470MvrhInstruction 
  //---------------------------------------------
  
  // mvrh rsb rsa [cN]
  
  class M470MvrhInstruction : public MvhOpInstruction
    {
    public: 
      
      M470MvrhInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src, 
			  RegPtr dst, 
			  OpndPtr mvhFlag)
        : MvhOpInstruction(lineNum, 
			   srcLineNum,
			   srcFileName, 
			   src, 
			   dst, 
			   mvhFlag)
	{}
      
      M470MvrhInstruction(const M470MvrhInstruction& rhs)
	: MvhOpInstruction(rhs)
	
	{}
      
      M470MvrhInstruction& operator=(const M470MvrhInstruction& rhs);
      
      ~M470MvrhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470UnlinkInstruction 
  //---------------------------------------------
  
  // unlink rd1-rd2
  
  class M470UnlinkInstruction : public MultiRegOpInstruction
    {
    public: 
      
      M470UnlinkInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    MultiRegPtr regs)
        : MultiRegOpInstruction(lineNum, 
				srcLineNum,
				srcFileName, 
				regs)
	{}
      
      M470UnlinkInstruction(const M470UnlinkInstruction& rhs)
	: MultiRegOpInstruction(rhs)
	{}
      
      M470UnlinkInstruction& operator=(const M470UnlinkInstruction& rhs);
      
      ~M470UnlinkInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470LinkInstruction 
  //---------------------------------------------
  
  // link rd1-rd2 rsb LNK1|LNK2|LNK3
  // link rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  // link rd1-rd2 BASE2|BASE3 uimm LNK1|LNK2|LNK3
  
  class M470LinkInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M470LinkInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  MultiRegPtr regs, 
			  MemPtr mem, 
			  LinkPtr linkFlag)
        : MultiRegLinkInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  regs, 
				  mem, 
				  linkFlag)
	{}
      
      M470LinkInstruction(const M470LinkInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M470LinkInstruction& operator=(const M470LinkInstruction& rhs);
      
      ~M470LinkInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470LinksInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M470LinksInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M470LinksInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   MultiRegPtr regs, 
			   MemPtr mem, 
			   LinkPtr linkFlag)
        : MultiRegLinkInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  regs, 
				  mem, 
				  linkFlag)
	{}
      
      M470LinksInstruction(const M470LinksInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M470LinksInstruction& operator=(const M470LinksInstruction& rhs);
      
      ~M470LinksInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470LmmInstruction 
  //---------------------------------------------
  
  // lmm rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmm rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmm rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M470LmmInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M470LmmInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 MultiRegPtr regs, 
			 MemPtr mem, 
			 OpndPtr linkFlag)
        : MultiRegLoadInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  regs, 
				  mem, 
				  linkFlag)
	{}
      
      M470LmmInstruction(const M470LmmInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M470LmmInstruction& operator=(const M470LmmInstruction& rhs);
      
      ~M470LmmInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470LmmsInstruction 
  //---------------------------------------------
  
  // lmms rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmms rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  
  class M470LmmsInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M470LmmsInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  MultiRegPtr regs, 
			  MemPtr mem, 
			  OpndPtr linkFlag)
        : MultiRegLoadInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  regs, 
				  mem, 
				  linkFlag)
	{}
      
      M470LmmsInstruction(const M470LmmsInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M470LmmsInstruction& operator=(const M470LmmsInstruction& rhs);
      
      ~M470LmmsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M470LspInstruction 
  //---------------------------------------------
  
  // lsp rd1-rd2 rsa [LNK1|LNK2|LNK3]
  // lsp rd1-rd2 imm [LNK1|LNK2|LNK3]
  // lsp rd1-rd2 imm(rsa) [LNK1|LNK2|LNK3]
  
  class M470LspInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M470LspInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 MultiRegPtr regs, 
			 MemPtr mem, 
			 OpndPtr linkFlag)
        : MultiRegLoadInstruction(lineNum, 
				  srcLineNum,
				  srcFileName, 
				  regs, 
				  mem, 
				  linkFlag)
	{}
      
      M470LspInstruction(const M470LspInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M470LspInstruction& operator=(const M470LspInstruction& rhs);
      
      ~M470LspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SmmInstruction 
  //---------------------------------------------
  
  // smm rd1-rd2 rsb 
  // smm rd1-rd2 simm(rsb) 
  // smm rd1-rd2 BASE2|BASE3 uimm 
  
  class M470SmmInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M470SmmInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 MultiRegPtr regs, 
			 MemPtr mem)
        : MultiRegStoreInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   regs, 
				   mem)
	{}
      
      M470SmmInstruction(const M470SmmInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M470SmmInstruction& operator=(const M470SmmInstruction& rhs);
      
      ~M470SmmInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  
  //---------------------------------------------
  // M470SmmsInstruction 
  //---------------------------------------------
  
  // smms rd1-rd2 rsb 
  // smms rd1-rd2 simm(rsb) 
  
  class M470SmmsInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M470SmmsInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  MultiRegPtr regs, 
			  MemPtr mem)
        : MultiRegStoreInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   regs, 
				   mem)
	{}
      
      M470SmmsInstruction(const M470SmmsInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M470SmmsInstruction& operator=(const M470SmmsInstruction& rhs);
      
      ~M470SmmsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470SspInstruction 
  //---------------------------------------------
  
  // ssp rsb rsa 
  // ssp rsb imm 
  // ssp rsb imm(rsa)
  
  class M470SspInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M470SspInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 MultiRegPtr regs, 
			 MemPtr mem)
        : MultiRegStoreInstruction(lineNum, 
				   srcLineNum,
				   srcFileName, 
				   regs, 
				   mem)
	{}
      
      M470SspInstruction(const M470SspInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M470SspInstruction& operator=(const M470SspInstruction& rhs);
      
      ~M470SspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  
  //---------------------------------------------
  // M470PutInstruction 
  //---------------------------------------------
  
  // put rsa rsb [put flags]  
  
  class M470PutInstruction : public TssRcOpInstruction
    {
    public: 
      
      M470PutInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr rsa, 
			 RegPtr rsb, 
			 OpndPtr flags)
        : TssRcOpInstruction(lineNum, 
			     srcLineNum,
			     srcFileName, 
			     rsa, 
			     flags), 
	m_rsb(rsb)
	{}
      
      M470PutInstruction(const M470PutInstruction& rhs)
	: TssRcOpInstruction(rhs), 
	m_rsb(rhs.m_rsb)
	{}
      
      M470PutInstruction& operator=(const M470PutInstruction& rhs);
      
      ~M470PutInstruction()
	{}
      
      RegPtr getRsb() const;
	
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_rsb;
      
    };
  
  
  //---------------------------------------------
  // M470GetInstruction 
  //---------------------------------------------
  
  // get rsa [get flags]  
  
  class M470GetInstruction : public TssRcOpInstruction
    {
    public: 
      
      M470GetInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr rsa, 
			 OpndPtr flags)
        : TssRcOpInstruction(lineNum, 
			     srcLineNum,
			     srcFileName, 
			     rsa, 
			     flags)
	{}
      
      M470GetInstruction(const M470GetInstruction& rhs)
	: TssRcOpInstruction(rhs)
	{}
      
      M470GetInstruction& operator=(const M470GetInstruction& rhs);
      
      ~M470GetInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470PolInstruction 
  //---------------------------------------------
  
  // pol rsa [pol flags]  
  
  class M470PolInstruction : public TssRcOpInstruction
    {
    public: 
      
      M470PolInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr rsa, 
			 OpndPtr flags)
        : TssRcOpInstruction(lineNum, 
			     srcLineNum,
			     srcFileName, 
			     rsa, 
			     flags)
	{}
      
      M470PolInstruction(const M470PolInstruction& rhs)
	: TssRcOpInstruction(rhs)
	{}
      
      M470PolInstruction& operator=(const M470PolInstruction& rhs);
      
      ~M470PolInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  
  //---------------------------------------------
  // M470PutcInstruction 
  //---------------------------------------------
  
  // putc par_offset pos_offset [pipe_depth] [put_flags]  
  
  class M470PutcInstruction : public TssNoRcOpInstruction
    {
    public: 
      
      M470PutcInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  UImmPtr parOffset,
			  UImmPtr posOffset, 
			  OpndPtr pipeDepth,
			  OpndPtr flags)
        : TssNoRcOpInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       parOffset, 
			       posOffset, 
			       flags),
	m_pipeDepth(pipeDepth)
	{}
      
      M470PutcInstruction(const M470PutcInstruction& rhs)
	: TssNoRcOpInstruction(rhs),
	m_pipeDepth(rhs.m_pipeDepth)
	{}
      
      M470PutcInstruction& operator=(const M470PutcInstruction& rhs);
      
      ~M470PutcInstruction()
	{}
      
      OpndPtr getPipeDepth() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_pipeDepth;
      
    };
  
  
  //---------------------------------------------
  // M470GetcInstruction 
  //---------------------------------------------
  
  // getc par_offset pos_offset [get_flags]  
  
  class M470GetcInstruction : public TssNoRcOpInstruction
    {
    public: 
      
      M470GetcInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  UImmPtr parOffset,
			  UImmPtr posOffset, 
			  OpndPtr flags)
        : TssNoRcOpInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       parOffset, 
			       posOffset, 
			       flags)
	{}
      
      M470GetcInstruction(const M470GetcInstruction& rhs)
	: TssNoRcOpInstruction(rhs)
	{}
      
      M470GetcInstruction& operator=(const M470GetcInstruction& rhs);
      
      ~M470GetcInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M470PolcInstruction 
  //---------------------------------------------
  
  // polc par_offset pos_offset [pol_flags]  
  
  class M470PolcInstruction : public TssNoRcOpInstruction
    {
    public: 
      
      M470PolcInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  UImmPtr parOffset,
			  UImmPtr posOffset, 
			  OpndPtr flags)
        : TssNoRcOpInstruction(lineNum, 
			       srcLineNum,
			       srcFileName, 
			       parOffset, 
			       posOffset, 
			       flags)
	{}
      
      M470PolcInstruction(const M470PolcInstruction& rhs)
	: TssNoRcOpInstruction(rhs)
	{}
      
      M470PolcInstruction& operator=(const M470PolcInstruction& rhs);
      
      ~M470PolcInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  //---------------------------------------------
  
} // end namespace Llir
  
#endif
