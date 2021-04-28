
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

#include "chasm/chasm-runtime.h"
#include "chasm/chasm-call-package.h"



typedef void (*_temp_minimal_fn_s0_r0_type)();



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

QString testqsr(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 return QString("%1, %2, %3").arg(arg1).arg(arg2).arg(arg3);
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


void f_140 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 u1 a1 = *(u1*)arg1;
 u4 a2 = *(u4*)arg2;
 n8& a3 = *(n8*)arg3;

 ((void(*)(u1,u4,n8&)) fn)(a1,a2,a3);
}

void f_149 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 u1 a1 = *(u1*)arg1;
 u4 a2 = *(u4*)arg2;
 n8 a3 = *(n8*)arg3;

 ((void(*)(u1,u4,n8)) fn)(a1,a2,a3);
}


void f_341 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 QString a1 = *(QString*)arg1;
 u4 a2 = *(u4*)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(QString,u4,u1)) fn)(a1,a2,a3);
}

void f_041 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 n8& a1 = *(n8*)arg1;
 u4 a2 = *(u4*)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(n8&,u4,u1)) fn)(a1,a2,a3);
}

void f_ (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 void* a1 = *(void**)arg1;
 void* a2 = *(void**)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(void*,void*,u1)) fn)(a1,a2,a3);
}

void f_769 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 QVariant a1 = *(QVariant*)arg1;
 r8 a2 = *(r8*)arg2;
 n8 a3 = *(n8*)arg3;

 ((void(*)(QVariant, r8, n8)) fn)(a1,a2,a3);
}

void f_220 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 u2 a1 = *(u2*)arg1;
 u2 a2 = *(u2*)arg2;
 n8& a3 = *(n8*)arg3;

 ((void(*)(u2, u2, n8&)) fn)(a1,a2,a3);
}


void f_881 (n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn)
{
 n8 a1 = *(n8*)arg1;
 n8 a2 = *(n8*)arg2;
 u1 a3 = *(u1*)arg3;

 ((void(*)(n8, n8, u1)) fn)(a1,a2,a3);
}

typedef void(*_temp_run_s0_3_type)(n8 arg1, n8 arg2, n8 arg3, _temp_minimal_fn_s0_r0_type fn);

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

void _temp_run(u4 code, _temp_minimal_fn_s0_r0_type fn, n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static _temp_s0_3_dispatch_array* fs = _temp_init_s0_3_dispatch_array(); // (farr*) new run_s0_3_type[1001];
 _temp_run_s0_3_type f = (*fs)[code];
 f(a1, a2, a3, fn);
}

#define run_s0_3_r0(a,b,c,d,e)

int main(int argc, char *argv[])
{
 Chasm_Runtime* csr = new Chasm_Runtime;
 csr->init_no_file_session();
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a11 = "Test";
 u4 a21 = 33;
 u1 a31 = 11;

 Chasm_Carrier cc1 = csr->gen_carrier();
 cc1.set_value((n8) &a11);

 Chasm_Carrier cc2 = csr->gen_carrier();
 cc1.set_value((n8) &a21);

 Chasm_Carrier cc3 = csr->gen_carrier();
 cc1.set_value((n8) &a31);

 ccp->add_carrier(cc1);
 ccp->add_carrier(cc2);
 ccp->add_carrier(cc3);

 csr->evaluate(ccp, 10341, (minimal_fn_s0_r0_type) &testqs);
 //ccp->add_carrier()
}

