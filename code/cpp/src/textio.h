
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TEXTIO__H
#define TEXTIO__H

#include "kans.h"

#include "global-types.h"

#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDir>
#include <QDebug>

#include <functional>


KANS_(TextIO)


inline QString make_inner_folder_from_file_name(QString folder_name, QString path)
{
 QFileInfo qfi(path);
 QDir qd = qfi.absoluteDir();
 if(qd.cd(folder_name))
 {
  qDebug() << "Folder already exists: " << qd.path();
  return qd.path();
 }
 //QString new_path = qd.absolutePath() + "/" + folder_name;
 if( qd.mkdir(folder_name) )
 {
  qd.cd(folder_name);
  qDebug() << "Made folder: " << qd.path();
  return qd.path();
 }
 if( qd.mkpath(folder_name) )
 {
  qd.cd(folder_name);
  qDebug() << "Made folder (recursive): " << qd.path();
  return qd.path();
 }

 qDebug() << "Could not make folder ...";
 return {};
}

inline QString make_folder_from_file_name(QString path, QString folder)
{
 QFileInfo qfi(path);
 QString bfn = qfi.baseName();
 QDir qd(folder);
 if(qd.cd(bfn))
 {
  qDebug() << "Folder already exists: " << qd.path();
  return qd.path();
 }
 if( qd.mkdir(bfn) )
 {
  qd.cd(bfn);
  qDebug() << "Made folder: " << qd.path();
  return qd.path();
 }
 if( qd.mkpath(bfn) )
 {
  qd.cd(bfn);
  qDebug() << "Made folder (recursive): " << qd.path();
  return qd.path();
 }

 qDebug() << "Could not make folder ...";
 return {};
}

inline QString get_path_with_different_folder(QString path, QString folder)
{
 QFileInfo qfi(path);
 QString fn = qfi.fileName();
 QFileInfo qfi1(folder + "/" + fn);
 return qfi1.absoluteFilePath();
}

inline QString load_file(QString path)
{
 QString result;
 QFile infile(path);
 if (!infile.open(QIODevice::ReadOnly | QIODevice::Text))
   return result;
 QTextStream in_ts(&infile);
 result = in_ts.readAll();
 infile.close();
 return result;
}

inline void load_file(QString path, QString& result)
{
 QFile infile(path);
 if (!infile.open(QIODevice::ReadOnly | QIODevice::Text))
   return;
 QTextStream in_ts(&infile);
 result = in_ts.readAll();
 infile.close();
}

inline void load_file(QString path, QByteArray& contents)
{
 QFile infile(path);
 if (!infile.open(QIODevice::ReadOnly))
   return;
 contents = infile.readAll();
 infile.close();
}

inline void load_file(QString path, std::function<int(QString&)> fn)
{
 QFile infile(path);
 if (!infile.open(QIODevice::ReadOnly | QIODevice::Text))
   return;
 QTextStream instream(&infile);
 n8 i = 0;
 QString line;
 while(i == 0) 
 {
  line = instream.readLine();
  if(line.isNull())
    break;
  i = fn(line);
  line.clear();
 }
 infile.close();
}

inline void save_file(QString path, QByteArray& contents)
{
 QFile outfile(path);
 if (!outfile.open(QIODevice::WriteOnly))
   return;
 outfile.write(contents);
 outfile.close();
}

inline void save_file(QString path, QString text)
{
 QFile outfile(path);
 if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream outstream(&outfile);
 outstream << text;
 outfile.close();
}

inline void save_file(QString path, QStringList& texts)
{
 QFile outfile(path);
 if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream outstream(&outfile);
 for(QString text : texts)
 {
  outstream << text;
 }
 outfile.close();
}

inline void save_file(QString path, QStringList&& texts)
{
 save_file(path, texts);
}

inline void save_file(QString path, std::function<int(QString&)> fn)
{
 QFile outfile(path);
 if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream outstream(&outfile);
 int i = 0;
 do
 {
  QString line;
  i = fn(line);
  outstream << line;
 }
 while(i > 0);

 outfile.close();
}

inline void save_file(QString path, std::function<int(QTextStream&, int)> fn)
{
 QFile outfile(path);
 if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream outstream(&outfile);
 int i = 0;
 int c = 0;
 do
 {
  ++c;
  i = fn(outstream, c);
 }
 while(i > 0);

 outfile.close();
}

inline void prepend_template_to_file(QString path, QString tpath,
 const QMap<QString, QString>& qm)
{
 QString contents = load_file(path);
 QString tmpl = load_file(tpath);
 QMapIterator<QString, QString> it(qm);
 while(it.hasNext())
 {
  it.next();
  tmpl.replace(it.key(), it.value());
 }
 save_file(path, {tmpl, contents});
}

inline QString copy_file_to_folder(QString path, QString folder)
{
 QFileInfo qfi(path);
 QString fn = qfi.fileName();
 QDir qd(folder);
 QString newpath = qd.filePath(fn);

 QString contents;
 load_file(path, contents);
 save_file(newpath, contents);
 return newpath;
}

inline QString copy_binary_file_to_folder(QString path, QString folder)
{
 QFileInfo qfi(path);
 QString fn = qfi.fileName();
 QDir qd(folder);
 QString newpath = qd.filePath(fn);

 if( QFile::copy(path, newpath) )
   return newpath;

 return {};
}

inline QString copy_file_to_folder_with_rename(QString path, QString folder, QString name)
{
 QFileInfo qfi(path);

 QString suffix = qfi.completeSuffix();

 QDir qd(folder);
 QString newpath = qd.filePath(name + "." + suffix);

 QString contents;
 load_file(path, contents);
 save_file(newpath, contents);
 return newpath;
}

inline QString copy_binary_file_to_folder_with_rename(QString path, QString folder, QString name)
{
 QFileInfo qfi(path);

 QString suffix = qfi.completeSuffix();

 QDir qd(folder);
 QString newpath = qd.filePath(name + "." + suffix);

 if( QFile::copy(path, newpath) )
   return newpath;

 return {};
}

inline QString copy_file_with_preliminary_suffix(QString path, QString preliminary_suffix)
{
 QFileInfo qfi(path);
 QString cbn = qfi.completeBaseName();
 QString suffix = qfi.suffix();
 QString ap = qfi.absolutePath();

 QString newpath = QString("%1/%2.%3.%4").arg(ap).arg(cbn).arg(preliminary_suffix).arg(suffix);
 QString contents;
 load_file(path, contents);
 save_file(newpath, contents);
 return newpath;
}


_KANS(TextIO)


#endif //TEXTIO__H
