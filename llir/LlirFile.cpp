#include <iostream>
using namespace std;


#include "LlirFile.h"
#include "LlirVisitor.h"
#include "LlirException.h"

namespace Llir {

LlirFile::LlirFile(const char *name) : m_FileName(name)
{}

LlirFile::~LlirFile() 
{}

void
LlirFile::addLlirNode(shared_ptr<LlirNode> node)
{
   m_nodeList.push_back(node);
}

LlirFile::Iterator
LlirFile::begin()
{
   return m_nodeList.begin();
}

LlirFile::Iterator
LlirFile::end()
{
   return m_nodeList.end();
}

LlirFile::ConstIterator
LlirFile::begin() const
{
   return m_nodeList.begin();
}

LlirFile::ConstIterator
LlirFile::end() const
{
   return m_nodeList.end();
}

const std::string&
LlirFile::getName() const
{
   return m_FileName;
}


void
LlirFile::accept(Visitor& v) const
{
  if(LlirVisitor *lv = dynamic_cast<LlirVisitor *>(&v))
  {
    lv->visit(*this);
  } 
  else
  {
    throw LLIR_INTERNAL_EXCEPTION("accept error");
  }	 
}


}  // namespace Llir


