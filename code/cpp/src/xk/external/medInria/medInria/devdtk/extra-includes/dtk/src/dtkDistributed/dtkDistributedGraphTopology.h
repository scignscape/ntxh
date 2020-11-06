// Version: $Id: d989dbea562faef13cd37dd996c25e205023180d $
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

#include <set>

#include "dtkDistributedArray.h"
#include "dtkDistributedNavigator.h"
#include "dtkDistributedContainer.h"
#include "dtkDistributedIterator.h"

#include <dtkDistributedExport.h>

#include <QtCore>

class dtkDistributedGraphTopology;

// /////////////////////////////////////////////////////////////////
// dtkDistributedGraphTopologyVertex declaration
// /////////////////////////////////////////////////////////////////

class DTKDISTRIBUTED_EXPORT dtkDistributedGraphTopologyVertex
{
    const dtkDistributedGraphTopology *g;
    qlonglong m_id;
    dtkDistributedArray<qlonglong>::const_iterator c_beg;
    dtkDistributedArray<qlonglong>::const_iterator c_it;
    dtkDistributedArray<qlonglong>::const_iterator v_it;
    dtkDistributedArray<qlonglong>::const_iterator n_it;
    qlonglong first_pos;

public:
    dtkDistributedGraphTopologyVertex(const dtkDistributedGraphTopology *graph, qlonglong id) : g(graph), m_id(id) {
        init();
    }
    dtkDistributedGraphTopologyVertex(const dtkDistributedGraphTopologyVertex& o) : g(o.g), m_id(o.m_id) {
        init();
    }

public:
    dtkDistributedGraphTopologyVertex& operator = (const dtkDistributedGraphTopologyVertex& o) {
        m_id = o.m_id;
        init();
        return *this;
    }

public:
    qlonglong id(void) const {
        return m_id;
    }

public:
    qlonglong neighbourCount(void) const {
        return *c_it;
    }
    qlonglong neighbourPos(qlonglong j) const {
        return *v_it + j;
    }
    qlonglong neighbourLocalPos(qlonglong j) const {
        return *v_it + j - first_pos;
    }

public:
    dtkDistributedArray<qlonglong>::const_iterator begin(void) const {
        return n_it;
    }
    dtkDistributedArray<qlonglong>::const_iterator   end(void) const {
        return n_it + *c_it;
    }

public:
    bool operator == (const dtkDistributedGraphTopologyVertex& o) const {
        return (m_id == o.m_id);
    }
    bool operator != (const dtkDistributedGraphTopologyVertex& o) const {
        return (m_id != o.m_id);
    }
    bool operator <  (const dtkDistributedGraphTopologyVertex& o) const {
        return (m_id <  o.m_id);
    }
    bool operator <= (const dtkDistributedGraphTopologyVertex& o) const {
        return (m_id <= o.m_id);
    }
    bool operator >  (const dtkDistributedGraphTopologyVertex& o) const {
        return (m_id >  o.m_id);
    }
    bool operator >= (const dtkDistributedGraphTopologyVertex& o) const {
        return (m_id >= o.m_id);
    }

public:
    dtkDistributedGraphTopologyVertex& operator ++ (void) {
        ++m_id;
        advance();
        return *this;
    }
    dtkDistributedGraphTopologyVertex  operator ++ (int)  {
        dtkDistributedGraphTopologyVertex o(*this);
        ++m_id;
        advance();
        return o;
    }
    dtkDistributedGraphTopologyVertex& operator -- (void) {
        --m_id;
        rewind();
        return *this;
    }
    dtkDistributedGraphTopologyVertex  operator -- (int)  {
        dtkDistributedGraphTopologyVertex o(*this);
        --m_id;
        rewind();
        return o;
    }
    dtkDistributedGraphTopologyVertex& operator += (qlonglong j) {
        m_id += j;
        advance(j);
        return *this;
    }
    dtkDistributedGraphTopologyVertex& operator -= (qlonglong j) {
        m_id -= j;
        rewind(j);
        return *this;
    }
    dtkDistributedGraphTopologyVertex  operator +  (qlonglong j) const {
        dtkDistributedGraphTopologyVertex o(*this);
        o += j;
        return o;
    }
    dtkDistributedGraphTopologyVertex  operator -  (qlonglong j) const {
        dtkDistributedGraphTopologyVertex o(*this);
        o -= j;
        return o;
    }

private:
    void init(void);
    void advance(void);
    void advance(qlonglong j);
    void rewind(void);
    void rewind(qlonglong j);
};

// /////////////////////////////////////////////////////////////////
// dtkDistributedGraphTopology declaration
// /////////////////////////////////////////////////////////////////

