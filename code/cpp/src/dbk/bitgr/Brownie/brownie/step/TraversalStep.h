#ifndef TRAVERSAL_STEP_H
#define TRAVERSAL_STEP_H

#include <QVector>
#include <QString>

#include "traversal/GraphTraversal.h"

class Traverser;

enum TraversalStepType {MAP, FILTER, BARRIER, MODULATOR, SIDE_EFFECT};

class TraversalStep
{
private:

 TraversalStepType type_;

 unsigned int uid_;
 bool is_barrier_;

public:

 QString hint;

 unsigned int uid(){ return uid_; }
 bool is_barrier(){ return is_barrier_; }

 TraversalStep(TraversalStepType tsType, unsigned int id);

 TraversalStep(bool is_barrier, TraversalStepType tsType, unsigned int id);



 virtual QString getInfo();
	virtual void apply(GraphTraversal* trv, QVector<Traverser*>& traversers);

};

#include "traversal/Traverser.h"

#define SET_HINT  hint = this->getInfo();


TraversalStep::TraversalStep(bool is_barrier, TraversalStepType tsType, unsigned int id)
{
  this->type_ = tsType;
  this->uid_ = id;
  this->is_barrier_ = is_barrier;
}

TraversalStep::TraversalStep(TraversalStepType tsType, unsigned int id)
  : TraversalStep(false, tsType, id)
{
}

QString TraversalStep::getInfo()
{
	return "UnknownTraversalStep{}";
}

void TraversalStep::apply(GraphTraversal* trv, TraverserSet& traversers)
{

}

#endif
