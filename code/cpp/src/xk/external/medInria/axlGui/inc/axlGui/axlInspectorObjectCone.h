/* axlInspectorObjectCone.h ---
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

#ifndef AXLINSPECTOROBJECTCONE_H
#define AXLINSPECTOROBJECTCONE_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlCone;
class dtkAbstractData;

class axlInspectorObjectConePrivate;

class AXLGUI_EXPORT axlInspectorObjectCone: public axlInspectorObjectInterface //QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectCone(QWidget *parent = 0);
    ~axlInspectorObjectCone(void);

public:
    QSize sizeHint(void) const;

//signals :
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);
//    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlCone *cone);

    void onCoordDataChangedApex_x(double x);
    void onCoordDataChangedApex_y(double y);
    void onCoordDataChangedApex_z(double z);

    void onCoordDataChangedBasePoint_x(double x);
    void onCoordDataChangedBasePoint_y(double y);
    void onCoordDataChangedBasePoint_z(double z);
    void onRadiusChanged(double radius);

    void onColorChanged(QColor color);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

public slots:
    void updateValues(void);

private :
    //void initComboBoxShaderValue(void);

    void initWidget(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectConePrivate *d;
};

#endif //AXLINSPECTOROBJECTCONE_H
