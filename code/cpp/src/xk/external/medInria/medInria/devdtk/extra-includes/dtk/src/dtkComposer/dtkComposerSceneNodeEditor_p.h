/* dtkComposerSceneNodeEditor_p.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Wed Feb  8 10:28:04 2012 (+0100)
 * Version: $Id: a0a8d8468bfe1033f330178cb9ec1970463104be $
 * Last-Updated: lun. juil.  6 16:22:43 2015 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 80
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERSCENENODEEDITOR_P_H
#define DTKCOMPOSERSCENENODEEDITOR_P_H

#include <QtWidgets>

class dtkComposerScene;
class dtkComposerSceneNode;
class dtkComposerScenePort;
class dtkComposerStack;
class dtkComposerGraph;
class dtkToolBox;

// /////////////////////////////////////////////////////////////////
// dtkComposerSceneNodeEditorList
// /////////////////////////////////////////////////////////////////

class dtkComposerSceneNodeEditorList : public QListWidget
{
    Q_OBJECT

public:
    dtkComposerSceneNodeEditorList(QWidget *parent = 0);
    ~dtkComposerSceneNodeEditorList(void);

public:
    QSize sizeHint(void) const;

public:
    void  addInputPort(dtkComposerScenePort *port);
    void addOutputPort(dtkComposerScenePort *port);

protected slots:
    void onItemChanged(QListWidgetItem *item);
    void onItemClicked(QListWidgetItem *item);
};

// /////////////////////////////////////////////////////////////////
// dtkComposerSceneNodeEditorListItem
// /////////////////////////////////////////////////////////////////

class dtkComposerSceneNodeEditorListItem : public QListWidgetItem
{
public:
    dtkComposerSceneNodeEditorListItem(dtkComposerScenePort *port, dtkComposerSceneNodeEditorList *parent);
    ~dtkComposerSceneNodeEditorListItem(void);

    int type(void) const;

    dtkComposerScenePort *port(void);

private:
    dtkComposerScenePort *m_port;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerSceneNodeEditor
// /////////////////////////////////////////////////////////////////

class dtkComposerSceneNodeEditorPrivate
{
public:
    dtkComposerSceneNodeEditorList *loop_ports;
    dtkComposerSceneNodeEditorList *input_ports;
    dtkComposerSceneNodeEditorList *output_ports;
    dtkComposerSceneNodeEditorList *blocks;

public:
    dtkComposerScene *scene;
    dtkComposerSceneNode *node;
    dtkComposerStack *stack;
    dtkComposerGraph *graph;

public:
    QPushButton *add_loop_port;
    QPushButton *rem_loop_port;

    QPushButton *add_block;
    QPushButton *rem_block;

    QPushButton *add_input_port;
    QPushButton *rem_input_port;
    QPushButton *add_output_port;
    QPushButton *rem_output_port;

public:
    QLineEdit *edit;

public:
    QSpinBox *spin_d;

public:
    QDoubleSpinBox *spin_f;

public:
    QLineEdit *edit_s;
    QToolButton *butn_f;
    QToolButton *butn_d;

public:
    QHBoxLayout *layout_widg_edit;
    QVBoxLayout *layout;

public:
    QRadioButton *t_b;
    QRadioButton *f_b;
    QButtonGroup *g_b;
    QWidget *bool_widget;
    QWidget *current_widget;

public:
    QComboBox *select_implementation;

public:
    QComboBox *selector;

public:
    dtkToolBox *node_toolbox;
};

#endif
