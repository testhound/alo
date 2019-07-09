#include <iostream>
#include <map>
using namespace std;

#include <LlirException.h>

#include "OctaveSymbol.h"
#include "OctaveVisitor.h"


namespace Llir 
{

  typedef std::map<string, shared_ptr<Type> >::difference_type MapDiffType; 

  //---------------------
  //Type
  //---------------------


  Type::Type(const char *name, OctaveSymbol::ScopeQualifier scope)
    : OctaveSymbol(name, scope)
  {}

  Type::Type(const Type& rhs) 
    : OctaveSymbol(rhs)
  {}

  Type&
  Type::operator=(const Type& rhs)
  {
    if(this == &rhs)
      return *this;

    OctaveSymbol::operator=(rhs);
    return *this;	
  }

  //---------------------
  //StructContent class
  //---------------------

  StructContent::StructContent(const char *name, unsigned int offset, OctaveSymbol::ScopeQualifier scope)
    : Type(name, scope), 
    m_offset(offset)
  {}

  StructContent::StructContent(const StructContent& rhs)
    : Type(rhs),	
    m_offset(rhs.m_offset)
  {}

  StructContent&
  StructContent::operator=(const StructContent& rhs)
  {
    if (this == &rhs)
      return *this;

    Type::operator=(rhs);
    m_offset = rhs.m_offset;
    return *this;

  }

  unsigned int 
  StructContent::getOffset() const
  {
    return m_offset;
  }



  //---------------------
  //Struct class
  //---------------------

  Struct::Struct(const char *name, 
		 unsigned int offset,
		 OctaveSymbol::ScopeQualifier scope)
    : StructContent(name, offset, scope), 
    m_nextOffset(0u), 
    m_size(0u)  
  {}

  Struct::Struct(const Struct& rhs)
    : StructContent(rhs),
      m_scMap(rhs.m_scMap),
      m_nextOffset(rhs.m_nextOffset),
      m_size(rhs.m_size)
  {}

  Struct&
  Struct::operator=(const Struct& rhs)
  {
    if(this == &rhs)
      return *this;

    StructContent::operator=(rhs);
    m_scMap = rhs.m_scMap;
    m_nextOffset = rhs.m_nextOffset;
    m_size = rhs.m_size;
    return *this;
  }


  shared_ptr<Struct>
  Struct::createStruct(const char *name)
  {

    shared_ptr<Struct> spStruct ( new Struct(name, m_nextOffset) );

    return spStruct;
  }

  shared_ptr<Element>
  Struct::createElement()
  {
    shared_ptr<Element> spElement ( new Element("elementHasNoName", m_nextOffset) );

    return spElement;
  }


  /**
   *
   * Struct::addType method does
   *
   * 1. ensure that elements are not added to struct
   *    and iterates over the fields of an element
   *    and adds them to struct
   *
   * 2. increment the size of the struct
   *     by sizeof(newTp) if Struct is being added
   *     by 4 if element is being added
   *
   * 3. update the m_currentOfset
   *      by 4 if element is added
   *      by sizeof(newTp) if struct is being added
   *
   */

  void
  Struct::addType(shared_ptr<Type> newTp)
  {

    shared_ptr<Struct> structTp = shared_dynamic_cast<Struct>(newTp);

    if(structTp)
      {

	string name = structTp->getName();

	unsigned int size = structTp->getSize();


	if(m_scMap.find(name) == m_scMap.end())
	  {
	    m_scMap[name] = structTp;
	  }
	else
	  {
	    throw LLIR_TYPE_EXCEPTION("type with same name already exists in the structure");
	  }

	m_size += size;	

	m_nextOffset += size;

      }
    else
      {
	shared_ptr<Element> elementTp = shared_dynamic_cast<Element>(newTp);
 
	if(elementTp)
	  {
	    //add all fields to the struct

	    Type::Iterator iter = elementTp->begin();

	    if(elementTp->begin() == elementTp->end())
	      {
		//fixme : internal error
		throw LLIR_INTERNAL_EXCEPTION("grammar does not allow empty .element (as of 11/15/2002)");
	      }
	    
	    unsigned int size = elementTp->getSize();

	    for(; iter != elementTp->end(); iter++)
	      { 
		shared_ptr<Type> fldTp = *iter;

		string name = fldTp->getName();

		if(m_scMap.find(name) == m_scMap.end()) 
		  {
		    m_scMap[name] = fldTp;
		  }
		else
		  { 
		    throw LLIR_TYPE_EXCEPTION("element with same name already exists in the structure");		    
		  }

	      }
	    m_size += size;

	    m_nextOffset += size;

	  }
	else
	  {	
	    throw LLIR_INTERNAL_EXCEPTION("Non Struct/Element type is being added to the struct");
	  } 
      }

  }

