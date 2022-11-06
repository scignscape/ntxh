
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-stat-assessment.h"

#include <QDebug>

#include <QDir>


//void ((*_make_run_0d))(DHAX_Stat_Assessment&)

//typedef void(*_make_run_0d_type)(DHAX_Stat_Assessment&);
//_make_run_0d_type _make_run_0d()
//void ((*_make_run_0d)(DHAX_Stat_Assessment&))()


//


template<cv::RetrievalModes rm, cv::ContourApproximationModes cam>
void (*_make_run_contours())(DHAX_Stat_Assessment&)
{
 return [](DHAX_Stat_Assessment& stat)
 {
  stat.load_images();

  cv::Mat threshold_full, threshold_1c, threshold_dist_1c;
  cv::threshold(stat.gray_image(), threshold_full, 200, 255, cv::THRESH_BINARY);
  cv::threshold(stat.one_channel_image(), threshold_1c, 200, 255, cv::THRESH_BINARY);
  cv::threshold(stat.one_channel_dist_image(), threshold_dist_1c, 200, 255, cv::THRESH_BINARY);

  cv::Mat copy_full = stat.full_image().clone();

  cv::Mat copy_1c = stat.one_channel_display_image().clone();

  cv::Mat copy_full_1c = stat.full_image().clone();

  cv::Mat copy_full_dist_1c = stat.full_image().clone();
//  cv::Mat copy_dist_1c = stat.one_channel_dist_image().clone();
  cv::Mat copy_dist_1cd = stat.one_channel_dist_display_image().clone();

  std::vector<std::vector<cv::Point>> contours_full, contours_1c, contours_dist_1c;
  std::vector<cv::Vec4i> hierarchy_full, hierarchy_1c, hierarchy_dist_1c;

  findContours(threshold_full, contours_full, hierarchy_full,
    rm, cam); //cv::CHAIN_APPROX_NONE);
  findContours(threshold_1c, contours_1c, hierarchy_1c,
    rm, cam); //, cv::CHAIN_APPROX_NONE);
  findContours(threshold_dist_1c, contours_dist_1c, hierarchy_dist_1c,
    rm, cam); //, cv::CHAIN_APPROX_NONE);

  static auto less_than = [](std::vector<cv::Point>& lhs,
    std::vector<cv::Point>& rhs)
  {
   return lhs.size() < rhs.size();
  };

  auto it_full = std::max_element(contours_full.begin(), contours_full.end(), less_than);

  auto it_1c = std::max_element(contours_1c.begin(), contours_1c.end(), less_than);

  auto it_dist_1c = std::max_element(contours_dist_1c.begin(), contours_dist_1c.end(), less_than);


  std::vector<cv::Point>& max_full = *it_full;
  std::vector<cv::Point>& max_1c = *it_1c;
  std::vector<cv::Point>& max_dist_1c = *it_dist_1c;

  qDebug() << "max = " << max_full.size();
  qDebug() << "max 1c = " << max_1c.size();
  qDebug() << "max dist 1c = " << max_dist_1c.size();

  std::vector<std::vector<cv::Point>> larger_contours_full,
    larger_contours_1c, larger_contours_dist_1c;

  std::vector<std::vector<cv::Point>> largest_contours_full,
    largest_contours_1c, largest_contours_dist_1c;

  std::vector<std::vector<cv::Point>> smaller_contours_full,
    smaller_contours_1c, smaller_contours_dist_1c;

  largest_contours_full.push_back(max_full);
  largest_contours_1c.push_back(max_1c);
  largest_contours_dist_1c.push_back(max_dist_1c);

  for(size_t i = 0;  i < contours_full.size(); ++i)
  {
   if(contours_full[i].size() > (max_full.size() / 2))
     larger_contours_full.push_back(contours_full[i]);

   else
     smaller_contours_full.push_back(contours_full[i]);

  }

  for(size_t i = 0;  i < contours_1c.size(); ++i)
  {
   if(contours_1c[i].size() > (max_1c.size() / 2))
     larger_contours_1c.push_back(contours_1c[i]);

   else
     smaller_contours_1c.push_back(contours_1c[i]);
  }

  for(size_t i = 0;  i < contours_dist_1c.size(); ++i)
  {
   if(contours_dist_1c[i].size() > (max_dist_1c.size() / 2))
     larger_contours_dist_1c.push_back(contours_dist_1c[i]);

   else
     smaller_contours_dist_1c.push_back(contours_dist_1c[i]);
  }


  drawContours(copy_full, smaller_contours_full, -1, cv::Scalar(255, 0, 0), 1);
  drawContours(copy_full_1c, smaller_contours_1c, -1, cv::Scalar(255, 0, 0), 1);
  drawContours(copy_1c, smaller_contours_1c, -1, cv::Scalar(255, 0, 0), 1);
  drawContours(copy_dist_1cd, smaller_contours_dist_1c, -1, cv::Scalar(255, 0, 0), 1);
  drawContours(copy_full_dist_1c, smaller_contours_dist_1c, -1, cv::Scalar(255, 0, 0), 1);


  drawContours(copy_full, larger_contours_full, -1, cv::Scalar(0, 255, 0), 2);
  drawContours(copy_full_1c, larger_contours_1c, -1, cv::Scalar(0, 255, 0), 2);
  drawContours(copy_1c, larger_contours_1c, -1, cv::Scalar(0, 255, 0), 2);
  drawContours(copy_dist_1cd, larger_contours_dist_1c, -1, cv::Scalar(0, 255, 0), 2);
  drawContours(copy_full_dist_1c, larger_contours_dist_1c, -1, cv::Scalar(0, 255, 0), 2);


  drawContours(copy_full, largest_contours_full, -1, cv::Scalar(0, 0, 255), 3);
  drawContours(copy_full_1c, largest_contours_1c, -1, cv::Scalar(0, 0, 255), 3);
  drawContours(copy_1c, largest_contours_1c, -1, cv::Scalar(0, 0, 255), 3);
  drawContours(copy_dist_1cd, largest_contours_dist_1c, -1, cv::Scalar(0, 0, 255), 3);
  drawContours(copy_full_dist_1c, largest_contours_dist_1c, -1, cv::Scalar(0, 0, 255), 3);

  cv::imwrite(stat.get_full_out_path().toStdString(), copy_full);
  cv::imwrite(stat.get_full_1c_out_path().toStdString(), copy_full_1c);
  cv::imwrite(stat.get_1c_out_path().toStdString(), copy_1c);

  cv::imwrite(stat.get_dist_1c_out_path().toStdString(), copy_dist_1cd);
  cv::imwrite(stat.get_full_dist_1c_out_path().toStdString(), copy_dist_1cd);


 // drawContours(image_copy, {max}, -1, cv::Scalar(0, 255, 0), 2);
 // // drawContours(image_copy, contours, -1, cv::Scalar(0, 255, 0), 2);
 // imwrite("contours_filter_image1.jpg", image_copy);

 };
}

