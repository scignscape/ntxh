
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_MODEL__H
#define QH_MODEL__H


#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>
#include <QMap>

#include "qh-package/runtime/qh-runtime.h"

class Qh_Type_System;


KANS_(DSM)

class Language_Sample;
class Language_Sample_Group;

class DSM_SDI_Document;

class Qh_Local;

class Dataset;

class Qh_Model
{
 Dataset* dataset_;

 Qh_Runtime qh_runtime_;
 Qh_Type_System* qh_type_system_;
 Qh_Local* qh_local_;


public:

 Qh_Model(Dataset* ds);

 void init();


};


_KANS(DSM)

#endif // DATASET__H
