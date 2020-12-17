#ifndef BIT_VERTEX_H
#define BIT_VERTEX_H

#define VERTEX_MAGIC_NUMBER 15134994420398101408ull

#include <inttypes.h>
#include <mutex>
#include <QVector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <QVariant>

#include "structure/Vertex.h"
#include "structure/Direction.h"

#include "structure/BrownEdge.h"
#include "structure/BrownGraph.h"

/*
Vertex type that uses a uint64_t for identifiers,
allowing for up to 2^64 = 10^19 vertices.
*/
class BrownVertex : public Vertex
{

public:
 // Magic number used for casting checks
 uint64_t magic;

private:
 // The id of this BrownVertex
 uint64_t vertex_id_;

 // The Graph this BrownVertex belongs to
 BrownGraph* graph_;

 // The outgoing edges
 QVector<BrownEdge*> edges_out_;

 // The incoming edges
 QVector<BrownEdge*> edges_in_;

 // The label, if it has one
 QString vertex_label_;

 // Boolean whether or not it has a label
 bool has_label()
 {
  return !vertex_label_.isNull();
 }

 // The properties
 std::unordered_map<QString, VertexProperty<QVariant>*> my_properties_;

 // Mutex that prevents concurrent edge addition
 //std::mutex add_edge_mutex;

 // Mutex that prevents concurrent property addition
 //std::mutex add_prop_mutex;

public:
 BrownVertex(BrownGraph* graph, uint64_t vid) {
  this->graph_ = graph;
  this->vertex_id_ = vid;
  //this->has_label = false;
  this->magic = VERTEX_MAGIC_NUMBER;
 }

 BrownVertex(BrownGraph* graph, uint64_t vid, QString v_label) {
  this->graph_ = graph;
  this->vertex_id_ = vid;
  //this->has_label = true;
  this->vertex_label_ = v_label;
  this->magic = VERTEX_MAGIC_NUMBER;
 }

 /*
                        Return the Graph this Vertex belongs to.
                */
 virtual Graph* getGraph() {
  return static_cast<Graph*>(this->graph_);
 }

 /*
                        Get the unique id of the Vertex.
                        In BrownGraph this is indirectly
                        derived from its initial position
                        in the list of Vertices.
                */
 virtual QVariant id() {
   return QVariant::fromValue(vertex_id_);
 }

 /*
                        Make sure to return NULL if there is
                        no label for the Vertex
                */
 virtual QString label() {
  return vertex_label_; //has_label ? QString(vertex_label_) : NULL;
 }

 /*
                        Nifty helper method that returns
                        whether or not this Vertex has a label.
                */
 virtual bool hasLabel() {
  return has_label();
 }

 /*
                        Add an edge to this Vertex in the
                        given direction.  Checks to make
                        sure the Edge makes sense.
                */
 void addEdge(BrownEdge* new_edge, Direction dir) {
  //add_edge_mutex.lock();

  if(dir == OUT && new_edge->outV() == this)
    edges_out_.push_back(new_edge);
  else if(dir == IN && new_edge->inV() == this)
    edges_in_.push_back(new_edge);

  //add_edge_mutex.unlock();
 }

 /*
                        Get edges in a particular direction.
                */
 virtual QVector<Edge*> edges(Direction dir)
 {
  switch(dir)
  {
  case OUT:
   {
    return QVector<Edge*>{this->edges_out_.begin(), this->edges_out_.end()};
   }
  case IN:
   {
    return QVector<Edge*>{this->edges_in_.begin(), this->edges_in_.end()};
   }
  case BOTH:
   {
    QVector<Edge*> both_edges;
    std::transform(this->edges_in_.begin(),
      this->edges_in_.end(), std::back_inserter(both_edges),
      [](BrownEdge* obj){ return (Edge*) obj; });

    std::transform(this->edges_out_.begin(),
      this->edges_out_.end(), std::back_inserter(both_edges),
      [](BrownEdge* obj){ return (Edge*) obj; });

    return both_edges;
   }
  default:
    break;
   // should never occur
  }
 }

 /*
                        Get the property with the given key.
                */
 virtual VertexProperty<QVariant>* property(QString key)
 {
  auto v = this->my_properties_.find(key);
  if(v == my_properties_.end()) return nullptr;
  return v->second;
 }

 /*
                        Set the property with the given key to the given value.
                */
 virtual VertexProperty<QVariant>* property(Cardinality card, QString key, QVariant& value) {
  auto old_prop = this->my_properties_.find(key);

  // Update the indexes if necessary.
  if(this->graph_->is_indexed(key))
  {
   if(card == SINGLE && old_prop != this->my_properties_.end())
   {
    this->graph_->clear_index(this, key, old_prop->second->value());
   }
   graph_->update_index(this, key, value);
  }

  if(card == SINGLE)
  {
   this->my_properties_[key] = new VertexProperty<QVariant>(SINGLE, key, {value});
  }
  else if(card == SET || card == LIST)
  { //TODO this is incorrect
   if(old_prop != this->my_properties_.end())
   {
    QVector<QVariant> vals = old_prop->second->values();
    vals.push_back(value);
    this->my_properties_[key] = new VertexProperty<QVariant>(card, key, vals);
   }
   else {
    this->my_properties_[key] = new VertexProperty<QVariant>(card, key, {value});
   }
  }
  else {
   throw std::runtime_error("Illegal cardinality!");
  }

  return this->my_properties_[key];
 }

 /*
                        Set the property with the given key to the given value.
                */
 virtual VertexProperty<QVariant>* property(QString key, QVariant& value)
 {
  return this->property(SINGLE, key, value);
 }
};

#endif
