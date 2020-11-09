/* axlIntersection.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLINTERSECTION_H
#define AXLINTERSECTION_H

#include "axlCoreExport.h"

#include "axlAbstractProcess.h"

#include <QtCore>

class axlPoint;
class axlLine;
class axlCircle;
class axlAbstractData;

class axlIntersectionPrivate;

class AXLCORE_EXPORT axlIntersection : public axlAbstractProcess
{
    Q_OBJECT

public:
    axlIntersection(QObject *parent = 0);
    ~axlIntersection(void);


public :
    axlAbstractData * getInput(int channel) const;

public :
    virtual int update(void);

public :
    QString description(void) const;
    QString identifier(void) const;

public :
//    virtual dtkAbstractData *output(int channel);
    dtkAbstractData *output(void);
    void setInput(dtkAbstractData *newData, int channel);
    int channelCount(void);


public:
    QString form(void) const
    {
        return QString(
             " INPUT:0 data line1 \n"
             " INPUT:1 data line2 \n"
             " OUTPUT:0 data point ");
    }


signals :
    void dataInserted(axlAbstractData *data);


private:
    axlIntersectionPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlIntersectionProcess(void);

#endif  // AXLINTERSECTION_H
