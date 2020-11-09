/* axlInspectorToolCreatorEllipsoid.cpp ---
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

#include "axlInspectorToolCreatorEllipsoid.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlEllipsoidCreator.h>

#include <QtGui>

class axlInspectorToolCreatorEllipsoidPrivate {
public:
    QSlider *sliderOpacity;
    dtkColorButton *colorButton;
    axlInspectorObjectController *controller;

    QDoubleSpinBox *center_x;
    QDoubleSpinBox *center_y;
    QDoubleSpinBox *center_z;
    QDoubleSpinBox *semix;
    QDoubleSpinBox *semix_x;
    QDoubleSpinBox *semix_y;
    QDoubleSpinBox *semix_z;
    QDoubleSpinBox *semiy;
    QDoubleSpinBox *semiy_x;
    QDoubleSpinBox *semiy_y;
    QDoubleSpinBox *semiy_z;
    QDoubleSpinBox *semiz;
    QDoubleSpinBox *semiz_x;
    QDoubleSpinBox *semiz_y;
    QDoubleSpinBox *semiz_z;

    QLabel *warningMessage;
    QLabel *errorMessage;

    QGroupBox *centerGroupBox;
    QGroupBox *semiXGroupBox;
    QGroupBox *semiYGroupBox;
    QGroupBox *semiZGroupBox;

    QLabel *messageToDisplay;
};

axlInspectorToolCreatorEllipsoid::axlInspectorToolCreatorEllipsoid(QWidget *parent) : axlInspectorToolCreator(parent), d(new axlInspectorToolCreatorEllipsoidPrivate) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    //WARNING MESSAGE//
    d->warningMessage = new QLabel("Warning: your axis have been orthogonalized.");
    d->warningMessage->setStyleSheet("color: #FF6600;");
    d->warningMessage->setVisible(false);


    //ERROR MESSAGE//
    d->errorMessage = new QLabel("Error: axis are parallele or nul.\nPlease check out your data and run again.");
    d->errorMessage->setStyleSheet("color: #FF0000;");
    d->errorMessage->setVisible(false);


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

    ///////CENTER///////////////
    d->center_x = new QDoubleSpinBox(this);
    d->center_x->setRange(-1000, 1000);
    d->center_x->setValue(0.0);
    d->center_x->setSingleStep(0.1);

    d->center_y = new QDoubleSpinBox(this);
    d->center_y->setRange(-1000, 1000);
    d->center_y->setValue(0.0);
    d->center_y->setSingleStep(0.1);

    d->center_z = new QDoubleSpinBox(this);
    d->center_z->setRange(-1000, 1000);
    d->center_z->setValue(0.0);
    d->center_z->setSingleStep(0.1);

    QHBoxLayout *layoutCenter_x = new QHBoxLayout;
    layoutCenter_x->addWidget(new QLabel("X",this));
    layoutCenter_x->addWidget(d->center_x);

    QHBoxLayout *layoutCenter_y = new QHBoxLayout;
    layoutCenter_y->addWidget(new QLabel("Y",this));
    layoutCenter_y->addWidget(d->center_y);

    QHBoxLayout *layoutCenter_z = new QHBoxLayout;
    layoutCenter_z->addWidget(new QLabel("Z",this));
    layoutCenter_z->addWidget(d->center_z);

    QVBoxLayout* layoutCenter = new QVBoxLayout;
    layoutCenter->addLayout(layoutCenter_x);
    layoutCenter->addLayout(layoutCenter_y);
    layoutCenter->addLayout(layoutCenter_z);

    d->centerGroupBox = new QGroupBox("Center");
    d->centerGroupBox->setLayout(layoutCenter);


    ///////SEMIX///////////////
    d->semix = new QDoubleSpinBox(this);
    d->semix->setRange(-1000, 1000);
    d->semix->setValue(1.00);
    d->semix->setSingleStep(0.1);

    d->semix_x = new QDoubleSpinBox(this);
    d->semix_x->setRange(-1000, 1000);
    d->semix_x->setValue(1.0);
    d->semix_x->setSingleStep(0.1);

    d->semix_y = new QDoubleSpinBox(this);
    d->semix_y->setRange(-1000, 1000);
    d->semix_y->setValue(0.0);
    d->semix_y->setSingleStep(0.1);

    d->semix_z = new QDoubleSpinBox(this);
    d->semix_z->setRange(-1000, 1000);
    d->semix_z->setValue(0.0);
    d->semix_z->setSingleStep(0.1);

    QHBoxLayout *layoutSemixRadius = new QHBoxLayout;
    layoutSemixRadius->addWidget(new QLabel("X radius", this));
    layoutSemixRadius->addWidget(d->semix);

    QHBoxLayout *layoutSemix_x = new QHBoxLayout;
    layoutSemix_x->addWidget(new QLabel("X",this));
    layoutSemix_x->addWidget(d->semix_x);

    QHBoxLayout *layoutSemix_y = new QHBoxLayout;
    layoutSemix_y->addWidget(new QLabel("Y",this));
    layoutSemix_y->addWidget(d->semix_y);

    QHBoxLayout *layoutSemix_z = new QHBoxLayout;
    layoutSemix_z->addWidget(new QLabel("Z",this));
    layoutSemix_z->addWidget(d->semix_z);

    QVBoxLayout* layoutSemiX = new QVBoxLayout;
    layoutSemiX->addLayout(layoutSemixRadius);
    layoutSemiX->addLayout(layoutSemix_x);
    layoutSemiX->addLayout(layoutSemix_y);
    layoutSemiX->addLayout(layoutSemix_z);

    d->semiXGroupBox = new QGroupBox("Semi Axis X");
    d->semiXGroupBox->setLayout(layoutSemiX);


    ///////SEMIY///////////////
    d->semiy = new QDoubleSpinBox(this);
    d->semiy->setRange(-1000, 1000);
    d->semiy->setValue(1.00);
    d->semiy->setSingleStep(0.1);

    d->semiy_x = new QDoubleSpinBox(this);
    d->semiy_x->setRange(-1000, 1000);
    d->semiy_x->setValue(0.0);
    d->semiy_x->setSingleStep(0.1);

    d->semiy_y = new QDoubleSpinBox(this);
    d->semiy_y->setRange(-1000, 1000);
    d->semiy_y->setValue(1.0);
    d->semiy_y->setSingleStep(0.1);

    d->semiy_z = new QDoubleSpinBox(this);
    d->semiy_z->setRange(-1000, 1000);
    d->semiy_z->setValue(0.0);
    d->semiy_z->setSingleStep(0.1);

    QHBoxLayout *layoutSemiyRadius = new QHBoxLayout;
    layoutSemiyRadius->addWidget(new QLabel("Y radius", this));
    layoutSemiyRadius->addWidget(d->semiy);

    QHBoxLayout *layoutSemiy_x = new QHBoxLayout;
    layoutSemiy_x->addWidget(new QLabel("X",this));
    layoutSemiy_x->addWidget(d->semiy_x);

    QHBoxLayout *layoutSemiy_y = new QHBoxLayout;
    layoutSemiy_y->addWidget(new QLabel("Y",this));
    layoutSemiy_y->addWidget(d->semiy_y);

    QHBoxLayout *layoutSemiy_z = new QHBoxLayout;
    layoutSemiy_z->addWidget(new QLabel("Z",this));
    layoutSemiy_z->addWidget(d->semiy_z);

    QVBoxLayout* layoutSemiY = new QVBoxLayout;
    layoutSemiY->addLayout(layoutSemiyRadius);
    layoutSemiY->addLayout(layoutSemiy_x);
    layoutSemiY->addLayout(layoutSemiy_y);
    layoutSemiY->addLayout(layoutSemiy_z);

    d->semiYGroupBox = new QGroupBox("Semi Axis Y");
    d->semiYGroupBox->setLayout(layoutSemiY);


    ///////SEMIZ///////////////
    d->semiz = new QDoubleSpinBox(this);
    d->semiz->setRange(-1000, 1000);
    d->semiz->setValue(1.00);
    d->semiz->setSingleStep(0.1);

    d->semiz_x = new QDoubleSpinBox(this);
    d->semiz_x->setRange(-1000, 1000);
    d->semiz_x->setValue(0.0);
    d->semiz_x->setSingleStep(0.1);

    d->semiz_y = new QDoubleSpinBox(this);
    d->semiz_y->setRange(-1000, 1000);
    d->semiz_y->setValue(0.0);
    d->semiz_y->setSingleStep(0.1);

    d->semiz_z = new QDoubleSpinBox(this);
    d->semiz_z->setRange(-1000, 1000);
    d->semiz_z->setValue(1.0);
    d->semiz_z->setSingleStep(0.1);

    QHBoxLayout *layoutSemizRadius = new QHBoxLayout;
    layoutSemizRadius->addWidget(new QLabel("Z radius", this));
    layoutSemizRadius->addWidget(d->semiz);

    QHBoxLayout *layoutSemiz_x = new QHBoxLayout;
    layoutSemiz_x->addWidget(new QLabel("X",this));
    layoutSemiz_x->addWidget(d->semiz_x);

    QHBoxLayout *layoutSemiz_y = new QHBoxLayout;
    layoutSemiz_y->addWidget(new QLabel("Y",this));
    layoutSemiz_y->addWidget(d->semiz_y);

    QHBoxLayout *layoutSemiz_z = new QHBoxLayout;
    layoutSemiz_z->addWidget(new QLabel("Z",this));
    layoutSemiz_z->addWidget(d->semiz_z);

    QVBoxLayout* layoutSemiZ = new QVBoxLayout;
    layoutSemiZ->addLayout(layoutSemizRadius);
    layoutSemiZ->addLayout(layoutSemiz_x);
    layoutSemiZ->addLayout(layoutSemiz_y);
    layoutSemiZ->addLayout(layoutSemiz_z);

    d->semiZGroupBox = new QGroupBox("Semi Axis Z");
    d->semiZGroupBox->setLayout(layoutSemiZ);

    //////MESSAGE TO DISPLAY////////////////
    d->messageToDisplay = new QLabel("",this);
    axlEllipsoidCreator *creator = new axlEllipsoidCreator();
    d->messageToDisplay->setText(creator->description());
    delete creator;
    d->messageToDisplay->setStyleSheet("color: #ff0000;");

    ///////BUTTON///////////////
    QPushButton *button = new QPushButton("Create", this);
    connect(button, SIGNAL(clicked()), this, SLOT(run()));


    ///////MAIN LAYOUT///////////////
    layout->addWidget(new QLabel("axlInspectorToolCreatorEllipsoid", this));
    layout->addWidget(d->messageToDisplay);
    layout->addWidget(d->centerGroupBox);
    layout->addWidget(d->semiXGroupBox);
    layout->addWidget(d->semiYGroupBox);
    layout->addWidget(d->semiZGroupBox);

    layout->addLayout(layoutOpacity);
    layout->addLayout(layoutColorButton);
    layout->addWidget(d->warningMessage);
    layout->addWidget(d->errorMessage);
    layout->addWidget(button);


    ///////CONNECTIONS///////////////
    connect(d->semix_x, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusX(double)));
    connect(d->semix_y, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusX(double)));
    connect(d->semix_z, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusX(double)));

    connect(this, SIGNAL(radiusXUpdated(double)), d->semix, SLOT(setValue(double)));
    connect(d->semix, SIGNAL(valueChanged(double)), this, SLOT(onUpdateSemix(double)));

    connect(d->semiy_x, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusY(double)));
    connect(d->semiy_y, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusY(double)));
    connect(d->semiy_z, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusY(double)));

    connect(this, SIGNAL(radiusYUpdated(double)), d->semiy, SLOT(setValue(double)));
    connect(d->semiy, SIGNAL(valueChanged(double)), this, SLOT(onUpdateSemiy(double)));

    connect(d->semiz_x, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusZ(double)));
    connect(d->semiz_y, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusZ(double)));
    connect(d->semiz_z, SIGNAL(valueChanged(double)), this, SLOT(onUpdateRadiusZ(double)));

    connect(this, SIGNAL(radiusZUpdated(double)), d->semiz, SLOT(setValue(double)));
    connect(d->semiz, SIGNAL(valueChanged(double)), this, SLOT(onUpdateSemiz(double)));

    d->centerGroupBox->hide();
    d->semiXGroupBox->hide();
    d->semiYGroupBox->hide();
    d->semiZGroupBox->hide();

}

axlInspectorToolCreatorEllipsoid::~axlInspectorToolCreatorEllipsoid(void) {
    delete d;
    d = NULL;
}

void axlInspectorToolCreatorEllipsoid::setController(axlInspectorObjectController *controller) {
    d->controller = controller;
    if(d->controller->size() < 4){
        d->messageToDisplay->hide();
        d->centerGroupBox->show();
        d->semiXGroupBox->show();
        d->semiYGroupBox->show();
        d->semiZGroupBox->show();
    }else{
        d->centerGroupBox->hide();
        d->semiXGroupBox->hide();
        d->semiYGroupBox->hide();
        d->semiZGroupBox->hide();
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

        if(nbRigthType > 3)
            hasRigthType = true;
        if(!hasRigthType){
            d->messageToDisplay->hide();
            d->centerGroupBox->show();
            d->semiXGroupBox->show();
            d->semiYGroupBox->show();
            d->semiZGroupBox->show();
        }
    }
}


QList<axlAbstractData *> axlInspectorToolCreatorEllipsoid::returnInputsList(void){
    QList<axlAbstractData *> list;
    if(d->centerGroupBox->isVisible()){
        axlPoint *center = new axlPoint(d->center_x->value(), d->center_y->value(), d->center_z->value());
        axlPoint *semiX = new axlPoint(d->semix_x->value(), d->semix_y->value(), d->semix_z->value());
        axlPoint *semiY = new axlPoint(d->semiy_x->value(), d->semiy_y->value(), d->semiy_z->value());
        axlPoint *semiZ = new axlPoint(d->semiz_x->value(), d->semiz_y->value(), d->semiz_z->value());

        list << center << semiX << semiY << semiZ;
    }
    return list;


}

void axlInspectorToolCreatorEllipsoid::orthogonalise(int& status) {
    axlPoint semix(d->semix_x->value(), d->semix_y->value(), d->semix_z->value());
    axlPoint startSemix(semix);
    double semixRadius = semix.norm();
    semix.normalize();

    axlPoint semiy(d->semiy_x->value(), d->semiy_y->value(), d->semiy_z->value());
    axlPoint startSemiy(semiy);
    double semiyRadius = semiy.norm();
    semiy.normalize();

    axlPoint semiz(d->semiz_x->value(), d->semiz_y->value(), d->semiz_z->value());
    axlPoint startSemiz(semiz);
    double semizRadius = semiz.norm();
    semiz.normalize();

    if (semix.norm() < 0.001) {
        axlPoint pv = axlPoint::crossProduct(semiy, semiz);
        if (pv.norm() < 0.001) {
            status = 2;
            return;
        } else {
            semix = pv;
            semix.normalize();
            semiy = axlPoint::crossProduct(semiz, semix);
            semiy.normalize();
        }
    } else {
        axlPoint pv = axlPoint::crossProduct(semix, semiy);
        if (pv.norm() < 0.001) {
            pv = axlPoint::crossProduct(semiz, semix);
            if (pv.norm() < 0.001) {
                status = 2;
                return;
            } else {
                semiy = pv;
                semiy.normalize();
                semiz = axlPoint::crossProduct(semix, semiy);
                semiz.normalize();
            }
        } else {
            semiz = pv;
            semiz.normalize();
            semiy = axlPoint::crossProduct(semiz, semix);
            semiy.normalize();
        }
    }

    semix *= semixRadius;
    d->semix_x->setValue(semix.x());
    d->semix_y->setValue(semix.y());
    d->semix_z->setValue(semix.z());
    semiy *= semiyRadius;
    d->semiy_x->setValue(semiy.x());
    d->semiy_y->setValue(semiy.y());
    d->semiy_z->setValue(semiy.z());
    semiz *= semizRadius;
    d->semiz_x->setValue(semiz.x());
    d->semiz_y->setValue(semiz.y());
    d->semiz_z->setValue(semiz.z());

    if (axlPoint::distance(&startSemix, &semix) < 0.001
            && axlPoint::distance(&startSemiy, &semiy) < 0.001
            && axlPoint::distance(&startSemiz, &semiz) < 0.001) {
        status = 0;
    } else {
        status = 1;
    }
}

void axlInspectorToolCreatorEllipsoid::onUpdateRadiusX(double) {
    emit radiusXUpdated(
                sqrt(
                    d->semix_x->value()*d->semix_x->value()
                    + d->semix_y->value()*d->semix_y->value()
                    + d->semix_z->value()*d->semix_z->value()
                    )
                );
}

void axlInspectorToolCreatorEllipsoid::onUpdateRadiusY(double) {
    emit radiusYUpdated(
                sqrt(
                    d->semiy_x->value()*d->semiy_x->value()
                    + d->semiy_y->value()*d->semiy_y->value()
                    + d->semiy_z->value()*d->semiy_z->value()
                    )
                );
}

void axlInspectorToolCreatorEllipsoid::onUpdateRadiusZ(double) {
    emit radiusZUpdated(
                sqrt(
                    d->semiz_x->value()*d->semiz_x->value()
                    + d->semiz_y->value()*d->semiz_y->value()
                    + d->semiz_z->value()*d->semiz_z->value()
                    )
                );
}

void axlInspectorToolCreatorEllipsoid::onUpdateSemix(double radius) {
    axlPoint semix(d->semix_x->value(), d->semix_y->value(), d->semix_z->value());

    semix.normalize();
    semix *= radius;

    d->semix_x->setValue(semix.x());
    d->semix_y->setValue(semix.y());
    d->semix_z->setValue(semix.z());
}

void axlInspectorToolCreatorEllipsoid::onUpdateSemiy(double radius) {
    axlPoint semiy(d->semiy_x->value(), d->semiy_y->value(), d->semiy_z->value());

    semiy.normalize();
    semiy *= radius;

    d->semiy_x->setValue(semiy.x());
    d->semiy_y->setValue(semiy.y());
    d->semiy_z->setValue(semiy.z());
}

void axlInspectorToolCreatorEllipsoid::onUpdateSemiz(double radius) {
    axlPoint semiz(d->semiz_x->value(), d->semiz_y->value(), d->semiz_z->value());

    semiz.normalize();
    semiz *= radius;

    d->semiz_x->setValue(semiz.x());
    d->semiz_y->setValue(semiz.y());
    d->semiz_z->setValue(semiz.z());
}

void axlInspectorToolCreatorEllipsoid::run(void) {
    int status = -1;
    orthogonalise(status);

    d->warningMessage->setVisible(status == 1);
    d->errorMessage->setVisible(status == 2);

    if (status == 2) {
        return;
    } else {


        if(!d->centerGroupBox->isVisible()){
            // all group box are hidden or visible at the same time.
            d->messageToDisplay->show();
            axlEllipsoidCreator *creator = new axlEllipsoidCreator();
            int nbPoints = 0;
            if(!(d->controller->size()==0)) {
                foreach(axlInspectorObjectManagerTreeItem *item, d->controller->items()){

                    if(item->text(2) == "Selected"|| item->text(2) == "Editable")
                    {
                        if(nbPoints < 4){
                            if(dynamic_cast<axlPoint *>(d->controller->data(item))) {
                                axlPoint *point = dynamic_cast<axlPoint *>(d->controller->data(item));
                                creator->setInput(point,nbPoints);
                                nbPoints++;
                            }
                        } else {
                            qDebug() << "To many inputs selected, only the two first points were used";
                        }
                    }
                }
            }

            if(nbPoints == 4) {
                creator->update();
                axlEllipsoid *ellipse = dynamic_cast<axlEllipsoid *>(creator->output());
                ellipse->setColor(d->colorButton->color());
                double opacity = 1.0 - 0.01 * d->sliderOpacity->value();
                ellipse->setOpacity(opacity);
                emit dataInserted(ellipse);

            } else {
                //display the coordinates to be chosen for the extremal points
                d->messageToDisplay->hide();
                d->centerGroupBox->show();
                d->semiXGroupBox->show();
                d->semiYGroupBox->show();
                d->semiZGroupBox->show();
            }
            delete creator;
        } else {

            d->messageToDisplay->hide();

            axlPoint *center = new axlPoint(d->center_x->value(), d->center_y->value(), d->center_z->value());

            axlPoint *semiX = new axlPoint(d->semix_x->value(), d->semix_y->value(), d->semix_z->value());
            axlPoint *semiY = new axlPoint(d->semiy_x->value(), d->semiy_y->value(), d->semiy_z->value());
            axlPoint *semiZ = new axlPoint(d->semiz_x->value(), d->semiz_y->value(), d->semiz_z->value());

            axlEllipsoid* ellipsoid = new axlEllipsoid(center, semiX, semiY, semiZ);

            double opacity = 1.0 - 0.01 * d->sliderOpacity->value();

            ellipsoid->setColor(d->colorButton->color());
            ellipsoid->setOpacity(opacity);
            emit dataInserted(ellipsoid);
            d->centerGroupBox->hide();
            d->semiXGroupBox->hide();
            d->semiYGroupBox->hide();
            d->semiZGroupBox->hide();
        }
    }
}

axlInspectorToolInterface *createaxlInspectorToolCreatorEllipsoid(void){
    return new axlInspectorToolCreatorEllipsoid;
}
