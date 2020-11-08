/* dtkComposerNodeVectorReal.h ---
 *
 * Author: sblekout
 * Copyright (C) 2011 - babette lekouta, Inria.
 * Created: Thu Apr 26 10:10:43 2012 (+0200)
 * Version: $Id: 0bf4baf45085bd7c1b3df665e2efb1e62b4ec9ce $
 * Last-Updated: Fri Apr 27 17:54:19 2012 (+0200)
 *           By: babette lekouta
 *     Update #: 9
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEVECTORREAL_H
#define DTKCOMPOSERNODEVECTORREAL_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeVectorRealPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVectorReal : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVectorReal(void);
    ~dtkComposerNodeVectorReal(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "vectorReal";
    }

    inline QString titleHint(void) {
        return "Vector Real";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeVectorRealPrivate *d;
};

#endif
