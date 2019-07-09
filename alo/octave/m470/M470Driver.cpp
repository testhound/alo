

#include "M470Driver.h"

namespace Alo
{
  //

  M470Driver::M470Driver() : 
    OctaveDriver(),
    m_makerProduct("cx27470-elf")
  {

  }

  M470Driver::~M470Driver()
  {}

  const std::string& 
  M470Driver::getMakerProduct() const
  {
    return m_makerProduct;
  }

}
