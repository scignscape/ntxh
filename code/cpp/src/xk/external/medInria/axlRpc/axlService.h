/* axlService.h ---
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
#ifndef AXLSERVICE_H
#define AXLSERVICE_H

#include "axlRpcExport.h"
#include <qjsonrpcservice.h>
#include <QObject>

class axlAbstractView;
class axlInspector;

class AXLRPC_EXPORT axlService : public QJsonRpcService
{
    Q_OBJECT
    Q_CLASSINFO("serviceName", "axlService")

public:

    axlService(QObject *parent = 0);
    ~axlService();
    void setView(axlAbstractView *w);
    void setInspector(axlInspector *insp);

public Q_SLOTS:

    //test
    QString echo(const QVariant &text);
    //insert a data represented by its identifier value.
    QString sendData(const QVariantList& list);
    //QString sendData(const QVariant& adress);//to be implemented


    //modify the data represented by the identifier id.
    //void modifyData(const QVariant id, const QVariantList list);
    QVariantList update(const QVariant& id) const;

    //read a data saved represented by the identifier id.
    QVariantList getData(const QVariant &id)const;
    //QHash<QString, QVariant> getAllSharedData(void);

    void deleteData(const QVariant& id);
    void modifyData(const QVariantList &list);

    QVariantList callProcess(const QVariantList list) const;


private :
    QHash<QString, QVariant> dataMap;
    axlAbstractView *view;
    axlInspector *inspector;
};
#endif // AXLSERVICE_H
