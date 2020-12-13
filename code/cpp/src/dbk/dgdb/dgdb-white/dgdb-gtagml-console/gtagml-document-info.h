
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef GTAGML_DOCUMENT_INFO__H
#define GTAGML_DOCUMENT_INFO__H

#include "accessors.h"

#include "global-types.h"

#include "dgdb-white/dw-stage-value.h"

#include <QString>
#include <QByteArray>


#include <functional>


#include "kans.h"
USING_KANS(DGDB)

KANS_CLASS_DECLARE(DGDB ,DW_Stage_Value)
KANS_CLASS_DECLARE(DGDB ,DW_Stage_Queue)


class GTagML_Document_Mark;


class GTagML_Document_Info
{
 u4 in_database_id_;
 QString document_title_;

 QMap<QString, QStringList> citations_;


 typedef QMap<u4, QPair<QString, u4>> mark_map_type;

 mark_map_type main_mark_map_;
 mark_map_type optional_argument_mark_map_;
 mark_map_type mandatory_argument_mark_map_;
 mark_map_type auxiliary_mark_map_;

 QDateTime created_;
 QDateTime modified_;

 QMultiMap<QString, QString> info_params_;

 std::function<n8 (GTagML_Document_Mark&)> mark_register_fn_;

 void register_marks(QVector<GTagML_Document_Mark*>& ms,
   u4 layer, mark_map_type& mark_map);

// static void static_set_mark_register_fn(GTagML_Document_Info& _this,
//   std::function<u4(GTagML_Document_Mark&)> fn)
// {
//  _this.set_mark_register_fn(fn);
// }
// fn_setter<GTagML_Document_Info, std::function<u4(GTagML_Document_Mark&)>>
//   set_mark_register_fn_;
// ACCESSORS_FN_SETTER_DECLARE(GTagML_Document_Info
//   ,u4 (GTagML_Document_Mark&)
//   ,mark_register_fn)


public:

 GTagML_Document_Info();

 ACCESSORS(QString ,document_title)

 ACCESSORS(u4 ,in_database_id)

 //ACCESSORS_FN_SET(u4(GTagML_Document_Mark&) ,mark_register_fn)

 ACCESSORS_FN_VIA_OP(GTagML_Document_Info
   ,n8 (GTagML_Document_Mark&)
   ,mark_register_fn)


 void load_marks(QString path);
 void register_marks();


// ACCESSORS(QString ,a_string)
// ACCESSORS(u4 ,a_number)


 void encode_stage_values(QByteArray& qba,
   DW_Stage_Value::Callback_type cb);

 void read_stage_queue(QQueue<void*>& vals);

 static void init_stage_queue(const QByteArray& qba,
   QMap<u4, DW_Stage_Value>& qm, DW_Stage_Queue& sq);

 void supply_data(QByteArray& qba);
 void absorb_data(const QByteArray& qba);


};



#endif // GTAGML_DOCUMENT_INFO__H
