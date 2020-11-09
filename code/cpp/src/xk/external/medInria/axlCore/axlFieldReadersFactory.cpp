/* axlFieldReadersFactory.cpp ---
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

#include "axlFieldReadersFactory.h"

//all field reader types
#include "axlFieldSpatialCoordinatesReader.h"
#include "axlFieldSpatialPointDistanceReader.h"
#include "axlFieldParametricCurveTangentVectorReader.h"
#include "axlFieldParametricSurfaceTangentVectorReader.h"
#include "axlFieldParametricVolumeTangentVectorReader.h"
#include "axlFieldParametricSurfaceNormalVectorReader.h"
#include "axlFieldParametricCurveReader.h"
#include "axlFieldParametricSurfaceReader.h"
#include "axlFieldParametricVolumeReader.h"
#include "axlFieldDiscreteReader.h"


// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

axlFieldReadersInterface::axlFieldReadersInterface(QWidget *parent) : QFrame(parent)
{
    m_actorFactorySingleton = axlFieldReadersFactory::instance();
}

axlFieldReadersInterface::~axlFieldReadersInterface(void)
{

}

void axlFieldReadersInterface::setActorFactorySingleton(axlFieldReadersFactory *actorFactorySingleton)
{
    m_actorFactorySingleton = actorFactorySingleton;
}

axlFieldReadersFactory *axlFieldReadersInterface::actorFactorySingleton(void)
{
    return m_actorFactorySingleton;
}

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlFieldReadersFactoryPrivate
{
public:
    axlFieldReadersFactory::axlFieldReadersCreatorHash creators;
};

axlFieldReadersFactory *axlFieldReadersFactory::instance(void)
{
    if(!s_instance)
        s_instance = new axlFieldReadersFactory;

    return s_instance;
}

bool axlFieldReadersFactory::registerFieldReaders(const QString& interface_name, axlFieldReadersCreator func)
{
    if(!d->creators.contains(interface_name))
        d->creators.insert(interface_name, func);

    return true;
}


void axlFieldReadersFactory::initialize(void)
{

    d->creators.insert("axlFieldSpatialCoordinates", createaxlFieldSpatialCoordinatesReader);
    d->creators.insert("axlFieldSpatialPointDistance", createaxlFieldSpatialPointDistanceReader);
    d->creators.insert("axlFieldParametricCurveTangentVector", createaxlFieldParametricCurveTangentVectorReader);
    d->creators.insert("axlFieldParametricSurfaceTangentVector", createaxlFieldParametricSurfaceTangentVectorReader);
    d->creators.insert("axlFieldParametricVolumeTangentVector", createaxlFieldParametricVolumeTangentVectorReader);
    d->creators.insert("axlFieldParametricNormalVector", createaxlFieldParametricSurfaceNormalVectorReader);
    d->creators.insert("axlFieldParametricCurve", createaxlFieldParametricCurveReader);
    d->creators.insert("axlFieldParametricSurface", createaxlFieldParametricSurfaceReader);
    d->creators.insert("axlFieldParametricVolume", createaxlFieldParametricVolumeReader);
    d->creators.insert("axlFieldDiscrete", createaxlFieldDiscreteReader);

}

dtkAbstractDataReader *axlFieldReadersFactory::create(const QString& interface_name)
{
    if(!d->creators.contains(interface_name))
        return NULL;

    return d->creators[interface_name]();

}

axlFieldReadersFactory::axlFieldReadersFactory(void) : QObject(), d(new axlFieldReadersFactoryPrivate)
{
    initialize();

}

axlFieldReadersFactory::~axlFieldReadersFactory(void)
{
    delete d;

    d = NULL;
}

axlFieldReadersFactory *axlFieldReadersFactory::s_instance = NULL;
