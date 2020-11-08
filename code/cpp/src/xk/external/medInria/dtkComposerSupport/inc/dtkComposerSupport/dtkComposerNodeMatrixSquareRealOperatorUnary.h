/* dtkComposerNodeMatrixSquareRealOperatorUnary.h ---
 *
 * Author: sblekout
 * Copyright (C) 2011 - Babette Lekouta, Inria.
 * Created: Thu Apr 26 15:57:47 2012 (+0200)
 * Version: $Id: b2b27180cbf87efa5b825c6a6e40410a6824ebcc $
 * Last-Updated: Tue May 29 15:17:06 2012 (+0200)
 *           By: tkloczko
 *     Update #: 13
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEMATRIXSQUAREREALOPERATORUNARY_H
#define DTKCOMPOSERNODEMATRIXSQUAREREALOPERATORUNARY_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMatrixSquareRealOperatorUnary interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMatrixSquareRealOperatorUnaryPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealOperatorUnary : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMatrixSquareRealOperatorUnary(void);
    ~dtkComposerNodeMatrixSquareRealOperatorUnary(void);

    inline QString inputLabelHint(int) {
        return "matrix";
    }

    inline QString outputLabelHint(int) {
        return "matrix";
    }

protected:
    dtkComposerNodeMatrixSquareRealOperatorUnaryPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMatrixSquareRealOperatorUnaryScalar interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMatrixSquareRealOperatorUnaryScalarPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealOperatorUnaryScalar : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMatrixSquareRealOperatorUnaryScalar(void);
    ~dtkComposerNodeMatrixSquareRealOperatorUnaryScalar(void);

    inline QString inputLabelHint(int port) {
        return "matrix";
    }

    inline QString outputLabelHint(int) {
        return "scalar";
    }

protected:
    dtkComposerNodeMatrixSquareRealOperatorUnaryScalarPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMatrixSquareRealOperatorUnary Transpose interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealOperatorUnaryTranspose : public dtkComposerNodeMatrixSquareRealOperatorUnary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "matrixSquare_real_transpose";
    }

    inline QString titleHint(void) {
        return "MatrixSquare Real Transpose";
    }
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMatrixSquareRealOperatorUnary Inverse interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealOperatorUnaryInverse: public dtkComposerNodeMatrixSquareRealOperatorUnary
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "matrixSquare_real_inverse";
    }

    inline QString titleHint(void) {
        return "MatrixSquare Real Inverse";
    }
};




// //////////////////////////////////////////////////////////////////////////
// dtkComposerNodeMatrixSquareRealOperatorUnaryScalar Determinant interface
// /////////////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealOperatorUnaryScalarDeterminant : public dtkComposerNodeMatrixSquareRealOperatorUnaryScalar
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "matrixSquare_real_determinant";
    }

    inline QString titleHint(void) {
        return "MatrixSquare Real Determinant";
    }
};

// //////////////////////////////////////////////////////////////////////////
// dtkComposerNodeMatrixSquareRealOperatorUnaryScalar Trace interface
// /////////////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealOperatorUnaryScalarTrace : public dtkComposerNodeMatrixSquareRealOperatorUnaryScalar
{
public:
    void run(void);

public:
    inline QString type(void) {
        return "matrixSquare_real_trace";
    }

    inline QString titleHint(void) {
        return "MatrixSquare Real Trace";
    }
};

#endif
