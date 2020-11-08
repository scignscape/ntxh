// Version: $Id: 7bb46fe07cae0b05739e6611f49f46d23ea9338f $
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

#include <dtkComposerSupportExport.h>

#include <dtkComposer/dtkComposerNodeFactory.h>

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerSupportFactoryExtension : public dtkComposerNodeFactoryExtension
{
public:
    dtkComposerSupportFactoryExtension(void);
    ~dtkComposerSupportFactoryExtension(void);

public:
    void extend(dtkComposerNodeFactory *factory);
};

//
// dtkComposerSupportFactoryExtension.h ends here
