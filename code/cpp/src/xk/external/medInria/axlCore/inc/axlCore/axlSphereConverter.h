/* axlSphereConverter.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 24 11:01:27 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 11:25:45 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 25
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLSPHERECONVERTER_H
#define AXLSPHERECONVERTER_H

#include <axlCore/axlAbstractDataConverter.h>

class axlSphereConverterPrivate;

class AXLCORE_EXPORT axlSphereConverter : public axlAbstractDataConverter
{
    Q_OBJECT

public:
     axlSphereConverter(void);
    ~axlSphereConverter(void);

    QString  description (void) const;
    QStringList fromTypes(void) const;
    QString       toType (void) const;

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

public:
    void setData(dtkAbstractData *data);

private:
    axlSphereConverterPrivate *d;
};

dtkAbstractDataConverter *createaxlSphereConverter(void);

#endif //AXLSPHERECONVERTER_H
