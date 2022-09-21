#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>

class Edge;
class Vertex;
class GraphTraversalSource;

class Graph
{
public:

 Graph(){}

	virtual GraphTraversalSource* traversal() = 0;
 virtual void* vertices() = 0;
 virtual void* edges() = 0;
	virtual Vertex* add_vertex(QString label) = 0;
	virtual Vertex* add_vertex() = 0;
	virtual Edge* add_edge(Vertex* from_vertex, Vertex* to_vertex, QString label) = 0;
};

#include "structure/Edge.h"
#include "structure/Vertex.h"
#include "traversal/GraphTraversalSource.h"

#endif
