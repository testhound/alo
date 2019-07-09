#include <cassert>
using namespace std;

#include <LlirException.h>
#include "M470Factory.h"


namespace Llir
{

  M470Factory::M470Factory() : 
    OctaveFactory()
  {}

  M470Factory::~M470Factory()
  {}

  shared_ptr<OctaveInstruction>
  M470Factory::createAddwhInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddwhInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }
  shared_ptr<OctaveInstruction>
  M470Factory::createAddwlInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddwlInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddwwInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddwwInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddlInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddlInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   dst, 
								   target)));
  }

  //

  shared_ptr<OctaveInstruction>
  M470Factory::createAddwhiInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddwhiInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddwliInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddwliInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddwwiInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddwwiInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddliInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const UnsignedImmediate> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddliInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubwhInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubwhInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }
  shared_ptr<OctaveInstruction>
  M470Factory::createSubwlInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubwlInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubwwInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubwwInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSublInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SublInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   dst, 
								   target)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createSubwhiInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubwhiInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubwliInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubwliInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubwwiInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubwwiInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubliInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const UnsignedImmediate> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubliInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createFfsInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> findFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470FfsInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  dst, 
								  abcFlag, 
								  findFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createFlsInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> findFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470FlsInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  dst, 
								  abcFlag, 
								  findFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createParInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ParInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAdd4xInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const Register> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470Add4xInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddcInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddcInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddciInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddciInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubbInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubbInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSubbiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470SubbiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAndInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470AndInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createOrInstruction(unsigned int lineNum, 
				   unsigned int srcLineNum, 
				   const char* srcFileName, 
				   shared_ptr<const Register> src1,
				   shared_ptr<const Register> src2, 
				   shared_ptr<const Register> dst, 
				   shared_ptr<const LlirOperand> abcFlag,
				   shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470OrInstruction(lineNum, 
								 srcLineNum, 
								 srcFileName, 
								 src1, 
								 src2, 
								 dst, 
								 abcFlag, 
								 modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createXorInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470XorInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMaxInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MaxInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMinInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MinInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRandInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RandInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createRotlInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RotlInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRotrInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RotrInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createClrbInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ClrbInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSetbInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470SetbInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShftInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShftInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShftaInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const Register> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShftaInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShlInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShlInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShrInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShrInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShraInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShraInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRandiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RandiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRotliInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RotliInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRotriInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RotriInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSetbiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470SetbiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createClrbiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ClrbiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createShliInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShliInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShriInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShriInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createShraiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ShraiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMaxiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MaxiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMiniInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MiniInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAndiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470AndiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createOriInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const SignedImmediate> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470OriInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createXoriInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470XoriInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMulInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MulInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMulhInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MulhInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMuliInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MuliInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMulhiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const SignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MulhiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDivInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470DivInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDiviInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470DiviInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddneInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const Register> src2, 
				      shared_ptr<const Register> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddneInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createAddneiInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> src1,
				       shared_ptr<const UnsignedImmediate> src2, 
				       shared_ptr<const Register> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M470AddneiInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1, 
								     src2, 
								     dst)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createByteswInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const UnsignedImmediate> b0, 
				       shared_ptr<const UnsignedImmediate> b1, 
				       shared_ptr<const UnsignedImmediate> b2, 
				       shared_ptr<const UnsignedImmediate> b3,
				       shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ByteswInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     src1,
								     dst, 
								     b0, 
								     b1, 
								     b2,
								     b3, 
								     abcFlag)));
  }
	
  shared_ptr<OctaveInstruction> 
  M470Factory::createBcdrInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<EssFlag> essFlag, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470BcdrInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1,
								   essFlag, 
								   dst, 
								   flags)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createBcrInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<EssFlag> essFlag, 
				    shared_ptr<const LlirOperand> dst, 
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470BcrInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1,
								  essFlag, 
								  dst, 
								  flags)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createBcdiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> src1, 
				     shared_ptr<EssFlag> essFlag, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470BcdiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1,
								   essFlag, 
								   dst, 
								   flags)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createBciInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const LlirOperand> src1, 
				    shared_ptr<EssFlag> essFlag, 
				    shared_ptr<const LlirOperand> dst, 
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470BciInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1,
								  essFlag, 
								  dst, 
								  flags)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createBnzrInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> src2,
				     shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M470BnzrInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   cmpReg)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBzrInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<const Register> src2, 
				    shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M470BzrInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  cmpReg)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBnziInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const LlirOperand> src2, 
				     shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M470BnziInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   cmpReg)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBziInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<const LlirOperand> src2, 
				    shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M470BziInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2, 
								  cmpReg)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createTsetbInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const UnsignedImmediate> bitpos, 
				      shared_ptr<const LlirOperand> disp)
  {
    return (shared_ptr<OctaveInstruction> (new M470TsetbInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    bitpos, 
								    disp)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createTclrbInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const UnsignedImmediate> bitpos, 
				      shared_ptr<const LlirOperand> disp)
  {
    return (shared_ptr<OctaveInstruction> (new M470TclrbInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    bitpos, 
								    disp)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRnmiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RnmiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   diFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createRintInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470RintInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   diFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBrsInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M470BrsInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  dst)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBrslInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> brslFlags)
  {
    return (shared_ptr<OctaveInstruction> (new M470BrslInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   brslFlags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBrspreInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName)
  {
    return (shared_ptr<OctaveInstruction> (new M470BrspreInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createCmpInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<const Register> src2,
				    shared_ptr<const LlirOperand> abcFlag, 
				    shared_ptr<const LlirOperand> branchTarget)
  {
    return (shared_ptr<OctaveInstruction> (new M470CmpInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  src1, 
								  src2,
								  abcFlag, 
								  branchTarget)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createCmpiInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const LlirOperand> abcFlag, 
				     shared_ptr<const LlirOperand> branchTarget)
  {
    return (shared_ptr<OctaveInstruction> (new M470CmpiInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2,
								   abcFlag, 
								   branchTarget)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createCmprInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> signFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470CmprInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   signFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createCmpriInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const SignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> signFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470CmpriInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    signFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBiInstruction(unsigned int lineNum, 
				   unsigned int srcLineNum, 
				   const char* srcFileName, 
				   shared_ptr<const LlirOperand> src1,
				   shared_ptr<const LlirOperand> dst, 
				   shared_ptr<const LlirOperand> cdFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470BiInstruction(lineNum, 
								 srcLineNum, 
								 srcFileName, 
								 src1, 
								 dst, 
								 cdFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createBrInstruction(unsigned int lineNum, 
				   unsigned int srcLineNum, 
				   const char* srcFileName, 
				   shared_ptr<const Register> src1,
				   shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M470BrInstruction(lineNum, 
								 srcLineNum, 
								 srcFileName, 
								 src1, 
								 dst)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJtablebrInstruction(unsigned int lineNum, 
					 unsigned int srcLineNum, 
					 const char* srcFileName,
					 shared_ptr<const Register> src1,
					 shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJtableRelativebrInstruction(unsigned int lineNum, 
						 unsigned int srcLineNum, 
						 const char* srcFileName,
						 shared_ptr<const Register> src1,
						 shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDepbInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src, 
				     shared_ptr<const UnsignedImmediate> srcBitNum,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> dstBitNum, 
				     shared_ptr<const UnsignedImmediate> numBits, 
				     shared_ptr<const LlirOperand> depbFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470DepbInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src,
								   srcBitNum, 
								   dst,
								   dstBitNum,
								   numBits, 
								   depbFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createExtbInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src, 
				     shared_ptr<const UnsignedImmediate> srcBitNum,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> dstBitNum, 
				     shared_ptr<const UnsignedImmediate> numBits, 
				     shared_ptr<const LlirOperand> signFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470ExtbInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src,
								   srcBitNum, 
								   dst,
								   dstBitNum,
								   numBits, 
								   signFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDepbiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const UnsignedImmediate> src, 
				      shared_ptr<const Register> dst,
				      shared_ptr<const UnsignedImmediate> dstBitNum, 
				      shared_ptr<const UnsignedImmediate> numBits, 
				      shared_ptr<const LlirOperand> depbFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470DepbiInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName,
								    src,
								    dst,
								    dstBitNum,
								    numBits, 
								    depbFlag)));
  }


  shared_ptr<OctaveInstruction> 
  M470Factory::createCmovInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<EssFlag> essFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470CmovInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src1,
								   src2, 
								   dst,
								   essFlag)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createCmoviInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<EssFlag> essFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470CmoviInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    src1,
								    src2, 
								    dst,
								    essFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDmapInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470DmapInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   convertSingleToDmaMultiReg(src1), 
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDmasrInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470DmasrInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    convertSingleToDmaMultiReg(src1), 
								    flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDmau0Instruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470Dmau0Instruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    convertSingleToDmaMultiReg(src1), 
								    flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createDmau1Instruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470Dmau1Instruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    convertSingleToDmaMultiReg(src1),
								    flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLihInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> dst,
				    shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M470LihInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  dst, 
								  src)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLilInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> dst,
				    shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M470LilInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  dst, 
								  src)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLwihInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M470LwihInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLwilInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M470LwilInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLaihInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M470LaihInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLailInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M470LailInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createNopInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName)
  {
    return (shared_ptr<OctaveInstruction> (new M470NopInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createHec5Instruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> bytes,
				     shared_ptr<const LlirOperand> cumeFlag, 
				     shared_ptr<const LlirOperand> branchTarget)
  {
    return (shared_ptr<OctaveInstruction> (new M470Hec5Instruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src, 
								   dst,
								   bytes, 
								   branchTarget,
								   cumeFlag)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJHec5Instruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> bytes,
				     shared_ptr<const LlirOperand> cumeFlag, 
				     shared_ptr<const LlirOperand> branchTarget,
				      OctaveInstruction::BranchProbability)
  {    
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
 
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createMvInstruction(unsigned int lineNum, 
				   unsigned int srcLineNum, 
				   const char* srcFileName, 
				   shared_ptr<const Register> src,
				   shared_ptr<const Register> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M470MvInstruction(lineNum, 
								 srcLineNum, 
								 srcFileName, 
								 src, 
								 dst)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMvhrInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> mvhFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MvhrInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src, 
								   dst, 
								   mvhFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createMvrhInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> mvhFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470MvrhInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   src, 
								   dst, 
								   mvhFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createUnlinkInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs)
  {
    return (shared_ptr<OctaveInstruction> (new M470UnlinkInstruction(lineNum, 
								     srcLineNum, 
								     srcFileName, 
								     convertSingleToMultiReg(regs))));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinkInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> regs,
				     shared_ptr<OctaveMemory> mem, 
				     shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470LinkInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   convertSingleToMultiReg(regs),
								   mem, 
								   linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinksInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470LinksInstruction(lineNum, 
								    srcLineNum, 
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinkspInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinksplInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const Register> regs,
					shared_ptr<OctaveMemory> mem, 
					shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinksrInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinksdInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinkccInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinkcclInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const Register> regs,
					shared_ptr<OctaveMemory> mem, 
					shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLinksioInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const Register> regs,
					shared_ptr<OctaveMemory> mem, 
					shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createLmmInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem, 
				    shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470LmmInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem, 
								  linkFlag)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createLmmsInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> regs,
				     shared_ptr<OctaveMemory> mem, 
				     shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470LmmsInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   convertSingleToMultiReg(regs),
								   mem, 
								   linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLspInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem, 
				    shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M470LspInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem, 
								  linkFlag)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createLmmspInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLmmsplInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createLmmccInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLmmcclInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createLmmsdInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createLmmsrInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction>
  M470Factory::createLmmsiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createSmmInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M470SmmInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSmmsInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> regs,
				     shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M470SmmsInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   convertSingleToMultiReg(regs),
								   mem)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSspInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M470SspInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createSmmspInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSmmsplInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createSmmccInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSmmcclInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction>
  M470Factory::createSmmsdInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createSmmsrInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction>
  M470Factory::createSmmsiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPutInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> rsa,
				    shared_ptr<const Register> rsb, 
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470PutInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  rsa, 
								  rsb, 
								  flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createGetInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> rsa,
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470GetInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  rsa, 
								  flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPolInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> rsa,
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470PolInstruction(lineNum, 
								  srcLineNum, 
								  srcFileName, 
								  rsa, 
								  flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPutcInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const UnsignedImmediate> parOffset,
				     shared_ptr<const UnsignedImmediate> posOffset,
				     shared_ptr<const LlirOperand> pipeDepth,
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470PutcInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   parOffset, 
								   posOffset,
								   pipeDepth,
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPutcInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPutmInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPutpInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPutdInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createGetcInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const UnsignedImmediate> parOffset,
				     shared_ptr<const UnsignedImmediate> posOffset,
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470GetcInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   parOffset, 
								   posOffset,
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createPolcInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const UnsignedImmediate> parOffset,
				     shared_ptr<const UnsignedImmediate> posOffset,
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M470PolcInstruction(lineNum, 
								   srcLineNum, 
								   srcFileName, 
								   parOffset, 
								   posOffset,
								   flags)));
  }






  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddwhInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
    
  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddwlInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddwwInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
    
  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddlInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register>, 
				      shared_ptr<const Register>, 
				      shared_ptr<const LlirOperand>,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddwhiInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate>, 
					shared_ptr<const Register>, 
					shared_ptr<const LlirOperand>,
					OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddwliInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate>, 
					shared_ptr<const Register>, 
					shared_ptr<const LlirOperand>,
					OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddwwiInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate>, 
					shared_ptr<const Register>, 
					shared_ptr<const LlirOperand>,
					OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJaddliInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  

  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubwhInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }


  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubwlInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubwwInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJsublInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register>, 
				      shared_ptr<const Register>, 
				      shared_ptr<const LlirOperand>,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
    
  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubwhiInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate>, 
					shared_ptr<const Register>, 
					shared_ptr<const LlirOperand>,
					OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
 
  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubwliInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate>, 
					shared_ptr<const Register>, 
					shared_ptr<const LlirOperand>,
					OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubwwiInstruction(unsigned int lineNum, 
					unsigned int srcLineNum, 
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate>, 
					shared_ptr<const Register>, 
					shared_ptr<const LlirOperand>,
					OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJsubliInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate>, 
				       shared_ptr<const Register>, 
				       shared_ptr<const LlirOperand>,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
    
  shared_ptr<OctaveInstruction> 
  M470Factory::createJbcdrInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<EssFlag>, 
				      shared_ptr<const LlirOperand> dst, 
				      shared_ptr<const LlirOperand> flags,
				      shared_ptr<const LlirOperand> targetList,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJbcdiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> src1, 
				      shared_ptr<EssFlag>, 
				      shared_ptr<const LlirOperand> dst, 
				      shared_ptr<const LlirOperand> flags,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJbcrInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<EssFlag>, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags,
				     shared_ptr<const LlirOperand> targetList,
				     OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJbciInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> src1, 
				     shared_ptr<EssFlag>, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags,
				     OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJbnzrInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> src2, 
				      shared_ptr<const LlirOperand> cmpReg,
				      shared_ptr<const LlirOperand> targetList,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJbzrInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> src2, 
				     shared_ptr<const LlirOperand> cmpReg,
				     shared_ptr<const LlirOperand> targetList,
				     OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  shared_ptr<OctaveInstruction> 
  M470Factory::createJbnziInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const LlirOperand> src2, 
				      shared_ptr<const LlirOperand> cmpReg,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJbziInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const LlirOperand> src2, 
				     shared_ptr<const LlirOperand> cmpReg,
				     OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M470Factory::createJtsetbInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const UnsignedImmediate> bitpos, 
				       shared_ptr<const LlirOperand> disp,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  shared_ptr<OctaveInstruction> 
  M470Factory::createJtclrbInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum, 
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const UnsignedImmediate> bitpos, 
				       shared_ptr<const LlirOperand> disp,
				       OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJrnmiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  shared_ptr<OctaveInstruction> 
  M470Factory::createJrintInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  shared_ptr<OctaveInstruction> 
  M470Factory::createJbrsInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  shared_ptr<OctaveInstruction> 
  M470Factory::createJbrslInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> brslFlags){
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJbiInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const LlirOperand> src1,
				    shared_ptr<const LlirOperand> dst, 
				    shared_ptr<const LlirOperand> cdFlag)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }
      
  shared_ptr<OctaveInstruction> 
  M470Factory::createJbrInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum, 
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const LlirOperand> dst,
				    shared_ptr<const LlirOperand> targetList)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M470Factory::createJcmpInstruction(unsigned int lineNum, 
				     unsigned int srcLineNum, 
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> src2,
				     shared_ptr<const LlirOperand> abcFlag, 
				     shared_ptr<const LlirOperand> branchTarget,
				     OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

  shared_ptr<OctaveInstruction> 
  M470Factory::createJcmpiInstruction(unsigned int lineNum, 
				      unsigned int srcLineNum, 
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const SignedImmediate> src2, 
				      shared_ptr<const LlirOperand> abcFlag, 
				      shared_ptr<const LlirOperand> branchTarget,
				      OctaveInstruction::BranchProbability)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum, 
									srcFileName)));
  }

}
