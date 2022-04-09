
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE_DATA__H
#define XCSD_IMAGE_DATA__H

#include "xcns.h"

#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"

#include "xcsd-1d/arr1d.h"

#include "xcsd-sdi-structures.h"

XCNS_(XCSD)

class XCSD_TierBox;

class XCSD_Image_Data
{
 Vec1d<XCSD_TierBox*>* tierboxes_;

 Arr1d<n8, index_types<s4>, _pr_break>* pixel_data_;

public:

 XCSD_Image_Data();

 void init_pixels(wh2 total_ground_size);
 void init_pixel_run(u4 start_index, u4 length, n8 const* source);

 void init_single_pixel(u4 index, n8 pixel_number);

 n8* get_pixel_data_start(u4 start_index);

 n8 get_single_pixel(u4 index);

 void copy_pixels(u4 start_index, const std::vector<n8>& vec);
 void get_pixel_run(u4 start_index, u4 length, std::vector<n8>& result);


};


_XCNS(XCSD)

#endif // XCSD_IMAGE_DATA__H

