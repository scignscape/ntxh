/* dtkComposerPath.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Mon Nov 19 11:40:26 2012 (+0100)
 * Version: $Id: 7f4c4fe9fe3b07603aa3a0b3aea44b34242c3ec9 $
 * Last-Updated: Mon Nov 19 15:08:48 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 17
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERPATH_H
#define DTKCOMPOSERPATH_H

#include <dtkComposerSupportExport.h>

#include <QtCore>
#include <QtWidgets>

class dtkComposerPathPrivate;
class dtkComposerScene;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerPath : public QFrame
{
    Q_OBJECT

public:
    dtkComposerPath(QWidget *parent = 0);
    ~dtkComposerPath(void);

public:
    void setScene(dtkComposerScene *scene);

public:
    QSize sizeHint(void) const;

public slots:
    void update(void);

private:
    dtkComposerPathPrivate *d;
};

#endif
