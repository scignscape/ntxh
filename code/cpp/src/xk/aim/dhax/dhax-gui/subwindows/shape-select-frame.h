
#ifndef SHAPE_SELECT_FRAME__H
#define SHAPE_SELECT_FRAME__H

#include <QFrame>

#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QButtonGroup>

#include <QTabWidget>


class Shape_Select_Frame : public QFrame
{
 Q_OBJECT

 QFrame* main_tab_;
 QFrame* clear_last_all_tab_;

 QTabWidget* main_tab_widget_;

 QPushButton* clear_selected_btn_;
 QPushButton* clear_last_btn_;
 QPushButton* clear_all_btn_;

 QVBoxLayout* main_layout_;
 QVBoxLayout* main_tab_layout_;

 QVBoxLayout* clear_last_all_tab_layout_;

 QCheckBox* domain_shape_ckb_;
 QComboBox* domain_shape_options_;

 QCheckBox* generic_shape_ckb_;
 QComboBox* generic_shape_options_;

 QButtonGroup* shape_ckb_group_;

 // QString current_shape_selection_;

 QCheckBox* highlight_ckb_;

 QHBoxLayout* save_button_layout_;
 QPushButton* save_button_;
 QPushButton* close_button_;

public:

 Shape_Select_Frame(QWidget* parent);

 QString current_shape_selection();

 void update_shape_selection();

 void set_clear_selected_btn_disabled()
 {
  clear_selected_btn_->setDisabled(true);
 }
 void set_clear_selected_btn_enabled()
 {
  clear_selected_btn_->setEnabled(true);
 }

 void set_clear_last_btn_disabled()
 {
  clear_last_btn_->setDisabled(true);
 }
 void set_clear_last_btn_enabled()
 {
  clear_last_btn_->setDisabled(false);
 }

 void set_clear_all_btn_disabled()
 {
  clear_last_btn_->setDisabled(true);
 }
 void set_clear_all_btn_enabled()
 {
  clear_last_btn_->setDisabled(false);
 }

 void set_highlight_ckb_disabled()
 {
  highlight_ckb_->setDisabled(true);
 }
 void set_highlight_ckb_enabled()
 {
  highlight_ckb_->setDisabled(false);
 }

 bool clear_selected_btn_is_enabled()
 {
  return clear_selected_btn_->isEnabled();
 }

 bool clear_last_btn_is_enabled()
 {
  return clear_last_btn_->isEnabled();
 }

 bool clear_all_btn_is_enabled()
 {
  return clear_all_btn_->isEnabled();
 }


Q_SIGNALS:

 void shape_selection_changed(QString new_selection);
 void save_requested(bool);
 void close_requested(bool);

};


#endif
