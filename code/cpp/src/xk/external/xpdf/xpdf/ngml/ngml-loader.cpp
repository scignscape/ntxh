
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "ngml-loader.h"

#include "textio.h"
USING_KANS(TextIO)

#include "xpdf-qt/XpdfWidget.h"

#include "quazip/quazip.h"
#include "quazip/quazipfile.h"

#include <QCoreApplication>

//NGML_SDI_Page::NGML_SDI_Page(u4 number)


NGML_Loader::NGML_Loader()
{
}


QPair<QString, QString> NGML_Loader::get_landmark_string(int page, int x, int y,
  QPair<int, int>& id, QPair<int, int>& start_index, QPair<int, int>& end_index, QString& file)
{
 QMapIterator<QPair<int, int>, element> it(elements_[page - 1]);

 QString result1, result2;

 bool have_first = false;

 while(it.hasNext())
 {
  it.next();
  int dx = qAbs(x - it.key().first);
  int dy = qAbs(y - it.key().second);
  if(dx < 20 && dy < 20)
  {
   element el = it.value();

   if(el.kind == "Paragraph" || have_first)
   {
    start_index.second = el.start_index;
    end_index.second = el.end_index;
    id.second = el.id;
    result2 =  el.kind;
   }
   else
   {
    have_first = true;

    result1 = el.kind;// += QString("%1:%2-%3").arg(el.kind).arg(el.start_index).arg(el.end_index);
    start_index.first = el.start_index;
    end_index.first = el.end_index;
    id.first = el.id;
   }
   file = file_job_info_[el.file_id].job_name;
  }
 }

 return {result1, result2};
}

QChar decode(u1 cue)
{
 switch(cue)
 {
  case 0: return '0';
  case 1: return '1';
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return 'a';
  case 11: return 'b';
  case 12: return 'c';
  case 13: return 'd';
  case 14: return 'e';
  case 15: return 'f';
  case 16: return 'g';
  case 17: return 'h';
  case 18: return 'i';
  case 19: return 'j';
  case 20: return 'k';
  case 21: return 'l';
  case 22: return 'm';
  case 23: return 'n';
  case 24: return 'o';
  case 25: return 'p';
  case 26: return 'q';
  case 27: return 'r';
  case 28: return 's';
  case 29: return 't';
  case 30: return 'u';
  case 31: return 'v';
  case 32: return 'w';
  case 33: return 'x';
  case 34: return 'y';
  case 35: return 'z';
  case 36: return '_';
  case 37: return 'A';
  case 38: return 'B';
  case 39: return 'C';
  case 40: return 'D';
  case 41: return 'E';
  case 42: return 'F';
  case 43: return 'G';
  case 44: return 'H';
  case 45: return 'I';
  case 46: return 'J';
  case 47: return 'K';
  case 48: return 'L';
  case 49: return 'M';
  case 50: return 'N';
  case 51: return 'O';
  case 52: return 'P';
  case 53: return 'Q';
  case 54: return 'R';
  case 55: return 'S';
  case 56: return 'T';
  case 57: return 'U';
  case 58: return 'V';
  case 59: return 'W';
  case 60: return 'X';
  case 61: return 'Y';
  case 62: return 'Z';
  case 63: return '-';

 //  64
  case 64: return '.'; // 64
  case 65: return ','; // 65
  case 66: return ';'; // 66
  case 67: return ':'; // 67
  case 68: return '('; // 68
  case 69: return ')'; // 69
  case 70: return '.'; // 70   se
  case 71: return ' '; // 71
  case 72: return ' '; // 72    se
  case 73: return '\n'; // 73
  case 74: return '-'; // 74 // se
  case 75: return '!'; // 75 // punc
  case 76: return '@'; // 76 // email, handles ...  (lit)
  case 77: return '#'; // 77 // number   (lit) or (word-repl)
  case 78: return '$'; // 78 // dollars  (lit) or (word-repl)
  case 79: return '%'; // 79 // percent  (lit) or (word-repl)
  case 80: return '&'; // 80 // part of name  (word-repl)
  case 81: return '&'; // 81 // not part of name  (colloq/subpunctuation)
  case 82: return '/'; // 82 // punc

  case 83: return ' ';
  case 84: return ' '; // 84

  case 85: return '*'; // 85 // polite
  case 86: return '='; // 86 // (quasi math)
  case 87: return '+'; // 87 // (quasi math)

  case 88: return '['; // 88 // (punc)
  case 89: return ']'; // 89 // (punc)

  case 90: return '{'; // 90 // lit
  case 91: return '}'; // 91 // lit

  case 92: return '\\'; // 92 // non-punc
  case 93: return '<'; // 93 // quasi-math
  case 94: return '>'; // 94 // quasi-math
  case 95: return '*'; // 95 // quasi math
  case 96: return '\''; // 96 // ' feet
  case 97: return '\"'; // 97 // " inches
  case 98: return '\''; // 98 // (apos) punc
  case 99: return '~'; // 99 // (word-repl)
  case 100: return '\n'; // 100 //  se  64+36
  case 101: return '-'; // 101

  case 102: return '.'; // 102 // num literal
  case 103: return '.'; // 103 // ell between sentence
  case 104: return '.'; // 104 // ell (condensed)
  case 105: return '.'; // 105 // abbr
  case 106: return '.'; // 106 // ellipses (1 char)
  case 107: return '.'; // 107 // ellipses part (subpunc)
  case 108: return '_'; // 108 // no esc
  case 109: return '#'; // 109 // no esc
  case 110: return '%'; // 110 // no esc
  case 111: return '$'; // 111 // no esc
  case 112: return '-'; // 112 // quasi-math (neg)
  case 113: return '-'; // 113 // quasi-math (minus)
  case 114: return ','; // 114 // quasi-math (lit)
  case 115: return '^'; // 115 // quasi-math

  case 116: return ' '; // 116 // se
  case 117: return ' '; // 116 // se

  case 118: return ' '; 
  case 119: return '\n'; 
  case 120: return '.'; 
  case 121: return ':'; 
  case 122: return ','; 

  default: return ' ';
 }

}

