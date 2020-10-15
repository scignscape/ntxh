
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


class DW_Frame
{
 u4 id_;

public:


 ACCESSORS(u4 ,id)

 DW_Frame(u4 id = 0);


};

struct _Frame_With_DW_QString
{
 DW_Frame fr;
 DW_Instance* dwi;
 QString connector;
};

struct _Frame_With_DW
{
 DW_Frame fr;
 DW_Instance* dwi;
 _Frame_With_DW_QString operator[](QString qs)
 {
  return {fr, dwi, qs};
 }
};

inline _Frame_With_DW operator/(DW_Frame fr, DW_Instance* dwi)
{
 return {fr, dwi};
}

_KANS(DGDB)

#endif // DW_FRAME__H


