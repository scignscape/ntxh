/* axlPlaneCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLPLANECREATOR_H
#define AXLPLANECREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlPlane;
class axlAbstractData;

class axlPlaneCreatorPrivate;

class AXLCORE_EXPORT axlPlaneCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlPlaneCreator(QObject *parent = 0);
    virtual ~axlPlaneCreator(void);


public :
    virtual axlAbstractData * getInput(int channel) const;
    void copyProcess(axlAbstractProcess *process);
    bool hasParameters(void);

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
    axlPlaneCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlPlaneCreator(void);

#endif// AXLPLANECREATOR_H
