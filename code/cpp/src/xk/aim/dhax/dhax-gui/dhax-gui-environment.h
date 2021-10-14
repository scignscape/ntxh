
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_GUI_ENVIRONMENT__H
#define DHAX_GUI_ENVIRONMENT__H


class DHAX_Main_Window;
class DHAX_Graphics_View;
class DHAX_Main_Window_Frame;


class DHAX_GUI_Environment
{
 DHAX_Main_Window* main_window_;
 DHAX_Graphics_View* graphics_view_;
 DHAX_Main_Window_Frame* main_window_frame_;

public:

 DHAX_GUI_Environment();

 void init_main_window();
 void init_graphics_view();
 void init_graphics_frame();
 void init_main_window_frame();
 void show_main_window();

};


#endif //  DHAX_GUI_ENVIRONMENT__H


