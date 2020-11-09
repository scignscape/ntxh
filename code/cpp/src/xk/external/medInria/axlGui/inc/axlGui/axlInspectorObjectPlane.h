/* axlInspectorObjectPlane.h ---
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

#ifndef AXLINSPECTOROBJECTPLANE_H
#define AXLINSPECTOROBJECTPLANE_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlPlane;
class dtkAbstractData;

class axlInspectorObjectPlanePrivate;

class AXLGUI_EXPORT axlInspectorObjectPlane: public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectPlane(QWidget *parent = 0);
    ~axlInspectorObjectPlane(void);

    QSize sizeHint(void) const;


//signals:
//    void colorChanged(QColor color,  dtkAbstractData *data);
//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedBySize(dtkAbstractData *data, double size);
//    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);
//    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlPlane *pointt);
    void onCoordDataChangedPoint_x(double x);
    void onCoordDataChangedPoint_y(double y);
    void onCoordDataChangedPoint_z(double z);

    void onCoordDataChangedNormal_x(double x);
    void onCoordDataChangedNormal_y(double y);
    void onCoordDataChangedNormal_z(double z);

    void onColorChanged(QColor color);
//    void onSizeChanged(int size);
    void onSizeChanged(double size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

    void updateValues(void);

private :
    //void initComboBoxShaderValue(void);
    void initWidget(void);
    int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectPlanePrivate *d;
};

#endif //AXLINSPECTOROBJECTPLANE_H
