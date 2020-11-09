/* axlInspectorLight.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 17:17:53 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:37:04 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 14
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORLIGHT_H
#define AXLINSPECTORLIGHT_H

#include "axlGuiExport.h"

class axlAbstractView;

class dtkAbstractData;

#include <QtWidgets>

class axlInspectorLightPrivate;

class AXLGUI_EXPORT axlInspectorLight : public QDialog
{
    Q_OBJECT

public:
     axlInspectorLight(QWidget *parent = 0);
    ~axlInspectorLight(void);

     void setView(axlAbstractView *view);


public slots:
    void onActiveDefaultLight(bool useDefaultLight);
    void onValueChanged(QString value);
    void onLightVisibilityChanged(bool hide);
    void onPositionChanged(double x, double y, double z);


private :
    void setStateLight(bool state);

private:
    axlInspectorLightPrivate *d;
};

#endif //AXLINSPECTORLIGHT_H
