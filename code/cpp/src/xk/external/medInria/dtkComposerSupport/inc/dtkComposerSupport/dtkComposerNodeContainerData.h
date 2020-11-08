/* dtkComposerNodeContainerData.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed May  9 12:12:04 2012 (+0200)
 * Version: $Id: 29591fc3eb00806db936cedf18d610e6c07365c4 $
 * Last-Updated: Wed May  9 14:09:48 2012 (+0200)
 *           By: tkloczko
 *     Update #: 3
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODECONTAINERDATA_H
#define DTKCOMPOSERNODECONTAINERDATA_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeContainerDataPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeContainerData : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeContainerData(void);
    ~dtkComposerNodeContainerData(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "data_container";
    }

    inline QString titleHint(void) {
        return "Data Container";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeContainerDataPrivate *d;
};

#endif
