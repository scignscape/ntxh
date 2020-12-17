#ifndef CPU_GRAPH_H
#define CPU_GRAPH_H

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

class BrownVertex;

enum IndexType {VERTEX_INDEX, EDGE_INDEX};

class CPUGraph : public Graph
{

private:

  QVector<Vertex*> vertex_vector_; // = QVector<Vertex*>(CPUGRAPH_INITIAL_LIST_SIZE);

  QVector<Edge*> edge_vector_;

  QMap<QString, Index*> vertex_index_;
  QMap<uint64_t, Vertex*> vertex_id_map_;

  uint64_t next_edge_id = 0;
		uint64_t next_vertex_id = 0;
  uint64_t num_vertices_ = 0;

	public:

		/*
			Main constructor for the CPUGraph.
		*/
		CPUGraph(): Graph() {}

		/*
			The list containing the CPUGraph's vertices.
			TODO may want to optimize this or switch to vector.
		*/
  QVector<Vertex*> vertices()
  {
   QVector<Vertex*> view;
   for(int k = 0; k < num_vertices_; ++k)
     view.push_back(vertex_vector_[k]);
			return view; 
		}

		/*
			Access the raw vertex vector.  Should not be called by users.
			Size of this list DOES NOT reflect the actual # of Vertices,
			which should be strictly checked using numVertices().
		*/
  QVector<Vertex*>& access_vertices()
  {
    return this->vertex_vector_;
		}

  uint64_t numVertices() { return this->num_vertices_; }

		/*
			The list containing the CPUGraph's edges.
		*/
  QVector<Edge*>& edges()
  {
   return edge_vector_;
  }

		/*
			Adds a new Vertex (w/label) to this CPUGraph.
		*/
		virtual Vertex* add_vertex(QString label);

		/*
			Adds a new Vertex (w/o label) to this CPUGraph.
		*/
		virtual Vertex* add_vertex();

		Vertex* get_vertex(QVariant& id);

		/*
			Adds a new Edge to this CPUGraph.
		*/
		virtual Edge* add_edge(Vertex* from_vertex, Vertex* to_vertex, QString label);

		/*
			Get a traversal source for this CPUGraph.
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

#include "traversal/CPUGraphTraversalSource.h"
#include "structure/BrownVertex.h"

/*
	Get a traversal source for this CPUGraph.
*/
GraphTraversalSource* CPUGraph::traversal()
{
	CPUGraph* ref = this;
	return new CPUGraphTraversalSource(ref);
}

/*
	Adds a new Vertex (w/label) to this CPUGraph.
	Currently not part of the higher-level api.
*/
Vertex* CPUGraph::add_vertex(QString label)
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
	Adds a new Vertex (w/o label) to this CPUGraph.
*/
Vertex* CPUGraph::add_vertex()
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

Vertex* CPUGraph::get_vertex(QVariant& id)
{
	uint64_t id_val = QVariant_cast<uint64_t>(id);
 return vertex_id_map_.value(id_val); //.find(id_val)->second;
}

/*
	Adds a new Edge to this CPUGraph.
*/
Edge* CPUGraph::add_edge(Vertex* out, Vertex* in, QString label)
{
 BrownEdge* new_edge = new BrownEdge(this, NEXT_EDGE_ID_CPU(), out, in, label);
 static_cast<BrownVertex*>(out)->addEdge(new_edge, OUT);
 static_cast<BrownVertex*>(in)->addEdge(new_edge, IN);
 edge_vector_.push_back(new_edge);
	return new_edge;
}

void CPUGraph::clear_index(BrownVertex* v, QString property_key, QVariant value)
{
 auto it = vertex_index_.find(property_key);
 if(it == vertex_index_.end())
   throw std::runtime_error("Property not indexed!\n");
 it.value()->remove(v, value);
// auto f = vertex_index_.find(property_key);
// if(f == vertex_index_.end()) throw std::runtime_error("Property not indexed!\n");
//	f->second->remove(v, value);
}

void CPUGraph::update_index(BrownVertex* v, QString property_key, QVariant value)
{
 auto it = vertex_index_.find(property_key);
 if(it == vertex_index_.end())
   throw std::runtime_error("Property not indexed!\n");
 it.value()->insert(v, value);
 //vertex_index_.insert(it, value);
 //
 //it.insert(v, value);
}

void CPUGraph::create_index(IndexType type, QString property_key, std::function<int64_t(QVariant&)> hash_func, std::function<bool(QVariant&, QVariant&)> equals_func)
{
	Index* idx = new Index(hash_func, equals_func);
 vertex_index_.insert(property_key, idx); // .insert(std::pair<QString, Index*>(property_key, idx));
}

#endif
