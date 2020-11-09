/* axlMeshWriter.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008-2011 - Meriadeg Perrinel, Inria.
 * Created: Wed Sep 21 11:36:52 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 12:11:29 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 88
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlMeshWriter.h"

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractFieldDiscrete.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlMesh.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlMeshWriter
// /////////////////////////////////////////////////////////////////

axlMeshWriter::axlMeshWriter(void)
{
    this->setObjectName(this->description());
}

axlMeshWriter::~axlMeshWriter(void)
{

}

QString axlMeshWriter::identifier(void) const
{
    return "axlMeshWriter";
}

QString axlMeshWriter::description(void) const
{
    return "axlMeshWriter";
}

QStringList axlMeshWriter::handled(void) const
{
    return QStringList() << "axlMesh";
}

bool axlMeshWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlMeshWriter", QStringList(), createaxlMeshWriter);
}

bool axlMeshWriter::accept(dtkAbstractData *data)
{
    axlMesh *mesh = dynamic_cast<axlMesh *>(data);
    if(mesh)
        return true;

    return false;
}

bool axlMeshWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlMeshWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlMesh *mesh = dynamic_cast<axlMesh *>(data);

    /////Name
    QDomElement meshElement = doc->createElement("mesh");
    QString name = data->name();
    if(name.size()>0)
      meshElement.setAttribute("name",name);

    /////Size
    meshElement.setAttribute("size", QString::number(mesh->size()));

    ////Color
    QString color ;

    QColor qcolor = mesh->color();
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) << " "
                        << QString::number(mesh->opacity());

    meshElement.setAttribute("color", color);

    ////Shader
    QString shader = mesh->shader();
    QFileInfo shaderFileInfo(shader);
    if(shader.size()>0)
      meshElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write point
    //number of points
    QDomElement count= doc->createElement("count");
    QString countStr;
    QTextStream(&countStr) << QString::number(mesh->vertex_count())
                           << " " << QString::number(mesh->edge_count())
                           << " " << QString::number(mesh->face_count());

    QDomText countDomText = doc->createTextNode(countStr);
    count.appendChild(countDomText);
    meshElement.appendChild(count);

    //// points
    QDomElement points = doc->createElement("points");
    if(mesh->color_used())
        points.setAttribute("color", "rgb");
    QString pointsText;
    for(int i = 0 ; i < mesh->vertex_count(); i++)
    {
        QTextStream(&pointsText)<< "\n  " << QString::number(mesh->vertexX(i)) << " "<< QString::number(mesh->vertexY(i)) << " "<< QString::number(mesh->vertexZ(i));
        if(mesh->color_used())
            QTextStream(&pointsText)<< " " << QString::number(mesh->colorR(i)) << " "<< QString::number(mesh->colorG(i)) << " "<< QString::number(mesh->colorB(i));

    }
    QTextStream(&pointsText)<< "\n"; // for easy read of the file
    QDomText pointsDomText = doc->createTextNode(pointsText);
    points.appendChild(pointsDomText);
    meshElement.appendChild(points);

    //// colors
    if(mesh->vertex_count()>0 && mesh->color_count()>0 && !mesh->color_used()) {
        QDomElement colors = doc->createElement("colors");
        QString colorsText;
        for(int i = 0 ; i < mesh->vertex_count(); i++)
        {
            QTextStream(&colorsText) << "\n  " << QString::number(mesh->colorR(i)) << " "<< QString::number(mesh->colorG(i)) << " "<< QString::number(mesh->colorB(i));
        }
        QTextStream(&colorsText)<< "\n"; // for easy read of the file
        QDomText colorsDomText = doc->createTextNode(colorsText);
        colors.appendChild(colorsDomText);
        meshElement.appendChild(colors);
    }

//    ///// Fields

//    foreach(axlAbstractField *field, mesh->fields())
//    {

//        axlAbstractFieldDiscrete *currentField = dynamic_cast<axlAbstractFieldDiscrete *>(field);
//        QDomElement fields = doc->createElement("field");



//        //Support
//        int fieldSupport= currentField->support();
//        if(fieldSupport == 1)
//            fields.setAttribute("support", "point");
//        else if (fieldSupport == 2)
//            fields.setAttribute("support", "cell");
//        else
//            fields.setAttribute("support", "custom");

//        //Kind
//        int fieldKind= currentField->kind();
//        if(fieldKind == 1)
//            fields.setAttribute("kind", "scalar");
//        else if (fieldKind == 2)
//            fields.setAttribute("kind", "sector");
//        else
//            fields.setAttribute("kind", "tensor");

//        //Type
//        int fieldType= currentField->type();
//        if(fieldType == 1)
//            fields.setAttribute("type", "int");
//        else if (fieldType == 2)
//            fields.setAttribute("type", "float");
//        else
//            fields.setAttribute("type", "double");

//        //Name
//        fields.setAttribute("name", currentField->name());

//        QString fieldsText;
//        qDebug()<<"axlMeshWritter"<<fieldType<<fieldKind<<fieldSupport;

//        if(fieldKind == 1)
//            for(int i = 0 ; i < mesh->vertex_count(); i++)
//                QTextStream(&fieldsText) << "\n  " << QString::number(currentField->scalar(i));
//        else if(fieldKind == 2)
//            for(int i = 0 ; i < mesh->vertex_count(); i++)
//                QTextStream(&fieldsText) << "\n  " << QString::number((currentField->vector(i))[0]) << " "<< QString::number((currentField->vector(i))[1]) << " "<< QString::number((currentField->vector(i))[2]);

//        QTextStream(&fieldsText)<< "\n"; // for easy read of the file
//        QDomText fieldsDomText = doc->createTextNode(fieldsText);
//        fields.appendChild(fieldsDomText);
//        meshElement.appendChild(fields);
//    }

    //// edges
    if(mesh->edge_count()>0) {
        QDomElement edges = doc->createElement("edges");
        QString edgesText;
        for(int i = 0 ; i < mesh->edge_count(); i++) {
            axlMesh::Edge e = mesh->edge(i);
            QTextStream(&edgesText)<< "\n  " << QString::number(e.size());
            for (int j=0;j<e.size();j++)
                QTextStream(&edgesText)<< " " << QString::number(e.at(j));
        }
        QTextStream(&edgesText)<< "\n"; // for easy read of the file
        QDomText edgesDomText = doc->createTextNode(edgesText);
        edges.appendChild(edgesDomText);
        meshElement.appendChild(edges);
    }

    //// faces
    if(mesh->face_count()>0) {
        QDomElement faces = doc->createElement("faces");
        QString facesText;
        for(int i = 0 ; i < mesh->face_count(); i++){
            QVector<int> f = mesh->face(i);
            QTextStream(&facesText)<< "\n  " << QString::number(f.size());
            for(int l=0; l < f.size(); l++)
                QTextStream(&facesText) << " " << QString::number(f.at(l));
        }
        QTextStream(&facesText)<< "\n"; // for easy read of the file
        QDomText facesDomText = doc->createTextNode(facesText);
        faces.appendChild(facesDomText);
        meshElement.appendChild(faces);
    }


    //Write fields if exist.
    if(!mesh->fields().isEmpty()){
        foreach(axlAbstractField *field, mesh->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            meshElement.appendChild(fieldElement);
        }
    }


    return meshElement;
}


QDomElement axlMeshWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlMeshWriter(void)
{
    return new axlMeshWriter;
}
