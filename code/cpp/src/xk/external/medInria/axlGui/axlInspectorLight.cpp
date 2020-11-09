/* axlInspectorLight.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 17:19:51 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 14:11:16 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 54
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorLight.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractView.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlInspectorLightPrivate
{
public:
    axlAbstractView *view;

    QCheckBox *checkBoxUseDefaultLight;
    QCheckBox *checkBoxHideLight;


    QDoubleSpinBox *spinBoxCoordonate_x;
    QDoubleSpinBox *spinBoxCoordonate_y;
    QDoubleSpinBox *spinBoxCoordonate_z;

    QSpinBox *spinBoxAmbiant_x;
    QSpinBox *spinBoxAmbiant_y;
    QSpinBox *spinBoxAmbiant_z;

    QSpinBox *spinBoxDiffuse_x;
    QSpinBox *spinBoxDiffuse_y;
    QSpinBox *spinBoxDiffuse_z;

    QSpinBox *spinBoxSpecular_x;
    QSpinBox *spinBoxSpecular_y;
    QSpinBox *spinBoxSpecular_z;

    QSpinBox *spinBoxExponent;
};

axlInspectorLight::axlInspectorLight(QWidget *parent) : QDialog(parent), d(new axlInspectorLightPrivate)
{
    d->view = NULL;

    QVBoxLayout *layout = new QVBoxLayout(this);

    QGridLayout *layoutLight1 = new QGridLayout();

    // checkbox
    QHBoxLayout *layoutCheckBox = new QHBoxLayout();

    QLabel *labelCheckBox = new QLabel("Use default light :", this);
    labelCheckBox->setToolTip("If the box is checked, the default light of the view plugin is"
                              "actived, if not, light widget is activated. In this case, the light is"
                              "draw in the view and user can handle it");

    d->checkBoxUseDefaultLight = new QCheckBox(this);
    d->checkBoxUseDefaultLight->setChecked(true);
    layoutCheckBox->addWidget(labelCheckBox);
    layoutCheckBox->addWidget(d->checkBoxUseDefaultLight);

    // checkbox
    QHBoxLayout *layoutCheckBoxHideLight = new QHBoxLayout();

    QLabel *labelCheckBoxHideLight = new QLabel("Hide light :", this);
    labelCheckBoxHideLight->setToolTip("Check the box to Hide or not the Light Actor");

    d->checkBoxHideLight = new QCheckBox(this);
    d->checkBoxHideLight->setChecked(false);
    layoutCheckBoxHideLight->addWidget(labelCheckBoxHideLight);
    layoutCheckBoxHideLight->addWidget(d->checkBoxHideLight);

    //coordonate

    QHBoxLayout *layoutCoordonate_x = new QHBoxLayout();
    QHBoxLayout *layoutCoordonate_y = new QHBoxLayout();
    QHBoxLayout *layoutCoordonate_z = new QHBoxLayout();
    QLabel *labelCoordonate = new QLabel("Position",this);
    labelCoordonate->setToolTip("Define the light position in the world space");
    d->spinBoxCoordonate_x = new QDoubleSpinBox(this);
    d->spinBoxCoordonate_y = new QDoubleSpinBox(this);
    d->spinBoxCoordonate_z = new QDoubleSpinBox(this);

    d->spinBoxCoordonate_x->setMinimum(-500);
    d->spinBoxCoordonate_x->setMaximum(500);
    d->spinBoxCoordonate_y->setMinimum(-500);
    d->spinBoxCoordonate_y->setMaximum(500);
    d->spinBoxCoordonate_z->setMinimum(-500);
    d->spinBoxCoordonate_z->setMaximum(500);

    d->spinBoxCoordonate_x->setValue(0.0);
    d->spinBoxCoordonate_y->setValue(0.0);
    d->spinBoxCoordonate_z->setValue(0.0);

    d->spinBoxCoordonate_x->setSingleStep(0.1);
    d->spinBoxCoordonate_y->setSingleStep(0.1);
    d->spinBoxCoordonate_z->setSingleStep(0.1);


    layoutCoordonate_x->addWidget(d->spinBoxCoordonate_x);
    layoutCoordonate_y->addWidget(d->spinBoxCoordonate_y);
    layoutCoordonate_z->addWidget(d->spinBoxCoordonate_z);

    layoutLight1->addWidget(labelCoordonate, 0, 0);
    layoutLight1->addLayout(layoutCoordonate_x, 0, 1);
    layoutLight1->addLayout(layoutCoordonate_y, 0, 2);
    layoutLight1->addLayout(layoutCoordonate_z, 0, 3);

    // Ambiant

    QHBoxLayout *layoutAmbiant_x = new QHBoxLayout();
    QHBoxLayout *layoutAmbiant_y = new QHBoxLayout();
    QHBoxLayout *layoutAmbiant_z = new QHBoxLayout();
    QLabel *labelAmbiant = new QLabel("Ambiant",this);
    labelAmbiant->setToolTip("Define the light Ambiant. Each value is defined between 0 and 255");

    d->spinBoxAmbiant_x = new QSpinBox(this);
    d->spinBoxAmbiant_x->setMinimum(0);
    d->spinBoxAmbiant_x->setMaximum(255);
    d->spinBoxAmbiant_x->setValue(255);
    d->spinBoxAmbiant_y = new QSpinBox(this);
    d->spinBoxAmbiant_y->setMinimum(0);
    d->spinBoxAmbiant_y->setMaximum(255);
    d->spinBoxAmbiant_y->setValue(255);
    d->spinBoxAmbiant_z = new QSpinBox(this);
    d->spinBoxAmbiant_z->setMinimum(0);
    d->spinBoxAmbiant_z->setMaximum(255);
    d->spinBoxAmbiant_z->setValue(255);
    layoutAmbiant_x->addWidget(d->spinBoxAmbiant_x);
    layoutAmbiant_y->addWidget(d->spinBoxAmbiant_y);
    layoutAmbiant_z->addWidget(d->spinBoxAmbiant_z);
    layoutLight1->addWidget(labelAmbiant, 1, 0);
    layoutLight1->addLayout(layoutAmbiant_x, 1, 1);
    layoutLight1->addLayout(layoutAmbiant_y, 1, 2);
    layoutLight1->addLayout(layoutAmbiant_z, 1, 3);

    //Diffuse

    QHBoxLayout *layoutDiffuse_x = new QHBoxLayout();
    QHBoxLayout *layoutDiffuse_y = new QHBoxLayout();
    QHBoxLayout *layoutDiffuse_z = new QHBoxLayout();

    QLabel *labelDiffuse = new QLabel("Diffuse",this);
    labelDiffuse->setToolTip("Define the light diffuse. Each value is defined between 0 and 255");

    d->spinBoxDiffuse_x = new QSpinBox(this);
    d->spinBoxDiffuse_x->setMinimum(0);
    d->spinBoxDiffuse_x->setMaximum(255);
    d->spinBoxDiffuse_x->setValue(255);

    d->spinBoxDiffuse_y = new QSpinBox(this);
    d->spinBoxDiffuse_y->setMinimum(0);
    d->spinBoxDiffuse_y->setMaximum(255);
    d->spinBoxDiffuse_y->setValue(255);

    d->spinBoxDiffuse_z = new QSpinBox(this);
    d->spinBoxDiffuse_z->setMinimum(0);
    d->spinBoxDiffuse_z->setMaximum(255);
    d->spinBoxDiffuse_z->setValue(255);

    layoutDiffuse_x->addWidget(d->spinBoxDiffuse_x);
    layoutDiffuse_y->addWidget(d->spinBoxDiffuse_y);
    layoutDiffuse_z->addWidget(d->spinBoxDiffuse_z);

    layoutLight1->addWidget(labelDiffuse, 2, 0);
    layoutLight1->addLayout(layoutDiffuse_x, 2, 1);
    layoutLight1->addLayout(layoutDiffuse_y, 2, 2);
    layoutLight1->addLayout(layoutDiffuse_z, 2, 3);

    //Specular

    QHBoxLayout *layoutSpecular_x = new QHBoxLayout();
    QHBoxLayout *layoutSpecular_y = new QHBoxLayout();
    QHBoxLayout *layoutSpecular_z = new QHBoxLayout();
    QLabel *labelSpecular = new QLabel("Specular",this);
    labelSpecular->setToolTip("Define the light Specular. Each value is defined between 0 and 255");
    d->spinBoxSpecular_x = new QSpinBox(this);
    d->spinBoxSpecular_x->setMinimum(0);
    d->spinBoxSpecular_x->setMaximum(255);
    d->spinBoxSpecular_x->setValue(255);
    d->spinBoxSpecular_y = new QSpinBox(this);
    d->spinBoxSpecular_y->setMinimum(0);
    d->spinBoxSpecular_y->setMaximum(255);
    d->spinBoxSpecular_y->setValue(255);
    d->spinBoxSpecular_z = new QSpinBox(this);
    d->spinBoxSpecular_z->setMinimum(0);
    d->spinBoxSpecular_z->setMaximum(255);
    d->spinBoxSpecular_z->setValue(255);
    layoutSpecular_x->addWidget(d->spinBoxSpecular_x);
    layoutSpecular_y->addWidget(d->spinBoxSpecular_y);
    layoutSpecular_z->addWidget(d->spinBoxSpecular_z);

    layoutLight1->addWidget(labelSpecular, 3, 0);
    layoutLight1->addLayout(layoutSpecular_x, 3, 1);
    layoutLight1->addLayout(layoutSpecular_y, 3, 2);
    layoutLight1->addLayout(layoutSpecular_z, 3, 3);

    //Specular Exponent
    QHBoxLayout *layoutExponent = new QHBoxLayout();
    QLabel *labelExponent = new QLabel("Exponent",this);
    labelExponent->setToolTip("Define the light Specular Exponent. More the exponent is elevated, more the specular effect of the light will be strong");
    d->spinBoxExponent = new QSpinBox(this);
    d->spinBoxExponent->setValue(50);
    d->spinBoxExponent->setMinimum(0);
    layoutExponent->addWidget(labelExponent);
    layoutExponent->addWidget(d->spinBoxExponent);

    layout->addLayout(layoutCheckBox);
    layout->addLayout(layoutCheckBoxHideLight);
    layout->addLayout(layoutLight1);
    layout->addLayout(layoutExponent);

    this->setStateLight(false);

    //connection :
    connect(d->checkBoxUseDefaultLight, SIGNAL(clicked(bool)), this, SLOT(onActiveDefaultLight(bool)));
    connect(d->checkBoxHideLight, SIGNAL(clicked(bool)), this, SLOT(onLightVisibilityChanged(bool)));


    connect(d->spinBoxCoordonate_x, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxCoordonate_y, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxCoordonate_z, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxAmbiant_x, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxAmbiant_y, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxAmbiant_z, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxDiffuse_x, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxDiffuse_y, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxDiffuse_z, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxSpecular_x, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxSpecular_y, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxSpecular_z, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxExponent,   SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));

}

axlInspectorLight::~axlInspectorLight(void)
{
    delete d;

    d = NULL;
}

void axlInspectorLight::setView(axlAbstractView *view)
{
    d->view = view;
}

void axlInspectorLight::onLightVisibilityChanged(bool hide)
{
    Q_UNUSED(hide)
    //just call the onValueChanged
    this->onValueChanged("");
}

void axlInspectorLight::onActiveDefaultLight(bool useDefaultLight)
{
    this->setStateLight(!useDefaultLight);

    if(d->view)
        d->view->activeDefaultLigh(useDefaultLight);
    else
        qDebug()<<"No view available to change the light. Please load a view plugin";

    if(!useDefaultLight)
        this->onValueChanged("");

}

void axlInspectorLight::setStateLight(bool state)
{
    d->checkBoxHideLight->setEnabled(state);

    d->spinBoxCoordonate_x->setEnabled(state);
    d->spinBoxCoordonate_y->setEnabled(state);
    d->spinBoxCoordonate_z->setEnabled(state);

    d->spinBoxAmbiant_x->setEnabled(state);
    d->spinBoxAmbiant_y->setEnabled(state);
    d->spinBoxAmbiant_z->setEnabled(state);

    d->spinBoxDiffuse_x->setEnabled(state);
    d->spinBoxDiffuse_y->setEnabled(state);
    d->spinBoxDiffuse_z->setEnabled(state);

    d->spinBoxSpecular_x->setEnabled(state);
    d->spinBoxSpecular_y->setEnabled(state);
    d->spinBoxSpecular_z->setEnabled(state);

    d->spinBoxExponent->setEnabled(state);
}

void axlInspectorLight::onValueChanged(QString value)
{
    //Q_UNUSED(value);

    double *position = new double[3];
    double *ambiant = new double[3];
    double *diffuse = new double[3];
    double *specular = new double[3];

    position[0] = (double)(d->spinBoxCoordonate_x->value());
    position[1] = (double)(d->spinBoxCoordonate_y->value());
    position[2] = (double)(d->spinBoxCoordonate_z->value());

    ambiant[0] = (double)((double)(d->spinBoxAmbiant_x->value())/255.0);
    ambiant[1] = (double)(double)((d->spinBoxAmbiant_y->value())/255.0);
    ambiant[2] = (double)(double)((d->spinBoxAmbiant_z->value())/255.0);

    diffuse[0] = (double)((double)(d->spinBoxDiffuse_x->value())/255.0);
    diffuse[1] = (double)((double)(d->spinBoxDiffuse_y->value())/255.0);
    diffuse[2] = (double)((double)(d->spinBoxDiffuse_z->value())/255.0);

    specular[0] = (double)((double)(d->spinBoxSpecular_x->value())/255.0);
    specular[1] = (double)((double)(d->spinBoxSpecular_y->value())/255.0);
    specular[2] = (double)((double)(d->spinBoxSpecular_z->value())/255.0);

    d->view->setLight(1, d->checkBoxHideLight->isChecked(), position, ambiant, diffuse, specular, d->spinBoxExponent->value());

    delete[] position;
    delete[] ambiant;
    delete[] diffuse;
    delete[] specular;
}

void axlInspectorLight::onPositionChanged(double x, double y, double z)
{
    disconnect(d->spinBoxCoordonate_x, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    disconnect(d->spinBoxCoordonate_y, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    disconnect(d->spinBoxCoordonate_z, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));

    d->spinBoxCoordonate_x->setValue(x);
    d->spinBoxCoordonate_y->setValue(y);
    d->spinBoxCoordonate_z->setValue(z);

    connect(d->spinBoxCoordonate_x, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxCoordonate_y, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(d->spinBoxCoordonate_z, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
}
