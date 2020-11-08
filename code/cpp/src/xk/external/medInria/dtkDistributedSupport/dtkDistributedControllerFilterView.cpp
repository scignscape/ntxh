/* dtkDistributedControllerFilterView.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Apr 10 10:12:41 2012 (+0200)
 * Version: $Id: b899c9eb8d2c5d0ec8f2745ccd8ef8a2cb44752f $
 * Last-Updated: mar. avril 24 10:37:10 2012 (+0200)
 *           By: Nicolas Niclausse
 *     Update #: 271
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkDistributedNode.h"
#include "dtkDistributedControllerFilterView.h"

class dtkDistributedControllerFilterViewPrivate
{
public:
    QFlags<dtkDistributedNode::Network> network_flags;
    QFlags<dtkDistributedNode::State> state_flags;
    QFlags<dtkDistributedNode::Brand> brand_flags;
    QFlags<dtkDistributedCpu::Architecture> arch_flags;
    QFlags<dtkDistributedCpu::Model> model_flags;
};

dtkDistributedControllerFilterView::dtkDistributedControllerFilterView(QWidget *parent) : QTreeWidget(parent), d(new dtkDistributedControllerFilterViewPrivate)
{
    QGroupBox *network_box = new QGroupBox(this);
    QGroupBox *state_box = new QGroupBox(this);
    QGroupBox *brand_box = new QGroupBox(this);
    QGroupBox *arch_box = new QGroupBox(this);
    QGroupBox *model_box = new QGroupBox(this);

    QRadioButton *network_1 = new QRadioButton("Ethernet1G", network_box);
    QRadioButton *network_2 = new QRadioButton("Ethernet10G", network_box);
    QRadioButton *network_3 = new QRadioButton("Myrinet2G", network_box);
    QRadioButton *network_4 = new QRadioButton("Myrinet10G", network_box);
    QRadioButton *network_5 = new QRadioButton("Infiniband10G", network_box);
    QRadioButton *network_6 = new QRadioButton("Infiniband20G", network_box);
    QRadioButton *network_7 = new QRadioButton("Infiniband40G", network_box);

    QRadioButton *state_1 = new QRadioButton("Free", state_box);
    QRadioButton *state_2 = new QRadioButton("Busy", state_box);
    QRadioButton *state_3 = new QRadioButton("Down", state_box);
    QRadioButton *state_4 = new QRadioButton("StandBy", state_box);
    QRadioButton *state_5 = new QRadioButton("Absent", state_box);

    QRadioButton *brand_1 = new QRadioButton("Hp", brand_box);
    QRadioButton *brand_2 = new QRadioButton("Ibm", brand_box);
    QRadioButton *brand_3 = new QRadioButton("Dell", brand_box);
    QRadioButton *brand_4 = new QRadioButton("Carri", brand_box);

    QRadioButton *arch_1 = new QRadioButton("x86", arch_box);
    QRadioButton *arch_2 = new QRadioButton("x86_64", arch_box);

    QRadioButton *model_1 = new QRadioButton("Xeon", model_box);
    QRadioButton *model_2 = new QRadioButton("Opteron", model_box);

    QButtonGroup *network_group = new QButtonGroup(this);
    network_group->setExclusive(false);
    network_group->addButton(network_1, 1);
    network_group->addButton(network_2, 2);
    network_group->addButton(network_3, 3);
    network_group->addButton(network_4, 4);
    network_group->addButton(network_5, 5);
    network_group->addButton(network_6, 6);
    network_group->addButton(network_7, 7);

    QButtonGroup *state_group = new QButtonGroup(this);
    state_group->setExclusive(false);
    state_group->addButton(state_1, 1);
    state_group->addButton(state_2, 2);
    state_group->addButton(state_3, 3);
    state_group->addButton(state_4, 4);
    state_group->addButton(state_5, 5);

    QButtonGroup *brand_group = new QButtonGroup(this);
    brand_group->setExclusive(false);
    brand_group->addButton(brand_1, 1);
    brand_group->addButton(brand_2, 2);
    brand_group->addButton(brand_3, 3);
    brand_group->addButton(brand_4, 4);

    QButtonGroup *arch_group = new QButtonGroup(this);
    arch_group->setExclusive(false);
    arch_group->addButton(arch_1, 1);
    arch_group->addButton(arch_2, 2);

    QButtonGroup *model_group = new QButtonGroup(this);
    model_group->setExclusive(false);
    model_group->addButton(model_1, 1);
    model_group->addButton(model_2, 2);

    QVBoxLayout *network_layout = new QVBoxLayout;
    network_layout->setContentsMargins(0, 0, 0, 0);
    network_layout->addWidget(network_1);
    network_layout->addWidget(network_2);
    network_layout->addWidget(network_3);
    network_layout->addWidget(network_4);
    network_layout->addWidget(network_5);
    network_layout->addWidget(network_6);
    network_layout->addWidget(network_7);

    QVBoxLayout *state_layout = new QVBoxLayout;
    state_layout->setContentsMargins(0, 0, 0, 0);
    state_layout->addWidget(state_1);
    state_layout->addWidget(state_2);
    state_layout->addWidget(state_3);
    state_layout->addWidget(state_4);
    state_layout->addWidget(state_5);

    QVBoxLayout *brand_layout = new QVBoxLayout;
    brand_layout->setContentsMargins(0, 0, 0, 0);
    brand_layout->addWidget(brand_1);
    brand_layout->addWidget(brand_2);
    brand_layout->addWidget(brand_3);
    brand_layout->addWidget(brand_4);

    QVBoxLayout *arch_layout = new QVBoxLayout;
    arch_layout->setContentsMargins(0, 0, 0, 0);
    arch_layout->addWidget(arch_1);
    arch_layout->addWidget(arch_2);

    QVBoxLayout *model_layout = new QVBoxLayout;
    model_layout->setContentsMargins(0, 0, 0, 0);
    model_layout->addWidget(model_1);
    model_layout->addWidget(model_2);

    network_box->setLayout(network_layout);
    state_box->setLayout(state_layout);
    brand_box->setLayout(brand_layout);
    arch_box->setLayout(arch_layout);
    model_box->setLayout(model_layout);

    QTreeWidgetItem *network_item = new QTreeWidgetItem(this, QStringList() << "Network");
    QTreeWidgetItem *state_item = new QTreeWidgetItem(this, QStringList() << "State");
    QTreeWidgetItem *brand_item = new QTreeWidgetItem(this, QStringList() << "Brand");
    QTreeWidgetItem *arch_item = new QTreeWidgetItem(this, QStringList() << "Architecture");
    QTreeWidgetItem *model_item = new QTreeWidgetItem(this, QStringList() << "Model");

    this->addTopLevelItem(network_item);
    this->addTopLevelItem(state_item);
    this->addTopLevelItem(brand_item);
    this->addTopLevelItem(arch_item);
    this->addTopLevelItem(model_item);

    network_item = new QTreeWidgetItem(network_item);
    state_item = new QTreeWidgetItem(state_item);
    brand_item = new QTreeWidgetItem(brand_item);
    arch_item = new QTreeWidgetItem(arch_item);
    model_item = new QTreeWidgetItem(model_item);

    this->setItemWidget(network_item, 0, network_box);
    this->setItemWidget(state_item, 0, state_box);
    this->setItemWidget(brand_item, 0, brand_box);
    this->setItemWidget(arch_item, 0, arch_box);
    this->setItemWidget(model_item, 0, model_box);

    this->setHeaderLabel("Filters");
    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setFrameStyle(QFrame::NoFrame);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(network_group, SIGNAL(buttonClicked(int)), this, SLOT(onNetworkButtonClicked(int)));
    connect(state_group, SIGNAL(buttonClicked(int)), this, SLOT(onStateButtonClicked(int)));
    connect(brand_group, SIGNAL(buttonClicked(int)), this, SLOT(onBrandButtonClicked(int)));
    connect(arch_group, SIGNAL(buttonClicked(int)), this, SLOT(onArchButtonClicked(int)));
    connect(model_group, SIGNAL(buttonClicked(int)), this, SLOT(onModelButtonClicked(int)));
}

dtkDistributedControllerFilterView::~dtkDistributedControllerFilterView(void)
{
    delete d;

    d = NULL;
}

QSize dtkDistributedControllerFilterView::sizeHint(void) const
{
    return QSize(100, 200);
}

QFlags<dtkDistributedNode::Network> dtkDistributedControllerFilterView::networkFlags(void)
{
    return d->network_flags;
}

QFlags<dtkDistributedNode::State> dtkDistributedControllerFilterView::stateFlags(void)
{
    return d->state_flags;
}

QFlags<dtkDistributedNode::Brand> dtkDistributedControllerFilterView::brandFlags(void)
{
    return d->brand_flags;
}

QFlags<dtkDistributedCpu::Architecture> dtkDistributedControllerFilterView::archFlags(void)
{
    return d->arch_flags;
}

QFlags<dtkDistributedCpu::Model> dtkDistributedControllerFilterView::modelFlags(void)
{
    return d->model_flags;
}

void dtkDistributedControllerFilterView::onNetworkButtonClicked(int button)
{
    switch (button) {
    case 1: d->network_flags ^= dtkDistributedNode::Ethernet1G; break;

    case 2: d->network_flags ^= dtkDistributedNode::Ethernet10G; break;

    case 3: d->network_flags ^= dtkDistributedNode::Myrinet2G; break;

    case 4: d->network_flags ^= dtkDistributedNode::Myrinet10G; break;

    case 5: d->network_flags ^= dtkDistributedNode::Infiniband10G; break;

    case 6: d->network_flags ^= dtkDistributedNode::Infiniband20G; break;

    case 7: d->network_flags ^= dtkDistributedNode::Infiniband40G; break;

    default:
        break;
    }

    emit updated();
}

void dtkDistributedControllerFilterView::onStateButtonClicked(int button)
{
    switch (button) {
    case 1: d->state_flags ^= dtkDistributedNode::Free; break;

    case 2: d->state_flags ^= dtkDistributedNode::Busy; break;

    case 3: d->state_flags ^= dtkDistributedNode::Down; break;

    case 4: d->state_flags ^= dtkDistributedNode::StandBy; break;

    case 5: d->state_flags ^= dtkDistributedNode::Absent; break;

    default:
        break;
    }

    emit updated();
}

void dtkDistributedControllerFilterView::onBrandButtonClicked(int button)
{
    switch (button) {
    case 1: d->brand_flags ^= dtkDistributedNode::Hp; break;

    case 2: d->brand_flags ^= dtkDistributedNode::Ibm; break;

    case 3: d->brand_flags ^= dtkDistributedNode::Dell; break;

    case 4: d->brand_flags ^= dtkDistributedNode::Carri; break;

    default:
        break;
    }

    emit updated();
}

void dtkDistributedControllerFilterView::onArchButtonClicked(int button)
{
    switch (button) {
    case 1: d->arch_flags ^= dtkDistributedCpu::x86; break;

    case 2: d->arch_flags ^= dtkDistributedCpu::x86_64; break;

    default:
        break;
    }

    emit updated();
}

void dtkDistributedControllerFilterView::onModelButtonClicked(int button)
{
    switch (button) {
    case 1: d->model_flags ^= dtkDistributedCpu::Xeon; break;

    case 2: d->model_flags ^= dtkDistributedCpu::Opteron; break;

    default:
        break;
    }

    emit updated();
}
