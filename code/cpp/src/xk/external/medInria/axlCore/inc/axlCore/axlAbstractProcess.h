/* axlAbstractProcess.h ---
 *
 * Author: Bernard Mourrain
 * Copyright (C) 2011 - Bernard Mourrain, Inria.
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

#ifndef AXLABSTRACTPROCESS_H
#define AXLABSTRACTPROCESS_H

#include "axlCoreExport.h"

#define AXLPROCESS_SUCCESS 1
#define AXLPROCESS_FAILURE 0

#include <dtkCoreSupport/dtkAbstractProcess.h>

class axlAbstractProcessPrivate;
class axlAbstractField;

class AXLCORE_EXPORT axlAbstractProcess : public dtkAbstractProcess
{
    Q_OBJECT


public:
    axlAbstractProcess(void);
    virtual ~axlAbstractProcess(void);

public :
    virtual void copyProcess(axlAbstractProcess *process);
    virtual bool hasParameters(void);


public:
    virtual QString description(void) const;
    virtual QString identifier(void) const;

    virtual void setDescription(QString description);
    virtual void setIdentifier(QString identifier);

public:
    virtual QString form(void) const;

private:
    axlAbstractProcessPrivate *d;
};

#endif //AXLABSTRACTPROCESS_H
