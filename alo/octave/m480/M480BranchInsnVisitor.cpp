#include <string>
#include <exception>
#include <cassert>

#include <Alo.h>
#include <LlirException.h>

#include "M480Instructions.h"
#include "BranchVisitor.h"
#include <OctaveBranchInsnVisitor.h>
#include "M480BranchInsnVisitor.h"

#include <iostream>
#include "M480RtlPrintVisitor.h"

using namespace Llir;

namespace Alo
{

  M480BranchInsnVisitor::M480BranchInsnVisitor(OctaveAlo &i, 	
					       shared_ptr<AltEntryFunction> fn)
    : OctaveBranchInsnVisitor(i),
      m_currentFn(fn)
  {}

  M480BranchInsnVisitor::M480BranchInsnVisitor(const M480BranchInsnVisitor& rhs)
    : OctaveBranchInsnVisitor(rhs),
      m_currentFn(rhs.m_currentFn)
  {}

  const M480BranchInsnVisitor&
  M480BranchInsnVisitor::operator=(const M480BranchInsnVisitor& rhs)
  {
    if(this == &rhs)
      {
	return *this;
      }

    m_currentFn = rhs.m_currentFn;
    OctaveBranchInsnVisitor::operator=(rhs);

    return *this;
  }


  shared_ptr<AltEntryFunction> 
  M480BranchInsnVisitor::getCurrentFn() const
  {
    return m_currentFn;
  }

  void M480BranchInsnVisitor::visit(const InvalidOctaveInstruction& v){}
  void M480BranchInsnVisitor::visit(const M480AddwhInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddwlInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddwwInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddlInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubwhInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubwlInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubwwInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SublInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddwhiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddwliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddwwiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubwhiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubwliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubwwiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480FfsInstruction &){}
  void M480BranchInsnVisitor::visit(const M480FlsInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ParInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddInstruction &){}
  void M480BranchInsnVisitor::visit(const M480Add4xInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddcInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AndInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MaxInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MinInstruction &){}
  void M480BranchInsnVisitor::visit(const M480OrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480XorInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddciInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SubbiInstruction &){}  
  void M480BranchInsnVisitor::visit(const M480RandInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RotlInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RotrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ClrbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SetbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShftInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShftaInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShlInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShraInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RandiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RotliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RotriInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SetbiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ClrbiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShriInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ShraiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MaxiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MiniInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AndiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480OriInstruction &){}
  void M480BranchInsnVisitor::visit(const M480XoriInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MulInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MulhInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MuliInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MulhiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddneInstruction &){}
  void M480BranchInsnVisitor::visit(const M480AddneiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ByteswInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BcdrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BcrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BcdiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BciInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BnzrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BzrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BnziInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BziInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RnmiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480RintInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BrsInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BrslInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BrspreInstruction &){}
  void M480BranchInsnVisitor::visit(const M480CmpInstruction &){}
  void M480BranchInsnVisitor::visit(const M480CmpiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480CmprInstruction &){}
  void M480BranchInsnVisitor::visit(const M480CmpriInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480BrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480DepbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480DepbiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480ExtbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480CmovInstruction &){}
  void M480BranchInsnVisitor::visit(const M480CmoviInstruction &){}
  void M480BranchInsnVisitor::visit(const M480DmapInstruction &){}
  void M480BranchInsnVisitor::visit(const M480DmasrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480Dmau0Instruction &){}
  void M480BranchInsnVisitor::visit(const M480Dmau1Instruction &){}
  void M480BranchInsnVisitor::visit(const M480LihInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LilInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LwihInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LwilInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LaihInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LailInstruction &){}
  void M480BranchInsnVisitor::visit(const M480NopInstruction &){}
  void M480BranchInsnVisitor::visit(const M480Hec5Instruction &){}
  void M480BranchInsnVisitor::visit(const M480MvInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MvrhInstruction &){}
  void M480BranchInsnVisitor::visit(const M480MvhrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480UnlinkInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinkInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinksInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinkspInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinksplInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinksrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinksdInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinkccInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinkcclInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LinksioInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmspInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmsplInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmsrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmsdInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmccInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmcclInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmsiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LmmsInstruction &){}
  void M480BranchInsnVisitor::visit(const M480LspInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmspInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmsplInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmsrInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmsdInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmccInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmcclInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmsiInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SmmsInstruction &){}
  void M480BranchInsnVisitor::visit(const M480SspInstruction &){}
  void M480BranchInsnVisitor::visit(const M480TsetbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480TclrbInstruction &){}
  void M480BranchInsnVisitor::visit(const M480GetInstruction &){}
  void M480BranchInsnVisitor::visit(const M480PutcInstruction &){}
  void M480BranchInsnVisitor::visit(const M480PutmInstruction &){}
  void M480BranchInsnVisitor::visit(const M480PutpInstruction &){}
  void M480BranchInsnVisitor::visit(const M480PutdInstruction &){}


