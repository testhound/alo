#ifndef _LLIR_OCTAVE_SYMBOL_H
#define _LLIR_OCTAVE_SYMBOL_H

/**
  * \file 
  *
  * \brief Symbol Class Description
  * 
  */



#include <LlirSymbol.h>
#include <LlirOperand.h>

namespace Llir 
{


  // Forward Declarations

  template <class S, class T, class D> class StlRandomAccessIterator;
  template <class S, class T, class D> class StlRandomAccessConstIterator;


  class Type;
  class Struct;
  class Element;
  class AbstractField;
  class Field;
  class BitField;
  class Visitor;

  template<class D> class TypeIterator;
  template<class D> class StructTypeIterator;
  template<class D> class ElementTypeIterator;
  template<class D> class NullRAIterator;

  template<class D> class TypeConstIterator;
  template<class D> class StructTypeConstIterator;
  template<class D> class ElementTypeConstIterator;
  template<class D> class NullRAConstIterator;



  class OctaveSymbol : public Symbol
    {

    public:

      enum ScopeQualifier { LOCAL, FILESCOPE, GLOBAL };

      ~OctaveSymbol() {}

      ScopeQualifier getScopeQualifier() const;

      void setScopeQualifier();
	
    protected:

      OctaveSymbol(const char* name, ScopeQualifier scope);

      OctaveSymbol(const OctaveSymbol& rhs);

      OctaveSymbol& operator=(const OctaveSymbol& rhs);
	
    private:

      ScopeQualifier m_symbolScope;
     
    };

  class BlockSymbol : public OctaveSymbol
    {
    public:

      BlockSymbol(const char *name, 
		  OctaveSymbol::ScopeQualifier);

      BlockSymbol(const BlockSymbol& rhs);

      ~BlockSymbol() {}	

      BlockSymbol& operator=(const BlockSymbol& rhs);

    private:
      bool equalTo(const Symbol &rhs) const;
    };

  class LabelSymbol : public OctaveSymbol
    {
    public:

      LabelSymbol(const char *name, 
		  OctaveSymbol::ScopeQualifier);

      LabelSymbol(const LabelSymbol& rhs);

      ~LabelSymbol() {}	

      LabelSymbol& operator=(const LabelSymbol& rhs);

      const string& getMangledName() const;

      void setMangledName(string);

    private:

      string m_mangledName;

      bool equalTo(const Symbol &rhs) const;

      static unsigned long m_localLabelCtr;

    };

  class NullSymbol : public OctaveSymbol
    {
    public:

      NullSymbol();

      NullSymbol(const NullSymbol& rhs);

      ~NullSymbol() {}	

      NullSymbol& operator=(const NullSymbol& rhs);

    private:

      bool equalTo(const Symbol &rhs) const;
      
    };

 
  class RegSymbol : public OctaveSymbol
    {
    public:
  
      virtual ~RegSymbol(){}

      virtual shared_ptr<const Register> getRegister() const =0;

      virtual shared_ptr<const Struct> getMappedStruct() const =0;
  
    protected:

      RegSymbol(const char *name, OctaveSymbol::ScopeQualifier scope);

      RegSymbol(const RegSymbol& rhs);

      RegSymbol& operator=(const RegSymbol& rhs);

    };


  class AbstractSymReg : public RegSymbol
    {
    public:

      enum SymRegConstraint { SRC_NONE   = 0, 
			      SRC_BEGIN_AT_EVEN_REG, 
			      SRC_BEGIN_AT_ODD_REG };
 
      ~AbstractSymReg(){}

      shared_ptr<const Struct> getMappedStruct() const;

      AbstractSymReg::SymRegConstraint getSymRegConstraint() const;

      shared_ptr<const Register> getContraintRegRange() const;

    protected:

      AbstractSymReg(const char *name, 
		     OctaveSymbol::ScopeQualifier,
		     AbstractSymReg::SymRegConstraint,
		     shared_ptr<const Register>);
	

      AbstractSymReg(const AbstractSymReg& rhs);

      AbstractSymReg& operator=(const AbstractSymReg& rhs);
    
    private:
      
      SymRegConstraint m_symRegConstraint;
      
      shared_ptr<const Register> m_constraintRegRange;

    };

  class SymReg : public AbstractSymReg
    {
    public:

      SymReg(const char* name, 
	     OctaveSymbol::ScopeQualifier, 
	     shared_ptr<const SingleRegister>,
	     AbstractSymReg::SymRegConstraint,
	     shared_ptr<const Register>);


      ~SymReg(){}

      SymReg(const SymReg& rhs);

      SymReg& operator=(const SymReg& rhs);

      shared_ptr<const Register> getRegister() const;

    private:

      bool equalTo(const Symbol &rhs) const;

    private:

      shared_ptr<const SingleRegister> m_singleReg;	

    };
 
  class MultiSymReg : public AbstractSymReg
    {
    public:

      MultiSymReg(const char *name, 
		  OctaveSymbol::ScopeQualifier, 
		  shared_ptr<const MultiRegister>);

      MultiSymReg(const char *name, 
		  OctaveSymbol::ScopeQualifier, 
		  shared_ptr<const MultiRegister>,
		  AbstractSymReg::SymRegConstraint,
		  shared_ptr<const Register>);

      ~MultiSymReg() {}

      MultiSymReg(const MultiSymReg& rhs);

      MultiSymReg& operator=(const MultiSymReg& rhs);

      shared_ptr<const Register> getRegister() const;

    private:

      bool equalTo(const Symbol &rhs) const;
  
    private:

