#ifndef GPU_FILTER_STEP_H
#define GPU_FILTER_STEP_H

#include "step/TraversalStep.h"
#include "CL/cl.hpp"
#include <functional>
#include <list>
#include <QVector>
#include "traversal/Traverser.h"

#define GPU_FILTER_STEP 0x11

class GPUFilterStep : public TraversalStep {
    private:
        std::function<QVector<bool>(QVector<Traverser*>*)> q_function;
    public:
        GPUFilterStep(std::function<QVector<bool>(QVector<Traverser*>*)> q);

        void apply(QVector<Traverser*>* traversers) {
            QVector<bool> results = this->q_function(traversers);
            int k = 0;
            for(auto it = traversers->begin(); it != traversers->end(); ) {
                if(results[k++]) ++it;
                else it = traversers->erase(it);
            }
        }
};

GPUFilterStep::GPUFilterStep(std::function<QVector<bool>(QVector<Traverser*>*)> q)
        : TraversalStep(FILTER, GPU_FILTER_STEP) {
            this->q_function = q;
        }

#endif