/* dtkDistributedControllerHeaderView.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Apr  4 12:22:09 2012 (+0200)
 * Version: $Id: 00842294e02f5e46f0435ba7e3952da516696036 $
 * Last-Updated: Fri Apr  6 11:05:46 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 14
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKDISTRIBUTEDCONTROLLERHEADERVIEW_H
#define DTKDISTRIBUTEDCONTROLLERHEADERVIEW_H

#include <dtkDistributedSupportExport.h>

#include <QtWidgets>

class dtkDistributedController;
class dtkDistributedControllerHeaderViewPrivate;

class DTKDISTRIBUTEDSUPPORT_EXPORT dtkDistributedControllerHeaderView : public QFrame
{
    Q_OBJECT

public:
    dtkDistributedControllerHeaderView(QWidget *parent = 0);
    ~dtkDistributedControllerHeaderView(void);

public:
    void setController(dtkDistributedController *controller);

public slots:
    void setCluster(const QString& cluster);

public slots:
    void onStatus(const QUrl& cluster);
    void onDisconnected(const QUrl& cluster);

protected:
    void update(void);

private:
    dtkDistributedControllerHeaderViewPrivate *d;
};

#endif
