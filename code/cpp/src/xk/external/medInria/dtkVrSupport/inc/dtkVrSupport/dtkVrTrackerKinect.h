/* dtkVrTrackerKinect.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Apr 25 16:58:36 2012 (+0200)
 * Version: $Id: 314a740f66b24991408511c81add355710b1a4ad $
 * Last-Updated: Wed Apr 25 17:24:45 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 6
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <dtkVrSupportExport.h>
#include "dtkVrTracker.h"

//? added ...
#include <dtkMathSupport/dtkVector3D>
using namespace dtkDeprecated;

class dtkVrTrackerKinectPrivate;

class DTKVRSUPPORT_EXPORT dtkVrTrackerKinect : public dtkVrTracker
{
    Q_OBJECT

public:
    dtkVrTrackerKinect(void);
    ~dtkVrTrackerKinect(void);

public:
    void   initialize(void);
    void uninitialize(void);

public:
    dtkVector3D<double> headPosition(void);
    dtkVector3D<double> handPosition(void);

public:
    dtkQuaternion<double> headOrientation(void);

private:
    dtkVrTrackerKinectPrivate *d;
};

