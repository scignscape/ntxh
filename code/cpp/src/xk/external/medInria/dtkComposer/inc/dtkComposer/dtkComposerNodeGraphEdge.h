// Version: $Id: 3143f89007d78f32d71fea05e05ea51c2cca2b88 $
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

#include <dtkGraphTemplateEdge>

#include <QtCore>

class dtkComposerNode;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeGraphEdge interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerNodeGraphEdge : public dtkGraphTemplateEdge<dtkComposerNode *>
{
public:
    typedef dtkGraphTemplateEdge<dtkComposerNode *> BaseClass;

public:
     dtkComposerNodeGraphEdge(void) = default;
     dtkComposerNodeGraphEdge(dtkComposerNode *s, dtkComposerNode *d, int emitter_id, int receiver_id);
     dtkComposerNodeGraphEdge(dtkComposerNode *s, dtkComposerNode *d, const QList< QPair<int, int> >& connexions);
     dtkComposerNodeGraphEdge(const dtkComposerNodeGraphEdge& o);
    ~dtkComposerNodeGraphEdge(void);

public:
    dtkComposerNodeGraphEdge& operator = (const dtkComposerNodeGraphEdge& o);

public:
    bool operator == (const dtkComposerNodeGraphEdge& o) const;

public:
    void addConnexion(int e_id, int r_id);
    void addConnexion(const QPair<int, int>& c);

    void removeConnexion(int e_id, int r_id);
    void removeConnexion(const QPair<int, int>& c);

    const QList< QPair<int, int> >& connexions(void) const;

public:
    void setParentNode(dtkComposerNode *n);
    void setSrcType(const QString& t);
    void setDstType(const QString& t);

public:
    dtkComposerNode *parentNode(void) const;
    QString srcType(void) const;
    QString dstType(void) const;

private:
    QList< QPair<int, int> > m_connexions;
    dtkComposerNode *m_parent;
    QString m_src_type;
    QString m_dst_type;
};

//
// dtkComposerNodeGraphEdge.h ends here
