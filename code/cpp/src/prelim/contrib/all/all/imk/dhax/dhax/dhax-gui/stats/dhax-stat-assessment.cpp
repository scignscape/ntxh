
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-stat-assessment.h"

#include "image-editor/frontend/main-window-dialog.h"
#include "image-editor/frontend/MainWindow.h"

#include "image-editor/backend/CommandPattern/dhax/shear-command.h"
#include "image-editor/backend/CommandPattern/dhax/quantize-3x3-command.h"

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


 cmds.push_back(c1);

 if(feature_classifier_transform_->box_sizes().width == 27)
   cmds.push_back("quantize_27x27"_qt);

 dlg->load_predefined_transforms(cmds);

 dlg->show();
 dlg->set_window_dimensions( QSize(full_image_.size[0], full_image_.size[1]) );

 dlg->run_predefined_transforms();

// dlg->set_window_dimensions(application_main_window_->size());

// return dlg;


}


