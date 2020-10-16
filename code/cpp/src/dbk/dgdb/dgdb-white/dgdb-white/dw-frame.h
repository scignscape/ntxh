
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DW_FRAME__H
#define DW_FRAME__H

#include <QString>
#include <QVector>
#include <QMap>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

#include "flags.h"


KANS_(DGDB)

class DW_Instance;
class DW_Dominion;
class DW_Record;

struct String_Label_Triple
{
 DW_Record* source;
 QString connector_label;
 DW_Record* target;
 DW_Dominion* dom;
};

class DW_Frame
{
 DW_Instance* dw_instance_;
 u4 id_;

 QVector<String_Label_Triple> new_string_label_triples_;

public:


 ACCESSORS(u4 ,id)
 ACCESSORS(QVector<String_Label_Triple> ,new_string_label_triples)

 DW_Frame(DW_Instance* dw_instance, u4 id = 0);

 DW_Record* register_new_triple(DW_Record* source, QString connector, DW_Record* target, 
 DW_Dominion* dom);

 u4 commit();

};

struct _Frame_With_Source_and_Dominion_Connector
{
 DW_Frame* fr;
 DW_Dominion* dom;
 QString connector;
 DW_Record* source;
 DW_Record& operator>>(DW_Record* rhs)
 {
  return *fr->register_new_triple(source, connector, rhs, dom);
 } 
 DW_Record& operator>>(DW_Record& rhs)
 {
  return *fr->register_new_triple(source, connector, &rhs, dom);
 } 
};


struct _Frame_With_Dominion_Connector
{
 DW_Frame* fr;
 DW_Dominion* dom;
 QString connector;
};

struct _Frame_With_Dominion
{
 DW_Frame* fr;
 DW_Dominion* dom;
 _Frame_With_Dominion_Connector operator[](QString qs)
 {
  return {fr, dom, qs};
 }
};

inline _Frame_With_Dominion operator/(DW_Frame& fr, DW_Dominion* dom)
{
 return {&fr, dom};
}

_KANS(DGDB)


#endif // DW_FRAME__H


