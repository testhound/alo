#include <iostream>
using namespace std;

#include <LlirSymbol.h>
#include <LlirOperand.h>
#include <LlirException.h>
#include "OctaveSymbol.h"

namespace Llir 
{

  shared_ptr<const Struct> m_globalStruct;

  shared_ptr<const Register> m_globalRegister;


  //class OctaveSymbol
  //------------------


  OctaveSymbol::OctaveSymbol(const char *name, OctaveSymbol::ScopeQualifier scope)
    : Symbol(name), 
    m_symbolScope(scope)	
  {}

  OctaveSymbol::OctaveSymbol(const OctaveSymbol& rhs)
    : Symbol(rhs), 
    m_symbolScope(rhs.m_symbolScope)	
  {}

  OctaveSymbol&
  OctaveSymbol::operator=(const OctaveSymbol& rhs)
  {
    if(this == &rhs)
      return *this;

    Symbol::operator=(rhs);
    m_symbolScope = rhs.m_symbolScope;
    return *this; 
  }

  OctaveSymbol::ScopeQualifier
  OctaveSymbol::getScopeQualifier() const
  {
    return m_symbolScope;
  }

  //--------------
  // Null Symbol
  //--------------

  NullSymbol::NullSymbol()
    : OctaveSymbol("", OctaveSymbol::GLOBAL)
  {}

  NullSymbol::NullSymbol(const NullSymbol& rhs)
    : OctaveSymbol(rhs)
  {}

  NullSymbol&
  NullSymbol::operator=(const NullSymbol& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveSymbol::operator=(rhs);
    return *this;
  }

  bool
  NullSymbol::equalTo(const Symbol& rhs) const
  {
    NullSymbol label = dynamic_cast<const NullSymbol&> (rhs);
    return true;
  }

  //--------------
  // Label Symbol
  //--------------

  unsigned long LabelSymbol::m_localLabelCtr = 0;

  LabelSymbol::LabelSymbol(const char* name, OctaveSymbol::ScopeQualifier scope)
    : OctaveSymbol(name, scope)
  {
    if(scope == OctaveSymbol::LOCAL)
      {
	char *buffer = new char[32];
	sprintf(buffer, "%lu", m_localLabelCtr);
	m_mangledName = name + string("_") + buffer;
	++m_localLabelCtr;
	delete buffer;
      }
    else
      {
	m_mangledName = name;
      }
  }

  LabelSymbol::LabelSymbol(const LabelSymbol& rhs)
    : OctaveSymbol(rhs)
  {}

  LabelSymbol&
  LabelSymbol::operator=(const LabelSymbol& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveSymbol::operator=(rhs);
    return *this;
  }

  const string&
  LabelSymbol::getMangledName() const
  {
    return m_mangledName;
  }

  void
  LabelSymbol::setMangledName(string name) 
  {
    m_mangledName = name;
  }

  bool
  LabelSymbol::equalTo(const Symbol& rhs) const
  {
    LabelSymbol label = dynamic_cast<const LabelSymbol&> (rhs);
    return (getName() == label.getName());
  }




  //----------------
  //RegSymbol class
  //----------------

  RegSymbol::RegSymbol(const char* name, OctaveSymbol::ScopeQualifier scope)
    : OctaveSymbol(name, scope)
  {}

  RegSymbol::RegSymbol(const RegSymbol& rhs)
    : OctaveSymbol(rhs)
  {}

  RegSymbol& 
  RegSymbol::operator=(const RegSymbol& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveSymbol::operator=(rhs);
    return *this;
  }


  //----------------------
  //class AbstractSymReg
  //----------------------

  AbstractSymReg::AbstractSymReg(const char*name, 
				 OctaveSymbol::ScopeQualifier scope,
				 AbstractSymReg::SymRegConstraint symRegConstraint,
				 shared_ptr<const Register> constraintRegRange)
    : RegSymbol(name, scope),
      m_symRegConstraint(symRegConstraint),
      m_constraintRegRange(constraintRegRange)
  {}


  AbstractSymReg::AbstractSymReg(const AbstractSymReg& rhs)
    : RegSymbol(rhs),
      m_symRegConstraint(rhs.m_symRegConstraint),
      m_constraintRegRange(rhs.m_constraintRegRange)
  {}

  AbstractSymReg&
  AbstractSymReg::operator=(const AbstractSymReg& rhs)
  {
    if(this == &rhs)
      return *this;

    m_symRegConstraint   = rhs.m_symRegConstraint;
    m_constraintRegRange = rhs.m_constraintRegRange;

    RegSymbol::operator=(rhs);
    return *this;
  }

  AbstractSymReg::SymRegConstraint 
  AbstractSymReg::getSymRegConstraint() const
  {
    return m_symRegConstraint;
  }

