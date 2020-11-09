/* axlInspectorObjectLine.h ---
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

#ifndef AXLINSPECTOROBJECTLINE_H
#define AXLINSPECTOROBJECTLINE_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlLine;
class dtkAbstractData;

class axlInspectorObjectLinePrivate;

class AXLGUI_EXPORT axlInspectorObjectLine: public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectLine(QWidget *parent = 0);
    ~axlInspectorObjectLine(void);

    QSize sizeHint(void) const;


//signals:
//    void colorChanged(QColor color,  dtkAbstractData *data);
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);
//    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlLine *point);
    void onCoordDataChangedFirst_x(double x);
    void onCoordDataChangedFirst_y(double y);
    void onCoordDataChangedFirst_z(double z);

    void onCoordDataChangedSecond_x(double x);
    void onCoordDataChangedSecond_y(double y);
    void onCoordDataChangedSecond_z(double z);

    void onColorChanged(QColor color);
//    void onSizeChanged(int size);
    void onSizeChanged(double size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

   //some adds for dynamic objects
   void updateValues(void);
   //end adds for dynamic objects


//private :
public :
    void initComboBoxShaderValue(void);
    void initWidget(void);
    int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectLinePrivate *d;
};

#endif //AXLINSPECTOROBJECTLINE_H
