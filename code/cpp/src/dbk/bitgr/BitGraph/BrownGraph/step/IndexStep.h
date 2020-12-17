#ifndef INDEX_STEP_H
#define INDEX_STEP_H

#define INDEX_STEP 0x12

#include <QVariant>
#include "step/TraversalStep.h"

class IndexStep : public TraversalStep {
    private:
        QString key;
        QVariant value;
    public:
        IndexStep(QString key, QVariant value)
        : TraversalStep(MAP, INDEX_STEP) {
            this->key = key;
            this->value = value;
        }

        QString get_key() {return key;}
        QVariant get_value() {return value;}

        virtual void apply(GraphTraversal* trv, TraverserSet& traversers) {
            Index* idx = dynamic_cast<BrownGraph*>(trv->getGraph())->get_index(this->key);
	        std::unordered_set<Element*> elements = idx->get_elements(this->value);
	        std::for_each(elements.begin(), elements.end(), [&, this](Element* e) {
          Traverser* trv = new Traverser(QVariant::fromValue((Vertex*)e)); // TODO this won't handle edges
		        traversers.push_back(trv);
	        });
        }
};

#endif
