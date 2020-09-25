
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef RZ_NGML_PARSE_CONTEXT__H
#define RZ_NGML_PARSE_CONTEXT__H

#include "relae-graph/relae-parser.h"

#include "flags.h"

#include "rzns.h"
RZNS_(NGML)


class NGML_Graph;
class NGML_Node;


class NGML_Parse_Context
{
 typedef NGML_Node tNode;

public:
 flags_(2)
  flag_(1, inside_khif_tile);
  flag_(2, inside_multiline_comment);
  flag_(3, inside_tag_body);
  flag_(4, inside_html_tag_body);
  flag_(5, inside_multi_parent);
  flag_(6, inside_inline_multi_parent);
  flag_(7, inside_html_script_tag);
  flag_(8, inside_html_style_tag);
  flag_(9, inside_multi_parent_semis);
  flag_(10, inside_multi_generic);
  flag_(11, inside_attribute_sequence);
 _flags_

public:

 NGML_Parse_Context();

};

_RZNS(NGML)

#endif