  shared_ptr<const Register>
  AbstractSymReg::getContraintRegRange() const
  {
    return m_constraintRegRange;
  }

  shared_ptr<const Struct>
  AbstractSymReg::getMappedStruct() const
  {
    throw LLIR_INTERNAL_EXCEPTION("AbstractSymReg::getMappedStruct not implemented");

    return m_globalStruct; //to supress compiler warning...
  }

  //------------
  //SymReg class
  //------------


  SymReg::SymReg(const char *name, 
		 OctaveSymbol::ScopeQualifier scope, 
		 shared_ptr<const SingleRegister> reg,
		 AbstractSymReg::SymRegConstraint symRegConstraint,
		 shared_ptr<const Register> constraintRegRange)
    : AbstractSymReg(name,
		     scope,
		     symRegConstraint,
		     constraintRegRange),
      m_singleReg(reg)	
	
  {}

  SymReg::SymReg(const SymReg& rhs)
    : AbstractSymReg(rhs),
      m_singleReg(rhs.m_singleReg)
  {}

  SymReg&
  SymReg::operator=(const SymReg& rhs)
  {
    if(this == &rhs)
      return *this;

    AbstractSymReg::operator=(rhs);
    m_singleReg = rhs.m_singleReg;
    return *this;
  }

  shared_ptr<const Register>
  SymReg::getRegister() const
  {
    return m_singleReg;
  }

  bool
  SymReg::equalTo(const Symbol& rhs) const
  {
    if(m_singleReg == (dynamic_cast<const SymReg&>(rhs)).m_singleReg) 
      return true;
    else
      {
	return false;
      }
  }

  //-----------------------
  //class MultiSymReg class
  //-----------------------

  MultiSymReg::MultiSymReg(const char *name, 
			   OctaveSymbol::ScopeQualifier scope, 
			   shared_ptr<const MultiRegister> reg,				 
			   AbstractSymReg::SymRegConstraint symRegConstraint,
			   shared_ptr<const Register> constraintRegRange)
    : AbstractSymReg(name, 
		     scope,
		     symRegConstraint,
		     constraintRegRange),
      m_multiReg(reg)	
  {}

  MultiSymReg::MultiSymReg(const MultiSymReg& rhs)
    : AbstractSymReg(rhs),
      m_multiReg(rhs.m_multiReg)
  {}


  MultiSymReg&
  MultiSymReg::operator=(const MultiSymReg& rhs)
  {
    if(this == &rhs)
      return *this;

    AbstractSymReg::operator=(rhs);
    m_multiReg = rhs.m_multiReg;
    return *this;
  }

  shared_ptr<const Register>
  MultiSymReg::getRegister() const
  {
    return m_multiReg;
  }


  bool
  MultiSymReg::equalTo(const Symbol& rhs) const
  {
    if(m_multiReg == (dynamic_cast<const MultiSymReg&>(rhs)).m_multiReg) 
      return true;
    else
      {
	return false;
      }
  }


  //--------------
  // Block Symbol
  //--------------

  BlockSymbol::BlockSymbol(const char* name, OctaveSymbol::ScopeQualifier scope)
    : OctaveSymbol(name, scope)
  {}

  BlockSymbol::BlockSymbol(const BlockSymbol& rhs)
    : OctaveSymbol(rhs)
  {}

  BlockSymbol&
  BlockSymbol::operator=(const BlockSymbol& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveSymbol::operator=(rhs);
    return *this;
  }

  bool
  BlockSymbol::equalTo(const Symbol& rhs) const
  {
    BlockSymbol block = dynamic_cast<const BlockSymbol&> (rhs);
    return (getName() == block.getName()
	    && getScopeQualifier() == block.getScopeQualifier());
  }

  //class MapSymbol
  //---------------

  MapSymbol::MapSymbol(const char* name, 
		       OctaveSymbol::ScopeQualifier scope, 
		       shared_ptr<const Struct> st)
    : RegSymbol(name, scope),
      m_structType(st)
  {} 

  MapSymbol::MapSymbol(const MapSymbol& rhs)
    : RegSymbol(rhs),
      m_structType(rhs.m_structType)
  {}

  MapSymbol&
  MapSymbol::operator=(const MapSymbol& rhs)
  {
    if(this == &rhs)
      return *this;

    RegSymbol::operator=(rhs);
    m_structType = rhs.m_structType;
    return *this; 
  }

  shared_ptr<const Struct>
  MapSymbol::getMappedStruct() const
  {
    return m_structType;
  } 

  //class MapToHardReg
  //------------------


  MapToHardReg::MapToHardReg(const char* mapName, 
			     OctaveSymbol::ScopeQualifier scope, 
			     shared_ptr<const Struct> tp, 
			     shared_ptr<const HardRegister> hreg)
    : MapSymbol(mapName, scope, tp) ,
      m_hReg(hreg)
  {}

