/* axlShapeWriter.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Jul 21 14:13:23 2013 (+0200)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlShapeWriter.h"

#include <axlCore/axlShape.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include <QtGui>

// /////////////////////////////////////////////////////////////////
// axlShapeWriter
// /////////////////////////////////////////////////////////////////

axlShapeWriter::axlShapeWriter(void) :
    axlAbstractDataWriter() {

    this->setObjectName(this->description());
}

axlShapeWriter::~axlShapeWriter(void) {
}

QString axlShapeWriter::identifier(void) const {
    return "axlShapeWriter";
}

QString axlShapeWriter::description(void) const {
    return "axlShapeWriter";
}

QStringList axlShapeWriter::handled(void) const {
    return QStringList() << "axlShape";
}

bool axlShapeWriter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlShapeWriter", QStringList(), createaxlShapeWriter);
}

bool axlShapeWriter::accept(dtkAbstractData *data) {
    axlShape *shape = dynamic_cast<axlShape*>(data);
    if(shape)
        return true;

    return false;
}

bool axlShapeWriter::reject(dtkAbstractData *data) {
    return !this->accept(data);
}

QDomElement axlShapeWriter::write(QDomDocument *doc, dtkAbstractData *data) {
    axlShape* shape = dynamic_cast<axlShape*>(data);

    ///// Name
    QDomElement shapeElement = doc->createElement("shape");
    shapeElement.setAttribute("name", shape->name());

    ///// Size
    shapeElement.setAttribute("size", QString::number(shape->size()));

    //// Color
    QColor qcolor = shape->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(shape->opacity());
    shapeElement.setAttribute("color", color);

    //// Shader
    QString shader = shape->shader();
    QFileInfo shaderFileInfo(shader);
    shapeElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write shape
    shapeElement.setAttribute("nb_vertices", shape->getVertexCount());
    shapeElement.setAttribute("nb_edges", shape->getEdgeCount());
    shapeElement.setAttribute("nb_faces", shape->getFaceCount());

    // Vertices
    QVector<axlPoint*> allVertices = shape->getVertices();
    QDomElement verticesElement = doc->createElement("vertices");
    for (int k = 0; k < allVertices.size(); k++) {
        axlPoint* currVertex = allVertices.at(k);
        QString coordsString = QString::number(currVertex->x()) + " "
                             + QString::number(currVertex->y()) + " "
                             + QString::number(currVertex->z()) + "\n\t";
        QDomText coordsDomText = doc->createTextNode(coordsString);
        verticesElement.appendChild(coordsDomText);
    }
    shapeElement.appendChild(verticesElement);

    // Edges
    QVector<axlShape::Edge*> allEdges = shape->getEdges();
    QDomElement edgesElement = doc->createElement("edges");
    for (int k = 0; k < allEdges.size(); k++) {
        QDomElement edgeElement = doc->createElement("edge");
        edgeElement.setAttribute("id", k);

        axlShape::Edge* currEdge = allEdges.at(k);

        //QDomElement edgeCurveElement = doc->createElement("edge_curve");
        axlAbstractCurveParametric* curve = currEdge->curve;
        QString curveWriterTag = curve->identifier()+"Writer";
        axlAbstractDataWriter* curveWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(curveWriterTag));
        QDomElement curveElement = curveWriter->write(doc, curve);
        //edgeCurveElement.appendChild(curveElement);
        //edgeCurveElement.setAttribute("type", curve->identifier());
        edgeElement.appendChild(curveElement);
        edgeElement.setAttribute("type", curve->identifier());

        //edgeElement.appendChild(edgeCurveElement);

        edgeElement.setAttribute("index_start", currEdge->indexStartVertex);
        edgeElement.setAttribute("index_end", currEdge->indexEndVertex);

        edgesElement.appendChild(edgeElement);
    }
    shapeElement.appendChild(edgesElement);

    // Faces
    QVector<axlShape::Face*> allFaces = shape->getFaces();
    QDomElement facesElement = doc->createElement("faces");
    for (int k = 0; k < allFaces.size(); k++) {
        QDomElement faceElement = doc->createElement("face");
        faceElement.setAttribute("id", k);

        axlShape::Face* currFace = allFaces.at(k);
        QVector<axlShape::Loop*> currLoops = currFace->loops;

        QDomElement faceSurfaceElement = doc->createElement("face_surface");
        axlAbstractSurfaceParametric* surface = currFace->surface;
        QString surfaceWriterTag = surface->identifier()+"Writer";
        axlAbstractDataWriter* surfaceWriter = dynamic_cast<axlAbstractDataWriter*>(dtkAbstractDataFactory::instance()->writer(surfaceWriterTag));
        if (surfaceWriter) {
            QDomElement surfaceElement = surfaceWriter->write(doc, surface);
            //faceSurfaceElement.appendChild(surfaceElement);
            faceElement.appendChild(surfaceElement);
        } else {
            dtkWarn() << surfaceWriterTag << "not supported yet.";
        }
        //faceSurfaceElement.setAttribute("type", surface->identifier());
        faceElement.setAttribute("type", surface->identifier());
        //faceElement.appendChild(faceSurfaceElement);

        for (int i = 0; i < currLoops.size(); i++) {
            QDomElement loopElement = doc->createElement("loop");
            loopElement.setAttribute("id", i);

            axlShape::Loop* currLoop = currLoops.at(i);
            QVector<int> currEdges = currLoop->edges;
            QVector<bool> currOrientations = currLoop->orientations;

            for (int j = 0; j < currEdges.size(); j++) {
                QDomElement edgeElement = doc->createElement("edge");
                edgeElement.setAttribute("id", currEdges.at(j));

                bool currOrientation = currOrientations.at(j);
                edgeElement.setAttribute("orientation", currOrientation);

                loopElement.appendChild(edgeElement);
            }
            faceElement.appendChild(loopElement);
        }
        facesElement.appendChild(faceElement);
    }
    shapeElement.appendChild(facesElement);

    return shapeElement;
}

QDomElement axlShapeWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data) {
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlShapeWriter(void) {
    return new axlShapeWriter;
}
