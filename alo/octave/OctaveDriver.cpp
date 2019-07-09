#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <string>

#include <sys/types.h>
typedef long blksize_t; // JOE we need to fix this....
#include <sys/stat.h>

#include "Alo.h"
#include <AloDriver.h>
#include <LlirException.h>
#include <AloException.h>

#include "OctaveDriver.h"
using namespace std;

extern const char *saved_argv0; // main.cpp

namespace Alo
{
  OctaveDriver::OctaveDriver() :
    AloDriver(), 
    m_asCppName("as_cpp"),
    m_asName("as")

  {
    m_makerRoot = getEnvironmentVariable("MAKER_ROOT");
    fixDirectoryPath(m_makerRoot);

    m_makerRev  = getEnvironmentVariable("MAKER_REV");
    fixDirectoryPath(m_makerRev); // XXX -- why should I fix this?

    m_makerSysType  = getEnvironmentVariable("MAKER_SYSTYPE");
    fixDirectoryPath(m_makerSysType);
  }

  OctaveDriver::~OctaveDriver()
  {}

  const std::string
  OctaveDriver::getEnvironmentVariable(const char *envVar) const
  {
    const char *p = getenv(envVar);
    if (p == NULL || *p == '\0')
      {
	std::string s = "Environment variable " +  std::string(envVar) + " not set.";
	throw EnvVarNotSet(s.c_str(), __LINE__, __FILE__);
      }

    const string value(p);

    // XXX -- Should I be checking for empty strings?
    // mxtas doesn't.

    if (value.empty())
      {
	std::string s1 = "Environment variable " +  std::string(envVar) + " not set.";
	throw EnvVarNotSet(s1.c_str(), __LINE__, __FILE__);
      }
    return value;
  }

/**
 * Cleans up a path string.
 *
 * @param path the path to be cleaned up
 *
 * Currently all this does is remove any ending '/'s.
 */

  void
  OctaveDriver::fixDirectoryPath(std::string &path)
  {
    // Remove any ending '/'s.
 
    string::size_type pos = path.rfind('/');
    if (pos == path.length() - 1)
      path.erase(pos);
  }

  bool
  OctaveDriver::pathExists(const string& path) const
  {
    struct stat buf;
    return (stat(path.c_str(), &buf) == 0);
  }

  const std::string&
  OctaveDriver::getMakerRootPath() const
  {
    return m_makerRoot;
  }

  const std::string&
  OctaveDriver::getMakerRevPath() const
  {
    return m_makerRev;
  }

  const std::string&
  OctaveDriver::getMakerSysType() const
  {
    return m_makerSysType;
  }

  const std::string&
  OctaveDriver::getPreprocessorName() const
  {
    return m_asCppName;
  }

  const std::string&
  OctaveDriver::getAssemblerName() const
  {
    return m_asName;
  }


  const std::string
  OctaveDriver::getAsmBaseName(const std::string& fileName) const
  {
    const string asm_extension = ".s";

    // Ensure that filename is longer than the file extension.

    if (fileName.length() <= asm_extension.length())
      {
	std::string s = "File name \"" + fileName + 
	  "\" is invalid. File must have a extension of \".s\".";
	throw InvalidFileName(s.c_str(), __LINE__,__FILE__);
      }

    // Ensure the last two characters are the file extension.

    const string::size_type basename_length = fileName.length() -
      asm_extension.length();

    if (fileName.compare(basename_length, asm_extension.length(),
			 asm_extension))
      {
	std::string s = "File name \"" + fileName + 
	  "\" is invalid. File must have a extension of \".s\".";
	throw InvalidFileName(s.c_str(), __LINE__,__FILE__);
      }


    string::size_type idx = fileName.rfind('/');
    if (idx == string::npos)
      return fileName;
    else
      {
	return (fileName.substr(idx + 1));
      }
  }

  const std::string
  OctaveDriver::createCppCmdLine(const std::string& cpp_path,
				   const std::string& asm_filename,
				   const std::string& preprocessed_filename,
				   const std::string& cpp_options)
  {
    return 
      cpp_path + " " + asm_filename + " " + cpp_options +
      " > " + preprocessed_filename;
  }

  const std::string
  OctaveDriver::createAsmCmdLine(const std::string& asm_path,
			      const std::string& asm_filename,
			      const std::string& obj_filename,
			      const std::string& asm_options)
  {
    return 
      asm_path + asm_options + obj_filename + " " + asm_filename;
  }


