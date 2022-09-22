
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE__H
#define XCSD_IMAGE__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"

#include <QImage>

#include "accessors.h"

#include "xcsd-sdi-structures.h"
#include "xcsd-image-data.h"
#include "xcsd-image-geometry.h"

#include "mat2d.templates.h"

XCNS_(XCSD)

class Local_Histogram_Data;

struct XCSD_Outer_Ring_Info
{
 enum Position { Corner, Horizontal, Horizontal_Center, Vertical, Vertical_Center };

 Position position;
 QImage image;
 QRect rect;
 QRect extra;
};


class XCSD_Image
{
 QImage image_;

 XCSD_Image_Data data_;
 XCSD_Image_Geometry geometry_;

 rc2s initial_setup_tierbox_;

 QVector<XCSD_Outer_Ring_Info>* outer_ring_info_;

 void _init_outer_ring_pixel_data_landscaoe();
 void _init_outer_ring_pixel_data_landscaoe_sym();

 void _init_outer_ring_pixel_data_portrait();
 void _init_outer_ring_pixel_data_portrait_sym();

 void _init_outer_ring_pixel_data(u4 start_offset,
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape area_index, se2 x_se, mm2 y_mm);

// void _init_outer_ring_pixel_data(u4 start_offset,
//   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape area_index_start,
//   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape area_index_end, se2 x_se);

// void _init_outer_ring_pixel_data(u4 start_offset,
//   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape area_index_start,
//   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape area_index_end, se2 x_se, mm2 y_mm);

 void _init_outer_ring_pixel_data(u4 start_offset,
   se1 area_index_se, pr4 outside_xareas, pr1 outside);

 void _init_outer_ring_pixel_data(u4 start_offset,
   se1 area_index_se);

 void _init_outer_ring_pixel_data(u4 start_offset,
   se1 area_index_se, pr4 outside_xareas, mm2 y_mm);

 void _init_outer_ring_pixel_data(u4 start_offset,
   se1 area_index_se, pr4 outside_xareas, pr1 outside, mm2 y_mm, u1 index_gap = 1, u2 x_ses [4] = nullptr);

 void _init_outer_ring_pixel_data_portrait(u4 start_offset,
   se1 area_index_se, pr4 outside_xareas, pr1 outside, mm2 y_mm, u1 index_gap = 1, u2 x_ses [4] = nullptr);


 void _init_outer_ring_pixel_data(QRgb* scanline,
   u4 mark_offset, u4 start_offset, se2 x_se);


 void _init_outer_ring_pixel_data_portrait(u4 start_offset,
   se1 area_index_se);

 void _init_outer_ring_pixel_data_portrait(u4 start_offset,
   se1 area_index_se, pr4 outside_xareas, pr1 outside);

 void _init_outer_ring_pixel_data_portrait(u4 start_offset,
   se1 area_index_se, pr4 outside_xareas, mm2 y_mm);


public:

 XCSD_Image();

 ACCESSORS__RGET(QImage ,image)
 ACCESSORS__RGET(XCSD_Image_Geometry ,geometry)

 ACCESSORS(QVector<XCSD_Outer_Ring_Info>* ,outer_ring_info)

 enum Save_Mode : u1 {
   Save_QRgb, Save_Palette, Save_FB, Save_FG, Save_BG,

   Tier_Blur_3 = 64, Tier_Blur_9 = 128, Tier_Blur_27 = 192
 };

 ENUM_FLAGS_OP_MACROS(Save_Mode)

 static QColor pixel_number_to_qcolor(n8 pixel);
 static QColor pixel_number_fb_to_qcolor(n8 pixel, Save_Mode save_mode);
 QColor pixel_number_palette_to_qcolor(n8 pixel);

 static QRgb pixel_number_to_qrgba(n8 pixel);
 static QRgb pixel_number_to_qrgb(n8 pixel);
 static QRgb pixel_number_fb_to_qrgb(n8 pixel, Save_Mode save_mode);
 QRgb pixel_number_palette_to_qrgb(n8 pixel);

