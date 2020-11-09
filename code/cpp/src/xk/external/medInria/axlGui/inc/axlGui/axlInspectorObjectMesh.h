/* axlInspectorObjectMesh.h ---
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

#ifndef axlInspectorObjectMesh_H
#define axlInspectorObjectMesh_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include <QtWidgets>

class axlAbstractData;
class dtkAbstractData;

class axlMesh;
class axlInspectorObjectMeshPrivate;

class AXLGUI_EXPORT axlInspectorObjectMesh:  public axlInspectorObjectInterface //public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectMesh(QWidget *parent = 0);
    ~axlInspectorObjectMesh(void);

    QSize sizeHint(void) const;

signals:
    void interpolationChanded(dtkAbstractData *data, int interpolation);

//    void colorChanged(QColor color,  dtkAbstractData *data);
//    void dataChangedByGeometry(dtkAbstractData *data);
//    void update(void);
//    void modifiedProperty(dtkAbstractData *,int);

public slots:
    void setData(axlAbstractData *data);
    void onColorChanged(QColor color);
    void onSizeChanged(int size);

    void onOpacityChanged(int opacity);

    void openShader(void);
    void onShaderStateChanged(bool isShader);
    void onShaderChanged(QString);
    void onLineEditShaderChanged(QString);

    void onUpdateGeometry(void);

public slots:
    void onInterpolationChanged(int modeInterpolation);


private :
    void initComboBoxShaderValue(void);
    void setObjectDataState(void);
    void initWidget(void);
    int initSizeValue(void);
    int initOpacityValue(void);
    QString initShaderValue(void);
    QColor initColorValue(void);


private:
    axlInspectorObjectMeshPrivate *d;
};

#endif //axlInspectorObjectMesh_H
