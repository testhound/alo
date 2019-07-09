#include <cassert>

using namespace std;

#include <LlirException.h>

#include "M480Factory.h"



namespace Llir
{

  M480Factory::M480Factory() : 
    OctaveFactory()
  {}

  M480Factory::~M480Factory()
  {}

  shared_ptr<OctaveInstruction>
  M480Factory::createAddwhInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddwhInstruction(lineNum, 
								    srcLineNum,
								    srcFileName,
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddwhInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddwhInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddwlInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddwlInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddwlInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddwlInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createAddwwInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddwwInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddwwInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddwwInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddlInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddlInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   dst, 
								   target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddlInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddlInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target,
								    probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddwhiInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddwhiInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddwhiInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate> src1, 
					shared_ptr<const Register> dst, 
					shared_ptr<const LlirOperand> target,
					OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddwhiInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      src1, 
								      dst, 
								      target,
								      probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createAddwliInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddwliInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddwliInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate> src1, 
					shared_ptr<const Register> dst, 
					shared_ptr<const LlirOperand> target,
					OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddwliInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      src1, 
								      dst, 
								      target,
								      probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createAddwwiInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddwwiInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddwwiInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate> src1, 
					shared_ptr<const Register> dst, 
					shared_ptr<const LlirOperand> target,
					OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddwwiInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      src1, 
								      dst, 
								      target,
								      probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createAddliInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const UnsignedImmediate> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddliInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJaddliInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JaddliInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createSubwhInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubwhInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJsubwhInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubwhInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubwlInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubwlInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJsubwlInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubwlInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubwwInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubwwInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJsubwwInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubwwInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createSublInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SublInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   dst, 
								   target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJsublInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsublInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target,
								    probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createSubwhiInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubwhiInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJsubwhiInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate> src1, 
					shared_ptr<const Register> dst, 
					shared_ptr<const LlirOperand> target,
					OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubwhiInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      src1, 
								      dst, 
								      target,
								      probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createSubwliInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubwliInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJsubwliInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate> src1, 
					shared_ptr<const Register> dst, 
					shared_ptr<const LlirOperand> target,
					OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubwliInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      src1, 
								      dst, 
								      target,
								      probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubwwiInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubwwiInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJsubwwiInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const UnsignedImmediate> src1, 
					shared_ptr<const Register> dst, 
					shared_ptr<const LlirOperand> target,
					OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubwwiInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      src1, 
								      dst, 
								      target,
								      probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubliInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const UnsignedImmediate> src1, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> target)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubliInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    dst, 
								    target)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJsubliInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const UnsignedImmediate> src1, 
				       shared_ptr<const Register> dst, 
				       shared_ptr<const LlirOperand> target,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JsubliInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     dst, 
								     target,
								     probability)));
  }


  shared_ptr<OctaveInstruction> 
  M480Factory::createFfsInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> findFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480FfsInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  dst, 
								  abcFlag, 
								  findFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createFlsInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> findFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480FlsInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  dst, 
								  abcFlag, 
								  findFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createParInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ParInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAdd4xInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const Register> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480Add4xInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddcInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddcInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddciInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddciInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubbInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubbInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSubbiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480SubbiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAndInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480AndInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createOrInstruction(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName, 
				   shared_ptr<const Register> src1,
				   shared_ptr<const Register> src2, 
				   shared_ptr<const Register> dst, 
				   shared_ptr<const LlirOperand> abcFlag,
				   shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480OrInstruction(lineNum, 
								 srcLineNum,
								 srcFileName, 
								 src1, 
								 src2, 
								 dst, 
								 abcFlag, 
								 modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createXorInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480XorInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMaxInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MaxInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMinInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag,
				    shared_ptr<const LlirOperand> modFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MinInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag, 
								  modFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRandInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RandInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createRotlInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RotlInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRotrInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RotrInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createClrbInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ClrbInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSetbInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480SetbInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShftInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShftInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShftaInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const Register> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShftaInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShlInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShlInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShrInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShrInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShraInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShraInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRandiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RandiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRotliInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RotliInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRotriInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RotriInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSetbiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480SetbiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createClrbiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ClrbiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createShliInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShliInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShriInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShriInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createShraiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ShraiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMaxiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MaxiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMiniInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MiniInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAndiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480AndiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createOriInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const SignedImmediate> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480OriInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createXoriInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480XoriInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMulInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MulInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  dst, 
								  sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMulhInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MulhInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMuliInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MuliInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMulhiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const SignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> sxFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MulhiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    sxFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDivInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const Register> src2, 
				    shared_ptr<const Register> dst, 
				    shared_ptr<const LlirOperand> sxFlag)
  {
    // 480 has no Divide instructions

    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum,
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDiviInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> sxFlag)
  {
    // 480 has no Divide instructions

    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum,
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddneInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const Register> src2, 
				      shared_ptr<const Register> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddneInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createAddneiInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1,
				       shared_ptr<const UnsignedImmediate> src2, 
				       shared_ptr<const Register> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480AddneiInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     src2, 
								     dst)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createByteswInstruction(unsigned int lineNum,
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
    return (shared_ptr<OctaveInstruction> (new M480ByteswInstruction(lineNum, 
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
  M480Factory::createBcdrInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<EssFlag> essFlag, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480BcdrInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1,
								   essFlag, 
								   dst, 
								   flags)));
  }
	
  shared_ptr<OctaveInstruction> 
  M480Factory::createJbcdrInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<EssFlag> essFlag, 
				      shared_ptr<const LlirOperand> dst, 
				      shared_ptr<const LlirOperand> flags,
				      shared_ptr<const LlirOperand> targetList,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbcdrInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1,
								    essFlag, 
								    dst, 
								    flags, 
								    targetList,
								    probability)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createBcrInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<EssFlag> essFlag, 
				    shared_ptr<const LlirOperand> dst, 
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480BcrInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1,
								  essFlag, 
								  dst, 
								  flags)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createJbcrInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<EssFlag> essFlag, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags,
				     shared_ptr<const LlirOperand> targetList,
				     OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbcrInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1,
								   essFlag, 
								   dst, 
								   flags, 
								   targetList,
								   probability)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createBcdiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> src1, 
				     shared_ptr<EssFlag> essFlag, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480BcdiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1,
								   essFlag, 
								   dst, 
								   flags)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createJbcdiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> src1, 
				      shared_ptr<EssFlag> essFlag, 
				      shared_ptr<const LlirOperand> dst, 
				      shared_ptr<const LlirOperand> flags,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbcdiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1,
								    essFlag, 
								    dst, 
								    flags,
								    probability)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createBciInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const LlirOperand> src1, 
				    shared_ptr<EssFlag> essFlag, 
				    shared_ptr<const LlirOperand> dst, 
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480BciInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1,
								  essFlag, 
								  dst, 
								  flags)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createJbciInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> src1, 
				     shared_ptr<EssFlag> essFlag, 
				     shared_ptr<const LlirOperand> dst, 
				     shared_ptr<const LlirOperand> flags,
				     OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbciInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1,
								   essFlag, 
								   dst, 
								   flags,
								   probability)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createBnzrInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> src2,
				     shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M480BnzrInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   cmpReg)));
  }


  shared_ptr<OctaveInstruction> 
  M480Factory::createJbnzrInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const Register> src2,
				      shared_ptr<const LlirOperand> cmpReg,
				      shared_ptr<const LlirOperand> targetList,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbnzrInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    cmpReg, 
								    targetList,
								    probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createBzrInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<const Register> src2, 
				    shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M480BzrInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  cmpReg)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJbzrInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> src2, 
				     shared_ptr<const LlirOperand> cmpReg,
				     shared_ptr<const LlirOperand> targetList,
				     OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbzrInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   cmpReg, 
								   targetList,
								   probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createBnziInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const LlirOperand> src2, 
				     shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M480BnziInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   cmpReg)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJbnziInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const LlirOperand> src2, 
				      shared_ptr<const LlirOperand> cmpReg,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbnziInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    cmpReg,
								    probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createBziInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<const LlirOperand> src2, 
				    shared_ptr<const LlirOperand> cmpReg)
  {
    return (shared_ptr<OctaveInstruction> (new M480BziInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2, 
								  cmpReg)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJbziInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const LlirOperand> src2, 
				     shared_ptr<const LlirOperand> cmpReg,
				     OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbziInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   cmpReg,
								   probability)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createTsetbInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const UnsignedImmediate> bitpos, 
				      shared_ptr<const LlirOperand> disp)
  {
    return (shared_ptr<OctaveInstruction> (new M480TsetbInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    bitpos, 
								    disp)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJtsetbInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const UnsignedImmediate> bitpos, 
				       shared_ptr<const LlirOperand> disp,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JtsetbInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     bitpos, 
								     disp,
								     probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createTclrbInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const UnsignedImmediate> bitpos, 
				      shared_ptr<const LlirOperand> disp)
  {
    return (shared_ptr<OctaveInstruction> (new M480TclrbInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    bitpos, 
								    disp)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJtclrbInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> src1, 
				       shared_ptr<const UnsignedImmediate> bitpos, 
				       shared_ptr<const LlirOperand> disp,
				       OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JtclrbInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     src1, 
								     bitpos, 
								     disp,
								     probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRnmiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RnmiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   diFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJrnmiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480JrnmiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    diFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createRintInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480RintInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   diFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJrintInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> diFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480JrintInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    diFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createBrsInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480BrsInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  dst)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJbrsInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbrsInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   dst)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createBrslInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const LlirOperand> brslFlags)
  {
    return (shared_ptr<OctaveInstruction> (new M480BrslInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   brslFlags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJbrslInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const LlirOperand> brslFlags)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbrslInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    brslFlags)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createBrspreInstruction(unsigned int lineNum, 
				       unsigned int srcLineNum,
				       const char* srcFileName)
  {
    return (shared_ptr<OctaveInstruction> (new M480BrspreInstruction(lineNum, 
								     srcLineNum,
								     srcFileName)));
  }
				       
  shared_ptr<OctaveInstruction>
  M480Factory::createCmpInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1, 
				    shared_ptr<const Register> src2,
				    shared_ptr<const LlirOperand> abcFlag, 
				    shared_ptr<const LlirOperand> branchTarget)
  {
    return (shared_ptr<OctaveInstruction> (new M480CmpInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  src2,
								  abcFlag, 
								  branchTarget)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createCmpiInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const SignedImmediate> src2, 
				     shared_ptr<const LlirOperand> abcFlag, 
				     shared_ptr<const LlirOperand> branchTarget)
  {
    return (shared_ptr<OctaveInstruction> (new M480CmpiInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2,
								   abcFlag, 
								   branchTarget)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJcmpInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1, 
				     shared_ptr<const Register> src2,
				     shared_ptr<const LlirOperand> abcFlag, 
				     shared_ptr<const LlirOperand> branchTarget,
				     OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JcmpInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2,
								   abcFlag, 
								   branchTarget,
								   probability)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createJcmpiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1, 
				      shared_ptr<const SignedImmediate> src2, 
				      shared_ptr<const LlirOperand> abcFlag, 
				      shared_ptr<const LlirOperand> branchTarget,
				      OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JcmpiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2,
								    abcFlag, 
								    branchTarget,
								    probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createCmprInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> abcFlag,
				     shared_ptr<const LlirOperand> signFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480CmprInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1, 
								   src2, 
								   dst, 
								   abcFlag, 
								   signFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createCmpriInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const SignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<const LlirOperand> abcFlag,
				      shared_ptr<const LlirOperand> signFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480CmpriInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1, 
								    src2, 
								    dst, 
								    abcFlag, 
								    signFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createBiInstruction(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName, 
				   shared_ptr<const LlirOperand> src1,
				   shared_ptr<const LlirOperand> dst, 
				   shared_ptr<const LlirOperand> cdFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480BiInstruction(lineNum, 
								 srcLineNum,
								 srcFileName, 
								 src1, 
								 dst, 
								 cdFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createJbiInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const LlirOperand> src1,
				    shared_ptr<const LlirOperand> dst, 
				    shared_ptr<const LlirOperand> cdFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbiInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  dst, 
								  cdFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createBrInstruction(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName, 
				   shared_ptr<const Register> src1,
				   shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480BrInstruction(lineNum, 
								 srcLineNum,
								 srcFileName, 
								 src1, 
								 dst)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createJtablebrInstruction(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName, 
					 shared_ptr<const Register> src1,
					 shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480JtablebrInstruction(lineNum, 
								       srcLineNum,
								       srcFileName, 
								       src1, 
								       dst)));
  }
  
  shared_ptr<OctaveInstruction>
  M480Factory::createJtableRelativebrInstruction(unsigned int lineNum,
						 unsigned int srcLineNum,
						 const char* srcFileName, 
						 shared_ptr<const Register> src1,
						 shared_ptr<const LlirOperand> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480JtableRelativebrInstruction(lineNum, 
									       srcLineNum,
									       srcFileName, 
									       src1, 
									       dst)));
  }
  
  shared_ptr<OctaveInstruction>
  M480Factory::createJbrInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> src1,
				    shared_ptr<const LlirOperand> dst,
				    shared_ptr<const LlirOperand> targetList)
  {
    return (shared_ptr<OctaveInstruction> (new M480JbrInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  src1, 
								  dst, 
								  targetList)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDepbInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src, 
				     shared_ptr<const UnsignedImmediate> srcBitNum,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> dstBitNum, 
				     shared_ptr<const UnsignedImmediate> numBits, 
				     shared_ptr<const LlirOperand> depbFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480DepbInstruction(lineNum, 
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
  M480Factory::createExtbInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src, 
				     shared_ptr<const UnsignedImmediate> srcBitNum,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> dstBitNum, 
				     shared_ptr<const UnsignedImmediate> numBits, 
				     shared_ptr<const LlirOperand> signFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480ExtbInstruction(lineNum, 
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
  M480Factory::createDepbiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const UnsignedImmediate> src, 
				      shared_ptr<const Register> dst,
				      shared_ptr<const UnsignedImmediate> dstBitNum, 
				      shared_ptr<const UnsignedImmediate> numBits, 
				      shared_ptr<const LlirOperand> depbFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480DepbiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName,
								    src,
								    dst,
								    dstBitNum,
								    numBits, 
								    depbFlag)));
  }


  shared_ptr<OctaveInstruction> 
  M480Factory::createCmovInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const Register> src2, 
				     shared_ptr<const Register> dst, 
				     shared_ptr<EssFlag> essFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480CmovInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src1,
								   src2, 
								   dst,
								   essFlag)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createCmoviInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> src2, 
				      shared_ptr<const Register> dst, 
				      shared_ptr<EssFlag> essFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480CmoviInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src1,
								    src2, 
								    dst,
								    essFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDmapInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src1,
				     shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480DmapInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   convertSingleToDmaMultiReg(src1), 
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDmasrInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480DmasrInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToDmaMultiReg(src1), 
								    flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDmau0Instruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480Dmau0Instruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToDmaMultiReg(src1), 
								    flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createDmau1Instruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> src1,
				      shared_ptr<const UnsignedImmediate> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480Dmau1Instruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToDmaMultiReg(src1),
								    flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLihInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> dst,
				    shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M480LihInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  dst, 
								  src)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLilInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> dst,
				    shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M480LilInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  dst, 
								  src)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLwihInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M480LwihInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLwilInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M480LwilInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLaihInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M480LaihInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLailInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> dst,
				     shared_ptr<const LlirOperand> src)
  {
    return (shared_ptr<OctaveInstruction> (new M480LailInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   dst, 
								   src)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createNopInstruction(unsigned int lineNum, 
				    unsigned int srcLineNum,
				    const char* srcFileName)
  {
    return (shared_ptr<OctaveInstruction> (new M480NopInstruction(lineNum, 
								  srcLineNum,
								  srcFileName)));
  }
  
  shared_ptr<OctaveInstruction> 
  M480Factory::createHec5Instruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> bytes,
				     shared_ptr<const LlirOperand> cumeFlag, 
				     shared_ptr<const LlirOperand> branchTarget)
  {
    return (shared_ptr<OctaveInstruction> (new M480Hec5Instruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src, 
								   dst,
								   bytes, 
								   branchTarget,
								   cumeFlag)));
  }

  shared_ptr<OctaveInstruction> 
  M480Factory::createJHec5Instruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst,
				     shared_ptr<const UnsignedImmediate> bytes,
				     shared_ptr<const LlirOperand> cumeFlag, 
				     shared_ptr<const LlirOperand> branchTarget,
				     OctaveInstruction::BranchProbability probability)
  {
    return (shared_ptr<OctaveInstruction> (new M480JHec5Instruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    src, 
								    dst,
								    bytes, 
								    branchTarget,
								    cumeFlag,
								    probability)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMvInstruction(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName, 
				   shared_ptr<const Register> src,
				   shared_ptr<const Register> dst)
  {
    return (shared_ptr<OctaveInstruction> (new M480MvInstruction(lineNum, 
								 srcLineNum,
								 srcFileName, 
								 src, 
								 dst)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMvhrInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> mvhFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MvhrInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src, 
								   dst, 
								   mvhFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createMvrhInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> src,
				     shared_ptr<const Register> dst, 
				     shared_ptr<const LlirOperand> mvhFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480MvrhInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   src, 
								   dst, 
								   mvhFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createUnlinkInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs)
  {
    return (shared_ptr<OctaveInstruction> (new M480UnlinkInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs))));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLinkInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> regs,
				     shared_ptr<OctaveMemory> mem, 
				     shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinkInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   convertSingleToMultiReg(regs),
								   mem, 
								   linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLinksInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinksInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }
  
  shared_ptr<OctaveInstruction>
  M480Factory::createLinkspInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinkspInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem, 
								     linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLinksplInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const Register> regs,
					shared_ptr<OctaveMemory> mem, 
					shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinksplInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      convertSingleToMultiReg(regs),
								      mem, 
								      linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLinksrInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinksrInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem, 
								     linkFlag)));
  }
  
  shared_ptr<OctaveInstruction>
  M480Factory::createLinksdInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinksdInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem, 
								     linkFlag)));
  }
  
  shared_ptr<OctaveInstruction>
  M480Factory::createLinkccInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinkccInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem, 
								     linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLinkcclInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const Register> regs,
					shared_ptr<OctaveMemory> mem, 
					shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinkcclInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      convertSingleToMultiReg(regs),
								      mem, 
								      linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLinksioInstruction(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName, 
					shared_ptr<const Register> regs,
					shared_ptr<OctaveMemory> mem, 
					shared_ptr<const LinkFlag> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LinksioInstruction(lineNum, 
								      srcLineNum,
								      srcFileName, 
								      convertSingleToMultiReg(regs),
								      mem, 
								      linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem, 
				    shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem, 
								  linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmspInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmspInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmsplInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmsplInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem, 
								     linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmsrInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmsrInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmsdInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmsdInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmccInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmccInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmcclInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem, 
				       shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmcclInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem, 
								     linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmsiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem, 
				      shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmsiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem, 
								    linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createLmmsInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> regs,
				     shared_ptr<OctaveMemory> mem, 
				     shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LmmsInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   convertSingleToMultiReg(regs),
								   mem, 
								   linkFlag)));
  }


  shared_ptr<OctaveInstruction>
  M480Factory::createLspInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem, 
				    shared_ptr<const LlirOperand> linkFlag)
  {
    return (shared_ptr<OctaveInstruction> (new M480LspInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem, 
								  linkFlag)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmspInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmspInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmsplInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmsplInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmsrInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmsrInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmsdInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmsdInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmccInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmccInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmcclInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName, 
				       shared_ptr<const Register> regs,
				       shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmcclInstruction(lineNum, 
								     srcLineNum,
								     srcFileName, 
								     convertSingleToMultiReg(regs),
								     mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmsiInstruction(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName, 
				      shared_ptr<const Register> regs,
				      shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmsiInstruction(lineNum, 
								    srcLineNum,
								    srcFileName, 
								    convertSingleToMultiReg(regs),
								    mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSmmsInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> regs,
				     shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SmmsInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   convertSingleToMultiReg(regs),
								   mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createSspInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> regs,
				    shared_ptr<OctaveMemory> mem)
  {
    return (shared_ptr<OctaveInstruction> (new M480SspInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  convertSingleToMultiReg(regs),
								  mem)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPutInstruction(unsigned int lineNum,
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
  M480Factory::createGetInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> rsa,
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480GetInstruction(lineNum, 
								  srcLineNum,
								  srcFileName, 
								  rsa, 
								  flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPolInstruction(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName, 
				    shared_ptr<const Register> rsa,
				    shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum,
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPutcInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480PutcInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   rsa, 
								   rsb, 
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPutmInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480PutmInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   rsa, 
								   rsb, 
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPutpInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480PutpInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   rsa, 
								   rsb, 
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPutdInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const Register> rsa,
				     shared_ptr<const Register> rsb, 
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new M480PutdInstruction(lineNum, 
								   srcLineNum,
								   srcFileName, 
								   rsa, 
								   rsb, 
								   flags)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPutcInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const UnsignedImmediate> parOffset,
				     shared_ptr<const UnsignedImmediate> posOffset,
				     shared_ptr<const LlirOperand> pipeDepth,
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum,
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createGetcInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const UnsignedImmediate> parOffset,
				     shared_ptr<const UnsignedImmediate> posOffset,
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum,
									srcFileName)));
  }

  shared_ptr<OctaveInstruction>
  M480Factory::createPolcInstruction(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName, 
				     shared_ptr<const UnsignedImmediate> parOffset,
				     shared_ptr<const UnsignedImmediate> posOffset,
				     shared_ptr<const LlirOperand> flags)
  {
    return (shared_ptr<OctaveInstruction> (new InvalidOctaveInstruction(lineNum, 
									srcLineNum,
									srcFileName)));
  }

}
