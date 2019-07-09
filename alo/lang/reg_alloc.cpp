/* C (and C++ in our case) #include's and declarations */

#include <stdio.h>
#include <stdlib.h>		/* free() in bison.simple */
#include <stdarg.h>		/* vfprintf() */
#include <limits.h>		/* PATH_MAX, UNIT_MAX */
#include <stack>
#include <iostream>
#include <sstream>

#include <Alo.h>
#include <AloException.h>
using namespace Alo;
#include <OctaveInstructions.h>
#include <OctaveNode.h>
using namespace Llir;

#include "yystypes.h"
#include "aloutil.h"
#include "conditionals.h"
#include "defmacro.h"



extern bool optimizing;
extern bool in_evh;
extern bool in_entry;
extern void d_printf(const char *fmt, ...);

//bridge functions.
unsigned int gcc_get_single_pseudo_reg(); 
int gcc_get_multi_hard_reg(unsigned int size, AbstractSymReg::SymRegConstraint);
void gcc_unget_multi_hard_reg(unsigned int, unsigned int);
extern void do_end_smap (shared_ptr<LlirOctaveBlock> block);

namespace Alo
{
  extern shared_ptr<AltEntryFunction> g_currentAltEntryFn;
}


void do_sregister(const char *sreg_name, 
		  AbstractSymReg::SymRegConstraint reg_constraint, 
		  shared_ptr<const Register> constraint_reg_range)
{
  if (!optimizing)
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError("cannot use .sreg without turning on optimization",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
      return;
    }
  if (! (in_evh || in_entry))
    {
      parseAlo->logException(shared_ptr<ParseError>(new ParseError(".sreg must appear within .evh or .entry block",
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));
    }

  else
    {
			
      /* 
	 - call CodeSourcery API function (in GCC) to create a pseudo register rtx in GCC.
	 - use that register number in llir  PseudoRegister creation 
         - associate it with the SymReg to be stored in the symbol table.
         - finally create the .sreg asm directive node.
      */


      if(reg_constraint == AbstractSymReg::SRC_NONE)
	{
	  /* 
	     do real register allocation 

	  */
	  shared_ptr<const PseudoRegister> pseudoReg;
      
	  unsigned int pseudoRegNum = gcc_get_single_pseudo_reg();

	  const char* pseudoRegName = sreg_name;

	  pseudoReg = llirFactory->createPseudoReg(pseudoRegNum, pseudoRegName);

	  //update the number of pseudo regs created per function
	  g_currentAltEntryFn->updateNumOfPseudoRegs(1);

	  AddOctaveSymbol(llirFactory->createSymReg(pseudoRegName, 
						    OctaveSymbol::LOCAL, 
						    pseudoReg,
						    reg_constraint,
						    constraint_reg_range));
			    
	  g_currentBlock->addLlirNode(g_currentBlock, 
				      llirFactory->createSregisterDirective(get_node_line(),
									    get_src_line(),
									    get_src_file(),
									    sreg_name, 
									    pseudoReg,
									    reg_constraint,
									    constraint_reg_range));
	}
      else
	{
	  /* 
	     grab a single 
	     constrained s/w register 
	     from the register pool 
	  */
	  shared_ptr<const HardRegister> hReg;

	  unsigned int regBlockSize = 1;

	  int regNum = gcc_get_multi_hard_reg(regBlockSize, reg_constraint);

	  const char* regName = sreg_name;
	      
	  if(regNum != -1)
	    {

	      hReg = llirFactory->createHardReg(regNum);
	      
	      AddOctaveSymbol(llirFactory->createSymReg(regName, 
							OctaveSymbol::LOCAL, 
							hReg,
							reg_constraint,
							constraint_reg_range));
	      
	      g_currentBlock->addLlirNode(g_currentBlock, 
					  llirFactory->createSregisterDirective(get_node_line(),
										get_src_line(),
										get_src_file(),
										sreg_name, 
										hReg,
										reg_constraint,
										constraint_reg_range));
	    }
	  else
	    {
	      ostringstream excStr;
	      excStr<< "unable to allocate register for .sreg " << string(regName) << " :";
	      throw AloFatalError(excStr.str().c_str(),
				  get_src_line(), 
				  get_src_file(), 
				  __LINE__, __FILE__);
	      return;	      
	    }
	}

    }
}


void do_scoped_mapping(TypeContainer *tc, 
		       const char *mapname, 
		       AbstractSymReg::SymRegConstraint reg_constriant, 
		       shared_ptr<const Register> constraint_reg_range)
{
  shared_ptr<const Struct> st;
  shared_ptr<MapSymbol> sym;
  shared_ptr<ScopedMapDirective> smd;
  shared_ptr<const PseudoRegister> pr;
  shared_ptr<const MultiHardRegister> mpr;


  if (!optimizing)
    {
      parseAlo->logException(shared_ptr<ParseError>
			     (new ParseError("cannot use .smap without turning on optimization",
					     get_src_line(), 
					     get_src_file(), 
					     __LINE__, __FILE__)));
      return;
    }
  if (! (in_evh || in_entry))
    {
      parseAlo->logException(shared_ptr<ParseError>
			     (new ParseError(".smap must appear within .evh or .entry block",
					     get_src_line(), 
					     get_src_file(), 
					     __LINE__, __FILE__)));
    }

  d_printf("scoped mapping type %s to instance %s\n", tc->ty->getName().c_str(), mapname);
  
  if (!(st = shared_dynamic_cast<const Struct>(tc->ty)))
    {
      string s = tc->name;

      s = s + " is not a structure, cannot smap to it";

      parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			     (new IllegalSymbolOperand(s.c_str(),
						       get_src_line(), 
						       get_src_file(), 
						       __LINE__, __FILE__)));
      return;
    }

  unsigned int size = st->getSize();

  unsigned int pseudoRegBlockSize = size/4;

  const char* pseudoRegName = mapname; 

  if(pseudoRegBlockSize == 1)
    {
      /*
	call code sourcery API to create a single
	pseudo register 
      */
      unsigned int pseudoRegNum = gcc_get_single_pseudo_reg();

      pr = llirFactory->createPseudoReg(pseudoRegNum, pseudoRegName);

      //update the number of pseudo regs created per function
      g_currentAltEntryFn->updateNumOfPseudoRegs(1);
	  
      sym = llirFactory->createMapToPseudoReg(mapname, OctaveSymbol::LOCAL, st, pr); 

      AddOctaveSymbol(sym);
      
      smd = llirFactory->createScopedMapDirective(get_node_line(), 
						  get_src_line(),
						  get_src_file(),
						  tc->name.c_str(), mapname, sym);
      
      g_currentBlock->addLlirNode(g_currentBlock, smd);
      
      return;
    }


  
  /* 
     The intent here should have been to call 
     CodeSourcey API function  to create 
     multi pseudo register block.
	 
     But, what we are creating here is not  a multi pseudo 
     register block, it is multi hard register block.

     Reason:

     We do not have support for allocating
     multi block of 'consecutive' pseudo 
     registers. 

     Even though the language construct '.smap' seems 
     to suggest that the ALO  will create as many registers 
     as the size of the struct and perform register
     allocation later to pick the optimal hard
     register block, this infact is not true in this
     implementation.
	 
     The API call just removes so many registers 
     from the available register pool, which is 
     very sub-optimal. Hopefully this restriction would
     go away later....
  */

  if(reg_constriant == AbstractSymReg::SRC_NONE)
    {
      /* 
	 if user did not specify any constraint first try
	 to get a register block starting at even register
	 as it will improve performance of generated code.
      */
	  
      int firstRegNum = gcc_get_multi_hard_reg(pseudoRegBlockSize, AbstractSymReg::SRC_BEGIN_AT_EVEN_REG);

      if (firstRegNum != -1)
	{
	  mpr = llirFactory->createMultiHardReg(pseudoRegBlockSize, firstRegNum);

	  sym = llirFactory->createMapToMultiHardReg(mapname, OctaveSymbol::LOCAL, st, mpr); 

	  g_currentBlock->addSmapRegister(mpr);

	  AddOctaveSymbol(sym);

	  smd = llirFactory->createScopedMapDirective(get_node_line(), 
						      get_src_line(),
						      get_src_file(),
						      tc->name.c_str(), mapname, sym);

	  g_currentBlock->addLlirNode(g_currentBlock, smd);
	      
	  return;
	      
	}
    }
      
  /* 
     the above special allocation seems to have failed...
     continue with normal allocation.
  */

  int firstRegNum = gcc_get_multi_hard_reg(pseudoRegBlockSize, reg_constriant);

  if (firstRegNum != -1)
    {
      mpr = llirFactory->createMultiHardReg(pseudoRegBlockSize, firstRegNum);

      sym = llirFactory->createMapToMultiHardReg(mapname, OctaveSymbol::LOCAL, st, mpr); 

      g_currentBlock->addSmapRegister(mpr);
	      
      AddOctaveSymbol(sym);

      smd = llirFactory->createScopedMapDirective(get_node_line(), 
						  get_src_line(),
						  get_src_file(),
						  tc->name.c_str(), 
						  mapname, 
						  sym);

      g_currentBlock->addLlirNode(g_currentBlock, smd);
	  
      return;
	      
    }


  /* 
     allocation completely failed...
     log an error...
  */

  ostringstream excStr;
  excStr<< "unable to allocate " << pseudoRegBlockSize << " registers for map name \'" << string(mapname) << "\'";
  throw AloFatalError(excStr.str().c_str(),
		      get_src_line(), 
		      get_src_file(), 
		      __LINE__, __FILE__);
  return;
}

