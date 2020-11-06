// Version: $Id: 440ca192747f48a3eea65149dca86810bc459bc0 $
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

#include <QtWidgets>

class dtkComposerScene;
class dtkComposerSceneViewPrivate;

class DTKCOMPOSER_EXPORT dtkComposerSceneView : public QTreeView
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
