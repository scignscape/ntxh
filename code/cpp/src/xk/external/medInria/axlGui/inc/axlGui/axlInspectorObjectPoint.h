/* axlInspectorObjectPoint.h ---
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

#ifndef AXLINSPECTOROBJECTPOINT_H
#define AXLINSPECTOROBJECTPOINT_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlPoint;
class dtkAbstractData;

class axlInspectorObjectPointPrivate;

class AXLGUI_EXPORT axlInspectorObjectPoint: public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectPoint(QWidget *parent = 0);
    ~axlInspectorObjectPoint(void);

    QSize sizeHint(void) const;


//signals:
//    void colorChanged(QColor color,  dtkAbstractData *data);
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);
//    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlPoint *point);
    void onCoordDataChanged_x(double x);
    void onCoordDataChanged_y(double y);
    void onCoordDataChanged_z(double z);

    void onColorChanged(QColor color);
//    void onSizeChanged(int size);
    void onSizeChanged(double size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

    //some adds for dynamic objects
    void onChangedBoxValue_x(void);
    void onChangedBoxValue_y(void);
    void onChangedBoxValue_z(void);
    void updateValues(void);
    //end adds for dynamic objects


private :
    void initComboBoxShaderValue(void);
    void initWidget(void);
    int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectPointPrivate *d;
};

#endif //AXLINSPECTOROBJECTPOINT_H
