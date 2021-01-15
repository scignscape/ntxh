#ifndef BROWN_GRAPH_H
#define BROWN_GRAPH_H

//?#define CPUGRAPH_INITIAL_LIST_SIZE 100000
//#define CPUGRAPH_INITIAL_LIST_SIZE 10


#include "index/Index.h"
#include "structure/Graph.h"
#include "structure/Vertex.h"
#include "structure/Element.h"
#include "structure/Direction.h"
#include <QString>
#include <QVector>
#include <QList>
#include <QMap>

#include "relae-graph/relae-caon-ptr.h"
#include "global-types.h"

class BrownVertex;

enum IndexType {VERTEX_INDEX, EDGE_INDEX};

class BrownGraph : public Graph
{

private:

  QVector< caon_ptr<Vertex> > vertex_vector_; // = QVector<Vertex*>(CPUGRAPH_INITIAL_LIST_SIZE);

  QVector< caon_ptr<Edge> > edge_vector_;

  QMap<QString, Index*> vertex_index_;
  QMap<uint64_t, Vertex*> vertex_id_map_;

  uint64_t next_edge_id = 0;
		uint64_t next_vertex_id = 0;
  uint64_t num_vertices_ = 0;

	public:

		/*
   Main constructor for the BrownGraph.
		*/
  BrownGraph(): Graph() {}

		/*
   The list containing the BrownGraph's vertices.
			TODO may want to optimize this or switch to vector.
		*/
  void* vertices()
  {
   return &vertex_vector_;
//   QVector<Vertex*> view;
//   for(int k = 0; k < num_vertices_; ++k)
//     view.push_back(vertex_vector_[k]);
//   return view;
  }

		/*
			Access the raw vertex vector.  Should not be called by users.
			Size of this list DOES NOT reflect the actual # of Vertices,
			which should be strictly checked using numVertices().
		*/
  QVector< caon_ptr<Vertex> >& access_vertices()
  {
    return this->vertex_vector_;
		}

  uint64_t numVertices() { return this->num_vertices_; }

  Vertex* resolve_vertex(caon_ptr<Vertex> pv);
  Vertex* resolve_vertex(n8 key);

  Edge* resolve_edge(caon_ptr<Edge> pv);
  Edge* resolve_edge(n8 key);

		/*
   The list containing the BrownGraph's edges.
		*/
  void* edges()
  {
   return &edge_vector_;
  }

  QVector<Edge*> all_edges();
  QVector<Vertex*> all_vertices();

  void all_edges(QVector<Edge*>& result);
  void all_vertices(QVector<Vertex*>& result);

		/*
   Adds a new Vertex (w/label) to this BrownGraph.
		*/
		virtual Vertex* add_vertex(QString label);

		/*
   Adds a new Vertex (w/o label) to this BrownGraph.
		*/
		virtual Vertex* add_vertex();

		Vertex* get_vertex(QVariant& id);

		/*
   Adds a new Edge to this BrownGraph.
		*/
		virtual Edge* add_edge(Vertex* from_vertex, Vertex* to_vertex, QString label);

		/*
   Get a traversal source for this BrownGraph.
		*/
		virtual GraphTraversalSource* traversal();

		bool is_indexed(QString key) {
   return vertex_index_.count(key) > 0;
		}

  void clear_index(BrownVertex* v, QString property_key, QVariant value);

  void update_index(BrownVertex* v, QString property_key, QVariant value);
		
		void create_index(IndexType type, QString property_key, std::function<int64_t(QVariant&)> hash_func, std::function<bool(QVariant&, QVariant&)> equals_func);

  Index* get_index(QString key)
  {
   return vertex_index_.value(key); //find(key)->second;
		}
};


#define NEXT_VERTEX_ID_CPU() ( (uint64_t)( next_vertex_id++ ))
#define NEXT_EDGE_ID_CPU() ((uint64_t)( next_edge_id++ ))

#include "structure/BrownVertex.h"
#include "traversal/CPUGraphTraversalSource.h"


