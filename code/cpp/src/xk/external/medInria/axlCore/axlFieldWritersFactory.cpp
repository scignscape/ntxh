/* axlFieldWritersFactory.cpp ---
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

#include "axlFieldWritersFactory.h"

//all field reader types
#include "axlFieldSpatialCoordinatesWriter.h"
#include "axlFieldSpatialPointDistanceWriter.h"
#include "axlFieldParametricCurveTangentVectorWriter.h"
#include "axlFieldParametricSurfaceTangentVectorWriter.h"
#include "axlFieldParametricSurfaceNormalVectorWriter.h"
#include "axlFieldParametricCurveWriter.h"
#include "axlFieldParametricSurfaceWriter.h"
#include "axlFieldParametricVolumeWriter.h"
#include "axlFieldDiscreteWriter.h"


// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

axlFieldWritersInterface::axlFieldWritersInterface(QWidget *parent) : QFrame(parent)
{
    m_actorFactorySingleton = axlFieldWritersFactory::instance();
}

axlFieldWritersInterface::~axlFieldWritersInterface(void)
{

}

void axlFieldWritersInterface::setActorFactorySingleton(axlFieldWritersFactory *actorFactorySingleton)
{
    m_actorFactorySingleton = actorFactorySingleton;
}

axlFieldWritersFactory *axlFieldWritersInterface::actorFactorySingleton(void)
{
    return m_actorFactorySingleton;
}

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlFieldWritersFactoryPrivate
{
public:
    axlFieldWritersFactory::axlFieldWritersCreatorHash creators;
};

axlFieldWritersFactory *axlFieldWritersFactory::instance(void)
{
    if(!s_instance)
        s_instance = new axlFieldWritersFactory;

    return s_instance;
}

bool axlFieldWritersFactory::registerFieldWriters(const QString& interface_name, axlFieldWritersCreator func)
{
    if(!d->creators.contains(interface_name))
        d->creators.insert(interface_name, func);

    return true;
}


void axlFieldWritersFactory::initialize(void)
{

    d->creators.insert("axlFieldSpatialCoordinates", createaxlFieldSpatialCoordinatesWriter);
    d->creators.insert("axlFieldSpatialPointDistance", createaxlFieldSpatialPointDistanceWriter);
    d->creators.insert("axlFieldParametricCurveTangentVector", createaxlFieldParametricCurveTangentVectorWriter);
    d->creators.insert("axlFieldParametricSurfaceTangentVector", createaxlFieldParametricSurfaceTangentVectorWriter);
    d->creators.insert("axlFieldParametricNormalVector", createaxlFieldParametricSurfaceNormalVectorWriter);
    d->creators.insert("axlFieldParametricCurve", createaxlFieldParametricCurveWriter);
    d->creators.insert("axlFieldParametricSurface", createaxlFieldParametricSurfaceWriter);
    d->creators.insert("axlFieldParametricVolume", createaxlFieldParametricVolumeWriter);
    d->creators.insert("axlFieldDiscrete", createaxlFieldDiscreteWriter);

}

dtkAbstractDataWriter *axlFieldWritersFactory::create(const QString& interface_name)
{
    if(!d->creators.contains(interface_name))
        return NULL;

    return d->creators[interface_name]();

}

axlFieldWritersFactory::axlFieldWritersFactory(void) : QObject(), d(new axlFieldWritersFactoryPrivate)
{
    initialize();

}

axlFieldWritersFactory::~axlFieldWritersFactory(void)
{
    delete d;

    d = NULL;
}

axlFieldWritersFactory *axlFieldWritersFactory::s_instance = NULL;
