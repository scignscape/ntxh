
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DATASET_INFO__H
#define DATASET_INFO__H

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

class Qh_Pack_Builder;

KANS_(DSM)

class Language_Sample;
class Language_Sample_Group;


class DSM_SDI_Document;

class Dataset;

class Dataset_Info
{
 Dataset* ds_;

 u4 number_of_samples_;
 u4 number_of_groups_;

public:

 Dataset_Info(Dataset* ds);

 Dataset_Info();

 ACCESSORS(Dataset* ,ds)


 void supply_pack(Qh_Pack_Builder& qpb);
 void absorb_pack(Qh_Pack_Builder& qpb);

 void supply_opaque(QByteArray& qba);
 void absorb_opaque(const QByteArray& qba);

};


_KANS(DSM)

#endif // DATASET_INFO__H
