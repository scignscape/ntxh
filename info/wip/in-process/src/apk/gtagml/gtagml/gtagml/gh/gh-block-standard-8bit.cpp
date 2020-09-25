
// licence_cpp

#include "gh-block-standard-8bit.h"

#include "gh-block-parse-mode.h"

#include "glyphdeck/gh-glyphdeck-standard-8bit.h"

#include <QTextStream>

GH_Block_Standard_8bit::GH_Block_Standard_8bit()
 :  current_index_(1), glyphdeck_(new GH_Glyphdeck_Standard_8bit)
    //parse_mode_(new GH_Block_Parse_Mode(247))
{
 parse_mode_ = new GH_Block_Parse_Mode(glyphdeck_->get_default_null());
 chars_.push_back(glyphdeck_->get_default_void_separator());
 chars_.push_back(glyphdeck_->get_default_void_separator());
}

u8 GH_Block_Standard_8bit::get_glyph_point_at_index(u4 i)
{
 if(i > chars_.size())
   return chars_.value(0, glyphdeck_->get_default_null());
 return chars_.at(i);
}

u4 GH_Block_Standard_8bit::check_confirm_sentence_end(u4 i, u4 e)
{
 for(u4 u = i; u <= e; ++u)
 {
  u8 uu = get_glyph_point_at_index(u);
  GH_Block_Base::Evaluation_Codes ec = glyphdeck_->check_confirm_sentence_end(uu);
  if(ec == GH_Block_Base::Evaluation_Codes::Confirm)
    return i;
  if(ec == GH_Block_Base::Evaluation_Codes::Refute)
    return 0;
 }
 return 0;
}

QPair<u1, u1> GH_Block_Standard_8bit::flag_as_sentence_end(u4 se, u4 sse)
{
 u1 dn = glyphdeck_->get_default_null();
 u1 c1 = chars_[se];
 u4 swap = glyphdeck_->get_sentence_end_swap(c1);
 if(swap == dn)
   return {dn, dn};
 chars_[se] = swap;
 if(sse == 0)
 {
  return {swap, dn};
 }
 u1 c2 = chars_[sse];
 u4 sswap = glyphdeck_->get_sentence_end_space_swap(c2);
 if(sswap == glyphdeck_->get_default_null())
   return {swap, dn};
 chars_[sse] = sswap;
 return {swap, sswap};
}

GH_Block_Base::SDI_Interpretation_Codes GH_Block_Standard_8bit::get_sdi_interpretation_code_at_index(u4 i)
{
 u8 u = get_glyph_point_at_index(i);
 return glyphdeck_->get_sdi_interpretation_code((u1) u);
}

void GH_Block_Standard_8bit::write(QString text, QPair<u4, u4>& result)
{
 QByteArray qba = text.toLatin1();
 write(qba, result);
}

QPair<u4, u4> GH_Block_Standard_8bit::get_effective_start_and_end_indices()
{
 return {2, chars_.size() - 1};
}

QString GH_Block_Standard_8bit::get_latex_supplement(u4 index)
{
 u1 code = chars_[index];
 return glyphdeck_->get_latex_supplement(code);
}

QString GH_Block_Standard_8bit::get_latex_out(const QPair<u4, u4>& indices)
{
 QString result;
 QTextStream qts(&result);
 for(u4 u = indices.first; u <= indices.second; ++u)
 {
  // first, inserts ...
  if(QString* pre = get_pre_insert_as<QString>(u))
    qts << *pre;

  qts << get_latex_representation(u);
  QString supl = get_latex_supplement(u);
  if(!supl.isEmpty())
    qts << supl; // " " << supl << " ";

  if(QString* post = get_insert_as<QString>(u))
    qts << *post;

 }
 return result;
}

void GH_Block_Standard_8bit::write(QByteArray& text, QPair<u4, u4>& result)
{

 if(text.isEmpty())
 {
  result.first = current_index_;
  result.second = current_index_ - 1;
  return;
 }
 result.first = current_index_ + 1;
 for(u1 u : text)
 {
  u1 check = parse_mode_->check_hold(u);
  if(check)
  {
   // // todo fewer raw numbers ...
   if(check == 200)
     continue;
   if(check > 200)
   {
    check -= 200;
    for(u1 uu = 0; uu < check; ++uu)
    {
     ++current_index_;
     chars_.push_back((u1) parse_mode_->release_glyph_point());
    }
   }
   if(check > 100)
   {
    check -= 100;
    for(u1 uu = 0; uu < check; ++uu)
    {
     ++current_index_;
     QPair<u1, u1> pr;
     parse_mode_->release_cancel_or_alt_char(pr);
     chars_.push_back(glyphdeck_->encode_alt_pair(pr));
    }
   }
   continue;
  }
//  parse_mode_->

  //  switch(parse_mode_)
//  {

//  }
  ++current_index_;
  u1 uu = glyphdeck_->encode_latin1(u);
  chars_.push_back(uu);
 }
 result.second = current_index_;
}

QString GH_Block_Standard_8bit::get_latex_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 
 
 u1 code = chars_[index];

 QString result = glyphdeck_->get_latex_representation(code);
 return result;
}

QString GH_Block_Standard_8bit::get_xml_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QString result;// = glyphdeck_->get_xml_representation(code);
 return result;
}

QChar GH_Block_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QChar result;// = glyphdeck_->get_latex_representation(code);//, alternate);
 return result;
}

QString GH_Block_Standard_8bit::get_qstring_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QString result;// = glyphdeck_->get_latex_representation(code);
 return result;
}


