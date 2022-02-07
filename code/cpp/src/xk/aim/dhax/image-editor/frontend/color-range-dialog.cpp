
#include "color-range-dialog.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

#include <QPainter>

#include "global-types.h"

//heap is managed by parent Widget (no leak), implementation with smart ptr is not suitable in this case.
//objects are used over the scope of this class.

Color_Range_Dialog::Color_Range_Dialog(QColor central_color, QWidget* parent)
{
 offset_ = 15;

 main_layout_ = new QGridLayout;

 details_layout_ = new QGridLayout;

 central_color_label_ = new QLabel("Central:", this);
 central_color_label_->setMaximumWidth(44);

 QString central_color_text = central_color_.name();

 central_color_line_edit_ = new QLineEdit(central_color_text, this);
 central_color_line_edit_->setMaximumWidth(55);
 central_color_select_button_ = new QPushButton("new", this);
 central_color_select_button_->setMaximumWidth(34);
 central_color_select_button_->setMaximumHeight(20);

 details_layout_->addWidget(central_color_label_, 0, 0);
 details_layout_->addWidget(central_color_line_edit_, 0, 1);
 details_layout_->addWidget(central_color_select_button_, 0, 2);

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

 details_layout_->addWidget(offset_label_, 1, 0, Qt::AlignRight);
 details_layout_->addWidget(offset_spin_box_, 1, 1, Qt::AlignRight);
 details_layout_->addWidget(offset_confirm_buttom_, 1, 2);
 details_layout_->addWidget(offset_slider_, 2, 0, 1, 3);

 details_layout_->setContentsMargins(0, 0, 0, 0);
 details_layout_->setSpacing(0);

 main_layout_->addLayout(details_layout_, 0, 0);

 central_color_ = central_color;

 red_green_label_ = new QLabel("RG", this);
 red_blue_label_ = new QLabel("RB", this);
 green_blue_label_ = new QLabel("GB", this);

 draw_label_pixmaps();

 main_layout_->addWidget(red_green_label_, 0, 1);
 main_layout_->addWidget(red_blue_label_, 1, 0);
 main_layout_->addWidget(green_blue_label_, 1, 1);

 setLayout(main_layout_);

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

 for(s2 dim1 = -offset_, x = 0; dim1 <= offset_; x += inner_width, dim1 += offset_)
 {
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
