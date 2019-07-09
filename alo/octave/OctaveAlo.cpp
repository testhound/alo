#include <iostream>
#include <fstream>
#include <cstdio>
#include <unistd.h>

#include <sys/types.h>
typedef long blksize_t; // JOE we need to fix this....

#include <sys/stat.h>

#include <AloErrorWarningVisitor.h>
#include "OctaveAlo.h"



using namespace Llir;
using namespace Alo;
using namespace std;

extern void parse_main(const char *ifile, OctaveAlo &alo, shared_ptr<LlirFile>);
extern int yydebug;

namespace Alo
{



  //////////////////////////////
  //globals
  //////////////////////////////
  
  //FIXME : try to eliminate these vars...
  
  extern shared_ptr<LlirOctaveBlock> g_rootBlock;
  extern shared_ptr<LlirOctaveBlock> g_currentBlock;
  extern shared_ptr<OctaveFactory> llirFactory;
  extern OctaveAlo *parseAlo;
  

  string
  fileBaseName(const std::string &fileName)
  {
    string::size_type idx = fileName.rfind('.');
    if (idx == string::npos)
      return fileName;
    else
      {
	return (fileName.substr(0, idx));
      }
  }

  const std::string
  getBaseName(const std::string& fileName)
  {
    string::size_type idx = fileName.rfind('/');

    if (idx == string::npos)
      return fileName;
    else
      {
	return (fileName.substr(idx + 1));
      }
  }

  OctaveAlo::OctaveAlo() :
    Alo(),
    m_numErrors(0),
    m_numWarnings(0),
    m_maxNumErrors(0),
    m_disableWarnings(false),
    m_objectFileName("")
  {}

  OctaveAlo::~OctaveAlo()
  {}

  void
  OctaveAlo::createLlirFile(const char *name)
  {
    shared_ptr<LlirFile> file (new LlirFile(name));
    m_fileList.push_back(file);
  }

  unsigned int
  OctaveAlo::getNumErrors() const
    {
      return m_numErrors;
    }

  OctaveAlo::Iterator
  OctaveAlo::begin()
  {
    return m_fileList.begin();
  }

  OctaveAlo::ConstIterator
  OctaveAlo::begin() const
  {
    return m_fileList.begin();
  }

  OctaveAlo::Iterator
  OctaveAlo::end()
  {
    return m_fileList.end();
  }

  OctaveAlo::ConstIterator
  OctaveAlo::end() const
  {
    return m_fileList.end();
  }


  unsigned int
  OctaveAlo::getNumWarnings() const
    {
      return m_numWarnings;
    }

  void
  OctaveAlo::logException(shared_ptr<std::exception> exc)
    {
      m_loggedExceptions.logException(exc);
    }

  void
  OctaveAlo::printFatalInternalError(const char *errorMsg)
    {
      std::cerr << "A Fatal Error has occurred. " << errorMsg << '\n';
      std::cerr << "Please contact Mindspeed Technical Support." << '\n';
      std::cerr << "Assembly terminating." << '\n';
      exit(1);
    }

  void
  OctaveAlo::printFatalInternalError(const char *errorMsg, const char *fileName, unsigned int lineNum)
    {
      std::cerr << "A Fatal Error has occurred: " << errorMsg << ' ' << fileName << ':' << lineNum << '\n';
      std::cerr << "Please contact Mindspeed Technical Support." << '\n';
      std::cerr << "Assembly terminating." << '\n';
      exit(1);
    }

  void
  OctaveAlo::printFatalError(const char *errorMsg)
    {
      std::cerr << errorMsg << '\n';
      std::cerr << "Assembly terminating." << '\n';
      exit(1);
    }

  void
  OctaveAlo::printFatalError(const char *errorMsg, const char *srcfileName, unsigned int srclineNum)
    {
      std::cerr << "A Fatal Error has occurred: " << errorMsg << ' ' << srcfileName << ':' << srclineNum << '\n';
      std::cerr << "Assembly terminating." << '\n';
      exit(1);
    }

  void
  OctaveAlo::printError(const char *fileName, unsigned int lineNum, const char *errorMsg)
    {
      if ((m_maxNumErrors == 0) || (m_numErrors < m_maxNumErrors))
	{
	  std::cerr << fileName << ":" << lineNum << ": Error: " << errorMsg << '\n';
	  m_numErrors++;
	}
      else
	printFatalError("Maximum number of errors reached.");
    }

  void
  OctaveAlo::printWarning(const char *fileName, unsigned int lineNum, const char *warnMsg)
    {
      if (m_disableWarnings == false)
	{
	  std::cerr << fileName << ":" << lineNum << ": Warning: " << warnMsg << '\n';
	  m_numWarnings++;
	}
    }

  void
  OctaveAlo::printWarning(const char *warnMsg)
    {
      if (m_disableWarnings == false)
	{
	  std::cerr << "Warning " << warnMsg << '\n';
	  m_numWarnings++;
	}
    }

  void
  OctaveAlo::disableWarnings()
  {
    m_disableWarnings = true;
  }

  void OctaveAlo::setMaxErrors(unsigned int maxErrors)
  {
    m_maxNumErrors = maxErrors;
  }

  void OctaveAlo::setObjectFileName(const char *name)
  {
    m_objectFileName = name;
  }

  const std::string&
  OctaveAlo::getObjectFileName() const
  {
    return m_objectFileName;
  }

  void
  OctaveAlo::handleLoggedExceptions()
    {
      AloErrorWarningVisitor ewv(*this);
      
      AloExceptionLogger::Iterator iter = m_loggedExceptions.begin();

      for(; iter != m_loggedExceptions.end(); iter++)
	{

	  shared_ptr<LlirException> exc = shared_dynamic_cast<LlirException>(*iter);

	  if(exc)
	    {
	      exc->accept(ewv);
	    }
	  else
	    {
	       shared_ptr<AloException> exc = shared_dynamic_cast<AloException>(*iter);

	       if(exc)
		 {
		   exc->accept(ewv);
		 }
	       else
		 {
		   //FIXME : throw
		   cout << "?? unknown exception found ??" << endl;
		 }
	     }
	 }

      // Don't report exceptions a second time.
      m_loggedExceptions.clear();
    }

}
