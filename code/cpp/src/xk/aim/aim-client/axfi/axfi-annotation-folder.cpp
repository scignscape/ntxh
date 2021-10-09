

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "axfi-annotation-folder.h"

#include <QDataStream>
#include <QDirIterator>


#include "axfi-annotation-folder.h"


AXFI_Annotation_Folder::AXFI_Annotation_Folder()
{

}


void AXFI_Annotation_Folder::read_path(QString path)
{
 path_ = path;

 QDirIterator qdi(path, {"*.xml"});

 while(qdi.hasNext())
 {
  qdi.next();
  aim_files_ << qdi.fileInfo().canonicalFilePath();
 }

}

void AXFI_Annotation_Folder::supply_data(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << a_string_ << a_number_;


#define TEMP_MACRO(cast, type ,name) << cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO


}

void AXFI_Annotation_Folder::absorb_data(const QByteArray& qba)
{
 QDataStream qds(qba);
// qds >> a_string_ >> a_number_;


#define TEMP_MACRO(cast, type ,name) >> cast name##_
// qds _Demo_Class_fm(TEMP_MACRO);
#undef TEMP_MACRO
}



