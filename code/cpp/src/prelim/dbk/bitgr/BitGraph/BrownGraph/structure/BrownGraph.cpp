
#include "BrownGraph.h"


Edge* BrownGraph::resolve_edge(caon_ptr<Edge> pv)
{
 if(pv.is_fixnum())
 {
  return resolve_edge(pv.get_fixnum());
 }
 if(pv.is_array())
 {
  // // TODO
  return nullptr;
 }
 return pv.raw_pointer();

}

Edge* BrownGraph::resolve_edge(n8 key)
{
 Q_UNUSED(key)
 return nullptr;
}


Vertex* BrownGraph::resolve_vertex(caon_ptr<Vertex> pv)
{
 if(pv.is_fixnum())
 {
  return resolve_vertex(pv.get_fixnum());
 }
 if(pv.is_array())
 {
  // // TODO
  return nullptr;
 }
 return pv.raw_pointer();
}

Vertex* BrownGraph::resolve_vertex(n8 key)
{
 Q_UNUSED(key)
 return nullptr;
}

void BrownGraph::all_edges(QVector<Edge*>& result)
{
 for(caon_ptr<Edge> pe : edge_vector_)
 {
  if(Edge* e = resolve_edge(pe))
    result.push_back(e);
 }
}

void BrownGraph::all_vertices(QVector<Vertex*>& result)
{
 for(caon_ptr<Vertex> pv : vertex_vector_)
 {
  if(Vertex* v = resolve_vertex(pv))
    result.push_back(v);
 }
}


QVector<Edge*> BrownGraph::all_edges()
{
 QVector<Edge*> result;
 all_edges(result);
 return result;
}

QVector<Vertex*> BrownGraph::all_vertices()
{
 QVector<Vertex*> result;
 all_vertices(result);
 return result;
}

