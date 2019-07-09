#ifndef _LLIR_SYMBOL_H
#define _LLIR_SYMBOL_H

/**
  * \file 
  *
  * \brief Symbol Class Description
  * 
  */

#include <string>
#include <map>
using namespace std;

#include <boost/shared_ptr.hpp>
using namespace boost;


namespace Llir 
{

  class Symbol;

  bool operator==(const Symbol& lhs, const Symbol& rhs);
  bool operator!=(const Symbol& lhs, const Symbol& rhs);

  class Symbol
    {
    public:

      virtual ~Symbol() 
	{}

      const string& getName() const;

      bool equal(const Symbol& rhs) const;

    protected:

      Symbol(const char *name);

      Symbol(const Symbol& rhs);

      Symbol& operator=(const Symbol& rhs);

    private:

      virtual bool equalTo(const Symbol& rhs) const=0;

      string m_symbolName;
  	
    };

} // namespace Llir 



#endif
