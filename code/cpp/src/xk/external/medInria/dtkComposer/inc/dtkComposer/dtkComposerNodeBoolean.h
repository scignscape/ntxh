// Version: $Id: 5133acd9c28701eab0f21639eb15461ab199cc98 $
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

#include "dtkComposerNodeBoolean_p.h"
#include "dtkComposerNodeLeaf.h"

class DTKCOMPOSER_EXPORT dtkComposerNodeBoolean : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeBoolean(void);
    ~dtkComposerNodeBoolean(void);

public:
    void run(void);

public:
    bool value(void);

public:
    void setValue(bool value);

public:
    dtkComposerNodeBooleanEditor *editor(void);

private:
    class dtkComposerNodeBooleanPrivate *d;
};

//
// dtkComposerNodeBoolean.h ends here
