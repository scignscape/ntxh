
#include "shape-select-frame.h"

#include "styles.h"

#include "stash-signals.h"
#include "self-connect.h"


#include <QDebug>

#include <QStandardItemModel>
#include <QStandardItem>
#include <QLabel>
#include <QLineEdit>

#include <QPushButton>



Shape_Select_Frame::Shape_Select_Frame(QWidget* parent)
  :  QFrame(parent)
{
 QString _button_style_sheet = light_small_button_style_sheet_();
 auto button_style_sheet = [_button_style_sheet](u1 sz = 8)
 {
  return _button_style_sheet.arg(sz);
 };

 main_tab_ = new QFrame(this);
 clear_last_all_tab_ = new QFrame(this);
 image_setup_tab_ = new QFrame(this);

 main_tab_->setContentsMargins(0,0,0,0);

//  main_tab_->setMaximumHeight(100);


 main_tab_widget_ = new QTabWidget(this);

 main_tab_widget_->addTab(main_tab_, "Notes");
 main_tab_widget_->addTab(image_setup_tab_, "Image");
 main_tab_widget_->addTab(clear_last_all_tab_, "Editing");


 image_setup_tab_layout_ = new QVBoxLayout;

 image_path_label_ = new QLabel("Path", this);
 image_path_line_edit_ = new QLineEdit(this);
 image_path_line_edit_->setReadOnly(true);
 //image_path_line_edit_->setMaximumWidth(90);
 image_path_show_folder_button_ = new QPushButton("Show", this);
 image_path_show_folder_button_->setToolTip("Show Folder");
 image_path_show_folder_button_->setMaximumWidth(40);
 image_path_show_folder_button_->setStyleSheet(button_style_sheet());

 connect(image_path_show_folder_button_, SIGNAL(clicked(bool)),
   this, SIGNAL(image_path_show_folder_requested(bool)));

 image_path_layout_ = new QHBoxLayout;

 image_path_layout_->setMargin(0);
 image_path_layout_->setSpacing(0);
 image_path_layout_->setContentsMargins(0,0,0,0);

 image_path_layout_->addWidget(image_path_label_);
 image_path_layout_->addWidget(image_path_line_edit_);
 image_path_layout_->setStretchFactor(image_path_line_edit_, 1);
 image_path_layout_->addSpacing(2);
 image_path_layout_->addWidget(image_path_show_folder_button_);
 image_setup_tab_layout_->addLayout(image_path_layout_);

 QString checkbox_stylesheet =  R"(
QCheckBox::indicator {
subcontrol-position: left;}
  )";


 sides_margin_check_box_label_ = new QLabel("Sides", this);
 sides_margin_check_box_label_->setMaximumWidth(30);
 sides_margin_check_box_label_->setToolTip("Make this automatically the same value as the top/bottom margins");

 sides_margin_check_box_ = new QCheckBox("", this);
 sides_margin_check_box_->setStyleSheet(checkbox_stylesheet);
 sides_margin_combo_box_ = new QComboBox(this);
 sides_margin_combo_box_->setMaximumWidth(40);

 border_label_ = new QLabel("Border", this);
 border_combo_box_ = new QComboBox(this);
 border_combo_box_->setMaximumWidth(40);

 border_layout_ = new QHBoxLayout;
 border_layout_->setMargin(0);
 border_layout_->setSpacing(0);
 border_layout_->setContentsMargins(0,0,0,0);

 border_layout_->addWidget(sides_margin_check_box_label_);//, 0, Qt::AlignLeft);
 border_layout_->addWidget(sides_margin_check_box_);//, 0, Qt::AlignLeft);
 border_layout_->addWidget(sides_margin_combo_box_);

 border_layout_->addStretch();
 border_layout_->addWidget(border_label_);
 border_layout_->addWidget(border_combo_box_);
 image_setup_tab_layout_->addLayout(border_layout_);


 vertical_margin_label_ = new QLabel("Margin", this);
 vertical_margin_combo_box_ = new QComboBox;
 vertical_margin_combo_box_->setMaximumWidth(45);

 vertical_margin_combo_box_->setEditable(true);
 vertical_margin_combo_box_->setCompleter(nullptr);

 vertical_margin_combo_box_->setContentsMargins(0,0,0,0);

 vertical_margin_combo_box_->setMaxVisibleItems(11);
 vertical_margin_combo_box_->setStyleSheet("combobox-popup: 0;");

