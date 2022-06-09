
#include "dhax-signal-generator.h"


DHAX_Signal_Generator::DHAX_Signal_Generator()
{

}


void DHAX_Signal_Generator::emit_received_datagram(QByteArray qba)
{
 Q_EMIT received_datagram(qba);
}

#ifdef USE_IFC
void DHAX_Signal_Generator::emit_ifc_convert_requested()
{
 Q_EMIT ifc_convert_requested();
}
#endif

void DHAX_Signal_Generator::emit_take_screenshot_requested()
{
 Q_EMIT take_screenshot_requested();
}

void DHAX_Signal_Generator::emit_load_image_requested()
{
 Q_EMIT load_image_requested();
}

void DHAX_Signal_Generator::emit_show_xcsd_scene_requested()
{
 Q_EMIT show_xcsd_scene_requested();
}

void DHAX_Signal_Generator::emit_calculate_local_color_histograms_requested()
{
 Q_EMIT calculate_local_color_histograms_requested();
}

void DHAX_Signal_Generator::emit_save_local_color_histograms_requested()
{
 Q_EMIT save_local_color_histograms_requested();
}

void DHAX_Signal_Generator::emit_save_fb_gradient_trimap_requested()
{
 Q_EMIT save_fb_gradient_trimap_requested();
}

void DHAX_Signal_Generator::emit_load_pdf_requested()
{
 Q_EMIT load_pdf_requested();
}

void DHAX_Signal_Generator::emit_load_notes_requested()
{
 Q_EMIT load_notes_requested();
}


void DHAX_Signal_Generator::emit_view_contours_requested()
{
 Q_EMIT view_contours_requested();
}

void DHAX_Signal_Generator::emit_view_3d_requested()
{
 Q_EMIT view_3d_requested();
}

void DHAX_Signal_Generator::emit_view_360_requested()
{
 Q_EMIT view_360_requested();
}

void DHAX_Signal_Generator::emit_view_cad_requested()
{
 Q_EMIT view_cad_requested();
}

void DHAX_Signal_Generator::emit_run_forge_workflow_requested()
{
 Q_EMIT run_forge_workflow_requested();
}

void DHAX_Signal_Generator::emit_quit_requested()
{
 Q_EMIT quit_requested();
}

