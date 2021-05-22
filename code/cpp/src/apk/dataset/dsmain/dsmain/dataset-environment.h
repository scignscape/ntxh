
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DATASET_ENVIRONMENT__H
#define DATASET_ENVIRONMENT__H

#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "qring/qring-file-structure.h"

#include "dsm-sdi-document.h"

#include "discourse-markup-sample.h"

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>
#include <QMap>

//#define PASTE_EXPRESSION(...) __VA_ARGS__

class Qh_Pack_Builder;

KANS_(DSM)

class Language_Sample;
class Language_Sample_Group;


class DSM_SDI_Document;

class Dataset;

class Dataset_Environment
{
 QStringList cmd_args_;

 QString current_paper_name_;
 QString initial_paper_name_;

 QString default_dataset_folder_;
 QString current_dataset_folder_;
 QString default_sdi_folder_;

public:

 Dataset_Environment(const QStringList& cmd_args, QString first_paper);

 static Dataset_Environment* _new(const QStringList& cmd_args, QString first_paper);

// Dataset_Environment();

 ACCESSORS(QString ,current_paper_name)
 ACCESSORS(QString ,initial_paper_name)

 ACCESSORS(QString ,default_dataset_folder)
 ACCESSORS(QString ,current_dataset_folder)

 ACCESSORS(QString ,default_sdi_folder)

 void init_dsfolder();

 bool check_setup_only();


};


_KANS(DSM)

#endif // DATASET_INFO__H
