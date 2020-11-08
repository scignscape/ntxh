/* dtkComposerSceneModel.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Sun Feb  5 15:22:50 2012 (+0100)
 * Version: $Id: c6bc97b290278a7bfc1474e982ed910ec9a6459f $
 * Last-Updated: Mon Apr 16 12:20:51 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 30
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERSCENEMODEL_H
#define DTKCOMPOSERSCENEMODEL_H

#include <dtkComposerSupportExport.h>

#include <QtCore>
#include <QtWidgets>

class dtkComposerScene;
class dtkComposerSceneModelPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerSceneModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    dtkComposerSceneModel(QObject *parent = 0);
    ~dtkComposerSceneModel(void);

public:
    void setScene(dtkComposerScene *scene);

public:
    Qt::ItemFlags flags(const QModelIndex& index) const;

    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& index) const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;

private:
    dtkComposerSceneModelPrivate *d;
};

#endif
