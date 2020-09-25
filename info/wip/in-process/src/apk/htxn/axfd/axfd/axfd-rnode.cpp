
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "axfd-rnode.h"

#include "axfd-string-node.h"


USING_KANS(AXFD)


AXFD_RNode::AXFD_RNode(QString tag_command_name)
  :  tag_command_name_(AXFD_String_Node::from_string(tag_command_name))
{
}


//AXFD_RNode::AXFD_RNode()
//{
//}



