
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NDS_PROJECT__H
#define NDS_PROJECT__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

#include "ntxh-parser/ntxh-document.h"


class NGML_SDI_Document;

KANS_CLASS_DECLARE(DGH ,DGH_SDI_Document)
USING_KANS(DGH)


KANS_(NGML)


class NDS_Project
{
 NGML_SDI_Document* ngml_;
 DGH_SDI_Document* dgh_;

public:

 NDS_Project();

 ACCESSORS(NGML_SDI_Document* ,ngml)
 ACCESSORS(DGH_SDI_Document* ,dgh)

};


_KANS(NGML)

#endif // NDS_PROJECT__H