void NGML_Loader::check_subdocument(QString landmark_file)
{
 if(!subdocuments_.contains(landmark_file))
 {
  subdocuments_.insert(landmark_file, Subdocument());
 }
}

void NGML_Loader::sentence::add_marks_info(QString& info)
{
 if(marks.isEmpty())
   return;
 info += "\n\nKey Phrases or Other Semantic Marks:\n";

 for(sentence_mark& sm : marks)
 {
  info += QString("\ntext:%1\n (internal data: start:%2, end:%3, mode:%4)")
    .arg(sm.text).arg(sm.start).arg(sm.end).arg(sm.mode);
 }
}



QString NGML_Loader::read_sentence(QString landmark_file,
  u4 start_index, u4 end_index, QString* info)
{
 QString result;

 check_subdocument(landmark_file);

 if(subdocuments_[landmark_file].blocks_.isEmpty())
 {
  QFileInfo qfi(pdf_file_);
  QString folder = qfi.absolutePath();

  QString base_file_name = load_htxn_block(folder, landmark_file);

  if(base_file_name.isEmpty())
    return "??";

  // // should this be somewhere else?
  load_marks(landmark_file, unzip_folder_ + "/" + base_file_name + ".marks.txt");
 }

 auto it = subdocuments_[landmark_file].sentences_.find(start_index);
 if(it != subdocuments_[landmark_file].sentences_.end())
 {
  result = (*it).text;
   // // this recalculates but it doesn't seem worth it to stash this ...
  if(info)
    (*it).add_marks_info(*info);
  else
    (*it).add_marks_info(result);
  return result;
 }

 QVector<u1>& chars = subdocuments_[landmark_file].blocks_;

 QList<sentence_mark> marks;

 for(u1 u = 1; u <= 4; ++u)
 {
  QMap<u4, QPair<QString, u4>>& qmap =
    subdocuments_[landmark_file].marks_by_mode_[u];

  QMapIterator<u4, QPair<QString, u4>> it(qmap);

//  QList<QPair<u4, u4>> ranges;
//  QStringList strings;

  while(it.hasNext())
  {
   it.next();
   u4 start = it.key();
   if( (start >= start_index) && (start <= end_index) )
   {
    // // i.e. the mark is inside the sentence range ...
    sentence_mark sm(u);
    sm.start = start;
    sm.end = it.value().second;
    sm.text = it.value().first;
    marks.push_back(sm);
//    u4 end = it.value().second;
//    ranges.push_back({start, end});
//    strings.push_back(qs);
   }
  }
 }

 QTextStream qts(&result);

 for(u4 uu = start_index; uu <= end_index; ++uu)
 {
  QChar decoded = decode(chars[uu]);
  if(decoded == '\n')
    decoded = ' ';
  qts << decoded;
 }

 subdocuments_[landmark_file].sentences_[start_index] = {start_index, end_index, result, marks};

 if(info)
   subdocuments_[landmark_file].sentences_[start_index].add_marks_info(*info);
 else
   subdocuments_[landmark_file].sentences_[start_index].add_marks_info(result);
 return result;
}


