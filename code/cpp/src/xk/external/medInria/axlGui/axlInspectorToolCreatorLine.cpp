/* axlInspectorToolCreatorLine.cpp ---
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

#include "axlInspectorToolCreatorLine.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlLineCreator.h>
//#include <axlCore/axlMiddleLine.h>

#include <QtGui>

class axlInspectorToolCreatorLinePrivate
{
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *spinBoxCoordinateFirst_x;
    QDoubleSpinBox *spinBoxCoordinateFirst_y;
    QDoubleSpinBox *spinBoxCoordinateFirst_z;

    QDoubleSpinBox *spinBoxCoordinateSecond_x;
    QDoubleSpinBox *spinBoxCoordinateSecond_y;
    QDoubleSpinBox *spinBoxCoordinateSecond_z;
    QGroupBox *coordinates;

    QLabel *messageToDisplay;
};

axlInspectorToolCreatorLine::axlInspectorToolCreatorLine(QWidget *parent) : axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorLinePrivate)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    d->messageToDisplay = new QLabel("Select two points to create a line", this);
    d->messageToDisplay->setStyleSheet("color: #ff0000;");

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

    QVBoxLayout *layoutCoordonate = new QVBoxLayout(this);
    QHBoxLayout *layoutCoordinateFirst_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateFirst_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateFirst_z = new QHBoxLayout();
    QLabel *labelCoordinateFirst_x = new QLabel("x",this);
    QLabel *labelCoordinateFirst_y = new QLabel("y",this);
    QLabel *labelCoordinateFirst_z = new QLabel("z",this);
    d->spinBoxCoordinateFirst_x = new QDoubleSpinBox(this);
    d->spinBoxCoordinateFirst_y = new QDoubleSpinBox(this);
    d->spinBoxCoordinateFirst_z = new QDoubleSpinBox(this);

    QHBoxLayout *layoutCoordinateSecond_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateSecond_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordinateSecond_z = new QHBoxLayout();
    QLabel *labelCoordinateSecond_x = new QLabel("x",this);
    QLabel *labelCoordinateSecond_y = new QLabel("y",this);
    QLabel *labelCoordinateSecond_z = new QLabel("z",this);
    d->spinBoxCoordinateSecond_x = new QDoubleSpinBox(this);
    d->spinBoxCoordinateSecond_y = new QDoubleSpinBox(this);
    d->spinBoxCoordinateSecond_z = new QDoubleSpinBox(this);

    d->spinBoxCoordinateFirst_x->setValue(0.0);
    d->spinBoxCoordinateFirst_y->setValue(0.0);
    d->spinBoxCoordinateFirst_z->setValue(0.0);
    d->spinBoxCoordinateFirst_x->setRange(-1000, 1000);
    d->spinBoxCoordinateFirst_y->setRange(-1000, 1000);
    d->spinBoxCoordinateFirst_z->setRange(-1000, 1000);
    d->spinBoxCoordinateFirst_x->setSingleStep(0.1);
    d->spinBoxCoordinateFirst_y->setSingleStep(0.1);
    d->spinBoxCoordinateFirst_z->setSingleStep(0.1);
    layoutCoordinateFirst_x->addWidget(labelCoordinateFirst_x);
    layoutCoordinateFirst_x->addWidget(d->spinBoxCoordinateFirst_x);
    layoutCoordinateFirst_y->addWidget(labelCoordinateFirst_y);
    layoutCoordinateFirst_y->addWidget(d->spinBoxCoordinateFirst_y);
    layoutCoordinateFirst_z->addWidget(labelCoordinateFirst_z);
    layoutCoordinateFirst_z->addWidget(d->spinBoxCoordinateFirst_z);
    layoutCoordonate->addWidget(new QLabel("First point :", this));
    layoutCoordonate->addLayout(layoutCoordinateFirst_x);
    layoutCoordonate->addLayout(layoutCoordinateFirst_y);
    layoutCoordonate->addLayout(layoutCoordinateFirst_z);

    d->spinBoxCoordinateSecond_x->setValue(1.0);
    d->spinBoxCoordinateSecond_y->setValue(0.0);
    d->spinBoxCoordinateSecond_z->setValue(0.0);
    d->spinBoxCoordinateSecond_x->setRange(-1000, 1000);
    d->spinBoxCoordinateSecond_y->setRange(-1000, 1000);
    d->spinBoxCoordinateSecond_z->setRange(-1000, 1000);
    d->spinBoxCoordinateSecond_x->setSingleStep(0.1);
    d->spinBoxCoordinateSecond_y->setSingleStep(0.1);
    d->spinBoxCoordinateSecond_z->setSingleStep(0.1);

    layoutCoordinateSecond_x->addWidget(labelCoordinateSecond_x);
    layoutCoordinateSecond_x->addWidget(d->spinBoxCoordinateSecond_x);
    layoutCoordinateSecond_y->addWidget(labelCoordinateSecond_y);
    layoutCoordinateSecond_y->addWidget(d->spinBoxCoordinateSecond_y);
    layoutCoordinateSecond_z->addWidget(labelCoordinateSecond_z);
    layoutCoordinateSecond_z->addWidget(d->spinBoxCoordinateSecond_z);
    layoutCoordonate->addWidget(new QLabel("Second point :", this));
    layoutCoordonate->addLayout(layoutCoordinateSecond_x);
    layoutCoordonate->addLayout(layoutCoordinateSecond_y);
    layoutCoordonate->addLayout(layoutCoordinateSecond_z);


    d->coordinates = new QGroupBox(tr("Enter coordinates"),this);
    d->coordinates->setLayout(layoutCoordonate);



    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));

    layout->addWidget(new QLabel("axlInspectorToolCreatorLine", this));
    //layout->addLayout(layoutCoordonate);
    layout->addWidget(d->messageToDisplay);
    layout->addWidget(d->coordinates);
    //    layout->addLayout(layoutDynamic);
    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(button);

    d->coordinates->hide();
    d->messageToDisplay->hide();
}

axlInspectorToolCreatorLine::~axlInspectorToolCreatorLine(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreatorLine::setController(axlInspectorObjectController *controller)
{
    d->controller = controller;
    if(d->controller->size() < 2){
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
        if(!hasRigthType)
            d->coordinates->show();
        else{
            d->messageToDisplay->show();
        }
    }
}

QList<axlAbstractData *> axlInspectorToolCreatorLine::returnInputsList(void){
    QList<axlAbstractData *> list;
    if(d->coordinates->isVisible()){
        axlPoint *firstPoint = new axlPoint(d->spinBoxCoordinateFirst_x->value(), d->spinBoxCoordinateFirst_y->value(), d->spinBoxCoordinateFirst_z->value());
        axlPoint *secondPoint = new axlPoint(d->spinBoxCoordinateSecond_x->value(), d->spinBoxCoordinateSecond_y->value(), d->spinBoxCoordinateSecond_z->value());


        list << firstPoint << secondPoint;
    }
    return list;

}


void axlInspectorToolCreatorLine::run(void)
{
    if( !d->coordinates->isVisible()){
        axlLineCreator *creator = new axlLineCreator();
        int nbPoints = 0;
        if(!d->controller->size()==0){
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
            axlLine *line = dynamic_cast<axlLine *>(creator->output());
            line->setColor(d->colorButton->color());
            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
            line->setOpacity(opacity);
            emit dataInserted(line);

        }else {
            //display the coordinates to be chosen for the extremal points
            d->coordinates->show();
            d->messageToDisplay->hide();
        }

        delete creator;

    }else{
        // WARNING THESE POINT ARE ONLY REFERENCED BY THE LINE : risk of memory leek when the line will be deleted
        axlPoint *firstPoint = new axlPoint(d->spinBoxCoordinateFirst_x->value(), d->spinBoxCoordinateFirst_y->value(), d->spinBoxCoordinateFirst_z->value());
        axlPoint *secondPoint = new axlPoint(d->spinBoxCoordinateSecond_x->value(), d->spinBoxCoordinateSecond_y->value(), d->spinBoxCoordinateSecond_z->value());

        axlLine *line = new axlLine(firstPoint, secondPoint);
        double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
        line->setColor(d->colorButton->color());
        line->setOpacity(opacity);
        emit dataInserted(line);


        d->coordinates->show();
        d->messageToDisplay->hide();

    }

}

axlInspectorToolInterface *createaxlInspectorToolCreatorLine(void)
{
    return new axlInspectorToolCreatorLine;
}

