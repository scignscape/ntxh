
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_TIERBOX__H
#define XCSD_TIERBOX__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"
#include "xcsd-1d/arr1d.h"

#include "xcsd-sdi-structures.h"

#include <QImage>

#include "accessors.h"

XCNS_(XCSD)

//class XCSD_XPixel;


struct Box3x3_8bytepx
{
 n8 color_average;
 Box3x3_8bytepx();
};

struct Box9x9_8bytepx
{
 Vec1d<Box3x3_8bytepx> vec_3x3;
 Box9x9_8bytepx();
};

class XCSD_TierBox
{
// u2 pixel_bytelength_;

 u2 non_full_;
 Vec1d<Box9x9_8bytepx> box9x9_;


 rc2 matrix_position_;

 pr2s mch_code_;

 u4 pixel_data_ground_index_;

 u2 tier_ring_;
 u2 inner_pushout_;
 u1 compressed_clock_index_;
 u1 full_clock_index_;
 u2 intra_tier_ring_index_;


public:

 XCSD_TierBox(rc2 matrix_position);

 ACCESSORS__DECLARE(u2 ,non_full_h)
 ACCESSORS__DECLARE(u2 ,non_full_v)

 ACCESSORS__DECLARE(bool ,non_full_up)
 ACCESSORS__DECLARE(bool ,non_full_left)

 ACCESSORS(rc2 ,matrix_position)
 ACCESSORS(pr2s ,mch_code)

 ACCESSORS(u4 ,pixel_data_ground_index)

 ACCESSORS(u2 ,tier_ring)
 ACCESSORS(u2 ,inner_pushout)
 ACCESSORS(u1 ,compressed_clock_index)
 ACCESSORS(u1 ,full_clock_index)
 ACCESSORS(u2 ,intra_tier_ring_index)

 union _inner_box {
   Box3x3_8bytepx* _3x3;
   Box9x9_8bytepx* _9x9;
   XCSD_TierBox* _this;
 };

 typedef Box3x3_8bytepx _inner_box_3x3;
 typedef Box9x9_8bytepx _inner_box_9x9;


 rc2 get_matrix_index_position()
 {
  return matrix_position_ + 1;
 }

 rc2 get_grid_position()
 {
  return matrix_position_ - 1;
 }

 void set_non_full_up() { set_non_full_up(true); }
 void set_non_full_left() { set_non_full_left(true); }

 void init_boxes();

 _inner_box get_inner_box(s1 index);

 static u2 get_scanline_offset_for_inner_top_left(s1 index);
 static u2 get_scanline_offset_for_inner_center(s1 index);

 static u2 get_ground_offset_for_inner_top_left(s1 index);
 static u2 get_ground_offset_for_inner_center(s1 index);

 static u2 get_ground_offset_sdi(s2 index);

 static bool normalize_sdi_index(s2& index);
 static bool normalize_inner_index(s1& index);

//? xy1 get_inner_location_for_inner_index(s1 index);

 static xy1 get_ground_location_for_inner_top_left(s1 index);
 static xy1 get_ground_location_for_inner_center(s1 index)
 {
  return get_ground_location_for_inner_top_left(index) + 1;
 }

 static u2 get_scanline_offset_sdi(s2 index);
 static xy1 get_ground_location_sdi(s2 index);

};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H
