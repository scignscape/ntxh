
#include "color-range-dialog.h"

#include "styles.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

#include <QPainter>


#include "QtColorWidgets/color_dialog.hpp"


#include "global-types.h"

//heap is managed by parent Widget (no leak), implementation with smart ptr is not suitable in this case.
//objects are used over the scope of this class.

Color_Range_Dialog::Color_Range_Dialog(QColor central_color, QWidget* parent)
  :  QDialog(parent)
{
 offset_ = 50;

 main_layout_ = new QGridLayout;

 details_layout_ = new QGridLayout;

 central_color_label_ = new QLabel("Central:", this);
 central_color_label_->setMaximumWidth(44);

 QString central_color_text = central_color.name();

 central_color_line_edit_ = new QLineEdit(central_color_text, this);
 central_color_line_edit_->setMaximumWidth(55);
 central_color_select_button_ = new QPushButton("new", this);
 central_color_select_button_->setMaximumWidth(34);
 central_color_select_button_->setMaximumHeight(20);

 u1 details_row = 0;

 details_layout_->addWidget(central_color_label_, details_row, 0);
 details_layout_->addWidget(central_color_line_edit_, details_row, 1);
 details_layout_->addWidget(central_color_select_button_, details_row, 2);

 ++details_row;
 details_layout_->setRowStretch(details_row, 1);
 ++details_row;


 offset_label_ = new QLabel("Offset:", this);
 offset_spin_box_ = new QSpinBox(this);
 offset_spin_box_->setValue(offset_);
 offset_spin_box_->setMinimum(0);
 offset_spin_box_->setMaximum(255);
 //offset_spin_box_->setMaximumWidth(50);

 offset_slider_ = new QSlider(Qt::Horizontal, this);
 offset_slider_->setMinimum(0);
 offset_slider_->setMaximum(255);
 offset_slider_->setValue(offset_);
 offset_confirm_buttom_ = new QPushButton("ok", this);
 offset_confirm_buttom_->setMaximumWidth(30);
 offset_confirm_buttom_->setMaximumHeight(20);

 connect(central_color_select_button_, &QPushButton::clicked, [this]()
 {
  color_widgets::ColorDialog dlg(this);
  dlg.setColor(central_color_);
  dlg.exec();
  QColor c = dlg.color();

  if(!c.isValid())
    return;

  if(c == central_color_)
    return;

  central_color_line_edit_->setText(c.name());
  central_color_ = c;
  draw_label_pixmaps();
 });

 connect(offset_slider_, &QSlider::valueChanged, [this](int value)
 {
  const QSignalBlocker qsb(offset_spin_box_);
  offset_spin_box_->setValue(value);
 });

 connect(offset_spin_box_, QOverload<int>::of(&QSpinBox::valueChanged), [this](int value)
 {
  const QSignalBlocker qsb(offset_slider_);
  offset_slider_->setValue(value);
 });

 connect(offset_confirm_buttom_, &QPushButton::clicked, [this]()
 {
  offset_ = offset_spin_box_->value();
  draw_label_pixmaps();
 });

 details_layout_->addWidget(offset_label_, details_row, 0, Qt::AlignRight);
 details_layout_->addWidget(offset_spin_box_, details_row, 1, Qt::AlignRight);
 details_layout_->addWidget(offset_confirm_buttom_, details_row, 2);
 ++details_row;
 details_layout_->addWidget(offset_slider_, details_row, 0, 1, 3);
 ++details_row;

 details_layout_->setRowStretch(details_row, 1);
 ++details_row;


 background_color_ = QColor(255, 255, 255);

 background_color_label_ = new QLabel("Back:", this);
 background_color_line_edit_ = new QLineEdit(background_color_.name());
 background_color_line_edit_->setMaximumWidth(55);
 background_color_select_button_ = new QPushButton("new", this);
 background_color_select_button_->setMaximumWidth(34);
 background_color_select_button_->setMaximumHeight(20);

 details_layout_->addWidget(background_color_label_, details_row, 0, Qt::AlignRight);
 details_layout_->addWidget(background_color_line_edit_, details_row, 1);
 details_layout_->addWidget(background_color_select_button_, details_row, 2);
 ++details_row;

 QGridLayout* background_opacity_layout = new QGridLayout;

 background_opacity_ = 255;
 old_background_opacity_ = 255;
 QLabel* alpha = new QLabel("opacity", this);
 alpha->setMaximumWidth(60);
 background_opacity_spin_box_ = new QSpinBox(this);
 background_opacity_spin_box_->setMinimum(0);
 background_opacity_spin_box_->setMaximum(255);
 background_opacity_spin_box_->setMaximumWidth(45);
 background_opacity_spin_box_->setValue(background_opacity_);
 QLabel* background_color_fully = new QLabel("fully", this);
 QLabel* background_color_transparent = new QLabel("transparent", this);
 //background_color_fully_transparent->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
 background_color_fully_transparent_ = new QCheckBox("", this);
 background_color_fully_transparent_->setChecked(false);

 connect(background_color_fully_transparent_, &QCheckBox::stateChanged, [this](int state)
 {
  QSignalBlocker qsb(background_opacity_spin_box_);
  if(state == 0)
  {
   background_opacity_ = old_background_opacity_;
   background_opacity_spin_box_->setValue(background_opacity_);
  }
  else
  {
   old_background_opacity_ = background_opacity_;
   background_opacity_ = 0;
   background_opacity_spin_box_->setValue(background_opacity_);
  }
 });

 connect(background_opacity_spin_box_, QOverload<int>::of(&QSpinBox::valueChanged), [this](int value)
 {
  QSignalBlocker qsb(background_color_fully_transparent_);
  background_color_fully_transparent_->setChecked(value == 0);
  background_opacity_ = value;
 });

 background_opacity_layout->setContentsMargins(0, 0, 0, 0);
 background_opacity_layout->setSpacing(0);

 background_opacity_layout->addWidget(background_opacity_spin_box_, 0, 0);
 background_opacity_layout->addWidget(alpha, 1, 0, Qt::AlignHCenter | Qt::AlignTop);
 //
 background_opacity_layout->setColumnStretch(1, 1);
 background_opacity_layout->addWidget(background_color_fully, 0, 2, Qt::AlignLeft | Qt::AlignBottom);
 background_opacity_layout->addWidget(background_color_transparent, 1, 2, 1, 2, Qt::AlignLeft | Qt::AlignTop);
 //background_opacity_layout->addSpacing(2);
 background_opacity_layout->addWidget(background_color_fully_transparent_, 0, 3, Qt::AlignLeft | Qt::AlignBottom);

 details_layout_->setRowStretch(details_row, 1);
 ++details_row;

 details_layout_->addLayout(background_opacity_layout, details_row, 0, 1, 3);

 details_layout_->setContentsMargins(0, 0, 0, 0);
 details_layout_->setSpacing(0);

 //background_opacity_layout->addStretch();

 main_layout_->addLayout(details_layout_, 0, 0);

 central_color_ = central_color;

 red_green_label_ = new QLabel("", this);
 red_blue_label_ = new QLabel("", this);
 green_blue_label_ = new QLabel("", this);

 draw_label_pixmaps();

 main_layout_->addWidget(red_green_label_, 0, 1);
 main_layout_->addWidget(red_blue_label_, 1, 0);
 main_layout_->addWidget(green_blue_label_, 1, 1);

 metric_group_box_ = new QGroupBox("Metric", this);
 max_difference_button_ = new QRadioButton("Max Difference", this);
 sum_difference_button_ = new QRadioButton("Sum Difference", this);
 vector_difference_button_ = new QRadioButton("Vector Difference", this);
 weighted_check_box_ =
   new QCheckBox("Weighted", this);

 QGridLayout* metric_layout = new QGridLayout;
 metric_layout->addWidget(max_difference_button_, 0, 0);
 metric_layout->addWidget(sum_difference_button_, 1, 0);
 metric_layout->addWidget(vector_difference_button_, 0, 1);
 metric_layout->addWidget(weighted_check_box_, 1, 1);

 max_difference_button_->setChecked(true);

 metric_group_box_->setLayout(metric_layout);

 main_layout_->addWidget(metric_group_box_, 2, 0, 1, 3);

 button_box_ = new QDialogButtonBox(this);

 //?url_label_ = new QLabel(this);
  //?url_label_->setText(url);

// name_qle_ = new QLineEdit(this);

 //button_ok_ = new QPushButton("OK");
 button_proceed_ = new QPushButton("Proceed");
 button_cancel_ = new QPushButton("Cancel");


 button_proceed_->setDefault(false);
 button_proceed_->setAutoDefault(false);

 button_cancel_->setDefault(true);

 button_proceed_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());


 //?button_ok_->setEnabled(false);
 //button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 button_box_->addButton(button_proceed_, QDialogButtonBox::AcceptRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);


 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(reject()));

 main_layout_->addWidget(button_box_, 3, 0, 1, 2);


 setLayout(main_layout_);

}

