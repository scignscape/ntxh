/* axlInspectorObjectSceneWidgetFieldVectorStream.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Dec 21 14:12:07 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Sep  9 15:18:17 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 13
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTSCENEWIDGETFIELDVECTORSTREAM_H
#define AXLINSPECTOROBJECTSCENEWIDGETFIELDVECTORSTREAM_H

#include <QtWidgets>

#include "axlGuiExport.h"

class axlInspectorObjectSceneWidgetFieldVectorStreamPrivate;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetFieldVectorStream : public QWidget
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetFieldVectorStream(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetFieldVectorStream(void);

signals:
    void streamRadiusValueChanged(double);
    void streamPropagationValueChanged(double);
    void streamDirectionValueChanged(int);

private:
    axlInspectorObjectSceneWidgetFieldVectorStreamPrivate *d;
};

#endif //axlInspectorObjectSceneWidgetFIELDVECTORSTREAM_H