// copied from GTagML_Output_Blocks

void NGML_Loader::load_marks(QString landmark_file, QString path)
{
 check_subdocument(landmark_file);

 u4 current_index = 0;
 u1 current_mode = 0;
 u4 last_index = 0;
 u1 last_mode = 0;

 QMultiMap<QString, QString> info_params;

// QMap<QString, QStringList> citations;

 Subdocument& subd = subdocuments_[landmark_file];


 load_file(path, [this, &subd, &info_params, //&citations,
           &current_index,
   &current_mode, &last_index, &last_mode](QString& line) -> int
 {
  if(line.isEmpty())
    return 0;

  if(line.startsWith("$$ "))
  {
   if(line.endsWith(';'))
     line.chop(1);
   QStringList qsl = line.mid(3).trimmed().split(" := ", Qt::KeepEmptyParts);
   QString key = qsl.takeFirst();
   for(QString v : qsl)
     info_params.insert(key, v);
   return 0;
  }

  if(line.startsWith("$& "))
  {
   QStringList qsl = line.mid(3).trimmed().split(' ', Qt::SkipEmptyParts);
   QString citation_text = qsl.takeFirst();
   citation_text.replace("%%", " ");
   QString optarg = qsl.takeFirst();
   if(optarg == "%%")
     optarg.clear();
   optarg.prepend('[');
   optarg.append(']');
   if(qsl.size() >= 3)
   {
    QString layer_code = qsl.takeFirst();
    int index = layer_code.startsWith('(')? 1 : 0;
    QString summary = QString("%1=%2:%4-%3").arg(optarg)
      .arg(layer_code.mid(index, 1)).arg(qsl.takeFirst()).arg(qsl.takeFirst());
    subd.citations_[citation_text].push_back(summary);
   }
   return 0;
  }


  if(line.startsWith("= "))
  {
   line = line.mid(2).trimmed();
   if(line.endsWith(':'))
   {
    line.chop(1);
    last_index = current_index;
    current_index = line.toUInt();
   }
   else
   {
    last_mode = current_mode;
    current_mode = line.toUInt();
    if(current_mode == 9)
    {
     subd.marks_by_mode_[last_mode][last_index].second = current_index;
    }
   }
  }
  else
  {
   subd.marks_by_mode_[current_mode][current_index] = {line, 0};
  }
  return 0;
 });
}

