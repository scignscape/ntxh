/* axlInspectorObjectSphere.h ---
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

#ifndef AXLINSPECTOROBJECTSPHERE_H
#define AXLINSPECTOROBJECTSPHERE_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlSphere;
class dtkAbstractData;

class axlInspectorObjectSpherePrivate;

class AXLGUI_EXPORT axlInspectorObjectSphere : public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectSphere(QWidget *parent = 0);
    ~axlInspectorObjectSphere(void);

    QSize sizeHint(void) const;


signals :

    void colorChanged(QColor color,  dtkAbstractData *data);

    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedBySize(dtkAbstractData *data, double size);
    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
    void dataChangedByGeometry(dtkAbstractData *data);


    void update(void);
    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlSphere *point);
    void onCoordDataChanged_x(double x);
    void onCoordDataChanged_y(double y);
    void onCoordDataChanged_z(double z);
    void onRadiusChanged(double radius);

    void onColorChanged(QColor color);
//    void onSizeChanged(int size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

    //void onResolutionChanged(int number);
    void updateValues(void);
public slots :
    void onRecievedDataChanged(void);

private :
    void initComboBoxShaderValue(void);
    void initWidget(void);
//    int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectSpherePrivate *d;
};

#endif //AXLINSPECTOROBJECTSPHERE_H
