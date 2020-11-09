/* axlAbstractView.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractView.h"
#include "axlAbstractCurveBSpline.h"
#include "axlAbstractSurfaceBSpline.h"
#include "axlAbstractActor.h"
#include "axlAbstractActorField.h"
#include "axlAbstractField.h"
#include "axlViewController.h"
#include "axlDataDynamic.h"

#include <dtkCoreSupport/dtkAbstractViewFactory.h>


class axlAbstractViewPrivate
{
public:
    axlViewController *view_controller;
};

axlAbstractView::axlAbstractView(void) : dtkAbstractView(), d(new axlAbstractViewPrivate)
{
    d->view_controller = new axlViewController;

    connect(d->view_controller, SIGNAL(inserted()), this, SIGNAL(inserted()));
}

axlAbstractView::~axlAbstractView(void)
{
    disconnect(d->view_controller, SIGNAL(inserted()), this, SIGNAL(inserted()));

    delete d->view_controller;
    delete d;

    d = NULL;
}

axlAbstractActor *axlAbstractView::insert(axlAbstractData *data)
{
    DTK_DEFAULT_IMPLEMENTATION;

    Q_UNUSED(data);

    return NULL;
}

QList<axlAbstractActor *> axlAbstractView::insertSet(QList<axlAbstractData *> dataSet)
{
    DTK_DEFAULT_IMPLEMENTATION;

    Q_UNUSED(dataSet);

    return QList<axlAbstractActor *>();
}

void axlAbstractView::removeSet(QList<axlAbstractActor *> actorSet)
{
    DTK_DEFAULT_IMPLEMENTATION;

    Q_UNUSED(actorSet);
}

void axlAbstractView::removeSetFields(QList<axlAbstractActorField *> actorSet)
{
    DTK_DEFAULT_IMPLEMENTATION;

    Q_UNUSED(actorSet);
}

void axlAbstractView::activeDefaultLigh(bool useDefaultLight)
{
    DTK_DEFAULT_IMPLEMENTATION;

    Q_UNUSED(useDefaultLight);
}

void axlAbstractView::setLight(int i, bool hide, double *position, double *ambiant, double *diffuse, double *specular, int exponent)
{
    DTK_DEFAULT_IMPLEMENTATION;

    Q_UNUSED(i);
    Q_UNUSED(hide);
    Q_UNUSED(position);
    Q_UNUSED(ambiant);
    Q_UNUSED(diffuse);
    Q_UNUSED(specular);
    Q_UNUSED(exponent);
}

axlAbstractActor *axlAbstractView::actor(dtkAbstractData *data)
{
    if(axlAbstractField *axlData = dynamic_cast<axlAbstractField *> (data))
        return d->view_controller->actorField(axlData);
    else
        return d->view_controller->actor(data);
}

void axlAbstractView::insert(dtkAbstractData *data, axlAbstractActor *actor)
{
    axlAbstractField *dataField = dynamic_cast<axlAbstractField *>(data);
    axlAbstractActorField *actorField =  dynamic_cast<axlAbstractActorField *>(actor);


    if(dataField && actorField)
        d->view_controller->insertField(dataField, actorField);
    else
        d->view_controller->insert(data, actor);
}

void axlAbstractView::removeData(dtkAbstractData *data)
{
    d->view_controller->remove(data);
}

void axlAbstractView::removeField(dtkAbstractData *data)
{
    if(axlAbstractField* dataField = dynamic_cast<axlAbstractField*>(data))
        d->view_controller->removeField(dataField);
}

axlViewController *axlAbstractView::controller(void)
{
    return d->view_controller;
}

void axlAbstractView::setCameraViewDefaut(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraViewNegativeX(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraViewPositiveX(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraViewNegativeY(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraViewPositiveY(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraViewNegativeZ(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraViewPositiveZ(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setCameraPosition(double x, double y, double z)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setGrid(bool isGridX, bool isGridY, bool isGridZ)
{
    Q_UNUSED(isGridX);
    Q_UNUSED(isGridY);
    Q_UNUSED(isGridZ);

    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::showColorMapping(dtkAbstractData *data)
{
    if(dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        d->view_controller->actor(data)->onSamplingChanged();
}

void axlAbstractView::onShaderChanged(dtkAbstractData *data, QString isophoteShaderXml)
{
    d->view_controller->actor(data)->setShader(isophoteShaderXml);
}

void axlAbstractView::onControlPointChanged(dtkAbstractData *data)
{
    d->view_controller->actor(data)->onControlPointChanged();
//    this->widget()->update();
    this->update();
}

void axlAbstractView::onTubeFilterRadiusChanged(dtkAbstractData *data, double radius)
{
    if(dynamic_cast<axlAbstractCurveBSpline *>(data))
        d->view_controller->actor(data)->onTubeFilterRadiusChanged(radius);
    else
        d->view_controller->actor(data)->setSize(radius);

    this->update();
}

void axlAbstractView::processIsophoteByShader(dtkAbstractData *data, QString isophoteShaderXml)
{
    if(dynamic_cast<axlAbstractSurfaceBSpline *>(data))
        d->view_controller->actor(data)->setShaderFromString(isophoteShaderXml);
}

void axlAbstractView::dataChangedByGeometry(dtkAbstractData *data)
{
    d->view_controller->actor(data)->onUpdateGeometry();
}


void axlAbstractView::dataChangedByOpacity(dtkAbstractData *data, double opacity)
{
    d->view_controller->actor(data)->setOpacity(opacity);
}

void axlAbstractView::dataChangedBySize(dtkAbstractData *data, double size)
{
    d->view_controller->actor(data)->setSize(size);
}

void axlAbstractView::dataChangedByColor(dtkAbstractData *data, double red, double green, double blue)
{
    d->view_controller->actor(data)->setColor(red, green, blue);
}

//! Modify the right property, which is defined by the channel number :
/*!
 * -channel == 0 : modify color property
 * -channel == 1 : modify opacity property
 * -channel == 2 : modify shader property
 * -channel == 3 : modify size property
 * Same channel definition used by the signal modifiedProperty(dtkAbstractData *data, int channel).
 */
