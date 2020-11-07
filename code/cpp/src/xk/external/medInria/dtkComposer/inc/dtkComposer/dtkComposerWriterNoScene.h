/* @(#)dtkComposerWriterNoScene.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2016 - Nicolas Niclausse, Inria.
 * Created: 2016/06/14 12:33:31
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once
#include <dtkComposerExport.h>

#include "dtkComposerWriter.h"
#include <QtCore>
#include <QDomDocument>

class dtkComposerWriterNoScenePrivate;
class dtkComposerNodeGraph;
class dtkComposerNodeGraphEdge;

class  DTKCOMPOSER_EXPORT dtkComposerWriterNoScene
{
public:
             dtkComposerWriterNoScene(void);
    virtual ~dtkComposerWriterNoScene(void);

public:
    bool write(const QString& file, dtkComposerWriter::Type type = dtkComposerWriter::Ascii);
    bool writeNode(dtkComposerNode *node, const QString& file, dtkComposerWriter::Type type = dtkComposerWriter::Ascii);

public:
    void setGraph(dtkComposerNodeGraph *graph);
    QDomDocument toXML(dtkComposerNode *node, bool addSelf = true);

public:
    QDomElement writeNode(dtkComposerNode *node, QDomElement& element, QDomDocument& document);
    QDomElement writeEdge(dtkComposerNodeGraphEdge edge, QDomElement& element, QDomDocument& document);

protected:
   virtual void extend(dtkComposerNode *node, QDomElement& element, QDomDocument& document);

private:
    dtkComposerWriterNoScenePrivate *d;
};

