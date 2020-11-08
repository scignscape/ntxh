/* dtkComposerNodeMatrixSquareRealExtractor.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Tue May 15 11:33:29 2012 (+0200)
 * Version: $Id: c87e2e78bcf4e0ba2a859d01827034361cd18d7f $
 * Last-Updated: Mon Jun 25 12:02:43 2012 (+0200)
 *           By: tkloczko
 *     Update #: 3
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEMATRIXSQUAREREALEXTRACTOR_H
#define DTKCOMPOSERNODEMATRIXSQUAREREALEXTRACTOR_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeMatrixSquareRealExtractorPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMatrixSquareRealExtractor : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMatrixSquareRealExtractor(void);
    ~dtkComposerNodeMatrixSquareRealExtractor(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "matrixSquare_real_extractor";
    }

    inline QString titleHint(void) {
        return "MatrixSquare Real Extractor";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeMatrixSquareRealExtractorPrivate *d;
};

#endif

