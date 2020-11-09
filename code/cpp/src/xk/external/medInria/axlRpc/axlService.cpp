/* axlService.cpp ---
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


#include "axlService.h"
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractData.h>
#include <axlCore/axlAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <axlCore/axlFactoryRegister.h>
#include <dtkCoreSupport/dtkPluginManager.h>


#include <QTime>
#include <qjsonrpcservice.h>
#include <qjsonrpclocalserver.h>
#include <QtDebug>
#include <QtNetwork/QLocalServer>
#include <iostream>
#include <QObject>

#include <axlCore/axlAbstractView.h>
#include <axlGui/axlInspector.h>

#include <axlCore/axlDouble.h>
#include <axlCore/axlInteger.h>

axlService::axlService(QObject *parent) : QJsonRpcService(parent) {
    qRegisterMetaType<axlAbstractData>();
    view = NULL;
    inspector = NULL;
    dtkPluginManager::instance()->initialize();
    axlFactoryRegister::initialized();
}

axlService::~axlService() {
}

QString axlService::sendData(const QVariantList &list ){
    QVariant id = list.first();
    QString dataDescription;
    axlAbstractData *dataToInsert = dynamic_cast<axlAbstractData *>(dtkAbstractDataFactory::instance()->create(id.toString()));
    if(dataToInsert){
        int isConverted = dataToInsert->convertQVariantToData(list);
        if(isConverted){
            view->add(dataToInsert);
            dataDescription.append("Data was saved : ");
            dataDescription.append(dataToInsert->description());
        }else{
            dataDescription.append("Cannot save data.");
        }
    }else{
        dataDescription.append("Unavailable data type.");
    }
    return dataDescription;
}

QString axlService::echo(const QVariant &text ){
    qDebug() << Q_FUNC_INFO;
    return text.toString();
}

// update a value of a specific data, that already exist in both application
QVariantList axlService::update(const QVariant &id) const{

    QVariantList newList;
    QList<dtkAbstractData *> data = inspector->dataSet();
    QString name = id.toString();
    int indice = 0;
    bool found = false;
    while(indice < data.size() && !found){
        found = (data.at(indice)->objectName()==name);
        if(found){
            newList = dynamic_cast<axlAbstractData *>(data.at(indice))->convertDataToQVariant();
        }else{
            indice++;
        }
    }
    return newList;
}


//read a data saved represented by the identifier id.
QVariantList axlService::getData(const QVariant& id) const{

    QVariantList newList;
    QList<dtkAbstractData *> data = inspector->dataSet();
    QString name = id.toString();
    int indice = 0;
    bool found = false;
    while(indice < data.size() && !found){
        found = (data.at(indice)->objectName()==name);
        if(found){
            newList = dynamic_cast<axlAbstractData *>(data.at(indice))->convertDataToQVariant();
        }else{
            indice++;
        }
    }
    return newList;
}

void axlService::deleteData(const QVariant& id){
    QVariantList newList;
    QList<dtkAbstractData *> data = inspector->dataSet();
    QString name = id.toString();
    int indice = 0;
    bool found = false;
    while(indice < data.size() && !found){
        found = (data.at(indice)->objectName()==name);
        if(found){
            //view->removeData(data.at(indice));
            QList<dtkAbstractData *> dataToRemove;
            dataToRemove << data.at(indice);
            view->ondataSetRemoved(dataToRemove);
            inspector->removeData(data.at(indice));
        }else{
            indice++;
        }
    }
}

void axlService::modifyData(const QVariantList& list){
    QList<dtkAbstractData *> data = inspector->dataSet();
    QString name = list.last().toString();
    int indice = 0;
    bool found = false;
    while(indice < data.size() && !found){
        found = (data.at(indice)->objectName()==name);
        if(found){
            dynamic_cast<axlAbstractData *>(data.at(indice))->convertQVariantToData(list);
            data.replace(indice,data.at(indice));
            view->dataChangedByGeometry(data.at(indice));
        }else{
            indice++;
        }
    }
}

QVariantList axlService::callProcess(const QVariantList list) const{
    QString nameProcess = list.first().toString();
    axlAbstractProcess *process = dynamic_cast<axlAbstractProcess *>(dtkAbstractProcessFactory::instance()->create(nameProcess));
    //read data and setInput or setParameter
    int currentIndice = 1;
    QVariantList list1;
    QList<axlAbstractData *>obj;
    int numData = 0;
    int channelinput = 0;
    int channelparameterInt = 0;
    int channelparameterDouble = 0;
    int nbInput = list.count(QVariant::fromValue(QString("input")));
    int nbParamInt = list.count(QVariant::fromValue(QString("axlInteger")));
    int nbParamDouble = list.count(QVariant::fromValue(QString("axlDouble")));;
    while(currentIndice < (list.size()-1)){
        QString what = list.at(currentIndice).toString();
        int count = list.at(currentIndice+1).toInt();
        QString id = list.at(currentIndice+2).toString();
        obj.append(dynamic_cast<axlAbstractData *>(dtkAbstractDataFactory::instance()->create(id)));
        for(int i = 0;i < count;i++){
            list1.append(list.at(currentIndice+2+i));
        }
        obj.at(numData)->convertQVariantToData(list1);

        list1.clear();
        //how to do with channel ?
        if(what=="input"){
            if(nbInput > 1){
                process->setInput(obj.at(numData),channelinput);
                channelinput++;
            }else{
                process->setInput(obj.at(numData));
            }
        }else if(what=="parameter"){
            if(dynamic_cast<axlDouble *>(obj.at(numData))){
                if(nbParamDouble >1){
                    process->setParameter(dynamic_cast<axlDouble *>(obj.at(numData))->value(), channelparameterDouble);
                    channelparameterDouble++;
                }else{
                    process->setParameter(dynamic_cast<axlDouble *>(obj.at(numData))->value());
                }
            }else{
                if(nbParamInt >1){
                    process->setParameter(dynamic_cast<axlInteger *>(obj.at(numData))->value(), channelparameterInt);
                    channelparameterInt++;
                }else{
                    process->setParameter(dynamic_cast<axlInteger *>(obj.at(numData))->value());
                }
            }
        }
        currentIndice = currentIndice+count+2;
        numData++;
    }
    //run process
    QVariantList result;
    int res = process->update();
    if(res){
        result = dynamic_cast<axlAbstractData *>(process->output())->convertDataToQVariant();
    }
    obj.clear();
    return result;
}

void axlService::setView(axlAbstractView *w){
    view = w;
}

void axlService::setInspector(axlInspector *insp){
    inspector = insp;
}
