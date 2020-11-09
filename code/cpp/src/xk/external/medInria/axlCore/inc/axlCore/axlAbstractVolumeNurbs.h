/* axlAbstractVolumeNurbs.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2008 - Anais Ducoffe, Inria.
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

#ifndef AXLABSTRACTVOLUMENURBS_H
#define AXLABSTRACTVOLUMENURBS_H

#include "axlAbstractVolumeBSpline.h"
#include "axlCoreExport.h"

class axlAbstractVolumeNurbsPrivate;

class AXLCORE_EXPORT axlAbstractVolumeNurbs : public axlAbstractVolumeBSpline
{
    Q_OBJECT

public:
    axlAbstractVolumeNurbs(void);
    virtual ~axlAbstractVolumeNurbs(void);




private:
    axlAbstractVolumeNurbsPrivate *d;
};
#endif
