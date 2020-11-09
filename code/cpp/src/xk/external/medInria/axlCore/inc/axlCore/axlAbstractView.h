/* axlAbstractView.cpp ---
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

#ifndef AXLABSTRACTVIEW_H
#define AXLABSTRACTVIEW_H

#include "axlAbstractActor.h"
#include "axlAbstractData.h"
#include "axlCoreExport.h"
#include "axlViewController.h"

#include <dtkCoreSupport/dtkAbstractView.h>
#include <dtkCoreSupport/dtkAbstractData.h>

#define AXL_PROPERTY_COLOR 0
#define AXL_PROPERTY_OPACITY 1
#define AXL_PROPERTY_SHADER  2
#define AXL_PROPERTY_SIZE 3

class dtkAbstractViewFactory;

class axlAbstractViewPrivate;

class AXLCORE_EXPORT axlAbstractView : public dtkAbstractView
{
    Q_OBJECT

public:
    axlAbstractView(void);
    virtual ~axlAbstractView(void);

    virtual axlAbstractActor *insert(axlAbstractData *data);
    virtual QList<axlAbstractActor *> insertSet(QList<axlAbstractData *> dataSet);
    virtual void removeSet(QList<axlAbstractActor *> actorSet);
    virtual void removeSetFields(QList<axlAbstractActorField *> actorSet);

    virtual axlAbstractActor *actor(dtkAbstractData *data);

    virtual void insert(dtkAbstractData *data, axlAbstractActor *actor);
    virtual void removeData(dtkAbstractData *data);
    virtual void removeField(dtkAbstractData *data);

    virtual void activeDefaultLigh(bool useDefaultLight);
    virtual void setLight(int i, bool hide, double *position, double *ambiant, double *diffuse, double *specular, int exponent);

    virtual int size(void);
    virtual QString description(void) const { return "axlAbstractView"; }

    axlViewController *controller(void);

    virtual void setCameraViewDefaut(void);
    virtual void setCameraViewNegativeX(void);
    virtual void setCameraViewPositiveX(void);
    virtual void setCameraViewNegativeY(void);
    virtual void setCameraViewPositiveY(void);
    virtual void setCameraViewNegativeZ(void);
    virtual void setCameraViewPositiveZ(void);
    virtual void setParallelCamera(bool parallel);
    virtual void setCameraPosition(double x, double y, double z);
    virtual double *getCameraFocalPoint(void);
    virtual void setCameraFocalPoint(double x, double y, double z);
    virtual double *getCameraUp(void);
    virtual void setCameraUp(double x, double y, double z);
    virtual double getCameraViewAngle(void);
    virtual void setCameraViewAngle(double angle);
    virtual double *getWorldCameraPosition(void);
    virtual bool getAxesVisibility(void);
    virtual bool getParallelProjection(void);
    virtual bool getBackgroundGradient(void);
    virtual void setParallelScale(double parallelScale);
    virtual double getParallelScale(void);



    virtual void setGrid(bool isGridX, bool isGridY, bool isGridZ);

    dtkAbstractViewFactory *getSingletonFactory(void);


signals:
    void inserted(void);
    void stateChanged(dtkAbstractData *data, int mode);
    void lightPositionChanged(double x, double y, double z);
    void insertData(axlAbstractData *data);

public slots:
    void onStateChanged(dtkAbstractData *data, int mode);
    void showColorMapping(dtkAbstractData *data);
    void onShaderChanged(dtkAbstractData *data, QString isophoteShaderXml);
    void onControlPointChanged(dtkAbstractData *data);
    void onTubeFilterRadiusChanged(dtkAbstractData *data, double radius);
    void processIsophoteByShader(dtkAbstractData *data, QString isophoteShaderXml);
    void dataChangedByGeometry(dtkAbstractData *data);
    void dataChangedByProperty(dtkAbstractData *data, int channel);
    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
    void dataChangedBySize(dtkAbstractData *data, double size);
    void dataChangedByColor(dtkAbstractData *data, double red, double green, double blue);
    void onActorVisibilityChanged(dtkAbstractData *data, bool actorVisibility);
    void ondataSetRemoved(QList<dtkAbstractData *> dataSetToRemoved);
    void onLightPositionChanged(double x, double y, double z);
    void onGridResolutionChanged(int resolution);
//    void onShowAxis(bool show);
    virtual void onUpdateActorField(QList<axlAbstractData *> axlDataSet, QString fieldName);
    void onInterpolationChanded(dtkAbstractData*data, int interpolation);



public slots:
    virtual void onShowAxis(bool show);
    virtual void onBackgroundGradientChange(bool gradient);
    virtual void setWorldCamera(void);
    virtual void setObjectCamera(void);
    virtual void setTrackballInteractor(void);
    virtual void setJoystickInteractor(void);
    virtual double *getBackgroundColor(void);

public:
    virtual void update(void);



public :
    // useful fron python interpreter
    virtual void add(dtkAbstractData *data);

    virtual void updateFieldActor(dtkAbstractData *data);

private:
    axlAbstractViewPrivate *d;
};

#endif // AXLABSTRACTVIEW_H
