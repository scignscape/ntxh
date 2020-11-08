/* dtkComposerControlsDelegate.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Nov 28 15:06:31 2012 (+0100)
 * Version: $Id: 74d204a72b0c305c0dd49aff3f896e5e1c0946cf $
 * Last-Updated: Wed Dec 18 15:39:32 2013 (+0100)
 *           By: etienne delclaux
 *     Update #: 58
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERCONTROLSDELEGATE_H
#define DTKCOMPOSERCONTROLSDELEGATE_H

#include <dtkComposerSupportExport.h>

#include <QtWidgets>

class dtkComposerControlsDelegatePrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerControlsDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    dtkComposerControlsDelegate(QObject *parent = 0);
    ~dtkComposerControlsDelegate(void);

public:
    void paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
public:
    void setEditorData(QWidget *editor, const QModelIndex& index ) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex& index) const;

public:
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

public:
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
    dtkComposerControlsDelegatePrivate *d;
};

#endif
