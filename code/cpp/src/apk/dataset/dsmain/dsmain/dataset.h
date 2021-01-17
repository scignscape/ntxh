
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DATASET__H
#define DATASET__H

#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "qring/qring-file-structure.h"

#include "dsm-sdi-document.h"

#include "kans.h"
#include "accessors.h"

#include <QVector>
#include <QString>
#include <QMap>

//#define PASTE_EXPRESSION(...) __VA_ARGS__


KANS_(DSM)

class Language_Sample;
class Language_Sample_Group;

class DSM_SDI_Document;

class Dataset :  public QRing_File_Structure
{
 QString samples_file_;
 QString merge_file_;

 QString pdf_file_;

 QVector<Language_Sample*>* samples_;

// QVector<int> chapter_pages_;
 QVector<Language_Sample_Group*>* groups_;

 QStringList issues_;
 QStringList forms_;

 QVector<QPair<QPair<QString, int>, QPair<int, int>>> subdocuments_;

 DSM_SDI_Document sdi_document_;

public:

 Dataset(QString root_folder = QString());//QString file);

 ACCESSORS(QVector<Language_Sample*>* ,samples)
 ACCESSORS(QVector<Language_Sample_Group*>* ,groups)

 ACCESSORS__RGET(QStringList ,issues)
// ACCESSORS__RGET(QStringList ,forms)

 ACCESSORS(QString ,samples_file)
 ACCESSORS(QString ,merge_file)

 ACCESSORS(QString ,pdf_file)

 ACCESSORS__RGET(MACRO_PASTE(QVector<QPair<QPair<QString, int>,
    QPair<int, int>>>) ,subdocuments)


 void load_from_folder(QString path);
 void load_from_folder();

 void save_raw_file(QString text, int page, int num);
 void parse_to_samples(QString text, int page, int num, phaong<pg_t>& phg);

 void save_to_file();
 void get_serialization(QString& text, QString& gtext);

 void load_from_file(QString path);
 void save_to_file(QString path);

 void save_to_file_udp();
 void save_to_file_udp(QString path, QString upath, QString ppath);


};


_KANS(DSM)

#endif // DATASET__H
