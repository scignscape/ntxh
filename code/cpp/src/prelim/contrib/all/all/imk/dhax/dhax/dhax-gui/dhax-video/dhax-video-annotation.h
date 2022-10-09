
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_VIDEO_ANNOTATION__H
#define DHAX_VIDEO_ANNOTATION__H

#include <QtWidgets>

#include <QVideoFrame>
#include <QVideoSurfaceFormat>
#include <QAbstractVideoSurface>

#include <QPointF>

#include "global-types.h"
#include "accessors.h"


class DHAX_Video_Annotation
{
 QString kind_;

 u4 starting_frame_number_;
 u4 ending_frame_number_;

 QString text_;
 QString inner_style_sheet_;

 QPointF corner_position_;

 QString html_text_;

 void* scene_data_;
 void* scene_type_data_;

 QString data64_;

public:

 DHAX_Video_Annotation();

 ACCESSORS(u4 ,starting_frame_number)
 ACCESSORS(u4 ,ending_frame_number)

 ACCESSORS(QString ,kind)
 ACCESSORS(QString ,text)
 ACCESSORS(QString ,inner_style_sheet)
 ACCESSORS(QPointF ,corner_position)
 ACCESSORS(QString ,html_text)

 ACCESSORS(void* ,scene_data)
 ACCESSORS(void* ,scene_type_data)

 ACCESSORS(QString ,data64)

 void finalize_html_text();

 template<typename DATA_Type>
 DATA_Type* scene_data_as()
 {
  return (DATA_Type*) scene_data_;
 }

 template<typename DATA_Type>
 DATA_Type* scene_type_data_as()
 {
  return (DATA_Type*) scene_type_data_;
 }

 template<typename DATA_Type>
 bool scene_data_as(DATA_Type*& d)
 {
  if(scene_data_)
  {
   d = (DATA_Type*) scene_data_;
   return true;
  }
  return false;
 }

//?
// template<typename T>
// friend T& operator<<(T& lhs, const DHAX_Video_Annotation& rhs)
// {
//  lhs << "%1 -> %2: %3"_qt.arg(rhs.starting_frame_number_)
//    .arg(rhs.ending_frame_number_).arg(rhs.text().mid(0, 10));
//  return lhs;
// }

 template<typename T>
 friend T operator<<(T lhs, const DHAX_Video_Annotation& rhs)
 {
  if(rhs.kind() == "text")
    lhs << "%1 -> %2: %3"_qt.arg(rhs.starting_frame_number_)
      .arg(rhs.ending_frame_number_).arg(rhs.text().mid(0, 10));
  else
    lhs << "%1 -> %2: %3"_qt.arg(rhs.starting_frame_number_)
      .arg(rhs.ending_frame_number_).arg(rhs.kind());
  return lhs;
 }

};

#endif //DHAX_VIDEO_ANNOTATION__H
