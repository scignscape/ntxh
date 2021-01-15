#ifndef GRAPH_TRAVERSAL_SOURCE_H
#define GRAPH_TRAVERSAL_SOURCE_H

#include <QString>
#include <QVector>
#include <functional>

class Graph;
class Vertex;
class Edge;
class TraversalStep;
class GraphTraversal;

typedef std::function<void(QVector<TraversalStep*>&)> TraversalStrategy;

class GraphTraversalSource
{

private:

 Graph* graph_;

protected:
 QVector<TraversalStrategy> strategies_;

public:

 GraphTraversalSource(Graph* gr);

 Graph* getGraph();

 GraphTraversalSource* withStrategy(TraversalStrategy strategy);

 QVector<TraversalStrategy>& getStrategies();

 virtual GraphTraversal* V() = 0;
 virtual GraphTraversal* V(Vertex* v) = 0;
 virtual GraphTraversal* E() = 0;
 virtual GraphTraversal* addV() = 0;
 virtual GraphTraversal* addV(QString label) = 0;
 virtual GraphTraversal* addE(QString label) = 0;
};

#include "traversal/GraphTraversal.h"
#include "strategy/TraversalStrategy.h"
#include "structure/Graph.h"
#include "structure/Vertex.h"
#include "structure/Edge.h"
#include "strategy/AddEdgeStepCompletionStrategy.h"

GraphTraversalSource::GraphTraversalSource(Graph* gr)
{
 graph_ = gr;
 this->withStrategy(add_edge_step_completion_strategy);
}

GraphTraversalSource* GraphTraversalSource::withStrategy(TraversalStrategy strategy)
{
 this->strategies_.push_back(strategy);
 return this;
}

QVector<TraversalStrategy>& GraphTraversalSource::getStrategies()
{
 return this->strategies_;
}

Graph* GraphTraversalSource::getGraph() {
 return graph_;
}

#endif
