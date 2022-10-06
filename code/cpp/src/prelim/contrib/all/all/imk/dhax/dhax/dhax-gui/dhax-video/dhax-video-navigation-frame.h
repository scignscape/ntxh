
#ifndef DHAX_VIDEO_NAVIGATION_FRAME__H
#define DHAX_VIDEO_NAVIGATION_FRAME__H


#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>


class DHAX_Video_Navigation_Frame : public QFrame
{
 Q_OBJECT

 QPushButton* restart_button_;
 QPushButton* pause_button_;
 QPushButton* resume_button_;
 QPushButton* full_size_button_;
 QPushButton* smaller_size_button_;

 QVBoxLayout* top_layout_;
 QHBoxLayout* bottom_layout_;
 QHBoxLayout* main_layout_;

public:

 DHAX_Video_Navigation_Frame(QWidget* parent = nullptr);


Q_SIGNALS:

 void restart_requested();
 void pause_requested();
 void resume_requested();
 void full_size_requested();
 void smaller_size_requested();


};


#endif // DHAX_VIDEO_NAVIGATION_FRAME__H
