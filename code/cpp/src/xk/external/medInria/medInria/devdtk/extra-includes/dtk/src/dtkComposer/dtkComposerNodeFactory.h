// Version: $Id: 1703d5f4a570838a663f7317d1d55492a79ace11 $
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

#include "dtkComposerNode.h"

#include <dtkCore/dtkCorePluginFactory.h>

class dtkComposerNodeFactoryPrivate;
class dtkComposerNodeMetaData;
class dtkComposerExtension;

// ///////////////////////////////////////////////////////////////////
// dtkComposerNodeFactory definition
// ///////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerNodeFactory : public dtkCorePluginFactory<dtkComposerNode>
{
public:
     dtkComposerNodeFactory(void);
    ~dtkComposerNodeFactory(void);

public:
    dtkComposerNode *create(const QString& node) const;

    void record(const QString& metadata_file_path, creator func);

    void extend(dtkComposerExtension *extension);

public:
    const QStringList& nodes(void) const;
    const QHash<QString, dtkComposerNodeMetaData *>& metaDatas(void) const;

protected:
    dtkComposerNodeFactoryPrivate *d;
};

// ///////////////////////////////////////////////////////////////////
// Helper function for node creation
// ///////////////////////////////////////////////////////////////////

template <typename T> dtkComposerNode *dtkComposerNodeCreator(void)
{
    return new T;
};

// ///////////////////////////////////////////////////////////////////
//
// ///////////////////////////////////////////////////////////////////


//
// dtkComposerNodeFactory.h ends here
