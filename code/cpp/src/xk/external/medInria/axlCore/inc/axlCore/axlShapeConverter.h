/* axlShapeConverter.h ---
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

#ifndef AXLSHAPECONVERTER_H
#define AXLSHAPECONVERTER_H

#include <axlCore/axlAbstractDataConverter.h>

class axlShapeConverterPrivate;

class AXLCORE_EXPORT axlShapeConverter : public axlAbstractDataConverter {
    Q_OBJECT

public:
    axlShapeConverter(void);
    virtual ~axlShapeConverter(void);

    QString description (void) const;
    QString identifier (void) const;

    QStringList fromTypes(void) const;
    QString toType (void) const;

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

public:
    void setData(dtkAbstractData *data);

private:
    axlShapeConverterPrivate *d;
};

dtkAbstractDataConverter *createaxlShapeConverter(void);

#endif // AXLSHAPECONVERTER_H
