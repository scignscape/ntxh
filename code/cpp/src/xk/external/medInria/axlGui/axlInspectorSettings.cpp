/* axlInspectorSettings.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Mar 15 14:09:00 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 17:06:56 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 117
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorSettings.h"
#include "axlInspectorSeparator.h"
#include "axlInspectorStack.h"

#include <dtkGuiSupport/dtkPluginsEditor.h>
#include <dtkGuiSupport/dtkSettingsEditor.h>

#include <QtGui>

class axlInspectorSettingsPrivate
{
public:
    axlInspectorStack *stack;

public:
    dtkSettingsEditor *settings_editor;
    dtkPluginsEditor *plugins_editor;
};

axlInspectorSettings::axlInspectorSettings(QWidget *parent) : QFrame(parent), d(new axlInspectorSettingsPrivate)
{
    QSettings settings("inria", "dtk");
    settings.beginGroup("shader");
    if(!settings.contains("path"))
        settings.setValue("path", QDir::homePath());
    settings.endGroup();

    d->settings_editor = new dtkSettingsEditor(this);
    d->settings_editor->setSettings("inria", "dtk");

    d->plugins_editor = new dtkPluginsEditor(this);

    d->stack = new axlInspectorStack(this);
    d->stack->addWidget("Settings", d->settings_editor);
    d->stack->addWidget("Plugins", d->plugins_editor);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(new axlInspectorSeparator(this, Qt::Vertical));
    layout->addWidget(d->stack);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}

axlInspectorSettings::~axlInspectorSettings(void)
{
    delete d;

    d = NULL;
}

int axlInspectorSettings::width() const
{
   return QFrame::width();
}

void axlInspectorSettings::setWidth(int width)
{
   this->setFixedWidth(width);
}

