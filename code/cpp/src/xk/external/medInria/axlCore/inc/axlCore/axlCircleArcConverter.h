/* axlSurfaceParametricOffsetConverter.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2011 - Valentin Michelet, Inria.
 * Created: Wed Jan 30 11:01:27 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCIRCLEARCCONVERTER_H
#define AXLCIRCLEARCCONVERTER_H

#include <axlCore/axlAbstractDataConverter.h>

class axlCircleArcConverterPrivate;

class AXLCORE_EXPORT axlCircleArcConverter : public axlAbstractDataConverter {
    Q_OBJECT

public:
    axlCircleArcConverter(void);
    virtual ~axlCircleArcConverter(void);

    QString  description (void) const;
    QString  identifier  (void) const;

    QStringList fromTypes(void) const;
    QString       toType (void) const;

    virtual void setParams(int channel, int index);
    virtual void setOutput(axlAbstractData* output);
    virtual void setPrecision(double eps);

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

public:
    void setData(dtkAbstractData *data);

private:
    axlCircleArcConverterPrivate *d;
};

dtkAbstractDataConverter *createaxlCircleArcConverter(void);

#endif // AXLCIRCLEARCCONVERTER_H
