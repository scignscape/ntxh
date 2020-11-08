/* dtkComposerNodeVectorRealExtractor.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Tue May 15 11:33:29 2012 (+0200)
 * Version: $Id: db8b94ea5dfd39b036aed7b765b629bd07915edc $
 * Last-Updated: 2012 Wed Oct 10 18:08:59 (+0200)
 *           By: Thibaud Kloczko, Inria.
 *     Update #: 9
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEVECTORREALEXTRACTOR_H
#define DTKCOMPOSERNODEVECTORREALEXTRACTOR_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeVectorRealExtractorPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVectorRealExtractor : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVectorRealExtractor(void);
    ~dtkComposerNodeVectorRealExtractor(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "vector_real_extractor";
    }

    inline QString titleHint(void) {
        return "Vector Real Extract";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeVectorRealExtractorPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeVectorRealExtractorSubVector interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeVectorRealExtractorSubVectorPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVectorRealExtractorSubVector : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVectorRealExtractorSubVector(void);
    ~dtkComposerNodeVectorRealExtractorSubVector(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "vectorRealExtractorSubVector";
    }

    inline QString titleHint(void) {
        return "Vector real : extract subvector";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeVectorRealExtractorSubVectorPrivate *d;
};

#endif

