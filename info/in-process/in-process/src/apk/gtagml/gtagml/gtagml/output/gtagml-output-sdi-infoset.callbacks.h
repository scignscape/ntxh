
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


GTagML_CALLBACK_(p)
 WHEN_(around)
 {
  check_sentence_boundaries(qts, node);
 }
 _WHEN
_GTagML_CALLBACK


//GTagML_CALLBACK_()
// WHEN_(around)
// {
//  check_sentence_boundaries(qts, node);
// }
// _WHEN
//_GTagML_CALLBACK


// WHEN_(pre)
// {
// }
// _WHEN_(post)
// {
//  check_
// }
// _WHEN




GTagML_CALLBACK_SUPPRESS(documentclass)
GTagML_CALLBACK_NOACTION(include)

GTagML_CALLBACK_(noxml_)
 WHEN_(around)
 {
  // suppress_node_ = node;
 }
 _WHEN
_GTagML_CALLBACK


GTagML_CALLBACK_(_noxml)
 WHEN_(around)
 {
  // suppress_node_ = nullptr;
 }
 _WHEN
_GTagML_CALLBACK


GTagML_CALLBACK_(dclass)
 WHEN_(pre)
 {
  // suppress_node_ = node;
 }
 _WHEN_(post)
 {
  // suppress_node_ = nullptr;
 }
 _WHEN
_GTagML_CALLBACK


GTagML_CALLBACK_(document)
 WHEN_(pre)
 {
 }
 _WHEN_(post)
 {
 }
 _WHEN
_GTagML_CALLBACK


GTagML_CALLBACK_(inc)
 WHEN_(around)
 {
 }
 _WHEN
_GTagML_CALLBACK



 GTagML_CALLBACK_(fnl)
  WHEN_(around)
  {
   qts << '\n';
  }
  _WHEN
 _GTagML_CALLBACK



//RENAME_TAG(cp, p)
RENAME_(cp, p, comment)
RENAME_(hide, span, hide)
RENAME_(ulead, u, leader)
RENAME_(iag, i, autogen)
RENAME_TAG(pdf-ref, span)
RENAME_(latex-only, span, latex-only)


GTagML_CALLBACK_(code)
 WHEN_(pre)
  {
//   flags.code_display_mode = true;
   cb->flags.pre_fallthrough = true;
  }
  _WHEN_(post)
  {
//   flags.code_display_mode = false;
   cb->flags.post_fallthrough = true;
  }
 _WHEN
_GTagML_CALLBACK

