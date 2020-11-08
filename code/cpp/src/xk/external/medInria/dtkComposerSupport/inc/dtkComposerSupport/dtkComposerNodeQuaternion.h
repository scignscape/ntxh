/* dtkComposerNodeQuaternion.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Thu Apr 26 13:03:34 2012 (+0200)
 * Version: $Id: bea8cd3414edcaa7724008947545f4a55fecc77c $
 * Last-Updated: Fri Apr 27 17:54:48 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 3
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEQUATERNION_H
#define DTKCOMPOSERNODEQUATERNION_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeQuaternionPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeQuaternion : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeQuaternion(void);
    ~dtkComposerNodeQuaternion(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "quaternion";
    }

    inline QString titleHint(void) {
        return "Quaternion";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeQuaternionPrivate *d;
};

#endif
