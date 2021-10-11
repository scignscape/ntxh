
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef USER_INFO__H
#define USER_INFO__H

#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QByteArray>

#include <QDateTime>

#include "al-wrap.h"


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


AL_WRAP_DECL(User_Info ,User)

//(u1&), Test_Enum ,test_enum    )field(,\
//(u1&), Test_Enum_Flags ,test_enum_flags)

class User_Info
{
 QString name_; // DICOM Pname
 QString login_name_;
 QString role_in_trial_;
 u4 number_within_role_in_trial_;


public:

 User_Info();

 AL_WRAP_CLASS(User)


 ACCESSORS(QString ,name)
 ACCESSORS(QString ,login_name)
 ACCESSORS(QString ,role_in_trial)
 ACCESSORS(u4 ,number_within_role_in_trial)


 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // USER_INFO__H