template<typename ALGORITHM_Type>
void (*_make_run_0d())(DHAX_Stat_Assessment&)
{
 return [](DHAX_Stat_Assessment& stat)
 {
  cv::Ptr<cv::FeatureDetector> detector;
  cv::Ptr<cv::DescriptorExtractor> descriptor;
  stat.load_images();

  detector = ALGORITHM_Type::create();
  descriptor = ALGORITHM_Type::create();

//  stat.set_user_data(detector.get());
  stat.set_user_data(detector.get());
  stat.check_follow_up();

//  if(stat.get_follow_up())
//  {
//   qDebug() << "Upright ...";
//   detector.staticCast<cv::xfeatures2d::SURF>()->setUpright(true);
//  }

//#ifdef _make_run_0d_UPRIGHT
//  qDebug() << "Upright ..."
//  detector.staticCast<cv::xfeatures2d::SURF>()->setUpright(true);
//#endif

  cv::Mat image_full, out_full, image_1c, out_1c, image_dist_1c, out_dist_1c, out_full_dist_1c;
  std::vector<cv::KeyPoint> keypoints_full, keypoints_1c, keypoints_dist_1c;

  detector->detectAndCompute(stat.gray_image(), cv::noArray(), keypoints_full, image_full);
  cv::drawKeypoints(stat.full_image(),
    keypoints_full, out_full, cv::Scalar(0, 255, 0));
  cv::imwrite(stat.get_full_out_path().toStdString(), out_full);
//?  cv::imwrite(stat.get_full_oa_out_path().toStdString(), image_full);

  detector->detectAndCompute(stat.one_channel_image(), cv::noArray(), keypoints_1c, image_1c);
  cv::drawKeypoints(stat.full_image(),
     keypoints_1c, out_1c, cv::Scalar(0, 255, 0));
  cv::imwrite(stat.get_full_1c_out_path().toStdString(), out_1c);
//?  cv::imwrite(stat.get_full_1c_oa_out_path().toStdString(), image_1c);

  detector->detectAndCompute(stat.one_channel_dist_image(), cv::noArray(), keypoints_dist_1c,
    image_dist_1c);
  cv::drawKeypoints(stat.full_image(),
     keypoints_dist_1c, out_dist_1c, cv::Scalar(0, 255, 0));
  cv::imwrite(stat.get_dist_1c_out_path().toStdString(), out_dist_1c);
//?  cv::imwrite(stat.get_dist_1c_oa_out_path().toStdString(), image_dist_1c);


  cv::drawKeypoints(stat.full_image(),
     keypoints_dist_1c, out_full_dist_1c, cv::Scalar(0, 255, 0));
  cv::imwrite(stat.get_full_dist_1c_out_path().toStdString(), out_full_dist_1c);

//  cv::imwrite("/home/nlevisrael/gits/im-cv/i4/images/AKAZE-result.jpg", _out);

 };
}



