/* axlAbstractVolume.h ---
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

#ifndef AXLABSTRACTVOLUME_H
#define AXLABSTRACTVOLUME_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractData.h>

class axlMesh;

class axlAbstractVolumePrivate;

class AXLCORE_EXPORT axlAbstractVolume : public axlAbstractData
{
    Q_OBJECT

public:
             axlAbstractVolume(void);
    virtual ~axlAbstractVolume(void);

    virtual int dimension(void) const;

    virtual axlMesh *toAxlMesh(void);



public:
    virtual void *volume(void);

private:
    axlAbstractVolumePrivate *d;
};
#endif
