
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-carrier.h"


//#include "kans.h"
//USING_KANS(GTagML)

#include <QDebug>

//#include "compilation-unit-object.h"
//#include "unified-runtime-object.h"
//#include "metatype-object.h"


Chasm_Carrier::Chasm_Carrier()
  :  key_(), value_(0)
{

}


template<>
void Chasm_Carrier::set_value_as<QString>(const QString& val)
{
 take_value(const_cast<QString*>(&val));
}


Chasm_Carrier& Chasm_Carrier::take_value(void* pv)
{
 u1 tf = key_.type_flag();

 switch (tf)
 {
 case 0: break; //

 case 1: set_value( (n8) *(u1*)pv ); break;
 case 2: set_value( (n8) *(u2*)pv ); break;
 case 3: set_value( (n8) new QString(*(QString*)pv) ); break;
 case 4: set_value( (n8) *(u4*)pv ); break;

 default: break;

 }

 return *this;

}


