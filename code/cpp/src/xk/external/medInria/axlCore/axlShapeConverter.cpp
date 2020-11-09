/* axlShapeConverter.cpp ---
            *
            * Author: Valentin Michelet
            * Copyright (C) 2008-2011 - Valentin Michelet, Inria.
            * Created: Tue Apr 30 11:03:18 2012 (+0100)
            */

/* Commentary:
            *
            */

/* Change log:
            *
            */

#include "axlMesh.h"
#include "axlShape.h"
#include "axlShapeConverter.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include "axlPoint.h"

#include <cmath>

class axlShapeConverterPrivate {
public:
    axlShape* data;
};

axlShapeConverter::axlShapeConverter(void) : axlAbstractDataConverter(), d(new axlShapeConverterPrivate) {
    d->data = NULL;
}

axlShapeConverter::~axlShapeConverter(void) {
    delete d;
    d = NULL;
}

QString axlShapeConverter::description(void) const {
    return "Converter from axlShape to axlMesh";
}

QString axlShapeConverter::identifier() const {
    return "axlShapeConverter";
}

QStringList axlShapeConverter::fromTypes(void) const {
    return QStringList() << "axlShapeConverter" << "axlShape";
}

QString axlShapeConverter::toType (void) const {
    return "axlMesh";
}

bool axlShapeConverter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlShapeConverter", QStringList(), "axlMesh", createaxlShapeConverter);
}

axlMesh* axlShapeConverter::toMesh(void) {
    //qDebug() << "#################################################";
    if(!d->data)
        return NULL;
    //qDebug() << "#################################################";

    // Create mesh
    axlMesh* mesh = new axlMesh;

    // Add every vertices to mesh
    QVector<axlPoint*> vertices = d->data->getVertices();
    for (int k = 0; k < d->data->getVertexCount(); k++) {
        mesh->push_back_vertex(*vertices.at(k));
    }

    dtkWarn() << "nb of edges" << d->data->getEdgeCount();

    // Add edges to mesh thanks to curve convector
    QVector<axlShape::Edge*> allEdges = d->data->getEdges();
    for (int k = 0; k < d->data->getEdgeCount(); k++) {
        // Get current edge
        axlShape::Edge currEdge = *allEdges.at(k);

        // Create current curve converter name
        QString converterName = currEdge.curve->identifier()+"Converter";
        dtkWarn() << currEdge.curve->identifier()+"Converter";
        // Create current converter according to current curve
        axlAbstractDataConverter* converter = dynamic_cast<axlAbstractDataConverter*>(dtkAbstractDataFactory::instance()->converter(converterName));

        // Complete current mesh from current converter
        if (converter) {
            converter->setData(currEdge.curve);
            converter->setParams(0, currEdge.indexStartVertex);
            converter->setParams(1, currEdge.indexEndVertex);
            converter->setOutput(mesh);
            if (!converter->toMesh()) {
                dtkWarn() << "Mesh is NULL within converterName::toMesh";
            }
        } else
            dtkWarn() << "No converter found for" << currEdge.curve->identifier();
    }

    dtkWarn() << "nb of faces" << d->data->getFaceCount();

    // Add faces to mesh thanks to surface convector
    QVector<axlShape::Face*> allFaces = d->data->getFaces();
    for (int k = 0; k < d->data->getFaceCount(); k++) {
        // Get current Face
        axlShape::Face currFace = *allFaces.at(k);

        // Create current curve converter name
        QString converterName = currFace.surface->identifier()+"Converter";
        dtkWarn() << currFace.surface->identifier()+"Converter";
        // Create current converter according to current curve
        axlAbstractDataConverter* converter = dynamic_cast<axlAbstractDataConverter*>(dtkAbstractDataFactory::instance()->converter(converterName));

        // Complete current mesh from current converter for faces with no loop.
        if (converter && currFace.loops.size()==1) {
            converter->setData(currFace.surface);
            converter->setOutput(mesh);
            if (!converter->toMesh()) {
                dtkWarn() << "Mesh is NULL within converterName::toMesh";
            }
        } else
            dtkWarn() << "No converter found for face with " << currFace.surface->identifier();
    }


    mesh->vertex_show() = false;
    mesh->normal_used() = false;
    mesh->color_used() = false;
    mesh->edge_show() = true;
    mesh->face_show() = true;

    if(mesh){
        dtkWarn() << Q_FUNC_INFO << "mesh is created with axlShapeConverter"
                  << "[" << mesh->vertex_count()<< mesh->edge_count()<< mesh->face_count() << "]";
    }

    return mesh;
}

void axlShapeConverter::setData(dtkAbstractData* data) {
    if(axlShape* shape = dynamic_cast<axlShape*>(data))
        d->data = shape;
}

dtkAbstractDataConverter* createaxlShapeConverter(void) {
    return new axlShapeConverter;
}
