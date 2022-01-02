
#include "page-and-search-frame.h"

#include "styles.h"

#include <QDebug>

#include <QStandardItemModel>
#include <QStandardItem>



Page_and_Search_Frame::Page_and_Search_Frame(QWidget* parent)
  :  QFrame(parent)
{
 main_layout_ = new QVBoxLayout;

 page_select_ = new QComboBox(this);
 page_select_->setMinimumWidth(50);

 page_select_label_  = new QLabel("Page", this);


 page_select_and_navigate_layout_ = new QHBoxLayout;
 page_select_and_navigate_layout_left_ = new QVBoxLayout;
 page_select_and_navigate_layout_right_ = new QVBoxLayout;

 page_select_layout_ = new QHBoxLayout;
 page_select_layout_->addWidget(page_select_label_);
 page_select_layout_->addSpacing(3);
 page_select_layout_->addWidget(page_select_);
 page_select_layout_->addStretch();
 page_select_and_navigate_layout_left_->addLayout(page_select_layout_);

 main_layout_->setMargin(0);
 main_layout_->setContentsMargins(QMargins(10,4,5,4));
 main_layout_->setSpacing(0);

// main_layout_->addLayout(page_select_layout_);

// main_layout_->addSpacing(4);

 page_navigate_layout_ = new QHBoxLayout;
 page_back_button_ = new QPushButton(this);
 page_forward_button_ = new QPushButton(this);
 page_first_button_ = new QPushButton(this);
 page_last_button_ = new QPushButton(this);

 make_light_double_back_button(page_first_button_);
 make_light_back_button(page_back_button_);
 make_light_forward_button(page_forward_button_);
 make_light_double_forward_button(page_last_button_);

 page_navigate_layout_->addWidget(page_first_button_);
 page_navigate_layout_->addSpacing(2);
 page_navigate_layout_->addWidget(page_back_button_);
 page_navigate_layout_->addSpacing(1);
 page_navigate_layout_->addWidget(page_forward_button_);
 page_navigate_layout_->addSpacing(2);
 page_navigate_layout_->addWidget(page_last_button_);

 page_navigate_layout_->addStretch();
 page_select_and_navigate_layout_left_->addSpacing(4);
 page_select_and_navigate_layout_left_->addLayout(page_navigate_layout_);

 page_print_or_pdf_ = new QCheckBox(this);
 page_print_or_pdf_->setToolTip("When checled, uses print instead of PDF (raw) page numbers "
                                "(may use letters/symbols or not start at 1)");

 page_print_or_pdf_label_ = new QLabel("print");
 page_print_or_pdf_label_->setToolTip(page_print_or_pdf_->toolTip());

 page_select_and_navigate_layout_right_->setContentsMargins(0,0,0,0);
 page_select_and_navigate_layout_right_->setMargin(0);
 page_select_and_navigate_layout_right_->setSpacing(0);

 page_select_and_navigate_layout_right_->addStretch();
 page_select_and_navigate_layout_right_->addWidget(page_print_or_pdf_, Qt::AlignHCenter);
 page_select_and_navigate_layout_right_->addWidget(page_print_or_pdf_label_);
 page_select_and_navigate_layout_right_->setAlignment(page_print_or_pdf_, Qt::AlignRight);
 page_select_and_navigate_layout_right_->setAlignment(page_print_or_pdf_label_, Qt::AlignRight);

 QFrame* line = new QFrame(this);
 line->setFrameShape(QFrame::HLine); // Horizontal line
 line->setFrameShadow(QFrame::Sunken);
 line->setLineWidth(1);

 page_select_and_navigate_layout_right_->addWidget(line);

 page_select_and_navigate_layout_right_->addSpacing(2);

 page_select_and_navigate_layout_->addLayout(page_select_and_navigate_layout_left_);
 page_select_and_navigate_layout_->addLayout(page_select_and_navigate_layout_right_);

// main_layout_->addLayout(page_navigate_layout_);
 main_layout_->addLayout(page_select_and_navigate_layout_);

 main_layout_->addStretch();

 special_navigate_layout_ = new QHBoxLayout;
 special_select_ = new QComboBox(this);
 special_select_->addItem("Annotation");
 special_select_->addItem("Section");
 special_select_->addItem("Chapter");
 special_select_->addItem("Bookmarks");
 special_select_->setToolTip("When applicable, chooses which document or image-series feature is browsed via these forward/back buttons");

 special_back_button_ = new QPushButton(this);
 special_forward_button_ = new QPushButton(this);
 make_light_special_back_button(special_back_button_);
 make_light_special_forward_button(special_forward_button_);

 special_navigate_layout_->addWidget(special_select_);
 special_navigate_layout_->addSpacing(3);
 special_navigate_layout_->addWidget(special_back_button_);
 special_navigate_layout_->addSpacing(1);
 special_navigate_layout_->addWidget(special_forward_button_);

 main_layout_->addLayout(special_navigate_layout_);
 main_layout_->addStretch();


 search_layout_ = new QHBoxLayout;

 search_label_ = new QLabel("Search", this);
 search_line_edit_ = new QLineEdit(this);

 main_layout_->addWidget(search_line_edit_);

 search_layout_->addWidget(search_label_);
 search_layout_->addSpacing(3);

 search_up_button_ = new QPushButton(this);
 search_down_button_ = new QPushButton(this);
 search_from_top_button_ = new QPushButton(this);

 make_up_button(search_up_button_);
 make_down_button(search_down_button_);
 make_top_down_button(search_from_top_button_);

 search_layout_->addWidget(search_up_button_);
 search_layout_->addSpacing(2);
 search_layout_->addWidget(search_down_button_);
 search_layout_->addSpacing(2);
 search_layout_->addWidget(search_from_top_button_);

// search_case_sensitive_ = new QCheckBox(this);
// search_case_sensitive_->setToolTip("Case Sensitive Search");

 search_case_sensitive_button_ = new QPushButton("Aa", this);
 search_case_sensitive_button_->setToolTip("Case Sensitive Search");
 search_case_sensitive_button_->setCheckable(true);
 search_case_sensitive_button_->setChecked(false);

 search_case_sensitive_button_->setStyleSheet(light_checkable_button_style_sheet_orange_());

 search_case_sensitive_button_->setMaximumHeight(15);
 search_case_sensitive_button_->setMaximumWidth(22);

 search_layout_->addStretch();

 search_layout_->addWidget(search_case_sensitive_button_);

 main_layout_->addLayout(search_layout_);

 main_layout_->addStretch();

 setLayout(main_layout_);


 setMaximumHeight(140);

}
