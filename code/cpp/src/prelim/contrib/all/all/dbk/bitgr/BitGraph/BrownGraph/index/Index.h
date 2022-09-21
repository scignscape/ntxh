#ifndef INDEX_H
#define INDEX_H

#include <inttypes.h>
#include <functional>
#include <QVector>
#include <unordered_set>
#include <memory>
#include <QVariant>
#include "structure/Element.h"

typedef std::function<int64_t(QVariant&)> HashFunction;
typedef std::function<bool(QVariant&, QVariant&)> EqualsFunction;

#define INDEX_MAX_LOAD_FACTOR 0.7
#define INDEX_SIZE_INCR 1000

class Index {
private:
 HashFunction hash_func;
 EqualsFunction equals_func;
 QVector<std::unordered_set<Element*>*> table;
 QVector<QVariant> dict;

 size_t actual_size;

 /*
            Inserts the value/element pair into the Index.
        */
 void insert(QVector<std::unordered_set<Element*>*>& table, QVector<QVariant>& dict, Element* e, QVariant val) {
  int64_t hash = hash_func(val);
  size_t index = hash % dict.size();

  // if the slot was empty
  if(dict[index].isNull()) {
   dict[index] = QVariant(val);
   table[index] = new std::unordered_set<Element*>;
   table[index]->insert(e);
   ++actual_size;
  }

  // if the key was there and we just need to add the Element
  else if(equals_func(val, dict[index])) {
   table[index]->insert(e);
  }

  // if the slot was not empty
  else {
   while(!dict[index].isNull() && !equals_func(dict[index], val)) {
    ++index;
    if(index >= dict.size()) index = 0;
   };

   // if the slot was empty
   if(dict[index].isNull()) {
    dict[index] = QVariant(val);
    table[index] = new std::unordered_set<Element*>;
    table[index]->insert(e);
    ++actual_size;
   }

   // if the key was there and we just need to add the Element
   else if(equals_func(val, dict[index])) {
    table[index]->insert(e);
   }
  }
 }

public:
 Index(HashFunction hash_func, EqualsFunction equals_func) {
  this->hash_func = hash_func;
  this->equals_func = equals_func;
  this->actual_size = 0;
  this->table.resize(INDEX_SIZE_INCR); //, nullptr);
  this->dict.resize(INDEX_SIZE_INCR);
 }

 bool is_indexed(QVariant& val) {
  int64_t hash = hash_func(val);
  size_t k = hash % dict.size();
  while(!dict[k].isNull() && !equals_func(dict[k], val)) {
   ++k;
   if(k > dict.size()) k = 0;
  }

  if(dict[k].isNull()) return false;
  return true; // index should never be full!
 }

 /*
            If necessary, rebuilds this index.
        */
 inline void rebuild() {
  if(static_cast<float>(actual_size) / static_cast<float>(table.size()) < INDEX_MAX_LOAD_FACTOR) return;

  size_t new_size = table.size()*5 + INDEX_SIZE_INCR;

  QVector<std::unordered_set<Element*>*> new_table;
  new_table.resize(new_size);

  QVector<QVariant> new_dict;
  new_dict.resize(new_size);

  size_t old_size = table.size();
  for(int k = 0; k < old_size; ++k) if(!dict[k].isNull()) {
   for(auto it = table[k]->begin(); it != table[k]->end(); ++it) {
    insert(new_table, new_dict, *it, dict[k]);
   }
  }

  table.resize(new_size);
  dict.resize(new_size);

  for(int k = 0; k < new_size; ++k) {
   if(table[k] != nullptr) delete table[k];

   table[k] = new_table[k];
   dict[k] = new_dict[k];
  }
 }

 /*
            Inserts the value/element pair into this Index.
        */
 void insert(Element* e, QVariant val) {
  insert(this->table, this->dict, e, val);
  rebuild();
 }

 std::unordered_set<Element*> get_elements(QVariant val) {
  size_t dict_size = dict.size();
  int64_t hash = hash_func(val);
  size_t index = hash % dict_size;

  std::unordered_set<Element*> s;

  if(dict[index].isNull()) return s;

  while(!dict[index].isNull() && !equals_func(dict[index], val)) {
   ++index;
   if(index >= dict_size) index = 0;
  }

  if(dict[index].isNull()) return s;

  for(auto it = table[index]->begin(); it != table[index]->end(); ++it) s.insert(*it);
  return s;
 }

 /*
            Returns true if removed successfully, false if there was nothing
            to be removed.
        */
 bool remove(Element* e, QVariant val) {
  int64_t hash = hash_func(val);
  size_t index = hash % dict.size();

  // if the slot was empty
  if(dict[index].isNull()) {
   return false;
  }

  // if the key was there and we just need to delete the Element
  else if(equals_func(val, dict[index])) {
   table[index]->erase(e);
   if(table[index]->empty()) {
    table[index] = nullptr;
    dict[index] = QVariant();
    --actual_size;
   }
  }

  // if the slot was not empty
  else {
   while(!dict[index].isNull() && !equals_func(dict[index], val)) {
    ++index;
    if(index >= dict.size()) index = 0;
   };

   // if the slot was empty
   if(dict[index].isNull()) {
    return false;
   }

   // if the key was there and we just need to delete the Element
   else if(equals_func(val, dict[index])) {
    table[index]->erase(e);
    if(table[index]->empty()) {
     table[index] = nullptr;
     dict[index] = QVariant();
     --actual_size;
    }
   }
  }

  rebuild();
  return true;
 }
};

#endif
