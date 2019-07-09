#include <string>
#include <exception>
#include <cassert>

#include <Alo.h>
#include <LlirException.h>

#include "M480Instructions.h"
#include <OctaveUpdateOpndVisitor.h>
#include "M480UpdateOpndVisitor.h"

#include <iostream>

#ifdef GCCBUILD
#include <insn-constants.h>
#endif

using namespace Llir;
extern std::map<string, shared_ptr<const PrototypeDirective> > g_prototypeDirList;

namespace Alo
{

  M480UpdateOpndVisitor::M480UpdateOpndVisitor(OctaveAlo &i, 	
					       shared_ptr<AltEntryFunction> fn)
    : OctaveUpdateOpndVisitor(i),
      m_currentFn(fn)
  {}

  M480UpdateOpndVisitor::M480UpdateOpndVisitor(const M480UpdateOpndVisitor& rhs)
    : OctaveUpdateOpndVisitor(rhs)
  {}

  const M480UpdateOpndVisitor&
  M480UpdateOpndVisitor::operator=(const M480UpdateOpndVisitor& rhs)
  {
    if(this == &rhs)
      {
	return *this;
      }

    OctaveUpdateOpndVisitor::operator=(rhs);

    return *this;
  }

  shared_ptr<AltEntryFunction> 
  M480UpdateOpndVisitor::getCurrentFn() const
  {
    return m_currentFn;
  }

  void M480UpdateOpndVisitor::visit(const InvalidOctaveInstruction& v){}

