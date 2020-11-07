// Version: $Id: d94e85633d0602fd2fa86186c8bc75fb475b2ebe $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include <dtkComposerExport.h>

#include <QtCore>
#include <QtWidgets>

class dtkComposerScene;
class dtkComposerSceneModelPrivate;

class DTKCOMPOSER_EXPORT dtkComposerSceneModel : public QAbstractItemModel
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

//
// dtkComposerSceneModel.h ends here
