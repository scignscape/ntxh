/* axlParameterSpace.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 28 13:53:28 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Mon Mar 28 16:41:06 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 25
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLPARAMETERSPACE_H
#define AXLPARAMETERSPACE_H

#include <QtGui>
#include <QtWidgets>

#include "axlGuiExport.h"

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlParameterSpaceViewPrivate;

class AXLGUI_EXPORT axlParameterSpaceView : public QGraphicsView
{
    Q_OBJECT

public:
     axlParameterSpaceView(QWidget *parent = 0);
    ~axlParameterSpaceView(void);

private:
    axlParameterSpaceViewPrivate *d;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlParameterSpaceScenePrivate;

class AXLGUI_EXPORT axlParameterSpaceScene : public QGraphicsScene
{
    Q_OBJECT

public:
     axlParameterSpaceScene(QObject *parent = 0);
    ~axlParameterSpaceScene(void);

    void resize(QSize size);

    void setRangeU(double min, double max);
    void setRangeV(double min, double max);
    void setRangeW(double min, double max);

signals:
    void showCurrentPoint(double u, double v);
    void moveCurrentPoint(double u, double v);
    void hideCurrentPoint(double u, double v);
    void update();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    axlParameterSpaceScenePrivate *d;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlParameterSpacePrivate;

class AXLGUI_EXPORT axlParameterSpace : public QFrame
{
    Q_OBJECT

public:
     axlParameterSpace(QWidget *parent = 0);
    ~axlParameterSpace(void);

    void setRangeU(double min, double max);
    void setRangeV(double min, double max);
    void setRangeW(double min, double max);

signals:
    void showCurrentPoint(double u, double v);
    void moveCurrentPoint(double u, double v);
    void hideCurrentPoint(double u, double v);
    void update();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    axlParameterSpacePrivate *d;
};

#endif
