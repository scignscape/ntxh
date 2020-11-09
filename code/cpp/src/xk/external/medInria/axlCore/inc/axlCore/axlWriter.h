    /* axlWriter.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 12:46:01 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 12:46:03 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 1
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLWRITER_H
#define AXLWRITER_H

#include "axlCoreExport.h"

#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtCore>
//#include <QtXml>
#include <QtXml/QtXml>

class axlAbstractCurveBSpline;
class axlAbstractDataComposite;
class axlAbstractSurfaceBSpline;
class axlPoint;

class axlAbstractDataWriter;

class dtkAbstractData;

class axlWriterPrivate;

class AXLCORE_EXPORT axlWriter: public QObject
{
    Q_OBJECT

public:
    axlWriter(void);
    virtual ~axlWriter(void);

    void setDataToWrite(QList<dtkAbstractData *> dataSet);
    void addDataToWrite(dtkAbstractData * dataSet);
    void setSceneToWrite(QDomElement sceneView);

    virtual QString description(void) const;

public :
    bool exportOFF(const QString& file);


signals:
    void dataSetInserted(QList<dtkAbstractData *> dataSet);

public slots:
    bool write(const QString& filename);
    bool exportTo_OFF(QString& filename);

public slots:
    int update(void);

private :
    QDomElement elementByWriter(axlAbstractDataWriter *axl_writer, dtkAbstractData *data);

    QDomElement setComposite(axlAbstractDataComposite *data);


    double *knots_u(axlAbstractSurfaceBSpline *surface);
    double *knots_v(axlAbstractSurfaceBSpline *surface);

    QList<axlPoint *> surfaceControlPoint(axlAbstractSurfaceBSpline *surface);
    int countAxlAbstractDataSurfaceBSpline();


private:
    axlWriterPrivate *d;
};

#endif //AXLWRITER_H
