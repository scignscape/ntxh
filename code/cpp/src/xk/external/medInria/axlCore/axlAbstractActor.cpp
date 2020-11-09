/* axlAbstractActor.cpp ---
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

#include "axlAbstractActor.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkGlobal.h>

#include "axlAbstractData.h"

#include <QtCore>

class axlAbstractActorPrivate
{
public:
    axlAbstractActor *parent;

public:
    QString active_scalars;
};

axlAbstractActor::axlAbstractActor(axlAbstractActor *parent) :QObject(parent), d(new axlAbstractActorPrivate)
{
    d->parent = NULL;
}

axlAbstractActor::~axlAbstractActor(void)
{
    delete d;

    d = NULL;
}

void axlAbstractActor::setParent(axlAbstractActor *parent)
{
    d->parent = parent;
}



QString axlAbstractActor::identifier(void){
    return QString();
}


//axlAbstractActor *axlAbstractActor::createActor(dtkAbstractData *data){
//    Q_UNUSED(data);
//    DTK_DEFAULT_IMPLEMENTATION;
//    return NULL;

//}

axlAbstractActor *axlAbstractActor::parent(void)
{
    return d->parent;
}

axlMesh *axlAbstractActor::toMesh(void){
    return NULL;
}

bool axlAbstractActor::isVisible(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractActor::setInteractor(void *interactor)
{
    Q_UNUSED(interactor);
}

void axlAbstractActor::setDisplay(bool display)
{
    Q_UNUSED(display);
}

void axlAbstractActor::setData(dtkAbstractData *data)
{
    Q_UNUSED(data);
}

void axlAbstractActor::showControlPoints(bool show)
{
    Q_UNUSED(show);
}

void axlAbstractActor::setMapperCollorArray(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::setShader(QString xmlfile)
{
    Q_UNUSED(xmlfile);
}

void axlAbstractActor::onControlPointChanged()
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::setShaderFromString(QString xmlfile)
{
    Q_UNUSED(xmlfile);
}

void axlAbstractActor::setOpacity(double opacity)
{
    Q_UNUSED(opacity);
}

void axlAbstractActor::setSize(double size)
{
    Q_UNUSED(size);
}

void axlAbstractActor::setColor(double red, double green, double blue)
{
    Q_UNUSED(red);
    Q_UNUSED(green);
    Q_UNUSED(blue);
}

void axlAbstractActor::setInterpolation(int interpolation)
{
    Q_UNUSED(interpolation);
}

bool axlAbstractActor::isShowControlPoints(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return false;
}

int axlAbstractActor::getState(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractActor::setMode(int state)
{
    Q_UNUSED(state);
}

void axlAbstractActor::hide(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::show(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::update(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::onSamplingChanged(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::onTubeFilterRadiusChanged(double radius)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::onRemoved(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::onModeChanged(int state)
{
    Q_UNUSED(state);
}

void axlAbstractActor::onUpdateGeometry(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActor::onUpdateProperty(void)
{
    axlAbstractData *data = dynamic_cast<axlAbstractData *>(this->data());
    QColor color = data->color();
    this->setColor(color.red(), color.green(), color.blue());
    this->setOpacity(data->opacity());
    this->setShader(data->shader());
//    this->setSize(data->size());

    emit updated();
}

void axlAbstractActor::showCurrentPoint(double u, double v, dtkAbstractData *data)
{
    Q_UNUSED(data);
}

void axlAbstractActor::moveCurrentPoint(double u, double v, dtkAbstractData *data)
{
    Q_UNUSED(data);
}

void axlAbstractActor::hideCurrentPoint(double u, double v,  dtkAbstractData *data)
{
    Q_UNUSED(data);
}

void axlAbstractActor::onSelectBoundaryEdge(int numEdge, int previous, int n){

    DTK_DEFAULT_IMPLEMENTATION;
}
