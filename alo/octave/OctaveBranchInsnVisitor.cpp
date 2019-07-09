#include <cmath>
#include <sstream>
using namespace std;
#include <OctaveNode.h>
#include <OctaveOperand.h>
#include <OctavePrintVisitor.h>

#include "OctaveBranchInsnVisitor.h"

using namespace Llir;
using namespace Alo;
 

namespace Alo
{

  OctaveBranchInsnVisitor::OctaveBranchInsnVisitor(OctaveAlo &o)    
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(o)
  {}

  OctaveBranchInsnVisitor::OctaveBranchInsnVisitor(const OctaveBranchInsnVisitor& rhs)
    : Visitor(),
      LlirOctaveVisitor(),
      m_alo(rhs.m_alo)
  {}
  
  const OctaveBranchInsnVisitor&
  OctaveBranchInsnVisitor::operator=(const OctaveBranchInsnVisitor& rhs)
  {
    if(this == &rhs)
      return *this;

    Visitor::operator=(rhs);
    LlirOctaveVisitor::operator=(rhs);
    
    m_alo = rhs.m_alo;

    return *this;
  }

  OctaveAlo&
  OctaveBranchInsnVisitor::getAlo() const
  {
    return m_alo;
  }

  void
  OctaveBranchInsnVisitor::visit(const LlirSequence& seq)
  {
    LlirNode::ConstIterator it = seq.begin();

    for (; it != seq.end(); it++)
      (*it)->accept(*this);

  }

  void
  OctaveBranchInsnVisitor::visit(const OctaveBlock& block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveBranchInsnVisitor::visit(const OctaveMacroBlock &macroBlk)
  {
    LlirNode::ConstIterator it = macroBlk.begin();

    for (; it != macroBlk.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveBranchInsnVisitor::visit(const OctaveImplicitBlock &block)
  {
    LlirNode::ConstIterator it = block.begin();

    for (; it != block.end(); it++)
      (*it)->accept(*this);
  }

  void
  OctaveBranchInsnVisitor::visit(const LlirLineControlDirective& v)
  {}

  void
  OctaveBranchInsnVisitor::visit(const MultipleEntryEvh &d)
  {
    d.getImplicitBlock()->accept(*this);
  }

  void
  OctaveBranchInsnVisitor::visit(const MultipleEntryFunction &d)
  {
    d.getImplicitBlock()->accept(*this);
  }
  
  void
  OctaveBranchInsnVisitor::visit(const JtableRelativeBegin& d)
  {
    d.getLabelList()->accept(*this);
  }

  void
  OctaveBranchInsnVisitor::visit(const JtableBegin& d)
  {
    d.getLabelList()->accept(*this);
  }

  void
  OctaveBranchInsnVisitor::visit(const LabelList &l)
  {
    LabelList::ConstIterator iter = l.begin();
    for(; iter != l.end(); iter++)
      {
	(*iter)->setBranchTarget();
      }
  }

}








