/* axlInspectorObjectCircleArc.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTCIRCLEARC_H
#define AXLINSPECTOROBJECTCIRCLEARC_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlCircleArc;
class dtkAbstractData;

class axlInspectorObjectCircleArcPrivate;

class AXLGUI_EXPORT axlInspectorObjectCircleArc: public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
    axlInspectorObjectCircleArc(QWidget *parent = 0);
    virtual ~axlInspectorObjectCircleArc(void);

    QSize sizeHint(void) const;

//signals:
//    void colorChanged(QColor color, dtkAbstractData *data);
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);
//    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlCircleArc *arc);

    void onCoordDataChangedPoint1_x(double x);
    void onCoordDataChangedPoint1_y(double y);
    void onCoordDataChangedPoint1_z(double z);

    void onCoordDataChangedPoint2_x(double x);
    void onCoordDataChangedPoint2_y(double y);
    void onCoordDataChangedPoint2_z(double z);

    void onCoordDataChangedCenter_x(double x);
    void onCoordDataChangedCenter_y(double y);
    void onCoordDataChangedCenter_z(double z);

    void onCoordDataChangedNormal_x(double x);
    void onCoordDataChangedNormal_y(double y);
    void onCoordDataChangedNormal_z(double z);

    void onSizeChanged(double);
    void onColorChanged(QColor color);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString shader);
    void onLineEditShaderChanged(QString shader);

    void manageNormal(double);
    void manageCenter(double);
    void inverseNormal(void);

public slots:
    void updateValues(void);

private:
    void initComboBoxShaderValue(void);
    void initWidget(void);
    int initOpacityValue(void);
    int initSizeValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectCircleArcPrivate* d;
};

#endif // AXLINSPECTOROBJECTCIRCLEARC_H