  unsigned int 
  Struct::getSize() const
  {
    return m_size;
  }

  Type::Iterator
  Struct::lookupType(const char* name)
  {
    return Type::Iterator(new StructTypeIterator<MapDiffType>(m_scMap.find(name)));
  }

  Type::ConstIterator
  Struct::lookupType(const char* name) const
  {
    return Type::ConstIterator(new StructTypeConstIterator<MapDiffType>(m_scMap.find(name)));
  }

  Type::Iterator
  Struct::begin()
  {
    Type::Iterator iter(new StructTypeIterator<MapDiffType>(m_scMap.begin()));
    return iter;
  }


  Type::Iterator
  Struct::end()
  {
    Type::Iterator iter(new StructTypeIterator<MapDiffType>(m_scMap.end()));
    return iter;
  }

  Type::ConstIterator
  Struct::begin() const
  {
    Type::ConstIterator citer(new StructTypeConstIterator<MapDiffType>(m_scMap.begin()));
    return citer; 
  }


  Type::ConstIterator
  Struct::end() const
  {
    Type::ConstIterator citer(new StructTypeConstIterator<MapDiffType>(m_scMap.end()));
    return citer; 
  }


  bool
  Struct::equalTo(const Symbol &rhs) const
  {
    const Struct &rhsType = dynamic_cast<const Struct &> (rhs);

    if( getName() != rhsType.getName() ||
	getSize() != rhsType.getSize() ||
	getScopeQualifier() != rhsType.getScopeQualifier() )
      {
	return false;
      }

    Type::ConstIterator thisIter = begin();
    Type::ConstIterator rhsIter = rhsType.begin();
    
    for(; thisIter != end(), rhsIter != rhsType.end(); thisIter++, rhsIter++)
      {

	// Note:
	// *(iter)   -> corresponds to shared_ptr<Type>
	// **(iter)  -> corresponds to Type

	if(**(thisIter) != **(rhsIter))
	  return false;
      }
     
    return true;


    /* 
       Note:
       offset of a struct should not be considered as 
       the defining characteristic while comparing two
       structures for equality because they may be two 
       identical inner structures of two seperate structures
       but at different offsets.
     */
  }

  //---------------------
  //Element class
  //---------------------


  Element::Element(const char *name, 
		   unsigned int offset, 
		   OctaveSymbol::ScopeQualifier scope)
    : StructContent(name, offset, scope)
  {}

  Element::Element(const Element& rhs)
    : StructContent(rhs),
      m_fldMap(rhs.m_fldMap)  
  {}

  Element&
  Element::operator=(const Element& rhs)
  {
    if(this == &rhs)
      return *this;

    StructContent::operator=(rhs);
    m_fldMap = rhs.m_fldMap;
    return *this;
  }

  unsigned int 
  Element::getSize() const
  {
    return Element_Size; 
  }

  shared_ptr<Field>
  Element::createField(const char* name)
  {
    //all the field's in an element have same offset 
    //same as that of that element offset

    shared_ptr<Field> fld(new Field(name, getOffset()));
    return fld;
  }

  shared_ptr<BitField>
  Element::createField(const char* name, unsigned int msb, unsigned int lsb)
  {
    //all the field's in an element have same offset 
    //same as that of that element offset

    shared_ptr<BitField> bitFld(new BitField(name, getOffset(), msb, lsb));
    return bitFld;
  }


  void
  Element::addType(shared_ptr<Type> newTp)
  {
    shared_ptr<AbstractField> fldTp = shared_dynamic_cast<AbstractField>(newTp);
    
    if(fldTp)
      {
	string name = newTp->getName();

	if(m_fldMap.find(name) == m_fldMap.end())
	  {
	    m_fldMap[name] = fldTp;
	  }
	else
	  {
	    throw LLIR_TYPE_EXCEPTION("field with same name already exists");
	  }  
      }
    else
      {
        throw LLIR_INTERNAL_EXCEPTION("Non-Field type is being added to Element");
      }
  }  

  Type::Iterator
  Element::lookupType(const char *name)
  {
    return Type::Iterator(new ElementTypeIterator<MapDiffType>(m_fldMap.find(name)));
  }

  Type::ConstIterator
  Element::lookupType(const char *name) const
  {
    return Type::ConstIterator(new ElementTypeConstIterator<MapDiffType>(m_fldMap.find(name)));
  }

  Type::Iterator
  Element::begin()
  {
    Type::Iterator iter(new ElementTypeIterator<MapDiffType>(m_fldMap.begin()));
    return iter; 
  }

