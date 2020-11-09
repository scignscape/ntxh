/* axlMeshReader.cpp ---
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

#include "axlMeshReader.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlAbstractFieldDiscrete.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlMeshReader
// /////////////////////////////////////////////////////////////////

axlMeshReader::axlMeshReader(void)
{
    this->setObjectName(this->description());
}

axlMeshReader::~axlMeshReader(void)
{

}

QString axlMeshReader::identifier(void) const
{
    return "axlMeshReader";
}

QString axlMeshReader::description(void) const
{
    return "axlMeshReader";
}

QStringList axlMeshReader::handled(void) const
{
    return QStringList() << "axlMesh";
}

bool axlMeshReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlMeshReader", QStringList(), createaxlMeshReader);
}

bool axlMeshReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "mesh")
        return false;

    if(!hasChildNode(element, "count"))
        return false;

    if(!hasChildNode(element, "points"))
        return false;

    //only off works for the moment
    // if(element.attribute("type") != "off")
    //     return false;

    return true;
}

bool axlMeshReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlMeshReader::read(const QDomNode& node)
{
    QDomElement element = node.toElement();

    axlMesh *mesh = new axlMesh;

    // mesh name
    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        mesh->setObjectName(name);
    }
    // mesh Color
    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() > 2) // rgb components
            mesh->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
        if(colorList.size() > 3) // opacity
            mesh->setOpacity(colorList.at(3).toDouble());
    }

    // mesh shader
    QString shader = element.attribute("shader");
    QString dirShader;
    if(!shader.isEmpty())
    {
        // try to read from axelShader.qrc
        dirShader = ":axlShader/shader/"+shader;
        if(!QFile::exists(dirShader))
        {
            QSettings settings("inria", "dtk");
            QString defaultPath;
            settings.beginGroup("shader");
            dirShader = settings.value("path", defaultPath).toString();
            //            dirShader = this->file().left(this->file().lastIndexOf("axel-data") + 9); // to Remove later
            dirShader.append("/"+shader);
        }
        mesh->setShader(dirShader);
    }

    // mesh size
    QString size = element.attribute("size");
    if(!size.isEmpty())
        mesh->setSize(size.toFloat());


    // Count
    QDomNodeList nodelist_count = element.elementsByTagName("count") ;
    QDomElement count = nodelist_count.item(0).toElement();
    QString *text_count = new QString(count.text());
    QTextStream in(text_count);

    int vertexCount = 0;
    int edgeCount = 0;
    int faceCount = 0;

    in.skipWhiteSpace();
    in >> vertexCount;
    if(!in.atEnd()){
        in.skipWhiteSpace();
        in >> edgeCount;
    }
    if(!in.atEnd()) {
        in.skipWhiteSpace();
        in >> faceCount;
    }

    delete text_count;

    // Points
    double vx = 0.0;
    double vy = 0.0;
    double vz = 0.0;
    int r = 255;
    int g = 0;
    int b = 0;

    if(vertexCount>0){

        QDomNodeList nodelist_points = element.elementsByTagName("points") ;
        QDomElement points = nodelist_points.item(0).toElement();

        QString *text_points = new QString(points.text());
        QTextStream in_points(text_points);

        QString color = points.attribute("color");
        if(color == "rgb")
            mesh->color_used()=true;

        for(int i = 0 ; i < vertexCount ; i++)
        {
            in_points.skipWhiteSpace();
            in_points >> vx;
            in_points.skipWhiteSpace();
            in_points >> vy;
            in_points.skipWhiteSpace();
            in_points >> vz;
            mesh->push_back_vertex(vx, vy, vz);

            if (mesh->color_used()) {
                in_points.skipWhiteSpace();
                in_points >> r;
                in_points.skipWhiteSpace();
                in_points >> g;
                in_points.skipWhiteSpace();
                in_points >> b;
                mesh->push_back_color(r, g, b);
            }
        }

        delete text_points;
    }


    //colors
    QDomNodeList nodelist_colors = element.elementsByTagName("colors") ;
    QString *text_colors;
    if(nodelist_colors.size()>0 && !mesh->color_used()) {
        text_colors = new QString(nodelist_colors.item(0).toElement().text());

        QTextStream in_colors(text_colors);

        for(int i = 0 ; i < vertexCount ; i++)
        {
            in_colors.skipWhiteSpace();
            in_colors >> r;
            in_colors.skipWhiteSpace();
            in_colors >> g;
            in_colors.skipWhiteSpace();
            in_colors >> b;
            mesh->push_back_color(r, g, b);
        }
        delete text_colors;
    }


    // Normals
    QDomNodeList nodelist_normals = element.elementsByTagName("normals") ;
    if(nodelist_normals.size()>0) {
        QString *text_normals = new QString(nodelist_normals.item(0).toElement().text());
        QTextStream in_normals(text_normals);

	mesh->normal_used()=true;

        for(int i = 0 ; i < vertexCount ; i++)
        {
            in_normals.skipWhiteSpace();
            in_normals >> vx;
            in_normals.skipWhiteSpace();
            in_normals >> vy;
            in_normals.skipWhiteSpace();
            in_normals >> vz;
            mesh->push_back_normal(vx, vy, vz);
        }

        delete text_normals;
    }

    //    //fields
    //    QDomNodeList nodelist_fields = element.elementsByTagName("field") ;
    //    int numOccurence = 1;
    //    for(int e = 0; e < nodelist_fields.count(); e++)
    //    {
    //        axlAbstractFieldDiscrete *field = dynamic_cast<axlAbstractFieldDiscrete *>(dtkAbstractDataFactory::instance()->create("axlFieldDiscrete"));

    //        QDomElement CurrentNodeElement = nodelist_fields.item(e).toElement();

    //        // Name
    //        QString fieldName = CurrentNodeElement.attribute("name");

    //        if(fieldName.isEmpty()){
    //            fieldName = "field";
    //            fieldName.append(QString::number(numOccurence));
    //            numOccurence++;
    //        }


    //        bool fieldWithSameNameExit = false;
    //        foreach(axlAbstractField *field, mesh->fields() )
    //            if(field->name().toLower() == fieldName.toLower())
    //                fieldWithSameNameExit = true;


    //        if(fieldWithSameNameExit)
    //        {
    //            qDebug()<< "Sorry, but you put two Fields with same name. The second one are not accepted";
    //            delete field; // free memory
    //        }
    //        else
    //        {
    //            // Type
    //            QString fieldType= CurrentNodeElement.attribute("type");
    //            if(fieldType.toLower() == "int")
    //                field->setType(axlAbstractFieldDiscrete::Int);
    //            else if (fieldType.toLower() == "float")
    //                field->setType(axlAbstractFieldDiscrete::Float);
    //            else if(fieldType.toLower() == "double")
    //                field->setType(axlAbstractFieldDiscrete::Double);
    //            else
    //            {
    //                qDebug()<<mesh->name()<< "havn't accepted Type";
    //                break;
    //            }

    //            // Kind
    //            QString fieldKind = CurrentNodeElement.attribute("kind");
    //            if(fieldKind.toLower() == "scalar")
    //                field->setKind(axlAbstractFieldDiscrete::Scalar);
    //            else if (fieldKind.toLower() == "vector")
    //                field->setKind(axlAbstractFieldDiscrete::Vector);
    //            else if(fieldKind.toLower() == "tensor")
    //                field->setKind(axlAbstractFieldDiscrete::Tensor);
    //            else
    //            {
    //                qDebug()<<mesh->name()<< "havn't accepted kind";
    //                break;
    //            }

    //            // Support
    //            QString fieldSupport = CurrentNodeElement.attribute("support");
    //            if(fieldSupport.toLower() == "point")
    //                field->setSupport(axlAbstractFieldDiscrete::Point);
    //            else if (fieldSupport.toLower() == "cell")
    //                field->setSupport(axlAbstractFieldDiscrete::Cell);
    //            else if(fieldSupport.toLower() == "custom")
    //                field->setSupport(axlAbstractFieldDiscrete::Custom);
    //            else
    //            {
    //                qDebug()<<mesh->name()<< "havn't accepted Support";
    //                break;
    //            }

    //            field->setObjectName(fieldName);


    //            QString *text_fields;
    //            if(nodelist_fields.size()>0)
    //            {
    //                //Field Values reading
    //                field->setSize(vertexCount);
    //                text_fields = new QString(CurrentNodeElement.text());

    //                QTextStream in_fields(text_fields);

    //                if(fieldKind.toLower() == "scalar")
    //                {
    //                    for(int i = 0 ; i < vertexCount ; i++)
    //                    {
    //                        in_fields.skipWhiteSpace();
    //                        in_fields >> s;
    //                        field->setScalar(i, s);
    //                    }
    //                }
    //                else if(fieldKind.toLower() == "vector")
    //                {
    //                    for(int i = 0 ; i < vertexCount ; i++)
    //                    {
    //                        in_fields.skipWhiteSpace();
    //                        in_fields >> vx;
    //                        in_fields.skipWhiteSpace();
    //                        in_fields >> vy;
    //                        in_fields.skipWhiteSpace();
    //                        in_fields >> vz;
    //                        field->setVector(i, vx, vy, vy);
    //                    }
    //                }

    //                mesh->addField(field);
    //                field->update();

    //                delete text_fields;

    //            }
    //        }
    //    }// End Fields

    //if there are some field, read them thanks to the factory.
    QDomNodeList nodeListField = element.elementsByTagName("field");
    if(!nodeListField.isEmpty()){
        for(int i =0; i < nodeListField.size(); i++){
            QDomElement fieldElement = nodeListField.at(i).toElement();
            QString fieldType = fieldElement.attribute("type");
            if(!fieldType.isEmpty()){
                axlAbstractDataReader *field_reader = dynamic_cast<axlAbstractDataReader *>(axlFieldReadersFactory::instance()->create(fieldType));
                if(field_reader){
                    axlAbstractField * fieldToAdd = dynamic_cast<axlAbstractField *>(field_reader->read(fieldElement));

                    if(fieldToAdd){
                        QString newName = mesh->changeFieldName(fieldToAdd->name());
                        fieldToAdd->setObjectName(newName);
                        mesh->addField(fieldToAdd);
                    }
                }else{
                    qDebug() << Q_FUNC_INFO << "no reader available";
                }
            }
        }
    }

    // Edges
    if(edgeCount>0) {

        QDomNodeList nodelist_edges = element.elementsByTagName("edges") ;
        if (nodelist_edges.size()==0) {
            dtkWarn() <<"Error in mesh format: no edge but edgeCount>0";
            return NULL;
        }

        QString *text_edges = new QString(nodelist_edges.item(0).toElement().text());
        QTextStream in_edges(text_edges);

        int l0, e1;
        for(int i = 0 ; i < edgeCount ; i++)
        {
            in_edges.skipWhiteSpace();
            in_edges >> l0;

            axlMesh::Edge newEdge;
            for(int j=0; j< l0; j++) {
                in_edges.skipWhiteSpace();
                in_edges >> e1;
                newEdge << e1;
            }
            mesh->push_back_edge(newEdge);
        }

        delete text_edges;
    }

    //// Faces
    if(faceCount>0) {

        QDomNodeList nodelist_faces = element.elementsByTagName("faces") ;
        if (nodelist_faces.size()==0) {
            dtkWarn() <<"Error in mesh format: no face but faceCount>0";
            return NULL;
        }

        QString *text_faces = new QString(nodelist_faces.item(0).toElement().text());
        QTextStream in_faces(text_faces);

        QVector<int> currentFace;
        int currentFaceSize = 0;
        int currentFaceIndex = 0;
        for(int i = 0 ; i < faceCount ; i++)
        {
            currentFace.clear();
            in_faces.skipWhiteSpace();
            in_faces >> currentFaceSize;

            // current face reading
            for(int j = 0 ; j < currentFaceSize ; j++)
            {
                in_faces.skipWhiteSpace();
                in_faces >> currentFaceIndex;
                currentFace << currentFaceIndex;
            }
            in_faces.readLine(75);
            mesh->push_back_face(currentFace);
        }

        delete text_faces;
    }

    mesh->face_show() = false;
    mesh->edge_show() = false;
    mesh->vertex_show() = false;

    if(mesh->face_count() >0)
    {
        mesh->face_show() = true;
        //        mesh->edge_show() = false;
        //        mesh->vertex_show() = false;
    }

    if(mesh->edge_count() != 0)
    {
        //    mesh->face_show() = false;
        mesh->edge_show() = true;
        //    mesh->vertex_show() = false;
    }

    if(mesh->vertex_count() > 0 && mesh->edge_count() ==0 && mesh->face_count() ==0 )
    {
        //mesh->face_show() = false;
        //mesh->edge_show() = false;
        mesh->vertex_show() = true;
    }
    return mesh;
}

dtkAbstractDataReader *createaxlMeshReader(void)
{
    return new axlMeshReader;
}
