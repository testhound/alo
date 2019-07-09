#ifndef _OCTAVE_CFG_BUILDER_H_
#define _OCTAVE_CFG_BUILDER_H_

#include <LlirNode.h>
#include <OctaveNode.h>

#include <LlirCfgBuilder.h>
#include "BasicBlock.h"


namespace Llir
{
  class OctaveCFGBuilder : public LlirCFGBuilder<BasicBlock<LlirNode, BitVector>, Edge>
    {
    public:

      OctaveCFGBuilder(shared_ptr<AltEntryFunction> f);
      ~OctaveCFGBuilder();
      OctaveCFGBuilder& operator=(const OctaveCFGBuilder& rhs);
      OctaveCFGBuilder(const OctaveCFGBuilder& rhs);

    private:

      shared_ptr<AltEntryFunction> m_f;
      std::list<shared_ptr<LlirNode> > m_nodeList;

    protected:

      void identifyValidLlirNodes();
      void identifyValidLlirNodes(shared_ptr<LlirNode> blk);

      bool isJtableBeginDirective(shared_ptr<LlirNode> node);

      typedef std::list<shared_ptr<LlirNode> >::iterator InsnListIterator;
      typedef std::list<shared_ptr<LlirNode> >::const_iterator InsnListConstIterator;

      InsnListIterator insnListBegin();
      InsnListIterator insnListEnd();
      InsnListConstIterator insnListBegin() const;
      InsnListConstIterator insnListEnd() const;

      shared_ptr<AltEntryFunction> getCurrentFunction() const;
      bool isJtableBegin(shared_ptr<LlirNode> node) const;
      bool isEntryPointLabel(shared_ptr<AltEntryFunction> fn, shared_ptr<LlirNode> node) const;
   
      bool isLastNode(shared_ptr<LlirNode> node) const;
      InsnListIterator searchForLabel(const char* name);
      shared_ptr<LlirNode> getJtableBeginDirective(const char* name) const;

    };
}

#endif
