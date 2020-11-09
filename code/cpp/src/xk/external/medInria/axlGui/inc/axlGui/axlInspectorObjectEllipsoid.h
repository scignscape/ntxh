/* axlInspectorObjectEllipsoid.h ---
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

#ifndef axlInspectorObjectEllipsoid_H
#define axlInspectorObjectEllipsoid_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlEllipsoid;
class dtkAbstractData;

class axlInspectorObjectEllipsoidPrivate;

class AXLGUI_EXPORT axlInspectorObjectEllipsoid: public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectEllipsoid(QWidget *parent = 0);
    ~axlInspectorObjectEllipsoid(void);

    QSize sizeHint(void) const;

//signals :
//    void colorChanged(QColor color, dtkAbstractData *data);
//    void modifiedProperty(dtkAbstractData *,int);
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);

public slots:
    void onUpdateSemix(double radius);
    void onUpdateSemiy(double radius);
    void onUpdateSemiz(double radius);

    void setData(axlEllipsoid *point);
    void onCoordDataChanged_x(double x);
    void onCoordDataChanged_y(double y);
    void onCoordDataChanged_z(double z);

    void onSemiXDataChanged(double semixx);
    void onSemiYDataChanged(double semixy);
    void onSemiZDataChanged(double semixz);

    void onColorChanged(QColor color);
    //void onSizeChanged(int size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

    void updateValues(void);

private :
    void updateDataNoSignals(void);
    void initComboBoxShaderValue(void);
    void initWidget(void);
    //int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectEllipsoidPrivate *d;
};

#endif //axlInspectorObjectEllipsoid_H
