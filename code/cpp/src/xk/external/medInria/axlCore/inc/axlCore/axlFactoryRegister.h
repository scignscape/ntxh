/* axlFactoryRegister.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C)
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLFACTORYREGISTER_H
#define AXLFACTORYREGISTER_H

#include "axlCoreExport.h"
#include <dtkCoreSupport/dtkAbstractObject.h>

class axlAbstractProcess;

class AXLCORE_EXPORT axlFactoryRegister: public dtkAbstractObject
{
    Q_OBJECT

public :
    axlFactoryRegister(void);
    ~axlFactoryRegister(void);

public :
    static void initialized(void);
    void uninitialized(void);

};

#endif // AXLFACTORYREGISTER_H
