
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-main-window-controller.h"

#include "dhax-main-window.h"

#include "image-viewer/dhax-display-image-data.h"

#include "pleneviews/zoom-and-navigate-frame.h"
#include "pleneviews/page-and-search-frame.h"

#include "image-viewer/dhax-image-viewer.h"

#include "image-viewer/dhax-image-scene-item.h"

#include "main-window/dhax-main-window-receiver.h"
#include "main-window/dhax-main-window-data.h"

#include "integration/meshlab/dhax-meshlab-integration-data.h"
#include "integration/freecad/dhax-freecad-integration-data.h"

#include "application/dhax-application-controller.h"

#include "dhax-graphics-scene.h"

#include "pdf-viewer/pdf-document-controller.h"

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>

#include <QFileDialog>

#include <QGraphicsProxyWidget>


DHAX_Main_Window_Controller::DHAX_Main_Window_Controller()
  :  display_image_data_(nullptr),
     zoom_frame_(nullptr), page_and_search_frame_(nullptr),
     image_scene_item_(nullptr),
     main_window_receiver_(nullptr),
     application_controller_(nullptr),
     document_controller_(nullptr)
{

}


void DHAX_Main_Window_Controller::show_annotation_comments(DHAX_Annotation_Instance* dai)
{
 QString text = dai->comment();
 QMessageBox::information(application_main_window_, dai->scoped_identifiers_to_string(),
   dai->comment());
}


void DHAX_Main_Window_Controller::init_image_scene_item(DHAX_Image_Scene_Item* si)
{
 image_scene_item_ = si;

 application_controller_->init_image_scene_item(si);

 si->set_meshlab_import_count(application_main_window_->
   main_window_data()->meshlab_integration()->meshlab_import_count());

 si->set_freecad_import_count(application_main_window_->
   main_window_data()->freecad_integration()->freecad_import_count());

// application_controller_

//?
// si->set_freecad_import_count(application_main_window_->
//   main_window_data()->freecad_integration()->freecad_import_count());


//?
// image_scene_item_->setGeometry(0,0,0,0);
// image_scene_item_->setObjectName(QString::fromUtf8("ImageDisplayWidget"));
// // //


 //image_scene_item_->self_connect()

// image_scene_item_->connect(image_scene_item_,SIGNAL(save_notation_requested(bool)),
//   main_window_receiver_, SLOT(handle_save_notation_requested(bool)));

// image_scene_item_->connect(image_scene_item_,SIGNAL(convert_notation_requested()),
//   main_window_receiver_, SLOT(handle_convert_notation_requested()));

// image_scene_item_->connect(image_scene_item_,SIGNAL(polygon_save_notation_requested()),
//   main_window_receiver_, SLOT(handle_polygon_save_notation_requested()));
// image_scene_item_->connect(image_scene_item_,SIGNAL(polygon_complete_and_save_notation_requested()),
//   main_window_receiver_, SLOT(handle_polygon_complete_and_save_notation_requested()));

 image_scene_item_->self_connect(SIGNAL(complete_polygon_requested()),
   main_window_receiver_, SLOT(handle_complete_polygon()));

 image_scene_item_->self_connect(SIGNAL(get_annotation_comments_requested(DHAX_Annotation_Instance*)),
   main_window_receiver_, SLOT(handle_get_annotation_comments(DHAX_Annotation_Instance*)));


 image_scene_item_->self_connect(SIGNAL(meshlab_import_info_requested()),
   main_window_receiver_, SLOT(handle_meshlab_import_info()));
   //show_meshlab_import_info

 image_scene_item_->self_connect(SIGNAL(freecad_import_info_requested()),
   main_window_receiver_, SLOT(handle_freecad_import_info()));

 image_scene_item_->self_connect(SIGNAL(draw_bezier_requested()),
   main_window_receiver_,
   SLOT(handle_draw_bezier()));

 image_scene_item_->self_connect(SIGNAL(draw_cubic_path_requested()),
   main_window_receiver_,
   SLOT(handle_draw_cubic_path()));

 image_scene_item_->self_connect(SIGNAL(draw_quad_path_requested()),
   main_window_receiver_,
   SLOT(handle_draw_quad_path()));

// image_scene_item_->self_connect(SIGNAL(meshlab_reset_requested()),
//   main_window_receiver_,
//   SLOT(send_meshlab_reset()));

// image_scene_item_->self_connect(SIGNAL(freecad_import_info_requested()),
//   main_window_receiver_,
//   SLOT(show_freecad_import_info()));


}



void DHAX_Main_Window_Controller::init_polyline()
{
 display_image_data_->init_polyline();
}


void DHAX_Main_Window_Controller::complete_polygon()
{
 display_image_data_->complete_polygon();
 image_scene_item_->update();

// DHAX_Drawn_Shape* dds = display_image_data_->current_drawn_shape();
// if(!dds)
//   return;
// dds->points().push_back(dds->points().first());

}


#include "libspline/aaCurve.h"
#include "libspline/spline.h"

