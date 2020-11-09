/* axlInspectorSwitch.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Feb  4 17:07:56 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 14 14:55:11 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 6
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORSWITCH_H
#define AXLINSPECTORSWITCH_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlInspectorSwitchPrivate;

class AXLGUI_EXPORT axlInspectorSwitch : public QWidget
{
    Q_OBJECT

public:
     axlInspectorSwitch(QWidget *parent = 0);
    ~axlInspectorSwitch(void);

    QSize sizeHint(void) const;

signals:
    void toggled(bool);

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    axlInspectorSwitchPrivate *d;
};

#endif
