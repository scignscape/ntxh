
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-stat-assessment.h"

#include <QDir>


void DHAX_Stat_Assessment::run_demo_test(QString folder,
  QString base_file_name, QString extension)
{
#ifdef USE_OpenCV

 QDir qd(folder);

 QString full = qd.absoluteFilePath(base_file_name + "-full" + extension);
 QString one_channel = qd.absoluteFilePath(base_file_name + "-1c" + extension);
 QString one_channel_display = qd.absoluteFilePath(base_file_name + "-1cd" + extension);

 std::shared_ptr<DHAX_Stat_Assessment> AKAZE_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> SIFT_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> BRISK_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> ORB_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> SURF_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> USURF_stat( new DHAX_Stat_Assessment );

 AKAZE_stat->set_full_image_path(full);
 AKAZE_stat->set_one_channel_image_path(one_channel);
 AKAZE_stat->set_one_channel_display_image_path(one_channel_display);

 SIFT_stat->set_full_image_path(full);
 SIFT_stat->set_one_channel_image_path(one_channel);
 SIFT_stat->set_one_channel_display_image_path(one_channel_display);

 BRISK_stat->set_full_image_path(full);
 BRISK_stat->set_one_channel_image_path(one_channel);
 BRISK_stat->set_one_channel_display_image_path(one_channel_display);

 ORB_stat->set_full_image_path(full);
 ORB_stat->set_one_channel_image_path(one_channel);
 ORB_stat->set_one_channel_display_image_path(one_channel_display);

 SURF_stat->set_full_image_path(full);
 SURF_stat->set_one_channel_image_path(one_channel);
 SURF_stat->set_one_channel_display_image_path(one_channel_display);

 USURF_stat->set_full_image_path(full);
 USURF_stat->set_one_channel_image_path(one_channel);
 USURF_stat->set_one_channel_display_image_path(one_channel_display);

 AKAZE_stat->set_proc([](DHAX_Stat_Assessment& stat)
 {
  cv::Ptr<cv::FeatureDetector> detector;
  cv::Ptr<cv::DescriptorExtractor> descriptor;
  stat.load_images();

  detector = cv::AKAZE::create();
  descriptor = cv::AKAZE::create();

  cv::Mat image_full, out_full, image_1c, out_1c;
  std::vector<cv::KeyPoint> keypoints_full, keypoints_1c;

  detector->detectAndCompute(stat.gray_image_, cv::noArray(), keypoints_full, image_full);
  cv::drawKeypoints(stat.full_image_, keypoints_full, out_full, cv::Scalar(0, 255, 0));
//  cv::imwrite("/home/nlevisrael/gits/im-cv/i4/images/AKAZE-result.jpg", _out);

  detector->detectAndCompute(stat.one_channel_image_, cv::noArray(), keypoints_full, image_1c);
  cv::drawKeypoints(stat.one_channel_display_image_,
     keypoints_full, out_1c, cv::Scalar(0, 255, 0));
//  cv::imwrite("/home/nlevisrael/gits/im-cv/i4/images/AKAZE-result.jpg", _out);

 });

//   AKAZE_detector = cv::AKAZE::create();
//   SIFT_detector = cv::SIFT::create(); //?min
//   BRISK_detector = cv::BRISK::create();
//   ORB_detector = cv::ORB::create(2000);
//   SURF_detector = cv::xfeatures2d::SURF::create();
//   USURF_detector = cv::xfeatures2d::SURF::create();


#endif
}
