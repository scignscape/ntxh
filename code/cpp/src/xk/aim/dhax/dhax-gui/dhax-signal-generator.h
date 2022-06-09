
#ifndef DHAX_SIGNAL_GENERATOR__H
#define DHAX_SIGNAL_GENERATOR__H

#include <QObject>

#include <QVariant>

#include "accessors.h"
#include "global-types.h"
#include "self-connect.h"



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
 void emit_load_pdf_requested();
 void emit_load_notes_requested();
 void emit_received_datagram(QByteArray qba);

 void emit_show_xcsd_scene_requested();
 void emit_calculate_local_color_histograms_requested();
 void emit_save_local_color_histograms_requested();
 void emit_save_fb_gradient_trimap_requested();

 void emit_view_contours_requested();
 void emit_view_3d_requested();
 void emit_view_360_requested();
 void emit_view_cad_requested();
 void emit_run_forge_workflow_requested();
 void emit_quit_requested();

#ifdef USE_IFC
 void emit_ifc_convert_requested();
#endif

Q_SIGNALS:

 void take_screenshot_requested();
 void load_pdf_requested();
 void load_image_requested();
 void load_notes_requested();
 void received_datagram(QByteArray qba);

 void view_contours_requested();
 void view_3d_requested();
 void view_360_requested();
 void view_cad_requested();
 void run_forge_workflow_requested();
 void quit_requested();

 void show_xcsd_scene_requested();

 void calculate_local_color_histograms_requested();
 void save_local_color_histograms_requested();
 void save_fb_gradient_trimap_requested();


#ifdef USE_IFC
 void ifc_convert_requested();
#endif


};

#endif // DHAX_SIGNAL_GENERATOR__H
