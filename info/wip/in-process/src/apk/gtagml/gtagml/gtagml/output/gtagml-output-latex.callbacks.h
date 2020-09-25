
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


GTagML_CALLBACK_NOACTION(noxml_)
GTagML_CALLBACK_NOACTION(_noxml)

GTagML_CALLBACK_SUPPRESS(xml-save_)
GTagML_CALLBACK_NOACTION(_xml-save)
GTagML_CALLBACK_SUPPRESS(saved-xml)


GTagML_CALLBACK_(body)
 WHEN_(pre)
 {
 }
 _WHEN_(post)
 {
 }
 _WHEN
_GTagML_CALLBACK


 GTagML_CALLBACK_(kf-link)
  WHEN_(around)
  {
  }
  _WHEN
 _GTagML_CALLBACK


 GTagML_CALLBACK_(div)
  WHEN_(pre)
  {
  }
  _WHEN_(post)
  {
  }
  _WHEN
 _GTagML_CALLBACK


 GTagML_CALLBACK_(html)
  WHEN_(pre)
  {
  }
  _WHEN_(post)
  {
  }
  _WHEN
 _GTagML_CALLBACK


 GTagML_CALLBACK_(head)
  WHEN_(around)
  {
  }
  _WHEN
 _GTagML_CALLBACK


RENAME_TAG(u, underline)
RENAME_TAG(a, anchor)

//  GTagML_CALLBACK_(p)
//   WHEN_(pre)
//    {
//     flags.paragraph_mode = true;
//     flags.display_mode = true;
//     qts << "\\rzp{";
//  //   cb.flags.pre_fallthrough = true;
//    }
//    _WHEN_(post)
//    {
//     flags.paragraph_mode = false;
//     flags.display_mode = flags.document_mode;
//     qts << "}";
//  //   cb.flags.post_fallthrough = true;
//    }
//   _WHEN
//  _GTagML_CALLBACK


//GTagML_CALLBACK_(analysis-package)
// WHEN_(around)
// {
//  //report_analysis_package(qts, node);
// }
// _WHEN
//_GTagML_CALLBACK


// GTagML_CALLBACK_(fnl)
//  WHEN_(around)
//  {
//   qts << '\n';
//  }
//  _WHEN
// _GTagML_CALLBACK



////RENAME_TAG(cp, p)
//RENAME_(cp, p, comment)
//RENAME_(hide, span, hide)
//RENAME_(ulead, u, leader)
//RENAME_(iag, i, autogen)
//RENAME_TAG(pdf-ref, span)
//RENAME_(latex-only, span, latex-only)


//GTagML_CALLBACK_(body)
// WHEN_(pre)
// {
// }
// _WHEN_(post)
// {
// }
// _WHEN
//_GTagML_CALLBACK



//GTagML_CALLBACK_(code)
// WHEN_(pre)
//  {
////   flags.code_display_mode = true;
//   cb->flags.pre_fallthrough = true;
//  }
//  _WHEN_(post)
//  {
////   flags.code_display_mode = false;
//   cb->flags.post_fallthrough = true;
//  }
// _WHEN
//_GTagML_CALLBACK


//GTagML_CALLBACK_(bq)
// WHEN_(around)
// {
//  qts << "`";
// }
// _WHEN
//_GTagML_CALLBACK


//GTagML_CALLBACK_(sq)
// WHEN_(pre)
// {
//  qts << "'";
// }
// _WHEN_(post)
// {
//  qts << "'";
// }
// _WHEN
//_GTagML_CALLBACK




//GTagML_CALLBACK_(kf-link)
// WHEN_(around)
// {
////?  insert_kf_link(qts);
////  qts << "<a href='/kf' class='kf-link'>.kf</a>";
// }
// _WHEN
//_GTagML_CALLBACK


//GTagML_CALLBACK_(show-annotations)
// WHEN_(around)
// {
////  html_show_annotations(qts);
// }
// _WHEN
//_GTagML_CALLBACK


//GTagML_CALLBACK_(show-local-annotations)
// WHEN_(around)
// {
////  html_show_local_annotations(qts, node);
// }
// _WHEN
//_GTagML_CALLBACK


//GTagML_CALLBACK_(srow)
// WHEN_(around)
// {
////  insert_semantic_row(qts, node);
// }
// _WHEN
//_GTagML_CALLBACK

