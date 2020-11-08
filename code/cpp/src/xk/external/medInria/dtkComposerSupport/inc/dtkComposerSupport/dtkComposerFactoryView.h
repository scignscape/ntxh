/* dtkComposerFactoryView.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 31 13:22:54 2012 (+0100)
 * Version: $Id: 507922901b31127e1b773c522edd888930e8ddfd $
 * Last-Updated: Tue Sep 17 13:43:47 2013 (+0200)
 *           By: Julien Wintz
 *     Update #: 28
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERFACTORYVIEW_H
#define DTKCOMPOSERFACTORYVIEW_H

#include <dtkComposerSupportExport.h>

#include <QtCore>
#include <QtWidgets>

class dtkComposerFactory;
class dtkComposerFactoryViewPrivate;
class dtkComposerSceneNode;
class dtkItemView;
class dtkTagScope;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerFactoryView : public QWidget
{
    Q_OBJECT

public:
    dtkComposerFactoryView(QWidget *parent = 0);
    ~dtkComposerFactoryView(void);

public:
    void setFactory(dtkComposerFactory *factory);

public slots:
    void onShowNodeDocumentation(dtkComposerSceneNode *node);

public:
    void showTagCloud(const bool show);

public:
    void setBlue(void);
    void setDark(void);

private:
    dtkComposerFactoryViewPrivate *d;
};

#endif
