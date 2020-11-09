/* axlInspectorToolFieldGenerator.h ---
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

#ifndef AXLINSPECTORTOOLFIELDGENERATOR_H
#define AXLINSPECTORTOOLFIELDGENERATOR_H

#include "axlGuiExport.h"

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolFieldGeneratorPrivate;

class AXLGUI_EXPORT axlInspectorToolFieldGenerator : public QFrame
{
    Q_OBJECT

public:
     axlInspectorToolFieldGenerator(QWidget *parent = 0);
    ~axlInspectorToolFieldGenerator(void);

     void setController(axlInspectorObjectController *controller);

signals:
     void dataSetFieldsChanged(QList<axlAbstractData *> dataSet, QString fieldName);


public slots:
    void setImplementation(const QString& implementation);

public slots:
    void run(void);

private:
    axlInspectorToolFieldGeneratorPrivate *d;
};

#endif //AXLINSPECTORTOOLFIELDGENERATOR_H
