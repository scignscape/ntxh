
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef RUN_TRANSFORMS_DIALOG__H
#define RUN_TRANSFORMS_DIALOG__H


#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QImage>
#include <QVector>
#include <QColor>

#include "global-types.h"

#include "accessors.h"


class Run_Transforms_Dialog : public QDialog
{
 Q_OBJECT

 QCheckBox* show_feature_points_check_box_;
 QPushButton* forward_button_;
 QPushButton* cancel_button_;

 QHBoxLayout* main_layout_;

 u1 step_count_;
 u1 step_total_;

 u1 overlay_cut_;

 QVector<QColor> feature_points_colors_;
 QString file_path_pattern_;

 QImage& base_image_;

 QImage overlay_cut_image_;
 QImage overlay_image_;

public:

 Run_Transforms_Dialog(QImage& base_image, QString file_path_pattern,
   u1 step_total, u1 overlay_cut, QWidget* parent = nullptr);

 ACCESSORS(QVector<QColor> ,feature_points_colors)

 void save_step_image_prelim();
 void save_step_image();

 QPixmap get_pixmap_with_overlays();

Q_SIGNALS:

 void sequence_finished();
 void next_step_requested(u1 count);

 void unshow_features_requested();
 void show_features_requested();


};

#endif //  RUN_TRANSFORMS_DIALOG__H