  const std::string
  OctaveDriver::getDefaultCppPath() const
  {
    std::string path = saved_argv0;
    string::size_type last_slash = path.rfind('/');
    if (last_slash == string::npos)
      {
	// No '/' in argv[0].  Assume the program was invoked from $PATH, and
	// allow as_cpp to be found the same way.
	path.erase();
      }
    else
      {
	path.erase(last_slash, path.size());
      }
    path = path + '/' + getPreprocessorName();

    return (path);
  }


  const std::string
  OctaveDriver::getDefaultAsmAndPath() const
  {

    std::string path = saved_argv0;
    string::size_type last_slash = path.rfind('/');
    if (last_slash == string::npos)
      {
	// See comments above.
	path.erase();
      }
    else
      {
	path.erase(last_slash, path.size());
      }
    path = path  + '/' + getAssemblerName();

    return (path);
  }


  void
  OctaveDriver::runExecutable(const char *toolName, 
			   const char *doWork, 
			   const std::string &cmdLine)
  {
    // XXX 
    // Note that the second catch block will catch
    // any error thrown. If people want more granularity
    // we can catch the different errors thrown by do_command.
    // But I just do like the current assembler for now. It
    // makes the distinction between failure to start the
    // command (popen) and lumps all non-zero exit statuses
    // together. do_command will throw different errors for
    // -1 and any other non-zero values.

    try
      {
	const int exit_status = executeCommand(cmdLine);
	if (exit_status != 0)
	{
	  std::string s = "Command failed: \"" + cmdLine + "\".";
	  throw AloInternalException(s.c_str(), __LINE__, __FILE__);
	}
      }
    catch (const CmdStartFailure &error)
      {
	string failMsg = string("Could not start the ") + toolName;

	throw AloInternalException(failMsg.c_str(),
				 __LINE__, __FILE__);
      }
    catch (const CmdFailure &error)
      {
	string failMsg = string("Failed to ") + doWork;
	throw AloInternalException(failMsg.c_str(),  __LINE__, __FILE__);
      }
  }



  int 
  OctaveDriver::executeCommand(const string& cmdLine)
  {
    // Open the process by creating a pipe, forking, and
    // invoking the shell.
    
    FILE *process = popen(cmdLine.c_str(), "r");
    if (process == NULL)
      {
	std::string s = "Failed to start command \"" + cmdLine + "\".";
	throw AloInternalException(s.c_str(), __LINE__, __FILE__);
      }

    // Wait for the process to terminate and then get its exit
    // status.
    
    const int exit_status = pclose(process);
    if (exit_status == -1)
      {
	std::string s = "Problem finishing command \"" + cmdLine + "\".";
	throw AloInternalException(s.c_str(), __LINE__, __FILE__);
      }

    return exit_status;
  }

  const std::string
  OctaveDriver::preprocessFile(const char *asmFileName, 
					std::string& cppPath, 
					const std::string& cppOptions)
  {
    if (cppPath.empty())
      cppPath = getDefaultCppPath();
    else
      {
	fixDirectoryPath(cppPath);
	if (!pathExists(cppPath))
	  {
	    std::string s = "Preprocessor not found at path \"" + cppPath + "\".";
	    throw AloInternalException(s.c_str(), __LINE__, __FILE__);
	  }
      }

    const string asmBaseName = getAsmBaseName(asmFileName);

    const string preprocessedFileName = fileBaseName(asmBaseName) + ".i";
      
    const string cppCmdLine = createCppCmdLine(cppPath, 
					       asmFileName,
					       preprocessedFileName,
					       cppOptions);

    runExecutable("Preprocessor", "preprocess", cppCmdLine);

    return preprocessedFileName;
  }


  void
  OctaveDriver::assembleFile(const string& intermediateAsmFileName,
			     const string& outObjFileName,
			     const string& asmOptions)
  {
    string asmPath = getDefaultAsmAndPath();

    if(!pathExists(asmPath))
      {
	std::string s = "Assembler not found at path \"" + asmPath + "\".";
	throw AloInternalException(s.c_str(), __LINE__, __FILE__);
      }

    string options = asmOptions + " -o ";

    const string asmCmdLine = createAsmCmdLine(asmPath, 
					       intermediateAsmFileName,
					       outObjFileName,
					       options);

    //call the acutal assembler...
    runExecutable("Assembler", "assemble", asmCmdLine);
  }




}



