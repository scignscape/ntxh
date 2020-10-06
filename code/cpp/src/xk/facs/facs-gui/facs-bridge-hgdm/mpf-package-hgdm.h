
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef MPF_PACKAGE_HGDM__H
#define MPF_PACKAGE_HGDM__H


#include "kans.h"
#include "accessors.h"

#include "global-types.h"

#include "hgdm-steps.h"

#include <QVector>
#include <QString>

class QTextStream;

class QVector_Matrix_R8;


KANS_(MPF)


class MPF_Package;


class MPF_Package_HGDM : public HGDM_Traverser
{
 MPF_Package& pkg_;

 enum class tStates
 {
  N_A, Object_Root, Selto,
 };

 tStates tstate_;

 enum class selto_Options
 {
  N_A, Column_Count, Row_Count
 };

 enum class Cue_Codes
 {
  None, Hyponode, Frame, Connector
 };


 selto_Options selto_as_tstate_;

 QVariant pvals_;
 u4 pval_count_;

 static selto_Options parse_selto(QString key);

 QVariant _read();

public:

 MPF_Package_HGDM(MPF_Package& pkg);

 MPF_Package_HGDM& selto(QString cue) Q_DECL_OVERRIDE;

 QVariant read() Q_DECL_OVERRIDE;

 void pval();

};


_KANS(MPF)

#endif // NTXH_BUILDER__H
