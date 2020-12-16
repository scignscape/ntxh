#ifndef ADD_PROPERTY_STEP_H
#define ADD_PROPERTY_STEP_H

#define ADD_PROPERTY_STEP 0x75

#include "step/TraversalStep.h"
#include "step/InjectStep.h"
#include "structure/Vertex.h"

#include <QVariant>
#include <QDebug>


// Edge properties currently not supported.
class AddPropertyStep : public TraversalStep {
	private:
		Cardinality cardinality;
		QString key;
		QVariant value;
	public:
		AddPropertyStep(QString property_key, QVariant& value)
		: TraversalStep(MAP, ADD_PROPERTY_STEP) {
			this->cardinality = SINGLE;
			this->key = QString(property_key);
			this->value = QVariant(value);
		}

		AddPropertyStep(Cardinality card, QString property_key, QVariant& value)
		: TraversalStep(MAP, ADD_PROPERTY_STEP) {
			this->cardinality = card;
			this->key = QString(property_key);
			this->value = QVariant(value);
		}

		QString get_key() { return this->key; }

		QVariant get_value() { return this->value; };

		inline Element* get_element(QVariant& e) {
//			const std::type_info& t = e.type();
//			if(t == typeid(Vertex*)) return static_cast<Element*>(QVariant_cast<Vertex*>(e));
//			else if(t == typeid(Edge*)) return static_cast<Element*>(QVariant_cast<Edge*>(e));
//			else throw std::runtime_error("Add Property Step Error: Not an element!");
		}
		
		virtual void apply(GraphTraversal* current_traversal, TraverserSet& traversers) {

   QVariant qvar = this->value;
   QString tn = QString::fromLatin1( qvar.typeName() );
   qDebug() << "TN = " << tn;

   QVariant qvar1 = QVariant::fromValue(new GraphTraversal);
   QString tn1 = QString::fromLatin1( qvar1.typeName() );
   qDebug() << "TN1 = " << tn1;

   if(tn == "GraphTraversal*")
   //if(false)//this->value.type() == typeid(GraphTraversal*))
   {
				GraphTraversal* ap_anonymous_trv = QVariant_cast<GraphTraversal*>(value);
				
				#pragma omp for
				//std::for_each(traversers.begin(), traversers.end(), [&](Traverser* trv) {
				for(int k = 0; k < traversers.size(); ++k) {
					Traverser* trv = traversers[k];
					//Element* e = get_element(trv->get());
					Vertex* e = QVariant_cast<Vertex*>(trv->get());
					GraphTraversal new_trv(current_traversal->getTraversalSource(), ap_anonymous_trv);
					
					// Execute traversal
					QVector<QVariant> inj; inj.push_back(trv->get());
					InjectStep inject_step(inj);
      //? new_trv.insertStep(0, &inject_step);
					QVariant prop_value = new_trv.next();

					// Store the property; TODO deal w/ edges
					e->property(this->cardinality, this->key, prop_value);
					//std::cout << "property stored!\n";
				}
				//});
			} 
			else {
				// Store the propety; TODO deal w/ edges
				std::for_each(traversers.begin(), traversers.end(), [&](Traverser* trv){
					Vertex* e = QVariant_cast<Vertex*>(trv->get());
					e->property(this->cardinality, this->key, this->value);	
				});
				//std::cout << "property stored!\n";
			}

			// Traversers aren't modified in this step.
		}
};

#endif
