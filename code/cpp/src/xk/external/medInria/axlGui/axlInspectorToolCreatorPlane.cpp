/* axlInspectorToolCreatorPlane.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Mar 16 17:19:51 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:38:31 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorToolCreatorPlane.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlPlane.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlPlaneCreator.h>

#include <QtGui>

class axlInspectorToolCreatorPlanePrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *spinBoxCoordinatePoint_x;
    QDoubleSpinBox *spinBoxCoordinatePoint_y;
    QDoubleSpinBox *spinBoxCoordinatePoint_z;

    QDoubleSpinBox *spinBoxCoordinateNormal_x;
    QDoubleSpinBox *spinBoxCoordinateNormal_y;
    QDoubleSpinBox *spinBoxCoordinateNormal_z;

    QGroupBox *coordinates;

    QLabel *messageToDisplay;
};

axlInspectorToolCreatorPlane::axlInspectorToolCreatorPlane(QWidget *parent) : axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorPlanePrivate)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    //OPACITY//
    d->sliderOpacity = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *layoutOpacity = new QHBoxLayout;
    layoutOpacity->addWidget(new QLabel("Opacity",this));
    layoutOpacity->addWidget(d->sliderOpacity);
    d->sliderOpacity->setMaximum(100);

    //COLOR//
    d->colorButton = new dtkColorButton(this);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
    layoutColorButton->addWidget(new QLabel("Color",this));
    layoutColorButton->addWidget(d->colorButton);
    d->colorButton->setColor(QColor("#a0a0a4"));


    QVBoxLayout *layoutCoordonate = new QVBoxLayout();
    QHBoxLayout *layoutCoordinatePoint_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordinatePoint_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordinatePoint_z = new QHBoxLayout();
    QLabel *labelCoordinatePoint_x = new QLabel("x",this);
    QLabel *labelCoordinatePoint_y = new QLabel("y",this);
    QLabel *labelCoordinatePoint_z = new QLabel("z",this);
    d->spinBoxCoordinatePoint_x = new QDoubleSpinBox(this);
    d->spinBoxCoordinatePoint_y = new QDoubleSpinBox(this);
    d->spinBoxCoordinatePoint_z = new QDoubleSpinBox(this);

    QHBoxLayout *layoutCoordinateNormal_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateNormal_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateNormal_z = new QHBoxLayout();
    QLabel *labelCoordinateNormal_x = new QLabel("x",this);
    QLabel *labelCoordinateNormal_y = new QLabel("y",this);
    QLabel *labelCoordinateNormal_z = new QLabel("z",this);
    d->spinBoxCoordinateNormal_x = new QDoubleSpinBox(this);
    d->spinBoxCoordinateNormal_y = new QDoubleSpinBox(this);
    d->spinBoxCoordinateNormal_z = new QDoubleSpinBox(this);

    d->spinBoxCoordinatePoint_x->setValue(0.0);
    d->spinBoxCoordinatePoint_y->setValue(0.0);
    d->spinBoxCoordinatePoint_z->setValue(0.0);
    d->spinBoxCoordinatePoint_x->setRange(-1000, 1000);
    d->spinBoxCoordinatePoint_y->setRange(-1000, 1000);
    d->spinBoxCoordinatePoint_z->setRange(-1000, 1000);
    layoutCoordinatePoint_x->addWidget(labelCoordinatePoint_x);
    layoutCoordinatePoint_x->addWidget(d->spinBoxCoordinatePoint_x);
    layoutCoordinatePoint_y->addWidget(labelCoordinatePoint_y);
    layoutCoordinatePoint_y->addWidget(d->spinBoxCoordinatePoint_y);
    layoutCoordinatePoint_z->addWidget(labelCoordinatePoint_z);
    layoutCoordinatePoint_z->addWidget(d->spinBoxCoordinatePoint_z);
    layoutCoordonate->addWidget(new QLabel("Point :", this));
    layoutCoordonate->addLayout(layoutCoordinatePoint_x);
    layoutCoordonate->addLayout(layoutCoordinatePoint_y);
    layoutCoordonate->addLayout(layoutCoordinatePoint_z);

    d->spinBoxCoordinateNormal_x->setValue(1.0);
    d->spinBoxCoordinateNormal_y->setValue(0.0);
    d->spinBoxCoordinateNormal_z->setValue(0.0);
    layoutCoordinateNormal_x->addWidget(labelCoordinateNormal_x);
    layoutCoordinateNormal_x->addWidget(d->spinBoxCoordinateNormal_x);
    layoutCoordinateNormal_y->addWidget(labelCoordinateNormal_y);
    layoutCoordinateNormal_y->addWidget(d->spinBoxCoordinateNormal_y);
    layoutCoordinateNormal_z->addWidget(labelCoordinateNormal_z);
    layoutCoordinateNormal_z->addWidget(d->spinBoxCoordinateNormal_z);
    layoutCoordonate->addWidget(new QLabel("Normal :", this));
    layoutCoordonate->addLayout(layoutCoordinateNormal_x);
    layoutCoordonate->addLayout(layoutCoordinateNormal_y);
    layoutCoordonate->addLayout(layoutCoordinateNormal_z);

    d->spinBoxCoordinatePoint_x->setSingleStep(0.1);
    d->spinBoxCoordinatePoint_y->setSingleStep(0.1);
    d->spinBoxCoordinatePoint_z->setSingleStep(0.1);
    d->spinBoxCoordinateNormal_x->setSingleStep(0.1);
    d->spinBoxCoordinateNormal_y->setSingleStep(0.1);
    d->spinBoxCoordinateNormal_z->setSingleStep(0.1);

    d->coordinates = new QGroupBox(tr("Enter coordinates"),this);
    d->coordinates->setLayout(layoutCoordonate);


    //message to display
    d->messageToDisplay = new QLabel("",this);
    axlPlaneCreator *creator = new axlPlaneCreator();
    d->messageToDisplay->setText(creator->description());
    delete creator;
    d->messageToDisplay->setStyleSheet("color: #ff0000;");


    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorPlane", this));
    //    layout->addLayout(layoutCoordonate);
    layout->addWidget(d->messageToDisplay);
    layout->addWidget(d->coordinates);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);
    d->coordinates->hide();
}

axlInspectorToolCreatorPlane::~axlInspectorToolCreatorPlane(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorPlane::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
    if(d->controller->size() < 2){
        d->messageToDisplay->hide();
        d->coordinates->show();
    }else{
        d->coordinates->hide();
        bool hasRigthType = false;
        int nbRigthType = 0;
        foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()){
            if(dynamic_cast<axlPoint *>(d->controller->data(item)))
                nbRigthType++;
            else if(dynamic_cast<axlDataDynamic *>(d->controller->data(item)))
                if(dynamic_cast<axlDataDynamic *>(d->controller->data(item))->outputs())
                    if(dynamic_cast<axlPoint *>(dynamic_cast<axlDataDynamic *>(d->controller->data(item))->outputs()))
                        nbRigthType++;
        }

        if(nbRigthType > 1)
            hasRigthType = true;
        if(!hasRigthType){
            d->messageToDisplay->hide();
            d->coordinates->show();
        }
    }
}

QList<axlAbstractData *> axlInspectorToolCreatorPlane::returnInputsList(void){
    QList<axlAbstractData *>list;
    if(d->coordinates->isVisible()){
        axlPoint *point = new axlPoint(d->spinBoxCoordinatePoint_x->value(), d->spinBoxCoordinatePoint_y->value(), d->spinBoxCoordinatePoint_z->value());
        axlPoint *normal = new axlPoint(d->spinBoxCoordinateNormal_x->value(), d->spinBoxCoordinateNormal_y->value(), d->spinBoxCoordinateNormal_z->value());

        list << point << normal;
    }
    return list;

}

void axlInspectorToolCreatorPlane::run(void)
{
    if(/*d->firstRun &&*/ !d->coordinates->isVisible()){
        d->messageToDisplay->show();
        axlPlaneCreator *creator = new axlPlaneCreator();
        int nbPoints = 0;
        if( d->controller->size() > 0){
            foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()){

                if(item->text(2) == "Selected"|| item->text(2) == "Editable")
                {
                    if(nbPoints < 2){
                        if(dynamic_cast<axlPoint *>(d->controller->data(item))) {
                            axlPoint *point = dynamic_cast<axlPoint *>(d->controller->data(item));
                            creator->setInput(point,nbPoints);
                            nbPoints++;
                        }
                    }else{
                        qDebug() << "To many inputs selected, only the two first points were used";
                    }
                }

            }
        }

        if(nbPoints == 2){
            creator->update();
            axlPlane *cylinder = dynamic_cast<axlPlane *>(creator->output());
            cylinder->setColor(d->colorButton->color());
            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
            cylinder->setOpacity(opacity);
            emit dataInserted(cylinder);
            d->coordinates->hide();


        }else {
            //display the coordinates to be chosen for the extremal points
            d->coordinates->show();
            d->messageToDisplay->hide();
        }
        delete creator;
    }else{
        d->messageToDisplay->hide();
        axlPoint *point = new axlPoint(d->spinBoxCoordinatePoint_x->value(), d->spinBoxCoordinatePoint_y->value(), d->spinBoxCoordinatePoint_z->value());
        axlPoint *normal = new axlPoint(d->spinBoxCoordinateNormal_x->value(), d->spinBoxCoordinateNormal_y->value(), d->spinBoxCoordinateNormal_z->value());



        axlPlane* plane = new axlPlane(point, normal);


        double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
        plane->setColor(d->colorButton->color());
        plane->setOpacity(opacity);
        emit dataInserted(plane);
    }
}

axlInspectorToolInterface *createaxlInspectorToolCreatorPlane(void)
{
    return new axlInspectorToolCreatorPlane;
}

