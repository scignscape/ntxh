/* axlInspectorView.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Mar 30 09:23:23 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Mar 30 13:14:44 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 18
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifndef AXLINSPECTORVIEW_H
#define AXLINSPECTORVIEW_H

#include <QtWidgets>
#include "axlInspectorSeparator.h"

#include "axlGuiExport.h"

class axlAbstractView;
class axlInspectorViewPrivate;

class AXLGUI_EXPORT axlInspectorView : public QFrame
{
    Q_OBJECT

public:
     axlInspectorView(QWidget *parent = 0);
    ~axlInspectorView(void);

    void updateView(void);

public slots:
    void setView(axlAbstractView *view);
    void onBackGroundColorChanged(QColor color);

protected slots:
    void onHeadAddressChanged(const QString&);
    void onFingerAddressChanged(const QString&);
    void onFlystickAddressChanged(const QString&);

    void onHeadToggled(bool);
    void onFingerToggled(bool);
    void onFlystickToggled(bool);

private:
    axlInspectorViewPrivate *d;
};

#endif
