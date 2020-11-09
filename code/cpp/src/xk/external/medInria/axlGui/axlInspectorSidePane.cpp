/* axlInspectorSidePane.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 15 14:09:00 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 16:22:02 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 54
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorSidePane.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkGuiSupport/dtkSpacer.h>

#include <QtGui>

class axlInspectorSidePanePrivate
{
public:
    QAction *side_pane_action_world_camera;
    QAction *side_pane_action_object_camera;
    QAction *side_pane_action_joystick_interactor;
    QAction *side_pane_action_trackball_interactor;
    QAction *side_pane_action_settings;
    QAction *side_pane_action_switch_fullScreen_normal;
};

axlInspectorSidePane::axlInspectorSidePane(QWidget *parent) : QToolBar(parent), d(new axlInspectorSidePanePrivate)
{
    d->side_pane_action_world_camera = new QAction("World mode", this);
    d->side_pane_action_world_camera->setShortcut(Qt::Key_C);
    d->side_pane_action_world_camera->setCheckable(true);
    d->side_pane_action_world_camera->setChecked(true);
    d->side_pane_action_world_camera->setToolTip("Set world mode");
    d->side_pane_action_world_camera->setIcon(QPixmap(":axlGui/pixmaps/video-camera.png"));

    d->side_pane_action_object_camera = new QAction("Object mode", this);
    d->side_pane_action_object_camera->setShortcut(Qt::Key_A);
    d->side_pane_action_object_camera->setCheckable(true);
    d->side_pane_action_object_camera->setChecked(false);
    d->side_pane_action_object_camera->setToolTip("Set object mode");
    d->side_pane_action_object_camera->setIcon(QPixmap(":axlGui/pixmaps/emblem-generic.png"));

    d->side_pane_action_trackball_interactor = new QAction("Trackball mode", this);
    d->side_pane_action_trackball_interactor->setShortcut(Qt::Key_T);
    d->side_pane_action_trackball_interactor->setCheckable(true);
    d->side_pane_action_trackball_interactor->setChecked(true);
    d->side_pane_action_trackball_interactor->setToolTip("Set trackball mode");
    d->side_pane_action_trackball_interactor->setIcon(QPixmap(":axlGui/pixmaps/applications-science.png"));

    d->side_pane_action_joystick_interactor = new QAction("Joystick mode", this);
    d->side_pane_action_joystick_interactor->setShortcut(Qt::Key_J);
    d->side_pane_action_joystick_interactor->setCheckable(true);
    d->side_pane_action_joystick_interactor->setChecked(false);
    d->side_pane_action_joystick_interactor->setToolTip("Set joytick mode");
    d->side_pane_action_joystick_interactor->setIcon(QPixmap(":axlGui/pixmaps/applications-games.png"));

    d->side_pane_action_settings = new QAction("Setting...", this);
    d->side_pane_action_settings->setShortcut(Qt::ControlModifier + Qt::AltModifier + Qt::Key_I);
    d->side_pane_action_settings->setCheckable(true);
    d->side_pane_action_settings->setChecked(false);
    d->side_pane_action_settings->setToolTip("Configure Axel");
    d->side_pane_action_settings->setIcon(QPixmap(":axlGui/pixmaps/applications-engineering.png"));

    d->side_pane_action_switch_fullScreen_normal = new QAction(QIcon(QPixmap(":axlGui/pixmaps/view-fullscreen.png")), QString("Show fullscreen"), this);
    d->side_pane_action_switch_fullScreen_normal->setShortcut(Qt::ControlModifier + Qt::Key_F);

    QActionGroup *camera_action_group = new QActionGroup(this);
    camera_action_group->addAction(d->side_pane_action_world_camera);
    camera_action_group->addAction(d->side_pane_action_object_camera);
    camera_action_group->setExclusive(true);

    QActionGroup *interactor_action_group = new QActionGroup(this);
    interactor_action_group->addAction(d->side_pane_action_trackball_interactor);
    interactor_action_group->addAction(d->side_pane_action_joystick_interactor);
    interactor_action_group->setExclusive(true);

    QAction *inspectorAction = new QAction("Inspector", this);
    inspectorAction->setIcon(QIcon(":axlGui/pixmaps/info2.png"));
    inspectorAction->setShortcut(Qt::ControlModifier + Qt::Key_I);
    inspectorAction->setCheckable(true);
    inspectorAction->setChecked(false);

    this->addAction(inspectorAction);
    this->addWidget(new dtkSpacer(this, 0, 50));
    this->addAction(d->side_pane_action_world_camera);
    this->addAction(d->side_pane_action_object_camera);
    this->addAction(d->side_pane_action_trackball_interactor);
    this->addAction(d->side_pane_action_joystick_interactor);
    this->addWidget(new dtkSpacer(this));
    this->addAction(d->side_pane_action_settings);
    this->addWidget(new dtkSpacer(this, 0, 50));
    this->addAction(d->side_pane_action_switch_fullScreen_normal);

    this->setFloatable(false);
    this->setIconSize(QSize(24, 24));
    this->setMovable(false);
    this->setOrientation(Qt::Vertical);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    this->setStyleSheet(dtkReadFile(":axlGui/axlInspectorSidePane.qss"));

    connect(d->side_pane_action_world_camera, SIGNAL(triggered()), this, SIGNAL(worldCamera()));
    connect(d->side_pane_action_object_camera, SIGNAL(triggered()), this, SIGNAL(objectCamera()));
    connect(d->side_pane_action_trackball_interactor, SIGNAL(triggered()), this, SIGNAL(trackballCamera()));
    connect(d->side_pane_action_joystick_interactor, SIGNAL(triggered()), this, SIGNAL(joystickCamera()));
    connect(d->side_pane_action_settings, SIGNAL(triggered(bool)), this, SIGNAL(showSettings(bool)));
    connect(d->side_pane_action_switch_fullScreen_normal, SIGNAL(triggered()), this, SIGNAL(switchFullScreen()));

    connect(inspectorAction, SIGNAL(triggered(bool)), this, SIGNAL(showInspector(bool)));
}

axlInspectorSidePane::~axlInspectorSidePane(void)
{
    delete d;

    d = NULL;
}

QSize axlInspectorSidePane::sizeHint(void) const
{
    return QSize(30, 100);
}
