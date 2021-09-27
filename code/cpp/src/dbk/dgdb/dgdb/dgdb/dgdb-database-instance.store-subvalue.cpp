
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-database-instance.h"

#include <QDir>
#include <QFileInfo>

#include "dgdb-location-structure.h"

#include "dwb/dwb-instance.h"

//#include "


#include "tkrzw/tkrzw_dbm.h"

#include "types/dh-type.h"

using namespace tkrzw;

#include <string_view>

#include "dgdb-record-processors.h"

#include "conversions.h"

#include "dgdb-hypernode.h"

#include <QDataStream>

//template<DgDb_Location_Structure::Data_Options OPTS>
//void store_subvalue_(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name);



template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::QVariant>
  (DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}


template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Numeric>
  (DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}


template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::QString>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Raw_Binary>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Shm_Pointer>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 void* mem = get_shm_field_ptr_(*this, *dh, dls.get_raw_primary_field_id(), field_name, nullptr, nullptr);

 //DH_Type* dht = dh->dh_type();
 DH_Subvalue_Field::Write_Mode wm = sf->write_mode();
 switch (wm)
 {
 case DH_Subvalue_Field::In_Block:
  memcpy(mem, value.data(), value.size());
  break;

 case DH_Subvalue_Field::Redirect_In_Block:
  break;

 case DH_Subvalue_Field::Redirect_In_Record:
  {
//   u4 sfo = sf->block_offset_start();
//   u2 sri = sf->record_column_index();
   u2 spl = sf->block_offset_record_column_split();

   u2 adj = blocks_dwb_->write_rec_field_via_split((char*)mem, spl, value);
   QByteArray qba = u2_to_qba(adj? adj : spl);
   memcpy(mem, qba.data(), qba.size());

  }
  break;

 case DH_Subvalue_Field::Redirect_External:
  {
   DWB_Instance* dwb = get_query_dwb(dh->dh_type(), *sf);
   void* rec = get_wdb_record_from_block(dh->shm_block());

   // //  assume always 2 for now ...
   static u1 rec_column = 2;

   // //  also assume the query column is the last column (so
    //    we don't need to allocate more fields than that ...)
   void* qrec = dwb->new_query_record(blocks_dwb_, rec, rec_column, sf->query_column(),
     value, sf->query_column() + 1);

   QByteArray enc = dwb->encode_record(qrec);
   memcpy(mem, enc.data(), enc.size());

//   QString qp = sf->query_path();
//   if(!qp.isEmpty())
//   {
//    DWB_Instance* dwb = get_query_dwb(qp, *sf);
//   }
  }
  break;

 }


 //ktype_<n8>::set ks(*nodes_dbm_);
 store_node_data(dls, mem);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 get_shm_field_ptr_(*this, *dh, dls.get_raw_primary_field_id(), field_name, nullptr, nullptr);
 //store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size_and_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Signed_Numeric>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_Numeric>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_QString>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_Raw_Binary>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Size>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_subvalue_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Size_and_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, DH_Subvalue_Field* sf, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}


