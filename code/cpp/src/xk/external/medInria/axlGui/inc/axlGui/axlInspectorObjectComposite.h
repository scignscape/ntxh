/* axlInspectorObjectComposite.h ---
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

#ifndef AXLINSPECTOROBJECTCOMPOSITE_H
#define AXLINSPECTOROBJECTCOMPOSITE_H

#include "axlGuiExport.h"

#include "axlInspectorUtils.h"

#include <QtWidgets>

class dtkAbstractData;

class axlAbstractDataComposite;
class axlInspectorObjectCompositePrivate;

class AXLGUI_EXPORT axlInspectorObjectComposite : public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectComposite(QWidget *parent = 0);
    ~axlInspectorObjectComposite(void);

     QSize sizeHint(void) const;

signals:
    void showCurrentPoint(double u, double v, dtkAbstractData *data);
    void moveCurrentPoint(double u, double v, dtkAbstractData *data);
    void hideCurrentPoint(double u, double v, dtkAbstractData *data);

//    void colorChanged(QColor color,  dtkAbstractData *data);

//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);

    void update(void);
    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlAbstractDataComposite *data);

    void onColorChanged(QColor color);

    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);


    void onShowCurrentPoint(double u, double v);
    void onMoveCurrentPoint(double u, double v);
    void onHideCurrentPoint(double u, double v);

private:
    void initComboBoxShaderValue(void);


private:
    axlInspectorObjectCompositePrivate *d;
};

#endif //AXLINSPECTOROBJECTCOMPOSITE_H
