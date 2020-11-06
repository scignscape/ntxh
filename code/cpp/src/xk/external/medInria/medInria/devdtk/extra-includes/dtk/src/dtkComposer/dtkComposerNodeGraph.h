// Version: $Id: 528403156aacb032790c3609752cdb90ad136997 $
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

#include <dtkGraphTemplate>

#include "dtkComposerNodeGraphEdge.h"

class dtkComposerNode;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeGraph interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerNodeGraph : public dtkGraphTemplate<dtkComposerNode *, dtkComposerNodeGraphEdge>
{
    typedef dtkComposerNode*                 Node;
    typedef dtkComposerNodeGraphEdge         Edge;
    typedef dtkGraphTemplate<Node, Edge> BaseClass;

    using BaseClass::m_nodes;
    using BaseClass::m_edges;
    using BaseClass::m_predecessors;
    using BaseClass::m_successors;

public:
     dtkComposerNodeGraph(void) = default;
     dtkComposerNodeGraph(const dtkComposerNodeGraph& o) = default;
    ~dtkComposerNodeGraph(void) = default;

public:
    dtkComposerNodeGraph& operator = (const dtkComposerNodeGraph& o) = default;

public:
    QString         toString(void) const;
    dtkComposerNode   *scope(dtkComposerNode *node) const;
    void            setScope(dtkComposerNode *node, dtkComposerNode *scope);

public:
    QList<Node> rootNodes(void) const;

public:
    void    addEdge(const Edge& e) override;
    void removeEdge(const Edge& e) override;

private:
    QHash<dtkComposerNode *, dtkComposerNode *> m_scopes;
};
