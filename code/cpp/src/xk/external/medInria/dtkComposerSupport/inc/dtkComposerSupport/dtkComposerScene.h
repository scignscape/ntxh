/* dtkComposerScene.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/01/30 10:11:39
 * Version: $Id: c34988c0611029704474f7cb3f2fad906945d8f2 $
 * Last-Updated: jeu. févr. 28 19:16:06 2013 (+0100)
 *           By: Nicolas Niclausse
 *     Update #: 242
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERSCENE_H
#define DTKCOMPOSERSCENE_H

#include <dtkComposerSupportExport.h>

#include <QtWidgets>

class dtkComposerMachine;
class dtkComposerFactory;
class dtkComposerGraph;
class dtkComposerSceneEdge;
class dtkComposerSceneNode;
class dtkComposerSceneNodeComposite;
class dtkComposerSceneNodeLeaf;
class dtkComposerSceneNote;
class dtkComposerScenePort;
class dtkComposerScenePrivate;
class dtkComposerStack;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerScene : public QGraphicsScene
{
    Q_OBJECT

public:
    dtkComposerScene(QObject *parent = 0);
    virtual ~dtkComposerScene(void);

// #pragma mark -
// #pragma mark - Setup

public:
    void setFactory(dtkComposerFactory *factory);
    void setMachine(dtkComposerMachine *machine);
    void setStack(dtkComposerStack *stack);
    void setGraph(dtkComposerGraph *graph);

// #pragma mark -
// #pragma mark - Composition depth management

public:
    dtkComposerSceneNodeComposite *root(void);
    dtkComposerSceneNodeComposite *current(void);

public:
    void setRoot(dtkComposerSceneNodeComposite *root);
    void setCurrent(dtkComposerSceneNode *node);
    void setCurrent(dtkComposerSceneNodeComposite *current);

// #pragma mark -
// #pragma mark - Scene management

public:
    void    addItem(QGraphicsItem *item);
    void removeItem(QGraphicsItem *item);

// #pragma mark -
// #pragma mark - Actions

public:
    QAction *flagAsBlueAction(void);
    QAction *flagAsGrayAction(void);
    QAction *flagAsGreenAction(void);
    QAction *flagAsOrangeAction(void);
    QAction *flagAsPinkAction(void);
    QAction *flagAsRedAction(void);
    QAction *flagAsYellowAction(void);

public:
    QAction *maskEdgesAction(void);
    QAction *unmaskEdgesAction(void);

public:
    QList<dtkComposerSceneNodeLeaf *> flagged(Qt::GlobalColor);

public:
    bool maskedEdges(void);

public slots:
    void clear(void);

// #pragma mark -
// #pragma mark - Sigs

public slots:
    void modify(bool modified);

signals:
    void changed(void);
    void modified(bool);
    void flagged(void);

signals:
    void selectedNode(dtkComposerSceneNode *node);
    void selectionCleared(void);
    // void selected(QGraphicsItem *item);

// #pragma mark -
// #pragma mark - Flag events

protected slots:
    void onFlagAsBlue(void);
    void onFlagAsGray(void);
    void onFlagAsGreen(void);
    void onFlagAsOrange(void);
    void onFlagAsRed(void);
    void onFlagAsPink(void);
    void onFlagAsYellow(void);
    void onFlagAs(Qt::GlobalColor);

protected slots:
    void onMaskEdge(void);
    void onUnMaskEdge(void);

// #pragma mark -
// #pragma mark - Drag Drop Events

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

// #pragma mark -
// #pragma mark - Keyboard Events

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

// #pragma mark -
// #pragma mark - Mouse Events

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);

// #pragma mark -
// #pragma mark - Geometric queries

protected:
    dtkComposerSceneNode *nodeAt(const QPointF& point, dtkComposerSceneNode *exclude) const;
    dtkComposerSceneNode *nodeAt(const QPointF& point) const;
    dtkComposerScenePort *portAt(const QPointF& point) const;
    dtkComposerSceneNodeComposite *parentAt(const QPointF& point) const;

// #pragma mark -
// #pragma mark - Helper function
protected:
    void populateEdges(dtkComposerSceneNode *root = NULL);

// #pragma mark -
// #pragma mark - Internal sigs handling

protected slots:
    void onSelectionChanged(void);

private:
    dtkComposerScenePrivate *d;
};

#endif