void do_end_smap (shared_ptr<LlirOctaveBlock> block)
{
  LlirOctaveBlock::SmapRegistersConstIterator multiHardRegIt = block->smapRegistersBegin();
  shared_ptr<const MultiHardRegister> multiHardRegister;

  for (; multiHardRegIt != block->smapRegistersEnd(); multiHardRegIt++)
    {
      unsigned int firstRegnum;
      unsigned int lastRegnum;
      multiHardRegister = *multiHardRegIt;

      firstRegnum = multiHardRegister->getFirstRegNum();
      lastRegnum = multiHardRegister->getFirstRegNum() + (multiHardRegister->getNumRegs() - 1);
      gcc_unget_multi_hard_reg(firstRegnum, lastRegnum);
    }
}




namespace Alo
{
  //for each label in the list find out
  //a prototype exists in the g_prototypeDirList;

  shared_ptr<const PrototypeDirective>
  searchForValidPrototype(shared_ptr<const LabelList> labelList)
  {
  
    bool validDeclFound = false;
    const char* name;
  
    PrototypeListIter piter;
  
    LabelList::ConstIterator iter = labelList->begin();
  
    for(; iter != labelList->end(); iter++)
      {
	name = (*iter)->getName().c_str();
      
	piter = searchForValidPrototype(name);
	if(piter != g_prototypeDirList.end())
	  {
	    validDeclFound = true;
	    continue;
	  }
	else
	  {
	    unsigned int excLine = get_src_line();
	    const char* excFile = get_src_file();
	  
	    shared_ptr<std::exception> exc;

	    char *excStr = new char[128];

	    sprintf(excStr, "Error:%s:%d: prototype not found for : %s", excFile, excLine, name);

	    throw ALO_INTERNAL_EXCEPTION(excStr);

	    delete excStr;
	  }
      }

    if(validDeclFound)
      {
	return g_prototypeDirList[name];
      }

    //dummy return
    return llirFactory->createPrototypeDirective
      (get_node_line(),
       get_src_line(),
       get_src_file(),
       shared_ptr<LabelList>                (new LabelList               ()), 
       shared_ptr<ArgList>                  (new ArgList                 (shared_ptr<RegList>(new RegList()))),
       shared_ptr<ResultList>               (new ResultList              (shared_ptr<RegList>(new RegList()))),
       shared_ptr<ScratchList>              (new ScratchList             (shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToSPRAM>       (new RegLnksListToSPRAM      (shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToLockedSPRAM> (new RegLnksListToLockedSPRAM(shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToSRAM>        (new RegLnksListToSRAM       (shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToSDRAM>       (new RegLnksListToSDRAM      (shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToCCRAM>       (new RegLnksListToCCRAM      (shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToLockedCCRAM> (new RegLnksListToLockedCCRAM(shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))),
       shared_ptr<RegLnksListToSIO>         (new RegLnksListToSIO        (shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()), 
									  shared_ptr<RegList>(new RegList()))));
    
  }


  PrototypeListIter
  searchForValidPrototype(const char* name)
  {
    return g_prototypeDirList.find(name);
  }

  bool 
  hasValidPrototype(const char* name)
  {
    if(g_prototypeDirList.find(name) != g_prototypeDirList.end())
      {
	return true;
      }
    else
      {
	return false;
      }
  }


  /* prototype directive handling */
  void
  addPrototypeToList(shared_ptr<PrototypeDirective> protoDir)
  {
    shared_ptr<const LabelList> labelList =
      protoDir->getEntryPtList();

    LabelList::ConstIterator iter = labelList->begin();

    //it is possible that pre-processed file
    //there can be multiple instances of a
    //prototype for the same label.

    //make sure g_prototypeDirList contains unique list of
    //such prototype directies.

    for(; iter != labelList->end(); iter++)
      {
	const string name = (*iter)->getName();

	PrototypeListIter piter = searchForValidPrototype(name.c_str());

	if(piter == g_prototypeDirList.end())
	  {
	    //if the list has no entry with that
	    //name add it to the list
	    g_prototypeDirList[name] = protoDir;
	  }
	else
	  {
	    // there exists a prototype with the same name
	    // in the list. make sure those two match
	    if(*protoDir != *(piter->second))
	      {
		unsigned int excLine = get_src_line();
		const char* excFile = get_src_file();

		shared_ptr<std::exception> exc;

		char *excStr = new char[128];

		sprintf(excStr, "Error:%s:%d: prototype mismatch", excFile, excLine);

		throw ALO_INTERNAL_EXCEPTION(excStr);

		delete excStr;
	      }
	  }
      }
  }


} // namespace Alo
