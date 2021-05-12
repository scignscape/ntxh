
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QPoint>

#include "chasm-lib/test-class.h"

#include "chasm-lib/unified-runtime-object.h"

#include "chasm-lib/metatype-object.h"

#include "chasm-lib/chasm/chasm-type-object.h"

#include "textio.h"
USING_KANS(TextIO)

#include "chasm-lib/chasm/chasm-runtime.h"
#include "chasm-lib/chasm/chasm-call-package.h"



typedef void (*_temp_minimal_fn_s0_r0_type)();

#ifdef HIDE
typedef minimal_fn_s0_re0_type minimal_fn_s0_type;
typedef minimal_fn_s1_re0_type minimal_fn_s1_type;


void testqvar(QVariant arg1, r8 arg2, u2 arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
}

void run_testqvar(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QVariant a1 = 103;
 r8 a2 = .12345;
 u2 a3 = 12345;

 Chasm_Carrier cc1 = csr->gen_carrier<QVariant>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<r8>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<u2>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});

 csr->evaluate(ccp, 70762, (minimal_fn_s0_type) &testqvar);
}


void testqvarf(QVariant arg1, r8 arg2, float* arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << *arg3;
}

void run_testqvarf(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QVariant a1 = 103;
 r8 a2 = .12345;
 float* a3 = new float(.12345);

 Chasm_Carrier cc1 = csr->gen_carrier<QVariant>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<r8>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<void*>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70769, (minimal_fn_s0_type) &testqvarf);
}




void testfn(s1 arg1, u4 arg2, s2& arg3)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << arg3;
 arg3 = -arg3;
}

void run_testfn(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 s1 a1 = -103;
 u4 a2 = -1;
 s2 a3 = -211;

 Chasm_Carrier cc1 = csr->gen_carrier<u1>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<n8&>(&a3);

 ccp->add_carriers({cc1,cc2,cc3});
 csr->evaluate(ccp, 70140, (minimal_fn_s0_type) &testfn);
 qDebug() << "a3 = " << a3;
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
 csr->evaluate(ccp, 70120, (minimal_fn_s0_type) &testsus);
 qDebug() << "a3 = " << a3;

 // ccp->add_new_channel("retvalue");
 // Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Retvalue._u1);
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
 csr->evaluate(ccp, 70120, (minimal_fn_s0_type) &testqss);
 qDebug() << "a3 = " << a3;

 // ccp->add_new_channel("retvalue");
 // Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Retvalue._u1);
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

 ccp->add_new_channel("retvalue");
 Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Retvalue._u1);
 ccp->add_carrier(cc0);

 csr->evaluate(ccp, 71341, (minimal_fn_s0_type) &testqs1, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Retvalue._u1);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 71341, (minimal_fn_s0_type) &testqs1n, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Retvalue._u2);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 72341, (minimal_fn_s0_type) &testqs2, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Retvalue._u2);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 72341, (minimal_fn_s0_type) &testqs2n, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<QString>(csr->Retvalue._QString);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 73341, (minimal_fn_s0_type) &testqsq, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Retvalue._u4);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 74341, (minimal_fn_s0_type) &testqs4, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Retvalue._u4);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 74341, (minimal_fn_s0_type) &testqs4n, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<QByteArray>(csr->Retvalue._QByteArray);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 75341, (minimal_fn_s0_type) &testqs5, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Retvalue._r8);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 76341, (minimal_fn_s0_type) &testqs6, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Retvalue._r8);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 76341, (minimal_fn_s0_type) &testqs6n, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<QVariant>(csr->Retvalue._QVariant);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 77341, (minimal_fn_s0_type) &testqsv, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<n8>(csr->Retvalue._n8);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 78341, (minimal_fn_s0_type) &testqs8, &cc0);
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

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<void*>();
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 79341, (minimal_fn_s0_type) &testqsp, &cc0);
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

 ccp->add_new_channel("retvalue");
 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);

 csr->evaluate(ccp, 79310, (minimal_fn_s0_type) &testqsb, &cc0);
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
 csr->evaluate(ccp, 70991, (minimal_fn_s0_type) &teste);
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
 csr->evaluate(ccp, 70000, (minimal_fn_s0_type) &testf);
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
 csr->evaluate(ccp, 70120, (minimal_fn_s0_type) &test2);
 qDebug() << "a3 = " << a3;
}



