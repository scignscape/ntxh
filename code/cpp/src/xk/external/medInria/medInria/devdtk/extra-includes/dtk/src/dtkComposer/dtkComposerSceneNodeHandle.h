// Version: $Id: 49626d0fe255af310f22f89fbe3e737d23dcc1d3 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include <QtCore>
#include <QtWidgets>

class dtkComposerSceneNodeControl;
class dtkComposerSceneNodeComposite;
class dtkComposerSceneNodeHandlePrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerSceneNodeHandle
// /////////////////////////////////////////////////////////////////

class  dtkComposerSceneNodeHandle : public QGraphicsItem
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

public:
    dtkComposerSceneNodeHandlePrivate *d;
};

//
// dtkComposerSceneNodeHandle.h ends here