      shared_ptr<const MultiRegister> m_multiReg;
  
    };

  class MapSymbol : public RegSymbol
    {
    public:

      MapSymbol(const char* name, 
		OctaveSymbol::ScopeQualifier, 
		shared_ptr<const Struct> t);

      virtual ~MapSymbol(){}  

      shared_ptr<const Struct> getMappedStruct() const;  

    protected:

      MapSymbol(const MapSymbol& rhs);

      MapSymbol& operator=(const MapSymbol& rhs);


    private:

      shared_ptr<const Struct> m_structType;
    };

  class MapToHardReg : public MapSymbol
    {
    public:
      MapToHardReg(const char* mapName, 
		   OctaveSymbol::ScopeQualifier s,  
		   shared_ptr<const Struct> tp, 
		   shared_ptr<const HardRegister> hreg); 

      ~MapToHardReg() {}

      MapToHardReg(const MapToHardReg& rhs);

      MapToHardReg& operator=(const MapToHardReg& rhs);

      shared_ptr<const Register> getRegister() const;

    private:

      bool equalTo(const Symbol &rhs) const;

    private:

      shared_ptr<const HardRegister> m_hReg;
    };

  class MapToPseudoReg : public MapSymbol
    {
    public:

      MapToPseudoReg(const char *mapName, 
		     OctaveSymbol::ScopeQualifier, 
		     shared_ptr<const Struct> st, 
		     shared_ptr<const PseudoRegister> sym);

      ~MapToPseudoReg() {}

      MapToPseudoReg(const MapToPseudoReg& rhs);

      MapToPseudoReg& operator=(const MapToPseudoReg& rhs); 

      shared_ptr<const Register> getRegister() const;

    private:

      bool equalTo(const Symbol &rhs) const;

    private:

      shared_ptr<const PseudoRegister> m_pseudoReg;
    };

  class MapToMultiHardReg : public MapSymbol
    {
    public:
      MapToMultiHardReg(const char *mapName, 
			OctaveSymbol::ScopeQualifier, 
			shared_ptr<const Struct> st, 
			shared_ptr<const MultiHardRegister> hreg);

      ~MapToMultiHardReg() {}

      MapToMultiHardReg(const MapToMultiHardReg& rhs);

      MapToMultiHardReg& operator=(const MapToMultiHardReg& rhs);

      shared_ptr<const Register> getRegister() const;

    private:

      bool equalTo(const Symbol &rhs) const;

    private:

      shared_ptr<const MultiHardRegister> m_multiHardReg;
 
    };

  class MapToMultiPseudoReg : public MapSymbol
    {
    public:
      MapToMultiPseudoReg(const char *mapName, 
			  OctaveSymbol::ScopeQualifier, 
			  shared_ptr<const Struct>, 
			  shared_ptr<const MultiPseudoRegister>); 

      ~MapToMultiPseudoReg() {}

      MapToMultiPseudoReg(const MapToMultiPseudoReg& rhs);

      MapToMultiPseudoReg& operator=(const MapToMultiPseudoReg& rhs);	

      shared_ptr<const Register> getRegister() const;

    
    private:

      bool equalTo(const Symbol& rhs) const;

    private:

      shared_ptr<const MultiPseudoRegister> m_multiPseudoReg;
    };



typedef shared_ptr<LabelSymbol> LabelSymbolPtr;
typedef shared_ptr<NullSymbol> NullSymbolPtr;
typedef shared_ptr<SymReg> SymRegPtr;
typedef shared_ptr<MultiSymReg> MultiSymRegPtr;
typedef shared_ptr<MapToPseudoReg> MapToPseudoRegPtr;
typedef shared_ptr<MapToMultiPseudoReg> MapToMultiPseudoRegPtr;
typedef shared_ptr<MapToHardReg> MapToHardRegPtr;
typedef shared_ptr<MapToMultiHardReg> MapToMultiHardRegPtr;







  class Type : public OctaveSymbol
    {

    public:

      typedef std::map<string, shared_ptr<Type> >::difference_type MapDiffType; 

      typedef StlRandomAccessIterator<Type, TypeIterator<MapDiffType>, MapDiffType> Iterator;

      typedef StlRandomAccessConstIterator<Type, TypeConstIterator<MapDiffType>, MapDiffType> ConstIterator;

      virtual ~Type(){}

      virtual unsigned int getSize() const=0;

      virtual unsigned int getOffset() const=0;

      virtual void addType(shared_ptr<Type> tp) =0;

      virtual Type::Iterator lookupType(const char *name) =0;

      virtual Type::ConstIterator lookupType(const char *name) const =0;

      virtual Type::Iterator begin()=0; 

      virtual Type::Iterator end()=0;

      virtual Type::ConstIterator begin() const =0; 

      virtual Type::ConstIterator end() const =0;

    protected:

      Type(const char *name, OctaveSymbol::ScopeQualifier scope);

      Type(const Type& rhs);

      Type& operator=(const Type& rhs);

    };


  class StructContent : public Type
    {
    public:

      virtual ~StructContent(){}

      unsigned int getOffset() const;

    protected:

      StructContent(const char *name, unsigned int offset, OctaveSymbol::ScopeQualifier scope);

      StructContent(const StructContent& rhs);

      StructContent& operator=(const StructContent& rhs);


    private:
	
      unsigned int m_offset;
    };



  class Struct : public StructContent
    {

    public:

      typedef map<std::string, shared_ptr<Type> >::iterator ScIterator;

      typedef map<std::string, shared_ptr<Type> >::const_iterator ScConstIterator;

