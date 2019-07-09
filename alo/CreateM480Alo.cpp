#include "M480Alo.h"

using namespace Alo;

shared_ptr<OctaveAlo>
createAlo()
{
  return shared_ptr<OctaveAlo> (new M480Alo());

}
