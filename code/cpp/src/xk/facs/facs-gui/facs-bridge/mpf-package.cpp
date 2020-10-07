
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "mpf-package.h"

#include "qvector-matrix-r8.h"


#include <QFile>
#include <QDataStream>

#include "kans.h"

USING_KANS(MPF)

MPF_Package::MPF_Package(u4 number_of_dimensions)
 : number_of_dimensions_(number_of_dimensions),
   matrix_(nullptr), raw_data_length_(0)
{
 dimension_shifts_ = QVector<s4>(number_of_dimensions_, 1);
 dimension_skews_ = QVector<s4>(number_of_dimensions_, 1);
 columns_ = QVector<u1>(number_of_dimensions_, 0);
}

void MPF_Package::init_dimensions(u4 number_of_dimensions)
{
 number_of_dimensions_ = number_of_dimensions;
 dimension_shifts_ = QVector<s4>(number_of_dimensions_, 1);
 dimension_skews_ = QVector<s4>(number_of_dimensions_, 1);
 columns_ = QVector<u1>(number_of_dimensions_, 0);
}


void MPF_Package::save_to_file(QString path)
{
 QFile qf(path);
 if(!qf.open( QIODevice::WriteOnly ))
   return;
 QDataStream qds(&qf);
 qds << data_file_path_ << fcs_file_path_ << number_of_dimensions_ <<
   dimension_shifts_ << dimension_skews_ << columns_ << raw_data_length_;

 if(raw_data_length_ > 0)
 {
  if(matrix_)
    matrix_->save_to_datastream(qds);
 }

 qf.close();
}

void MPF_Package::load_from_file(QString path)
{
 QFile qf(path);
 if(!qf.open( QIODevice::ReadOnly ))
   return;
 QDataStream qds(&qf);
 qds >> data_file_path_ >> fcs_file_path_  >> number_of_dimensions_ >>
   dimension_shifts_ >> dimension_skews_ >> columns_ >> raw_data_length_;

 if(raw_data_length_ > 0)
 {
  if(!matrix_)
    matrix_ = new QVector_Matrix_R8;
  matrix_->load_from_datastream(qds);
 }

 qf.close();
}



