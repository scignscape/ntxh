#ifndef ID_STEP_H
#define ID_STEP_H

#include "step/TraversalStep.h"
#include "structure/Vertex.h"
#include "structure/Edge.h"

#define ID_STEP 0x66

class IdStep : public TraversalStep
{
public:

 IdStep(): TraversalStep(MAP, ID_STEP) {}

 virtual void apply(GraphTraversal* trv, TraverserSet& traversers)
 {
  std::for_each(traversers.begin(), traversers.end(), [](Traverser* trv)
  {
   //QByteArray tn = trv->get().typeName();
   //if(tn == "Vertex*")

   if(trv->get().userType() == qMetaTypeId<Vertex*>())
     trv->replace_data(QVariant_cast<Vertex*>(trv->get())->id());

   else if(trv->get().userType() == qMetaTypeId<Edge*>())
     trv->replace_data(QVariant_cast<Edge*>(trv->get())->id());

   else
     throw std::runtime_error("Error: Traverser does not appear to contain an element.");

   //                const std::type_info& t = trv->get().type();
   //                if(t == typeid(Vertex*)) trv->replace_data(QVariant_cast<Vertex*>(trv->get())->id());
   //                else if(t == typeid(Edge*)) trv->replace_data(QVariant_cast<Edge*>(trv->get())->id());
   //                else throw std::runtime_error("Error: Traverser does not appear to contain an element.");
  });
 }
};

#endif
