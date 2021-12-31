
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_ANNOTATION_EDITOR__H
#define DHAX_ANNOTATION_EDITOR__H


#include <QString>
#include <QPoint>
#include <QVector>
#include <QMenu>

#include <QMap>


#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include <functional>

#include "kans.h"


//KANS_(GTagML)


class DHAX_Annotation_Editor
{
 void* current_pcd_vars_;
 u2 target_search_page_;
 u2 target_search_line_;

 r8 search_xmin_;
 r8 search_ymin_;
 r8 search_xmax_;
 r8 search_ymax_;

 QString full_path_;
 QString file_name_;
 QString file_specific_path_;

 QString last_saved_file_path_;

 //u4 autogen_index_;

 s2 last_paragraph_[2][2];
 u2 last_page_;

 r8 estimate_line(r8 height);

 QPoint column_first_line_crossing_;
// r8 column_border_;
// r8 first_line_height_;

 std::function<void(QString)> search_cb_;

public:
 struct Edit_Data
 {
  u2 file_version;
  u1 kind;
  u1 agree_disagree;
  u2 line;
  u2 page;
  s2 paragraph;
  s2 paragraph_2nd_column;
  s1 offset_paragraph_original;
  s1 offset_paragraph_original_2nd_column;
  QString edit;
  QString original;
  QString first_edit;
  QString comment;
  r8 x_pos;
  r8 y_pos;
  s4 x_point;
  s4 y_point;
 };

 template<typename T>
 friend T& operator<<(T& lhs, const Edit_Data& ed)
 {
  lhs << ed.file_version
  << ed.kind
  << ed.agree_disagree
  << ed.line
  << ed.page
  << ed.paragraph
  << ed.paragraph_2nd_column
  << ed.offset_paragraph_original
  << ed.offset_paragraph_original_2nd_column
  << ed.edit
  << ed.original
  << ed.first_edit
  << ed.comment
  << ed.x_pos
  << ed.y_pos
  << ed.x_point
  << ed.y_point;

  return lhs;
 }

 template<typename T>
 friend T& operator>>(T& lhs, Edit_Data& ed)
 {
  lhs >> ed.file_version
  >> ed.kind
  >> ed.agree_disagree
  >> ed.line
  >> ed.page
  >> ed.paragraph
  >> ed.paragraph_2nd_column
  >> ed.offset_paragraph_original
  >> ed.offset_paragraph_original_2nd_column
  >> ed.edit
  >> ed.original
  >> ed.first_edit
  >> ed.comment
  >> ed.x_pos
  >> ed.y_pos
  >> ed.x_point
  >> ed.y_point;

  return lhs;
 }

private:

 QVector<Edit_Data*> edits_;

 QMap<QPair<u2, u2>, QVector<u2>> edit_map_;


public:

 DHAX_Annotation_Editor();

 ACCESSORS(QString ,full_path)
 ACCESSORS(QString ,file_name)
 ACCESSORS(std::function<void(QString)> ,search_cb)

 ACCESSORS(u2 ,target_search_page)
 ACCESSORS(u2 ,target_search_line)

 void reset_search_minmax(r8 xm, r8 ym, r8 xx, r8 yx)
 {
  search_xmin_ = xm;
  search_ymin_ = ym;
  search_xmax_ = xx;
  search_ymax_ = yx;
 }

 void reset_search_minmax()
 {
  reset_search_minmax(0,0,0,0);
 }

 void check_file_specific_path();

 void context_menu(QMenu* m,
   const QPoint& qts, u2 page, QPair<r8, r8> pos);

 void show_editor_dialog(QMenu* m,
   const QPoint& qts, u2 page, QPair<r8, r8> pos);

 void run_pcds(QMenu* m,
   const QPoint& qp, u2 page, QPair<r8, r8> pos);

 void run_tikz_margins(QMenu* m,
   const QPoint& qp, u2 page, QPair<r8, r8> pos);


 void update_edit_file(u2 page, u2 line);
 void update_edit_file(u2 page, u2 line, u1 index, Edit_Data* ed);
 void update_edit_file(QString file_path, QString append_path, Edit_Data* ed);

 void update_short_edit_file(QString file_path, QString append_path, Edit_Data* ed);

 void update_test_edit_file(Edit_Data* ed);

 void edit_data_to_string(Edit_Data& ed, QString& result);
 void edit_data_to_short_string(Edit_Data& ed, QString& result);

 Edit_Data* read_edit_data(QString file_path);
 Edit_Data* read_edit_data();
 static Edit_Data* read_edit_data(const QByteArray& qba);
};

// _KANS(GTagML)


#endif  //  DHAX_ANNOTATION_EDITOR__H
