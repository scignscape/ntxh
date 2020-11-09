/* axlToMesh.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Comment:
 */

/* Change log:
 *
 */
#include "axlToMesh.h"
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractDataConverter.h>
#include <axlCore/axlMesh.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>

//////////////////////////////////////////////////////////
////axlToMeshPrivate
//////////////////////////////////////////////////////////

class axlToMeshPrivate{

public :
    //inputs
    QVector<axlAbstractData *> input;
    //output
    QVector<axlAbstractData *> output;
};

//////////////////////////////////////////////////////////
//// axlToMeshPrivate
//////////////////////////////////////////////////////////
axlToMesh::axlToMesh(QObject *parent) : axlAbstractProcess(), d(new axlToMeshPrivate){

}

axlToMesh::~axlToMesh(void){
    delete d;
    d= NULL;
}


axlAbstractData * axlToMesh::getInput(int channel) const{
    if(channel < d->input.size())
        return d->input.at(channel);
    else {
        qDebug()<< "You are trying to acces an input that is not exit";
        return nullptr;
    }
}

dtkAbstractData *axlToMesh::output(int channel){
    if(channel < d->output.size()){
        return d->output.at(channel);
    }
    else
        qDebug()<< "You are trying to acces an output that is not exit";
    return NULL;
}

dtkAbstractData *axlToMesh::output(void){

        return d->output.at(0);
}


void axlToMesh::setInput(dtkAbstractData *newData, int channel)
{
//    qDebug()<<"-- set input"<<channel;

    // TO DO : Be careful we don't have choice their for the resize ... we need more method on dtkAbstractProcess
//    if(channel >= d->input.size())
//        d->input.resize(channel + 1);


    if(axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(newData)){
//        if(channel < d->input.size()) {
//            d->input[channel] = axlData;
//        } else {
            d->input.push_back(axlData);
//        }
    }
}

//void axlToMesh::setInput(dtkAbstractData *newData)
//{
//    if(axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(newData)){
//        d->input.push_back(axlData);
//    }
//    else
//        qDebug()<< "You are trying to set an input that is not exit";

//}


int axlToMesh::channelCount(void){

    return d->output.size();
}


int axlToMesh::update(void)
{
    //TO DO: Because setInput method is not perfect, We cannot assert that all inputs are correctly set.
//    qDebug() << "-- axlToMesh::update" <<d->input.size();
    for(int i = 0 ; i < d->input.size() ; i++)
    {
        axlAbstractData *data = d->input.at(i);
//        qDebug() << Q_FUNC_INFO << "data input type  "<< i << data->identifier()+"Converter";
        axlAbstractDataConverter *converter = dynamic_cast<axlAbstractDataConverter *>(dtkAbstractDataFactory::instance()->converter(data->identifier()+"Converter"));

        if(converter)
        {
//            qDebug() << Q_FUNC_INFO << "converter type "<< converter->identifier();
            converter->setData(data);
            axlMesh *currentMesh = converter->toMesh();
            d->output.push_back(currentMesh);
            dtkWarn()<<"Mesh"<< currentMesh->vertex_count() << currentMesh->edge_count() << currentMesh->face_count();
        }
        else{
            qDebug()<< "Cannot find converter for : "<< d->input[i]->identifier();
            return 0;
        }
    }

    dtkWarn()<<"axlConvertToMesh::update :" <<d->output.size() << "data has been converted sucessfully";

    foreach(axlAbstractData *data, d->output) {
        emit dataInserted(data);
    }


    return 1;
}

QString axlToMesh::description(void) const{
    return "Convert all Input selected Data to axlMesh. Only data with converter will be converted";
}


QString axlToMesh::identifier(void) const{
    return "axlToMesh";
}

dtkAbstractProcess *createaxlToMeshProcess(void){
    return new axlToMesh;
}

// /////////////////////////////////////////////////////////////////
// axlToMesh documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlToMesh
 *
 *  \brief axlToMesh is a process that allow you to convert data to mesh.
 *
 *  Convert all Input selected Data to axlMesh. Only data with converter will be converted.
 *
 *  \endcode
 */
