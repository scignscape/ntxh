/* axlServer.cpp ---
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


#include "axlServer.h"
#include <QTime>
#include <qjsonrpcservice.h>
#include <qjsonrpclocalserver.h>
#include <QtDebug>
#include <QLocalServer>
#include <iostream>
#include "axlService.h"
#include <QFile>

axlServer::axlServer(){

    if (QFile::exists("/tmp/axlService")) {
        if (!QFile::remove("/tmp/axlService")) {
            qDebug() << "couldn't delete temporary service";
        }
    }

    rpcServer = new QJsonRpcLocalServer();
    service = new axlService();
    rpcServer->addService(service);
    if (!rpcServer->listen("/tmp/axlService")) {
        qDebug() << "can't start local server: " << rpcServer->errorString();
    }else {
        //std::cout << "Listening..." << std::endl;
        qDebug() << "Listening..." ;
    }
}

axlServer::~axlServer(){
    delete service;
    delete rpcServer;
}

void axlServer::setView(axlAbstractView *v){
    service->setView(v);
}


void axlServer::setInspector(axlInspector *insp){
    service->setInspector(insp);

}

