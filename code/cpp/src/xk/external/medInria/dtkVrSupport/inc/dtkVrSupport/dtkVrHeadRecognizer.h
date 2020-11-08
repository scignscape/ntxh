/* dtkVrHeadRecognizer.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Oct 26 12:38:20 2010 (+0200)
 * Version: $Id: bee77c73bcbe5157b673dade7eec757231920b9c $
 * Last-Updated: Thu Oct 28 15:53:53 2010 (+0200)
 *           By: Julien Wintz
 *     Update #: 6
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <dtkVrSupportExport.h>

#include <QtCore>

class dtkAbstractView;
class dtkVrHeadRecognizerPrivate;

class DTKVRSUPPORT_EXPORT dtkVrHeadRecognizer : public QObject
{
    Q_OBJECT

public:
    dtkVrHeadRecognizer(void);
    ~dtkVrHeadRecognizer(void);

    void setView(dtkAbstractView *view);

public slots:
    void startConnection(const QUrl& server);
    void stopConnection(void);

protected slots:
    void onMoved(void);
    void onButtonPressed(int);
    void onButtonReleased(int);

private:
    dtkVrHeadRecognizerPrivate *d;
};