  Type::Iterator
  Element::end()
  {
    Type::Iterator iter(new ElementTypeIterator<MapDiffType>(m_fldMap.end()));
    return iter; 
  }

  Type::ConstIterator
  Element::begin() const
  {
    Type::ConstIterator citer(new ElementTypeConstIterator<MapDiffType>(m_fldMap.begin()));
    return citer; 
  }

  Type::ConstIterator
  Element::end() const
  {
    Type::ConstIterator citer(new ElementTypeConstIterator<MapDiffType>(m_fldMap.end()));
    return citer; 
  }


  bool
  Element::equalTo(const Symbol& rhs) const
  {
    const Element &rhsType = dynamic_cast<const Element &> (rhs);

    if(( getName() != rhsType.getName() ) ||
       ( getSize() != rhsType.getSize() ) ||
       ( getOffset() != rhsType.getOffset() ||
	 getScopeQualifier() != rhsType.getScopeQualifier() ))	
      return false;

    Type::ConstIterator thisIter = begin();
    Type::ConstIterator rhsIter = rhsType.begin();
    
    for(; thisIter != end(), rhsIter != rhsType.end(); thisIter++, rhsIter++)
      {
	if(**(thisIter) != **(rhsIter))
	  return false;
      }
 
    return true;
  }

  //---------------------
  //AbstractField Class
  //---------------------

  AbstractField::AbstractField(const char *name, 
			       unsigned int offset, 
			       unsigned int msb, 
			       unsigned int lsb, 
			       OctaveSymbol::ScopeQualifier scope)
    : StructContent(name, offset, scope), 
    m_msbPos(msb), 
    m_lsbPos(lsb)
  {}


  AbstractField::AbstractField(const AbstractField& rhs)
    : StructContent(rhs), 
    m_msbPos(rhs.m_msbPos),
    m_lsbPos(rhs.m_lsbPos)
  {}

  AbstractField&
  AbstractField::operator=(const AbstractField& rhs)
  {
    if(this == &rhs)
      return *this;

    StructContent::operator=(rhs);
    m_msbPos = rhs.m_msbPos; 
    m_lsbPos = rhs.m_lsbPos; 
    return *this;
  }

  unsigned int
  AbstractField::getSize() const
  {
    return Field_Size;
  }

  unsigned int
  AbstractField::getMSBitPosition() const
  {
    return m_msbPos;
  }

  unsigned int
  AbstractField::getLSBitPosition() const
  {
    return m_lsbPos;
  }

  void
  AbstractField::addType(shared_ptr<Type> addTp)
  {
   throw LLIR_INTERNAL_EXCEPTION("Cannot Add Type to a Field");
  }

  Type::Iterator
  AbstractField::lookupType(const char *name)
  {
   throw LLIR_INTERNAL_EXCEPTION("AbstractField::lookupType not implemented");

    return Type::Iterator(new NullRAIterator<MapDiffType>());
  }

  Type::ConstIterator
  AbstractField::lookupType(const char *name) const
  {
   throw LLIR_INTERNAL_EXCEPTION("AbstractField::lookupType not implemented");

    return Type::ConstIterator(new NullRAConstIterator<MapDiffType>());
  }

  Type::Iterator
  AbstractField::begin()
  {
   throw LLIR_INTERNAL_EXCEPTION("AbstractField::begin not implemented");

   Type::Iterator iter(new NullRAIterator<MapDiffType>());
   return iter; 
  }

  Type::Iterator
  AbstractField::end()
  {
   throw LLIR_INTERNAL_EXCEPTION("AbstractField::end not implemented");

   Type::Iterator iter(new NullRAIterator<MapDiffType>());
   return iter; 
  }

  Type::ConstIterator
  AbstractField::begin() const
  {
   throw LLIR_INTERNAL_EXCEPTION("AbstractField::begin not implemented");

    Type::ConstIterator citer(new NullRAConstIterator<MapDiffType>());
    return citer;
  }

  Type::ConstIterator
  AbstractField::end() const
  {
   throw LLIR_INTERNAL_EXCEPTION("AbstractField::end not implemented");

    Type::ConstIterator citer(new NullRAConstIterator<MapDiffType>());
    return citer;
  }



  //---------------------
  //class Field
  //---------------------



  Field::Field(const char *name, 
	       unsigned int offset, 
	       OctaveSymbol::ScopeQualifier scope)
    : AbstractField(name, offset, 31, 0, scope)
  {}


  Field::Field(const Field& rhs)
    : AbstractField(rhs)
  {}

  Field&
  Field::operator=(const Field& rhs)
  {
    if(this == &rhs)
      return *this;
 
    AbstractField::operator=(rhs);
    return *this;

  }


