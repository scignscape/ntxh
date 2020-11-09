/* axlAbstractSurface.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTSURFACE_H
#define AXLABSTRACTSURFACE_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractData.h>

class axlMesh;

class axlAbstractSurfacePrivate;

class AXLCORE_EXPORT axlAbstractSurface : public axlAbstractData
{
    Q_OBJECT

public:
             axlAbstractSurface(void);
    virtual ~axlAbstractSurface(void);

    virtual int dimension(void) const;

    virtual axlMesh *toAxlMesh(void);



public:
    virtual void *surface(void);

private:
    axlAbstractSurfacePrivate *d;
};
#endif

