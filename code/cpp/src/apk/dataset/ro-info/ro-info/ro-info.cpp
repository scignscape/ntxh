
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "ro-info.h"

#include "textio.h"

#include "kans.h"

USING_KANS(DSM)
USING_KANS(TextIO)


RO_Info::RO_Info(std::function<void(RO_Info&)> fn)
{
 if(fn)
   fn(*this);
}

QString RO_Info::get_summary()
{
 return QString(R"(
Article URL: %1
Main Repo URL: %2
Local Article Path: %3
Main Project Path: %4
Main Executable Path: %5
)")
   .arg(article_url_.toDisplayString())
   .arg(main_repo_url_.toDisplayString())
   .arg(local_article_path_)
   .arg(main_project_path_)
   .arg(main_executable_path_);
}

void RO_Info::parse_kai_signatures_from_file(QString class_name,
  QString path)
{
 QString lines = load_file(path);
 if(!lines.isEmpty())
 {
  kai_signatures_[class_name] = lines.split('\n', QString::SkipEmptyParts);
 }
}

