// Version: $Id: a3e4dea61564030e4eae7c4082c83f524532d6f2 $
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

class dtkComposerNodeMetaDataPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaData
{
public:
    dtkComposerNodeMetaData(void);
    virtual ~dtkComposerNodeMetaData(void);

public:
    bool setFromFile(const QString& file_path);

public:
    void setTitle(const QString& title);
    void setKind(const QString& kind);
    void setType(const QString& type);
    void setColor(const QString& color);
    void setTags(const QStringList& tags);
    void setDescription(const QString& description);
    void appendInputLabel(const QString& label);
    void appendOutputLabel(const QString& label);
    void setInputLabel(int i, const QString& label);
    void setOutputLabel(int i, const QString& label);

public:
    const QString& title(void) const;
    dtkComposerNode::Kind kind(void) const;
    const QString& color(void) const;
    const QString& type(void) const;
    const QStringList& tags(void) const;
    const QString& description(void) const;
    const QStringList& inputLabels(void) const;
    const QStringList& outputLabels(void) const;

public:
    dtkComposerNodeMetaDataPrivate *d;
};

//
// dtkComposerNodeMetaData.h ends here
