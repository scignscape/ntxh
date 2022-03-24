
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_SDI_STRUCTURES__H
#define XCSD_SDI_STRUCTURES__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"

#include <QImage>

#include "accessors.h"

#include "xcns.h"

XCNS_(XCSD)

// template<typename VAL_Type, typename = index_types<s2>,
//typename = _pr_break> class

inline constexpr u1 _ctz(int x)
{
 return x == 0? 0: (u1) __builtin_ctz(x);
}

#define Ty_DEF_MACRO(ty, size, asize, field1, field2) \
 struct ty##size { u##size field1, field2; \
   using field_type = u##size; \
   template<typename T> friend T& operator<<(T& lhs, const ty##size& rhs) \
   { lhs << "(" << rhs.field1 << ", " << rhs.field2 << ")"; return lhs; } \
   template<typename T> ty##size operator<<(T val) \
   { return {field1 << val, field2 << val}; } \
   template<typename T> ty##size operator>>(T val) \
   { return {field1 >> val, field2 >> val}; } \
   template<typename T> ty##size operator&(T val) \
   { return {field1 & val, field2 & val}; } \
   template<typename T> ty##size operator*(T val) \
   { return {field1 * val, field2 * val}; } \
   template<typename T> ty##size operator+(T val) \
   { return {field1 + val, field2 + val}; } \
   ty##size operator+(ty##size rhs) \
   { return {(u##size)(field1 + rhs.field1), (u##size)(field2 + rhs.field2)}; } \
   ty##size operator-(ty##size rhs) \
   { return {(u##size)(field1 - rhs.field1), (u##size)(field2 - rhs.field2)}; } \
   ty##size operator*(ty##size rhs) \
   { return {(u##size)(field1 * rhs.field1), (u##size)(field2 * rhs.field2)}; } \
   ty##size operator/(ty##size rhs) \
   { return {(u##size)(field1 / rhs.field1), (u##size)(field2 / rhs.field2)}; } \
   ty##size operator%(ty##size rhs) \
   { return {(u##size)(field1 % rhs.field1), (u##size)(field2 % rhs.field2)}; } \
   template<typename T> ty##size operator||(T val) \
   { return {field1 < val? field1 : val, field2 < val? field2 : val}; } \
   template<typename T> ty##size operator&&(T val) \
   { return {(field1 & val) >> _ctz(val), (field2 & val) >> _ctz(val)}; } \
   template<typename T> T _to() \
   { return {(typename T::field_type)field1, (typename T::field_type)field2}; } \
   asize area() {return field1 * field2;} };

#define Tys_DEF_MACRO(ty, size, asize, field1, field2) \
struct ty##size##s { s##size field1, field2; \
   using field_type = s##size; \
   template<typename T> friend T& operator<<(T& lhs, const ty##size##s& rhs) \
   { lhs << "(" << rhs.field1 << ", " << rhs.field2 << ")"; return lhs; } \
   bool is_nonnegative() { return field1 >= 0 && field2 >= 0; } \
   template<typename T> ty##size##s operator<<(T val) \
   { return {field1 << val, field2 << val}; } \
   template<typename T> ty##size##s operator>>(T val) \
   { return {field1 >> val, field2 >> val}; } \
   template<typename T> ty##size##s operator&(T val) \
   { return {field1 & val, field2 & val}; } \
   template<typename T> ty##size##s operator*(T val) \
   { return {field1 * val, field2 * val}; } \
   template<typename T> ty##size##s operator+(T val) \
   { return {field1 + val, field2 + val}; } \
   ty##size##s operator+(ty##size##s rhs) \
   { return {(s##size)(field1 + rhs.field1), (s##size)(field2 + rhs.field2)}; } \
   ty##size##s operator-(ty##size##s rhs) \
   { return {(s##size)(field1 - rhs.field1), (s##size)(field2 - rhs.field2)}; } \
   ty##size##s operator*(ty##size##s rhs) \
   { return {(s##size)(field1 * rhs.field1), (s##size)(field2 * rhs.field2)}; } \
   ty##size##s operator/(ty##size##s rhs) \
   { return {(s##size)(field1 / rhs.field1), (s##size)(field2 / rhs.field2)}; } \
   ty##size##s operator%(ty##size##s rhs) \
   { return {(s##size)(field1 % rhs.field1), (s##size)(field2 % rhs.field2)}; } \
   template<typename T> ty##size##s operator||(T val) \
   { return {field1 < val? field1 : val, field2 < val? field2 : val}; } \
   template<typename T> T _to() \
   { return {(typename T::field_type)field1, (typename T::field_type)field2}; } \
   asize area() {return field1 * field2;} };

Ty_DEF_MACRO(wh, 1, u2, width, height)
Ty_DEF_MACRO(wh, 2, u4, width, height)
Ty_DEF_MACRO(wh, 4, n8, width, height)
Ty_DEF_MACRO(args, 1, u2, arg1, arg2)
Ty_DEF_MACRO(args, 2, u4, arg1, arg2)
Ty_DEF_MACRO(args, 4, n8, arg1, arg2)
Ty_DEF_MACRO(xy, 1, u2, x, y)
Ty_DEF_MACRO(xy, 2, u4, x, y)
Ty_DEF_MACRO(xy, 4, n8, x, y)
Ty_DEF_MACRO(rc, 1, u2, r, c)
Ty_DEF_MACRO(rc, 2, u4, r, c)
Ty_DEF_MACRO(rc, 4, n8, r, c)
Ty_DEF_MACRO(hv, 1, u2, h, v)
Ty_DEF_MACRO(hv, 2, u4, h, v)
Ty_DEF_MACRO(hv, 4, n8, h, v)
Ty_DEF_MACRO(lr, 1, u2, left, right)
Ty_DEF_MACRO(lr, 2, u4, left, right)
Ty_DEF_MACRO(lr, 4, n8, left, right)
Ty_DEF_MACRO(pr, 1, u2,first, second)
Ty_DEF_MACRO(pr, 2, u4,first, second)
Ty_DEF_MACRO(pr, 4, n8, first, second)
Ty_DEF_MACRO(tb, 1, u2, top, bottom)
Ty_DEF_MACRO(tb, 2, u4, top, bottom)
Ty_DEF_MACRO(tb, 4, n8, first, second)

Tys_DEF_MACRO(wh, 1, u2, width, height)
Tys_DEF_MACRO(wh, 2, u4, width, height)
Tys_DEF_MACRO(wh, 4, n8, width, height)
Tys_DEF_MACRO(args, 1, u2, arg1, arg2)
Tys_DEF_MACRO(args, 2, u4, arg1, arg2)
Tys_DEF_MACRO(args, 4, n8, arg1, arg2)
Tys_DEF_MACRO(xy, 1, u2, x, y)
Tys_DEF_MACRO(xy, 2, u4, x, y)
Tys_DEF_MACRO(xy, 4, n8, x, y)
Tys_DEF_MACRO(rc, 1, u2, r, c)
Tys_DEF_MACRO(rc, 2, u4, r, c)
Tys_DEF_MACRO(rc, 4, n8, r, c)
Tys_DEF_MACRO(hv, 1, u2, h, v)
Tys_DEF_MACRO(hv, 2, u4, h, v)
Tys_DEF_MACRO(hv, 4, n8, h, v)
Tys_DEF_MACRO(lr, 1, u2, left, right)
Tys_DEF_MACRO(lr, 2, u4, left, right)
Tys_DEF_MACRO(lr, 4, n8, left, right)
Tys_DEF_MACRO(pr, 1, u2, first, second)
Tys_DEF_MACRO(pr, 2, u4, first, second)
Tys_DEF_MACRO(pr, 4, n8, first, second)
Tys_DEF_MACRO(tb, 1, u2, top, bottom)
Tys_DEF_MACRO(tb, 2, u4, top, bottom)
Tys_DEF_MACRO(tb, 4, n8, first, second)



#define Ty3_DEF_MACRO(ty, ty2, size, asize, field1, field2, field3) \
 struct ty##size { u##size field1, field2, field3; \
   using field_type = u##size; \
   template<typename T> friend T& operator<<(T& lhs, const ty##size& rhs) \
   { lhs << "(" << rhs.field1 << ", " << rhs.field2 << ", " << rhs.field3 << ")"; return lhs; } \
   ty2##size fold_in() { return {field1, field3}; } \
   template<typename T> ty##size operator<<(T val) \
   { return {field1 << val, field2 << val, field3 << val}; } \
   template<typename T> ty##size operator>>(T val) \
   { return {field1 >> val, field2 >> val, field3 >> val}; } \
   template<typename T> ty##size operator&(T val) \
   { return {field1 & val, field2 & val, field3 & val}; } \
   template<typename T> ty##size operator*(T val) \
   { return {field1 * val, field2 * val, field3 * val}; } \
   template<typename T> ty##size operator+(T val) \
   { return {field1 + val, field2 + val, field3 + val}; } \
   ty##size operator+(ty##size rhs) \
   { return {(u##size)(field1 + rhs.field1), (u##size)(field2 + rhs.field2), (u##size)(field3 + rhs.field3)}; } \
   ty##size operator-(ty##size rhs) \
   { return {(u##size)(field1 - rhs.field1), (u##size)(field2 - rhs.field2), (u##size)(field3 - rhs.field3)}; } \
   ty##size operator*(ty##size rhs) \
   { return {(u##size)(field1 * rhs.field1), (u##size)(field2 * rhs.field2), (u##size)(field3 * rhs.field3)}; } \
   ty##size operator/(ty##size rhs) \
   { return {(u##size)(field1 / rhs.field1), (u##size)(field2 / rhs.field2), (u##size)(field3 / rhs.field3)}; } \
   ty##size operator%(ty##size rhs) \
   { return {(u##size)(field1 % rhs.field1), (u##size)(field2 % rhs.field2), (u##size)(field3 % rhs.field3)}; } \
   template<typename T> ty##size operator||(T val) \
   { return {field1 < val? field1 : val, field2 < val? field2 : val, field3 < val? field3 : val}; } \
   template<typename T> ty##size operator&&(T val) \
   { return {(field1 & val) >> _ctz(val), (field2 & val) >> _ctz(val), (field3 & val) >> _ctz(val)}; } \
   template<typename T> T _to() \
   { return {(typename T::field_type)field1, (typename T::field_type)field2, (typename T::field_type)field3}; } \
   asize product() {return field1 * field2 * field3;} };

#define Ty3s_DEF_MACRO(ty, ty2, size, asize, field1, field2, field3) \
struct ty##size##s { s##size field1, field2, field3; \
   using field_type = s##size; \
   template<typename T> friend T& operator<<(T& lhs, const ty##size##s& rhs) \
   { lhs << "(" << rhs.field1 << ", " << rhs.field2 << ", " << rhs.field3 << ")"; return lhs; } \
   ty2##size##s fold_in() { return {field1, field3}; } \
   bool is_nonnegative() { return field1 >= 0 && field2 >= 0 && field3 >= 0; } \
   template<typename T> ty##size##s operator<<(T val) \
   { return {field1 << val, field2 << val, field3 << val}; } \
   template<typename T> ty##size##s operator>>(T val) \
   { return {field1 >> val, field2 >> val, field3 >> val}; } \
   template<typename T> ty##size##s operator&(T val) \
   { return {field1 & val, field2 & val, field3 & val}; } \
   template<typename T> ty##size##s operator*(T val) \
   { return {field1 * val, field2 * val, field3 * val}; } \
   template<typename T> ty##size##s operator+(T val) \
   { return {field1 + val, field2 + val, field3 + val}; } \
   ty##size##s operator+(ty##size##s rhs) \
   { return {(s##size)(field1 + rhs.field1), (s##size)(field2 + rhs.field2), (s##size)(field3 + rhs.field3)}; } \
   ty##size##s operator-(ty##size##s rhs) \
   { return {(s##size)(field1 - rhs.field1), (s##size)(field2 - rhs.field2), (s##size)(field3 - rhs.field3)}; } \
   ty##size##s operator*(ty##size##s rhs) \
   { return {(s##size)(field1 * rhs.field1), (s##size)(field2 * rhs.field2), (s##size)(field3 * rhs.field3)}; } \
   ty##size##s operator/(ty##size##s rhs) \
   { return {(s##size)(field1 / rhs.field1), (s##size)(field2 / rhs.field2), (s##size)(field3 / rhs.field3)}; } \
   ty##size##s operator%(ty##size##s rhs) \
   { return {(s##size)(field1 % rhs.field1), (s##size)(field2 % rhs.field2), (s##size)(field3 % rhs.field3)}; } \
   template<typename T> ty##size##s operator||(T val) \
   { return {field1 < val? field1 : val, field2 < val? field2 : val, field3 < val? field3 : val}; } \
   template<typename T> T _to() \
   { return {(typename T::field_type)field1, (typename T::field_type)field2}; } \
   asize product() {return std::abs(field1 * field2 * field3);} };

Ty3_DEF_MACRO(lmr, lr, 1, u2, left, main, right)
Ty3_DEF_MACRO(lmr, lr, 2, u4, left, main, right)
Ty3_DEF_MACRO(lmr, lr, 4, n8, left, main, right)

Ty3_DEF_MACRO(tmb, tb, 1, u2, top, main, bottom)
Ty3_DEF_MACRO(tmb, tb, 2, u4, top, main, bottom)
Ty3_DEF_MACRO(tmb, tb, 4, n8, top, main, bottom)

Ty3s_DEF_MACRO(lmr, lr, 1, u2, left, main, right)
Ty3s_DEF_MACRO(lmr, lr, 2, u4, left, main, right)
Ty3s_DEF_MACRO(lmr, lr, 4, n8, left, main, right)

Ty3s_DEF_MACRO(tmb, tb, 1, u2, top, main, bottom)
Ty3s_DEF_MACRO(tmb, tb, 2, u4, top, main, bottom)
Ty3s_DEF_MACRO(tmb, tb, 4, n8, top, main, bottom)

inline u2 _ring_count(rc2 pos, wh2 size)
{
 return
   (pos.r < (size.width >> 1))? (size.width >> 1) - pos.r :
      pos.r - (size.width >> 1) - (1 - (size.width % 1))
   +
   (pos.c < (size.height >> 1))? (size.height >> 1) - pos.c :
      pos.c - (size.height >> 1) - (1 - (size.height % 1));
}

template<typename T>
struct Mod
{
 using Unsigned = T;
};

#define Mod_DEF_MACRO(ty) \
template<> struct Mod<ty> { using Unsigned = ty##s; };

Mod_DEF_MACRO(wh1)
Mod_DEF_MACRO(wh2)
Mod_DEF_MACRO(wh4)
Mod_DEF_MACRO(args1)
Mod_DEF_MACRO(args2)
Mod_DEF_MACRO(args4)
Mod_DEF_MACRO(xy1)
Mod_DEF_MACRO(xy2)
Mod_DEF_MACRO(xy4)
Mod_DEF_MACRO(rc1)
Mod_DEF_MACRO(rc2)
Mod_DEF_MACRO(rc4)
Mod_DEF_MACRO(hv1)
Mod_DEF_MACRO(hv2)
Mod_DEF_MACRO(hv4)
Mod_DEF_MACRO(lr1)
Mod_DEF_MACRO(lr2)
Mod_DEF_MACRO(lr4)
Mod_DEF_MACRO(pr1)
Mod_DEF_MACRO(pr2)
Mod_DEF_MACRO(pr4)
Mod_DEF_MACRO(tb1)
Mod_DEF_MACRO(tb2)
Mod_DEF_MACRO(tb4)

class XCSD_TierBox;

struct _binmask
{
 struct _hold
 {
  u1 val;
  u1 operator[](u1 arg)
  {
   return val << arg;
  }
  u1 operator()(u1 arg)
  {
   return val << arg;
  }
 };

 u1 arg;
 u1 operator%(u1 x) const
 {
  return (1 << x) - arg;
 }
 u1 operator/(u1 x) const
 {
  return (1 << x) - arg;
 }
 _hold operator[](u1 val) const
 {
  return {*this % val};
 }
};

constexpr _binmask binmask = {1};

struct SDI_Position
{
 rc2 tier;
 hv1 mid;
 hv2 mid_rep;
 xy1 full_ground;

 template<typename T>
 friend T& operator<<(T& lhs, const SDI_Position& rhs)
 {
  lhs << "(" << rhs.tier << ", " << rhs.full_ground
      << ": " << rhs.mid << "; " << rhs.mid_rep << ")";
  return lhs;
 }

 void init_full_ground();

 void init_mid();
 static void init_mid(u1 arg, u1& binary, u2& decimal);

 static void octal_to_mid(u2 arg, u1& binary, u2& decimal);
 static void octal_to_mid(args2 args, hv1& binary, hv2& decimal);

 xy1s get_mid1();
 xy1s get_mid2();
 xy1s get_ground();

 static xy1s ternary_to_semi_balanced(xy1 xy)
 {
  return { xy.x == 3? (s1)-1:(s1)xy.x, xy.y == 3? (s1)-1:(s1)xy.y};
 }

};


 // u1 r3[3];
 // r3[2] = right / 100;
 // right %= 100;
 // r3[1] = right / 10;
 // right %= 10;
 // r3[0] = right;
 // u1 rr3[3];
 //rr3[i/3] = right / pow;

inline lr2 operator""_sdi(unsigned long long arg)
{
 u2 right = arg % 1000;
 u2 r = 0, pow = 100;
 for(s1 i = 6; i >= 0; i -= 3)
 {
  r += ((right / pow) * (1 << i));
  right %= pow; pow /= 10;
 }

 return {(u2)(arg / 10000), r};

 //return {(u2)(arg / 10000), (u2) (r3[0] + r3[1] * 8 + r3[2] * 64)};
}

inline SDI_Position operator""_sd2(unsigned long long arg)
{


}

inline SDI_Position sdi_octal(u2 r, u2 h_mid, u2 c, u2 v_mid)
{
 hv1 mid;
 hv2 mid_rep;
 args2 args {h_mid, v_mid};
 SDI_Position::octal_to_mid(args, mid, mid_rep);
 SDI_Position result {{r, c}, mid, mid_rep, {0,0}};
 result.init_full_ground();
 return result;
}

inline SDI_Position sdi_octal(lr2 h, lr2 v)
{
 return sdi_octal(h.left, h.right, v.left, v.right);
}


_XCNS(XCSD)

#endif // XCSD_IMAGE__H

