/* axlInspectorObject.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 19:39:37 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Mar 28 17:00:42 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECT_H
#define AXLINSPECTOROBJECT_H

#include "axlGuiExport.h"

#include <QtWidgets>

class dtkAbstractData;

class axlInspectorObjectController;

class axlInspectorObjectPrivate;

class AXLGUI_EXPORT axlInspectorObject : public QScrollArea
{
    Q_OBJECT

public:
     axlInspectorObject(QWidget *parent = 0);
    ~axlInspectorObject(void);

     void setController(axlInspectorObjectController *controller);

signals:
     void update(void);

//     void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//     void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//     void dataChangedBySize(dtkAbstractData *data, double size);
     void dataChangedByGeometry(dtkAbstractData *data);

     void interpolationChanded(dtkAbstractData *data, int interpolation);

//     void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
     void modifiedProperty(dtkAbstractData *,int);

     void showCurrentPoint(double u, double v, dtkAbstractData *data);
     void moveCurrentPoint(double u, double v, dtkAbstractData *data);
     void hideCurrentPoint(double u, double v,  dtkAbstractData *data);

     void tubeFilterRadiusChanged(dtkAbstractData *, double);

public slots:
    void onDataSelected(dtkAbstractData *data);
    void onDataSetSelected(QList<dtkAbstractData *> dataSet);
    void onDataSetRemoved(QList<dtkAbstractData *> dataSetRemoved);

private:
    axlInspectorObjectPrivate *d;
};

#endif // AXLINSPECTOROBJECT_H
