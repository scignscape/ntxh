// Version: $Id: 860322a59bd9ed339cf36f00a7c4e8015051476f $
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

#include "dtkComposerNodeControl.h"

class dtkComposerNodeControlForEachPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeControlForEach interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerNodeControlForEach : public dtkComposerNodeControl
{
public:
    dtkComposerNodeControlForEach(void);
    virtual ~dtkComposerNodeControlForEach(void);

public:
    int blockCount(void);
    dtkComposerNodeLeaf *header(void);
    dtkComposerNodeLeaf *footer(void);
    dtkComposerNodeComposite *block(int id);

public:
    void setInputs(void);
    void setOutputs(void);
    void setVariables(void);
    int selectBranch(void);
    void begin(void);
    void end(void);
    qlonglong size(void);

private:
    dtkComposerNodeControlForEachPrivate *d;
};

//
// dtkComposerNodeControlForEach.h ends here
