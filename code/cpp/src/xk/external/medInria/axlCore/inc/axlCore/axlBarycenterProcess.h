/* axlBarycenterProcess.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef axlBarycenterProcess_H
#define axlBarycenterProcess_H

#include "axlCoreExport.h"

#include "axlAbstractProcess.h"

#include <QtCore>

class axlPoint;
class axlLine;
class axlAbstractData;

class axlBarycenterProcessPrivate;

class AXLCORE_EXPORT axlBarycenterProcess : public axlAbstractProcess
{
    Q_OBJECT

public:
    axlBarycenterProcess(QObject *parent = 0);
    ~axlBarycenterProcess(void);

public :
    axlAbstractData * getInput(int channel) const;
    double getCoeffValue(void) const;

public :
    virtual int update(void);

public :
    QString description(void) const;
    QString identifier(void) const;

public :
    dtkAbstractData *output(void);
    void setInput(dtkAbstractData *newData, int channel = 0);
    void setParameter(double data, int channel = 0);
    int channelCount(void);

public:
    QString form(void) const
    {
        return QString(
             " INPUT:0 data line \n"
             " PARAMETER:0 double coefficient 0.5 \n"
             " OUTPUT:0 data barycenterPoint ");
    }

signals:
    void dataInserted(axlAbstractData *data);

private:
    axlBarycenterProcessPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlBarycenterProcess(void);

#endif// axlBarycenterProcess_H
