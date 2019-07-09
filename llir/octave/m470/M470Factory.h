#ifndef _LLIR_M470_FACTORY_H
#define _LLIR_M470_FACTORY_H

#include <OctaveFactory.h>
#include "M470Instructions.h"

namespace Llir
{
  class M470Factory : public OctaveFactory
    {
    public:
      M470Factory();
      ~M470Factory();

      shared_ptr<OctaveInstruction> createAddwhInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddwlInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddwwInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddlInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register>, 
							  shared_ptr<const Register>, 
							  shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddwhiInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const UnsignedImmediate>, 
							    shared_ptr<const Register>, 
							    shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddwliInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const UnsignedImmediate>, 
							    shared_ptr<const Register>, 
							    shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddwwiInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const UnsignedImmediate>, 
							    shared_ptr<const Register>, 
							    shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createAddliInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const UnsignedImmediate>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubwhInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubwlInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubwwInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSublInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register>, 
							  shared_ptr<const Register>, 
							  shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubwhiInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const UnsignedImmediate>, 
							    shared_ptr<const Register>, 
							    shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubwliInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const UnsignedImmediate>, 
							    shared_ptr<const Register>, 
							    shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubwwiInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const UnsignedImmediate>, 
							    shared_ptr<const Register>, 
							    shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createSubliInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const UnsignedImmediate>, 
							   shared_ptr<const Register>, 
							   shared_ptr<const LlirOperand>);

