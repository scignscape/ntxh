
// licence_h

#ifndef GH_BLOCK_BASE__H
#define GH_BLOCK_BASE__H

#include "global-types.h"

#include <QPair>
#include <QMap>
#include <QString>
 

class GH_Block_Base
{
protected:

 QMap<QString, QPair<u4, u4>>* cache_;
 QMap<QPair<u4, u4>, QPair<u8, QString>>* inserts_;

public:

 GH_Block_Base();

 enum class SDI_Interpretation_Codes
 {
  N_A, Letter, Potential_Sentence_End, Sentence_End,
  Potential_Sentence_End_Space, Sentence_End_Space,
  GH_Interpretation, Void_Null
 };

 enum class Evaluation_Codes
 {
  Confirm, Refute, Neutral
 };

 template<typename T>
 T* get_insert_as(u4 index)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index, index});
   if(it != inserts_->end())
     return reinterpret_cast<T*>(it.value().first);
  }
  return nullptr;
 }

 template<typename T>
 T* get_insert_as(u4 index1, u4 index2)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index1, index2});
   if(it != inserts_->end())
     return reinterpret_cast<T*>(it.value().first);
  }
  return nullptr;
 }

 template<typename T>
 T* get_pre_insert_as(u4 index)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index, index - 1});
   if(it != inserts_->end())
     return reinterpret_cast<T*>(it.value().first);
  }
  return nullptr;
 }

 template<typename T>
 void set_insert(u4 index, T* tt, QString context = QString())
 {
  if(inserts_)
    inserts_->insert({index, index}, {(u8) tt, context});
 }

 template<typename T>
 void set_insert(QPair<u4, u4> indexes, T* tt, QString context = QString())
 {
  if(inserts_)
    inserts_->insert(indexes, {(u8) tt, context});
 }

 template<typename T>
 void set_pre_insert(u4 index, T* tt, QString context = QString())
 {
  if(inserts_)
    inserts_->insert({index, index - 1}, {(u8) tt, context});
 }


 template<typename T>
 T* get_insert_as(u4 index, QString context)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index, index});
   if(it != inserts_->end())
   {
    if(it.value().second == context)
      return reinterpret_cast<T*>(it.value().first);
   }
  }
  return nullptr;
 }

 template<typename T>
 T* get_insert_as(u4 index1, u4 index2, QString context)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index1, index2});
   if(it != inserts_->end())
   {
    if(it.value().second == context)
      return reinterpret_cast<T*>(it.value().first);
   }
  }
  return nullptr;
 }


 template<typename T>
 T* get_pre_insert_as(u4 index, QString context)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index, index - 1});
   if(it != inserts_->end())
   {
    if(it.value().second == context)
      return reinterpret_cast<T*>(it.value().first);
   }
  }
  return nullptr;
 }


 virtual void check_cached(QString key, QPair<u4, u4>& result);
 virtual void write(QString text, QPair<u4, u4>& result) = 0;

 virtual QPair<u1, u1> flag_as_sentence_end(u4 ii1, u4 ii2) = 0;

 virtual void activate_cache();
 virtual void activate_inserts();

 virtual QPair<u4, u4> get_effective_start_and_end_indices() = 0;

 virtual u8 get_glyph_point_at_index(u4 i) = 0;
 virtual SDI_Interpretation_Codes get_sdi_interpretation_code_at_index(u4 i) = 0;

 virtual u4 check_confirm_sentence_end(u4 i, u4 e) = 0;


 virtual QString get_latex_out(const QPair<u4, u4>& indices) = 0;

 virtual QString get_latex_representation(u4 index) = 0;
 virtual QString get_xml_representation(u4 index) = 0;
 virtual QChar get_qchar_representation(u4 index, QString& alternate) = 0;
 virtual QString get_qstring_representation(u4 index) = 0;

};


#endif // GH_BLOCK_BASE__H


