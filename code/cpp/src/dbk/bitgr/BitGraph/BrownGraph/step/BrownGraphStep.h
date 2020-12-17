#ifndef BROWNGRAPH_STEP_H
#define BROWNGRAPH_STEP_H

#include <unordered_map>

#include "structure/Vertex.h"
#include "step/graph/GraphStep.h"
#include "structure/BrownGraph.h"

class BrownGraphStep: public GraphStep
{
 bool start_;

public:

 BrownGraphStep(bool start, GraphStepType gs_type, QVector<QVariant> element_ids)
   :  GraphStep(gs_type, element_ids)
 {
  this->start_ = start;

  SET_HINT
 }

 virtual void apply(GraphTraversal* trv, TraverserSet& traversers)
 {
  if(start_)
    traversers.push_back(new Traverser(QVariant())); // add an empty traverser when this is being used as a start step.

  // For each traverser, a traverser should be created for each Vertex and passed to the next step
  BrownGraph* bg = static_cast<BrownGraph*>(trv->getGraph());


  QVector<QVariant> element_ids = this->get_element_ids();

  // Short circuit if there are no element ids.
  // Gets ALL elements.
  if(element_ids.empty())
  {
   QVector<Vertex*>& vertices = bg->access_vertices();
   TraverserSet new_traversers;
   std::for_each(traversers.begin(), traversers.end(), [&](Traverser* t)
   {
    for(int k = 0; k < bg->numVertices(); ++k)
    {
     Traverser* tr = new Traverser(QVariant::fromValue(vertices[k]));
     new_traversers.push_back(tr);
    }
   });

   traversers.swap(new_traversers);
   std::for_each(new_traversers.begin(), new_traversers.end(), [](Traverser* t)
   {
    delete t;
   });

   return;
  }

  // Make map of element ids to counts
  std::unordered_map<uint64_t, unsigned long> element_id_counts;

  std::for_each(element_ids.begin(), element_ids.end(), [&](QVariant id_ctr)
  {
   uint64_t id = QVariant_cast<uint64_t>(id_ctr);
   if(element_id_counts.find(id) != element_id_counts.end()) element_id_counts[id]++;
   else element_id_counts[id] = 1;
  });

  TraverserSet new_traversers;

  // For each traverser...
  std::for_each(traversers.begin(), traversers.end(), [&](Traverser* trv)
  {
   std::for_each(element_ids.begin(), element_ids.end(), [&](QVariant id_ctr)
   {
    Vertex* v = bg->get_vertex(id_ctr);
    uint64_t id = QVariant_cast<uint64_t>(id_ctr);

    for(auto k = 0; k < element_id_counts[id]; k++)
      new_traversers.push_back(new Traverser(QVariant::fromValue(v)));

    //TODO retain side effects, path
   });
  });

  traversers.swap(new_traversers);
  std::for_each(new_traversers.begin(), new_traversers.end(), [](Traverser* t)
  {
   delete t;
  });
 }

 virtual QString getInfo()
 {
  QString info = "BrownGraphStep(";
  info = info + (this->element_ids_.size() > 0 ? "{...}" : "{}");
  return info + ")";
 }
};

#endif
