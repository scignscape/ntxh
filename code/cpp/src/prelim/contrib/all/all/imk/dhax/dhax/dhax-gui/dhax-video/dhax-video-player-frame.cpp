
#include "dhax-video-player-frame.h"
#include "dhax-video-navigation-frame.h"

#include <QGraphicsVideoItem>

#include <QMenu>
#include <QStyle>
#include <QDir>

#include "styles.h"


DHAX_Video_Player_Frame::DHAX_Video_Player_Frame(QWidget* parent)
  :  QFrame(parent), full_size_rect_item_(nullptr),
     smaller_size_rect_item_(nullptr)
{
// setLayout(new QVBoxLayout);
// layout()->setContentsMargins(0, 0, 0, 0);

//? video_widget_ = new QVideoWidget(this);

 //        btn = new QPushButton(this);
 //        btn->setText("tux.jpeg");
 //        btn->resize(QSize(128, 128));
 //        btn->setIconSize(QSize(128, 128));


 navigation_ = new DHAX_Video_Navigation_Frame;
 navigation_->setFrameStyle(QFrame::Panel | QFrame::Sunken);

 main_layout_ = new QVBoxLayout;

 main_layout_->setContentsMargins(0, 0, 0, 0);
 main_layout_->setMargin(0);

 graphics_view_ = new QGraphicsView(this);
 graphics_scene_ = new QGraphicsScene(this);
 graphics_view_->setScene(graphics_scene_);
 video_item_ = new QGraphicsVideoItem;
 graphics_scene_->addItem(video_item_);

 connect(video_item_,
   &QGraphicsVideoItem::nativeSizeChanged, [this]()
 {
//?  QSize sz = media_player_->media().canonicalResource().resolution();
  QSize sz = media_player_->metaData("Resolution").value<QSize>();
  qDebug() << "size = " << sz;
 });

// main_layout_->addWidget(video_widget_);
 main_layout_->addWidget(graphics_view_);
 main_layout_->addWidget(navigation_);

//  video_frame_grabber_ = new VideoFrameGrabber(this);

 media_player_ = new QMediaPlayer(this);
 media_player_->setVideoOutput(video_item_);
// media_player_->setVideoOutput(video_widget_);
//  media_player_->setVideoOutput(video_frame_grabber_);

// connect(media_player_, &QMediaPlayer::metaDataChanged,
//   []()
// {

// });

 video_probe_ = new QVideoProbe;

 if(video_probe_->setSource(media_player_))
 {
  qDebug() << "probe ok";
 }
 else
 {
  qDebug() << "probe bad";
 }


 connect(video_probe_, &QVideoProbe::videoFrameProbed, [this](QVideoFrame qvf)
//  connect(video_frame_grabber_, &VideoFrameGrabber::frameAvailable, [this](QImage frame_image)
 {
  if(need_video_size_)
  {
   --need_video_size_;
   if(media_player_->isMetaDataAvailable())
   {
    video_size_ = media_player_->metaData("Resolution").value<QSize>();
    if(video_size_.isValid())
    {
     need_video_size_ = 0;
     confirm_video_size();
    }
   }
  }

//  qint64 st = qvf.startTime();
//  qint64 fn = st/40000;
////  qDebug() << fn;
  current_video_frame_ = qvf;

//    QSize sz = media_player_->media().canonicalResource().resolution();
//    qDebug() << "size = " << sz;
//    QSize sz1 = media_player_->metaData("Resolution").value<QSize>();
//    qDebug() << "size1 = " << sz1;

//   QImage frame_image = qvf.image();

//   QLabel* l = new QLabel;
//   l->setPixmap(QPixmap::fromImage(frame_image));
//   l->show();

 });

 connect(navigation_, &DHAX_Video_Navigation_Frame::grab_frame_requested, [this]()
 {
  pause();

  qDebug() << "pos: " << media_player_->position();
  QImage frame_image = current_video_frame_.image();
  QLabel* l = new QLabel;
  l->setPixmap(QPixmap::fromImage(frame_image));

  l->setContextMenuPolicy(Qt::CustomContextMenu);

  connect(l, &QLabel::customContextMenuRequested, [this, l](QPoint pos)
  {
   QMenu* m = new QMenu;
   m->addAction("Send video frame to main window", [this, l]()
   {
    handle_send_video_frame_to_main_window(l);
   });
   m->popup(pos + l->pos() + QPoint(0,
     QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight)));
  });

  l->show();
 });

 connect(navigation_, &DHAX_Video_Navigation_Frame::pause_requested, [this]()
 {
  pause();
  //      qDebug()<<"p clicked";
 });

 connect(navigation_, &DHAX_Video_Navigation_Frame::resume_requested, [this]()
 {
//      qDebug()<<"r clicked";
  media_player_->play();
  navigation_->set_play_button_to_play();

 });

 connect(navigation_, &DHAX_Video_Navigation_Frame::restart_requested, [this]()
 {
//      qDebug()<<"r clicked";
  media_player_->setPosition(0);
  media_player_->play();
 });

 connect(navigation_, &DHAX_Video_Navigation_Frame::full_size_requested, [this]()
 {
  reset_to_full_size();
//      qDebug()<<"r clicked";
 });

 connect(navigation_, &DHAX_Video_Navigation_Frame::smaller_size_requested, [this]()
 {
  reset_to_smaller_size();
 });

// navigation_->show();

 setLayout(main_layout_);

