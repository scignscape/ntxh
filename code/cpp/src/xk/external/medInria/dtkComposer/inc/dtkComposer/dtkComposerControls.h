// Version: $Id: c813d1907e8645de28f608581f640670e1e067ac $
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

class dtkComposerControlsPrivate;
class dtkComposerScene;

class DTKCOMPOSER_EXPORT  dtkComposerControls : public QFrame
{
    Q_OBJECT

public:
     dtkComposerControls(QWidget *parent = 0);
    ~dtkComposerControls(void);

public:
    void setScene(dtkComposerScene *scene);

protected slots:
    void setup(void);
    void setup(int index);

private:
    dtkComposerControlsPrivate *d;
};

//
// dtkComposerControls.h ends here
