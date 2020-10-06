
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "mpf-package-hgdm.h"

#include "facs-bridge/mpf-package.h"
#include "facs-bridge/qvector-matrix-r8.h"


#include <QFile>
#include <QDataStream>
#include <QDebug>


#include "kans.h"

USING_KANS(MPF)

MPF_Package_HGDM::MPF_Package_HGDM(MPF_Package& pkg)
  :  pkg_(pkg), tstate_(tStates::Object_Root),
     selto_as_tstate_(selto_Options::N_A), pval_count_(0)
{


}

void MPF_Package_HGDM::pval()
{
 QVariant qv = _read();
 if(pval_count_ == 0)
   pvals_ = qv;
 else if(pval_count_ == 1)
 {
  QVector<QVariant> qvv({pvals_, qv});
  pvals_.setValue(qvv);
 }
 else
 {
  QVector<QVariant> qvv = pvals_.value<QVector<QVariant>>();
  qvv.push_back(qv);
 }
 ++pval_count_;
}


MPF_Package_HGDM::selto_Options MPF_Package_HGDM::parse_selto(QString key)
{
 static QMap<QString, selto_Options> static_map {{
   {"column-count", selto_Options::Column_Count },
   {"row-count", selto_Options::Row_Count },
  }};

 return static_map.value(key, selto_Options::N_A);
}

QVariant MPF_Package_HGDM::read()
{
 QVariant result;
 if(pval_count_ > 0)
 {
  result = pvals_;
  pval_count_ = 0;
  pvals_.clear();
 }
 else
   result = _read();
 tstate_ = tStates::Object_Root;
 return result;
}

QVariant MPF_Package_HGDM::_read()
{
 if(tstate_ == tStates::Selto)
 {
  switch (selto_as_tstate_)
  {
  case selto_Options::Column_Count:
    return QVariant::fromValue(pkg_.matrix()->n_cols());
  case selto_Options::Row_Count:
    return QVariant::fromValue(pkg_.matrix()->n_rows());
  }
 }
 return  {};
}

MPF_Package_HGDM& MPF_Package_HGDM::selto(QString cue)
{
 if(cue.isEmpty())
   return *this;
 u1 c1 = cue.at(0).toLatin1();

 Cue_Codes cc;

 u4 mid = 0;

 switch (c1)
 {
 case '$': cc = Cue_Codes::Connector; ++mid; break;
 case '@': cc = Cue_Codes::Hyponode; ++mid; break;
 case '#': cc = Cue_Codes::Frame; ++mid; break;
 case '%': cc = Cue_Codes::None;  ++mid; break;
 default: cc = Cue_Codes::None; break;
 }

 if(mid)
   cue = cue.mid(mid);

 selto_Options opt = parse_selto(cue);

 switch (opt)
 {
 case selto_Options::N_A:
  qDebug() << "Unrecognized Selto Option: " << cue;
  break; // do nothing ...
 default: selto_as_tstate_ = opt; tstate_ = tStates::Selto;
 }

 return *this;
}


