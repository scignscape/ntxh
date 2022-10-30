
#include "dhax-signal-generator.h"

#define STATIC_COUNT static u2 static_count = 0;

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
 STATIC_COUNT
 Q_EMIT ifc_convert_requested(++static_count);
}
#endif

void DHAX_Signal_Generator::emit_take_screenshot_requested()
{
 // //  set this to use a specific folder for testing/dev ...
 static QString default_screenshot_folder;
 STATIC_COUNT
 Q_EMIT take_screenshot_requested(++static_count, default_screenshot_folder);
}

void DHAX_Signal_Generator::emit_load_image_requested()
{
 STATIC_COUNT
 Q_EMIT load_image_requested(++static_count);
}

void DHAX_Signal_Generator::emit_show_xcsd_scene_requested()
{
 STATIC_COUNT
 Q_EMIT show_xcsd_scene_requested(++static_count);
}

void DHAX_Signal_Generator::emit_calculate_local_color_histograms_requested()
{
 STATIC_COUNT
 Q_EMIT calculate_local_color_histograms_requested(++static_count);
}

void DHAX_Signal_Generator::emit_save_local_color_histograms_requested()
{
 STATIC_COUNT
 Q_EMIT save_local_color_histograms_requested(++static_count);
}

void DHAX_Signal_Generator::emit_show_fb_gradient_trimap_requested()
{
 STATIC_COUNT
 Q_EMIT show_fb_gradient_trimap_requested(++static_count);
}


void DHAX_Signal_Generator::emit_launch_edge_detection_dialog_requested()
{
 STATIC_COUNT
 Q_EMIT launch_edge_detection_dialog_requested(++static_count);
}

void DHAX_Signal_Generator::emit_calculate_fb_gaussian_requested()
{
 STATIC_COUNT
 Q_EMIT calculate_fb_gaussian_requested(++static_count);
}

void DHAX_Signal_Generator::emit_show_pixel_local_aggregate_color_distance_requested()
{
 STATIC_COUNT
 Q_EMIT show_pixel_local_aggregate_color_distance_requested(++static_count);
}



void DHAX_Signal_Generator::emit_load_pdf_requested()
{
 STATIC_COUNT
 Q_EMIT load_pdf_requested(++static_count);
}

void DHAX_Signal_Generator::emit_load_notes_requested()
{
 STATIC_COUNT
 Q_EMIT load_notes_requested(++static_count);
}


void DHAX_Signal_Generator::emit_view_contours_requested()
{
 STATIC_COUNT
 Q_EMIT view_contours_requested(++static_count);
}

void DHAX_Signal_Generator::emit_view_3d_requested()
{
 STATIC_COUNT
 Q_EMIT view_3d_requested(++static_count);
}

void DHAX_Signal_Generator::emit_view_360_requested()
{
 STATIC_COUNT
 Q_EMIT view_360_requested(++static_count);
}


void DHAX_Signal_Generator::emit_prepare_video_recorder_requested()
{
 STATIC_COUNT
 Q_EMIT prepare_video_recorder_requested(++static_count);
}

void DHAX_Signal_Generator::emit_test_ssr_datagram_requested()
{
 STATIC_COUNT
 Q_EMIT test_ssr_datagram_requested(++static_count);
}


void DHAX_Signal_Generator::emit_play_video_requested(DHAX_Video_Player_Dialog::Annotation_Settings s)
{
 STATIC_COUNT
 Q_EMIT play_video_requested(++static_count, s);
}


void DHAX_Signal_Generator::emit_view_cad_requested()
{
 STATIC_COUNT
 Q_EMIT view_cad_requested(++static_count);
}

void DHAX_Signal_Generator::emit_run_forge_workflow_requested()
{
 STATIC_COUNT
 Q_EMIT run_forge_workflow_requested(++static_count);
}

void DHAX_Signal_Generator::emit_quit_requested()
{
 STATIC_COUNT
 Q_EMIT quit_requested(++static_count);
}

