

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-video-player-frame.h"
#include "dhax-video-navigation-frame.h"

#include "dhax-video-annotation-set.h"

#include <QGraphicsVideoItem>

#include <QMenu>
#include <QStyle>
#include <QDir>

#include <QScrollBar>

#include "styles.h"


DHAX_Video_Player_Frame::DHAX_Video_Player_Frame(QWidget* parent)
  :  QFrame(parent), annotation_set_(nullptr),
     full_size_rect_item_(nullptr),
     smaller_size_rect_item_(nullptr),
     replay_count_(0), current_frame_count_(0)
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

 video_item_->setFlags(QGraphicsItem::ItemIsMovable);

//? graphics_view_->setAlignment(Qt::AlignHCenter | Qt::AlignBaseline);

 frame_number_text_ = nullptr;


 graphics_view_->setContextMenuPolicy(Qt::CustomContextMenu);

 connect(graphics_view_, &QGraphicsView::customContextMenuRequested, [this](const QPoint& pos)
 {
  QMenu* menu = new QMenu(this);
  menu->addAction("Load annotations", this, &DHAX_Video_Player_Frame::load_annotations);
  menu->popup(mapToGlobal(pos));
 });


 connect(video_item_,
   &QGraphicsVideoItem::nativeSizeChanged, [this]()
 {
//?  QSize sz = media_player_->media().canonicalResource().resolution();
//?  QSize sz = media_player_->metaData("Resolution").value<QSize>();
  QSizeF szf = video_item_->nativeSize();

  if(szf == QSize(0,0))
  {
   ++replay_count_;
   current_frame_count_ = 0;
  }
  else if(replay_count_ > 0)
  {
   graphics_view_->centerOn(video_item_);
  }


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

 connect(media_player_, &QMediaPlayer::stateChanged, [this](QMediaPlayer::State state)
 {
  if(state == QMediaPlayer::StoppedState)
  {
   qDebug() << "stopped";
//   media_player_->setPosition(0);
//   media_player_->play();
   //video_probe_->
  }
 });

 video_probe_ = new QVideoProbe;

 if(video_probe_->setSource(media_player_))
 {
  qDebug() << "probe ok";
 }
 else
 {
  qDebug() << "probe bad";
 }

 connect_video_probe();


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
  current_frame_count_ = 0;
  update_frame_number_text();
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

 setLayout(main_layout_);

//  QMediaPlaylist *playList = new QMediaPlaylist(this);
//  playList->addMedia(QUrl::fromLocalFile("/home/nlevisrael/gits/ctg-temp/stella/videos/test.webm"));
//  playList->setPlaybackMode(QMediaPlaylist::Loop);
//  media_player_->setPlaylist(playList);


//  current_path_ = "/home/nlevisrael/gits/ctg-temp/stella/videos/test.mp4";


}


void DHAX_Video_Player_Frame::connect_video_probe()
{
 connect(video_probe_, &QVideoProbe::videoFrameProbed, [this](const QVideoFrame& qvf)
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

  qint64 st = qvf.startTime();
  qint64 seconds = st/1000;
  qint64 fn = st/40000;

  ++current_frame_count_;

  if((current_frame_count_ & 20) == 0)
  {
   if(frame_number_text_)
     update_frame_number_text();
  }


//  qDebug() << fn;
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
}


void DHAX_Video_Player_Frame::init_annotations()
{
 annotation_set_ = new DHAX_Video_Annotation_Set;
}


void DHAX_Video_Player_Frame::load_annotations()
{
 pause();
 init_annotations();
 qDebug( ) << "init_aaa";
}

void DHAX_Video_Player_Frame::update_frame_number_text()
{
 QString text = QString::number(current_frame_count_);
//      "%1\n%2"_qt.arg(current_frame_count_).arg(seconds);
 frame_number_text_->setPlainText(text);
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


void DHAX_Video_Player_Frame::halt()
{
 media_player_->stop();
}


void DHAX_Video_Player_Frame::play_local_video(QString file_path)
{
// current_path_ = file_path;

 current_path_ = "/home/nlevisrael/gits/ctg-temp/stella/videos/test.mkv";


 current_url_ =  QUrl::fromLocalFile(current_path_);

 QMediaPlaylist* play_list = new QMediaPlaylist();
 media_player_->setPlaylist(play_list);
 play_list->addMedia(QMediaContent(current_url_));
 play_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

// media_player_->setMedia(current_url_);

 // //  give it a bit of time
 need_video_size_ = 10; //

// ?check_adjust_size();

 media_player_->play();



 qDebug() << " SR1: " << graphics_scene_->sceneRect();
 qDebug() << " IBR1: " << graphics_scene_->itemsBoundingRect();

 QSizeF sz = video_item_->size(); //.grownBy(QMargins(5,5,5,5));
 qDebug() << " SZ1: " << sz;


// navigation_->show();
}

QSize DHAX_Video_Player_Frame::get_navigation_size()
{
 return navigation_->size();
}

void DHAX_Video_Player_Frame::confirm_video_size()
{
 QColor c (200, 100, 10, 100);

 qDebug() << " SR2: " << graphics_scene_->sceneRect();
 qDebug() << " IBR2: " << graphics_scene_->itemsBoundingRect();

 QSizeF sz = video_item_->size(); //.grownBy(QMargins(5,5,5,5));
 qDebug() << " SZ2: " << sz;


 double ratio = (double) video_size_.width() / video_size_.height();

 double new_width = sz.height() * ratio;

 double left = (sz.width() / 2) - (new_width / 2);

 double h_center = sz.width() / 2;

 QRectF video_rect(left, video_item_->pos().y(), new_width, sz.height());

 smaller_size_rect_item_ = graphics_scene_->addRect(left,
   video_item_->pos().y(),new_width,sz.height(),QPen(QBrush(c), 4));

 smaller_size_rect_item_->setParentItem(video_item_);

 QRectF framed_scene_rect = graphics_scene_->sceneRect();

 QColor text_bkg_color (110, 80, 20, 40);
 QColor text_color (10, 80, 20, 255);

// u1 frame_number_text_background_extra_height = 10;

// frame_number_text_background_ = graphics_scene_->addRect(
//   QRect(smaller_size_rect_item_->rect().bottomRight().toPoint() - QPoint(120, 2),
//   smaller_size_rect_item_->rect().bottomRight().toPoint() + QPoint(-100, frame_number_text_background_extra_height)));

// frame_number_text_background_ = graphics_scene_->addRect(
//   QRect(smaller_size_rect_item_->rect().center().toPoint() - QPoint(20, 2),
//   smaller_size_rect_item_->rect().center().toPoint()));

  frame_number_text_background_ = graphics_scene_->addRect(
    QRect(smaller_size_rect_item_->rect().topLeft().toPoint() + QPoint(-20, 5),
    smaller_size_rect_item_->rect().topLeft().toPoint() + QPoint(3, 20)));

 frame_number_text_background_->setParentItem(smaller_size_rect_item_);

 frame_number_text_background_->setBrush(QBrush(text_bkg_color));
 frame_number_text_background_->setPen(Qt::NoPen);

 frame_number_text_ = graphics_scene_->addText("0000");
 frame_number_text_->setParentItem(frame_number_text_background_);
 frame_number_text_->setPos(frame_number_text_background_->rect().topLeft());

 frame_number_text_->setDefaultTextColor(text_color);
 QFont font = frame_number_text_->font();
 font.setPointSize(5);
 frame_number_text_->setFont(font);

 reset_graphics_scene_rect();

 graphics_scene_->setSceneRect(framed_scene_rect);
 initial_smaller_scene_rect_ = framed_scene_rect;

 qDebug() << " SR4: " << graphics_scene_->sceneRect();
 qDebug() << " IBR4: " << graphics_scene_->itemsBoundingRect();

 double left_half = h_center - graphics_scene_->sceneRect().left();
 double right_half = h_center - graphics_scene_->sceneRect().right();

 qDebug() << " left half: " << left_half;
 qDebug() << " right half: " << right_half;

 Q_EMIT video_size_established(QSize(new_width, sz.height() ));


}

void DHAX_Video_Player_Frame::reset_graphics_scene_rect()
{
 QRectF rect = graphics_scene_->itemsBoundingRect();
 graphics_scene_->setSceneRect(rect);
}

void DHAX_Video_Player_Frame::reset_to_smaller_size()
{
 if(full_size_rect_item_)
   graphics_scene_->removeItem(full_size_rect_item_);
 if(smaller_size_rect_item_)
 {
  graphics_scene_->addItem(smaller_size_rect_item_);
  smaller_size_rect_item_->setParentItem(video_item_);
 }

// frame_number_text_background_->show();
// frame_number_text_->show();


 video_item_->setSize(last_smaller_size_);

 reset_graphics_scene_rect();

 graphics_scene_->setSceneRect(initial_smaller_scene_rect_);

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

 QColor c (200, 100, 10, 100);

 if(smaller_size_rect_item_)
   graphics_scene_->removeItem(smaller_size_rect_item_);

 if(full_size_rect_item_)
   graphics_scene_->addItem(full_size_rect_item_);
 else
 {
  QSizeF szs = video_size_.grownBy(QMargins(3,3,3,3));

  full_size_rect_item_ = graphics_scene_->addRect(0, 0, szs.width(), szs.height(),
   QPen(QBrush(c), 10), Qt::NoBrush);
 }

 if(true) //last_larger_video_size_.isEmpty())
 {
//  frame_number_text_background_->hide();
//  frame_number_text_->hide();

  last_smaller_size_ = video_item_->size();

  video_item_->setSize(video_size_);

  QSizeF sza = video_size_.grownBy(QMargins(5,5,5,5));

  last_larger_video_size_ = video_size_;
  last_larger_graphics_view_size_ = sza;

  graphics_view_->resize(sza.toSize());
  QRectF rect = graphics_scene_->itemsBoundingRect();
  graphics_scene_->setSceneRect(rect);

  Q_EMIT full_video_size_requested(sza.toSize());
 }

}

void DHAX_Video_Player_Frame::recenter()
{
 graphics_view_->centerOn(video_item_);
}

void DHAX_Video_Player_Frame::resizeEvent(QResizeEvent* event)
{
 graphics_view_->centerOn(video_item_);

//? setMaximumWidth(video_widget_->width() + 12);
//? navigation_->move(p.x(), p.y() - 20);
//? navigation_->move(rect().bottomRight() - navigation_->rect().bottomRight());// + QPoint(-40,-40));
// navigation_->move(video_widget_->rect().bottomRight() - navigation_->rect().bottomRight() + QPoint(0,10));
 QWidget::resizeEvent(event);
}
