/* axlInspectorView.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Mar 30 09:26:03 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Apr  3 14:21:33 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 78
 */

/* Commentary: 
 *
 */

/* Change log:
 *
 */

#include "axlInspectorView.h"
#include "axlInspectorUtils.h"
#include "axlInspector.h"

#include <axlCore/axlAbstractView.h>

#include <axlGui/axlColorDialog.h>
#include <axlGui/axlInspectorLight.h>
#include <axlGui/axlInspectorCamera.h>

#include <dtkConfig.h>

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkGuiSupport/dtkColorButton.h>

#ifdef DTK_BUILD_VR
#include <dtkVr/dtkVrHeadRecognizer.h>
#include <dtkVr/dtkVrFlystickRecognizer.h>
#include <dtkVr/dtkVrGestureRecognizer.h>
#endif

class axlInspectorViewPrivate
{

#ifdef DTK_BUILD_VR
public:
    dtkVrHeadRecognizer *head_recognizer;
    dtkVrFlystickRecognizer *flystick_recognizer;
    dtkVrGestureRecognizer *gesture_recognizer;
#endif

public:
    axlAbstractView *view;

public:
    dtkColorButton *colorButton;
    axlInspectorLight *lightDialog;
    axlInspectorCamera *inpectorCamera;

    QFrame *box_head;
    QFrame *box_flystick;
    QFrame *box_finger;
    QFrame *box_background;

    QCheckBox *switch_head;
    QCheckBox *switch_flystick;
    QCheckBox *switch_finger;
    QCheckBox *checkBoxGradientBackground;

    QLineEdit *head_address;
    QLineEdit *flystick_address;
    QLineEdit *finger_address;

    QString head_address_url;
    QString flystick_address_url;
    QString finger_address_url;
};

axlInspectorView::axlInspectorView(QWidget *parent) : QFrame(parent), d(new axlInspectorViewPrivate)
{
#ifdef DTK_BUILD_VR
    d->head_recognizer = new dtkVrHeadRecognizer;
    d->flystick_recognizer = new dtkVrFlystickRecognizer;
    d->gesture_recognizer = new dtkVrGestureRecognizer;
#endif

    d->head_address_url = "DTrackCW@is-sound";
    d->flystick_address_url = "DTrackCW@is-sound";
    d->finger_address_url = "DTrackCW@is-sound";

    d->view = NULL;

    d->box_head = new QFrame(this);
    d->head_address = new QLineEdit("DTrackCW@is-sound", d->box_head);
    d->switch_head = new QCheckBox(this);

    d->colorButton = new dtkColorButton(this);

    d->lightDialog = new axlInspectorLight;

    d->inpectorCamera = new axlInspectorCamera;


    QVBoxLayout *box_head_layout = new QVBoxLayout(d->box_head);

    QHBoxLayout *box_head_layout_top = new QHBoxLayout;
    box_head_layout_top->addWidget(new QLabel("Head tracking", d->box_head));
    box_head_layout_top->addWidget(d->switch_head);

    box_head_layout->addLayout(box_head_layout_top);
    box_head_layout->addWidget(d->head_address);

    d->box_flystick = new QFrame(this);
    d->flystick_address = new QLineEdit("DTrackCW@is-sound", d->box_flystick);
    d->switch_flystick = new QCheckBox(this);

    QVBoxLayout *box_flystick_layout = new QVBoxLayout(d->box_flystick);

    QHBoxLayout *box_flystick_layout_top = new QHBoxLayout;
    box_flystick_layout_top->addWidget(new QLabel("Flystick tracking", d->box_flystick));
    box_flystick_layout_top->addWidget(d->switch_flystick);

    box_flystick_layout->addLayout(box_flystick_layout_top);
    box_flystick_layout->addWidget(d->flystick_address);

    d->box_finger = new QFrame(this);
    d->finger_address = new QLineEdit("DTrackCW@is-sound", d->box_finger);
    d->switch_finger = new QCheckBox(this);

    QVBoxLayout *box_finger_layout = new QVBoxLayout(d->box_finger);

    QHBoxLayout *box_finger_layout_top = new QHBoxLayout;
    box_finger_layout_top->addWidget(new QLabel("Finger tracking", d->box_finger));
    box_finger_layout_top->addWidget(d->switch_finger);

    box_finger_layout->addLayout(box_finger_layout_top);
    box_finger_layout->addWidget(d->finger_address);

    d->box_background = new QFrame(this);
    QVBoxLayout *box_background_layout = new QVBoxLayout(d->box_background);

    QHBoxLayout *layoutColorButton = new QHBoxLayout;
//    layoutColorButton->setContentsMargins(20, 20, 20, 20);
    layoutColorButton->addWidget(new QLabel("Color",d->box_background));
    layoutColorButton->addWidget(d->colorButton);

    QHBoxLayout *layoutGradientCheckBox = new QHBoxLayout;
    d->checkBoxGradientBackground = new QCheckBox(this);
    d->checkBoxGradientBackground->setChecked(true);
    QLabel *labelGradientBackground = new QLabel("Gradient :", d->box_background);
    layoutGradientCheckBox->addWidget(labelGradientBackground);
    layoutGradientCheckBox->addWidget(d->checkBoxGradientBackground);
    labelGradientBackground->setToolTip("Turn on/off the gradient background.");

    box_background_layout->addWidget(new QLabel("Background", this));
    box_background_layout->addLayout(layoutColorButton);
    box_background_layout->addLayout(layoutGradientCheckBox);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(d->box_head);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(d->box_flystick);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(d->box_finger);
    layout->addWidget(new axlInspectorSeparator(this));
//    layout->addLayout(layoutColorButton);
    layout->addWidget(d->box_background);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(d->lightDialog);
    layout->addWidget(new axlInspectorSeparator(this));
    layout->addWidget(d->inpectorCamera);
    layout->addWidget(new axlInspectorSeparator(this));

    connect(d->head_address, SIGNAL(textChanged(const QString&)), this, SLOT(onHeadAddressChanged(const QString&)));
    connect(d->flystick_address, SIGNAL(textChanged(const QString&)), this, SLOT(onFlystickAddressChanged(const QString&)));
    connect(d->finger_address, SIGNAL(textChanged(const QString&)), this, SLOT(onFingerAddressChanged(const QString&)));

    connect(d->switch_head, SIGNAL(toggled(bool)), this, SLOT(onHeadToggled(bool)));
    connect(d->switch_flystick, SIGNAL(toggled(bool)), this, SLOT(onFlystickToggled(bool)));
    connect(d->switch_finger, SIGNAL(toggled(bool)), this, SLOT(onFingerToggled(bool)));

}