  void M480BranchInsnVisitor::visit(const M480JtablebrInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getDst();

    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JtableRelativebrInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getDst();

    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JHec5Instruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand())
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddlInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }
  
  void M480BranchInsnVisitor::visit(const M480JaddliInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddwhInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddwhiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddwlInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddwliInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddwwInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JaddwwiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsublInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubliInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubwhInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubwhiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubwlInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubwliInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubwwInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JsubwwiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }

  void M480BranchInsnVisitor::visit(const M480JbcdiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc1();
    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	if(rpc->isNullOperand())
	  { 
	    //no RPC hence a branch...
	   opnd->accept(v);
	  }
      }
  }

  void M480BranchInsnVisitor::visit(const M480JbcdrInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbciInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc1();

    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	if(rpc->isNullOperand())
	  { 
	    //no RPC hence a branch...
	   opnd->accept(v);
	  }
      }
  }

  void M480BranchInsnVisitor::visit(const M480JbcrInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JrnmiInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JrintInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc1();
    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	if(rpc->isNullOperand())
	  { 
	    //no RPC hence a branch...
	    opnd->accept(v);
	  }
      }
  }
  
  void M480BranchInsnVisitor::visit(const M480JbnzrInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbnziInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc2();
    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();
	
	if(rpc->isNullOperand())
	  { 
	    //no RPC hence a branch...
	    opnd->accept(v);
	  }
      }
  }

  void M480BranchInsnVisitor::visit(const M480JbrInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbrsInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbrslInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbzrInstruction &i)
  {}

  void M480BranchInsnVisitor::visit(const M480JbziInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc2();
    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();

	if(rpc->isNullOperand())
	  { 
	    //no RPC hence a branch...
	    opnd->accept(v);
	  }
      }
  }

  void M480BranchInsnVisitor::visit(const M480JcmpInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }
  
  void M480BranchInsnVisitor::visit(const M480JcmpiInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getBranchTarget();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }
  
  void M480BranchInsnVisitor::visit(const M480JtsetbInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getDisp();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }
  
  void M480BranchInsnVisitor::visit(const M480JtclrbInstruction &i)
  {
    BranchIsJumpVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getDisp();
    if(!opnd->isNullOperand()) 
      opnd->accept(v);
  }



  //////////////////////////
  // Call Insn Visitor
  //////////////////////////

  M480CallInsnVisitor::M480CallInsnVisitor(OctaveAlo &i, 			  
					   shared_ptr<AltEntryFunction> fn)
    : OctaveBranchInsnVisitor(i),
      m_currentFn(fn)
  {}

  M480CallInsnVisitor::M480CallInsnVisitor(const M480CallInsnVisitor& rhs)
    : OctaveBranchInsnVisitor(rhs)
  {}

  const M480CallInsnVisitor&
  M480CallInsnVisitor::operator=(const M480CallInsnVisitor& rhs)
  {
    if(this == &rhs)
      {
	return *this;
      }

    OctaveBranchInsnVisitor::operator=(rhs);

    return *this;
  }


  shared_ptr<AltEntryFunction> 
  M480CallInsnVisitor::getCurrentFn() const
  {
    return m_currentFn;
  }

  void M480CallInsnVisitor::visit(const InvalidOctaveInstruction& v){}
  void M480CallInsnVisitor::visit(const M480AddwhInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddwlInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddwwInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddlInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubwhInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubwlInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubwwInstruction &){}
  void M480CallInsnVisitor::visit(const M480SublInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddwhiInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddwliInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddwwiInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddliInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubwhiInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubwliInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubwwiInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubliInstruction &){}
  void M480CallInsnVisitor::visit(const M480FfsInstruction &){}
  void M480CallInsnVisitor::visit(const M480FlsInstruction &){}
  void M480CallInsnVisitor::visit(const M480ParInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddInstruction &){}
  void M480CallInsnVisitor::visit(const M480Add4xInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddcInstruction &){}
  void M480CallInsnVisitor::visit(const M480AndInstruction &){}
  void M480CallInsnVisitor::visit(const M480MaxInstruction &){}
  void M480CallInsnVisitor::visit(const M480MinInstruction &){}
  void M480CallInsnVisitor::visit(const M480OrInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubbInstruction &){}
  void M480CallInsnVisitor::visit(const M480XorInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddiInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddciInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubiInstruction &){}
  void M480CallInsnVisitor::visit(const M480SubbiInstruction &){}  
  void M480CallInsnVisitor::visit(const M480RandInstruction &){}
  void M480CallInsnVisitor::visit(const M480RotlInstruction &){}
  void M480CallInsnVisitor::visit(const M480RotrInstruction &){}
  void M480CallInsnVisitor::visit(const M480ClrbInstruction &){}
  void M480CallInsnVisitor::visit(const M480SetbInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShftInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShftaInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShlInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShrInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShraInstruction &){}
  void M480CallInsnVisitor::visit(const M480RandiInstruction &){}
  void M480CallInsnVisitor::visit(const M480RotliInstruction &){}
  void M480CallInsnVisitor::visit(const M480RotriInstruction &){}
  void M480CallInsnVisitor::visit(const M480SetbiInstruction &){}
  void M480CallInsnVisitor::visit(const M480ClrbiInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShliInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShriInstruction &){}
  void M480CallInsnVisitor::visit(const M480ShraiInstruction &){}
  void M480CallInsnVisitor::visit(const M480MaxiInstruction &){}
  void M480CallInsnVisitor::visit(const M480MiniInstruction &){}
  void M480CallInsnVisitor::visit(const M480AndiInstruction &){}
  void M480CallInsnVisitor::visit(const M480OriInstruction &){}
  void M480CallInsnVisitor::visit(const M480XoriInstruction &){}
  void M480CallInsnVisitor::visit(const M480MulInstruction &){}
  void M480CallInsnVisitor::visit(const M480MulhInstruction &){}
  void M480CallInsnVisitor::visit(const M480MuliInstruction &){}
  void M480CallInsnVisitor::visit(const M480MulhiInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddneInstruction &){}
  void M480CallInsnVisitor::visit(const M480AddneiInstruction &){}
  void M480CallInsnVisitor::visit(const M480ByteswInstruction &){}
  void M480CallInsnVisitor::visit(const M480BcdrInstruction &){}
  void M480CallInsnVisitor::visit(const M480BcrInstruction &){}
  void M480CallInsnVisitor::visit(const M480BcdiInstruction &){}
  void M480CallInsnVisitor::visit(const M480BciInstruction &){}
  void M480CallInsnVisitor::visit(const M480BnzrInstruction &){}
  void M480CallInsnVisitor::visit(const M480BzrInstruction &){}
  void M480CallInsnVisitor::visit(const M480BnziInstruction &){}
  void M480CallInsnVisitor::visit(const M480BziInstruction &){}
  void M480CallInsnVisitor::visit(const M480RnmiInstruction &){}
  void M480CallInsnVisitor::visit(const M480RintInstruction &){}
  void M480CallInsnVisitor::visit(const M480BrsInstruction &){}
  void M480CallInsnVisitor::visit(const M480BrslInstruction &){}
  void M480CallInsnVisitor::visit(const M480BrspreInstruction &){}
  void M480CallInsnVisitor::visit(const M480CmpInstruction &){}
  void M480CallInsnVisitor::visit(const M480CmpiInstruction &){}
  void M480CallInsnVisitor::visit(const M480CmprInstruction &){}
  void M480CallInsnVisitor::visit(const M480CmpriInstruction &){}
  void M480CallInsnVisitor::visit(const M480BiInstruction &){}
  void M480CallInsnVisitor::visit(const M480BrInstruction &){}
  void M480CallInsnVisitor::visit(const M480JtablebrInstruction &){}
  void M480CallInsnVisitor::visit(const M480JtableRelativebrInstruction &){}
  void M480CallInsnVisitor::visit(const M480DepbInstruction &){}
  void M480CallInsnVisitor::visit(const M480DepbiInstruction &){}
  void M480CallInsnVisitor::visit(const M480ExtbInstruction &){}
  void M480CallInsnVisitor::visit(const M480CmovInstruction &){}
  void M480CallInsnVisitor::visit(const M480CmoviInstruction &){}
  void M480CallInsnVisitor::visit(const M480DmapInstruction &){}
  void M480CallInsnVisitor::visit(const M480DmasrInstruction &){}
  void M480CallInsnVisitor::visit(const M480Dmau0Instruction &){}
  void M480CallInsnVisitor::visit(const M480Dmau1Instruction &){}
  void M480CallInsnVisitor::visit(const M480LihInstruction &){}
  void M480CallInsnVisitor::visit(const M480LilInstruction &){}
  void M480CallInsnVisitor::visit(const M480LwihInstruction &){}
  void M480CallInsnVisitor::visit(const M480LwilInstruction &){}
  void M480CallInsnVisitor::visit(const M480LaihInstruction &){}
  void M480CallInsnVisitor::visit(const M480LailInstruction &){}
  void M480CallInsnVisitor::visit(const M480NopInstruction &){}
  void M480CallInsnVisitor::visit(const M480Hec5Instruction &){}
  void M480CallInsnVisitor::visit(const M480MvInstruction &){}
  void M480CallInsnVisitor::visit(const M480MvrhInstruction &){}
  void M480CallInsnVisitor::visit(const M480MvhrInstruction &){}
  void M480CallInsnVisitor::visit(const M480UnlinkInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinkInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinksInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinkspInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinksplInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinksrInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinksdInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinkccInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinkcclInstruction &){}
  void M480CallInsnVisitor::visit(const M480LinksioInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmspInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmsplInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmsrInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmsdInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmccInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmcclInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmsiInstruction &){}
  void M480CallInsnVisitor::visit(const M480LmmsInstruction &){}
  void M480CallInsnVisitor::visit(const M480LspInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmspInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmsplInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmsrInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmsdInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmccInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmcclInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmsiInstruction &){}
  void M480CallInsnVisitor::visit(const M480SmmsInstruction &){}
  void M480CallInsnVisitor::visit(const M480SspInstruction &){}
  void M480CallInsnVisitor::visit(const M480GetInstruction &){}
  void M480CallInsnVisitor::visit(const M480PutcInstruction &){}
  void M480CallInsnVisitor::visit(const M480PutmInstruction &){}
  void M480CallInsnVisitor::visit(const M480PutpInstruction &){}
  void M480CallInsnVisitor::visit(const M480PutdInstruction &){}
  void M480CallInsnVisitor::visit(const M480TsetbInstruction &){}
  void M480CallInsnVisitor::visit(const M480TclrbInstruction &){}

  void M480CallInsnVisitor::visit(const M480JHec5Instruction &)
  {}

  void M480CallInsnVisitor::visit(const M480JaddlInstruction &i)
  {}
  
  void M480CallInsnVisitor::visit(const M480JaddliInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JaddwhInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JaddwhiInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JaddwlInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JaddwliInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JaddwwInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JaddwwiInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsublInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubliInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubwhInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubwhiInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubwlInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubwliInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubwwInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JsubwwiInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbcdiInstruction &i)
  {
    BranchIsCallVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc1();
    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	if(!rpc->isNullOperand())
	  { 
	    //RPC present, hence a call..
	   opnd->accept(v);
	  }
      }

  }

  void M480CallInsnVisitor::visit(const M480JbcdrInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbciInstruction &i)
  {
    BranchIsCallVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc1();

    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	if(!rpc->isNullOperand())
	  { 
	    //RPC present, hence a call..
	   opnd->accept(v);
	  }
      }
  }

  void M480CallInsnVisitor::visit(const M480JbcrInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JrnmiInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JrintInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbiInstruction &i)
  {
    BranchIsCallVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc1();

    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getDst();
	
	if(!rpc->isNullOperand())
	  { 
	    //RPC present, hence a call..
	   opnd->accept(v);
	  }
      }
  }
  
  void M480CallInsnVisitor::visit(const M480JbnzrInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbnziInstruction &i)
  {
    BranchIsCallVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc2();


    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();
	
	if(!rpc->isNullOperand())
	  { 
	    //RPC present, hence a call..
	    opnd->accept(v);
	  }
      }
  }

  void M480CallInsnVisitor::visit(const M480JbrInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbrsInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbrslInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbzrInstruction &i)
  {}

  void M480CallInsnVisitor::visit(const M480JbziInstruction &i)
  {
    BranchIsCallVisitor v(getCurrentFn());
    shared_ptr<const LlirOperand> opnd = i.getSrc2();

    if(!opnd->isNullOperand()) 
      {
	shared_ptr<const LlirOperand> rpc = i.getCmpReg();
	
	if(!rpc->isNullOperand())
	  { 
	    //RPC present, hence a call..
	    opnd->accept(v);
	  }
      }
  }

  void M480CallInsnVisitor::visit(const M480JcmpInstruction &i)
  {}
  
  void M480CallInsnVisitor::visit(const M480JcmpiInstruction &i)
  {}
  
  void M480CallInsnVisitor::visit(const M480JtsetbInstruction &i)
  {}
  
  void M480CallInsnVisitor::visit(const M480JtclrbInstruction &i)
  {}


  ///////////////////////////////////////////////



}
