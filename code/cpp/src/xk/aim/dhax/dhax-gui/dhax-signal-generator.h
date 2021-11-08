
#ifndef DHAX_SIGNAL_GENERATOR__H
#define DHAX_SIGNAL_GENERATOR__H

#include <QObject>

#include <QVariant>

#include "accessors.h"
#include "global-types.h"



class DHAX_Signal_Generator : public QObject
{
 Q_OBJECT

 //QObject* held_object_;

public:

 DHAX_Signal_Generator();


 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)


 //void hold(QObject* obj);
 void emit_take_screenshot_requested();
 void emit_load_image_requested();
 void emit_received_datagram(QByteArray qba);

 void emit_view_contours_requested();
 void emit_view_3d_requested();
 void emit_view_360_requested();
 void emit_view_cad_requested();
 void emit_run_forge_workflow_requested();
 void emit_quit_requested();


Q_SIGNALS:

 void take_screenshot_requested();
 void load_image_requested();
 void received_datagram(QByteArray qba);

 void view_contours_requested();
 void view_3d_requested();
 void view_360_requested();
 void view_cad_requested();
 void run_forge_workflow_requested();
 void quit_requested();

};

#endif // DHAX_SIGNAL_GENERATOR__H