// connect(vertical_margin_combo_box_, &QComboBox::currentTextChanged,
//   [this](QString text)
// {
//  qDebug() << "text = " << text;
//  if(vertical_margin_percent_check_box_->isChecked())
//  {
//   u1 percent = vertical_margin_combo_box_->currentIndex();
//   qDebug() << "percent = " << percent;
//  }
//  else
//  {

//  }
// });

 connect(vertical_margin_combo_box_, QOverload<int>::of(&QComboBox::currentIndexChanged),
   [this](int index)
 {
  bool and_sides = !sides_margin_check_box_->isChecked();

  if(vertical_margin_percent_check_box_->isChecked())
  {
   u1 percent = vertical_margin_combo_box_->currentIndex();
   vertical_margin_combo_box_data_.current_alt_selected_index = percent;
   Q_EMIT change_vertical_margin_percent_requested(percent, and_sides);
   return;
  }

//  if(vertical_margin_combo_box_data_.status_Pre_Init())
//  {
//   qDebug() << "V: " << (int) vertical_margin_combo_box_data_.status;
//   vertical_margin_combo_box_data_.mark_initialized();
//   return;
//  }

  auto [new_value, old_new] = vertical_margin_combo_box_data_.callback_over_increment_data(
    vertical_margin_combo_box_, index, (u1) 5);

  if(old_new != (u1)-1)
    Q_EMIT new_vertical_margin_value_rescinded(old_new);

  Q_EMIT change_vertical_margin_requested(new_value, and_sides);

//  if(vertical_margin_combo_box_data_.status_Processing_Non_Standard_Item())
//  {
//   if(index > vertical_margin_combo_box_data_.max_index)
//   {
//    const QSignalBlocker bl(vertical_margin_combo_box_);
//    vertical_margin_combo_box_->removeItem(vertical_margin_combo_box_data_.temp_in_process_index);
//    vertical_margin_combo_box_data_.clear_temp_in_process_index();
//    --index;
//   }
//   else
//   {
//    vertical_margin_combo_box_data_.clear_processing_non_standard();
//    return;
//   }
//  }

//  if(index > vertical_margin_combo_box_data_.max_index)
//  {
//   vertical_margin_combo_box_data_.mark_processing_non_standard();
//   u1 new_value = (u1) vertical_margin_combo_box_->currentText().toUInt();
//   u1 insert = (new_value / 5) + 1;
//   (*vertical_margin_combo_box_data_.extra_numbers())[insert] = new_value;
//   const QSignalBlocker bl(vertical_margin_combo_box_);
//   vertical_margin_combo_box_->removeItem(index);
//   vertical_margin_combo_box_->insertItem(insert, QString::number(new_value));
//   vertical_margin_combo_box_data_.temp_in_process_index = insert;
//   vertical_margin_combo_box_data_.current_selected_index = insert;
//   //    vertical_margin_combo_box_data_.current_selected_index = insert;
//   //    ++vertical_margin_combo_box_data_.max_index;

//   vertical_margin_combo_box_->setCurrentIndex(insert);
//   //mark_processing_non_standard();
//   //vertical_margin_combo_box_->model()->sort(0);
//  }
//  else
//  {
//   vertical_margin_combo_box_data_.current_selected_index = index;
//  }
 });

 vertical_margin_percent_check_box_label_ = new QLabel("%", this);
 vertical_margin_percent_check_box_label_->setToolTip("Set margins as percent of image dimensions");
 vertical_margin_percent_check_box_label_->setMaximumWidth(10);
 vertical_margin_percent_check_box_ = new QCheckBox(" ", this);
 vertical_margin_percent_check_box_->setMaximumWidth(15);


 connect(vertical_margin_percent_check_box_, &QCheckBox::clicked,
   [this](bool state)
 {
  if(state)
    switch_to_margins_percent();
  else
    switch_to_margins_non_percent();
 });

 vertical_margin_layout_ = new QHBoxLayout;
 vertical_margin_layout_->addWidget(vertical_margin_label_);
 vertical_margin_layout_->addWidget(vertical_margin_combo_box_);

 vertical_margin_layout_->addWidget(vertical_margin_percent_check_box_label_, 0, Qt::AlignRight);
 vertical_margin_layout_->addWidget(vertical_margin_percent_check_box_, 0, Qt::AlignLeft);

 populate_margins_non_percent();

 // vertical_margin_layout_->addStretch();
 vertical_margin_layout_->setMargin(0);
 vertical_margin_layout_->setSpacing(0);
 vertical_margin_layout_->setContentsMargins(0,0,0,0);

 //sides_margin_label_ = new QLabel("Sides", this);
