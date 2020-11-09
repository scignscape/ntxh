/* axlEllipsoidCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#ifndef AXLELLIPSOIDCREATOR_H
#define AXLELLIPSOIDCREATOR_H

#include "axlCoreExport.h"

#include "axlAbstractCreatorProcess.h"

#include <QtCore>

class axlPoint;
class axlEllipsoid;
class axlAbstractData;

class axlEllipsoidCreatorPrivate;

class AXLCORE_EXPORT axlEllipsoidCreator : public axlAbstractCreatorProcess
{
    Q_OBJECT

public:
    axlEllipsoidCreator(QObject *parent = 0);
    virtual ~axlEllipsoidCreator(void);


public :
    virtual axlAbstractData * getInput(int channel) const;
    void copyProcess(axlAbstractProcess *process);
    bool hasParameters(void);


public :
    static bool registered(void);



/* dtk overload */
public :
    virtual int update(void);

public :

    virtual QString description(void) const;
    virtual QString identifier(void) const;

public :
    virtual void setInput(dtkAbstractData *newData, int channel);
    virtual dtkAbstractData *output(void);

private:
    axlEllipsoidCreatorPrivate *d;
};

AXLCORE_EXPORT dtkAbstractProcess *createaxlEllipsoidCreator(void);

#endif // AXLELLIPSOIDCREATOR_H
