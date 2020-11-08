// Version: $Id: 66701796e3bb434a00252e42091cf0855d2939ad $
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

#include <dtkComposerSupportExport.h>

#include <QtWidgets>

class dtkComposerScene;
class dtkComposerSceneViewPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerSceneView : public QTreeView
{
    Q_OBJECT

public:
     dtkComposerSceneView(QWidget *parent = 0);
    ~dtkComposerSceneView(void);

public:
    void setScene(dtkComposerScene *scene);

public:
    void reset(void);

public slots:
    void clearSelection(void);

protected slots:
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

private:
    dtkComposerSceneViewPrivate *d;
};

//
// dtkComposerSceneView.h ends here
