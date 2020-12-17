#ifndef HAS_STEP_H
#define HAS_STEP_H
#include <QString>
#include <QVector>
#include <stdexcept>
#include <iostream>
#include <QVariant>
#include "step/TraversalStep.h"
#include "traversal/P.h"
#include "structure/Vertex.h"

#define HAS_STEP 0x83

class HasStep : public TraversalStep
{
private:
 // The key of the property where data to compare
 // against is stored.
 QString property_key_or_label_;

 // The value to be compared against.
 QVariant value_;

 // A function that compares extracted objects.
 // Generated by the P class (or an extension class)
 std::function<bool(QVariant)> predicate_;

public:

 HasStep(QString key, std::function<bool(QVariant)> pred)
    : TraversalStep(FILTER, HAS_STEP)
 {
  predicate_ = pred;
  property_key_or_label_ = key;

  SET_HINT
 }

 HasStep(QString key, QVariant value, std::function<bool(QVariant)> pred)
   : TraversalStep(FILTER, HAS_STEP)
 {
  predicate_ = pred;
  property_key_or_label_ = key;
  this->value_ = value;

  SET_HINT
 }

 virtual QString	getInfo()
 {
  QString info = "HasStep(";
  info = info + property_key_or_label_ + " " + "<predicate>" + ")";
  return info;
 }

 QVariant get_value()
 {
  return this->value_;
 }

 QString get_key()
 {
  return this->property_key_or_label_;
 }

 /**
            This is used for the expansion of has(prop) and has(prop, val)
            It tests whether the Vertex in question has the property/value
            in question and returns true if this is in fact the case.
  **/
 bool test(Vertex* v)
 {
  //std::cout << "id: " << QVariant_cast<uint64_t>(v->id());
  //std::cout << "search for " << property_key_or_label << "\n";
  VertexProperty<QVariant>* vp = v->property(property_key_or_label_);
  //std::cout << "null? " << (vp == nullptr) << "\n";

  //std::cout << QVariant_cast<QString>(vp->value()) << "\n";
  if(predicate_ == nullptr)
    return vp == nullptr;
  else
  {
   //std::cout << "need to test predicate\n";
   //std::cout << "key: " << vp->key() << "\n";
   QString value = QVariant_cast<QString>(vp->value());
   //std::cout << "value: " << value << "\n";
   return vp != nullptr && predicate_(value);
  }
 }

 virtual void apply(GraphTraversal* trv, TraverserSet& traversers)
 {
  TraverserSet new_traversers;

  for(auto it = traversers.begin(); it != traversers.end(); ++it)
  {
   Traverser* trv = *it;
   Vertex* v = QVariant_cast<Vertex*>(trv->get());
   bool advance = this->test(v);
   if(advance)
     new_traversers.push_back(trv);
   else
     delete trv;
  }

  traversers.swap(new_traversers);
 }
};

#endif
