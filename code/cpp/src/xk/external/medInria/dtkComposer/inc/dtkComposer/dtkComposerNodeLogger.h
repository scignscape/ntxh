// Version: $Id: 1145e1320515cc7a7998dd4e990ccebec74b1dd5 $
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

#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeLoggerPrivate;

class  dtkComposerNodeLogger : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeLogger(void);
    ~dtkComposerNodeLogger(void);

public:
    void run(void);

private:
    dtkComposerNodeLoggerPrivate *d;
};

//
// dtkComposerNodeLogger.h ends here
