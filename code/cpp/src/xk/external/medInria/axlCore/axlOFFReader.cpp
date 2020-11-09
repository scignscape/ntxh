/* axlOFFReader.cpp ---
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

#include "axlOFFReader.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlAbstractDataConverter.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlOFFReader
// /////////////////////////////////////////////////////////////////

axlOFFReader::axlOFFReader(void)
{
    this->setObjectName(this->identifier());
}

axlOFFReader::~axlOFFReader(void)
{

}


//! Return the identifier "axlOFFReader".
/*!
 *
 */
QString axlOFFReader::identifier(void) const
{
    return "axlOFFReader";
}


//! Return a description of the reader.
/*!
 *
 */
QString axlOFFReader::description(void) const
{
    return "axlOFFReader";
}


//! Return the type of file that the reader is able to read : "OFF files (.OFF, .off)" .
/*!
 *
 */
QStringList axlOFFReader::handled(void) const
{
    return QStringList() << ".off" << "off document";
}


//! Register this reader type in the factory.
/*!
 *
 */
bool axlOFFReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlOFFReader", QStringList(), createaxlOFFReader);
}


//! Check that the file can be read by this type of reader.
/*!
 *
 */
bool axlOFFReader::canRead(const QString& file)
{
    QFile filename(file);
    if (filename.open(QFile::ReadOnly))
    {
        QTextStream in(&filename);

        QString format = "";

        QVector<int> currentFace;

        format = in.readLine(75);

        if(format.startsWith("OFF") || format.startsWith("off") ||  format.startsWith("Off")){
            return true;
        }

    }

    return false;
}

//! Read the file which is supposed to be of right type OFF and create a data.
/*! Return true if the data is correctly created, else return false.
 *
 */
bool axlOFFReader::read(const QString& file)
{
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


            if(mesh->face_count() != 0)
            {
                mesh->vertex_show() = true;
                mesh->edge_show() = true;
                if(mesh->edge_show())
                    mesh->face_show() = true;

            }
            else if(mesh->edge_count() != 0)
            {
                mesh->face_show() = false;
                mesh->edge_show() = true;
                mesh->vertex_show() = true;
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
            this->setData(mesh);
            return true;
        }

    }

    //    qDebug()<<"nb element "<<d->dataList.size();

    // emit dataSetInserted(d->dataList);


    return false;

}

dtkAbstractDataReader *createaxlOFFReader(void)
{
    return new axlOFFReader;
}
