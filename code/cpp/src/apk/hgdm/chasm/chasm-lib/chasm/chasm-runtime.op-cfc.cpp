
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


u1 _early_parse(Chasm_Function_Code& cfc, n8& cue)
{
 if(cue >= 10000000000) // 10 digits
 {
  cfc.arg_count = cue / 10000000000;
  cue %= 10000000000;
  cfc.convention = cue / 1000000000;
  cue %= 1000000000;
  cfc.return_code = cue / 100000000;
  cue %= 100000000; // 8 digits left
  return 8;
 }
 else if(cue >= 1000000000) // 10 digits
 {
  cfc.arg_count = cue / 1000000000;
  cue %= 1000000000;
  cfc.convention = cue / 100000000;
  cue %= 100000000;
  cfc.return_code = cue / 10000000;
  cue %= 10000000; // 7 digits left
  return 7;
 }
 else if(cue >= 100000000) // 9 digits
 {
  cfc.arg_count = cue / 100000000;
  cue %= 100000000;
  cfc.convention = cue / 10000000;
  cue %= 10000000;
  cfc.return_code = cue / 1000000;
  cue %= 1000000; // 6 digits left
  return 6;
 }
 else if(cue >= 10000000) // 8 digits
 {
  cfc.arg_count = cue / 10000000;
  cue %= 10000000;
  cfc.convention = cue / 1000000;
  cue %= 1000000;
  cfc.return_code = cue / 100000;
  cue %= 100000; // 5 digits left
  return 5;
 }
 else if(cue >= 1000000) // 7 digits
 {
  cfc.arg_count = cue / 1000000;
  cue %= 1000000;
  cfc.convention = cue / 100000;
  cue %= 100000;
  cfc.return_code = cue / 10000;
  cue %= 10000; // 4 digits left
  return 4;
 }
 else if(cue >= 10000) // 6 digits
 {
  cfc.arg_count = cue / 100000;
  cue %= 100000;
  cfc.convention = cue / 10000;
  cue %= 10000;
  cfc.return_code = cue / 1000;
  cue %= 1000; // 3 digits left
  return 3;
 }
 else if(cue >= 10000) // 5 digits
 {
  cfc.arg_count = cue / 10000;
  cue %= 10000;
  cfc.convention = cue / 1000;
  cue %= 1000;
  cfc.return_code = cue / 100;
  cue %= 100; // 2 digits left
  return 2;
 }
 else if(cue >= 1000) // 4 digits
 {
  cfc.arg_count = cue / 1000;
  cue %= 1000;
  cfc.convention = cue / 100;
  cue %= 100;
  cfc.return_code = cue / 10;
  cue %= 10; // 1 digits left
  return 1;
 }
 else if(cue >= 100) // 3 digits
 {
  cfc.arg_count = cue / 100;
  cue %= 100;
  cfc.convention = cue / 10;
  cue %= 10;
  cfc.return_code = cue;  // 0 digits left
  return 0;
 }
 else if(cue >= 10) // 2 digits
 {
  cfc.arg_count = 0;
  cfc.convention = cue / 10;
  cfc.return_code = cue % 10;
  return 0;
 }
 else // 1 digit
 {
  cfc.arg_count = 0;
  cfc.convention = 0;
  cfc.return_code = cue;
  return 0;
 }

}

u1 _do_binary(u1 arg_count, u4 type_pattern)
{
 u1 result = 0;
 u1 mask = ~((1 << arg_count) - 1);
 bool last_true = false;
 for(u1 i = 0, b = 1; i < arg_count; ++i, b <<= 1)
 {
  u1 d = type_pattern % 10;
  last_true = (d == 2);
  if(last_true)
    result |= b;
  type_pattern /= 10;
 }
 if(!last_true)
 {
  result |= mask;
 }
 return result;
}

