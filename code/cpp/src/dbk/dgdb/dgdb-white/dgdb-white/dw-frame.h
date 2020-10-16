
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DW_FRAME__H
#define DW_FRAME__H

#include <QString>

#include <QMap>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

#include "flags.h"


KANS_(DGDB)

class DW_Instance;
class DW_Dominion;


class DW_Frame
{
 DW_Instance* dw_instance_;
 u4 id_;

public:


 ACCESSORS(u4 ,id)

 DW_Frame(DW_Instance* dw_instance, u4 id = 0);


};

struct _Frame_With_Dominion_QString
{
 DW_Frame fr;
 DW_Dominion* dom;
 QString connector;
};

struct _Frame_With_Dominion
{
 DW_Frame fr;
 DW_Dominion* dom;
 _Frame_With_Dominion_QString operator[](QString qs)
 {
  return {fr, dom, qs};
 }
};

inline _Frame_With_Dominion operator/(DW_Frame& fr, DW_Dominion* dom)
{
 return {fr, dom};
}

_KANS(DGDB)


#endif // DW_FRAME__H


