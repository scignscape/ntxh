#ifndef COALESCE_STEP_H
#define COALESCE_STEP_H

#define COALESCE_STEP 0x40

#include <QVector>

#include "step/TraversalStep.h"

class TraversalStep;
class GraphTraversal;

class CoalesceStep: public TraversalStep
{
 QVector<GraphTraversal*> traversals_;

public:

 CoalesceStep(QVector<GraphTraversal*>& traversals_);
 QVector<GraphTraversal*>& get_traversals();
 virtual void apply(GraphTraversal* parent_traversal, TraverserSet& traversers);

};

#include "traversal/GraphTraversal.h"
#include "step/TraversalStep.h"
#include "step/InjectStep.h"

CoalesceStep::CoalesceStep(QVector<GraphTraversal*>& traversals_)
 : TraversalStep(MAP, COALESCE_STEP)
{
 for(auto it = traversals_.begin(); it != traversals_.end(); ++it) this->traversals_.push_back(*it);
}

QVector<GraphTraversal*>& CoalesceStep::get_traversals()
{
 return this->traversals_;
}

void CoalesceStep::apply(GraphTraversal* parent_traversal, TraverserSet& traversers)
{
 size_t num_traversers = traversers.size();
 QVector<Traverser*> new_traversers;

 for(auto it = this->traversals_.begin(); it != this->traversals_.end(); ++it)
 {
  GraphTraversal* current_coalesce_traversal = *it;

  QVector<QVariant> objects(num_traversers);
  for(size_t k = 0; k < num_traversers; ++k) objects[k] = traversers[k]->get();

  GraphTraversal executing_traversal(parent_traversal->getTraversalSource(), current_coalesce_traversal);
  InjectStep inject_step(objects);
  executing_traversal.insertStep(0, &inject_step);

  executing_traversal.forEachRemaining([&](QVariant& obj)
  {
   new_traversers.push_back(new BrownTraverser(obj));
  });

  if(new_traversers.size() > 0) break;
 }

 traversers.swap(new_traversers);

 std::for_each(new_traversers.begin(), new_traversers.end(), [](Traverser* trv)
 {
  delete trv;
 });
}

#endif

