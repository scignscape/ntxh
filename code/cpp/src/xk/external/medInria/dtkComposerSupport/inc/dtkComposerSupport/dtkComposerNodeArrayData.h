/* dtkComposerNodeArrayData.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed Jul  4 09:09:31 2012 (+0200)
 * Version: $Id: ef0d4c6583e4a1dd976a5ef0f6481b88b525e824 $
 * Last-Updated: Wed Jul  4 09:10:25 2012 (+0200)
 *           By: tkloczko
 *     Update #: 2
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEARRAYDATA_H
#define DTKCOMPOSERNODEARRAYDATA_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeArrayDataPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeArrayData interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeArrayData : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeArrayData(void);
    ~dtkComposerNodeArrayData(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "array_data";
    }

    inline QString titleHint(void) {
        return "Data Array";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeArrayDataPrivate *d;
};

#endif