Chasm_Function_Code _parse_cfc(n8 cue, bool udn_literal = true)
{
 Chasm_Function_Code result;

 //result.type_pattern_binary = udn_literal? 100:200;

 result.type_pattern_binary = 0;

 u1 distinct_type_pattern_len, arg_count;
 u4 distinct_type_pattern_len_exp = 1;
 u4 arg_count_exp = 1;

 auto do_exp = [&distinct_type_pattern_len, &arg_count,
   &distinct_type_pattern_len_exp, &arg_count_exp]()
 {
  for(int i = 0; i < distinct_type_pattern_len; ++i)
    distinct_type_pattern_len_exp *= 10;
  distinct_type_pattern_len_exp *= arg_count;
  for(int i = 0; i < arg_count; ++i)
    arg_count_exp *= 10;
 };



 u1 len = _early_parse(result, cue);
 arg_count = result.arg_count;

 if(len == 1)
 {
  result.distinct_type_pattern = cue % 10;
  result.type_pattern = 1;
  result.type_pattern_binary = arg_count;
  return result;
 }

 if(len > result.arg_count)
 {
  // type pattern already encoded
  distinct_type_pattern_len = len - result.arg_count;
    // result.type_pattern_binary += (distinct_type_pattern_len * 10) + result.arg_count;
  do_exp();

  if(distinct_type_pattern_len > 2)
  {
   result.type_pattern = cue % arg_count_exp;
   cue /= arg_count_exp;
   result.distinct_type_pattern = distinct_type_pattern_len_exp + cue;
   return result;
  }
  else if(distinct_type_pattern_len == 2)
  {
   u4 type_pattern = cue % arg_count_exp;
   cue /= arg_count_exp;
   result.distinct_type_pattern = distinct_type_pattern_len_exp + cue;
   if(arg_count < 6)
     result.type_pattern = type_pattern;
   else
     result.type_pattern = -1;

   result.type_pattern_binary = _do_binary(arg_count, type_pattern);
   return result;
  }
  else if(distinct_type_pattern_len == 1)
  {

  }
 }

 result.type_pattern = result.distinct_type_pattern = 0;

 // // need to encode the type pattern
 u1 type_counts[arg_count];
 u1 distinct_type_numbers[arg_count];// {255,255,255};
 u1 type_numbers[arg_count];// {255,255,255};
// for(int i = 0; i < arg_count; ++i)
// {
//  type_counts[i] = 0;
//  type_numbers[i] = 255;
// }

 u1 seen_type_count = 0;
 u1 digit_exp = 1;

 u4 types = cue; // % arg_count_exp;


 for(int i = 0; i < arg_count; ++i) //, digit_exp *= 10)
 {
  u1 d = types % 10;
  type_numbers[arg_count - i - 1] = d;

  u1 j = 0;

  if(seen_type_count == 0)
  {
   seen_type_count = 1;
   distinct_type_numbers[0] = d;
   type_counts[0] = 1;
//   types /= 10;
//   continue;
   goto outer_continue;
  }

  for(; j < seen_type_count; ++j)
  {
   if(distinct_type_numbers[j] == d)
   {
    ++type_counts[j];
    goto outer_continue;
   }
  }

  ++seen_type_count;
  distinct_type_numbers[j] = d;
  type_counts[j] = 1;

 outer_continue:
  types /= 10;
 }

 // problem if any type counts are > 3 ...


 std::sort(distinct_type_numbers, distinct_type_numbers + seen_type_count);

 u4 e = 1;
 for(s1 i = seen_type_count - 1; i >= 0; --i, e *= 10) //, digit_exp *= 10)
 {
  u1 d = distinct_type_numbers[i];
  result.distinct_type_pattern += d * e;
 }
 result.distinct_type_pattern += arg_count * e;

 u4 type_pattern = 0;
 e = 1;
 for(s1 i = arg_count - 1; i >= 0; --i, e *= 10) //, digit_exp *= 10)
 {
  u1 d = type_numbers[i];
  for(u1 j = 0; j < seen_type_count; ++j)
  {
   if(d == distinct_type_numbers[j])
   {
    type_pattern += ((j + 1) * e);
    break;
   }
  }
 }

 if(arg_count < 6)
   result.type_pattern = type_pattern;

 if(seen_type_count == 2)
   result.type_pattern_binary = _do_binary(arg_count, type_pattern);

 return result;
}



Chasm_Function_Code operator""_cfc(n8 cue)
{
 return _parse_cfc(cue);
}
