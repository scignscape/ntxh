/* axlInspector.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Mar 14 18:22:02 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov  9 10:59:16 2011 (+0100)
 *           By: Julien Wintz
 *     Update #: 51
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOR_H
#define AXLINSPECTOR_H

#include "axlGuiExport.h"

#include <QtWidgets>

class axlAbstractData;
class dtkAbstractData;
class axlDouble;

class axlAbstractView;
class axlInspectorPrivate;

class AXLGUI_EXPORT axlInspector : public QFrame
{
    Q_OBJECT

public:
             axlInspector(QWidget *parent = 0);
    virtual ~axlInspector(void);

public:
    QSize sizeHint(void) const;

public:
    void insertData(axlAbstractData *data);
    void insertDataSet(QList<axlAbstractData *> dataSet);
    QList<dtkAbstractData *> dataSet(void);

    void setView(axlAbstractView *view);
    void updateView(void);

    void sendFieldSignal(QList<axlAbstractData *> dataSet, QString fieldName);
    void removeData(dtkAbstractData *data);

    void clearScene(void);

signals:
    void update(void);
    void inserted(void);

    void selected(dtkAbstractData *data);
    void stateChanged(dtkAbstractData *data, int mode);
    void actorVisibilityChanged(dtkAbstractData *data, bool actorVisibility);

    void dataInserted(axlAbstractData *data);
    void dataSetRemoved(QList<dtkAbstractData *> dataSetRemoved);

    void dataChanged(dtkAbstractData *data);
    void dataChangedByControlPoints(dtkAbstractData *data);
    void dataChangedByGeometry(dtkAbstractData *data);
//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByShaderFromString(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
//    void dataChangedBySize(dtkAbstractData *data, double size);
//    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
    void modifiedProperty(dtkAbstractData *, int);

    void interpolationChanded(dtkAbstractData *data, int interpolation);


    void showCurrentPoint(double u, double v, dtkAbstractData *data);
    void moveCurrentPoint(double u, double v, dtkAbstractData *data);
    void hideCurrentPoint(double u, double v, dtkAbstractData *data);

    void worldCamera(void);
    void objectCamera(void);
    void trackballCamera(void);
    void joystickCamera(void);
    void switchFullScreen(void);

public slots:
     void onStateChanged(dtkAbstractData *data ,int mode);

protected slots:
     void onShowInspector(bool);
     void onShowSettings(bool);

private:
    axlInspectorPrivate *d;
};

#endif