u1 Color_Range_Dialog::get_metric_code()
{
 if(offset_ == 0)
   return (u1) Color_Range_Dialog::Metric_Codes::Exact_Match;
 u1 add = weighted_check_box_->isChecked()? 3 : 0;
 if(max_difference_button_->isChecked())
   return (u1) Color_Range_Dialog::Metric_Codes::Max_Difference + add;
 if(sum_difference_button_->isChecked())
   return (u1) Color_Range_Dialog::Metric_Codes::Sum_Difference + add;
 if(vector_difference_button_->isChecked())
   return (u1) Color_Range_Dialog::Metric_Codes::Vector_Difference + add;

 // //  one should always be checked so this is presumably unreachable ...
 return 0;
}


u1 to_u1_range(s2 val)
{
 if(val < 0)
   return 0;
 if(val > 255)
   return 255;
 return (u1) val;
}


void Color_Range_Dialog::draw_label_pixmaps()
{
 s2 inner_width = 50;

 QPixmap rg_pixmap(3 * inner_width, 3 * inner_width);
 QPixmap rb_pixmap(3 * inner_width, 3 * inner_width);
 QPixmap gb_pixmap(3 * inner_width, 3 * inner_width);

 QPainter rg_painter(&rg_pixmap);
 QPainter rb_painter(&rb_pixmap);
 QPainter gb_painter(&gb_pixmap);

 rg_painter.setPen(Qt::NoPen);
 rb_painter.setPen(Qt::NoPen);
 gb_painter.setPen(Qt::NoPen);

 u1 cred = central_color_.red();
 u1 cblue = central_color_.blue();
 u1 cgreen = central_color_.green();

 if(offset_ == 0)
 {
  rg_painter.setBrush(central_color_);
  rb_painter.setBrush(central_color_);
  gb_painter.setBrush(central_color_);
  rg_painter.drawRect(0, 0, inner_width * 3, inner_width * 3);
  rb_painter.drawRect(0, 0, inner_width * 3, inner_width * 3);
  gb_painter.drawRect(0, 0, inner_width * 3, inner_width * 3);
 }
 else
 {
  for(s2 dim1 = -offset_, x = 0; dim1 <= offset_; x += inner_width, dim1 += offset_)
    for(s2 dim2 = -offset_, y = 0; dim2 <= offset_; y += inner_width, dim2 += offset_)
    {
     u1 red = to_u1_range(cred + dim1);
     u1 green1 = to_u1_range(cgreen + dim1);
     u1 green2 = to_u1_range(cgreen + dim2);
     u1 blue = to_u1_range(cblue + dim2);
     rg_painter.setBrush(QColor(red, green2, cblue));
     rg_painter.drawRect(x, y, inner_width, inner_width);
     rb_painter.setBrush(QColor(red, cgreen, blue));
     rb_painter.drawRect(x, y, inner_width, inner_width);
     gb_painter.setBrush(QColor(cred, green1, blue));
     gb_painter.drawRect(x, y, inner_width, inner_width);
    }
 }

 red_green_label_->setPixmap(rg_pixmap);
 red_blue_label_->setPixmap(rb_pixmap);
 green_blue_label_->setPixmap(gb_pixmap);
}
