#ifndef _M480_DRIVER_H
#define _M480_DRIVER_H

#include <string> 
using namespace std;

#include <OctaveDriver.h>

namespace Alo
{
  class M480Driver : public OctaveDriver
  {
  public:
    M480Driver();
    ~M480Driver();

    virtual const string& getMakerProduct() const;

  private:
    string m_makerProduct;
  };

}

#endif