// vertical_margin_layout_->addWidget(sides_margin_check_box_label_);//, 0, Qt::AlignLeft);
// vertical_margin_layout_->addWidget(sides_margin_check_box_);//, 0, Qt::AlignLeft);
// vertical_margin_layout_->addWidget(sides_margin_combo_box_);

 border_color_label_ = new QLabel("Color", this);
 border_color_button_ = new QPushButton(this);
 border_color_button_->setMaximumWidth(30);

// connect(border_color_button_, SIGNAL(clicked(bool)),
//   this, SIGNAL(change_border_color_requested(bool)));

// connect(border_color_button_, &QPushButton::clicked,
//   this, &std::remove_reference<decltype(*this)>::type::change_border_color_requested);

 //connect_to_this(border_color_button_, &QPushButton::clicked, change_border_color_requested);
 //sigma(border_color_button_)->connect_to_this(&QPushButton::clicked, change_border_color_requested);

 //Connect(border_color_button_, &QPushButton::clicked)->to_this(change_border_color_requested);

 //connector<QPushButton>::add_pmfn("clicked", &QPushButton::clicked);

// _saved_mfn_connector<QPushButton>::add_signal("clicked", &QPushButton::clicked);

// stash_signal(QPushButton::clicked);
// stash_signal(QPushButton,clicked);

// SIGNAL_Type

 //Cc((QPushButton*)nullptr).slot_type<bool>get_pmfn("clicked", &QPushButton::clicked);

// Cc(border_color_button_).Cnct<QAbstractButton, Shape_Select_Frame,
//   decltype (&Shape_Select_Frame::change_border_color_requested), bool>("clicked", this, &Shape_Select_Frame::change_border_color_requested);

 //_saved_mfn_connector_precursor prec({"clicked"});
 //prec->_to_this(this, &Shape_Select_Frame::change_border_color_requested);


 border_color_button_ > Connect(clicked) -> to_this(change_border_color_requested);

// Cc(border_color_button_).Cnct("clicked", this, &Shape_Select_Frame::change_border_color_requested);


// pmfns_[{"QPushButton", "clicked"}] = (pmfn) &QPushButton::clicked;

// connect(border_color_button_, pmfns_[{"QPushButton", "clicked"}], this,
//   &Shape_Select_Frame::change_border_color_requested);

//  border_color_button_ >- Connect(,QPushButton::clicked,) -> to_this(change_border_color_requested);
// border_color_button_ >- Connect(,clicked,) -> to_this(change_border_color_requested);


 // -- Connect(border_color_button_ ,clicked) -> to_this(change_border_color_requested);

 //Connect(border_color_button_ ,clicked) -> to_this(change_border_color_requested)

 //border_color_button_ - Connect(QPushButton ,clicked) -> to_this(change_border_color_requested);


 vertical_margin_layout_->addSpacing(5);

 vertical_margin_layout_->addWidget(border_color_label_);
 vertical_margin_layout_->addWidget(border_color_button_);

 image_setup_tab_layout_->addLayout(vertical_margin_layout_);

 image_setup_tab_->setLayout(image_setup_tab_layout_);

 clear_selected_btn_ = new QPushButton("Clear Selected", this);
 clear_last_btn_ = new QPushButton("Clear Last", this);
 clear_all_btn_ = new QPushButton("Clear All", this);

 clear_last_btn_->setEnabled(false);
 clear_all_btn_->setEnabled(false);

 //main_tab_layout_ = new QVBoxLayout;
 main_tab_layout_ = new QGridLayout;
 main_layout_ = new QVBoxLayout;

 domain_shape_options_ = new QComboBox(this);
 domain_shape_options_->addItem("select ...");
 domain_shape_options_->addItem("Pipes");
 domain_shape_options_->addItem("Lighting");
 domain_shape_options_->addItem("Devices");

 domain_shape_options_->setCurrentText("select ...");

 domain_shape_ckb_ = new QCheckBox("Registered\nMarking", this);
