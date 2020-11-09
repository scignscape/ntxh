/* axlDataDynamic.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C)
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlDataDynamic.h"
#include <axlCore/axlAbstractProcess.h>
#include <axlCore/axlCone.h>
#include <axlCore/axlCylinder.h>
#include <axlCore/axlCircleArc.h>
#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlPlane.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlSphere.h>
#include <axlCore/axlTorus.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractCurveBSpline.h>
#include <axlCore/axlAbstractSurfaceBSpline.h>
#include <axlCore/axlAbstractVolumeBSpline.h>

#include <dtkCoreSupport/dtkGlobal.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <QtGui>


class axlDataDynamicPrivate
{
public:
    QList<axlAbstractData *> inputs;
    QList<axlAbstractData *> parameters;
    axlAbstractProcess *process;
    QList<axlAbstractData*> output;
    int nbUp;
    //determine if it is a dynamic object or just to remind a computation.
    axlDataDynamic::Type type;

};

axlDataDynamic::axlDataDynamic(void) : axlAbstractDataComposite(), d(new axlDataDynamicPrivate)
{
    this->setObjectName(this->identifier());
    d->nbUp = 0;
    d->process = NULL;
    d->type = axlDataDynamic::Dynamic;

}

axlDataDynamic::~axlDataDynamic(void)
{

    if(d->process){
        delete d->process;
        d->process = NULL;
    }

    for(int k = 0; k < d->inputs.size();k++){
        disconnect(d->inputs.at(k), SIGNAL(modifiedGeometry()),this, SLOT(update()));
        if(!dynamic_cast<axlDouble *>(d->inputs.at(k)) && !dynamic_cast<axlInteger *>(d->inputs.at(k))){
            disconnect(d->inputs.at(k), SIGNAL(destroyed()),this, SLOT(onRemoved()));
        }else{
            delete d->inputs.at(k);
        }
    }
    d->inputs.clear();
    d->parameters.clear();


    if(!d->output.isEmpty()){
        for(int i = 0; i < d->output.size();i++){
            if(d->output.at(i)){
                delete d->output.at(i);
            }
        }
        d->output.clear();
    }

    delete d;
    d = NULL;

}

//! This slot is called whenever one of the dynamic object input is deleted.
/*!
 *
 */
void axlDataDynamic::onRemoved(void){
    emit destroyed(this);
    delete this;

}

//! Return the type : dynamic if it is a dynamic object or static if it is just a computation node.
/*! By default type is dynamic.
 *
 */
axlDataDynamic::Type axlDataDynamic::getType(void){
    return d->type;

}

//! Sets the type of the object. Type could be dynamic or static.
/*!
 *
 */
void axlDataDynamic::setType(axlDataDynamic::Type type){
    d->type = type;

}

//! Return how many times the geometry of the dynamic object has been updated.
/*!
 *
 */
int axlDataDynamic::numberOfUpdate(void){
    return d->nbUp;

}

//! Return the channel-th output of the list.
/*!
 *
 */
axlAbstractData* axlDataDynamic::outputs(int channel){
    if (d->output.size() > channel) {
        return d->output.at(channel);
    } else {
        qDebug() << Q_FUNC_INFO << "no channel-th output available";
        return NULL;
    }
}

//! Return the first output of the list.
/*!
 *
 */
axlAbstractData* axlDataDynamic::outputs(void){
    if (d->output.size() > 0) {
        return d->output.at(0);
    } else {
        qDebug() << Q_FUNC_INFO << "no output computed" << d->process->identifier();
        return NULL;
    }

}


//! Clear input list.
/*!
 *
 */
void axlDataDynamic::clearInputs(void){
    d->inputs.clear();
}

//! Check whether the output of the process is a different object that one of its inputs.
/*!
 *
 */
bool axlDataDynamic::isNotInputProcess(dtkAbstractData * data){
    if(dynamic_cast<axlAbstractData *>(data)){
        return !(d->inputs.contains(dynamic_cast<axlAbstractData *>(data)));
    }

    return true;
}

//! Check whether the data is an output of the process.
/*!
 *
 */
bool axlDataDynamic::isNotOutputProcess(dtkAbstractData * data){
    if(dynamic_cast<axlAbstractData *>(data)){
        return !(d->output.contains(dynamic_cast<axlAbstractData *>(data)));
    }

    return true;
}


//! Return input list;
/*!
 *
 */
QList<axlAbstractData *> axlDataDynamic::inputs(void){
    return d->inputs;
}

//! Return the process.
/*!
 *
 */
axlAbstractProcess * axlDataDynamic::process(void){
    return d->process;
}

//! Add input;
/*!
 *
 */
