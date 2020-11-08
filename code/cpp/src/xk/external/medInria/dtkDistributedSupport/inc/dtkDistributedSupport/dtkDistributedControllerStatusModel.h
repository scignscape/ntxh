/* dtkDistributedControllerStatusModel.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Jun 29 11:21:32 2011 (+0200)
 * Version: $Id: 29aef624112bf16e838016a4aef17cc35e58a1ad $
 * Last-Updated: Fri Apr  6 11:23:25 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 45
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKDISTRIBUTEDCONTROLLERSTATUSMODEL_H
#define DTKDISTRIBUTEDCONTROLLERSTATUSMODEL_H

#include <QtWidgets>

#include <dtkDistributedSupportExport.h>

class dtkDistributedController;
class dtkDistributedControllerStatusModelPrivate;

class DTKDISTRIBUTEDSUPPORT_EXPORT dtkDistributedControllerStatusModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    dtkDistributedControllerStatusModel(QObject *parent = 0);
    ~dtkDistributedControllerStatusModel(void);

public:
    void setController(dtkDistributedController *controller);

public slots:
    void setCluster(const QString& server);

public slots:
    void onUpdated(void);
    void onUpdated(const QUrl& cluster);
    void onDisconnected(const QUrl& cluster);

public:
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& index) const;

    Qt::ItemFlags flags(const QModelIndex& index) const;

private:
    friend class dtkDistributedControllerStatusModelPrivate; dtkDistributedControllerStatusModelPrivate *d;
};

#endif
