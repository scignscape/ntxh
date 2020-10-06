
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef HGDM_ANGEL_RUNTIME_CONTEXT__H
#define PHRA_ANGEL_RUNTIME_CONTEXT__H

#include <QDebug>
#include <QVector>
#include <QString>

//#include "angelscript.h"

#include "accessors.h"

#include "global-types.h"

#include <string>

#include "kans.h"

class hQVariant;

KANS_CLASS_DECLARE(MPF ,MPF_Package_HGDM)

USING_KANS(MPF)

class HGDM_Angel_Runtime_Context
{
 int ref_count_;
 
 MPF_Package_HGDM* pkg_;

public:

 HGDM_Angel_Runtime_Context();

 ACCESSORS(MPF_Package_HGDM* ,pkg)

 HGDM_Angel_Runtime_Context* selto_ss(const std::string& ss);
 HGDM_Angel_Runtime_Context* init2();
 HGDM_Angel_Runtime_Context* init3();

 hQVariant* read_hqv();
 HGDM_Angel_Runtime_Context* pval();

 void add_ref();
 void release();
};


#endif //  HGDM_ANGEL_RUNTIME_CONTEXT__H

