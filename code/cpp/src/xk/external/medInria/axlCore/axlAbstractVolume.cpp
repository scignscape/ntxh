/* axlAbstractVolume.cpp ---
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

#include "axlAbstractVolume.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlAbstractVolumePrivate
{

};

axlAbstractVolume::axlAbstractVolume(void) : axlAbstractData(), d(new axlAbstractVolumePrivate)
{

}

axlAbstractVolume::~axlAbstractVolume(void)
{
    delete d;

    d = NULL;
}

int axlAbstractVolume::dimension(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

axlMesh *axlAbstractVolume::toAxlMesh(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

void *axlAbstractVolume::volume(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}