      Struct(const char *name, 
	     unsigned int offset =0,  
	     OctaveSymbol::ScopeQualifier scope =OctaveSymbol::FILESCOPE);

      ~Struct(){}

      Struct(const Struct& rhs);

      Struct& operator=(const Struct& rhs);

      shared_ptr<Struct> createStruct(const char *name);

      shared_ptr<Element> createElement();

      void addType(shared_ptr<Type> newTp);

      Type::Iterator lookupType(const char *name);

      Type::ConstIterator lookupType(const char *name) const;

      unsigned int getSize() const;

      Type::Iterator begin();

      Type::Iterator end();

      Type::ConstIterator begin() const; 

      Type::ConstIterator end() const;

    protected:

      unsigned int getNextOffset();
 
    private:

      std::map<std::string, shared_ptr<Type> > m_scMap;

      unsigned int m_nextOffset;

      unsigned int m_size;

      bool equalTo(const Symbol &rhs) const;
    };

  class Element : public StructContent
    {
      static const int Element_Size = 4;

    public:

      typedef std::map<string, shared_ptr<Type> >::iterator FldIterator;

      typedef std::map<string, shared_ptr<Type> >::const_iterator FldConstIterator;

      Element(const char *name, unsigned int offset, 
	      OctaveSymbol::ScopeQualifier scope= OctaveSymbol::FILESCOPE);

      ~Element() {}

      Element(const Element& rhs);

      Element& operator=(const Element& rhs);
	
      shared_ptr<Field> createField(const char *name);

      shared_ptr<BitField> createField(const char *name, unsigned int msb, unsigned int lsb);

      void addType(shared_ptr<Type> newTp);

      Type::Iterator lookupType(const char *name);

      Type::ConstIterator lookupType(const char *name) const;

      unsigned int getSize() const;

      Type::Iterator begin();

      Type::Iterator end();

      Type::ConstIterator begin() const; 

      Type::ConstIterator end() const;

    private:

      std::map<string, shared_ptr<Type> > m_fldMap;

      bool equalTo(const Symbol &rhs) const;

    };

  class AbstractField : public StructContent
    {
      static const int Field_Size = 4;

    public:

      AbstractField(const char *name, 
		    unsigned int offset, 
		    unsigned int msb, 
		    unsigned int lsb, 
		    OctaveSymbol::ScopeQualifier scope = OctaveSymbol::FILESCOPE);

      virtual ~AbstractField() {}

      AbstractField(const AbstractField& rhs);

      AbstractField& operator=(const AbstractField& rhs);
	
      void addType(shared_ptr<Type> newTp); //Throws

      Type::Iterator lookupType(const char *name);  //Throws

      Type::ConstIterator lookupType(const char *name) const;  //Throws

      unsigned int getSize() const;

      unsigned int getMSBitPosition() const;

      unsigned int getLSBitPosition() const;

      Type::Iterator begin();

      Type::Iterator end();

      Type::ConstIterator begin() const; 

      Type::ConstIterator end() const;


    private:

      unsigned int m_msbPos;	  

      unsigned int m_lsbPos;	  

    };

  class Field : public AbstractField
    {
    public:

      Field(const char *name, 
	    unsigned int offset, 
	    OctaveSymbol::ScopeQualifier scope = OctaveSymbol::FILESCOPE);

      ~Field() {}

      Field(const Field& rhs);

      Field& operator=(const Field& rhs);

      void accept(Visitor &v) const;

    private:

      bool equalTo(const Symbol &rhs) const;

    };


  class BitField : public AbstractField
    {
    public:

      BitField(const char *name, 
	       unsigned int offset, 
	       unsigned int msb, 
	       unsigned int lsb, 
	       OctaveSymbol::ScopeQualifier scope = OctaveSymbol::FILESCOPE);

      ~BitField() {}

      BitField(const BitField& rhs);

      BitField& operator=(const BitField& rhs);

      void accept(Visitor &v) const;

    private:

      bool equalTo(const Symbol &rhs) const;

    };


  class NullType : public Type
    {

    public:

      NullType();

      NullType(const NullType& rhs);

      ~NullType(){}

      NullType& operator=(const NullType& rhs);

      unsigned int getSize() const;

      unsigned int getOffset() const;

      void addType(shared_ptr<Type> tp);

      Type::Iterator lookupType(const char *name);

      Type::ConstIterator lookupType(const char *name) const ;

      Type::Iterator begin();

      Type::Iterator end();

      Type::ConstIterator begin() const ;

      Type::ConstIterator end() const ;

      bool equalTo(const Symbol &rhs) const;

    };




  //--------------------------------------------------
  // StlRandomAccessIterator
  //--------------------------------------------------


  template <class S, class T, class DiffType>
    class StlRandomAccessIterator : public std::iterator<std::random_access_iterator_tag, shared_ptr<S>, DiffType>
    {
    public:
      StlRandomAccessIterator() : m_p( static_cast<shared_ptr<T> >(0) ) {}

      StlRandomAccessIterator(T *p) : m_p(p) {}

      StlRandomAccessIterator(const StlRandomAccessIterator &rhs) : m_p(rhs.m_p) {}

      const StlRandomAccessIterator& operator=(const StlRandomAccessIterator &rhs)
      {
	if (this == &rhs)
	  return *this;

	m_p = rhs.m_p;
	return *this;
      }

      ~StlRandomAccessIterator() {}

      StlRandomAccessIterator &operator++()
	{
	  m_p->preInc();
	  return *this;
	}

      StlRandomAccessIterator operator++(int)   // postincrement
	{
	  T *old = m_p->postInc();
	  return StlRandomAccessIterator(old) ;
	}