  void 
  M480UpdateOpndVisitor::visit(const M480AddwhInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
    
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddwlInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddwwInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddlInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SubwhInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SubwlInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SubwwInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SublInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddwhiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddwliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddwwiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480AddliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480SubwhiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480SubwliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480SubwwiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480SubliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480FfsInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480FlsInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ParInstruction &i)  
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }
    
  void M480UpdateOpndVisitor::visit(const M480Add4xInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddcInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
    i.addUsedRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480AndInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480MaxInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480MinInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480OrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SubInstruction &i)
   {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

 void M480UpdateOpndVisitor::visit(const M480SubbInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addUsedRegister(getHardRegister(REG_ESS));
    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480XorInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddciInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
    i.addUsedRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SubiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SubbiInstruction &i)
   {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
    i.addUsedRegister(getHardRegister(REG_ESS));
        

  }

  void M480UpdateOpndVisitor::visit(const M480RandInstruction &i)
  {
    
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480RotlInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480RotrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ClrbInstruction &i)  
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480SetbInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ShftInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ShftaInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
        
    i.addSetRegister(getHardRegister(REG_ESS));

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ShlInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ShrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ShraInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480RandiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480RotliInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480RotriInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480SetbiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480ClrbiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480ShliInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480ShriInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480ShraiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480MaxiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480MiniInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480AndiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480OriInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480XoriInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480MulInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
  }

  void M480UpdateOpndVisitor::visit(const M480MulhInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
  }

  void M480UpdateOpndVisitor::visit(const M480MuliInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
  }

  void M480UpdateOpndVisitor::visit(const M480MulhiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
  }

  void M480UpdateOpndVisitor::visit(const M480AddneInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480AddneiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ByteswInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480BcdrInstruction &i)
  {
    shared_ptr<const Register> rsb = i.getSrc1();
    shared_ptr<const LlirOperand> rpc = i.getDst();

    i.addUsedRegister(rsb);
    
    if(i.isCallInsn())
      {
	
	i.addSetRegister(rpc);
      }
  }

  void M480UpdateOpndVisitor::visit(const M480BcrInstruction &i)
  {
    shared_ptr<const Register> rsb = i.getSrc1();
    shared_ptr<const LlirOperand> rpc = i.getDst();

    i.addUsedRegister(rsb);
    
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BcdiInstruction &i)
  {
    shared_ptr<const LlirOperand> rpc = i.getDst();

    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BciInstruction &i)
  {
    shared_ptr<const LlirOperand> rpc = i.getDst();

    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BnzrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const Register> rsb = i.getSrc2();
    shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
	
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BzrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const Register> rsb = i.getSrc2();
    shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
	
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BnziInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    
    i.addUsedRegister(rsa);
	
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BziInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    
    i.addUsedRegister(rsa);
	
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480RnmiInstruction &i)
  {
    //use REG_88
    i.addUsedRegister(getHardRegister(REG_88));
  }

  void M480UpdateOpndVisitor::visit(const M480RintInstruction &i)
  {
    //use REG_87
    i.addUsedRegister(getHardRegister(REG_87));
  }

  void M480UpdateOpndVisitor::visit(const M480BrsInstruction &i)
  {
    //use REG_69
    i.addUsedRegister(getHardRegister(REG_69));
  }

  void M480UpdateOpndVisitor::visit(const M480BrslInstruction &i)
  {
    //clobber/set REG26:REG59
    i.addSetRegister(getHardRegister(REG_26, REG_59));
  }

  void M480UpdateOpndVisitor::visit(const M480BrspreInstruction &i)
  {}

  void M480UpdateOpndVisitor::visit(const M480CmpInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480CmpiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);

    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480CmprInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
    i.addSetRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480CmpriInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
    i.addSetRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480BiInstruction &i)
  {
    shared_ptr<const LlirOperand> rpc = i.getDst();
    	
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480BrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rpc = i.getDst();
    	
    i.addUsedRegister(rsa);
    if(i.isCallInsn())
      {
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480DepbInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480DepbiInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    
    i.addUsedRegister(rd);
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480ExtbInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480CmovInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    shared_ptr<const Register> rd = i.getDst();

    i.addUsedRegister(getHardRegister(REG_ESS));    

    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
    i.addSetRegister(rd);
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480CmoviInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addUsedRegister(getHardRegister(REG_ESS));    

    i.addUsedRegister(rsa);
    i.addSetRegister(rd);
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480DmapInstruction &i)
  {
    shared_ptr<const MultiRegister> rsa = i.getRegs();
    i.addUsedRegister(rsa);
    i.addUsedRegister(getHardRegister(REG_107));
    i.addUsedRegister(getHardRegister(REG_108));
    i.addUsedRegister(getHardRegister(REG_109));
  }

  void M480UpdateOpndVisitor::visit(const M480DmasrInstruction &i)
  {
    shared_ptr<const MultiRegister> rsa = i.getRegs();
    i.addUsedRegister(rsa);
    i.addUsedRegister(getHardRegister(REG_107));
    i.addUsedRegister(getHardRegister(REG_108));
    i.addUsedRegister(getHardRegister(REG_109));
  }

  void M480UpdateOpndVisitor::visit(const M480Dmau0Instruction &i)
  {
    shared_ptr<const MultiRegister> rsa = i.getRegs();
    i.addUsedRegister(rsa);
    i.addUsedRegister(getHardRegister(REG_107));
    i.addUsedRegister(getHardRegister(REG_108));
    i.addUsedRegister(getHardRegister(REG_109));
  }

  void M480UpdateOpndVisitor::visit(const M480Dmau1Instruction &i)
  {
    shared_ptr<const MultiRegister> rsa = i.getRegs();
    i.addUsedRegister(rsa);
    i.addUsedRegister(getHardRegister(REG_107));
    i.addUsedRegister(getHardRegister(REG_108));
    i.addUsedRegister(getHardRegister(REG_109));
  }

  void M480UpdateOpndVisitor::visit(const M480LihInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480LilInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480LwihInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }


  void M480UpdateOpndVisitor::visit(const M480LwilInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    i.addSetRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480LaihInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    i.addSetRegister(rd);
    i.addUsedRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480LailInstruction &i)
  {
    shared_ptr<const Register> rd = i.getDst();
    i.addSetRegister(rd);
    i.addUsedRegister(rd);

    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480NopInstruction &i)
  {}

  void M480UpdateOpndVisitor::visit(const M480Hec5Instruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addUsedRegister(rsb);
    i.addSetRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480MvInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addSetRegister(rd);
    i.addUsedRegister(rsa);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480MvrhInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
    
    //if rd is REG_80, set REG_ESS_BMEHWEPD
    //if rd is REG_80, set REG_ESS_BMEEXHAUST
    if(rd->getRegNum() == REG_80)
      {
	i.addSetRegister(getHardRegister(REG_ESS_BMEHWEPD));
	i.addSetRegister(getHardRegister(REG_ESS_BMEEXHAUST));
      }
    //if rd is REG_94, set REG_ESS_BMESWEPD
    else if(rd->getRegNum() == REG_94)
      {
	i.addSetRegister(getHardRegister(REG_ESS_BMESWEPD));
      }
    //update this method as per m480.md mvrh patterns
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480MvhrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc();
    shared_ptr<const Register> rd = i.getDst();
    
    i.addSetRegister(rd);
    i.addUsedRegister(rsa);
            
    setLinkRegisterUsage(i, rd);
  }

  void M480UpdateOpndVisitor::visit(const M480UnlinkInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();

    i.addUsedRegister(mRegs);

    unsigned int count = mRegs->getNumRegs();
    
    unsigned int rd1 = mRegs->getFirstRegNum();
    unsigned int rdN = rd1 + count - 1;
    
    unsigned int reg;
    for(reg = rd1; reg <= rdN; reg++)
      {
	setRegLink(reg, LinkFlag::NOLINK);
      }
  }

  void M480UpdateOpndVisitor::visit(const M480LinkInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_ANY, lnk, mRegs);

    i.addUsedRegister(mRegs);

    
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinksInstruction &i)
  {

    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinkspInstruction &i)
  {
    
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType(); 
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinksplInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
 

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM_LOCKED, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinksrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SRAM, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinksdInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SDRAM, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinkccInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
 
    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_CCRAM, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinkcclInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
 

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_CCRAM_LOCKED, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LinksioInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    shared_ptr<const OctaveMemory> mem = i.getMem();
 

    shared_ptr<const LinkFlag> linkFlag = i.getLinkFlag();
    LinkFlag::Link_Flag_t lnk = linkFlag->getLinkFlagType();
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SIO, lnk, mRegs);

    i.addUsedRegister(mRegs);
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_ANY, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    

    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmsplInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM_LOCKED, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM_LOCK));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmsrInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SRAM, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SRAM));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmsdInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();
    
    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SDRAM, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SDRAM));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmccInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_CCRAM, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_CCRAM));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmcclInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_CCRAM_LOCKED, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_CCRAM_LOCK));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmsiInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SIO, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SIO));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LmmsInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480LspInstruction &i)
  {
    unsigned int excLine = i.getSrcLineNum();
    const char* excFile = i.getSrcFile().c_str();

    shared_ptr<const LinkFlag> linkFlag = 
      shared_dynamic_cast<const LinkFlag>(i.getLinkFlag());
    
    shared_ptr<const OctaveMemory> mem = i.getMem();

    LinkFlag::Link_Flag_t lnk;

    if(linkFlag)
      {
	lnk = linkFlag->getLinkFlagType();
      }
    else
      {
	lnk = LinkFlag::CLEARLINK;
      }
    
    updateLinkInfo(excLine, excFile, OctaveMemory::MEMTYPE_SPRAM, lnk, i.getRegs());

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addSetRegister(mRegs);

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM));
    setMemRefRegisterUsage(i, mem);
    i.addSetRegister(getLinkRegister(lnk));
  }

  void M480UpdateOpndVisitor::visit(const M480SmmInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmspInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmsplInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM_LOCK));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmsrInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SRAM));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmsdInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SDRAM));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmccInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_CCRAM));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmcclInstruction &i)
  {

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_CCRAM_LOCK));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmsiInstruction &i)
  {

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SIO));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SmmsInstruction &i)
  {
    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480SspInstruction &i)
  {

    shared_ptr<const MultiRegister> mRegs = i.getRegs();
    i.addUsedRegister(mRegs);

    shared_ptr<const OctaveMemory> mem = i.getMem();

    i.addUsedRegister(getHardRegister(REG_BASE_SPRAM));
    setMemRefRegisterUsage(i, mem);
  }

  void M480UpdateOpndVisitor::visit(const M480TsetbInstruction &i)
  {   
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);
    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480TclrbInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);    
    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480GetInstruction &i)
  {
    i.addUsedRegister(i.getRsa());
    //use REG_110
    i.addUsedRegister(getHardRegister(REG_110));   
  }

  void M480UpdateOpndVisitor::visit(const M480PutcInstruction &i)
  {
    i.addUsedRegister(i.getRsa());
    i.addUsedRegister(i.getRsb());
    //use REG_110
    i.addUsedRegister(getHardRegister(REG_110));   
  }

  void M480UpdateOpndVisitor::visit(const M480PutmInstruction &i)
  {
    i.addUsedRegister(i.getRsa());
    i.addUsedRegister(i.getRsb());
    //use REG_110
    i.addUsedRegister(getHardRegister(REG_110));   
  }

  void M480UpdateOpndVisitor::visit(const M480PutpInstruction &i)
  {
    i.addUsedRegister(i.getRsa());
    i.addUsedRegister(i.getRsb());
  }
  

  void M480UpdateOpndVisitor::visit(const M480PutdInstruction &i)
  {
    i.addUsedRegister(i.getRsa());
    i.addUsedRegister(i.getRsb());
  }

  void M480UpdateOpndVisitor::visit(const M480JtablebrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);
  }

  void M480UpdateOpndVisitor::visit(const M480JtableRelativebrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);
  }

  void M480UpdateOpndVisitor::visit(const M480JHec5Instruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rd);
    i.addUsedRegister(rsb);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddlInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddwhInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddwhiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddwlInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddwliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }


  void M480UpdateOpndVisitor::visit(const M480JaddwwInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JaddwwiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsublInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubwhInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubwhiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubwlInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubwliInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubwwInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JsubwwiInstruction &i)
  {
    shared_ptr<const LlirOperand> rsb = i.getSrc1();
    shared_ptr<const Register> rd = i.getDst();

    i.addSetRegister(rsb);
    i.addUsedRegister(rsb);
    i.addUsedRegister(rd);

    i.addSetRegister(getHardRegister(REG_ESS));
        
    setLinkRegisterUsage(i, rd);

  }

  void M480UpdateOpndVisitor::visit(const M480JbcdiInstruction &i)
  {
    i.addUsedRegister(getHardRegister(REG_ESS));

    if(i.isCallInsn())
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(i.getSrc1());

	const char* name; 

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getDst();
    
	i.addSetRegister(rpc);
      }    
  }


  void M480UpdateOpndVisitor::visit(const M480JbcdrInstruction &i)
  {
    i.addUsedRegister(getHardRegister(REG_ESS));

    shared_ptr<const Register> rsb = i.getSrc1();
    i.addUsedRegister(rsb);
    
    if(i.isCallInsn())
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	const char* name;

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	i.addSetRegister(rpc);
      }
  }

  void M480UpdateOpndVisitor::visit(const M480JbciInstruction &i)
  {
    i.addUsedRegister(getHardRegister(REG_ESS));

    if(i.isCallInsn())
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(i.getSrc1());

	const char* name;

	if(l)
	   name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getDst();
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480JbcrInstruction &i)
  {
    i.addUsedRegister(getHardRegister(REG_ESS));

    shared_ptr<const Register> rsb = i.getSrc1();
    i.addUsedRegister(rsb);
    
    if(i.isCallInsn())
      {
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	const char* name;

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getDst();
	i.addSetRegister(rpc);
      }    
  }


  void M480UpdateOpndVisitor::visit(const M480JrnmiInstruction &i)
  {
    //use REG_88
    i.addUsedRegister(getHardRegister(REG_88));   
  }

  void M480UpdateOpndVisitor::visit(const M480JrintInstruction &i)
  {
    //use REG_87    
    i.addUsedRegister(getHardRegister(REG_87));   
  }

  void M480UpdateOpndVisitor::visit(const M480JbiInstruction &i)  
  {
    if(i.isCallInsn())
      {
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(i.getSrc1());
	    
	const char* name;

	if(l)
	  name = l->getName().c_str();


	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getDst();

	i.addSetRegister(rpc);
      }
  }    

  void M480UpdateOpndVisitor::visit(const M480JbnzrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    i.addUsedRegister(rsa);

    shared_ptr<const Register> rsb = i.getSrc2();
    i.addUsedRegister(rsb);
	
    if(i.isCallInsn())
      {
	//mark call result regs as set
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	const char* name;

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();

	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480JbnziInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    i.addUsedRegister(rsa);
	
    if(i.isCallInsn())
      {
	//mark call result regs as set
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(i.getSrc2());

	const char* name;

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }


	//mark call return reg as set
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480JbrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    i.addUsedRegister(rsa);
	
    if(i.isCallInsn())
      {
	//mark call result regs as set
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));

	const char* name;

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark RPC return reg as set
	shared_ptr<const LlirOperand> rpc = i.getDst();
    
	i.addUsedRegister(rsa);    
      }
  }

  void M480UpdateOpndVisitor::visit(const M480JbrsInstruction &i)
  {
    //use REG_69
    i.addUsedRegister(getHardRegister(REG_69));   
  }

  void M480UpdateOpndVisitor::visit(const M480JbrslInstruction &i)
  {
    //clobber/set REG26:REG59
    i.addSetRegister(getHardRegister(REG_26, REG_59));   
  }

  void M480UpdateOpndVisitor::visit(const M480JbzrInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    i.addUsedRegister(rsa);

    shared_ptr<const Register> rsb = i.getSrc2();
    i.addUsedRegister(rsb);
	
    if(i.isCallInsn())
      {
	//mark call result regs as set
	shared_ptr<const IndirectCallTargetList> targetList =
	  shared_dynamic_cast<const IndirectCallTargetList>(i.getTargetLabelList());

	shared_ptr<const OpndLabel> l;

	if(targetList)
	  l = shared_dynamic_cast<const OpndLabel>(targetList->getLabelList()->getLabel(0));
	
	const char* name;

	if(l)
	  name = l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg as set
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();
	
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480JbziInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    i.addUsedRegister(rsa);
	
    if(i.isCallInsn())
      {
	//mark call result regs as set
	shared_ptr<const OpndLabel> l = shared_dynamic_cast<const OpndLabel>(i.getSrc2());

	const char* name;

	if(l)
	  name =  l->getName().c_str();

	shared_ptr<const PrototypeDirective> proto = searchForPrototype(i.getLineNum(), 
									i.getSrcFile().c_str(),
									name);
	
	RegList::ConstIterator iter;

	//mark call input arg regs as used
	shared_ptr<const RegList> argList = proto->getArgList()->getRegList();

	iter = argList->begin();
	
	for(; iter != argList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addUsedRegister(reg);
	  }

	//mark call result regs as set
	shared_ptr<const RegList> resultList = proto->getResultList()->getRegList();

	iter = resultList->begin();
	
	for(; iter != resultList->end(); iter++)
	  {
	    shared_ptr<const Register> reg = iter->second;
	    i.addSetRegister(reg);
	  }

	//mark call return reg RPC as set
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();
    
	i.addSetRegister(rpc);
      }    
  }

  void M480UpdateOpndVisitor::visit(const M480JcmpInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    shared_ptr<const LlirOperand> rsb = i.getSrc2();
    
    i.addUsedRegister(rsa);
    i.addUsedRegister(rsb);
    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480JcmpiInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);
    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480JtsetbInstruction &i)
  {
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);    
    i.addSetRegister(getHardRegister(REG_ESS));
  }

  void M480UpdateOpndVisitor::visit(const M480JtclrbInstruction &i)
  {   
    shared_ptr<const Register> rsa = i.getSrc1();
    
    i.addUsedRegister(rsa);
    i.addSetRegister(getHardRegister(REG_ESS));
  }


  void 
  M480UpdateOpndVisitor::setLinkRegisterUsage(const OctaveInstruction &i,
					      shared_ptr<const Register> rd)
  {
    LinkFlag::Link_Flag_t lnk = getRegLink(rd->getRegNum());
    OctaveMemory::MemType_t mem = getRegisterLinkedMemoryType(rd->getRegNum());
	
    if(lnk != LinkFlag::NOLINK)
      {
	i.addUsedRegister(getLinkRegister(lnk));
	i.addUsedRegister(getLinkedMemTypeRegister(mem));
      }
  }

  void 
  M480UpdateOpndVisitor::setMemRefRegisterUsage(const OctaveInstruction &i,
						shared_ptr<const OctaveMemory> mem)
  {
    
    shared_ptr<const RegPlusOffsetIndirect> regOffset =
      shared_dynamic_cast<const RegPlusOffsetIndirect>(mem);

    shared_ptr<const Base2PlusOffset> base2Offset =
      shared_dynamic_cast<const Base2PlusOffset>(mem);

    shared_ptr<const Base3PlusOffset> base3Offset =
      shared_dynamic_cast<const Base3PlusOffset>(mem);

    shared_ptr<const ImpliedBase2Offset> impOffset = 
      shared_dynamic_cast<const ImpliedBase2Offset>(mem);

    if(regOffset)
      {
	// 0(rsa)
	// imm(rsa)

	shared_ptr<const Register> rsa = regOffset->getBaseRegister();
	i.addUsedRegister(rsa);

      }
    else if(base2Offset || impOffset)
      {
	// BASE2 label_expr

	i.addUsedRegister(getHardRegister(REG_BASE2));

      }
    else if(base3Offset)
      {
	// BASE3 label_expr

	i.addUsedRegister(getHardRegister(REG_BASE3));
      }

  }
					      
  shared_ptr<const Register>
  M480UpdateOpndVisitor::getHardRegister(unsigned int regNo)
  {
    shared_ptr<OctaveFactory> m480f = getAlo().getFactory();
    
    return m480f->createHardReg(regNo);
  }
					      
  shared_ptr<const Register>
  M480UpdateOpndVisitor::getHardRegister(unsigned int lsw, unsigned int msw)
  {
    shared_ptr<OctaveFactory> m480f = getAlo().getFactory();
    
    return m480f->createMultiHardReg(msw-lsw+1, lsw);
  }

  shared_ptr<const Register>
  M480UpdateOpndVisitor::getLinkRegister(LinkFlag::Link_Flag_t lnk)
  {
    shared_ptr<OctaveFactory> m480f = getAlo().getFactory();

    switch(lnk)
      {
      case LinkFlag::LNK1:
	return getHardRegister(REG_LNK1);

      case LinkFlag::LNK2:
	return getHardRegister(REG_LNK2);

      case LinkFlag::LNK3:
	return getHardRegister(REG_LNK3);

      default:
	return m480f->createNullReg();
      }
  }

  shared_ptr<const Register>
  M480UpdateOpndVisitor::getLinkedMemTypeRegister(OctaveMemory::MemType_t mem)
  {
    shared_ptr<OctaveFactory> m480f = getAlo().getFactory();

    switch(mem)
      {
      case OctaveMemory::MEMTYPE_SRAM:
	return getHardRegister(REG_BASE_SPRAM);

      case OctaveMemory::MEMTYPE_SDRAM:
	return getHardRegister(REG_BASE_SDRAM);

      case OctaveMemory::MEMTYPE_SIO:
	return getHardRegister(REG_BASE_SIO);

      case OctaveMemory::MEMTYPE_SPRAM:
	return getHardRegister(REG_BASE_SPRAM);

      case OctaveMemory::MEMTYPE_SPRAM_LOCKED:
	return getHardRegister(REG_BASE_SPRAM_LOCK);

      case OctaveMemory::MEMTYPE_CCRAM:
	return getHardRegister(REG_BASE_CCRAM);

      case OctaveMemory::MEMTYPE_CCRAM_LOCKED:
	return getHardRegister(REG_BASE_CCRAM_LOCK);

      default:
	return m480f->createNullReg();
      }
  }



  //book keeping function which
  //tracks which register is linked 
  //to what memory and through which
  //link register (LNK1,LNK2,LNK3)

  void 
  M480UpdateOpndVisitor::updateLinkInfo(unsigned int excLine,
					const char* excFile,
					OctaveMemory::MemType_t  mem,
					LinkFlag::Link_Flag_t lnk,
					shared_ptr<const MultiRegister> mRegs)
  {
    unsigned int rd1 = mRegs->getFirstRegNum();
    unsigned int rdN = rd1 + mRegs->getNumRegs() - 1;


    if(rdN > 63)
      {
	//Note: links can only be set between hard registers and memory

	//generating rtl for lmm/smm instruction containing
	//pseudo registers... make sure that lnk flag is 
	//not specified in such instructions

	if(lnk == LinkFlag::LNK1 || 
	   lnk == LinkFlag::LNK2 ||
	   lnk == LinkFlag::LNK3)
	  {
	    OctaveAlo& alo = getAlo();
	    char *excStr = new char[128];
	    shared_ptr<std::exception> exc; 
	    
	    sprintf(excStr, "Cannot associate memory links to pseudo registers");
	    exc = shared_ptr<IllegalInsn> 
	      (new IllegalInsn(excStr, excLine, excFile, __LINE__, __FILE__));
	    alo.logException(exc);
	    delete excStr;
	  }
      }

    if(lnk != LinkFlag::NOLINK)
      {
	if(lnk == LinkFlag::CLEARLINK)
	  {
	    for(unsigned int reg = rd1; reg <= rdN; reg++)
	      {
		setRegLink(reg, LinkFlag::NOLINK);
		setRegisterLinkedMemoryType(reg, OctaveMemory::MEMTYPE_ANY);
	      }
	  }
	else 
	  {
	    //set links...
	    for(unsigned int reg = rd1; reg <= rdN; reg++)
	      {
		setRegLink(reg, lnk);
		setRegisterLinkedMemoryType(reg, mem);
	      }
	  }
      }
  }


  shared_ptr<const PrototypeDirective>
  M480UpdateOpndVisitor::searchForPrototype(unsigned int line,
					    const char* file,
					    const char* name)
  {
    std::map<string, shared_ptr<const PrototypeDirective> >::const_iterator iter;

    iter = g_prototypeDirList.find(name);

    if(iter != g_prototypeDirList.end())
      {
        return iter->second;
      }
    else
      {
        shared_ptr<std::exception> exc;

        char *excStr = new char[128];

        sprintf(excStr, "%s:%d: Valid prototype not found for Call label : %s", file, line, name);

        throw LLIR_INTERNAL_EXCEPTION(excStr);

        delete excStr;
      }
  }


}
