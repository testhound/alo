/*
 * This is stuff that might be usable from either the lexer or parser,
 * but isn't lex or parse specifc.
 */

#include <stdio.h>
#include <stdlib.h>		/* free() in bison.simple */
#include <stdarg.h>		/* vfprintf() */
#include <limits.h>		/* PATH_MAX, UNIT_MAX */

#include <ctype.h>
#include <stack>
using namespace std;

#include <Alo.h>
#include <OctaveFactory.h>
using namespace Llir;

#include "aloutil.h"
#include "yystypes.h"
using namespace Alo;

extern int alo_lineno;
extern const char *alo_text;


namespace Alo
{



  /* Remove whitespace from a string, overwriting it in place. */
  void strip_string(char *s)
  {
    char *p = s;
    while (*s)
      {
	if (!isspace(*s))
	  {
	    *p = *s;
	    p++;
	  }
	s++;
      }
    *p = '\0';
  }

   
  /* Store and garbage collect YystypeContainer objects. */
  static stack<YystypeContainer *> garbage_bin[2];
  static int garbage_index = 0;

  void aloutil_store(YystypeContainer *p)
  {
    garbage_bin[garbage_index].push(p);
  }


  void aloutil_cleanup()
  {
    int clean_index = (garbage_index + 1) % 2;
    while (!garbage_bin[clean_index].empty())
      {
	delete garbage_bin[clean_index].top();
	garbage_bin[clean_index].pop();
      }
    garbage_index = (garbage_index + 1) % 2;
  }



  /*
   * Management of include files and line numbers at parse time is
   * managed here.  
   */


  class FileStackEntry {
  public:
    FileStackEntry(char *fname);
    const char *getFile();
    int getLine();
    void setLinediff(int newValue);
    ~FileStackEntry();
  private:
    string filename;
    int yylineno_diff;
  };


  FileStackEntry::FileStackEntry(char *fname)
  {
    filename = fname;
  }

  const char *FileStackEntry::getFile()
  {
    return filename.c_str();
  }

  int FileStackEntry::getLine()
  {
    int fixup = 0;
    if (!strcmp(alo_text, "\n"))
      {
	/* If just read newline, adjust to accurately report previous line. */
	fixup = -1;
      }
    return alo_lineno - yylineno_diff + fixup;
  }


  void FileStackEntry::setLinediff(int newValue)
  {
    yylineno_diff = newValue;
  }


  FileStackEntry::~FileStackEntry()
  {
  }


  stack<FileStackEntry> line_control_stack;
  static int last_lcd_dot_i_linenum;
  static int last_lcd_line_controlnum;
  static char last_filename[PATH_MAX];

  void handle_line_control_directive(unsigned int line_controlnum, const char *filename, unsigned int flag)
  {
    strcpy(last_filename, filename);
    last_lcd_dot_i_linenum = alo_lineno - 1;
    last_lcd_line_controlnum = line_controlnum;
  }

  /*
    This function returns the position of LLIR node in the
    include file. This unique line number is very important
    and enables us to reproduce the .i file back after LLIR
    processing, for the back end assembler to operate on.
  */

  int get_node_line()
  {
    int fixup = 0;
    if (!strcmp(alo_text, "\n"))
      {
	/* If just read newline, adjust to accurately report previous line. */
	fixup = -1;
      }
    return alo_lineno + fixup;
  }

  /*
    Each line in the include has a source file (.s/.h) origin
    This function returns the source file line number of the
    corresponding node
  */

  int get_src_line()
  {
    return get_node_line() - last_lcd_dot_i_linenum - 1 + last_lcd_line_controlnum;
  }

  /*
    Return the source file to which the current LLIR node
    originated from.
   */

  const char *get_src_file()
  {
    return last_filename;
  }



  //////////////////////////////////////////////
  // parser specific Symbol table functions.
  //////////////////////////////////////////////

  //OctaveAlo methods

  //------------------
  //AddSymbol Function
  //------------------

