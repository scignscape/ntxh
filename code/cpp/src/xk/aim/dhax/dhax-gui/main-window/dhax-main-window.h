
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW__H
#define DHAX_MAIN_WINDOW__H


#include <QMainWindow>

#include "accessors.h"


class DHAX_Main_Window_Data;
class DHAX_Main_Window_Menus;
class DHAX_Signal_Generator;



class DHAX_Main_Window : public QMainWindow
{
 DHAX_Main_Window_Data* main_window_data_;
 DHAX_Main_Window_Menus* menus_;
 DHAX_Signal_Generator* signal_generator_;

public:

 DHAX_Main_Window();

 ACCESSORS(DHAX_Signal_Generator* ,signal_generator)


 void init_menus();
 void init_signal_generator();


};


#endif //  DHAX_MAIN_WINDOW__H


