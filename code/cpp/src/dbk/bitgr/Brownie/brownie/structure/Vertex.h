#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include <QVector>
#include <QVariant>
#include "structure/VertexProperty.h"
#include "structure/Element.h"
#include "structure/Direction.h"

class Graph;

class Vertex : public Element {
public:
	/*
		Create a new Vertex; does nothing since
		Vertex is just an interface
	*/
	Vertex(){};

	/*
		Get the Graph this Vertex belongs to.
	*/
	virtual Graph* getGraph() = 0;

	/*
		Return a pointer to the Graph's unique 
		Vertex id for this Vertex.
	*/
	virtual QVariant id() = 0;

	/*
		Return a pointer to the Graph's label
		for this Vertex.  If this Vertex does
		not have a label, return NULL.
	*/
	virtual QString label() = 0;

	/*
		Get the edges for this Vertex in the given direction.
	*/
	virtual QVector<Edge*> edges(Direction dir) = 0;

	/*
		Get the property corresponding to the given
		key.
	*/
	virtual VertexProperty<QVariant>* property(QString key) = 0;

	/*
		Set the property corresponding to the given
		key assuming the given cardinality.
	*/
	virtual VertexProperty<QVariant>* property(Cardinality cardinality, QString key, QVariant& value) = 0;

	/*
		Set the property corresponding to the given
		key.
	*/
	virtual VertexProperty<QVariant>* property(QString key, QVariant& value) = 0;
};

#include "structure/Graph.h"

#endif