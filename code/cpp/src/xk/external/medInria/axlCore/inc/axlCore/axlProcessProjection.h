/* axlProcessProjection.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef axlProcessProjection_H
#define axlProcessProjection_H

#include "axlCoreExport.h"

#include "axlAbstractProcess.h"

#include <QtCore>

class axlPoint;
class axlPlane;
class axlAbstractData;

class axlProcessProjectionPrivate;

class AXLCORE_EXPORT axlProcessProjection : public axlAbstractProcess
{
    Q_OBJECT

public:
    axlProcessProjection(QObject *parent = 0);
    virtual ~axlProcessProjection(void);


public :
    virtual axlAbstractData * getInput(int channel) const;
    void copyProcess(axlAbstractProcess *process);
    bool hasParameters(void);
    bool isOnLine(void);


public:
//    QString form(void) const
//    {
//        return QString(
//                    " INPUT:0 data point \n"
//                    " INPUT:1 data line");
//    }

/* dtk overload */
public :
    virtual int update(void);

public :

    virtual QString description(void) const;
    virtual QString identifier(void) const;

public :
    static bool registered(void) ;

public :
    virtual void setInput(dtkAbstractData *newData, int channel);
    virtual dtkAbstractData *output(void);

private:
    axlProcessProjectionPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlProcessProjection(void);

#endif // AXLPROCESSPROJECTION_H
