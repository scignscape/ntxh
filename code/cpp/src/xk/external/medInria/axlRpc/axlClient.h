/* axClient.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2014 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCLIENT_H
#define AXLCLIENT_H


#include <QObject>
#include <QVariant>
#include "axlRpcExport.h"
class axlAbstractData;
class axlAbstractDataComposite;


class AXLRPC_EXPORT axlClient : public QObject
{

    Q_OBJECT

public:
    axlClient();
    ~axlClient();

public slots:

    //send an object represented by its identifier value to the axel view.
    QString sendData(axlAbstractData *data);
    QString sendData(axlAbstractData &data);

    //update the values of data that were modified by axel.
    //void update(void);

    //update one specific object of the client. If the object was deleted in the other application delete it.
    QString update(axlAbstractData *data);
    QString update(axlAbstractData &data);

    //get a data created in axel
    axlAbstractData *getData(const QString& name);

    //delete a data in both application
    void deleteData(axlAbstractData *data);
    void deleteData(axlAbstractData &data);

    //modify a property of a data in the view
    void modifyData(axlAbstractData *data);
    void modifyData(axlAbstractData &data);

    //call a process registered in Axel app. Not necessary to be registered on the python app part.
    axlAbstractData *callProcess(const QString name, axlAbstractDataComposite *inputs , axlAbstractDataComposite *parameters) const;
private :
    QVariantList update(const QString& name) const;
    void sendData(const QVariantList &data);


};

#endif // AXLCLIENT_H