//  main_tab_layout_->addWidget(domain_shape_ckb_);
//  main_tab_layout_->addWidget(domain_shape_options_);
  main_tab_layout_->addWidget(domain_shape_ckb_, 0, 0);
  main_tab_layout_->addWidget(domain_shape_options_, 0, 1);


  //?main_tab_layout_->setColumnMinimumWidth(0, 150);


 shape_ckb_group_ = new QButtonGroup(this);

 shape_ckb_group_->setExclusive(true);
 shape_ckb_group_->addButton(domain_shape_ckb_);

 connect(domain_shape_options_, &QComboBox::currentTextChanged,
   [this] {update_shape_selection();});

// main_tab_layout_->addStretch();

 generic_shape_options_ = new QComboBox(this);
 generic_shape_options_->addItem("Rectangle");
 generic_shape_options_->addItem("Ellipse");
 generic_shape_options_->addItem("Polygon");
 generic_shape_options_->addItem("N_A");

 QStandardItemModel* model = qobject_cast<QStandardItemModel*>(generic_shape_options_->model());

 int index = generic_shape_options_->findText("N_A");

 QStandardItem* item = model->item(index);
 item->setFlags(item->flags() & ~Qt::ItemIsEnabled);


 connect(generic_shape_options_, &QComboBox::currentTextChanged,
   [this] {update_shape_selection();});


 generic_shape_ckb_ = new QCheckBox("Generic\nShape", this);
// main_tab_layout_->addWidget(generic_shape_ckb_);
// main_tab_layout_->addWidget(generic_shape_options_);
 main_tab_layout_->addWidget(generic_shape_ckb_, 1, 0);
 main_tab_layout_->addWidget(generic_shape_options_, 1, 1);

 //main_tab_layout_->setRowH(1, 1);

 QSpacerItem* verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
 main_tab_layout_->addItem(verticalSpacer, 2, 0, 1, 2, Qt::AlignTop);

 main_tab_layout_->setMargin(0);
 main_tab_layout_->setContentsMargins(QMargins(10,0,10,0));
 main_tab_layout_->setSpacing(0);

 main_layout_->setMargin(0);
 main_layout_->setContentsMargins(QMargins(0,4,5,4));
 main_layout_->setSpacing(0);

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

 auto_store_check_box_ = new QCheckBox(this);
 store_button_ = new QPushButton("Store", this);
 store_button_->setMinimumWidth(45);
 store_button_->setMaximumWidth(45);
 store_button_->setMaximumHeight(15);
 store_button_->setStyleSheet(soft_small_colorful_button_style_sheet_().arg(8));

 save_button_ = new QPushButton("Save", this);
 save_button_->setMinimumWidth(55);
 save_button_->setMaximumWidth(55);
 save_button_->setMaximumHeight(15);
 save_button_->setStyleSheet(soft_small_colorful_button_style_sheet_().arg(8));

 close_button_ = new QPushButton("Close", this);
 close_button_->setMinimumWidth(55);
 close_button_->setMaximumWidth(55);
 close_button_->setStyleSheet(soft_colorful_button_style_sheet_());

 save_button_layout_ = new QHBoxLayout;

 save_and_close_layout_ = new QHBoxLayout;
 save_layout_ = new QVBoxLayout;
 auto_store_label_ = new QLabel("auto", this);
 auto_store_label_->setMaximumHeight(10);

 auto_store_config_button_ = new QPushButton("config", this);
 auto_store_config_button_->setStyleSheet(light_small_thin_button_style_sheet_().arg(7));
 auto_store_config_button_->setMaximumHeight(13);

 cloud_store_check_box_ = new QCheckBox(" ", this);
 cloud_store_check_box_->setMaximumHeight(13);
 cloud_store_check_box_->setMaximumWidth(13);

 cloud_store_button_ = new QPushButton("cloud", this);
 cloud_store_button_->setStyleSheet(light_small_thin_button_style_sheet_().arg(7));
 cloud_store_button_->setMaximumHeight(13);

 //auto_store_->setMaximumWidth(20);
 QHBoxLayout* auto_store_layout_ = new QHBoxLayout;

 auto_store_layout_->addWidget(auto_store_label_);
 auto_store_layout_->addSpacing(2);
 auto_store_layout_->addWidget(auto_store_config_button_);
 auto_store_layout_->addStretch();
 auto_store_layout_->addWidget(cloud_store_check_box_);
 auto_store_layout_->addWidget(cloud_store_button_);


 save_button_layout_->addWidget(auto_store_check_box_, 0, Qt::AlignBottom);
 save_button_layout_->addSpacing(2);
 save_button_layout_->addStretch();
 save_button_layout_->addWidget(store_button_);
 save_button_layout_->addSpacing(10);
 save_button_layout_->addStretch();
 save_button_layout_->addWidget(save_button_);
 save_layout_->addLayout(save_button_layout_);

 //save_layout_->addWidget(auto_store_label_);
 //save_layout_->addSpacing(1);
 save_layout_->addLayout(auto_store_layout_);


 save_and_close_layout_->addLayout(save_layout_);
 save_and_close_layout_->addStretch();
 save_and_close_layout_->addWidget(close_button_);
 save_and_close_layout_->addStretch();

 main_layout_->addLayout(save_and_close_layout_);

 main_layout_->addSpacing(4);

 main_layout_->addWidget(main_tab_widget_);

 main_layout_->addStretch();

 connect(save_button_, SIGNAL(clicked(bool)), this, SIGNAL(save_requested(bool)));
 connect(close_button_, SIGNAL(clicked(bool)), this, SIGNAL(close_requested(bool)));

 setLayout(main_layout_);

