/* dtkComposerStackView.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 31 11:06:43 2012 (+0100)
 * Version: $Id: 113136475848f44fa304c3a68e1e5be1c2ac6537 $
 * Last-Updated: Thu Apr 11 10:36:50 2013 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 30
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <dtkComposerExport.h>

#include <QtWidgets>

class dtkComposerStack;
class dtkComposerStackViewPrivate;

class DTKCOMPOSER_EXPORT dtkComposerStackView : public QWidget
{
    Q_OBJECT

public:
    dtkComposerStackView(QWidget *parent = 0);
    ~dtkComposerStackView(void);

public:
    void setStack(dtkComposerStack *stack);

private:
    dtkComposerStackViewPrivate *d;
};

