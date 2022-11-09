
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "run-transforms-dialog.h"

#include "image-editor/backend/Image.h"

#include "styles.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

#include <QPainter>


#include "QtColorWidgets/color_dialog.hpp"


#include "global-types.h"


Run_Transforms_Dialog::Run_Transforms_Dialog(QImage& base_image, QString file_path_pattern,
  u1 step_total, u1 overlay_cut, QWidget* parent)
  :  QDialog(parent), base_image_(base_image), file_path_pattern_(file_path_pattern),
     overlay_cut_(overlay_cut), step_total_(step_total), step_count_(0)
{
// setStyleSheet("QLabel{font-size:10pt;}"
//   "QLineEdit{font-size:10pt;}"
//   "QSpinBox{font-size:10pt;}"
//               );


 main_layout_ = new QHBoxLayout;

 show_feature_points_check_box_ = new QCheckBox("Show Feature Points", this);
 forward_button_ = new QPushButton("Next", this);
 cancel_button_ = new QPushButton("Cancel", this);

 forward_button_->setMaximumHeight(20);

 cancel_button_->setStyleSheet(basic_button_style_sheet_());

 main_layout_->addWidget(show_feature_points_check_box_);
 main_layout_->addWidget(forward_button_);
 main_layout_->addWidget(cancel_button_);

 connect(cancel_button_, &QPushButton::clicked, [this]
 {
  close();
 });

 connect(show_feature_points_check_box_, &QCheckBox::stateChanged, [this] (int state)
 {
  if(state == 0)
    Q_EMIT unshow_features_requested();

  else
    Q_EMIT show_features_requested();
 });

 connect(forward_button_, &QPushButton::clicked, [this]
 {
  ++step_count_;
  Q_EMIT next_step_requested(step_count_, show_feature_points_check_box_->isChecked());
  if(step_count_ == step_total_)
  {
   forward_button_->setEnabled(false);
   cancel_button_->setText("Close");
   Q_EMIT sequence_finished();
  }
 });

 setLayout(main_layout_);
}


QPixmap Run_Transforms_Dialog::get_pixmap_with_overlays()
{
 if(overlay_image_.isNull())
 {
  overlay_image_ = base_image_.copy();
  Image::show_alpha_codes(feature_points_colors_, overlay_image_); // file_path_pattern.arg(count));
 }

 return QPixmap::fromImage(overlay_image_);
}


void Run_Transforms_Dialog::save_step_image_prelim()
{
 if(feature_points_colors_.isEmpty())
   base_image_.save(file_path_pattern_.arg(step_count_));
 else
 {
  QImage qim = base_image_.copy();
  Image::show_alpha_codes(feature_points_colors_, qim); // file_path_pattern.arg(count));
  qim.save(file_path_pattern_.arg(step_count_));
 }
}


void Run_Transforms_Dialog::save_step_image()
{
 if(feature_points_colors_.isEmpty())
   base_image_.save(file_path_pattern_.arg(step_count_));
 else
 {
  QImage* overlay_source_image = nullptr;

  if(step_count_ == overlay_cut_)
  {
   overlay_cut_image_ = base_image_.copy();
   overlay_image_ = overlay_cut_image_.copy();
//?     overlay_image = &qim;
  }
  else
  {
   overlay_image_ = base_image_.copy();
   if(step_count_ > overlay_cut_)
     overlay_source_image = &overlay_cut_image_;
  }
  qDebug() << "Showing alpha codes: " << step_count_;
  Image::show_alpha_codes(feature_points_colors_, overlay_image_, overlay_source_image);
  overlay_image_.save(file_path_pattern_.arg(step_count_));

 }

}

