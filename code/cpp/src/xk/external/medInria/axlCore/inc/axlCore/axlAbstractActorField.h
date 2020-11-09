/* axlAbstractActorField.h ---
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

#ifndef AXLABSTRACTACTORFIELD_H
#define AXLABSTRACTACTORFIELD_H

#include "axlCoreExport.h"

#include "axlAbstractActor.h"

class axlAbstractField;

class dtkAbstractData;

#include <QObject>
#include <QtGui>
class axlAbstractActorFieldPrivate;

class AXLCORE_EXPORT axlAbstractActorField : public axlAbstractActor
{
    Q_OBJECT

//protected:
public:
    axlAbstractActorField();
    virtual ~axlAbstractActorField(void);

public:

    virtual axlAbstractField *field(void);
    virtual axlAbstractField *magnitude(void);
    virtual axlAbstractActor *actorField(void);

    virtual double colRangeMin(void);
    virtual double colRangeMax(void);
    virtual double maxValue(void);
    virtual double minValue(void);

    virtual int isoCount(void);
    virtual double isoRangeMin(void);
    virtual double isoRangeMax(void);

    virtual double glyphScale(void);

    virtual double streamRadius(void);

    virtual void setInteractor(void *interactor);
    virtual void setData(dtkAbstractData *field);
    virtual void setActorField(axlAbstractActor *mesh);

    virtual void setColRangeMin(double min);
    virtual void setColRangeMax(double max);

    virtual void setIsoCount(int count);
    virtual void setIsoRangeMin(double min);
    virtual void setIsoRangeMax(double max);

    virtual void setGlyphScale(double scale);

    virtual void setStreamPropagation(double propagation);
    virtual void setStreamRadius(double radius);
    virtual void setStreamDirection(int direction);

    virtual void setActiveFieldKind(void);

public slots:
    virtual void displayAsNoneScalar(void);
    virtual void displayAsNoneVector(void);
    virtual void displayAsColor(void);
    virtual void displayAsIso(void);

    virtual void displayAsHedge(void);
    virtual void displayAsGlyph(void);
    virtual void displayAsStream(void);
    virtual void onIsoRadiusChanged(double radius);


    void update(void);

public:
    void *scalarColorMapper(void);

private:
    axlAbstractActorFieldPrivate *d;
};

#endif // AXLABSTRACTACTORFIELD_H
