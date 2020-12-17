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

class BrownVertex;

enum IndexType {VERTEX_INDEX, EDGE_INDEX};

class BrownGraph : public Graph
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
   Main constructor for the BrownGraph.
		*/
  BrownGraph(): Graph() {}

		/*
   The list containing the BrownGraph's vertices.
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
   The list containing the BrownGraph's edges.
		*/
  QVector<Edge*>& edges()
  {
   return edge_vector_;
  }

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

#endif // BROWN_GRAPH_H
