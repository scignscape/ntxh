/* axlClient.cpp ---
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


#include "axlClient.h"

#include <QApplication>
#include <QtNetwork/QLocalSocket>
#include <qjsonrpcservice.h>
#include <qjsonrpcservicereply.h>
#include <qjsonrpcsocket.h>
#include <QtDebug>
#include <QtGui>

#include <axlCore/axlAbstractData.h>

#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractData.h>
#include <axlCore/axlAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkPluginManager.h>
#include <axlCore/axlFactoryRegister.h>

#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractDataComposite.h>

axlClient::axlClient() {

    dtkPluginManager::instance()->initialize();
    axlFactoryRegister::initialized();

}

axlClient::~axlClient(){

    dtkPluginManager::instance()->uninitialize();

}


//! Send an object to the Axel view. The object sended must be an Axel object.
/*!
 *
 */
QString axlClient::sendData(axlAbstractData *data ){
    QString formerName = data->objectName();
    if(formerName.startsWith("axl")){
        formerName.remove(0,3);//remove axl
        QString newName;
        newName.append("client");//new namespace
        newName.append(formerName);
        data->setObjectName(newName);
    }
    QVariantList list = data->convertDataToQVariant();
    sendData(list);
    return data->objectName() + "was sent to the view";
}

//! Send an object to the Axel view. The object sended must be an Axel object.
/*!
 *
 */
QString axlClient::sendData(axlAbstractData &data ){
    QString formerName = data.objectName();
    if(formerName.startsWith("axl")){
        formerName.remove(0,3);//remove axl
        QString newName;
        newName.append("client");//new namespace
        newName.append(formerName);
        data.setObjectName(newName);
    }
    QVariantList list = data.convertDataToQVariant();
    sendData(list);
    return data.objectName() + "was sent to the view";
}


//!  Send an object to the Axel view defined with a QVariantList of all its properties. See convertDataToQVariant() in axlAbstractData class.
/*!
 *   Check your object properties are well defined in the QVariantlist input.
 */
void axlClient::sendData(const QVariantList &data ){
    if(data.isEmpty()){
    }else{
        QLocalSocket socket;
        socket.connectToServer("/tmp/axlService");
        if(!socket.waitForConnected()){
            qDebug() << "couldn't connect to local server: " << socket.errorString();
        }
        QEventLoop loop;
        QJsonRpcServiceSocket service(&socket);
        QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.sendData",data);
        //QObject::connect(replySent, SIGNAL(finished()), this, SLOT(processResponse()));
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        //return reply->response().result().toString();
    }
}



//! If the object with this name was modified in the Axel view, modify the object properties with the same name in the client app.
/*!
 *
 */
