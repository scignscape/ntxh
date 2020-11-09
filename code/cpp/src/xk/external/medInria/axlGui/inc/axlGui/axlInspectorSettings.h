/* axlInspectorSettings.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Mar 15 14:06:35 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 15:53:56 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 13
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORSETTINGS_H
#define AXLINSPECTORSETTINGS_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlInspectorSettingsPrivate;

class AXLGUI_EXPORT axlInspectorSettings : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth)

public:
     axlInspectorSettings(QWidget *parent = 0);
    ~axlInspectorSettings(void);

public:
     int width(void) const;

public slots:
     void setWidth(int width);

private:
    axlInspectorSettingsPrivate *d;
};

#endif
