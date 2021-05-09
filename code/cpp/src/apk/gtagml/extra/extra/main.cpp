
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include <QMap>
#include <QTextStream>
#include <QDataStream>

#include <QDirIterator>

#include "textio.h"
USING_KANS(TextIO)


QStringList returns{{"void", "u1", "u2", "QString", "u4", "QByteArray", "r8", "QVariant", "n8", "void*"}};


void parse_fn_code(u4 cue)
{
 u4 cc = cue;

 u1 st_code, return_type_code, pattern_digits_run;
 u2 distinct_type_pattern, arguments_type_pattern;

 if(cue >= 10000000)
 {
  st_code = (cue/10000000) - 1;
  cue %= 10000000;
  return_type_code = cue/1000000;
  cue %= 1000000;
  pattern_digits_run = 6;
 }
 else if(cue >= 1000000)
 {
  st_code = (cue/1000000) - 1;
  cue %= 1000000;
  return_type_code = cue/100000;
  cue %= 10000;
  pattern_digits_run = 5;
 }
 else if(cue >= 100000)
 {
  st_code = (cue/100000) - 1;
  cue %= 100000;
  return_type_code = cue/1000;
  cue %= 1000;
  pattern_digits_run = 4;
 }
 else if(cue >= 10000)
 {
  st_code = (cue/10000) - 1;
  cue %= 10000;
  return_type_code = cue/1000;
  cue %= 1000;
  pattern_digits_run = 3;
 }
 else if(cue >= 1000)
 {
  st_code = (cue/1000) - 1;
  cue %= 1000;
  return_type_code = cue/100;
  cue %= 100;
  pattern_digits_run = 2;
 }
 else
 {
  // only valid range 10-29
  return_type_code = cue % 10;
  st_code = (cue / 10) - 1;
  pattern_digits_run = 0;
 }

// else if(cue >= 100)
// {
//  // error?
////  st_code = (cue/100) - 1;
////  cue %= 100;
////  return_type_code = cue/10;
////  cue %= 10;
////  pattern_digits_run = 1;
// }
// else if(cue >= 10)
// {
//  st_code = (cue/10) - 1;
//  return_type_code = cue % 10;
//  pattern_digits_run = 0;
// }
// else
// {
//  // errer?
// }


 u1 distinct_type_count = (st_code & 6) >> 1;
 bool s1 = st_code & 1;

 u1 arg_count = pattern_digits_run - distinct_type_count;

 u4 st_base = 1;
 for(int i = 0; i < distinct_type_count; ++i) st_base *= 10;

 switch (arg_count)
 {
 case 3: arguments_type_pattern = cue % 1000; distinct_type_pattern = cue / 1000; break;
 //case 23: arguments_type_pattern = cue % 1000; distinct_type_pattern = cue / 1000; break;
 case 2: arguments_type_pattern = cue % 100; distinct_type_pattern = cue / 100; break;
 case 1: arguments_type_pattern = cue % 10; distinct_type_pattern = cue / 10; break;
 case 0: arguments_type_pattern = distinct_type_pattern = 0; break;
 }



 u2 dd = ( (st_code + 1) * st_base) + distinct_type_pattern;

 qDebug() << "cue: " << cc << ", D: " << dd << ", A: " << arguments_type_pattern;

}

