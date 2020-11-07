// Version: $Id: d9d2973d2c02c70cb4867ca24533d10c36d0d10a $
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

class dtkComposerNodeControlParallelMapPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeControlParallelMap interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerNodeControlParallelMap : public dtkComposerNodeControl
{
public:
             dtkComposerNodeControlParallelMap(void);
    virtual ~dtkComposerNodeControlParallelMap(void);

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
    dtkComposerNodeControlParallelMapPrivate *d;
};

//
// dtkComposerNodeControlParallelMap.h ends here
