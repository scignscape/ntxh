/* axlInspectorToolCreateMiddlePoint.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLCREATEMIDDLEPOINT_H
#define AXLINSPECTORTOOLCREATEMIDDLEPOINT_H

#include "axlGuiExport.h"

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreateMiddlePointPrivate;

class AXLGUI_EXPORT axlInspectorToolCreateMiddlePoint : public QFrame
{
    Q_OBJECT

public:
     axlInspectorToolCreateMiddlePoint(QWidget *parent = 0);
    ~axlInspectorToolCreateMiddlePoint(void);

     //void setController(axlInspectorObjectController *controller);

signals:
          void dataInserted(axlAbstractData *data);


public slots:
    void run(void);

private:
    axlInspectorToolCreateMiddlePointPrivate *d;
};

#endif  // AXLINSPECTORTOOLCREATEMIDDLEPOINT_H
