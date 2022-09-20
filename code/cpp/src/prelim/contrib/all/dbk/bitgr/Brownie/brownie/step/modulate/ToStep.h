#ifndef TO_STEP_H
#define TO_STEP_H

#include "step/TraversalStep.h"
#include <QString>

class GraphTraversal;
class Vertex;

#define TO_STEP 0x91

class ToStep : public TraversalStep
{
 GraphTraversal* to_traversal_;

public:
 ToStep(QString side_effect_label);

 ToStep(Vertex* to_vertex);

 ToStep(GraphTraversal* to_vertex_traversal)
   :  TraversalStep(MODULATOR, TO_STEP)
 {
  to_traversal_ = to_vertex_traversal;
 }

 GraphTraversal* getTraversal()
 {
  return to_traversal_;
 }

 virtual QString getInfo();
};

#include "traversal/GraphTraversal.h"

ToStep::ToStep(QString side_effect_label)
  : TraversalStep(MODULATOR, TO_STEP)
{
 to_traversal_ = (GraphTraversal*)__->select(side_effect_label);

 hint = "ToStep";
}

ToStep::ToStep(Vertex* to_vertex)
 : TraversalStep(MODULATOR, TO_STEP)
{
 to_traversal_ = __->V(to_vertex);

 hint = "ToStep";
}

QString ToStep::getInfo()
{
 return "ToStep {\n" + this->to_traversal_->explain() + "\n}";
}

#endif
