/* axlParameterSpace.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 28 13:54:50 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 15:04:28 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 80
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "axlParameterSpace.h"

// /////////////////////////////////////////////////////////////////
// axlParameterSpaceView
// /////////////////////////////////////////////////////////////////

class axlParameterSpaceViewPrivate
{
public:
    
};

axlParameterSpaceView::axlParameterSpaceView(QWidget *parent) : QGraphicsView(parent), d(new axlParameterSpaceViewPrivate)
{
    this->setFrameShape(QFrame::NoFrame);
}

axlParameterSpaceView::~axlParameterSpaceView(void)
{
    delete d;

    d = NULL;
}

// /////////////////////////////////////////////////////////////////
// axlParameterSpaceScene
// /////////////////////////////////////////////////////////////////

class axlParameterSpaceScenePrivate
{
public:
    double min_range_u;
    double max_range_u;

    double min_range_v;
    double max_range_v;

    double min_range_w;
    double max_range_w;
};

axlParameterSpaceScene::axlParameterSpaceScene(QObject *parent) : QGraphicsScene(parent), d(new axlParameterSpaceScenePrivate)
{
    d->min_range_u = 0.0;
    d->max_range_u = 0.0;
    d->min_range_v = 0.0;
    d->max_range_v = 0.0;
    d->min_range_w = 0.0;
    d->max_range_w = 0.0;

    this->setBackgroundBrush(QColor(230, 230, 230));
}

axlParameterSpaceScene::~axlParameterSpaceScene(void)
{
    delete d;

    d = NULL;
}

void axlParameterSpaceScene::resize(QSize size)
{
    this->setSceneRect(0, 0, size.width(), size.height());
}

void axlParameterSpaceScene::setRangeU(double min, double max)
{
    d->min_range_u = min;
    d->max_range_u = max;
}

void axlParameterSpaceScene::setRangeV(double min, double max)
{
    d->min_range_v = min;
    d->max_range_v = max;
}

void axlParameterSpaceScene::setRangeW(double min, double max)
{
    d->min_range_w = min;
    d->max_range_w = max;
}

void axlParameterSpaceScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    double x = event->scenePos().x();
    double y = event->scenePos().y();

    double u = d->min_range_u + x/this->width()  * (d->max_range_u - d->min_range_u);
    double v = d->min_range_v + y/this->height() * (d->max_range_v - d->min_range_v);

    if(u > d->max_range_u)
        u = d->max_range_u;

    if(u < d->min_range_u)
        u = d->min_range_u;

    if(v > d->max_range_v)
        v = d->max_range_v;

    if(v < d->min_range_v)
        v = d->min_range_v;


    emit moveCurrentPoint(u, v);
    emit update();
}

void axlParameterSpaceScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    double x = event->scenePos().x();
    double y = event->scenePos().y();

    double u = d->min_range_u + x/this->width()  * (d->max_range_u - d->min_range_u);
    double v = d->min_range_v + y/this->height() * (d->max_range_v - d->min_range_v);

    emit showCurrentPoint(u, v);
    emit update();
}

void axlParameterSpaceScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    double x = event->scenePos().x();
    double y = event->scenePos().y();

    double u = d->min_range_u + x/this->width()  * (d->max_range_u - d->min_range_u);
    double v = d->min_range_v + y/this->height() * (d->max_range_v - d->min_range_v);

    emit hideCurrentPoint(u, v);
    emit update();
}

// /////////////////////////////////////////////////////////////////
// axlParameterSpaceView
// /////////////////////////////////////////////////////////////////

class axlParameterSpacePrivate
{
public:
    axlParameterSpaceScene *scene;
    axlParameterSpaceView *view;
};

axlParameterSpace::axlParameterSpace(QWidget *parent) : QFrame(parent), d(new axlParameterSpacePrivate)
{
    d->scene = new axlParameterSpaceScene(this);

    d->view = new axlParameterSpaceView(this);
    d->view->setScene(d->scene);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(d->view);

    connect(d->scene, SIGNAL(showCurrentPoint(double, double)), this, SIGNAL(showCurrentPoint(double, double)));
    connect(d->scene, SIGNAL(hideCurrentPoint(double, double)), this, SIGNAL(hideCurrentPoint(double, double)));
    connect(d->scene, SIGNAL(moveCurrentPoint(double, double)), this, SIGNAL(moveCurrentPoint(double, double)));
    connect(d->scene, SIGNAL(update()), this, SIGNAL(update()));
}


axlParameterSpace::~axlParameterSpace(void)
{
    delete d;

    d = NULL;
}

void axlParameterSpace::setRangeU(double min, double max)
{
    d->scene->setRangeU(min, max);
}

void axlParameterSpace::setRangeV(double min, double max)
{
    d->scene->setRangeV(min, max);
}

void axlParameterSpace::setRangeW(double min, double max)
{
    d->scene->setRangeW(min, max);
}

void axlParameterSpace::resizeEvent(QResizeEvent *event)
{
    d->scene->resize(event->size());
}
