
#ifndef EDGE_DETECTION_DIALOG__H
#define EDGE_DETECTION_DIALOG__H

#include <QDialog>
#include <QtWidgets>

#include "edge-detection-kernels.h"

#include "global-types.h"


#include "self-connect.h"


//namespace Ui {
//class Edge_Detection_Dialog;
//}

class Edge_Detection_Dialog : public QDialog
{
 Q_OBJECT

 QVBoxLayout* main_layout_;
 QGroupBox* view_group_box_;

 QHBoxLayout* view_group_box_layout_;

 QPushButton* select_image_button_;
 QComboBox* view_combo_box_;
 QLabel* view_combo_box_label_;

 QVBoxLayout* check_box_layout_;
 QCheckBox* blur_check_box_;
 QCheckBox* fb_poles_check_box_;

 QPushButton* save_button_;
 QPushButton* close_button_;
 QGraphicsView* image_;


 //Ui::Edge_Detection_Dialog* ui;

 QImage original_, grayscale_, current_;
 QString filename_;
 QGraphicsScene* scene_;
 u1 blur_factor_;

 QColor background_pole_, foreground_pole_;

 void display(const QImage&);
 void resizeEvent(QResizeEvent*);

 void retranslateUi();

 void set_view_box_title(QString file_path);

 void load_file(QString file_path);


public:

 explicit Edge_Detection_Dialog(QString file_path, QWidget* parent = nullptr);
 Edge_Detection_Dialog(QString file_path, QColor background_pole, QColor foreground_pole, QWidget* parent = nullptr);


 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)


 ~Edge_Detection_Dialog();

private Q_SLOTS:
 void on_select_image_button_clicked(bool);
 void on_view_combo_box_currentIndexChanged(int index);

 void on_save_button_clicked(bool);

};


#endif // EDGE_DETECTION_DIALOG__H
