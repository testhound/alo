#ifndef _ALOUTIL_H_
#define _ALOUTIL_H_


#include <OctaveAlo.h>

#include "yystypes.h"

using namespace Llir;
extern std::map<string, shared_ptr<const PrototypeDirective> > g_prototypeDirList;
typedef std::map<string, shared_ptr<const PrototypeDirective> >::iterator PrototypeListIter;

namespace Alo
{
  void strip_string(char *s);

  /* Support for garbage-collecting YystypeContainer's. */
  void aloutil_store(YystypeContainer *p);
  void aloutil_cleanup();
  #define NEW(_type,_instance) _type *_instance = new _type(); aloutil_store(_instance);



  /* line control specific */
  void handle_line_control_directive(unsigned int linenum, const char *filename, unsigned int flag);
  int get_node_line();
  int get_src_line();
  const char *get_src_file();



  //////////////////////////////
  //globals
  //////////////////////////////
  
  extern  shared_ptr<LlirOctaveBlock> g_rootBlock;
  extern  shared_ptr<LlirOctaveBlock> g_currentBlock;
  extern  shared_ptr<AllocMemoryDirective> g_currentByteDirective;
  extern  shared_ptr<AllocMemoryDirective> g_currentWordDirective;
  extern  shared_ptr<AllocMemoryDirective> g_currentHalfWordDirective;
  extern  shared_ptr<OctaveFactory> llirFactory;
  extern  OctaveAlo *parseAlo;
  
  
  
  
  void fixLabelOperands();

  //symbol table support
  bool AddOctaveSymbol(shared_ptr<OctaveSymbol> newSym);
  void UnMapSymbol(const char* name);
  shared_ptr<OctaveSymbol> lookupOctaveSymbol(const char* name);
  shared_ptr<OctaveSymbol> lookupOctaveSymbol(shared_ptr<LlirOctaveBlock> block, const char* name);
  shared_ptr<const Register> lookupRegisterSymbol(const char *name);
  shared_ptr<const Register> lookupMapNameOrSymReg(const char* refPath);
  shared_ptr<const Register> lookupMapReferencePath(const char* refPath);
  shared_ptr<const Type> lookupType(const char* refPath);      //end pt should be found
  shared_ptr<const Type> lookupTypePath(const char* refPath);  //end pt should be struct

  unsigned int getSize(const char* refPath);
  unsigned int getNumBits(const char* refPath);
  unsigned int getBitPos(const char* refPath);
  unsigned int getMsbOf(const char* refPath);
  unsigned int getLsbOf(const char* refPath);
  unsigned int getOffset(const char* refPath);
  unsigned int getRelativeOffset(const char* path, const char* subPath);
  shared_ptr<const Register> getBaseOf(const char* refPath);
 
  bool compareStruct(const char* testedPath, const char* refPath);
  bool isSubset(shared_ptr<const Struct> testedPath, shared_ptr<const Struct> refPath);
 
  
    // helper fns for sym table methods
  void fixupLabels(shared_ptr<LlirOctaveBlock> block);
  void fixLabelOperands(shared_ptr<LlirOctaveBlock> block);
  string getTokenStr(string str);
  string extractSubString(string str);
  bool isPseudoRegister(shared_ptr<const Register> reg);
  shared_ptr<const Type> lookupPathEndPoint(const char* refPath);
  shared_ptr<const Register> createRegister(unsigned int firstRegNum, 
					    unsigned int numRegs, 
					    bool isPseudo, 
					    const char* name);
  

  void addPrototypeToList(shared_ptr<PrototypeDirective> protoDir);
  shared_ptr<const PrototypeDirective> searchForValidPrototype(shared_ptr<const LabelList> labelList);
  PrototypeListIter searchForValidPrototype(const char* name);
  bool hasValidPrototype(const char* name);


}
#endif










