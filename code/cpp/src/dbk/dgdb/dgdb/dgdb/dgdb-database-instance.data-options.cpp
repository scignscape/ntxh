
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-database-instance.h"

#include <QDir>
#include <QFileInfo>

#include "dgdb-location-structure.h"

#include "dh-stage-value.h"

//#include "


#include "tkrzw/tkrzw_dbm.h"

#include "types/dh-type.h"

using namespace tkrzw;

#include <string_view>

#include "dgdb-record-processors.h"

#include "dgdb-hypernode.h"

#include <QDataStream>

//template<DgDb_Location_Structure::Data_Options OPTS>
//void store_indexed_field_(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name);



template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::QVariant>
  (DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sh, //const QByteArray& value,
   QString field_name)
{
 //?// store_node_data(dls, value);
}


template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Numeric>
  (DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sh, //const QByteArray& value,
   QString field_name)
{
//?// store_node_data(dls, value);
}


//template<>
//void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::QVariant>
//(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
//{
//// store_node_data(dls, value);
//}

//template<>
//void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Numeric>
//(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
//{
//// store_node_data(dls, value);
//}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::QString>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sh, //const QByteArray& value,
 QString field_name)
{
//?// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Raw_Binary>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sh, //const QByteArray& value,
 QString field_name)
{
//?// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, QString field_name)
{
 u2 raw = dls.get_raw_primary_field_id();

 auto [fio, ix] = _class_DgDb_Location_Structure::_split_index_code(raw);

 void* mem = default_get_shm_field_ptr(dls, dh, dls.get_raw_primary_field_id(), field_name, nullptr, nullptr);

 DH_Type* dht = dh->dh_type();
 //DH_Subvalue_Field::Write_Mode wm = dht->get_write_mode(field_name);

 //DH_Subvalue_Field* sf = dht->get_subvalue_field_by_field_name(field_name);
 DH_Subvalue_Field* sf = dht->get_subvalue_field_by_index(ix);

 DH_Subvalue_Field::Write_Mode wm = sf->write_mode();

 switch (wm)
 {
 case DH_Subvalue_Field::In_Block:
  {
   QByteArray value;
   sv.to_qba(value);
   memcpy(mem, value.data(), value.size());
  }
  break;

 case DH_Subvalue_Field::Redirect_In_Block:
  break;

 case DH_Subvalue_Field::Redirect_In_Record:
  break;

 case DH_Subvalue_Field::Redirect_External:
  store_subvalue_to_external_record(dh, sf, (char*) mem, sv); //value);
  break;

 }


 //ktype_<n8>::set ks(*nodes_dbm_);
 store_node_data(dls, mem);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, // const QByteArray& value,
 QString field_name)
{
 //?get_shm_field_ptr_(*this, *dh, dls.get_raw_primary_field_id(), field_name, nullptr, nullptr);
 //store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size_and_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Signed_Numeric>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Numeric>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_QString>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Raw_Binary>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Size>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Size_and_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Stage_Value& sv, //const QByteArray& value,
 QString field_name)
{
// store_node_data(dls, value);
}


