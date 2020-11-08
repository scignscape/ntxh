/* dtkComposerStack.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 31 18:23:50 2012 (+0100)
 * Version: $Id: 374d80df3a07694d937ef8d5dad987b15b90e000 $
 * Last-Updated: Tue Jan 31 18:30:19 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 7
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerStack.h"
#include "dtkComposerStackCommand.h"

void dtkComposerStack::push(dtkComposerStackCommand *command)
{
    QUndoStack::push(command);
}
