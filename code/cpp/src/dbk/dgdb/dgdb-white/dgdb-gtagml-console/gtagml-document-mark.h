
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef GTAGML_DOCUMENT_MARK__H
#define GTAGML_DOCUMENT_MARK__H

#include "accessors.h"

#include "global-types.h"

#include "dgdb-white/dw-stage-value.h"

#include <QString>
#include <QByteArray>

#include "kans.h"
USING_KANS(DGDB)

KANS_CLASS_DECLARE(DGDB ,DW_Stage_Value)
KANS_CLASS_DECLARE(DGDB ,DW_Stage_Queue)

class GTagML_Document_Mark
{
 u4 document_id_;

 QString text_;
 QString annotation_;
 u4 start_;
 u4 end_;
 u4 layer_;
 
public:

 GTagML_Document_Mark(u4 document_id, QString text);
 GTagML_Document_Mark();

 ACCESSORS(QString ,text)
 ACCESSORS(QString ,annotation)

 ACCESSORS(u4 ,document_id)

 ACCESSORS(u4 ,start)
 ACCESSORS(u4 ,end)
 ACCESSORS(u4 ,layer)

 void encode_stage_values(QByteArray& qba,
   DW_Stage_Value::Callback_type cb);

 void read_stage_queue(QQueue<void*>& vals);
 
 static void init_stage_queue(const QByteArray& qba, 
   QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq); 

};



#endif // GTAGML_DOCUMENT_MARK__H
