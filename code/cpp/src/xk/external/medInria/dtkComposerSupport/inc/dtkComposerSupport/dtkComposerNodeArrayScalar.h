/* dtkComposerNodeArrayScalar.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Tue May 15 11:33:29 2012 (+0200)
 * Version: $Id: 4759bc84e2b7400557af431d1047f8a7996f178f $
 * Last-Updated: Tue May 15 11:37:39 2012 (+0200)
 *           By: tkloczko
 *     Update #: 2
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEARRAYSCALAR_H
#define DTKCOMPOSERNODEARRAYSCALAR_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeArrayScalarPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeArrayScalar : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeArrayScalar(void);
    ~dtkComposerNodeArrayScalar(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "array_scalar";
    }

    inline QString titleHint(void) {
        return "Scalar Array";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeArrayScalarPrivate *d;
};

#endif