      StlRandomAccessIterator &operator--()
	{
	  m_p->preDec();
	  return *this;
	}

      StlRandomAccessIterator operator--(int)  // postdecrement
	{
	  T *old = m_p->postDec();
	  return StlRandomAccessIterator(old);
	}

      friend bool operator==(const StlRandomAccessIterator &lhs, const StlRandomAccessIterator &rhs)
      {
	return (*(lhs.m_p) == *(rhs.m_p));
      }

      friend bool operator!=(const StlRandomAccessIterator &lhs, const StlRandomAccessIterator &rhs)
      {
	return !(Llir::operator==(lhs,rhs));
      }

      shared_ptr<S>& operator*() const
	{
	  return m_p->operator*();
	}

      shared_ptr<S>* operator->() const
	{
	  return m_p->operator->();
	}

      //new operators

      StlRandomAccessIterator operator+(DiffType n) const 
	{ 
	  return StlRandomAccessIterator(m_p->operator+(n));
	}

      StlRandomAccessIterator& operator+=(DiffType n) 
      {
	m_p->operator+=(n); 
	return *this;
      }

      StlRandomAccessIterator operator-(DiffType n) const 
	{ 
	  return StlRandomAccessIterator(m_p->operator-(n)); 
	}

      StlRandomAccessIterator& operator-=(DiffType n) 
      {
	m_p->operator-=(n); 
	return *this;
      }

      shared_ptr<S> operator[](DiffType n) const 
	{ 
	  shared_ptr<T> tmp = m_p->operator+(n);
	  return tmp->operator*();
	} 

      /*
	shared_ptr<S> operator[]=(DiffType n, shared_ptr<S> val) const
	{
	shared_ptr<T> tmp = m_p->operator+(n);
	tmp->operator*() = val;
	}
      */

      friend DiffType operator-(StlRandomAccessIterator &lhs, StlRandomAccessIterator &rhs)
	{
	  return lhs.m_p - rhs.m_p;
	}

      friend bool operator<(StlRandomAccessIterator &lhs, StlRandomAccessIterator &rhs)
	{
	  return lhs.m_p < rhs.m_p;
	}

    private:
      shared_ptr<T> m_p;

    };


  //--------------------------------------------------
  // StlRandomAccessConstIterator
  //--------------------------------------------------

  template <class S, class T, class DiffType>
    class StlRandomAccessConstIterator : public std::iterator<std::random_access_iterator_tag, shared_ptr<S>, DiffType>
    {
    public:
      StlRandomAccessConstIterator() : m_p( static_cast<shared_ptr<const T> >(0) ) {}

      StlRandomAccessConstIterator(T *p) : m_p(p) {}

      StlRandomAccessConstIterator(const StlRandomAccessConstIterator &rhs) : m_p(rhs.m_p) {}

      const StlRandomAccessConstIterator& operator=(const StlRandomAccessConstIterator &rhs)
      {
	if (this == &rhs)
	  return *this;

	m_p = rhs.m_p;
	return *this;
      }

      ~StlRandomAccessConstIterator() {}

      StlRandomAccessConstIterator &operator++()
	{
	  m_p->preInc();
	  return *this;
	}

      StlRandomAccessConstIterator operator++(int)   // postincrement
	{
	  T *old = m_p->postInc();
	  return StlRandomAccessConstIterator(old);
	}

      StlRandomAccessConstIterator &operator--()
	{
	  m_p->preDec();
	  return *this;
	}

      StlRandomAccessConstIterator operator--(int)  // postdecrement
	{
	  T *old = m_p->postDec();
	  return StlRandomAccessConstIterator(old);
	}

      friend bool operator==(const StlRandomAccessConstIterator &lhs, const StlRandomAccessConstIterator &rhs)
      {
	return (*(lhs.m_p) == *(rhs.m_p));
      }

      friend bool operator!=(const StlRandomAccessConstIterator &lhs, const StlRandomAccessConstIterator &rhs)
      {
	return !(Llir::operator==(lhs,rhs));
      }

      const shared_ptr<S>& operator*() const
	{
	  return m_p->operator*();
	}

      const shared_ptr<S>* operator->() const
	{
	  return m_p->operator->();
	}

      //new operators

      StlRandomAccessConstIterator operator+(DiffType n) const 
	{ 
	  return StlRandomAccessConstIterator(m_p->operator+(n));
	}

      StlRandomAccessConstIterator& operator+=(DiffType n) 
      {
	m_p->operator+=(n); 
	return *this;
      }

      StlRandomAccessConstIterator operator-(DiffType n) const 
	{ 
	  return StlRandomAccessConstIterator(m_p->operator-(n)); 
	}

      StlRandomAccessConstIterator& operator-=(DiffType n) 
      {
	m_p->operator-=(n); 
	return *this;
      }

      shared_ptr<S> operator[](DiffType n) const 
	{ 
	  shared_ptr<T> tmp = m_p->operator+(n);
	  return tmp->operator*();
	} 

      /*
	shared_ptr<S> operator[]=(DiffType n, shared_ptr<S> val) const
	{
	shared_ptr<T> tmp = m_p->operator+(n);
	tmp->operator*() = val;
	}
      */

      friend DiffType operator-(StlRandomAccessConstIterator &lhs, StlRandomAccessConstIterator &rhs)
	{
	  return lhs.m_p - rhs.m_p;
	}

      friend bool operator<(StlRandomAccessConstIterator &lhs, StlRandomAccessConstIterator &rhs)
	{
	  return lhs.m_p < rhs.m_p;
	}

