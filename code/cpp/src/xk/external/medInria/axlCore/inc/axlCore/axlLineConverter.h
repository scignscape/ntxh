/* axlLineConverter.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2011 - Valentin Michelet, Inria.
 * Created: Tue Apr 30 11:01:27 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLLINECONVERTER_H
#define AXLLINECONVERTER_H

#include <axlCore/axlAbstractDataConverter.h>

class axlLineConverterPrivate;

class AXLCORE_EXPORT axlLineConverter : public axlAbstractDataConverter {
    Q_OBJECT

public:
    axlLineConverter(void);
    virtual ~axlLineConverter(void);

    QString  description (void) const;
    QString  identifier  (void) const;

    QStringList fromTypes(void) const;
    QString       toType (void) const;

    void setParams(int channel, int index);
    void setOutput(axlAbstractData* output);
    void setPrecision(double eps);

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

public:
    void setData(dtkAbstractData *data);

private:
    axlLineConverterPrivate *d;
};

dtkAbstractDataConverter *createaxlLineConverter(void);

#endif // AXLLINECONVERTER_H