int main(int argc, char *argv[])
{
 QString case_text_4_file = QString(ROOT_FOLDER "/dev/consoles/fns/case-text-4.cpp");

 QString case_text_4;

 for(int i = 1; i <= 3; ++i)
 {
  for(int j = 1; j <= 3; ++j)
  {
   for(int k = 1; k <= 3; ++k)
   {
    for(int l = 1; l <= 3; ++l)
    {
     u4 same = 0;
     if(i == j) ++same;
     if(i == k) ++same;
     if(i == l) ++same;
     if(j == k) ++same;
     if(j == l) ++same;
     if(k == l) ++same;
     if(same > 1)
       continue;
     u2 caseval = (1000*i) + (100*j) + (10*k) + l;
     case_text_4 += QString("\ncase %1: ").arg(caseval);
    }
   }
  }
 }
 save_file(case_text_4_file, case_text_4);


 QString case_text_5_file = QString(ROOT_FOLDER "/dev/consoles/fns/case-text-5.cpp");
 QString case_text_5a_file = QString(ROOT_FOLDER "/dev/consoles/fns/case-text-5a.cpp");
 QString case_text_5b_file = QString(ROOT_FOLDER "/dev/consoles/fns/case-text-5b.cpp");

 QString case_text_5;
 QString case_text_5a;
 QString case_text_5b;

 for(int i = 1; i <= 3; ++i)
 {
  for(int j = 1; j <= 3; ++j)
  {
   for(int k = 1; k <= 3; ++k)
   {
    for(int l = 1; l <= 3; ++l)
    {
     for(int m = 1; m <= 3; ++m)
     {
      u4 same = 0;
      if(i == j) ++same;
      if(i == k) ++same;
      if(i == l) ++same;
      if(i == m) ++same;
      if(j == k) ++same;
      if(j == l) ++same;
      if(j == m) ++same;
      if(k == l) ++same;
      if(k == m) ++same;
      if(l == m) ++same;
      if(same > 3)
        continue;
      u2 caseval = (10000*i) + (1000*j) + (100*k) + (10*l) + m;
      case_text_5 += QString("\ncase %1: ").arg(caseval);

      if(same == 2)
        case_text_5a += QString("\ncase %1: ").arg(caseval);
      if(same == 3)
        case_text_5b += QString("\ncase %1: ").arg(caseval);
     }
    }
   }
  }
 }
 save_file(case_text_5_file, case_text_5);
 save_file(case_text_5a_file, case_text_5a);
 save_file(case_text_5b_file, case_text_5b);

}

int main4(int argc, char *argv[])
{
 QString case_text_file = QString(ROOT_FOLDER "/dev/consoles/fns/case-text.cpp");

 QString case_text;

 for(int i = 1; i <= 3; ++i)
 {
  for(int j = 1; j <= 3; ++j)
  {
   if(j == i)
     continue;
   for(int k = 1; k <= 3; ++k)
   {
    if(k == i)
      continue;
    if(k == j)
      continue;

    u2 caseval = (100*i) + (10*j) + k;
    case_text += QString("\ncase %1: ").arg(caseval);
   }
  }
 }

 case_text += "\n";

 for(u1 i = 1; i < 63; ++i)
 {
  case_text += QString("\ncase 0b%1: ").arg(i, 6, 2, QLatin1Char('0'));
 }

 case_text += "\n";

// for(int i = 1; i <= 3; ++i)
// {
//  for(int j = 1; j <= 3; ++j)
//  {

//  }
// }

 save_file(case_text_file, case_text);

}



int main2(int argc, char *argv[])
{
#define INCLUDE_MAP_CODE
 QMap<u2, u2> type_patterns_3_map {
  #include "./dev/consoles/fns/type-patterns-3.cpp"
 };

 QMap<u2, u2> type_patterns_2_map {
  #include "./dev/consoles/fns/type-patterns-2.cpp"
 };

 QMap<u2, u2> type_patterns_1_map {
  #include "./dev/consoles/fns/type-patterns-1.cpp"
 };

 return 0;
}


int main1(int argc, char *argv[])
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

// u1 ac = 3;


// parse_fn_code(84049123);
// parse_fn_code(74049123);

// parse_fn_code(6409121);
// parse_fn_code(5409121);

// parse_fn_code(440111);
// parse_fn_code(340111);

// parse_fn_code(44011);
// parse_fn_code(34011);

// parse_fn_code(4401);
// parse_fn_code(3401);


// parse_fn_code(29);
// parse_fn_code(19);

 QString type_pattern_3_file = QString(ROOT_FOLDER "/dev/consoles/fns/type-patterns-3.cpp");
 QString type_pattern_3_text = "#ifdef INCLUDE_ARRAY_CODE\n{";

 QString type_pattern_2_file = QString(ROOT_FOLDER "/dev/consoles/fns/type-patterns-2.cpp");
 QString type_pattern_2_text = "#ifdef INCLUDE_ARRAY_CODE\n{";

 int col3 = 0;
 int col2 = 0;

 int row3 = 0;

 QMap<u2, u2> type_pattern_3_map;
 QMap<u2, u2> type_pattern_2_map;

 int count2 = 0;
 int count3 = 0;

 for(int i = 0; i <= 8; ++i)
 {
  for(int j = i + 1; j <= 9; ++j)
  {
   u2 val2 = 200 + (i*10) + j;
   type_pattern_2_map[val2] = count2;
   ++count2;

   ++col2;
   if(col2 == 10)
     col2 = 1;

   if(col2 == 1)
     type_pattern_2_text += "\n";
   else if(col2 == 4 || col2 == 7)
     type_pattern_2_text += "  ";


   type_pattern_2_text += QString(" %1,").arg(val2);

   if(j == 9)
     continue;
   if(i == 8)
     continue;

   for(int k = j + 1; k <= 9; ++k)
   {
    u2 val3 = 3000 + (i*100) + (j*10) + k;
    type_pattern_3_map[val3] = count3;
    ++count3;

    ++col3;
    if(col3 == 13)
    {
     col3 = 1;
     ++row3;
     if(row3 == 5)
       type_pattern_3_text += "\n";
    }


    if(col3 == 1)
      type_pattern_3_text += "\n";
    else if(col3 == 4 || col3 == 7 || col3 == 10)
      type_pattern_3_text += "  ";

    type_pattern_3_text += QString(" %1,").arg(val3);
   }
  }
 }

 type_pattern_3_text.chop(1);
 type_pattern_3_text += "\n}\n#endif //def INCLUDE_ARRAY_CODE\n";

 type_pattern_2_text.chop(1);
 type_pattern_2_text += "\n}\n#endif // def INCLUDE_ARRAY_CODE\n";

