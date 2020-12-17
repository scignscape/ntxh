#ifndef INJECT_STEP_H
#define INJECT_STEP_H

#define INJECT_STEP 0x74

#include "traversal/BrownTraverser.h"

#include <QVariant>
#include <QVector>
#include <algorithm>

class InjectStep : public TraversalStep
{
 QVector<QVariant> objects_;

public:
 InjectStep(QVector<QVariant>& injects) : TraversalStep(SIDE_EFFECT, INJECT_STEP)
 {
  std::copy(injects.begin(), injects.end(), std::back_inserter(objects_));
 }

 virtual void apply(GraphTraversal* trv, TraverserSet& traversers)
 {
  std::for_each(objects_.begin(), objects_.end(), [&](QVariant obj)
  {
   traversers.push_back(new BrownTraverser(obj));
  });
 }
};

#endif
