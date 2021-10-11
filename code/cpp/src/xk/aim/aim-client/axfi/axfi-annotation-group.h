
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFI_ANNOTATION_GROUP__H
#define AXFI_ANNOTATION_GROUP__H

#include <QString>
#include <QPoint>
#include <QVector>


#include "accessors.h"
#include "flags.h"

#include "global-types.h"

#include "axfi-location-2d.h"


#include <functional>

#include <QDateTime>

#include "kans.h"


//KANS_(GTagML)

class AXFI_Annotation;
class AXFI_Environment_Settings;

class AXFI_Annotation_Group
{
// flags_(1)
//  bool use_pseudo_real_coordinates_;

// _flags

 AXFI_Annotation_Group* parent_group_;

 AXFI_Environment_Settings* specified_environment_settings_;

 QVector<AXFI_Annotation*> annotations_;

 n8 target_data_;


public:

 AXFI_Annotation_Group(AXFI_Annotation_Group* parent_group = nullptr);

 ACCESSORS(AXFI_Annotation_Group* ,parent_group)
 ACCESSORS__RGET( QVector<AXFI_Annotation*> ,annotations)
 ACCESSORS(AXFI_Environment_Settings* ,specified_environment_settings)
 ACCESSORS(n8 ,target_data)


 template<typename OBJECT_Type>
 OBJECT_Type* target_data_as()
 {
  return (OBJECT_Type*) target_data_;
 }

 template<typename OBJECT_Type>
 void set_target_data_as(OBJECT_Type* ptr)
 {
  target_data_ = (n8) ptr;
 }

 void add_annotation(AXFI_Annotation* axa);

};

// _KANS(GTagML)


#endif  //  AXFI_ANNOTATION_GROUP__H
