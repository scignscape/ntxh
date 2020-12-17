#ifndef VERTEX_STEP_H
#define VERTEX_STEP_H
#include <QString>
#include <QVector>
#include <set>
#include <algorithm>
#include "step/TraversalStep.h"
#include "structure/Direction.h"
#include "step/graph/GraphStep.h"
#include "traversal/Traverser.h"
#include "traversal/GraphTraversal.h"

#include <boost/lockfree/stack.hpp>

#define VERTEX_STEP 0x80

class VertexStep : public TraversalStep
{
	private:
  Direction direction_;
  std::set<QString> edge_labels_;
  GraphStepType gsType_;

public:

		VertexStep(Direction dir, QVector<QString> edge_labels_arg, GraphStepType gsType_arg)
    : TraversalStep(MAP, VERTEX_STEP)
  {
   direction_ = dir;
   std::for_each(edge_labels_arg.begin(), edge_labels_arg.end(), [&](QString str){ this->edge_labels_.insert(str); });
   this->gsType_ = gsType_arg;

   SET_HINT
		}

		VertexStep(Direction dir, GraphStepType gsType_arg)
    : TraversalStep(MAP, VERTEX_STEP)
  {
   direction_ = dir;
   this->gsType_ = gsType_arg;

   SET_HINT
		}

  Direction get_direction()
  {
   return this->direction_;
		}

  std::set<QString> get_labels()
  {
   return this->edge_labels_;
		}

  virtual QString getInfo()
  {
			QString info = "VertexStep(";
   info += (direction_ == IN ? "IN" : direction_ == OUT ? "OUT" : "BOTH");
			info += ", ";
   if(!edge_labels_.empty())
   {
				info += "{";
    auto p = edge_labels_.begin();
    for(int k = 0; k < edge_labels_.size() - 1; k++) info = info + *(p++) + ", ";
				info = info + *p + "}";
			}
			else info += "{}";
   info = info + ", " + (gsType_ == VERTEX ? "VERTEX" : "EDGE");
			return info + ")";
		}

  virtual void apply(GraphTraversal* traversal, TraverserSet& traversers)
  {
   bool label_required = !this->edge_labels_.empty();

			QVector<Traverser*> new_traversers;
			
			//boost::lockfree::stack<Traverser*> new_traversers(8);
   std::for_each(traversers.begin(), traversers.end(), [&, this](Traverser* trv)
   {
				Vertex* v = QVariant_cast<Vertex*>(trv->get());
    QVector<Edge*> edges = v->edges(direction_);
				//#pragma omp for
    for(size_t k = 0; k < edges.size(); ++k)
    {
					Edge* e = edges[k];
     if(label_required && this->edge_labels_.count(e->label()) == 0)
       continue;

     switch(direction_)
     {
      case IN:
      {
       Vertex* w = e->inV();
       new_traversers.push_back(new Traverser(QVariant::fromValue(w)));
							break;
						}
      case OUT:
      {
       Vertex* w = e->outV();
       new_traversers.push_back(new Traverser(QVariant::fromValue(w)));
							break;
						}
      case BOTH:
      {
							Vertex* u = e->outV();
							Vertex* w = u == v ? e->inV() : u;
       new_traversers.push_back(new Traverser(QVariant::fromValue(w)));
							break;
						}
					}
				}
			});
		

			traversers.swap(new_traversers);
			std::for_each(new_traversers.begin(), new_traversers.end(), [](Traverser* trav){delete trav;});
			//traversers.clear();
			//new_traversers.consume_all([&](Traverser* trv){ traversers.push_back(trv); }); 
		}
};

#endif
