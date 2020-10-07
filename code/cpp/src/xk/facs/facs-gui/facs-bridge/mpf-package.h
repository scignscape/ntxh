
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef MPF_PACKAGE__H
#define MPF_PACKAGE__H


#include "kans.h"
#include "accessors.h"

#include "global-types.h"

#include <QVector>
#include <QString>

class QTextStream;

class QVector_Matrix_R8;


KANS_(MPF)

class MPF_Package
{
 QString fcs_file_path_;
 QString data_file_path_;

 u4 number_of_dimensions_;
 QVector<s4> dimension_shifts_;
 QVector<s4> dimension_skews_;

 QVector<u1> columns_;

 QVector_Matrix_R8* matrix_;

 u4 raw_data_length_;

public:

 MPF_Package(u4 number_of_dimensions = 0);

 ACCESSORS(QString ,fcs_file_path)
 ACCESSORS(QString ,data_file_path)

 ACCESSORS(u4 ,number_of_dimensions)
 ACCESSORS__RGET(QVector<s4> ,dimension_shifts)
 ACCESSORS__RGET(QVector<s4> ,dimension_skews)
 ACCESSORS__RGET(QVector<u1> ,columns)
 ACCESSORS(QVector_Matrix_R8* ,matrix)
 ACCESSORS(u4 ,raw_data_length)


 void save_to_file(QString path);
 void load_from_file(QString path);

 void init_dimensions(u4 number_of_dimensions);


};


_KANS(MPF)

#endif // NTXH_BUILDER__H
