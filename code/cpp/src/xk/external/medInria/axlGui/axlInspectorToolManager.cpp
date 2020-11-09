/* axlInspectorToolManager.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 19:39:10 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:19:11 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 167
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorTool.h"

#include "axlInspectorToolManager.h"
#include "axlInspectorToolManager_p.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorSeparator.h"

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <dtkCoreSupport/dtkPlugin.h>
#include <dtkCoreSupport/dtkPluginManager.h>

#include <dtkGuiSupport/dtkTagCloud.h>

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManagerView
// /////////////////////////////////////////////////////////////////

axlInspectorToolManagerView::axlInspectorToolManagerView(QWidget *parent) : QTreeWidget(parent)
{
    this->setAlternatingRowColors(false);
    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setColumnHidden(1, true);
    this->setFrameShape(QFrame::NoFrame);
    this->setHeaderHidden(true);

    connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), this, SLOT(onItemDoubleClicked(QTreeWidgetItem *, int)));
}

axlInspectorToolManagerView::~axlInspectorToolManagerView(void)
{

}

void axlInspectorToolManagerView::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    DTK_UNUSED(column);

    emit clicked(item->text(0), item->text(1));
}

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManagerController helper
// /////////////////////////////////////////////////////////////////
static bool filterNum3sisPlugins(QString item_name)
{
    QRegExp rx("^num[A-Z]");

    if(!(rx.indexIn(item_name) == 0))
        return true;
    else
        return false;
}

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManagerController
// /////////////////////////////////////////////////////////////////

axlInspectorToolManagerController::axlInspectorToolManagerController(QObject *parent) : QObject(parent)
{
    this->view = NULL;
    this->cloud = NULL;
    this->scope = NULL;
    this->union_mode = false;

}

axlInspectorToolManagerController::~axlInspectorToolManagerController(void)
{

}

void axlInspectorToolManagerController::attach(axlInspectorToolManagerView *view)
{
    this->view = view;
}

void axlInspectorToolManagerController::attach(dtkTagCloud *cloud)
{
    this->cloud = cloud;

    connect(this->cloud, SIGNAL(tagClicked(QString)), this, SLOT(setFilter(QString)));
}

void axlInspectorToolManagerController::attach(dtkTagScope *scope)
{
    this->scope = scope;

    connect(this->scope, SIGNAL(tagSet(QString)),   this, SLOT(setFilter(QString)));
    connect(this->scope, SIGNAL(tagAdded(QString)), this, SLOT(addFilter(QString)));
    connect(this->scope, SIGNAL(cleared(void)), this, SLOT(clear()));
    connect(this->scope, SIGNAL(unionMode(bool)), this, SLOT(onUnionMode(bool)));
}

void axlInspectorToolManagerController::addItem(QString name)
{
    this->items << dtkItem(name, "", QStringList());

    this->update();
    this->render();
}

void axlInspectorToolManagerController::addItem(QString name, QString description)
{
    this->items << dtkItem(name, description, QStringList());

    this->update();
    this->render();
}

void axlInspectorToolManagerController::addItem(QString name, QString description, QStringList tags)
{
    this->items << dtkItem(name, description, tags);

    this->update();
    this->render();
}

// void axlInspectorToolManagerController::addItem(QString name, QString description, QStringList tags, QStringList types)
// {
//     this->items << dtkItem(name, description, tags, types);

//     this->update();
//     this->render();
// }

void axlInspectorToolManagerController::update(void)
{
    this->tags.clear();

    QHash<QString, QStringList> tags;

    foreach(dtkItem item, this->items)
        foreach(QString tag, item.tags())
            tags[tag] << item.name();

    foreach(QString tag, tags.keys())
        this->tags << dtkTag(tag, tags[tag].count(), tags[tag]);
}

static bool axlInspectorToolManagerControllerFilter(QStringList l1, QStringList l2)
{
    QStringList ll1; foreach(QString s1, l1) ll1 << s1.toLower();
    QStringList ll2; foreach(QString s2, l2) ll2 << s2.toLower();

    bool pass = true;

    foreach(QString s, ll1)
        if(!ll2.contains(s))
            pass = false;

    return pass;
}

void axlInspectorToolManagerController::clear(void)
{
    this->filters.clear();

    this->render();
}


void axlInspectorToolManagerController::onUnionMode(bool mode){

    this->union_mode = !mode;
    this->render();
}

static bool intersect(QStringList l1, QStringList l2) {
    bool pass = true;
    foreach(QString s, l1) if(!l2.contains(s)) pass = false;
    return pass;
}

static bool unite(QStringList l1, QStringList l2) {
    if(l1.isEmpty()) return true;
    bool pass = false;
    foreach(QString s, l1) if(l2.contains(s)) pass = true;
    return pass;
}

void axlInspectorToolManagerController::render(void)
{
    this->tags.clear();

    //    if (this->view) {
    //        this->view->clear();
    //        foreach(dtkItem item, this->items)
    //            if(axlInspectorToolManagerControllerFilter(this->filters, item.tags()))
    //                this->view->addTopLevelItem(new QTreeWidgetItem(this->view, QStringList() << item.name() << item.description()));

    //    if (this->cloud) {
    //        this->cloud->clear();

    //        for(int i = 0 ; i < this->tags.count(); i++)
    //            this->cloud->addTag(this->tags.at(i));
    //        this->cloud->render();
    //    }

    //    if (this->scope) {
    //        this->scope->clear();
    //        foreach(QString filter, this->filters)
    //            this->scope->addTag(filter);
    //        this->scope->render();
    //    }

    QHash<QString, QStringList> tags;

    foreach(dtkItem item, this->items)
        foreach(QString tag, item.tags())
            tags[tag] << item.name();

    foreach(QString tag, tags.keys())
        this->tags << dtkTag(tag, tags[tag].count(), tags[tag]);


    if (this->view) {
        this->view->clear();
        foreach(dtkItem item, this->items)
            if((this->union_mode && unite(this->filters, item.tags())) || (!this->union_mode && intersect(this->filters, item.tags())) || axlInspectorToolManagerControllerFilter(this->filters, item.tags()))
                this->view->addTopLevelItem(new QTreeWidgetItem(this->view, QStringList() << item.name() << item.description()));
    }

    if (this->cloud) {
        this->cloud->clear();
        foreach(dtkTag tag, this->tags)
            this->cloud->addTag(tag);
        this->cloud->render();
    }

    if (this->scope) {
        this->scope->clear();
        foreach(QString filter, this->filters){
            if(filter.at(0).isLower())
                filter.replace(0,1,filter.at(0).toUpper());
            this->scope->addTag(filter, tags[filter].count());
        }
        this->scope->render();
    }

    if (this->scope)
        this->scope->setTags(tags.keys());
}

void axlInspectorToolManagerController::addFilter(QString filter)
{
    this->filters << filter;

    this->render();
}

void axlInspectorToolManagerController::setFilter(QString filter)
{
    this->filters.clear();
    this->filters << filter;

    this->render();
}

// /////////////////////////////////////////////////////////////////
// axlInspectorToolManager
// /////////////////////////////////////////////////////////////////

static QString axlInspectorToolManager_cloud_stylesheet =
        "body      { color: rgb(230, 230, 230); background-color: rgb(230, 230, 230); }"
        "a:link    { color: rgb(70, 70, 70); text-decoration:none; }"
        "a:active  { color: rgb(70, 70, 70); text-decoration:none; }"
        "a:hover   { color: rgb(90, 90, 90); text-decoration:none; }";

static QString axlInspectorToolManager_scope_stylesheet =
        "body { background-color: rgb(230, 230, 230); }"
        "input.text { background-color: rgb(230, 230, 230); border: 1px solid rgb(100, 100, 100); }";

axlInspectorToolManager::axlInspectorToolManager(QWidget *parent) : QFrame(parent), d(new axlInspectorToolManagerPrivate)
{
    d->cloud = new dtkTagCloud(this);
    d->cloud->setSortingType(dtkTagCloud::Alpha);
    d->cloud->setSortingOrder(dtkTagCloud::Asc);
    d->cloud->setFontSize(18);
    d->cloud->setFontRange(10);
    d->cloud->setMinimumHeight(100);
    d->cloud->setMinimumWidth(300);
    d->cloud->setMaximumHeight(130);
    d->cloud->setStyleSheet(axlInspectorToolManager_cloud_stylesheet);
    d->cloud->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    d->scope = new dtkTagScope(this);
    d->scope->setStyleSheet(axlInspectorToolManager_scope_stylesheet);

    d->view = new axlInspectorToolManagerView(this);
    d->view->setMinimumHeight(25);
    d->view->setMinimumWidth(300);
    d->view->setMaximumHeight(400);
    d->view->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    d->view->setSortingEnabled(1);
    d->view->header()->setSortIndicator(0, Qt::AscendingOrder);

    d->inspector_tool = new axlInspectorTool(this);
    d->inspector_tool->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    d->controller = new axlInspectorToolManagerController(this);
    d->controller->attach(d->view);
    d->controller->attach(d->scope);
    d->controller->attach(d->cloud);

    QStringList interfaceList;

    foreach(QString interface_name, dtkAbstractProcessFactory::instance()->interfaces())
    {
        if(!interfaceList.contains(interface_name) )
        {
            interfaceList << interface_name;

            foreach(QString implementation, dtkAbstractProcessFactory::instance()->implementations(interface_name))
            {
                if(filterNum3sisPlugins(implementation))
                    d->controller->addItem(implementation, interface_name, QStringList() << interface_name.remove("axlAbstract"));
            }
        }
    }

    // registered of atomics data
    d->controller->addItem("axlCircleArcCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlConeCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlCylinderCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlDataDynamicCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlEllipsoidCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlLineCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlPlaneCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlPointCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    //d->controller->addItem("axlCreatePointSet", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlSphereCreator", "axlAbstractCreator", QStringList() << QString("Creator"));
    d->controller->addItem("axlTorusCreator", "axlAbstractCreator", QStringList() << QString("Creator"));



    //d->controller->addItem("axlCreateBSplineCurve", "axlAbstractCreator", QStringList() << QString("Creator"));
    //d->controller->addItem("axlCreateBSplineSurface", "axlAbstractCreator", QStringList() << QString("Creator"));

    //d->controller->addItem("axlProcessSpatialDistanceField", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Spatial" << "Distance");
    //d->controller->addItem("axlProcessZScalarField", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "ZScalar");
    //d->controller->addItem("axlProcessTangentVectorField", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Tangent" << "Vector");
    d->controller->addItem("axlBarycenterProcess", "axlAbstractProcess", QStringList() << "Barycenter");
    d->controller->addItem("axlIntersection", "axlAbstractProcess", QStringList() << "Intersection");
    d->controller->addItem("axlProcessProjection", "axlAbstractProcess", QStringList() << "Projection");

    d->controller->addItem("axlFieldSpatialCoordinatesCreator", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Creator");
    d->controller->addItem("axlFieldSpatialPointDistanceCreator", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Spatial" << "Distance" << "Creator");
    d->controller->addItem("axlFieldParametricNormalVectorCreator", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Parametric"<< "Creator");
    d->controller->addItem("axlFieldParametricCurveTangentVectorCreator", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Parametric"<< "Creator");
    d->controller->addItem("axlFieldParametricSurfaceTangentVectorCreator", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Parametric"<< "Creator");
    d->controller->addItem("axlFieldParametricVolumeTangentVectorCreator", "axlAbstractProcess", QStringList() << "FieldGenerator" << "Field" << "Generator" << "Parametric"<< "Creator");



    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(d->cloud);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(d->scope);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(d->view);
    layout->addWidget(new axlInspectorSeparator(this));

    layout->addWidget(d->inspector_tool);


    connect(d->view, SIGNAL(clicked(QString, QString)), this, SIGNAL(selected(QString, QString)));
    connect(d->inspector_tool, SIGNAL(update()), this, SIGNAL(update()));
    connect(d->inspector_tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
    connect(d->inspector_tool, SIGNAL(dataSetToRemove(QList<dtkAbstractData*>)), this, SIGNAL(dataSetToRemove(QList<dtkAbstractData*>)));
    connect(d->inspector_tool, SIGNAL(dataChanged(dtkAbstractData *)), this, SIGNAL(dataChanged(dtkAbstractData *)));
    connect(d->inspector_tool, SIGNAL(dataChangedByControlPoints(dtkAbstractData *)), this, SIGNAL(dataChangedByControlPoints(dtkAbstractData *)));
    //    connect(d->inspector_tool, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData * ,QString)));
    //    connect(d->inspector_tool, SIGNAL(dataChangedByShaderFromString(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShaderFromString(dtkAbstractData * ,QString)));
    connect(d->inspector_tool, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData*>, QString)), this, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData*>, QString)));
    //    connect(d->inspector_tool, SIGNAL(doubleInputInserted(QList<axlDouble*>)), this, SIGNAL(doubleInputInserted(QList<axlDouble*>)));
    connect(d->inspector_tool, SIGNAL(modifiedProperty(dtkAbstractData*,int)), this, SIGNAL(modifiedProperty(dtkAbstractData*,int)));
    connect(this, SIGNAL(selected(QString,QString)), d->inspector_tool, SLOT(onProcessSelected(QString,QString)));
}

axlInspectorToolManager::~axlInspectorToolManager(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorToolManager::sizeHint(void) const
{
    return QSize(300, 1000);
}

void axlInspectorToolManager::setController(axlInspectorObjectController *controller)
{
    d->ObjectController = controller;
    d->inspector_tool->setController(controller);
}

void axlInspectorToolManager::setView(axlAbstractView *view)
{
    d->inspector_tool->setView(view);
}
