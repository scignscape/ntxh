#ifndef GRAPH_STEP_H
#define GRAPH_STEP_H
#include <QString>
#include <QVector>
#include <QVariant>
#include "step/TraversalStep.h"
#include "traversal/Traverser.h"

#define GRAPH_STEP 0x81

enum GraphStepType {VERTEX, EDGE};

class GraphStep : public TraversalStep {
	protected:
		GraphStepType gs_type;
  QVector<QVariant> element_ids;
	public:
  GraphStep(GraphStepType gsType_arg, QVector<QVariant> eids)
		: TraversalStep(MAP, GRAPH_STEP) {
			this->gs_type = gsType_arg;
   for(QVariant id_ctr : eids)
     this->element_ids.push_back(id_ctr);
		}

		virtual QString	getInfo() {
			QString info = "GraphStep(";
			info += this->gs_type == VERTEX ? "VERTEX" : "EDGE";
			info = info + ", " + (element_ids.size() > 0 ? "{...}" : "{}");
			return info + ")";
		}

		GraphStepType getType() { return this->gs_type; }

  QVector<QVariant>& get_element_ids() { return this->element_ids; }

		virtual void apply(GraphTraversal* trv, TraverserSet& traversers) {
			throw std::runtime_error("Unsupported operation!");
		}
};

#endif