//#define run_s0_3_r0(a,b,c,d,e)


struct test_qpr
{
 QString qs;
 u4 uu;
 ~test_qpr()
 {
  qDebug() << "~test qpr";
 }

 QPair<QString, u4> to_pr() { return {qs, uu}; }
};



QPoint* test_smart(test_qpr& arg1, //QPair<QString, u4>& arg1,  //test_qpr& arg1,
                   QPoint& arg2, QStringList* arg3)
{
 qDebug() << "arg1 = " << arg1.to_pr();
 qDebug() << "arg2 = " << arg2;
 qDebug() << "arg3 = " << *arg3;
 return new QPoint(600,601);
}


void pre_run_smart(Chasm_Runtime* csr, QVector<Chasm_Typed_Value_Representation>& args)
{
 Chasm_Type_Object* ref_type_shared = csr->get_type_object_by_name("n8&!");
 Chasm_Type_Object* pVoid_type = csr->get_type_object_by_name("void*");
 Chasm_Type_Object* ref_type = csr->get_type_object_by_name("n8&");

 QString a11 = "Test";
 u4 a12 = 33;

 test_qpr* a1 = new test_qpr{a11, a12};
 args.push_back( ref_type_shared->make_instance(a1) );
 // args.push_back( ref_type_shared->with_instance(_a1) );

 QPoint* a2 = new QPoint(500,501);
 args.push_back( ref_type_shared->make_instance(a2) );


 QStringList* qsl = new QStringList{"qsl1", "qsl2"};

 args.push_back( pVoid_type->with_instance(qsl) );

}

void run_smart(Chasm_Runtime* csr, QVector<Chasm_Typed_Value_Representation>& args)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");


 Chasm_Carrier cc1 = csr->gen_carrier(args[0]);
 Chasm_Carrier cc2 = csr->gen_carrier(args[1]);
 Chasm_Carrier cc3 = csr->gen_carrier(args[2]);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 79009, (minimal_fn_s0_type) &test_smart, &cc0);
 QPoint* result = cc0.value<QPoint*>();
 qDebug() << "r = " << *result;

 csr->release(ccp);
}


void run_smart(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 QString a11 = "Test";
 u4 a12 = 33;
 test_qpr* a1 = new test_qpr{a11, a12};

 QPoint* a2 = new QPoint(500,501);
 QStringList* qsl = new QStringList{"qsl1", "qsl2"};


 Chasm_Carrier cc1 = csr->gen_carrier<n8&>(a1);
 Chasm_Carrier cc2 = csr->gen_carrier<n8&>(a2);
 Chasm_Carrier cc3 = csr->gen_carrier<void*>(&qsl);

 ccp->add_carriers({cc1,cc2,cc3});

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);
 csr->evaluate(ccp, 79009, (minimal_fn_s0_type) &test_smart, &cc0);
 QPoint* result = cc0.value<QPoint*>();
 qDebug() << "r = " << *result;

 csr->release(ccp);
}



void test2arg(bool arg1, s2& arg2)
{
 qDebug() << "arg1 = " << arg1;
 qDebug() << "arg2 = " << arg2;
 --arg2;
}

void run_test2arg(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 bool a1 = "true";
 s2 a2 = -533;

 Chasm_Carrier cc1 = csr->gen_carrier<u1>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<n8&>(&a2);

 ccp->add_carriers({cc1,cc2});
 csr->evaluate(ccp, 7010, (minimal_fn_s0_type) &test2arg);
 qDebug() << "a2 = " << a2;
}


