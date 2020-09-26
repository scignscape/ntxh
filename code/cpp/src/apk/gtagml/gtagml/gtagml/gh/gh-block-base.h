
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
 QMap<QPair<u4, u4>, QList<QPair<u8, QString>>>* inserts_;

public:

 GH_Block_Base();

 virtual u8 get_default_null() = 0;

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
 QList<T*> get_insert_as(u4 index1, u4 index2)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index1, index2});
   if(it != inserts_->end())
   {
    QList<T*> result;
    for(const QPair<u8, QString>& pr : it.value())
    {
     result.push_back(reinterpret_cast<T*>(pr.first));
    }
    return result;
   }
  }
  return {};
 }

 template<typename T>
 QList<T*> get_insert_as(u4 index)
 {
  return get_insert_as<T>(index, index);
 }

 template<typename T>
 QList<T*> get_pre_insert_as(u4 index)
 {
  return get_insert_as<T>(index, index - 1);
 }

 template<typename T>
 void set_insert_back(u4 index, T* tt, QString context = QString())
 {
  if(inserts_)
  {
   (*inserts_)[QPair<u4, u4>({index, index})].push_back({(u8) tt, context});
  }
 }

 template<typename T>
 void set_insert_front(u4 index, T* tt, QString context = QString())
 {
  if(inserts_)
  {
   (*inserts_)[QPair<u4, u4>({index, index})].push_front({(u8) tt, context});
  }
 }

 template<typename T>
 void set_insert_back(QPair<u4, u4> indexes, T* tt, QString context = QString())
 {
  if(inserts_)
  {
   (*inserts_)[indexes].push_back({(u8) tt, context});
  }
 }

 template<typename T>
 void set_insert_front(QPair<u4, u4> indexes, T* tt, QString context = QString())
 {
  if(inserts_)
  {
   (*inserts_)[indexes].push_front({(u8) tt, context});
  }
 }

 template<typename T>
 void set_pre_insert_back(u4 index, T* tt, QString context = QString())
 {
  set_insert_back({index, index - 1}, tt, context);
 }

 template<typename T>
 void set_pre_insert_front(u4 index, T* tt, QString context = QString())
 {
  set_insert_front({index, index - 1}, tt, context);
 }

 template<typename T>
 QList<T*> get_insert_as(u4 index1, u4 index2, QString context)
 {
  if(inserts_)
  {
   auto it = inserts_->find({index1, index2});
   if(it != inserts_->end())
   {
    QList<T*> result;
    for(const QPair<u8, QString>& pr : it.value())
    {
     if(pr.second == context)
       result.push_back(reinterpret_cast<T*>(pr.first));
    }
    return result;
   }
  }
  return {};
 }

 template<typename T>
 QList<T*> get_insert_as(u4 index, QString context)
 {
  return get_insert_as<T>(index, index, context);

//  if(inserts_)
//  {
//   auto it = inserts_->find({index, index});
//   if(it != inserts_->end())
//   {
//    if(it.value().second == context)
//      return reinterpret_cast<T*>(it.value().first);
//   }
//  }
//  return nullptr;
 }


 template<typename T>
 QList<T*> get_pre_insert_as(u4 index, QString context)
 {
  return get_insert_as<T>(index, index - 1, context);
 }


 virtual void check_cached(QString key, QPair<u4, u4>& result);
 virtual void write(QString text, QPair<u4, u4>& result) = 0;

 virtual void flag_as_sentence_end(u4 ii1, u4 ii2, QPair<QPair<u8, u8>, QPair<u8, u8>>& r) = 0;

 virtual void activate_cache();
 virtual void activate_inserts();

 virtual QPair<u4, u4> get_effective_start_and_end_indices() = 0;

 virtual u8 get_glyph_point_at_index(u4 i) = 0;
 virtual u4 clear_to_sentence_start(u4 pre, u4 start) = 0;
 virtual SDI_Interpretation_Codes get_sdi_interpretation_code_at_index(u4 i) = 0;

 virtual u4 check_confirm_sentence_end(u4 i, u4 e) = 0;

 virtual void swap_codes(u4 i, u8 oldc, u8 newc) = 0;


 virtual QString get_latex_out(const QPair<u4, u4>& indices) = 0;

 virtual QString get_latex_representation(u4 index) = 0;
 virtual QString get_xml_representation(u4 index) = 0;
 virtual QChar get_qchar_representation(u4 index, QString& alternate) = 0;
 virtual QString get_qstring_representation(u4 index) = 0;

};


#endif // GH_BLOCK_BASE__H


