/* axlAbstractVolumeNurbs.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012 - Anais Ducoffe, Inria.
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

#include "axlAbstractVolumeNurbs.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractVolumeNurbsPrivate
{
public:
};

axlAbstractVolumeNurbs::axlAbstractVolumeNurbs(void) : axlAbstractVolumeBSpline(), d(new axlAbstractVolumeNurbsPrivate)
{

}

axlAbstractVolumeNurbs::~axlAbstractVolumeNurbs(void)
{
    delete d;

    d = NULL;
}
