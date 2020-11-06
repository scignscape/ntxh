// Version: $Id: 2d51d2bc4b2ef65005bc55946d195b0fb4d9ceec $
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
// dtkComposerNodeSpawnEmbedded declaration
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeSpawnEmbeddedPrivate;
class dtkComposerNodeComposite;

class DTKCOMPOSER_EXPORT dtkComposerNodeSpawnEmbedded : public dtkComposerNodeRemote
{
    Q_OBJECT

public:
             dtkComposerNodeSpawnEmbedded(void);
    virtual ~dtkComposerNodeSpawnEmbedded(void);

public:
    void setApplication(QString app);
    void setComposition(QDomDocument document);

    void setParentNode(dtkComposerNodeComposite *parent);
    void setOutputContainer(QVariant v);
    void setContainer(QVariant v);
    void setContainerIndex(qlonglong index);

public:
    QVariant outputContainer(void);

public:
    bool isSlave(void);

public:
    virtual void begin(void);
    virtual void end(void);

private:
    dtkComposerNodeSpawnEmbeddedPrivate *d;
};

//
// dtkComposerNodeSpawnEmbedded.h ends here
