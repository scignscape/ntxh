

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-video-annotation-set.h"

#include "ntxh-parser/ntxh-document.h"



#include <QtWidgets>
#include <qabstractvideosurface.h>
#include <qvideosurfaceformat.h>



DHAX_Video_Annotation_Set::DHAX_Video_Annotation_Set()
  :  circled_text_default_font_size_(12),
    circled_text_default_width_(0), circled_text_default_border_(2)
{

}


void DHAX_Video_Annotation_Set::parse_text_annotation_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 6}}, [this](QVector<QPair<QString, void*>>& prs)
 {
  u4 start = prs[0].first.toUInt();
  u4 end = prs[1].first.toUInt();
  if(prs[1].first.startsWith('+'))
    end += start;

  DHAX_Video_Annotation dva;
  dva.set_kind("text");
  dva.set_text(prs[2].first);
  dva.set_inner_style_sheet(prs[3].first);
  dva.set_starting_frame_number(start);
  dva.set_ending_frame_number(end);
  dva.set_corner_position(QPointF{prs[4].first.toFloat(), prs[5].first.toFloat()});
  dva.finalize_html_text();
  load_annotation(dva);

//  QString name_description = prs[0].first;
 });

}

void DHAX_Video_Annotation_Set::parse_circled_text_default_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 15}}, [this](QVector<QPair<QString, void*>>& prs)
 {
  circled_text_default_font_size_ = prs[13].first.toFloat();
  circled_text_default_border_ = prs[14].first.toInt();
  circled_text_default_width_ = prs[0].first.toInt();

#define _PRS_(x)     prs[x].first.toUInt()
  circled_text_default_background_color_ = QColor(
    _PRS_(1), _PRS_(2), _PRS_(3), _PRS_(4));
  circled_text_default_foreground_color_ = QColor(
    _PRS_(5), _PRS_(6), _PRS_(7), _PRS_(8));
  circled_text_default_outline_color_ = QColor(
    _PRS_(9), _PRS_(10), _PRS_(11), _PRS_(12));
 });
}

void DHAX_Video_Annotation_Set::parse_circled_text_annotation_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 5}}, [this](QVector<QPair<QString, void*>>& prs)
 {
  u4 start = prs[0].first.toUInt();
  u4 end = prs[1].first.toUInt();
  if(prs[1].first.startsWith('+'))
    end += start;

  DHAX_Video_Annotation dva;
  dva.set_kind("circled");

  dva.set_text(prs[2].first);
  dva.set_starting_frame_number(start);
  dva.set_ending_frame_number(end);
  dva.set_corner_position(QPointF{prs[3].first.toFloat(), prs[4].first.toFloat()});
  load_annotation(dva);
 });
}


void DHAX_Video_Annotation_Set::parse_shape_annotation_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 5}}, [this](QVector<QPair<QString, void*>>& prs)
 {
  u4 start = prs[1].first.toUInt();
  u4 end = prs[2].first.toUInt();
  if(prs[2].first.startsWith('+'))
    end += start;

//?  QString data64 = prs[5].first;

  DHAX_Video_Annotation dva;
  dva.set_kind(prs[0].first);
  dva.set_starting_frame_number(start);
  dva.set_ending_frame_number(end);
  dva.set_kv_text(prs[3].first);
  dva.set_data64(prs[4].first);
  load_annotation(dva);

//  QString name_description = prs[0].first;
 });

}



void DHAX_Video_Annotation_Set::read_ntxh_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 QString ty = h->type_descriptor().first;
 if(ty == "Text_Annotation")
   parse_text_annotation_hypernode(g, h);

 else if(ty == "Shape_Annotation")
   parse_shape_annotation_hypernode(g, h);

 else if(ty == "Circled_Text_Default")
   parse_circled_text_default_hypernode(g, h);

 else if(ty == "Circled_Text_Annotation")
   parse_circled_text_annotation_hypernode(g, h);

}


void DHAX_Video_Annotation_Set::load_annotation_file(QString file_path)
{
 NTXH_Document doc(file_path);

 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 NTXH_Graph& g = *doc.graph();
 const QVector<hypernode_type*>& v = g.hypernodes();

 for(hypernode_type* h : v)
 {
  read_ntxh_hypernode(g, h);
 }


}

void DHAX_Video_Annotation_Set::load_annotation(DHAX_Video_Annotation& dva)
{
 (*this)[dva.starting_frame_number()] = dva;
}


void DHAX_Video_Annotation_Set::load_sample_annotations()
{
 DHAX_Video_Annotation dva;
 dva.set_text("TEST");
 dva.set_inner_style_sheet("color:red");
 dva.set_starting_frame_number(100);
 dva.set_ending_frame_number(300);
 dva.set_corner_position(QPointF{100, 100});
 dva.finalize_html_text();
 load_annotation(dva);
}

QPair<void*, void*> DHAX_Video_Annotation_Set::get_data_by_end_frame(u4 key)
{
 auto it = end_frame_data_.find(key);
 if(it == end_frame_data_.end())
   return {nullptr, nullptr};
 return it->value(0);
}

void DHAX_Video_Annotation_Set::set_end_frame_data(u4 key, void* data1, void* data2)
{
 end_frame_data_[key].push_back({data1, data2});
}

void DHAX_Video_Annotation_Set::set_end_frame_data(u4 key, DHAX_Video_Annotation& dva)
{
 set_end_frame_data(key, dva.scene_type_data(), dva.scene_data());
}


DHAX_Video_Annotation* DHAX_Video_Annotation_Set::get_annotation_by_start_frame(u4 key)
{
 auto it = find(key);
 if(it == end())
   return nullptr;
 return &it.value();
}
