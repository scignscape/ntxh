
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



void testqvar(QVariant arg1, double arg2, float* arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << *arg3;
}


void testfn(s1 arg1, u4 arg2, s2& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 arg3 = -arg3;
}

s1 testsus(s1 arg1, u4 arg2, s2 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;

 return -arg1;
}

void run_testsus(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 bool a1 = "true";
 s2 a2 = -533;
 s2 a3 = -211;

 Chasm_Carrier cc1 = csr->gen_carrier<u1>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u2>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<n8&>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70120, (minimal_fn_s0_re0_type) &testsus);
 qDebug() << "a3 = " << a3;

 // ccp->add_new_channel("result");
 // Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Result._u1);
 // ccp->add_carrier(cc0);
 // csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1, &cc0);
 // u1 result = cc0.value<u1>();
 // qDebug() << "r = " << result;
}


void testqs(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
}

QString testqss(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 return QString("%1, %2, %3").arg(arg1).arg(arg2).arg(arg3);
}

void run_testqss(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 bool a1 = "true";
 s2 a2 = -533;
 s2 a3 = -211;

 Chasm_Carrier cc1 = csr->gen_carrier<u1>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u2>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<n8&>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70120, (minimal_fn_s0_re0_type) &testqss);
 qDebug() << "a3 = " << a3;

 // ccp->add_new_channel("result");
 // Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Result._u1);
 // ccp->add_carrier(cc0);
 // csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1, &cc0);
 // u1 result = cc0.value<u1>();
 // qDebug() << "r = " << result;
}


u1 testqs1(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 u1 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return result;
}

void run_testqs1(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "A1";
 u4 a2 = 123456789;
 u1 a3 = 135;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");
 Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Result._u1);
 ccp->add_carrier(cc0);

 csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1, &cc0);
 u1 result = cc0.value<u1>();
 qDebug() << "r = " << result;
}


s1 testqs1n(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 u1 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return -result;
}

void run_testqs1n(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Result._u1);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1n, &cc0);
 s1 result = cc0.value<s1>();
 qDebug() << "r = " << result;
}

u2 testqs2(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 u2 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return result * 100;
}

void run_testqs2(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Result._u2);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 72341, (minimal_fn_s0_re2_type) &testqs2, &cc0);
 u2 result = cc0.value<u2>();
 qDebug() << "r = " << result;
}


s2 testqs2n(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 s2 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return -result * 100;
}

void run_testqs2n(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Result._u2);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 72341, (minimal_fn_s0_re2_type) &testqs2n, &cc0);
 s2 result = cc0.value<s2>();
 qDebug() << "r = " << result;
}


QString testqsq(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 QString result = QString("[%1 - %2 - %3]").arg(arg1).arg(arg2).arg(arg3);
 return result;
}

void run_testqsq(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<QString>(csr->Result._QString);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 73341, (minimal_fn_s0_re3_type) &testqsq, &cc0);
 QString result = cc0.value<QString>();
 qDebug() << "r = " << result;
}



u4 testqs4(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 u4 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return result * 10000;
}

void run_testqs4(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Result._u4);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 74341, (minimal_fn_s0_re4_type) &testqs4, &cc0);
 u4 result = cc0.value<u4>();
 qDebug() << "r = " << result;
}

s4 testqs4n(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 s4 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return -result * 10000;
}

void run_testqs4n(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Result._u4);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 74341, (minimal_fn_s0_re4_type) &testqs4n, &cc0);
 s4 result = cc0.value<s4>();
 qDebug() << "r = " << result;
}


QByteArray testqs5(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 QByteArray result = QString("%1, %2, %3").arg(arg1).arg(arg2).arg(arg3).toLatin1();
 return result;
}

void run_testqs5(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<QByteArray>(csr->Result._QByteArray);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 75341, (minimal_fn_s0_re5_type) &testqs5, &cc0);
 QByteArray result = cc0.value<QByteArray>();
 qDebug() << "r = " << result;
}



r8 testqs6(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 r8 result = ((r8) arg1.size()) / (arg1.size() + arg2 + arg3);
 return result;
}

void run_testqs6(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Result._r8);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 76341, (minimal_fn_s0_re6_type) &testqs6, &cc0);
 QVariant result = cc0.value<r8>();
 qDebug() << "r = " << result;
}


r8 testqs6n(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 r8 result = ((r8) arg1.size()) / (arg1.size() + arg2 + arg3);
 return -result;
}

void run_testqs6n(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Result._r8);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 76341, (minimal_fn_s0_re6_type) &testqs6n, &cc0);
 QVariant result = cc0.value<r8>();
 qDebug() << "r = " << result;
}

