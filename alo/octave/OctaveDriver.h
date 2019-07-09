#ifndef _OCTAVE_ALO_DRIVER_H
#define _OCTAVE_ALO_DRIVER_H

#include <string> 
using namespace std;

#include <AloDriver.h>

namespace Alo
{
  string fileBaseName(const string &fileName);

  class OctaveDriver : public AloDriver
  {
  public:
    OctaveDriver();
    virtual ~OctaveDriver();

    const string preprocessFile(const char *fileName, string& cppPath, 
				const string& cppOptions);

    void assembleFile(const string& intermediateAsmFileName, 
		      const string& outObjFileName,
		      const string& asmOptions);

  protected:
    const string getEnvironmentVariable(const char *env) const;
    void fixDirectoryPath(string &path);
    bool pathExists(const string &path) const;
    const string getDefaultCppPath() const;
    const string getDefaultAsmAndPath() const;
    const string& getMakerRootPath() const;
    const string& getMakerRevPath() const;
    const string& getMakerSysType() const;
    const string getAsmBaseName(const string&) const;
    const string& getPreprocessorName() const;
    const string& getAssemblerName() const;
    virtual const string& getMakerProduct() const = 0;
    const string createCppCmdLine(const string& cpp_path,
			 	       const string& asm_filename,
				       const string& preprocessed_filename,
				       const string& cpp_options);
    const string createAsmCmdLine(const string& asm_path,
			 	       const string& asm_filename,
				       const string& obj_filename,
				       const string& asm_options);
    void runExecutable(const char *toolName,
		       const char *doWork,
		       const string &cmdLine);
    int executeCommand(const string& cmd_line);


  private:
    string m_makerRoot;
    string m_makerRev;
    string m_makerSysType;
    string m_asCppName;
    string m_asName;
  };

}

#endif
