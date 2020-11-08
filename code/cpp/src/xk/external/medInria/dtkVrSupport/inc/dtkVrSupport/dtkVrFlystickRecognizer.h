/* dtkVrFlystickRecognizer.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Mon Feb  7 10:04:10 2011 (+0100)
 * Version: $Id: 9e94269c2dc16b1a34676d889a723bb9ff869a47 $
 * Last-Updated: Wed Mar 30 13:24:39 2011 (+0200)
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
class dtkVrFlystickRecognizerPrivate;

class DTKVRSUPPORT_EXPORT dtkVrFlystickRecognizer : public QObject
{
    Q_OBJECT

public:
    dtkVrFlystickRecognizer(void);
    ~dtkVrFlystickRecognizer(void);

public slots:
    void startConnection(const QUrl& server);
    void stopConnection(void);

protected slots:
    void onMoved(void);
    void onRotated(void);
    void onButtonPressed(int);
    void onButtonReleased(int);

private:
    dtkVrFlystickRecognizerPrivate *d;
};
