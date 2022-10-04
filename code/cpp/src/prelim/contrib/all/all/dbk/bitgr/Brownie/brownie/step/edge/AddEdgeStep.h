#ifndef ADD_EDGE_STEP_H
#define ADD_EDGE_STEP_H

#include "traversal/GraphTraversal.h"
#include "step/TraversalStep.h"
#include "step/InjectStep.h"
#include <QString>
#include <QVector>

#define ADD_EDGE_STEP 0x73

class AddEdgeStep: public TraversalStep
{
 QString label_;
 GraphTraversal* out_vertex_traversal_; // filled in at runtime
 GraphTraversal* in_vertex_traversal_; // filled in at runtime

public:

 AddEdgeStep(QString label_arg)
   :  TraversalStep(MAP, ADD_EDGE_STEP)
 {
  label_ = label_arg;
  out_vertex_traversal_ = nullptr;
  in_vertex_traversal_ = nullptr;

  SET_HINT
 }

 virtual QString getInfo()
 {
  QString info = "AddEdgeStep(";
  info += label_ + ")";
  return info;
 }

 GraphTraversal* get_out_traversal() { return this->out_vertex_traversal_; }
 GraphTraversal* get_in_traversal() { return this->in_vertex_traversal_; }
 void set_out_traversal(GraphTraversal* new_traversal) { this->out_vertex_traversal_ = new_traversal; }
 void set_in_traversal(GraphTraversal* new_traversal) { this->in_vertex_traversal_ = new_traversal; }
 QString get_label() { return this->label_; }

 virtual void apply(GraphTraversal* traversal, TraverserSet& traversers)
 {
  // For each traverser
  std::for_each(traversers.begin(), traversers.end(), [&, this](Traverser* trv)
  {
   // Need to check if there is enough info to add the Edge, then add it if we can.

   GraphTraversalSource* my_traversal_source = traversal->getTraversalSource();
   if(my_traversal_source == NULL) throw std::runtime_error("Cannot call this step from an anonymous traversal!");

   Vertex* from_vertex;
   Vertex* to_vertex;
   bool used_current_traverser = false;
   if(this->out_vertex_traversal_ == nullptr)
   {
    from_vertex = QVariant_cast<Vertex*>(trv->get());
    used_current_traverser = true;
   }
   else
   {
    GraphTraversal from_traversal(my_traversal_source, this->out_vertex_traversal_);
    QVector<QVariant> inj; inj.push_back(trv->get());
    InjectStep inject_step(inj);
    from_traversal.insertStep(0, &inject_step);
    from_vertex = QVariant_cast<Vertex*>(from_traversal.next());
   }

   if(this->in_vertex_traversal_ == nullptr)
   {
    if(used_current_traverser)
    {
     throw std::runtime_error("No from/to step was provided.");
    }
    to_vertex = QVariant_cast<Vertex*>(trv->get());
   }
   else
   {
    GraphTraversal to_traversal(my_traversal_source, this->in_vertex_traversal_);
    QVector<QVariant> inj; inj.push_back(trv->get());
    InjectStep inject_step(inj);
    to_traversal.insertStep(0, &inject_step);
    to_vertex = QVariant_cast<Vertex*>(to_traversal.next());
   }

   Graph* my_graph = my_traversal_source->getGraph();
   Edge* new_edge = my_graph->add_edge(from_vertex, to_vertex, label_);
   trv->replace_data(QVariant::fromValue(new_edge));
  });
 }
};

#endif