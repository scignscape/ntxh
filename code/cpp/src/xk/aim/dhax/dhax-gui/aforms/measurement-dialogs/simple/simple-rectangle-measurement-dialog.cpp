
#include "simple-rectangle-measurement-dialog.h"

#include "aforms/simple/simple-rectangle-annotation.h"

#include "styles.h"

#include <QPushButton>

#include <QDebug>
#include <QMessageBox>

#include "subwindows/clickable-label.h"


#include <QPainter>
#include <QPainterPath>
#include <QPen>


QString add_ratio_glyph(QString s)
{
 return s + QString(" (%1)").arg(QChar(0x223A));
}


void Solid_Color_Label::paintEvent(QPaintEvent* e)
{
 QPainter p(this);
 p.setRenderHint(QPainter::Antialiasing);
 QPainterPath path;
 path.addRoundedRect(QRectF(1, 1, width_, height_), corners_, corners_);
 p.setPen(Qt::NoPen);
 p.fillPath(path, color_);
 p.drawPath(path);

 QFont font;
 font.setPixelSize(font_pixel_size_);

 QPen pen(Qt::black, 1);
 p.setPen(pen);
 p.setFont(font);
 p.drawText(width_ + text_offset_, height_ - ((height_ - font_pixel_size_) / 2),
   QString("Hex: %1").arg(QString::number(color_.rgb(), 16).mid(2)));
}


