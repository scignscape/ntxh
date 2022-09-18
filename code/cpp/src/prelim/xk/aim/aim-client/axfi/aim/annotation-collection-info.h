
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef Image_Annotation_Collection_Info__H
#define Image_Annotation_Collection_Info__H

#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QByteArray>

#include <QDateTime>

#include "al-wrap.h"

#include "aim/imaging-equipment-info.h"
#include "aim/user-info.h"


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


AL_WRAP_DECL(Image_Annotation_Collection_Info ,ImageAnnotationCollection)

//(u1&), Test_Enum ,test_enum    )field(,\
//(u1&), Test_Enum_Flags ,test_enum_flags)

class Image_Annotation_Collection_Info
{
 QString description_; //  for annotation collection _description
 QDateTime datetime_; //  for annotation collection _dateTime

 Imaging_Equipment_Info equipment_;
 User_Info user_;


public:

 Image_Annotation_Collection_Info();

 AL_WRAP_CLASS(ImageAnnotationCollection)


 ACCESSORS(QString ,description) //  for annotation collection _description
 ACCESSORS(QDateTime ,datetime) //  for annotation collection _dateTime

 ACCESSORS__RGET(Imaging_Equipment_Info ,equipment)
 ACCESSORS__RGET(User_Info ,user)


 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // Image_Annotation_Collection_Info__H