#include "qmetas.h"
//Q_DECLARE_METATYPE(GraphTraversal*)
//Q_DECLARE_METATYPE(Edge*)
//Q_DECLARE_METATYPE(Vertex*)
//Q_DECLARE_METATYPE(caon_ptr<Vertex>)
//Q_DECLARE_METATYPE(VertexProperty<QVariant>*)


/*
 Get a traversal source for this BrownGraph.
*/
GraphTraversalSource* BrownGraph::traversal()
{
 BrownGraph* ref = this;
 return new CPUGraphTraversalSource(ref);
}

/*
 Adds a new Vertex (w/label) to this BrownGraph.
 Currently not part of the higher-level api.
*/
Vertex* BrownGraph::add_vertex(QString label)
{
// if(this->vertex_vector_.size() == this->num_vertices_)
//   this->vertex_vector_.resize(2*num_vertices_);

 Vertex* v = new BrownVertex(this, NEXT_VERTEX_ID_CPU(), label);
 uint64_t id_val = QVariant_cast<uint64_t>(v->id());

 vertex_vector_.push_back(v); //  [this->num_vertices_++] = v;
 ++this->num_vertices_;

 vertex_id_map_.insert(id_val, v); //.insert(std::pair<uint64_t, Vertex*>{id_val, v});

 return v;
}

/*
 Adds a new Vertex (w/o label) to this BrownGraph.
*/
Vertex* BrownGraph::add_vertex()
{
 //if(this->vertex_vector_.size() == this->num_vertices_) this->vertex_vector_.resize(2*num_vertices_);

 Vertex* v = new BrownVertex(this, NEXT_VERTEX_ID_CPU());
 uint64_t id_val = QVariant_cast<uint64_t>(v->id());

 vertex_vector_.push_back(v); //  [this->num_vertices_++] = v;
 ++this->num_vertices_;

 //vertex_vector_[this->num_vertices_++] = v;
 vertex_id_map_.insert(id_val, v); //insert(std::pair<uint64_t, Vertex*>{id_val, v});
 return v;
}

Vertex* BrownGraph::get_vertex(QVariant& id)
{
 uint64_t id_val = QVariant_cast<uint64_t>(id);
 return vertex_id_map_.value(id_val); //.find(id_val)->second;
}

/*
 Adds a new Edge to this BrownGraph.
*/
Edge* BrownGraph::add_edge(Vertex* out, Vertex* in, QString label)
{
 BrownEdge* new_edge = new BrownEdge(this, NEXT_EDGE_ID_CPU(), out, in, label);
 static_cast<BrownVertex*>(out)->addEdge(new_edge, OUT);
 static_cast<BrownVertex*>(in)->addEdge(new_edge, IN);
 edge_vector_.push_back(new_edge);
 return new_edge;
}

void BrownGraph::clear_index(BrownVertex* v, QString property_key, QVariant value)
{
 auto it = vertex_index_.find(property_key);
 if(it == vertex_index_.end())
   throw std::runtime_error("Property not indexed!\n");
 it.value()->remove(v, value);
// auto f = vertex_index_.find(property_key);
// if(f == vertex_index_.end()) throw std::runtime_error("Property not indexed!\n");
//	f->second->remove(v, value);
}

void BrownGraph::update_index(BrownVertex* v, QString property_key, QVariant value)
{
 auto it = vertex_index_.find(property_key);
 if(it == vertex_index_.end())
   throw std::runtime_error("Property not indexed!\n");
 it.value()->insert(v, value);
 //vertex_index_.insert(it, value);
 //
 //it.insert(v, value);
}

void BrownGraph::create_index(IndexType type, QString property_key, std::function<int64_t(QVariant&)> hash_func, std::function<bool(QVariant&, QVariant&)> equals_func)
{
 Index* idx = new Index(hash_func, equals_func);
 vertex_index_.insert(property_key, idx); // .insert(std::pair<QString, Index*>(property_key, idx));
}


#endif // BROWN_GRAPH_H
