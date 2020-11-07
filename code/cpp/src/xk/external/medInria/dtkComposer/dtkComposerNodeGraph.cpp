// Version: $Id: 7e4f8b8534d76201289006594812ee10b718b964 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerNodeGraph.h"

#include <dtkComposerNode.h>

// ///////////////////////////////////////////////////////////////////
// dtkComposerNodeGraph implementation
// ///////////////////////////////////////////////////////////////////

void dtkComposerNodeGraph::addEdge(const Edge& e)
{
    int edge_id = m_edges.indexOf(e);
    if (edge_id < 0) {
        BaseClass::addEdge(e);

    } else {
        Edge& current_e = m_edges[edge_id];

        if (!(current_e == e)) {
            auto cs = e.connexions();
            for (const auto c : cs) {
                current_e.addConnexion(c);
            }
        }
    }
}

void dtkComposerNodeGraph::removeEdge(const Edge& e)
{
    int edge_id = m_edges.indexOf(e);
    if (edge_id >= 0) {
        Edge& current_e = m_edges[edge_id];
        if (current_e == e) {
            BaseClass::removeEdge(e);

        } else {
            auto cs = e.connexions();
            for (auto c : cs) {
                current_e.removeConnexion(c);
            }
        }
    }
}

// TODO: copy operator

dtkComposerNode *dtkComposerNodeGraph::scope(dtkComposerNode *node) const
{
    return m_scopes.value(node,NULL);
}

void dtkComposerNodeGraph::setScope(dtkComposerNode *node, dtkComposerNode *scope)
{
    m_scopes[node] = scope;
}

QList<dtkComposerNode *> dtkComposerNodeGraph::rootNodes(void) const
{
    QList<dtkComposerNode *> rootNodes;

    foreach(dtkComposerNode *n, m_nodes) {
        if (m_scopes[n] == NULL) {
            rootNodes <<  n;
        }
    }

    return rootNodes;
}

// export as dot format in a string.
QString dtkComposerNodeGraph::toString(void) const
{
    QStringList txt;
    txt <<"digraph dtkComposerGraph {";
    foreach(dtkComposerNodeGraphEdge e, m_edges) {
        txt << e.source()->titleHint() + " -> "+ e.destination()->titleHint();
    }
    txt << "}";
    return txt.join("\n");
}

//
// dtkComposerNodeGraph.cpp ends here
