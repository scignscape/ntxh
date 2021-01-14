
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DSM_SDI_DOCUMENT__H
#define DSM_SDI_DOCUMENT__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

#include "ntxh-parser/ntxh-document.h"


class NGML_SDI_Paragraph;

//KANS_CLASS_DECLARE(HGDMCore ,NTXH_Graph)
//USING_KANS(HGDMCore)


KANS_(DSM)


class Language_Sample_Group;
class Language_Sample;


class DSM_SDI_Document
{
 QVector<Language_Sample_Group*> language_sample_groups_;
 QVector<Language_Sample*> language_samples_;

public:

 DSM_SDI_Document();

 void parse_group_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);
 void parse_sample_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);

 void load_from_ntxh(QString path);


};


_KANS(DSM)

#endif // DSM_SDI_DOCUMENT__H
