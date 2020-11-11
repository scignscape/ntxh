/* axlInspectorObjectPointSet.h ---
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

#ifndef AXLINSPECTOROBJECTPOINTSET_H
#define AXLINSPECTOROBJECTPOINTSET_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlPointSet;
class dtkAbstractData;

class axlInspectorObjectPointSetPrivate;

class AXLGUI_EXPORT axlInspectorObjectPointSet : public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectPointSet(QWidget *parent = 0);
    ~axlInspectorObjectPointSet(void);

    QSize sizeHint(void) const;


signals :

    void colorChanged(QColor color,  dtkAbstractData *data);

    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
    void dataChangedBySize(dtkAbstractData *data, double size);
    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
    void dataChangedByGeometry(dtkAbstractData *data);


    void update(void);

public slots:
    void setData(axlPointSet *pointt);
    void onColorChanged(QColor color);
    void onSizeChanged(int size);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);


private :
    void initComboBoxShaderValue(void);
    void initWidget(void);
    int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);

private:
    axlInspectorObjectPointSetPrivate *d;
};

#endif //AXLINSPECTOROBJECTPOINTSET_H