void test1arg(s2& arg1)
{
 qDebug() << "arg1 = " << arg1;
 --arg1;
}

void run_test1arg(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 ccp->add_new_channel("lambda");

 s2 a1 = -533;

 Chasm_Carrier cc1 = csr->gen_carrier<n8&>(&a1);

 ccp->add_carriers({cc1});
 csr->evaluate(ccp, 700, (minimal_fn_s0_type) &test1arg);
 qDebug() << "a1 = " << a1;
}


void test0arg()
{
 qDebug() << "0 arg";
}

void run_test0arg(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();
 csr->evaluate(ccp, 70, (minimal_fn_s0_type) &test0arg);
}


QStringList* test0r9()
{
 QStringList* result = new QStringList;
 (*result) << "qsl1" << "qsl2";
 return result;
}

void run_test0r9(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();

 ccp->add_new_channel("retvalue");
 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);

 csr->evaluate(ccp, 79, (minimal_fn_s0_type) &test0r9, &cc0);
 QStringList* result = cc0.value<QStringList*>();
 qDebug() << "r = " << *result;

}


struct test0s1
{
 QStringList qsl;

 void test()
 {
  QStringList* result = new QStringList(qsl);
  (*result) << "_qsl1" << "_qsl2";
  qDebug() << "new string list: " << *result;
 }

 QStringList* testr()
 {
  QStringList* result = new QStringList(qsl);
  (*result) << "_qsl1" << "_qsl2";
  return result;
 }

};

void run_test0s1(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();

// ccp->add_new_channel("retvalue");

 ccp->add_new_channel("sigma");
 test0s1 ts1{{"q1", "q2"}};

 test0s1* arg1 = &ts1;

 Chasm_Carrier cc0 = csr->gen_carrier<void*>(&arg1);
 ccp->add_carrier(cc0);

 //csr->evaluate(ccp, 80, (minimal_fn_s1_type) &test0s1::test);

 csr->evaluate(ccp, 80, (minimal_fn_s1_type) &test0s1::test);


 //QStringList* result = cc0.value<QStringList*>();
 //qDebug() << "r = " << *result;

}


void run_test0s1r(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();


 ccp->add_new_channel("sigma");
 test0s1 ts1{{"q1", "q2"}};

 test0s1* arg1 = &ts1;

 Chasm_Carrier cc_this = csr->gen_carrier<void*>(&arg1);
 ccp->add_carrier(cc_this);

 ccp->add_new_channel("retvalue");
 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);

 csr->evaluate(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

// csr->evaluate_s1(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

// csr->evaluate_s01(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

 QStringList* result = cc0.value<QStringList*>();
 qDebug() << "r = " << *result;
}

#endif


QStringList* teste4(QString start, QVector<u4>& nums, u2 c1, QChar c2)
{
 QStringList* result = new QStringList(start);
 u2 i = 0;
 for(u4 n: nums)
 {
  ++i;
  (*result) << QString("%1=%2").arg(i).arg(n, c1, 10, QChar(c2) );
 }
 return result;
}

void run_teste4(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();


 ccp->add_new_channel("lambda");

 QString a1 = "true";
 QVector<u4> nums {12, 144, 542, 5578};
 u2 fw = 10;
 u2 ch = '*';

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<n8&>(&nums);
 Chasm_Carrier cc3 = csr->gen_carrier<u2>(&fw);
 Chasm_Carrier cc4 = csr->gen_carrier<u2>(&ch);

 ccp->add_carriers({cc1,cc2,cc3,cc4});

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);


  // 49'023'3122_cfc

  //  Chasm_Function_Code cfc = 0x9F4090233122_parse;

// Chasm_Function_Code cfc1 = 4090233122_cfc;
// Chasm_Function_Code cfc2 = 4093022_cfc; //parse;

// Chasm_Function_Code cfc1 = 5096821122_cfc;
// Chasm_Function_Code cfc2 = 60968122122_cfc;