Simple_Rectangle_Measurement_Dialog::Simple_Rectangle_Measurement_Dialog(Simple_Rectangle_Annotation* ann,
  QWidget* parent)
  :  QDialog(parent)
{
 main_layout_ = new QVBoxLayout;

 info_layout_ = new QFormLayout;

 info_scroll_area_ = new QScrollArea(this);

 info_frame_ = new QFrame(this);


 Simple_Rectangle_Annotation::Measurements& ms = ann->get_measurements();

 using Parameters = Simple_Rectangle_Annotation::Parameters;
 parameter_labels_.resize(Parameters::count);

 parameter_labels_[Parameters::u2_width] = new_QLabel(ms.width);
 parameter_labels_[Parameters::u2_height] = new_QLabel(ms.height);
 parameter_labels_[Parameters::u2_perimeter] = new_QLabel(ms.perimeter);

 parameter_labels_[Parameters::u2_image_width] = new_QLabel(ms.image_width);
 parameter_labels_[Parameters::u2_image_height] = new_QLabel(ms.image_height);
 parameter_labels_[Parameters::u2_image_perimeter] = new_QLabel(ms.image_perimeter);

 parameter_labels_[Parameters::u4_area] = new_QLabel(ms.area);
 parameter_labels_[Parameters::u4_image_area] = new_QLabel(ms.image_area);

 parameter_labels_[Parameters::r8_wh_ratio] = new_QLabel(ms.wh_ratio);
 parameter_labels_[Parameters::r8_hw_ratio] = new_QLabel(ms.hw_ratio);
 parameter_labels_[Parameters::r8_image_wh_ratio] = new_QLabel(ms.image_wh_ratio);
 parameter_labels_[Parameters::r8_image_hw_ratio] = new_QLabel(ms.image_hw_ratio);

 parameter_labels_[Parameters::r8_width_against_image] = new_QLabel(ms.width_against_image);
 parameter_labels_[Parameters::r8_height_against_image] = new_QLabel(ms.height_against_image);
 parameter_labels_[Parameters::r8_perimeter_against_image] = new_QLabel(ms.perimeter_against_image);
 parameter_labels_[Parameters::r8_area_against_image] = new_QLabel(ms.area_against_image);

 using D = Simple_Rectangle_Annotation::Directions;

 parameter_labels_[Parameters::u2_left_margin] = new_QLabel(ms.margins[D::left]);
 parameter_labels_[Parameters::u2_top_left_margin] = new_QLabel(ms.margins[D::top_left]);
 parameter_labels_[Parameters::u2_top_margin] = new_QLabel(ms.margins[D::top]);
 parameter_labels_[Parameters::u2_top_right_margin] = new_QLabel(ms.margins[D::top_right]);

 parameter_labels_[Parameters::u2_right_margin] = new_QLabel(ms.margins[D::right]);
 parameter_labels_[Parameters::u2_bottom_right_margin] = new_QLabel(ms.margins[D::bottom_right]);
 parameter_labels_[Parameters::u2_bottom_margin] = new_QLabel(ms.margins[D::bottom]);
 parameter_labels_[Parameters::u2_bottom_left_margin] = new_QLabel(ms.margins[D::bottom_left]);

 parameter_labels_[Parameters::r8_left_margin_against_image] = new_QLabel(ms.margins_against_image[D::left]);
 parameter_labels_[Parameters::r8_top_left_margin_against_image] = new_QLabel(ms.margins_against_image[D::top_left]);
 parameter_labels_[Parameters::r8_top_margin_against_image] = new_QLabel(ms.margins_against_image[D::top]);
 parameter_labels_[Parameters::r8_top_right_margin_against_image] = new_QLabel(ms.margins_against_image[D::top_right]);

 parameter_labels_[Parameters::r8_right_margin_against_image] = new_QLabel(ms.margins_against_image[D::right]);
 parameter_labels_[Parameters::r8_bottom_right_margin_against_image] = new_QLabel(ms.margins_against_image[D::bottom_right]);
 parameter_labels_[Parameters::r8_bottom_margin_against_image] = new_QLabel(ms.margins_against_image[D::bottom]);
 parameter_labels_[Parameters::r8_bottom_left_margin_against_image] = new_QLabel(ms.margins_against_image[D::bottom_left]);


 info_layout_->addRow("Width", parameter_labels_[Parameters::u2_width]);
 info_layout_->addRow("Height", parameter_labels_[Parameters::u2_height]);
 info_layout_->addRow("Perimeter", parameter_labels_[Parameters::u2_perimeter]);

 info_layout_->addRow("Image Width", parameter_labels_[Parameters::u2_image_width]);
 info_layout_->addRow("Image Height", parameter_labels_[Parameters::u2_image_height]);
 info_layout_->addRow("Image Perimeter", parameter_labels_[Parameters::u2_image_perimeter]);

 info_layout_->addRow("Area", parameter_labels_[Parameters::u4_area]);
 info_layout_->addRow("Image Area", parameter_labels_[Parameters::u4_image_area]);

 info_layout_->addRow("Width/Height", parameter_labels_[Parameters::r8_wh_ratio]);
 info_layout_->addRow("Height/Width", parameter_labels_[Parameters::r8_hw_ratio]);
 info_layout_->addRow("Image Width/Height", parameter_labels_[Parameters::r8_image_wh_ratio]);
 info_layout_->addRow("Image Height/Width", parameter_labels_[Parameters::r8_image_hw_ratio]);

 info_layout_->addRow(add_ratio_glyph("Width"), parameter_labels_[Parameters::r8_width_against_image]);
 info_layout_->addRow(add_ratio_glyph("Height"), parameter_labels_[Parameters::r8_height_against_image]);
 info_layout_->addRow(add_ratio_glyph("Perimeter"), parameter_labels_[Parameters::r8_perimeter_against_image]);
 info_layout_->addRow(add_ratio_glyph("Area"), parameter_labels_[Parameters::r8_area_against_image]);


 info_layout_->addRow("Left Margin", parameter_labels_[Parameters::u2_left_margin]); //  = new_QLabel(ms.margins[D::left]);
 info_layout_->addRow("Top Left Margin", parameter_labels_[Parameters::u2_top_left_margin]); //  = new_QLabel(ms.margins[D::top_left]);
 info_layout_->addRow("Top Margin", parameter_labels_[Parameters::u2_top_margin]); //  = new_QLabel(ms.margins[D::top]);
 info_layout_->addRow("Top Right Margin", parameter_labels_[Parameters::u2_top_right_margin]); //  = new_QLabel(ms.margins[D::top_right]);

 info_layout_->addRow("Right Margin", parameter_labels_[Parameters::u2_right_margin]); //  = new_QLabel(ms.margins[D::right]);
 info_layout_->addRow("Bottom Right Margin", parameter_labels_[Parameters::u2_bottom_right_margin]); //  = new_QLabel(ms.margins[D::bottom_right]);
 info_layout_->addRow("Bottom Margin", parameter_labels_[Parameters::u2_bottom_margin]); //  = new_QLabel(ms.margins[D::bottom]);
 info_layout_->addRow("Bottom Left Margin", parameter_labels_[Parameters::u2_bottom_left_margin]); //  = new_QLabel(ms.margins[D::bottom_left]);


 info_layout_->addRow(add_ratio_glyph("Left Margin"), parameter_labels_[Parameters::r8_left_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::left]);
 info_layout_->addRow(add_ratio_glyph("Top Left Margin"), parameter_labels_[Parameters::r8_top_left_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::top_left]);
 info_layout_->addRow(add_ratio_glyph("Top Margin"), parameter_labels_[Parameters::r8_top_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::top]);
 info_layout_->addRow(add_ratio_glyph("Top Right Margin"), parameter_labels_[Parameters::r8_top_right_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::top_right]);

 info_layout_->addRow(add_ratio_glyph("Right Margin"), parameter_labels_[Parameters::r8_right_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::right]);
 info_layout_->addRow(add_ratio_glyph("Bottom Right Margin"), parameter_labels_[Parameters::r8_bottom_right_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::bottom_right]);
 info_layout_->addRow(add_ratio_glyph("Bottom Margin"), parameter_labels_[Parameters::r8_bottom_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::bottom]);
 info_layout_->addRow(add_ratio_glyph("Bottom Left Margin"), parameter_labels_[Parameters::r8_bottom_left_margin_against_image]); //  = new_QLabel(ms.margins_against_image[D::bottom_left]);

 QColor qc = ann->get_color_mean();

 solid_color_labels_.resize(1);
 //solid_color_labels_[0] = new QLabel(this);
 solid_color_labels_[0] = new Solid_Color_Label(qc);

 //qDebug() << "qc = " << qc;

 //fill_solid_color_label(solid_color_labels_[0], qc);

 info_layout_->addRow("Additive Color Mean", solid_color_labels_[0]);


 info_frame_->setLayout(info_layout_);

 info_scroll_area_->setWidget(info_frame_);

 //info_scroll_area_->setWidgetResizable(true);

 main_layout_->addWidget(info_scroll_area_);

 //setMinimumWidth(400);

 setWindowTitle("Annotation Measurement");

 button_box_ = new QDialogButtonBox(this);

 button_ok_ = new QPushButton("OK");
 //? button_proceed_ = new QPushButton("Proceed");
 button_cancel_ = new QPushButton("Cancel");

 button_ok_->setDefault(false);
 button_ok_->setAutoDefault(false);

 //?button_proceed_->setDefault(false);
 //?button_proceed_->setAutoDefault(false);

 button_cancel_->setDefault(true);

 button_ok_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());


 //?button_ok_->setEnabled(false);
 button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 //?button_box_->addButton(button_proceed_, QDialogButtonBox::ApplyRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);


 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(close()));

 main_layout_->addWidget(button_box_);

// setWindowFlags(windowFlags() | Qt::FramelessWindowHint);


 setLayout(main_layout_);
}


Simple_Rectangle_Measurement_Dialog::~Simple_Rectangle_Measurement_Dialog()
{

}
