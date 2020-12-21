
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGH_SDI_DOCUMENT__H
#define DGH_SDI_DOCUMENT__H

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>

#include "global-types.h"

#include "ntxh-parser/ntxh-document.h"


class NGML_SDI_Paragraph;

//KANS_CLASS_DECLARE(HGDMCore ,NTXH_Graph)
//USING_KANS(HGDMCore)


KANS_(DGH)

class DGH_SDI_Sentence;
class DGH_SDI_Paragraph;


class DGH_SDI_Document
{
 QVector<DGH_SDI_Paragraph*> paragraphs_;

public:

 DGH_SDI_Document();

 //void parse_sentence_start_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);
 void parse_paragraph_hypernode(NTXH_Graph& g, NTXH_Graph::hypernode_type* hn);

 void load_from_ntxh(QString path);

 void review_dgh();

};


_KANS(GHL)

#endif // DGH_SDI_DOCUMENT__H
