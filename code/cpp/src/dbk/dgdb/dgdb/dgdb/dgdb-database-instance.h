
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_DATABASE_INSTANCE__H
#define DGDB_DATABASE_INSTANCE__H

#include <QByteArray>

#include <functional>

#include "global-types.h"

#include "accessors.h"


#include "tkrzw/tkrzw_dbm_hash.h"

#include "dgdb-location-structure.h"

#include <QVariant>

class DGDB_Hypernode;

class DGDB_Database_Instance
{
 QString private_folder_path_;
 QString confirmed_private_folder_path_;
 s4 hypernode_count_status_;
 u2 pinterns_count_;
 u2 finterns_count_;

 tkrzw::HashDBM* info_dbm_;
 tkrzw::HashDBM* pinterns_dbm_;
 tkrzw::HashDBM* finterns_dbm_;
 tkrzw::HashDBM* nodes_dbm_;

 QMap<QString, u2> property_ids_;
 QMap<QString, u2> field_ids_;

public:

 static constexpr s4 _unknown = -1;
 static constexpr s4 _file_create_failed = -2;
 static constexpr s4 _folder_create_failed = -3;


 DGDB_Database_Instance(QString private_folder_path = {});

 ACCESSORS(QString ,private_folder_path)

 DGDB_Hypernode* new_hypernode();

 u2 check_field_id(QString key);
 u2 check_property_id(QString key);
 void set_property(DGDB_Hypernode* hypernode, QString key, QVariant value);

 void check_construct_files();

 s4 read_hypernode_count_status();
 void read_interns_count_status();

 tkrzw::HashDBM* check_info_dbm();
 tkrzw::HashDBM* check_nodes_dbm();

 void check_interns_dbm();
 void check_internal_dbm(QString which, tkrzw::HashDBM*& result);

 QVariant get_property(DGDB_Hypernode* hypernode, QString key);


 void store_hypernode_count_status(u4 count);
 void store_node_data(DGDB_Location_Structure dls, QVariant value);
 void store_node_data(DGDB_Location_Structure dls, QByteArray& value);

 void get_node_data(DGDB_Location_Structure dls, QVariant& result);


};


#endif // DGDB_DATABASE_INSTANCE__H


