
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QDirIterator>

#include "textio.h"
USING_KANS(TextIO)


QStringList returns{{"void", "u1", "u2", "QString", "u4", "QByteArray", "r8", "QVariant", "n8", "void*"}};

QString generate_function_code(u1 retc, u2 key, QString sc)
{
 QString ret = returns[retc];
 QString retv;
 if(retc > 0) retv = ret + "& retv, ";


 QString result = QString("void _f_%1%2_(%3n8 arg1, n8 arg2, n8 arg3, minimal_fn_%4_re%1_type fn){\n  ")
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
  case 9: akey = 8; // fallthrough
  case 1: case 2: case 4: case 8:
   types[i] = QString("%1%2").arg(akey == 8?'n':'u').arg(akey);
   result += QString("%1 a%2=*(%1*)arg%2;").arg(types[i]).arg(i);
   break;

  case 3: // QString
   types[i] = "QString";
   result += QString("QString a%1=*(QString*)arg%1;").arg(i);
   break;

  case 5: // QByteArray
   types[i] = "QByteArray";
   result += QString("QByteArray a%1=*(QByteArray*)arg%1;").arg(i);
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

int main(int argc, char *argv[])
{
 /*
 0 = ref
 1 = u1
 2 = u2
 3 = QString
 4 = u4
 5 = QByteArray
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

  QString s0_3_reX_ch_eval_file = QString(ROOT_FOLDER "/dev/consoles/fns/s0/a3/ch-eval-s0_3_re%1.cpp").arg(i);
  QString s0_3_reX_ch_eval_text = R"(

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;
)";

  if(i > 0)
    s0_3_reX_ch_eval_text += R"(
Chasm_Channel* resultch = ccp->channel("result");
if(!resultch)
  return;
)";

  if(i == 0)
  {
   s0_3_reX_ch_eval_text += QString(R"(
run_s0_3_re0(fncode, (minimal_fn_s0_re0_type) fn,
  lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));
)");
  }
  else
  {
   s0_3_reX_ch_eval_text += QString(R"(
Chasm_Carrier cc = resultch->first_carrier();

%1%2 rr = %3cc.value%4<%1>();
run_s0_3_re%5(fncode, (minimal_fn_s0_re%5_type) fn,
  rr, lambda->pasn8(1), lambda->pasn8(2), lambda->pasn8(3));

if(rcar)
  rcar->set_value%6(rr);
)").arg(ret).arg( (i == 3 || i == 5 || i == 7 || i == 9)?"&":"")
   .arg("")  //.arg((i == 3 || i == 5 || i == 7 || i == 9)?"*("+ret+"*)":"")
   .arg((i == 3 || i == 5 || i == 7 || i == 9)?"_as":"")
   .arg(i)
   .arg((i == 3 || i == 5 || i == 7 || i == 9)?"_as<"+ret+">":
     //(i==9)?"":(i==0)?"*":
     ""

   )
   ;
  }
  save_file(s0_3_reX_ch_eval_file, s0_3_reX_ch_eval_text);

  // (i==9)?"*"

  QString s0_3_reX_file = QString(ROOT_FOLDER "/dev/consoles/fns/s0/a3/run-s0_3_re%1.cpp").arg(i);
  QString fn_array_reX_file = QString(ROOT_FOLDER "/dev/consoles/fns/s0/a3/fn-array-s0_3_re%1.cpp").arg(i);

  QString fn_array_reX_text;
  QString s0_3_reX_text = QString(R"(


#ifndef SEEN_DEFS_S0_3_RE%2
#define SEEN_DEFS_S0_3_RE%2

typedef %1(*minimal_fn_s0_re%2_type)();
typedef void(*run_s0_3_re%2_type)(%3n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re%2_type fn);
typedef run_s0_3_re%2_type s0_3_re%2_dispatch_array [1000];

#endif //  SEEN_DEFS_S0_3_RE%2

#ifdef FULL_INCLUDE

#include "fn-array-s0_3_re%2.cpp"

s0_3_re%2_dispatch_array* init_s0_3_re%2_dispatch_array()
{
 s0_3_re%2_dispatch_array* result = (s0_3_re%2_dispatch_array*) new run_s0_3_re%2_type[1000];
 )").arg(ret).arg(i).arg(retv);

  for(u2 j = 0; j < 1000; ++j)
  {
   s0_3_reX_text += QString("\n (*result)[%1] = &_f_%2%3_;").arg(j).arg(i).arg(j, 3, 10, QLatin1Char('0'));
  }

  s0_3_reX_text += QString(R"(
}

void run_s0_3_re%1(u4 code, minimal_fn_s0_re%1_type fn, %2n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static s0_3_re%1_dispatch_array* dispatch_array = init_s0_3_re%1_dispatch_array();
 run_s0_3_re%1_type f = (*dispatch_array)[code];
 f(%3a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
)").arg(i).arg(retv).arg(rsym);

  save_file(s0_3_reX_file, s0_3_reX_text);

  for(int j = 0; j < 1000; ++j)
    fn_array_reX_text += generate_function_code(i, j, "s0");
  save_file(fn_array_reX_file, fn_array_reX_text);
 }

 return 0;
}
