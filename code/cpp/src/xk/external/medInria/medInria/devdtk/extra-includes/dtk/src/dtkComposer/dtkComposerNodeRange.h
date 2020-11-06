// Version: $Id: 87b768b6c41d4336ae9dce3f708595b7eca81ecb $
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

class DTKCOMPOSER_EXPORT dtkComposerNodeRange : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeRange(void);
    ~dtkComposerNodeRange(void);

public slots:
    void setValue(int);

public:
    void run(void);

public:
    dtkComposerViewWidget *widget(void);

private:
    class dtkComposerNodeRangePrivate *d;
};

//
// dtkComposerNodeRange.h ends here
