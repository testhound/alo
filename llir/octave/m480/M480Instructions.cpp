
#include <iostream>
using namespace std;

#include <LlirException.h>

#include "M480Instructions.h"
#include "M480Visitor.h"


namespace Llir {
  
  
  //---------------------------------------------
  // M480AddwhInstruction
  //---------------------------------------------
  
  M480AddwhInstruction&
  M480AddwhInstruction::operator=(const M480AddwhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddwhInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddwhInstruction dynRhs = 
      dynamic_cast<const M480AddwhInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddwhInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JaddwhInstruction
  //---------------------------------------------
  

  bool 
  M480JaddwhInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JaddwhInstruction&
  M480JaddwhInstruction::operator=(const M480JaddwhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddwhInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddwhInstruction dynRhs = 
      dynamic_cast<const M480JaddwhInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddwhInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddwlInstruction
  //---------------------------------------------
  
  M480AddwlInstruction&
  M480AddwlInstruction::operator=(const M480AddwlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddwlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddwlInstruction dynRhs = 
      dynamic_cast<const M480AddwlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddwlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JaddwlInstruction
  //---------------------------------------------


  bool 
  M480JaddwlInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JaddwlInstruction&
  M480JaddwlInstruction::operator=(const M480JaddwlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddwlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddwlInstruction dynRhs = 
      dynamic_cast<const M480JaddwlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddwlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480AddwwInstruction
  //---------------------------------------------
  
  M480AddwwInstruction&
  M480AddwwInstruction::operator=(const M480AddwwInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddwwInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddwwInstruction dynRhs = 
      dynamic_cast<const M480AddwwInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddwwInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  
  //---------------------------------------------
  // M480JaddwwInstruction
  //---------------------------------------------
  

  bool 
  M480JaddwwInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JaddwwInstruction&
  M480JaddwwInstruction::operator=(const M480JaddwwInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddwwInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddwwInstruction dynRhs = 
      dynamic_cast<const M480JaddwwInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddwwInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    

  //---------------------------------------------
  // M480AddlInstruction
  //---------------------------------------------
  
  M480AddlInstruction&
  M480AddlInstruction::operator=(const M480AddlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddlInstruction dynRhs = 
      dynamic_cast<const M480AddlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
   
  //---------------------------------------------
  // M480JaddlInstruction
  //---------------------------------------------
  

  bool 
  M480JaddlInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JaddlInstruction&
  M480JaddlInstruction::operator=(const M480JaddlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddlInstruction dynRhs = 
      dynamic_cast<const M480JaddlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubwhInstruction
  //---------------------------------------------
  


  M480SubwhInstruction&
  M480SubwhInstruction::operator=(const M480SubwhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubwhInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubwhInstruction dynRhs = 
      dynamic_cast<const M480SubwhInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubwhInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JsubwhInstruction
  //---------------------------------------------
  

  bool 
  M480JsubwhInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JsubwhInstruction&
  M480JsubwhInstruction::operator=(const M480JsubwhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubwhInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubwhInstruction dynRhs = 
      dynamic_cast<const M480JsubwhInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubwhInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480SubwlInstruction
  //---------------------------------------------
  

  M480SubwlInstruction&
  M480SubwlInstruction::operator=(const M480SubwlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubwlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubwlInstruction dynRhs = 
      dynamic_cast<const M480SubwlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubwlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JsubwlInstruction
  //---------------------------------------------


  bool 
  M480JsubwlInstruction::isPseudoInsn() const
  {
    return true;
  }
  
  M480JsubwlInstruction&
  M480JsubwlInstruction::operator=(const M480JsubwlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubwlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubwlInstruction dynRhs = 
      dynamic_cast<const M480JsubwlInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubwlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480SubwwInstruction
  //---------------------------------------------
  
  M480SubwwInstruction&
  M480SubwwInstruction::operator=(const M480SubwwInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubwwInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubwwInstruction dynRhs = 
      dynamic_cast<const M480SubwwInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubwwInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JsubwwInstruction
  //---------------------------------------------
  

  bool 
  M480JsubwwInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JsubwwInstruction&
  M480JsubwwInstruction::operator=(const M480JsubwwInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubwwInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubwwInstruction dynRhs = 
      dynamic_cast<const M480JsubwwInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubwwInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SublInstruction
  //---------------------------------------------
  
  M480SublInstruction&
  M480SublInstruction::operator=(const M480SublInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SublInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SublInstruction dynRhs = 
      dynamic_cast<const M480SublInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SublInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    
  //---------------------------------------------
  // M480JsublInstruction
  //---------------------------------------------
  

  bool 
  M480JsublInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JsublInstruction&
  M480JsublInstruction::operator=(const M480JsublInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsublInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsublInstruction dynRhs = 
      dynamic_cast<const M480JsublInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsublInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddwhiInstruction
  //---------------------------------------------
  
  M480AddwhiInstruction&
  M480AddwhiInstruction::operator=(const M480AddwhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddwhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddwhiInstruction dynRhs = 
      dynamic_cast<const M480AddwhiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddwhiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
   
  //---------------------------------------------
  // M480JaddwhiInstruction
  //---------------------------------------------
  

  bool 
  M480JaddwhiInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JaddwhiInstruction&
  M480JaddwhiInstruction::operator=(const M480JaddwhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddwhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddwhiInstruction dynRhs = 
      dynamic_cast<const M480JaddwhiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddwhiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddwliInstruction
  //---------------------------------------------
  
  M480AddwliInstruction&
  M480AddwliInstruction::operator=(const M480AddwliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddwliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddwliInstruction dynRhs = 
      dynamic_cast<const M480AddwliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddwliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480JaddwliInstruction
  //---------------------------------------------
  

  bool 
  M480JaddwliInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JaddwliInstruction&
  M480JaddwliInstruction::operator=(const M480JaddwliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddwliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddwliInstruction dynRhs = 
      dynamic_cast<const M480JaddwliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddwliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480AddwwiInstruction
  //---------------------------------------------
  
  M480AddwwiInstruction&
  M480AddwwiInstruction::operator=(const M480AddwwiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddwwiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddwwiInstruction dynRhs = 
      dynamic_cast<const M480AddwwiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddwwiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    
  //---------------------------------------------
  // M480JaddwwiInstruction
  //---------------------------------------------
  

  bool 
  M480JaddwwiInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JaddwwiInstruction&
  M480JaddwwiInstruction::operator=(const M480JaddwwiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddwwiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddwwiInstruction dynRhs = 
      dynamic_cast<const M480JaddwwiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddwwiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddliInstruction
  //---------------------------------------------
  
  M480AddliInstruction&
  M480AddliInstruction::operator=(const M480AddliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddliInstruction dynRhs = 
      dynamic_cast<const M480AddliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480AddliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
   
  //---------------------------------------------
  // M480JaddliInstruction
  //---------------------------------------------
  

  bool 
  M480JaddliInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JaddliInstruction&
  M480JaddliInstruction::operator=(const M480JaddliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JaddliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JaddliInstruction dynRhs = 
      dynamic_cast<const M480JaddliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JaddliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubwhiInstruction
  //---------------------------------------------
  
  M480SubwhiInstruction&
  M480SubwhiInstruction::operator=(const M480SubwhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubwhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubwhiInstruction dynRhs = 
      dynamic_cast<const M480SubwhiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubwhiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
   
  //---------------------------------------------
  // M480JsubwhiInstruction
  //---------------------------------------------
  

  bool 
  M480JsubwhiInstruction::isPseudoInsn() const
  {
    return true;
  }

 
  M480JsubwhiInstruction&
  M480JsubwhiInstruction::operator=(const M480JsubwhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubwhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubwhiInstruction dynRhs = 
      dynamic_cast<const M480JsubwhiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubwhiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubwliInstruction
  //---------------------------------------------
  
  M480SubwliInstruction&
  M480SubwliInstruction::operator=(const M480SubwliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubwliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubwliInstruction dynRhs = 
      dynamic_cast<const M480SubwliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubwliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480JsubwliInstruction
  //---------------------------------------------
  

  bool 
  M480JsubwliInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JsubwliInstruction&
  M480JsubwliInstruction::operator=(const M480JsubwliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubwliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubwliInstruction dynRhs = 
      dynamic_cast<const M480JsubwliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubwliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  
  //---------------------------------------------
  // M480SubwwiInstruction
  //---------------------------------------------
  
  M480SubwwiInstruction&
  M480SubwwiInstruction::operator=(const M480SubwwiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubwwiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubwwiInstruction dynRhs = 
      dynamic_cast<const M480SubwwiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubwwiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480JsubwwiInstruction
  //---------------------------------------------
  

  bool 
  M480JsubwwiInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JsubwwiInstruction&
  M480JsubwwiInstruction::operator=(const M480JsubwwiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubwwiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubwwiInstruction dynRhs = 
      dynamic_cast<const M480JsubwwiInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubwwiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  


  
  //---------------------------------------------
  // M480SubliInstruction
  //---------------------------------------------
  
  M480SubliInstruction&
  M480SubliInstruction::operator=(const M480SubliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubliInstruction dynRhs = 
      dynamic_cast<const M480SubliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480SubliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  

  
  //---------------------------------------------
  // M480JsubliInstruction
  //---------------------------------------------
  

  bool 
  M480JsubliInstruction::isPseudoInsn() const
  {
    return true;
  }


  M480JsubliInstruction&
  M480JsubliInstruction::operator=(const M480JsubliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JsubliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JsubliInstruction dynRhs = 
      dynamic_cast<const M480JsubliInstruction&> (rhs); 
    return (    (getLineNum()      == dynRhs.getLineNum()     )
	     && (getSrc1()         == dynRhs.getSrc1()        )
	     && (getDst()          == dynRhs.getDst()         )
	     && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JsubliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  


  //---------------------------------------------
  // M480FfsInstruction
  //---------------------------------------------
  
  M480FfsInstruction&
  M480FfsInstruction::operator=(const M480FfsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpFindInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480FfsInstruction::equalTo(const LlirNode& rhs) const
  {
    M480FfsInstruction dynRhs = 
      dynamic_cast<const M480FfsInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum() )
	     && (getSrc1()     == dynRhs.getSrc1()    )
	     && (getDst()      == dynRhs.getDst()     )
	     && (getAbcFlag()  == dynRhs.getAbcFlag() )
	     && (getFindFlag() == dynRhs.getFindFlag()) );
  }
  
  void 
  M480FfsInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480FlsInstruction
  //---------------------------------------------
  
  M480FlsInstruction&
  M480FlsInstruction::operator=(const M480FlsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpFindInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480FlsInstruction::equalTo(const LlirNode& rhs) const
  {
    M480FlsInstruction dynRhs = 
      dynamic_cast<const M480FlsInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum() )
	     && (getSrc1()     == dynRhs.getSrc1()    )
	     && (getDst()      == dynRhs.getDst()     )
	     && (getAbcFlag()  == dynRhs.getAbcFlag() )
	     && (getFindFlag() == dynRhs.getFindFlag()) );
  }
  
  void 
  M480FlsInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ParInstruction
  //---------------------------------------------
 

  bool 
   M480ParInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480ParInstruction::getNumDelaySlots() const
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
  M480ParInstruction::isAbcInsn() const
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
  M480ParInstruction::isBranchInsn() const
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
  M480ParInstruction::isValidDslotInsn() const
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
  M480ParInstruction::hasValidAbcFlag() const
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
  M480ParInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  M480ParInstruction&
  M480ParInstruction::operator=(const M480ParInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpInstruction::operator=(rhs);
    m_abcFlag  = rhs.m_abcFlag;
    return *this;
    
  }
  
  bool
  M480ParInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ParInstruction dynRhs = 
      dynamic_cast<const M480ParInstruction&> (rhs); 
    return (    (getLineNum()  == dynRhs.getLineNum())
	     && (getSrc1()     == dynRhs.getSrc1()   )
	     && (getDst()      == dynRhs.getDst()    )
	     && (getAbcFlag()  == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ParInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddInstruction
  //---------------------------------------------
  
  M480AddInstruction&
  M480AddInstruction::operator=(const M480AddInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddInstruction dynRhs = 
      dynamic_cast<const M480AddInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag())
	     && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480AddInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480Add4xInstruction
  //---------------------------------------------
  
  M480Add4xInstruction&
  M480Add4xInstruction::operator=(const M480Add4xInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480Add4xInstruction::equalTo(const LlirNode& rhs) const
  {
    M480Add4xInstruction dynRhs = 
      dynamic_cast<const M480Add4xInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480Add4xInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddcInstruction
  //---------------------------------------------
  
  M480AddcInstruction&
  M480AddcInstruction::operator=(const M480AddcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddcInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddcInstruction dynRhs = 
      dynamic_cast<const M480AddcInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480AddcInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AndInstruction
  //---------------------------------------------
  
  M480AndInstruction&
  M480AndInstruction::operator=(const M480AndInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AndInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AndInstruction dynRhs = 
      dynamic_cast<const M480AndInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480AndInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MaxInstruction
  //---------------------------------------------
  
  M480MaxInstruction&
  M480MaxInstruction::operator=(const M480MaxInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MaxInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MaxInstruction dynRhs = 
      dynamic_cast<const M480MaxInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480MaxInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MinInstruction
  //---------------------------------------------
  
  M480MinInstruction&
  M480MinInstruction::operator=(const M480MinInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MinInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MinInstruction dynRhs = 
      dynamic_cast<const M480MinInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480MinInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480OrInstruction
  //---------------------------------------------
  
  M480OrInstruction&
  M480OrInstruction::operator=(const M480OrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480OrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480OrInstruction dynRhs = 
      dynamic_cast<const M480OrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480OrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubInstruction
  //---------------------------------------------
  
  M480SubInstruction&
  M480SubInstruction::operator=(const M480SubInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubInstruction dynRhs = 
      dynamic_cast<const M480SubInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480SubInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubbInstruction
  //---------------------------------------------
  
  M480SubbInstruction&
  M480SubbInstruction::operator=(const M480SubbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubbInstruction dynRhs = 
      dynamic_cast<const M480SubbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480SubbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480XorInstruction
  //---------------------------------------------
  
  M480XorInstruction&
  M480XorInstruction::operator=(const M480XorInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480XorInstruction::equalTo(const LlirNode& rhs) const
  {
    M480XorInstruction dynRhs = 
      dynamic_cast<const M480XorInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480XorInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddiInstruction
  //---------------------------------------------
  
  M480AddiInstruction&
  M480AddiInstruction::operator=(const M480AddiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddiInstruction dynRhs = 
      dynamic_cast<const M480AddiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480AddiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddciInstruction
  //---------------------------------------------
  
  M480AddciInstruction&
  M480AddciInstruction::operator=(const M480AddciInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddciInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddciInstruction dynRhs = 
      dynamic_cast<const M480AddciInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480AddciInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubiInstruction
  //---------------------------------------------
  
  M480SubiInstruction&
  M480SubiInstruction::operator=(const M480SubiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubiInstruction dynRhs = 
      dynamic_cast<const M480SubiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480SubiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SubbiInstruction
  //---------------------------------------------
  
  M480SubbiInstruction&
  M480SubbiInstruction::operator=(const M480SubbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcModInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SubbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SubbiInstruction dynRhs = 
      dynamic_cast<const M480SubbiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
             && (getSrc1()    == dynRhs.getSrc1()   )
             && (getSrc2()    == dynRhs.getSrc2()   )
             && (getDst()     == dynRhs.getDst()    )
             && (getAbcFlag() == dynRhs.getAbcFlag())
             && (getModFlag() == dynRhs.getModFlag()) );
  }
  
  void 
  M480SubbiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480RandInstruction
  //---------------------------------------------
  
  M480RandInstruction&
  M480RandInstruction::operator=(const M480RandInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RandInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RandInstruction dynRhs = 
      dynamic_cast<const M480RandInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480RandInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480RotlInstruction
  //---------------------------------------------
  
  M480RotlInstruction&
  M480RotlInstruction::operator=(const M480RotlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RotlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RotlInstruction dynRhs = 
      dynamic_cast<const M480RotlInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480RotlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480RotrInstruction
  //---------------------------------------------
  
  M480RotrInstruction&
  M480RotrInstruction::operator=(const M480RotrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RotrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RotrInstruction dynRhs = 
      dynamic_cast<const M480RotrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480RotrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ClrbInstruction
  //---------------------------------------------
  
  M480ClrbInstruction&
  M480ClrbInstruction::operator=(const M480ClrbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ClrbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ClrbInstruction dynRhs = 
      dynamic_cast<const M480ClrbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ClrbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SetbInstruction
  //---------------------------------------------
  
  M480SetbInstruction&
  M480SetbInstruction::operator=(const M480SetbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SetbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SetbInstruction dynRhs = 
      dynamic_cast<const M480SetbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480SetbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShftInstruction
  //---------------------------------------------
  
  M480ShftInstruction&
  M480ShftInstruction::operator=(const M480ShftInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShftInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShftInstruction dynRhs = 
      dynamic_cast<const M480ShftInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShftInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShftaInstruction
  //---------------------------------------------
  
  M480ShftaInstruction&
  M480ShftaInstruction::operator=(const M480ShftaInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShftaInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShftaInstruction dynRhs = 
      dynamic_cast<const M480ShftaInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShftaInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShlInstruction
  //---------------------------------------------
  
  M480ShlInstruction&
  M480ShlInstruction::operator=(const M480ShlInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShlInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShlInstruction dynRhs = 
      dynamic_cast<const M480ShlInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShlInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShrInstruction
  //---------------------------------------------
  
  M480ShrInstruction&
  M480ShrInstruction::operator=(const M480ShrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShrInstruction dynRhs = 
      dynamic_cast<const M480ShrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShraInstruction
  //---------------------------------------------
  
  M480ShraInstruction&
  M480ShraInstruction::operator=(const M480ShraInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShraInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShraInstruction dynRhs = 
      dynamic_cast<const M480ShraInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShraInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480RandiInstruction
  //---------------------------------------------
  
  M480RandiInstruction&
  M480RandiInstruction::operator=(const M480RandiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RandiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RandiInstruction dynRhs = 
      dynamic_cast<const M480RandiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480RandiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480RotliInstruction
  //---------------------------------------------
  
  M480RotliInstruction&
  M480RotliInstruction::operator=(const M480RotliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RotliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RotliInstruction dynRhs = 
      dynamic_cast<const M480RotliInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480RotliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480RotriInstruction
  //---------------------------------------------
  
  M480RotriInstruction&
  M480RotriInstruction::operator=(const M480RotriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RotriInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RotriInstruction dynRhs = 
      dynamic_cast<const M480RotriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480RotriInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SetbiInstruction
  //---------------------------------------------
  
  M480SetbiInstruction&
  M480SetbiInstruction::operator=(const M480SetbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480SetbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SetbiInstruction dynRhs = 
      dynamic_cast<const M480SetbiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480SetbiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480ClrbiInstruction
  //---------------------------------------------
  
  M480ClrbiInstruction&
  M480ClrbiInstruction::operator=(const M480ClrbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ClrbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ClrbiInstruction dynRhs = 
      dynamic_cast<const M480ClrbiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ClrbiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  
  //---------------------------------------------
  // M480ShliInstruction
  //---------------------------------------------
  
  M480ShliInstruction&
  M480ShliInstruction::operator=(const M480ShliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShliInstruction dynRhs = 
      dynamic_cast<const M480ShliInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShriInstruction
  //---------------------------------------------
  
  M480ShriInstruction&
  M480ShriInstruction::operator=(const M480ShriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShriInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShriInstruction dynRhs = 
      dynamic_cast<const M480ShriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShriInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ShraiInstruction
  //---------------------------------------------
  
  M480ShraiInstruction&
  M480ShraiInstruction::operator=(const M480ShraiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480ShraiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ShraiInstruction dynRhs = 
      dynamic_cast<const M480ShraiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480ShraiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480MaxiInstruction
  //---------------------------------------------
  
  M480MaxiInstruction&
  M480MaxiInstruction::operator=(const M480MaxiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MaxiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MaxiInstruction dynRhs = 
      dynamic_cast<const M480MaxiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480MaxiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MiniInstruction
  //---------------------------------------------
  
  M480MiniInstruction&
  M480MiniInstruction::operator=(const M480MiniInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MiniInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MiniInstruction dynRhs = 
      dynamic_cast<const M480MiniInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480MiniInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AndiInstruction
  //---------------------------------------------
  
  M480AndiInstruction&
  M480AndiInstruction::operator=(const M480AndiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AndiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AndiInstruction dynRhs = 
      dynamic_cast<const M480AndiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480AndiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480OriInstruction
  //---------------------------------------------
  
  M480OriInstruction&
  M480OriInstruction::operator=(const M480OriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480OriInstruction::equalTo(const LlirNode& rhs) const
  {
    M480OriInstruction dynRhs = 
      dynamic_cast<const M480OriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480OriInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480XoriInstruction
  //---------------------------------------------
  
  M480XoriInstruction&
  M480XoriInstruction::operator=(const M480XoriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpAbcInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480XoriInstruction::equalTo(const LlirNode& rhs) const
  {
    M480XoriInstruction dynRhs = 
      dynamic_cast<const M480XoriInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getAbcFlag() == dynRhs.getAbcFlag()) );
  }
  
  void 
  M480XoriInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MulInstruction
  //---------------------------------------------
  
  M480MulInstruction&
  M480MulInstruction::operator=(const M480MulInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MulInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MulInstruction dynRhs = 
      dynamic_cast<const M480MulInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M480MulInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MulhInstruction
  //---------------------------------------------
  
  M480MulhInstruction&
  M480MulhInstruction::operator=(const M480MulhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MulhInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MulhInstruction dynRhs = 
      dynamic_cast<const M480MulhInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M480MulhInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480MuliInstruction
  //---------------------------------------------
  
  M480MuliInstruction&
  M480MuliInstruction::operator=(const M480MuliInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MuliInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MuliInstruction dynRhs = 
      dynamic_cast<const M480MuliInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M480MuliInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MulhiInstruction
  //---------------------------------------------
  
  M480MulhiInstruction&
  M480MulhiInstruction::operator=(const M480MulhiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpSxInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480MulhiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MulhiInstruction dynRhs = 
      dynamic_cast<const M480MulhiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getSxFlag()  == dynRhs.getSxFlag() ) );
  }
  
  void 
  M480MulhiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480AddneInstruction
  //---------------------------------------------


  bool 
  M480AddneInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480AddneInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M480AddneInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M480AddneInstruction::isValidDslotInsn() const
  {
    return true;
  }

  M480AddneInstruction&
  M480AddneInstruction::operator=(const M480AddneInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddneInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddneInstruction dynRhs = 
      dynamic_cast<const M480AddneInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480AddneInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480AddneiInstruction
  //---------------------------------------------

  bool 
  M480AddneiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480AddneiInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M480AddneiInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M480AddneiInstruction::isValidDslotInsn() const
  {
    return true;
  }

  M480AddneiInstruction&
  M480AddneiInstruction::operator=(const M480AddneiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu3OpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480AddneiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480AddneiInstruction dynRhs = 
      dynamic_cast<const M480AddneiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480AddneiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ByteswInstruction
  //---------------------------------------------

  bool 
  M480ByteswInstruction::isPseudoInsn() const
  {
    return false;
  }

   unsigned int
  M480ByteswInstruction::getNumDelaySlots() const
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
  M480ByteswInstruction::isAbcInsn() const
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
  M480ByteswInstruction::isValidDslotInsn() const
  {
    return true;
  }

  bool
  M480ByteswInstruction::hasValidAbcFlag() const
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
  M480ByteswInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  RegPtr
  M480ByteswInstruction::getDst() const
  {
    return m_dst;
  }
  
  UImmPtr
  M480ByteswInstruction::getB0() const
  {
    return m_b0;
  }
  
  UImmPtr
  M480ByteswInstruction::getB1() const
  {
    return m_b1;
  }
  
  UImmPtr
  M480ByteswInstruction::getB2() const
  {
    return m_b2;
  }
  
  UImmPtr
  M480ByteswInstruction::getB3() const
  {
    return m_b3;
  }
  
  OpndPtr
  M480ByteswInstruction::getAbcFlag() const
  {
    return m_abcFlag;
  }
  
  M480ByteswInstruction&
  M480ByteswInstruction::operator=(const M480ByteswInstruction& rhs)
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
  M480ByteswInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ByteswInstruction dynRhs = 
      dynamic_cast<const M480ByteswInstruction&> (rhs); 
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
  M480ByteswInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480DepbInstruction
  //---------------------------------------------

  OpndPtr
  M480DepbInstruction::getDepbFlag() const
  {
    return m_depbFlag;
  }
  
  M480DepbInstruction&
  M480DepbInstruction::operator=(const M480DepbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BitOpInstruction::operator=(rhs);
    m_depbFlag = rhs.m_depbFlag;
    return *this;
    
  }
  
  bool
  M480DepbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480DepbInstruction dynRhs = 
      dynamic_cast<const M480DepbInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getSrc1()      == dynRhs.getSrc1()     )
            && (getSrcBitNum() == dynRhs.getSrcBitNum())
            && (getDst()       == dynRhs.getDst()      ) 
            && (getDstBitNum() == dynRhs.getDstBitNum()) 
            && (getNumBits()   == dynRhs.getNumBits()  )
	    && (getDepbFlag()  == dynRhs.getDepbFlag() ) );
  }
  
  void 
  M480DepbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480ExtbInstruction
  //---------------------------------------------
  
  OpndPtr
  M480ExtbInstruction::getSignFlag() const
  {
    return m_sign;
  }
  
  M480ExtbInstruction&
  M480ExtbInstruction::operator=(const M480ExtbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BitOpInstruction::operator=(rhs);
    m_sign = rhs.m_sign;
    return *this;
    
  }
  
  bool
  M480ExtbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480ExtbInstruction dynRhs = 
      dynamic_cast<const M480ExtbInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getSrc1()      == dynRhs.getSrc1()     )
            && (getSrcBitNum() == dynRhs.getSrcBitNum())
            && (getDst()       == dynRhs.getDst()      ) 
            && (getDstBitNum() == dynRhs.getDstBitNum()) 
            && (getNumBits()   == dynRhs.getNumBits()  )
	    && (getSignFlag()  == dynRhs.getSignFlag() ) );
  }
  
  void 
  M480ExtbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480DepbiInstruction
  //---------------------------------------------
  
  OpndPtr
  M480DepbiInstruction::getDepbFlag() const
  {
    return m_depbFlag;
  }
  
  M480DepbiInstruction&
  M480DepbiInstruction::operator=(const M480DepbiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BitOpImmInstruction::operator=(rhs);
    m_depbFlag = rhs.m_depbFlag;
    return *this;
    
  }
  
  bool
  M480DepbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480DepbiInstruction dynRhs = 
      dynamic_cast<const M480DepbiInstruction&> (rhs); 
    return (   (getLineNum()   == dynRhs.getLineNum()  )
            && (getSrc1()      == dynRhs.getSrc1()     )
            && (getDst()       == dynRhs.getDst()      ) 
            && (getDstBitNum() == dynRhs.getDstBitNum()) 
            && (getNumBits()   == dynRhs.getNumBits()  )
	    && (getDepbFlag()  == dynRhs.getDepbFlag() ) );
  }
  
  void 
  M480DepbiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480CmovInstruction
  //---------------------------------------------
  
  M480CmovInstruction&
  M480CmovInstruction::operator=(const M480CmovInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CmovOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480CmovInstruction::equalTo(const LlirNode& rhs) const
  {
    M480CmovInstruction dynRhs = 
      dynamic_cast<const M480CmovInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum())
            && (getSrc1()     == dynRhs.getSrc1()   )
            && (getSrc2()     == dynRhs.getSrc2()   )
            && (getDst()      == dynRhs.getDst()    ) 
	    && (getEssFlag()  == dynRhs.getEssFlag()) );
  }
  
  void 
  M480CmovInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480CmoviInstruction
  //---------------------------------------------
  
  M480CmoviInstruction&
  M480CmoviInstruction::operator=(const M480CmoviInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CmovOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480CmoviInstruction::equalTo(const LlirNode& rhs) const
  {
    M480CmoviInstruction dynRhs = 
      dynamic_cast<const M480CmoviInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum())
            && (getSrc1()     == dynRhs.getSrc1()   )
            && (getSrc2()     == dynRhs.getSrc2()   )
            && (getDst()      == dynRhs.getDst()    ) 
	    && (getEssFlag()  == dynRhs.getEssFlag()) );
  }
  
  void 
  M480CmoviInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480DmapInstruction
  //---------------------------------------------
  
  M480DmapInstruction&
  M480DmapInstruction::operator=(const M480DmapInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480DmapInstruction::equalTo(const LlirNode& rhs) const
  {
    M480DmapInstruction dynRhs = 
      dynamic_cast<const M480DmapInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M480DmapInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480DmasrInstruction
  //---------------------------------------------
  
  M480DmasrInstruction&
  M480DmasrInstruction::operator=(const M480DmasrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480DmasrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480DmasrInstruction dynRhs = 
      dynamic_cast<const M480DmasrInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M480DmasrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480Dmau0Instruction
  //---------------------------------------------
  
  M480Dmau0Instruction&
  M480Dmau0Instruction::operator=(const M480Dmau0Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480Dmau0Instruction::equalTo(const LlirNode& rhs) const
  {
    M480Dmau0Instruction dynRhs = 
      dynamic_cast<const M480Dmau0Instruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M480Dmau0Instruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480Dmau1Instruction
  //---------------------------------------------
  
  M480Dmau1Instruction&
  M480Dmau1Instruction::operator=(const M480Dmau1Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    DmaOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480Dmau1Instruction::equalTo(const LlirNode& rhs) const
  {
    M480Dmau1Instruction dynRhs = 
      dynamic_cast<const M480Dmau1Instruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
	    && (getDmaFlags() == dynRhs.getDmaFlags()) );
  }
  
  void 
  M480Dmau1Instruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LihInstruction
  //---------------------------------------------
  
  M480LihInstruction&
  M480LihInstruction::operator=(const M480LihInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LihInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LihInstruction dynRhs = 
      dynamic_cast<const M480LihInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M480LihInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LilInstruction
  //---------------------------------------------
  
  M480LilInstruction&
  M480LilInstruction::operator=(const M480LilInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LilInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LilInstruction dynRhs = 
      dynamic_cast<const M480LilInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M480LilInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LaihInstruction
  //---------------------------------------------
  
  M480LaihInstruction&
  M480LaihInstruction::operator=(const M480LaihInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LaihInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LaihInstruction dynRhs = 
      dynamic_cast<const M480LaihInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M480LaihInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LailInstruction
  //---------------------------------------------
  
  M480LailInstruction&
  M480LailInstruction::operator=(const M480LailInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadImmediateInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LailInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LailInstruction dynRhs = 
      dynamic_cast<const M480LailInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M480LailInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LwihInstruction
  //---------------------------------------------
  
  M480LwihInstruction&
  M480LwihInstruction::operator=(const M480LwihInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadHalfwordInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LwihInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LwihInstruction dynRhs = 
      dynamic_cast<const M480LwihInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M480LwihInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LwilInstruction
  //---------------------------------------------
  
  M480LwilInstruction&
  M480LwilInstruction::operator=(const M480LwilInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    LoadHalfwordInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LwilInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LwilInstruction dynRhs = 
      dynamic_cast<const M480LwilInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getDst()     == dynRhs.getDst()    )
	    && (getSrc()     == dynRhs.getSrc()    ) );
  }
  
  void 
  M480LwilInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480NopInstruction
  //---------------------------------------------

  bool 
  M480NopInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480NopInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M480NopInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M480NopInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  M480NopInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }

  M480NopInstruction&
  M480NopInstruction::operator=(const M480NopInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480NopInstruction::equalTo(const LlirNode& rhs) const
  {
    M480NopInstruction dynRhs = 
      dynamic_cast<const M480NopInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M480NopInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480Hec5Instruction
  //---------------------------------------------
  
  UImmPtr
  M480Hec5Instruction::getBytes() const
  {
    return m_bytes;
  }
  
  OpndPtr
  M480Hec5Instruction::getCumeFlag() const
  {
    return m_cumeFlag;
  }
  
  M480Hec5Instruction&
  M480Hec5Instruction::operator=(const M480Hec5Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    m_bytes        = rhs.m_bytes;
    m_cumeFlag     = rhs.m_cumeFlag;
    return *this;
    
  }
  
  bool
  M480Hec5Instruction::equalTo(const LlirNode& rhs) const
  {
    M480Hec5Instruction dynRhs = 
      dynamic_cast<const M480Hec5Instruction&> (rhs);
 
    return ((getLineNum()      == dynRhs.getLineNum())
	    && (getSrc1()          == dynRhs.getSrc1())
	    && (getDst()          == dynRhs.getDst()) 
	    && (getBytes()        == dynRhs.getBytes()) 
	    && (getBranchTarget() == dynRhs.getBranchTarget())
	    && (getCumeFlag()     == dynRhs.getCumeFlag()));
  }
  
  void 
  M480Hec5Instruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    
  //---------------------------------------------
  // M480JHec5Instruction
  //---------------------------------------------
  
  UImmPtr
  M480JHec5Instruction::getBytes() const
  {
    return m_bytes;
  }
  
  OpndPtr
  M480JHec5Instruction::getCumeFlag() const
  {
    return m_cumeFlag;
  }
  
  M480JHec5Instruction&
  M480JHec5Instruction::operator=(const M480JHec5Instruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    Alu2OpBranchInstruction::operator=(rhs);
    m_bytes        = rhs.m_bytes;
    m_cumeFlag     = rhs.m_cumeFlag;
    return *this;
    
  }
  
  bool
  M480JHec5Instruction::equalTo(const LlirNode& rhs) const
  {
    M480JHec5Instruction dynRhs = 
      dynamic_cast<const M480JHec5Instruction&> (rhs);
 
    return ((getLineNum()      == dynRhs.getLineNum())
	    && (getSrc1()          == dynRhs.getSrc1())
	    && (getDst()          == dynRhs.getDst()) 
	    && (getBytes()        == dynRhs.getBytes()) 
	    && (getBranchTarget() == dynRhs.getBranchTarget())
	    && (getCumeFlag()     == dynRhs.getCumeFlag())
	    && (getBranchProbability() == dynRhs.getBranchProbability()));
  }
  
  void 
  M480JHec5Instruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480MvInstruction
  //---------------------------------------------

  bool 
  M480MvInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480MvInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M480MvInstruction::isAbcInsn() const
  {
    return false;
  }

  bool
  M480MvInstruction::isValidDslotInsn() const
  {
    return true;
  }

  OctaveInstruction::BranchProbability 
  M480MvInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }


  RegPtr
  M480MvInstruction::getSrc() const
  {
    return m_src;
  }
  
  RegPtr
  M480MvInstruction::getDst() const
  {
    return m_dst;
  }
  
  M480MvInstruction&
  M480MvInstruction::operator=(const M480MvInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    m_src = rhs.m_src;
    m_dst = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M480MvInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MvInstruction dynRhs = 
      dynamic_cast<const M480MvInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc()     == dynRhs.getSrc()    )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480MvInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MvhrInstruction
  //---------------------------------------------
  
  M480MvhrInstruction&
  M480MvhrInstruction::operator=(const M480MvhrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MvhOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480MvhrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MvhrInstruction dynRhs = 
      dynamic_cast<const M480MvhrInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M480MvhrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480MvrhInstruction
  //---------------------------------------------
  
  M480MvrhInstruction&
  M480MvrhInstruction::operator=(const M480MvrhInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MvhOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480MvrhInstruction::equalTo(const LlirNode& rhs) const
  {
    M480MvrhInstruction dynRhs = 
      dynamic_cast<const M480MvrhInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M480MvrhInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480UnlinkInstruction
  //---------------------------------------------
  
  M480UnlinkInstruction&
  M480UnlinkInstruction::operator=(const M480UnlinkInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480UnlinkInstruction::equalTo(const LlirNode& rhs) const
  {
    M480UnlinkInstruction dynRhs = 
      dynamic_cast<const M480UnlinkInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
	    && (getRegs()    == dynRhs.getRegs()   ) );
  }
  
  void 
  M480UnlinkInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LinkInstruction
  //---------------------------------------------
  
  M480LinkInstruction&
  M480LinkInstruction::operator=(const M480LinkInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinkInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinkInstruction dynRhs = 
      dynamic_cast<const M480LinkInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinkInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LinksInstruction
  //---------------------------------------------
  
  M480LinksInstruction&
  M480LinksInstruction::operator=(const M480LinksInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinksInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinksInstruction dynRhs = 
      dynamic_cast<const M480LinksInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinksInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  
  //---------------------------------------------
  // M480LinkspInstruction
  //---------------------------------------------
  
  M480LinkspInstruction&
  M480LinkspInstruction::operator=(const M480LinkspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinkspInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinkspInstruction dynRhs = 
      dynamic_cast<const M480LinkspInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinkspInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
     
  
  //---------------------------------------------
  // M480LinksplInstruction
  //---------------------------------------------
  
  M480LinksplInstruction&
  M480LinksplInstruction::operator=(const M480LinksplInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinksplInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinksplInstruction dynRhs = 
      dynamic_cast<const M480LinksplInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinksplInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

   
  
  //---------------------------------------------
  // M480LinksrInstruction
  //---------------------------------------------
  
  M480LinksrInstruction&
  M480LinksrInstruction::operator=(const M480LinksrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinksrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinksrInstruction dynRhs = 
      dynamic_cast<const M480LinksrInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinksrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480LinksdInstruction
  //---------------------------------------------
  
  M480LinksdInstruction&
  M480LinksdInstruction::operator=(const M480LinksdInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinksdInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinksdInstruction dynRhs = 
      dynamic_cast<const M480LinksdInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinksdInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480LinkccInstruction
  //---------------------------------------------
  
  M480LinkccInstruction&
  M480LinkccInstruction::operator=(const M480LinkccInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinkccInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinkccInstruction dynRhs = 
      dynamic_cast<const M480LinkccInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinkccInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480LinkcclInstruction
  //---------------------------------------------
  
  M480LinkcclInstruction&
  M480LinkcclInstruction::operator=(const M480LinkcclInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinkcclInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinkcclInstruction dynRhs = 
      dynamic_cast<const M480LinkcclInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinkcclInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
 
  //---------------------------------------------
  // M480LinksioInstruction
  //---------------------------------------------
  
  M480LinksioInstruction&
  M480LinksioInstruction::operator=(const M480LinksioInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLinkInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LinksioInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LinksioInstruction dynRhs = 
      dynamic_cast<const M480LinksioInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LinksioInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480LmmInstruction
  //---------------------------------------------
  
  M480LmmInstruction&
  M480LmmInstruction::operator=(const M480LmmInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmInstruction dynRhs = 
      dynamic_cast<const M480LmmInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  //---------------------------------------------
  // M480LmmspInstruction
  //---------------------------------------------
  
  M480LmmspInstruction&
  M480LmmspInstruction::operator=(const M480LmmspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmspInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmspInstruction dynRhs = 
      dynamic_cast<const M480LmmspInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmspInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480LmmsplInstruction
  //---------------------------------------------
  
  M480LmmsplInstruction&
  M480LmmsplInstruction::operator=(const M480LmmsplInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmsplInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmsplInstruction dynRhs = 
      dynamic_cast<const M480LmmsplInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmsplInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  //---------------------------------------------
  // M480LmmsrInstruction
  //---------------------------------------------
  
  M480LmmsrInstruction&
  M480LmmsrInstruction::operator=(const M480LmmsrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmsrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmsrInstruction dynRhs = 
      dynamic_cast<const M480LmmsrInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmsrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  //---------------------------------------------
  // M480LmmsdInstruction
  //---------------------------------------------
  
  M480LmmsdInstruction&
  M480LmmsdInstruction::operator=(const M480LmmsdInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmsdInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmsdInstruction dynRhs = 
      dynamic_cast<const M480LmmsdInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmsdInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  //---------------------------------------------
  // M480LmmccInstruction
  //---------------------------------------------
  
  M480LmmccInstruction&
  M480LmmccInstruction::operator=(const M480LmmccInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmccInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmccInstruction dynRhs = 
      dynamic_cast<const M480LmmccInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmccInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480LmmcclInstruction
  //---------------------------------------------
  
  M480LmmcclInstruction&
  M480LmmcclInstruction::operator=(const M480LmmcclInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmcclInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmcclInstruction dynRhs = 
      dynamic_cast<const M480LmmcclInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmcclInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480LmmsiInstruction
  //---------------------------------------------
  
  M480LmmsiInstruction&
  M480LmmsiInstruction::operator=(const M480LmmsiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmsiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmsiInstruction dynRhs = 
      dynamic_cast<const M480LmmsiInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmsiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480LmmsInstruction
  //---------------------------------------------
  
  M480LmmsInstruction&
  M480LmmsInstruction::operator=(const M480LmmsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LmmsInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LmmsInstruction dynRhs = 
      dynamic_cast<const M480LmmsInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LmmsInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480LspInstruction
  //---------------------------------------------
  
  M480LspInstruction&
  M480LspInstruction::operator=(const M480LspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegLoadInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480LspInstruction::equalTo(const LlirNode& rhs) const
  {
    M480LspInstruction dynRhs = 
      dynamic_cast<const M480LspInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRegs()     == dynRhs.getRegs()    )
            && (getMem()      == dynRhs.getMem()     )
            && (getLinkFlag() == dynRhs.getLinkFlag()) );
  }
  
  void 
  M480LspInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480SmmInstruction
  //---------------------------------------------
  
  M480SmmInstruction&
  M480SmmInstruction::operator=(const M480SmmInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmInstruction dynRhs = 
      dynamic_cast<const M480SmmInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480SmmspInstruction
  //---------------------------------------------
  
  M480SmmspInstruction&
  M480SmmspInstruction::operator=(const M480SmmspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmspInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmspInstruction dynRhs = 
      dynamic_cast<const M480SmmspInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmspInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480SmmsplInstruction
  //---------------------------------------------
  
  M480SmmsplInstruction&
  M480SmmsplInstruction::operator=(const M480SmmsplInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmsplInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmsplInstruction dynRhs = 
      dynamic_cast<const M480SmmsplInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmsplInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  //---------------------------------------------
  // M480SmmsrInstruction
  //---------------------------------------------
  
  M480SmmsrInstruction&
  M480SmmsrInstruction::operator=(const M480SmmsrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmsrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmsrInstruction dynRhs = 
      dynamic_cast<const M480SmmsrInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmsrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480SmmsdInstruction
  //---------------------------------------------
  
  M480SmmsdInstruction&
  M480SmmsdInstruction::operator=(const M480SmmsdInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmsdInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmsdInstruction dynRhs = 
      dynamic_cast<const M480SmmsdInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmsdInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480SmmccInstruction
  //---------------------------------------------
  
  M480SmmccInstruction&
  M480SmmccInstruction::operator=(const M480SmmccInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmccInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmccInstruction dynRhs = 
      dynamic_cast<const M480SmmccInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmccInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480SmmcclInstruction
  //---------------------------------------------
  
  M480SmmcclInstruction&
  M480SmmcclInstruction::operator=(const M480SmmcclInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmcclInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmcclInstruction dynRhs = 
      dynamic_cast<const M480SmmcclInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmcclInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480SmmsiInstruction
  //---------------------------------------------
  
  M480SmmsiInstruction&
  M480SmmsiInstruction::operator=(const M480SmmsiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmsiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmsiInstruction dynRhs = 
      dynamic_cast<const M480SmmsiInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmsiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480SmmsInstruction
  //---------------------------------------------
  
  M480SmmsInstruction&
  M480SmmsInstruction::operator=(const M480SmmsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SmmsInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SmmsInstruction dynRhs = 
      dynamic_cast<const M480SmmsInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SmmsInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  
  
  //---------------------------------------------
  // M480SspInstruction
  //---------------------------------------------
  
  M480SspInstruction&
  M480SspInstruction::operator=(const M480SspInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    MultiRegStoreInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480SspInstruction::equalTo(const LlirNode& rhs) const
  {
    M480SspInstruction dynRhs = 
      dynamic_cast<const M480SspInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getRegs()    == dynRhs.getRegs()   )
            && (getMem()     == dynRhs.getMem()    ) );
  }
  
  void 
  M480SspInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480PutcInstruction
  //---------------------------------------------
  
  M480PutcInstruction&
  M480PutcInstruction::operator=(const M480PutcInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    m_rsb = rhs.m_rsb;
    return *this;
    
  }
   
  RegPtr
  M480PutcInstruction::getRsb() const
  {
    return m_rsb;
  }
  
  bool
  M480PutcInstruction::equalTo(const LlirNode& rhs) const
  {
    M480PutcInstruction dynRhs = 
      dynamic_cast<const M480PutcInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getRsb()      == dynRhs.getRsb()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M480PutcInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480PutmInstruction
  //---------------------------------------------
  
  M480PutmInstruction&
  M480PutmInstruction::operator=(const M480PutmInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    m_rsb = rhs.m_rsb;
    return *this;
    
  }
   
  RegPtr
  M480PutmInstruction::getRsb() const
  {
    return m_rsb;
  }
  
  bool
  M480PutmInstruction::equalTo(const LlirNode& rhs) const
  {
    M480PutmInstruction dynRhs = 
      dynamic_cast<const M480PutmInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getRsb()      == dynRhs.getRsb()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M480PutmInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480PutpInstruction
  //---------------------------------------------
  
  M480PutpInstruction&
  M480PutpInstruction::operator=(const M480PutpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    m_rsb = rhs.m_rsb;
    return *this;
    
  }
   
  RegPtr
  M480PutpInstruction::getRsb() const
  {
    return m_rsb;
  }
  
  bool
  M480PutpInstruction::equalTo(const LlirNode& rhs) const
  {
    M480PutpInstruction dynRhs = 
      dynamic_cast<const M480PutpInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getRsb()      == dynRhs.getRsb()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M480PutpInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480PutdInstruction
  //---------------------------------------------
  
  M480PutdInstruction&
  M480PutdInstruction::operator=(const M480PutdInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    m_rsb = rhs.m_rsb;
    return *this;
    
  }
   
  RegPtr
  M480PutdInstruction::getRsb() const
  {
    return m_rsb;
  }
  
  bool
  M480PutdInstruction::equalTo(const LlirNode& rhs) const
  {
    M480PutdInstruction dynRhs = 
      dynamic_cast<const M480PutdInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getRsb()      == dynRhs.getRsb()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M480PutdInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480GetInstruction
  //---------------------------------------------
  
  M480GetInstruction&
  M480GetInstruction::operator=(const M480GetInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TssRcOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480GetInstruction::equalTo(const LlirNode& rhs) const
  {
    M480GetInstruction dynRhs = 
      dynamic_cast<const M480GetInstruction&> (rhs); 
    return (   (getLineNum()  == dynRhs.getLineNum() )
            && (getRsa()      == dynRhs.getRsa()     )
            && (getTssFlags() == dynRhs.getTssFlags()) );
  }
  
  void 
  M480GetInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480BcdrInstruction
  //---------------------------------------------

  bool 
  M480BcdrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BcdrInstruction::getNumDelaySlots() const
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
  

  M480BcdrInstruction&
  M480BcdrInstruction::operator=(const M480BcdrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BcdrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BcdrInstruction dynRhs = 
      dynamic_cast<const M480BcdrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480BcdrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480JbcdrInstruction
  //---------------------------------------------

  bool 
  M480JbcdrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480JbcdrInstruction::getNumDelaySlots() const
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
  
  
  OpndPtr
  M480JbcdrInstruction::getTargetLabelList() const
  {
    return m_targetList;
  }
  

  M480JbcdrInstruction&
  M480JbcdrInstruction::operator=(const M480JbcdrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;

    m_targetList = rhs.m_targetList;
    CondBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbcdrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbcdrInstruction dynRhs = 
      dynamic_cast<const M480JbcdrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480JbcdrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480BcrInstruction
  //---------------------------------------------


  bool 
  M480BcrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BcrInstruction::getNumDelaySlots() const
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
  

  M480BcrInstruction&
  M480BcrInstruction::operator=(const M480BcrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BcrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BcrInstruction dynRhs = 
      dynamic_cast<const M480BcrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480BcrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    
  //---------------------------------------------
  // M480JbcrInstruction
  //---------------------------------------------
  unsigned int
  M480JbcrInstruction::getNumDelaySlots() const
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
  

  bool 
  M480JbcrInstruction::isPseudoInsn() const
  {
    return true;
  }

 
  M480JbcrInstruction&
  M480JbcrInstruction::operator=(const M480JbcrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;

    m_targetList = rhs.m_targetList;
    CondBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
    
  OpndPtr
  M480JbcrInstruction::getTargetLabelList() const
  {
    return m_targetList;
  }
  
  bool
  M480JbcrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbcrInstruction dynRhs = 
      dynamic_cast<const M480JbcrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480JbcrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480BcdiInstruction
  //---------------------------------------------
  

  bool 
  M480BcdiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BcdiInstruction::getNumDelaySlots() const
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


  M480BcdiInstruction&
  M480BcdiInstruction::operator=(const M480BcdiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BcdiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BcdiInstruction dynRhs = 
      dynamic_cast<const M480BcdiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480BcdiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JbcdiInstruction
  //---------------------------------------------
  

  bool 
  M480JbcdiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480JbcdiInstruction::getNumDelaySlots() const
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


  M480JbcdiInstruction&
  M480JbcdiInstruction::operator=(const M480JbcdiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbcdiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbcdiInstruction dynRhs = 
      dynamic_cast<const M480JbcdiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480JbcdiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480BciInstruction
  //---------------------------------------------


  bool 
  M480BciInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BciInstruction::getNumDelaySlots() const
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

  
  M480BciInstruction&
  M480BciInstruction::operator=(const M480BciInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BciInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BciInstruction dynRhs = 
      dynamic_cast<const M480BciInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480BciInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JbciInstruction
  //---------------------------------------------


  bool 
  M480JbciInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbciInstruction::getNumDelaySlots() const
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

  
  M480JbciInstruction&
  M480JbciInstruction::operator=(const M480JbciInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CondBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbciInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbciInstruction dynRhs = 
      dynamic_cast<const M480JbciInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getEss()     == dynRhs.getEss()    )
	     && (getDst()     == dynRhs.getDst()    )
	     && (getFlags()   == dynRhs.getFlags()  ) );
  }
  
  void 
  M480JbciInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480BnzrInstruction
  //---------------------------------------------


  bool 
  M480BnzrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BnzrInstruction::getNumDelaySlots() const
  {
    return 2;
  }

  

  M480BnzrInstruction&
  M480BnzrInstruction::operator=(const M480BnzrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BnzrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BnzrInstruction dynRhs = 
      dynamic_cast<const M480BnzrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480BnzrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    
  //---------------------------------------------
  // M480JbnzrInstruction
  //---------------------------------------------


  bool 
  M480JbnzrInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbnzrInstruction::getNumDelaySlots() const
  {
    return 2;
  }
  
  OpndPtr
  M480JbnzrInstruction::getTargetLabelList() const
  {
    return m_targetList;
  }
  

  M480JbnzrInstruction&
  M480JbnzrInstruction::operator=(const M480JbnzrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    m_targetList = rhs.m_targetList;
    ZeroBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbnzrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbnzrInstruction dynRhs = 
      dynamic_cast<const M480JbnzrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480JbnzrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480BzrInstruction
  //---------------------------------------------


  bool 
  M480BzrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BzrInstruction::getNumDelaySlots() const
  {
    return 2;
  }

  

  M480BzrInstruction&
  M480BzrInstruction::operator=(const M480BzrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BzrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BzrInstruction dynRhs = 
      dynamic_cast<const M480BzrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480BzrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JbzrInstruction
  //---------------------------------------------


  bool 
  M480JbzrInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbzrInstruction::getNumDelaySlots() const
  {
    return 2;
  }

  OpndPtr
  M480JbzrInstruction::getTargetLabelList() const
  {
    return m_targetList;
  }

  M480JbzrInstruction&
  M480JbzrInstruction::operator=(const M480JbzrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    m_targetList = rhs.m_targetList;
    ZeroBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbzrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbzrInstruction dynRhs = 
      dynamic_cast<const M480JbzrInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480JbzrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480BnziInstruction
  //---------------------------------------------
  

  bool 
  M480BnziInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BnziInstruction::getNumDelaySlots() const
  {
    return 2;
  }




  M480BnziInstruction&
  M480BnziInstruction::operator=(const M480BnziInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BnziInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BnziInstruction dynRhs = 
      dynamic_cast<const M480BnziInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480BnziInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
    
  //---------------------------------------------
  // M480JbnziInstruction
  //---------------------------------------------
  

  bool 
  M480JbnziInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbnziInstruction::getNumDelaySlots() const
  {
    return 2;
  }




  M480JbnziInstruction&
  M480JbnziInstruction::operator=(const M480JbnziInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbnziInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbnziInstruction dynRhs = 
      dynamic_cast<const M480JbnziInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   )
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480JbnziInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480BziInstruction
  //---------------------------------------------
  

  bool 
  M480BziInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BziInstruction::getNumDelaySlots() const
  {
    return 2;
  }



  M480BziInstruction&
  M480BziInstruction::operator=(const M480BziInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480BziInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BziInstruction dynRhs = 
      dynamic_cast<const M480BziInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   ) 
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480BziInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
   
  //---------------------------------------------
  // M480JbziInstruction
  //---------------------------------------------
  

  bool 
  M480JbziInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbziInstruction::getNumDelaySlots() const
  {
    return 2;
  }



  M480JbziInstruction&
  M480JbziInstruction::operator=(const M480JbziInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ZeroBranchImmedInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JbziInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbziInstruction dynRhs = 
      dynamic_cast<const M480JbziInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getSrc2()    == dynRhs.getSrc2()   ) 
	     && (getCmpReg() == dynRhs.getCmpReg()));
  }
  
  void 
  M480JbziInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480TsetbInstruction
  //---------------------------------------------
  
  M480TsetbInstruction&
  M480TsetbInstruction::operator=(const M480TsetbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TestBitBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480TsetbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480TsetbInstruction dynRhs = 
      dynamic_cast<const M480TsetbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getBitpos()  == dynRhs.getBitpos() )
	     && (getDisp()    == dynRhs.getDisp()   ) );
  }
  
  void 
  M480TsetbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480JtsetbInstruction
  //---------------------------------------------

  bool 
  M480JtsetbInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JtsetbInstruction&
  M480JtsetbInstruction::operator=(const M480JtsetbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TestBitBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JtsetbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JtsetbInstruction dynRhs = 
      dynamic_cast<const M480JtsetbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getBitpos()  == dynRhs.getBitpos() )
	     && (getDisp()    == dynRhs.getDisp()   ) );
  }
  
  void 
  M480JtsetbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  
  //---------------------------------------------
  // M480TclrbInstruction
  //---------------------------------------------
  
  M480TclrbInstruction&
  M480TclrbInstruction::operator=(const M480TclrbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TestBitBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480TclrbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480TclrbInstruction dynRhs = 
      dynamic_cast<const M480TclrbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getBitpos()  == dynRhs.getBitpos() )
	     && (getDisp()    == dynRhs.getDisp()   ) );
  }
  
  void 
  M480TclrbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  
  //---------------------------------------------
  // M480JtclrbInstruction
  //---------------------------------------------
  

  bool 
  M480JtclrbInstruction::isPseudoInsn() const
  {
    return true;
  }

  M480JtclrbInstruction&
  M480JtclrbInstruction::operator=(const M480JtclrbInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    TestBitBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JtclrbInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JtclrbInstruction dynRhs = 
      dynamic_cast<const M480JtclrbInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getSrc1()    == dynRhs.getSrc1()   )
	     && (getBitpos()  == dynRhs.getBitpos() )
	     && (getDisp()    == dynRhs.getDisp()   ) );
  }
  
  void 
  M480JtclrbInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  
  //---------------------------------------------
  // M480RnmiInstruction
  //---------------------------------------------
  

  bool 
  M480RnmiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480RnmiInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  M480RnmiInstruction&
  M480RnmiInstruction::operator=(const M480RnmiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ReturnOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RnmiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RnmiInstruction dynRhs = 
      dynamic_cast<const M480RnmiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDiFlag()  == dynRhs.getDiFlag() ) );
  }
  
  void 
  M480RnmiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  
  //---------------------------------------------
  // M480JrnmiInstruction
  //---------------------------------------------
  

  bool 
  M480JrnmiInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JrnmiInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  M480JrnmiInstruction&
  M480JrnmiInstruction::operator=(const M480JrnmiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ReturnOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JrnmiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JrnmiInstruction dynRhs = 
      dynamic_cast<const M480JrnmiInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDiFlag()  == dynRhs.getDiFlag() ) );
  }
  
  void 
  M480JrnmiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  


  //---------------------------------------------
  // M480RintInstruction
  //---------------------------------------------


  bool 
  M480RintInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480RintInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  

  M480RintInstruction&
  M480RintInstruction::operator=(const M480RintInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ReturnOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480RintInstruction::equalTo(const LlirNode& rhs) const
  {
    M480RintInstruction dynRhs = 
      dynamic_cast<const M480RintInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDiFlag()  == dynRhs.getDiFlag() ) );
  }
  
  void 
  M480RintInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    


  //---------------------------------------------
  // M480JrintInstruction
  //---------------------------------------------


  bool 
  M480JrintInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JrintInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  

  M480JrintInstruction&
  M480JrintInstruction::operator=(const M480JrintInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    ReturnOpInstruction::operator=(rhs);
    return *this;
    
  }
  
  
  bool
  M480JrintInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JrintInstruction dynRhs = 
      dynamic_cast<const M480JrintInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDiFlag()  == dynRhs.getDiFlag() ) );
  }
  
  void 
  M480JrintInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  


  //---------------------------------------------
  // M480BrsInstruction
  //---------------------------------------------

  bool 
  M480BrsInstruction::isReturnInsn() const
  {
    return true;
  }

  bool
  M480BrsInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480BrsInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M480BrsInstruction::isCallInsn() const
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
  M480BrsInstruction::hasReturnReg() const
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
  M480BrsInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BrsInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  
  OpndPtr
  M480BrsInstruction::getDst() const
  {
    return m_dst;
  }
  
  M480BrsInstruction&
  M480BrsInstruction::operator=(const M480BrsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_dst = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M480BrsInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BrsInstruction dynRhs = 
      dynamic_cast<const M480BrsInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480BrsInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  


  //---------------------------------------------
  // M480JbrsInstruction
  //---------------------------------------------

  bool 
  M480JbrsInstruction::isReturnInsn() const
  {
    return true;
  }

  bool
  M480JbrsInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480JbrsInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M480JbrsInstruction::hasReturnReg() const
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
  M480JbrsInstruction::isCallInsn() const
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
  M480JbrsInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbrsInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  
  OpndPtr
  M480JbrsInstruction::getDst() const
  {
    return m_dst;
  }
  
  M480JbrsInstruction&
  M480JbrsInstruction::operator=(const M480JbrsInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_dst = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M480JbrsInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbrsInstruction dynRhs = 
      dynamic_cast<const M480JbrsInstruction&> (rhs); 
    return (    (getLineNum() == dynRhs.getLineNum())
	     && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480JbrsInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  

  
  //---------------------------------------------
  // M480BrslInstruction
  //---------------------------------------------
  
  bool 
  M480BrslInstruction::isReturnInsn() const
  {
    return true;
  }

  bool
  M480BrslInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480BrslInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool 
  M480BrslInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BrslInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  OpndPtr
  M480BrslInstruction::getBrslFlags() const
  {
    return m_flags;
  }
  
  M480BrslInstruction&
  M480BrslInstruction::operator=(const M480BrslInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_flags = rhs.m_flags;
    return *this;
    
  }
  
  bool
  M480BrslInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BrslInstruction dynRhs = 
      dynamic_cast<const M480BrslInstruction&> (rhs); 
    return (    (getLineNum()   == dynRhs.getLineNum()  )
	     && (getBrslFlags() == dynRhs.getBrslFlags()) );
  }
  
  void 
  M480BrslInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  
  //---------------------------------------------
  // M480JbrslInstruction
  //---------------------------------------------
  
  bool 
  M480JbrslInstruction::isReturnInsn() const
  {
    return true;
  }

  bool
  M480JbrslInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480JbrslInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool 
  M480JbrslInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbrslInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  OpndPtr
  M480JbrslInstruction::getBrslFlags() const
  {
    return m_flags;
  }
  
  M480JbrslInstruction&
  M480JbrslInstruction::operator=(const M480JbrslInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_flags = rhs.m_flags;
    return *this;
    
  }
  
  bool
  M480JbrslInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbrslInstruction dynRhs = 
      dynamic_cast<const M480JbrslInstruction&> (rhs); 
    return (    (getLineNum()   == dynRhs.getLineNum()  )
	     && (getBrslFlags() == dynRhs.getBrslFlags()) );
  }
  
  void 
  M480JbrslInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480BrspreInstruction
  //---------------------------------------------

  bool 
  M480BrspreInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BrspreInstruction::getNumDelaySlots() const
  {
    return 0;
  }

  bool
  M480BrspreInstruction::isAbcInsn() const
  {
    return false;
  }
    
  bool
  M480BrspreInstruction::isValidDslotInsn() const
  {
    return true;
  }
  
  OctaveInstruction::BranchProbability 
  M480BrspreInstruction::getBranchProbability() const
  {
    return OctaveInstruction::NONE;
  }    

  M480BrspreInstruction&
  M480BrspreInstruction::operator=(const M480BrspreInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    OctaveInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480BrspreInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BrspreInstruction dynRhs = 
      dynamic_cast<const M480BrspreInstruction&> (rhs); 
    return (getLineNum() == dynRhs.getLineNum());
  }
  
  void 
  M480BrspreInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480CmpInstruction
  //---------------------------------------------
  
  M480CmpInstruction&
  M480CmpInstruction::operator=(const M480CmpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480CmpInstruction::equalTo(const LlirNode& rhs) const
  {
    M480CmpInstruction dynRhs = 
      dynamic_cast<const M480CmpInstruction&> (rhs); 
    return (   (getLineNum()      == dynRhs.getLineNum()     )
            && (getSrc1()         == dynRhs.getSrc1()        )
	    && (getSrc2()         == dynRhs.getSrc2()        )
            && (getAbcFlag()      == dynRhs.getAbcFlag()     )
            && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480CmpInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480JcmpInstruction
  //---------------------------------------------
  
  M480JcmpInstruction&
  M480JcmpInstruction::operator=(const M480JcmpInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480JcmpInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JcmpInstruction dynRhs = 
      dynamic_cast<const M480JcmpInstruction&> (rhs); 
    return (   (getLineNum()      == dynRhs.getLineNum()     )
            && (getSrc1()         == dynRhs.getSrc1()        )
	    && (getSrc2()         == dynRhs.getSrc2()        )
            && (getAbcFlag()      == dynRhs.getAbcFlag()     )
            && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JcmpInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480CmpiInstruction
  //---------------------------------------------
  
  M480CmpiInstruction&
  M480CmpiInstruction::operator=(const M480CmpiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480CmpiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480CmpiInstruction dynRhs = 
      dynamic_cast<const M480CmpiInstruction&> (rhs); 
    return (   (getLineNum()      == dynRhs.getLineNum()     )
            && (getSrc1()         == dynRhs.getSrc1()        )
	    && (getSrc2()         == dynRhs.getSrc2()        )
            && (getAbcFlag()      == dynRhs.getAbcFlag()     )
            && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480CmpiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480JcmpiInstruction
  //---------------------------------------------
  
  M480JcmpiInstruction&
  M480JcmpiInstruction::operator=(const M480JcmpiInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpBranchInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480JcmpiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JcmpiInstruction dynRhs = 
      dynamic_cast<const M480JcmpiInstruction&> (rhs); 
    return (   (getLineNum()      == dynRhs.getLineNum()     )
            && (getSrc1()         == dynRhs.getSrc1()        )
	    && (getSrc2()         == dynRhs.getSrc2()        )
            && (getAbcFlag()      == dynRhs.getAbcFlag()     )
            && (getBranchTarget() == dynRhs.getBranchTarget()) );
  }
  
  void 
  M480JcmpiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480CmprInstruction
  //---------------------------------------------
  
  M480CmprInstruction&
  M480CmprInstruction::operator=(const M480CmprInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpSignInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480CmprInstruction::equalTo(const LlirNode& rhs) const
  {
    M480CmprInstruction dynRhs = 
      dynamic_cast<const M480CmprInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
	    && (getSrc2()    == dynRhs.getSrc2()   )
            && (getAbcFlag() == dynRhs.getAbcFlag())
            && (getDst()     == dynRhs.getDst()    ) 
            && (getSign()    == dynRhs.getSign()   ) );
  }
  
  void 
  M480CmprInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480CmpriInstruction
  //---------------------------------------------
  
  M480CmpriInstruction&
  M480CmpriInstruction::operator=(const M480CmpriInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    CompareOpSignInstruction::operator=(rhs);
    return *this;
    
  }
  
  bool
  M480CmpriInstruction::equalTo(const LlirNode& rhs) const
  {
    M480CmpriInstruction dynRhs = 
      dynamic_cast<const M480CmpriInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
	    && (getSrc2()    == dynRhs.getSrc2()   )
            && (getAbcFlag() == dynRhs.getAbcFlag())
            && (getDst()     == dynRhs.getDst()    ) 
            && (getSign()    == dynRhs.getSign()   ) );
  }
  
  void 
  M480CmpriInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  
  //---------------------------------------------
  // M480BiInstruction
  //---------------------------------------------

  bool
  M480BiInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480BiInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M480BiInstruction::isCallInsn() const
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
  M480BiInstruction::hasReturnReg() const
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
  M480BiInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BiInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  OpndPtr
  M480BiInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M480BiInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  M480BiInstruction::getCdFlag() const
  {
    return m_cdFlag;
  }
  
  M480BiInstruction&
  M480BiInstruction::operator=(const M480BiInstruction& rhs)
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
  M480BiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BiInstruction dynRhs = 
      dynamic_cast<const M480BiInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) 
            && (getCdFlag()  == dynRhs.getCdFlag() ) );
  }
  
  void 
  M480BiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
    
  //---------------------------------------------
  // M480JbiInstruction
  //---------------------------------------------

  bool
  M480JbiInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480JbiInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M480JbiInstruction::isCallInsn() const
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
  M480JbiInstruction::hasReturnReg() const
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
  M480JbiInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbiInstruction::getNumDelaySlots() const
  {
    return 1;
  }

  OctaveInstruction::BranchProbability 
  M480JbiInstruction::getBranchProbability() const
  {
    return OctaveInstruction::TAKEN;
  }

  OpndPtr
  M480JbiInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M480JbiInstruction::getDst() const
  {
    return m_dst;
  }
  

  OpndPtr
  M480JbiInstruction::getCdFlag() const
  {
    return m_cdFlag;
  }
  
  M480JbiInstruction&
  M480JbiInstruction::operator=(const M480JbiInstruction& rhs)
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
  M480JbiInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbiInstruction dynRhs = 
      dynamic_cast<const M480JbiInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) 
            && (getCdFlag()  == dynRhs.getCdFlag() ) );
  }
  
  void 
  M480JbiInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }
  
  //---------------------------------------------
  // M480BrInstruction
  //---------------------------------------------
  
  bool 
  M480BrInstruction::isReturnInsn() const
  {
    if(! getSrc1()->isNullOperand())
      {
	unsigned int rpcRegNum = getSrc1()->getRegNum();
	
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
  M480BrInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480BrInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M480BrInstruction::hasReturnReg() const
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
  M480BrInstruction::isCallInsn() const
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
  M480BrInstruction::isPseudoInsn() const
  {
    return false;
  }

  unsigned int
  M480BrInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  RegPtr
  M480BrInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M480BrInstruction::getDst() const
  {
    return m_dst;
  }
  
  M480BrInstruction&
  M480BrInstruction::operator=(const M480BrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_dst    = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M480BrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480BrInstruction dynRhs = 
      dynamic_cast<const M480BrInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480BrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480JtablebrInstruction
  //---------------------------------------------
    
  bool
  M480JtablebrInstruction::isBranchInsn() const
  {
    return true;
  }
 
  bool
  M480JtablebrInstruction::isValidDslotInsn() const
  {
    return false;
  }
 
  OctaveInstruction::BranchProbability 
  M480JtablebrInstruction::getBranchProbability() const
  {
    return OctaveInstruction::TAKEN;
  }

  bool 
  M480JtablebrInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JtablebrInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  RegPtr
  M480JtablebrInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M480JtablebrInstruction::getDst() const
  {
    return m_dst;
  }
  
  M480JtablebrInstruction&
  M480JtablebrInstruction::operator=(const M480JtablebrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_dst    = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M480JtablebrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JtablebrInstruction dynRhs = 
      dynamic_cast<const M480JtablebrInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480JtablebrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }


  //---------------------------------------------
  // M480JtableRelativebrInstruction
  //---------------------------------------------
    
  bool
  M480JtableRelativebrInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480JtableRelativebrInstruction::isValidDslotInsn() const
  {
    return false;
  }

  OctaveInstruction::BranchProbability 
  M480JtableRelativebrInstruction::getBranchProbability() const
  {
    return OctaveInstruction::TAKEN;
  }

  bool 
  M480JtableRelativebrInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JtableRelativebrInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  RegPtr
  M480JtableRelativebrInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M480JtableRelativebrInstruction::getDst() const
  {
    return m_dst;
  }
  
  M480JtableRelativebrInstruction&
  M480JtableRelativebrInstruction::operator=(const M480JtableRelativebrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_dst    = rhs.m_dst;
    return *this;
    
  }
  
  bool
  M480JtableRelativebrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JtableRelativebrInstruction dynRhs = 
      dynamic_cast<const M480JtableRelativebrInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480JtableRelativebrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
      {
	lv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("accept error");
      }       
    
  }

  //---------------------------------------------
  // M480JbrInstruction
  //---------------------------------------------
  
  bool 
  M480JbrInstruction::isReturnInsn() const
  {
    if(! getSrc1()->isNullOperand())
      {
	unsigned int rpcRegNum = getSrc1()->getRegNum();
	
	if(rpcRegNum == 60 ||
	   rpcRegNum == 61 ||
	   rpcRegNum == 62)
	  {
	    return true;
	  }
      }

    return false;
  }

  OctaveInstruction::BranchProbability 
  M480JbrInstruction::getBranchProbability() const
  {
    return OctaveInstruction::TAKEN;
  }

  bool
  M480JbrInstruction::isBranchInsn() const
  {
    return true;
  }

  bool
  M480JbrInstruction::isValidDslotInsn() const
  {
    return false;
  }

  bool
  M480JbrInstruction::isCallInsn() const
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
  M480JbrInstruction::hasReturnReg() const
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
  M480JbrInstruction::isPseudoInsn() const
  {
    return true;
  }

  unsigned int
  M480JbrInstruction::getNumDelaySlots() const
  {
    return 1;
  }


  RegPtr
  M480JbrInstruction::getSrc1() const
  {
    return m_src1;
  }
  
  OpndPtr
  M480JbrInstruction::getDst() const
  {
    return m_dst;
  }
  
  OpndPtr
  M480JbrInstruction::getTargetLabelList() const
  {
    return m_targetList;
  }
  
  M480JbrInstruction&
  M480JbrInstruction::operator=(const M480JbrInstruction& rhs)
  {
    if(this == &rhs)
      return *this;
    
    BranchOpInstruction::operator=(rhs);
    m_src1   = rhs.m_src1;
    m_dst    = rhs.m_dst;
    m_targetList = rhs.m_targetList;
    return *this;
    
  }
  
  bool
  M480JbrInstruction::equalTo(const LlirNode& rhs) const
  {
    M480JbrInstruction dynRhs = 
      dynamic_cast<const M480JbrInstruction&> (rhs); 
    return (   (getLineNum() == dynRhs.getLineNum())
            && (getSrc1()    == dynRhs.getSrc1()   )
            && (getDst()     == dynRhs.getDst()    ) );
  }
  
  void 
  M480JbrInstruction::accept(Visitor& v) const
  {
    if(M480Visitor *lv = 
       dynamic_cast<M480Visitor *>(&v)) 
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