    private:
      shared_ptr<T> m_p;

    };




  //--------------------------
  // TypeIterator 
  //--------------------------

  typedef std::map<string, shared_ptr<Type> >::difference_type MapDiffType;
  bool operator==(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs);
  bool operator!=(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs);
  bool operator-(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs);
  bool operator<(const TypeIterator<MapDiffType> &lhs, const TypeIterator<MapDiffType> &rhs);


  template<class DiffTp>
    class TypeIterator
    {
    public:
      virtual ~TypeIterator() 
	{}

      virtual TypeIterator<DiffTp>* postInc() = 0;

      virtual void preInc() = 0;

      virtual TypeIterator<DiffTp>* postDec() = 0;

      virtual void preDec() = 0;

      virtual shared_ptr<Type>& operator*() = 0;

      virtual shared_ptr<Type> *operator->() = 0;

      bool equal(const TypeIterator &rhs) const
	{
	  if (typeid(*this) == typeid(rhs))
	    return equalTo(rhs);
	  else
	    return false;
	}

      //new operators
      virtual shared_ptr<TypeIterator> operator+(DiffTp count) = 0; 

      virtual TypeIterator& operator+=(DiffTp count) = 0; 

      virtual shared_ptr<TypeIterator> operator-(DiffTp count) = 0; 

      virtual TypeIterator& operator-=(DiffTp count) = 0; 

      virtual shared_ptr<Type> operator[](DiffTp index) = 0; 

    protected:

      TypeIterator() {}

      TypeIterator(const TypeIterator &) {}

      virtual bool equalTo(const TypeIterator &rhs) const = 0;

      TypeIterator &operator=(const TypeIterator &) {	return *this; }

    };


  //--------------------------
  // TypeConstIterator
  //--------------------------

  bool operator==(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs);
  bool operator!=(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs);
  bool operator-(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs);
  bool operator<(const TypeConstIterator<MapDiffType> &lhs, const TypeConstIterator<MapDiffType> &rhs);

  template<class DiffTp>
    class TypeConstIterator
    {
    public:
      virtual ~TypeConstIterator() {}

      virtual TypeConstIterator<DiffTp>* postInc() = 0;

      virtual void preInc() = 0;

      virtual TypeConstIterator<DiffTp>* postDec() = 0;

      virtual void preDec() = 0;

      virtual const shared_ptr<Type>& operator*() = 0;

      virtual const shared_ptr<Type> *operator->() = 0;

      bool equal(const TypeConstIterator &rhs) const
	{
	  if (typeid(*this) == typeid(rhs))
	    return equalTo(rhs);
	  else
	    return false;
	}

      //new operators

      virtual shared_ptr<TypeConstIterator> operator+(DiffTp count) = 0; 

      virtual TypeConstIterator& operator+=(DiffTp count) = 0; 

      virtual shared_ptr<TypeConstIterator> operator-(DiffTp count) = 0; 

      virtual TypeConstIterator& operator-=(DiffTp count) = 0; 

      virtual const shared_ptr<Type> operator[](DiffTp index) = 0; 

    protected:

      TypeConstIterator() {}

      TypeConstIterator(const TypeConstIterator &) {}

      virtual bool equalTo(const TypeConstIterator &rhs) const = 0;

      TypeConstIterator &operator=(const TypeConstIterator &) 
      {	
	return *this; 
      }

    };



  //--------------------------
  // StructTypeIterator
  //--------------------------

  template<class DiffTp>
    class StructTypeIterator : public TypeIterator<DiffTp>
    {
    public:

      StructTypeIterator() {}

      StructTypeIterator(Struct::ScIterator iter) : m_iterator(iter) {}

      StructTypeIterator(const StructTypeIterator &rhs) 
	:  TypeIterator<DiffTp>(rhs),  
	m_iterator(rhs.m_iterator) {}

      StructTypeIterator& operator=(const StructTypeIterator &rhs)
      {  
	if (this == &rhs) 
	  return *this;

	this->TypeIterator<DiffTp>::operator=(rhs);
	m_iterator = rhs.m_iterator;
	return *this;
      }

      ~StructTypeIterator() {}

      TypeIterator<DiffTp>* postInc() 
        { 
  	  TypeIterator<DiffTp>* old( new StructTypeIterator(m_iterator) );
	  m_iterator++; 
 	  return old;
        }

      void preInc()  
        { 
	  ++m_iterator; 
   	}

      TypeIterator<DiffTp>* postDec() 
	{ 
  	  TypeIterator<DiffTp>* old( new StructTypeIterator(m_iterator) );
	  m_iterator--; 
 	  return old;
 	}

      void preDec()  
	{ 
	  --m_iterator; 
	}

      shared_ptr<Type>& operator*() 
	{ 
	  return m_iterator->second; 
	}

      shared_ptr<Type> *operator->() 
	{ 
	  return &(m_iterator->second); 
	}

      bool equalTo(const TypeIterator<DiffTp> &rhs) const
	{
	  return (m_iterator == (dynamic_cast<const StructTypeIterator<DiffTp> &> (rhs)).m_iterator);
	}

      //new operators
      shared_ptr<TypeIterator<DiffTp> > operator+(DiffTp count)
	{
	  shared_ptr<StructTypeIterator<DiffTp> >  tmp ( new StructTypeIterator<DiffTp> (*this) );

          if(count > 0)
          {
	    while(count--) { tmp->preInc(); }
          }
          else
          {
            while(count++) { tmp->preDec(); }
          }

	  return tmp;
	}

