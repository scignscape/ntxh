
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "axfd-string-node.h"

USING_KANS(AXFD)

AXFD_String_Node::AXFD_String_Node(QString str)
 :  enter_(0), leave_(0)
{
 string_or_layer_ = new QString(str);
}

AXFD_String_Node::AXFD_String_Node(void* pv)
 :  enter_(0), leave_(0), string_or_layer_(pv)
{
}

AXFD_String_Node AXFD_String_Node::from_range(u4 enter, u4 leave)
{
 AXFD_String_Node result;
 result.set_enter(enter);
 result.set_leave(leave);
 return result;
}

AXFD_String_Node AXFD_String_Node::_from_range(void* pv, u4 enter, u4 leave)
{
 AXFD_String_Node result(pv);
 result.set_enter(enter);
 result.set_leave(leave);
 return result; 
}

AXFD_String_Node AXFD_String_Node::from_string(QString str)
{
 return AXFD_String_Node(str);
}

