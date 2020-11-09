/* axlShapeBSplineWriter.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2014 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlShapeBSplineWriter.h"

#include <axlCore/axlShapeBSpline.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlShapeBSplineWriter
// /////////////////////////////////////////////////////////////////

axlShapeBSplineWriter::axlShapeBSplineWriter(void)
{
    this->setObjectName(this->description());
}

axlShapeBSplineWriter::~axlShapeBSplineWriter(void)
{

}

QString axlShapeBSplineWriter::identifier(void) const
{
    return "axlShapeBSplineWriter";
}

QString axlShapeBSplineWriter::description(void) const
{
    return "axlShapeBSplineWriter";
}

QStringList axlShapeBSplineWriter::handled(void) const
{
    return QStringList() << "axlShapeBSpline";
}

bool axlShapeBSplineWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlShapeBSplineWriter", QStringList(), createaxlShapeBSplineWriter);
}

bool axlShapeBSplineWriter::accept(dtkAbstractData *data)
{
    axlShapeBSpline *surf = dynamic_cast<axlShapeBSpline *>(data);
    if(surf){
        if(surf->identifier() == "axlShapeBSpline"){
            return true;
        }else {
            return false;
        }
    }
    return false;
}

bool axlShapeBSplineWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlShapeBSplineWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlShapeBSpline* surf = dynamic_cast<axlShapeBSpline*>(data);

    ///// Name
    QDomElement surfElement = doc->createElement("surface");
    surfElement.setAttribute("name", surf->name());

    ///// Type
    surfElement.setAttribute("type", "patch");

    ///// Size
    surfElement.setAttribute("size", QString::number(surf->size()));

    //// Color
    QColor qcolor = surf->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(surf->opacity());
    surfElement.setAttribute("color", color);

    //// Shader
    QString shader = surf->shader();
    QFileInfo shaderFileInfo(shader);
    surfElement.setAttribute("shader", shaderFileInfo.fileName());

    // Write surf
    surfElement.setAttribute("nb_points", surf->countControlPoints());
    surfElement.setAttribute("nb_edges", surf->countBoundaryEdges());
    surfElement.setAttribute("nb_faces", surf->countFaces());
    surfElement.setAttribute("orderu", surf->order_u());
    surfElement.setAttribute("orderv", surf->order_v());

    // Vertices
    QDomElement verticesElement = doc->createElement("points");
    for (int k = 1; k <= surf->countControlPoints(); k++) {
        QString coordsString = QString::number(surf->getCoef(k).x()) + " "
                + QString::number(surf->getCoef(k).y()) + " "
                + QString::number(surf->getCoef(k).z()) + "\n\t";
        QDomText coordsDomText = doc->createTextNode(coordsString);
        verticesElement.appendChild(coordsDomText);
    }
    surfElement.appendChild(verticesElement);

    // Edges
    QDomElement edgesElement = doc->createElement("edges");
    for (int k = 0; k < surf->countBoundaryEdges(); k++) {
        QDomElement edgeElement = doc->createElement("edge");
        edgeElement.setAttribute("id", k);

        axlShapeBSpline::Edge* currEdge = surf->getEdge(k);

        QDomElement controlP = doc->createElement("controlPoints");
        for (int j = 0; j < currEdge->controlPointsIndices.size(); j++) {
            QString coordsString = QString::number(currEdge->controlPointsIndices.at(j)) + " ";
            QDomText coordsDomText = doc->createTextNode(coordsString);
            controlP.appendChild(coordsDomText);
        }

        edgeElement.appendChild(controlP);
        edgeElement.setAttribute("tag", currEdge->tag);
        edgesElement.appendChild(edgeElement);
    }

    surfElement.appendChild(edgesElement);

    // Faces
    QDomElement facesElement = doc->createElement("faces");
    for (int k = 0; k < surf->countFaces(); k++) {
        QDomElement faceElement = doc->createElement("face");
        faceElement.setAttribute("id", k);

        axlShapeBSpline::Face* currFace =surf->getFace(k);

        QDomElement controlP = doc->createElement("controlPoints");
        for (int j = 0; j < currFace->controlPointsIndices.size(); j++) {
            QString coordsString = QString::number(currFace->controlPointsIndices.at(j)) + " ";
            QDomText coordsDomText = doc->createTextNode(coordsString);
            controlP.appendChild(coordsDomText);
        }

        QDomElement edgeInd = doc->createElement("nbpts");

            QString coordsString = QString::number(currFace->nbpts_u) + " " + QString::number(currFace->nbpts_v);
            QDomText coordsDomText = doc->createTextNode(coordsString);
            edgeInd.appendChild(coordsDomText);


        faceElement.appendChild(controlP);
        faceElement.appendChild(edgeInd);
        facesElement.appendChild(faceElement);
    }
    surfElement.appendChild(facesElement);

    return surfElement;
}


QDomElement axlShapeBSplineWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlShapeBSplineWriter(void)
{
    return new axlShapeBSplineWriter;
}