      shared_ptr<TypeIterator<DiffTp> > operator-(DiffTp count) 
	{
  	  shared_ptr<StructTypeIterator<DiffTp> >  tmp ( new StructTypeIterator<DiffTp> (*this) );

          if(count > 0)
          {
  	    while(count--) { tmp->preDec(); }
          }
          else
          {
            while(count++) { tmp->preDec(); }
          }

  	  return tmp;
	}

      TypeIterator<DiffTp>& operator+=(DiffTp count)
      { 
          if(count > 0)
          {
	    while(count--) { this->preInc(); }
          }
          else
          {
            while(count++) { this->preDec(); }
          }

	return *this;
      }
 
      TypeIterator<DiffTp>& operator-=(DiffTp count) 
      { 
          if(count > 0)
          {
	    while(count--) { this->preDec(); }
          }
          else
          {
	    while(count++) { this->preInc(); }
          }

	return *this;
      }

      shared_ptr<Type> operator[](DiffTp index)
	{
          //FIXME : fix this ????
  	  StructTypeIterator<DiffTp> tmp(*this);

          if(index > 0)
          {
  	    while(index--) { tmp.preInc(); }
          }
	  else
	  {
  	    while(index++) { tmp.preDec(); }
	  }

	  return *tmp;
	}

    private:

      Struct::ScIterator m_iterator;

    };

  //--------------------------
  // StructTypeConstIterator
  //--------------------------

  template<class DiffTp>
    class StructTypeConstIterator : public TypeConstIterator<DiffTp>
    {
    public:

      StructTypeConstIterator() {}

      StructTypeConstIterator(Struct::ScConstIterator iter) 
	: m_iterator(iter) {}

      StructTypeConstIterator(const StructTypeConstIterator &rhs) 
	:  TypeConstIterator<DiffTp>(rhs),  
	m_iterator(rhs.m_iterator) 	{}

      ~StructTypeConstIterator() {}

      StructTypeConstIterator& operator=(const StructTypeConstIterator &rhs)
      {  
	if (this == &rhs) 
	  return *this;

	this->TypeConstIterator<DiffTp>::operator=(rhs);
	m_iterator = rhs.m_iterator;
	return *this;
      }

      bool equalTo(const TypeConstIterator<DiffTp> &rhs) const
	{
	  return (m_iterator == (dynamic_cast<const StructTypeConstIterator<DiffTp> &> (rhs)).m_iterator);
	}

     TypeConstIterator<DiffTp>* postInc() 
        { 
  	  TypeConstIterator<DiffTp>* old( new StructTypeConstIterator(m_iterator) );
	  m_iterator++; 
 	  return old;
        }

      void preInc()  
        { 
	  ++m_iterator; 
   	}

      TypeConstIterator<DiffTp>* postDec() 
	{ 
  	  TypeConstIterator<DiffTp>* old( new StructTypeConstIterator(m_iterator) );
	  m_iterator--; 
 	  return old;
 	}

      void preDec()  
	{ 
	  --m_iterator; 
	}

      const shared_ptr<Type>& operator*() 
	{ 
	  return m_iterator->second; 
	}

      const shared_ptr<Type> *operator->() 
	{ 
	  return &(m_iterator->second); 
	}

      //new operators

      shared_ptr<TypeConstIterator<DiffTp> > operator+(DiffTp count)
	{
	  shared_ptr<StructTypeConstIterator<DiffTp> >  tmp ( new StructTypeConstIterator<DiffTp> (*this) );

          if(count > 0)
          {
	    while(count--) { tmp->preInc(); }
          }
          else
          {
            while(count++) { tmp->preDec(); }
          }

	  return tmp;

	}

      shared_ptr<TypeConstIterator<DiffTp> > operator-(DiffTp count) 
	{


	  shared_ptr<StructTypeConstIterator<DiffTp> >  tmp ( new StructTypeConstIterator<DiffTp> (*this) );

          if(count > 0)
          {
  	    while(count--) { tmp->preDec(); }
          }
          else
          {
            while(count++) { tmp->preDec(); }
          }

  	  return tmp;


	}

      TypeConstIterator<DiffTp>& operator+=(DiffTp count)
      { 

         if(count > 0)
          {
	    while(count--) { this->preInc(); }
          }
          else
          {
            while(count++) { this->preDec(); }
          }

	return *this;
      }
 
      TypeConstIterator<DiffTp>& operator-=(DiffTp count) 
      { 
          if(count > 0)
          {
	    while(count--) { this->preDec(); }
          }
          else
          {
	    while(count++) { this->preInc(); }
          }

	return *this;
      }

      const shared_ptr<Type> operator[](DiffTp index)
	{

          //FIXME : fix this ????
  	  StructTypeConstIterator<DiffTp> tmp(*this);

          if(index > 0)
          {
  	    while(index--) { tmp.preInc(); }
          }
	  else
	  {
  	    while(index++) { tmp.preDec(); }
	  }

	  return *tmp;
	}

    private:

      Struct::ScConstIterator m_iterator;

    };


  //--------------------------
  // ElementTypeIterator
  //--------------------------



  template<class DiffTp>
    class ElementTypeIterator : public TypeIterator<DiffTp>
    {

    public:

      ElementTypeIterator() {}

      ElementTypeIterator(Element::FldIterator iter) : m_iterator(iter) {}

      ElementTypeIterator(const ElementTypeIterator &rhs) 
	: TypeIterator<DiffTp>(rhs),
	m_iterator(rhs.m_iterator) {}

      ElementTypeIterator& operator=(const ElementTypeIterator &rhs)
      {
	if (this == &rhs)
    	  return *this;

	this->TypeIterator<DiffTp>::operator=(rhs);
	m_iterator = rhs.m_iterator;
	return *this;
      }

