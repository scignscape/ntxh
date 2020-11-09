/* axlInspectorSidePane.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 15 14:06:35 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 11:12:00 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 11
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORSIDEPANE_H
#define AXLINSPECTORSIDEPANE_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlInspectorSidePanePrivate;

class AXLGUI_EXPORT axlInspectorSidePane : public QToolBar
{
    Q_OBJECT

public:
     axlInspectorSidePane(QWidget *parent = 0);
    ~axlInspectorSidePane(void);

    QSize sizeHint(void) const;

signals:
    void showInspector(bool);
    void worldCamera(void);
    void objectCamera(void);
    void trackballCamera(void);
    void joystickCamera(void);
    void showSettings(bool);
    void switchFullScreen(void);

private:
    axlInspectorSidePanePrivate *d;
};

#endif
