/* axlInspectorObjectSet.h ---
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

#ifndef AXLINSPECTOROBJECTSET_H
#define AXLINSPECTOROBJECTSET_H

#include "axlGuiExport.h"

#include <QtWidgets>

class dtkAbstractData;

class axlInspectorObjectSetPrivate;

class AXLGUI_EXPORT axlInspectorObjectSet : public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectSet(QWidget *parent = 0);
    ~axlInspectorObjectSet(void);

    QSize sizeHint(void) const;


signals :

    void colorChanged(QColor color,  dtkAbstractData *data);

//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
    void dataChangedByGeometry(dtkAbstractData *data);
//    void dataChangedBySize(dtkAbstractData *data, double size);

    void update(void);
    void modifiedProperty(dtkAbstractData *, int);

public slots:
    void setData(QList<dtkAbstractData *> dataSet);
    void onSamplingDataChanged_u(int numSamples);
    void onSamplingDataChanged_v(int numSamples);
    void onSizeChanged(int size);

    void onColorChanged(QColor color);
    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);


private :
    void initComboBoxShaderValue(void);
    void initTag(void);
    void initWidget(void);
    int initSizeValue(void);
    int initOpacityValue(void);

private:
    axlInspectorObjectSetPrivate *d;
};

#endif //AXLINSPECTOROBJECTSET_H