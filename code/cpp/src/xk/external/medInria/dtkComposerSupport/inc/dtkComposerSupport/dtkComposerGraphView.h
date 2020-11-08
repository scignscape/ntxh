/* dtkComposerGraphView.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Feb  9 14:42:13 2012 (+0100)
 * Version: $Id: 07bf00f27054f653ea4b3b6f69454ae10bafb889 $
 * Last-Updated: Mon Apr 16 12:21:19 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 20
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERGRAPHVIEW_H
#define DTKCOMPOSERGRAPHVIEW_H

#include <dtkComposerSupportExport.h>

#include <QtWidgets>

class dtkComposerGraphViewPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerGraphView : public QGraphicsView
{
    Q_OBJECT

public:
    dtkComposerGraphView(QWidget *parent = 0);
    ~dtkComposerGraphView(void);

private:
    dtkComposerGraphViewPrivate *d;
};

#endif