axlInspectorView::~axlInspectorView(void)
{
#ifdef DTK_BUILD_VR
    delete d->head_recognizer;
    delete d->flystick_recognizer;
    delete d->gesture_recognizer;
#endif
    delete d->lightDialog;
    delete d->inpectorCamera;
    delete d;

    d = NULL;
}

void axlInspectorView::setView(axlAbstractView *view)
{
    if(view){
        d->view = view;
        d->lightDialog->setView(view);
        d->inpectorCamera->setView(view);
        QColor c;
        c.setRgbF(d->view->getBackgroundColor()[0],d->view->getBackgroundColor()[1],d->view->getBackgroundColor()[2]);
        d->colorButton->setColor(c);
        connect(d->view, SIGNAL(lightPositionChanged(double,double,double)), d->lightDialog, SLOT(onPositionChanged(double,double,double)));
        connect(d->colorButton, SIGNAL(colorChanged(QColor)), this, SLOT(onBackGroundColorChanged(QColor)));
        connect(d->checkBoxGradientBackground, SIGNAL(clicked(bool)),  d->view, SLOT(onBackgroundGradientChange(bool)));
    }

}

void axlInspectorView::updateView(){
        QColor c;
        c.setRgbF(d->view->getBackgroundColor()[0],d->view->getBackgroundColor()[1],d->view->getBackgroundColor()[2]);
        d->colorButton->setColor(c);
        d->checkBoxGradientBackground->setChecked(d->view->getBackgroundGradient());

        d->inpectorCamera->updateView();
}

void axlInspectorView::onBackGroundColorChanged(QColor color)
{
    d->view->setBackgroundColor(color.redF(), color.greenF(), color.blueF());
}

void axlInspectorView::onHeadAddressChanged(const QString& address)
{
    d->head_address_url = address;
}

void axlInspectorView::onFlystickAddressChanged(const QString& address)
{
    d->flystick_address_url = address;
}

void axlInspectorView::onFingerAddressChanged(const QString& address)
{
    d->finger_address_url = address;
}

void axlInspectorView::onHeadToggled(bool toggled)
{
    qDebug() << DTK_PRETTY_FUNCTION << toggled << QUrl(d->head_address_url);
#ifdef DTK_BUILD_VR
    if(toggled)
        d->head_recognizer->startConnection(QUrl(d->head_address_url));
    else
        d->head_recognizer->stopConnection();

    d->head_recognizer->setView(d->view);
#endif
}

void axlInspectorView::onFlystickToggled(bool toggled)
{
    qDebug() << DTK_PRETTY_FUNCTION << toggled << QUrl(d->flystick_address_url);
#ifdef DTK_BUILD_VR
    if(toggled)
        d->flystick_recognizer->startConnection(QUrl(d->flystick_address_url));
    else
        d->flystick_recognizer->stopConnection();
#endif
}

void axlInspectorView::onFingerToggled(bool toggled)
{
#ifdef DTK_BUILD_VR
    if(toggled)
        d->gesture_recognizer->startConnection(QUrl(d->finger_address_url));
    else
        d->gesture_recognizer->stopConnection();
#endif
}