QVariantList axlClient::update(const QString& name) const{
    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if (!socket.waitForConnected()) {
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;

    QJsonRpcServiceSocket service(&socket);
    QVariant item =QVariant::fromValue(name);//data->convertDataToQVariant();
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.update",item);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QVariantList list;
    QJsonArray parameters = reply->response().result().toArray();
    for(int i = 0; i < parameters.size(); i++){
        QJsonValue value = parameters.at(i);
        list.append(value.toVariant());
    }
    return list;
}


//! Update the properties of the object in the client app part if its correspondent one was modified in the Axel view.
/*! If the object was deleted in Axel app, delete it.
 *
 */
QString axlClient::update(axlAbstractData *data){
    QString name = data->objectName();
    QVariantList res = update(name);
    if(res.isEmpty()){
        delete data;
        data = NULL;
        return name + " was deleted";
    }else{
        data->convertQVariantToData(res);
        return name + " was updated : "+ data->description();
    }
}

//! Update the properties of the object in the client app part if its correspondent one was modified in the Axel view.
/*! If the object was deleted in Axel app, delete it.
 *
 */
QString axlClient::update(axlAbstractData &data){
    QString name = data.objectName();
    QVariantList res = update(name);
    if(res.isEmpty()){
        //delete data;
        data = NULL;
        return name + " was deleted";
    }else{
        data.convertQVariantToData(res);
        return name + " was updated : "+ data.description();
    }
}


//! If an object of this name was first created in the Axel view, your application can get it.
/*!
 *
 */
axlAbstractData *axlClient::getData(const QString& name){
    QVariantList list;
    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if(!socket.waitForConnected()){
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;
    QJsonRpcServiceSocket service(&socket);
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.getData",QVariant::fromValue(name));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QJsonArray parameters = reply->response().result().toArray();
    for(int i = 0; i < parameters.size(); i++){
        QJsonValue value = parameters.at(i);
        list.append(value.toVariant());
    }
    if(!list.isEmpty()){
        axlAbstractData *data = dynamic_cast<axlAbstractData *>(dtkAbstractDataFactory::instance()->create(list.first().toString()));
        if(data){
            data->convertQVariantToData(list);
            //inspector.insert(name,list);
            return data;
        }else{
            return NULL;
        }

    }else{
        return NULL;
    }

}


//! If you want your object to be deleted in the Axel application, you should delete it with this function.
/*!
 *
 */
void axlClient::deleteData(axlAbstractData *data){
    QVariant name = QVariant::fromValue(data->objectName());
    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if(!socket.waitForConnected()){
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;
    QJsonRpcServiceSocket service(&socket);
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.deleteData",name);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    //    delete data;
    //    data = NULL;
}

//! If you want your object to be deleted in the Axel application, you should delete it with this function.
/*!
 *
 */
void axlClient::deleteData(axlAbstractData &data){
    QVariant name = QVariant::fromValue(data.objectName());
    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if(!socket.waitForConnected()){
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;
    QJsonRpcServiceSocket service(&socket);
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.deleteData",name);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}



//! If you modify an object in your application, the modification will be transmitted and displayed into Axel only using this function.
/*!
 *
 */
void axlClient::modifyData(axlAbstractData *data){
    QVariantList list;
    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if(!socket.waitForConnected()){
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;
    QJsonRpcServiceSocket service(&socket);
    list = data->convertDataToQVariant();
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.modifyData",list);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}

//! If you modify an object in your application, the modification will be transmitted and displayed into Axel only using this function.
/*!
 *
 */
void axlClient::modifyData(axlAbstractData &data){
    QVariantList list;
    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if(!socket.waitForConnected()){
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;
    QJsonRpcServiceSocket service(&socket);
    list = data.convertDataToQVariant();
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.modifyData",list);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}

//! Call a process registered in Axel app with the given name. Not necessary to be registered on the python app part.
/*! Run it into axel with the given input(s) and parameter(s). Return the output of the process.
 *
 */
axlAbstractData *axlClient::callProcess(const QString name, axlAbstractDataComposite *ins ,axlAbstractDataComposite *params) const{

    QVariantList list;
    list << QVariant::fromValue(name);
    //same method as for the dynamic data. We add the size of each description.
    QList<axlAbstractData *>inputs ;
    for(int i= 0; i < ins->count();i++){
        inputs.append(dynamic_cast<axlAbstractData *>(ins->get(i)));
    }
    foreach(axlAbstractData *input, inputs){
        QVariantList l = input->convertDataToQVariant();
        list << "input"<< QVariant::fromValue(l.size())  << l;
    }


    QList<axlAbstractData *>parameters;
    for(int i= 0; i < params->count();i++){
        inputs.append(dynamic_cast<axlAbstractData *>(params->get(i)));
    }
    foreach(axlAbstractData *param, parameters){
        QVariantList l = param->convertDataToQVariant();
        list <<"parameter"<< QVariant::fromValue(l.size()) << l;
    }


    QLocalSocket socket;
    socket.connectToServer("/tmp/axlService");
    if(!socket.waitForConnected()){
        qDebug() << "couldn't connect to local server: " << socket.errorString();
    }
    QEventLoop loop;
    QJsonRpcServiceSocket service(&socket);
    QJsonRpcServiceReply *reply = service.invokeRemoteMethod("axlService.callProcess",list);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    //get the output
    QVariantList listRes;
    QJsonArray response = reply->response().result().toArray();
    for(int i = 0; i < response.size(); i++){
        QJsonValue value = response.at(i);
        listRes.append(value.toVariant());
    }

    if(!listRes.isEmpty()){
        axlAbstractData *data = dynamic_cast<axlAbstractData *>(dtkAbstractDataFactory::instance()->create(listRes.first().toString()));
        if(data){
            data->convertQVariantToData(listRes);
            return data;
        }else{
            return NULL;
        }

    }else{
        return NULL;
    }

}

// /////////////////////////////////////////////////////////////////
// axlClient documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlClient
 *
 *  \brief Class axlClient defines an API for JSON-RPC clients.
 *
 *  Using an axlClient in another application enables to connect and send messages to the axlServer embedded in Axel application.
 *  That way your app can exchange data with Axel using JSon-RPC protocol. Data in Axel and in your application won't be the same, but each object in one application
 *  could have its correspondent one in the other application. Correspondent data have the same name in both applications.
 *
 */
