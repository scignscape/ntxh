/* axlReader.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 12:46:11 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 11:11:59 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 94
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlReader.h"

#include <axlCore/axlCircleArc.h>
#include <axlCore/axlAbstractField.h>

#include <axlCore/axlAbstractDataCompositeReader.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlConeReader.h>
#include <axlCore/axlCylinderReader.h>
#include <axlCore/axlEllipsoidReader.h>
#include <axlCore/axlLineReader.h>
#include <axlCore/axlPlaneReader.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlMeshReader.h>
#include <axlCore/axlSphereReader.h>
#include <axlCore/axlPointReader.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlMeshReader.h>
#include <axlCore/axlTorusReader.h>
#include <axlCore/axlCircleArcReader.h>
#include <axlCore/axlShapeReader.h>

#include <axlCore/axlLine.h>
#include <axlCore/axlSphere.h>
#include <axlCore/axlCircleArc.h>
#include <axlCore/axlTorus.h>
#include <axlCore/axlAbstractCurveBSpline.h>
#include <axlCore/axlAbstractSurfaceBSpline.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractDataReader.h>

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlDataDynamicReader.h>
#include <axlCore/axlAbstractDataComposite.h>

#include <QtWidgets>

// /////////////////////////////////////////////////////////////////
// axlReaderPrivate
// /////////////////////////////////////////////////////////////////

class axlReaderPrivate
{
public:
    QList<axlAbstractData *> dataList;

    QString filename;
};

// /////////////////////////////////////////////////////////////////
// axlReader
// /////////////////////////////////////////////////////////////////

axlReader::axlReader(void) : QObject(), d(new axlReaderPrivate)
{
}

axlReader::~axlReader(void)
{
    delete d;

    d = NULL;
}


QList<axlAbstractData *> axlReader::dataSet(void){
    return d->dataList;
}

axlAbstractData *axlReader::data(int index){
    if(d->dataList.size() > index){
        return d->dataList.at(index);
    }
    return NULL;
}

bool axlReader::read(const QString& file)
{
    d->filename = file;

    d->dataList.clear(); // make sur that the list is empty

    QDomDocument domdocument("axl");

    QFile f(file);

    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Axel", "Error of reading", "&Ok", 0);
        return 0;
    }

    if(!domdocument.setContent(&f)) {
        QMessageBox::information(0, "Axel", file + " is not a valid Axel file", "&Ok", 0);
        return 0;
    }

    f.close();

    QDomNode n = domdocument.firstChildElement("axl").firstChild();
    QDomElement view;

    bool sameName = false;
    while (!n.isNull()) {


        dtkAbstractData *readData = this->read(n);
        if(axlAbstractData *axldata = dynamic_cast<axlAbstractData *>(readData)){

//            qDebug()<<"-- read"<<axldata->identifier();
            if(!d->dataList.isEmpty() && axldata->name() != axldata->identifier() && !sameName){
                foreach(axlAbstractData *listData, d->dataList){
                    if(listData->name() == axldata->name() ){
                        sameName = true;
                    }
                    if(!sameName && dynamic_cast<axlDataDynamic *>(listData)){
                        axlDataDynamic *dataD = dynamic_cast<axlDataDynamic *>(listData);
                        for(int i = 0; i< dataD->numberOfChannels();i++){
                            if(dataD->outputs(i)->name() == axldata->name()){
                                sameName = true;
                            }
                        }
                    }
                }
            }

            if(!dynamic_cast<axlAbstractField *>(axldata)){
                d->dataList << axldata;
//                qDebug()<<"-- data list"<<d->dataList.size();
            }
        }

        if (n.toElement().tagName() == "view")
            view = n.toElement();

        n = n.nextSibling();
    }

    dtkWarn() << Q_FUNC_INFO << "reads" <<d->dataList.size()<<"object(s)";
    emit dataSetInserted(d->dataList);
    int sizeList = d->dataList.size();
    for(int i = 0; i < sizeList; i++){
        if(!d->dataList.at(i)->fields().isEmpty()){
            foreach(axlAbstractField *field, d->dataList.at(i)->fields()){
                QList<axlAbstractData *>a;
                a << d->dataList.at(i);
                emit dataSetFieldsChanged(a, field->name());
            }
        }
    }

    // emit last the scene (inserted data reset the camera)
    if (view.tagName() == "view")
        emit dataSceneRead(view);

    if(sameName){
       //QMessageBox::information(0, "Axel", "Two or more objects have the same name: \n geometry may be false" , "&Ok", 0);
       dtkWarn()<<"\e[1;31m Two or more objects have the same name in"<< file<<" (name changed) \e[0m";
    }

    return true;
}

axlAbstractData *axlReader::read(const QDomNode& node)
{

    axlAbstractData *data = NULL;
    // test for all reader registered in the factory
    foreach(QString reader, dtkAbstractDataFactory::instance()->readers()) {
        dtkWarn()<<"reader"<<reader;
        axlAbstractDataReader *axl_reader = dynamic_cast<axlAbstractDataReader *>(dtkAbstractDataFactory::instance()->reader(reader));
        data = this->dataByReader(axl_reader, node);
        delete axl_reader;

        if(data){
            return data;
        }

    }

    // test for particular case
    axlConeReader *axl_cone_reader = new axlConeReader;
    data = this->dataByReader(axl_cone_reader, node);
    delete axl_cone_reader;

    if(data)
        return data;

    axlCylinderReader *axl_cylinder_reader = new axlCylinderReader;
    data = this->dataByReader(axl_cylinder_reader, node);
    delete axl_cylinder_reader;

    if(data)
        return data;

    axlTorusReader *axl_torus_reader = new axlTorusReader;
    data = this->dataByReader(axl_torus_reader, node);
    delete axl_torus_reader;

    if(data)
        return data;

    axlCircleArcReader *axl_arc_reader = new axlCircleArcReader;
    data = this->dataByReader(axl_arc_reader, node);
    delete axl_arc_reader;

    if(data)
        return data;

    axlShapeReader *axl_shape_reader = new axlShapeReader;
    data = this->dataByReader(axl_shape_reader, node);
    delete axl_shape_reader;

    if(data)
        return data;

    axlEllipsoidReader *axl_ellipsoid_reader = new axlEllipsoidReader;
    data = this->dataByReader(axl_ellipsoid_reader, node);
    delete axl_ellipsoid_reader;

    if(data)
        return data;


    axlLineReader *axl_line_reader = new axlLineReader;
    data = this->dataByReader(axl_line_reader, node);
    delete axl_line_reader;

    if(data)
        return data;


    axlPlaneReader *axl_plane_reader = new axlPlaneReader;
    data = this->dataByReader(axl_plane_reader, node);
    delete axl_plane_reader;

    if(data)
        return data;

    axlPointReader *axl_point_reader = new axlPointReader;
    data = this->dataByReader(axl_point_reader, node);
    delete axl_point_reader;

    if(data)
        return data;

    // test for particular case
    //    axlPointSetReader *axl_pointSet_reader = new axlPointSetReader;
    //    data = this->dataByReader(axl_pointSet_reader, node);

    //    if(data) {
    //        return data;
    //    }
    //    else
    //        delete axl_pointSet_reader;

    axlSphereReader *axl_sphere_reader = new axlSphereReader;
    data = this->dataByReader(axl_sphere_reader, node);

    delete axl_sphere_reader;

    if(data)
        return data;

    axlAbstractDataCompositeReader *axl_composite_reader = new axlAbstractDataCompositeReader;
    data = this->dataByReader(axl_composite_reader, node);
    delete axl_composite_reader;

    if(data)
        return data;

    axlDataDynamicReader *axl_dynamic_reader = new axlDataDynamicReader;
    data = this->dataByReader(axl_dynamic_reader, node);

    if(data){
        axlDataDynamic *axldata = dynamic_cast<axlDataDynamic *>(data);
        data = axl_dynamic_reader->readInputs(axldata, node, d->dataList);
        return data;
    }
    delete axl_dynamic_reader;

    axlMeshReader *axl_mesh_reader = new axlMeshReader;
    data = this->dataByReader(axl_mesh_reader, node);
    delete axl_mesh_reader;

    return data; //Mesh or NULL
}

axlAbstractData *axlReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
{
    if(!axl_reader)
        return NULL;

    if(!axl_reader->accept(node))
        return NULL;

    dtkWarn()<<"data accepted";

    axl_reader->dtkAbstractDataReader::read(d->filename);

    if(axlAbstractData *data = dynamic_cast<axlAbstractData*>(axl_reader->read(node)))
        return data;

    return NULL;
}


bool axlReader::importOFF(const QString& file)
{
    d->dataList.clear(); // make sur that the list is empty

    QFile filename(file);
    if (filename.open(QFile::ReadOnly))
    {
        QTextStream in(&filename);

        QString format = "";
        int vertexCount = 0;
        int faceCount = 0;
        int edgeCount = 0;
        bool intConvert = false;

        double vx = 0.0;
        double vy = 0.0;
        double vz = 0.0;

        QVector<int> currentFace;
        int currentFaceSize = 0;
        int currentFaceIndex = 0;

        format = in.readLine(75);

        if(format.startsWith("OFF") || format.startsWith("off") ||  format.startsWith("Off"))
        {
            axlMesh *mesh = new axlMesh;
            //format = in.skipWhiteSpace();

            // head reading
            while(!intConvert)
            {
                in.skipWhiteSpace();
                in >> format;// skip commentary
                vertexCount = format.toInt(&intConvert);
            }
            in.skipWhiteSpace();
            in >> faceCount;
            in.skipWhiteSpace();
            in >> edgeCount;

            // vertices reading

            for(int i = 0 ; i < vertexCount ; i++)
            {
                in.skipWhiteSpace();
                in >> vx;
                in.skipWhiteSpace();
                in >> vy;
                in.skipWhiteSpace();
                in >> vz;

                mesh->push_back_vertex(vx, vy, vz);
            }// vertices are read

            qDebug()<< "axlReader::importOFF"<< faceCount+edgeCount;
            // faces reading
            for(int i = 0 ; i < faceCount+edgeCount ; i++)
            {
                currentFace.clear();
                in.skipWhiteSpace();
                in >> currentFaceSize;

                if(currentFaceSize == 1){
                    for(int j = 0 ; j < 2 ; j++)
                    {
                        in.skipWhiteSpace();
                        in >> currentFaceIndex;
                        currentFace << currentFaceIndex;
                    }
                    // skip color information if necessary
                    in.readLine(75);
                    mesh->push_back_edge(currentFace.at(0), currentFace.at(1));

                }else{
                    // current face reading
                    for(int j = 0 ; j < currentFaceSize ; j++)
                    {
                        in.skipWhiteSpace();
                        in >> currentFaceIndex;
                        currentFace << currentFaceIndex;
                    }
                    // skip color information if necessary
                    in.readLine(75);
                    mesh->push_back_face(currentFace);
                }
            }// faces and edges are read

            d->dataList << mesh;


            //qDebug()<<"axlMeshReader::read"<< mesh->face_count()<<mesh->edge_count()<< mesh->vertex_count();
            if(mesh->face_count() != 0)
            {
                mesh->face_show() = true;
                mesh->edge_show() = false;
                mesh->vertex_show() = false;
            }
            if(mesh->edge_count() != 0)
            {
                //                mesh->face_show() = false;
                mesh->edge_show() = true;
                mesh->vertex_show() = false;
            }
            else if(mesh->vertex_count() != 0 )
            {
                mesh->face_show() = false;
                mesh->edge_show() = false;
                mesh->vertex_show() = true;
            }
            else
            {
                mesh->face_show() = false;
                mesh->edge_show() = false;
                mesh->vertex_show() = false;
            }
        }

    }

    //    qDebug()<<"nb element "<<d->dataList.size();

    emit dataSetInserted(d->dataList);


    return true;
}
