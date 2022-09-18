
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)



#ifndef NAV_LING_1D_PANEL__H
#define NAV_LING_1D_PANEL__H

#include <QObject>

#include <QMetaType>

#include <QList>
#include <QGraphicsScene>
#include <QPoint>

#include <QDialog>

#include <QFrame>



#include "accessors.h"
#include "qsns.h"


class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QTabWidget;
class QTextEdit;
class QFrame;
class QHBoxLayout;
class QVBoxLayout;
class QSlider;
class QPlainTextEdit;
class QBoxLayout;
class QButtonGroup;
class QGroupBox;
class QScrollArea;
class QGridLayout;


class ScignStage_Clickable_Label;
class ScignStage_Image_Tile;


class NAV_Ling1D_Panel : public QFrame
{
 Q_OBJECT

 QVBoxLayout* main_layout_;
 QHBoxLayout* navigation_layout_;

 ScignStage_Image_Tile* current_sample_;

 QPushButton* filtered_up_button_;
 QPushButton* filtered_down_button_;

 QPushButton* sample_up_button_;
 QPushButton* sample_down_button_;

 QPushButton* peer_up_button_;
 QPushButton* peer_down_button_;

 QPushButton* section_up_button_;
 QPushButton* section_down_button_;

 QPushButton* section_start_button_;
 QPushButton* section_end_button_;

 QVBoxLayout* first_auto_expand_layout_;

 QLabel* first_label_;
 QPushButton* sample_first_button_;

 QLabel* auto_expand_label_;
 QPushButton* auto_expand_button_;

 QHBoxLayout* first_layout_;
 QVBoxLayout* auto_expand_layout_;


 QVBoxLayout* filter_up_down_layout_;
 QGroupBox* filter_up_down_group_box_;
 QButtonGroup* filter_up_down_button_group_;

 QVBoxLayout* example_up_down_layout_;
 QGroupBox* example_up_down_group_box_;
 QButtonGroup* example_up_down_button_group_;

 QVBoxLayout* peer_up_down_layout_;
 QGroupBox* peer_up_down_group_box_;
 QButtonGroup* peer_up_down_button_group_;


 QVBoxLayout* section_up_down_layout_;
 QGroupBox* section_up_down_group_box_;
 QButtonGroup* section_up_down_button_group_;

 QVBoxLayout* section_se_layout_;
 QGroupBox* section_se_group_box_;
 QButtonGroup* section_se_button_group_;

public:

 NAV_Ling1D_Panel(int vmn, int vmx, int v, QWidget* parent = nullptr);

 ~NAV_Ling1D_Panel();

 void set_sample_text(int r);

Q_SIGNALS:

 void canceled(QDialog*);
 void accepted(QDialog*);

 void volume_change_requested(int);

 void zoom_in_requested();
 void zoom_out_requested();
 void scale_ratio_change_requested(qreal ratio);

 void peer_up_requested();
 void peer_down_requested();

 void filtered_up_requested();
 void filtered_down_requested();

 void section_up_requested();
 void section_down_requested();

 void section_start_requested();
 void section_end_requested();

 void sample_up_requested();
 void sample_down_requested();
 void sample_first_requested();

 void auto_expand_changed(bool);

//?public Q_SLOTS:

};


#endif  // NAV_Ling_1D_PANEL__H



