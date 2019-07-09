#include <iostream>
using namespace std;

#include <LlirException.h>
#include "M470Instructions.h"
#include "M470Visitor.h"

namespace Llir {
  
  
  //---------------------------------------------
  // M470AddwhInstruction
  //---------------------------------------------
  
  M470AddwhInstruction&
  M470AddwhInstruction::operator=(const M470AddwhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddwhInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddwhInstruction dynRhs = 
      dynamic_cast<const M470AddwhInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddwhInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddwlInstruction
  //---------------------------------------------
  
  M470AddwlInstruction&
  M470AddwlInstruction::operator=(const M470AddwlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddwlInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddwlInstruction dynRhs = 
      dynamic_cast<const M470AddwlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddwlInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddwwInstruction
  //---------------------------------------------
  
  M470AddwwInstruction&
  M470AddwwInstruction::operator=(const M470AddwwInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddwwInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddwwInstruction dynRhs = 
      dynamic_cast<const M470AddwwInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddwwInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddlInstruction
  //---------------------------------------------
  
  M470AddlInstruction&
  M470AddlInstruction::operator=(const M470AddlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddlInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddlInstruction dynRhs = 
      dynamic_cast<const M470AddlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddlInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubwhInstruction
  //---------------------------------------------
  
  M470SubwhInstruction&
  M470SubwhInstruction::operator=(const M470SubwhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubwhInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubwhInstruction dynRhs = 
      dynamic_cast<const M470SubwhInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubwhInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubwlInstruction
  //---------------------------------------------
  
  M470SubwlInstruction&
  M470SubwlInstruction::operator=(const M470SubwlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubwlInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubwlInstruction dynRhs = 
      dynamic_cast<const M470SubwlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubwlInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubwwInstruction
  //---------------------------------------------
  
  M470SubwwInstruction&
  M470SubwwInstruction::operator=(const M470SubwwInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubwwInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubwwInstruction dynRhs = 
      dynamic_cast<const M470SubwwInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubwwInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SublInstruction
  //---------------------------------------------
  
  M470SublInstruction&
  M470SublInstruction::operator=(const M470SublInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SublInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SublInstruction dynRhs = 
      dynamic_cast<const M470SublInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SublInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddwhiInstruction
  //---------------------------------------------
  
  M470AddwhiInstruction&
  M470AddwhiInstruction::operator=(const M470AddwhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddwhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddwhiInstruction dynRhs = 
      dynamic_cast<const M470AddwhiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddwhiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddwliInstruction
  //---------------------------------------------
  
  M470AddwliInstruction&
  M470AddwliInstruction::operator=(const M470AddwliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddwliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddwliInstruction dynRhs = 
      dynamic_cast<const M470AddwliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddwliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddwwiInstruction
  //---------------------------------------------
  
  M470AddwwiInstruction&
  M470AddwwiInstruction::operator=(const M470AddwwiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddwwiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddwwiInstruction dynRhs = 
      dynamic_cast<const M470AddwwiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddwwiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddliInstruction
  //---------------------------------------------
  
  M470AddliInstruction&
  M470AddliInstruction::operator=(const M470AddliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddliInstruction dynRhs = 
      dynamic_cast<const M470AddliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470AddliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubwhiInstruction
  //---------------------------------------------
  
  M470SubwhiInstruction&
  M470SubwhiInstruction::operator=(const M470SubwhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubwhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubwhiInstruction dynRhs = 
      dynamic_cast<const M470SubwhiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubwhiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubwliInstruction
  //---------------------------------------------
  
  M470SubwliInstruction&
  M470SubwliInstruction::operator=(const M470SubwliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubwliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubwliInstruction dynRhs = 
      dynamic_cast<const M470SubwliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubwliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubwwiInstruction
  //---------------------------------------------
  
  M470SubwwiInstruction&
  M470SubwwiInstruction::operator=(const M470SubwwiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubwwiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubwwiInstruction dynRhs = 
      dynamic_cast<const M470SubwwiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubwwiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubliInstruction
  //---------------------------------------------
  
  M470SubliInstruction&
  M470SubliInstruction::operator=(const M470SubliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubliInstruction dynRhs = 
      dynamic_cast<const M470SubliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470SubliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470FfsInstruction
  //---------------------------------------------
  
  M470FfsInstruction&
  M470FfsInstruction::operator=(const M470FfsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpFindInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470FfsInstruction::equalTo(const LlirNode& rhs) const
  {
    M470FfsInstruction dynRhs = 
      dynamic_cast<const M470FfsInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum() )
	     && (getSrc1()     == dynRhs.getSrc1()    )
	     && (getDst()      == dynRhs.getDst()     )
	     && (getAbcFlag()  == dynRhs.getAbcFlag() )
	     && (getFindFlag() == dynRhs.getFindFlag()) );
  }
  
  void 
  M470FfsInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470FlsInstruction
  //---------------------------------------------
  
  M470FlsInstruction&
  M470FlsInstruction::operator=(const M470FlsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpFindInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470FlsInstruction::equalTo(const LlirNode& rhs) const
  {
    M470FlsInstruction dynRhs = 
      dynamic_cast<const M470FlsInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum() )
	     && (getSrc1()     == dynRhs.getSrc1()    )
	     && (getDst()      == dynRhs.getDst()     )
	     && (getAbcFlag()  == dynRhs.getAbcFlag() )
	     && (getFindFlag() == dynRhs.getFindFlag()) );
  }
  
  void 
  M470FlsInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ParInstruction
  //---------------------------------------------
 

  bool 
  M470ParInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470ParInstruction::getNumDelaySlots() const
  {
    if(hasValidAbcFlag())
      {
        return 3;
      }
    else
      {
        return 0;
      }
  }

  bool
  M470ParInstruction::isAbcInsn() const
  {
    if(hasValidAbcFlag())
      {
        return true;
      }
    else
      {
        return false;
      }
  }

  bool
  M470ParInstruction::isBranchInsn() const
  {
    if(hasValidAbcFlag())
      {
        return true;
      }
    else
      {
        return false;
      }
  }

  bool
  M470ParInstruction::isValidDslotInsn() const
  {
    if(hasValidAbcFlag())
      {
        return false;
      }
    else
      {
        return true;
      }
  }

  bool
  M470ParInstruction::hasValidAbcFlag() const
  {
    shared_ptr<const LlirOperand> opnd = getAbcFlag();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
        return false;
      }
    else
      {
        return true;
      }
  }


  OpndPtr
  M470ParInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  M470ParInstruction&
  M470ParInstruction::operator=(const M470ParInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpInstruction::operator=(rhs);
    m_abcFlag  = rhs.m_abcFlag;
    return *this;
    
  }
  
  bool
  M470ParInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ParInstruction dynRhs = 
      dynamic_cast<const M470ParInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum())
	     && (getSrc1()     == dynRhs.getSrc1()   )
	     && (getDst()      == dynRhs.getDst()    )
	     && (getAbcFlag()  == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ParInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddInstruction
  //---------------------------------------------
  
  M470AddInstruction&
  M470AddInstruction::operator=(const M470AddInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddInstruction dynRhs = 
      dynamic_cast<const M470AddInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag())
	     && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470AddInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470Add4xInstruction
  //---------------------------------------------
  
  M470Add4xInstruction&
  M470Add4xInstruction::operator=(const M470Add4xInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470Add4xInstruction::equalTo(const LlirNode& rhs) const
  {
    M470Add4xInstruction dynRhs = 
      dynamic_cast<const M470Add4xInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470Add4xInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddcInstruction
  //---------------------------------------------
  
  M470AddcInstruction&
  M470AddcInstruction::operator=(const M470AddcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddcInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddcInstruction dynRhs = 
      dynamic_cast<const M470AddcInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470AddcInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AndInstruction
  //---------------------------------------------
  
  M470AndInstruction&
  M470AndInstruction::operator=(const M470AndInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AndInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AndInstruction dynRhs = 
      dynamic_cast<const M470AndInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470AndInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MaxInstruction
  //---------------------------------------------
  
  M470MaxInstruction&
  M470MaxInstruction::operator=(const M470MaxInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MaxInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MaxInstruction dynRhs = 
      dynamic_cast<const M470MaxInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470MaxInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MinInstruction
  //---------------------------------------------
  
  M470MinInstruction&
  M470MinInstruction::operator=(const M470MinInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MinInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MinInstruction dynRhs = 
      dynamic_cast<const M470MinInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470MinInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470OrInstruction
  //---------------------------------------------
  
  M470OrInstruction&
  M470OrInstruction::operator=(const M470OrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470OrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470OrInstruction dynRhs = 
      dynamic_cast<const M470OrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470OrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubInstruction
  //---------------------------------------------
  
  M470SubInstruction&
  M470SubInstruction::operator=(const M470SubInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubInstruction dynRhs = 
      dynamic_cast<const M470SubInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470SubInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubbInstruction
  //---------------------------------------------
  
  M470SubbInstruction&
  M470SubbInstruction::operator=(const M470SubbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubbInstruction dynRhs = 
      dynamic_cast<const M470SubbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470SubbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470XorInstruction
  //---------------------------------------------
  
  M470XorInstruction&
  M470XorInstruction::operator=(const M470XorInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470XorInstruction::equalTo(const LlirNode& rhs) const
  {
    M470XorInstruction dynRhs = 
      dynamic_cast<const M470XorInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470XorInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddiInstruction
  //---------------------------------------------
  
  M470AddiInstruction&
  M470AddiInstruction::operator=(const M470AddiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddiInstruction dynRhs = 
      dynamic_cast<const M470AddiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470AddiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddciInstruction
  //---------------------------------------------
  
  M470AddciInstruction&
  M470AddciInstruction::operator=(const M470AddciInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddciInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddciInstruction dynRhs = 
      dynamic_cast<const M470AddciInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470AddciInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubiInstruction
  //---------------------------------------------
  
  M470SubiInstruction&
  M470SubiInstruction::operator=(const M470SubiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubiInstruction dynRhs = 
      dynamic_cast<const M470SubiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470SubiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SubbiInstruction
  //---------------------------------------------
  
  M470SubbiInstruction&
  M470SubbiInstruction::operator=(const M470SubbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SubbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SubbiInstruction dynRhs = 
      dynamic_cast<const M470SubbiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M470SubbiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RandInstruction
  //---------------------------------------------
  
  M470RandInstruction&
  M470RandInstruction::operator=(const M470RandInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RandInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RandInstruction dynRhs = 
      dynamic_cast<const M470RandInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470RandInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RotlInstruction
  //---------------------------------------------
  
  M470RotlInstruction&
  M470RotlInstruction::operator=(const M470RotlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RotlInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RotlInstruction dynRhs = 
      dynamic_cast<const M470RotlInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470RotlInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RotrInstruction
  //---------------------------------------------
  
  M470RotrInstruction&
  M470RotrInstruction::operator=(const M470RotrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RotrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RotrInstruction dynRhs = 
      dynamic_cast<const M470RotrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470RotrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ClrbInstruction
  //---------------------------------------------
  
  M470ClrbInstruction&
  M470ClrbInstruction::operator=(const M470ClrbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ClrbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ClrbInstruction dynRhs = 
      dynamic_cast<const M470ClrbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ClrbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SetbInstruction
  //---------------------------------------------
  
  M470SetbInstruction&
  M470SetbInstruction::operator=(const M470SetbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SetbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SetbInstruction dynRhs = 
      dynamic_cast<const M470SetbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470SetbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShftInstruction
  //---------------------------------------------
  
  M470ShftInstruction&
  M470ShftInstruction::operator=(const M470ShftInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShftInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShftInstruction dynRhs = 
      dynamic_cast<const M470ShftInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShftInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShftaInstruction
  //---------------------------------------------
  
  M470ShftaInstruction&
  M470ShftaInstruction::operator=(const M470ShftaInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShftaInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShftaInstruction dynRhs = 
      dynamic_cast<const M470ShftaInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShftaInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShlInstruction
  //---------------------------------------------
  
  M470ShlInstruction&
  M470ShlInstruction::operator=(const M470ShlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShlInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShlInstruction dynRhs = 
      dynamic_cast<const M470ShlInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShlInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShrInstruction
  //---------------------------------------------
  
  M470ShrInstruction&
  M470ShrInstruction::operator=(const M470ShrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShrInstruction dynRhs = 
      dynamic_cast<const M470ShrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShraInstruction
  //---------------------------------------------
  
  M470ShraInstruction&
  M470ShraInstruction::operator=(const M470ShraInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShraInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShraInstruction dynRhs = 
      dynamic_cast<const M470ShraInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShraInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RandiInstruction
  //---------------------------------------------
  
  M470RandiInstruction&
  M470RandiInstruction::operator=(const M470RandiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RandiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RandiInstruction dynRhs = 
      dynamic_cast<const M470RandiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470RandiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RotliInstruction
  //---------------------------------------------
  
  M470RotliInstruction&
  M470RotliInstruction::operator=(const M470RotliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RotliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RotliInstruction dynRhs = 
      dynamic_cast<const M470RotliInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470RotliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RotriInstruction
  //---------------------------------------------
  
  M470RotriInstruction&
  M470RotriInstruction::operator=(const M470RotriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RotriInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RotriInstruction dynRhs = 
      dynamic_cast<const M470RotriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470RotriInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SetbiInstruction
  //---------------------------------------------
  
  M470SetbiInstruction&
  M470SetbiInstruction::operator=(const M470SetbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470SetbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SetbiInstruction dynRhs = 
      dynamic_cast<const M470SetbiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470SetbiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }


  //---------------------------------------------
  // M470ClrbiInstruction
  //---------------------------------------------
  
  M470ClrbiInstruction&
  M470ClrbiInstruction::operator=(const M470ClrbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ClrbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ClrbiInstruction dynRhs = 
      dynamic_cast<const M470ClrbiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ClrbiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  
  
  //---------------------------------------------
  // M470ShliInstruction
  //---------------------------------------------
  
  M470ShliInstruction&
  M470ShliInstruction::operator=(const M470ShliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShliInstruction dynRhs = 
      dynamic_cast<const M470ShliInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShriInstruction
  //---------------------------------------------
  
  M470ShriInstruction&
  M470ShriInstruction::operator=(const M470ShriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShriInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShriInstruction dynRhs = 
      dynamic_cast<const M470ShriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShriInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ShraiInstruction
  //---------------------------------------------
  
  M470ShraiInstruction&
  M470ShraiInstruction::operator=(const M470ShraiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470ShraiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ShraiInstruction dynRhs = 
      dynamic_cast<const M470ShraiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ShraiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M470MaxiInstruction
  //---------------------------------------------
  
  M470MaxiInstruction&
  M470MaxiInstruction::operator=(const M470MaxiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MaxiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MaxiInstruction dynRhs = 
      dynamic_cast<const M470MaxiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470MaxiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MiniInstruction
  //---------------------------------------------
  
  M470MiniInstruction&
  M470MiniInstruction::operator=(const M470MiniInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MiniInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MiniInstruction dynRhs = 
      dynamic_cast<const M470MiniInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470MiniInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AndiInstruction
  //---------------------------------------------
  
  M470AndiInstruction&
  M470AndiInstruction::operator=(const M470AndiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AndiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AndiInstruction dynRhs = 
      dynamic_cast<const M470AndiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470AndiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470OriInstruction
  //---------------------------------------------
  
  M470OriInstruction&
  M470OriInstruction::operator=(const M470OriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470OriInstruction::equalTo(const LlirNode& rhs) const
  {
    M470OriInstruction dynRhs = 
      dynamic_cast<const M470OriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470OriInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470XoriInstruction
  //---------------------------------------------
  
  M470XoriInstruction&
  M470XoriInstruction::operator=(const M470XoriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470XoriInstruction::equalTo(const LlirNode& rhs) const
  {
    M470XoriInstruction dynRhs = 
      dynamic_cast<const M470XoriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470XoriInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MulInstruction
  //---------------------------------------------
  
  M470MulInstruction&
  M470MulInstruction::operator=(const M470MulInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MulInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MulInstruction dynRhs = 
      dynamic_cast<const M470MulInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M470MulInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MulhInstruction
  //---------------------------------------------
  
  M470MulhInstruction&
  M470MulhInstruction::operator=(const M470MulhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MulhInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MulhInstruction dynRhs = 
      dynamic_cast<const M470MulhInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M470MulhInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470DivInstruction
  //---------------------------------------------
  
  M470DivInstruction&
  M470DivInstruction::operator=(const M470DivInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470DivInstruction::equalTo(const LlirNode& rhs) const
  {
    M470DivInstruction dynRhs = 
      dynamic_cast<const M470DivInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M470DivInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MuliInstruction
  //---------------------------------------------
  
  M470MuliInstruction&
  M470MuliInstruction::operator=(const M470MuliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MuliInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MuliInstruction dynRhs = 
      dynamic_cast<const M470MuliInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M470MuliInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MulhiInstruction
  //---------------------------------------------
  
  M470MulhiInstruction&
  M470MulhiInstruction::operator=(const M470MulhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470MulhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MulhiInstruction dynRhs = 
      dynamic_cast<const M470MulhiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M470MulhiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470DiviInstruction
  //---------------------------------------------
  
  M470DiviInstruction&
  M470DiviInstruction::operator=(const M470DiviInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470DiviInstruction::equalTo(const LlirNode& rhs) const
  {
    M470DiviInstruction dynRhs = 
      dynamic_cast<const M470DiviInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M470DiviInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddneInstruction
  //---------------------------------------------


  bool 
  M470AddneInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470AddneInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M470AddneInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M470AddneInstruction::isValidDslotInsn() const
  {
    return true;
  }

  M470AddneInstruction&
  M470AddneInstruction::operator=(const M470AddneInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddneInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddneInstruction dynRhs = 
      dynamic_cast<const M470AddneInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M470AddneInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470AddneiInstruction
  //---------------------------------------------

  bool 
  M470AddneiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470AddneiInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M470AddneiInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M470AddneiInstruction::isValidDslotInsn() const
  {
    return true;
  }

  M470AddneiInstruction&
  M470AddneiInstruction::operator=(const M470AddneiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470AddneiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470AddneiInstruction dynRhs = 
      dynamic_cast<const M470AddneiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M470AddneiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ByteswInstruction
  //---------------------------------------------

  bool 
  M470ByteswInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470ByteswInstruction::getNumDelaySlots() const
  {
    if(hasValidAbcFlag())
      {
        return 3;
      }
    else
      {
        return 0;
      }
  }

  bool
  M470ByteswInstruction::isAbcInsn() const
  {
    if(hasValidAbcFlag())
      {
        return true;
      }
    else
      {
        return false;
      }
  }

  bool
  M470ByteswInstruction::isValidDslotInsn() const
  {
    return true;
  }

  bool
  M470ByteswInstruction::hasValidAbcFlag() const
  {
    shared_ptr<const LlirOperand> opnd = getAbcFlag();

    shared_ptr<const OpndNull> nullOpnd = shared_dynamic_cast<const OpndNull>(opnd);

    if(nullOpnd)
      {
        return false;
      }
    else
      {
        return true;
      }
  }


  RegPtr
  M470ByteswInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  RegPtr
  M470ByteswInstruction::getDst() const
  {
    return m_dst;
  }
  
  UImmPtr
  M470ByteswInstruction::getB0() const
  {
    return m_b0;
  }
  
  UImmPtr
  M470ByteswInstruction::getB1() const
  {
    return m_b1;
  }
  
  UImmPtr
  M470ByteswInstruction::getB2() const
  {
    return m_b2;
  }
  
  UImmPtr
  M470ByteswInstruction::getB3() const
  {
    return m_b3;
  }
  
  OpndPtr
  M470ByteswInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  M470ByteswInstruction&
  M470ByteswInstruction::operator=(const M470ByteswInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    AluOpInstruction::operator=(rhs);
    m_src1 = rhs.m_src1;
    m_dst = rhs.m_dst;
    m_b0 = rhs.m_b0;
    m_b1 = rhs.m_b1;
    m_b2 = rhs.m_b2;
    m_b3 = rhs.m_b3;
    m_abcFlag  = rhs.m_abcFlag;
    return *this;
    
  }
  
  bool
  M470ByteswInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ByteswInstruction dynRhs = 
      dynamic_cast<const M470ByteswInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum())
	     && (getSrc1()     == dynRhs.getSrc1()   )
	     && (getDst()      == dynRhs.getDst()    )
	     && (getB0()       == dynRhs.getB0()     )
	     && (getB1()       == dynRhs.getB1()     )
	     && (getB2()       == dynRhs.getB2()     )
	     && (getB3()       == dynRhs.getB3()     )
	     && (getAbcFlag()  == dynRhs.getAbcFlag()) );
  }
  
  void 
  M470ByteswInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470DepbInstruction
  //---------------------------------------------

  OpndPtr
  M470DepbInstruction::getDepbFlag() const
  {
    return m_depbFlag;
  }
  
  M470DepbInstruction&
  M470DepbInstruction::operator=(const M470DepbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BitOpInstruction::operator=(rhs);
    m_depbFlag = rhs.m_depbFlag;
    return *this;
    
  }
  
  bool
  M470DepbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470DepbInstruction dynRhs = 
      dynamic_cast<const M470DepbInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getSrc1()      == dynRhs.getSrc1()     )
            && (getSrcBitNum() == dynRhs.getSrcBitNum())
            && (getDst()       == dynRhs.getDst()      ) 
            && (getDstBitNum() == dynRhs.getDstBitNum()) 
            && (getNumBits()   == dynRhs.getNumBits()  )
	    && (getDepbFlag()  == dynRhs.getDepbFlag() ) );
  }
  
  void 
  M470DepbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470ExtbInstruction
  //---------------------------------------------

  OpndPtr
  M470ExtbInstruction::getSignFlag() const
  {
    return m_sign;
  }
  
  M470ExtbInstruction&
  M470ExtbInstruction::operator=(const M470ExtbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BitOpInstruction::operator=(rhs);
    m_sign = rhs.m_sign;
    return *this;
    
  }
  
  bool
  M470ExtbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470ExtbInstruction dynRhs = 
      dynamic_cast<const M470ExtbInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getSrc1()      == dynRhs.getSrc1()     )
            && (getSrcBitNum() == dynRhs.getSrcBitNum())
            && (getDst()       == dynRhs.getDst()      ) 
            && (getDstBitNum() == dynRhs.getDstBitNum()) 
            && (getNumBits()   == dynRhs.getNumBits()  )
	    && (getSignFlag()  == dynRhs.getSignFlag() ) );
  }
  
  void 
  M470ExtbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470DepbiInstruction
  //---------------------------------------------
 
  OpndPtr
  M470DepbiInstruction::getDepbFlag() const
  {
    return m_depbFlag;
  }
  
  M470DepbiInstruction&
  M470DepbiInstruction::operator=(const M470DepbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BitOpImmInstruction::operator=(rhs);
    m_depbFlag = rhs.m_depbFlag;
    return *this;
    
  }
  
  bool
  M470DepbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470DepbiInstruction dynRhs = 
      dynamic_cast<const M470DepbiInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getSrc1()      == dynRhs.getSrc1()     )
            && (getDst()       == dynRhs.getDst()      ) 
            && (getDstBitNum() == dynRhs.getDstBitNum()) 
            && (getNumBits()   == dynRhs.getNumBits()  )
	    && (getDepbFlag()  == dynRhs.getDepbFlag() ) );
  }
  
  void 
  M470DepbiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470CmovInstruction
  //---------------------------------------------
  
  M470CmovInstruction&
  M470CmovInstruction::operator=(const M470CmovInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CmovOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470CmovInstruction::equalTo(const LlirNode& rhs) const
  {
    M470CmovInstruction dynRhs = 
      dynamic_cast<const M470CmovInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum())
            && (getSrc1()     == dynRhs.getSrc1()   )
            && (getSrc2()     == dynRhs.getSrc2()   )
            && (getDst()      == dynRhs.getDst()    ) 
	    && (getEssFlag()  == dynRhs.getEssFlag()) );
  }
  
  void 
  M470CmovInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470CmoviInstruction
  //---------------------------------------------
  
  M470CmoviInstruction&
  M470CmoviInstruction::operator=(const M470CmoviInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CmovOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470CmoviInstruction::equalTo(const LlirNode& rhs) const
  {
    M470CmoviInstruction dynRhs = 
      dynamic_cast<const M470CmoviInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum())
            && (getSrc1()     == dynRhs.getSrc1()   )
            && (getSrc2()     == dynRhs.getSrc2()   )
            && (getDst()      == dynRhs.getDst()    ) 
	    && (getEssFlag()  == dynRhs.getEssFlag()) );
  }
  
  void 
  M470CmoviInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470DmapInstruction
  //---------------------------------------------
  
  M470DmapInstruction&
  M470DmapInstruction::operator=(const M470DmapInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470DmapInstruction::equalTo(const LlirNode& rhs) const
  {
    M470DmapInstruction dynRhs = 
      dynamic_cast<const M470DmapInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M470DmapInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470DmasrInstruction
  //---------------------------------------------
  
  M470DmasrInstruction&
  M470DmasrInstruction::operator=(const M470DmasrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470DmasrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470DmasrInstruction dynRhs = 
      dynamic_cast<const M470DmasrInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M470DmasrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470Dmau0Instruction
  //---------------------------------------------
  
  M470Dmau0Instruction&
  M470Dmau0Instruction::operator=(const M470Dmau0Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470Dmau0Instruction::equalTo(const LlirNode& rhs) const
  {
    M470Dmau0Instruction dynRhs = 
      dynamic_cast<const M470Dmau0Instruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M470Dmau0Instruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470Dmau1Instruction
  //---------------------------------------------
  
  M470Dmau1Instruction&
  M470Dmau1Instruction::operator=(const M470Dmau1Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470Dmau1Instruction::equalTo(const LlirNode& rhs) const
  {
    M470Dmau1Instruction dynRhs = 
      dynamic_cast<const M470Dmau1Instruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M470Dmau1Instruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LihInstruction
  //---------------------------------------------
  
  M470LihInstruction&
  M470LihInstruction::operator=(const M470LihInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LihInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LihInstruction dynRhs = 
      dynamic_cast<const M470LihInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M470LihInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LilInstruction
  //---------------------------------------------
  
  M470LilInstruction&
  M470LilInstruction::operator=(const M470LilInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LilInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LilInstruction dynRhs = 
      dynamic_cast<const M470LilInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M470LilInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LaihInstruction
  //---------------------------------------------
  
  M470LaihInstruction&
  M470LaihInstruction::operator=(const M470LaihInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LaihInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LaihInstruction dynRhs = 
      dynamic_cast<const M470LaihInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M470LaihInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LailInstruction
  //---------------------------------------------
  
  M470LailInstruction&
  M470LailInstruction::operator=(const M470LailInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LailInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LailInstruction dynRhs = 
      dynamic_cast<const M470LailInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M470LailInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LwihInstruction
  //---------------------------------------------
  
  M470LwihInstruction&
  M470LwihInstruction::operator=(const M470LwihInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadHalfwordInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LwihInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LwihInstruction dynRhs = 
      dynamic_cast<const M470LwihInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M470LwihInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LwilInstruction
  //---------------------------------------------
  
  M470LwilInstruction&
  M470LwilInstruction::operator=(const M470LwilInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadHalfwordInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LwilInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LwilInstruction dynRhs = 
      dynamic_cast<const M470LwilInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M470LwilInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470NopInstruction
  //---------------------------------------------

  bool 
  M470NopInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470NopInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M470NopInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M470NopInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  M470NopInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  M470NopInstruction&
  M470NopInstruction::operator=(const M470NopInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470NopInstruction::equalTo(const LlirNode& rhs) const
  {
    M470NopInstruction dynRhs = 
      dynamic_cast<const M470NopInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M470NopInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470Hec5Instruction
  //---------------------------------------------
  

  UImmPtr
  M470Hec5Instruction::getBytes() const
  {
    return m_bytes;
  }
  
  OpndPtr
  M470Hec5Instruction::getCumeFlag() const
  {
    return m_cumeFlag;
  }
  
  M470Hec5Instruction&
  M470Hec5Instruction::operator=(const M470Hec5Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    m_bytes        = rhs.m_bytes;
    m_cumeFlag     = rhs.m_cumeFlag;
    return *this;
    
  }
  
  bool
  M470Hec5Instruction::equalTo(const LlirNode& rhs) const
  {
    M470Hec5Instruction dynRhs = 
      dynamic_cast<const M470Hec5Instruction&> (rhs); 

    return ((getLineNum() == dynRhs.getLineNum())
            && (getBytes() == dynRhs.getBytes()) 
	    && (getCumeFlag() == dynRhs.getCumeFlag()));
  }
  
  void 
  M470Hec5Instruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MvInstruction
  //---------------------------------------------

  bool 
  M470MvInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470MvInstruction::getNumDelaySlots() const
  {//FIXME:::
    return 0;
  }

  bool
  M470MvInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M470MvInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  M470MvInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }


  RegPtr
  M470MvInstruction::getSrc() const
  {
    return m_src;
  }
  
  RegPtr
  M470MvInstruction::getDst() const
  {
    return m_dst;
  }
  
  M470MvInstruction&
  M470MvInstruction::operator=(const M470MvInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src = rhs.m_src;
    m_dst = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M470MvInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MvInstruction dynRhs = 
      dynamic_cast<const M470MvInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc()     == dynRhs.getSrc()    )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M470MvInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MvhrInstruction
  //---------------------------------------------
  
  M470MvhrInstruction&
  M470MvhrInstruction::operator=(const M470MvhrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MvhOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470MvhrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MvhrInstruction dynRhs = 
      dynamic_cast<const M470MvhrInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M470MvhrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470MvrhInstruction
  //---------------------------------------------
  
  M470MvrhInstruction&
  M470MvrhInstruction::operator=(const M470MvrhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MvhOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470MvrhInstruction::equalTo(const LlirNode& rhs) const
  {
    M470MvrhInstruction dynRhs = 
      dynamic_cast<const M470MvrhInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M470MvrhInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470UnlinkInstruction
  //---------------------------------------------
  
  M470UnlinkInstruction&
  M470UnlinkInstruction::operator=(const M470UnlinkInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470UnlinkInstruction::equalTo(const LlirNode& rhs) const
  {
    M470UnlinkInstruction dynRhs = 
      dynamic_cast<const M470UnlinkInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
	    && (getRegs()    == dynRhs.getRegs()   ) );
  }
  
  void 
  M470UnlinkInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LinkInstruction
  //---------------------------------------------
  
  M470LinkInstruction&
  M470LinkInstruction::operator=(const M470LinkInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LinkInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LinkInstruction dynRhs = 
      dynamic_cast<const M470LinkInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M470LinkInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LinksInstruction
  //---------------------------------------------
  
  M470LinksInstruction&
  M470LinksInstruction::operator=(const M470LinksInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LinksInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LinksInstruction dynRhs = 
      dynamic_cast<const M470LinksInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M470LinksInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470LmmInstruction
  //---------------------------------------------
  
  M470LmmInstruction&
  M470LmmInstruction::operator=(const M470LmmInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LmmInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LmmInstruction dynRhs = 
      dynamic_cast<const M470LmmInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M470LmmInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M470LmmsInstruction
  //---------------------------------------------
  
  M470LmmsInstruction&
  M470LmmsInstruction::operator=(const M470LmmsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LmmsInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LmmsInstruction dynRhs = 
      dynamic_cast<const M470LmmsInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M470LmmsInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M470LspInstruction
  //---------------------------------------------
  
  M470LspInstruction&
  M470LspInstruction::operator=(const M470LspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470LspInstruction::equalTo(const LlirNode& rhs) const
  {
    M470LspInstruction dynRhs = 
      dynamic_cast<const M470LspInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M470LspInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470SmmInstruction
  //---------------------------------------------
  
  M470SmmInstruction&
  M470SmmInstruction::operator=(const M470SmmInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470SmmInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SmmInstruction dynRhs = 
      dynamic_cast<const M470SmmInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M470SmmInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  //---------------------------------------------
  // M470SmmsInstruction
  //---------------------------------------------
  
  M470SmmsInstruction&
  M470SmmsInstruction::operator=(const M470SmmsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470SmmsInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SmmsInstruction dynRhs = 
      dynamic_cast<const M470SmmsInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M470SmmsInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  
  //---------------------------------------------
  // M470SspInstruction
  //---------------------------------------------
  
  M470SspInstruction&
  M470SspInstruction::operator=(const M470SspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470SspInstruction::equalTo(const LlirNode& rhs) const
  {
    M470SspInstruction dynRhs = 
      dynamic_cast<const M470SspInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M470SspInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470PutInstruction
  //---------------------------------------------
  
  M470PutInstruction&
  M470PutInstruction::operator=(const M470PutInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    m_rsb = rhs.m_rsb;
    return *this;
    
  }
   
  RegPtr
  M470PutInstruction::getRsb() const
  {
    return m_rsb;
  }
  
  bool
  M470PutInstruction::equalTo(const LlirNode& rhs) const
  {
    M470PutInstruction dynRhs = 
      dynamic_cast<const M470PutInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getRsb()      == dynRhs.getRsb()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M470PutInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470GetInstruction
  //---------------------------------------------
  
  M470GetInstruction&
  M470GetInstruction::operator=(const M470GetInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470GetInstruction::equalTo(const LlirNode& rhs) const
  {
    M470GetInstruction dynRhs = 
      dynamic_cast<const M470GetInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M470GetInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470PolInstruction
  //---------------------------------------------
  
  M470PolInstruction&
  M470PolInstruction::operator=(const M470PolInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470PolInstruction::equalTo(const LlirNode& rhs) const
  {
    M470PolInstruction dynRhs = 
      dynamic_cast<const M470PolInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M470PolInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  
  //---------------------------------------------
  // M470PutcInstruction
  //---------------------------------------------
  
  OpndPtr
  M470PutcInstruction::getPipeDepth() const
  {
    return m_pipeDepth;
  }
  
  M470PutcInstruction&
  M470PutcInstruction::operator=(const M470PutcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssNoRcOpInstruction::operator=(rhs);
    m_pipeDepth = rhs.m_pipeDepth;
    return *this;
    
  }
  
  bool
  M470PutcInstruction::equalTo(const LlirNode& rhs) const
  {
    M470PutcInstruction dynRhs = 
      dynamic_cast<const M470PutcInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getParOffset() == dynRhs.getParOffset())
            && (getPosOffset() == dynRhs.getPosOffset())
	    && (getPipeDepth() == dynRhs.getPipeDepth())
            && (getTssFlags()  == dynRhs.getTssFlags() ) );
  }
  
  void 
  M470PutcInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470GetcInstruction
  //---------------------------------------------
  
  M470GetcInstruction&
  M470GetcInstruction::operator=(const M470GetcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssNoRcOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470GetcInstruction::equalTo(const LlirNode& rhs) const
  {
    M470GetcInstruction dynRhs = 
      dynamic_cast<const M470GetcInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getParOffset() == dynRhs.getParOffset())
            && (getPosOffset() == dynRhs.getPosOffset())
            && (getTssFlags()  == dynRhs.getTssFlags() ) );
  }
  
  void 
  M470GetcInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470PolcInstruction
  //---------------------------------------------
  
  M470PolcInstruction&
  M470PolcInstruction::operator=(const M470PolcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssNoRcOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470PolcInstruction::equalTo(const LlirNode& rhs) const
  {
    M470PolcInstruction dynRhs = 
      dynamic_cast<const M470PolcInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getParOffset() == dynRhs.getParOffset())
            && (getPosOffset() == dynRhs.getPosOffset())
            && (getTssFlags()  == dynRhs.getTssFlags() ) );
  }
  
  void 
  M470PolcInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BcdrInstruction
  //---------------------------------------------

  bool 
  M470BcdrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BcdrInstruction::getNumDelaySlots() const
  {
    if(hasValidCFlag())
      {
	return 0;
      }
    else
      {
	return 2;
      }
  }
  

  M470BcdrInstruction&
  M470BcdrInstruction::operator=(const M470BcdrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BcdrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BcdrInstruction dynRhs = 
      dynamic_cast<const M470BcdrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M470BcdrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BcrInstruction
  //---------------------------------------------


  bool 
  M470BcrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BcrInstruction::getNumDelaySlots() const
  {
    if(hasValidCFlag())
      {
	return 0;
      }
    else
      {
	return 1;
      }
  }
  

  M470BcrInstruction&
  M470BcrInstruction::operator=(const M470BcrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BcrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BcrInstruction dynRhs = 
      dynamic_cast<const M470BcrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M470BcrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BcdiInstruction
  //---------------------------------------------
  

  bool 
  M470BcdiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BcdiInstruction::getNumDelaySlots() const
  {
    if(hasValidCFlag())
      {
	return 0;
      }
    else
      {
	return 2;
      }
  }


  M470BcdiInstruction&
  M470BcdiInstruction::operator=(const M470BcdiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BcdiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BcdiInstruction dynRhs = 
      dynamic_cast<const M470BcdiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M470BcdiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BciInstruction
  //---------------------------------------------


  bool 
  M470BciInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BciInstruction::getNumDelaySlots() const
  {
    if(hasValidCFlag())
      {
	return 0;
      }
    else
      {
	return 1;
      }
  }

  
  M470BciInstruction&
  M470BciInstruction::operator=(const M470BciInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BciInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BciInstruction dynRhs = 
      dynamic_cast<const M470BciInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M470BciInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BnzrInstruction
  //---------------------------------------------


  bool 
  M470BnzrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BnzrInstruction::getNumDelaySlots() const
  {
    return 2;
  }

  

  M470BnzrInstruction&
  M470BnzrInstruction::operator=(const M470BnzrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BnzrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BnzrInstruction dynRhs = 
      dynamic_cast<const M470BnzrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M470BnzrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BzrInstruction
  //---------------------------------------------


  bool 
  M470BzrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BzrInstruction::getNumDelaySlots() const
  {
    return 2;
  }

  

  M470BzrInstruction&
  M470BzrInstruction::operator=(const M470BzrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BzrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BzrInstruction dynRhs = 
      dynamic_cast<const M470BzrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M470BzrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BnziInstruction
  //---------------------------------------------
  

  bool 
  M470BnziInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BnziInstruction::getNumDelaySlots() const
  {
    return 2;
  }




  M470BnziInstruction&
  M470BnziInstruction::operator=(const M470BnziInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BnziInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BnziInstruction dynRhs = 
      dynamic_cast<const M470BnziInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M470BnziInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BziInstruction
  //---------------------------------------------
  

  bool 
  M470BziInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BziInstruction::getNumDelaySlots() const
  {
    return 2;
  }



  M470BziInstruction&
  M470BziInstruction::operator=(const M470BziInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470BziInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BziInstruction dynRhs = 
      dynamic_cast<const M470BziInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   ) 
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M470BziInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470TsetbInstruction
  //---------------------------------------------
  
  M470TsetbInstruction&
  M470TsetbInstruction::operator=(const M470TsetbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TestBitBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470TsetbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470TsetbInstruction dynRhs = 
      dynamic_cast<const M470TsetbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getBitpos()  == dynRhs.getBitpos() )
	     && (getDisp()    == dynRhs.getDisp()   ) );
  }
  
  void 
  M470TsetbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470TclrbInstruction
  //---------------------------------------------
  
  M470TclrbInstruction&
  M470TclrbInstruction::operator=(const M470TclrbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TestBitBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470TclrbInstruction::equalTo(const LlirNode& rhs) const
  {
    M470TclrbInstruction dynRhs = 
      dynamic_cast<const M470TclrbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getBitpos()  == dynRhs.getBitpos() )
	     && (getDisp()    == dynRhs.getDisp()   ) );
  }
  
  void 
  M470TclrbInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RnmiInstruction
  //---------------------------------------------
  

  bool 
  M470RnmiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470RnmiInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  M470RnmiInstruction&
  M470RnmiInstruction::operator=(const M470RnmiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ReturnOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RnmiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RnmiInstruction dynRhs = 
      dynamic_cast<const M470RnmiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDiFlag()  == dynRhs.getDiFlag() ) );
  }
  
  void 
  M470RnmiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470RintInstruction
  //---------------------------------------------


  bool 
  M470RintInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470RintInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  

  M470RintInstruction&
  M470RintInstruction::operator=(const M470RintInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ReturnOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M470RintInstruction::equalTo(const LlirNode& rhs) const
  {
    M470RintInstruction dynRhs = 
      dynamic_cast<const M470RintInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDiFlag()  == dynRhs.getDiFlag() ) );
  }
  
  void 
  M470RintInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BrsInstruction
  //---------------------------------------------

  bool
  M470BrsInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M470BrsInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M470BrsInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return false;
      }
    else
      {
	return true;
      }
  }

  bool
  M470BrsInstruction::hasReturnReg() const
  {
    if(! getDst()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getDst());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  bool 
  M470BrsInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BrsInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  
  OpndPtr
  M470BrsInstruction::getDst() const
  {
    return m_dst;
  }
  
  M470BrsInstruction&
  M470BrsInstruction::operator=(const M470BrsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_dst = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M470BrsInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BrsInstruction dynRhs = 
      dynamic_cast<const M470BrsInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M470BrsInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BrslInstruction
  //---------------------------------------------

  bool
  M470BrslInstruction::isBranchInsn() const
  {
    return true;
  }
  
  bool
  M470BrslInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool 
  M470BrslInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BrslInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  OpndPtr
  M470BrslInstruction::getBrslFlags() const
  {
    return m_flags;
  }
  
  M470BrslInstruction&
  M470BrslInstruction::operator=(const M470BrslInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_flags = rhs.m_flags;
    return *this;
    
  }
  
  bool
  M470BrslInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BrslInstruction dynRhs = 
      dynamic_cast<const M470BrslInstruction&> (rhs); 
    return (    (getLineNum()   == dynRhs.getLineNum()  )
	     && (getBrslFlags() == dynRhs.getBrslFlags()) );
  }
  
  void 
  M470BrslInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BrspreInstruction
  //---------------------------------------------

  bool 
  M470BrspreInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BrspreInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M470BrspreInstruction::isAbcInsn() const
  {
    return false;
  }
  
  bool
  M470BrspreInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  M470BrspreInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }  

  M470BrspreInstruction&
  M470BrspreInstruction::operator=(const M470BrspreInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470BrspreInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BrspreInstruction dynRhs = 
      dynamic_cast<const M470BrspreInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M470BrspreInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470CmpInstruction
  //---------------------------------------------
  
  M470CmpInstruction&
  M470CmpInstruction::operator=(const M470CmpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470CmpInstruction::equalTo(const LlirNode& rhs) const
  {
    M470CmpInstruction dynRhs = 
      dynamic_cast<const M470CmpInstruction&> (rhs); 
    return (   (getLineNum()      == dynRhs.getLineNum()     )
            && (getSrc1()         == dynRhs.getSrc1()        )
	    && (getSrc2()         == dynRhs.getSrc2()        )
            && (getAbcFlag()      == dynRhs.getAbcFlag()     )
            && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470CmpInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470CmpiInstruction
  //---------------------------------------------
  
  M470CmpiInstruction&
  M470CmpiInstruction::operator=(const M470CmpiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470CmpiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470CmpiInstruction dynRhs = 
      dynamic_cast<const M470CmpiInstruction&> (rhs); 
    return (   (getLineNum()      == dynRhs.getLineNum()     )
            && (getSrc1()         == dynRhs.getSrc1()        )
	    && (getSrc2()         == dynRhs.getSrc2()        )
            && (getAbcFlag()      == dynRhs.getAbcFlag()     )
            && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M470CmpiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470CmprInstruction
  //---------------------------------------------
  
  M470CmprInstruction&
  M470CmprInstruction::operator=(const M470CmprInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpSignInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470CmprInstruction::equalTo(const LlirNode& rhs) const
  {
    M470CmprInstruction dynRhs = 
      dynamic_cast<const M470CmprInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
	    && (getSrc2()    == dynRhs.getSrc2()   )
            && (getAbcFlag() == dynRhs.getAbcFlag())
            && (getDst()     == dynRhs.getDst()    ) 
            && (getSign()    == dynRhs.getSign()   ) );
  }
  
  void 
  M470CmprInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470CmpriInstruction
  //---------------------------------------------
  
  M470CmpriInstruction&
  M470CmpriInstruction::operator=(const M470CmpriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpSignInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M470CmpriInstruction::equalTo(const LlirNode& rhs) const
  {
    M470CmpriInstruction dynRhs = 
      dynamic_cast<const M470CmpriInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
	    && (getSrc2()    == dynRhs.getSrc2()   )
            && (getAbcFlag() == dynRhs.getAbcFlag())
            && (getDst()     == dynRhs.getDst()    ) 
            && (getSign()    == dynRhs.getSign()   ) );
  }
  
  void 
  M470CmpriInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BiInstruction
  //---------------------------------------------

  bool
  M470BiInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M470BiInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M470BiInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool
  M470BiInstruction::hasReturnReg() const
  {
    if(! getDst()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getDst());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }


  bool 
  M470BiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BiInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  OpndPtr
  M470BiInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M470BiInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  M470BiInstruction::getCdFlag() const
  {
    return m_cdFlag;
  }
  
  M470BiInstruction&
  M470BiInstruction::operator=(const M470BiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_dst    = rhs.m_dst;
    m_cdFlag = rhs.m_cdFlag;
    return *this;
    
  }
  
  bool
  M470BiInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BiInstruction dynRhs = 
      dynamic_cast<const M470BiInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) 
            && (getCdFlag()  == dynRhs.getCdFlag() ) );
  }
  
  void 
  M470BiInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M470BrInstruction
  //---------------------------------------------

  bool
  M470BrInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M470BrInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M470BrInstruction::isCallInsn() const
  {
    if(hasReturnReg())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool
  M470BrInstruction::hasReturnReg() const
  {
    if(! getDst()->isNullOperand())
      {
	shared_ptr<const Register> rpc = shared_dynamic_cast<const Register>(getDst());

	unsigned int rpcRegNum = rpc->getRegNum();
	    
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  bool 
  M470BrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M470BrInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  RegPtr
  M470BrInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M470BrInstruction::getDst() const
  {
    return m_dst;
  }
  
  M470BrInstruction&
  M470BrInstruction::operator=(const M470BrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_dst    = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M470BrInstruction::equalTo(const LlirNode& rhs) const
  {
    M470BrInstruction dynRhs = 
      dynamic_cast<const M470BrInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M470BrInstruction::accept(Visitor& v) const
  {
    if(M470Visitor *lv = 
       dynamic_cast<M470Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  //---------------------------------------------

} // end of namespace Llir
