
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_VIDEO_ANNOTATION_SET__H
#define DHAX_VIDEO_ANNOTATION_SET__H


#include <QMap>

#include <QVideoFrame>
#include <QVideoSurfaceFormat>
#include <QAbstractVideoSurface>

#include "global-types.h"
#include "accessors.h"

#include "dhax-video-annotation.h"

#include "ntxh-parser/ntxh-document.h"

USING_KANS(HGDMCore)

class DHAX_Video_Annotation_Set : public QMap<u4, DHAX_Video_Annotation>
{
 typedef NTXH_Graph::hypernode_type hypernode_type;

 QMap<u4, QVector<QPair<void*, void*>>> end_frame_data_;

 QColor circled_text_default_background_color_;
 QColor circled_text_default_foreground_color_;
 QColor circled_text_default_outline_color_;

 r4 circled_text_default_font_size_;
 u1 circled_text_default_width_;
 u1 circled_text_default_border_;

 QSizeF smaller_video_size_;
 QSizeF larger_video_size_;


 r8 sizes_ratio_x_;
 r8 sizes_ratio_y_;

 r8 sizes_ratio_x_adjustment_;
 r8 sizes_ratio_y_adjustment_;

 s2 smaller_size_x_translation_;
 s2 smaller_size_y_translation_;

 s2 larger_size_x_translation_;
 s2 larger_size_y_translation_;

public:

 DHAX_Video_Annotation_Set();


 ACCESSORS(QColor ,circled_text_default_background_color)
 ACCESSORS(QColor ,circled_text_default_foreground_color)
 ACCESSORS(QColor ,circled_text_default_outline_color)

 ACCESSORS(r4 ,circled_text_default_font_size)
 ACCESSORS(u1 ,circled_text_default_width)

 ACCESSORS(QSizeF ,smaller_video_size)
 ACCESSORS(QSizeF ,larger_video_size)

 ACCESSORS(s2 ,smaller_size_x_translation)
 ACCESSORS(s2 ,smaller_size_y_translation)

 ACCESSORS(s2 ,larger_size_x_translation)
 ACCESSORS(s2 ,larger_size_y_translation)

 ACCESSORS(r8 ,sizes_ratio_x)
 ACCESSORS(r8 ,sizes_ratio_y)


 ACCESSORS(r8 ,sizes_ratio_x_adjustment)
 ACCESSORS(r8 ,sizes_ratio_y_adjustment)


 void check_ratios()
 {
  sizes_ratio_x_ = larger_video_size_.width() / smaller_video_size_.width();
  sizes_ratio_y_ = larger_video_size_.height() / smaller_video_size_.height();
 }


 DHAX_Video_Annotation* get_annotation_by_start_frame(u4 key);

 QPair<void*, void*> get_data_by_end_frame(u4 key);
 void set_end_frame_data(u4 key, void* data1, void* data2);
 void set_end_frame_data(u4 key, DHAX_Video_Annotation& dva);

 void load_sample_annotations();

 void load_annotation(DHAX_Video_Annotation& dva);
 void load_annotation_file(QString file_path);

 void read_ntxh_hypernode(NTXH_Graph& g, hypernode_type* h);

 void parse_circled_text_default_hypernode(NTXH_Graph& g, hypernode_type* h);
 void parse_circled_text_annotation_hypernode(NTXH_Graph& g, hypernode_type* h);
 void parse_text_annotation_hypernode(NTXH_Graph& g, hypernode_type* h);
 void parse_shape_annotation_hypernode(NTXH_Graph& g, hypernode_type* h);
 void parse_annotation_settings_hypernode(NTXH_Graph& g, hypernode_type* h);

};

#endif //DHAX_VIDEO_ANNOTATION_SET__H
