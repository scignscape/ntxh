
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-database-instance.h"

#include <QDir>
#include <QFileInfo>

#include "dgdb-location-structure.h"

//#include "


#include "tkrzw/tkrzw_dbm.h"

using namespace tkrzw;

#include <string_view>

#include "dgdb-record-processors.h"

#include "dgdb-hypernode.h"

#include <QDataStream>

//template<DgDb_Location_Structure::Data_Options OPTS>
//void store_indexed_field_(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name);



template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::QVariant>
  (DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}


template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Numeric>
  (DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}


//template<>
//void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::QVariant>
//(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
//{
// store_node_data(dls, value);
//}

//template<>
//void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Numeric>
//(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
//{
// store_node_data(dls, value);
//}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::QString>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Raw_Binary>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 void* mem = get_shm_field_ptr_(*this, *dh, dls.get_raw_primary_field_id(), field_name, nullptr, nullptr);
 memcpy(mem, value.data(), value.size());

 //ktype_<n8>::set ks(*nodes_dbm_);
 store_node_data(dls, mem);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 get_shm_field_ptr_(*this, *dh, dls.get_raw_primary_field_id(), field_name, nullptr, nullptr);
 //store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Shm_Pointer_With_Size_and_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Signed_Numeric>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Numeric>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_QString>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Raw_Binary>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Size>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}

template<>
void DgDb_Database_Instance::store_indexed_field_<DgDb_Location_Structure::Data_Options::Typed_Shm_Pointer_With_Size_and_Path_Code>
(DgDb_Location_Structure dls, DgDb_Hypernode* dh, const QByteArray& value, QString field_name)
{
 store_node_data(dls, value);
}


