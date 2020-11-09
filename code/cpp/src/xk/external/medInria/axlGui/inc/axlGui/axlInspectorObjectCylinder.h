/* axlInspectorObjectCylinder.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Fri Mar 18 11:18:43 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 28 16:57:54 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 13
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTCYLINDER_H
#define AXLINSPECTOROBJECTCYLINDER_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlCylinder;
class dtkAbstractData;

class axlInspectorObjectCylinderPrivate;

class AXLGUI_EXPORT axlInspectorObjectCylinder: public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectCylinder(QWidget *parent = 0);
    ~axlInspectorObjectCylinder(void);

    QSize sizeHint(void) const;

//signals:
    //void dataChangedByGeometry(dtkAbstractData *data);
    //void modifiedProperty(dtkAbstractData *,int);
    //void update(void);

public slots:
    void setData(axlCylinder *cylinder);
    void onCoordDataChangedFirst_x(double x);
    void onCoordDataChangedFirst_y(double y);
    void onCoordDataChangedFirst_z(double z);

    void onCoordDataChangedSecond_x(double x);
    void onCoordDataChangedSecond_y(double y);
    void onCoordDataChangedSecond_z(double z);
    void onRadiusChanged(double radius);


    void onColorChanged(QColor color);
   // void onSizeChanged(int size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

public slots:
    void updateValues(void);

private :
    //  void initComboBoxShaderValue(void);
    void initWidget(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectCylinderPrivate *d;
};

#endif //AXLINSPECTOROBJECTCYLINDER_H
