/* axlFieldSpatialPointDistanceCreator.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2011 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov 11 16:58:59 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef axlFieldSpatialPointDistanceCreator_H
#define axlFieldSpatialPointDistanceCreator_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractFieldGenerator.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlFieldSpatialPointDistanceCreatorPrivate;
class axlAbstractField;
class axlAbstractData;

class AXLCORE_EXPORT axlFieldSpatialPointDistanceCreator : public axlAbstractFieldGenerator
{
    Q_OBJECT

public:
     axlFieldSpatialPointDistanceCreator(void);
    ~axlFieldSpatialPointDistanceCreator(void);

public:
    QString description(void) const;
    QString identifier(void) const;

public slots:
    void setInput(dtkAbstractData *data, int channel=0);
    void setParameter(double data, int channel=0);

public slots:
    int update(void);
    int channelCount(void);

public:
    QString form(void) const
    {
        return QString(
             " INPUT:0 data supportData \n"
             " PARAMETER:0 double x 0.0 \n"
             " PARAMETER:1 double y 0.0 \n"
             " PARAMETER:2 double z 0.0 ");
    }

public:
    static bool registered(void);

private:
    axlFieldSpatialPointDistanceCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlFieldSpatialPointDistanceCreator(void);

#endif // axlFieldSpatialPointDistanceCreator_H
