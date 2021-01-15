#ifndef VERTEX_PROPERTY_H
#define VERTEX_PROPERTY_H

#include <set>
#include <exception>
#include <stdexcept>
#include <QVector>
#include <algorithm>
#include <functional>
#include <QVariant>
#include "structure/Property.h"

enum Cardinality {SINGLE, LIST, SET};

template<typename T>
class VertexProperty
{
 QString my_key_;
 QVector<T>* my_values_;

public:

 VertexProperty(Cardinality card, QString new_key, QVector<T> new_values)
 {
  this->my_key_ = new_key;

  // sets are weird in general, and the default comparator won't work in this method
  if(card == SET)
  {
   throw std::runtime_error("Set cardinality not yet supported!");
  }
  else if(card == LIST)
  {
   my_values_ = new QVector<T>;
   for(T t : new_values)
     my_values_->push_back(T(t));
  }
  else
  {
   if(new_values.size() > 1)
     throw std::runtime_error("Specified single Cardinality but provided a vector of size > 1!");
   my_values_ = new QVector<T>;
   my_values_->push_back(T(new_values[0]));
  }
 }

 QString key()
 {
  return my_key_;
 }

 QVector<T> values()
 {
  return *my_values_;
 }

 T value()
 {
  if(my_values_->empty()) throw std::runtime_error("No values present for the given property key.");
  T z = my_values_->at(0);
  return z;
 }
};

#endif
