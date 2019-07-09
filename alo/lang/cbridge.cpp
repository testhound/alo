/*
 * "C" interface for yyparse, and possibly other functions.  These
 * functions are required to allow GCC to call (from "C") ALO
 * functions that are compiled with C++ linkage
*/
#include <OctaveSymbol.h>
using namespace Llir;

extern int yyparse_cpp();

extern "C" int alo_parse()
{
  return yyparse_cpp();
}

#ifdef GCCBUILD
// count_error() is defined in gcc/diagnostic.c.  It
// provides a means to signal toplev.c that we should
// exit non-zero.
extern "C" int count_error(int);	

extern int alo_fe_main_cpp(int argc, char *argv[]);

extern "C" int alo_fe_main(int argc, char *argv[])
{
  int status;
  status = alo_fe_main_cpp(argc, argv);
  if (status != 0)
    {
      count_error(0);
    }
  return status;
}
#endif


extern "C"
{
  unsigned int get_single_pseudo_reg();
  int get_multi_hard_reg(unsigned int, unsigned int);
  void unget_multi_hard_reg(unsigned int, unsigned int);
}

unsigned int 
gcc_get_single_pseudo_reg()
{
#ifdef GCCBUILD
  return get_single_pseudo_reg();
#else
  return 128;
#endif
}

enum REG_TYPE { GENERAL=0, EVEN, ODD };

int 
gcc_get_multi_hard_reg(unsigned int size, AbstractSymReg::SymRegConstraint constraint)
{
#ifdef GCCBUILD

 
   if(constraint == AbstractSymReg::SRC_BEGIN_AT_EVEN_REG)
    {
      return get_multi_hard_reg(size, EVEN);
    }
  
   if(constraint == AbstractSymReg::SRC_BEGIN_AT_ODD_REG)
    {
      return get_multi_hard_reg(size, ODD);
    }

   return get_multi_hard_reg(size, GENERAL);

#else

   /* dummy return */
   return 128;

#endif
}

void
gcc_unget_multi_hard_reg (unsigned int firstRegno, unsigned int lastRegno)
{
#ifdef GCCBUILD
  return unget_multi_hard_reg(firstRegno, lastRegno);
#endif
}




