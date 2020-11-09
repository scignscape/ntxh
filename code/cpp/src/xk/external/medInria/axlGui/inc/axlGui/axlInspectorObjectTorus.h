/* axlInspectorObjectTorus.h ---
 *
 * Author: Valntin Michelet
 * Copyright (C) 2008 - Valntin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Valntin Michelet
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTTORUS_H
#define AXLINSPECTOROBJECTTORUS_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlTorus;
class dtkAbstractData;

class axlInspectorObjectTorusPrivate;

class AXLGUI_EXPORT axlInspectorObjectTorus : public QFrame {
    Q_OBJECT

public:
    axlInspectorObjectTorus(QWidget *parent = 0);
    virtual ~axlInspectorObjectTorus(void);

    QSize sizeHint(void) const;

signals:
    void colorChanged(QColor color, dtkAbstractData *data);
//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
    void dataChangedByGeometry(dtkAbstractData *data);

    void update(void);
    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlTorus* torus);

    void onCoordDataChangedCenter_x(double x);
    void onCoordDataChangedCenter_y(double y);
    void onCoordDataChangedCenter_z(double z);

    void onCoordDataChangedDirection_x(double x);
    void onCoordDataChangedDirection_y(double y);
    void onCoordDataChangedDirection_z(double z);

    void onRingRadiusChanged(double ringRadius);
    void onCrossSectionRadiusChanged(double crossSectionRadius);

    void onColorChanged(QColor color);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString shader);
    void onLineEditShaderChanged(QString shader);
    void updateValues(void);

private:
    void initComboBoxShaderValue(void);
    void initWidget(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectTorusPrivate* d;
};

#endif // AXLINSPECTOROBJECTTORUS_H
