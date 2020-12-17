
#include "BrownGraph.h"

#define NEXT_VERTEX_ID_CPU() ( (uint64_t)( next_vertex_id++ ))
#define NEXT_EDGE_ID_CPU() ((uint64_t)( next_edge_id++ ))

#include "traversal/CPUGraphTraversalSource.h"
#include "structure/BrownVertex.h"



Q_DECLARE_METATYPE(GraphTraversal*)
Q_DECLARE_METATYPE(Edge*)
Q_DECLARE_METATYPE(Vertex*)
Q_DECLARE_METATYPE(VertexProperty<QVariant>*)




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
