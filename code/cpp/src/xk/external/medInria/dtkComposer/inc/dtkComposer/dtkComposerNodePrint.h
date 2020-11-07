// Version: $Id: a672ae6123c76e8ee5fa09734e97c934afb091e6 $
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
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodePrintPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodePrint : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodePrint(void);
    ~dtkComposerNodePrint(void);

public:
    void run(void);

private:
    dtkComposerNodePrintPrivate *d;
};

//
// dtkComposerNodePrint.h ends here