  bool 
  AddOctaveSymbol(shared_ptr<OctaveSymbol> newSym)
  {
 
    const char *name = (newSym->getName()).c_str();

    OctaveSymbol::ScopeQualifier scope= newSym->getScopeQualifier();
  
    SymbolTable<OctaveSymbol>::Iterator symIter;

    switch(scope)
      {

      case OctaveSymbol::LOCAL:
	{
	  symIter = g_currentBlock->lookupSymbol(name);

	  if(symIter != g_currentBlock->symTableEnd())
	    {
	      string s = string("symbol '") + name + string("' already exists");
	      parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				     (new IllegalSymbolOperand(s.c_str(),
							       get_src_line(), 
							       get_src_file(), 
							       __LINE__, __FILE__)));
	    
	      return false;
	    }
	  else
	    {
	      symIter = g_rootBlock->lookupSymbol(name);

	      if(symIter != g_rootBlock->symTableEnd())
		{

		  OctaveSymbol::ScopeQualifier scope = symIter->second->getScopeQualifier();
		
		  if(scope == OctaveSymbol::GLOBAL || scope == OctaveSymbol::FILESCOPE)
		    {
		      string s = string("symbol '") + name + string("' already exists ");
		      parseAlo->logException(shared_ptr<IllegalSymbolOperand>
					     (new IllegalSymbolOperand(s.c_str(),
								       get_src_line(), 
								       get_src_file(), 
								       __LINE__, __FILE__)));
	      
		      return false;
		    }
		}
	      else
		{
		  g_currentBlock->addSymbol(newSym);

		  return true;
		}
	    }
	  break;
	}
      case OctaveSymbol::GLOBAL:
      case OctaveSymbol::FILESCOPE:
	{
	  symIter = g_currentBlock->lookupSymbol(name);
	  
	  if(symIter != g_currentBlock->symTableEnd())
	    {
	      string s = string("symbol '") + name + string("' already exists ");
	      parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				     (new IllegalSymbolOperand(s.c_str(),
							       get_src_line(), 
							       get_src_file(), 
							       __LINE__, __FILE__)));
	      
	      return false;
	    }
	  else
	    {
	      symIter = g_rootBlock->lookupSymbol(name);
	    
	      if(symIter != g_rootBlock->symTableEnd())
		{
		  string s = string("symbol '") + name + string("' already exists ");
		  parseAlo->logException(shared_ptr<IllegalSymbolOperand>
					 (new IllegalSymbolOperand(s.c_str(),
								   get_src_line(), 
								   get_src_file(), 
								   __LINE__, __FILE__)));

		  return false;
		}
	      else
		{
		  g_rootBlock->addSymbol(newSym);
		  return true;
		}
	    }
	  break;
	}
      default:
	{
	  throw LLIR_INTERNAL_EXCEPTION("unknown Symbol::ScopeQualifier");
	  return false;
	}
      }

    return false;
  }

  //-----------------------------
  // Lookup Label Symbol Function
  //-----------------------------

  shared_ptr<OctaveSymbol> 
  lookupOctaveSymbol(const char *name)
  {
    return lookupOctaveSymbol(g_currentBlock, name);
  }


  shared_ptr<OctaveSymbol> 
  lookupOctaveSymbol(shared_ptr<LlirOctaveBlock> block, 
		     const char* name)
  {
  
    shared_ptr<LlirOctaveBlock> blk = block;

    SymbolTable<OctaveSymbol>::Iterator symIter = blk->lookupSymbol(name);
    
    if(symIter == blk->symTableEnd())
      {
	//symbol not found in the current block
	//so search the parent blocks.

	LlirOctaveBlock::ParentListIterator pIter = blk->getParent();

	while(pIter != blk->parentListEnd())  
	  {

	    blk = pIter->second;

	    symIter = blk->lookupSymbol(name);

	    if(symIter != blk->symTableEnd())
	      {
		//symbol found
		break;
	      }
	    else
	      {
		pIter = blk->getParent();
	      }
	  }

      }

    if(symIter != blk->symTableEnd())
      {
	return symIter->second;
      }
    else
      {
	//Note: It is the responsibility of caller to
	//log error message in case symbol is not found.

	return llirFactory->createNullSymbol();
	
      }
  }

  

  //------------------------
  // Lookup Register Symbol
  //------------------------

  /*
   * Guys, 
   *
   *  A register symbol can be a MapSymbol, 
   *  or a Symbolic Register. 
   *  
   *  map symbols always get into g_rootBlock.
   *
   *  The way lookupOctaveSymbol
   *  works is it starts with g_currentBlock and
   *  walks all the way up to g_rootBlock and looks for
   *  register symbols.
   *
   *  The side effect of this kind of insertion and 
   *  lookup is a symbolic register in an inner block
   *  with same name as that of map name in the root blcok
   *  always hides the map name.
   */

  shared_ptr<const Register> 
  lookupRegisterSymbol(const char *name)
  {
    shared_ptr<OctaveSymbol> octSym = lookupOctaveSymbol(g_currentBlock, name);

    shared_ptr<RegSymbol> regSym = shared_dynamic_cast<RegSymbol>(octSym);

    if(regSym)
      {
	return regSym->getRegister();
      }
    else
      {
	string s = string("symbol '") + name + string("' is not a map symbol or symbolic register");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	  
	return llirFactory->createNullReg();
      }
  }




  //------------------
  // LookupType
  //------------------
  /**
   * Input:       
   * ------
   *
   *    refPath = mapIdent/TypeIdent
   *    refPath = MapIdent/TypeIdent '.' StructPath
   *
   * Assumptions:
   * ------------
   * The following is assumed in this function
   *
   * End point of the path should be found
   *
   * Output:
   * -------
   *
   *
   * if any token in the path is not found the
   * the lookup fails and returns a null type
   *
   * this function is intended to be used
   * for looking for a type (which can be
   * struct, field, bitfield)
   *
   */


  shared_ptr<const Type> 
  lookupType(const char* refPath)
  {

    shared_ptr<const Struct> stType;

    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path);


    //lookup symbol
    shared_ptr<OctaveSymbol> octSym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(octSym))
      {
	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return llirFactory->createNullType();
      }


    stType = shared_dynamic_cast<const Struct>(octSym);

    if(stType == 0)
      {
	shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(octSym);

	if(mapSym)
	  {
	    stType = mapSym->getMappedStruct();
	  }
	else
	  {
	    string s = string("'") + token + string("' is not a structure type or a map name");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	    return llirFactory->createNullType();
	  }
      }

    //lookup the rest of the path in
    //the found structure.

    shared_ptr<const Type> type = stType;

    while(path.empty() == false)
      {

	token = getTokenStr(path);
	path = extractSubString(path);
  
	// lookup struct element
	Type::ConstIterator iter = stType->lookupType(token.c_str());

	if(iter != stType->end())
	  {
	    // token found

	    type = *iter;

	    shared_ptr<const Struct> elem = shared_dynamic_cast<const Struct>(type);
	  
	    if(elem)
	      {
		//token is a struct

		stType = elem;
	      }
	    else
	      {
		//token is not a struct
		//hence should be last token
	      
		if(path.empty() == false)
		  {
		    string s = string("'") + token + string("' is not a struct type");
		    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
					   (new IllegalSymbolOperand(s.c_str(),
								     get_src_line(), 
								     get_src_file(), 
								     __LINE__, __FILE__)));
		    return llirFactory->createNullType();
		  }
	      }
	  }
	else
	  {
	    string s =  string("'") + token + string("' is not an elment of  ") + stType->getName();
	    return llirFactory->createNullType();
	  }
      }

    return type;

  }




  //------------------
  // LookupType Path 
  //------------------
  /**
   * Input:       
   * ------
   *
   *    refPath = mapIdent/TypeIdent
   *    refPath = MapIdent/TypeIdent '.' StructPath
   *
   * Assumptions:
   * ------------
   * The following is assumed in this function
   *
   * End point of the path should always be a structure.
   *
   * Output:
   * -------
   *
   * if the end point is a struct it is returned
   * or a null type is returned,
   *
   * this function is intended to be used as the
   * when looking up the first argument of the
   * .map directive.
   *
   */


  shared_ptr<const Type> 
  lookupTypePath(const char* refPath)
  {

    shared_ptr<const Struct> stType;

    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path);


    //lookup symbol
    shared_ptr<OctaveSymbol> octSym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(octSym))
      {
	string s = string("symbol '") + token + string("' not found");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return llirFactory->createNullType();
      }

    stType = shared_dynamic_cast<const Struct>(octSym);

    if(stType == 0)
      {
	shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(octSym);

	if(mapSym)
	  {
	    stType = mapSym->getMappedStruct();
	  }
	else
	  {
	    string s = string("'") + token + string("' is not a structure type or a map name");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	    return llirFactory->createNullType();
	  }
      }

    //lookup the rest of the path in
    //the found structure.

    while(path.empty() == false)
      {

	token = getTokenStr(path);
	path = extractSubString(path);
  
	// lookup struct element
	Type::ConstIterator iter = stType->lookupType(token.c_str());

	if(iter != stType->end())
	  {
	    // token found

	    shared_ptr<const Struct> elem = shared_dynamic_cast<const Struct>(*iter);
	  
	    if(elem)
	      {
		//token is a struct

		stType = elem;
	      }
	    else
	      {
		string s = string("'") + token + string("' in struct '") + stType->getName() + string("' is not a struct type");
		parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				       (new IllegalSymbolOperand(s.c_str(),
								 get_src_line(), 
								 get_src_file(), 
								 __LINE__, __FILE__)));
	  
		return llirFactory->createNullType();
	      }
	  }
	else
	  {
	    string s =  string("'") + token + string("' is not an elment of  ") + stType->getName();
	    return llirFactory->createNullType();
	  }
      }

    return stType;

  }







  shared_ptr<const Register> 
  lookupMapNameOrSymReg(const char* refPath)
  {
    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path);

    //lookup symbol
    shared_ptr<OctaveSymbol> octSym  = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(octSym))
      {
	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
      	return llirFactory->createNullReg();
      }
    
    shared_ptr<AbstractSymReg> symReg = shared_dynamic_cast<AbstractSymReg>(octSym);

    if(symReg)
      {
	return symReg->getRegister();
      }
    else
      {
	return lookupMapReferencePath(refPath);
      }
  }




  //-----------------------------
  // Lookup Map Reference Path
  //-----------------------------

  /**
   * Input:       
   * ------
   *
   *    refPath = MapIdent '.' StructPath
   *
   * Output:
   * -------
   * if sizeof(refPath) is one
   *   returns a SingleRegister
   * else
   *   returns a MultiRegister[size]
   *
   * The returned register kind will be Pseudo or Hard
   * depending on the MapToRegister kind.
   *
   * The firstRegNum of the returned register depends 
   * on the offset of the 'refPath' from the beginning of 
   * MappedStruct
   * 
   */

  shared_ptr<const Register> 
  lookupMapReferencePath(const char* refPath)
  {
    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path); // unused!

    // Look up symbol, this must work for both local (.smap) and global (.map)
    // mappings.
    shared_ptr<OctaveSymbol> sym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(sym))
      {	
	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));


      	return llirFactory->createNullReg();
      }

    shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(sym);

    if(mapSym)
      {
	// MapName found 

	unsigned int firstRegNum = mapSym->getRegister()->getRegNum();

	bool isPseudoReg = isPseudoRegister(mapSym->getRegister());

	string name = "";

	if(isPseudoReg)
	  {
	    name = mapSym->getRegister()->getRegName();
	  }
  
	// FIXME:
	// If refPath is invalid both getOffset() 
	// and getSize() log the same error message how do we 
	// effectively solve this problem.

	firstRegNum += (getOffset(refPath) / 4);

	unsigned int numRegs = (getSize(refPath) / 4);

	
	return createRegister(firstRegNum, numRegs, isPseudoReg, name.c_str());

      }
    else
      {

	string s = string("'") + token + string("' is not a map symbol");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));

	return llirFactory->createNullReg();
      }
  }



  //helpers for lookup 'path'  function

  string 
  getTokenStr(string str)
  {
    return str.substr(0, str.find('.') );
  }

  string 
  extractSubString(string str)
  {
    string::size_type begIdx = str.find('.');

    if(begIdx != string::npos)
      {
	return str.substr(begIdx+1);
      }
    else
      {
	return "";
      }
  }


  bool 
  isPseudoRegister(shared_ptr<const Register> reg)
  {
    shared_ptr<const PseudoRegister> pReg = shared_dynamic_cast<const PseudoRegister>(reg);

    if(pReg)
      {
	return true;
      }
    else
      {
	shared_ptr<const MultiPseudoRegister> mpReg = shared_dynamic_cast<const MultiPseudoRegister>(reg);
	
	if(mpReg)
	  {
	    return true;
	  }
	else
	  {
	    return false;
	  }
      }
  }

  shared_ptr<const Register> 
  createRegister(unsigned int firstRegNum, 
		 unsigned int numRegs, 
		 bool isPseudo, 
		 const char* name)
  {
    if(numRegs == 1)
      {
	if(isPseudo)
	  {
	    return llirFactory->createPseudoReg(firstRegNum, name);
	  }
	else
	  {
	    return llirFactory->createHardReg(firstRegNum);
	  }
      }
    else if(numRegs >= 1)
      {
	if(isPseudo)
	  {
	    return llirFactory->createMultiPseudoReg(numRegs, firstRegNum, name);
	  }
	else
	  {
	    return llirFactory->createMultiHardReg(numRegs, firstRegNum);
	  }
      }
    else
      {
	//need not throw already message logged....
	//throw LLIR_INTERNAL_EXCEPTION("invalid number of registers"); 

	return llirFactory->createNullReg();
      }
  }


  

  //--------------------
  // Size of
  //--------------------

  unsigned int 
  getSize(const char* refPath)
  {
    shared_ptr<const Struct> stType;

    static const int errorReturnValue = 4;

    string path = refPath;
    string token = getTokenStr(path);
    path = extractSubString(path);

    // Look up symbol, this must work for both local (.smap) and global (.map)
    // mappings.
    shared_ptr<OctaveSymbol> sym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(sym))
      {	

	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));

	return errorReturnValue;
      }

    shared_ptr<const AbstractSymReg> symReg = shared_dynamic_cast<const AbstractSymReg>(sym);

    if(symReg)
      {
	return symReg->getRegister()->getNumRegs() * 4;
      }


    stType = shared_dynamic_cast<const Struct>(sym);

    if(stType == 0)
      {
	shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(sym);

	if(mapSym)
	  {
	    stType = mapSym->getMappedStruct();
	  }
	else
	  {
	    string s = string("'") + token + string("' is not a struct type or a map name");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  
	    return errorReturnValue;
	  }
      }

    //lookup the rest of the path in
    //the structure stType

    unsigned int size = stType->getSize();


    while(path.empty() == false)
      {

	token = getTokenStr(path);
	path = extractSubString(path);
  
	// lookup struct element

	Type::ConstIterator iter = stType->lookupType(token.c_str());

	if(iter != stType->end())
	  {
	    // token found

	    size = (*iter)->getSize();

	    shared_ptr<const Struct> elem = shared_dynamic_cast<const Struct>(*iter);
	  
	    if(elem)
	      {
		//token is a struct

		stType = elem;
	      }
	    else
	      {
		//token is not a struct
		//hence should be last token
	      
		if(path.empty() == false)
		  {
		    string s = string("'") + token + string("' is not a struct type");
		    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
					   (new IllegalSymbolOperand(s.c_str(),
								     get_src_line(), 
								     get_src_file(), 
								     __LINE__, __FILE__)));
		    return errorReturnValue;
		  }
	      }
	  }
	else
	  {
	    string s = string("'") + token + string("' not found in struct ")  + stType->getName();
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	    return errorReturnValue;
	  }
      }

    return size;

  }


  //------------------
  // Offsetof 
  //------------------

  unsigned int 
  getOffset(const char* refPath)
  {

    shared_ptr<const Struct> stType;

    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path);

    // Look up symbol, this must work for both local (.smap) and global (.map)
    // mappings.
    shared_ptr<OctaveSymbol> sym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(sym))
      {
	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return 0;
      }

    stType = shared_dynamic_cast<const Struct>(sym);

    if(stType == 0)
      {
	//lookup in Symbol table

	shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(sym);

	if(mapSym)
	  {
	    stType = mapSym->getMappedStruct();
	  }
	else
	  {

	    string s = string("'") + token + string("' is not a struct type or a map name");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  
	    return 0;
	  }
      }

    //lookup the rest of the path in
    //the found structure.

    unsigned int offset = 0;

    while(path.empty() == false)
      {

	token = getTokenStr(path);
	path = extractSubString(path);
  
	// lookup struct element
	Type::ConstIterator iter = stType->lookupType(token.c_str());

	if(iter != stType->end())
	  {
	    // token found

	    offset += (*iter)->getOffset();

	    shared_ptr<const Struct> elem = shared_dynamic_cast<const Struct>(*iter);
	  
	    if(elem)
	      {
		//token is a struct

		stType = elem;
	      }
	    else
	      {
		//token is not a struct
		//hence should be last token
	      
		if(path.empty() == false)
		  {
		    string s = string("'") + token + string("' is not a struct type");
		    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
					   (new IllegalSymbolOperand(s.c_str(),
								     get_src_line(), 
								     get_src_file(), 
								     __LINE__, __FILE__)));
		    
		    return 0;
		  }
	      }
	  }
	else
	  {
	    string s = string("'") + token + string("' not found in struct '") + stType->getName() + string("'");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  

	    return 0;
	  }
      }

    return offset;

  }



  //lookup path end point
  shared_ptr<const Type> 
  lookupPathEndPoint(const char* refPath)
  {

    shared_ptr<const Struct> stType;

    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path);

    // Look up symbol, this must work for both local (.smap) and global (.map)
    // mappings.
    shared_ptr<OctaveSymbol> sym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(sym))
      {

	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));

	return llirFactory->createNullType();
      }

    stType = shared_dynamic_cast<const Struct>(sym);

    if(stType == 0)
      {
	shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(sym);

	if(mapSym)
	  {
	    stType = mapSym->getMappedStruct();
	  }
	else
	  {
	    string s = string("'") + token + string("' is not a struct type or a map name");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  
	    return llirFactory->createNullType();
	  }
      }

    //lookup the rest of the path in
    //the found structure.
    shared_ptr<const Type> type = stType;

    while(path.empty() == false)
      {

	token = getTokenStr(path);
	path = extractSubString(path);
  
	// lookup struct element
	Type::ConstIterator iter = stType->lookupType(token.c_str());

	if(iter != stType->end())
	  {
	    // token found
	    type = *iter;

	    shared_ptr<const Struct> elem = shared_dynamic_cast<const Struct>(type);

	    if(elem)
	      {
		stType = elem;
	      }
	    else
	      {
		//token is not a struct
		//hence should be last token
	      
		if(path.empty() == false)
		  {
		    string s = string("'") + token + string("' is not a struct type");
		    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
					   (new IllegalSymbolOperand(s.c_str(),
								     get_src_line(), 
								     get_src_file(), 
								     __LINE__, __FILE__)));
	  
		    return llirFactory->createNullType();
		  }
	      }

	  }
	else
	  {
	    string s = string("'") + token + string("' is not an elment of  ") + stType->getName();
	    
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  
	    return llirFactory->createNullType();
	  }
      }

    return type;

  }


  //---------------
  // lsbof(operand)
  //---------------

  unsigned int 
  getLsbOf(const char* refPath)
  {
    shared_ptr<const Type> type = lookupPathEndPoint(refPath);

    shared_ptr<const BitField> bfldTp = shared_dynamic_cast<const BitField>(type);

    if(bfldTp)
      {
	return bfldTp->getLSBitPosition();
      }
    else
      {
	string s = string("'") + string(refPath) + string("' is not a bit field");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return 0;
      }
  }


  //---------------
  // msbof(operand)
  //---------------

  unsigned int 
  getMsbOf(const char* refPath)
  {
    shared_ptr<const Type> type = lookupPathEndPoint(refPath);

    shared_ptr<const BitField> bfldTp = shared_dynamic_cast<const BitField>(type);

    if(bfldTp)
      {
	return bfldTp->getMSBitPosition();
      }
    else
      {
	string s = string("'") + string(refPath) + string("' is not a bit field");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return 0;
      }
  }



  //---------------
  // bitpos(operand)
  //---------------

  unsigned int 
  getBitPos(const char* refPath)
  {
    shared_ptr<const Type> type = lookupPathEndPoint(refPath);

    shared_ptr<const BitField> bfldTp = shared_dynamic_cast<const BitField>(type);

    if(bfldTp)
      {
	if(bfldTp->getMSBitPosition() == bfldTp->getLSBitPosition())
	  {
	    return bfldTp->getMSBitPosition();
	  }
	else
	  {
	    string s = string("'") + string(refPath) + string("' is not a single bit field");
	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	    return 0;
	  }
      }
    else
      {
	//for struct/element/field
	string s = string("'") + string(refPath) + string("' not found");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return 0;
      }
  }



  //---------------
  // nrbits(operand)
  //---------------

  unsigned int 
  getNumBits(const char* refPath)
  {
    shared_ptr<const Type> type = lookupPathEndPoint(refPath);

    shared_ptr<const AbstractField> fldTp = shared_dynamic_cast<const AbstractField>(type);

    if(fldTp)
      {
	return (fldTp->getMSBitPosition() - fldTp->getLSBitPosition() + 1);
      }
    else
      {
	string s = string("'") + refPath + string("' is not a field");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return 0;
      }
    
  }


  //---------------
  // baseof(path)
  //---------------

  shared_ptr<const Register> 
  getBaseOf(const char* refPath)
  {

    shared_ptr<const Struct> stType;

    string path = refPath;

    string token = getTokenStr(path);
    path = extractSubString(path);

    // Look up symbol, this must work for both local (.smap) and global (.map)
    // mappings.
    shared_ptr<OctaveSymbol> sym = lookupOctaveSymbol(token.c_str());

    if(shared_dynamic_cast<NullSymbol>(sym))
      {
	string s = string("symbol '") + token + string("' not found");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));

	return llirFactory->createNullReg();
      }

    shared_ptr<const MapSymbol> mapSym = shared_dynamic_cast<const MapSymbol>(sym);

    if(mapSym)
      {
	stType = mapSym->getMappedStruct();
      }
    else
      {
	string s = string("'") + token + string("' is not a map name");
	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	  
	return llirFactory->createNullReg();      
      }


    // return the first register to which
    // mapName is associated with.

    shared_ptr<const Register> mappedReg = mapSym->getRegister();

    return mappedReg->getRegister(0);

  }


  //--------------------------------
  //offsetof(mapped_path, type_path)
  //--------------------------------

  unsigned int 
  getRelativeOffset(const char* subPath, const char* path)
  {


    //return getOffset(subPath) - getOffset(path);

    unsigned int offset1 = getOffset(path);
    unsigned int offset2 = getOffset(subPath);

    return offset2 - offset1;

    //FIXME:
    //complain if subPath is not within the path...
    //complain if return value is negative...
  }


  //------------------
  // .meets directive
  //------------------

  bool 
  compareStruct(const char* testedPath, const char* refPath)
  {
    shared_ptr<const Type> testedType = lookupPathEndPoint(testedPath);
    shared_ptr<const Type> refType = lookupPathEndPoint(refPath);
    
    shared_ptr<const Struct> testedStruct = shared_dynamic_cast<const Struct>(testedType);
    shared_ptr<const Struct> refStruct = shared_dynamic_cast<const Struct>(refType);

    if(! testedStruct)
      {
	string s = string("'") + testedPath + string("' is not a struct endpoint");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));
	return false;
      }

    if(! refStruct)
      {
	string s = string("'") + refPath + string("' is not a struct endpoint");

	parseAlo->logException(shared_ptr<IllegalSymbolOperand>
			       (new IllegalSymbolOperand(s.c_str(),
							 get_src_line(), 
							 get_src_file(), 
							 __LINE__, __FILE__)));

	return false;
      }

    return isSubset(testedStruct, refStruct);

  }

  bool
  isSubset(shared_ptr<const Struct> testedStruct, shared_ptr<const Struct> refStruct)
  {
    // recursive function.

    // test recursively to see if refStruct is proper subset of
    // testedStruct, all the elements of refStruct should be found
    // with same attributes (name, offset, size, bitpoisitions)

    //      if( testedStruct->getName() != refStruct->getName() ||
    //  	testedStruct->getScopeQualifier() != refStruct->getScopeQualifier() )
    //        {
    //  	 return false;
    //        }
    
    Type::ConstIterator testedStructIter = testedStruct->begin();
    Type::ConstIterator refStructIter = refStruct->begin();
    
    for(; refStructIter != refStruct->end(); refStructIter++)
      {
	
	string name = (*refStructIter)->getName();
	
	// lookup element 'name' of refStruct in testedStruct
	Type::ConstIterator tTpIter = testedStruct->lookupType(name.c_str());
	
	if(tTpIter != testedStruct->end())
	  {

	    shared_ptr<const Struct> tInnerSt = shared_dynamic_cast<const Struct>(*tTpIter);
	    shared_ptr<const Struct> rInnerSt = shared_dynamic_cast<const Struct>(*refStructIter);
		
	    if(tInnerSt && rInnerSt)
	      {
		// both testedStruct and refStruct have an 
		// element with same 'name' and both are 
		// structures

		//check if they are at the same offset
		if(tInnerSt->getOffset() != rInnerSt->getOffset())
		  {
		    return false;
		  }

		//check if the inner structs  'meet' too.
		return isSubset(tInnerSt, rInnerSt);
	      }

	    //else they could be fields or bitfields 
	    //so test for their equality

	    if(**refStructIter != **tTpIter)
	      {
		return false;
	      }
	    // both elements meet so continue;
	  }
	else
	  {
	    //element of testedStruct not found in refStruct
	    return false;
	  }
      }
    
    return true;

  }

  //-------------------
  // Fix Label Operands
  //-------------------


  void 
  fixLabelOperands()
  {
    fixLabelOperands(g_rootBlock);
  }


  //recursive function

  void 
  fixLabelOperands(shared_ptr<LlirOctaveBlock> blk)
  {
  
    fixupLabels(blk);
  
    LlirNode::Iterator nodeIter = blk->begin();
  
    for(; nodeIter != blk->end(); nodeIter++)
      {
	try 
	  {
	    shared_ptr<LlirOctaveBlock> child = shared_dynamic_cast<LlirOctaveBlock>(*nodeIter);
	  
	    if(child)
	      {
		fixLabelOperands(child);
	      }
	  
	  }
	catch(std::bad_cast)
	  {
	    throw LLIR_INTERNAL_EXCEPTION("bad cast exception");
	  }
      }
  }


  //helper for the fixupLabelOperands function

  void 
  fixupLabels(shared_ptr<LlirOctaveBlock> block)
  {

    LlirOctaveBlock::FixupListIterator iter = block->fixupListBegin();

    for(; iter != block->fixupListEnd(); iter++)
      {
	shared_ptr<OpndLabel> labelOpnd = *iter;

	const char* labelName = labelOpnd->getName().c_str();

	//if label opernad is a function entry label, 
	//we need not fix it, as semantic visitor makes sure that
	//function entry points have unique labels.

#ifdef OPTIMIZING_ALO
	if(hasValidPrototype(labelName))
	  {
	    // mangled name == original name
	    labelOpnd->setMangledName(labelName);
	    continue;
	  }
#endif

	shared_ptr<OctaveSymbol> symbol = lookupOctaveSymbol(block, labelName);

	shared_ptr<LabelSymbol> labelSymbol = shared_dynamic_cast<LabelSymbol> (symbol);

	string mName;

	if(labelSymbol)
	  {

	    //symbol found in this compilation unit
	    //so set the OpndLabel's mangledName to 
	    //that of OctaveSymbol's mangledName

	    mName = labelSymbol->getMangledName();

	    labelOpnd->setMangledName(mName);

	  }
	else
	  {
	    //seems to be a GLOBAL symbol
	    //so OpndLabel's mangledName == name

	    labelOpnd->setMangledName(labelName);

	  }
      }

  }


  void UnMapSymbol(const char* name)
  {
    shared_ptr<OctaveSymbol> octSym = lookupOctaveSymbol(g_rootBlock, name);
    
    shared_ptr<MapSymbol> mapSym = shared_dynamic_cast<MapSymbol>(octSym);

    if(mapSym)
      {
	g_rootBlock->removeSymbol(mapSym);
      }
    else
      {
	shared_ptr<NullSymbol> nullSym = shared_dynamic_cast<NullSymbol>(octSym);

	if(!nullSym)
	  {
	    string s = string("symbol '") + name + string("' is not a map name");

	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  }
	else
	  {
	    string s = string("symbol '") + name + string("' not found");

	    parseAlo->logException(shared_ptr<IllegalSymbolOperand>
				   (new IllegalSymbolOperand(s.c_str(),
							     get_src_line(), 
							     get_src_file(), 
							     __LINE__, __FILE__)));
	  }
      }
    
  }

}

