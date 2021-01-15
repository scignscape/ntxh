#ifndef CPU_GRAPH_TRAVERSAL_SOURCE_H
#define CPU_GRAPH_TRAVERSAL_SOURCE_H

#include "traversal/GraphTraversalSource.h"
#include "traversal/CPUGraphTraversal.h"
#include "step/graph/GraphStep.h"
#include "step/vertex/AddVertexStartStep.h"
#include "step/edge/AddEdgeStartStep.h"

#include "step/BrownGraphStep.h"

class BrownGraph;
class GPUGraphTraversalSource;

class CPUGraphTraversalSource : public GraphTraversalSource
{
public:

 CPUGraphTraversalSource(BrownGraph* gr);

 GPUGraphTraversalSource* withGPU();

 GraphTraversal* V()
 {
  GraphTraversal* trv = new CPUGraphTraversal(this);
  trv->appendStep(new GraphStep(VERTEX, {}));

  //new BrownGraphStep(true, VERTEX, {})); //new GraphStep(VERTEX, {}));
  return trv;
 }

 GraphTraversal* V(Vertex* v)
 {
  GraphTraversal* trv = new CPUGraphTraversal(this);

  trv->appendStep(new GraphStep(VERTEX, {v->id()}));

//  trv->appendStep(new BrownGraphStep(true, VERTEX, {v->id()}));
  return trv;
 }

 /*
   Although the API allows for making this a special call,
   CPUGraph treats this as shorthand for g.V().outE()
  */
 GraphTraversal* E()
 {
  return (GraphTraversal*)this->V()->outE();
 }

 GraphTraversal* addV()
 {
  GraphTraversal* trv = new CPUGraphTraversal(this);
  trv->appendStep(new AddVertexStartStep());
  return trv;
 }

 GraphTraversal* addV(QString label)
 {
  GraphTraversal* trv = new CPUGraphTraversal(this);
  trv->appendStep(new AddVertexStartStep(label));
  return trv;
 }

 GraphTraversal* addE(QString label)
 {
  GraphTraversal* trv = new CPUGraphTraversal(this);
  trv->appendStep(new AddEdgeStartStep(label));
  return trv;
 }
};

#include "structure/BrownGraph.h"
#include "strategy/TraversalStrategy.h"
#include "strategy/BrownGraphStrategy.h"
//#include "GPUGraphTraversalSource.h"

CPUGraphTraversalSource::CPUGraphTraversalSource(BrownGraph* gr)
 : GraphTraversalSource(gr)
{
 this->strategies_.push_back([this](QVector<TraversalStep*>& t)
 {
  browngraph_strategy(static_cast<BrownGraph*>(this->getGraph()), t);
 });
}

/*
GPUGraphTraversalSource* BrownGraphTraversalSource::withGPU() {
 return new GPUGraphTraversalSource(static_cast<BrownGraph*>(this->getGraph()));
}
*/

#endif
