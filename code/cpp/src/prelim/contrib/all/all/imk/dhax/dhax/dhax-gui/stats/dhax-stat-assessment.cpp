
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-stat-assessment.h"


DHAX_Stat_Assessment::DHAX_Stat_Assessment()
  :  user_data_(nullptr), proc_(nullptr), follow_up_(nullptr)
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

 one_channel_display_image_ = cv::imread(one_channel_display_image_path_.toStdString());


#else
// //?  Anything here?
#endif

}


void DHAX_Stat_Assessment::run()
{
 proc_(*this);
}

void DHAX_Stat_Assessment::check_follow_up()
{
 if(follow_up_)
   follow_up_(*this);
}



QString DHAX_Stat_Assessment::get_full_1c_out_path(QString name_extra)
{
 QString result = full_image_path_;
 return result.replace("-full", "-full-1c-" + name_extra);
}

QString DHAX_Stat_Assessment::get_full_out_path(QString name_extra)
{
 QString result = full_image_path_;
 return result.replace("-full", "-full-" + name_extra);
}

QString DHAX_Stat_Assessment::get_1c_out_path(QString name_extra)
{
 QString result = one_channel_image_path_;
 return result.replace("-1c", "-1c-" + name_extra);
}

