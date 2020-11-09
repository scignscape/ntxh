/* axlInspectorToolCreatorEllipsoid.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 17:17:53 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:37:04 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 14
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLCREATORELLIPSOID_H
#define AXLINSPECTORTOOLCREATORELLIPSOID_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorToolFactory.h>
#include <axlGui/axlInspectorToolCreator.h>

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorEllipsoidPrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorEllipsoid : public axlInspectorToolCreator
{
    Q_OBJECT

public:
    axlInspectorToolCreatorEllipsoid(QWidget *parent = 0);
    ~axlInspectorToolCreatorEllipsoid(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void radiusXUpdated(double radiusX);
    void radiusYUpdated(double radiusY);
    void radiusZUpdated(double radiusZ);
    void dataInserted(axlAbstractData *data);

public slots:
    void onUpdateRadiusX(double);
    void onUpdateRadiusY(double);
    void onUpdateRadiusZ(double);
    void onUpdateSemix(double radius);
    void onUpdateSemiy(double radius);
    void onUpdateSemiz(double radius);
    void orthogonalise(int& status);
    void run(void);

private:
    axlInspectorToolCreatorEllipsoidPrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorEllipsoid(void);

#endif //AXLINSPECTORTOOLCREATORELLIPSOID_H
