#ifndef FROM_STEP_H
#define FROM_STEP_H

class GraphTraversal;
class TraversalStep;
class Vertex;

#include <QString>

#define FROM_STEP 0x90

class FromStep : public TraversalStep {
	private:
		GraphTraversal* from_traversal;
	public:
		FromStep(QString side_effect_label);

		FromStep(Vertex* to_vertex);

		FromStep(GraphTraversal* from_vertex_traversal);

		GraphTraversal* getTraversal();

		virtual QString getInfo();
};

#include "traversal/GraphTraversal.h"
#include "step/TraversalStep.h"

FromStep::FromStep(GraphTraversal* from_vertex_traversal)
: TraversalStep(MODULATOR, FROM_STEP) {
	from_traversal = from_vertex_traversal;
}

FromStep::FromStep(QString side_effect_label)
: TraversalStep(MODULATOR, FROM_STEP) {
	this->from_traversal = (GraphTraversal*)__->select(side_effect_label);
}

FromStep::FromStep(Vertex* to_vertex) 
: TraversalStep(MODULATOR, FROM_STEP) {
	this->from_traversal = __->V(to_vertex);
}

GraphTraversal* FromStep::getTraversal() {
	return this->from_traversal;
}

QString FromStep::getInfo() {
	return "FromStep {\n" + this->from_traversal->explain() + "\n}";
}

#endif