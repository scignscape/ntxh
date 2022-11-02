
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_STAT_ASSESSMENT__H
#define DHAX_STAT_ASSESSMENT__H


#include <QString>

#include <QImage>

#include "accessors.h"


#ifdef USE_OpenCV

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/xfeatures2d/nonfree.hpp>

#include "opencv2/features2d/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

#endif

class DHAX_Stat_Assessment
{
 QString full_image_path_;
 QString gray_image_path_;
 QString one_channel_image_path_;
 QString one_channel_display_image_path_;

 QString algorithm_name_;

// typedef void (*proc_type) (DHAX_Stat_Assessment&);

// typedef std::function<void(DHAX_Stat_Assessment&)> proc_type;

 void (*proc_)(DHAX_Stat_Assessment&); // proc_;
 void (*follow_up_)(DHAX_Stat_Assessment&); // proc_;
// proc_type proc_;

 void* user_data_;

#ifdef USE_OpenCV

 cv::Mat full_image_;
 cv::Mat gray_image_;
 cv::Mat one_channel_image_;
 cv::Mat one_channel_display_image_;

#endif


public:

 DHAX_Stat_Assessment();


 ACCESSORS(QString ,full_image_path)
 ACCESSORS(QString ,gray_image_path)
 ACCESSORS(QString ,one_channel_image_path)
 ACCESSORS(QString ,one_channel_display_image_path)

 ACCESSORS(QString ,algorithm_name)

 ACCESSORS(void* ,user_data)


 ACCESSORS(cv::Mat ,full_image)
 ACCESSORS(cv::Mat ,gray_image)
 ACCESSORS(cv::Mat ,one_channel_image)
 ACCESSORS(cv::Mat ,one_channel_display_image)


 QString get_full_1c_out_path(QString name_extra);
 QString get_full_out_path(QString name_extra);
 QString get_1c_out_path(QString name_extra);

 QString get_full_out_path()
 {
  return get_full_out_path(algorithm_name_);
 }

 QString get_1c_out_path()
 {
  return get_1c_out_path(algorithm_name_);
 }

 QString get_full_1c_out_path()
 {
  return get_full_1c_out_path(algorithm_name_);
 }


 void run();

 void check_follow_up();

 ACCESSORS__FNP(void, DHAX_Stat_Assessment& ,proc)
 ACCESSORS__FNP(void, DHAX_Stat_Assessment& ,follow_up)

// ACCESSORS__SET_FNP(void, DHAX_Stat_Assessment& ,proc)
// ACCESSORS__GET_FNP(void, DHAX_Stat_Assessment& ,proc)

// void set_proc(void (*proc)(DHAX_Stat_Assessment&))
// {
//  proc_ = proc;
// }

// void (*get_proc(DHAX_Stat_Assessment&))()
// {
//  return proc_;
// }

// ACCESSORS(void (*)()  ,proc)
// ACCESSORS(proc_type ,proc)



 void load_images();

 static void run_demo_test(QString folder, QString base_file_name, QString extension);


};


#endif // DHAX_STAT_ASSESSMENT__H
