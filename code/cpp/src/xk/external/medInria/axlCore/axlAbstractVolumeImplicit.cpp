/* axlAbstractVolumeImplicit.cpp ---
 *
 * Author:Anais Ducoffe
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

#include "axlAbstractVolumeImplicit.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractVolumeImplicitPrivate
{
public:
};

axlAbstractVolumeImplicit::axlAbstractVolumeImplicit(void) : axlAbstractVolume(), d(new axlAbstractVolumeImplicitPrivate)
{

}

axlAbstractVolumeImplicit::~axlAbstractVolumeImplicit(void)
{
    delete d;

    d = NULL;
}
