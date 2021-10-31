
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW_DATA__H
#define DHAX_MAIN_WINDOW_DATA__H

#include <QMainWindow>

class DHAX_Meshlab_Integration_Data;
class DHAX_FreeCAD_Integration_Data;
class DHAX_FORGE_API_Integration_Data;


class DHAX_Main_Window_Data
{
 DHAX_Meshlab_Integration_Data* meshlab_integration_;
 DHAX_FreeCAD_Integration_Data* freecad_integration_;
 DHAX_FORGE_API_Integration_Data* forge_api_integration_;

public:

 DHAX_Main_Window_Data();

};


#endif //  DHAX_MAIN_WINDOW_DATA__H


