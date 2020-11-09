/* axlWriter.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 12:46:11 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 11:00:32 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 14
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlWriter.h"

#include "axlAbstractCurveBSpline.h"
#include "axlAbstractDataComposite.h"
#include "axlAbstractSurfaceBSpline.h"

#include "axlAbstractDataCompositeWriter.h"

#include "axlAbstractDataConverter.h"

#include "axlConeWriter.h"
#include "axlCylinderWriter.h"
#include "axlCylinderParametricWriter.h"
#include "axlCircleArcWriter.h"
#include "axlEllipsoidWriter.h"
#include "axlLineWriter.h"
#include "axlPlaneWriter.h"
#include "axlPlaneParametricWriter.h"
#include "axlTorusWriter.h"
#include "axlTorusParametricWriter.h"
#include "axlShapeWriter.h"

#include "axlPoint.h"
#include "axlPointConverter.h"
#include "axlPointWriter.h"

#include "axlSphereWriter.h"

#include "axlMesh.h"
#include "axlMeshWriter.h"

#include "axlDataDynamic.h"
#include "axlDataDynamicWriter.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include <QDomDocument>
#include <QString>

#include <QtWidgets>

// /////////////////////////////////////////////////////////////////
// axlWriterPrivate
// /////////////////////////////////////////////////////////////////

class axlWriterPrivate
{
public:
    QList<dtkAbstractData *>  dataList;
    QDomDocument *domdocument;
    QList<QDomElement> *elements ;

    QDomElement *sceneView ;
};

// /////////////////////////////////////////////////////////////////
// axlWriter
// /////////////////////////////////////////////////////////////////

axlWriter::axlWriter(void) : QObject(), d(new axlWriterPrivate)
{
    d->domdocument = new QDomDocument() ;
    d->elements = new QList<QDomElement>;

    d->sceneView = NULL;
}

axlWriter::~axlWriter(void)
{
    delete d->elements;

    delete d->domdocument;

    delete d;

    d = NULL;
}

void axlWriter::setDataToWrite(QList<dtkAbstractData *> dataSet)
{
    d->dataList = dataSet;
}

void axlWriter::addDataToWrite(dtkAbstractData * data)
{
    d->dataList.push_back(data);
}

int axlWriter::update(void)
{
    emit dataSetInserted(d->dataList);

    return 1;
}

//void axlWriter::setSceneToWrite(axlAbstractView *sceneView)
void axlWriter::setSceneToWrite(QDomElement sceneView)
{
    d->sceneView = &sceneView;
}

bool axlWriter::write(const QString& filename)
{
    QFile file(filename);

    if( !file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Axel","Error of reading","&Ok",0) ;
        return false;
    }

    // run the QDomDocument
    foreach(dtkAbstractData *data, d->dataList) {

        bool founded = false;

        // test for all reader registered in the factory
        foreach(QString writer, dtkAbstractDataFactory::instance()->writers()) {


            axlAbstractDataWriter *axl_writer = dynamic_cast<axlAbstractDataWriter *>(dtkAbstractDataFactory::instance()->writer(writer));
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
//                axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data);
//                if (!axlData->fields().isEmpty()){
//                    qDebug() << "axlWriter::write general fields";
//                    axlAbstractDataWriter *axl_writer_field = dynamic_cast<axlAbstractDataWriter *>(dtkAbstractDataFactory::instance()->writer("axlFieldSpatialWriter"));
//                    foreach(axlAbstractField *field , axlData->fields()){
//                        //dtkAbstractData *field2= dtkAbstractDataFactory::instance()->create("axlProcessSpatialZCoordinates");
//                        QDomElement element = this->elementByWriter(axl_writer_field, reinterpret_cast<dtkAbstractData*>(field));
//                        d->elements->append(element);

//                        delete axl_writer_field;
//                    }
//                }
                founded = true;
            }

            delete axl_writer;

        }

        //Atomics data writer

        if(!founded)
        {
            axlAbstractDataCompositeWriter *axl_writer = new axlAbstractDataCompositeWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlConeWriter *axl_writer = new axlConeWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                //                qDebug() << "axlWriter::write isCone";
                //                axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data);
                //                if (!axlData->fields().isEmpty()){
                //                    qDebug() << "axlWriter::write fields";
                //                    axlFieldSpatialWriter *axl_writer = new axlFieldSpatialWriter;
                //                    foreach(axlAbstractField *field , axlData->fields()){
                //                        QDomElement element = this->elementByWriter(axl_writer, field);
                //                        d->elements->append(element);
                //                    }
                //}
                founded = true;
            }

            delete axl_writer;
        }

        if(!founded)
        {
            axlCylinderWriter *axl_writer = new axlCylinderWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }
        }

        if(!founded)
        {
            axlTorusWriter *axl_writer = new axlTorusWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }
        }

        if(!founded)
        {
            axlCircleArcWriter *axl_writer = new axlCircleArcWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }
        }

        if(!founded)
        {
            axlEllipsoidWriter *axl_writer = new axlEllipsoidWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;
        }


        if(!founded)
        {
            axlLineWriter *axl_writer = new axlLineWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlPlaneWriter *axl_writer = new axlPlaneWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlPlaneParametricWriter *axl_writer = new axlPlaneParametricWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlPointWriter *axl_writer = new axlPointWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlMeshWriter *axl_writer = new axlMeshWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }
        }


        if(!founded)
        {
            axlSphereWriter *axl_writer = new axlSphereWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlShapeWriter *axl_writer = new axlShapeWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

        if(!founded)
        {
            axlDataDynamicWriter *axl_writer = new axlDataDynamicWriter;
            QDomElement element = this->elementByWriter(axl_writer, data);
            d->elements->append(element);

            if(element.hasChildNodes()) {
                d->elements->append(element);
                founded = true;
            }

            delete axl_writer;

        }

    }

    QDomElement axl = d->domdocument->createElement("axl");
    d->domdocument->appendChild(axl);

    foreach(QDomElement e, *(d->elements)){
        axl.appendChild(e) ;
    }

    // when we want to write the scene view
    if (d->sceneView)
        axl.appendChild(*(d->sceneView));

    QTextStream ts( &file );
    ts << d->domdocument->toString();

    file.close();


    return true;
}

bool axlWriter::exportOFF(const QString& file)
{
    QFile filename(file);
    QTextStream os( &filename );

    if( !filename.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Axel","Error of reading","&Ok",0) ;
        return false;
    }

    // construct the axlMesh;
    axlMesh *mesh = new axlMesh;

    for(int i = 0 ; i < d->dataList.size() ; i++)
    {
        // bool founded = false;

        axlMesh *currentMesh = NULL;

        bool founded = false;

        // test for all converters registered in the factory

        foreach(QString converter, dtkAbstractDataFactory::instance()->converters())
        {
            if(!founded)
            {
                axlAbstractDataConverter *axl_converter = dynamic_cast<axlAbstractDataConverter *>(dtkAbstractDataFactory::instance()->converter(converter));
                axl_converter->setData(d->dataList.at(i));
                currentMesh = axl_converter->toMesh();
                if(currentMesh)
                    founded = true;
            }

        }


        //Atomics data writers

        if(!founded)
        {
            axlPointConverter *axl_converter = new axlPointConverter;
            axl_converter->setData(d->dataList.at(i));
            currentMesh = axl_converter->toMesh();
            if(currentMesh)
                founded = true;
        }

        if(!founded)
        {
            if ((currentMesh = dynamic_cast<axlMesh*>(d->dataList.at(i))))
                founded = true;
        }

        if(currentMesh)
            mesh->append(currentMesh);

        if(!founded)
            return false;
    }

    if(mesh->vertex_count() == 0)
        return false;

    os << "OFF\n";
    os << "#\n";
    os << "# "<< file << "\n";
    os << "# This file was created with axelModeler.\n";
    os << "# Go to https://axl.inria.fr for more information.\n";
    os << "#\n";

    //write of the mesh

    os << mesh->vertex_count() << " " << mesh->face_count() << " "<< mesh->edge_count()<< "\n";

    for(int i = 0 ; i < mesh->vertex_count() ; i++)
    {
        axlPoint p;
        mesh->vertex(i, &p);
        os << p.x() << " " << p.y() << " " << p.z()<< "\n";
    }

    for(int i = 0 ; i < mesh->face_count() ; i++)
    {
        QVector<int> face = mesh->face(i);

        os << face.size();
        for(int j = 0 ; j < face.size(); j++)
        {
            os << " " << face.at(j);
        }

        os << "\n";
    }

//    for(int i = 0 ; i < mesh->edge_count() ; i++)
//    {
//        axlMesh::Edge edge = mesh->edge(i);
//        os << 1 << " " << edge.first << " " << edge.second << "\n";
//    }

    filename.close();

    delete mesh;

    return true;
}

bool axlWriter::exportTo_OFF(QString& filename)
{
    QFile file(filename);
    int num_spline = 0;
    int number_SurfaceBSpline;

    QTextStream os( &file );

    if( !file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Axel","Error of reading","&Ok",0) ;
        return false;
    }

    number_SurfaceBSpline = countAxlAbstractDataSurfaceBSpline();
    // surface number
    os << number_SurfaceBSpline << "\n";

    // run the QDomDocument
    foreach(dtkAbstractData *data, d->dataList)
    {

        if(axlAbstractSurfaceBSpline *surface = dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        {
            double start_u = surface->startParam_u();
            double start_v = surface->startParam_v();
            double end_u = surface->endParam_u();
            double end_v = surface->endParam_v();
            double paramCourant_u = start_u;
            double paramCourant_v = start_v;

            axlPoint pointCourant;

            int n_u = surface->numSamples_u();// need to be superior than 1
            int n_v = surface->numSamples_v();

            // point number triangle number
            os << (n_u) * (n_v) << " " << (n_u - 1)*(n_v - 1) * 2 << "\n";

            double interval_u = (double)(end_u - start_u) / (n_u - 1);
            double interval_v = (double)(end_v - start_v) / (n_v - 1);

            // writte point x y z u v num_spline
            for(int j = 0; j < n_v - 1; j++)
            {
                for(int i = 0; i < n_u - 1; i++)
                {
                    pointCourant = surface->eval(paramCourant_u, paramCourant_v);

                    os << pointCourant.x() << " " << pointCourant.y() << " " << pointCourant.z() << " ";
                    os << paramCourant_u << " " << paramCourant_v << " ";
                    os << num_spline << "\n";

                    paramCourant_u += interval_u;
                }

                pointCourant = surface->eval(end_u, paramCourant_v);

                os << pointCourant.x() << " " << pointCourant.y() << " " << pointCourant.z() << " ";
                os << paramCourant_u << " " << paramCourant_v << " ";
                os << num_spline << "\n";

                paramCourant_u = start_u;
                paramCourant_v += interval_v;
            }

            for(int i = 0; i < n_u - 1; i++)
            {
                pointCourant=surface->eval(paramCourant_u, end_v);

                os << pointCourant.x() << " " << pointCourant.y() << " " << pointCourant.z() << " ";
                os << paramCourant_u << " " << paramCourant_v << " ";
                os << num_spline << "\n";

                paramCourant_u += interval_u;
            }

            // writte triangle connections
            int ind1 = 0;
            int ind2 = 0;

            for(int j = 0; j < n_v - 1; j++)
            {
                for(int i= 0; i <n_u - 1; i++)
                {
                    ind1 =  j * n_u + i;
                    ind2 = ind1 + n_u;

                    os << ind1 << " " << ind1 + 1 << " " << ind2 << "\n";

                    os << ind1 + 1 << " " << ind2 << " " << ind2 + 1 << "\n";
                }
            }
            num_spline ++;
        }
    }
    file.close();
    return 1;
}

int axlWriter::countAxlAbstractDataSurfaceBSpline()
{
    int num_SurfaceBSpline = 0;

    foreach(dtkAbstractData *data, d->dataList)
    {
        if(dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        {
            ++ num_SurfaceBSpline;
        }
    }

    return num_SurfaceBSpline;
}

QDomElement axlWriter::setComposite(axlAbstractDataComposite *composite)
{
    QDomElement compositeElement = d->domdocument->createElement("composite");
    compositeElement.setAttribute("name",composite->name());

    QColor qcolor = composite->color();
    QString color ;
    QTextStream(&color) << QString::number(qcolor.red()) << " "
                        << QString::number(qcolor.green()) << " "
                        << QString::number(qcolor.blue()) ;
    compositeElement.setAttribute("color", color);
    QString shader = composite->shader();
    QFileInfo shaderFileInfo(shader);
    compositeElement.setAttribute("shader", shaderFileInfo.fileName());

    for(int i = 0; i < composite->count(); i ++)
    {
        if(axlAbstractCurveBSpline *curve = dynamic_cast<axlAbstractCurveBSpline *>(composite->get(i)))
        {
            //compositeElement.appendChild(setBSplineCurve(curve));

            Q_UNUSED(curve);
        }
        else if(axlAbstractSurfaceBSpline *surface = dynamic_cast<axlAbstractSurfaceBSpline *>(composite->get(i)))
        {
            //compositeElement.appendChild(setBSplineSurface(surface));

            Q_UNUSED(surface);
        }
        else if(axlAbstractDataComposite *dataComposite = dynamic_cast<axlAbstractDataComposite *>(composite->get(i)))
        {
            compositeElement.appendChild(setComposite(dataComposite));
        }
    }

    return compositeElement;
}


QDomElement axlWriter::elementByWriter(axlAbstractDataWriter *axl_writer, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;


    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(d->domdocument, data);

    return element;
}


QString axlWriter::description(void) const
{
    return "axlWriter";
}
