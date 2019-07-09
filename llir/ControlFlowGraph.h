#ifndef _CONTROL_FLOW_GRAPH_H_
#define _CONTROL_FLOW_GRAPH_H_

#include <boost/graph/adjacency_list.hpp>
#include <boost/property_map.hpp>

namespace boost
{

  enum vertex_llir_bb_t { vertex_llir_bb };
  enum edge_llir_e_t { edge_llir_e };

  BOOST_INSTALL_PROPERTY (vertex, llir_bb);
  BOOST_INSTALL_PROPERTY (edge, llir_e);
}


namespace Llir
{
  using namespace boost;

  template <class B, class E>
    class ControlFlowGraph
    {
    public:

      typedef adjacency_list
	<// Store edges in a list
	listS,
	// Store vertex set in a vector
	vecS,
	// The CFG is directed
	bidirectionalS,
	// additional attribute of vertex
	property <vertex_llir_bb_t, shared_ptr<B> >,
	// additional attribute of edge
	property <edge_llir_e_t, shared_ptr<E> >
	> Graph;

      typedef graph_traits<Graph>::vertex_descriptor Vertex;
      typedef graph_traits<Graph>::edge_descriptor Edge;
      
      typedef property_map<Graph, vertex_llir_bb_t>::type VertexPropertyType;
      typedef property_map<Graph, edge_llir_e_t>::type EdgePropertyType;

      typedef graph_traits<Graph>::in_edge_iterator PredEdgeListIter;
      typedef graph_traits<Graph>::out_edge_iterator SuccEdgeListIter;

      typedef graph_traits<Graph>::vertex_iterator BasicBlockIterator;

      ControlFlowGraph(const char* name) 
	: m_name(name),
	m_graph(Graph()),
	m_bbIndex(0) {}

      ControlFlowGraph(const ControlFlowGraph& rhs) 
	: m_name(rhs.m_name),
	m_graph(rhs.m_graph),
	m_bbIndex(rhs.m_bbIndex)
	{}
	
      ControlFlowGraph& operator=(const ControlFlowGraph& rhs)
	{
	  if(this == &rhs)
	    return *this;

	  m_name = rhs.m_name;
	  m_graph = rhs.m_graph;
	  m_bbIndex = rhs.m_bbIndex;
	  return *this;
	}

      ~ControlFlowGraph() {}

      const string& getName() const
	{
	  return m_name;
	}

      shared_ptr<B> createBasicBlock()
	{
	  shared_ptr<B> bb(new B(m_bbIndex));
	  ++m_bbIndex;
	  return bb;
	}
      
      shared_ptr<E> createEdge(typename E::EdgeType et)
	{
	  shared_ptr<E> e(new E(et));
	  return e;
	}
	
      void addBasicBlock(shared_ptr<B> blk)
	{
	  Vertex v = add_vertex(m_graph);
	  
	  VertexPropertyType vpType = get(vertex_llir_bb, m_graph);
	  
	  put(vpType, v, blk);
	}

      void addEdge(shared_ptr<B> src, shared_ptr<B> dst, shared_ptr<E> eP)
	{
	  unsigned int srcBlkIndex = src->getIndex();
	  
	  unsigned int dstBlkIndex = dst->getIndex();
	  
	  Vertex srcV = vertex(srcBlkIndex, m_graph);
	  
	  Vertex dstV = vertex(dstBlkIndex, m_graph);
	  
	  std::pair<Edge, bool> p = add_edge(srcV, dstV, m_graph);
	  
	  Edge edge = p.first;
	  
	  EdgePropertyType epType = get(edge_llir_e, m_graph);
	  
	  put(epType, edge, eP);
	}
      
      shared_ptr<B> getPseudoEntryBB()
	{
	  return getBasicBlock(0);
	}

      shared_ptr<B> getPseudoExitBB()
	{
	  return getBasicBlock(getNumVertices() - 1);
	}
      
