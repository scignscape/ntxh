/* dtkVrTracker.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Thu Feb 18 20:32:08 2010 (+0100)
 * Version: $Id: 71ad2dbb0fc88f798f16dd4f86b8ed309b2cb416 $
 * Last-Updated: Thu Apr 26 17:49:32 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 16
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkVrTracker.h"

#include <dtkCoreSupport/dtkGlobal.h>

class dtkVrTrackerPrivate
{
public:
};

dtkVrTracker::dtkVrTracker(void) : QObject(), d(new dtkVrTrackerPrivate)
{

}

dtkVrTracker::~dtkVrTracker(void)
{
    delete d;

    d = NULL;
}

void dtkVrTracker::initialize(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void dtkVrTracker::uninitialize(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void dtkVrTracker::setUrl(const QUrl& url)
{
    DTK_UNUSED(url);

    DTK_DEFAULT_IMPLEMENTATION;
}

dtkDeprecated::dtkVector3D<double> dtkVrTracker::headPosition(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return dtkDeprecated::dtkVector3D<double>();
}

dtkDeprecated::dtkVector3D<double> dtkVrTracker::handPosition(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return dtkDeprecated::dtkVector3D<double>();
}

dtkDeprecated::dtkQuaternion<double> dtkVrTracker::headOrientation(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return dtkDeprecated::dtkQuaternion<double>();
}
