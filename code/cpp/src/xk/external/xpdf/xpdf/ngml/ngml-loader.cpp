
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
  case 63: return ' ';

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

  case 83: return '('; // 83 // surround
  case 84: return ')'; // 84 // surround

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
  case 103: return '?'; // 103 // punc
  case 104: return '!'; // 104 // //? punc
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

  case 116: return ':'; // 116 // se

  default: return ' ';
 }

}

QString NGML_Loader::read_sentence(QString pdf_file, QString landmark_file, u4 start_index, u4 end_index)
{
 if(!blocks_.contains(landmark_file))
 {
  QFileInfo qfi(pdf_file);
  QString folder = qfi.absolutePath();
  load_htxn_block(folder, landmark_file);
 }

 QVector<u1>& chars = blocks_[landmark_file];

 QString result;
 QTextStream qts(&result);

 for(u4 uu = start_index; uu <= end_index; ++uu)
 {
  if(uu == 500)
    qDebug() << uu;
  qts << decode(chars[uu]);
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

   elements_[page - 1][{tlx, tly}] = {file_id, kind, id, count, brx, bry, start_index, end_index};


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

void NGML_Loader::load_htxn_block(QString folder, QString file)
{
 QDir qd(folder);
 QString full_path = qd.absoluteFilePath(file + ".htxn.txt");
 QFile infile(full_path);
 if (!infile.open(QIODevice::ReadOnly | QIODevice::Text))
   return;
 QTextStream in_ts(&infile);

 QVector<u1>& block = blocks_[file];

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
}