      shared_ptr<OctaveInstruction> createFfsInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> findFlag);

      shared_ptr<OctaveInstruction> createFlsInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> findFlag);

      shared_ptr<OctaveInstruction> createParInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag);

      shared_ptr<OctaveInstruction> createAddInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createAdd4xInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const Register> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag,
							   shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createAddcInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createAddiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const UnsignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createAddciInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag,
							   shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createSubInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createSubbInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createSubiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const UnsignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createSubbiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag,
							   shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createAndInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createAndiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);

      shared_ptr<OctaveInstruction> createOrInstruction(unsigned int lineNum,
							unsigned int srcLineNum,
							const char* srcFileName, 
							shared_ptr<const Register> src1,
							shared_ptr<const Register> src2, 
							shared_ptr<const Register> dst, 
							shared_ptr<const LlirOperand> abcFlag,
							shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createOriInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const SignedImmediate> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag);

      shared_ptr<OctaveInstruction> createXorInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> modFlag);

      shared_ptr<OctaveInstruction> createXoriInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);

      shared_ptr<OctaveInstruction> createMaxInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> modFlag);
      shared_ptr<OctaveInstruction> createMinInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> modFlag);
      shared_ptr<OctaveInstruction> createRandInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createRotlInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createRotrInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createClrbInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createSetbInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShftInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShftaInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const Register> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShlInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShrInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShraInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createRandiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createRotliInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createRotriInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createSetbiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createClrbiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShliInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const UnsignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShriInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const UnsignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createShraiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createMaxiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createMiniInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag);
      shared_ptr<OctaveInstruction> createMulInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> sxFlag);
      shared_ptr<OctaveInstruction> createMulhInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> sxFlag);
      shared_ptr<OctaveInstruction> createMuliInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> sxFlag);
      shared_ptr<OctaveInstruction> createMulhiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const SignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> sxFlag);
      shared_ptr<OctaveInstruction> createDivInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1,
							 shared_ptr<const Register> src2, 
							 shared_ptr<const Register> dst, 
							 shared_ptr<const LlirOperand> sxFlag);
      shared_ptr<OctaveInstruction> createDiviInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> sxFlag);
      shared_ptr<OctaveInstruction> createAddneInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const Register> src2, 
							   shared_ptr<const Register> dst);
      shared_ptr<OctaveInstruction> createAddneiInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> src1,
							    shared_ptr<const UnsignedImmediate> src2, 
							    shared_ptr<const Register> dst);
      shared_ptr<OctaveInstruction> createByteswInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> src1, 
							    shared_ptr<const Register> dst, 
							    shared_ptr<const UnsignedImmediate> b0, 
							    shared_ptr<const UnsignedImmediate> b1, 
							    shared_ptr<const UnsignedImmediate> b2, 
							    shared_ptr<const UnsignedImmediate> b3,
							    shared_ptr<const LlirOperand> abcFlag);

      shared_ptr<OctaveInstruction> createBcdrInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1, 
							  shared_ptr<EssFlag>, 
							  shared_ptr<const LlirOperand> dst, 
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createBcrInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1, 
							 shared_ptr<EssFlag>, 
							 shared_ptr<const LlirOperand> dst, 
							 shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createBcdiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const LlirOperand> src1, 
							  shared_ptr<EssFlag>, 
							  shared_ptr<const LlirOperand> dst, 
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createBciInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const LlirOperand> src1, 
							 shared_ptr<EssFlag>, 
							 shared_ptr<const LlirOperand> dst, 
							 shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createBnzrInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1, 
							  shared_ptr<const Register> src2, 
							  shared_ptr<const LlirOperand> cmpReg);
      shared_ptr<OctaveInstruction> createBzrInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1, 
							 shared_ptr<const Register> src2,
							 shared_ptr<const LlirOperand> cmpReg);
      shared_ptr<OctaveInstruction> createBnziInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1, 
							  shared_ptr<const LlirOperand> src2, 
							  shared_ptr<const LlirOperand> cmpReg);
      shared_ptr<OctaveInstruction> createBziInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1, 
							 shared_ptr<const LlirOperand> src2,
							 shared_ptr<const LlirOperand> cmpReg);
      shared_ptr<OctaveInstruction> createTsetbInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1, 
							   shared_ptr<const UnsignedImmediate> bitpos, 
							   shared_ptr<const LlirOperand> disp);
      shared_ptr<OctaveInstruction> createTclrbInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1, 
							   shared_ptr<const UnsignedImmediate> bitpos, 
							   shared_ptr<const LlirOperand> disp);
      shared_ptr<OctaveInstruction> createRnmiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const LlirOperand> diFlag);
      shared_ptr<OctaveInstruction> createRintInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const LlirOperand> diFlag);
      shared_ptr<OctaveInstruction> createBrsInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const LlirOperand> dst);
      shared_ptr<OctaveInstruction> createBrslInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const LlirOperand> brslFlags);
      shared_ptr<OctaveInstruction> createBrspreInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName);
      shared_ptr<OctaveInstruction> createCmpInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> src1, 
							 shared_ptr<const Register> src2, 
							 shared_ptr<const LlirOperand> abcFlag,
							 shared_ptr<const LlirOperand> branchTarget);
      shared_ptr<OctaveInstruction> createCmpiInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1, 
							  shared_ptr<const SignedImmediate> src2, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> branchTarget);
      shared_ptr<OctaveInstruction> createJcmpInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1, 
							  shared_ptr<const Register> src2, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> branchTarget,
							  OctaveInstruction::BranchProbability);
      shared_ptr<OctaveInstruction> createJcmpiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1, 
							   shared_ptr<const SignedImmediate> src2, 
							   shared_ptr<const LlirOperand> abcFlag,
							   shared_ptr<const LlirOperand> branchTarget,
							   OctaveInstruction::BranchProbability);
      shared_ptr<OctaveInstruction> createCmprInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> abcFlag,
							  shared_ptr<const LlirOperand> signFlag);
      shared_ptr<OctaveInstruction> createCmpriInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const SignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<const LlirOperand> abcFlag,
							   shared_ptr<const LlirOperand> signFlag);
      shared_ptr<OctaveInstruction> createBiInstruction(unsigned int lineNum,
							unsigned int srcLineNum,
							const char* srcFileName, 
							shared_ptr<const LlirOperand> src1,
							shared_ptr<const LlirOperand> dst, 
							shared_ptr<const LlirOperand> cdFlag);
      shared_ptr<OctaveInstruction> createBrInstruction(unsigned int lineNum,
							unsigned int srcLineNum,
							const char* srcFileName, 
							shared_ptr<const Register> src1,
							shared_ptr<const LlirOperand> dst);
      shared_ptr<OctaveInstruction> createJtablebrInstruction(unsigned int lineNum,
							      unsigned int srcLineNum,
							      const char* srcFileName, 
							      shared_ptr<const Register> src1,
							      shared_ptr<const LlirOperand> dst);
      shared_ptr<OctaveInstruction> createJtableRelativebrInstruction(unsigned int lineNum,
								      unsigned int srcLineNum,
								      const char* srcFileName, 
								      shared_ptr<const Register> src1,
								      shared_ptr<const LlirOperand> dst); 
     shared_ptr<OctaveInstruction> createDepbInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src, 
							  shared_ptr<const UnsignedImmediate> srcBitNum,
							  shared_ptr<const Register> dst,
							  shared_ptr<const UnsignedImmediate> dstBitNum, 
							  shared_ptr<const UnsignedImmediate> numBits, 
							  shared_ptr<const LlirOperand> depbFlag);
      shared_ptr<OctaveInstruction> createDepbiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const UnsignedImmediate> src, 
							   shared_ptr<const Register> dst,
							   shared_ptr<const UnsignedImmediate> dstBitNum, 
							   shared_ptr<const UnsignedImmediate> numBits, 
							   shared_ptr<const LlirOperand> depbFlag);
      shared_ptr<OctaveInstruction> createExtbInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src, 
							  shared_ptr<const UnsignedImmediate> srcBitNum,
							  shared_ptr<const Register> dst,
							  shared_ptr<const UnsignedImmediate> dstBitNum, 
							  shared_ptr<const UnsignedImmediate> numBits, 
							  shared_ptr<const LlirOperand> signFlag);
      shared_ptr<OctaveInstruction> createCmovInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const Register> src2, 
							  shared_ptr<const Register> dst, 
							  shared_ptr<EssFlag> essFlag);
      shared_ptr<OctaveInstruction> createCmoviInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> src2, 
							   shared_ptr<const Register> dst, 
							   shared_ptr<EssFlag> essFlag);
      shared_ptr<OctaveInstruction> createDmapInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src1,
							  shared_ptr<const UnsignedImmediate> flags);
      shared_ptr<OctaveInstruction> createDmasrInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> flags);
      shared_ptr<OctaveInstruction> createDmau0Instruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> flags);
      shared_ptr<OctaveInstruction> createDmau1Instruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> src1,
							   shared_ptr<const UnsignedImmediate> flags);
      shared_ptr<OctaveInstruction> createLihInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> dst,
							 shared_ptr<const LlirOperand> src);
      shared_ptr<OctaveInstruction> createLilInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> dst,
							 shared_ptr<const LlirOperand> src);
      shared_ptr<OctaveInstruction> createLwihInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> dst,
							  shared_ptr<const LlirOperand> src);
      shared_ptr<OctaveInstruction> createLwilInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> dst,
							  shared_ptr<const LlirOperand> src);
      shared_ptr<OctaveInstruction> createLaihInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> dst,
							  shared_ptr<const LlirOperand> src);
      shared_ptr<OctaveInstruction> createLailInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> dst,
							  shared_ptr<const LlirOperand> src);
      shared_ptr<OctaveInstruction> createNopInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName);
      shared_ptr<OctaveInstruction> createHec5Instruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src,
							  shared_ptr<const Register> dst,
							  shared_ptr<const UnsignedImmediate> bytes,
							  shared_ptr<const LlirOperand> cumeFlag, 
							  shared_ptr<const LlirOperand> branchTarget);
      
      shared_ptr<OctaveInstruction> createJHec5Instruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src,
							  shared_ptr<const Register> dst,
							  shared_ptr<const UnsignedImmediate> bytes,
							  shared_ptr<const LlirOperand> cumeFlag, 
							  shared_ptr<const LlirOperand> branchTarget,
							  OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> createMvInstruction(unsigned int lineNum,
							unsigned int srcLineNum,
							const char* srcFileName, 
							shared_ptr<const Register> src,
							shared_ptr<const Register> dst);
      shared_ptr<OctaveInstruction> createMvhrInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src,
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> mvhFlag);
      shared_ptr<OctaveInstruction> createMvrhInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> src,
							  shared_ptr<const Register> dst, 
							  shared_ptr<const LlirOperand> mvhFlag);
      shared_ptr<OctaveInstruction> createUnlinkInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs);
      shared_ptr<OctaveInstruction> createLinkInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> regs,
							  shared_ptr<OctaveMemory> mem, 
							  shared_ptr<const LinkFlag> linkFlag);
      shared_ptr<OctaveInstruction> createLinksInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem, 
							   shared_ptr<const LinkFlag> linkFlag);    
      shared_ptr<OctaveInstruction> createLinkspInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem, 
							    shared_ptr<const LinkFlag> linkFlag); 
      shared_ptr<OctaveInstruction> createLinksplInstruction(unsigned int lineNum,
							     unsigned int srcLineNum,
							     const char* srcFileName, 
							     shared_ptr<const Register> regs,
							     shared_ptr<OctaveMemory> mem, 
							     shared_ptr<const LinkFlag> linkFlag); 
      shared_ptr<OctaveInstruction> createLinksrInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem, 
							    shared_ptr<const LinkFlag> linkFlag); 
      shared_ptr<OctaveInstruction> createLinksdInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem, 
							    shared_ptr<const LinkFlag> linkFlag); 
      shared_ptr<OctaveInstruction> createLinkccInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem, 
							    shared_ptr<const LinkFlag> linkFlag); 
      shared_ptr<OctaveInstruction> createLinkcclInstruction(unsigned int lineNum,
							     unsigned int srcLineNum,
							     const char* srcFileName, 
							     shared_ptr<const Register> regs,
							     shared_ptr<OctaveMemory> mem, 
							     shared_ptr<const LinkFlag> linkFlag); 
      shared_ptr<OctaveInstruction> createLinksioInstruction(unsigned int lineNum,
							     unsigned int srcLineNum,
							     const char* srcFileName, 
							     shared_ptr<const Register> regs,
							     shared_ptr<OctaveMemory> mem, 
							     shared_ptr<const LinkFlag> linkFlag);
      shared_ptr<OctaveInstruction> createLmmInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> regs,
							 shared_ptr<OctaveMemory> mem, 
							 shared_ptr<const LlirOperand> linkFlag);
      shared_ptr<OctaveInstruction> createLmmsInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> regs,
							  shared_ptr<OctaveMemory> mem, 
							  shared_ptr<const LlirOperand> linkFlag);
      shared_ptr<OctaveInstruction> createLspInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> regs,
							 shared_ptr<OctaveMemory> mem, 
							 shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmspInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem, 
							   shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmsplInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem, 
							    shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmccInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem, 
							   shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmcclInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem, 
							    shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmsrInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem, 
							   shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmsiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem, 
							   shared_ptr<const LlirOperand> linkFlag);

      shared_ptr<OctaveInstruction> createLmmsdInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem, 
							   shared_ptr<const LlirOperand> linkFlag);


      shared_ptr<OctaveInstruction> createSmmInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> regs,
							 shared_ptr<OctaveMemory> mem);
      shared_ptr<OctaveInstruction> createSmmsInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> regs,
							  shared_ptr<OctaveMemory> mem);
      shared_ptr<OctaveInstruction> createSspInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> regs,
							 shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmspInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmsplInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmccInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmcclInstruction(unsigned int lineNum,
							    unsigned int srcLineNum,
							    const char* srcFileName, 
							    shared_ptr<const Register> regs,
							    shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmsrInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmsiInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem);

      shared_ptr<OctaveInstruction> createSmmsdInstruction(unsigned int lineNum,
							   unsigned int srcLineNum,
							   const char* srcFileName, 
							   shared_ptr<const Register> regs,
							   shared_ptr<OctaveMemory> mem);


      shared_ptr<OctaveInstruction> createPutInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> rsa,
							 shared_ptr<const Register> rsb,
							 shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createGetInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> rsa,
							 shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPolInstruction(unsigned int lineNum,
							 unsigned int srcLineNum,
							 const char* srcFileName, 
							 shared_ptr<const Register> rsa,
							 shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPutcInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const UnsignedImmediate> parOffset,
							  shared_ptr<const UnsignedImmediate> posOffset,
							  shared_ptr<const LlirOperand> pipeDepth,
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPutcInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> rsa,
							  shared_ptr<const Register> rsb, 
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPutmInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> rsa,
							  shared_ptr<const Register> rsb, 
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPutpInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> rsa,
							  shared_ptr<const Register> rsb, 
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPutdInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const Register> rsa,
							  shared_ptr<const Register> rsb, 
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createGetcInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const UnsignedImmediate> parOffset,
							  shared_ptr<const UnsignedImmediate> posOffset,
							  shared_ptr<const LlirOperand> flags);
      shared_ptr<OctaveInstruction> createPolcInstruction(unsigned int lineNum,
							  unsigned int srcLineNum,
							  const char* srcFileName, 
							  shared_ptr<const UnsignedImmediate> parOffset,
							  shared_ptr<const UnsignedImmediate> posOffset,
							  shared_ptr<const LlirOperand> flags);

      shared_ptr<OctaveInstruction> 
	createJaddwhInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);
  
      shared_ptr<OctaveInstruction> 
	createJaddwlInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJaddwwInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);
    
      shared_ptr<OctaveInstruction> 
	createJaddlInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>,
			       OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJaddwhiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJaddwliInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJaddwwiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJaddliInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);


      shared_ptr<OctaveInstruction> 
	createJsubwhInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);


      shared_ptr<OctaveInstruction> 
	createJsubwlInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJsubwwInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);
    
      shared_ptr<OctaveInstruction> 
	createJsublInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register>, 
			       shared_ptr<const Register>, 
			       shared_ptr<const LlirOperand>,
			       OctaveInstruction::BranchProbability);
    
      shared_ptr<OctaveInstruction> 
	createJsubwhiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability);

 
      shared_ptr<OctaveInstruction> 
	createJsubwliInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability);

  
      shared_ptr<OctaveInstruction> 
	createJsubwwiInstruction(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName, 
				 shared_ptr<const UnsignedImmediate>, 
				 shared_ptr<const Register>, 
				 shared_ptr<const LlirOperand>,
				 OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJsubliInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const UnsignedImmediate>, 
				shared_ptr<const Register>, 
				shared_ptr<const LlirOperand>,
				OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbcdrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<EssFlag>, 
			       shared_ptr<const LlirOperand> dst, 
			       shared_ptr<const LlirOperand> flags,
			       shared_ptr<const LlirOperand> targetList,
			       OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbcdiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> src1, 
			       shared_ptr<EssFlag>, 
			       shared_ptr<const LlirOperand> dst, 
			       shared_ptr<const LlirOperand> flags,
			       OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbcrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<EssFlag>, 
			      shared_ptr<const LlirOperand> dst, 
			      shared_ptr<const LlirOperand> flags,
			      shared_ptr<const LlirOperand> targetList,
			      OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbciInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> src1, 
			      shared_ptr<EssFlag>, 
			      shared_ptr<const LlirOperand> dst, 
			      shared_ptr<const LlirOperand> flags,
			      OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbnzrInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const Register> src2, 
			       shared_ptr<const LlirOperand> cmpReg,
			       shared_ptr<const LlirOperand> targetList,
			       OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbzrInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const Register> src2, 
			      shared_ptr<const LlirOperand> cmpReg,
			      shared_ptr<const LlirOperand> targetList,
			      OctaveInstruction::BranchProbability);
 
      shared_ptr<OctaveInstruction> 
	createJbnziInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const Register> src1, 
			       shared_ptr<const LlirOperand> src2, 
			       shared_ptr<const LlirOperand> cmpReg,
			       OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJbziInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const Register> src1, 
			      shared_ptr<const LlirOperand> src2, 
			      shared_ptr<const LlirOperand> cmpReg,
			      OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJtsetbInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> src1, 
				shared_ptr<const UnsignedImmediate> bitpos, 
				shared_ptr<const LlirOperand> disp,
				OctaveInstruction::BranchProbability);

      shared_ptr<OctaveInstruction> 
	createJtclrbInstruction(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName, 
				shared_ptr<const Register> src1, 
				shared_ptr<const UnsignedImmediate> bitpos, 
				shared_ptr<const LlirOperand> disp,
				OctaveInstruction::BranchProbability);



      shared_ptr<OctaveInstruction> 
	createJrnmiInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> diFlag);


      shared_ptr<OctaveInstruction> 
	createJrintInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> diFlag);



      shared_ptr<OctaveInstruction> 
	createJbrsInstruction(unsigned int lineNum,
			      unsigned int srcLineNum,
			      const char* srcFileName, 
			      shared_ptr<const LlirOperand> dst);

      shared_ptr<OctaveInstruction> 
	createJbrslInstruction(unsigned int lineNum,
			       unsigned int srcLineNum,
			       const char* srcFileName, 
			       shared_ptr<const LlirOperand> brslFlags);

      shared_ptr<OctaveInstruction> 
	createJbiInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const LlirOperand> src1,
			     shared_ptr<const LlirOperand> dst, 
			     shared_ptr<const LlirOperand> cdFlag);

      shared_ptr<OctaveInstruction> 
	createJbrInstruction(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName, 
			     shared_ptr<const Register> src1,
			     shared_ptr<const LlirOperand> dst,
			     shared_ptr<const LlirOperand> targetList);


    };
} // namespace Llir
#endif