      bool isPseudoEntryBB(shared_ptr<B> blk)
	{
	  if(blk->getIndex() == getPseudoEntryBB()->getIndex())
	    return true;

	  return false;
	}

      bool isPseudoExitBB(shared_ptr<B> blk)
	{
	  if(blk->getIndex() == getPseudoExitBB()->getIndex())
	    return true;

	  return false;
	}

      shared_ptr<B> getBasicBlock(unsigned int idx)
	{
	  if(idx <= getNumVertices())
	    {
	      Vertex v = vertex(idx, m_graph);
	      
	      VertexPropertyType vpType = get(vertex_llir_bb, m_graph);
	      
	      return get(vpType, v);
	    }

	  //throw
	  //return dummy
	  return shared_ptr<B>(new B(0));

	}
      
      shared_ptr<B> getBasicBlock(BasicBlockIterator iter)
	{
	  std::pair<BasicBlockIterator, BasicBlockIterator> p = vertices(m_graph);

	  if(iter != p.second)
	    {
	      Vertex v = *iter;

	      VertexPropertyType vpType = get(vertex_llir_bb, m_graph);

	      return get(vpType, v);
	    }

	  //throw
	  //return dummy
	  return shared_ptr<B>(new B(0));
	}

      unsigned int getNumVertices()
	{
	  return num_vertices(m_graph);
	}

      unsigned int getNumEdges()
	{
	  return num_edges(m_graph);
	}

      BasicBlockIterator basicBlockListBegin()
	{
	  std::pair<BasicBlockIterator, BasicBlockIterator> p = vertices(m_graph);

	  //return begin iter
	  return p.first;
	}
            
      BasicBlockIterator basicBlockListEnd()
	{
	  std::pair<BasicBlockIterator, BasicBlockIterator> p = vertices(m_graph);

	  //return end iter
	  return p.second;
	}


      PredEdgeListIter getPredListBegin (shared_ptr<B> blk)
	{
	  unsigned int blkIndex = blk->getIndex();	  

	  Vertex v = vertex(blkIndex, m_graph);

	  std::pair<PredEdgeListIter, PredEdgeListIter> p = in_edges(v, m_graph);

	  return p.first;
	}
      
      PredEdgeListIter getPredListEnd (shared_ptr<B> blk)
	{
	  unsigned int blkIndex = blk->getIndex();	  

	  Vertex v = vertex(blkIndex, m_graph);

	  std::pair<PredEdgeListIter, PredEdgeListIter> p = in_edges(v, m_graph);

	  return p.second;
	}

      shared_ptr<B> getSrcBlkAtPredEdge(PredEdgeListIter iter)
	{
	  Edge e = *iter;
	  
	  Vertex srcV = source(e, m_graph);

	  VertexPropertyType vpType = get(vertex_llir_bb, m_graph);
	      
	  return get(vpType, srcV);
	}

      SuccEdgeListIter getSuccListBegin (shared_ptr<B> blk)
	{
	  unsigned int blkIndex = blk->getIndex();	  

	  Vertex v = vertex(blkIndex, m_graph);

	  std::pair<SuccEdgeListIter, SuccEdgeListIter> p = out_edges(v, m_graph);

	  return p.first;
	}
      
      SuccEdgeListIter getSuccListEnd (shared_ptr<B> blk)
	{
	  unsigned int blkIndex = blk->getIndex();	  

	  Vertex v = vertex(blkIndex, m_graph);

	  std::pair<SuccEdgeListIter, SuccEdgeListIter> p = out_edges(v, m_graph);

	  return p.second;
	}

      shared_ptr<B> getDstBlkAtSuccEdge(SuccEdgeListIter iter)
	{
	  Edge e = *iter;
	  
	  Vertex dstV = target(e, m_graph);

	  VertexPropertyType vpType = get(vertex_llir_bb, m_graph);
	      
	  return get(vpType, dstV);
	}

    private:
      string m_name;
      Graph m_graph;
      unsigned int m_bbIndex;
    };
}

#endif
