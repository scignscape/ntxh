
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_GRAPHICS_FRAME__H
#define DHAX_GRAPHICS_FRAME__H

#include <QFrame>
#include <QBoxLayout>

#include "accessors.h"

#include "global-types.h"


class Shape_Select_Frame;
class Zoom_and_Navigate_Frame;
class DHAX_Graphics_View;
class DHAX_Display_Image_Data;
class DHAX_Image_Viewer;
class Page_and_Search_Frame;


class DHAX_Graphics_Frame : public QFrame
{
 Q_OBJECT

 QBoxLayout* main_layout_;
 QBoxLayout* secondary_layout_;
 Page_and_Search_Frame* page_and_search_frame_;
 Zoom_and_Navigate_Frame* zoom_frame_;
 Shape_Select_Frame* shape_select_frame_;
 DHAX_Graphics_View* graphics_view_;
 DHAX_Image_Viewer* image_viewer_;
 DHAX_Display_Image_Data* display_image_data_;

 const QMap<QString, QColor>* application_colors_;

public:

 DHAX_Graphics_Frame(QWidget* parent = nullptr);

 void init_layout(QBoxLayout::Direction qbd, QBoxLayout::Direction secqbd);

 ACCESSORS(DHAX_Graphics_View* ,graphics_view)
 ACCESSORS(DHAX_Display_Image_Data* ,display_image_data)
 ACCESSORS(DHAX_Image_Viewer* ,image_viewer)

 ACCESSORS(Zoom_and_Navigate_Frame* ,zoom_frame)
 ACCESSORS(Page_and_Search_Frame* ,page_and_search_frame)
 ACCESSORS(Shape_Select_Frame* ,shape_select_frame)

 ACCESSORS(MACRO_PASTE(const QMap<QString, QColor>*) ,application_colors)


 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)

 void setup_shape_rectangle();
 void setup_shape_polygon();
 void setup_shape_ellipse();
 void setup_highlight(bool checked);


Q_SIGNALS:

 void close_requested(bool);
 void save_requested();
 void image_path_show_folder_requested();

public Q_SLOTS:

 void handle_zoom_factor_changed(r8);


};

#endif //  DHAX_GRAPHICS_FRAME__H