// QTextStream qts3(&type_pattern_3_text);

 type_pattern_3_text += "\n\n#ifdef INCLUDE_MAP_CODE\n{\n";
 QMapIterator<u2, u2> it3(type_pattern_3_map);
 while(it3.hasNext())
 {
  it3.next();
  type_pattern_3_text += QString(" {%1,%2},").arg(it3.key()).arg(it3.value());
  if( (it3.value() % 6) == 5 )
    type_pattern_3_text += "\n";
 }
 type_pattern_3_text.chop(2);
 type_pattern_3_text += "\n}\n#endif // INCLUDE_MAP_CODE\n";


// QTextStream qts2(&type_pattern_2_text);

 type_pattern_2_text += "\n\n#ifdef INCLUDE_MAP_CODE\n{\n";
 QMapIterator<u2, u2> it2(type_pattern_2_map);
 while(it2.hasNext())
 {
  it2.next();
  type_pattern_2_text += QString(" {%1,%2},").arg(it2.key()).arg(it2.value());
  if( (it2.value() % 5) == 4 )
    type_pattern_2_text += "\n";
 }
 type_pattern_2_text.chop(2);
 type_pattern_2_text += "\n}\n#endif // INCLUDE_MAP_CODE\n";


 save_file(type_pattern_3_file, type_pattern_3_text);
 save_file(type_pattern_2_file, type_pattern_2_text);
}





#ifdef HIDE

