

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
  :  circled_text_default_font_size_(12), reffed_annotation_count_(0),
    circled_text_default_width_(0), circled_text_default_border_(2),
    sizes_ratio_x_(0), sizes_ratio_y_(0),
    sizes_ratio_x_adjustment_(0), sizes_ratio_y_adjustment_(0),
    current_pause_annotation_(nullptr)
{

}


void DHAX_Video_Annotation_Set::parse_annotation_settings_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 6}}, [this](QVector<QPair<QString, void*>>& prs)
 {
  sizes_ratio_x_adjustment_ = prs[0].first.toDouble();
  sizes_ratio_y_adjustment_ = prs[1].first.toDouble();

  smaller_size_x_translation_ = prs[2].first.toShort();
  smaller_size_y_translation_ = prs[3].first.toShort();

  larger_size_x_translation_ = prs[4].first.toShort();
  larger_size_y_translation_ = prs[5].first.toShort();
 });
}

void DHAX_Video_Annotation_Set::parse_reused_style_sheet(QString& iss)
{
 int index = iss.indexOf(')', 2);
 if(index != -1)
 {
  QString key = iss.mid(2, index - 2);
  iss = iss.mid(index + 1);
  reused_inner_style_sheets_[key] = iss;
 }
}

void DHAX_Video_Annotation_Set::fetch_reused_style_sheet(QString& iss)
{
 int index = iss.indexOf(']', 2);
 if(index != -1)
 {
  QString key = iss.mid(2, index - 2);
  iss = reused_inner_style_sheets_[key];
 }
}

void DHAX_Video_Annotation_Set::parse_text_annotation_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 7}}, [this](QVector<QPair<QString, void*>>& prs)
 {

  DHAX_Video_Annotation dva;
  dva.set_kind("text");

  dva.set_element_name(prs[2].first);

  dva.set_text(prs[3].first);

  QString iss = prs[4].first;
  if(iss.startsWith("($"))
    parse_reused_style_sheet(iss);
  else if(iss.startsWith("[$"))
    fetch_reused_style_sheet(iss);

  dva.set_inner_style_sheet(iss);

  dva.set_corner_position(QPointF{prs[5].first.toFloat(), prs[6].first.toFloat()});
  dva.finalize_html_text();

  QString s = prs[0].first;
  QString e = prs[1].first;
  if(s.startsWith('!'))
  {
   dva.set_ref_id(s.mid(1));

   // //  convert 10ths of a second to milliseconds
   dva.set_ref_time_offset(prs[1].first.toUInt() * 100);
  }
  else
  {
   u4 start = s.toInt();
   u4 end = e == "*"? INT_MAX : e.toInt();
   if(e.startsWith('+'))
     end += start;

   dva.set_starting_frame_number(start);
   dva.set_ending_frame_number(end);
  }

  load_annotation(dva);

//  QString name_description = prs[0].first;
 });

}


void DHAX_Video_Annotation_Set::parse_pause_annotation_hypernode(NTXH_Graph& g, hypernode_type* h)
{
 g.get_sfsr(h, {{1, 3}}, [this](QVector<QPair<QString, void*>>& prs)
 {
  DHAX_Video_Annotation dva;
  dva.set_starting_frame_number(prs[0].first.toInt());
  dva.set_id(prs[1].first);
  dva.set_pause_time(prs[2].first.toInt() * 100);
  dva.set_kind("pause");
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

// typedef void (DHAX_Video_Annotation_Set::*fn_type)();
// fn_type fn = &DHAX_Video_Annotation_Set::parse_text_annotation_hypernode;

 static QMap<QString, void (DHAX_Video_Annotation_Set::*)
   (NTXH_Graph&, hypernode_type*)> static_map
 {
#define TEMP_MACRO(x, y) {#x, &DHAX_Video_Annotation_Set::y},
  TEMP_MACRO(Text_Annotation, parse_text_annotation_hypernode)
  TEMP_MACRO(Pause_Annotation, parse_pause_annotation_hypernode)
  TEMP_MACRO(Shape_Annotation, parse_shape_annotation_hypernode)
  TEMP_MACRO(Circled_Text_Default,  parse_circled_text_default_hypernode)
  TEMP_MACRO(Circled_Text_Annotation,  parse_circled_text_annotation_hypernode)
  TEMP_MACRO(Annotation_Settings,  parse_annotation_settings_hypernode)
#undef TEMP_MACRO
 };

 auto it = static_map.find(ty);
 if(it != static_map.end())
   (this->**it)(g, h);

// if(ty == "Text_Annotation")
//   parse_text_annotation_hypernode(g, h);

// else if(ty == "Shape_Annotation")
//   parse_shape_annotation_hypernode(g, h);

// else if(ty == "Circled_Text_Default")
//   parse_circled_text_default_hypernode(g, h);

// else if(ty == "Circled_Text_Annotation")
//   parse_circled_text_annotation_hypernode(g, h);

// else if(ty == "Annotation_Settings")
//   parse_annotation_settings_hypernode(g, h);

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

void DHAX_Video_Annotation_Set::load_annotation(const DHAX_Video_Annotation& dva)
{
 if(dva.ref_id().isEmpty())
 {
  (*this)[dva.starting_frame_number()] = dva;

  DHAX_Video_Annotation* copied_dva = &(*this)[dva.starting_frame_number()];

  if(!dva.id().isEmpty())
    annotations_by_id_[dva.id()] = copied_dva;
 }
 else
 {
  --reffed_annotation_count_;
  (*this)[reffed_annotation_count_] = dva;
  DHAX_Video_Annotation* copied_dva = &(*this)[reffed_annotation_count_];
  if(DHAX_Video_Annotation* ref = annotations_by_id_.value(dva.ref_id()))
  {
   copied_dva->set_ref_annotation(ref);
   anchored_ref_annotations_[ref].insert(copied_dva);
  }
 }
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
