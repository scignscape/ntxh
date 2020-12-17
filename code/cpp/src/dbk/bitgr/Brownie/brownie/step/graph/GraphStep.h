#ifndef GRAPH_STEP_H
#define GRAPH_STEP_H
#include <QString>
#include <QVector>
#include <QVariant>
#include "step/TraversalStep.h"
#include "traversal/Traverser.h"

#define GRAPH_STEP 0x81

#define SET_HINT  hint = this->getInfo();


enum GraphStepType {VERTEX, EDGE};

class GraphStep : public TraversalStep
{

protected:

 GraphStepType gs_type_;
 QVector<QVariant> element_ids_;

public:

 QString hint;

 GraphStep(GraphStepType gsType_arg, QVector<QVariant> eids)
  : TraversalStep(MAP, GRAPH_STEP)
 {
  this->gs_type_ = gsType_arg;

  for(QVariant id_ctr : eids)
    this->element_ids_.push_back(id_ctr);

  SET_HINT
 }

 virtual QString	getInfo()
 {
  QString info = "GraphStep(";
  info += this->gs_type_ == VERTEX ? "VERTEX" : "EDGE";
  info = info + ", " + (element_ids_.size() > 0 ? "{...}" : "{}");
  return info + ")";
 }

 GraphStepType getType()
 {
  return this->gs_type_;
 }

 QVector<QVariant>& get_element_ids()
 {
  return this->element_ids_;
 }

 virtual void apply(GraphTraversal* trv, TraverserSet& traversers)
 {
  throw std::runtime_error("Unsupported operation!");
 }

};

#endif