class DTKDISTRIBUTED_EXPORT dtkDistributedGraphTopology : public dtkDistributedContainer
{

public:
    enum GraphFile {
        MetisFormat,
        MetisDirectedFormat,
        MatrixMarketFormat
    };

public:
    typedef dtkDistributedNavigator<dtkDistributedArray<qlonglong> > Neighbours;
    typedef dtkDistributedIterator<dtkDistributedGraphTopology> iterator;
    typedef dtkDistributedGraphTopologyVertex vertex;
    friend vertex;

public:
    typedef Neighbours value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef qptrdiff difference_type;
    typedef qlonglong size_type;

public:
    dtkDistributedGraphTopology(void);
    dtkDistributedGraphTopology(const qlonglong& vertex_count);
    dtkDistributedGraphTopology(const qlonglong& vertex_count, dtkDistributedMapper *mapper);
    dtkDistributedGraphTopology(const dtkDistributedGraphTopology& other);

public:
    ~dtkDistributedGraphTopology(void);

public:
    dtkDistributedGraphTopology& operator = (const dtkDistributedGraphTopology& o);

private:
    void initialize(void);

public:
    void  rlock(void);
    void  wlock(void);
    void unlock(void);

public:
    void clear(void);
    void resize(qlonglong vertexCount);

public:
    void addEdge(qlonglong from, qlonglong to);

public:
    void assemble(void);
    void assembleDomainDecompositionFeatures(void);

protected:
    void buildDomainDecompositionMaps(void);
    void buildDomainDecompositionData(void);

public:
    bool isAssembled(void) const;

public:
    qlonglong vertexCount(void) const;
    qlonglong   edgeCount(void) const;

public:
    qlonglong vertexCount(const qlonglong& wid) const;
    qlonglong   edgeCount(const qlonglong& wid) const;

public:
    qlonglong neighbourCount(qlonglong vertex_id) const;

    Neighbours operator[](qlonglong vertex_id) const;

public:
    qlonglong firstNeighbourPos(qlonglong vertex_id) const;
    qlonglong  firstNeighbourId(qlonglong vertex_id) const;

public:
    vertex beginVertex() const {
        return vertex(this, this->m_mapper->firstIndex(this->wid()));
    }
    vertex   endVertex() const {
        return vertex(this, this->m_mapper->lastIndex(this->wid()) + 1);
    }

public:
    iterator cbegin(void) const;
    iterator   cend(void) const;

    iterator begin(void) const;
    iterator   end(void) const;

public:
    void stats(void) const;

public:
    dtkDistributedMapper *edgeMapper(void) const;

public:
    bool read(const QString& filename, GraphFile format = MetisFormat);

    template <class T = double> bool readWithValues(const QString& filename, GraphFile format, dtkDistributedArray<T> *&values );

public:
    void setEdgeCountArray(dtkDistributedArray<qlonglong> *edge_count_array);
    void setEdgeToVertexArray(dtkDistributedArray<qlonglong> *edge_to_vertex_array);
    void setAssembleFlag(bool is_assembled);

    const dtkDistributedArray<qlonglong> *vertexToEdgeArray(void) const;
          dtkDistributedArray<qlonglong> *vertexToEdgeArray(void);

    const dtkDistributedArray<qlonglong> *neighbourCountArray(void) const;
          dtkDistributedArray<qlonglong> *neighbourCountArray(void);

protected:
    bool m_is_assembled;

    //typedef QList<qlonglong> EdgeList;
    typedef std::set<qlonglong> EdgeList;
    typedef QMap<qlonglong, EdgeList> EdgeMap;

    dtkDistributedArray<qlonglong> *m_edge_count;

    dtkDistributedArray<qlonglong> *m_neighbour_count;
    dtkDistributedArray<qlonglong> *m_vertex_to_edge;

    dtkDistributedArray<qlonglong> *m_edge_to_vertex;

public:
    struct DDData {

        EdgeMap map;
        EdgeMap map_hybrid;
        EdgeMap map_remote;

        EdgeMap map_itf;
        qlonglong local_intern_size;
        qlonglong local_itf_size;
        qlonglong global_itf_size;

        dtkDistributedMapper *mapper;
        dtkDistributedArray<qlonglong> *positions;

        dtkArray<qlonglong, 0> local_vertex_to_edge;
        dtkArray<qlonglong, 0> local_edge_to_vertex;

        QMap<qlonglong, qlonglong> glob_to_loc;
        dtkArray<qlonglong, 0> loc_to_glob;
    } m_dd;
};

// /////////////////////////////////////////////////////////////////

#include "dtkDistributedGraphTopology.tpp"

//
// dtkDistributedGraphTopology.h ends here
