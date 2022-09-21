#ifndef BROWN_TRAVERSER__H
#define BROWN_TRAVERSER__H

#include "traversal/Traverser.h"

#include <QDebug>

#include "relae-graph/relae-caon-ptr.h"

class Vertex;
class Edge;

#include "qmetas.h"


class BrownTraverser : public Traverser
{
public:

 BrownTraverser(QVariant t)
   :  Traverser(t)
 {
 }

 virtual QVariant get()
 {
  QVariant result = Traverser::get();

  if(result.userType() == qMetaTypeId<caon_ptr<Vertex>>())
  {
   return QVariant::fromValue(
     result.value<caon_ptr<Vertex>>().raw_pointer());
  }
  if(result.userType() == qMetaTypeId<caon_ptr<Edge>>())
  {
   return QVariant::fromValue(
     result.value<caon_ptr<Edge>>().raw_pointer());
  }


  return result;
 }

 virtual void replace_data(QVariant t)
 {
  //?my_data_ = t;
 }
};

typedef QVector<Traverser*> TraverserSet;

#endif
