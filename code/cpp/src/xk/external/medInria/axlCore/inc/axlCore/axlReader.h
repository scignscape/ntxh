/* axlReader.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 12:46:01 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Sep 21 11:07:14 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 43
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLREADER_H
#define AXLREADER_H

#include "axlCoreExport.h"

#include <QtCore>
#include <QtXml>

class dtkAbstractData;
class axlAbstractData;


class axlReaderPrivate;

class axlAbstractDataReader;

class AXLCORE_EXPORT axlReader: public QObject
{
    Q_OBJECT

public:
     axlReader(void);
    ~axlReader(void);

signals:
    void dataSetInserted(QList<axlAbstractData *> dataSet);
    void dataSetFieldsChanged(QList<axlAbstractData *> dataSet, QString fieldName);
    void dataSceneRead(QDomElement);

public :
    bool importOFF(const QString& file);

public slots:
    bool read(const QString& file);
    axlAbstractData *read(const QDomNode& node);

public :
    QList<axlAbstractData *> dataSet(void);
    axlAbstractData *data(int index);

private :
    axlAbstractData *dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node);

private:
    axlReaderPrivate *d;
};


#endif //AXLREADER_H