      ~ElementTypeIterator() {}

      bool equalTo(const TypeIterator<DiffTp> &rhs) const
	{
	  return (m_iterator == (dynamic_cast<const ElementTypeIterator<DiffTp> &> (rhs)).m_iterator);
	}

      TypeIterator<DiffTp>* postInc()
        {
          TypeIterator<DiffTp>* old( new ElementTypeIterator(m_iterator) );
          m_iterator++;
          return old;
        }

      void preInc()
        {
          ++m_iterator;
        }

      TypeIterator<DiffTp>* postDec()
        {
          TypeIterator<DiffTp>* old( new ElementTypeIterator(m_iterator) );
          m_iterator--;
          return old;
        }

      void preDec()
        {
          --m_iterator;
        }
	
      shared_ptr<Type>& operator*()
	{
	  return m_iterator->second;
	}

      shared_ptr<Type> *operator->()
	{
	  return &(m_iterator->second);
	}

      //new operators

      shared_ptr<TypeIterator<DiffTp> > operator+(DiffTp count) 
	{
  	  shared_ptr<ElementTypeIterator<DiffTp> >  tmp ( new ElementTypeIterator<DiffTp>(*this) );

          if(count > 0)
          {
            while(count--) { tmp->preInc(); }
          }
          else
          {
            while(count++) { tmp->preDec(); }
          }

  	  return tmp;
	}
	
      shared_ptr<TypeIterator<DiffTp> > operator-(DiffTp count) 
	{
	  shared_ptr<ElementTypeIterator<DiffTp> >  tmp ( new ElementTypeIterator(*this) );


          if(count > 0)
          {
            while(count--) { tmp->preDec(); }
          }
          else
          {
            while(count++) { tmp->preInc(); }
          }

  	  return tmp;
	}

      TypeIterator<DiffTp>& operator+=(DiffTp count) 
      {

          if(count > 0)
          {
            while(count--) { this->preInc(); }
          }
          else
          {
            while(count++) { this->preDec(); }
          }

	return *this;
      }

      TypeIterator<DiffTp>& operator-=(DiffTp count) 
      {

          if(count > 0)
          {
            while(count--) { this->preDec(); }
          }
          else
          {
            while(count++) { this->preInc(); }
          }

	return *this;
      }

      shared_ptr<Type> operator[](DiffTp index)
	{
          //FIXME : fix this ????
	  ElementTypeIterator<DiffTp> tmp(*this);
            
          if(index > 0)
          {
  	    while(index--) { tmp.preInc(); }
          }
	  else
	  {
  	    while(index++) { tmp.preDec(); }
	  }

  	  return *tmp;
	}

    private:

      Element::FldIterator m_iterator;

    };



  //--------------------------
  // ElementTypeConstIterator
  //--------------------------




  template<class DiffTp>
    class ElementTypeConstIterator : public TypeConstIterator<DiffTp>
    {

    public:

      ElementTypeConstIterator() {}

      ElementTypeConstIterator(Element::FldConstIterator iter) : m_iterator(iter) {}

      ElementTypeConstIterator(const ElementTypeConstIterator &rhs) 
	: TypeConstIterator<DiffTp>(rhs),
	m_iterator(rhs.m_iterator) {}

      ~ElementTypeConstIterator() {}

      ElementTypeConstIterator& operator=(const ElementTypeConstIterator &rhs)
      {
	if (this == &rhs)
    	  return *this;

	this->TypeConstIterator<DiffTp>::operator=(rhs);
	m_iterator = rhs.m_iterator;
	return *this;
      }

      bool equalTo(const TypeConstIterator<DiffTp> &rhs) const
	{
	  return (m_iterator == (dynamic_cast<const ElementTypeConstIterator<DiffTp> &> (rhs)).m_iterator);
	}

      TypeConstIterator<DiffTp>* postInc()
	{          
	  TypeConstIterator<DiffTp>* old( new ElementTypeConstIterator(m_iterator) );
          m_iterator++;
          return old;
	  
	}	

      void preInc()
	{
	  ++m_iterator;
	}	

      TypeConstIterator<DiffTp>* postDec()
	{
          TypeConstIterator<DiffTp>* old( new ElementTypeConstIterator(m_iterator) );
          m_iterator--;
          return old;
	}	
	
      void preDec()
	{
	  --m_iterator;
	}
	
      const shared_ptr<Type>& operator*()
	{
	  return m_iterator->second;
	}

      const shared_ptr<Type>* operator->()
	{
	  return &(m_iterator->second);
	}

      //new operators

      shared_ptr<TypeConstIterator<DiffTp> > operator+(DiffTp count) 
	{
 	  shared_ptr<ElementTypeConstIterator<DiffTp> >  tmp ( new ElementTypeConstIterator<DiffTp>(*this) );

          if(count > 0)
          {
            while(count--) { tmp->preInc(); }
          }
          else
          {
            while(count++) { tmp->preDec(); }
          }

  	  return tmp;
	}
	
      shared_ptr<TypeConstIterator<DiffTp> > operator-(DiffTp count) 
	{

	  shared_ptr<ElementTypeConstIterator<DiffTp> >  tmp ( new ElementTypeConstIterator(*this) );


          if(count > 0)
          {
            while(count--) { tmp->preDec(); }
          }
          else
          {
            while(count++) { tmp->preInc(); }
          }

  	  return tmp;

	}