void axlDataDynamic::setInput(dtkAbstractData *data, int channel)
{
    if (axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(data)) {
        d->inputs.append(axlData);
//        qDebug() << "---------------------";
//        qDebug() << "data :" << &data;
//        for(int i = 0; i < d->inputs.count(); i++)
//            qDebug() << &(d->inputs.at(i));

        if (d->type == axlDataDynamic::Dynamic) {
            connect(axlData, SIGNAL(modifiedGeometry()), this, SLOT(update()));
        }
        if (!dynamic_cast<axlDouble *>(data) && !dynamic_cast<axlInteger *>(data)) {
            // connect(this, SIGNAL(modifiedGeometry()), axlData, SIGNAL(modifiedGeometry()));
            connect(axlData, SIGNAL(destroyed()), this, SLOT(onRemoved()));
        }
    }
}

//! Set parameter
/*!
 *
 */
void axlDataDynamic::setParameter(int value){
    if(d->process!= NULL)
        d->process->setParameter(value);
    else
        dtkWarn()<<"axlDataDynamic: process NULL";
}

//! Set parameter
/*!
 *
 */
void axlDataDynamic::setParameter(int value, int channel){
    if(d->process!= NULL)
        d->process->setParameter(value,channel);
    else
        dtkWarn()<<"axlDataDynamic: process NULL";
}

//! Set parameter
/*!
 *
 */
void axlDataDynamic::setParameter(double value){
    if(d->process!= NULL)
        d->process->setParameter(value);
    else
        dtkWarn()<<"axlDataDynamic: process NULL";
}

//! Set parameter
/*!
 *
 */
void axlDataDynamic::setParameter(double value, int channel){
    if(d->process!= NULL)
        d->process->setParameter(value,channel);
    else
        dtkWarn()<<"axlDataDynamic: process NULL";
}

//! Create the dynamic object process only with the name of its latter.
/*!
 *
 */
int axlDataDynamic::setProcess(QString processName){
    d->process = dynamic_cast<axlAbstractProcess *>(dtkAbstractProcessFactory::instance()->create(processName));
    dtkWarn() << "Process" << processName;
    if(d->process)
        return 1;
    else {
        dtkWarn() << "Process" << processName << "not found";
        return 0;
    }
}

//! Create the dynamic object process by copying the current state of a process.
/*!
 *
 */
void axlDataDynamic::setProcess(axlAbstractProcess *process){
    d->process = dynamic_cast<axlAbstractProcess *>(dtkAbstractProcessFactory::instance()->create(process->identifier()));
    d->process->copyProcess(process);

}

/* dtk overload */
//! Return a description of the dynamic object.
/*!
 *
 */
QString axlDataDynamic::description(void) const
{
    if(d->output.empty()){
        return " create a dynamic object";
    }else{
        if(!d->output.isEmpty()){

            axlAbstractData *output = dynamic_cast<axlAbstractData *>(d->output.at(0));
            return " create a dynamic object  \n" + output->description();
        }else{
            return "";
        }
    }
}


//! Return the identifier "axlDataDynamic".
/*!
 *
 */
QString axlDataDynamic::identifier(void) const
{
    return "axlDataDynamic";
}


//! Return the number of output(s);
/*!
 *
 */
int axlDataDynamic::numberOfChannels(void){
    return d->output.size();
}


//! Update the dynamic object.
/*!
 *
 */
