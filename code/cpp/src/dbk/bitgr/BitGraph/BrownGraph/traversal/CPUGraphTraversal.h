#ifndef CPU_GRAPH_TRAVERSAL_H
#define CPU_GRAPH_TRAVERSAL_H

#include <algorithm>
#include <iostream>
#include <QVariant>

#include "traversal/GraphTraversal.h"
#include "traversal/GraphTraversalSource.h"

class CPUGraphTraversal : public GraphTraversal
{

public:
 CPUGraphTraversal(GraphTraversalSource* src);

};

#include "structure/BrownGraph.h"

CPUGraphTraversal::CPUGraphTraversal(GraphTraversalSource* src)
	: GraphTraversal(src) {}

#endif
