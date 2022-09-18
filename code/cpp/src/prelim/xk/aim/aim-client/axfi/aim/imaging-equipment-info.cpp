

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "imaging-equipment-info.h"

#include <QDataStream>

#include "AIMLib/stdafx.h"

#include "AIMLib/entity/Equipment.h"


Imaging_Equipment_Info::Imaging_Equipment_Info()
 // :  axfi_annotation_group_(new AXFI_Annotation_Group)
{

}

//void Imaging_Equipment_Info AL_INIT

//AL_INIT(Imaging_Equipment_Info)
AL_INIT(Equipment)

void Imaging_Equipment_Info::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << a_string_ << a_number_;


#define TEMP_MACRO(cast, type ,name) << cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO


}

void Imaging_Equipment_Info::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
// qds >> a_string_ >> a_number_;


#define TEMP_MACRO(cast, type ,name) >> cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO
}



