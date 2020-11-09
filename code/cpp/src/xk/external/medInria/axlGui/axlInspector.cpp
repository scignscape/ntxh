/* axlInspector.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 18:23:13 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 11:00:11 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 75
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspector.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManager.h"
#include "axlInspectorToolManager.h"
#include "axlInspectorSettings.h"
#include "axlInspectorStack.h"
#include "axlInspectorView.h"
#include "axlInspectorSidePane.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkGlobal>

#include <QtGui>
#include <QtDebug>

#include <axlCore/axlDouble.h>

class axlInspectorPrivate
{
public:
    axlInspectorObjectController *controller;
    axlInspectorObjectManager *inspector_object_manager;
    axlInspectorToolManager *inspector_tool_manager;
    axlInspectorView *inspector_view;
    axlInspectorSidePane *side_pane;
    axlInspectorStack *stack;
    axlInspectorSettings *settings;
};

axlInspector::axlInspector(QWidget *parent) : QFrame(parent), d(new axlInspectorPrivate)
{

    Q_INIT_RESOURCE(axlGui);
    Q_INIT_RESOURCE(axelShader);

    d->controller = new axlInspectorObjectController();

    d->inspector_object_manager = new axlInspectorObjectManager(this);
    d->inspector_object_manager->setController(d->controller);

    d->inspector_tool_manager = new axlInspectorToolManager(this);
    d->inspector_tool_manager->setController(d->controller);

    d->inspector_view = new axlInspectorView(this);

    d->side_pane = new axlInspectorSidePane(this);

    //behavior

    connect(d->inspector_tool_manager, SIGNAL(update()), this, SIGNAL(update()));
    connect(d->inspector_tool_manager, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
    connect(d->inspector_tool_manager, SIGNAL(dataChanged(dtkAbstractData *)), this, SIGNAL(dataChanged(dtkAbstractData *)));
    connect(d->inspector_tool_manager, SIGNAL(dataChangedByControlPoints(dtkAbstractData *)), this, SIGNAL(dataChangedByControlPoints(dtkAbstractData *)));
    //    connect(d->inspector_tool_manager, SIGNAL(dataChangedByShader(dtkAbstractData*, QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
    //    connect(d->inspector_tool_manager, SIGNAL(dataChangedByShaderFromString(dtkAbstractData*, QString)), this, SIGNAL(dataChangedByShaderFromString(dtkAbstractData *, QString)));
    connect(d->inspector_tool_manager, SIGNAL(dataSetToRemove(QList<dtkAbstractData*>)), d->inspector_object_manager, SLOT(onDataRemoved(QList<dtkAbstractData*>)));
    connect(d->inspector_tool_manager, SIGNAL(dataSetToRemove(QList<dtkAbstractData*>)), this, SIGNAL(dataSetRemoved(QList<dtkAbstractData*>)));
    connect(d->inspector_tool_manager, SIGNAL(dataSetToRemove(QList<dtkAbstractData*>)), d->controller, SLOT(onDataRemoved(QList<dtkAbstractData*>)));
    connect(d->inspector_tool_manager, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData*>, QString)), d->inspector_object_manager, SLOT(onFieldsCreatedOnData(QList<axlAbstractData *>, QString)));
    connect(d->inspector_tool_manager, SIGNAL(modifiedProperty(dtkAbstractData*, int)), this, SIGNAL(modifiedProperty(dtkAbstractData*,int)));

    connect(d->inspector_object_manager, SIGNAL(stateChanged(dtkAbstractData*,int)), this, SIGNAL(stateChanged(dtkAbstractData*,int)));
    connect(d->inspector_object_manager, SIGNAL(actorVisibilityChanged(dtkAbstractData*,bool)), this, SIGNAL(actorVisibilityChanged(dtkAbstractData*,bool)));
    connect(d->inspector_object_manager, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
    //    connect(d->inspector_object_manager, SIGNAL(dataChangedByShader(dtkAbstractData*, QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
    //    connect(d->inspector_object_manager, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
    //    connect(d->inspector_object_manager, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
    connect(d->inspector_object_manager, SIGNAL(interpolationChanded(dtkAbstractData*,int)), this, SIGNAL(interpolationChanded(dtkAbstractData*,int)));

    connect(d->inspector_object_manager, SIGNAL(dataSetRemoved(QList<dtkAbstractData*>)), this, SIGNAL(dataSetRemoved(QList<dtkAbstractData*>)));
    connect(d->inspector_object_manager, SIGNAL(dataSetRemoved(QList<dtkAbstractData *>)), d->controller, SLOT(onDataRemoved(QList<dtkAbstractData*>)));
    //    connect(d->inspector_object_manager, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
    connect(d->inspector_object_manager, SIGNAL(modifiedProperty(dtkAbstractData*, int)), this, SIGNAL(modifiedProperty(dtkAbstractData*,int)));

    connect(d->inspector_object_manager, SIGNAL(update()), this, SIGNAL(update()));
    connect(d->inspector_object_manager, SIGNAL(showCurrentPoint(double, double, dtkAbstractData *)), this, SIGNAL(showCurrentPoint(double, double, dtkAbstractData *)));
    connect(d->inspector_object_manager, SIGNAL(hideCurrentPoint(double, double, dtkAbstractData *)), this, SIGNAL(hideCurrentPoint(double, double, dtkAbstractData *)));
    connect(d->inspector_object_manager, SIGNAL(moveCurrentPoint(double, double, dtkAbstractData *)), this, SIGNAL(moveCurrentPoint(double, double, dtkAbstractData *)));

    //    //useful for dynamic objects
    //    connect(d->inspector_tool_manager, SIGNAL(doubleInputInserted(QList<axlDouble*>)), d->inspector_object_manager, SLOT(onDoubleInputInserted(QList<axlDouble*>)));

    connect(d->side_pane, SIGNAL(showInspector(bool)), this, SLOT(onShowInspector(bool)));
    connect(d->side_pane, SIGNAL(worldCamera()), this, SIGNAL(worldCamera()));
    connect(d->side_pane, SIGNAL(objectCamera()), this, SIGNAL(objectCamera()));
    connect(d->side_pane, SIGNAL(trackballCamera()), this, SIGNAL(trackballCamera()));
    connect(d->side_pane, SIGNAL(joystickCamera()), this, SIGNAL(joystickCamera()));
    connect(d->side_pane, SIGNAL(showSettings(bool)), this, SLOT(onShowSettings(bool)));
    connect(d->side_pane, SIGNAL(switchFullScreen()), this, SIGNAL(switchFullScreen()));

    d->stack = new axlInspectorStack(this);
    d->stack->setFixedWidth(0);
    d->stack->addWidget("object", d->inspector_object_manager);
    d->stack->addWidget("tool", d->inspector_tool_manager);
    d->stack->addWidget("view", d->inspector_view);

    d->settings = new axlInspectorSettings(this);
    d->settings->setFixedWidth(0);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(d->side_pane);
    layout->addWidget(d->stack);
    layout->addWidget(d->settings);

    this->setStyleSheet(dtkReadFile(":axlGui/axlInspector.qss"));
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}

axlInspector::~axlInspector(void)
{
    delete d;

    d = NULL;
}

QSize axlInspector::sizeHint(void) const
{
    return d->stack->size() + d->side_pane->size();
}

void axlInspector::insertDataSet(QList<axlAbstractData *> dataSet)
{
    foreach(axlAbstractData *data, dataSet)
        d->inspector_object_manager->insert(data);

    d->inspector_object_manager->resizeColumnToContents();
}

void axlInspector::insertData(axlAbstractData *data)
{
    d->inspector_object_manager->insert(data);
    d->inspector_object_manager->resizeColumnToContents();
}

void axlInspector::removeData(dtkAbstractData *data){
    d->inspector_object_manager->removeData(data);
}

QList<dtkAbstractData *> axlInspector::dataSet(void)
{
    return d->inspector_object_manager->dataSet();
}

void axlInspector::setView(axlAbstractView *view)
{
    d->inspector_object_manager->setView(view);
    d->inspector_tool_manager->setView(view);
    d->inspector_view->setView(view);
}

void axlInspector::updateView()
{
    d->inspector_view->updateView();
}

void axlInspector::sendFieldSignal(QList<axlAbstractData *>dataSet, QString fieldName){
    d->inspector_object_manager->onFieldOpened(dataSet, fieldName);
   //d->inspector_object_manager->onFieldsCreatedOnData(dataSet, fieldName);

}

void axlInspector::onStateChanged(dtkAbstractData *data ,int mode)
{
    d->inspector_object_manager->onStateChanged(data, mode);
}

void axlInspector::onShowInspector(bool show)
{
    QPropertyAnimation *animation = new QPropertyAnimation(d->stack, "width");
    animation->setDuration(600);
    animation->setStartValue(0);
    animation->setEndValue(300);
    if(show) {
        // animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->setDirection(QAbstractAnimation::Forward);
    } else {
        //        animation->setEasingCurve(QEasingCurve::InBounce);
        animation->setDirection(QAbstractAnimation::Backward);
    }
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void axlInspector::onShowSettings(bool show)
{
    QPropertyAnimation *animation = new QPropertyAnimation(d->settings, "width");
    animation->setDuration(600);
    animation->setStartValue(0);
    animation->setEndValue(300);
    if(show) {
        //     animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->setDirection(QAbstractAnimation::Forward);
    } else {
        //    animation->setEasingCurve(QEasingCurve::InBounce);
        animation->setDirection(QAbstractAnimation::Backward);
    }
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void axlInspector::clearScene(void){
    d->inspector_object_manager->clearScene();
}
