// Version: $Id: 6eb20ba97f6e19b2a58e3829feaaad5074739209 $
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
#include "dtkComposerNodeRemote.h"

#include <QDomDocument>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeSpawn declaration
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeSpawnPrivate;
class dtkComposerNodeComposite;

class DTKCOMPOSER_EXPORT dtkComposerNodeSpawn : public dtkComposerNodeRemote
{
    Q_OBJECT

public:
    dtkComposerNodeSpawn(void);
    virtual ~dtkComposerNodeSpawn(void);

public:
    void setApplication(QString app);
    void setComposition(QDomDocument document);

    void setParentNode(dtkComposerNodeComposite *parent);

public:
    bool isSlave(void);

public:
    virtual void begin(void);
    virtual void end(void);

private:
    dtkComposerNodeSpawnPrivate *d;
};

//
// dtkComposerNodeSpawn.h ends here