//? setMaximumWidth(190);

 setMaximumHeight(140);

 main_tab_widget_->tabBar()->setShape(QTabBar::RoundedSouth);
 main_tab_widget_->setTabPosition(QTabWidget::South);
 //?
 main_tab_widget_->setStyleSheet(mini_tab_style_sheet_inverted_());

}


void Shape_Select_Frame::switch_to_margins_percent()
{
 vertical_margin_combo_box_data_.clear_processing_non_standard();

 QSignalBlocker sb(vertical_margin_combo_box_);

 vertical_margin_combo_box_->clear();

 for(u1 i = 0; i <= 100; ++i)
 {
  vertical_margin_combo_box_->addItem(QString::number(i));
 }

 if(vertical_margin_combo_box_data_.current_alt_selected_index != (u1)-1)
   vertical_margin_combo_box_->setCurrentIndex(vertical_margin_combo_box_data_.current_alt_selected_index);

 vertical_margin_combo_box_->setValidator(ComboBox_Data::int_validator(0, 100));
}

void Shape_Select_Frame::switch_to_margins_non_percent()
{
 populate_margins_non_percent(true);
}

void Shape_Select_Frame::populate_margins_non_percent(bool clear)
{
 QSignalBlocker sb(vertical_margin_combo_box_);

 if(clear)
   vertical_margin_combo_box_->clear();

 vertical_margin_combo_box_->setValidator(ComboBox_Data::int_validator(0, 500));


 for(u1 i = 0; i <= 250; i += 5)
 {
  vertical_margin_combo_box_->addItem(QString::number(i));
 }

 if(vertical_margin_combo_box_data_.extra_items)
 {
  QMapIterator<u1, u2> it(*vertical_margin_combo_box_data_.extra_numbers());
  while (it.hasNext())
  {
   it.next();
   vertical_margin_combo_box_->insertItem(it.key(), QString::number(it.value()));
  }
 }

 if(vertical_margin_combo_box_data_.status_Pre_Init())
 {
  vertical_margin_combo_box_data_.mark_initialized();
  vertical_margin_combo_box_data_.max_index = 50;
  vertical_margin_combo_box_data_.current_selected_index = 0;
 }
 else
 {
  vertical_margin_combo_box_->setCurrentIndex(vertical_margin_combo_box_data_.current_selected_index);
 }
}


void Shape_Select_Frame::update_border_color_button_color(QColor c)
{
 fill_solid_color_button(border_color_button_, c);
}


void Shape_Select_Frame::update_image_path(QString path, u4 page_number)
{
 if(page_number > 0)
   path += "#" + QString::number(page_number);
 image_path_line_edit_->setText(path);
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



