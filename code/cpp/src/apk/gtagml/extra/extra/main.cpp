
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QDirIterator>

#include "test-class.h"

#include "unified-runtime-object.h"

#include "metatype-object.h"

#include "textio.h"
USING_KANS(TextIO)

#include "./dev/consoles/fns/run-s0_3_r0.cpp"


typedef void (*_temp_minimal_fn_type)();



void testqvar(QVariant arg1, double arg2, float* arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << *arg3;
}


void testfn(s1 arg1, u4 arg2, s1& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 arg3 = -arg3;
}

void testqs(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
}

void testf(QString& arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 arg1.prepend("'");
 arg1.append("'");
}

enum class test_enum { E1, E2, E3 };

void teste(QStringList* arg1, u4* arg2, test_enum arg3)
{
 qDebug() << "arg1 = " << *arg1;
 qDebug() << "arg2 = " << *arg2;
 qDebug() << "arg3 = " << (u1) arg3;
 ++*arg2;
}

void test2(u2 arg1, s2 arg2, s2& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 --arg3;
}

/*
0 = ref
1 = u1
2 = u2
3 = QString
4 = u4
5 = call/expr
6 = dbl
7 = QVariant
8 = n8
9 = pointer
*/


void f_140 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 u1 a1 = *(u1*)arg1;
 u4 a2 = *(u4*)arg2;
 n8& a3 = *(n8*)arg3;

 ((void(*)(u1,u4,n8&)) fn)(a1,a2,a3);
}

void f_149 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 u1 a1 = *(u1*)arg1;
 u4 a2 = *(u4*)arg2;
 n8 a3 = *(n8*)arg3;

 ((void(*)(u1,u4,n8)) fn)(a1,a2,a3);
}


void f_341 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 QString a1 = *(QString*)arg1;
 u4 a2 = *(u4*)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(QString,u4,u1)) fn)(a1,a2,a3);
}

void f_041 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 n8& a1 = *(n8*)arg1;
 u4 a2 = *(u4*)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(n8&,u4,u1)) fn)(a1,a2,a3);
}

void f_ (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 void* a1 = *(void**)arg1;
 void* a2 = *(void**)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(void*,void*,u1)) fn)(a1,a2,a3);
}

void f_769 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 QVariant a1 = *(QVariant*)arg1;
 r8 a2 = *(r8*)arg2;
 n8 a3 = *(n8*)arg3;

 ((void(*)(QVariant, r8, n8)) fn)(a1,a2,a3);
}

void f_220 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 u2 a1 = *(u2*)arg1;
 u2 a2 = *(u2*)arg2;
 n8& a3 = *(n8*)arg3;

 ((void(*)(u2, u2, n8&)) fn)(a1,a2,a3);
}


void f_881 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn)
{
 n8 a1 = *(n8*)arg1;
 n8 a2 = *(n8*)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(n8, n8, u1)) fn)(a1,a2,a3);
}

typedef void(*_temp_run_s0_3_type)(n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_type fn);

typedef _temp_run_s0_3_type _temp_s0_3_dispatch_array [1001];

_temp_s0_3_dispatch_array* _temp_init_s0_3_dispatch_array()
{
 _temp_s0_3_dispatch_array* result = (_temp_s0_3_dispatch_array*) new _temp_run_s0_3_type[1001];

 for(int i = 0; i < 1001; ++i)
   (*result)[i] = 0;

 (*result)[769] = (_temp_run_s0_3_type) &f_769;
 (*result)[341] = (_temp_run_s0_3_type) &f_341;
 (*result)[41] = (_temp_run_s0_3_type) &f_041;
 (*result)[140] = (_temp_run_s0_3_type) &f_140;
 (*result)[149] = (_temp_run_s0_3_type) &f_149;
 (*result)[220] = (_temp_run_s0_3_type) &f_220;
 (*result)[881] = (_temp_run_s0_3_type) &f_881;

 return result;
}

void _temp_run(u4 code, _temp_minimal_fn_type fn, n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static _temp_s0_3_dispatch_array* fs = _temp_init_s0_3_dispatch_array(); // (farr*) new run_s0_3_type[1001];
 _temp_run_s0_3_type f = (*fs)[code];
 f(a1, a2, a3, fn);
}

