#ifndef __ALO_DRIVER_H_
#define __ALO_DRIVER_H_

#include <string> 
using namespace std;

namespace Alo
{
  string fileBaseName(const string &fileName);

  class AloDriver
  {
  public:
    AloDriver()
      {}

    virtual ~AloDriver()
      {}

    virtual const string preprocessFile(const char *fileName, string& cppPath, 
					     const string& cppOptions) = 0;

    virtual void assembleFile(const string& intermediateAsmFileName,
			      const string& outObjFileName,
			      const string& asmOptions) = 0;

  };
}

#endif
