/* axlSurfaceParametricOffsetConverter.h ---
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

#ifndef AXLSURFACEPARAMETRICOFFSETCONVERTER_H
#define AXLSURFACEPARAMETRICOFFSETCONVERTER_H

#include <axlCore/axlAbstractDataConverter.h>

class axlSurfaceParametricOffsetConverterPrivate;

class AXLCORE_EXPORT axlSurfaceParametricOffsetConverter : public axlAbstractDataConverter
{
    Q_OBJECT

public:
     axlSurfaceParametricOffsetConverter(void);
    ~axlSurfaceParametricOffsetConverter(void);

    QString  description (void) const;
    QString  identifier  (void) const;

    QStringList fromTypes(void) const;
    QString       toType (void) const;

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

public:
    void setData(dtkAbstractData *data);

private:
    axlSurfaceParametricOffsetConverterPrivate *d;
};

dtkAbstractDataConverter *createaxlSurfaceParametricOffsetConverter(void);

#endif //AXLSURFACEPARAMETRICOFFSETCONVERTER_H