QVariant testqsv(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 QString result = QString("%1, %2, %3").arg(arg1).arg(arg2).arg(arg3).toLatin1();
 return QVariant::fromValue(result);
}

void run_testqsv(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<QVariant>(csr->Result._QVariant);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 77341, (minimal_fn_s0_re7_type) &testqsv, &cc0);
 QVariant result = cc0.value<QVariant>();
 qDebug() << "r = " << result;
}



n8 testqs8(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 n8 result = arg1.size() + (arg2 % 10) + (arg3 % 10);
 return result * 10000000;
}

void run_testqs8(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<n8>(csr->Result._n8);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 78341, (minimal_fn_s0_re8_type) &testqs8, &cc0);
 n8 result = cc0.value<n8>();
 qDebug() << "r = " << result;
}




QString* testqsp(QString arg1, u4 arg2, u1 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 QString result = QString("%1, %2, %3").arg(arg1).arg(arg2).arg(arg3).toLatin1();
 return new QString(result);
}

void run_testqsp(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "Test";
 u4 a2 = 33;
 u1 a3 = 111;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");

 Chasm_Carrier cc0 = csr->gen_carrier<void*>();
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 79341, (minimal_fn_s0_re9_type) &testqsp, &cc0);
 QString* result = (QString*) cc0.value<void*>();
 qDebug() << "r = " << *result;
}




QString* testqsb(QString arg1, bool arg2, bool& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 QString result = QString("%1, %2, %3").arg(arg1).arg(arg2).arg(arg3).toLatin1();
 arg3 = !arg3;
 return new QString(result);
}

void run_testqsb(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a1 = "A1";
 bool a2 = true;
 bool a3 = false;

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u1>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<n8&>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("result");
 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Result._ptr);
 ccp->add_carrier(cc0);

 csr->evaluate(ccp, 79310, (minimal_fn_s0_re9_type) &testqsb, &cc0);
 qDebug() << "a3 = " << a3;
 QString result = cc0.value<QString>();
 qDebug() << "r = " << result;
}


enum class test_enum { E1, E2, E3 };

void teste(QStringList* arg1, u4* arg2, test_enum arg3)
{
 qDebug() << "arg1 = " << *arg1;
 qDebug() << "arg2 = " << *arg2;
 qDebug() << "arg3 = " << (u1) arg3;
 ++*arg2;
}

void run_teste(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QStringList* a1 = new QStringList({"Ptr", "A2"});
 u4* a2 = new u4(92300);
 test_enum a3 = test_enum::E3;

 Chasm_Carrier cc1 = csr->gen_carrier<void*>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<void*>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70991, (minimal_fn_s0_re0_type) &teste);
 qDebug() << "a2 = " << *a2;
}


void testf(QStringList& arg1, test_enum& arg2, double& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << (u1) arg2;
 qDebug() << "arg3 = " << arg3;
 arg1.first().prepend("(");
 arg1.first().append(")");

 arg1.append("OK");

 arg2 = test_enum::E2;

 arg3 = 0.12345;
}


void run_testf(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QStringList a1 {"Ptr", "A2"};
 test_enum a2 = test_enum::E3;
 double a3 = 0.98765;

 Chasm_Carrier cc1 = csr->gen_carrier<n8&>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<n8&>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<n8&>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70000, (minimal_fn_s0_re0_type) &testf);
 qDebug() << "a1 = " << a1;
 qDebug() << "a2 = " << (u1) a2;
 qDebug() << "a3 = " << a3;
}


void test2(bool arg1, s2 arg2, s2& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 --arg3;
}

void run_test2(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 bool a1 = "true";
 s2 a2 = -533;
 s2 a3 = -211;

 Chasm_Carrier cc1 = csr->gen_carrier<u1>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u2>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<n8&>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70120, (minimal_fn_s0_re0_type) &test2);
 qDebug() << "a3 = " << a3;
}



//#define run_s0_3_r0(a,b,c,d,e)