int main2(int argc, char *argv[])
{
 QString a11 = "Test";
 u4 a21 = 33;
 u1 a31 = 11;
 _temp_run(10341, (_temp_minimal_fn_type) &testqs, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;

 qDebug() << "\n====\n";
 run_s0_3_r0(10341, (minimal_fn_type) &testqs, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;
 qDebug() << "\n====\n\n";

 _temp_run(10041, (_temp_minimal_fn_type) &testf, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;

 qDebug() << "\n====\n";
 run_s0_3_r0(10041, (minimal_fn_type) &testf, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;
 qDebug() << "\n====\n\n";

 s1 a12 = -4;
 u4 a22 = 10033;
 s1 a32 = -40;

 _temp_run(10140, (_temp_minimal_fn_type) &testfn, (n8) &a12, (n8) &a22, (n8) &a32);
 qDebug() << "a32 = " << a32;

 qDebug() << "\n====\n";
 run_s0_3_r0(10140, (minimal_fn_type) &testfn, (n8) &a12, (n8) &a22, (n8) &a32);
 qDebug() << "a32 = " << a32;

 qDebug() << "\n====\n\n";

// run(149, (_temp_minimal_fn_type) &testfn, (n8) &a12, (n8) &a22, (n8) &a32);
// qDebug() << "a32 = " << a32;

 QStringList* a13 = new QStringList({"Ptr", "A2"});
 u4* a23 = new u4(92300);
 test_enum a33 = test_enum::E3;

 _temp_run(10881, (_temp_minimal_fn_type) &teste, (n8) &a13, (n8) &a23, (n8) &a33);
 qDebug() << "a23 = " << *a23;

 qDebug() << "\n====\n";
 run_s0_3_r0(10881, (minimal_fn_type) &teste, (n8) &a13, (n8) &a23, (n8) &a33);
 qDebug() << "a23 = " << *a23;
 qDebug() << "\n====\n\n";

 u2 a14 = 22;
 s2 a24 = -22;
 s2 a34 = 0;

 _temp_run(10220, (_temp_minimal_fn_type) &test2, (n8) &a14, (n8) &a24, (n8) &a34);
 qDebug() << "a34 = " << a34;

 qDebug() << "\n====\n";
 run_s0_3_r0(10220, (minimal_fn_type) &test2, (n8) &a14, (n8) &a24, (n8) &a34);
 qDebug() << "a34 = " << a34;
 qDebug() << "\n====\n\n";


 QVariant a15 = QVariant::fromValue(QString("var..."));
 double a25 = 22./93;
 float a35 = 22./95;
 float* _a35 = &a35;
 qDebug() << "a15 = " << a15;
 qDebug() << "a25 = " << a25;
 qDebug() << "a35 = " << a35;

 _temp_run(10769, (_temp_minimal_fn_type) &testqvar, (n8) &a15, (n8) &a25, (n8) &_a35);

 qDebug() << "\n====\n";
 run_s0_3_r0(10769, (minimal_fn_type) &testqvar, (n8) &a15, (n8) &a25, (n8) &_a35);
 qDebug() << "\n====\n\n";

 return 0;
}


QString generate_function_code(u2 key)
{
 QString result = QString("void _f_%1_(n8 arg1, n8 arg2, n8 arg3, minimal_fn_type fn){\n  ")
   .arg(key, 3, 10, QLatin1Char('0'));
 u1 akey = 0;

 // types[0] is "this" ...
 static QString types [4] = {{},{},{}};

 for(u1 i = 1, factor = 100; i <= 3; ++i, factor /= 10)
 {
  akey = key/factor;
  key -= akey*factor;
  switch(akey)
  {
  case 0: // ref
   types[i] = "n8&";
   result += QString("n8& a%1=*(n8*)arg%1;").arg(i);
   break;

   // // for now treat 5 and 9 like a n8
  case 5: case 9: akey = 8; // fallthrough
  case 1: case 2: case 4: case 8:
   types[i] = QString("%1%2").arg(akey == 8?'n':'u').arg(akey);
   result += QString("%1 a%2=*(%1*)arg%2;").arg(types[i]).arg(i);
   break;

  case 3: // QString
   types[i] = "QString";
   result += QString("QString a%1=*(QString*)arg%1;").arg(i);
   break;

  case 6: // double
   types[i] = "r8";
   result += QString("r8 a%1=*(r8*)arg%1;").arg(i);
   break;

  case 7: // QVariant
   types[i] = "QVariant";
   result += QString("QVariant a%1 = *(QVariant*)arg%1;").arg(i);
   break;

  }
 }

 result += QString("((void(*)(%1,%2,%3)) fn)(a1,a2,a3);}\n\n")
   .arg(types[1]).arg(types[2]).arg(types[3]);

 return result;
}

int main3(int argc, char *argv[])
{
 QString s0_3_r0_file = ROOT_FOLDER "/dev/consoles/fns/run-s0_3_r0.cpp";
 QString fn_array_r0_file = ROOT_FOLDER "/dev/consoles/fns/fn-array-s0_3_r0.cpp";

 QString fn_array_r0_text;
 QString s0_3_r0_text = R"(

typedef void (*minimal_fn_type)();
typedef void(*run_s0_3_r0_type)(n8 arg1, n8 arg2, n8 arg3, minimal_fn_type fn);
typedef run_s0_3_r0_type s0_3_r0_dispatch_array [1000];

#include "fn-array-s0_3_r0.cpp"

s0_3_r0_dispatch_array* init_s0_3_r0_dispatch_array()
{
 s0_3_r0_dispatch_array* result = (s0_3_r0_dispatch_array*) new run_s0_3_r0_type[1000];
)";
 for(u2 i = 0; i < 1000; ++i)
 {
  s0_3_r0_text += QString("\n (*result)[%1] = &_f_%2_;").arg(i).arg(i, 3, 10, QLatin1Char('0'));
 }

 s0_3_r0_text +=  R"(
}

void run_s0_3_r0(u4 code, minimal_fn_type fn, n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static s0_3_r0_dispatch_array* dispatch_array = init_s0_3_r0_dispatch_array();
 run_s0_3_r0_type f = (*dispatch_array)[code];
 f(a1, a2, a3, fn);
}
)";

 save_file(s0_3_r0_file, s0_3_r0_text);

 for(int i = 0; i < 1000; ++i)
   fn_array_r0_text += generate_function_code(i);
 save_file(fn_array_r0_file, fn_array_r0_text);

 return 0;
}

int main1(int argc, char *argv[])
{
 Unified_Runtime_Object& uro = *Unified_Runtime_Object::instance();
 uro.register_new_metatype_object("Test_Class");

 Test_Class tc("OK");
 qDebug() << tc.text();


 Metatype_Object& mto = *uro.get_metetype_object_by_type_name("Test_Class");

 mto.register_guard_fn("test_method@enter", [](QVector<n8> args) -> n8
 {
  QString& arg0 = *(QString*)args[0];
  u4& arg1 = *(u4*)args[1];
  u4& arg2 = *(u4*)args[2];
  return 0;
 });

// mto

 tc.test_method(ROOT_FOLDER "/dev/extra", 79, 81);
 tc.test_cuo();
 return 0;
}

void get_section_files(QString paper_name, QMap<QString, QString>& result)
{
 QString folder = ROOT_FOLDER "/../dev/documents/" + paper_name + "/src";

 QDirIterator qdi(folder, {"*.gt"});
 while(qdi.hasNext())
 {
  qdi.next();
  QString fp = qdi.filePath();
  QFileInfo qfi(fp);
  if(qfi.fileName().startsWith("section"))
  {
   QString tail;
   if(qfi.fileName().length() == 12)
     tail = qfi.fileName().mid(8, 1);
   int sectno = qfi.fileName().midRef(7, 1).toInt();
   result[QString("%1-%2%3").arg(paper_name).arg(sectno).arg(tail)] = fp;
  }
  else if(qfi.fileName().startsWith("intro"))
  {
   result[QString("%1-intro").arg(paper_name)] = fp;
  }
 }

}

void get_source_files(QString paper_name, QMap<QString, QMap<QString, QStringList>>& result)
{
 QString folder = ROOT_FOLDER "/../dev/documents/" + paper_name + "/src";

 QDirIterator qdi(folder, {"*.gt", "*.tex"});
 while(qdi.hasNext())
 {
  qdi.next();
  QString fp = qdi.filePath();
  QFileInfo qfi(fp);
  if(qfi.completeSuffix() == "gt.tex")
    continue;
  if(qfi.completeSuffix() == "prep.tex")
    continue;

  result[paper_name]["src"].push_back(fp);
 }

 QString folderx = ROOT_FOLDER "/../dev/documents/" + paper_name + "/extra";
 QDirIterator qdix(folderx, {"*.tex"});
 while(qdix.hasNext())
 {
  qdix.next();
  QString fp = qdix.filePath();
  QFileInfo qfi(fp);
  if(qfi.fileName() == "biblio.tex")
    result[paper_name]["extra"].push_back(fp);
 }

 QString folderf = ROOT_FOLDER "/../dev/documents/" + paper_name + "/figures";
 QDirIterator qdif(folderf, {"*.tex"});
 while(qdif.hasNext())
 {
  qdif.next();
  QString fp = qdif.filePath();
  result[paper_name]["figures"].push_back(fp);
 }
}


void generate_swl()
{
 // //  Pull all the `swl tag-commands

 QMap<QString, QString> files;

 get_section_files("ctg", files);
 get_section_files("icg", files);
 get_section_files("itm", files);

 qDebug() << files;


 QMap<QString, QMap<QString, QStringList>> source_files;

 get_source_files("ctg", source_files);
 get_source_files("icg", source_files);
 get_source_files("itm", source_files);

 QString src_copy_folder = ROOT_FOLDER "/../dev";
 QDir scdir(src_copy_folder);
 if(!scdir.exists("src-copy"))
   scdir.mkdir("src-copy");
 scdir.cd("src-copy");
 QMapIterator<QString, QMap<QString, QStringList>> sfit(source_files);
 while(sfit.hasNext())
 {
  sfit.next();
  QString pn = sfit.key();
  if(!scdir.exists(pn))
    scdir.mkdir(pn);
  scdir.cd(pn);

  QMapIterator<QString, QStringList> sfiti(sfit.value());

  while(sfiti.hasNext())
  {
   sfiti.next();
   QString subdir = sfiti.key();
   if(!scdir.exists(subdir))
     scdir.mkdir(subdir);
   scdir.cd(subdir);
   for(QString sf : sfiti.value())
   {
    copy_binary_file_to_folder(sf, scdir.absolutePath());
   }
   scdir.cdUp();
  }
  scdir.cdUp();
 }

 QString all_swl;

 u4 total_sample_count = 0;

 QString all_swl_top = R"(
;;--

  This file is automatically generated by extracting
  all "swl" and "udref" tag-commands from each .gt
  file used to generate the essays from which the
  data set is compiled.  The main purpose of this
  file is to document notation for different facets
  of language-sample annotations and metadata.

  While the GTagML compiler can parse this file
  and produce TeX output, the resulting code
  by itself would not be able to generate
  a usable PDF file (for example).

  Total samples: %1

--;;
)";


// if(files.contains())

 QStringList keys = files.keys();

 // // arrange keys so intro is always first

 QVector<QString> akeys(keys.size());

 s4 count = 0;
 s4 last_intro_pos = 0;
 for(QString key : keys)
 {
  if(key.endsWith("-intro"))
  {
   akeys[last_intro_pos] = key;
  }
  else if(key.endsWith("-1"))
  {
   last_intro_pos = count;
   ++count;
   akeys[count] = key;
   ++count;
  }
  else
  {
   akeys[count] = key;
   ++count;
  }
 }

// QMapIterator<QString, QString> it(files);

 for(QString akey: akeys)
 {
  QString val = files[akey];

  QString text = load_file(val);

  int samp_count = 0;
  int index = 0;
  int last = 0;
  int udr = 0;

  QString local_swl;
  while(last != -1)
  {
   index = text.indexOf("`swl ", last);
   if(index == -1)
     break;
   last = text.indexOf(";;", index);

   ++samp_count;

   QString swl = text.mid(index, last - index + 3);

   // // now look for a udref
   udr = text.indexOf("`udref", last);
   if(udr != -1)
   {
    // // 10 here is a rough number, just want to be
     //   sure only to match a udref immediately after
     //   the relevant swl ...
    if(udr < last + 10)
    {
     last = text.indexOf(";;", udr);
     if(!swl.endsWith("\n"))
       swl += "\n";
     swl += text.mid(udr, last - udr + 3);
    }
   }

   local_swl += "\n" + swl;

   if(!swl.endsWith("\n"))
     local_swl += "\n";
  }

  if(samp_count == 0)
    continue;

  total_sample_count += samp_count;

  QString sect = akey;

  if(sect.endsWith("-intro"))
    sect.replace("-", " (");
  else
    sect.replace("-", " (section ");
  sect += ")";

  all_swl += QString(
    "\n\n ;;- __________ \n ;;- From file: " + sect +
    "\n ;;- __________ (count: %1) \n\n")
    .arg(samp_count);

  all_swl += local_swl;

 }

 all_swl.append("\n\n");

 all_swl.prepend(all_swl_top.arg(total_sample_count));

 save_file(ROOT_FOLDER "/documents/all-samples.gt", all_swl);
}

void merge_markdown_samples(QStringList paper_names, QString out_name)
{
 QString markdown_folder = ROOT_FOLDER "/documents/markdown";
 QString all_text;
 for(QString pn : paper_names)
 {
  all_text += load_file(markdown_folder + "/" + pn + ".md");
 }

 backup_binary_file(markdown_folder + "/" + out_name + ".md");
 save_file(markdown_folder + "/" + out_name + ".md", all_text);
}

void copy_and_backup(QString paper_name, QString full_name)
{
 QString out_folder = ROOT_FOLDER "/../dev/documents/" + paper_name + "/out";
 QString dataset_folder = ROOT_FOLDER "/data/dataset/" + paper_name;

 QString documents_folder = ROOT_FOLDER "/documents";

 QDir qd(dataset_folder);
 if(!qd.exists("osf"))
   qd.mkdir("osf");

 qd.cd("osf");

 QString osf_folder = qd.absolutePath();

 backup_binary_file(dataset_folder + "/samples.ntxh");
 backup_binary_file(osf_folder + QString("/samples-%1.ntxh").arg(paper_name));

 copy_binary_file_to_folder_with_rename(out_folder + "/" + paper_name + ".ntxh",
   dataset_folder, "samples");
 copy_binary_file_to_folder_with_rename(out_folder + "/" + paper_name + ".ntxh",
   osf_folder, QString("samples-%1").arg(paper_name));

 backup_binary_file(dataset_folder + "/sdi-merge.ntxh");
 backup_binary_file(osf_folder + QString("/sdi-merge-%1.ntxh").arg(paper_name));

 copy_binary_file_to_folder_with_rename(out_folder + "/../sdi-merge.ntxh",
   dataset_folder, "sdi-merge");
 copy_binary_file_to_folder_with_rename(out_folder + "/../sdi-merge.ntxh",
   osf_folder, QString("sdi-merge-%1").arg(paper_name));

 backup_binary_file(dataset_folder + "/main.pdf");
 copy_binary_file_to_folder_with_rename(out_folder + "/" + paper_name + ".pdf",
   dataset_folder, "main");

 copy_binary_file_to_folder_with_rename(out_folder + "/" + paper_name + ".pdf",
   documents_folder, full_name);
}

// // a handful of utilities for finalizing the data set ...
int main(int argc, char *argv[])
{
 generate_swl();

 copy_and_backup("ctg", "CognitiveTransformGrammar");
 copy_and_backup("icg", "ConceptualSpacesAndTheIntroToCognitiveGrammar");
 copy_and_backup("itm", "InterfaceTheoryOfMeaning");

 merge_markdown_samples({"ctg", "icg", "itm"}, "samples");

 return 0;
}



