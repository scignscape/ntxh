
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-image-data.h"


USING_XCNS(XCSD)

XCSD_Image_Data::XCSD_Image_Data()
  :  tierboxes_(nullptr), pixel_data_(nullptr)
{

}

void XCSD_Image_Data::init_pixels(wh2 total_ground_size)
{
 u4 area = total_ground_size.area();
 pixel_data_ = new Arr1d<n8, index_types<s4>>({(s4)area});
}

void XCSD_Image_Data::get_pixel_run(u4 start_index, u4 length, std::vector<n8>& result)
{
 if(result.size() < length)
   result.resize(length);
 pixel_data_->fetch_raw_data(start_index, length, result.data());
}

n8* XCSD_Image_Data::get_pixel_data_start(u4 start_index)
{
 return pixel_data_->get(start_index);
}

void XCSD_Image_Data::init_pixel_run(u4 start_index, u4 length, n8 const* source)
{
 pixel_data_->init_raw_data(start_index, length, source);
}

void XCSD_Image_Data::copy_pixels(u4 start_index, const std::vector<n8>& vec)
{
 init_pixel_run(start_index, vec.size(), vec.data());
}

// // //  this should be a raw copy ...
//for(u1 i = 0; i < 9; ++i)
//{

//}

