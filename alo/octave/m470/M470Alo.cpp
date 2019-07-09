#include <iostream>
#include <fstream>
#include <cstdio>
#include <unistd.h>

#include <sys/types.h>
typedef long blksize_t; // JOE we need to fix this....

#include <sys/stat.h>

#include <Alo.h>
#include <LlirFile.h>
#include <LlirException.h>
#include <AloException.h>
#include <OctaveDelaySlotAnalyzer.h>
#include <M470Factory.h>
#include <M470PrintVisitor.h>

#include "M470Alo.h"
#include "M470SemanticVisitor.h"

#include "cmdline.h"

using namespace Llir;
using namespace Alo;
using namespace std;

extern void parse_main(const char *ifile, OctaveAlo &alo, shared_ptr<LlirFile>);

/* 
   Now that we are using -palo_ option with
   bison all yy variables are renamed
*/

extern int alo_debug;

namespace Alo
{
  extern string fileBaseName(const string &fileName);
  extern const std::string getBaseName(const std::string& fileName);

  // M470Alo

  M470Alo::M470Alo() : 
    OctaveAlo(),
    m_asm(),
    m_M470Factory(new M470Factory),
    m_preprocessedFileName(""),
    m_aloGeneratedAsmFileName("")
    {}

  M470Alo::~M470Alo()
    {}

  void
  M470Alo::assemble(int argc, char *argv[])
  {
    parseCommandLine(argc, argv);

    const char *fileName;

    for (OctaveAlo::Iterator it = begin(); it != end(); it++)
      {

	fileName = (*it)->getName().c_str();

	preprocessAsmFile(fileName);

	parseAsmFile(*it);

	//  if (!optimize)
	  {
	    m_aloGeneratedAsmFileName = fileBaseName(getBaseName((*it)->getName())) + ".i2";
	    if (!aloCmdLine.m_explicitObjectFileSpecified)
	      {
		setObjectFileName((fileBaseName(getBaseName((*it)->getName())) + ".o").c_str());
	      }

	    // iterate over all nodes of the file
	    // and analyze their semantics.

	    LlirFile::Iterator nIter = (*it)->begin();
	    for(; nIter != (*it)->end(); nIter++)
	      {
		analyzeSemantics(*nIter);
	      }

	    if(! aloCmdLine.m_noDslotWarn)
	      {
		checkDelaySlots(*it);
	      }

	    handleLoggedExceptions();

	    if(getNumErrors() == 0)
	      {
		printAssemblyFile(*it);
		generateObjectCode(fileName);
	      }
	  }
	  //}

	if (!aloCmdLine.m_saveTemps)
	  {
	    unlink(m_preprocessedFileName.c_str());
	    unlink(m_aloGeneratedAsmFileName.c_str());
	  }

#if 0
	fixLabelOperands();
#endif
      }
  }


  void
  M470Alo::checkDelaySlots(shared_ptr<LlirFile> file)
  {
    //*this is passed along so that the analyzer
    //can log exceptions.
    OctaveDelaySlotAnalyzer dslotAnalyzer(*this);

    dslotAnalyzer.checkDelaySlots(file);
  }


//   void
//   M470Alo::analyzeSemantics(shared_ptr<LlirFile> file)
//   {
//     LlirFile::Iterator it = file->begin();
//     M470SemanticAnalysisVisitor semanticVisitor(*this);
//     for (; it != file->end(); it++)
//       (*it)->accept(semanticVisitor);
//   }

  void
  M470Alo::analyzeSemantics(shared_ptr<LlirNode> node)
  {
    M470SemanticAnalysisVisitor semanticVisitor(*this);
    node->accept(semanticVisitor);
  }

  void
  M470Alo::markSequenceInsns(shared_ptr<LlirOctaveBlock> blk)
  {
    string s = "Rtl sequence recognition not supported forM470";
    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
  }


  void
  M470Alo::analyzeCurrentFunction(shared_ptr<LlirNode> node)
  {
    string s = "Rtl generation and analysis of function not supported forM470";
    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
  }

  void
  M470Alo::generateRTL(shared_ptr<LlirNode> node)
  {
    string s = "Rtl generation not supported forM470";
    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
  }


  void
  M470Alo::identifyBranchTargets(shared_ptr<AltEntryFunction> node)
  {
    string s = "Branch target identification not supported forM470";
    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
  }

