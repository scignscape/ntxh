/* axlAbstractDataConverter.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 24 10:42:31 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 10:58:39 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 26
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTDATACONVERTER_H
#define AXLABSTRACTDATACONVERTER_H

#include <dtkCoreSupport/dtkAbstractDataConverter.h>
#include <axlCore/axlAbstractData.h>

#include "axlCoreExport.h"

class axlMesh;

class AXLCORE_EXPORT axlAbstractDataConverter : public dtkAbstractDataConverter
{
    Q_OBJECT

public:
    axlAbstractDataConverter(void);
    virtual ~axlAbstractDataConverter(void);

    //             virtual void toto(void) {}
    virtual void setParams(int channel, int index);
    virtual void setOutput(axlAbstractData* output);
    virtual void setPrecision(double eps);


public slots:
    virtual axlMesh *toMesh(void);
};

#endif
