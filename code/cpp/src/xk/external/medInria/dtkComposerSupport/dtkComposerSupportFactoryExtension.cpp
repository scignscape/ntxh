// Version: $Id: 852290603f25f3b11ac23d3be742bfb7b2561628 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerSupportFactoryExtension.h"

#include "dtkComposerNodeData.h"
#include "dtkComposerNodeProcess.h"
#include "dtkComposerNodeView.h"

// ///////////////////////////////////////////////////////////////////
//
// ///////////////////////////////////////////////////////////////////

dtkComposerSupportFactoryExtension::dtkComposerSupportFactoryExtension(void) : dtkComposerNodeFactoryExtension()
{

}

dtkComposerSupportFactoryExtension::~dtkComposerSupportFactoryExtension(void)
{

}

void dtkComposerSupportFactoryExtension::extend(dtkComposerNodeFactory *factory)
{
    factory->record(":dtkComposerSupport/dtkComposerNodeData.json",    dtkComposerNodeCreator< dtkComposerNodeData >);
    factory->record(":dtkComposerSupport/dtkComposerNodeProcess.json", dtkComposerNodeCreator< dtkComposerNodeProcess >);
    factory->record(":dtkComposerSupport/dtkComposerNodeView.json",    dtkComposerNodeCreator< dtkComposerNodeView >);
}

//
// dtkComposerSupportFactoryExtension.cpp ends here
