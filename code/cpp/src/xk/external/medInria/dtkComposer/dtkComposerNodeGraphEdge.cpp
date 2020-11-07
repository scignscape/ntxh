// Version: $Id: e435e5661eb6a8024f42f9ab9a7acccf692e93f0 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerNodeGraphEdge.h"

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

dtkComposerNodeGraphEdge::dtkComposerNodeGraphEdge(dtkComposerNode *s, dtkComposerNode *d, int e_id, int r_id) : BaseClass(s, d), m_connexions(QList<QPair<int, int> >() << qMakePair(e_id, r_id)), m_parent(nullptr)
{

}

dtkComposerNodeGraphEdge::dtkComposerNodeGraphEdge(dtkComposerNode *s, dtkComposerNode *d, const QList< QPair<int, int> >& connexions) : BaseClass(s, d), m_connexions(connexions), m_parent(nullptr)
{

}

dtkComposerNodeGraphEdge::dtkComposerNodeGraphEdge(const dtkComposerNodeGraphEdge& o) : BaseClass(o), m_connexions(o.m_connexions), m_parent(o.m_parent), m_src_type(o.m_src_type), m_dst_type(o.m_dst_type)
{

}

dtkComposerNodeGraphEdge::~dtkComposerNodeGraphEdge(void)
{
    m_connexions.clear();
    m_parent = nullptr;
}

dtkComposerNodeGraphEdge& dtkComposerNodeGraphEdge::operator = (const dtkComposerNodeGraphEdge& o)
{
    BaseClass::operator = (o);
    m_connexions = o.m_connexions;
    m_parent = o.m_parent;
    m_src_type = o.m_src_type;
    m_dst_type = o.m_dst_type;

    return *this;
}

bool dtkComposerNodeGraphEdge::operator == (const dtkComposerNodeGraphEdge& o) const
{
    if (BaseClass::operator == (o)) {
        return m_connexions == o.m_connexions;
    }
    return false;
}

void dtkComposerNodeGraphEdge::addConnexion(int e_id, int r_id)
{
    this->addConnexion(qMakePair(e_id, r_id));
}

void dtkComposerNodeGraphEdge::addConnexion(const QPair<int, int>& c)
{
    if (!m_connexions.contains(c)) {
        m_connexions << c;
    }
}

void dtkComposerNodeGraphEdge::removeConnexion(int e_id, int r_id)
{
    this->removeConnexion(qMakePair(e_id, r_id));
}

void dtkComposerNodeGraphEdge::removeConnexion(const QPair<int, int>& c)
{
    m_connexions.removeOne(c);
}

const QList< QPair<int, int> >& dtkComposerNodeGraphEdge::connexions(void) const
{
    return m_connexions;
}

void dtkComposerNodeGraphEdge::setParentNode(dtkComposerNode *n)
{
    m_parent = n;
}

void dtkComposerNodeGraphEdge::setSrcType(const QString & t)
{
    m_src_type = t;
}

void dtkComposerNodeGraphEdge::setDstType(const QString & t)
{
    m_dst_type = t;
}

dtkComposerNode *dtkComposerNodeGraphEdge::parentNode(void) const
{
    return m_parent;
}

QString dtkComposerNodeGraphEdge::srcType(void) const
{
    return m_src_type;
}

QString dtkComposerNodeGraphEdge::dstType(void) const
{
    return m_dst_type;
}

//
// dtkComposerNodeGraphEdge.cpp ends here
