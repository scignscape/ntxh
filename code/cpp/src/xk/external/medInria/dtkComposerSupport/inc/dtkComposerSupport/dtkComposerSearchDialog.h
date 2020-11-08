/* dtkComposerSearchDialog.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Mon Nov  5 16:35:28 2012 (+0100)
 * Version: $Id: 4b64e0166383b16deecc1f1f2f53bb44003d88b6 $
 * Last-Updated: Thu Nov  8 15:58:02 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 23
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERSEARCHDIALOG_H
#define DTKCOMPOSERSEARCHDIALOG_H

#include <dtkComposerSupportExport.h>

#include <QtWidgets>

class dtkComposerScene;
class dtkComposerSearchDialogPrivate;
class dtkComposerView;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerSearchDialog : public QDialog
{
    Q_OBJECT

public:
    dtkComposerSearchDialog(dtkComposerView *parent = 0);
    ~dtkComposerSearchDialog(void);

public:
    void setScene(dtkComposerScene *scene);

protected slots:
    void find(void);
    void next(void);
    void more(void);
    void clear(void);

private:
    dtkComposerSearchDialogPrivate *d;
};

#endif