int main3(int argc, char *argv[])
{
 QString a11 = "Test";
 u4 a21 = 33;
 u1 a31 = 11;
 _temp_run(10341, (_temp_minimal_fn_s0_r0_type) &testqs, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;

 qDebug() << "\n====\n";
 run_s0_3_r0(10341, (minimal_fn_s0_r0_type) &testqs, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;
 qDebug() << "\n====\n\n";

 _temp_run(10041, (_temp_minimal_fn_s0_r0_type) &testf, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;

 qDebug() << "\n====\n";
 run_s0_3_r0(10041, (minimal_fn_s0_r0_type) &testf, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "a11 = " << a11;
 qDebug() << "\n====\n\n";


 QString test_res;
 //run_s0_3_r3(30341, (minimal_fn_s0_r3_type) &testqsr, test_res, (n8) &a11, (n8) &a21, (n8) &a31);
 qDebug() << "test_res = " << test_res;
 qDebug() << "\n====\n\n";


 s1 a12 = -4;
 u4 a22 = 10033;
 s1 a32 = -40;

 _temp_run(10140, (_temp_minimal_fn_s0_r0_type) &testfn, (n8) &a12, (n8) &a22, (n8) &a32);
 qDebug() << "a32 = " << a32;

 qDebug() << "\n====\n";
 run_s0_3_r0(10140, (minimal_fn_s0_r0_type) &testfn, (n8) &a12, (n8) &a22, (n8) &a32);
 qDebug() << "a32 = " << a32;

 qDebug() << "\n====\n\n";

// run(149, (_temp_minimal_fn_s0_r0_type) &testfn, (n8) &a12, (n8) &a22, (n8) &a32);
// qDebug() << "a32 = " << a32;

 QStringList* a13 = new QStringList({"Ptr", "A2"});
 u4* a23 = new u4(92300);
 test_enum a33 = test_enum::E3;

 _temp_run(10881, (_temp_minimal_fn_s0_r0_type) &teste, (n8) &a13, (n8) &a23, (n8) &a33);
 qDebug() << "a23 = " << *a23;

 qDebug() << "\n====\n";
 run_s0_3_r0(10881, (minimal_fn_s0_r0_type) &teste, (n8) &a13, (n8) &a23, (n8) &a33);
 qDebug() << "a23 = " << *a23;
 qDebug() << "\n====\n\n";

 u2 a14 = 22;
 s2 a24 = -22;
 s2 a34 = 0;

 _temp_run(10220, (_temp_minimal_fn_s0_r0_type) &test2, (n8) &a14, (n8) &a24, (n8) &a34);
 qDebug() << "a34 = " << a34;

 qDebug() << "\n====\n";
 run_s0_3_r0(10220, (minimal_fn_s0_r0_type) &test2, (n8) &a14, (n8) &a24, (n8) &a34);
 qDebug() << "a34 = " << a34;
 qDebug() << "\n====\n\n";


 QVariant a15 = QVariant::fromValue(QString("var..."));
 double a25 = 22./93;
 float a35 = 22./95;
 float* _a35 = &a35;
 qDebug() << "a15 = " << a15;
 qDebug() << "a25 = " << a25;
 qDebug() << "a35 = " << a35;

 _temp_run(10769, (_temp_minimal_fn_s0_r0_type) &testqvar, (n8) &a15, (n8) &a25, (n8) &_a35);

 qDebug() << "\n====\n";
 run_s0_3_r0(10769, (minimal_fn_s0_r0_type) &testqvar, (n8) &a15, (n8) &a25, (n8) &_a35);
 qDebug() << "\n====\n\n";

 return 0;
}

QStringList returns{{"void", "u1", "u2", "QString", "u4", "void**", "r8", "QVariant", "n8", "void*"}};

QString generate_function_code(u1 retc, u2 key, QString sc)
{
 QString ret = returns[retc];
 QString retv;
 if(retc > 0) retv = ret + "& retv, ";


 QString result = QString("void _f_%1%2_(%3n8 arg1, n8 arg2, n8 arg3, minimal_fn_%4_r%1_type fn){\n  ")
   .arg(retc).arg(key, 3, 10, QLatin1Char('0')).arg(retv).arg(sc);

 u1 akey = 0;

 // types[0] is return ...
 static QString types [4] = {ret,{},{},{}};

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

 if(retc > 0) result += "retv=";

 result += QString("((%1(*)(%2,%3,%4)) fn)(a1,a2,a3);}\n\n")
   .arg(ret).arg(types[1]).arg(types[2]).arg(types[3]);

 return result;
}

int main2(int argc, char *argv[])
{
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

 for(u1 i = 0; i < 10; ++i)
 {
  QString ret = returns[i];
  QString retv, rsym;

  // //  concisely initialize two strings.  A bit cute.
  if(i > 0) retv = QString("%1& %2").arg(ret).arg(rsym = "retv, ");

  QString s0_3_rX_file = QString(ROOT_FOLDER "/dev/consoles/fns/run-s0_3_r%1.cpp").arg(i);
  QString fn_array_rX_file = QString(ROOT_FOLDER "/dev/consoles/fns/fn-array-s0_3_r%1.cpp").arg(i);

  QString fn_array_rX_text;
  QString s0_3_rX_text = QString(R"(

typedef %1(*minimal_fn_s0_r%2_type)();
typedef void(*run_s0_3_r%2_type)(%3n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_r%2_type fn);
typedef run_s0_3_r%2_type s0_3_r%2_dispatch_array [1000];

#include "fn-array-s0_3_r%2.cpp"

s0_3_r%2_dispatch_array* init_s0_3_r%2_dispatch_array()
{
 s0_3_r%2_dispatch_array* result = (s0_3_r%2_dispatch_array*) new run_s0_3_r%2_type[1000];
 )").arg(ret).arg(i).arg(retv);

  for(u2 j = 0; j < 1000; ++j)
  {
   s0_3_rX_text += QString("\n (*result)[%1] = &_f_%2%3_;").arg(j).arg(i).arg(j, 3, 10, QLatin1Char('0'));
  }

  s0_3_rX_text += QString(R"(
}

void run_s0_3_r%1(u4 code, minimal_fn_s0_r%1_type fn, %2n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static s0_3_r%1_dispatch_array* dispatch_array = init_s0_3_r%1_dispatch_array();
 run_s0_3_r%1_type f = (*dispatch_array)[code];
 f(%3a1, a2, a3, fn);
}
)").arg(i).arg(retv).arg(rsym);

  save_file(s0_3_rX_file, s0_3_rX_text);

  for(int j = 0; j < 1000; ++j)
    fn_array_rX_text += generate_function_code(i, j, "s0");
  save_file(fn_array_rX_file, fn_array_rX_text);
 }

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