QString generate_function_code(u1 retc, u2 key, QString sc0, QString sc1, u1 ac)
{
 QString ret = returns[retc];
 QString retv;
 if(retc > 0) retv = ret + "& retv, ";

 QString more_args;

 if(ac > 0)
 {
  for(u1 aa = 1; aa <= ac; ++aa)
  {
   more_args += QString("n8 arg%1, ").arg(aa);
  }
 }
//   more_args += "n8 arg1, ";
// if(ac > 1)
//   more_args += "n8 arg2, ";
// if(ac > 2)
//   more_args += "n8 arg3, ";



 QString result = (ac > 0)? QString(
   "void _f_%1%2_(%3%4minimal_fn_%5_re%1_type fn, "
   "minimal_fn_%6_re%1_type sfn, void* _this)\n{\n ")
     .arg(retc).arg(key, ac, 10, QLatin1Char('0'))
     .arg(retv).arg(more_args).arg(sc0).arg(sc1)
   :
   QString("void _f_%1_(%2%3minimal_fn_%4_re%1_type fn, "
     "minimal_fn_%5_re%1_type sfn, void* _this)\n{\n ")
     .arg(retc).arg(retv).arg(more_args).arg(sc0).arg(sc1);

 u1 akey = 0;

 // types[0] is return ...  less than 3 others might be used (if ac < 3)
 static QString types [4] = {ret,{},{},{}};

 if(ac > 0)
 {
  static u2 exps[3] {1, 10, 100};
  u2 f = exps[ac - 1];
  for(u1 i = 1, factor = f; i <= ac; ++i, factor /= 10)
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
  result += "\n ";
 }

 QString sfn_line;
 QString if_this;
 if(retc > 0) if_this = "retv=";

 QString if_this_else = if_this;
 if_this.prepend(" if(_this) ");
 if_this_else.prepend("\n else ");


 switch(ac)
 {
 case 0:
  sfn_line += QString("auto _sfn = (%1(_min_::*)())(sfn);\n").arg(ret);
  if_this += "((_min_*)_this->*_sfn)();\n";//.arg(ret);
  if_this_else += QString("((%1(*)()) fn)();\n}\n").arg(ret);
  break;

 case 1:  //(%2))
  sfn_line += QString("auto _sfn = (%1(_min_::*)(%2))(sfn);\n").arg(ret).arg(types[1]);
  if_this += " ((_min_*)_this->*_sfn)(a1);"; // //(%2))\n"; //.arg(ret).arg(types[1]);
  if_this_else += QString("((%1(*)(%2)) fn)(a1);\n}\n").arg(ret).arg(types[1]);
  break;

 case 2: //(%2,%3))
  sfn_line += QString("auto _sfn = (%1(_min_::*)(%2,%3))(sfn);\n").arg(ret)
    .arg(types[1]).arg(types[2]);
  if_this += " ((_min_*)_this->*_sfn)(a1,a2);"; // //(2,3))\n")
    //.arg(types[1]).arg(types[2]);
  if_this_else += QString("((%1(*)(%2,%3)) fn)(a1,a2);\n}\n")
    .arg(ret).arg(types[1]).arg(types[2]);
  break;

 case 3: //(%2,%3,%4))
  sfn_line += QString("auto _sfn = (%1(_min_::*)(%2,%3,%4))(sfn);\n")
    .arg(ret).arg(types[1]).arg(types[2]).arg(types[3]);
  if_this += " ((_min_*)_this->*_sfn)(a1,a2,a3);"; //(%2,%3,%4))\n"
    //.arg(ret).arg(types[1]).arg(types[2]).arg(types[3]);
  if_this_else += QString("((%1(*)(%2,%3,%4))fn)(a1,a2,a3);\n}\n")
    .arg(ret).arg(types[1]).arg(types[2]).arg(types[3]);
  break;
 }

 result += sfn_line + if_this + if_this_else;

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

// u1 ac = 3;

 for(u1 ac = 0; ac <= 3; ++ac)
 {
  static u2 exps[4] {1, 10, 100, 1000};

  u2 arsize = exps[ac];

  for(u1 i = 0; i < 10; ++i)
  {
   QString ret = returns[i];
   QString retv, rsym;

   // //  concisely initialize two strings.  A bit cute.
   if(i > 0)
     retv = QString("%1& %2").arg(ret).arg(rsym = "retv, ");


   QString s01_X_reX_ch_eval_file = QString(ROOT_FOLDER "/dev/consoles/fns/s01/a%1/ch-eval-s01_%1_re%2.cpp").arg(ac).arg(i);
   QString s01_X_reX_ch_eval_text = (ac == 0)? "" : R"(

Chasm_Channel* lambda = ccp->channel("lambda");
if(!lambda)
  return;
)";

   if(i > 0)
     s01_X_reX_ch_eval_text += R"(
Chasm_Channel* retvalue = ccp->channel("retvalue");
if(!retvalue)
  return;
)";


   s01_X_reX_ch_eval_text += R"(
Chasm_Channel* sigma = ccp->channel("sigma");
void* _this;
if(sigma)
  _this = sigma->first_carrier().value<void*>();
else
  _this = nullptr;
)";

   QString pasn8s;
   if(ac > 0)
   {
    for(int aa = 1; aa <= ac; ++aa)
      pasn8s += QString(", lambda->pasn8(%1)").arg(aa);
   }

   if(i == 0)
   {
    s01_X_reX_ch_eval_text += QString(R"(
run_s01_%1_re0(fncode, (minimal_fn_s0_re0_type) fn,
  (minimal_fn_s1_re0_type) sfn%2, _this);
)").arg(ac).arg(pasn8s);
   }
   else
   {
    s01_X_reX_ch_eval_text += QString(R"(
Chasm_Carrier cc = retvalue->first_carrier();

%1%2 rr = %3cc.value%4<%1>();
run_s01_%5_re%6(fncode, (minimal_fn_s0_re%6_type) fn,
  (minimal_fn_s1_re%6_type) sfn, rr%7, _this);

if(rcar)
  rcar->set_value%8(rr);
)").arg(ret).arg( (i == 3 || i == 5 || i == 7)?"&":"")
   .arg("")  //.arg((i == 3 || i == 5 || i == 7)?"*("+ret+"*)":"")
   .arg((i == 3 || i == 5 || i == 7)?"_as":"")
   .arg(ac)
   .arg(i).arg(pasn8s)
   .arg((i == 3 || i == 5 || i == 7)?"_as<"+ret+">":
     //(i==9)?"":(i==0)?"*":
     ""

    )
    ;
   }
   save_file(s01_X_reX_ch_eval_file, s01_X_reX_ch_eval_text);

   QString s01_X_reX_file = QString(ROOT_FOLDER "/dev/consoles/fns/s01/a%1/run-s01_%1_re%2.cpp").arg(ac).arg(i);
   QString fn_array_reX_file = QString(ROOT_FOLDER "/dev/consoles/fns/s01/a%1/fn-array-s01_%1_re%2.cpp").arg(ac).arg(i);

   QString fn_array_reX_text;

   QString n8argtext;
   if(ac > 0)
   {
    for(u1 aa = 1; aa <= ac; ++aa)
    {
     n8argtext += QString("n8 arg%1, ").arg(aa);
    }
   }

   QString s01_X_reX_text = QString(R"(


#ifndef SEEN_DEFS_S01_%4_RE%2
#define SEEN_DEFS_S01_%4_RE%2

typedef %1(*minimal_fn_s0_re%2_type)();
typedef %1(_min_::*minimal_fn_s1_re%2_type)();
typedef void(*run_s01_%4_re%2_type)(%3%6minimal_fn_s0_re%2_type fn,
  minimal_fn_s1_re%2_type sfn, void* _this);
typedef run_s01_%4_re%2_type s01_%4_re%2_dispatch_array [%5];

#endif //  SEEN_DEFS_S01_%4_RE%2

#ifdef FULL_INCLUDE

#include "fn-array-s01_%4_re%2.cpp"

s01_%4_re%2_dispatch_array* init_s01_%4_re%2_dispatch_array()
{
 s01_%4_re%2_dispatch_array* result = (s01_%4_re%2_dispatch_array*) new run_s01_%4_re%2_type[%5];
 )").arg(ret).arg(i).arg(retv).arg(ac).arg(arsize).arg(n8argtext);

   for(u2 j = 0; j < arsize; ++j)
   {
    if(ac > 0)
      s01_X_reX_text += QString("\n (*result)[%1] = &_f_%2%3_;").arg(j).arg(i).arg(j, ac, 10, QLatin1Char('0'));
    else
      s01_X_reX_text += QString("\n (*result)[%1] = &_f_%2_;").arg(j).arg(i);
   }

   QString atext;
   QString natext;
   if(ac > 0)
   {
    for(u1 aa = 1; aa <= ac; ++aa)
    {
     natext += QString("n8 a%1%2").arg(aa).arg(aa < ac? ", " : "");
     atext += QString("a%1,").arg(aa);
    }
   }

   if( (ac > 0) )
     s01_X_reX_text += QString(R"(
 return result;
}

void run_s01_%1_re%2(u4 code, minimal_fn_s0_re%2_type fn,
   minimal_fn_s1_re%2_type sfn, %3%4, void* _this))")
   .arg(ac).arg(i).arg(retv).arg(natext);

   else if( (i > 0) )
     s01_X_reX_text += QString(R"(
 return result;
}

