/* axlInspectorStack.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 15 14:06:35 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Dec 27 12:45:13 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 16
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORSTACK_H
#define AXLINSPECTORSTACK_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlInspectorStackPrivate;

class AXLGUI_EXPORT axlInspectorStack : public QFrame
{
    Q_OBJECT

    Q_PROPERTY(int width READ width WRITE setWidth)

public:
     axlInspectorStack(QWidget *parent = 0);
    ~axlInspectorStack(void);

public:
     int width(void) const;

public:
     void addWidget(QString title, QWidget *widget);

public slots:
     void setWidth(int width);

protected slots:
     void onActionClicked(void);

private:
    axlInspectorStackPrivate *d;
};

#endif
