/* axlInspectorToolCreatorSphere.cpp ---
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

#include "axlInspectorToolCreatorSphere.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlSphere.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDouble.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlSphereCreator.h>

#include <QtGui>

class axlInspectorToolCreatorSpherePrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *spinBoxCoordonate_x;
    QDoubleSpinBox *spinBoxCoordonate_y;
    QDoubleSpinBox *spinBoxCoordonate_z;
    QDoubleSpinBox *spinBoxRadius;

    QGroupBox *coordinates;
    QLabel *messageToDisplay;

};

axlInspectorToolCreatorSphere::axlInspectorToolCreatorSphere(QWidget *parent) : axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorSpherePrivate)
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
    QHBoxLayout *layoutCoordonate_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordonate_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordonate_z = new QHBoxLayout();
    QHBoxLayout *layoutRadius = new QHBoxLayout();
    QLabel *labelCoordonate_x = new QLabel("x",this);
    QLabel *labelCoordonate_y = new QLabel("y",this);
    QLabel *labelCoordonate_z = new QLabel("z",this);
    QLabel *labelRadius = new QLabel("radius",this);
    d->spinBoxCoordonate_x = new QDoubleSpinBox(this);
    d->spinBoxCoordonate_y = new QDoubleSpinBox(this);
    d->spinBoxCoordonate_z = new QDoubleSpinBox(this);
    d->spinBoxRadius = new QDoubleSpinBox(this);

    d->spinBoxCoordonate_x->setValue(0.0);
    d->spinBoxCoordonate_y->setValue(0.0);
    d->spinBoxCoordonate_z->setValue(0.0);
    d->spinBoxRadius->setValue(1.0);
    d->spinBoxCoordonate_x->setSingleStep(0.1);
    d->spinBoxCoordonate_y->setSingleStep(0.1);
    d->spinBoxCoordonate_z->setSingleStep(0.1);
    d->spinBoxRadius->setSingleStep(0.1);
    d->spinBoxCoordonate_x->setRange(-1000, 1000);
    d->spinBoxCoordonate_y->setRange(-1000, 1000);
    d->spinBoxCoordonate_z->setRange(-1000, 1000);
    layoutCoordonate_x->addWidget(labelCoordonate_x);
    layoutCoordonate_x->addWidget(d->spinBoxCoordonate_x);
    layoutCoordonate_y->addWidget(labelCoordonate_y);
    layoutCoordonate_y->addWidget(d->spinBoxCoordonate_y);
    layoutCoordonate_z->addWidget(labelCoordonate_z);
    layoutCoordonate_z->addWidget(d->spinBoxCoordonate_z);
    layoutRadius->addWidget(labelRadius);
    layoutRadius->addWidget(d->spinBoxRadius);

    layoutCoordonate->addLayout(layoutCoordonate_x);
    layoutCoordonate->addLayout(layoutCoordonate_y);
    layoutCoordonate->addLayout(layoutCoordonate_z);

    d->coordinates = new QGroupBox(tr("Enter coordinates"),this);
    d->coordinates->setLayout(layoutCoordonate);

    //message to display
    d->messageToDisplay = new QLabel("",this);
    axlSphereCreator *creator = new axlSphereCreator();
    d->messageToDisplay->setText(creator->description());
    delete creator;
    d->messageToDisplay->setStyleSheet("color: #ff0000;");

    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorSphere", this));
    //    layout->addLayout(layoutCoordonate);
    layout->addWidget(d->messageToDisplay);
    layout->addWidget(d->coordinates);
    layout->addLayout(layoutRadius);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);
    d->coordinates->hide();
}

axlInspectorToolCreatorSphere::~axlInspectorToolCreatorSphere(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorSphere::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
    if(d->controller->size() < 1){
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

        if(nbRigthType > 0)
            hasRigthType = true;
        if(!hasRigthType){
            d->messageToDisplay->hide();
            d->coordinates->show();
        }
    }
}


QList<axlAbstractData *> axlInspectorToolCreatorSphere::returnInputsList(void){
    QList<axlAbstractData *> list;
    if(d->coordinates->isVisible()){
        axlPoint *center = new axlPoint(d->spinBoxCoordonate_x->value(), d->spinBoxCoordonate_y->value(), d->spinBoxCoordonate_z->value());
        axlDouble *radius = new axlDouble(d->spinBoxRadius->value());

        list << center << radius;
    }
    return list;

}

void axlInspectorToolCreatorSphere::run(void)
{

    if(!d->coordinates->isVisible()){
        d->messageToDisplay->show();
        axlSphereCreator *creator = new axlSphereCreator();
        int nbPoints = 0;
        if(d->controller->size()!=0){
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
            creator->setParameter(d->spinBoxRadius->value());
            creator->update();
            axlSphere *sphere = dynamic_cast<axlSphere *>(creator->output());
            sphere->setColor(d->colorButton->color());
            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
            sphere->setOpacity(opacity);
            emit dataInserted(sphere);

        }else {
            //display the coordinates to be chosen for the extremal points
            d->coordinates->show();
            d->messageToDisplay->hide();
        }
        delete creator;
    }else{
        d->messageToDisplay->hide();
        axlSphere *newSphere = new axlSphere(d->spinBoxCoordonate_x->value(), d->spinBoxCoordonate_y->value(), d->spinBoxCoordonate_z->value(), d->spinBoxRadius->value());

        newSphere->setColor(d->colorButton->color());
        double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
        newSphere->setOpacity(opacity);
        emit dataInserted(newSphere);
    }
}

axlInspectorToolInterface *createaxlInspectorToolCreatorSphere(void)
{
    return new axlInspectorToolCreatorSphere;
}
