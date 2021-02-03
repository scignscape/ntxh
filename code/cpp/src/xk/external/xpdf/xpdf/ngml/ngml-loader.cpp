
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "ngml-loader.h"

#include "textio.h"

#include "xpdf-qt/XpdfWidget.h"


//NGML_SDI_Page::NGML_SDI_Page(u4 number)


NGML_Loader::NGML_Loader()
{
}


QString NGML_Loader::get_landmark_string(int page, int x, int y,
  int& id, int& start_index, int& end_index, QString& file)
{
 QMapIterator<QPair<int, int>, element> it(elements_[page - 1]);

 QString result;

 while(it.hasNext())
 {
  it.next();
  int dx = qAbs(x - it.key().first);
  int dy = qAbs(y - it.key().second);
  if(dx < 20 && dy < 20)
  {
   element el = it.value();
   result = el.kind;// += QString("%1:%2-%3").arg(el.kind).arg(el.start_index).arg(el.end_index);
   start_index = el.start_index;
   end_index = el.end_index;
   id = el.id;
   file = file_job_info_[el.file_id].job_name;
  }
 }

 return result;
}


void NGML_Loader::load_pages(XpdfWidget* pdf)
{
 for(int page = 1;;++page)
 {
  elements_.push_back({});
  QString file = QString(AR_ROOT_DIR "/data/dataset/ctg/pages/p%1.txt").arg(page);

  QString text = load_file(file);
  if(text.isEmpty())
    break;

  QStringList lines = text.split('\n');

  int count = 0;

  for(QString line : lines)
  {
   ++count;
   line = line.trimmed();
   if(line.isEmpty())
     continue;
   QStringList qsl = line.split(' ');

   QString qf = qsl.takeFirst();
   if(qf == "=")
   {
    QString job_name = qsl.takeFirst();
    int file_id = qsl.takeFirst().toInt();
    int paragraph_count = qsl.takeFirst().toInt();
    file_job_info_[file_id] = {job_name, paragraph_count};
   }

   if(qsl.size() != 8)
    continue;

   int file_id = qf.toInt();


   int tlx = qsl[4].toInt();
   int tly = qsl[5].toInt();

   int brx = qsl[6].toInt();
   int bry = qsl[7].toInt();

   int id = qsl[0].toInt();

   int pg;
   double x, y;

   int start_index = qsl[3].toInt();
   int end_index = qsl[4].toInt();


//   int wtlx, wtly;
//   pdf->convertPDFToWindowCoords(1, tlx, tly, &wtlx, &wtly);
//   int wbrx, wbry;
//   pdf->convertPDFToWindowCoords(1, brx, bry, &wbrx, &wbry);

   QString kind;

   if(qsl[1] == "\\+")
     kind = "Sentence";

   else if(qsl[1] == "\\:")
     kind = "Paragraph";

   elements_[page - 1][{tlx, tly}] = {file_id, kind, id, brx, bry, start_index, end_index};


//   {QString("%1-%2-tl").arg(id).arg(kind), {brx, bry}};
//   elements_[page - 1][{brx, bry}] = QString("%1-%2-br").arg(id).arg(kind);

  }
 }
}