void DHAX_Stat_Assessment::run_demo_test(QString folder,
  QString base_file_name, QString extension)
{
#ifdef USE_OpenCV

 QDir qd(folder);

 QString full = qd.absoluteFilePath(base_file_name + "-full." + extension);
 QString one_channel_dist = qd.absoluteFilePath(base_file_name + "-dist-1c." + extension);
 QString one_channel_dist_display = qd.absoluteFilePath(base_file_name + "-1cd." + extension);

 QString one_channel_fb = qd.absoluteFilePath(base_file_name + ".fb-1c." + extension);

 std::shared_ptr<DHAX_Stat_Assessment> AKAZE_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> SIFT_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> BRISK_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> ORB_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> SURF_stat( new DHAX_Stat_Assessment );
 std::shared_ptr<DHAX_Stat_Assessment> USURF_stat( new DHAX_Stat_Assessment );

 std::shared_ptr<DHAX_Stat_Assessment> RETR_TREE_CHAIN_APPROX_NONE_stat( new DHAX_Stat_Assessment );

// AKAZE_stat->set_full_image_path(full);
// AKAZE_stat->set_one_channel_image_path(one_channel);
// AKAZE_stat->set_one_channel_display_image_path(one_channel_display);

// SIFT_stat->set_full_image_path(full);
// SIFT_stat->set_one_channel_image_path(one_channel);
// SIFT_stat->set_one_channel_display_image_path(one_channel_display);

// BRISK_stat->set_full_image_path(full);
// BRISK_stat->set_one_channel_image_path(one_channel);
// BRISK_stat->set_one_channel_display_image_path(one_channel_display);

// ORB_stat->set_full_image_path(full);
// ORB_stat->set_one_channel_image_path(one_channel);
// ORB_stat->set_one_channel_display_image_path(one_channel_display);

// SURF_stat->set_full_image_path(full);
// SURF_stat->set_one_channel_image_path(one_channel);
// SURF_stat->set_one_channel_display_image_path(one_channel_display);

// USURF_stat->set_full_image_path(full);
// USURF_stat->set_one_channel_image_path(one_channel);
// USURF_stat->set_one_channel_display_image_path(one_channel_display);

#define setup(ALGORITHM_NAME) \
 ALGORITHM_NAME##_stat->set_full_image_path(full); \
 ALGORITHM_NAME##_stat->set_one_channel_image_path(one_channel_fb); \
 ALGORITHM_NAME##_stat->set_one_channel_dist_image_path(one_channel_dist); \
 ALGORITHM_NAME##_stat->set_one_channel_dist_display_image_path(one_channel_dist_display); \
 ALGORITHM_NAME##_stat->set_algorithm_name(#ALGORITHM_NAME); \


#define make_0d_proc(ALGORITHM) \
 setup(ALGORITHM) \
 ALGORITHM##_stat->set_proc(_make_run_0d<cv::ALGORITHM>()); \

#define make_0d_xproc(ALGORITHM) \
 setup(ALGORITHM) \
 ALGORITHM##_stat->set_proc(_make_run_0d<cv::xfeatures2d::ALGORITHM>()); \

#define make_0d_uxproc(ALGORITHM) \
 setup(U##ALGORITHM) \
 U##ALGORITHM##_stat->set_proc(_make_run_0d<cv::xfeatures2d::ALGORITHM>()); \


#define make_contours_proc(retrievalModes, contourApproximationModes)  \
 setup(retrievalModes ##_## contourApproximationModes) \
 retrievalModes ##_## contourApproximationModes ##_stat  \
   ->set_proc(_make_run_contours<cv::retrievalModes, \
     cv::contourApproximationModes>()); \


 make_0d_proc(AKAZE)
 AKAZE_stat->run();

 make_0d_proc(SIFT)
 SIFT_stat->run();

 make_0d_proc(BRISK)
 BRISK_stat->run();

 make_0d_proc(ORB)
 ORB_stat->run();

 make_0d_xproc(SURF)
 SURF_stat->run();

 make_0d_uxproc(SURF)
 USURF_stat->set_follow_up([](DHAX_Stat_Assessment& stat)
 {
  qDebug() << "setting upright ";
  (static_cast<cv::xfeatures2d::SURF*>(stat.user_data()))->setUpright(true);
 });
 USURF_stat->run();

 make_contours_proc(RETR_TREE, CHAIN_APPROX_NONE);
 RETR_TREE_CHAIN_APPROX_NONE_stat->run();

// CHAIN_APPROX_NONE_stat->set_proc(_make_run_contours<cv::CHAIN_APPROX_NONE>());


#undef make_0d_proc
#undef make_0d_xproc
#undef make_0d_uxproc

#undef make_contours_proc
#undef setup

//   AKAZE_detector = cv::AKAZE::create();
//   SIFT_detector = cv::SIFT::create(); //?min
//   BRISK_detector = cv::BRISK::create();
//   ORB_detector = cv::ORB::create(2000);
//   SURF_detector = cv::xfeatures2d::SURF::create();
//   USURF_detector = cv::xfeatures2d::SURF::create();


#endif
}
