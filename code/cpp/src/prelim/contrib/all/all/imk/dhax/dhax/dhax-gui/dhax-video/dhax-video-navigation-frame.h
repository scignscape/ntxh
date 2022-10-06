
#ifndef DHAX_VIDEO_NAVIGATION_FRAME__H
#define DHAX_VIDEO_NAVIGATION_FRAME__H


#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>

#include "styles.h"


class DHAX_Video_Navigation_Frame : public QFrame
{
 Q_OBJECT

 #define _sigma_ns_(global)
 #define _my_sigma_(includes) \
 includes(buttons, layout, tooltip, stylesheet)
 #include "sigma.h"

 QPushButton* restart_button_;
 QPushButton* pause_button_;
 QPushButton* resume_button_;
 QPushButton* full_size_button_;
 QPushButton* smaller_size_button_;

 QPushButton* grab_frame_button_;

 QHBoxLayout* top_layout_;
 QHBoxLayout* bottom_layout_;
 QHBoxLayout* main_layout_;

public:

 DHAX_Video_Navigation_Frame(QWidget* parent = nullptr);

 void set_play_button_to_resume();
 void set_play_button_to_play();
 //?sigma(resume_button_)->make_resume_button();

Q_SIGNALS:

 void restart_requested();
 void pause_requested();
 void resume_requested();
 void full_size_requested();
 void smaller_size_requested();
 void grab_frame_requested();

};


#endif // DHAX_VIDEO_NAVIGATION_FRAME__H
