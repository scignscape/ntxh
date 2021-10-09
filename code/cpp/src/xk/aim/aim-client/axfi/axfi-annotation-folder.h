
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef AXFI_ANNOTATION_FOLDER__H
#define AXFI_ANNOTATION_FOLDER__H

#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QByteArray>

#include <QDateTime>



 // //  defines the serialization order ...
#define _Demo_Class_fm(field      )field(,\
 QString ,string_in_record        )field(,\
 QString ,string_for_query        )field(,\
 QString ,string_encoded          )field(,\
 u4 ,u4_in_block                  )field(,\
 u4 ,u4_for_query                 )field(,\
 s1 ,s1_in_block                  )field(,\
 s2 ,s2_for_query                 )field(,\
 QDateTime ,datetime_in_block     )field(,\
 QDateTime ,datetime_for_query    )field(,\
 QTime ,time_in_block             )field(,\
 QTime ,time_for_query            )field(,\
 QDate ,date_in_block             )field(,\
 QDate ,date_for_query            )field(,\
 Demo_Class::Test_Enum ,test_enum             )field(,\
 Demo_Class::Test_Enum_Flags ,test_enum_flags )\


//(u1&), Test_Enum ,test_enum    )field(,\
//(u1&), Test_Enum_Flags ,test_enum_flags)

class AXFI_Annotation_Group;
class AXFI_Annotation_Folder;

class AXFI_Annotation_Folder
{
 QString path_;

 QStringList aim_files_;

public:

 AXFI_Annotation_Folder();

 ACCESSORS(QString ,path)
 ACCESSORS__CONST_RGET(QStringList ,aim_files)

 bool is_empty() { return aim_files_.isEmpty(); }

 void read_path(QString path);

 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // AXFI_ANNOTATION_ENVIRONMENT__H
