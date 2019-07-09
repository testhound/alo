#include "LlirSymbol.h"

namespace Llir 
{


  bool 
  operator==(const Symbol &lhs, const Symbol &rhs)
  {
    return lhs.equal(rhs);
  }

  bool 
  operator!=(const Symbol &lhs, const Symbol &rhs)
  {
    return !(Llir::operator==(lhs,rhs));
  }


  
  Symbol::Symbol(const char* name) 
    : m_symbolName(name)
  {}

  Symbol::Symbol(const Symbol& rhs) 
    : m_symbolName(rhs.m_symbolName)
  {}

  Symbol&
  Symbol::operator=(const Symbol& rhs)
  {
    if(this == &rhs)
      return *this;

    m_symbolName = rhs.m_symbolName;
    return *this;
  }

  bool 
  Symbol::equal(const Symbol &rhs) const
  {
    if(typeid(*this) != typeid(rhs))
      return false;
    else
      return rhs.equalTo(*this);
  }

  const string&
  Symbol::getName() const
  {
    return m_symbolName;
  }


} // namespace Llir
