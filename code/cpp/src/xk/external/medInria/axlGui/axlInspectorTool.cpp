/* axlInspectorTool.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 19:39:54 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 15:08:23 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 72
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorTool.h"
#include "axlInspectorToolCreatorEllipsoid.h"
#include "axlInspectorToolCreatorLine.h"
#include "axlInspectorToolCreatorPlane.h"
#include "axlInspectorToolCreatorPoint.h"
//#include "axlInspectorToolCreatorPointSet.h"
#include "axlInspectorToolCreatorSphere.h"
#include "axlInspectorToolCreatorCone.h"
#include "axlInspectorToolCreatorCylinder.h"
#include "axlInspectorToolCreatorTorus.h"
#include "axlInspectorToolCreatorCircleArc.h"
#include "axlInspectorToolCreatorDataDynamicDialog.h"

#include "axlInspectorToolFactory.h"
#include "axlInspectorToolGeneric.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorToolFieldGenerator.h"

#include <axlCore/axlAbstractView.h>
#include <axlCore/axlPoint.h>

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkCoreSupport/dtkGlobal.h>

#include <QtDebug>

class axlInspectorToolPrivate
{
public:
    axlAbstractView *view;
    axlInspectorObjectController *controller;
};

axlInspectorTool::axlInspectorTool(QWidget *parent) : QScrollArea(parent), d(new axlInspectorToolPrivate)
{
    d->controller = NULL;
    d->view = NULL;

    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setFrameShape(QFrame::NoFrame);
    this->setWidgetResizable(true);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
}

axlInspectorTool::~axlInspectorTool(void)
{
    delete d;

    d = NULL;
}

void axlInspectorTool::onCloseProcessDialog(void){
    QObject * obj = QObject::sender();

    if(axlInspectorToolInterface *tool = dynamic_cast<axlInspectorToolInterface *>(obj)){
        tool->setVisible(false);
        disconnect(tool, SIGNAL(dataChanged(dtkAbstractData*)), this, SIGNAL(dataChanged(dtkAbstractData *)));
        disconnect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), d->view, SLOT(onUpdateActorField(QList<axlAbstractData *>, QString)));
        disconnect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), this, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData *>, QString)));
        disconnect(tool, SIGNAL(dataInserted(axlAbstractData*)), this, SIGNAL(dataInserted(axlAbstractData*)));
        disconnect(tool, SIGNAL(dataChangedByControlPoints(dtkAbstractData*)), this, SIGNAL(dataChangedByControlPoints(dtkAbstractData *)));
        disconnect(tool, SIGNAL(modifiedProperty(dtkAbstractData*,int)), this, SIGNAL(modifiedProperty(dtkAbstractData * ,int)));

        disconnect(tool, SIGNAL(dataSetToRemove(QList<dtkAbstractData *>)), this, SIGNAL(dataSetToRemove(QList<dtkAbstractData *>)));
        disconnect(tool, SIGNAL(update()), this, SIGNAL(update()));
        disconnect(tool, SIGNAL(finished()),this, SLOT(onCloseProcessDialog()));
        delete tool;
        tool = NULL;
    }

}

void axlInspectorTool::onProcessSelected(QString implementation, QString interface_name)
{

    axlInspectorToolInterface *tool = axlInspectorToolFactory::instance()->create(implementation);

    if (tool && !dynamic_cast<axlInspectorToolCreator *>(tool)) {
        //qDebug()<< " axlInspectorTool::onProcessSelected";
        if(d->controller)
            tool->setController(d->controller);
        else
            if(d->view)
                tool->setView(d->view);


        connect(tool, SIGNAL(dataChanged(dtkAbstractData*)), this, SIGNAL(dataChanged(dtkAbstractData *)));
        connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), d->view, SLOT(onUpdateActorField(QList<axlAbstractData *>, QString)));
        connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), this, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData *>, QString)));
        //        connect(tool, SIGNAL(dataChangedByShader(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShader(dtkAbstractData * ,QString)));
        //        connect(tool, SIGNAL(dataChangedByShaderFromString(dtkAbstractData*,QString)), this, SIGNAL(dataChangedByShaderFromString(dtkAbstractData * ,QString)));
        connect(tool, SIGNAL(dataInserted(axlAbstractData*)), this, SIGNAL(dataInserted(axlAbstractData*)));
        connect(tool, SIGNAL(dataChangedByControlPoints(dtkAbstractData*)), this, SIGNAL(dataChangedByControlPoints(dtkAbstractData *)));
        connect(tool, SIGNAL(modifiedProperty(dtkAbstractData*,int)), this, SIGNAL(modifiedProperty(dtkAbstractData * ,int)));

        connect(tool, SIGNAL(dataSetToRemove(QList<dtkAbstractData *>)), this, SIGNAL(dataSetToRemove(QList<dtkAbstractData *>)));
        connect(tool, SIGNAL(update()), this, SIGNAL(update()));
        connect(tool, SIGNAL(finished()),this, SLOT(onCloseProcessDialog()));


                if(!(interface_name == "FieldGenerator")) {
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }
        tool->setImplementation(implementation);

        if(interface_name == "FieldGenerator") {
            connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), d->view, SLOT(onUpdateActorField(QList<axlAbstractData *>, QString)));
            connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), this, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData *>, QString)));
            //connect(tool->getProcess(), SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)), tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)));

        }
        this->setWidget(tool);


    } else if(interface_name == "axlAbstractCreator") {

        if(implementation == "axlLineCreator") {

            axlInspectorToolCreatorLine *tool = new axlInspectorToolCreatorLine(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

        else if(implementation == "axlConeCreator") {

            axlInspectorToolCreatorCone *tool = new axlInspectorToolCreatorCone(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            //            //useful for dynamic objects
            //            connect(tool,SIGNAL(doubleInputInserted(QList<axlDouble*>)), this, SIGNAL(doubleInputInserted(QList<axlDouble*>)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

        else if(implementation == "axlCylinderCreator") {

            axlInspectorToolCreatorCylinder *tool = new axlInspectorToolCreatorCylinder(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            //            //useful for dynamic objects
            //            connect(tool,SIGNAL(doubleInputInserted(QList<axlDouble*>)), this, SIGNAL(doubleInputInserted(QList<axlDouble*>)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

        else if(implementation == "axlTorusCreator") {

            axlInspectorToolCreatorTorus *tool = new axlInspectorToolCreatorTorus(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            //            //useful for dynamic objects
            //            connect(tool,SIGNAL(doubleInputInserted(QList<axlDouble*>)), this, SIGNAL(doubleInputInserted(QList<axlDouble*>)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }


        else if(implementation == "axlCircleArcCreator") {

            axlInspectorToolCreatorCircleArc *tool = new axlInspectorToolCreatorCircleArc(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

        else if(implementation == "axlEllipsoidCreator") {

            axlInspectorToolCreatorEllipsoid *tool = new axlInspectorToolCreatorEllipsoid(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }


        else if(implementation == "axlPlaneCreator") {

            axlInspectorToolCreatorPlane *tool = new axlInspectorToolCreatorPlane(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }


        if(implementation == "axlPointCreator") {

            axlInspectorToolCreatorPoint *tool = new axlInspectorToolCreatorPoint(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData *)), this, SIGNAL(dataInserted(axlAbstractData *)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

        //        if(implementation == "axlCreatePointSet") {

        //            axlInspectorToolCreatorPointSet *tool = new axlInspectorToolCreatorPointSet(this);

        //            if(d->controller)
        //                tool->setController(d->controller);
        //            else
        //                qDebug()<<"No controller founded for InspectorTool";

        //            connect(tool, SIGNAL(dataInserted(axlAbstractData*)), this, SIGNAL(dataInserted(axlAbstractData*)));
        //            this->setWidget(tool);
        //            tool->setAttribute(Qt::WA_DeleteOnClose);
        //        }
        if(implementation == "axlSphereCreator") {

            axlInspectorToolCreatorSphere *tool = new axlInspectorToolCreatorSphere(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData*)), this, SIGNAL(dataInserted(axlAbstractData*)));
            //            //useful for dynamic objects
            //            connect(tool,SIGNAL(doubleInputInserted(QList<axlDouble*>)), this, SIGNAL(doubleInputInserted(QList<axlDouble*>)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

        if(implementation == "axlDataDynamicCreator") {

            axlInspectorToolCreatorDataDynamicDialog *tool = new axlInspectorToolCreatorDataDynamicDialog(this);

            if(d->controller)
                tool->setController(d->controller);
            else
                qDebug()<<"No controller founded for InspectorTool";

            connect(tool, SIGNAL(dataInserted(axlAbstractData*)), this, SIGNAL(dataInserted(axlAbstractData*)));
            this->setWidget(tool);
            tool->setAttribute(Qt::WA_DeleteOnClose);
        }

    }


    else if(interface_name == "FieldGenerator") {

        axlInspectorToolFieldGenerator *tool = new axlInspectorToolFieldGenerator(this);

        if(d->controller)
            tool->setController(d->controller);
        else
            qDebug()<<"No controller founded for InspectorTool";

        connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), d->view, SLOT(onUpdateActorField(QList<axlAbstractData *>, QString)));
        connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), this, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData *>, QString)));

        this->setWidget(tool);
        //tool->setAttribute(Qt::WA_DeleteOnClose);
        tool->setImplementation(implementation);
        //tool->setParent(this);
    }

    else /*if(interface_name == "axlAbstractProcess")*/{
        //qDebug() << Q_FUNC_INFO << implementation << interface_name;
        //        if(d->controller)
        axlInspectorToolGeneric *tool = new axlInspectorToolGeneric(implementation,d->controller, this);
        //        else
        //            qDebug() << Q_FUNC_INFO << implementation << interface_name << "no controller";

        //fields display
        connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), d->view, SLOT(onUpdateActorField(QList<axlAbstractData *>, QString)));
        connect(tool, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData*>, QString)), this, SIGNAL(fieldsCreatedOnData(QList<axlAbstractData *>, QString)));
        //data inserted in view
        connect(tool, SIGNAL(dataInserted(axlAbstractData*)), this, SIGNAL(dataInserted(axlAbstractData*)));
        this->setWidget(tool);

    }

    if (this->widget() && this->widget()->layout()) {
        this->widget()->layout()->setAlignment(Qt::AlignTop);
    }
}

void axlInspectorTool::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
}

void axlInspectorTool::setView(axlAbstractView *view)
{
    d->view = view;
}
