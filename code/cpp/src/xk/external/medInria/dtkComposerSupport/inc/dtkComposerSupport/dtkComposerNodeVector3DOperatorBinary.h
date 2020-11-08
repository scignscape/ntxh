/* dtkComposerNodeVector3DOperatorBinary.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Thu Apr 26 16:14:44 2012 (+0200)
 * Version: $Id: 3be97bca588467393b3abca075b13ffb498ce8b1 $
 * Last-Updated: Thu Apr 26 17:34:34 2012 (+0200)
 *           By: tkloczko
 *     Update #: 38
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEVECTOR3DOPERATORBINARY_H
#define DTKCOMPOSERNODEVECTOR3DOPERATORBINARY_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorBinary interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeVector3DOperatorBinaryPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorBinary : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVector3DOperatorBinary(void);
    ~dtkComposerNodeVector3DOperatorBinary(void);

    inline QString inputLabelHint(int port) {
        if (port == 0)
            return "vec_lhs";
        else
            return "vec_rhs";
    }

    inline QString outputLabelHint(int) {
        return "vector";
    }

protected:
    dtkComposerNodeVector3DOperatorBinaryPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorBinaryScalar interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeVector3DOperatorBinaryScalarPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorBinaryScalar : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVector3DOperatorBinaryScalar(void);
    ~dtkComposerNodeVector3DOperatorBinaryScalar(void);

    inline QString inputLabelHint(int port) {
        if (port == 0)
            return "vec_lhs";
        else
            return "vec_rhs";
    }

    inline QString outputLabelHint(int) {
        return "scalar";
    }

protected:
    dtkComposerNodeVector3DOperatorBinaryScalarPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorHomothetic interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeVector3DOperatorHomotheticPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorHomothetic : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVector3DOperatorHomothetic(void);
    ~dtkComposerNodeVector3DOperatorHomothetic(void);

    inline QString inputLabelHint(int port) {
        if (port == 0)
            return "vector";
        else
            return "scalar";
    }

    inline QString outputLabelHint(int) {
        return "vector";
    }

protected:
    dtkComposerNodeVector3DOperatorHomotheticPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorBinary - SUM
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorBinarySum : public dtkComposerNodeVector3DOperatorBinary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_sum";
    }

    inline QString titleHint(void) {
        return "Vector3D Sum";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorBinary - SUBSTRACT
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorBinarySubstract : public dtkComposerNodeVector3DOperatorBinary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_substract";
    }

    inline QString titleHint(void) {
        return "Vector3D Substract";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorBinary - CROSS PROD
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorBinaryCrossProd : public dtkComposerNodeVector3DOperatorBinary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_cross_prod";
    }

    inline QString titleHint(void) {
        return "Vector3D Cross Prod";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorBinaryScalar - DOT PRODUCT
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorBinaryScalarDotProd : public dtkComposerNodeVector3DOperatorBinaryScalar
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_dot_prod";
    }

    inline QString titleHint(void) {
        return "Vector3D Dot Prod";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorHomothetic - MULTIPLY
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorHomotheticMult : public dtkComposerNodeVector3DOperatorHomothetic
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_scal_mult";
    }

    inline QString titleHint(void) {
        return "Vector3D: scal * vec";
    }
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVector3DOperatorHomothetic - DIVIDE
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3DOperatorHomotheticDivision : public dtkComposerNodeVector3DOperatorHomothetic
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D_scal_divide";
    }

    inline QString titleHint(void) {
        return "Vector3D: vec / scal";
    }
};

#endif