  MapToHardReg::MapToHardReg(const MapToHardReg& rhs)
    : MapSymbol(rhs),
      m_hReg(rhs.m_hReg)
  {}

  MapToHardReg&
  MapToHardReg::operator=(const MapToHardReg& rhs)
  {
    if(this == &rhs)
      return *this;

    MapSymbol::operator=(rhs);
    m_hReg = rhs.m_hReg;
    return *this;
  }

  shared_ptr<const Register>
  MapToHardReg::getRegister() const
  {
    return m_hReg;
  }

  bool
  MapToHardReg::equalTo(const Symbol& rhs) const
  {
    if(m_hReg == (dynamic_cast<const MapToHardReg &>(rhs)).m_hReg)
      return true;
    else
      {
	return false;
      }
  }


  //class MapToPseudoReg
  //----------------- 

  MapToPseudoReg::MapToPseudoReg(const char* mapName, 
			   OctaveSymbol::ScopeQualifier scope, 
			   shared_ptr<const Struct> tp, 
			   shared_ptr<const PseudoRegister> sreg)
    : MapSymbol(mapName, scope, tp) ,
      m_pseudoReg(sreg)
  {}

  MapToPseudoReg::MapToPseudoReg(const MapToPseudoReg& rhs)
    : MapSymbol(rhs),
      m_pseudoReg(rhs.m_pseudoReg)
  {}

  MapToPseudoReg&
  MapToPseudoReg::operator=(const MapToPseudoReg& rhs)
  {
    if(this == &rhs)
      return *this;

    MapSymbol::operator=(rhs);
    m_pseudoReg = rhs.m_pseudoReg;
    return *this;
  }

  shared_ptr<const Register>
  MapToPseudoReg::getRegister() const
  {
    return m_pseudoReg;
  }

  bool
  MapToPseudoReg::equalTo(const Symbol& rhs) const
  {
    if(m_pseudoReg == (dynamic_cast<const MapToPseudoReg &>(rhs)).m_pseudoReg)
      return true;
    else
      {
	return false;
      }
  }


  //class MapToMultiHardReg
  //---------------------- 

  MapToMultiHardReg::MapToMultiHardReg(const char* mapName, 
				       OctaveSymbol::ScopeQualifier scope, 
				       shared_ptr<const Struct> tp, 
				       shared_ptr<const MultiHardRegister> mreg)
    : MapSymbol(mapName, scope, tp) ,
      m_multiHardReg(mreg)
  {}

  MapToMultiHardReg::MapToMultiHardReg(const MapToMultiHardReg& rhs)
    : MapSymbol(rhs),
      m_multiHardReg(rhs.m_multiHardReg)
  {}

  MapToMultiHardReg&
  MapToMultiHardReg::operator=(const MapToMultiHardReg& rhs)
  {
    if(this == &rhs)
      return *this;

    MapSymbol::operator=(rhs);
    m_multiHardReg = rhs.m_multiHardReg;
    return *this;
  }

  shared_ptr<const Register>
  MapToMultiHardReg::getRegister() const
  {
    return m_multiHardReg;
  }

  bool
  MapToMultiHardReg::equalTo(const Symbol& rhs) const
  {
    if(m_multiHardReg == (dynamic_cast<const MapToMultiHardReg &>(rhs)).m_multiHardReg)
      return true;
    else
      {
	return false;
      }
  }



  //class MapToMultiPseudoReg
  //---------------------- 

  MapToMultiPseudoReg::MapToMultiPseudoReg(const char* mapName, 
				     OctaveSymbol::ScopeQualifier scope, 
				     shared_ptr<const Struct> tp, 
				     shared_ptr<const MultiPseudoRegister> mreg)
    : MapSymbol(mapName, scope, tp) ,
      m_multiPseudoReg(mreg)
  {}

  MapToMultiPseudoReg::MapToMultiPseudoReg(const MapToMultiPseudoReg& rhs)
    : MapSymbol(rhs),
      m_multiPseudoReg(rhs.m_multiPseudoReg)
  {}

  MapToMultiPseudoReg&
  MapToMultiPseudoReg::operator=(const MapToMultiPseudoReg& rhs)
  {
    if(this == &rhs)
      return *this;

    MapSymbol::operator=(rhs);
    m_multiPseudoReg = rhs.m_multiPseudoReg;
    return *this;
  }

  shared_ptr<const Register>
  MapToMultiPseudoReg::getRegister() const
  {
    return m_multiPseudoReg;
  }

  bool
  MapToMultiPseudoReg::equalTo(const Symbol& rhs) const
  {
    if(m_multiPseudoReg == (dynamic_cast<const MapToMultiPseudoReg &>(rhs)).m_multiPseudoReg)
      return true;
    else
      {
	return false;
      }
  }

}  // namespace Llir








