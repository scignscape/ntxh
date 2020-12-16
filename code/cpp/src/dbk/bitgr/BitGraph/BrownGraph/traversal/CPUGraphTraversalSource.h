#ifndef CPU_GRAPH_TRAVERSAL_SOURCE_H
#define CPU_GRAPH_TRAVERSAL_SOURCE_H

#include "traversal/GraphTraversalSource.h"
#include "traversal/CPUGraphTraversal.h"
#include "step/graph/GraphStep.h"
#include "step/vertex/AddVertexStartStep.h"
#include "step/edge/AddEdgeStartStep.h"

class CPUGraph;
class GPUGraphTraversalSource;

class CPUGraphTraversalSource : public GraphTraversalSource {
	public:
		CPUGraphTraversalSource(CPUGraph* gr);

		GPUGraphTraversalSource* withGPU();

		GraphTraversal* V() {
			GraphTraversal* trv = new CPUGraphTraversal(this);
			trv->appendStep(new GraphStep(VERTEX, {}));
			return trv;
		}

		GraphTraversal* V(Vertex* v) {
			GraphTraversal* trv = new CPUGraphTraversal(this);
			trv->appendStep(new GraphStep(VERTEX, {v->id()}));
			return trv;
		}

		/*
			Although the API allows for making this a special call,
			CPUGraph treats this as shorthand for g.V().outE()
		*/
		GraphTraversal* E() {
			return (GraphTraversal*)this->V()->outE();
		}
		
		GraphTraversal* addV() {
			GraphTraversal* trv = new CPUGraphTraversal(this);
			trv->appendStep(new AddVertexStartStep());
			return trv;
		}
		
		GraphTraversal* addV(QString label) {
			GraphTraversal* trv = new CPUGraphTraversal(this);
			trv->appendStep(new AddVertexStartStep(label));
			return trv;
		}

		GraphTraversal* addE(QString label) {
			GraphTraversal* trv = new CPUGraphTraversal(this);
			trv->appendStep(new AddEdgeStartStep(label));
			return trv;
		}
};

#include "structure/CPUGraph.h"
#include "strategy/TraversalStrategy.h"
#include "strategy/BrownGraphStrategy.h"
//#include "GPUGraphTraversalSource.h"

CPUGraphTraversalSource::CPUGraphTraversalSource(CPUGraph* gr)
  : GraphTraversalSource(gr)
{
 this->strategies_.push_back([this](QVector<TraversalStep*>& t) {
   browngraph_strategy(static_cast<CPUGraph*>(this->getGraph()), t);
 });
}

/*
GPUGraphTraversalSource* CPUGraphTraversalSource::withGPU() {
	return new GPUGraphTraversalSource(static_cast<CPUGraph*>(this->getGraph()));
}
*/

#endif
