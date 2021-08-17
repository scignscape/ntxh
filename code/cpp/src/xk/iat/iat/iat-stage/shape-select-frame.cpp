
#include "shape-select-frame.h"

#include <QDebug>


Shape_Select_Frame::Shape_Select_Frame(QWidget* parent)
  :  QFrame(parent)
{
 main_tab_ = new QFrame(this);
 clear_last_all_tab_ = new QFrame(this);

 main_tab_widget_ = new QTabWidget(this);

 main_tab_widget_->addTab(main_tab_, "Notes");
 main_tab_widget_->addTab(clear_last_all_tab_, "Editing ...");


 clear_selected_btn_ = new QPushButton("Clear Selected", this);
 clear_last_btn_ = new QPushButton("Clear Last", this);
 clear_all_btn_ = new QPushButton("Clear All", this);

 clear_last_btn_->setEnabled(false);
 clear_all_btn_->setEnabled(false);

 main_tab_layout_ = new QVBoxLayout;
 main_layout_ = new QVBoxLayout;

 domain_shape_options_ = new QComboBox(this);
 domain_shape_options_->addItem("select ...");
 domain_shape_options_->addItem("Pipes");
 domain_shape_options_->addItem("Lighting");
 domain_shape_options_->addItem("Devices");

 domain_shape_options_->setCurrentText("select ...");

 domain_shape_ckb_ = new QCheckBox("Registered Marking", this);
  main_tab_layout_->addWidget(domain_shape_ckb_);
  main_tab_layout_->addWidget(domain_shape_options_);

 shape_ckb_group_ = new QButtonGroup(this);

 shape_ckb_group_->setExclusive(true);
 shape_ckb_group_->addButton(domain_shape_ckb_);

 connect(domain_shape_options_, &QComboBox::currentTextChanged,
   [this] {update_shape_selection();});

 main_tab_layout_->addStretch();

 generic_shape_options_ = new QComboBox(this);
 generic_shape_options_->addItem("Rectangle");
 generic_shape_options_->addItem("Ellipse");
 generic_shape_options_->addItem("Polygon");
 generic_shape_options_->addItem("N_A");

 connect(generic_shape_options_, &QComboBox::currentTextChanged,
   [this] {update_shape_selection();});


 generic_shape_ckb_ = new QCheckBox("Generic Shape", this);
 main_tab_layout_->addWidget(generic_shape_ckb_);
 main_tab_layout_->addWidget(generic_shape_options_);

 shape_ckb_group_->addButton(generic_shape_ckb_);

 generic_shape_ckb_->setChecked(true);

 connect(shape_ckb_group_, &QButtonGroup::idClicked,
   [this](int id)
 {
  int ii = -2 - id;
  if(ii) // generic
  {
   generic_shape_options_->setEnabled(true);
   domain_shape_options_->setEnabled(false);
  }
  else
  {
   generic_shape_options_->setEnabled(false);
   domain_shape_options_->setEnabled(true);
  }
  update_shape_selection();
 });

 domain_shape_options_->setEnabled(false);

 main_tab_->setLayout(main_tab_layout_);

 clear_last_all_tab_layout_ = new QVBoxLayout;

 //main_layout_->addStretch();

 clear_last_all_tab_layout_->addWidget(clear_selected_btn_);

 QHBoxLayout* clear_last_all_layout = new QHBoxLayout;
 clear_last_all_layout->addWidget(clear_last_btn_);
 clear_last_all_layout->addWidget(clear_all_btn_);

 clear_last_all_tab_layout_->addLayout(clear_last_all_layout);

 highlight_ckb_ = new QCheckBox("Highlight", this);
 clear_last_all_tab_layout_->addWidget(highlight_ckb_);

 clear_last_all_tab_->setLayout(clear_last_all_tab_layout_);

 main_layout_->addWidget(main_tab_widget_);

 setLayout(main_layout_);

 setMaximumWidth(190);
 setMaximumHeight(190);

}


void Shape_Select_Frame::update_shape_selection()
{
 QString sel = current_shape_selection();
 emit shape_selection_changed(sel);
}


QString Shape_Select_Frame::current_shape_selection()
{
 if(domain_shape_options_->isEnabled())
 {
  if(domain_shape_options_->currentText() == "select ...")
    return "N_A";
  return domain_shape_options_->currentText();
 }
 return generic_shape_options_->currentText();
}



