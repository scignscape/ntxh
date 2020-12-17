#ifndef QMETAS__H
#define QMETAS__H

#include <QVariant>

#include <QMetaType>

#include "relae-graph/relae-caon-ptr.h"

template<typename T>
class VertexProperty;

class Vertex;
class Edge;
class GraphTraversal;



Q_DECLARE_METATYPE(GraphTraversal*)
Q_DECLARE_METATYPE(Edge*)
Q_DECLARE_METATYPE(Vertex*)
Q_DECLARE_METATYPE(caon_ptr<Vertex>)
Q_DECLARE_METATYPE(caon_ptr<Edge>)
Q_DECLARE_METATYPE(VertexProperty<QVariant>*)

#endif // QMETAS__H