 static n8 qrgb_to_pixel_number(QRgb rgb);

 XCSD_TierBox* get_tierbox_at_ground_position(u2 x, u2 y);

 rc2 get_tierbox_at_ground_position_RC2(u2 x, u2 y);

 SDI_Position get_sdi_at_ground_position(u2 x, u2 y);

 void load_image(QString path);

 static constexpr u1 tierbox_width = 27;

 //get_pixel_vector(SDI_Position )

 void image_tierbox_to_sdi_pixel_map(const QImage& ci, std::map<s1, std::vector<n8>>& result);

 void init_outer_ring_pixel_data();

 u4 data_tierbox_to_sdi_pixel_map(u4 tierbox_index,
   std::map<s1, std::pair<u2, std::vector<n8>>>& result);

 void tierbox_to_qimage(XCSD_Image_Geometry::Grid_TierBox& gtb, QImage& target,
   Save_Mode save_mode,
   XCSD_Image_Geometry::Iteration_Environment ienv,
   u4* data_index, n8** data_start,
   XCSD_Image_Geometry::MCH_Info* mchi,
   QString info_folder); // = {});

 wh2 get_wh()
 {
  return {(u2)image_.width(), (u2)image_.height()};
 }

 void init_tier_counts(XCSD_Image_Geometry::TierGrid_Preferances pref);

 void init_geometry();
 void init_tierboxes();

 void init_pixel_data(QString info_folder = {});

 void calculate_pixel_averages_1byte(u1 start, u1 end, n8* reset = nullptr);

 void get_255_palette(QVector<QColor>& vec);

 void save_full_tier_image(QString path, Save_Mode save_mode,
    QString info_folder = {},
   std::function<void(QImage&, XCSD_Image_Geometry::Grid_TierBox&,
     XCSD_Image_Geometry::Iteration_Environment, u4, n8*,
     const XCSD_Image_Geometry::MCH_Info&, QString, u1)> cb = nullptr,
   std::function<void(QImage&, s1)> ocb = nullptr);

 static QString stringify_qcolor(const QColor& qc)
 {
  return QString("%1:%2:%3;%4").arg(qc.red()).arg(qc.green()).arg(qc.blue()).arg(qc.alpha());
 }

 void draw_tierboxes_to_folder(QString path,
   Mat2d<Vec1d<QString>>* paths = nullptr);

 void init_outer_ring_info();

 u4 tierbox_index_to_full_tier_index(rc2 rc);

 QVector<Local_Histogram_Data>* calculate_local_histograms(); //QString path_template);
 void set_individual_pixel_local_histogram_channels(n8& pixel);
 void set_local_histograms_channels();

 void init_local_histogram_vector(QVector<Local_Histogram_Data>& result);
 void save_local_histogram_vector_to_folder(const QVector<Local_Histogram_Data>& data, QString path_template);

 static QVector<s2> rgb555_to_hsv(u2 rgb555);
 static QColor rgb555_to_qcolor(u2 rgb555);

 static prr1 rgb555_color_distance(clrs2 colors);
 static prr1 rgb555_color_distance_expanded(clrs2 colors);
 static prr1 rgb555_to_prr(u2 rgb555);
 static prr1 rgb_to_prr(u4 rgb);
 static prr1 qcolor_to_prr(const QColor& clr);

 static prr1 rgb555_888_color_distance(u2 rgb555, u4 rgb);

 static prr1 rgb888_qcolor_distance(u4 rgb, const QColor& clr);
 static fb1 collapse_fb_distances(const prr1& dist1, const prr1& dist2);

 QSize show_255_palette(QString path,
   QString sorted_path, u1 box_width = 50, u1 padline_width = 8);


 void save_fb_gradient_trimap(fb2 poles, QString file_path,
   QString folder);

 XCSD_TierBox* get_tierbox_from_grid_tierbox(const XCSD_Image_Geometry::Grid_TierBox& gtb);
};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H
