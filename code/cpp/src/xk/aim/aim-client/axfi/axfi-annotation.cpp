
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "axfi-annotation.h"



#define TAB_DIVIDER '|'
#define TAB_DIVIDER_STR "|"

#define LINE_DIVIDER '|'
#define LINE_DIVIDER_STR "|"

#define LINE_SUBDIVIDER '^'
#define LINE_SUBDIVIDER_STR "^"



AXFI_Annotation::AXFI_Annotation()
  :  opaque_shape_kind_code_(0xFFFFFFFFFFFFFFFF)
{

}

void AXFI_Annotation::locations_to_qpoints(QVector<QPoint>& result)
{
 for(n8 nn : locations_)
 {
  AXFI_Location_2d* loc = (AXFI_Location_2d*) nn;
  QPoint qp = loc->to_qpoint();
  result.push_back(qp);
 }
}


QString AXFI_Annotation::to_compact_string()
{
 QString result = scoped_identifiers_.join('^');
 result += QString("|%1|%2|").arg(shape_designation_).arg(opaque_shape_kind_code_);
 for(n8 nn : locations_)
 {
  AXFI_Location_2d* loc = (AXFI_Location_2d*) nn;
  result += loc->to_string() + ":";
 }
 result.chop(1);
 return result;
}


void AXFI_Annotation::absorb_shape_point(const QPoint& qp)
{
 AXFI_Location_2d* loc = new AXFI_Location_2d(qp.x(), qp.y());
 locations_.push_back( (n8) loc );
}

void AXFI_Annotation::add_scoped_identifier(QString si)
{
 scoped_identifiers_.push_back(si);
}

QString AXFI_Annotation::scoped_identifiers_to_string()
{
 return scoped_identifiers_.join(':');
}

void AXFI_Annotation::from_compact_string(QString cs)
{
 QStringList parts = cs.split(LINE_DIVIDER_STR);

 if(parts.isEmpty())
   return;

 QString ids = parts.takeFirst();
 scoped_identifiers_ = ids.split(LINE_SUBDIVIDER_STR);

 if(parts.isEmpty())
   return;

 shape_designation_ = parts.takeFirst();

 if(parts.isEmpty())
   return;

 opaque_shape_kind_code_ = parts.takeFirst().toLongLong();

 if(parts.isEmpty())
   return;

 QString locs = parts.takeFirst();
 AXFI_Location_2d::read_string(locs, locations_);
}


void AXFI_Annotation::read_iat_string(QString line)
{
 QStringList parts = line.split(TAB_DIVIDER_STR);

 if(parts.isEmpty())
   return;

 QString object = parts.takeFirst();
 scoped_identifiers_.push_back(object);

 if(parts.isEmpty())
   return;

 QString index = parts.takeFirst();
 scoped_identifiers_.push_back(object);

 if(parts.isEmpty())
   return;

 QString number = parts.takeFirst();
 scoped_identifiers_.push_back(number);

 if(parts.isEmpty())
   return;

}
