
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>
#include <QApplication>

#include "dhax-gui/dhax-gui-environment.h"

#include "dhax-data/ann/dhax-annotation-environment.h"
#include "dhax-data/ann/dhax-annotation-instance.h"
#include "dhax-data/ann/dhax-annotation-folder.h"
#include "dhax-data/ann/dhax-annotation-group.h"


int main(int argc, char *argv[])
{
 QApplication qapp(argc, argv);
 DHAX_GUI_Environment dge;
 dge.init_main_window();
 dge.init_main_window_frame();
 dge.init_graphics_view();
 dge.init_graphics_scene();
 dge.init_image_viewer();
 dge.init_graphics_frame();
 dge.init_graphics_frame_layout(QBoxLayout::TopToBottom, QBoxLayout::LeftToRight);
 dge.init_main_window_frame_layout(QBoxLayout::TopToBottom);

 DHAX_Annotation_Environment& dae = *dge.init_annotation_environment();
 dae.default_extensions();

 DHAX_Annotation_Folder* daf = dae.add_image_folder(DHAX_IMAGE_FOLDER);
 if(daf->images_is_empty())
   return 0;

 QString fp = daf->image_files().first();
 dge.show_image(fp);

 DHAX_Annotation_Group* dag = dae.add_annotation_group(fp);

 DHAX_Annotation_Instance* dai = dag->add_annotation();
 dai->default_dimensions();

// dai->init_polygon();

 dai->init_rectangle();

 dai->add_shape_point(5,5);
 dai->add_shape_point(25,35);
 //?dai->add_shape_point(15,45);

 dge.show_annotation_on_current_image(dai);

// DHAX_Location_2d* loc = (DHAX_Location_2d*) dai->locations().first();
// n8 enc = loc->encode8();
// loc->check_decode8(enc);

 //dge.add_image(DHAX_IMAGE_FOLDER "/t1.png");
 dge.show_main_window();
 return qapp.exec();
}