void NGML_Loader::load_pages(XpdfWidget* pdf, QString file_name)
{
 QString appd = QCoreApplication::applicationDirPath();
 QDir appqd(appd);

 QString src = appqd.absoluteFilePath( pdf->unzip_file() );


 pdf_file_ = file_name;
 QFileInfo qfi(file_name);
 QDir qd = qfi.absoluteDir();

 if(qd.exists("_unzip"))
 {
  qd.cd("_unzip");
  qd.removeRecursively();
  qd.cdUp();
 }
 qd.mkdir("_unzip");
 qd.cd("_unzip");

 QString dest = qd.absoluteFilePath( pdf->unzip_file() );

 qDebug() << "First Unzip Source: " << src;
 qDebug() << "First Unzip Destination: " << dest;

 QFile::copy(src, dest);

 // // need to unzip ...
 check_unzip_folder(dest);

 if(! qd.cd("pages") )
   return;

 unzip_folder_ = qd.absolutePath();

 for(int page = 1;;++page)
 {
  elements_.push_back({});
  QString file = qd.absoluteFilePath(QString("p%1.txt").arg(page));

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

   int start_index = qsl[2].toInt();
   int end_index = qsl[3].toInt();


//   int wtlx, wtly;
//   pdf->convertPDFToWindowCoords(1, tlx, tly, &wtlx, &wtly);
//   int wbrx, wbry;
//   pdf->convertPDFToWindowCoords(1, brx, bry, &wbrx, &wbry);

   QString kind;

   if(qsl[1] == "\\+")
     kind = "Sentence";

   else if(qsl[1] == "\\:")
     kind = "Paragraph";

   elements_[page - 1].insert({tlx, tly}, {file_id, kind, id, count, brx, bry, start_index, end_index});


//   {QString("%1-%2-tl").arg(id).arg(kind), {brx, bry}};
//   elements_[page - 1][{brx, bry}] = QString("%1-%2-br").arg(id).arg(kind);

  }
 }
}



u1 get_default_null()
{
 return 247;
}

// // based on glyphdeck ...
u1 encode_latin1(u1 chr)
{
 if(chr < 48)
   goto MainSwitch;
 if(chr < 58)
 {
  // // (48 - 57):  a digit
  return chr - 48;
 }
 else if(chr < 65)
 {
  goto MainSwitch;
 }
 else if(chr < 91)
 {
  // //   (A .. Z)
  return chr - 28;
 }
 else if(chr < 97)
 {
  goto MainSwitch;
 }
 else if(chr < 123)
 {
  // //   (a .. z)
  return chr - 87;
 }

MainSwitch:
 switch (chr)
 {
  //?
 case ':': return 67;   //ascii 58
 case ';': return 66;   //ascii 59

 case '<': return 93;   //ascii 60
 case '=': return 86;   //ascii 61
 case '>': return 94;   //ascii 62

 case '?': return 103;   //ascii 63

 case ' ': return 71;//
 case '\n': return 73;//
//? case '`': return 74; //64
 case '~': return 99; //64  //?
 case '!': return 75;
 case '@': return 76; //ascii 64
 case '#': return 77; //66
 case '$': return 78; //67
 case '%': return 79; //68  // hyphen
  //? case '^': return 80; //69
 case '&': return 80; //70
 case '*': return 95; //71
 case '(': return 68; //72
 case ')': return 69; //73

 case '-': return 63; //74  // NpMinus
 case '+': return 87; //76  // NpDot

 case '[': return 88; //77
 case ']': return 89; //78

 case '{': return 90; // no esc
 case '}': return 91; // no esc

 case '_': return 36;
 case '`': return 128;
 case '^': return 135;

 case '|': return 148; //86
 case '\\': return 92; //87

 case '\'': return 98; //90  // NsExc
 case '"': return 97; //91  // SnSp

 case ',': return 65; //92 // Boundary
 case '.': return 64; //94  // DashX
 case '/': return 82; //96  // OSqBrX


 default:
  return get_default_null();
 }


}

