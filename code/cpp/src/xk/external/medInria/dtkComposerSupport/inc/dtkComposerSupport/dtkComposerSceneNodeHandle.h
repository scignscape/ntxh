/* dtkComposerSceneNodeHandle.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Sep 18 14:05:01 2012 (+0200)
 * Version: $Id: 329ca1b63092f83effafb869e5587735d34e5761 $
 * Last-Updated: Tue Sep 18 14:41:22 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 14
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERSCENENODEHANDLE_H
#define DTKCOMPOSERSCENENODEHANDLE_H

#include <dtkComposerSupportExport.h>

#include <QtCore>
#include <QtWidgets>

class dtkComposerSceneNodeControl;
class dtkComposerSceneNodeComposite;
class dtkComposerSceneNodeHandlePrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerSceneNodeHandle : public QGraphicsItem
{
public:
    dtkComposerSceneNodeHandle(dtkComposerSceneNodeControl *parent);
    ~dtkComposerSceneNodeHandle(void);

public:
    void setTopBlock(dtkComposerSceneNodeComposite *block);
    void setBotBlock(dtkComposerSceneNodeComposite *block);

public:
    void layout(void);

public:
    QRectF boundingRect(void) const;

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    dtkComposerSceneNodeHandlePrivate *d;
};

#endif