void axlDataDynamic::update(void)
{
    //    static axlDataDynamic *last = NULL;

    if (!(d->output.empty())) {
        for (int i = 0; i < d->output.size(); i++) {
            this->remove(d->output.at(i));
        }
        d->output.clear();
    }

    //Count number of parameters
    int compteurParametre = 0;
    for (int i = 0;i < d->inputs.size(); i++) {
        if(dynamic_cast<axlDouble *>(d->inputs.at(i)) || dynamic_cast<axlInteger *>(d->inputs.at(i)) ) {
            compteurParametre++;
        }
    }

    int countData = 0;
    int countParametersDouble = 0;
    int countParametersInt = 0;

    int result = 0;

    if (d->process) {
        for (int i = 0; i < d->inputs.size(); i++) {
            if (axlDouble *axldata = dynamic_cast<axlDouble *>(d->inputs.at(i))) {
                if (compteurParametre == 1){
                    d->process->setParameter(axldata->value());
                } else {
                    d->process->setParameter(axldata->value(), countParametersDouble);
                }
                countParametersDouble++;
            } else if(axlInteger *axldata = dynamic_cast<axlInteger *>(d->inputs.at(i))) {
                if (compteurParametre == 1) {
                    d->process->setParameter(axldata->value());
                } else {
                    d->process->setParameter(axldata->value(), countParametersInt);
                }
                countParametersInt++;
            } else {
                if (d->nbUp == 0) {
                    d->process->setInput(d->inputs.at(i),countData);
                    countData++;
                }
            }
        }
        result = d->process->update();

    } else {
        dtkWarn()<<Q_FUNC_INFO << "no process found";
        return;
    }

    if (result == 0) {
        dtkWarn() << Q_FUNC_INFO << "problem in process, should return 1" << d->process->identifier() << "update";
        return;
    }

    if (d->process->channelCount() > 1) {
        for (int i = 0; i< d->process->channelCount(); i++) {
            //if(d->output.isEmpty()){
                d->output.append(dynamic_cast<axlAbstractData *>(d->process->output(i)));
            //}

            if(dynamic_cast<axlAbstractData *>(d->output.at(i))){
                axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(d->output.at(i));
                axlData->setEditable(false);
                //                axlData->setColor(this->color());
                //                axlData->setOpacity(this->opacity());
                //                axlData->setShader(this->shader());
                //                axlData->setSize(this->size());
                axlData->setObjectName(axlData->identifier());
                //axlData->setParent(this);
                axlData->touchGeometry();
            }

        }

    } else {
        d->output.append(dynamic_cast<axlAbstractData *>(d->process->output()));

        if(dynamic_cast<axlAbstractData *>(d->output.at(0))){
            axlAbstractData *axlData =dynamic_cast<axlAbstractData *>(d->output.at(0));
            axlData->setEditable(false);
            //            axlData->setColor(this->color());
            //            axlData->setOpacity(this->opacity());
            //            axlData->setShader(this->shader());
            //            axlData->setSize(this->size());
            axlData->setObjectName(axlData->identifier());
            //axlData->setParent(this);
            axlData->touchGeometry();
        }

    }

    for(int i = 0; i < d->inputs.size(); i++){
        for (int j = 0; j< d->output.size();j++){
            if(d->output.at(j) == d->inputs.at(i)){
                d->inputs.at(i)->setEditable(true);
            }
        }
    }


    for(int i = 0; i < d->output.size();i++){
        this->add(d->output.at(i));
    }

    d->nbUp += 1;

    if(!this->fields().isEmpty())
        this->touchField();

    this->touchGeometry();
}


QVariantList axlDataDynamic::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    list.append(id);
    QVariant nbUp = QVariant::fromValue(d->nbUp);
    list.append(nbUp);
    QVariant process = QVariant::fromValue(d->process->identifier());
    list.append(process);
    if(d->type == axlDataDynamic::Dynamic){
        QVariant type = QVariant::fromValue(1);
        list.append(type);
    }else{
        QVariant type = QVariant::fromValue(2);
        list.append(type);
    }


    //inputs
    for(int i = 0; i < d->inputs.size();i++){
        QVariantList in = d->inputs.at(i)->convertDataToQVariant();
        int s = in.size();
        list.append("input");
        list.append(s);
        list.append(in);

    }

    //parameters
    for(int i = 0; i < d->parameters.size();i++){
        QVariantList param = d->parameters.at(i)->convertDataToQVariant();
        int s = param.size();
        list.append("parameter");
        list.append(s);
        list.append(param);

    }

    //outputs
    for(int i = 0; i < d->output.size();i++){
        QVariantList out = d->output.at(i)->convertDataToQVariant();
        int s = out.size();
        list.append("output");
        list.append(s);
        list.append(out);

    }

    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlDataDynamic::convertQVariantToData(const QVariantList &data){

    d->nbUp = data.at(1).toInt();
    setProcess(data.at(2).toString());
    int type = data.at(3).toInt();
    if(type ==1){
        d->type = axlDataDynamic::Dynamic;
    }else{
        d->type = axlDataDynamic::Static;
    }

    int currentIndice = 4;
    while(currentIndice < (data.size()-1)){
        QString what = data.at(currentIndice).toString();
        int count = data.at(currentIndice+1).toInt();
        QString id = data.at(currentIndice+2).toString();
        axlAbstractData *obj = dynamic_cast<axlAbstractData *>(dtkAbstractDataFactory::instance()->create(id));
        QVariantList list;
        for(int i = 0;i < count;i++){
            list.append(data.at(currentIndice+2+i));
        }
        obj->convertQVariantToData(list);

        if(what=="input"){
            d->inputs.append(obj);


        }else if(what=="parameter"){
            d->parameters.append(obj);

        }else{
            d->output.append(obj);

        }
        currentIndice = currentIndice+count+2;
    }

    setObjectName(data.last().toString());

    return 1;

}

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createAxlDataDynamic(void)
{
    return new axlDataDynamic();

}

// /////////////////////////////////////////////////////////////////
// axlDataDynamic documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlDataDynamic
 *
 *  \brief Class axlDataDynamic defines a dynamic object.
 *
 *  This class enables to represent and manipulate dynamic object.
 *
 *  Example:
 *  \code
 *  axlDataDynamic *object = new axlDataDynamicObject();
 *  object->setProcess("axlLineCreator");
 *  object->setInput(new axlPoint());
 *  object->setInput(new axlPoint(1.,0.));
 *  object->update();
 *  dynamic_cast<axlLine *>(object->outputs());
 *  \endcode
 */
