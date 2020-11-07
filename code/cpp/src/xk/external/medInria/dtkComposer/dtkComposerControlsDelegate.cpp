// Version: $Id: 49927a385e7500b1f29e8930cc7797dc55b85490 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerControls.h"
#include "dtkComposerControlsDelegate.h"
#include "dtkComposerControlsListItem.h"

class dtkComposerControlsDelegatePrivate
{
public:
};

dtkComposerControlsDelegate::dtkComposerControlsDelegate(QObject *parent) : QStyledItemDelegate(parent), d(new dtkComposerControlsDelegatePrivate)
{

}

dtkComposerControlsDelegate::~dtkComposerControlsDelegate(void)
{
    delete d;

    d = NULL;
}

void dtkComposerControlsDelegate::paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QLinearGradient gradient;
    gradient.setStart(option.rect.topLeft());
    gradient.setFinalStop(option.rect.bottomLeft());
    gradient.setColorAt(0, Qt::lightGray);
    gradient.setColorAt(1, Qt::gray);

    painter->save();
    painter->fillRect(option.rect, gradient);
    painter->setPen(QColor("#eeeeee"));
    painter->drawLine(option.rect.topLeft(), option.rect.topRight());
    painter->setPen(Qt::darkGray);
    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
    painter->restore();

    QStyledItemDelegate::paint(painter, option, index);
}

void dtkComposerControlsDelegate::setEditorData(QWidget *editor, const QModelIndex& index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}

void dtkComposerControlsDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex& index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);
}

QSize dtkComposerControlsDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    size.setHeight(300);

    return size;
}

void dtkComposerControlsDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}

//
// dtkComposerControlsDelegate.cpp ends here