// Chasm_Function_Code cfc1 = 5096_cfc;
// Chasm_Function_Code cfc2 = 6096_cfc;


// Chasm_Function_Code cfc1 = 50964446_cfc;
// Chasm_Function_Code cfc2 = 609787878_cfc;

 csr->evaluate(ccp, 4093022_cfc, //(minimal_fn_s0_re4_type)
         &teste4, &cc0);

// csr->evaluate(ccp, 4090233122_cfc, //(minimal_fn_s0_re4_type)
//         &teste4, &cc0);

// csr->e4(ccp, 309023312_cfc, //(minimal_fn_s0_re4_type)
//         &teste4, &cc0);




// csr->evaluate_s1(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

// csr->evaluate_s01(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

 QStringList* result = cc0.value<QStringList*>();
 qDebug() << "r = " << *result;
}




QStringList* teste4of1(QString start, QString start1, QString start2, QString start3)
{
 QStringList* result = new QStringList({start, start1, start2, start3});
 return result;
}

void run_teste4of1(Chasm_Runtime* csr)
{
 Chasm_Call_Package* ccp = csr->new_call_package();


 ccp->add_new_channel("lambda");

 QString a1 = "true";
 QString a2 = "false";
 QString a3 = "maybe";
 QString a4 = "unknown";

 Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a1);
 Chasm_Carrier cc2 = csr->gen_carrier<QString>(&a2);
 Chasm_Carrier cc3 = csr->gen_carrier<QString>(&a3);
 Chasm_Carrier cc4 = csr->gen_carrier<QString>(&a4);

 ccp->add_carriers({cc1,cc2,cc3,cc4});

 ccp->add_new_channel("retvalue");

 Chasm_Carrier cc0 = csr->gen_carrier<void*>(csr->Retvalue._ptr);
 ccp->add_carrier(cc0);


  // 49'023'3122_cfc

  //  Chasm_Function_Code cfc = 0x9F4090233122_parse;

// Chasm_Function_Code cfc1 = 4090233122_cfc;
// Chasm_Function_Code cfc2 = 4093022_cfc; //parse;

// Chasm_Function_Code cfc1 = 5096821122_cfc;
// Chasm_Function_Code cfc2 = 60968122122_cfc;

// Chasm_Function_Code cfc1 = 5096_cfc;
// Chasm_Function_Code cfc2 = 6096_cfc;


// Chasm_Function_Code cfc1 = 50964446_cfc;
// Chasm_Function_Code cfc2 = 609787878_cfc;

 csr->evaluate(ccp, 4093_cfc, //(minimal_fn_s0_re4_type)
         &teste4of1, &cc0);

// csr->evaluate(ccp, 4090233122_cfc, //(minimal_fn_s0_re4_type)
//         &teste4, &cc0);

// csr->e4(ccp, 309023312_cfc, //(minimal_fn_s0_re4_type)
//         &teste4, &cc0);




// csr->evaluate_s1(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

// csr->evaluate_s01(ccp, 89, (minimal_fn_s1_type) &test0s1::testr, &cc0);

 QStringList* result = cc0.value<QStringList*>();
 qDebug() << "r = " << *result;
}