  bool
  Field::equalTo(const Symbol& rhs) const 
  {
    const Field &rhsType = dynamic_cast<const Field &> (rhs);

    if( getName() == rhsType.getName() &&
	getSize() == rhsType.getSize() &&
        getOffset() == rhsType.getOffset() &&
        getMSBitPosition() == rhsType.getMSBitPosition() &&
        getLSBitPosition() == rhsType.getLSBitPosition() &&
	getScopeQualifier() == rhsType.getScopeQualifier() )
      {
	return true; 
      }
    else
      {
	return false;
      }

  }

  void Field::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("Accept Error");
      }       
  }

  //---------------------
  //class BitField
  //---------------------


  BitField::BitField(const char *name, 
		     unsigned int offset, 
		     unsigned int msb, 
		     unsigned int lsb, 
		     OctaveSymbol::ScopeQualifier scope)
    : AbstractField(name, offset, msb, lsb, scope) 
  {}


  BitField::BitField(const BitField& rhs)
    : AbstractField(rhs)
  {}

  BitField&
  BitField::operator=(const BitField& rhs)
  {
    if(this == &rhs)
      return *this;

    AbstractField::operator=(rhs);
    return *this; 

  }


  bool
  BitField::equalTo(const Symbol& rhs) const 
  {
    const BitField &rhsType = dynamic_cast<const BitField &> (rhs);

    if( getName() == rhsType.getName() &&
	getSize() == rhsType.getSize() &&
        getOffset() == rhsType.getOffset() &&
        getMSBitPosition() == rhsType.getMSBitPosition() &&
        getLSBitPosition() == rhsType.getLSBitPosition() &&
	getScopeQualifier() == rhsType.getScopeQualifier() )
      {
	return true; 
      }
    else
      {
	return false;
      }

  }

  void BitField::accept(Visitor &v) const
  {
    if(LlirOctaveVisitor *lbv = dynamic_cast<LlirOctaveVisitor *>(&v)) 
      {
	lbv->visit(*this);
      } 
    else
      {
	throw LLIR_INTERNAL_EXCEPTION("Accept Error");
      }       
  }



  //--------------------
  // Null Type class
  //--------------------

  NullType::NullType()
    : Type("", OctaveSymbol::FILESCOPE)
  {}

  NullType::NullType(const NullType& rhs)
    : Type(rhs)
  {}

  NullType& 
  NullType::operator=(const NullType& rhs)
  {
    if(this == &rhs)
      return *this;

    Type::operator=(rhs);
    return *this;
  }

  bool
  NullType::equalTo(const Symbol& rhs) const
  {
    if(getName() == rhs.getName())
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  unsigned int 
  NullType::getSize() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::getSize() not implemented");
    
    return 0; // to suppress compiler warning
  }


  unsigned int 
  NullType::getOffset() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::getOffset() not implemented");
    
    return 0; // to suppress compiler warning
  }

  void
  NullType::addType(shared_ptr<Type> tp)
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::addType() not implemented");
  }

  Type::Iterator
  NullType::lookupType(const char* name)
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::lookupType() not implemented");

    return Type::Iterator(new NullRAIterator<MapDiffType>());
  }
  
  Type::ConstIterator
  NullType::lookupType(const char* name) const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::lookupType() not implemented");

    return Type::ConstIterator(new NullRAConstIterator<MapDiffType>());
  }

  Type::Iterator
  NullType::begin()
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::begin() not implemented");

    return Type::Iterator(new NullRAIterator<MapDiffType>());
  }
  
  Type::ConstIterator
  NullType::begin() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::begin() not implemented");

    return Type::ConstIterator(new NullRAConstIterator<MapDiffType>());
  }

  Type::Iterator
  NullType::end()
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::end() not implemented");

    return Type::Iterator(new NullRAIterator<MapDiffType>());
  }
  
  Type::ConstIterator
  NullType::end() const
  {
    throw LLIR_INTERNAL_EXCEPTION("NullType::end() not implemented");

    return Type::ConstIterator(new NullRAConstIterator<MapDiffType>());
  }




  //---------------------
  // global operators   
  //---------------------


  bool operator==(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs)
  {
    return lhs.equal(rhs);
  }

  bool operator!=(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs)
  {
    return !(lhs.equal(rhs));
  }

  bool operator-(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs)
  { 
    //FIXME
    return true;
  }

  bool operator<(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs)
  {
    //FIXME
    return true;
  }


  bool operator==(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs)
  {
    return lhs.equal(rhs);
  }

  bool operator!=(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs)
  {
    return !(lhs.equal(rhs));  
  }


  bool operator-(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs)
  {
    //FIXME
    return true;
  }

  bool operator<(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs)
  {
    //FIXME
    return true;
  }









} // namespace Llir
