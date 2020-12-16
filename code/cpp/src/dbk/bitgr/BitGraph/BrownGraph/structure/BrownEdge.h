#ifndef BROWN_EDGE_H
#define BROWN_EDGE_H

#include "structure/Edge.h"
#include <inttypes.h>
#include <QVariant>

class BrownEdge : public Edge
{

private:

 // The Graph this Edge belongs to
 CPUGraph* graph_;

 // The unique id of this BrownEdge
 uint64_t edge_id_;

 // The out-vertex of this BrownEdge
 Vertex* out_vertex_;

 // The in-vertex of this BrownEdge
 Vertex* in_vertex_;

 // The label of this BrownEdge
 QString edge_label_;

public:
 /*
                        Construct a new BrownEdge with the given in and
                        out vertices and the given label.  Per TP3
                        standard, all Edges must have a label.
                */
 BrownEdge(CPUGraph* graph, uint64_t id, Vertex* out, Vertex* in, QString label)
 {
  this->graph_ = graph;
  this->edge_id_ = id;
  this->out_vertex_ = out;
  this->in_vertex_ = in;
  this->edge_label_ = label;
 }

 /*
                        Get a pointer to the id of the given Edge.
                */
 virtual QVariant id() { return QVariant::fromValue(this->edge_id_); }
 virtual Graph* getGraph() { return static_cast<Graph*>(this->graph_); }
 virtual QString label() { return this->edge_label_; }
 virtual Vertex* outV() { return this->out_vertex_; }
 virtual Vertex* inV() { return this->in_vertex_; }
};

#endif
