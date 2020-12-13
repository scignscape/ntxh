
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


GTagML_CALLBACK_NOACTION(noxml_)
GTagML_CALLBACK_NOACTION(_noxml)

GTagML_CALLBACK_SUPPRESS(xml-save_)
GTagML_CALLBACK_NOACTION(_xml-save)
GTagML_CALLBACK_SUPPRESS(saved-xml)

GTagML_CALLBACK_NOACTION(copy)
GTagML_CALLBACK_NOACTION(document-title)
GTagML_CALLBACK_NOACTION(local-title)


GTagML_CALLBACK_(cite)
 WHEN_(around)
 {
  mark_citation(qts, node, prior_node, parent_of_siblings);
 }
 _WHEN
_GTagML_CALLBACK


