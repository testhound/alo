#ifndef _M480_INSTRUCTIONS_H
#define _M480_INSTRUCTIONS_H

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
  // M480AddwhInstruction 
  //---------------------------------------------
  
  // addwh rsb rd [br=disp]
  
  
  class M480AddwhInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddwhInstruction(unsigned int lineNum,
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
      
      M480AddwhInstruction(const M480AddwhInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddwhInstruction& operator=(const M480AddwhInstruction& rhs);
      
      ~M480AddwhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480JaddwhInstruction 
  //---------------------------------------------
  
  // addwh rsb rd [br=disp]
  
  
  class M480JaddwhInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddwhInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName,
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddwhInstruction(const M480JaddwhInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddwhInstruction& operator=(const M480JaddwhInstruction& rhs);
      
      ~M480JaddwhInstruction()
	{}


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  //---------------------------------------------
  // M480AddwlInstruction 
  //---------------------------------------------
  
  // addwl rsb rd [br=disp]
  
  
  class M480AddwlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddwlInstruction(unsigned int lineNum,
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
      
      M480AddwlInstruction(const M480AddwlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddwlInstruction& operator=(const M480AddwlInstruction& rhs);
      
      ~M480AddwlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480JaddwlInstruction 
  //---------------------------------------------
  
  // addwl rsb rd [br=disp]
  
  
  class M480JaddwlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddwlInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddwlInstruction(const M480JaddwlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddwlInstruction& operator=(const M480JaddwlInstruction& rhs);
      
      ~M480JaddwlInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480AddwwInstruction 
  //---------------------------------------------
  
  // addww rsb rd [br=disp]
  
  
  class M480AddwwInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddwwInstruction(unsigned int lineNum,
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
      
      M480AddwwInstruction(const M480AddwwInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddwwInstruction& operator=(const M480AddwwInstruction& rhs);
      
      ~M480AddwwInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480JaddwwInstruction 
  //---------------------------------------------
  
  // addww rsb rd [br=disp]
  
  
  class M480JaddwwInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddwwInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddwwInstruction(const M480JaddwwInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddwwInstruction& operator=(const M480JaddwwInstruction& rhs);
      
      ~M480JaddwwInstruction()
	{}
      
      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AddlInstruction 
  //---------------------------------------------
  
  // addl rsb rd [br=disp]
  
  
  class M480AddlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddlInstruction(unsigned int lineNum,
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
      
      M480AddlInstruction(const M480AddlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddlInstruction& operator=(const M480AddlInstruction& rhs);
      
      ~M480AddlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480JaddlInstruction 
  //---------------------------------------------
  
  // addl rsb rd [br=disp]
  
  
  class M480JaddlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddlInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target,
			   BranchProbability probability)
	: Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddlInstruction(const M480JaddlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddlInstruction& operator=(const M480JaddlInstruction& rhs);
      
      ~M480JaddlInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480SubwhInstruction 
  //---------------------------------------------
  
  // subwh rsb rd [br=disp]
  
  
  class M480SubwhInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubwhInstruction(unsigned int lineNum,
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
      
      M480SubwhInstruction(const M480SubwhInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubwhInstruction& operator=(const M480SubwhInstruction& rhs);
      
      ~M480SubwhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480JsubwhInstruction 
  //---------------------------------------------
  
  // subwh rsb rd [br=disp]
  
  
  class M480JsubwhInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubwhInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubwhInstruction(const M480JsubwhInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubwhInstruction& operator=(const M480JsubwhInstruction& rhs);
      
      ~M480JsubwhInstruction()
	{}
      

      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SubwlInstruction 
  //---------------------------------------------
  
  // subwl rsb rd [br=disp]
  
  
  class M480SubwlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubwlInstruction(unsigned int lineNum,
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
      
      M480SubwlInstruction(const M480SubwlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubwlInstruction& operator=(const M480SubwlInstruction& rhs);
      
      ~M480SubwlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480JsubwlInstruction 
  //---------------------------------------------
  
  // subwl rsb rd [br=disp]
  
  
  class M480JsubwlInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubwlInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubwlInstruction(const M480JsubwlInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubwlInstruction& operator=(const M480JsubwlInstruction& rhs);
      
      ~M480JsubwlInstruction()
	{}
      

      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SubwwInstruction 
  //---------------------------------------------
  
  // subww rsb rd [br=disp]
  
  
  class M480SubwwInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubwwInstruction(unsigned int lineNum,
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
      
      M480SubwwInstruction(const M480SubwwInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubwwInstruction& operator=(const M480SubwwInstruction& rhs);
      
      ~M480SubwwInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  //---------------------------------------------
  // M480JsubwwInstruction 
  //---------------------------------------------
  
  // subww rsb rd [br=disp]
  
  
  class M480JsubwwInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubwwInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubwwInstruction(const M480JsubwwInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubwwInstruction& operator=(const M480JsubwwInstruction& rhs);
      
      ~M480JsubwwInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SublInstruction 
  //---------------------------------------------
  
  // subl rsb rd [br=disp]
  
  
  class M480SublInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SublInstruction(unsigned int lineNum,
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
      
      M480SublInstruction(const M480SublInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SublInstruction& operator=(const M480SublInstruction& rhs);
      
      ~M480SublInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
   
  //---------------------------------------------
  // M480JsublInstruction 
  //---------------------------------------------
  
  // subl rsb rd [br=disp]
  
  
  class M480JsublInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsublInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr dst, 
			   OpndPtr target,
			   BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsublInstruction(const M480JsublInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsublInstruction& operator=(const M480JsublInstruction& rhs);
      
      ~M480JsublInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AddwhiInstruction 
  //---------------------------------------------
  
  // addwhi usi rd [br=disp]
  
  
  class M480AddwhiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddwhiInstruction(unsigned int lineNum,
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
      
      M480AddwhiInstruction(const M480AddwhiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddwhiInstruction& operator=(const M480AddwhiInstruction& rhs);
      
      ~M480AddwhiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  //---------------------------------------------
  // M480JaddwhiInstruction 
  //---------------------------------------------
  
  // addwhi usi rd [br=disp]
  
  
  class M480JaddwhiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddwhiInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     UImmPtr src1, 
			     RegPtr dst, 
			     OpndPtr target,
			     BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddwhiInstruction(const M480JaddwhiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddwhiInstruction& operator=(const M480JaddwhiInstruction& rhs);
      
      ~M480JaddwhiInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  
  //---------------------------------------------
  // M480AddwliInstruction 
  //---------------------------------------------
  
  // addwli usi rd [br=disp]
  
  
  class M480AddwliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddwliInstruction(unsigned int lineNum,
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
      
      M480AddwliInstruction(const M480AddwliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddwliInstruction& operator=(const M480AddwliInstruction& rhs);
      
      ~M480AddwliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  //---------------------------------------------
  // M480JaddwliInstruction 
  //---------------------------------------------
  
  // addwli usi rd [br=disp]
  
  
  class M480JaddwliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddwliInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     UImmPtr src1, 
			     RegPtr dst, 
			     OpndPtr target,
			     BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddwliInstruction(const M480JaddwliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddwliInstruction& operator=(const M480JaddwliInstruction& rhs);
      
      ~M480JaddwliInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  
  //---------------------------------------------
  // M480AddwwiInstruction 
  //---------------------------------------------
  
  // addwwi usi rd [br=disp]
  
  
  class M480AddwwiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddwwiInstruction(unsigned int lineNum,
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
      
      M480AddwwiInstruction(const M480AddwwiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddwwiInstruction& operator=(const M480AddwwiInstruction& rhs);
      
      ~M480AddwwiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  
  //---------------------------------------------
  // M480JaddwwiInstruction 
  //---------------------------------------------
  
  // addwwi usi rd [br=disp]
  
  
  class M480JaddwwiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddwwiInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     UImmPtr src1, 
			     RegPtr dst, 
			     OpndPtr target,
			     BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddwwiInstruction(const M480JaddwwiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddwwiInstruction& operator=(const M480JaddwwiInstruction& rhs);
      
      ~M480JaddwwiInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AddliInstruction 
  //---------------------------------------------
  
  // addli usi rd [br=disp]
  
  
  class M480AddliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480AddliInstruction(unsigned int lineNum,
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
      
      M480AddliInstruction(const M480AddliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480AddliInstruction& operator=(const M480AddliInstruction& rhs);
      
      ~M480AddliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  //---------------------------------------------
  // M480JaddliInstruction 
  //---------------------------------------------
  
  // addli usi rd [br=disp]
  
  
  class M480JaddliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JaddliInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JaddliInstruction(const M480JaddliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JaddliInstruction& operator=(const M480JaddliInstruction& rhs);
      
      ~M480JaddliInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };


  
  //---------------------------------------------
  // M480SubwhiInstruction 
  //---------------------------------------------
  
  // subwhi usi rd [br=disp]
  
  
  class M480SubwhiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubwhiInstruction(unsigned int lineNum,
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
      
      M480SubwhiInstruction(const M480SubwhiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubwhiInstruction& operator=(const M480SubwhiInstruction& rhs);
      
      ~M480SubwhiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  
  //---------------------------------------------
  // M480JsubwhiInstruction 
  //---------------------------------------------
  
  // subwhi usi rd [br=disp]
  
  
  class M480JsubwhiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubwhiInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     UImmPtr src1, 
			     RegPtr dst, 
			     OpndPtr target,
			     BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubwhiInstruction(const M480JsubwhiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubwhiInstruction& operator=(const M480JsubwhiInstruction& rhs);
      
      ~M480JsubwhiInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  //---------------------------------------------
  // M480SubwliInstruction 
  //---------------------------------------------
  
  // subwli usi rd [br=disp]
  
  
  class M480SubwliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubwliInstruction(unsigned int lineNum,
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
      
      M480SubwliInstruction(const M480SubwliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubwliInstruction& operator=(const M480SubwliInstruction& rhs);
      
      ~M480SubwliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  //---------------------------------------------
  // M480JsubwliInstruction 
  //---------------------------------------------
  
  // subwli usi rd [br=disp]
  
  
  class M480JsubwliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubwliInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     UImmPtr src1, 
			     RegPtr dst, 
			     OpndPtr target,
			     BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubwliInstruction(const M480JsubwliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubwliInstruction& operator=(const M480JsubwliInstruction& rhs);
      
      ~M480JsubwliInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SubwwiInstruction 
  //---------------------------------------------
  
  // subwwi usi rd [br=disp]
  
  
  class M480SubwwiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubwwiInstruction(unsigned int lineNum,
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
      
      M480SubwwiInstruction(const M480SubwwiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubwwiInstruction& operator=(const M480SubwwiInstruction& rhs);
      
      ~M480SubwwiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  
  //---------------------------------------------
  // M480JsubwwiInstruction 
  //---------------------------------------------
  
  // subwwi usi rd [br=disp]
  
  
  class M480JsubwwiInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubwwiInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     UImmPtr src1, 
			     RegPtr dst, 
			     OpndPtr target,
			     BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubwwiInstruction(const M480JsubwwiInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubwwiInstruction& operator=(const M480JsubwwiInstruction& rhs);
      
      ~M480JsubwwiInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    

  //---------------------------------------------
  // M480SubliInstruction 
  //---------------------------------------------
  
  // subli usi rd [br=disp]
  
  
  class M480SubliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480SubliInstruction(unsigned int lineNum,
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
      
      M480SubliInstruction(const M480SubliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480SubliInstruction& operator=(const M480SubliInstruction& rhs);
      
      ~M480SubliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    

  //---------------------------------------------
  // M480JsubliInstruction 
  //---------------------------------------------
  
  // subli usi rd [br=disp]
  
  
  class M480JsubliInstruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JsubliInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    UImmPtr src1, 
			    RegPtr dst, 
			    OpndPtr target,
			    BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName, 
				  src1, 
				  dst, 
				  target,
				  probability)
	{}
      
      M480JsubliInstruction(const M480JsubliInstruction& rhs)
	: Alu2OpBranchInstruction(rhs)
	{}
      
      M480JsubliInstruction& operator=(const M480JsubliInstruction& rhs);
      
      ~M480JsubliInstruction()
	{}
      

      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  
  //---------------------------------------------
  // M480FfsInstruction 
  //---------------------------------------------
  
  // ffs rsa rd [ABC] [ZD]
  
  
  class M480FfsInstruction : public Alu2OpFindInstruction
    {
    public: 
      
      M480FfsInstruction(unsigned int lineNum,
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
      
      M480FfsInstruction(const M480FfsInstruction& rhs)
	: Alu2OpFindInstruction(rhs)
	{}
      
      M480FfsInstruction& operator=(const M480FfsInstruction& rhs);
      
      ~M480FfsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480FlsInstruction 
  //---------------------------------------------
  
  // fls rsa rd [ABC] [ZD]
  
  
  class M480FlsInstruction : public Alu2OpFindInstruction
    {
    public: 
      
      M480FlsInstruction(unsigned int lineNum,
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
      
      M480FlsInstruction(const M480FlsInstruction& rhs)
	: Alu2OpFindInstruction(rhs)
	{}
      
      M480FlsInstruction& operator=(const M480FlsInstruction& rhs);
      
      ~M480FlsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ParInstruction 
  //---------------------------------------------
  
  // par rsa rd [ABC]
  
  class M480ParInstruction : public Alu2OpInstruction
    {
    public:

      M480ParInstruction(unsigned int lineNum,
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
      
      M480ParInstruction(const M480ParInstruction& rhs)
	: Alu2OpInstruction(rhs),
	m_abcFlag(rhs.m_abcFlag)
	{}	 
      
      M480ParInstruction& operator=(const M480ParInstruction& rhs); 
      
      ~M480ParInstruction()
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
  // M480AddInstruction 
  //---------------------------------------------
  
  // add rsa rsb rd [MODX] [ABC]
  
  
  class M480AddInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480AddInstruction(unsigned int lineNum,
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
      
      M480AddInstruction(const M480AddInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480AddInstruction& operator=(const M480AddInstruction& rhs);
      
      ~M480AddInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Add4xInstruction 
  //---------------------------------------------
  
  // add4x rsa rsb rd [MODX] [ABC]
  
  
  class M480Add4xInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480Add4xInstruction(unsigned int lineNum,
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
      
      M480Add4xInstruction(const M480Add4xInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480Add4xInstruction& operator=(const M480Add4xInstruction& rhs);
      
      ~M480Add4xInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AddcInstruction 
  //---------------------------------------------
  
  // addc rsa rsb rd [MODX] [ABC]
  
  
  class M480AddcInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480AddcInstruction(unsigned int lineNum,
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
      
      M480AddcInstruction(const M480AddcInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480AddcInstruction& operator=(const M480AddcInstruction& rhs);
      
      ~M480AddcInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AndInstruction 
  //---------------------------------------------
  
  // and rsa rsb rd [MODX] [ABC]
  
  
  class M480AndInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480AndInstruction(unsigned int lineNum,
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
      
      M480AndInstruction(const M480AndInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480AndInstruction& operator=(const M480AndInstruction& rhs);
      
      ~M480AndInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MaxInstruction 
  //---------------------------------------------
  
  // max rsa rsb rd [MODX] [ABC]
  
  
  class M480MaxInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480MaxInstruction(unsigned int lineNum,
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
      
      M480MaxInstruction(const M480MaxInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480MaxInstruction& operator=(const M480MaxInstruction& rhs);
      
      ~M480MaxInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MinInstruction 
  //---------------------------------------------
  
  // min rsa rsb rd [MODX] [ABC]
  
  
  class M480MinInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480MinInstruction(unsigned int lineNum,
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
      
      M480MinInstruction(const M480MinInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480MinInstruction& operator=(const M480MinInstruction& rhs);
      
      ~M480MinInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480OrInstruction 
  //---------------------------------------------
  
  // or rsa rsb rd [MODX] [ABC]
  
  
  class M480OrInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480OrInstruction(unsigned int lineNum,
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
      
      M480OrInstruction(const M480OrInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480OrInstruction& operator=(const M480OrInstruction& rhs);
      
      ~M480OrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SubInstruction 
  //---------------------------------------------
  
  // and sub rsb rd [MODX] [ABC]
  
  
  class M480SubInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480SubInstruction(unsigned int lineNum,
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
      
      M480SubInstruction(const M480SubInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480SubInstruction& operator=(const M480SubInstruction& rhs);
      
      ~M480SubInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SubbInstruction 
  //---------------------------------------------
  
  // and subb rsb rd [MODX] [ABC]
  
  
  class M480SubbInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480SubbInstruction(unsigned int lineNum,
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
      
      M480SubbInstruction(const M480SubbInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480SubbInstruction& operator=(const M480SubbInstruction& rhs);
      
      ~M480SubbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480XorInstruction 
  //---------------------------------------------
  
  // xor rsa rsb rd [MODX] [ABC]
  
  
  class M480XorInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480XorInstruction(unsigned int lineNum,
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
      
      M480XorInstruction(const M480XorInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480XorInstruction& operator=(const M480XorInstruction& rhs);
      
      ~M480XorInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AddiInstruction 
  //---------------------------------------------
  
  // addi rsa usi rd [MODX] [ABC]
  
  
  class M480AddiInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480AddiInstruction(unsigned int lineNum,
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
      
      M480AddiInstruction(const M480AddiInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480AddiInstruction& operator=(const M480AddiInstruction& rhs);
      
      ~M480AddiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AddciInstruction 
  //---------------------------------------------
  
  // addci rsa usi rd [MODX] [ABC]
  
  
  class M480AddciInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480AddciInstruction(unsigned int lineNum,
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
      
      M480AddciInstruction(const M480AddciInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480AddciInstruction& operator=(const M480AddciInstruction& rhs);
      
      ~M480AddciInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480SubiInstruction 
  //---------------------------------------------
  
  // subi rsa usi rd [MODX] [ABC]
  
  
  class M480SubiInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480SubiInstruction(unsigned int lineNum,
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
      
      M480SubiInstruction(const M480SubiInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480SubiInstruction& operator=(const M480SubiInstruction& rhs);
      
      ~M480SubiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480SubbiInstruction 
  //---------------------------------------------
  
  // subbi rsa usi rd [MODX] [ABC]
  
  
  class M480SubbiInstruction : public Alu3OpAbcModInstruction
    {
    public: 
      
      M480SubbiInstruction(unsigned int lineNum,
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
      
      M480SubbiInstruction(const M480SubbiInstruction& rhs)
	: Alu3OpAbcModInstruction(rhs)
	{}
      
      M480SubbiInstruction& operator=(const M480SubbiInstruction& rhs);
      
      ~M480SubbiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480RandInstruction 
  //---------------------------------------------
  
  // rand rsa rsb rd [ABC]
  
  
  class M480RandInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480RandInstruction(unsigned int lineNum,
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
      
      M480RandInstruction(const M480RandInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480RandInstruction& operator=(const M480RandInstruction& rhs);
      
      ~M480RandInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480RotlInstruction 
  //---------------------------------------------
  
  // rotl rsa rsb rd [ABC]
  
  
  class M480RotlInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480RotlInstruction(unsigned int lineNum,
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
      
      M480RotlInstruction(const M480RotlInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480RotlInstruction& operator=(const M480RotlInstruction& rhs);
      
      ~M480RotlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480RotrInstruction 
  //---------------------------------------------
  
  // rotr rsa rsb rd [ABC]
  
  
  class M480RotrInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480RotrInstruction(unsigned int lineNum,
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
      
      M480RotrInstruction(const M480RotrInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480RotrInstruction& operator=(const M480RotrInstruction& rhs);
      
      ~M480RotrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ClrbInstruction 
  //---------------------------------------------
  
  // clrb rsa rsb rd [ABC]
  
  
  class M480ClrbInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ClrbInstruction(unsigned int lineNum,
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
      
      M480ClrbInstruction(const M480ClrbInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ClrbInstruction& operator=(const M480ClrbInstruction& rhs);
      
      ~M480ClrbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SetbInstruction 
  //---------------------------------------------
  
  // setb rsa rsb rd [ABC]
  
  
  class M480SetbInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480SetbInstruction(unsigned int lineNum,
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
      
      M480SetbInstruction(const M480SetbInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480SetbInstruction& operator=(const M480SetbInstruction& rhs);
      
      ~M480SetbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShftInstruction 
  //---------------------------------------------
  
  // shft rsa rsb rd [ABC]
  
  
  class M480ShftInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShftInstruction(unsigned int lineNum,
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
      
      M480ShftInstruction(const M480ShftInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShftInstruction& operator=(const M480ShftInstruction& rhs);
      
      ~M480ShftInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShftaInstruction 
  //---------------------------------------------
  
  // shfta rsa rsb rd [ABC]
  
  
  class M480ShftaInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShftaInstruction(unsigned int lineNum,
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
      
      M480ShftaInstruction(const M480ShftaInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShftaInstruction& operator=(const M480ShftaInstruction& rhs);
      
      ~M480ShftaInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShlInstruction 
  //---------------------------------------------
  
  // shl rsa rsb rd [ABC]
  
  
  class M480ShlInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShlInstruction(unsigned int lineNum,
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
      
      M480ShlInstruction(const M480ShlInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShlInstruction& operator=(const M480ShlInstruction& rhs);
      
      ~M480ShlInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShrInstruction 
  //---------------------------------------------
  
  // shr rsa rsb rd [ABC]
  
  
  class M480ShrInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShrInstruction(unsigned int lineNum,
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
      
      M480ShrInstruction(const M480ShrInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShrInstruction& operator=(const M480ShrInstruction& rhs);
      
      ~M480ShrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShraInstruction 
  //---------------------------------------------
  
  // shra rsa rsb rd [ABC]
  
  
  class M480ShraInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShraInstruction(unsigned int lineNum,
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
      
      M480ShraInstruction(const M480ShraInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShraInstruction& operator=(const M480ShraInstruction& rhs);
      
      ~M480ShraInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480RandiInstruction 
  //---------------------------------------------
  
  // randi rsa uimm6 rd [ABC]
  
  
  class M480RandiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480RandiInstruction(unsigned int lineNum,
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
      
      M480RandiInstruction(const M480RandiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480RandiInstruction& operator=(const M480RandiInstruction& rhs);
      
      ~M480RandiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480RotliInstruction 
  //---------------------------------------------
  
  // rotli rsa usa rd [ABC]
  
  
  class M480RotliInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480RotliInstruction(unsigned int lineNum,
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
      
      M480RotliInstruction(const M480RotliInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480RotliInstruction& operator=(const M480RotliInstruction& rhs);
      
      ~M480RotliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480RotriInstruction 
  //---------------------------------------------
  
  // rotri rsa usa rd [ABC]
  
  
  class M480RotriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480RotriInstruction(unsigned int lineNum,
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
      
      M480RotriInstruction(const M480RotriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480RotriInstruction& operator=(const M480RotriInstruction& rhs);
      
      ~M480RotriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SetbiInstruction 
  //---------------------------------------------
  
  // setbi rsa uimm5 rd [ABC]
  
  
  class M480SetbiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480SetbiInstruction(unsigned int lineNum,
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
      
      M480SetbiInstruction(const M480SetbiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480SetbiInstruction& operator=(const M480SetbiInstruction& rhs);
      
      ~M480SetbiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  
  //---------------------------------------------
  // M480ClrbiInstruction 
  //---------------------------------------------
  
  // clrbi rsa uimm5 rd [ABC]
  
  
  class M480ClrbiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ClrbiInstruction(unsigned int lineNum,
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
      
      M480ClrbiInstruction(const M480ClrbiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ClrbiInstruction& operator=(const M480ClrbiInstruction& rhs);
      
      ~M480ClrbiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShliInstruction 
  //---------------------------------------------
  
  // shli rsa usa rd [ABC]
  
  
  class M480ShliInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShliInstruction(unsigned int lineNum,
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
      
      M480ShliInstruction(const M480ShliInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShliInstruction& operator=(const M480ShliInstruction& rhs);
      
      ~M480ShliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShriInstruction 
  //---------------------------------------------
  
  // shri rsa usa rd [ABC]
  
  
  class M480ShriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShriInstruction(unsigned int lineNum,
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
      
      M480ShriInstruction(const M480ShriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShriInstruction& operator=(const M480ShriInstruction& rhs);
      
      ~M480ShriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ShraiInstruction 
  //---------------------------------------------
  
  // shrai rsa usa rd [ABC]
  
  
  class M480ShraiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480ShraiInstruction(unsigned int lineNum,
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
      
      M480ShraiInstruction(const M480ShraiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480ShraiInstruction& operator=(const M480ShraiInstruction& rhs);
      
      ~M480ShraiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MaxiInstruction 
  //---------------------------------------------
  
  // shrai rsa simm rd [ABC]
  
  
  class M480MaxiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480MaxiInstruction(unsigned int lineNum,
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
      
      M480MaxiInstruction(const M480MaxiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480MaxiInstruction& operator=(const M480MaxiInstruction& rhs);
      
      ~M480MaxiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MiniInstruction 
  //---------------------------------------------
  
  // shrai rsa simm rd [ABC]
  
  
  class M480MiniInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480MiniInstruction(unsigned int lineNum,
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
      
      M480MiniInstruction(const M480MiniInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480MiniInstruction& operator=(const M480MiniInstruction& rhs);
      
      ~M480MiniInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480AndiInstruction 
  //---------------------------------------------
  
  // shrai rsa simm rd [ABC]
  
  
  class M480AndiInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480AndiInstruction(unsigned int lineNum,
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
      
      M480AndiInstruction(const M480AndiInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480AndiInstruction& operator=(const M480AndiInstruction& rhs);
      
      ~M480AndiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480OriInstruction 
  //---------------------------------------------
  
  // shrai rsa si rd [ABC]
  
  
  class M480OriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480OriInstruction(unsigned int lineNum,
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
      
      M480OriInstruction(const M480OriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480OriInstruction& operator=(const M480OriInstruction& rhs);
      
      ~M480OriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480XoriInstruction 
  //---------------------------------------------
  
  // shrai rsa si rd [ABC]
  
  
  class M480XoriInstruction : public Alu3OpAbcInstruction
    {
    public: 
      
      M480XoriInstruction(unsigned int lineNum,
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
      
      M480XoriInstruction(const M480XoriInstruction& rhs)
	: Alu3OpAbcInstruction(rhs)
	{}
      
      M480XoriInstruction& operator=(const M480XoriInstruction& rhs);
      
      ~M480XoriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MulInstruction 
  //---------------------------------------------
  
  // mul rsa rsb rd [SX]
  
  
  class M480MulInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M480MulInstruction(unsigned int lineNum,
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
      
      M480MulInstruction(const M480MulInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M480MulInstruction& operator=(const M480MulInstruction& rhs);
      
      ~M480MulInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MulhInstruction 
  //---------------------------------------------
  
  // mulh rsa rsb rd [SX]
  
  
  class M480MulhInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M480MulhInstruction(unsigned int lineNum,
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
      
      M480MulhInstruction(const M480MulhInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M480MulhInstruction& operator=(const M480MulhInstruction& rhs);
      
      ~M480MulhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480MuliInstruction 
  //---------------------------------------------
  
  // muli rsa rsb rd [SX]
  
  
  class M480MuliInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M480MuliInstruction(unsigned int lineNum,
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
      
      M480MuliInstruction(const M480MuliInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M480MuliInstruction& operator=(const M480MuliInstruction& rhs);
      
      ~M480MuliInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MulhiInstruction 
  //---------------------------------------------
  
  // mulhi rsa rsb rd [SX]
  
  
  class M480MulhiInstruction : public Alu3OpSxInstruction
    {
    public: 
      
      M480MulhiInstruction(unsigned int lineNum,
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
      
      M480MulhiInstruction(const M480MulhiInstruction& rhs)
	: Alu3OpSxInstruction(rhs)
	{}
      
      M480MulhiInstruction& operator=(const M480MulhiInstruction& rhs);
      
      ~M480MulhiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480Addne Instruction
  //---------------------------------------------
  
  // addne rsa rsb rdi
  
  class M480AddneInstruction : public Alu3OpInstruction
    {
    public:
      
      M480AddneInstruction(unsigned int lineNum,
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
      
      M480AddneInstruction(const M480AddneInstruction& rhs)
	: Alu3OpInstruction(rhs)
	{}
      
      M480AddneInstruction& operator=(const M480AddneInstruction& rhs);
      
      ~M480AddneInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Addnei Instruction
  //---------------------------------------------
  
  // addnei rsa usi rdi
  
  class M480AddneiInstruction : public Alu3OpInstruction
    {
    public:
      
      M480AddneiInstruction(unsigned int lineNum,
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
      
      M480AddneiInstruction(const M480AddneiInstruction& rhs)
	: Alu3OpInstruction(rhs)
	{}
      
      M480AddneiInstruction& operator=(const M480AddneiInstruction& rhs);
      
      ~M480AddneiInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480ByteswInstruction 
  //---------------------------------------------
  
  // bytesw rsa rd b0# b1# b2# b3# [ABC]
  
  class M480ByteswInstruction : public AluOpInstruction
    {
    public:
      
      M480ByteswInstruction(unsigned int lineNum,
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
      
      M480ByteswInstruction(const M480ByteswInstruction& rhs)
	: AluOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_b0(rhs.m_b0),
	m_b1(rhs.m_b1),
	m_b2(rhs.m_b2),
	m_b3(rhs.m_b3),
	m_abcFlag(rhs.m_abcFlag)
	{}	 
      
      M480ByteswInstruction& operator=(const M480ByteswInstruction& rhs); 
      
      ~M480ByteswInstruction()
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
  // M480Bcdr Instruction
  //---------------------------------------------
  
  // bcdr rsb [!]ess# [rd(60:62)] [BF] [C]
  
  class M480BcdrInstruction : public CondBranchInstruction
    {
    public:
      
      M480BcdrInstruction(unsigned int lineNum,
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
      
      M480BcdrInstruction(const M480BcdrInstruction& rhs)
	: CondBranchInstruction(rhs)
	{}
      
      M480BcdrInstruction& operator=(const M480BcdrInstruction& rhs);
      
      ~M480BcdrInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480Jbcdr Instruction
  //---------------------------------------------
  
  // bcdr rsb [!]ess# [rd(60:62)] [BF] [C]
  
  class M480JbcdrInstruction : public CondBranchInstruction
    {
    public:
      
      M480JbcdrInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   EssPtr ess, 
			   OpndPtr dst, 
			   OpndPtr flags,
			   OpndPtr targetList,
			   BranchProbability probability)
        : CondBranchInstruction(lineNum,
				srcLineNum,
				srcFileName, 
				src1, 
				ess, 
				dst, 
				flags,
				probability),
	m_targetList(targetList)
	{}
      
      M480JbcdrInstruction(const M480JbcdrInstruction& rhs)
	: CondBranchInstruction(rhs),
	m_targetList(rhs.m_targetList)
	{}
      
      M480JbcdrInstruction& operator=(const M480JbcdrInstruction& rhs);
      
      ~M480JbcdrInstruction()
	{}

      OpndPtr getTargetLabelList() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      OpndPtr m_targetList;
    };
  
  
  //---------------------------------------------
  // M480Bcr Instruction
  //---------------------------------------------
  
  // bcr rsb [!]ess# [rd(60:62)] [BF] [C]
  
  class M480BcrInstruction : public CondBranchInstruction
    {
    public:
      
      M480BcrInstruction(unsigned int lineNum,
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
      
      M480BcrInstruction(const M480BcrInstruction& rhs)
	: CondBranchInstruction(rhs)
	{}
      
      M480BcrInstruction& operator=(const M480BcrInstruction& rhs);
      
      ~M480BcrInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480Jbcr Instruction
  //---------------------------------------------
  
  // bcr rsb [!]ess# [rd(60:62)] [BF] [C]
  
  class M480JbcrInstruction : public CondBranchInstruction
    {
    public:
      
      M480JbcrInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  EssPtr ess, 
			  OpndPtr dst, 
			  OpndPtr flags,
			  OpndPtr targetList,
			  BranchProbability probability)
        : CondBranchInstruction(lineNum,
				srcLineNum,
				srcFileName, 
				src1, 
				ess, 
				dst, 
				flags,
				probability),
	m_targetList(targetList)
	{}
      
      M480JbcrInstruction(const M480JbcrInstruction& rhs)
	: CondBranchInstruction(rhs),
	m_targetList(rhs.m_targetList)
	{}
      
      M480JbcrInstruction& operator=(const M480JbcrInstruction& rhs);
      
      ~M480JbcrInstruction()
	{}

      
      OpndPtr getTargetLabelList() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      OpndPtr m_targetList;
    };
  
  
  //---------------------------------------------
  // M480Bcdi Instruction
  //---------------------------------------------
  
  // bcdi disp[15:0] [!]ess# [rd(60:62)] [BF] [C]
  
  class M480BcdiInstruction : public CondBranchImmedInstruction
    {
    public:
      
      M480BcdiInstruction(unsigned int lineNum,
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
      
      M480BcdiInstruction(const M480BcdiInstruction& rhs)
	: CondBranchImmedInstruction(rhs)
	{}
      
      M480BcdiInstruction& operator=(const M480BcdiInstruction& rhs);
      
      ~M480BcdiInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
   
  //---------------------------------------------
  // M480Jbcdi Instruction
  //---------------------------------------------
  
  // bcdi disp[15:0] [!]ess# [rd(60:62)] [BF] [C]
  
  class M480JbcdiInstruction : public CondBranchImmedInstruction
    {
    public:
      
      M480JbcdiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   OpndPtr src1, 
			   EssPtr ess, 
			   OpndPtr dst, 
			   OpndPtr flags,
			   BranchProbability probability)
        : CondBranchImmedInstruction(lineNum,
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     ess, 
				     dst, 
				     flags,
				     probability)
	{}
      
      M480JbcdiInstruction(const M480JbcdiInstruction& rhs)
	: CondBranchImmedInstruction(rhs)
	{}
      
      M480JbcdiInstruction& operator=(const M480JbcdiInstruction& rhs);
      
      ~M480JbcdiInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Bci Instruction
  //---------------------------------------------
  
  // bci disp[15:0] [!]ess# [rd(60:62)] [BF] [C]
  
  class M480BciInstruction : public CondBranchImmedInstruction
    {
    public:
      
      M480BciInstruction(unsigned int lineNum,
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
      
      M480BciInstruction(const M480BciInstruction& rhs)
	: CondBranchImmedInstruction(rhs)
	{}
      
      M480BciInstruction& operator=(const M480BciInstruction& rhs);
      
      ~M480BciInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Jbci Instruction
  //---------------------------------------------
  
  // bci disp[15:0] [!]ess# [rd(60:62)] [BF] [C]
  
  class M480JbciInstruction : public CondBranchImmedInstruction
    {
    public:
      
      M480JbciInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr src1, 
			  EssPtr ess, 
			  OpndPtr dst, 
			  OpndPtr flags,
			  BranchProbability probability)
        : CondBranchImmedInstruction(lineNum,
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     ess, 
				     dst, 
				     flags,
				     probability)
	{}
      
      M480JbciInstruction(const M480JbciInstruction& rhs)
	: CondBranchImmedInstruction(rhs)
	{}
      
      M480JbciInstruction& operator=(const M480JbciInstruction& rhs);
      
      ~M480JbciInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  
  //---------------------------------------------
  // M480Bnzr Instruction
  //---------------------------------------------
  
  // bnzr rsa rsb
  
  class M480BnzrInstruction : public ZeroBranchInstruction
    {
    public:
      
      M480BnzrInstruction(unsigned int lineNum,
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
      
      M480BnzrInstruction(const M480BnzrInstruction& rhs)
	: ZeroBranchInstruction(rhs)
	{}
      
      M480BnzrInstruction& operator=(const M480BnzrInstruction& rhs);
      
      ~M480BnzrInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
   
  //---------------------------------------------
  // M480Jbnzr Instruction
  //---------------------------------------------
  
  // bnzr rsa rsb
  
  class M480JbnzrInstruction : public ZeroBranchInstruction
    {
    public:
      
      M480JbnzrInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   RegPtr src2, 
			   OpndPtr cmpReg, 
			   OpndPtr targetList,
			   BranchProbability probability) 
        : ZeroBranchInstruction(lineNum,
				srcLineNum,
				srcFileName, 
				src1, 
				src2, 
				cmpReg,
				probability),
	m_targetList(targetList)
	{}
      
      M480JbnzrInstruction(const M480JbnzrInstruction& rhs)
	: ZeroBranchInstruction(rhs),
	m_targetList(rhs.m_targetList)
	{}
      
      M480JbnzrInstruction& operator=(const M480JbnzrInstruction& rhs);
      
      ~M480JbnzrInstruction()
	{}
      
      OpndPtr getTargetLabelList() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      OpndPtr m_targetList;
    };
  

  
  //---------------------------------------------
  // M480Bzr Instruction
  //---------------------------------------------
  
  // bzr rsa rsb
  
  class M480BzrInstruction : public ZeroBranchInstruction
    {
    public:
      
      M480BzrInstruction(unsigned int lineNum,
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
      
      M480BzrInstruction(const M480BzrInstruction& rhs)
	: ZeroBranchInstruction(rhs)
	{}
      
      M480BzrInstruction& operator=(const M480BzrInstruction& rhs);
      
      ~M480BzrInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
   
  //---------------------------------------------
  // M480Jbzr Instruction
  //---------------------------------------------
  
  // bzr rsa rsb
  
  class M480JbzrInstruction : public ZeroBranchInstruction
    {
    public:
      
      M480JbzrInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  OpndPtr cmpReg,
			  OpndPtr targetList,
			  BranchProbability probability) 
        : ZeroBranchInstruction(lineNum,
				srcLineNum,
				srcFileName, 
				src1, 
				src2, 
				cmpReg,
				probability),
	m_targetList(targetList)
	{}
      
      M480JbzrInstruction(const M480JbzrInstruction& rhs)
	: ZeroBranchInstruction(rhs),
	m_targetList(rhs.m_targetList)
	{}
      
      M480JbzrInstruction& operator=(const M480JbzrInstruction& rhs);
      
      ~M480JbzrInstruction()
	{}

     
      OpndPtr getTargetLabelList() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;

    private:

      OpndPtr m_targetList;
    };
  
  
  //---------------------------------------------
  // M480Bnzi Instruction
  //---------------------------------------------
  
  // bnzi rsa disp[15:0]
  
  class M480BnziInstruction : public ZeroBranchImmedInstruction
    {
    public:
      
      M480BnziInstruction(unsigned int lineNum,
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
      
      M480BnziInstruction(const M480BnziInstruction& rhs)
	: ZeroBranchImmedInstruction(rhs)
	{}
      
      M480BnziInstruction& operator=(const M480BnziInstruction& rhs);
      
      ~M480BnziInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  //---------------------------------------------
  // M480Jbnzi Instruction
  //---------------------------------------------
  
  // bnzi rsa disp[15:0]
  
  class M480JbnziInstruction : public ZeroBranchImmedInstruction
    {
    public:
      
      M480JbnziInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   OpndPtr src2, 
			   OpndPtr cmpReg,
			   BranchProbability probability) 
        : ZeroBranchImmedInstruction(lineNum,
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     cmpReg,
				     probability)
	{}
      
      M480JbnziInstruction(const M480JbnziInstruction& rhs)
	: ZeroBranchImmedInstruction(rhs)
	{}
      
      M480JbnziInstruction& operator=(const M480JbnziInstruction& rhs);
      
      ~M480JbnziInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Bzi Instruction
  //---------------------------------------------
  
  // bzi rsa disp[15:0]
  
  class M480BziInstruction : public ZeroBranchImmedInstruction
    {
    public:
      
      M480BziInstruction(unsigned int lineNum,
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
      
      M480BziInstruction(const M480BziInstruction& rhs)
	: ZeroBranchImmedInstruction(rhs)
	{}
      
      M480BziInstruction& operator=(const M480BziInstruction& rhs);
      
      ~M480BziInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480Jbzi Instruction
  //---------------------------------------------
  
  // bzi rsa disp[15:0]
  
  class M480JbziInstruction : public ZeroBranchImmedInstruction
    {
    public:
      
      M480JbziInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  OpndPtr src2, 
			  OpndPtr cmpReg,
			  BranchProbability probability) 
        : ZeroBranchImmedInstruction(lineNum,
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     cmpReg,
				     probability)
	{}
      
      M480JbziInstruction(const M480JbziInstruction& rhs)
	: ZeroBranchImmedInstruction(rhs)
	{}
      
      M480JbziInstruction& operator=(const M480JbziInstruction& rhs);
      
      ~M480JbziInstruction()
	{}


      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480Tsetb Instruction
  //---------------------------------------------
  
  // tsetb rsa bitpos br=disp
  
  class M480TsetbInstruction : public TestBitBranchInstruction
    {
    public:
      
      M480TsetbInstruction(unsigned int lineNum,
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
      
      M480TsetbInstruction(const M480TsetbInstruction& rhs)
	: TestBitBranchInstruction(rhs)
	{}
      
      M480TsetbInstruction& operator=(const M480TsetbInstruction& rhs);
      
      ~M480TsetbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  //---------------------------------------------
  // M480Jtsetb Instruction
  //---------------------------------------------
  
  // tsetb rsa bitpos br=disp
  
  class M480JtsetbInstruction : public TestBitBranchInstruction
    {
    public:
      
      M480JtsetbInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    UImmPtr bitpos, 
			    OpndPtr disp,
			    BranchProbability probability) 
        : TestBitBranchInstruction(lineNum,
				   srcLineNum,
				   srcFileName, 
				   src1, 
				   bitpos, 
				   disp,
				   probability)
	{}
      
      M480JtsetbInstruction(const M480JtsetbInstruction& rhs)
	: TestBitBranchInstruction(rhs)
	{}
      
      M480JtsetbInstruction& operator=(const M480JtsetbInstruction& rhs);
      
      ~M480JtsetbInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Tclrb Instruction
  //---------------------------------------------
  
  // tclrb rsa bitpos br=disp
  
  class M480TclrbInstruction : public TestBitBranchInstruction
    {
    public:
      
      M480TclrbInstruction(unsigned int lineNum,
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
      
      M480TclrbInstruction(const M480TclrbInstruction& rhs)
	: TestBitBranchInstruction(rhs)
	{}
      
      M480TclrbInstruction& operator=(const M480TclrbInstruction& rhs);
      
      ~M480TclrbInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480Jtclrb Instruction
  //---------------------------------------------
  
  // tclrb rsa bitpos br=disp
  
  class M480JtclrbInstruction : public TestBitBranchInstruction
    {
    public:
      
      M480JtclrbInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    RegPtr src1, 
			    UImmPtr bitpos, 
			    OpndPtr disp,
			    BranchProbability probability) 
        : TestBitBranchInstruction(lineNum,
				   srcLineNum,
				   srcFileName, 
				   src1, 
				   bitpos, 
				   disp,
				   probability)
	{}
      
      M480JtclrbInstruction(const M480JtclrbInstruction& rhs)
	: TestBitBranchInstruction(rhs)
	{}
      
      M480JtclrbInstruction& operator=(const M480JtclrbInstruction& rhs);
      
      ~M480JtclrbInstruction()
	{}
      


      bool isPseudoInsn() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Rnmi Instruction
  //---------------------------------------------
  
  // rnmi [DI]
  
  class M480RnmiInstruction : public ReturnOpInstruction
    {
    public:
      
      M480RnmiInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr diFlag) 
        : ReturnOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName, 
			      diFlag)
	{}
      
      M480RnmiInstruction(const M480RnmiInstruction& rhs)
	: ReturnOpInstruction(rhs)
	{}
      
      M480RnmiInstruction& operator=(const M480RnmiInstruction& rhs);
      
      ~M480RnmiInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
   
  //---------------------------------------------
  // M480Jrnmi Instruction
  //---------------------------------------------
  
  // rnmi [DI]
  
  class M480JrnmiInstruction : public ReturnOpInstruction
    {
    public:
      
      M480JrnmiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   OpndPtr diFlag) 
        : ReturnOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName, 
			      diFlag)
	{}
      
      M480JrnmiInstruction(const M480JrnmiInstruction& rhs)
	: ReturnOpInstruction(rhs)
	{}
      
      M480JrnmiInstruction& operator=(const M480JrnmiInstruction& rhs);
      
      ~M480JrnmiInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480Rint Instruction
  //---------------------------------------------
  
  // rint [DI]
  
  class M480RintInstruction : public ReturnOpInstruction
    {
    public:
      
      M480RintInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr diFlag) 
        : ReturnOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName, 
			      diFlag)
	{}
      
      M480RintInstruction(const M480RintInstruction& rhs)
	: ReturnOpInstruction(rhs)
	{}
      
      M480RintInstruction& operator=(const M480RintInstruction& rhs);
      
      ~M480RintInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
      
  //---------------------------------------------
  // M480Jrint Instruction
  //---------------------------------------------
  
  // rint [DI]
  
  class M480JrintInstruction : public ReturnOpInstruction
    {
    public:
      
      M480JrintInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   OpndPtr diFlag) 
        : ReturnOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName, 
			      diFlag)
	{}
      
      M480JrintInstruction(const M480JrintInstruction& rhs)
	: ReturnOpInstruction(rhs)
	{}
      
      M480JrintInstruction& operator=(const M480JrintInstruction& rhs);
      
      ~M480JrintInstruction()
	{}
      

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
    
  
  //---------------------------------------------
  // M480Brs Instruction
  //---------------------------------------------
  
  // brs [rd(60:62]
  
  class M480BrsInstruction : public BranchOpInstruction
    {
    public:
      
      M480BrsInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 OpndPtr dst)
	: BranchOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName),
	m_dst(dst) 
	{}
      
      M480BrsInstruction(const M480BrsInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_dst(rhs.m_dst)
	{}
      
      M480BrsInstruction& operator=(const M480BrsInstruction& rhs);
      
      ~M480BrsInstruction()
	{}

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isReturnInsn() const;

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
  // M480Jbrs Instruction
  //---------------------------------------------
  
  // brs [rd(60:62]
  
  class M480JbrsInstruction : public BranchOpInstruction
    {
    public:
      
      M480JbrsInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr dst)
	: BranchOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName),
	m_dst(dst) 
	{}
      
      M480JbrsInstruction(const M480JbrsInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_dst(rhs.m_dst)
	{}
      
      M480JbrsInstruction& operator=(const M480JbrsInstruction& rhs);
      
      ~M480JbrsInstruction()
	{}

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isReturnInsn() const;

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
  // M480Brsl Instruction
  //---------------------------------------------
  
  // brsl [UNLNK] [DLNK] [FLUSH] [PRE]
  
  class M480BrslInstruction : public BranchOpInstruction
    {
    public:
      
      M480BrslInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  OpndPtr flags)
	: BranchOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName),
	m_flags(flags)  
	{}
      
      M480BrslInstruction(const M480BrslInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_flags(rhs.m_flags)
	{}
      
      M480BrslInstruction& operator=(const M480BrslInstruction& rhs);
      
      ~M480BrslInstruction()
	{}
      
      OpndPtr getBrslFlags() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isReturnInsn() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_flags;
      
    };
   
  //---------------------------------------------
  // M480Jbrsl Instruction
  //---------------------------------------------
  
  // brsl [UNLNK] [DLNK] [FLUSH] [PRE]
  
  class M480JbrslInstruction : public BranchOpInstruction
    {
    public:
      
      M480JbrslInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   OpndPtr flags)
	: BranchOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName),
	m_flags(flags)  
	{}
      
      M480JbrslInstruction(const M480JbrslInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_flags(rhs.m_flags)
	{}
      
      M480JbrslInstruction& operator=(const M480JbrslInstruction& rhs);
      
      ~M480JbrslInstruction()
	{}
      
      OpndPtr getBrslFlags() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isReturnInsn() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_flags;
      
    };
  
  
  //---------------------------------------------
  // M480Brspre Instruction
  //---------------------------------------------
  
  // brspre
  
  class M480BrspreInstruction : public OctaveInstruction
    {
    public:
      
      M480BrspreInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName) 
	: OctaveInstruction(lineNum,
			    srcLineNum,
			    srcFileName)
	{}
      
      M480BrspreInstruction(const M480BrspreInstruction& rhs)
	: OctaveInstruction(rhs)
	{}
      
      M480BrspreInstruction& operator=(const M480BrspreInstruction& rhs);
      
      ~M480BrspreInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    };
  
  
  //---------------------------------------------
  // M480Cmp Instruction
  //---------------------------------------------
  
  // cmp rsa rsb [br=disp ABC]
  
  class M480CmpInstruction : public CompareOpBranchInstruction
    {
    public:
      
      M480CmpInstruction(unsigned int lineNum,
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
      
      M480CmpInstruction(const M480CmpInstruction& rhs)
	: CompareOpBranchInstruction(rhs)
	{}
      
      M480CmpInstruction& operator=(const M480CmpInstruction& rhs);
      
      ~M480CmpInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  class M480JcmpInstruction : public CompareOpBranchInstruction
    {
    public:
      
      M480JcmpInstruction(unsigned int lineNum,
			  unsigned int srcLineNum,
			  const char* srcFileName, 
			  RegPtr src1, 
			  RegPtr src2, 
			  OpndPtr abcFlag, 
			  OpndPtr branchTarget,
			  BranchProbability probability)
        : CompareOpBranchInstruction(lineNum,
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     abcFlag, 
				     branchTarget,
				     probability)
	{}
      
      M480JcmpInstruction(const M480JcmpInstruction& rhs)
	: CompareOpBranchInstruction(rhs)
	{}
      
      M480JcmpInstruction& operator=(const M480JcmpInstruction& rhs);
      
      ~M480JcmpInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Cmpi Instruction
  //---------------------------------------------
  
  // cmpi rsa si [br=disp ABC]
  
  class M480CmpiInstruction : public CompareOpBranchInstruction
    {
    public:
      
      M480CmpiInstruction(unsigned int lineNum,
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
      
      M480CmpiInstruction(const M480CmpiInstruction& rhs)
	: CompareOpBranchInstruction(rhs)
	{}
      
      M480CmpiInstruction& operator=(const M480CmpiInstruction& rhs);
      
      ~M480CmpiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  class M480JcmpiInstruction : public CompareOpBranchInstruction
    {
    public:
      
      M480JcmpiInstruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src1, 
			   SImmPtr src2, 
			   OpndPtr abcFlag, 
			   OpndPtr branchTarget,
			   BranchProbability probability)
        : CompareOpBranchInstruction(lineNum,
				     srcLineNum,
				     srcFileName, 
				     src1, 
				     src2, 
				     abcFlag, 
				     branchTarget,
				     probability)
	{}
      
      M480JcmpiInstruction(const M480JcmpiInstruction& rhs)
	: CompareOpBranchInstruction(rhs)
	{}
      
      M480JcmpiInstruction& operator=(const M480JcmpiInstruction& rhs);
      
      ~M480JcmpiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Cmpr Instruction
  //---------------------------------------------
  
  // cmpr rsa rsb rd [ABC] [SIGN]
  
  class M480CmprInstruction : public CompareOpSignInstruction
    {
    public:
      
      M480CmprInstruction(unsigned int lineNum,
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
      
      M480CmprInstruction(const M480CmprInstruction& rhs)
	: CompareOpSignInstruction(rhs)
	{}
      
      M480CmprInstruction& operator=(const M480CmprInstruction& rhs);
      
      ~M480CmprInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Cmpri Instruction
  //---------------------------------------------
  
  // cmpr rsa si rd [ABC] [SIGN]
  
  class M480CmpriInstruction : public CompareOpSignInstruction
    {
    public:
      
      M480CmpriInstruction(unsigned int lineNum,
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
      
      M480CmpriInstruction(const M480CmpriInstruction& rhs)
	: CompareOpSignInstruction(rhs)
	{}
      
      M480CmpriInstruction& operator=(const M480CmpriInstruction& rhs);
      
      ~M480CmpriInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480Bi Instruction
  //---------------------------------------------
  
  // bi disp[21:0] [rd(60:62)] [CD]
  
  class M480BiInstruction : public BranchOpInstruction
    {
    public:
      
      M480BiInstruction(unsigned int lineNum,
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
      
      M480BiInstruction(const M480BiInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_cdFlag(rhs.m_cdFlag)
	{}
      
      M480BiInstruction& operator=(const M480BiInstruction& rhs);
      
      ~M480BiInstruction()
	{}
      
      OpndPtr getSrc1() const;
      
      OpndPtr getDst() const;
      
      OpndPtr getCdFlag() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

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
  // M480Jbi Instruction
  //---------------------------------------------
  
  // bi disp[21:0] [rd(60:62)] [CD]
  
  class M480JbiInstruction : public BranchOpInstruction
    {
    public:
      
      M480JbiInstruction(unsigned int lineNum,
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
      
      M480JbiInstruction(const M480JbiInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_cdFlag(rhs.m_cdFlag)
	{}
      
      M480JbiInstruction& operator=(const M480JbiInstruction& rhs);
      
      ~M480JbiInstruction()
	{}
      
      OpndPtr getSrc1() const;
      
      OpndPtr getDst() const;
      
      OpndPtr getCdFlag() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      BranchProbability getBranchProbability() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

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
  // M480Br Instruction
  //---------------------------------------------
  
  // br rsb [rd(60:62)]
  
  class M480BrInstruction : public BranchOpInstruction
    {
    public:
      
      M480BrInstruction(unsigned int lineNum,
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
      
      M480BrInstruction(const M480BrInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst)
	{}
      
      M480BrInstruction& operator=(const M480BrInstruction& rhs);
      
      ~M480BrInstruction()
	{}
      
      RegPtr getSrc1() const;
      
      OpndPtr getDst() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      bool isReturnInsn() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;

    private:

      bool hasReturnReg() const;
      
    private:
      
      RegPtr m_src1;
      OpndPtr m_dst;
      
    };


  //---------------------------------------------
  // M480Br Instruction
  //---------------------------------------------
  
  // jtablebr rsb label
  
  class M480JtablebrInstruction : public BranchOpInstruction
    {
    public:
      
      M480JtablebrInstruction(unsigned int lineNum,
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
      
      M480JtablebrInstruction(const M480JtablebrInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst)
	{}
      
      M480JtablebrInstruction& operator=(const M480JtablebrInstruction& rhs);
      
      ~M480JtablebrInstruction()
	{}
      
      RegPtr getSrc1() const;
      
      OpndPtr getDst() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      
      BranchProbability getBranchProbability() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_src1;
      OpndPtr m_dst;
      
    };

  
  //---------------------------------------------
  // M480Br Instruction
  //---------------------------------------------
  
  // jtablebr_r rsb label
  
  class M480JtableRelativebrInstruction : public BranchOpInstruction
    {
    public:
      
      M480JtableRelativebrInstruction(unsigned int lineNum,
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
      
      M480JtableRelativebrInstruction(const M480JtableRelativebrInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst)
	{}
      
      M480JtableRelativebrInstruction& operator=(const M480JtableRelativebrInstruction& rhs);
      
      ~M480JtableRelativebrInstruction()
	{}
      
      RegPtr getSrc1() const;
      
      OpndPtr getDst() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;
       
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_src1;
      OpndPtr m_dst;
      
    };

  //---------------------------------------------
  // M480Jbr Instruction
  //---------------------------------------------
  
  // br rsb [rd(60:62)]
  
  class M480JbrInstruction : public BranchOpInstruction
    {
    public:
      
      M480JbrInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName, 
			 RegPtr src1, 
			 OpndPtr dst, 
			 OpndPtr targetList)
        : BranchOpInstruction(lineNum,
			      srcLineNum,
			      srcFileName),
	m_src1(src1),
	m_dst(dst),
	m_targetList(targetList)
	{}
      
      M480JbrInstruction(const M480JbrInstruction& rhs)
	: BranchOpInstruction(rhs),
	m_src1(rhs.m_src1),
	m_dst(rhs.m_dst),
	m_targetList(rhs.m_targetList)
	{}
      
      M480JbrInstruction& operator=(const M480JbrInstruction& rhs);
      
      ~M480JbrInstruction()
	{}
      
      RegPtr getSrc1() const;
      
      OpndPtr getDst() const;
      
      OpndPtr getTargetLabelList() const;

      bool isReturnInsn() const;

      bool isBranchInsn() const;

      bool isValidDslotInsn() const;

      bool isCallInsn() const;
      
      BranchProbability getBranchProbability() const;
       
      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;

    private:

      bool hasReturnReg() const;
      
    private:
      
      RegPtr m_src1;
      OpndPtr m_dst;
      OpndPtr m_targetList;
    };
  
  //---------------------------------------------
  // M480DepbInstruction 
  //---------------------------------------------
  
  // depb rsb rsb-bit# rd rd-bit# #bits [Z]
  
  
  class M480DepbInstruction : public BitOpInstruction
    {
    public: 
      
      M480DepbInstruction(unsigned int lineNum,
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
      
      M480DepbInstruction(const M480DepbInstruction& rhs)
	: BitOpInstruction(rhs),
	m_depbFlag(rhs.m_depbFlag)
	{}
      
      M480DepbInstruction& operator=(const M480DepbInstruction& rhs);
      
      ~M480DepbInstruction()
	{}
            
      OpndPtr getDepbFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_depbFlag;
      
    };
  
  
  //---------------------------------------------
  // M480ExtbInstruction 
  //---------------------------------------------
  
  // extb rsb rsb-bit# rd rd-bit# #bits [SIGN]
  
  
  class M480ExtbInstruction : public BitOpInstruction
    {
    public: 
      
      M480ExtbInstruction(unsigned int lineNum,
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
      
      M480ExtbInstruction(const M480ExtbInstruction& rhs)
	: BitOpInstruction(rhs),
	m_sign(rhs.m_sign)
	{}
      
      M480ExtbInstruction& operator=(const M480ExtbInstruction& rhs);
      
      ~M480ExtbInstruction()
	{}
            
      OpndPtr getSignFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_sign;
      
    };
  
  
  //---------------------------------------------
  // M480DepbiInstruction 
  //---------------------------------------------
  
  // depb usi rd rd-bit# #bits [Z]
  
  
  class M480DepbiInstruction : public BitOpImmInstruction
    {
    public: 
      
      M480DepbiInstruction(unsigned int lineNum,
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
      
      M480DepbiInstruction(const M480DepbiInstruction& rhs)
	: BitOpImmInstruction(rhs),
	m_depbFlag(rhs.m_depbFlag)
	{}
      
      M480DepbiInstruction& operator=(const M480DepbiInstruction& rhs);
      
      ~M480DepbiInstruction()
	{}
            
      OpndPtr getDepbFlag() const;
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      OpndPtr m_depbFlag;
      
    };
  
  
  //---------------------------------------------
  // M480CmovInstruction 
  //---------------------------------------------
  
  // cmov rsa rsb rd [!]ess#
  
  
  class M480CmovInstruction : public CmovOpInstruction
    {
    public: 
      
      M480CmovInstruction(unsigned int lineNum,
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
      
      M480CmovInstruction(const M480CmovInstruction& rhs)
	: CmovOpInstruction(rhs)
	{}
      
      M480CmovInstruction& operator=(const M480CmovInstruction& rhs);
      
      ~M480CmovInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480CmoviInstruction 
  //---------------------------------------------
  
  // cmovi rsa uimm rd [!]ess#
  
  
  class M480CmoviInstruction : public CmovOpInstruction
    {
    public: 
      
      M480CmoviInstruction(unsigned int lineNum,
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
      
      M480CmoviInstruction(const M480CmoviInstruction& rhs)
	: CmovOpInstruction(rhs)
	{}
      
      M480CmoviInstruction& operator=(const M480CmoviInstruction& rhs);
      
      ~M480CmoviInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480DmapInstruction 
  //---------------------------------------------
  
  // dmap rsa-rsa+1 dmaflags
  
  
  class M480DmapInstruction : public DmaOpInstruction
    {
    public: 
      
      M480DmapInstruction(unsigned int lineNum,
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
      
      M480DmapInstruction(const M480DmapInstruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M480DmapInstruction& operator=(const M480DmapInstruction& rhs);
      
      ~M480DmapInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480DmasrInstruction 
  //---------------------------------------------
  
  // dmasr rsa DMAflags
  
  
  class M480DmasrInstruction : public DmaOpInstruction
    {
    public: 
      
      M480DmasrInstruction(unsigned int lineNum,
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
      
      M480DmasrInstruction(const M480DmasrInstruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M480DmasrInstruction& operator=(const M480DmasrInstruction& rhs);
      
      ~M480DmasrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480Dmau0Instruction 
  //---------------------------------------------
  
  // dmau0 rsa-rsa+1 dmaflags
  
  
  class M480Dmau0Instruction : public DmaOpInstruction
    {
    public: 
      
      M480Dmau0Instruction(unsigned int lineNum,
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
      
      M480Dmau0Instruction(const M480Dmau0Instruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M480Dmau0Instruction& operator=(const M480Dmau0Instruction& rhs);
      
      ~M480Dmau0Instruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480Dmau1Instruction 
  //---------------------------------------------
  
  // dmau1 rsa-rsa+1 dmaflags
  
  
  class M480Dmau1Instruction : public DmaOpInstruction
    {
    public: 
      
      M480Dmau1Instruction(unsigned int lineNum,
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
      
      M480Dmau1Instruction(const M480Dmau1Instruction& rhs)
	: DmaOpInstruction(rhs)
	{}
      
      M480Dmau1Instruction& operator=(const M480Dmau1Instruction& rhs);
      
      ~M480Dmau1Instruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480LihInstruction 
  //---------------------------------------------
  
  // lih rd[0-127] imm
  
  
  class M480LihInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M480LihInstruction(unsigned int lineNum,
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
      
      M480LihInstruction(const M480LihInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M480LihInstruction& operator=(const M480LihInstruction& rhs);
      
      ~M480LihInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480LilInstruction 
  //---------------------------------------------
  
  // lil rd[0-127] imm
  
  
  class M480LilInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M480LilInstruction(unsigned int lineNum,
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
      
      M480LilInstruction(const M480LilInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M480LilInstruction& operator=(const M480LilInstruction& rhs);
      
      ~M480LilInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480LaihInstruction 
  //---------------------------------------------
  
  // laih rd[0-63] imm
  
  
  class M480LaihInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M480LaihInstruction(unsigned int lineNum,
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
      
      M480LaihInstruction(const M480LaihInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M480LaihInstruction& operator=(const M480LaihInstruction& rhs);
      
      ~M480LaihInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480LailInstruction 
  //---------------------------------------------
  
  // lail rd[0-63] imm
  
  
  class M480LailInstruction : public LoadImmediateInstruction
    {
    public: 
      
      M480LailInstruction(unsigned int lineNum,
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
      
      M480LailInstruction(const M480LailInstruction& rhs)
	: LoadImmediateInstruction(rhs)
	{}
      
      M480LailInstruction& operator=(const M480LailInstruction& rhs);
      
      ~M480LailInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480LwihInstruction 
  //---------------------------------------------
  
  // lwih rd[0-63] imm
  
  
  class M480LwihInstruction : public LoadHalfwordInstruction
    {
    public: 
      
      M480LwihInstruction(unsigned int lineNum,
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
      
      M480LwihInstruction(const M480LwihInstruction& rhs)
	: LoadHalfwordInstruction(rhs)
	{}
      
      M480LwihInstruction& operator=(const M480LwihInstruction& rhs);
      
      ~M480LwihInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480LwilInstruction 
  //---------------------------------------------
  
  // lwil rd[0-63] imm
  
  
  class M480LwilInstruction : public LoadHalfwordInstruction
    {
    public: 
      
      M480LwilInstruction(unsigned int lineNum,
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
      
      M480LwilInstruction(const M480LwilInstruction& rhs)
	: LoadHalfwordInstruction(rhs)
	{}
      
      M480LwilInstruction& operator=(const M480LwilInstruction& rhs);
      
      ~M480LwilInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480NopInstruction 
  //---------------------------------------------
  
  // nop
  
  
  class M480NopInstruction : public OctaveInstruction
    {
    public: 
      
      M480NopInstruction(unsigned int lineNum,
			 unsigned int srcLineNum,
			 const char* srcFileName)
        : OctaveInstruction(lineNum,
			    srcLineNum,
			    srcFileName)
	{}
      
      M480NopInstruction(const M480NopInstruction& rhs)
	: OctaveInstruction(rhs)
	{}
      
      M480NopInstruction& operator=(const M480NopInstruction& rhs);
      
      ~M480NopInstruction()
	{}

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    };
  
  
  //---------------------------------------------
  // M480Hec5Instruction 
  //---------------------------------------------
  
  // hec5 rsb rd bytes [CUME] [br=pc]
  
  
  class M480Hec5Instruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480Hec5Instruction(unsigned int lineNum,
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
      
      M480Hec5Instruction(const M480Hec5Instruction& rhs)
	: Alu2OpBranchInstruction(rhs),
	m_bytes(rhs.m_bytes),
	m_cumeFlag(rhs.m_cumeFlag)
	{}
      
      M480Hec5Instruction& operator=(const M480Hec5Instruction& rhs);
      
      ~M480Hec5Instruction()
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
  // M480JHec5Instruction 
  //---------------------------------------------
  
  // hec5 rsb rd bytes [CUME] [br=pc]
  
  
  class M480JHec5Instruction : public Alu2OpBranchInstruction
    {
    public: 
      
      M480JHec5Instruction(unsigned int lineNum,
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
            
      M480JHec5Instruction(unsigned int lineNum,
			   unsigned int srcLineNum,
			   const char* srcFileName, 
			   RegPtr src, 
			   RegPtr dst,
			   UImmPtr bytes, 
			   OpndPtr branchTarget, 
			   OpndPtr cumeFlag,
			   BranchProbability probability)
        : Alu2OpBranchInstruction(lineNum,
				  srcLineNum,
				  srcFileName,
				  src,
				  dst,
				  branchTarget,
				  probability),
	m_bytes(bytes),
	m_cumeFlag(cumeFlag)
	{}

      M480JHec5Instruction(const M480JHec5Instruction& rhs)
	: Alu2OpBranchInstruction(rhs),
	m_bytes(rhs.m_bytes),
	m_cumeFlag(rhs.m_cumeFlag)
	{}
      
      M480JHec5Instruction& operator=(const M480JHec5Instruction& rhs);
      
      ~M480JHec5Instruction()
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
  // M480MvInstruction 
  //---------------------------------------------
  
  // mv rsa rd
  
  class M480MvInstruction : public OctaveInstruction
    {
    public: 
      
      M480MvInstruction(unsigned int lineNum,
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
      
      M480MvInstruction(const M480MvInstruction& rhs)
	: OctaveInstruction(rhs),
	m_src(rhs.m_src),
	m_dst(rhs.m_dst)

	{}
      
      M480MvInstruction& operator=(const M480MvInstruction& rhs);
      
      ~M480MvInstruction()
	{}
      
      RegPtr getSrc() const;
      
      RegPtr getDst() const;

      bool isPseudoInsn() const;

      unsigned int getNumDelaySlots() const;

      bool isAbcInsn() const;

      bool isValidDslotInsn() const;

      BranchProbability getBranchProbability() const;

      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
    
    private:
      
      RegPtr  m_src;
      
      RegPtr  m_dst;
      
    };
  
  
  //---------------------------------------------
  // M480MvhrInstruction 
  //---------------------------------------------
  
  // mvhr rsb rsa [cN]
  
  class M480MvhrInstruction : public MvhOpInstruction
    {
    public: 
      
      M480MvhrInstruction(unsigned int lineNum,
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
      
      M480MvhrInstruction(const M480MvhrInstruction& rhs)
	: MvhOpInstruction(rhs)
	
	{}
      
      M480MvhrInstruction& operator=(const M480MvhrInstruction& rhs);
      
      ~M480MvhrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480MvrhInstruction 
  //---------------------------------------------
  
  // mvrh rsb rsa [cN]
  
  class M480MvrhInstruction : public MvhOpInstruction
    {
    public: 
      
      M480MvrhInstruction(unsigned int lineNum,
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
      
      M480MvrhInstruction(const M480MvrhInstruction& rhs)
	: MvhOpInstruction(rhs)
	
	{}
      
      M480MvrhInstruction& operator=(const M480MvrhInstruction& rhs);
      
      ~M480MvrhInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480UnlinkInstruction 
  //---------------------------------------------
  
  // unlink rd1-rd2
  
  class M480UnlinkInstruction : public MultiRegOpInstruction
    {
    public: 
      
      M480UnlinkInstruction(unsigned int lineNum,
			    unsigned int srcLineNum,
			    const char* srcFileName, 
			    MultiRegPtr regs)
        : MultiRegOpInstruction(lineNum,
				srcLineNum,
				srcFileName, 
				regs)
	{}
      
      M480UnlinkInstruction(const M480UnlinkInstruction& rhs)
	: MultiRegOpInstruction(rhs)
	{}
      
      M480UnlinkInstruction& operator=(const M480UnlinkInstruction& rhs);
      
      ~M480UnlinkInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480LinkInstruction 
  //---------------------------------------------
  
  // link rd1-rd2 rsb LNK1|LNK2|LNK3
  // link rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  // link rd1-rd2 BASE2|BASE3 uimm LNK1|LNK2|LNK3
  
  class M480LinkInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinkInstruction(unsigned int lineNum,
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
      
      M480LinkInstruction(const M480LinkInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinkInstruction& operator=(const M480LinkInstruction& rhs);
      
      ~M480LinkInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480LinksInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinksInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinksInstruction(unsigned int lineNum,
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
      
      M480LinksInstruction(const M480LinksInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinksInstruction& operator=(const M480LinksInstruction& rhs);
      
      ~M480LinksInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
    
  //---------------------------------------------
  // M480LinkspInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinkspInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinkspInstruction(unsigned int lineNum,
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
      
      M480LinkspInstruction(const M480LinkspInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinkspInstruction& operator=(const M480LinkspInstruction& rhs);
      
      ~M480LinkspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LinksplInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinksplInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinksplInstruction(unsigned int lineNum,
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
      
      M480LinksplInstruction(const M480LinksplInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinksplInstruction& operator=(const M480LinksplInstruction& rhs);
      
      ~M480LinksplInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LinksrInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinksrInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinksrInstruction(unsigned int lineNum,
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
      
      M480LinksrInstruction(const M480LinksrInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinksrInstruction& operator=(const M480LinksrInstruction& rhs);
      
      ~M480LinksrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LinksdInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinksdInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinksdInstruction(unsigned int lineNum,
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
      
      M480LinksdInstruction(const M480LinksdInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinksdInstruction& operator=(const M480LinksdInstruction& rhs);
      
      ~M480LinksdInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LinkccInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinkccInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinkccInstruction(unsigned int lineNum,
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
      
      M480LinkccInstruction(const M480LinkccInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinkccInstruction& operator=(const M480LinkccInstruction& rhs);
      
      ~M480LinkccInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LinkcclInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinkcclInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinkcclInstruction(unsigned int lineNum,
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
      
      M480LinkcclInstruction(const M480LinkcclInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinkcclInstruction& operator=(const M480LinkcclInstruction& rhs);
      
      ~M480LinkcclInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LinksioInstruction 
  //---------------------------------------------
  
  // links rd1-rd2 rsb LNK1|LNK2|LNK3
  // links rd1-rd2 simm(rsb) LNK1|LNK2|LNK3
  
  class M480LinksioInstruction : public MultiRegLinkInstruction
    {
    public: 
      
      M480LinksioInstruction(unsigned int lineNum,
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
      
      M480LinksioInstruction(const M480LinksioInstruction& rhs)
	: MultiRegLinkInstruction(rhs)
	
	{}
      
      M480LinksioInstruction& operator=(const M480LinksioInstruction& rhs);
      
      ~M480LinksioInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LmmInstruction 
  //---------------------------------------------
  
  // lmm rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmm rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmm rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmInstruction(unsigned int lineNum,
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
      
      M480LmmInstruction(const M480LmmInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmInstruction& operator=(const M480LmmInstruction& rhs);
      
      ~M480LmmInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480LmmsInstruction 
  //---------------------------------------------
  
  // lmms rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmms rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  
  class M480LmmsInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmsInstruction(unsigned int lineNum,
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
      
      M480LmmsInstruction(const M480LmmsInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmsInstruction& operator=(const M480LmmsInstruction& rhs);
      
      ~M480LmmsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LspInstruction 
  //---------------------------------------------
  
  // lsp rd1-rd2 rsa [LNK1|LNK2|LNK3]
  // lsp rd1-rd2 imm [LNK1|LNK2|LNK3]
  // lsp rd1-rd2 imm(rsa) [LNK1|LNK2|LNK3]
  
  class M480LspInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LspInstruction(unsigned int lineNum,
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
      
      M480LspInstruction(const M480LspInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LspInstruction& operator=(const M480LspInstruction& rhs);
      
      ~M480LspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //--------------------------------------------------------------
  // M480LmmspInstruction - Load from scratch pad memory pseudo-op
  //--------------------------------------------------------------
  
  // lmmsp rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmsp rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmmsp rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmspInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmspInstruction(unsigned int lineNum,
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
      
      M480LmmspInstruction(const M480LmmspInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmspInstruction& operator=(const M480LmmspInstruction& rhs);
      
      ~M480LmmspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //--------------------------------------------------------------
  // M480LmmsplInstruction - Load from scratch pad memory (locked) pseudo-op
  //--------------------------------------------------------------
  
  // lmmspl rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmspl rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmmspl rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmsplInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmsplInstruction(unsigned int lineNum,
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
      
      M480LmmsplInstruction(const M480LmmsplInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmsplInstruction& operator=(const M480LmmsplInstruction& rhs);
      
      ~M480LmmsplInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  // M480LmmsrInstruction - Load from SRAM pseudo-op 
  //---------------------------------------------
  
  // lmmsr rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmsr rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmmsr rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmsrInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmsrInstruction(unsigned int lineNum,
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
      
      M480LmmsrInstruction(const M480LmmsrInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmsrInstruction& operator=(const M480LmmsrInstruction& rhs);
      
      ~M480LmmsrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //-------------------------------------------------
  // M480LmmsdInstruction - Load from SDRAM pseudo-op
  //-------------------------------------------------
  
  // lmmsd rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmsd rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmmsd rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmsdInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmsdInstruction(unsigned int lineNum,
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
      
      M480LmmsdInstruction(const M480LmmsdInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmsdInstruction& operator=(const M480LmmsdInstruction& rhs);
      
      ~M480LmmsdInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //-------------------------------------------------
  // M480LmmccInstruction - Load from CCRAM pseudo-op 
  //-------------------------------------------------
  
  // lmmcc rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmcc rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmmcc rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmccInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmccInstruction(unsigned int lineNum,
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
      
      M480LmmccInstruction(const M480LmmccInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmccInstruction& operator=(const M480LmmccInstruction& rhs);
      
      ~M480LmmccInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //------------------------------------------------------------
  // M480LmmcclInstruction - Load from CCRAM (locked) pseudo-op 
  //------------------------------------------------------------
  
  // lmmccl rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmccl rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  // lmmccl rd1-rd2 BASE2|BASE3 uimm [LNK1|LNK2|LNK3]
  
  class M480LmmcclInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmcclInstruction(unsigned int lineNum,
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
      
      M480LmmcclInstruction(const M480LmmcclInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmcclInstruction& operator=(const M480LmmcclInstruction& rhs);
      
      ~M480LmmcclInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //------------------------------------------------------
  // M480LmmsiInstruction - Load from SIO memory pseudo-op
  //------------------------------------------------------
  
  // lmmsi rd1-rd2 rsb [LNK1|LNK2|LNK3]
  // lmmsi rd1-rd2 simm(rsb) [LNK1|LNK2|LNK3]
  
  class M480LmmsiInstruction : public MultiRegLoadInstruction
    {
    public: 
      
      M480LmmsiInstruction(unsigned int lineNum,
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
      
      M480LmmsiInstruction(const M480LmmsiInstruction& rhs)
	: MultiRegLoadInstruction(rhs)
	
	{}
      
      M480LmmsiInstruction& operator=(const M480LmmsiInstruction& rhs);
      
      ~M480LmmsiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480SmmInstruction 
  //---------------------------------------------
  
  // smm rd1-rd2 rsb 
  // smm rd1-rd2 simm(rsb) 
  // smm rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmInstruction(unsigned int lineNum,
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
      
      M480SmmInstruction(const M480SmmInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmInstruction& operator=(const M480SmmInstruction& rhs);
      
      ~M480SmmInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //----------------------------------------------
  // M480SmmspInstruction - Store to SPRAM Pseudo Op
  //----------------------------------------------
  
  // smmsp rd1-rd2 rsb 
  // smmsp rd1-rd2 simm(rsb) 
  // smmsp rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmspInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmspInstruction(unsigned int lineNum,
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
      
      M480SmmspInstruction(const M480SmmspInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmspInstruction& operator=(const M480SmmspInstruction& rhs);
      
      ~M480SmmspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //--------------------------------------------------------
  // M480SmmsplInstruction - Store to SPRAM (lock) Pseudo Op
  //--------------------------------------------------------
  
  // smmspl rd1-rd2 rsb 
  // smmspl rd1-rd2 simm(rsb) 
  // smmspl rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmsplInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmsplInstruction(unsigned int lineNum,
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
      
      M480SmmsplInstruction(const M480SmmsplInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmsplInstruction& operator=(const M480SmmsplInstruction& rhs);
      
      ~M480SmmsplInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //----------------------------------------------
  // M480SmmsrInstruction - Store to SRAM Pseudo Op
  //----------------------------------------------
  
  // smmsr rd1-rd2 rsb 
  // smmsr rd1-rd2 simm(rsb) 
  // smmsr rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmsrInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmsrInstruction(unsigned int lineNum,
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
      
      M480SmmsrInstruction(const M480SmmsrInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmsrInstruction& operator=(const M480SmmsrInstruction& rhs);
      
      ~M480SmmsrInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  

  //------------------------------------------------
  // M480SmmsdInstruction - Store to SDRAM Pseudo Op
  //------------------------------------------------
  
  // smmsd rd1-rd2 rsb 
  // smmsd rd1-rd2 simm(rsb) 
  // smmsd rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmsdInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmsdInstruction(unsigned int lineNum,
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
      
      M480SmmsdInstruction(const M480SmmsdInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmsdInstruction& operator=(const M480SmmsdInstruction& rhs);
      
      ~M480SmmsdInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //----------------------------------------------
  // M480SmmccInstruction - Store to CC Pseudo Op
  //----------------------------------------------
  
  // smmcc rd1-rd2 rsb 
  // smmcc rd1-rd2 simm(rsb) 
  // smmcc rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmccInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmccInstruction(unsigned int lineNum,
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
      
      M480SmmccInstruction(const M480SmmccInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmccInstruction& operator=(const M480SmmccInstruction& rhs);
      
      ~M480SmmccInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //----------------------------------------------
  // M480SmmcclInstruction - Store to CC Pseudo Op
  //----------------------------------------------
  
  // smmccl rd1-rd2 rsb 
  // smmccl rd1-rd2 simm(rsb) 
  // smmccl rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmcclInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmcclInstruction(unsigned int lineNum,
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
      
      M480SmmcclInstruction(const M480SmmcclInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmcclInstruction& operator=(const M480SmmcclInstruction& rhs);
      
      ~M480SmmcclInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //----------------------------------------------
  // M480SmmsiInstruction - Store to SPRAM Pseudo Op
  //----------------------------------------------
  
  // smmsi rd1-rd2 rsb 
  // smmsi rd1-rd2 simm(rsb) 
  // smmsi rd1-rd2 BASE2|BASE3 uimm 
  
  class M480SmmsiInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmsiInstruction(unsigned int lineNum,
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
      
      M480SmmsiInstruction(const M480SmmsiInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmsiInstruction& operator=(const M480SmmsiInstruction& rhs);
      
      ~M480SmmsiInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  //---------------------------------------------
  // M480SmmsInstruction 
  //---------------------------------------------
  
  // smms rd1-rd2 rsb 
  // smms rd1-rd2 simm(rsb) 
  
  class M480SmmsInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SmmsInstruction(unsigned int lineNum,
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
      
      M480SmmsInstruction(const M480SmmsInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SmmsInstruction& operator=(const M480SmmsInstruction& rhs);
      
      ~M480SmmsInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  //---------------------------------------------
  // M480SspInstruction 
  //---------------------------------------------
  
  // ssp rsb rsa 
  // ssp rsb imm 
  // ssp rsb imm(rsa)
  
  class M480SspInstruction : public MultiRegStoreInstruction
    {
    public: 
      
      M480SspInstruction(unsigned int lineNum,
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
      
      M480SspInstruction(const M480SspInstruction& rhs)
	: MultiRegStoreInstruction(rhs)
	
	{}
      
      M480SspInstruction& operator=(const M480SspInstruction& rhs);
      
      ~M480SspInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };
  
  
  
  //---------------------------------------------
  // M480PutcInstruction 
  //---------------------------------------------
  
  // putc rsa rsb [put flags]  
  
  class M480PutcInstruction : public TssRcOpInstruction
    {
    public: 
      
      M480PutcInstruction(unsigned int lineNum,
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
      
      M480PutcInstruction(const M480PutcInstruction& rhs)
	: TssRcOpInstruction(rhs), 
	m_rsb(rhs.m_rsb)
	{}
      
      M480PutcInstruction& operator=(const M480PutcInstruction& rhs);
      
      ~M480PutcInstruction()
	{}
      
      RegPtr getRsb() const;
	
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_rsb;
      
    };

  //---------------------------------------------
  // M480PutmInstruction 
  //---------------------------------------------
  
  // putm rsa rsb [put flags]  
  
  class M480PutmInstruction : public TssRcOpInstruction
    {
    public: 
      
      M480PutmInstruction(unsigned int lineNum,
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
      
      M480PutmInstruction(const M480PutmInstruction& rhs)
	: TssRcOpInstruction(rhs), 
	m_rsb(rhs.m_rsb)
	{}
      
      M480PutmInstruction& operator=(const M480PutmInstruction& rhs);
      
      ~M480PutmInstruction()
	{}
      
      RegPtr getRsb() const;
	
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_rsb;
      
    };
  
  
  //---------------------------------------------
  // M480PutpInstruction 
  //---------------------------------------------
  
  // putp rsa rsb [put flags]  
  
  class M480PutpInstruction : public TssRcOpInstruction
    {
    public: 
      
      M480PutpInstruction(unsigned int lineNum,
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
      
      M480PutpInstruction(const M480PutpInstruction& rhs)
	: TssRcOpInstruction(rhs), 
	m_rsb(rhs.m_rsb)
	{}
      
      M480PutpInstruction& operator=(const M480PutpInstruction& rhs);
      
      ~M480PutpInstruction()
	{}
      
      RegPtr getRsb() const;
	
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_rsb;
      
    };
  
  
  //---------------------------------------------
  // M480PutdInstruction 
  //---------------------------------------------
  
  // putd rsa rsb [put flags]  
  
  class M480PutdInstruction : public TssRcOpInstruction
    {
    public: 
      
      M480PutdInstruction(unsigned int lineNum,
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
      
      M480PutdInstruction(const M480PutdInstruction& rhs)
	: TssRcOpInstruction(rhs), 
	m_rsb(rhs.m_rsb)
	{}
      
      M480PutdInstruction& operator=(const M480PutdInstruction& rhs);
      
      ~M480PutdInstruction()
	{}
      
      RegPtr getRsb() const;
	
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    private:
      
      RegPtr m_rsb;
      
    };
  
  

  //---------------------------------------------
  // M480GetInstruction 
  //---------------------------------------------
  
  // get rsa [get flags]  
  
  class M480GetInstruction : public TssRcOpInstruction
    {
    public: 
      
      M480GetInstruction(unsigned int lineNum,
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
      
      M480GetInstruction(const M480GetInstruction& rhs)
	: TssRcOpInstruction(rhs)
	{}
      
      M480GetInstruction& operator=(const M480GetInstruction& rhs);
      
      ~M480GetInstruction()
	{}
      
      bool equalTo(const LlirNode& rhs) const;
      
      void accept(Visitor& v) const;
      
    };

  //---------------------------------------------
  //---------------------------------------------
  
} // end namespace Llir
  
#endif
