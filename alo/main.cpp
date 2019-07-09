#include <iostream>
#include <OctaveAlo.h>

using namespace Llir;
using namespace Alo;

extern shared_ptr<OctaveAlo> createAlo();

const char *saved_argv0; // Used by OctaveDriver.

/// The program entry point.
#ifdef GCCBUILD
int alo_fe_main_cpp(int argc, char *argv[])
#else
int main(int argc, char* argv[])
#endif
{
  saved_argv0 = argv[0];

  shared_ptr<OctaveAlo> alo;

  try
    {
      alo = createAlo();
    }
  catch(EnvVarNotSet &e)
    {
      std::cout <<  e.what() << '\n';
      cout << "Assembly terminating.\n";
      exit(1);
    }
  catch(...)
    {
      std::cerr << "An unknown exception was thrown. Please report this bug.\n";      
      cout << "Assembly terminating.\n";
      exit(1);
    }



  try
    {
      alo->assemble(argc, argv);
    }
  catch (NoInputFileSpecified &e)
    {
      alo->printFatalError(e.what());
    }
  catch (InvalidFileName &e)
    {
      alo->printFatalError(e.what());
    }
  catch (AloInternalException &e)
    {
      alo->printFatalInternalError(e.what());
    }
  catch (LlirInternalException &e)
    {
      alo->printFatalInternalError(e.what(), e.getFileName().c_str(), e.getLineNum());
    }
  catch (AloFatalError &e)
    {
      alo->printFatalError(e.what(), e.getInputSrcFileName().c_str(), e.getInputSrcLineNum());
    }
  catch (LlirSemanticException &e)
    {      
      alo->printFatalError(e.what(), e.getInputSrcFileName().c_str(), e.getInputSrcLineNum());
    }
  catch (...)
    {
      // If all of our errors and exceptions are 
      // defined correctly, we should never get here.
      
      std::cerr << "An unknown exception was thrown. Please report this bug.\n";
    }

  // The exit status of the program is the value returned by main.
  if (alo->getNumErrors() != 0)
    {
      return 1;
    }
  
  return 0;
}




