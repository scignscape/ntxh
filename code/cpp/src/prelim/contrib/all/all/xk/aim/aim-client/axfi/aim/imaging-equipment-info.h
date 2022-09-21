
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef IMAGING_EQUIPMENT_INFO__H
#define IMAGING_EQUIPMENT_INFO__H

#include "accessors.h"

#include "global-types.h"

#include "al-wrap.h"


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



AL_WRAP_DECL(Imaging_Equipment_Info ,Equipment)

//class Imaging_Equipment_Info;
//namespace aim_lib{ class Equipment; } \
//template<> struct wrapper_for<aim_lib::Equipment> { typedef Imaging_Equipment_Info _class; };


//namespace aim_lib{ class Equipment; }

//using namespace aim_lib;

class Imaging_Equipment_Info
{
 QString manufacturer_name_;
 QString manufacturer_model_name_;
 QString software_version_;
 QString device_serial_number_;


public:

 AL_WRAP_CLASS(Equipment)

// class _al {
//   friend class Imaging_Equipment_Info;
//   Equipment* object_;

// public:

//   ACCESSORS(Equipment* ,object)
// };

// _al al;
// void alinit();

 Imaging_Equipment_Info();


 ACCESSORS(QString ,manufacturer_name)
 ACCESSORS(QString ,manufacturer_model_name)
 ACCESSORS(QString ,software_version)
 ACCESSORS(QString ,device_serial_number)

 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // IMAGING_EQUIPMENT_INFO__H
