

#include "M480Driver.h"

namespace Alo
{
  //

  M480Driver::M480Driver() : 
    OctaveDriver(),
    m_makerProduct("m27480-elf")
  {

  }

  M480Driver::~M480Driver()
  {}

  const std::string& 
  M480Driver::getMakerProduct() const
  {
    return m_makerProduct;
  }

}
