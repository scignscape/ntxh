
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "stat-test-image.h"

#include <QFileInfo>


Stat_Test_Image::Stat_Test_Image(QString file_path)
  :  file_path_(file_path)
{

}


QString Stat_Test_Image::file_path_with_presuffix(QString pres)
{
 QFileInfo qfi(file_path_);

 return qfi.absolutePath() + "/" +
   qfi.completeBaseName() + "." + pres + "." + qfi.suffix();
}

QString Stat_Test_Image::file_path_with_name_addon(QString addon)
{
 QFileInfo qfi(file_path_);

 return qfi.absolutePath() + "/" +
   qfi.completeBaseName() + addon + "." + qfi.suffix();
}