void run_s01_%1_re%2(u4 code, minimal_fn_s0_re%2_type fn,
   minimal_fn_s1_re%2_type sfn, %3, void* _this))")
   .arg(ac).arg(i).arg(retv.left(retv.size() - 2));

   else
    s01_X_reX_text += QString(R"(
 return result;
}

void run_s01_%1_re%2(u4 code, minimal_fn_s0_re%2_type fn,
  minimal_fn_s1_re%2_type sfn, void* _this))")
  .arg(ac).arg(i); // // here ac = 0 and i = 0 always but keep the substitutions for clarity ...

   s01_X_reX_text += QString(R"(
{
 code %= %1;
 static s01_%2_re%3_dispatch_array* dispatch_array = init_s01_%2_re%3_dispatch_array();
 run_s01_%2_re%3_type f = (*dispatch_array)[code];
 f(%4%5fn, sfn, _this);
}

#endif //def FULL_INCLUDE
)").arg(arsize).arg(ac).arg(i).arg(rsym).arg(atext); // .arg(ac).arg(arsize * 10).arg(atext);

   save_file(s01_X_reX_file, s01_X_reX_text);

   for(int j = 0; j < arsize; ++j)
     fn_array_reX_text += generate_function_code(i, j, "s0", "s1", ac);
   save_file(fn_array_reX_file, fn_array_reX_text);
  }

 }
 return 0;
}

#endif //def HIDE