void DHAX_Main_Window_Controller::draw_demo_bezier()
{
 DHAX_Drawn_Shape* cdds = display_image_data_->active_curve();
 if(!cdds)
   return;

 QPoint _p1 = cdds->points()[0];
 QPoint _p2 = cdds->points()[1];
 QPoint _mid = cdds->extra_points()[0];


 QPoint p1 = image_viewer_->control_center(1).toPoint();
 QPoint mid = image_viewer_->control_center(2).toPoint();
 QPoint p2 = image_viewer_->control_center(3).toPoint();

 qDebug() << "_p1 = " << _p1;
 qDebug() << "_p2 = " << _p2;
 qDebug() << "_mid = " << _mid;

 qDebug() << "p1 = " << p1;
 qDebug() << "p2 = " << p2;
 qDebug() << "mid = " << mid;

 std::vector<aaAaa::aaSpline> splines;

 aaAaa::aaSpline spline;
 spline.addKnots(aaAaa::aaPoint(p1.x(), p1.y()));
 spline.addKnots(aaAaa::aaPoint(mid.x(), mid.y()));
 spline.addKnots(aaAaa::aaPoint(p2.x(), p2.y()));

 aaAaa::aaCurvePtr pspline = aaAaa::aaCurveFactory::createCurve(spline);

 aaAaa::aaSpline::KnotsList::iterator beg = spline.knots.begin();
 aaAaa::aaSpline::KnotsList::reverse_iterator rbeg = spline.knots.rbegin();

 static const int Y_FACTOR = 1;
 double m_deltaT = 0.1;

 double t = (*beg).t;
 double v = (*beg).y;
 //glVertex3f(t, v * Y_FACTOR, Z_VALUE);
 t += m_deltaT;

 while(t < (*rbeg).t - m_deltaT){
     pspline->getValue(t, v);
     if(spline.bLimited){
//         if(v > m_spline_data.limit_top)
//             v = m_spline_data.limit_top;
//         else if(v < m_spline_data.limit_bottom)
//             v = m_spline_data.limit_bottom;
     }

//     qDebug() << "t = " << t;
//     qDebug() << "v = " << v;

     QPoint ptv(t, v);
     image_viewer_->draw_circle(ptv, 2, Qt::cyan, Qt::transparent, 0);

//     glVertex3f(t, v * Y_FACTOR, Z_VALUE);
     t += m_deltaT;
 }

 t = (*rbeg).t;
 v = (*rbeg).y;


 {
  aaAaa::aaSpline spline;
  spline.addKnots(aaAaa::aaPoint(_p1.x(), _p1.y()));
  spline.addKnots(aaAaa::aaPoint(_mid.x(), _mid.y()));
  spline.addKnots(aaAaa::aaPoint(_p2.x(), _p2.y()));

  aaAaa::aaCurvePtr pspline = aaAaa::aaCurveFactory::createCurve(spline);

  aaAaa::aaSpline::KnotsList::iterator beg = spline.knots.begin();
  aaAaa::aaSpline::KnotsList::reverse_iterator rbeg = spline.knots.rbegin();

  static const int Y_FACTOR = 1;
  double m_deltaT = 0.1;

  double t = (*beg).t;
  double v = (*beg).y;
  //glVertex3f(t, v * Y_FACTOR, Z_VALUE);
  t += m_deltaT;

  static u1 color_min = 100;
  static u1 color_max = 210;
  static u1 color_inc = color_max - color_min;

  double c = 100;

  double max = (*rbeg).t - m_deltaT;
  double color_change = max - t;
  double increments = color_change / m_deltaT;
  double increment = color_inc / increments;

  qDebug() << "inc = " << increment;

  while(t < (*rbeg).t - m_deltaT){
      pspline->getValue(t, v);
      if(spline.bLimited){
 //         if(v > m_spline_data.limit_top)
 //             v = m_spline_data.limit_top;
 //         else if(v < m_spline_data.limit_bottom)
 //             v = m_spline_data.limit_bottom;
      }

 //     qDebug() << "t = " << t;
 //     qDebug() << "v = " << v;


      QPoint ptv(t, v);
      image_viewer_->draw_circle(ptv, 2, QColor(c, c + 40, 200, 140), Qt::transparent, 0);

      c += increment;

 //     glVertex3f(t, v * Y_FACTOR, Z_VALUE);
      t += m_deltaT;
  }

  t = (*rbeg).t;
  v = (*rbeg).y;
 }
}


void DHAX_Main_Window_Controller::draw_demo_cubic()
{
 DHAX_Drawn_Shape* cdds = display_image_data_->active_curve();
 if(!cdds)
   return;

 QPoint _p1 = cdds->points()[0];
 QPoint _p2 = cdds->points()[1];
 QPoint _mid = cdds->extra_points()[0];

 QPoint p1 = image_viewer_->control_center(1).toPoint();
 QPoint mid = image_viewer_->control_center(2).toPoint();
 QPoint p2 = image_viewer_->control_center(3).toPoint();

 image_viewer_->draw_circle(p1, 2, Qt::cyan, Qt::transparent, 0);
 image_viewer_->draw_circle(mid, 2, Qt::cyan, Qt::transparent, 0);
 image_viewer_->draw_circle(p2, 2, Qt::cyan, Qt::transparent, 0);

 QPainterPath path;

// display_image_->scrolled_image_pixmap_item()->mapToScene()

 path.moveTo(p1);
 path.cubicTo(mid, mid, p2);

 QGraphicsPathItem* ppi = image_viewer_->scrolled_image_scene()->addPath(path,
   QPen(QColor(25, 79, 106), 1, Qt::SolidLine,
   Qt::FlatCap, Qt::MiterJoin), QBrush(QColor(5, 122, 163, 100)));

 ppi->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
 ppi->setParentItem(image_viewer_->scrolled_image_pixmap_item()); //image_scene_item_->this_proxy_widget()->graphicsItem());

    //image_viewer_->scrolled_image_pixmap_item());

}


