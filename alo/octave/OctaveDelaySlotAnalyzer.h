#ifndef _ALO_Octave_DELAY_SLOTS_H
#define _ALO_Octave_DELAY_SLOTS_H

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

  class OctaveDelaySlotAnalyzer
    {

    public:

      OctaveDelaySlotAnalyzer(OctaveAlo &);

      ~OctaveDelaySlotAnalyzer();

      OctaveDelaySlotAnalyzer& operator=(const OctaveDelaySlotAnalyzer&rhs);

      OctaveDelaySlotAnalyzer(const OctaveDelaySlotAnalyzer& rhs);
      
      void checkDelaySlots(shared_ptr<LlirFile> file);
      void checkDelaySlots(shared_ptr<LlirOctaveBlock> block);


    private:

      void checkDelaySlots(shared_ptr<LlirOctaveBlock> blk, 
			    shared_ptr<LlirNode> node, 
			    unsigned int numSlots);

      void checkDelaySlots(shared_ptr<OctaveInstruction> insn, 
			   std::vector<shared_ptr<OctaveInstruction> > delayInsns);

      shared_ptr<OctaveInstruction> getNextInsn(shared_ptr<LlirOctaveBlock> blk, 
						shared_ptr<LlirNode> node);


      
      //Need a handle to log exception.
      OctaveAlo& m_alo;

      //Store the node whose delay slots are being checked
      shared_ptr<LlirNode> m_dslotNode;

      shared_ptr<LlirOctaveBlock> m_nextDslotBlock;
    };

}


#endif
