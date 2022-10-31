
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-stat-assessment.h"


DHAX_Stat_Assessment::DHAX_Stat_Assessment()
{

}

void DHAX_Stat_Assessment::load_images()
{
#ifdef USE_OpenCV

 full_image_ = cv::imread(full_image_path_.toStdString());

 if(gray_image_path_.isEmpty())
   cv::cvtColor(full_image_, gray_image_, cv::COLOR_BGR2GRAY);
 else
   gray_image_ = cv::imread(gray_image_path_.toStdString());

 one_channel_image_ = cv::imread(one_channel_image_path_.toStdString(),
   cv::IMREAD_GRAYSCALE);

#else
// //?  Anything here?
#endif


}

