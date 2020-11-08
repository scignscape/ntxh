// Version: $Id: 973ae254f60ca31eacc6047809e93a225be34073 $
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

class dtkComposerNodeFactoryViewPrivate;
class dtkComposerSceneNode;
class dtkWidgetsTagCloudScope;
class dtkWidgetsTagCloudView;

 // //? added
class dtkComposerNodeFactory;



class DTKCOMPOSER_EXPORT dtkComposerNodeFactoryView : public QWidget
{
    Q_OBJECT

public:
    dtkComposerNodeFactoryView(QWidget *parent = 0);
    ~dtkComposerNodeFactoryView(void);

public slots:
    void onShowNodeDocumentation(dtkComposerSceneNode *node);

public:
    void addNote(void);

public:
    void setFactory(dtkComposerNodeFactory *factory);

public:
    void setDark(void);
    void setDoom(void);

public:
    dtkWidgetsTagCloudView   *itemView(void) const;
    dtkWidgetsTagCloudScope *scopeView(void) const;

private:
    dtkComposerNodeFactoryViewPrivate *d;
};

//
// dtkComposerNodeFactoryView.h ends here
