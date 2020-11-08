/* @(#)dtkComposerNodeMovieWriter.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2013 - Nicolas Niclausse, Inria.
 * Created: 2013/10/11 16:12:13
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEMOVIEWRITER_H
#define DTKCOMPOSERNODEMOVIEWRITER_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

#include <QtCore>

class dtkComposerNodeMovieWriterPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeMovieWriter : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMovieWriter(void);
    ~dtkComposerNodeMovieWriter(void);

public:
    void run(void);

public:
    QString type(void);
    QString titleHint(void);

public:
    QString inputLabelHint(int);

private:
    dtkComposerNodeMovieWriterPrivate *d;
};

#endif