  void
  M470Alo::identifyCallTargets(shared_ptr<AltEntryFunction> node)
  {
    string s = "Call target identification not supported forM470";
    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
  }

  void
  M470Alo::identifyLiveEssRegisters(shared_ptr<AltEntryFunction> node)
  {
    string s = "Ess Register Liveness Identification is not supported for M470";
    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
  }

  void 
  M470Alo::parseAsmFile(shared_ptr<LlirFile> llirFile)
  {
    parse_main(m_preprocessedFileName.c_str(), *this, llirFile);
  }

  void 
  M470Alo::preprocessAsmFile(const char *asmFileName)
  {
    m_preprocessedFileName = m_asm.preprocessFile(asmFileName, aloCmdLine.m_cppPath, aloCmdLine.m_cppOptions);
  }


  void
  M470Alo::generateObjectCode(const char* asmFileName)
  {

    string asmOptions = " --nocpp "; //to disable mxtas as_cpp
    
    if(getNumWarnings())
      {
	//disable warnings in the back end assembler if 
	//alo already generated them...
	
	asmOptions += " -W ";
      }
 
    m_asm.assembleFile(m_aloGeneratedAsmFileName,
		       getObjectFileName(),
		       asmOptions);
  }


  void
  M470Alo::printAssemblyFile(shared_ptr<LlirFile> file)
  {
    ofstream outAsmFile(m_aloGeneratedAsmFileName.c_str());

    if (!outAsmFile)
      throw AloInternalException("Unable to open assembly language file for output", __LINE__, __FILE__);

    M470PrintVisitor printVisitor(outAsmFile);
    LlirFile::Iterator it = file->begin();

    for (; it != file->end(); it++)
      (*it)->accept(printVisitor);
  }


  void
  M470Alo::parseCommandLine(int argc, char *argv[])
  {
    int optind;

    optind = cmdline_process_all_options(argc, argv);

    if (aloCmdLine.m_errorLimit_set)
      {
	if (aloCmdLine.m_errorLimit > 0)
	  setMaxErrors(aloCmdLine.m_errorLimit);
	else
	  printWarning("Error limit must be > 0. Option ignored.");
      }

    // Note: there is NO else case here.  If the object file name was
    // not explicitly specified, we should handle the case where there
    // are multiple input files, and derive the object file name
    // with each iteration.  We handle that in the ::assemble metod.
    if (aloCmdLine.m_explicitObjectFileSpecified)
      {
	setObjectFileName(aloCmdLine.m_objectFileName);
      }


#if 0
    while (1)
      {
	  case 'h':
	    displayUsage();
	    exit(1);
	    break;

	  case 'v':
	    break;

	  case 'W':
	    disableWarnings();
	    break;
	  }
      }

#endif

    if (optind == argc)
      throw NoInputFileSpecified("No input file specified", __LINE__, __FILE__);

    struct stat buf;
    for (int i = optind, numFiles = 0; i < argc; i++, numFiles++)
      {
	if (stat(argv[i], &buf) == 0)
	  {
	    if (aloCmdLine.m_explicitObjectFileSpecified == true && numFiles == 1)
	      {
		printFatalError("Cannot specifiy -o <objfile> and more than one assembly file");
	      }
	    createLlirFile(argv[i]);
	  }
	else
	  {
	    string s = "File \"" + string(argv[i]) + "\" could not be found.";
	    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
	  }
      }
  }


  shared_ptr<Llir::OctaveFactory>
  M470Alo::getFactory() const
  {
    return m_M470Factory;
  }

  void
  M470Alo::displayUsage()
  {
    cerr << endl;
    cerr << "Usage: " << "alo" << " [options] file\n";
    cerr << endl;
    cerr << "Options:\n";
    cerr << "-h, --help        Display this help and exit\n";
    cerr << "-v                Does nothing\n";
    cerr << "--version         Does nothing\n";
    cerr << "--verbose         Does nothing\n";
    cerr << "--cpp_path=PATH   Specify the path to the preprocessor to \n";
    cerr << "                  run on the source file. The default is \n";
    cerr << "                  found in MAKER_ROOT.\n";
    cerr << "--Wno-dslot-warn  Do not show invalid delay slot warnings \n";
    cerr << "-I FILE           Include FILE.\n";
    cerr << "-D <var>          Define  var\n";
    cerr << "--yydebug         Turn on parser debug output to stderr\n";
    cerr << endl;
  }


}
