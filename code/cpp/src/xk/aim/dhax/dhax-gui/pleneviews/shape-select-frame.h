
#ifndef SHAPE_SELECT_FRAME__H
#define SHAPE_SELECT_FRAME__H

#include <QFrame>

#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QButtonGroup>

#include <QTabWidget>

#include "global-types.h"

class QLabel;


class Shape_Select_Frame : public QFrame
{
 Q_OBJECT

 QFrame* main_tab_;

 QFrame* clear_last_all_tab_;
 QFrame* image_setup_tab_;

 QTabWidget* main_tab_widget_;

 QPushButton* clear_selected_btn_;
 QPushButton* clear_last_btn_;
 QPushButton* clear_all_btn_;

 QVBoxLayout* main_layout_;
 //QVBoxLayout* main_tab_layout_;
 QGridLayout* main_tab_layout_;

 QVBoxLayout* clear_last_all_tab_layout_;

 QVBoxLayout* image_setup_tab_layout_;

 QLabel* image_path_label_;
 QLineEdit* image_path_line_edit_;
 QPushButton* image_path_show_folder_button_;
 QHBoxLayout* image_path_layout_;

 QLabel* vertical_margin_label_;

 QCheckBox* vertical_margin_percent_check_box_;
 QLabel* vertical_margin_percent_check_box_label_;

 QComboBox* vertical_margin_combo_box_;
 QHBoxLayout* vertical_margin_layout_;

 ComboBox_Data vertical_margin_combo_box_data_;

 QCheckBox* sides_margin_check_box_;
 QLabel* sides_margin_check_box_label_;
 QComboBox* sides_margin_combo_box_;

 ComboBox_Data sides_margin_combo_box_data_;

 QHBoxLayout* border_layout_;
 QLabel* border_label_;
 QComboBox* border_combo_box_;
 QLabel* border_color_label_;
 QPushButton* border_color_button_;

 QCheckBox* domain_shape_ckb_;
 QComboBox* domain_shape_options_;

 QCheckBox* generic_shape_ckb_;
 QComboBox* generic_shape_options_;

 QButtonGroup* shape_ckb_group_;

 // QString current_shape_selection_;

 QCheckBox* highlight_ckb_;

 QHBoxLayout* save_button_layout_;
 QCheckBox* auto_store_check_box_;
 QPushButton* store_button_;
 QPushButton* save_button_;
 QPushButton* close_button_;

 QPushButton* auto_store_config_button_;
 QPushButton* cloud_store_button_;
 QCheckBox* cloud_store_check_box_;

 QHBoxLayout* save_and_close_layout_;
 QVBoxLayout* save_layout_;
 QLabel* auto_store_label_;

 //struct
 template<typename OBJECT_Type>
 struct connector
 {
  //template<typename ...Args>
  template<typename ftype>
  struct slot_type
  {
   typedef ftype pmfn; //   (OBJECT_Type::*pmfn)(Args...);
   static pmfn get_pmfn(QString fname, pmfn add = nullptr)
   {
    static QMap<QString, pmfn> static_map;
    pmfn result = static_map.value(fname);
    if(add)
    {
     static_map[fname] = add;
    }
    return result;
   }
  };
  OBJECT_Type* obj;

  template<typename SOBJECT_Type, typename ...Args>
  static void add_pmfn(QString name, void (SOBJECT_Type::*add)(Args...))
  {
   //typedef void (SOBJECT_Type::*ft)(Args...);
   slot_type<void (OBJECT_Type::*)(Args...)>::get_pmfn(name, add);
  }

  //template<typename THIS_Type, typename FN_Type> //, typename ...ARGS>
  template<typename THIS_Type, typename ...Args>
  void Cnct(QString mfn, THIS_Type* _this, void(THIS_Type::*fn)(Args...) )
  {
   auto _mfn = slot_type<void(OBJECT_Type::*)(Args...)>::get_pmfn(mfn);
   //typename slot_type<bool>::pmfn _mfn
   //  = slot_type<bool>::get_pmfn(mfn);
   obj->connect(obj, _mfn, _this, fn);
  }
 };

 template<typename OBJECT_Type>
 connector<OBJECT_Type>
 Cc(OBJECT_Type* obj) { return {obj}; }

public:

 Shape_Select_Frame(QWidget* parent);

 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)


 QString current_shape_selection();

 void update_shape_selection();

 void update_border_color_button_color(QColor c);

 void switch_to_margins_percent();
 void switch_to_margins_non_percent();
 void populate_margins_non_percent(bool clear = false);

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

 void update_image_path(QString path, u4 page_number = 0);

Q_SIGNALS:

 void shape_selection_changed(QString new_selection);
 void save_requested(bool);
 void close_requested(bool);

 void image_path_show_folder_requested(bool);
 void change_border_color_requested(bool);

 void change_vertical_margin_percent_requested(u1, bool);
 void change_vertical_margin_requested(u1, bool);
 void new_vertical_margin_value_rescinded(u1);


};


#endif
