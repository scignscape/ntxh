
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>
#include <QApplication>

#include "dhax-gui/dhax-gui-environment.h"


int main(int argc, char *argv[])
{
 QApplication qapp(argc, argv);
 DHAX_GUI_Environment dge;
 dge.init_main_window();
 dge.init_main_window_frame();
 dge.show_main_window();
 return qapp.exec();
}
