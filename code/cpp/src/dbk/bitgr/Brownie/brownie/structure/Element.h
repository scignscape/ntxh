#ifndef ELEMENT_H
#define ELEMENT_H

#include <QVariant>
#include <QString>

class Graph;

class Element
{
 virtual QVariant id() = 0;
	virtual QString label() = 0;
	virtual Graph* getGraph() = 0;
};

#include "structure/Graph.h"

#endif
