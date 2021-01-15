#ifndef TRAVERSER_H
#define TRAVERSER_H

#include <list>
#include <map>
#include <string.h>
#include <QVariant>

class Traverser
{
 QVariant my_data_;
 std::list<QVariant> path_;
 std::map<QString, QVariant> side_effects_;

public:

 Traverser(QVariant t)
 {
  my_data_ = QVariant(t);
 }

 virtual QVariant get()
 {
  return my_data_;
 }

 virtual void replace_data(QVariant t)
 {
  my_data_ = t;
 }
};

typedef QVector<Traverser*> TraverserSet;

#endif
