#ifndef _LLIR_FILE_H
#define _LLIR_FILE_H

/**
  * \file
  *
  * \author Kiran Kumar K.
  * 
  * \version
  *
  * \brief LlirFile Class Description
  * 
  */

/**
  * Standard Header Files
  */

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
using namespace boost;

#include "LlirNode.h"



namespace Llir {


/**
 *
 * An LlirFile Object is created once per file being
 * processed by ALO. LlirFile is a container class and
 * holds the set of nodes which are objects of class LlirNode.
 * Public interface methods nodeBegin() and nodeEnd() provide 
 * access to this list.
 *
 * Singleton pattern to be used for ensuring that 
 * only one instance of this class exists at runtime
 *
 * Genereal Comment: 
 * In this project it is decided that to take
 * advantage of Value Semantics provided by SmartPointers as opposed
 * Bare Pointers, shared_ptr implementation from boost Library will be
 * used. Refer to Andrei Alexandrescu book Modern C++ Design for more details.
 * Similarly references or const references would be passed appropriately
 * instead of passing objects by value wherever possible.
 *
 * Exception to To this General Comment:
 * In all member functions which takes a char* pointer it is decided for 
 * for performance reasons that a 'const char *' would be passed instead
 * of std::string objects.
 *
 */

class Visitor;

class LlirFile 
{
public:

  typedef std::list<shared_ptr<LlirNode> >::iterator Iterator;
  typedef std::list<shared_ptr<LlirNode> >::const_iterator ConstIterator;

  LlirFile(const char *name);
  ~LlirFile();
  void addLlirNode(shared_ptr<LlirNode> node);

  Iterator begin();
  Iterator end();
  ConstIterator begin() const;
  ConstIterator end() const;
  const std::string& getName() const;

  void accept(Visitor &v) const;

private:

  std::string m_FileName;

  std::list<shared_ptr<LlirNode> > m_nodeList;

  LlirFile(const LlirFile &);
  LlirFile& operator=(const LlirFile &);

};

}  // namespace Llir


#endif
