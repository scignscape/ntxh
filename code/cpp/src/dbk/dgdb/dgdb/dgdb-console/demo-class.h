
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DEMO_CLASS__H
#define DEMO_CLASS__H 

#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QByteArray>

#include <QDateTime>


// //  defines the serialization order ...
#define _Demo_Class_fm(field    )field(,\
 QDateTime ,datetime_for_query  )field(,\
 QTime ,time_for_query          )field(,\
 QDate ,date_for_query          )field(,\
 QString ,string_in_record      )field(,\
 QString ,string_for_query      )field(,\
 u4 ,u4_in_block                )field(,\
 u4 ,u4_for_query               )field(,\
 s1 ,s1_in_block                )field(,\
 s2 ,s2_for_query               )field(,\
 QDate ,date_in_block           )field(,\
 QTime ,time_in_block           )field(,\
 QDateTime ,datetime_in_block   )\
 /* enum fields need cast ... */ \
field((u1&), Test_Enum_Flags ,test_enum_flags)\
field((u1&), Test_Enum ,test_enum)\




// // //  defines the serialization order ...
//#define _Demo_Class_fm(field    )field(,\
// QString ,string_in_record      )field(,\
// QString ,string_for_query      )field(,\
// u4 ,u4_in_block                )field(,\
// u4 ,u4_for_query               )field(,\
// s1 ,s1_in_block                )field(,\
// s2 ,s2_for_query               )field(,\
// QDateTime ,datetime_in_block   )field(,\
// QDateTime ,datetime_for_query  )field(,\
// QTime ,time_in_block           )field(,\
// QTime ,time_for_query          )field(,\
// QDate ,date_in_block           )field(,\
// QDate ,date_for_query          )\
//\
//field((u1&), Test_Enum ,test_enum)\
//field((u1&), Test_Enum_Flags ,test_enum_flags)


class Demo_Class
{

public:

 enum class Test_Enum {
   Enum_Val_0,
   Enum_Val_1,
   Enum_Val_2,
   Enum_Val_3,
 };

 enum class Test_Enum_Flags {
   Enum_Flags_1 = 1,
   Enum_Flags_2 = 2,
   Enum_Flags_4 = 4,
   Enum_Flags_8 = 8,
 };

 ENUM_FLAGS_OP_MACROS(Test_Enum_Flags)


private:

#define fields(cast, type ,name) type name##_;
_Demo_Class_fm(fields)
#undef fields

// QString string_in_record_;
// QString string_for_query_;
// u4 u4_in_block_;
// u4 u4_for_query_;
// s1 s1_in_block_;
// s2 s2_for_query_;
// QDateTime datetime_in_block_;
// QDateTime datetime_for_query_;
// QDate date_in_block_;
// QDate date_for_query_;

public:

 Demo_Class();

#define fields(cast, type ,name) ACCESSORS(type ,name);
 _Demo_Class_fm(fields)
#undef fields



 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // DEMO_CLASS__H 