int main(int argc, char *argv[])
{
 Chasm_Runtime* csr = new Chasm_Runtime;
 csr->init_no_file_session();

 run_test2(csr);
 qDebug() << "\n===\n";
 run_teste(csr);
 qDebug() << "\n===\n";
 run_testf(csr);

 qDebug() << "\n===\n";

 run_testqs1(csr);
 qDebug() << "\n===\n";

 run_testqs1n(csr);
 qDebug() << "\n===\n";

 run_testqs2(csr);
 qDebug() << "\n===\n";
 run_testqs2n(csr);
 qDebug() << "\n===\n";

 run_testqsq(csr);
 qDebug() << "\n===\n";

 run_testqs4(csr);
 qDebug() << "\n===\n";
 run_testqs4n(csr);
 qDebug() << "\n===\n";

 run_testqs5(csr);
 qDebug() << "\n===\n";


 run_testqs6(csr);
 qDebug() << "\n===\n";
 run_testqs6n(csr);
 qDebug() << "\n===\n";

 run_testqsv(csr);
 qDebug() << "\n===\n";
 run_testqs8(csr);
 qDebug() << "\n===\n";
 run_testqsp(csr);
 qDebug() << "\n===\n";
 run_testqsb(csr);



// Chasm_Call_Package* ccp = csr->new_call_package();
// ccp->add_new_channel("lambda");

// QString a11 = "Test";
// u4 a21 = 33;
// u1 a31 = 111;

// Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a11);
// Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a21);
// Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a31);

// ccp->add_carriers({cc1,cc2,cc3});

// ccp->add_new_channel("result");


// Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Result._u1);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1, &cc0);
// u1 result = cc0.value<u1>();
// qDebug() << "r = " << result;


//  Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Result._u1);
//  ccp->add_carrier(cc0);
//  csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1n, &cc0);
//  s1 result = cc0.value<s1>();
//  qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Result._u2);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 72341, (minimal_fn_s0_re1_type) &testqs2, &cc0);
// u2 result = cc0.value<u2>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Result._u2);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 72341, (minimal_fn_s0_re1_type) &testqs2n, &cc0);
// s2 result = cc0.value<s2>();
// qDebug() << "r = " << result;


 // Chasm_Carrier cc0 = csr->gen_carrier<QString>(csr->Result._QString);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 13341, (minimal_fn_s0_re3_type) &testqss);
// QString result = cc0.value<QString>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Result._u4);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 74341, (minimal_fn_s0_re4_type) &testqs4, &cc0);
// u4 result = cc0.value<u4>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Result._u4);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 74341, (minimal_fn_s0_re4_type) &testqs4n, &cc0);
// s4 result = cc0.value<s4>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<QByteArray>(csr->Result._QByteArray);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 75341, (minimal_fn_s0_re5_type) &testqs5, &cc0);
// QByteArray result = cc0.value<QByteArray>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Result._r8);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 76341, (minimal_fn_s0_re6_type) &testqs6, &cc0);
// r8 result = cc0.reinterpret_value<r8>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Result._r8);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 76341, (minimal_fn_s0_re6_type) &testqs6n, &cc0);
// r8 result = cc0.reinterpret_value<r8>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<QVariant>(csr->Result._QVariant);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 77341, (minimal_fn_s0_re7_type) &testqsv, &cc0);
// QVariant result = cc0.value<QVariant>();
// qDebug() << "r = " << result.toString();

// Chasm_Carrier cc0 = csr->gen_carrier<n8>(csr->Result._n8);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 78341, (minimal_fn_s0_re8_type) &testqs8, &cc0);
// n8 result = cc0.value<n8>();
// qDebug() << "r = " << result;

// Chasm_Call_Package* ccp = csr->new_call_package();
// ccp->add_new_channel("lambda");

// QString a11 = "Test";
// u4 a21 = 33;
// u1 a31 = 111;

//  Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a11);
//  Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a21);
//  Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a31);

// ccp->add_carriers({cc1,cc2,cc3});

// ccp->add_new_channel("result");

// Chasm_Carrier cc0 = csr->gen_carrier<void*>();
// //cc0.set_raw_value((n8) *(void**)pv )//csr->Result._ptr);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 79341, (minimal_fn_s0_re9_type) &testqsp, &cc0);
// QString* result = (QString*) cc0.value<void*>();
// qDebug() << "r = " << *result;

// s1 a12 = -4;
// u4 a22 = 10033;
// s2 a32 = -340;

// Chasm_Carrier cc1 = csr->gen_carrier<u1>(&a12);
// Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a22);
// Chasm_Carrier cc3 = csr->gen_carrier<u2>(&a32);

// ccp->add_carriers({cc1,cc2,cc3});

// ccp->add_new_channel("result");

// Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Result._u1);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 71142, (minimal_fn_s0_re1_type) &testsus, &cc0);

// s1 result = cc0.value<s1>();
// qDebug() << "r = " << result;

// QStringList* a13 = new QStringList({"Ptr", "A2"});
// u4* a23 = new u4(92300);
// test_enum a33 = test_enum::E3;


// Chasm_Carrier cc1 = csr->gen_carrier<void*>(&a13);
// Chasm_Carrier cc2 = csr->gen_carrier<void*>(&a23);
// Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a33);

// ccp->add_carriers({cc1,cc2,cc3});

// csr->evaluate(ccp, 70991, (minimal_fn_s0_re0_type) &teste);

// qDebug() << "a23 = " << *a23;
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


