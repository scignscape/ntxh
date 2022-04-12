
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

XCNS_(XCSD)



class XCSD_Image
{
 QImage image_;

 XCSD_Image_Data data_;
 XCSD_Image_Geometry geometry_;

 rc2s initial_setup_tierbox_;

 void _init_outer_ring_pixel_data_landscaoe();
 void _init_outer_ring_pixel_data_landscaoe_sym();

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


 void _init_outer_ring_pixel_data(QRgb* scanline,
   u4 mark_offset, u4 start_offset, se2 x_se);

public:

 XCSD_Image();

 ACCESSORS__RGET(QImage ,image)
 ACCESSORS__RGET(XCSD_Image_Geometry ,geometry)

 QColor pixel_number_to_qcolor(n8 pixel);

 QRgb pixel_number_to_qrgb(n8 pixel);

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

 void get_255_palatte(QVector<QColor>& vec);

 void save_full_tier_image(QString path, QString info_folder = {},
   std::function<void(QImage&, XCSD_Image_Geometry::Grid_TierBox&,
     XCSD_Image_Geometry::Iteration_Environment, u4, n8*,
     const XCSD_Image_Geometry::MCH_Info&, QString, u1)> cb = nullptr,
   std::function<void(QImage&, s1)> ocb = nullptr);




};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H