void axlAbstractView::dataChangedByProperty(dtkAbstractData *data, int channel)
{
    if (channel == 0) {
        //qDebug() << Q_FUNC_INFO;
        QColor color = dynamic_cast<axlAbstractData *>(data)->color();
        d->view_controller->actor(data)->setColor(color.red(), color.green(), color.blue());
    } else if (channel == 1) {
        double opacity =  dynamic_cast<axlAbstractData *>(data)->opacity();
        d->view_controller->actor(data)->setOpacity(opacity);
    } else if (channel == 2) {
        QString xmlFile = dynamic_cast<axlAbstractData *>(data)->shader();
        d->view_controller->actor(data)->setShader(xmlFile);
    } else if (channel == 3) {
        double size =  dynamic_cast<axlAbstractData *>(data)->size();
        axlAbstractActor *actor = d->view_controller->actor(data);
        if (actor) {
            //qDebug() << Q_FUNC_INFO<< "size";
            //            if(!(actor->identifier()=="axlActorMesh")){
            //                d->view_controller->actor(data)->onUpdateGeometry();
            //            }else{
            actor->setSize(size);
            //            }
        }
    }

    //    if(!dynamic_cast<axlAbstractData *>(data)->fields().isEmpty())
    //        dynamic_cast<axlAbstractData *>(data)->runFieldUpdated();

    this->update();
}

void axlAbstractView::onInterpolationChanded(dtkAbstractData *data, int interpolation)
{
    d->view_controller->actor(data)->setInterpolation(interpolation);
}

void axlAbstractView::onStateChanged(dtkAbstractData *data, int mode)
{
    d->view_controller->actor(data)->onModeChanged(mode);
//    this->widget()->update();
    this->update();
}

void axlAbstractView::onActorVisibilityChanged(dtkAbstractData *data, bool actorVisibility)
{
    if(actorVisibility){
        d->view_controller->actor(data)->show();
        if( axlDataDynamic* axlData = dynamic_cast<axlDataDynamic*>(data)){
            int indiceOutput = axlData->numberOfChannels();
            for( int i = 0; i < indiceOutput; i++){
                d->view_controller->actor(axlData->outputs(i))->show();
            }
        }


        if(d->view_controller->actor(data)->parent()){
            //hide parents for dynamic object, the problem is hide not just one output actor.
            d->view_controller->actor(data)->parent()->show();
        }
        //        axlAbstractData* axlData = dynamic_cast<axlAbstractData*>(data);
        //        foreach(axlAbstractField* field, axlData->fields()){
        //            d->view_controller->actorField(field)->show();
        //        }
    }
    else{
        d->view_controller->actor(data)->hide();

        if( axlDataDynamic* axlData = dynamic_cast<axlDataDynamic*>(data)){
            int indiceOutput = axlData->numberOfChannels();
            for( int i = 0; i < indiceOutput; i++){
                d->view_controller->actor(axlData->outputs(i))->hide();
            }

        }

        if(d->view_controller->actor(data)->parent()){
            //hide parents for dynamic object, not just one output actor.
            d->view_controller->actor(data)->parent()->hide();
            ////method that hides only the appropriated outputs of the parent actor.
            //            if(axlDataDynamic* axlObject = dynamic_cast<axlDataDynamic *>(d->view_controller->actor(data)->parent()->data())){
            //                int indiceO = axlObject->numberOfChannels();
            //                for( int i = 0; i < indiceO; i++){
            //                    if(d->view_controller->actor(axlObject->outputs(i))->data()->objectName() == d->view_controller->actor(data)->objectName() ){
            //                        qDebug() << "passe a l'endroit souhaite";
            //                    d->view_controller->actor(axlObject->outputs(i))->hide();
            //                    }
            //                }

            //            }
        }
        //        axlAbstractData* axlData = dynamic_cast<axlAbstractData*>(data);
        //        foreach(axlAbstractField* field, axlData->fields()){
        //            d->view_controller->actorField(field)->hide();
        //        }


        //// if there are some fields to hide
        if (!dynamic_cast<axlAbstractData *>(data)->fields().isEmpty()) {
            foreach (axlAbstractField * field,dynamic_cast<axlAbstractData *>(data)->fields() ) {
                axlAbstractField::Kind kind = field->kind();

                if (kind == axlAbstractField::Scalar) {
                    d->view_controller->actorField(field)->displayAsNoneScalar();
                } else if (kind == axlAbstractField::Vector) {
                    d->view_controller->actorField(field)->displayAsNoneVector();
                }

            }
        }
    }

//    this->widget()->update();
    this->update();
}

