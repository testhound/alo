#include <iostream>
using namespace std;

#include <typeinfo>
#include <cassert>

#include <LlirVisitor.h>
#include <LlirException.h>

#include "OctaveOperand.h"
#include "OctaveVisitor.h"

namespace Llir
{
  // OctaveFlag

  OctaveFlag::OctaveFlag() : LlirOperand()
  {}

  OctaveFlag::OctaveFlag(const OctaveFlag &rhs) : LlirOperand(rhs)
  {}

  OctaveFlag &
  OctaveFlag::operator=(const OctaveFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    LlirOperand::operator=(rhs);
    return *this;
  }

  // ModFlag

  ModFlag::ModFlag() : OctaveFlag()
  {}

  ModFlag::ModFlag(const ModFlag &rhs) : OctaveFlag(rhs)
  {}

  ModFlag &
  ModFlag::operator=(const ModFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  bool
  ModFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }






// Mod2Flag

  Mod2Flag::Mod2Flag() : ModFlag()
  {}

  Mod2Flag::Mod2Flag(const Mod2Flag &rhs) : ModFlag(rhs)
  {}

  Mod2Flag &
  Mod2Flag::operator=(const Mod2Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod2Flag::getModuloWidth() const
  {
    return ModFlag::MOD2;
  }

  void
  Mod2Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod4Flag

  Mod4Flag::Mod4Flag() : ModFlag()
  {}

  Mod4Flag::Mod4Flag(const Mod4Flag &rhs) : ModFlag(rhs)
  {}

  Mod4Flag &
  Mod4Flag::operator=(const Mod4Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod4Flag::getModuloWidth() const
  {
    return ModFlag::MOD4;
  }


  void
  Mod4Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod8Flag

  Mod8Flag::Mod8Flag() : ModFlag()
  {}

  Mod8Flag::Mod8Flag(const Mod8Flag &rhs) : ModFlag(rhs)
  {}

  Mod8Flag &
  Mod8Flag::operator=(const Mod8Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod8Flag::getModuloWidth() const
  {
    return ModFlag::MOD8;
  }


  void
  Mod8Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod16Flag

  Mod16Flag::Mod16Flag() : ModFlag()
  {}

  Mod16Flag::Mod16Flag(const Mod16Flag &rhs) : ModFlag(rhs)
  {}

  Mod16Flag &
  Mod16Flag::operator=(const Mod16Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod16Flag::getModuloWidth() const
  {
    return ModFlag::MOD16;
  }


  void
  Mod16Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod32Flag

  Mod32Flag::Mod32Flag() : ModFlag()
  {}

  Mod32Flag::Mod32Flag(const Mod32Flag &rhs) : ModFlag(rhs)
  {}

  ModFlag::ModuloWidth 
  Mod32Flag::getModuloWidth() const
  {
    return ModFlag::MOD32;
  }


  Mod32Flag &
  Mod32Flag::operator=(const Mod32Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  void
  Mod32Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod64Flag

  Mod64Flag::Mod64Flag() : ModFlag()
  {}

  Mod64Flag::Mod64Flag(const Mod64Flag &rhs) : ModFlag(rhs)
  {}

  Mod64Flag &
  Mod64Flag::operator=(const Mod64Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod64Flag::getModuloWidth() const
  {
    return ModFlag::MOD64;
  }


  void
  Mod64Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod128Flag

  Mod128Flag::Mod128Flag() : ModFlag()
  {}

  Mod128Flag::Mod128Flag(const Mod128Flag &rhs) : ModFlag(rhs)
  {}

  Mod128Flag &
  Mod128Flag::operator=(const Mod128Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod128Flag::getModuloWidth() const
  {
    return ModFlag::MOD128;
  }


  void
  Mod128Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod256Flag

  Mod256Flag::Mod256Flag() : ModFlag()
  {}

  Mod256Flag::Mod256Flag(const Mod256Flag &rhs) : ModFlag(rhs)
  {}

  Mod256Flag &
  Mod256Flag::operator=(const Mod256Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod256Flag::getModuloWidth() const
  {
    return ModFlag::MOD256;
  }


  void
  Mod256Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod512Flag

  Mod512Flag::Mod512Flag() : ModFlag()
  {}

  Mod512Flag::Mod512Flag(const Mod512Flag &rhs) : ModFlag(rhs)
  {}

  Mod512Flag &
  Mod512Flag::operator=(const Mod512Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod512Flag::getModuloWidth() const
  {
    return ModFlag::MOD512;
  }


  void
  Mod512Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod1KFlag

  Mod1KFlag::Mod1KFlag() : ModFlag()
  {}

  Mod1KFlag::Mod1KFlag(const Mod1KFlag &rhs) : ModFlag(rhs)
  {}

  Mod1KFlag &
  Mod1KFlag::operator=(const Mod1KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod1KFlag::getModuloWidth() const
  {
    return ModFlag::MOD1K;
  }


  void
  Mod1KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod2KFlag

  Mod2KFlag::Mod2KFlag() : ModFlag()
  {}

  Mod2KFlag::Mod2KFlag(const Mod2KFlag &rhs) : ModFlag(rhs)
  {}

  Mod2KFlag &
  Mod2KFlag::operator=(const Mod2KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod2KFlag::getModuloWidth() const
  {
    return ModFlag::MOD2K;
  }



  void
  Mod2KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod4KFlag

  Mod4KFlag::Mod4KFlag() : ModFlag()
  {}

  Mod4KFlag::Mod4KFlag(const Mod4KFlag &rhs) : ModFlag(rhs)
  {}

  Mod4KFlag &
  Mod4KFlag::operator=(const Mod4KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod4KFlag::getModuloWidth() const
  {
    return ModFlag::MOD4K;
  }


  void
  Mod4KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod8KFlag

  Mod8KFlag::Mod8KFlag() : ModFlag()
  {}

  Mod8KFlag::Mod8KFlag(const Mod8KFlag &rhs) : ModFlag(rhs)
  {}

  Mod8KFlag &
  Mod8KFlag::operator=(const Mod8KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod8KFlag::getModuloWidth() const
  {
    return ModFlag::MOD8K;
  }



  void
  Mod8KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod16KFlag

  Mod16KFlag::Mod16KFlag() : ModFlag()
  {}

  Mod16KFlag::Mod16KFlag(const Mod16KFlag &rhs) : ModFlag(rhs)
  {}

  Mod16KFlag &
  Mod16KFlag::operator=(const Mod16KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod16KFlag::getModuloWidth() const
  {
    return ModFlag::MOD16K;
  }



  void
  Mod16KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod32KFlag

  Mod32KFlag::Mod32KFlag() : ModFlag()
  {}

  Mod32KFlag::Mod32KFlag(const Mod32KFlag &rhs) : ModFlag(rhs)
  {}

  Mod32KFlag &
  Mod32KFlag::operator=(const Mod32KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod32KFlag::getModuloWidth() const
  {
    return ModFlag::MOD32K;
  }



  void
  Mod32KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod64KFlag

  Mod64KFlag::Mod64KFlag() : ModFlag()
  {}

  Mod64KFlag::Mod64KFlag(const Mod64KFlag &rhs) : ModFlag(rhs)
  {}

  Mod64KFlag &
  Mod64KFlag::operator=(const Mod64KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod64KFlag::getModuloWidth() const
  {
    return ModFlag::MOD64K;
  }



  void
  Mod64KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod128KFlag

  Mod128KFlag::Mod128KFlag() : ModFlag()
  {}

  Mod128KFlag::Mod128KFlag(const Mod128KFlag &rhs) : ModFlag(rhs)
  {}

  Mod128KFlag &
  Mod128KFlag::operator=(const Mod128KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod128KFlag::getModuloWidth() const
  {
    return ModFlag::MOD128K;
  }



  void
  Mod128KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod256KFlag

  Mod256KFlag::Mod256KFlag() : ModFlag()
  {}

  Mod256KFlag::Mod256KFlag(const Mod256KFlag &rhs) : ModFlag(rhs)
  {}

  Mod256KFlag &
  Mod256KFlag::operator=(const Mod256KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod256KFlag::getModuloWidth() const
  {
    return ModFlag::MOD256K;
  }



  void
  Mod256KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod512KFlag

  Mod512KFlag::Mod512KFlag() : ModFlag()
  {}

  Mod512KFlag::Mod512KFlag(const Mod512KFlag &rhs) : ModFlag(rhs)
  {}

  Mod512KFlag &
  Mod512KFlag::operator=(const Mod512KFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod512KFlag::getModuloWidth() const
  {
    return ModFlag::MOD512K;
  }



  void
  Mod512KFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod1MFlag

  Mod1MFlag::Mod1MFlag() : ModFlag()
  {}

  Mod1MFlag::Mod1MFlag(const Mod1MFlag &rhs) : ModFlag(rhs)
  {}

  Mod1MFlag &
  Mod1MFlag::operator=(const Mod1MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod1MFlag::getModuloWidth() const
  {
    return ModFlag::MOD1M;
  }



  void
  Mod1MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod2MFlag

  Mod2MFlag::Mod2MFlag() : ModFlag()
  {}

  Mod2MFlag::Mod2MFlag(const Mod2MFlag &rhs) : ModFlag(rhs)
  {}

  Mod2MFlag &
  Mod2MFlag::operator=(const Mod2MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod2MFlag::getModuloWidth() const
  {
    return ModFlag::MOD2M;
  }



  void
  Mod2MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod4MFlag

  Mod4MFlag::Mod4MFlag() : ModFlag()
  {}

  Mod4MFlag::Mod4MFlag(const Mod4MFlag &rhs) : ModFlag(rhs)
  {}

  Mod4MFlag &
  Mod4MFlag::operator=(const Mod4MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod4MFlag::getModuloWidth() const
  {
    return ModFlag::MOD4M;
  }




  void
  Mod4MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod8MFlag

  Mod8MFlag::Mod8MFlag() : ModFlag()
  {}

  Mod8MFlag::Mod8MFlag(const Mod8MFlag &rhs) : ModFlag(rhs)
  {}

  Mod8MFlag &
  Mod8MFlag::operator=(const Mod8MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod8MFlag::getModuloWidth() const
  {
    return ModFlag::MOD8M;
  }



  void
  Mod8MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod16MFlag

  Mod16MFlag::Mod16MFlag() : ModFlag()
  {}

  Mod16MFlag::Mod16MFlag(const Mod16MFlag &rhs) : ModFlag(rhs)
  {}

  Mod16MFlag &
  Mod16MFlag::operator=(const Mod16MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod16MFlag::getModuloWidth() const
  {
    return ModFlag::MOD16M;
  }



  void
  Mod16MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod32MFlag

  Mod32MFlag::Mod32MFlag() : ModFlag()
  {}

  Mod32MFlag::Mod32MFlag(const Mod32MFlag &rhs) : ModFlag(rhs)
  {}

  Mod32MFlag &
  Mod32MFlag::operator=(const Mod32MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }


  ModFlag::ModuloWidth 
  Mod32MFlag::getModuloWidth() const
  {
    return ModFlag::MOD32M;
  }


  void
  Mod32MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod64MFlag

  Mod64MFlag::Mod64MFlag() : ModFlag()
  {}

  Mod64MFlag::Mod64MFlag(const Mod64MFlag &rhs) : ModFlag(rhs)
  {}

  Mod64MFlag &
  Mod64MFlag::operator=(const Mod64MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod64MFlag::getModuloWidth() const
  {
    return ModFlag::MOD64M;
  }


  void
  Mod64MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod128MFlag

  Mod128MFlag::Mod128MFlag() : ModFlag()
  {}

  Mod128MFlag::Mod128MFlag(const Mod128MFlag &rhs) : ModFlag(rhs)
  {}

  Mod128MFlag &
  Mod128MFlag::operator=(const Mod128MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod128MFlag::getModuloWidth() const
  {
    return ModFlag::MOD128M;
  }


  void
  Mod128MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod256MFlag

  Mod256MFlag::Mod256MFlag() : ModFlag()
  {}

  Mod256MFlag::Mod256MFlag(const Mod256MFlag &rhs) : ModFlag(rhs)
  {}

  Mod256MFlag &
  Mod256MFlag::operator=(const Mod256MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod256MFlag::getModuloWidth() const
  {
    return ModFlag::MOD256M;
  }


  void
  Mod256MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod512MFlag

  Mod512MFlag::Mod512MFlag() : ModFlag()
  {}

  Mod512MFlag::Mod512MFlag(const Mod512MFlag &rhs) : ModFlag(rhs)
  {}

  Mod512MFlag &
  Mod512MFlag::operator=(const Mod512MFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod512MFlag::getModuloWidth() const
  {
    return ModFlag::MOD512M;
  }


  void
  Mod512MFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod1GFlag

  Mod1GFlag::Mod1GFlag() : ModFlag()
  {}

  Mod1GFlag::Mod1GFlag(const Mod1GFlag &rhs) : ModFlag(rhs)
  {}

  Mod1GFlag &
  Mod1GFlag::operator=(const Mod1GFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod1GFlag::getModuloWidth() const
  {
    return ModFlag::MOD1G;
  }


  void
  Mod1GFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

// Mod2GFlag

  Mod2GFlag::Mod2GFlag() : ModFlag()
  {}

  Mod2GFlag::Mod2GFlag(const Mod2GFlag &rhs) : ModFlag(rhs)
  {}

  Mod2GFlag &
  Mod2GFlag::operator=(const Mod2GFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    ModFlag::operator=(rhs);
    return *this;
  }

  ModFlag::ModuloWidth 
  Mod2GFlag::getModuloWidth() const
  {
    return ModFlag::MOD2G;
  }


  void
  Mod2GFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }





  // AbcFlag

  AbcFlag::AbcFlag() : OctaveFlag()
  {}

  AbcFlag::AbcFlag(const AbcFlag &rhs) : OctaveFlag(rhs)
  {}

  AbcFlag &
  AbcFlag::operator=(const AbcFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  // AbcGenericFlag

  AbcGenericFlag::AbcGenericFlag() : AbcFlag()
  {}

  AbcGenericFlag::AbcGenericFlag(const AbcGenericFlag &rhs) : AbcFlag(rhs)
  {}

  AbcGenericFlag &
  AbcGenericFlag::operator=(const AbcGenericFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcFlag::operator=(rhs);
    return *this;
  }

  bool
  AbcGenericFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // AbcCompareFlag

  AbcCompareFlag::AbcCompareFlag() : AbcFlag()
  {}

  AbcCompareFlag::AbcCompareFlag(const AbcCompareFlag &rhs) : AbcFlag(rhs)
  {}

  AbcCompareFlag &
  AbcCompareFlag::operator=(const AbcCompareFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcFlag::operator=(rhs);
    return *this;
  }

  bool
  AbcCompareFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }


  // BZFlag

  BZFlag::BZFlag() : AbcGenericFlag()
  {}

  BZFlag::BZFlag(const BZFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BZFlag &
  BZFlag::operator=(const BZFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BZFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BNCFlag

  BNCFlag::BNCFlag() : AbcGenericFlag()
  {}

  BNCFlag::BNCFlag(const BNCFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BNCFlag &
  BNCFlag::operator=(const BNCFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BNCFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BNOFlag

  BNOFlag::BNOFlag() : AbcGenericFlag()
  {}

  BNOFlag::BNOFlag(const BNOFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BNOFlag &
  BNOFlag::operator=(const BNOFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BNOFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BGEZFlag

  BGEZFlag::BGEZFlag() : AbcGenericFlag()
  {}

  BGEZFlag::BGEZFlag(const BGEZFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BGEZFlag &
  BGEZFlag::operator=(const BGEZFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BGEZFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BLZFlag

  BLZFlag::BLZFlag() : AbcGenericFlag()
  {}

  BLZFlag::BLZFlag(const BLZFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BLZFlag &
  BLZFlag::operator=(const BLZFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BLZFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BNZFlag

  BNZFlag::BNZFlag() : AbcGenericFlag()
  {}

  BNZFlag::BNZFlag(const BNZFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BNZFlag &
  BNZFlag::operator=(const BNZFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BNZFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BLEZFlag

  BLEZFlag::BLEZFlag() : AbcGenericFlag()
  {}

  BLEZFlag::BLEZFlag(const BLEZFlag &rhs) : AbcGenericFlag(rhs)
  {}

  BLEZFlag &
  BLEZFlag::operator=(const BLEZFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcGenericFlag::operator=(rhs);
    return *this;
  }

  void
  BLEZFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BAGBFlag

  BAGBFlag::BAGBFlag() : AbcCompareFlag()
  {}

  BAGBFlag::BAGBFlag(const BAGBFlag &rhs) : AbcCompareFlag(rhs)
  {}

  BAGBFlag &
  BAGBFlag::operator=(const BAGBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcCompareFlag::operator=(rhs);
    return *this;
  }

  AbcCompareFlag::Abc_Compare_t
  BAGBFlag::getABCFlagType() const
  {
    return BAGB;
  }

  void
  BAGBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BAEBFlag

  BAEBFlag::BAEBFlag() : AbcCompareFlag()
  {}

  BAEBFlag::BAEBFlag(const BAEBFlag &rhs) : AbcCompareFlag(rhs)
  {}


  AbcCompareFlag::Abc_Compare_t
  BAEBFlag::getABCFlagType() const
  {
    return BAEB;
  }

  BAEBFlag &
  BAEBFlag::operator=(const BAEBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcCompareFlag::operator=(rhs);
    return *this;
  }



  void
  BAEBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BALBFlag

  BALBFlag::BALBFlag() : AbcCompareFlag()
  {}

  BALBFlag::BALBFlag(const BALBFlag &rhs) : AbcCompareFlag(rhs)
  {}


  AbcCompareFlag::Abc_Compare_t
  BALBFlag::getABCFlagType() const
  {
    return BALB;
  }


  BALBFlag &
  BALBFlag::operator=(const BALBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcCompareFlag::operator=(rhs);
    return *this;
  }

  void
  BALBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BANEBFlag

  BANEBFlag::BANEBFlag() : AbcCompareFlag()
  {}

  BANEBFlag::BANEBFlag(const BANEBFlag &rhs) : AbcCompareFlag(rhs)
  {}


  AbcCompareFlag::Abc_Compare_t
  BANEBFlag::getABCFlagType() const
  {
    return BANEB;
  }


  BANEBFlag &
  BANEBFlag::operator=(const BANEBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcCompareFlag::operator=(rhs);
    return *this;
  }

  void
  BANEBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BAGEBFlag

  BAGEBFlag::BAGEBFlag() : AbcCompareFlag()
  {}

  BAGEBFlag::BAGEBFlag(const BAGEBFlag &rhs) : AbcCompareFlag(rhs)
  {}


  AbcCompareFlag::Abc_Compare_t
  BAGEBFlag::getABCFlagType() const
  {
    return BAGEB;
  }


  BAGEBFlag &
  BAGEBFlag::operator=(const BAGEBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcCompareFlag::operator=(rhs);
    return *this;
  }

  void
  BAGEBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BALEBFlag

  BALEBFlag::BALEBFlag() : AbcCompareFlag()
  {}

  BALEBFlag::BALEBFlag(const BALEBFlag &rhs) : AbcCompareFlag(rhs)
  {}


  AbcCompareFlag::Abc_Compare_t
  BALEBFlag::getABCFlagType() const
  {
    return BALEB;
  }


  BALEBFlag &
  BALEBFlag::operator=(const BALEBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    AbcCompareFlag::operator=(rhs);
    return *this;
  }

  void
  BALEBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // EssFlag

  EssFlag::EssFlag(bool negate) : OctaveFlag(), m_negate(negate)
  {}

  EssFlag::EssFlag(const EssFlag &rhs) : OctaveFlag(rhs), m_negate(rhs.m_negate)
  {}

  EssFlag &
  EssFlag::operator=(const EssFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    m_negate = rhs.m_negate;
    return *this;
  }

  bool
  EssFlag::isNegated() const
  {
    return m_negate;
  }

  bool
  EssFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }



  // Ess0Flag

  Ess0Flag::Ess0Flag(bool negate) : EssFlag(negate)
  {}

  Ess0Flag::Ess0Flag(const Ess0Flag &rhs) : EssFlag(rhs)
  {}

  Ess0Flag &
  Ess0Flag::operator=(const Ess0Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }

  EssFlag::ESS_Flag_t 
  Ess0Flag::getFlagNum() const
  {
    return EssFlag::ESS0;
  }

  void
  Ess0Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess1Flag

  Ess1Flag::Ess1Flag(bool negate) : EssFlag(negate)
  {}

  Ess1Flag::Ess1Flag(const Ess1Flag &rhs) : EssFlag(rhs)
  {}

  Ess1Flag &
  Ess1Flag::operator=(const Ess1Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess1Flag::getFlagNum() const
  {
    return EssFlag::ESS1;
  }

  void
  Ess1Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess2Flag

  Ess2Flag::Ess2Flag(bool negate) : EssFlag(negate)
  {}

  Ess2Flag::Ess2Flag(const Ess2Flag &rhs) : EssFlag(rhs)
  {}

  Ess2Flag &
  Ess2Flag::operator=(const Ess2Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess2Flag::getFlagNum() const
  {
    return EssFlag::ESS2;
  }


  void
  Ess2Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess3Flag

  Ess3Flag::Ess3Flag(bool negate) : EssFlag(negate)
  {}

  Ess3Flag::Ess3Flag(const Ess3Flag &rhs) : EssFlag(rhs)
  {}

  Ess3Flag &
  Ess3Flag::operator=(const Ess3Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess3Flag::getFlagNum() const
  {
    return EssFlag::ESS3;
  }

  void
  Ess3Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess4Flag

  Ess4Flag::Ess4Flag(bool negate) : EssFlag(negate)
  {}

  Ess4Flag::Ess4Flag(const Ess4Flag &rhs) : EssFlag(rhs)
  {}

  Ess4Flag &
  Ess4Flag::operator=(const Ess4Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }



  EssFlag::ESS_Flag_t 
  Ess4Flag::getFlagNum() const
  {
    return EssFlag::ESS4;
  }


  void
  Ess4Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess5Flag

  Ess5Flag::Ess5Flag(bool negate) : EssFlag(negate)
  {}

  Ess5Flag::Ess5Flag(const Ess5Flag &rhs) : EssFlag(rhs)
  {}

  Ess5Flag &
  Ess5Flag::operator=(const Ess5Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess5Flag::getFlagNum() const
  {
    return EssFlag::ESS5;
  }


  void
  Ess5Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess6Flag

  Ess6Flag::Ess6Flag(bool negate) : EssFlag(negate)
  {}

  Ess6Flag::Ess6Flag(const Ess6Flag &rhs) : EssFlag(rhs)
  {}

  Ess6Flag &
  Ess6Flag::operator=(const Ess6Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess6Flag::getFlagNum() const
  {
    return EssFlag::ESS6;
  }


  void
  Ess6Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess7Flag

  Ess7Flag::Ess7Flag(bool negate) : EssFlag(negate)
  {}

  Ess7Flag::Ess7Flag(const Ess7Flag &rhs) : EssFlag(rhs)
  {}

  Ess7Flag &
  Ess7Flag::operator=(const Ess7Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }



  EssFlag::ESS_Flag_t 
  Ess7Flag::getFlagNum() const
  {
    return EssFlag::ESS7;
  }


  void
  Ess7Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess8Flag

  Ess8Flag::Ess8Flag(bool negate) : EssFlag(negate)
  {}

  Ess8Flag::Ess8Flag(const Ess8Flag &rhs) : EssFlag(rhs)
  {}

  Ess8Flag &
  Ess8Flag::operator=(const Ess8Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess8Flag::getFlagNum() const
  {
    return EssFlag::ESS8;
  }


  void
  Ess8Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess9Flag

  Ess9Flag::Ess9Flag(bool negate) : EssFlag(negate)
  {}

  Ess9Flag::Ess9Flag(const Ess9Flag &rhs) : EssFlag(rhs)
  {}

  Ess9Flag &
  Ess9Flag::operator=(const Ess9Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess9Flag::getFlagNum() const
  {
    return EssFlag::ESS9;
  }


  void
  Ess9Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess10Flag

  Ess10Flag::Ess10Flag(bool negate) : EssFlag(negate)
  {}

  Ess10Flag::Ess10Flag(const Ess10Flag &rhs) : EssFlag(rhs)
  {}

  Ess10Flag &
  Ess10Flag::operator=(const Ess10Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess10Flag::getFlagNum() const
  {
    return EssFlag::ESS10;
  }


  void
  Ess10Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // Ess11Flag

  Ess11Flag::Ess11Flag(bool negate) : EssFlag(negate)
  {}

  Ess11Flag::Ess11Flag(const Ess11Flag &rhs) : EssFlag(rhs)
  {}

  Ess11Flag &
  Ess11Flag::operator=(const Ess11Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess11Flag::getFlagNum() const
  {
    return EssFlag::ESS11;
  }


  void
  Ess11Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess12Flag

  Ess12Flag::Ess12Flag(bool negate) : EssFlag(negate)
  {}

  Ess12Flag::Ess12Flag(const Ess12Flag &rhs) : EssFlag(rhs)
  {}

  Ess12Flag &
  Ess12Flag::operator=(const Ess12Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess12Flag::getFlagNum() const
  {
    return EssFlag::ESS12;
  }


  void
  Ess12Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess13Flag

  Ess13Flag::Ess13Flag(bool negate) : EssFlag(negate)
  {}

  Ess13Flag::Ess13Flag(const Ess13Flag &rhs) : EssFlag(rhs)
  {}

  Ess13Flag &
  Ess13Flag::operator=(const Ess13Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess13Flag::getFlagNum() const
  {
    return EssFlag::ESS13;
  }


  void
  Ess13Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess14Flag

  Ess14Flag::Ess14Flag(bool negate) : EssFlag(negate)
  {}

  Ess14Flag::Ess14Flag(const Ess14Flag &rhs) : EssFlag(rhs)
  {}

  Ess14Flag &
  Ess14Flag::operator=(const Ess14Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess14Flag::getFlagNum() const
  {
    return EssFlag::ESS14;
  }


  void
  Ess14Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess15Flag

  Ess15Flag::Ess15Flag(bool negate) : EssFlag(negate)
  {}

  Ess15Flag::Ess15Flag(const Ess15Flag &rhs) : EssFlag(rhs)
  {}

  Ess15Flag &
  Ess15Flag::operator=(const Ess15Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }



  EssFlag::ESS_Flag_t 
  Ess15Flag::getFlagNum() const
  {
    return EssFlag::ESS15;
  }


  void
  Ess15Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess16Flag

  Ess16Flag::Ess16Flag(bool negate) : EssFlag(negate)
  {}

  Ess16Flag::Ess16Flag(const Ess16Flag &rhs) : EssFlag(rhs)
  {}

  Ess16Flag &
  Ess16Flag::operator=(const Ess16Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess16Flag::getFlagNum() const
  {
    return EssFlag::ESS16;
  }


  void
  Ess16Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess17Flag

  Ess17Flag::Ess17Flag(bool negate) : EssFlag(negate)
  {}

  Ess17Flag::Ess17Flag(const Ess17Flag &rhs) : EssFlag(rhs)
  {}

  Ess17Flag &
  Ess17Flag::operator=(const Ess17Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess17Flag::getFlagNum() const
  {
    return EssFlag::ESS17;
  }


  void
  Ess17Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess18Flag

  Ess18Flag::Ess18Flag(bool negate) : EssFlag(negate)
  {}

  Ess18Flag::Ess18Flag(const Ess18Flag &rhs) : EssFlag(rhs)
  {}

  Ess18Flag &
  Ess18Flag::operator=(const Ess18Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess18Flag::getFlagNum() const
  {
    return EssFlag::ESS18;
  }


  void
  Ess18Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess19Flag

  Ess19Flag::Ess19Flag(bool negate) : EssFlag(negate)
  {}

  Ess19Flag::Ess19Flag(const Ess19Flag &rhs) : EssFlag(rhs)
  {}

  Ess19Flag &
  Ess19Flag::operator=(const Ess19Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess19Flag::getFlagNum() const
  {
    return EssFlag::ESS19;
  }


  void
  Ess19Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess20Flag

  Ess20Flag::Ess20Flag(bool negate) : EssFlag(negate)
  {}

  Ess20Flag::Ess20Flag(const Ess20Flag &rhs) : EssFlag(rhs)
  {}

  Ess20Flag &
  Ess20Flag::operator=(const Ess20Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess20Flag::getFlagNum() const
  {
    return EssFlag::ESS20;
  }


  void
  Ess20Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess21Flag

  Ess21Flag::Ess21Flag(bool negate) : EssFlag(negate)
  {}

  Ess21Flag::Ess21Flag(const Ess21Flag &rhs) : EssFlag(rhs)
  {}

  Ess21Flag &
  Ess21Flag::operator=(const Ess21Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess21Flag::getFlagNum() const
  {
    return EssFlag::ESS21;
  }


  void
  Ess21Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess22Flag

  Ess22Flag::Ess22Flag(bool negate) : EssFlag(negate)
  {}

  Ess22Flag::Ess22Flag(const Ess22Flag &rhs) : EssFlag(rhs)
  {}

  Ess22Flag &
  Ess22Flag::operator=(const Ess22Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess22Flag::getFlagNum() const
  {
    return EssFlag::ESS22;
  }


  void
  Ess22Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess23Flag

  Ess23Flag::Ess23Flag(bool negate) : EssFlag(negate)
  {}

  Ess23Flag::Ess23Flag(const Ess23Flag &rhs) : EssFlag(rhs)
  {}

  Ess23Flag &
  Ess23Flag::operator=(const Ess23Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess23Flag::getFlagNum() const
  {
    return EssFlag::ESS23;
  }

  void
  Ess23Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess24Flag

  Ess24Flag::Ess24Flag(bool negate) : EssFlag(negate)
  {}

  Ess24Flag::Ess24Flag(const Ess24Flag &rhs) : EssFlag(rhs)
  {}

  Ess24Flag &
  Ess24Flag::operator=(const Ess24Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess24Flag::getFlagNum() const
  {
    return EssFlag::ESS24;
  }


  void
  Ess24Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess25Flag

  Ess25Flag::Ess25Flag(bool negate) : EssFlag(negate)
  {}

  Ess25Flag::Ess25Flag(const Ess25Flag &rhs) : EssFlag(rhs)
  {}

  Ess25Flag &
  Ess25Flag::operator=(const Ess25Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }



  EssFlag::ESS_Flag_t 
  Ess25Flag::getFlagNum() const
  {
    return EssFlag::ESS25;
  }


  void
  Ess25Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess26Flag

  Ess26Flag::Ess26Flag(bool negate) : EssFlag(negate)
  {}

  Ess26Flag::Ess26Flag(const Ess26Flag &rhs) : EssFlag(rhs)
  {}

  Ess26Flag &
  Ess26Flag::operator=(const Ess26Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess26Flag::getFlagNum() const
  {
    return EssFlag::ESS26;
  }


  void
  Ess26Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess27Flag

  Ess27Flag::Ess27Flag(bool negate) : EssFlag(negate)
  {}

  Ess27Flag::Ess27Flag(const Ess27Flag &rhs) : EssFlag(rhs)
  {}

  Ess27Flag &
  Ess27Flag::operator=(const Ess27Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess27Flag::getFlagNum() const
  {
    return EssFlag::ESS27;
  }


  void
  Ess27Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess28Flag

  Ess28Flag::Ess28Flag(bool negate) : EssFlag(negate)
  {}

  Ess28Flag::Ess28Flag(const Ess28Flag &rhs) : EssFlag(rhs)
  {}

  Ess28Flag &
  Ess28Flag::operator=(const Ess28Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess28Flag::getFlagNum() const
  {
    return EssFlag::ESS28;
  }


  void
  Ess28Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess29Flag

  Ess29Flag::Ess29Flag(bool negate) : EssFlag(negate)
  {}

  Ess29Flag::Ess29Flag(const Ess29Flag &rhs) : EssFlag(rhs)
  {}

  Ess29Flag &
  Ess29Flag::operator=(const Ess29Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess29Flag::getFlagNum() const
  {
    return EssFlag::ESS29;
  }


  void
  Ess29Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess30Flag

  Ess30Flag::Ess30Flag(bool negate) : EssFlag(negate)
  {}

  Ess30Flag::Ess30Flag(const Ess30Flag &rhs) : EssFlag(rhs)
  {}

  Ess30Flag &
  Ess30Flag::operator=(const Ess30Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess30Flag::getFlagNum() const
  {
    return EssFlag::ESS30;
  }

  void
  Ess30Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // Ess31Flag

  Ess31Flag::Ess31Flag(bool negate) : EssFlag(negate)
  {}

  Ess31Flag::Ess31Flag(const Ess31Flag &rhs) : EssFlag(rhs)
  {}

  Ess31Flag &
  Ess31Flag::operator=(const Ess31Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    EssFlag::operator=(rhs);
    return *this;
  }


  EssFlag::ESS_Flag_t 
  Ess31Flag::getFlagNum() const
  {
    return EssFlag::ESS31;
  }


  void
  Ess31Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // MvhFlag

  MvhFlag::MvhFlag() : OctaveFlag()
  {}

  MvhFlag::MvhFlag(const MvhFlag &rhs) : OctaveFlag(rhs)
  {}

  MvhFlag &
  MvhFlag::operator=(const MvhFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  bool
  MvhFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }



  // C0Flag

  C0Flag::C0Flag() : MvhFlag()
  {}

  C0Flag::C0Flag(const C0Flag &rhs) : MvhFlag(rhs)
  {}

  C0Flag &
  C0Flag::operator=(const C0Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }

  MvhFlag::CN_Flag
  C0Flag::getCNValue() const
  {
    return C0;
  }

  void
  C0Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C1Flag

  C1Flag::C1Flag() : MvhFlag()
  {}

  C1Flag::C1Flag(const C1Flag &rhs) : MvhFlag(rhs)
  {}

  C1Flag &
  C1Flag::operator=(const C1Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }

  MvhFlag::CN_Flag
  C1Flag::getCNValue() const
  {
    return C1;
  }

  void
  C1Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C2Flag

  C2Flag::C2Flag() : MvhFlag()
  {}

  C2Flag::C2Flag(const C2Flag &rhs) : MvhFlag(rhs)
  {}

  C2Flag &
  C2Flag::operator=(const C2Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C2Flag::getCNValue() const
  {
    return C2;
  }

  void
  C2Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C3Flag

  C3Flag::C3Flag() : MvhFlag()
  {}

  C3Flag::C3Flag(const C3Flag &rhs) : MvhFlag(rhs)
  {}

  C3Flag &
  C3Flag::operator=(const C3Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C3Flag::getCNValue() const
  {
    return C3;
  }


  void
  C3Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C4Flag

  C4Flag::C4Flag() : MvhFlag()
  {}

  C4Flag::C4Flag(const C4Flag &rhs) : MvhFlag(rhs)
  {}

  C4Flag &
  C4Flag::operator=(const C4Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C4Flag::getCNValue() const
  {
    return C4;
  }


  void
  C4Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C5Flag

  C5Flag::C5Flag() : MvhFlag()
  {}

  C5Flag::C5Flag(const C5Flag &rhs) : MvhFlag(rhs)
  {}

  C5Flag &
  C5Flag::operator=(const C5Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C5Flag::getCNValue() const
  {
    return C5;
  }


  void
  C5Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C6Flag

  C6Flag::C6Flag() : MvhFlag()
  {}

  C6Flag::C6Flag(const C6Flag &rhs) : MvhFlag(rhs)
  {}

  C6Flag &
  C6Flag::operator=(const C6Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C6Flag::getCNValue() const
  {
    return C6;
  }


  void
  C6Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C7Flag

  C7Flag::C7Flag() : MvhFlag()
  {}

  C7Flag::C7Flag(const C7Flag &rhs) : MvhFlag(rhs)
  {}

  C7Flag &
  C7Flag::operator=(const C7Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C7Flag::getCNValue() const
  {
    return C7;
  }


  void
  C7Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C8Flag

  C8Flag::C8Flag() : MvhFlag()
  {}

  C8Flag::C8Flag(const C8Flag &rhs) : MvhFlag(rhs)
  {}

  C8Flag &
  C8Flag::operator=(const C8Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C8Flag::getCNValue() const
  {
    return C8;
  }


  void
  C8Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C9Flag

  C9Flag::C9Flag() : MvhFlag()
  {}

  C9Flag::C9Flag(const C9Flag &rhs) : MvhFlag(rhs)
  {}

  C9Flag &
  C9Flag::operator=(const C9Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C9Flag::getCNValue() const
  {
    return C9;
  }


  void
  C9Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C10Flag

  C10Flag::C10Flag() : MvhFlag()
  {}

  C10Flag::C10Flag(const C10Flag &rhs) : MvhFlag(rhs)
  {}

  C10Flag &
  C10Flag::operator=(const C10Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C10Flag::getCNValue() const
  {
    return C10;
  }


  void
  C10Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C11Flag

  C11Flag::C11Flag() : MvhFlag()
  {}

  C11Flag::C11Flag(const C11Flag &rhs) : MvhFlag(rhs)
  {}

  C11Flag &
  C11Flag::operator=(const C11Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C11Flag::getCNValue() const
  {
    return C11;
  }


  void
  C11Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C12Flag

  C12Flag::C12Flag() : MvhFlag()
  {}

  C12Flag::C12Flag(const C12Flag &rhs) : MvhFlag(rhs)
  {}

  C12Flag &
  C12Flag::operator=(const C12Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C12Flag::getCNValue() const
  {
    return C12;
  }


  void
  C12Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C13Flag

  C13Flag::C13Flag() : MvhFlag()
  {}

  C13Flag::C13Flag(const C13Flag &rhs) : MvhFlag(rhs)
  {}

  C13Flag &
  C13Flag::operator=(const C13Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C13Flag::getCNValue() const
  {
    return C13;
  }


  void
  C13Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C14Flag

  C14Flag::C14Flag() : MvhFlag()
  {}

  C14Flag::C14Flag(const C14Flag &rhs) : MvhFlag(rhs)
  {}

  C14Flag &
  C14Flag::operator=(const C14Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C14Flag::getCNValue() const
  {
    return C14;
  }


  void
  C14Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // C15Flag

  C15Flag::C15Flag() : MvhFlag()
  {}

  C15Flag::C15Flag(const C15Flag &rhs) : MvhFlag(rhs)
  {}

  C15Flag &
  C15Flag::operator=(const C15Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    MvhFlag::operator=(rhs);
    return *this;
  }


  MvhFlag::CN_Flag
  C15Flag::getCNValue() const
  {
    return C15;
  }


  void
  C15Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // SXFlag

  SXFlag::SXFlag() : OctaveFlag()
  {}

  SXFlag::SXFlag(const SXFlag &rhs) : OctaveFlag(rhs)
  {}

  SXFlag &
  SXFlag::operator=(const SXFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  SXFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  SXFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }


  // FindFlag

  FindFlag::FindFlag() : OctaveFlag()
  {}

  FindFlag::FindFlag(const FindFlag &rhs) : OctaveFlag(rhs)
  {}

  FindFlag &
  FindFlag::operator=(const FindFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  FindFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  FindFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // CumeFlag

  CumeFlag::CumeFlag() : OctaveFlag()
  {}

  CumeFlag::CumeFlag(const CumeFlag &rhs) : OctaveFlag(rhs)
  {}

  CumeFlag &
  CumeFlag::operator=(const CumeFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  CumeFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  CumeFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // SignFlag

  SignFlag::SignFlag() : OctaveFlag()
  {}

  SignFlag::SignFlag(const SignFlag &rhs) : OctaveFlag(rhs)
  {}

  SignFlag &
  SignFlag::operator=(const SignFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  SignFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  SignFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // CDFlag

  CDFlag::CDFlag() : OctaveFlag()
  {}

  CDFlag::CDFlag(const CDFlag &rhs) : OctaveFlag(rhs)
  {}

  CDFlag &
  CDFlag::operator=(const CDFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  CDFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  CDFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // DepbFlag

  DepbFlag::DepbFlag() : OctaveFlag()
  {}

  DepbFlag::DepbFlag(const DepbFlag &rhs) : OctaveFlag(rhs)
  {}

  DepbFlag &
  DepbFlag::operator=(const DepbFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  DepbFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  DepbFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }


  // DIFlag

  DIFlag::DIFlag() : OctaveFlag()
  {}

  DIFlag::DIFlag(const DIFlag &rhs) : OctaveFlag(rhs)
  {}

  DIFlag &
  DIFlag::operator=(const DIFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  void
  DIFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  bool
  DIFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }


  // LinkFlag

  LinkFlag::LinkFlag() : OctaveFlag()
  {}

  LinkFlag::LinkFlag(const LinkFlag &rhs) : OctaveFlag(rhs)
  {}

  LinkFlag &
  LinkFlag::operator=(const LinkFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  bool
  LinkFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }


  // LNK1Flag

  LNK1Flag::LNK1Flag() : LinkFlag()
  {}

  LNK1Flag::LNK1Flag(const LNK1Flag &rhs) : LinkFlag(rhs)
  {}

  LNK1Flag &
  LNK1Flag::operator=(const LNK1Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    LinkFlag::operator=(rhs);
    return *this;
  }

  LinkFlag::Link_Flag_t 
  LNK1Flag::getLinkFlagType() const
  {
    return LNK1;
  }

  void
  LNK1Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // LNK2Flag

  LNK2Flag::LNK2Flag() : LinkFlag()
  {}

  LNK2Flag::LNK2Flag(const LNK2Flag &rhs) : LinkFlag(rhs)
  {}

  LNK2Flag &
  LNK2Flag::operator=(const LNK2Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    LinkFlag::operator=(rhs);
    return *this;
  }

  LinkFlag::Link_Flag_t 
  LNK2Flag::getLinkFlagType() const
  {
    return LNK2;
  }


  void
  LNK2Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // LNK3Flag

  LNK3Flag::LNK3Flag() : LinkFlag()
  {}

  LNK3Flag::LNK3Flag(const LNK3Flag &rhs) : LinkFlag(rhs)
  {}

  LNK3Flag &
  LNK3Flag::operator=(const LNK3Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    LinkFlag::operator=(rhs);
    return *this;
  }

  LinkFlag::Link_Flag_t 
  LNK3Flag::getLinkFlagType() const
  {
    return LNK3;
  }


  void
  LNK3Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // TSSFlag

  TSSFlag::TSSFlag() : OctaveFlag()
  {}

  TSSFlag::TSSFlag(const TSSFlag &rhs) : OctaveFlag(rhs)
  {}

  TSSFlag &
  TSSFlag::operator=(const TSSFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  bool
  TSSFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // GC1AFlag

  GC1AFlag::GC1AFlag() : TSSFlag()
  {}

  GC1AFlag::GC1AFlag(const GC1AFlag &rhs) : TSSFlag(rhs)
  {}

  GC1AFlag &
  GC1AFlag::operator=(const GC1AFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GC1AFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // GC1BFlag

  GC1BFlag::GC1BFlag() : TSSFlag()
  {}

  GC1BFlag::GC1BFlag(const GC1BFlag &rhs) : TSSFlag(rhs)
  {}

  GC1BFlag &
  GC1BFlag::operator=(const GC1BFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GC1BFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GC1OFlag

  GC1OFlag::GC1OFlag() : TSSFlag()
  {}

  GC1OFlag::GC1OFlag(const GC1OFlag &rhs) : TSSFlag(rhs)
  {}

  GC1OFlag &
  GC1OFlag::operator=(const GC1OFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GC1OFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GC2AFlag

  GC2AFlag::GC2AFlag() : TSSFlag()
  {}

  GC2AFlag::GC2AFlag(const GC2AFlag &rhs) : TSSFlag(rhs)
  {}

  GC2AFlag &
  GC2AFlag::operator=(const GC2AFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GC2AFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GC2BFlag

  GC2BFlag::GC2BFlag() : TSSFlag()
  {}

  GC2BFlag::GC2BFlag(const GC2BFlag &rhs) : TSSFlag(rhs)
  {}

  GC2BFlag &
  GC2BFlag::operator=(const GC2BFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GC2BFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GC2OFlag

  GC2OFlag::GC2OFlag() : TSSFlag()
  {}

  GC2OFlag::GC2OFlag(const GC2OFlag &rhs) : TSSFlag(rhs)
  {}

  GC2OFlag &
  GC2OFlag::operator=(const GC2OFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GC2OFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GPAFlag

  GPAFlag::GPAFlag() : TSSFlag()
  {}

  GPAFlag::GPAFlag(const GPAFlag &rhs) : TSSFlag(rhs)
  {}

  GPAFlag &
  GPAFlag::operator=(const GPAFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GPAFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GPUFlag

  GPUFlag::GPUFlag() : TSSFlag()
  {}

  GPUFlag::GPUFlag(const GPUFlag &rhs) : TSSFlag(rhs)
  {}

  GPUFlag &
  GPUFlag::operator=(const GPUFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GPUFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GPBFlag

  GPBFlag::GPBFlag() : TSSFlag()
  {}

  GPBFlag::GPBFlag(const GPBFlag &rhs) : TSSFlag(rhs)
  {}

  GPBFlag &
  GPBFlag::operator=(const GPBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GPBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GTAFlag

  GTAFlag::GTAFlag() : TSSFlag()
  {}

  GTAFlag::GTAFlag(const GTAFlag &rhs) : TSSFlag(rhs)
  {}

  GTAFlag &
  GTAFlag::operator=(const GTAFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GTAFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GTOFlag

  GTOFlag::GTOFlag() : TSSFlag()
  {}

  GTOFlag::GTOFlag(const GTOFlag &rhs) : TSSFlag(rhs)
  {}

  GTOFlag &
  GTOFlag::operator=(const GTOFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GTOFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GTBFlag

  GTBFlag::GTBFlag() : TSSFlag()
  {}

  GTBFlag::GTBFlag(const GTBFlag &rhs) : TSSFlag(rhs)
  {}

  GTBFlag &
  GTBFlag::operator=(const GTBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GTBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // FPFlag

  FPFlag::FPFlag() : TSSFlag()
  {}

  FPFlag::FPFlag(const FPFlag &rhs) : TSSFlag(rhs)
  {}

  FPFlag &
  FPFlag::operator=(const FPFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  FPFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // GSTICKFlag

  GSTICKFlag::GSTICKFlag() : TSSFlag()
  {}

  GSTICKFlag::GSTICKFlag(const GSTICKFlag &rhs) : TSSFlag(rhs)
  {}

  GSTICKFlag &
  GSTICKFlag::operator=(const GSTICKFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GSTICKFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // NG2Flag

  NG2Flag::NG2Flag() : TSSFlag()
  {}

  NG2Flag::NG2Flag(const NG2Flag &rhs) : TSSFlag(rhs)
  {}

  NG2Flag &
  NG2Flag::operator=(const NG2Flag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  NG2Flag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GZFlag

  GZFlag::GZFlag() : TSSFlag()
  {}

  GZFlag::GZFlag(const GZFlag &rhs) : TSSFlag(rhs)
  {}

  GZFlag &
  GZFlag::operator=(const GZFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GZFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // OAMFlag

  OAMFlag::OAMFlag() : TSSFlag()
  {}

  OAMFlag::OAMFlag(const OAMFlag &rhs) : TSSFlag(rhs)
  {}

  OAMFlag &
  OAMFlag::operator=(const OAMFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  OAMFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // RPFlag

  RPFlag::RPFlag() : TSSFlag()
  {}

  RPFlag::RPFlag(const RPFlag &rhs) : TSSFlag(rhs)
  {}

  RPFlag &
  RPFlag::operator=(const RPFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  RPFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // LOGFlag

  LOGFlag::LOGFlag() : TSSFlag()
  {}

  LOGFlag::LOGFlag(const LOGFlag &rhs) : TSSFlag(rhs)
  {}

  LOGFlag &
  LOGFlag::operator=(const LOGFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  LOGFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // FPBFlag

  FPBFlag::FPBFlag() : TSSFlag()
  {}

  FPBFlag::FPBFlag(const FPBFlag &rhs) : TSSFlag(rhs)
  {}

  FPBFlag &
  FPBFlag::operator=(const FPBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  FPBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // CSBFlag

  CSBFlag::CSBFlag() : TSSFlag()
  {}

  CSBFlag::CSBFlag(const CSBFlag &rhs) : TSSFlag(rhs)
  {}

  CSBFlag &
  CSBFlag::operator=(const CSBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  CSBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // DELETEFlag

  DELETEFlag::DELETEFlag() : TSSFlag()
  {}

  DELETEFlag::DELETEFlag(const DELETEFlag &rhs) : TSSFlag(rhs)
  {}

  DELETEFlag &
  DELETEFlag::operator=(const DELETEFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  DELETEFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // NBFlag

  NBFlag::NBFlag() : TSSFlag()
  {}

  NBFlag::NBFlag(const NBFlag &rhs) : TSSFlag(rhs)
  {}

  NBFlag &
  NBFlag::operator=(const NBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  NBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // NULFlag

  NULFlag::NULFlag() : TSSFlag()
  {}

  NULFlag::NULFlag(const NULFlag &rhs) : TSSFlag(rhs)
  {}

  NULFlag &
  NULFlag::operator=(const NULFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  NULFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // NCFlag

  NCFlag::NCFlag() : TSSFlag()
  {}

  NCFlag::NCFlag(const NCFlag &rhs) : TSSFlag(rhs)
  {}

  NCFlag &
  NCFlag::operator=(const NCFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  NCFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GWFlag

  GWFlag::GWFlag() : TSSFlag()
  {}

  GWFlag::GWFlag(const GWFlag &rhs) : TSSFlag(rhs)
  {}

  GWFlag &
  GWFlag::operator=(const GWFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GWFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GRFlag

  GRFlag::GRFlag() : TSSFlag()
  {}

  GRFlag::GRFlag(const GRFlag &rhs) : TSSFlag(rhs)
  {}

  GRFlag &
  GRFlag::operator=(const GRFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GRFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // AFlag

  AFlag::AFlag() : TSSFlag()
  {}

  AFlag::AFlag(const AFlag &rhs) : TSSFlag(rhs)
  {}

  AFlag &
  AFlag::operator=(const AFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  AFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // RFlag

  RFlag::RFlag() : TSSFlag()
  {}

  RFlag::RFlag(const RFlag &rhs) : TSSFlag(rhs)
  {}

  RFlag &
  RFlag::operator=(const RFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  RFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // GUFlag

  GUFlag::GUFlag() : TSSFlag()
  {}

  GUFlag::GUFlag(const GUFlag &rhs) : TSSFlag(rhs)
  {}

  GUFlag &
  GUFlag::operator=(const GUFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  GUFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // TFlag

  TFlag::TFlag() : TSSFlag()
  {}

  TFlag::TFlag(const TFlag &rhs) : TSSFlag(rhs)
  {}

  TFlag &
  TFlag::operator=(const TFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  TFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // RBFlag

  RBFlag::RBFlag() : TSSFlag()
  {}

  RBFlag::RBFlag(const RBFlag &rhs) : TSSFlag(rhs)
  {}

  RBFlag &
  RBFlag::operator=(const RBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  RBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // FBFlag

  FBFlag::FBFlag() : TSSFlag()
  {}

  FBFlag::FBFlag(const FBFlag &rhs) : TSSFlag(rhs)
  {}

  FBFlag &
  FBFlag::operator=(const FBFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  FBFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // SFlag

  SFlag::SFlag() : TSSFlag()
  {}

  SFlag::SFlag(const SFlag &rhs) : TSSFlag(rhs)
  {}

  SFlag &
  SFlag::operator=(const SFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  SFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // NTFlag

  NTFlag::NTFlag() : TSSFlag()
  {}

  NTFlag::NTFlag(const NTFlag &rhs) : TSSFlag(rhs)
  {}

  NTFlag &
  NTFlag::operator=(const NTFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  NTFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }



  // IFlag

  IFlag::IFlag() : TSSFlag()
  {}

  IFlag::IFlag(const IFlag &rhs) : TSSFlag(rhs)
  {}

  IFlag &
  IFlag::operator=(const IFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  IFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // FRFlag

  FRFlag::FRFlag() : TSSFlag()
  {}

  FRFlag::FRFlag(const FRFlag &rhs) : TSSFlag(rhs)
  {}

  FRFlag &
  FRFlag::operator=(const FRFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  FRFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // RSCHFlag

  RSCHFlag::RSCHFlag() : TSSFlag()
  {}

  RSCHFlag::RSCHFlag(const RSCHFlag &rhs) : TSSFlag(rhs)
  {}

  RSCHFlag &
  RSCHFlag::operator=(const RSCHFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  RSCHFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // CLOSEFlag

  CLOSEFlag::CLOSEFlag() : TSSFlag()
  {}

  CLOSEFlag::CLOSEFlag(const CLOSEFlag &rhs) : TSSFlag(rhs)
  {}

  CLOSEFlag &
  CLOSEFlag::operator=(const CLOSEFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  CLOSEFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // NEFlag

  NEFlag::NEFlag() : TSSFlag()
  {}

  NEFlag::NEFlag(const NEFlag &rhs) : TSSFlag(rhs)
  {}

  NEFlag &
  NEFlag::operator=(const NEFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    TSSFlag::operator=(rhs);
    return *this;
  }

  void
  NEFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // CbranchFlag

  CbranchFlag::CbranchFlag() : OctaveFlag()
  {}

  CbranchFlag::CbranchFlag(const CbranchFlag &rhs) : OctaveFlag(rhs)
  {}

  CbranchFlag &
  CbranchFlag::operator=(const CbranchFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  bool
  CbranchFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }


  // CFlag

  CFlag::CFlag() : CbranchFlag()
  {}

  CFlag::CFlag(const CFlag &rhs) : CbranchFlag(rhs)
  {}

  CFlag &
  CFlag::operator=(const CFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    CbranchFlag::operator=(rhs);
    return *this;
  }

  void
  CFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // BFFlag

  BFFlag::BFFlag() : CbranchFlag()
  {}

  BFFlag::BFFlag(const BFFlag &rhs) : CbranchFlag(rhs)
  {}

  BFFlag &
  BFFlag::operator=(const BFFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    CbranchFlag::operator=(rhs);
    return *this;
  }

  void
  BFFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // BrslFlag
  BrslFlag::BrslFlag() : OctaveFlag()
  {}

  BrslFlag::BrslFlag(const BrslFlag &rhs) : OctaveFlag(rhs)
  {}

  BrslFlag &
  BrslFlag::operator=(const BrslFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    return *this;
  }

  bool
  BrslFlag::equalTo(const LlirOperand &rhs) const
  {
    return true;
  }

  // UNLNKFlag

  UNLNKFlag::UNLNKFlag() : BrslFlag()
  {}

  UNLNKFlag::UNLNKFlag(const UNLNKFlag &rhs) : BrslFlag(rhs)
  {}

  UNLNKFlag &
  UNLNKFlag::operator=(const UNLNKFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    BrslFlag::operator=(rhs);
    return *this;
  }

  void
  UNLNKFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // PREFlag

  PREFlag::PREFlag() : BrslFlag()
  {}

  PREFlag::PREFlag(const PREFlag &rhs) : BrslFlag(rhs)
  {}

  PREFlag &
  PREFlag::operator=(const PREFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    BrslFlag::operator=(rhs);
    return *this;
  }

  void
  PREFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // DLNKFlag

  DLNKFlag::DLNKFlag() : BrslFlag()
  {}

  DLNKFlag::DLNKFlag(const DLNKFlag &rhs) : BrslFlag(rhs)
  {}

  DLNKFlag &
  DLNKFlag::operator=(const DLNKFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    BrslFlag::operator=(rhs);
    return *this;
  }

  void
  DLNKFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // FLUSHFlag

  FLUSHFlag::FLUSHFlag() : BrslFlag()
  {}

  FLUSHFlag::FLUSHFlag(const FLUSHFlag &rhs) : BrslFlag(rhs)
  {}

  FLUSHFlag &
  FLUSHFlag::operator=(const FLUSHFlag &rhs)
  {
    if (this == &rhs)
      return *this;

    BrslFlag::operator=(rhs);
    return *this;
  }

  void
  FLUSHFlag::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  // BrslFlags

  BrslFlags::BrslFlags(BrslPtr flag) : OctaveFlag()
  {
    m_brslFlags.push_back(flag);
  }

  BrslFlags::BrslFlags(BrslPtr flag1, BrslPtr flag2) : OctaveFlag()
  {
    m_brslFlags.push_back(flag1);
    m_brslFlags.push_back(flag2);
  }

  BrslFlags::BrslFlags(BrslPtr flag1, BrslPtr flag2, BrslPtr flag3) : OctaveFlag()
  {
    m_brslFlags.push_back(flag1);
    m_brslFlags.push_back(flag2);
    m_brslFlags.push_back(flag3);
  }

  BrslFlags::BrslFlags(BrslPtr flag1, BrslPtr flag2, BrslPtr flag3, BrslPtr flag4) : 
    OctaveFlag()
  {
    m_brslFlags.push_back(flag1);
    m_brslFlags.push_back(flag2);
    m_brslFlags.push_back(flag3);
    m_brslFlags.push_back(flag4);
  }



  BrslFlags::BrslFlags(const BrslFlags &rhs) : 
    OctaveFlag(rhs), m_brslFlags(rhs.m_brslFlags)
  {}

  BrslFlags &
  BrslFlags::operator=(const BrslFlags &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    m_brslFlags = rhs.m_brslFlags;
    return *this;
  }

  int
  BrslFlags::getNumBrslFlags() const
  {
    return m_brslFlags.size();
  }

  bool
  BrslFlags::equalTo(const LlirOperand &rhs) const
  {
    const BrslFlags rhsTemp = (dynamic_cast<const BrslFlags &> (rhs));

    if (getNumBrslFlags() != rhsTemp.getNumBrslFlags())
      return false;

    BrslFlags::ConstIterator thisIterator = begin();
    BrslFlags::ConstIterator rhsIterator;
    bool brslFlagFound;

    for (; thisIterator != end(); thisIterator++)
      {
	brslFlagFound = false;

	// To determine equality:
	// We need to search every element because the BrlsFlags can be given to
	// the instruction in any order

	for (rhsIterator = rhsTemp.begin(); rhsIterator != rhsTemp.end();
	     rhsIterator++)
	  {
	    if (*(*thisIterator) == *(*rhsIterator))
	      {
		brslFlagFound = true;
		break;
	      }
	  }

	if (brslFlagFound == false)
	  return false;
      }
    return true;
  }

  BrslFlags::Iterator
  BrslFlags::begin()
  {
    return m_brslFlags.begin();
  }

  BrslFlags::Iterator
  BrslFlags::end()
  {
    return m_brslFlags.end();
  }

  BrslFlags::ConstIterator
  BrslFlags::begin() const
  {
    return m_brslFlags.begin();
  }

  BrslFlags::ConstIterator
  BrslFlags::end() const
  {
    return m_brslFlags.end();
  }

  void
  BrslFlags::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // TrafficScheduleFlags

  TrafficScheduleFlags::TrafficScheduleFlags() : OctaveFlag()
  {}


  TrafficScheduleFlags::TrafficScheduleFlags(const TrafficScheduleFlags &rhs) : 
    OctaveFlag(rhs), m_tssFlags(rhs.m_tssFlags)
  {}

  TrafficScheduleFlags &
  TrafficScheduleFlags::operator=(const TrafficScheduleFlags &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    m_tssFlags = rhs.m_tssFlags;
    return *this;
  }

  void
  TrafficScheduleFlags::addFlag(TssPtr flag)
  {
    m_tssFlags.push_back(flag);
  }

  int
  TrafficScheduleFlags::getNumTssFlags() const
  {
    return m_tssFlags.size();
  }

  bool
  TrafficScheduleFlags::equalTo(const LlirOperand &rhs) const
  {
    const TrafficScheduleFlags &rhsTemp = (dynamic_cast<const TrafficScheduleFlags &> (rhs));

    if (getNumTssFlags() != rhsTemp.getNumTssFlags())
      return false;

    TrafficScheduleFlags::ConstIterator thisIterator = begin();
    TrafficScheduleFlags::ConstIterator rhsIterator;
    bool tssFlagFound;

    for (; thisIterator != end(); thisIterator++)
      {
	tssFlagFound = false;

	// To determine equality:
	// We need to search every element because the TSS Flags can be given to
	// the instruction in any order

	for (rhsIterator = rhsTemp.begin(); rhsIterator != rhsTemp.end();
	     rhsIterator++)
	  {
	    if (*(*thisIterator) == *(*rhsIterator))
	      {
		tssFlagFound = true;
		break;
	      }
	  }

	if (tssFlagFound == false)
	  return false;
      }
    return true;
  }

  void
  TrafficScheduleFlags::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }


  TrafficScheduleFlags::Iterator
  TrafficScheduleFlags::begin()
  {
    return m_tssFlags.begin();
  }

  TrafficScheduleFlags::Iterator
  TrafficScheduleFlags::end()
  {
    return m_tssFlags.end();
  }

  TrafficScheduleFlags::ConstIterator
  TrafficScheduleFlags::begin() const
  {
    return m_tssFlags.begin();
  }

  TrafficScheduleFlags::ConstIterator
  TrafficScheduleFlags::end() const
  {
    return m_tssFlags.end();
  }

  // GetFlags

  GetFlags::GetFlags() : TrafficScheduleFlags()
  {}

  GetFlags::GetFlags(const GetFlags &rhs) : TrafficScheduleFlags(rhs)
  {}

  GetFlags &
  GetFlags::operator=(const GetFlags &rhs)
  {
    if (this == &rhs)
      return *this;

    TrafficScheduleFlags::operator=(rhs);
    return *this;
  }

  void
  GetFlags::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // PolFlags

  PolFlags::PolFlags() : TrafficScheduleFlags()
  {}

  PolFlags::PolFlags(const PolFlags &rhs) : TrafficScheduleFlags(rhs)
  {}

  PolFlags &
  PolFlags::operator=(const PolFlags &rhs)
  {
    if (this == &rhs)
      return *this;

    TrafficScheduleFlags::operator=(rhs);
    return *this;
  }

  void
  PolFlags::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // PutFlags

  PutFlags::PutFlags() : TrafficScheduleFlags()
  {}

  PutFlags::PutFlags(const PutFlags &rhs) : TrafficScheduleFlags(rhs)
  {}

  PutFlags &
  PutFlags::operator=(const PutFlags &rhs)
  {
    if (this == &rhs)
      return *this;

    TrafficScheduleFlags::operator=(rhs);
    return *this;
  }

  void
  PutFlags::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

  // CbranchFlags

  CbranchFlags::CbranchFlags(CbranchPtr flag) : OctaveFlag()
  {
    m_cbranchFlags.push_back(flag);
  }

  CbranchFlags::CbranchFlags(CbranchPtr flag1, CbranchPtr flag2) : OctaveFlag()
  {
    m_cbranchFlags.push_back(flag1);
    m_cbranchFlags.push_back(flag2);
  }


  CbranchFlags::CbranchFlags(const CbranchFlags &rhs) : 
    OctaveFlag(rhs), m_cbranchFlags(rhs.m_cbranchFlags)
  {}

  CbranchFlags &
  CbranchFlags::operator=(const CbranchFlags &rhs)
  {
    if (this == &rhs)
      return *this;

    OctaveFlag::operator=(rhs);
    m_cbranchFlags = rhs.m_cbranchFlags;
    return *this;
  }

  bool
  CbranchFlags::equalTo(const LlirOperand &rhs) const
  {
    const CbranchFlags rhsTemp = (dynamic_cast<const CbranchFlags &> (rhs));

    if (m_cbranchFlags.size() != rhsTemp.m_cbranchFlags.size())
      return false;

    CbranchFlags::ConstIterator thisIterator = begin();
    CbranchFlags::ConstIterator rhsIterator;
    bool cbranchFlagFound;

    for (; thisIterator != end(); thisIterator++)
      {
	cbranchFlagFound = false;

	// To determine equality:
	// We need to search every element because the CbranchFlags can be given to
	// the instruction in any order

	for (rhsIterator = rhsTemp.begin(); rhsIterator != rhsTemp.end();
	     rhsIterator++)
	  {
	    if (*(*thisIterator) == *(*rhsIterator))
	      {
		cbranchFlagFound = true;
		break;
	      }
	  }

	if (cbranchFlagFound == false)
	  return false;
      }
    return true;
  }

  CbranchFlags::Iterator
  CbranchFlags::begin()
  {
    return m_cbranchFlags.begin();
  }

  CbranchFlags::Iterator
  CbranchFlags::end()
  {
    return m_cbranchFlags.end();
  }

  CbranchFlags::ConstIterator
  CbranchFlags::begin() const
  {
    return m_cbranchFlags.begin();
  }

  CbranchFlags::ConstIterator
  CbranchFlags::end() const
  {
    return m_cbranchFlags.end();
  }

  void
  CbranchFlags::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
    {
      lbv->visit(*this);
    } 
    else
    {
      throw LLIR_INTERNAL_EXCEPTION("accept error");
    }       
  }

} // namespace Llir
