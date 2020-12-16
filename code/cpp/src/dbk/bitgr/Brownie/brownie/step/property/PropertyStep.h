#ifndef PROPERTY_STEP_H
#define PROPERTY_STEP_H

#include "step/TraversalStep.h"
#include "structure/Property.h"
#include <QVector>
#include <QString>
#include <QVariant>

#define PROPERTY_STEP 0x67

enum PropertyStepType { VALUE, PROPERTY };

class PropertyStep: public TraversalStep {
    private:
        QVector<QString> keys; //duplicates are allowed, per api
        PropertyStepType ps_type;

    public:
        PropertyStep(PropertyStepType type, QVector<QString> property_keys)
        : TraversalStep(MAP, PROPERTY_STEP) {
            this->keys = property_keys;
            this->ps_type = type;
        }

        QVector<QString>& get_keys() { return keys; }

        PropertyStepType get_type() { return ps_type; }

        virtual void apply(GraphTraversal* traversal, TraverserSet& traversers) {
            QVector<Traverser*> new_traversers;
            bool get_value = this->ps_type == VALUE;

            for(Traverser* trv : traversers) {
                for(QString key : keys) {
                    QVariant x = trv->get();
                    /*
                    if(x.type() != typeid(Vertex*)) {
                        throw std::runtime_error("Error: Traverser does not appear to contain a Vertex.");
                    }
                    */

                    Vertex* v = QVariant_cast<Vertex*>(x);
                    VertexProperty<QVariant>* p = v->property(key); //TODO multiproperties?
                    if(p == nullptr) new_traversers.push_back(new Traverser(QVariant()));
                    else if(get_value && !p->value().isNull()) new_traversers.push_back(new Traverser(p->value()));
                    else if(!get_value) new_traversers.push_back(new Traverser(QVariant::fromValue(p)));
                }
            }

            traversers.swap(new_traversers);
            std::for_each(new_traversers.begin(), new_traversers.end(), [](Traverser* trav){delete trav;});
        }
};

#endif
