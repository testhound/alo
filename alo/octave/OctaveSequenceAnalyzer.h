#ifndef _ALO_OCTAVE_SEQUENCE_ANALYZER_H
#define _ALO_OCTAVE_SEQUENCE_ANALYZER_H

#include <vector>
#include <iostream>
using namespace std;

#include <LlirFile.h>
#include <OctaveNode.h>

#include <AloException.h>
#include <LlirException.h>

#include <OctaveInstructions.h>

#include <Alo.h>
#include "OctaveAlo.h"


using namespace Llir;
using namespace Alo;


namespace Alo
{

  class OctaveAlo;

  class OctaveSequenceAnalyzer
    {

    public:

      OctaveSequenceAnalyzer(OctaveAlo &o) ;

      ~OctaveSequenceAnalyzer();

      OctaveSequenceAnalyzer& operator=(const OctaveSequenceAnalyzer&rhs);

      OctaveSequenceAnalyzer(const OctaveSequenceAnalyzer& rhs);
      
      void makeSequences(shared_ptr<LlirFile> file);

      void makeSequences(shared_ptr<LlirOctaveBlock> block);


    private:

      void makeSequences(shared_ptr<LlirOctaveBlock> blk, 
			 shared_ptr<LlirNode> node, 
			 unsigned int numSlots);

      void updateLlirNodeList(shared_ptr<OctaveInstruction> insn, 
			      std::vector<shared_ptr<OctaveInstruction> > sequenceInsns);

      shared_ptr<OctaveInstruction> getNextInsn(shared_ptr<LlirOctaveBlock> blk, 
						shared_ptr<LlirNode> node);


      
      //Need a handle to log exception.
      OctaveAlo& m_alo;

      //To store linenum of node under consideration
      //and whose sequence slots are being checked.
      shared_ptr<LlirNode> m_seqNode;

      shared_ptr<LlirOctaveBlock> m_nextSequenceBlock;
    };

}


#endif
