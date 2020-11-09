/* axlAbstractActor.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTACTOR_H
#define AXLABSTRACTACTOR_H

#include "axlCoreExport.h"

class dtkAbstractData;
class axlActor;
class axlMesh;

#include <QObject>
#include <QtGui>
class axlAbstractActorPrivate;

class AXLCORE_EXPORT axlAbstractActor : public QObject
{
    Q_OBJECT

//protected:
public :
    axlAbstractActor(axlAbstractActor *parent = 0);
    virtual ~axlAbstractActor(void);

public:
    virtual bool isVisible(void);

    virtual void setInteractor(void *interactor);
    virtual void setDisplay(bool display);
    virtual void setData(dtkAbstractData *data);
    virtual void showControlPoints(bool show);
    virtual bool isShowControlPoints(void);
    virtual void setMapperCollorArray(void);
    virtual void setShader(QString xmlfile);
    virtual void setShaderFromString(QString xmlfile);
    virtual void setOpacity(double opacity);
    virtual void setSize(double size);
    virtual void setColor(double red, double green, double blue);
    virtual void setInterpolation(int interpolation);

    virtual void setParent(axlAbstractActor *parent);
    virtual axlAbstractActor *parent(void);

    virtual axlMesh *toMesh(void);

    virtual int getState(void);
    virtual void setMode(int state);
    virtual dtkAbstractData *data(void) = 0;
    virtual QString identifier(void);

signals:
    void stateChanged(dtkAbstractData * data, int mode);
    void updated(void);

public slots:
    // bridge
    // AM: do we need both refresh() and onUpdateGeometry ? They seem
    // duplicated here.
    // void refresh(void) { this->onUpdateGeometry(); }
    virtual void onUpdateGeometry(void) = 0;
    virtual void onUpdateProperty(void);

    // Used to update the structure of an object, eg. the control
    // points of a spline geometry when their structure changes
    // (eg. after refinement, ie. adding more control points)
    // Note: by default nothing happens on this event. Re-implement
    // this slot to add behaviour
    virtual void onUpdateStructure(void) { }

    virtual void hide(void);
    virtual void show(void);
    virtual void update(void);

    virtual void onSamplingChanged(void);
    virtual void onTubeFilterRadiusChanged(double radius);
    virtual void onControlPointChanged(void);
    virtual void onRemoved(void);
    virtual void onModeChanged(int state);

    virtual void showCurrentPoint(double u, double v, dtkAbstractData *data);
    virtual void moveCurrentPoint(double u, double v, dtkAbstractData *data);
    virtual void hideCurrentPoint(double u, double v, dtkAbstractData *data);

    virtual void onSelectBoundaryEdge(int numEdge, int previous, int n);

private:
    axlAbstractActorPrivate *d;
};

#endif // AXLABSTRACTACTOR_H
