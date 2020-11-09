/* axlInspectorCamera.h ---
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

#ifndef AXLINSPECTORCAMERA_H
#define AXLINSPECTORCAMERA_H

#include "axlGuiExport.h"

class axlAbstractView;

class dtkAbstractData;

#include <QtWidgets>

class axlInspectorCameraPrivate;

class AXLGUI_EXPORT axlInspectorCamera : public QDialog
{
    Q_OBJECT

public:
     axlInspectorCamera(QWidget *parent = 0);
    ~axlInspectorCamera(void);

     void setView(axlAbstractView *view);
     void updateView(void);

public slots:
     void onCameraViewChanged(void);
     void onCameraProjectionChanged(void);
     void onGridChanged(void);


private :
    void setStateLight(bool state);

private:
    axlInspectorCameraPrivate *d;
};

#endif //AXLINSPECTORCAMERA_H