void DHAX_Main_Window_Controller::draw_demo_quad()
{
 DHAX_Drawn_Shape* cdds = display_image_data_->active_curve();
 if(!cdds)
   return;

 QPoint _p1 = cdds->points()[0];
 QPoint _p2 = cdds->points()[1];
 QPoint _mid = cdds->extra_points()[0];

 QPoint p1 = image_viewer_->control_center(1).toPoint();
 QPoint mid = image_viewer_->control_center(2).toPoint();
 QPoint p2 = image_viewer_->control_center(3).toPoint();

 image_viewer_->draw_circle(p1, 2, Qt::cyan, Qt::transparent, 0);
 image_viewer_->draw_circle(mid, 2, Qt::cyan, Qt::transparent, 0);
 image_viewer_->draw_circle(p2, 2, Qt::cyan, Qt::transparent, 0);

 QPainterPath path;

// display_image_->scrolled_image_pixmap_item()->mapToScene()

 path.moveTo(p1);
 path.quadTo(mid, p2);

 QGraphicsPathItem* ppi = image_viewer_->scrolled_image_scene()->addPath(path,
   QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
   Qt::FlatCap, Qt::MiterJoin), QBrush(QColor(39, 122, 163, 100)));

 ppi->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
 ppi->setParentItem(image_viewer_->scrolled_image_pixmap_item());

}

void DHAX_Main_Window_Controller::check_init_document_controller()
{
 if(!document_controller_)
 {
  document_controller_ = new PDF_Document_Controller;
  document_controller_->set_page_and_search_frame(page_and_search_frame_);

  _self_connect_(page_and_search_frame_ ,page_select_requested)
    << [this](u4 page)
  {
   document_controller_->switch_to_page(page);
   reinit_pdf_page_view(page);
  // display_image_data_->unset_multi_draw();
  };

 }
}

void DHAX_Main_Window_Controller::delayed_image_viewer_recenter_scroll_top_left()
{
 QTimer::singleShot(0, [this]
 {
  image_viewer_->recenter_scroll_top_left();
 });
}

void DHAX_Main_Window_Controller::load_pdf()
{
 QString ws =  ROOT_FOLDER "/../pdf";

 QString filters = "PDF Files (*.pdf)";

 QString file_path = QFileDialog::getOpenFileName(application_main_window_, "Open Image", ws, filters);

 if(file_path.isEmpty())
   return;

 check_init_document_controller();

 document_controller_->load_document(file_path);

 QPair dpis {image_viewer_->physicalDpiX(), image_viewer_->physicalDpiY()};
 document_controller_->load_page(dpis);

 init_pdf_page_view();
}

void DHAX_Main_Window_Controller::reinit_pdf_page_view(u4 page)
{
 init_pdf_page_view();
}

void DHAX_Main_Window_Controller::init_pdf_page_view()
{
 image_viewer_->load_image(document_controller_->pixmap());
 delayed_image_viewer_recenter_scroll_top_left();
}

void DHAX_Main_Window_Controller::load_image()
{
 QString ws =  ROOT_FOLDER "/../pics";

 QString filters = "Images (*.jpg *.png *.bmp)";
 QFileDialog qdialog;

 QString file_path = qdialog.getOpenFileName(application_main_window_, "Open Image", ws, filters);

 if(!file_path.isNull())
 {
  load_image(file_path);
 }

}

void DHAX_Main_Window_Controller::load_image(QString file_path)
{
 current_image_file_path_ = file_path;
 display_image_data_->setNameSelected(true);

 zoom_frame_->reset_with_image_data(&current_image_file_path_);

 image_viewer_->load_image(current_image_file_path_);

// display_->update();
// display_->repaint();

 init_image_scene_item(image_viewer_->image_scene_item());

 delayed_image_viewer_recenter_scroll_top_left();

}


void DHAX_Main_Window_Controller::take_screenshot()
{
 QScreen* screen = QGuiApplication::primaryScreen();
 if (!screen)
   return;

 QTimer::singleShot(10000, [=]
 {
  QPixmap pixmap = screen->grabWindow(application_main_window_->winId());
  QString path = SCREENSHOTS_FOLDER "/dhax.png";
  qDebug() << "Saving to path: " << path;

  QFile file(path);
  if(file.open(QIODevice::WriteOnly))
  {
   pixmap.save(&file, "PNG");
  }
 });

}