//  QMediaPlaylist *playList = new QMediaPlaylist(this);
//  playList->addMedia(QUrl::fromLocalFile("/home/nlevisrael/gits/ctg-temp/stella/videos/test.webm"));
//  playList->setPlaybackMode(QMediaPlaylist::Loop);
//  media_player_->setPlaylist(playList);


//  current_path_ = "/home/nlevisrael/gits/ctg-temp/stella/videos/test.mp4";


}

void DHAX_Video_Player_Frame::pause()
{
 media_player_->pause();
 navigation_->set_play_button_to_resume();
}

void DHAX_Video_Player_Frame::handle_send_video_frame_to_main_window(QLabel* l)
{
 QString cnf = class_name_folder(DEFAULT_DHAX_TEMP_FOLDER "/_proc");

 QDir qd(cnf);
 if(!qd.exists())
   qd.mkpath(".");

 cnf += "/temp.png";
 l->pixmap()->save(cnf);

 qDebug() << "saving pixmap: " << cnf;

 Q_EMIT show_video_frame_requested(cnf);
}

void DHAX_Video_Player_Frame::play_local_video(QString file_path)
{
 current_path_ = file_path;
// current_path_ = "/home/nlevisrael/gits/ctg-temp/stella/videos/test.mkv";
 current_url_ =  QUrl::fromLocalFile(current_path_);

 media_player_->setMedia(current_url_);

 // //  give it a bit of time
 need_video_size_ = 10; //

// ?check_adjust_size();

 media_player_->play();


// navigation_->show();
}

QSize DHAX_Video_Player_Frame::get_navigation_size()
{
 return navigation_->size();
}

void DHAX_Video_Player_Frame::confirm_video_size()
{
 QColor c (200, 100, 10, 100);

 QSizeF sz = video_item_->size(); //.grownBy(QMargins(5,5,5,5));
 double ratio = (double) video_size_.width() / video_size_.height();

 int new_width = sz.height() * ratio;

 float left = (sz.width() / 2) - (new_width / 2);

 smaller_size_rect_item_ = graphics_scene_->addRect(left,
   video_item_->pos().y(),new_width,sz.height(),QPen(QBrush(c), 4));

 Q_EMIT video_size_established(QSize(new_width, sz.height()));

// qDebug() << "sz = " << sz;
// qDebug() << "ratio = " << ratio;
// qDebug() << "new w = " << new_width;
// qDebug() << "szh = " << sz.height();

//  QSizeF szs = video_item_->size().grownBy(QMargins(3,3,3,3));
//  QSizeF sza = video_item_->size().grownBy(QMargins(5,5,5,5));

//  graphics_view_->resize(new_width + 7, sz.height() + 7);

//  this->resize(graphics_view_->size());

//  graphics_scene_->addRect(video_item_->pos().x(), video_item_->pos().y(),
//    new_width, sz.height(),
//    QPen(QBrush(c), 10), Qt::NoBrush);

// graphics_view_->resize(new_width, sz.height());

// QColor c (200, 100, 10, 100);

// graphics_scene_->addRect(0, 0, szs.width(), szs.height(),
//   QPen(QBrush(c), 10), Qt::NoBrush);

// graphics_view_->resize(sza.toSize());


// graphics_scene_->addRect(0, 0, video_size_.width(), video_size_.height(),
//   QPen(QBrush(c), 10), Qt::NoBrush);

}

void DHAX_Video_Player_Frame::reset_to_smaller_size()
{
 if(full_size_rect_item_)
   graphics_scene_->removeItem(full_size_rect_item_);
 if(smaller_size_rect_item_)
   graphics_scene_->addItem(smaller_size_rect_item_);

 video_item_->setSize(last_smaller_size_);

 QRectF rect = graphics_scene_->itemsBoundingRect();
 graphics_scene_->setSceneRect(rect);

 Q_EMIT smaller_video_size_requested(last_smaller_size_.toSize());
}

void DHAX_Video_Player_Frame::reset_to_full_size()
{
// qDebug() << "new size: " << video_size_;
// QSize sza = video_size_.grownBy(QMargins(5,5,5,5));
// setMaximumWidth(sza.width());
// setMaximumHeight(sza.height());
// graphics_view_->resize(video_size_);
// graphics_view_->update();

// video_item_->setSize(video_size_);

 QSizeF szs = video_size_.grownBy(QMargins(3,3,3,3));
 QSizeF sza = video_size_.grownBy(QMargins(5,5,5,5));


 QColor c (200, 100, 10, 100);

 if(smaller_size_rect_item_)
   graphics_scene_->removeItem(smaller_size_rect_item_);

 if(full_size_rect_item_)
   graphics_scene_->addItem(full_size_rect_item_);
 else
   full_size_rect_item_ = graphics_scene_->addRect(0, 0, szs.width(), szs.height(),
     QPen(QBrush(c), 10), Qt::NoBrush);

 last_smaller_size_ = video_item_->size();

 video_item_->setSize(video_size_);


 graphics_view_->resize(sza.toSize());

 Q_EMIT full_video_size_requested(sza.toSize());

}


void DHAX_Video_Player_Frame::resizeEvent(QResizeEvent* event)
{
//? setMaximumWidth(video_widget_->width() + 12);
//? navigation_->move(p.x(), p.y() - 20);
//? navigation_->move(rect().bottomRight() - navigation_->rect().bottomRight());// + QPoint(-40,-40));
// navigation_->move(video_widget_->rect().bottomRight() - navigation_->rect().bottomRight() + QPoint(0,10));
 QWidget::resizeEvent(event);
}
