#ifndef _M470_DRIVER_H
#define _M470_DRIVER_H

#include <string> 
using namespace std;

#include <OctaveDriver.h>

namespace Alo
{
  class M470Driver : public OctaveDriver
  {
  public:
    M470Driver();
    ~M470Driver();

    virtual const string& getMakerProduct() const;

  private:
    string m_makerProduct;
  };

}

#endif
