
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
 page_select_label_  = new QLabel("Page", this);
 page_select_layout_ = new QHBoxLayout;
 page_select_layout_->addStretch();
 page_select_layout_->addWidget(page_select_label_);
 page_select_layout_->addWidget(page_select_);
 page_select_layout_->addStretch();

 search_label_ = new QLabel("Search", this);
 search_line_edit_ = new QLineEdit(this);


 main_layout_->setMargin(0);
 main_layout_->setContentsMargins(QMargins(10,4,5,4));
 main_layout_->setSpacing(0);

 main_layout_->addLayout(page_select_layout_);

 main_layout_->addSpacing(4);

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
 page_navigate_layout_->addSpacing(4);
 page_navigate_layout_->addWidget(page_back_button_);
 page_navigate_layout_->addSpacing(4);
 page_navigate_layout_->addWidget(page_forward_button_);
 page_navigate_layout_->addSpacing(4);
 page_navigate_layout_->addWidget(page_last_button_);

 main_layout_->addLayout(page_navigate_layout_);

 main_layout_->addStretch();

 main_layout_->addWidget(search_line_edit_);

 search_layout_ = new QHBoxLayout;

 search_layout_->addWidget(search_label_);

 search_up_button_ = new QPushButton(this);
 search_down_button_ = new QPushButton(this);
 search_from_top_button_ = new QPushButton(this);

 search_layout_->addWidget(search_up_button_);
 search_layout_->addWidget(search_down_button_);
 search_layout_->addWidget(search_from_top_button_);


 make_up_button(search_up_button_);
 make_down_button(search_down_button_);
 make_top_down_button(search_from_top_button_);

 main_layout_->addLayout(search_layout_);

 main_layout_->addStretch();

 setLayout(main_layout_);


 setMaximumHeight(140);

}
