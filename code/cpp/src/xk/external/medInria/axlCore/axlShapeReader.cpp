/* axlShapeReader.cpp ---
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

#include "axlShapeReader.h"

#include <axlCore/axlShape.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>

#include <axlCore/axlPlane.h>
#include <axlCore/axlPlaneParametric.h>

#include <QtGui>

// /////////////////////////////////////////////////////////////////
// axlShapeReader
// /////////////////////////////////////////////////////////////////

axlShapeReader::axlShapeReader(void) :
    axlAbstractDataReader() {

    this->setObjectName(this->description());
}

axlShapeReader::~axlShapeReader(void) {
}

QString axlShapeReader::identifier(void) const {
    return "axlShapeReader";
}

QString axlShapeReader::description(void) const {
    return "axlShapeReader";
}

QStringList axlShapeReader::handled(void) const {
    return QStringList() << "axlShape";
}

bool axlShapeReader::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlShapeReader", QStringList(), createaxlShapeReader);
}

bool axlShapeReader::accept(const QDomNode& node) {
    QDomElement element = node.toElement();

    if (element.tagName() != "shape")
        return false;

    return true;
}

bool axlShapeReader::reject(const QDomNode& node) {
    return !this->accept(node);
}

axlAbstractData *axlShapeReader::read(const QDomNode& node) {
    // Create element from given node
    QDomElement element = node.toElement();

    // Create shape from vertices, edges and faces counters
    int vertexCount = element.attribute("nb_vertices").toInt();
    int edgeCount = element.attribute("nb_edges").toInt();
    int faceCount = element.attribute("nb_faces").toInt();
    axlShape* shape = new axlShape(vertexCount, edgeCount, faceCount);

    // Handle name
    QString name = element.attribute("name");
    if (!name.isEmpty()) {
        shape->setObjectName(name);
    }

    // Handle color
    QString color = element.attribute("color");
    if (!color.isEmpty()) {
        QStringList colorList = color.split(" ");
        if (colorList.size() > 2) // rgb components
            shape->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if (colorList.size() == 4)
            shape->setOpacity(colorList.at(3).toFloat());
    }

    // Handle shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if (!shader.isEmpty()) {
        // Try to read from axelShader.qrc
        dirShader = ":axlShader/shader/" + shader;
        if (!QFile::exists(dirShader)) {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
            dirShader.append("/" + shader);
        }
        shape->setShader(dirShader);
    }

    // Handle size
    QString size = element.attribute("size");
    if (!size.isEmpty())
        shape->setSize(size.toFloat());

    // Handle vertices
    QDomElement verticesElement = element.elementsByTagName("vertices").at(0).toElement();
    QStringList verticesList = verticesElement.text().simplified().split(QRegExp("\\s+"));
    for (int k = 0; k < verticesList.size(); k+=3) {
        axlPoint* newPoint = new axlPoint(verticesList.at(k+0).toDouble(),
                                          verticesList.at(k+1).toDouble(),
                                          verticesList.at(k+2).toDouble());
        shape->insert_vertex(newPoint, k/3);
    }

    // Handle edges
    QDomElement edgesElement = element.elementsByTagName("edges").at(0).toElement();
    QDomNodeList edgesList = edgesElement.elementsByTagName("edge");

    for (int k = 0; k < edgesList.size(); k++) {
        QDomElement edgeElement = edgesList.at(k).toElement();

        axlShape::Edge* newEdge = new axlShape::Edge;
        newEdge->indexStartVertex = edgeElement.attribute("index_start").toInt();
        newEdge->indexEndVertex = edgeElement.attribute("index_end").toInt();

        //QDomElement curveElement = edgeElement.elementsByTagName("edge_curve").at(0).toElement();
        //QString curveReaderTag = curveElement.attribute("type")+"Reader";
        QString curveReaderTag = edgeElement.attribute("type")+"Reader";

        axlAbstractDataReader* curveReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(curveReaderTag));
        //newEdge->curve = dynamic_cast<axlAbstractCurveParametric*>(curveReader->read(curveElement.childNodes().at(0)));
        if(curveReader) {
            newEdge->curve = dynamic_cast<axlAbstractCurveParametric*>(curveReader->read(edgeElement.childNodes().at(0)));
            shape->insert_edge(newEdge, edgeElement.attribute("id").toInt());
            dtkWarn()<<"axlShapeReader::read"<< curveReaderTag;
        } else {
            dtkWarn()<< "Error within axlShapeReader::read edge:" << curveReaderTag << "is not registered within readers.";
        }
    }

    // Handle faces
    QDomElement facesElement = element.elementsByTagName("faces").at(0).toElement();
    QDomNodeList facesList = facesElement.elementsByTagName("face");

    for (int k = 0; k < facesList.size(); k++) {
        QDomElement faceElement = facesList.at(k).toElement();
        axlShape::Face* face = new axlShape::Face;

        QDomNodeList loopsList = faceElement.elementsByTagName("loop");

        //QDomElement surfaceElement = faceElement.elementsByTagName("face_surface").at(0).toElement();
        //QString surfaceReaderTag = surfaceElement.attribute("type")+"Reader";
        QString surfaceReaderTag = faceElement.attribute("type")+"Reader";

        axlAbstractDataReader* surfaceReader = dynamic_cast<axlAbstractDataReader*>(dtkAbstractDataFactory::instance()->reader(surfaceReaderTag));

        if (surfaceReader) {
            //dtkAbstractData* s = surfaceReader->read(surfaceElement.childNodes().at(0));
            //dtkAbstractData* s = surfaceReader->read(faceElement.childNodes().at(0));
            //axlAbstractSurfaceParametric* absSurfParam = dynamic_cast<axlAbstractSurfaceParametric*>(surfaceReader->read(surfaceElement.childNodes().at(0)));
            axlAbstractSurfaceParametric* absSurfParam = dynamic_cast<axlAbstractSurfaceParametric*>(surfaceReader->read(faceElement.childNodes().at(0)));
            face->surface = absSurfParam;
        } else {
            dtkWarn() << "Error within axlShapeReader::read face:" << surfaceReaderTag << "is not registered within readers.";
            axlPlaneParametric pl(axlPlane(axlPoint(0, 0, 0), axlPoint(0, 0, 1)), axlPoint(1, 0, 0));
            pl.setSize(0.01);
            face->surface = new axlPlaneParametric(pl);
        }

        for (int i = 0; i < loopsList.size(); i++) {
            QDomElement loopElement = loopsList.at(i).toElement();
            axlShape::Loop* loop = new axlShape::Loop;

            QDomNodeList edgesList = loopElement.elementsByTagName("edge");

            for (int j = 0; j < edgesList.size(); j++) {
                QDomElement edgeElement = edgesList.at(j).toElement();

                loop->edges << edgeElement.attribute("id").toInt();

                bool currOrientation = edgeElement.attribute("orientation").toInt();
                loop->orientations << currOrientation;
            }
            face->loops << loop;
        }

        shape->insert_face(face, faceElement.attribute("id").toInt());
    }

    return shape;
}

dtkAbstractDataReader *createaxlShapeReader(void) {
    return new axlShapeReader;
}
