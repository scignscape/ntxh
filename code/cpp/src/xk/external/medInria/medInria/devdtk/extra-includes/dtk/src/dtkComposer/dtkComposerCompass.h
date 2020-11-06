// Version: $Id: bf2563d306b2138da88fd75e1072b9e3dbfcc636 $
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

#include <QtGui>
#include <QtWidgets>

class dtkComposerCompassPrivate;
class dtkComposerView;

class DTKCOMPOSER_EXPORT dtkComposerCompass : public QGraphicsView
{
    Q_OBJECT

public:
     dtkComposerCompass(QWidget *parent = 0);
    ~dtkComposerCompass(void);

public:
    void setView(dtkComposerView *view);

public slots:
    void update(void);

protected:
    void paintEvent(QPaintEvent *event);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    dtkComposerCompassPrivate *d;
};

//
// dtkComposerCompass.h ends here
