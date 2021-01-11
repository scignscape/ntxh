
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "prosodic-annotation.h"


#include <QDebug>

#include "textio.h"

#include "qh-package/qh-pack-code.h"
#include "qh-package/qh-pack-builder.h"


//?
USING_KANS(GHL)
USING_KANS(TextIO)


Prosodic_Annotation::Prosodic_Annotation()
{

}


void Prosodic_Annotation::parse_elements(QString text)
{
 int index = 0;
 int last_index = 0;
 while (index != -1)
 {
  index = text.indexOf('\n', index + 1);
  QString line = text.mid(last_index, index);
  if(line.isEmpty())
   continue;

  QStringList elems = line.simplified().split(' ', Qt::SkipEmptyParts);
  QString lrc = elems.takeFirst();
  QString text = elems.takeFirst();
  Prosodic_Annotation_Element pae(text);
  pae.parse_layer_range_code(lrc);

  pae.annotations() = elems;

  elements_.push_back(pae);
 }
}

