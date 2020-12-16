#ifndef INJECT_STEP_H
#define INJECT_STEP_H

#define INJECT_STEP 0x74

#include "traversal/Traverser.h"
#include <QVariant>
#include <QVector>
#include <algorithm>

class InjectStep : public TraversalStep {
    private:
        QVector<QVariant> objects;
        
    public:
        InjectStep(QVector<QVariant>& injects) : TraversalStep(SIDE_EFFECT, INJECT_STEP) {
            std::copy(injects.begin(), injects.end(), std::back_inserter(objects));
        }

        virtual void apply(GraphTraversal* trv, TraverserSet& traversers) {
            std::for_each(objects.begin(), objects.end(), [&](QVariant obj){
                traversers.push_back(new Traverser(obj));
            });
        }
};

#endif