QString NGML_Loader::load_htxn_block(QString folder, QString file)
{
 //QDir qd(folder);
 QDir qd(unzip_folder_);

 QString ff = file;
 if(ff.endsWith(".gt"))
   ff.chop(3);
 QString full_path = qd.absoluteFilePath(ff + ".htxn");
 QFile infile(full_path);
 if (!infile.open(QIODevice::ReadOnly | QIODevice::Text))
 {
  // // fallback in case the zip/unzip didn't work ...
  qd.cd(folder);
  infile.setFileName(qd.absoluteFilePath(file + ".htxn.txt"));
  if (!infile.open(QIODevice::ReadOnly | QIODevice::Text))
    return {};
 }
 QTextStream in_ts(&infile);

 QVector<u1>& block = subdocuments_[file].blocks_;

 QChar qc;
 while(!in_ts.atEnd())
 {
  in_ts >> qc;
  char c = qc.toLatin1();

  if(c == '|')
  {
   QChar c1, c2;
   in_ts >> c1; in_ts >> c2;
   QString qs = "00";
   qs[0] = c1;
   qs[1] = c2;
   block.push_back(qs.toInt());
  }
  else if(c == '`')
  {
   QChar c1, c2, c3;
   in_ts >> c1; in_ts >> c2; in_ts >> c3;
   QString qs = "000";
   qs[0] = c1;
   qs[1] = c2;
   qs[2] = c3;
   block.push_back(qs.toInt());
  }
  else
  {
   u1 uu = encode_latin1(c);
   block.push_back(uu);
  }

//  switch (c)
//  {
//  }
 }

 return ff;
}

// // mostly copied from NGML Document ...
void NGML_Loader::check_unzip_folder(QString zip_file_path)
{
 QFileInfo qfi(zip_file_path);
 QDir qd = qfi.absoluteDir();
// QDir dir(unzip_path);
// dir.mkdir(unzip_folder_name);
// unzip_folder_ = new QString(dir.absoluteFilePath(unzip_folder_name));

 QuaZip zip(zip_file_path);

 if (!zip.open(QuaZip::mdUnzip))
 {
  qWarning("testRead(): zip.open(): %d", zip.getZipError());
  return;
 }

 zip.setFileNameCodec("IBM866");

 qWarning("%d entries\n", zip.getEntriesCount());
 qWarning("Global comment: %s\n", zip.getComment().toLocal8Bit().constData());

 QuaZipFileInfo info;

 QuaZipFile file(&zip);

 QFile out;
 QString name;
 char c;
 for (bool more = zip.goToFirstFile(); more; more = zip.goToNextFile())
 {
  if (!zip.getCurrentFileInfo(&info))
  {
   qWarning("testRead(): getCurrentFileInfo(): %d\n", zip.getZipError());
  }
  if (!file.open(QIODevice::ReadOnly))
  {
   qWarning("testRead(): file.open(): %d", file.getZipError());
   return;
  }

  QString afn = file.getActualFileName();

  QFileInfo aqfi(afn);
  qd.mkdir(aqfi.dir().dirName());

  name = qd.absoluteFilePath(afn);


    //QString("%1/%2").arg(unzip_path).arg(file.getActualFileName());

  qDebug() << "Name: " << name;

  if (file.getZipError() != UNZ_OK)
  {
   qWarning("testRead(): file.getFileName(): %d", file.getZipError());
   return;
  }

  //out.setFileName("out/" + name);
  out.setFileName(name);

  // this will fail if "name" contains subdirectories, but we don't mind that
  if(!out.open(QIODevice::WriteOnly))
  {
   qDebug() << "Out failed ...";
   return;
  }

  // Slow like hell (on GNU/Linux at least), but it is not my fault.
  // Not ZIP/UNZIP package's fault either.
  // The slowest thing here is out.putChar(c).
  while (file.getChar(&c)) out.putChar(c);

  out.close();

  if (file.getZipError() != UNZ_OK)
  {
   qWarning("testRead(): file.getFileName(): %d", file.getZipError());
   return;
  }

  if (!file.atEnd())
  {
   qWarning("testRead(): read all but not EOF");
   return;
  }

  file.close();

  if (file.getZipError() != UNZ_OK)
  {
   qWarning("testRead(): file.close(): %d", file.getZipError());
   return;
  }
 }

 zip.close();

 if (zip.getZipError() != UNZ_OK)
 {
  qWarning("testRead(): zip.close(): %d", zip.getZipError());
  return;
 }
}



