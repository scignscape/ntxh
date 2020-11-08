/* dtkComposerNodeQuaternionOperatorUnary.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Fri Apr 27 14:19:43 2012 (+0200)
 * Version: $Id: 8a9b56816175fd482426b7fd956654d2646cd5b3 $
 * Last-Updated: Fri Apr 27 14:53:27 2012 (+0200)
 *           By: tkloczko
 *     Update #: 9
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEQUATERNIONOPERATORUNARY_H
#define DTKCOMPOSERNODEQUATERNIONOPERATORUNARY_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeQuaternionOperatorUnary interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeQuaternionOperatorUnaryPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeQuaternionOperatorUnary : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeQuaternionOperatorUnary(void);
    ~dtkComposerNodeQuaternionOperatorUnary(void);

    inline QString inputLabelHint(int) {
        return "quat";
    }

    inline QString outputLabelHint(int) {
        return "quat";
    }

protected:
    dtkComposerNodeQuaternionOperatorUnaryPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeQuaternionOperatorUnaryScalar interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeQuaternionOperatorUnaryScalarPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeQuaternionOperatorUnaryScalar : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeQuaternionOperatorUnaryScalar(void);
    ~dtkComposerNodeQuaternionOperatorUnaryScalar(void);

    inline QString inputLabelHint(int port) {
        return "quat";
    }

    inline QString outputLabelHint(int) {
        return "scalar";
    }

protected:
    dtkComposerNodeQuaternionOperatorUnaryScalarPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeQuaternionOperatorUnary UNITARY interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeQuaternionOperatorUnaryUnitary : public dtkComposerNodeQuaternionOperatorUnary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "quat_unit";
    }

    inline QString titleHint(void) {
        return "Quat Unit";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeQuaternionOperatorUnaryScalar NORM interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeQuaternionOperatorUnaryScalarNorm : public dtkComposerNodeQuaternionOperatorUnaryScalar
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "quat_norm";
    }

    inline QString titleHint(void) {
        return "Quat Norm";
    }
};

#endif
