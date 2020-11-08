/* dtkComposerNodeControlFor.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed Feb 15 09:12:58 2012 (+0100)
 * Version: $Id: 5f08fd7106f395f453799221b1d2b0e608c63bd9 $
 * Last-Updated: mer. mars 28 13:59:31 2012 (+0200)
 *           By: Nicolas Niclausse
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODECONTROLFOR_H
#define DTKCOMPOSERNODECONTROLFOR_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeControl.h"

class dtkComposerNodeControlForPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeControlFor : public dtkComposerNodeControl
{
public:
    dtkComposerNodeControlFor(void);
    virtual ~dtkComposerNodeControlFor(void);

public:
    int blockCount(void);
    dtkComposerNodeLeaf *header(void);
    dtkComposerNodeLeaf *footer(void);
    dtkComposerNodeComposite *block(int id);

public:
    void setInputs(void);
    void setOutputs(void);
    void setVariables(void);
    int selectBranch(void);
    void begin(void);
    void end(void);

public:
    QString type(void);

public:
    QString titleHint(void);

private:
    dtkComposerNodeControlForPrivate *d;
};

#endif
