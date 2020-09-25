
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_INSTANCE__H
#define DGDB_INSTANCE__H

#include <QString>

#include <QMap>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

#ifndef REGISTER_TYPE_NAME_RESOLUTION
#define REGISTER_TYPE_NAME_RESOLUTION(tn) \
register_type_name_resolution<tn>(#tn)
#endif

#ifndef REGISTER_TYPE_NAME_RESOLUTION_2_1
#define REGISTER_TYPE_NAME_RESOLUTION_2_1(ho_tname ,tn) \
register_type_name_resolution<ho_tname<tn>>("(" #ho_tname \
  " " #tn ")")
#endif

#ifndef REGISTER_TYPE
#define REGISTER_TYPE(tn) \
register_type_with_name_resolution<tn>(#tn)
#endif


#include "flags.h"


KANS_(DGDB)

class DgDb_Node;
class DgDb_Frame;
class DgDb_Type;

class DgDb_Type_Builder;
class WDB_Manager;
class WG_Stage_Value;
class WG_Stage_Queue;
class WDB_Instance;


class DgDb_Instance
{
 QString db_root_folder_;
 DgDb_Frame* default_frame_;
 DgDb_Frame* current_frame_;

 DgDb_Node* _add(void* v, QString tn);

 QMap<QString, QString> type_name_resolutions_;

 QMap<QString, DgDb_Type*> types_by_name_;

 DgDb_Type_Builder* current_type_builder_;

 WDB_Manager* wdb_manager_;

public:

 struct _Config
 {
  flags_(1)
   bool scratch_mode:1;
   bool local_scratch_mode:1;
   bool auto_stage:1;
   bool auto_commit:1;
  _flags

  _Config() : Flags(0) {}  
 };

 _Config Config; 

 ACCESSORS(QString ,db_root_folder)
 ACCESSORS(WDB_Manager* ,wdb_manager)

 DgDb_Instance();

 void init(); 

 void* new_wg_record(QByteArray& qba, QMap<u4, WG_Stage_Value>& wsvs,
   u4 qba_index = 0, WDB_Instance* wdbi = nullptr);

 void parse_wg_record(void* rec, std::function<void(const QByteArray&, 
   QMap<u4, WG_Stage_Value>&, WG_Stage_Queue& sq//, QQueue<void*>&
   )> cb, u4 qba_index = 0, WDB_Instance* wdbi = nullptr);

 void init_from_ntxh(QString fld, u1 code);

 void build_default_types();

 void to_ntxh(QString& ty, QString& result);

 DgDb_Type* get_type_by_name(QString tn);
 DgDb_Type& register_type(QString tn, QString ctn = QString());

 template<typename VERTEX_Type>
 QString register_type_name_resolution(QString desired)
 {
  QString tn = QString::fromStdString(typeid(VERTEX_Type).name());
  type_name_resolutions_[tn] = desired;
  return tn;
 }

 template<typename VERTEX_Type>
 DgDb_Type& register_type_with_name_resolution(QString desired)
 {
  QString ctn = register_type_name_resolution<VERTEX_Type>(desired);
  return register_type(desired, ctn);
 }

 template<typename VERTEX_Type>
 DgDb_Node* add(VERTEX_Type* v)
 {
  QString tn = QString::fromStdString(typeid(VERTEX_Type).name());
  tn = type_name_resolutions_.value(tn, tn);
  _add((void*) v, tn);
 }

};


_KANS(DGDB)

#endif // DGDB_INSTANCE__H
