/* axlInspectorObject.cpp --- 
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 19:39:54 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 28 17:07:33 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 48
 */

/* Commentary: 
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObject.h"
#include "axlInspectorObjectComposite.h"
#include "axlInspectorObjectFactory.h"
#include "axlInspectorObjectSet.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectCone.h"
#include "axlInspectorObjectCylinder.h"
#include "axlInspectorObjectEllipsoid.h"
#include "axlInspectorObjectLine.h"
#include "axlInspectorObjectMesh.h"
#include "axlInspectorObjectPlane.h"
#include "axlInspectorObjectPoint.h"
#include "axlInspectorObjectSphere.h"
#include "axlInspectorObjectTorus.h"
#include "axlInspectorObjectDataDynamic.h"
#include "axlInspectorObjectCircleArc.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkGlobal.h>

#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractCurveBSpline.h>
#include <axlCore/axlAbstractDataComposite.h>
#include <axlCore/axlAbstractSurfaceBSpline.h>
#include <axlCore/axlCone.h>
#include <axlCore/axlCylinder.h>
#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlPlane.h>
#include <axlCore/axlSphere.h>
#include <axlCore/axlTorus.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlCircleArc.h>
#include <axlCore/axlAbstractCurveParametric.h>
#include <axlCore/axlAbstractSurfaceParametric.h>
#include <axlCore/axlAbstractVolumeParametric.h>
//#include <axlCore/axlAbstractVisitor.h>
//#include <axlCore/axlAbstractVisitorParametric.h>


#include <QtDebug>

class axlInspectorObjectPrivate
{
public:
    axlInspectorObjectController *controller;
};

axlInspectorObject::axlInspectorObject(QWidget *parent) : QScrollArea(parent), d(new axlInspectorObjectPrivate)
{
    d->controller = NULL;

    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setFrameShape(QFrame::NoFrame);
    this->setWidgetResizable(true);
}

axlInspectorObject::~axlInspectorObject(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObject::onDataSelected(dtkAbstractData *data)
{
    if (axlInspectorObjectInterface *widget = axlInspectorObjectFactory::instance()->create(data->identifier()))
    {
        widget->setData(data);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        connect(widget, SIGNAL(tubeFilterRadiusChanged(dtkAbstractData *, double)), this, SIGNAL(tubeFilterRadiusChanged(dtkAbstractData *, double)));

        widget->setAttribute(Qt::WA_DeleteOnClose);
    }
    else if(axlDataDynamic *dataDynamic = dynamic_cast<axlDataDynamic *>(data)) {
        axlInspectorObjectDataDynamic *widget = new axlInspectorObjectDataDynamic(this);
        widget->setData(dataDynamic);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        //connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        //connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }
    else if(axlAbstractDataComposite *composite = dynamic_cast<axlAbstractDataComposite *>(data)) {
        axlInspectorObjectComposite *widget = new axlInspectorObjectComposite(this);
        widget->setData(composite);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlCone *cone = dynamic_cast<axlCone *>(data)) {
        axlInspectorObjectCone *widget = new axlInspectorObjectCone(this);
        widget->setData(cone);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //       // connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlCylinder *cylinder = dynamic_cast<axlCylinder *>(data)) {
        axlInspectorObjectCylinder *widget = new axlInspectorObjectCylinder(this);
        widget->setData(cylinder);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //       // connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlTorus *torus = dynamic_cast<axlTorus *>(data)) {
        axlInspectorObjectTorus *widget = new axlInspectorObjectTorus(this);
        widget->setData(torus);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlCircleArc *arc = dynamic_cast<axlCircleArc *>(data)) {
        axlInspectorObjectCircleArc *widget = new axlInspectorObjectCircleArc(this);
        widget->setData(arc);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlEllipsoid *ellipsoid = dynamic_cast<axlEllipsoid *>(data)) {
        axlInspectorObjectEllipsoid *widget = new axlInspectorObjectEllipsoid(this);
        widget->setData(ellipsoid);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //       // connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlLine *line = dynamic_cast<axlLine *>(data)) {
        axlInspectorObjectLine *widget = new axlInspectorObjectLine(this);
        widget->setData(line);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlPlane *plane = dynamic_cast<axlPlane *>(data)) {
        axlInspectorObjectPlane *widget = new axlInspectorObjectPlane(this);
        widget->setData(plane);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        //connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlPoint *point = dynamic_cast<axlPoint *>(data)) {
        axlInspectorObjectPoint *widget = new axlInspectorObjectPoint(this);
        widget->setData(point);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }

    else if(axlSphere *pointSet = dynamic_cast<axlSphere *>(data)) {
        axlInspectorObjectSphere *widget = new axlInspectorObjectSphere(this);
        widget->setData(pointSet);
        this->setWidget(widget);
        //        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }
    else if(axlAbstractData *dt = dynamic_cast<axlAbstractData *>(data)) {

        //We don't make any difference between data and mesh for the basic inspector...
        axlInspectorObjectMesh *widget = new axlInspectorObjectMesh(this);
        widget->setData(dt);
        this->setWidget(widget);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        //        connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        connect(widget, SIGNAL(interpolationChanded(dtkAbstractData*,int)), this, SIGNAL(interpolationChanded(dtkAbstractData*,int)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData *, int)), this, SIGNAL(modifiedProperty(dtkAbstractData *, int)));
        widget->setAttribute(Qt::WA_DeleteOnClose);
        // }
    }

    //    else if(axlMesh *mesh = dynamic_cast<axlMesh *>(data)) {
    //        axlInspectorObjectMesh *widget = new axlInspectorObjectMesh(this);
    //        widget->setData(mesh);
    //        this->setWidget(widget);
    //        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
    //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
    //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
    //        connect(widget, SIGNAL(updateStateColor(dtkAbstractData*,int)), this, SIGNAL(updateStateColor(dtkAbstractData*,int)));
    //        widget->setAttribute(Qt::WA_DeleteOnClose);
    //    }

}

void axlInspectorObject::onDataSetSelected(QList<dtkAbstractData *> dataSet)
{
    if(dataSet.size() == 0) //If we have only data selected, we can use the onDataSelected Method
    {
        if(this->widget())
            this->widget()->close();
    }
    if(dataSet.size() == 1) //If we have only data selected, we can use the onDataSelected Method
    {
        this->onDataSelected(dataSet.first());
    }
    else if(dataSet.size() > 1)
    {
        axlInspectorObjectSet *widget = new axlInspectorObjectSet(this);
        connect(widget, SIGNAL(update()), this, SIGNAL(update()));
        //        connect(widget, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData *, QString)));
        //        connect(widget, SIGNAL(dataChangedByOpacity(dtkAbstractData*, double)), this, SIGNAL(dataChangedByOpacity(dtkAbstractData *, double)));
        //        connect(widget, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)), this, SIGNAL(dataChangedByColor(dtkAbstractData *, double, double, double)));
        connect(widget, SIGNAL(dataChangedByGeometry(dtkAbstractData *)), this, SIGNAL(dataChangedByGeometry(dtkAbstractData *)));
        //        connect(widget, SIGNAL(dataChangedBySize(dtkAbstractData*, double)), this, SIGNAL(dataChangedBySize(dtkAbstractData *, double)));
        connect(widget, SIGNAL(modifiedProperty(dtkAbstractData*, int)), this, SIGNAL(modifiedProperty(dtkAbstractData*, int)));

        widget->setData(dataSet);
        this->setWidget(widget);
        widget->setAttribute(Qt::WA_DeleteOnClose);
    }
}


void axlInspectorObject::onDataSetRemoved(QList<dtkAbstractData *> dataSetRemoved)
{
    if(this->widget())
        this->widget()->close();
}

void axlInspectorObject::setController(axlInspectorObjectController *controller)
{   
    d->controller = controller;
}
