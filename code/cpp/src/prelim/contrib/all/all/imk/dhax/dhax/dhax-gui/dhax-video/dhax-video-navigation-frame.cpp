
#include "dhax-video-navigation-frame.h"


#include <QDebug>

DHAX_Video_Navigation_Frame::DHAX_Video_Navigation_Frame(QWidget* parent)
  :  QFrame(parent)
{
 main_layout_ = new QHBoxLayout;

 top_layout_ = new QVBoxLayout;
 bottom_layout_ = new QHBoxLayout;

 main_layout_->setContentsMargins(0,0,0,0);
 main_layout_->setMargin(0);

 top_layout_->setContentsMargins(0,0,0,0);
 top_layout_->setMargin(0);

 bottom_layout_->setContentsMargins(0,0,0,0);
 bottom_layout_->setMargin(0);

 full_size_button_ = new QPushButton("*", this);
 full_size_button_->setMaximumWidth(25);
 full_size_button_->setMaximumHeight(15);

 smaller_size_button_ = new QPushButton("-", this);
 smaller_size_button_->setMaximumWidth(25);
 smaller_size_button_->setMaximumHeight(15);

 top_layout_->addWidget(full_size_button_);
 top_layout_->addWidget(smaller_size_button_);

 restart_button_ = new QPushButton("<", this);
 restart_button_->setMaximumWidth(25);
 restart_button_->setMaximumHeight(15);
 pause_button_ = new QPushButton("=", this);
 pause_button_->setMaximumWidth(25);
 pause_button_->setMaximumHeight(15);
 resume_button_  = new QPushButton(">", this);
 resume_button_->setMaximumWidth(25);
 resume_button_->setMaximumHeight(15);

 bottom_layout_->addStretch();
 bottom_layout_->addWidget(restart_button_);
 bottom_layout_->addWidget(pause_button_);
 bottom_layout_->addWidget(resume_button_);


 main_layout_->addLayout(top_layout_);
 main_layout_->addLayout(bottom_layout_);
 setLayout(main_layout_);

 connect(pause_button_, &QPushButton::clicked,
   this, &DHAX_Video_Navigation_Frame::pause_requested);

 connect(resume_button_, &QPushButton::clicked,
   this, &DHAX_Video_Navigation_Frame::resume_requested);

 connect(restart_button_, &QPushButton::clicked,
   this, &DHAX_Video_Navigation_Frame::restart_requested);

 connect(full_size_button_, &QPushButton::clicked,
   this, &DHAX_Video_Navigation_Frame::full_size_requested);

 connect(smaller_size_button_, &QPushButton::clicked,
   this, &DHAX_Video_Navigation_Frame::smaller_size_requested);

}