
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QDirIterator>

#include "chasm-lib/test-class.h"

#include "chasm-lib/unified-runtime-object.h"

#include "chasm-lib/metatype-object.h"

#include "textio.h"
USING_KANS(TextIO)

#include "chasm-lib/chasm/chasm-runtime.h"
#include "chasm-lib/chasm/chasm-call-package.h"



typedef void (*_temp_minimal_fn_s0_r0_type)();



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



