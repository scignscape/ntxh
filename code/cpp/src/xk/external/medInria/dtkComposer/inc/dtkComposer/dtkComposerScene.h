// Version: $Id: 24bb2d4c4466369b11ffbadab2fa0352264d856b $
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

#include <dtkComposerExport.h>

#include <QtWidgets>

class dtkComposerNode;
class dtkComposerNodeFactory;
class dtkComposerGraph;
class dtkComposerSceneNode;
class dtkComposerSceneNodeComposite;
class dtkComposerSceneNodeLeaf;
class dtkComposerScenePort;
class dtkComposerScenePrivate;
class dtkComposerStack;

// /////////////////////////////////////////////////////////////////
// dtkComposerScene
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerScene : public QGraphicsScene
{
    Q_OBJECT

public:
    dtkComposerScene(QObject *parent = 0);
    virtual ~dtkComposerScene(void);

// #pragma mark -
// #pragma mark - Setup

public:
    void setFactory(dtkComposerNodeFactory *factory);
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
    QAction *setBreakPointAction(void);

public:
    QAction   *maskEdgesAction(void);
    QAction *unmaskEdgesAction(void);

public:
    QList<dtkComposerSceneNodeLeaf *> flagged(Qt::GlobalColor);
    bool checkImplementations(void);

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
    void flagged(dtkComposerSceneNode *);

signals:
    void selectedNode(dtkComposerSceneNode *node);
    void selectionCleared(void);
    // void selected(QGraphicsItem *item);

// #pragma mark -
// #pragma mark - Flag events

public:
    void onEvaluationPaused(dtkComposerNode *node);
    void onEvaluationFinished(void);

protected slots:
    void onFlagAsBlue(void);
    void onFlagAsGray(void);
    void onFlagAsGreen(void);
    void onFlagAsOrange(void);
    void onFlagAsRed(void);
    void onFlagAsPink(void);
    void onFlagAsYellow(void);
    void onFlagAs(Qt::GlobalColor);
    void onBreakPointSet(void);

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
    void populateNodes(dtkComposerSceneNode *root = NULL);

// #pragma mark -
// #pragma mark - Internal sigs handling

protected slots:
    void onSelectionChanged(void);

private:
    dtkComposerScenePrivate *d;
};

//
// dtkComposerScene.h ends here
