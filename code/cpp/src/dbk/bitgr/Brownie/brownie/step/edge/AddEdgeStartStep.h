#ifndef ADD_EDGE_START_STEP_H
#define ADD_EDGE_START_STEP_H

#define ADD_EDGE_START_STEP 0x72

#include <QString>
#include <QVector>

#include "step/TraversalStep.h"

class GraphTraversalSource;
class GraphTraversal;
class Traverser;
class TraversalStep;
typedef QVector<Traverser*> TraverserSet;

class AddEdgeStartStep: public TraversalStep
{
  QString label_;
  GraphTraversal* out_vertex_traversal_; // filled in at runtime
  GraphTraversal* in_vertex_traversal_; // filled in at runtime

public:

		AddEdgeStartStep(QString label_arg);
		
  virtual QString getInfo()
  {
			QString info = "AddEdgeStartStep(";
   info += label_ + ")";
			return info;
		}


		GraphTraversal* get_out_traversal();
		GraphTraversal* get_in_traversal();
		void set_out_traversal(GraphTraversal* new_traversal);
		void set_in_traversal(GraphTraversal* new_traversal);

  QString get_label() { return this->label_; }

		virtual void apply(GraphTraversal* trv, TraverserSet& traversers);
};

#include "traversal/GraphTraversal.h"
#include "step/TraversalStep.h"
#include "traversal/Traverser.h"
#include "structure/Graph.h"
#include "structure/Vertex.h"
#include "structure/Edge.h"

AddEdgeStartStep::AddEdgeStartStep(QString label_arg)
  :  TraversalStep(MAP, ADD_EDGE_START_STEP)
{
 this->label_ = label_arg;
 this->out_vertex_traversal_ = nullptr;
 this->in_vertex_traversal_ = nullptr;

 SET_HINT
}

GraphTraversal* AddEdgeStartStep::get_out_traversal() { return this->out_vertex_traversal_; }
GraphTraversal* AddEdgeStartStep::get_in_traversal() { return this->in_vertex_traversal_; }
void AddEdgeStartStep::set_out_traversal(GraphTraversal* new_traversal) { this->out_vertex_traversal_ = new_traversal; }
void AddEdgeStartStep::set_in_traversal(GraphTraversal* new_traversal) { this->in_vertex_traversal_ = new_traversal; }

void AddEdgeStartStep::apply(GraphTraversal* trv, TraverserSet& traversers) {
	// Need to check if there is enough info to add the Edge, then add it
	// if we can.
	// from() and to() are both always required here.
	GraphTraversalSource* my_traversal_source = trv->getTraversalSource();
	if(my_traversal_source == NULL) throw std::runtime_error("Cannot call this step from an anonymous traversal!\n");

 GraphTraversal from_traversal(my_traversal_source, this->out_vertex_traversal_);
 GraphTraversal to_traversal(my_traversal_source, this->in_vertex_traversal_);

	Vertex* from_vertex = QVariant_cast<Vertex*>(from_traversal.next());
	Vertex* to_vertex = QVariant_cast<Vertex*>(to_traversal.next());

 Edge* new_edge = trv->getGraph()->add_edge(from_vertex, to_vertex, label_);
 traversers.push_back(new Traverser(QVariant::fromValue(new_edge)));
}

#endif
