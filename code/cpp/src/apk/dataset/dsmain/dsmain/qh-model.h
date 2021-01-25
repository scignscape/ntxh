
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef QH_MODEL__H
#define QH_MODEL__H

#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "qring/qring-file-structure.h"

#include "dsm-sdi-document.h"

#include "discourse-markup-sample.h"

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>
#include <QMap>

//#define PASTE_EXPRESSION(...) __VA_ARGS__


KANS_(DSM)

class Language_Sample;
class Language_Sample_Group;

class DSM_SDI_Document;

class Dataset;

class Qh_Model
{
 Dataset* ds_;

public:

 Qh_Model(Dataset* ds);

 void init();


};


_KANS(DSM)

#endif // DATASET__H
