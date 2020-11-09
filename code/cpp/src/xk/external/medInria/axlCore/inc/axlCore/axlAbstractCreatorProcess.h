/* axlAbstractCreatorProcess.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCREATORPROCESS_H
#define AXLABSTRACTCREATORPROCESS_H

#include "axlCoreExport.h"

#include "axlAbstractProcess.h"

#include <QtCore>

class axlAbstractData;
class axlAbstractCreatorProcessPrivate;

class AXLCORE_EXPORT axlAbstractCreatorProcess : public axlAbstractProcess
{
    Q_OBJECT

public:
    axlAbstractCreatorProcess(QObject *parent = 0);
    virtual ~axlAbstractCreatorProcess(void);


public :
    axlAbstractData * getInput(int channel) const;



    /* dtk overload */
public :
    virtual int update(void);

public :

    virtual QString description(void) const;
    virtual QString identifier(void) const;

public :
    virtual void setInput(dtkAbstractData *newData, int channel);
    virtual dtkAbstractData *output(void);
    virtual dtkAbstractData *output(int channel);
    virtual int channelCount(void);

private:
    axlAbstractCreatorProcessPrivate *d;
};



#endif // AXLABSTRACTCREATORPROCESS_H
