#ifndef ADD_VERTEX_START_STEP_H
#define ADD_VERTEX_START_STEP_H

#include "step/TraversalStep.h"
#include "traversal/Traverser.h"
#include "traversal/GraphTraversal.h"
#include <QString>
#include <QVector>

#define ADD_VERTEX_START_STEP 0x70

class AddVertexStartStep: public TraversalStep
{
private:

 QString label_;

 bool has_label()
 {
  return !label_.isNull();
 }

public:
 AddVertexStartStep(QString label_arg)
   : TraversalStep(MAP, ADD_VERTEX_START_STEP)
 {
  label_ = label_arg;
  SET_HINT
  //has_label = true;
 }

 AddVertexStartStep()
   : TraversalStep(MAP, ADD_VERTEX_START_STEP)
 {
  //has_label = false;
 }

 virtual QString getInfo()
 {
  QString info = "AddVertexStartStep(";
  info += label_;// has_label ? label : "";
  info += ")";
  return info;
 }

 virtual void apply(GraphTraversal* trv, TraverserSet& traversers)
 {
  Vertex* v = this->has_label()
    ? trv->getGraph()->add_vertex(this->label_)
    : trv->getGraph()->add_vertex();
  traversers.push_back(new BrownTraverser(QVariant::fromValue(v)));
 }
};

#endif
