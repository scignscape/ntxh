/* axlAbstractVolumeImplicit.h ---
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

#ifndef AXLABSTRACTVOLUMEIMPLICIT_H
#define AXLABSTRACTVOLUMEIMPLICIT_H

#include "axlAbstractVolume.h"
#include "axlCoreExport.h"

class axlAbstractVolumeImplicitPrivate;

class AXLCORE_EXPORT axlAbstractVolumeImplicit : public axlAbstractVolume
{
    Q_OBJECT

public:
    axlAbstractVolumeImplicit(void);
    virtual ~axlAbstractVolumeImplicit(void);




private:
    axlAbstractVolumeImplicitPrivate *d;
};
#endif