int main(int argc, char *argv[])
{
 Chasm_Runtime* csr = new Chasm_Runtime;
 csr->init_no_file_session();

 qDebug() << "\n----\n";
// run_teste4(csr);
//
//
 run_teste4of1(csr);

 qDebug() << "\n===\n";


#ifdef HIDE
 qDebug() << "\n----\n";
 run_test0s1(csr);

 qDebug() << "\n===\n";
 run_test0s1r(csr);

 qDebug() << "\n===\n";
 run_test0arg(csr);

 qDebug() << "\n===\n";
 run_test0r9(csr);


// run_test0arg(csr);
// qDebug() << "\n===\n";
// run_test0r9(csr);

 qDebug() << "\n===\n";
 run_test1arg(csr);

 qDebug() << "\n===\n";
 run_test2arg(csr);

// QVector<Chasm_Typed_Value_Representation> rs_args;

// pre_run_smart(csr, rs_args);
// run_smart(csr, rs_args);

//#endif //def HIDE

 qDebug() << "\n===\n";
 run_testqvar(csr);

//#ifdef HIDE
 qDebug() << "\n===\n";
 run_testqvarf(csr);

 qDebug() << "\n===\n";
 run_testfn(csr);

 qDebug() << "\n===\n";
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

 qDebug() << "\n_____\n";

#endif

// Chasm_Call_Package* ccp = csr->new_call_package();
// ccp->add_new_channel("lambda");

// QString a11 = "Test";
// u4 a21 = 33;
// u1 a31 = 111;

// Chasm_Carrier cc1 = csr->gen_carrier<QString>(&a11);
// Chasm_Carrier cc2 = csr->gen_carrier<u4>(&a21);
// Chasm_Carrier cc3 = csr->gen_carrier<u1>(&a31);

// ccp->add_carriers({cc1,cc2,cc3});

// ccp->add_new_channel("retvalue");


// Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Retvalue._u1);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1, &cc0);
// u1 result = cc0.value<u1>();
// qDebug() << "r = " << result;


//  Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Retvalue._u1);
//  ccp->add_carrier(cc0);
//  csr->evaluate(ccp, 71341, (minimal_fn_s0_re1_type) &testqs1n, &cc0);
//  s1 result = cc0.value<s1>();
//  qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Retvalue._u2);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 72341, (minimal_fn_s0_re1_type) &testqs2, &cc0);
// u2 result = cc0.value<u2>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u2>(csr->Retvalue._u2);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 72341, (minimal_fn_s0_re1_type) &testqs2n, &cc0);
// s2 result = cc0.value<s2>();
// qDebug() << "r = " << result;


 // Chasm_Carrier cc0 = csr->gen_carrier<QString>(csr->Retvalue._QString);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 13341, (minimal_fn_s0_re3_type) &testqss);
// QString result = cc0.value<QString>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Retvalue._u4);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 74341, (minimal_fn_s0_re4_type) &testqs4, &cc0);
// u4 result = cc0.value<u4>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<u4>(csr->Retvalue._u4);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 74341, (minimal_fn_s0_re4_type) &testqs4n, &cc0);
// s4 result = cc0.value<s4>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<QByteArray>(csr->Retvalue._QByteArray);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 75341, (minimal_fn_s0_re5_type) &testqs5, &cc0);
// QByteArray result = cc0.value<QByteArray>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Retvalue._r8);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 76341, (minimal_fn_s0_re6_type) &testqs6, &cc0);
// r8 result = cc0.reinterpret_value<r8>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Retvalue._r8);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 76341, (minimal_fn_s0_re6_type) &testqs6n, &cc0);
// r8 result = cc0.reinterpret_value<r8>();
// qDebug() << "r = " << result;

// Chasm_Carrier cc0 = csr->gen_carrier<QVariant>(csr->Retvalue._QVariant);
// ccp->add_carrier(cc0);
// csr->evaluate(ccp, 77341, (minimal_fn_s0_re7_type) &testqsv, &cc0);
// QVariant result = cc0.value<QVariant>();
// qDebug() << "r = " << result.toString();

// Chasm_Carrier cc0 = csr->gen_carrier<n8>(csr->Retvalue._n8);
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

// ccp->add_new_channel("retvalue");

// Chasm_Carrier cc0 = csr->gen_carrier<void*>();
// //cc0.set_raw_value((n8) *(void**)pv )//csr->Retvalue._ptr);
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

// ccp->add_new_channel("retvalue");

// Chasm_Carrier cc0 = csr->gen_carrier<u1>(csr->Retvalue._u1);
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



int main2(int argc, char *argv[])
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


