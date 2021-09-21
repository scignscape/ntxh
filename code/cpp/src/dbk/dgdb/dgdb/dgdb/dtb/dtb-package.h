
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DTB_PACKAGE__H
#define DTB_PACKAGE__H

#include <QByteArray>

#include <QVariant>

#include <functional>

#include "global-types.h"

#include "accessors.h"

#include <sys/types.h>

#include "tkrzw/tkrzw_dbm_hash.h"

#include "dgdb-location-structure.h"


class DTB_Package
{

 QMap<QString, u2> property_ids_;
 QMap<QString, u2> field_ids_;

public:

 DTB_Package();

 tkrzw::HashDBM* info_dbm_;
 tkrzw::HashDBM* pinterns_dbm_;
 tkrzw::HashDBM* finterns_dbm_;
 tkrzw::HashDBM* nodes_dbm_;

 u2 pinterns_count_;
 u2 finterns_count_;


 tkrzw::HashDBM* check_info_dbm(QString folder_path);
 tkrzw::HashDBM* check_nodes_dbm(QString folder_path);
 void check_internal_dbm(QString folder_path, QString which, tkrzw::HashDBM*& result);

 void store_hypernode_count_status(u4 count);

 void check_interns_dbm(QString folder_path);

 s4 read_hypernode_count_status();
 void read_interns_count_status(); //u2& p, u2& f);

 void fetch_node_data(DgDb_Location_Structure dls, QVariant& result);
 void fetch_node_data(DgDb_Location_Structure dls, QByteArray& result);
 void fetch_node_data(DgDb_Location_Structure dls, void*& result);

 void store_node_data(DgDb_Location_Structure dls, void* value);

 void store_node_data(DgDb_Location_Structure dls, const QByteArray& value);
 u2 check_property_id(QString key);
 u2 check_field_id(QString key);


};


#endif // DWB_INSTANCE__H