      TypeConstIterator<DiffTp>& operator+=(DiffTp count) 
      {

          if(count > 0)
          {
            while(count--) { this->preInc(); }
          }
          else
          {
            while(count++) { this->preDec(); }
          }

	return *this;

      }

      TypeConstIterator<DiffTp>& operator-=(DiffTp count) 
      {

          if(count > 0)
          {
            while(count--) { this->preDec(); }
          }
          else
          {
            while(count++) { this->preInc(); }
          }

	return *this;

      }

      const shared_ptr<Type> operator[](DiffTp index)
	{
	
          //FIXME : fix this ????
	  ElementTypeConstIterator<DiffTp> tmp(*this);
            
          if(index > 0)
          {
  	    while(index--) { tmp.preInc(); }
          }
	  else
	  {
  	    while(index++) { tmp.preDec(); }
	  }

  	  return *tmp;


	}

    private:

      Element::FldConstIterator m_iterator;

    };


  //--------------------------
  // NullRAIterator
  //--------------------------


  template<class DiffTp>
    class NullRAIterator : public TypeIterator<DiffTp>
    {

    public:

      NullRAIterator() {}

      //NullRAIterator(Field::NullRAIterator);

      NullRAIterator(const NullRAIterator &rhs) : TypeIterator<DiffTp>(rhs) {} 

      NullRAIterator& operator=(const NullRAIterator &rhs)
      {
	if(this == &rhs) return *this;
	this->TypeIterator<DiffTp>::operator=(rhs);
	return *this;
      }

      ~NullRAIterator() {}

      bool equalTo(const TypeIterator<DiffTp> &rhs) const
	{
   	  //return (this == (dynamic_cast<const NullRAIterator<DiffTp> &> (rhs)));
   	  return true;
	}

      NullRAIterator<DiffTp>* postInc() 
	{ 
	  //assert 
	  return m_dummyIter;
	}

      void preInc()
	{
          //assert 
	}

       NullRAIterator<DiffTp>* postDec()
	{
          //assert  
	  return m_dummyIter;

	}

      void preDec() 
	{
	  //assert 
	}

      shared_ptr<Type>& operator*()
	{ 
	  return dummy1; //to shut the compiler warning 
        }

      shared_ptr<Type> *operator->()
	{ 
	  return &dummy1; //to shut the compiler warning 
        }

      //new operators
      shared_ptr<TypeIterator<DiffTp> > operator+(DiffTp count)
	{
	  return dummy2; //to shut the compiler warning 
	}
	
      TypeIterator<DiffTp>& operator+=(DiffTp count) 
      {
	return *dummy2; //to shut the compiler warning 
      }

      shared_ptr<TypeIterator<DiffTp> > operator-(DiffTp count) 
	{
	  return dummy2; //to shut the compiler warning 
	}	

      TypeIterator<DiffTp>& operator-=(DiffTp count) 
      {
	return *dummy2; //to shut the compiler warning 
      }

      shared_ptr<Type> operator[](DiffTp index)
	{ 
	  return dummy1; //to shut the compiler warning 
        }


    private:

      shared_ptr<Type> dummy1;

      shared_ptr<TypeIterator<DiffTp> > dummy2;

      NullRAIterator *m_dummyIter;
    };


  //--------------------------
  // NullRAConstIterator
  //--------------------------



  template<class DiffTp>
    class NullRAConstIterator : public TypeConstIterator<DiffTp>
    {

    public:

      NullRAConstIterator() {}

      //NullRAConstIterator(Field::NullRAConstIterator);

      NullRAConstIterator(const NullRAConstIterator &rhs) : TypeConstIterator<DiffTp>(rhs) {} 

      NullRAConstIterator& operator=(const NullRAConstIterator &rhs)
      {
	if(this == &rhs) return *this;
	this->TypeConstIterator<DiffTp>::operator=(rhs);
	return *this;
      }

      ~NullRAConstIterator() {}

      bool equalTo(const TypeConstIterator<DiffTp> &rhs) const
	{
   	  //return (this == (dynamic_cast<const NullRAConstIterator<DiffTp> &> (rhs)));
   	  return true;
	}

       NullRAConstIterator<DiffTp>* postInc() 
	{ 
	  //assert
	  return m_dummyCIter;
	}

      void preInc()
	{
          //assert 
	}

      NullRAConstIterator<DiffTp>* postDec()
	{
          //assert 
	  return m_dummyCIter;
	}

      void preDec() 
	{
	  //assert 
	}

      const shared_ptr<Type>& operator*()
	{ 
	  return dummy1; //to shut the compiler warning 
        }

      const shared_ptr<Type> *operator->()
	{ 
	  return &dummy1; //to shut the compiler warning 
        }

      //new operators
      shared_ptr<TypeConstIterator<DiffTp> > operator+(DiffTp count)
	{
	  return dummy2; //to shut the compiler warning 
	}
	
      TypeConstIterator<DiffTp>& operator+=(DiffTp count) 
      {
	return *dummy2; //to shut the compiler warning 
      }

      shared_ptr<TypeConstIterator<DiffTp> > operator-(DiffTp count) 
	{
	  return dummy2; //to shut the compiler warning 
	}	

      TypeConstIterator<DiffTp>& operator-=(DiffTp count) 
      {
	return *dummy2; //to shut the compiler warning 
      }

      const shared_ptr<Type> operator[](DiffTp index)
	{ 
	  return dummy1; //to shut the compiler warning 
        }


    private:
      shared_ptr<Type> dummy1;

      shared_ptr<TypeConstIterator<DiffTp> > dummy2;

      NullRAConstIterator<DiffTp>* m_dummyCIter;
    };







}  // namespace Llir







#endif

