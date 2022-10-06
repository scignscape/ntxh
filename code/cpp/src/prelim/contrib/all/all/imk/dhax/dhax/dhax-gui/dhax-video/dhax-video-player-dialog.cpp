
#include "dhax-video-player-dialog.h"

#include "dhax-video-player-frame.h"

#include "styles.h"


DHAX_Video_Player_Dialog::DHAX_Video_Player_Dialog(QWidget* parent)
  :  QDialog(parent)
{
// setLayout(new QVBoxLayout);
// layout()->setContentsMargins(0, 0, 0, 0);


 main_layout_ = new QVBoxLayout;

 main_layout_->setContentsMargins(0, 0, 0, 0);
 main_layout_->setMargin(0);


 player_ = new DHAX_Video_Player_Frame(this);

 main_layout_->addWidget(player_);
 button_box_ = new QDialogButtonBox(this);

 button_close_ = new QPushButton("Close");
 button_suspend_ = new QPushButton("Proceed");
 button_cancel_ = new QPushButton("Cancel");

 button_close_->setDefault(true);

 button_close_->setStyleSheet(basic_button_style_sheet_());
 button_suspend_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());


 button_box_->addButton(button_close_, QDialogButtonBox::AcceptRole);
 button_box_->addButton(button_suspend_, QDialogButtonBox::ActionRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::DestructiveRole);

 //?connect(button_proceed_, SIGNAL(clicked()), this, SLOT(proceed()));
// connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
// connect(button_box_, SIGNAL(rejected()), this, SLOT(close()));

 main_layout_->addWidget(button_box_);

 setLayout(main_layout_);

 connect(player_, &DHAX_Video_Player_Frame::show_video_frame_requested,
  this, &DHAX_Video_Player_Dialog::show_video_frame_requested);

 connect(player_, &DHAX_Video_Player_Frame::video_size_established,
  [this](QSize sz)
 {
  check_adjust_size(sz, 20);

//  QSize ns = player_->get_navigation_size();
//  int h = sz.height() + button_box_->height() + ns.height();
//  int w = qMax(sz.width(), button_box_->width());
//  w = qMax(w, ns.width());

//  this->resize(w, h + 20);
 });

 connect(player_, &DHAX_Video_Player_Frame::full_video_size_requested,
  [this](QSize sz)
 {
  last_smaller_screen_position_ = pos();
  last_smaller_size_ = size();

  qDebug() << "full: " << sz;
  check_adjust_size(sz, 20);
 });

 connect(player_, &DHAX_Video_Player_Frame::smaller_video_size_requested,
  [this](QSize sz)
 {
  move(last_smaller_screen_position_);
  resize(last_smaller_size_);
  qDebug() << " small: " << sz;

//  check_adjust_size(sz, 20);
 });

//  QMediaPlaylist *playList = new QMediaPlaylist(this);
//  playList->addMedia(QUrl::fromLocalFile("/home/nlevisrael/gits/ctg-temp/stella/videos/test.webm"));
//  playList->setPlaybackMode(QMediaPlaylist::Loop);
//  media_player_->setPlaylist(playList);


//  current_path_ = "/home/nlevisrael/gits/ctg-temp/stella/videos/test.mp4";


}

void DHAX_Video_Player_Dialog::check_adjust_size(QSize sz, int height_margin)
{
 qDebug() << " sz: " << sz;

 QSize ns = player_->get_navigation_size();
 int h = sz.height() + button_box_->height() + ns.height();
 int w = qMax(sz.width(), button_box_->width());
 w = qMax(w, ns.width());

 this->resize(w, h + height_margin);

}

void DHAX_Video_Player_Dialog::play_local_video(QString file_path)
{
 player_->play_local_video(file_path);
}
