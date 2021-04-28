
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-call-package.h"

//#include "./dev/consoles/fns/run-s0_3_r0.cpp"
//#include "./dev/consoles/fns/run-s0_3_r3.cpp"


//#include "kans.h"
//USING_KANS(GTagML)

#include <QDebug>

#include "chasm-channel.h"

//#include "compilation-unit-object.h"
//#include "unified-runtime-object.h"
//#include "metatype-object.h"


Chasm_Call_Package::Chasm_Call_Package(u4 id)
  :  current_build_channel_(nullptr), id_(id)
{

}

void Chasm_Call_Package::add_new_channel(QString name)
{
 current_build_channel_ = new Chasm_Channel(name);
}

void Chasm_Call_Package::add_carrier(const Chasm_Carrier& cc)
{
 current_build_channel_->add_carrier(cc);
}



