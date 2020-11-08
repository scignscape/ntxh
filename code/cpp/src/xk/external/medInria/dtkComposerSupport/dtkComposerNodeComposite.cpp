/* dtkComposerNodeComposite.cpp ---
 *
 * Author: David Rey
 * Copyright (C) 2008-2011 - David Rey, Inria.
 * Created: Tue Feb 14 15:40:50 2012 (+0100)
 * Version: $Id: 59b30b2ad663fc313e517b97688ca52efe16d3f3 $
 * Last-Updated: mar. avril  3 15:09:01 2012 (+0200)
 *           By: Nicolas Niclausse
 *     Update #: 30
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerNodeComposite.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeCompositePrivate definition
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeCompositePrivate
{
public:

};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeComposite implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeComposite::dtkComposerNodeComposite(void) : dtkComposerNode(), d(new dtkComposerNodeCompositePrivate)
{

}

dtkComposerNodeComposite::~dtkComposerNodeComposite(void)
{
    delete d;

    d = NULL;
}

QString dtkComposerNodeComposite::type(void)
{
    return "composite";
}

void dtkComposerNodeComposite::begin(void)
{

}

void dtkComposerNodeComposite::end(void)
{

}
