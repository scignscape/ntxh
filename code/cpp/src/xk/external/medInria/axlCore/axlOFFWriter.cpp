/* axlOFFWriter.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlOFFWriter.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include<axlCore/axlAbstractDataConverter.h>
#include<axlCore/axlMesh.h>
#include<axlCore/axlPoint.h>
#include<axlCore/axlPointConverter.h>

#include <axlCore/axlAbstractDataComposite.h>

#include <QtWidgets>

// /////////////////////////////////////////////////////////////////
// axlOFFWriter
// /////////////////////////////////////////////////////////////////

axlOFFWriter::axlOFFWriter(void) : dtkAbstractDataWriter()
{
    this->setObjectName(this->description());

}

axlOFFWriter::~axlOFFWriter(void)
{

}



//! Return the identifier "axlOFFWriter".
/*!
 *
 */
QString axlOFFWriter::identifier(void) const
{
    return "axlOFFWriter";
}


//! Return a description of the writer.
/*!
 *
 */
QString axlOFFWriter::description(void) const
{
    return "axlOFFWriter";
}


//! Return the appropriate extension of files (.off) written by this writer.
/*!
 *
 */
QStringList axlOFFWriter::handled(void) const
{
    return QStringList() <<".off" << "off document";
}



//! Register the writer in the factory.
/*!
 *
 */
bool axlOFFWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlOFFWriter", QStringList(), createaxlOFFWriter);
}


//! Check if the writer can write the file.
/*! file must have extension .off
 *
 */
bool axlOFFWriter::canWrite(const QString& file){
    return (file.endsWith(".off")); //Qt::CaseInsensitive(
}


//! Write the .off file.
/*!
 *
 */
bool axlOFFWriter::write(const QString& file)
{
    QFile filename(file);
    QTextStream os( &filename);

    if( !filename.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Axel","Error of writing","&Ok",0) ;
        return false;
    }

    // construct the axlMesh;
    axlMesh *mesh = new axlMesh;

    //dtkAbstractData *data = d->dataList.at(i);
    axlAbstractDataComposite *data = dynamic_cast<axlAbstractDataComposite *>(this->data());
    int numberElement = data->count();

    for(int i = 0 ; i < numberElement ; i++)
    {
        bool founded = false;

        axlMesh *currentMesh = NULL;


        // test for all converters registered in the factory

        foreach(QString converter, dtkAbstractDataFactory::instance()->converters())
        {
            if(!founded)
            {
                axlAbstractDataConverter *axl_converter = dynamic_cast<axlAbstractDataConverter *>(dtkAbstractDataFactory::instance()->converter(converter));
                axl_converter->setData(data->get(i));
                currentMesh = axl_converter->toMesh();
                if(currentMesh)
                    founded = true;
            }

        }


        //        //Atomics data writers

        //        if(!founded)
        //        {
        //            axlPointConverter *axl_converter = new axlPointConverter;
        //            axl_converter->setData(data);
        //            currentMesh = axl_converter->toMesh();
        //            if(currentMesh)
        //                founded = true;
        //        }

        if(!founded)
        {
            if ( (currentMesh = dynamic_cast<axlMesh*>(data->get(i))) ) {
                founded = true;
            }
        }

        if(currentMesh)
            mesh->append(currentMesh);


        if(!founded)
            return false;
    }

    if(mesh->vertex_count() == 0){
        return false;
    }

    os << "OFF\n";
    os << "#\n";
    os << "# "<< file << "\n";
    os << "# This file was created with axelModeler.\n";
    os << "# Go to http://axl.inria.fr for more information.\n";
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



dtkAbstractDataWriter *createaxlOFFWriter(void)
{
    return new axlOFFWriter;
}
