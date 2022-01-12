
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef ENUM_MACROS__H
#define ENUM_MACROS__H


#define ENUM_FLAGS_OP_MACROS(e) \
 friend constexpr e operator|(e lhs, e rhs) \
 { \
  return (e) ( (u1) lhs | (u1) rhs ); \
 } \
 friend constexpr e operator|=(e& lhs, e rhs) \
 { \
  return lhs = (e) (lhs | rhs); \
 } \
 friend constexpr u1 operator^(e lhs, e rhs) \
 { \
  return (u1) lhs ^ (u1) rhs; \
 } \
 friend constexpr u1 operator^(e lhs, u1 rhs) \
 { \
  return (u1) lhs ^ (u1) rhs; \
 } \
 friend constexpr e operator^=(e& lhs, e rhs) \
 { \
  return lhs = (e) (lhs ^ rhs); \
 } \
 friend constexpr e operator^=(e& lhs, u1 rhs) \
 { \
  return lhs = (e) (lhs ^ rhs); \
 } \
 friend constexpr e operator,(e& lhs, e rhs) \
 { \
  if(lhs & rhs) lhs = (e) (lhs ^ rhs); \
  return lhs; \
 } \
 friend constexpr e operator,(e& lhs, u1 rhs) \
 { \
  if(lhs & rhs) lhs = (e) (lhs ^ rhs); \
  return lhs; \
 } \
 friend constexpr u1 operator&(e lhs, e rhs) \
 { \
  return (u1) lhs & (u1) rhs; \
 } \


#define ENUM_PLUS_MACRO(e) \
 friend u1 operator +(e lhs) \
 { \
  return (u1) lhs; \
 } \


#endif // ENUM_MACROS__H
