/* axlInspectorCamera.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 17:19:51 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:38:31 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorCamera.h"
#include "axlInspectorSeparator.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlAbstractView.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtGui>

class axlInspectorCameraPrivate
{
public:
    axlAbstractView *view;

    QRadioButton *radioButtonLastCamera;

    QRadioButton *radioButtonCameraX;
    QRadioButton *radioButtonCameraY;
    QRadioButton *radioButtonCameraZ;

    QRadioButton *radioButtonCameraInverseX;
    QRadioButton *radioButtonCameraInverseY;
    QRadioButton *radioButtonCameraInverseZ;

    QRadioButton *radioButtonCameraPerpective;
    QRadioButton *radioButtonCameraParallel;

    QCheckBox *checkBoxGridX;
    QCheckBox *checkBoxGridY;
    QCheckBox *checkBoxGridZ;

    QCheckBox *checkBoxShowAxes;

    QSlider *sliderResolution;

};

axlInspectorCamera::axlInspectorCamera(QWidget *parent) : QDialog(parent), d(new axlInspectorCameraPrivate)
{
    d->view = NULL;

    QVBoxLayout *layout = new QVBoxLayout(this);

    QGridLayout *layoutCamera = new QGridLayout();
    QButtonGroup *buttonGroupCamera = new QButtonGroup(this);
    QButtonGroup *buttonGroupCameraProjection = new QButtonGroup(this);

    // last Camera
    d->radioButtonLastCamera = new QRadioButton("Free", this);
    d->radioButtonLastCamera->setToolTip("switch to free camera");
    d->radioButtonLastCamera->setChecked(true);
    d->radioButtonLastCamera->setFocusPolicy(Qt::NoFocus);
    layoutCamera->addWidget(d->radioButtonLastCamera, 0, 0);


    //Positive Camera
    d->radioButtonCameraX = new QRadioButton(" X", this);
    d->radioButtonCameraX->setFocusPolicy(Qt::NoFocus);

    d->radioButtonCameraY = new QRadioButton(" Y", this);
    d->radioButtonCameraY->setFocusPolicy(Qt::NoFocus);

    d->radioButtonCameraZ = new QRadioButton(" Z", this);
    d->radioButtonCameraZ->setFocusPolicy(Qt::NoFocus);

    layoutCamera->addWidget(d->radioButtonCameraX, 1, 0);
    layoutCamera->addWidget(d->radioButtonCameraY, 1, 1);
    layoutCamera->addWidget(d->radioButtonCameraZ, 1, 2);

    //Negative CameraV
    d->radioButtonCameraInverseX = new QRadioButton("-X", this);
    d->radioButtonCameraInverseX->setFocusPolicy(Qt::NoFocus);

    d->radioButtonCameraInverseY = new QRadioButton("-Y", this);
    d->radioButtonCameraInverseY->setFocusPolicy(Qt::NoFocus);

    d->radioButtonCameraInverseZ = new QRadioButton("-Z", this);
    d->radioButtonCameraInverseZ->setFocusPolicy(Qt::NoFocus);

    layoutCamera->addWidget(d->radioButtonCameraInverseX, 2, 0);
    layoutCamera->addWidget(d->radioButtonCameraInverseY, 2, 1);
    layoutCamera->addWidget(d->radioButtonCameraInverseZ, 2, 2);

    buttonGroupCamera->addButton(d->radioButtonLastCamera);
    buttonGroupCamera->addButton(d->radioButtonCameraX);
    buttonGroupCamera->addButton(d->radioButtonCameraY);
    buttonGroupCamera->addButton(d->radioButtonCameraZ);
    buttonGroupCamera->addButton(d->radioButtonCameraInverseX);
    buttonGroupCamera->addButton(d->radioButtonCameraInverseY);
    buttonGroupCamera->addButton(d->radioButtonCameraInverseZ);

    QHBoxLayout *layoutCameraProjection = new QHBoxLayout();

    d->radioButtonCameraPerpective = new QRadioButton(" Perspective", this);
    d->radioButtonCameraPerpective->setFocusPolicy(Qt::NoFocus);
    d->radioButtonCameraPerpective->setChecked(true);

    d->radioButtonCameraParallel = new QRadioButton(" Parallel", this);
    d->radioButtonCameraParallel->setFocusPolicy(Qt::NoFocus);
    layoutCameraProjection->addWidget(d->radioButtonCameraPerpective);
    layoutCameraProjection->addWidget(d->radioButtonCameraParallel);

    buttonGroupCameraProjection->addButton(d->radioButtonCameraPerpective);
    buttonGroupCameraProjection->addButton(d->radioButtonCameraParallel);
    QGridLayout *layoutGrid = new QGridLayout();

    d->checkBoxGridX = new QCheckBox(" X", this);
    d->checkBoxGridX->setFocusPolicy(Qt::NoFocus);

    d->checkBoxGridY = new QCheckBox(" Y", this);
    d->checkBoxGridY->setFocusPolicy(Qt::NoFocus);

    d->checkBoxGridZ = new QCheckBox(" Z", this);
    d->checkBoxGridZ->setFocusPolicy(Qt::NoFocus);

    d->sliderResolution = new QSlider(Qt::Horizontal, this);
    d->sliderResolution->setMinimum(1);
    d->sliderResolution->setMaximum(100);
    d->sliderResolution->setToolTip("Set the grid resolution between 1 and 100");


    layoutGrid->addWidget(d->checkBoxGridX, 0, 0);
    layoutGrid->addWidget(d->checkBoxGridY, 0, 1);
    layoutGrid->addWidget(d->checkBoxGridZ, 0, 2);
    layoutGrid->addWidget(d->sliderResolution, 1, 0, 1, 3);

    d->checkBoxShowAxes = new QCheckBox(" Show axes", this);
    d->checkBoxShowAxes->setChecked(true);
    //d->checkBoxShowAxes->setFocusPolicy(Qt::NoFocus);

    // QAction *actionShowAxes = new QAction("Show axes", this);

    layout->addWidget(new QLabel("Projection :", this));
    layout->addLayout(layoutCameraProjection);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(new QLabel("View", this));
    layout->addLayout(layoutCamera);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(new QLabel("Grid :", this));
    layout->addLayout(layoutGrid);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(new QLabel("Axes :", this));
    layout->addWidget(d->checkBoxShowAxes);

    connect(d->radioButtonLastCamera, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraX, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraY, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraZ, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraInverseX, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraInverseY, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraInverseZ, SIGNAL(clicked()), this, SLOT(onCameraViewChanged()));
    connect(d->radioButtonCameraPerpective, SIGNAL(clicked()), this, SLOT(onCameraProjectionChanged()));
    connect(d->radioButtonCameraParallel, SIGNAL(clicked()), this, SLOT(onCameraProjectionChanged()));
    connect(d->checkBoxGridX, SIGNAL(clicked()), this, SLOT(onGridChanged()));
    connect(d->checkBoxGridY, SIGNAL(clicked()), this, SLOT(onGridChanged()));
    connect(d->checkBoxGridZ, SIGNAL(clicked()), this, SLOT(onGridChanged()));
}

axlInspectorCamera::~axlInspectorCamera(void)
{
    delete d;

    d = NULL;
}

void axlInspectorCamera::setView(axlAbstractView *view)
{
    d->view = view;
    connect(d->sliderResolution, SIGNAL(valueChanged(int)), d->view, SLOT(onGridResolutionChanged(int)));

    connect(d->checkBoxShowAxes, SIGNAL(clicked(bool)),  d->view, SLOT(onShowAxis(bool)));

}

void axlInspectorCamera::updateView()
{
    d->checkBoxShowAxes->setChecked(d->view->getAxesVisibility());

    if (d->view->getParallelProjection())
        d->radioButtonCameraParallel->setChecked(true);
    else
        d->radioButtonCameraPerpective->setChecked(true);
}

void axlInspectorCamera::onCameraProjectionChanged(void)
{
    if(d->radioButtonCameraParallel->isChecked())
        d->view->setParallelCamera(true);

    if(d->radioButtonCameraPerpective->isChecked())
        d->view->setParallelCamera(false);

}

void axlInspectorCamera::onCameraViewChanged(void)
{
    if(d->radioButtonLastCamera->isChecked())
        d->view->setCameraViewDefaut();

    if(d->radioButtonCameraX->isChecked())
        d->view->setCameraViewPositiveX();

    if(d->radioButtonCameraY->isChecked())
        d->view->setCameraViewPositiveY();

    if(d->radioButtonCameraZ->isChecked())
        d->view->setCameraViewPositiveZ();

    if(d->radioButtonCameraInverseX->isChecked())
        d->view->setCameraViewNegativeX();

    if(d->radioButtonCameraInverseY->isChecked())
        d->view->setCameraViewNegativeY();

    if(d->radioButtonCameraInverseZ->isChecked())
        d->view->setCameraViewNegativeZ();
}

void axlInspectorCamera::onGridChanged(void)
{
    d->view->setGrid(d->checkBoxGridX->isChecked(), d->checkBoxGridY->isChecked(), d->checkBoxGridZ->isChecked());
}