void axlAbstractView::ondataSetRemoved(QList<dtkAbstractData *> dataSetToRemoved)
{
    QList<axlAbstractActor *> actorSetToRemoved;
    QList<axlAbstractActorField *> actorSetFieldToRemoved;

    for(int i = 0 ; i < dataSetToRemoved .size() ; i++)
    {
        if(axlAbstractActor *actor = d->view_controller->actor(dataSetToRemoved.value(i)))
            actorSetToRemoved << actor;

        if (axlAbstractData* data = dynamic_cast<axlAbstractData*>(dataSetToRemoved.value(i))){
            foreach(axlAbstractField* field,data->fields()){
                if(axlAbstractActorField *actor = d->view_controller->actorField(field)){
                    actorSetFieldToRemoved << actor;
                }
            }
        }
    }
    this->removeSet(actorSetToRemoved);
    this->removeSetFields(actorSetFieldToRemoved);
}

int axlAbstractView::size(void)
{
    return d->view_controller->size();
}

void axlAbstractView::onLightPositionChanged(double x, double y, double z)
{
    emit lightPositionChanged(x, y, z);
}

void axlAbstractView::onGridResolutionChanged(int resolution)
{
    Q_UNUSED(resolution);

    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::onShowAxis(bool show)
{
    Q_UNUSED(show);

    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::onBackgroundGradientChange(bool gradient)
{
    Q_UNUSED(gradient);

    DTK_DEFAULT_IMPLEMENTATION;
}

bool axlAbstractView::getBackgroundGradient()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractView::setParallelScale(double parallelScale)
{
    Q_UNUSED(parallelScale);

    DTK_DEFAULT_IMPLEMENTATION;
}

double axlAbstractView::getParallelScale()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double *axlAbstractView::getWorldCameraPosition()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

bool axlAbstractView::getAxesVisibility()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

bool axlAbstractView::getParallelProjection()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

double *axlAbstractView::getCameraFocalPoint()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

void axlAbstractView::setCameraFocalPoint(double x, double y, double z)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);

    DTK_DEFAULT_IMPLEMENTATION;
}

double *axlAbstractView::getCameraUp()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

void axlAbstractView::setCameraUp(double x, double y, double z)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);

    DTK_DEFAULT_IMPLEMENTATION;
}

double axlAbstractView::getCameraViewAngle()
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

void axlAbstractView::setCameraViewAngle(double angle)
{
    Q_UNUSED(angle);

    DTK_DEFAULT_IMPLEMENTATION;
}


double *axlAbstractView::getBackgroundColor(){
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

void axlAbstractView::setParallelCamera(bool parallel)
{
    Q_UNUSED(parallel);

    DTK_DEFAULT_IMPLEMENTATION;
}

//! Use view as input to open a data in axel
/*!
 * Usefull with interpreter
 */
void axlAbstractView::add(dtkAbstractData *data)
{
    if(axlAbstractData *axldata = dynamic_cast<axlAbstractData *>(data) )
    {
        if(!d->view_controller->contains(axldata))
            emit insertData(axldata);
        else
            dtkWarn() << "this data has already been inserted";
    }
}

//! Use view as input to update fields actors on a data
/*!
 * Usefull with interpreter
 */
void axlAbstractView::updateFieldActor(dtkAbstractData *data)
{
    Q_UNUSED(data);

    DTK_DEFAULT_IMPLEMENTATION;
}




void axlAbstractView::setWorldCamera()
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setObjectCamera()
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setTrackballInteractor()
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractView::setJoystickInteractor()
{
    DTK_DEFAULT_IMPLEMENTATION;
}


void axlAbstractView::update(void)
{

}

void axlAbstractView::onUpdateActorField(QList<axlAbstractData *> axlDataSet, QString fieldName)
{
    Q_UNUSED(axlDataSet);
}


dtkAbstractViewFactory *axlAbstractView::getSingletonFactory(void)
{
    //qDebug()<<"axlAbstractView :: getSingletonFactory"<<dtkAbstractViewFactory::instance();

    return dtkAbstractViewFactory::instance();
}
