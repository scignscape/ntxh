
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-stat-assessment.h"

#include "image-editor/frontend/main-window-dialog.h"
#include "image-editor/frontend/MainWindow.h"

#include "image-editor/backend/CommandPattern/dhax/shear-command.h"
#include "image-editor/backend/CommandPattern/dhax/quantize-3x3-command.h"
#include "image-editor/backend/CommandPattern/dhax/heuristic-color-mask-command.h"

#include "feature-classifier-transform.h"



#include <QFileInfo>


DHAX_Stat_Assessment::DHAX_Stat_Assessment()
  :  user_data_(nullptr), proc_(nullptr),
     follow_up_(nullptr),
     feature_classifier_transform_(nullptr),
     xcsd_image_(nullptr)
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

 one_channel_display_image_ = cv::imread(one_channel_image_path_.toStdString());

 one_channel_dist_image_ = cv::imread(one_channel_dist_image_path_.toStdString(),
   cv::IMREAD_GRAYSCALE);

 one_channel_dist_display_image_ = cv::imread(one_channel_dist_display_image_path_.toStdString());


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

QString DHAX_Stat_Assessment::get_1c_out_path(QString name_extra)
{
 QString result = one_channel_image_path_;
 return result.replace("-1c", "-1c-" + name_extra);
}

QString DHAX_Stat_Assessment::get_full_out_path(QString name_extra)
{
 QString result = full_image_path_;
 return result.replace("-full", "-full-" + name_extra);
}

QString DHAX_Stat_Assessment::get_dist_1c_out_path(QString name_extra)
{
 QString result = one_channel_dist_image_path_;
 return result.replace("-1c", "-1c-" + name_extra);
}

QString DHAX_Stat_Assessment::get_full_dist_1c_out_path(QString name_extra)
{
 QString result = full_image_path_;
 return result.replace("-full", "-full-1cd-" + name_extra);
}


QString DHAX_Stat_Assessment::get_full_1c_oa_out_path(QString name_extra)
{
 QString result = full_image_path_;
 return result.replace("-full", "-full-1c-oa-" + name_extra);
}

QString DHAX_Stat_Assessment::get_full_oa_out_path(QString name_extra)
{
 QString result = full_image_path_;
 return result.replace("-full", "-full-oa-" + name_extra);
}

QString DHAX_Stat_Assessment::get_dist_1c_oa_out_path(QString name_extra)
{
 QString result = one_channel_dist_image_path_;
 return result.replace("-1c", "-1c-oa-" + name_extra);
}

void DHAX_Stat_Assessment::run_classifier_transform()
{
 if(!feature_classifier_transform_)
   return;

 typedef Main_Window_Dialog Image_Editor_Dialog_Window;

 QFileInfo qfi(full_image_path_);

 Image_Editor_Dialog_Window* dlg = new Image_Editor_Dialog_Window(nullptr);

 dlg->set_default_image_folder(qfi.absolutePath());
 dlg->set_default_image_file(full_image_path_);

 QImage& qim = dlg->get_active_image().getQImage();

 for(cv::KeyPoint kp : keypoints_1c_)
 {
  u2 x = kp.pt.x, y = kp.pt.y;
  QColor c = qim.pixelColor(x, y);
  c.setAlpha(254);
  qim.setPixelColor(x, y, c);
 }

 for(cv::KeyPoint kp : keypoints_full_)
 {
  u2 x = kp.pt.x, y = kp.pt.y;
  QColor c = qim.pixelColor(x, y);

  if(c.alpha() == 255)
    c.setAlpha(253);
  else
    c.setAlpha(252);

//  c.setAlpha(c.alpha() - 2);

//  if(c.alpha() < 252)
//  {
//   qDebug() << "c a: " << c.alpha();
//  }

  qim.setPixelColor(x, y, c);
 }


//? qim.save("/home/nlevisrael/gits/ctg-temp/dev/dhax-stats/temp.png");

// for(u2 y = 0; y < qim.height(); ++y)
//  for(u2 x = 0; x < qim.width(); ++x)
//  {
//   qim.pixel()
//  }

 //qim.setPixel()


// dlg->set_default_image_file(main_window_controller_->current_image_file_path());


// QVector<std::shared_ptr<ICommand>> cmds;
 QVector<Command_or_String> cmds;

 std::shared_ptr<ICommand> c1( new Shear_Command(dlg->get_active_image(),
   feature_classifier_transform_->horizontal_shear(),
   feature_classifier_transform_->horizontal_shear_centered(),
   feature_classifier_transform_->vertical_shear(),
   feature_classifier_transform_->vertical_shear_centered(),
   feature_classifier_transform_->horizontal_skew(),
   feature_classifier_transform_->vertical_skew(),
   feature_classifier_transform_->rotation()) );


 std::shared_ptr<ICommand> c2(
   new Heuristic_Color_Mask_Command(dlg->get_active_image(),
   feature_classifier_transform_->foreground_color(), Qt::white,
   feature_classifier_transform_->color_distance_threshold(),
   feature_classifier_transform_->color_distance_model()) );

 cmds.push_back(c1);

 if(feature_classifier_transform_->box_sizes().width == 27)
   cmds.push_back("quantize_27x27"_qt);

 cmds.push_back(c2);


 dlg->load_predefined_transforms(cmds);

 dlg->show();
 dlg->set_window_dimensions( QSize(full_image_.size[0], full_image_.size[1]) );

 QVector<QColor> colors;
 colors << Qt::cyan << Qt::yellow << Qt::green;

 dlg->run_predefined_transforms("/home/nlevisrael/gits/ctg-temp/dev/dhax-stats/temp-%1.png", colors);

//? dlg->show_alpha_codes(colors, "/home/nlevisrael/gits/ctg-temp/dev/dhax-stats/temp.png");


// dlg->set_window_dimensions(application_main_window_->size());

// return dlg;


}


