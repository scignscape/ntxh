/* dtkComposerNodeVector3DOperatorTernary.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Thu Apr 26 16:54:35 2012 (+0200)
 * Version: $Id: 186e441b909df1d2327784476c397c93963978fb $
 * Last-Updated: Thu Apr 26 17:28:32 2012 (+0200)
 *           By: tkloczko
 *     Update #: 6
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEVECTOR3DOPERATORTERNARY_H
#define DTKCOMPOSERNODEVECTOR3DOPERATORTERNARY_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorTernary interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeVector3DOperatorTernaryPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorTernary : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVector3DOperatorTernary(void);
    ~dtkComposerNodeVector3DOperatorTernary(void);

    inline QString inputLabelHint(int port) {
        if (port == 0)
            return "vector_0";
        else if (port == 1)
            return "vector_1";
        else
            return "vector_2";
    }

    inline QString outputLabelHint(int) {
        return "vector";
    }

protected:
    dtkComposerNodeVector3DOperatorTernaryPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorTernaryScalar interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeVector3DOperatorTernaryScalarPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorTernaryScalar : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVector3DOperatorTernaryScalar(void);
    ~dtkComposerNodeVector3DOperatorTernaryScalar(void);

    inline QString inputLabelHint(int port) {
        if (port == 0)
            return "vector_0";
        else if (port == 1)
            return "vector_1";
        else
            return "vector_2";
    }

    inline QString outputLabelHint(int) {
        return "scalar";
    }

protected:
    dtkComposerNodeVector3DOperatorTernaryScalarPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorTernary - Vector Triple Prod
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorTernaryTripleProd : public dtkComposerNodeVector3DOperatorTernary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_triple_prod";
    }

    inline QString titleHint(void) {
        return "Vector3D Triple Prod";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorTernaryScalar - Mixed Prod
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorTernaryScalarMixedProd : public dtkComposerNodeVector3DOperatorTernaryScalar
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_mixed_prod";
    }

    inline QString titleHint(void) {
        return "Vector3D Mixed Prod";
    }
};

#endif
