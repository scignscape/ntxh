

//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef _SIGMA_INCLUDE_BLOCK

#ifndef sigmans
#define sigmans(arg) _sigma_ns_(arg)::arg
#endif

#ifndef oself
#define oself get_oself()
#endif

#ifndef _STRING
#define _STRING(x) #x
#endif

#ifndef _SIGMA_INCLUDE
#define _SIGMA_INCLUDE(x) _STRING(sigmas/x.h)
#endif



// //  we use this file itself as a "dummy" include
 //    for items in variadic macro parameter lists
 //    longer than the parameters given -- e.g.,
 //    parameter '_3_of_2' -- defining a temporary
 //    _SIGMA_INCLUDE_BLOCK macro which makes
 //    this file appear empty when including itself.

#ifndef _preproc_NUM_ARGS_
#define _preproc_NUM_ARGS_(_1, _2, _3, _4, _5, _6, _7, _8, _9, TOTAL, ...) TOTAL
#endif

#ifndef _preproc_NUM_ARGS
#define _preproc_NUM_ARGS(...) _preproc_NUM_ARGS_(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#endif

//#ifndef _preproc_NUM_ARGS_BUT_FIRST
//#define _preproc_NUM_ARGS_BUT_FIRST(...) _preproc_NUM_ARGS_(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
//#endif

#ifndef _preproc_CONCAT_
#define _preproc_CONCAT_(X, Y) X##Y
#endif

#ifndef _preproc_CONCAT
#define _preproc_CONCAT(MACRO, NUMBER) _preproc_CONCAT_(MACRO, NUMBER)
#endif


#define _SIGMA_ADAPTER_get1(_1, _2) _1
#define _SIGMA_ADAPTER_get2(_1, _2) _2


#ifndef _SIGMA_ADAPTER_3
#define _SIGMA_ADAPTER_3(fname, arg1, arg2) \
void fname(_SIGMA_ADAPTER_get1 arg1 _SIGMA_ADAPTER_get2 arg1, \
  _SIGMA_ADAPTER_get1 arg2 _SIGMA_ADAPTER_get2 arg2) \
{ sigmans(fname)(oself, _SIGMA_ADAPTER_get2 arg1, _SIGMA_ADAPTER_get2 arg2); }
#endif


#ifndef SIGMA_ADAPTER
#define SIGMA_ADAPTER(...) \
  _preproc_CONCAT(_SIGMA_ADAPTER_, _preproc_NUM_ARGS (__VA_ARGS__))(__VA_ARGS__)
#endif


#ifndef _SIGMA_ADAPTER_PAIR_1
#define _SIGMA_ADAPTER_PAIR_1(fname) \
void fname() \
{ sigmans(fname)(oself->first, oself->second); oself_done(); }
#endif


#ifndef SIGMA_ADAPTER_PAIR
#define SIGMA_ADAPTER_PAIR(...) \
  _preproc_CONCAT(_SIGMA_ADAPTER_PAIR_, _preproc_NUM_ARGS (__VA_ARGS__))(__VA_ARGS__)
#endif



#define _SIGMA_INCLUDE_1_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_1_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)
#define _SIGMA_INCLUDE_2_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_2_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)
#define _SIGMA_INCLUDE_3_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_3_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)

#define _SIGMA_INCLUDE_4_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_4_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)
#define _SIGMA_INCLUDE_5_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_5_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)
#define _SIGMA_INCLUDE_6_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_6_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)

#define _SIGMA_INCLUDE_7_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_7_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)
#define _SIGMA_INCLUDE_8_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_8_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)
#define _SIGMA_INCLUDE_9_of_VAR(...) _preproc_CONCAT(_SIGMA_INCLUDE_9_of_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)


#ifndef _SIGMA_INCLUDE_1_of_1
#define _SIGMA_INCLUDE_1_of_1(_1) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_2
#define _SIGMA_INCLUDE_1_of_2(_1, _2) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_3
#define _SIGMA_INCLUDE_1_of_3(_1, _2, _3) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_4
#define _SIGMA_INCLUDE_1_of_4(_1, _2, _3, _4) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_5
#define _SIGMA_INCLUDE_1_of_5(_1, _2, _3, _4, _5) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_6
#define _SIGMA_INCLUDE_1_of_6(_1, _2, _3, _4, _5, _6) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_7
#define _SIGMA_INCLUDE_1_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_8
#define _SIGMA_INCLUDE_1_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_1.h)
#endif

#ifndef _SIGMA_INCLUDE_1_of_9
#define _SIGMA_INCLUDE_1_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_1.h)
#endif


#ifndef _SIGMA_INCLUDE_2_of_1
#define _SIGMA_INCLUDE_2_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_2_of_2
#define _SIGMA_INCLUDE_2_of_2(_1, _2) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_3
#define _SIGMA_INCLUDE_2_of_3(_1, _2, _3) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_4
#define _SIGMA_INCLUDE_2_of_4(_1, _2, _3, _4) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_5
#define _SIGMA_INCLUDE_2_of_5(_1, _2, _3, _4, _5) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_6
#define _SIGMA_INCLUDE_2_of_6(_1, _2, _3, _4, _5, _6) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_7
#define _SIGMA_INCLUDE_2_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_8
#define _SIGMA_INCLUDE_2_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_2.h)
#endif

#ifndef _SIGMA_INCLUDE_2_of_9
#define _SIGMA_INCLUDE_2_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_2.h)
#endif


#ifndef _SIGMA_INCLUDE_3_of_1
#define _SIGMA_INCLUDE_3_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_3_of_2
#define _SIGMA_INCLUDE_3_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_3_of_3
#define _SIGMA_INCLUDE_3_of_3(_1, _2, _3) _STRING(sigmas/_3.h)
#endif

#ifndef _SIGMA_INCLUDE_3_of_4
#define _SIGMA_INCLUDE_3_of_4(_1, _2, _3, _4) _STRING(sigmas/_3.h)
#endif

#ifndef _SIGMA_INCLUDE_3_of_5
#define _SIGMA_INCLUDE_3_of_5(_1, _2, _3, _4, _5) _STRING(sigmas/_3.h)
#endif

#ifndef _SIGMA_INCLUDE_3_of_6
#define _SIGMA_INCLUDE_3_of_6(_1, _2, _3, _4, _5, _6) _STRING(sigmas/_3.h)
#endif

#ifndef _SIGMA_INCLUDE_3_of_7
#define _SIGMA_INCLUDE_3_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_3.h)
#endif

#ifndef _SIGMA_INCLUDE_3_of_8
#define _SIGMA_INCLUDE_3_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_3.h)
#endif

#ifndef _SIGMA_INCLUDE_3_of_9
#define _SIGMA_INCLUDE_3_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_3.h)
#endif


#ifndef _SIGMA_INCLUDE_4_of_1
#define _SIGMA_INCLUDE_4_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_4_of_2
#define _SIGMA_INCLUDE_4_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_4_of_3
#define _SIGMA_INCLUDE_4_of_3(_1, _2, _3) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_4_of_4
#define _SIGMA_INCLUDE_4_of_4(_1, _2, _3, _4) _STRING(sigmas/_4.h)
#endif

#ifndef _SIGMA_INCLUDE_4_of_5
#define _SIGMA_INCLUDE_4_of_5(_1, _2, _3, _4, _5) _STRING(sigmas/_4.h)
#endif

#ifndef _SIGMA_INCLUDE_4_of_6
#define _SIGMA_INCLUDE_4_of_6(_1, _2, _3, _4, _5, _6) _STRING(sigmas/_4.h)
#endif

#ifndef _SIGMA_INCLUDE_4_of_7
#define _SIGMA_INCLUDE_4_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_4.h)
#endif

#ifndef _SIGMA_INCLUDE_4_of_8
#define _SIGMA_INCLUDE_4_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_4.h)
#endif

#ifndef _SIGMA_INCLUDE_4_of_9
#define _SIGMA_INCLUDE_4_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_4.h)
#endif


#ifndef _SIGMA_INCLUDE_5_of_1
#define _SIGMA_INCLUDE_5_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_5_of_2
#define _SIGMA_INCLUDE_5_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_5_of_3
#define _SIGMA_INCLUDE_5_of_3(_1, _2, _3) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_5_of_4
#define _SIGMA_INCLUDE_5_of_4(_1, _2, _3, _4) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_5_of_5
#define _SIGMA_INCLUDE_5_of_5(_1, _2, _3, _4, _5) _STRING(sigmas/_5.h)
#endif

#ifndef _SIGMA_INCLUDE_5_of_6
#define _SIGMA_INCLUDE_5_of_6(_1, _2, _3, _4, _5, _6) _STRING(sigmas/_5.h)
#endif

#ifndef _SIGMA_INCLUDE_5_of_7
#define _SIGMA_INCLUDE_5_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_5.h)
#endif

#ifndef _SIGMA_INCLUDE_5_of_8
#define _SIGMA_INCLUDE_5_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_5.h)
#endif

#ifndef _SIGMA_INCLUDE_5_of_9
#define _SIGMA_INCLUDE_5_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_5.h)
#endif


#ifndef _SIGMA_INCLUDE_6_of_1
#define _SIGMA_INCLUDE_6_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_6_of_2
#define _SIGMA_INCLUDE_6_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_6_of_3
#define _SIGMA_INCLUDE_6_of_3(_1, _2, _3) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_6_of_4
#define _SIGMA_INCLUDE_6_of_4(_1, _2, _3, _4) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_6_of_5
#define _SIGMA_INCLUDE_6_of_5(_1, _2, _3, _4, _5) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_6_of_6
#define _SIGMA_INCLUDE_6_of_6(_1, _2, _3, _4, _5, _6) _STRING(sigmas/_6.h)
#endif

#ifndef _SIGMA_INCLUDE_6_of_7
#define _SIGMA_INCLUDE_6_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_6.h)
#endif

#ifndef _SIGMA_INCLUDE_6_of_8
#define _SIGMA_INCLUDE_6_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_6.h)
#endif

#ifndef _SIGMA_INCLUDE_6_of_9
#define _SIGMA_INCLUDE_6_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_6.h)
#endif


#ifndef _SIGMA_INCLUDE_7_of_1
#define _SIGMA_INCLUDE_7_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_7_of_2
#define _SIGMA_INCLUDE_7_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_7_of_3
#define _SIGMA_INCLUDE_7_of_3(_1, _2, _3) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_7_of_4
#define _SIGMA_INCLUDE_7_of_4(_1, _2, _3, _4) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_7_of_5
#define _SIGMA_INCLUDE_7_of_5(_1, _2, _3, _4, _5) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_7_of_6
#define _SIGMA_INCLUDE_7_of_6(_1, _2, _3, _4, _5, _6) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_7_of_7
#define _SIGMA_INCLUDE_7_of_7(_1, _2, _3, _4, _5, _6, _7) _STRING(sigmas/_7.h)
#endif

#ifndef _SIGMA_INCLUDE_7_of_8
#define _SIGMA_INCLUDE_7_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_7.h)
#endif

#ifndef _SIGMA_INCLUDE_7_of_9
#define _SIGMA_INCLUDE_7_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_7.h)
#endif


#ifndef _SIGMA_INCLUDE_8_of_1
#define _SIGMA_INCLUDE_8_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_2
#define _SIGMA_INCLUDE_8_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_3
#define _SIGMA_INCLUDE_8_of_3(_1, _2, _3) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_4
#define _SIGMA_INCLUDE_8_of_4(_1, _2, _3, _4) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_5
#define _SIGMA_INCLUDE_8_of_5(_1, _2, _3, _4, _5) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_6
#define _SIGMA_INCLUDE_8_of_6(_1, _2, _3, _4, _5, _6) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_7
#define _SIGMA_INCLUDE_8_of_7(_1, _2, _3, _4, _5, _6, _7) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_8_of_8
#define _SIGMA_INCLUDE_8_of_8(_1, _2, _3, _4, _5, _6, _7, _8) _STRING(sigmas/_8.h)
#endif

#ifndef _SIGMA_INCLUDE_8_of_9
#define _SIGMA_INCLUDE_8_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_8.h)
#endif


#ifndef _SIGMA_INCLUDE_9_of_1
#define _SIGMA_INCLUDE_9_of_1(_1) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_2
#define _SIGMA_INCLUDE_9_of_2(_1, _2) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_3
#define _SIGMA_INCLUDE_9_of_3(_1, _2, _3) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_4
#define _SIGMA_INCLUDE_9_of_4(_1, _2, _3, _4) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_5
#define _SIGMA_INCLUDE_9_of_5(_1, _2, _3, _4, _5) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_6
#define _SIGMA_INCLUDE_9_of_6(_1, _2, _3, _4, _5, _6) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_7
#define _SIGMA_INCLUDE_9_of_7(_1, _2, _3, _4, _5, _6, _7) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_8
#define _SIGMA_INCLUDE_9_of_8(_1, _2, _3, _4, _5, _6, _7, _8) __FILE__
#endif

#ifndef _SIGMA_INCLUDE_9_of_9
#define _SIGMA_INCLUDE_9_of_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) _STRING(sigmas/_9.h)
#endif


template<typename THIS_Type>
struct xSigma : THIS_Type {

typedef THIS_Type oself_t;

 THIS_Type* get_oself()
 {
  return reinterpret_cast<THIS_Type*>(this);
 }

 void oself_done()
 {
  delete get_oself();
 }

#define _SIGMA_INCLUDE_BLOCK
#include _my_sigma_(_SIGMA_INCLUDE_1_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_2_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_3_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_4_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_5_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_6_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_7_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_8_of_VAR)
#include _my_sigma_(_SIGMA_INCLUDE_9_of_VAR)
#undef _SIGMA_INCLUDE_BLOCK

};

template<typename THIS1_Type, typename THIS2_Type>
struct xSigmaPair : xSigma<QPair<THIS1_Type, THIS2_Type>>
{
};

template<typename THIS_Type>
xSigma<THIS_Type>* sigma(THIS_Type* o) { return reinterpret_cast<xSigma<THIS_Type>*>(o);}

template<typename THIS1_Type, typename THIS2_Type>
xSigmaPair<THIS1_Type, THIS2_Type>*
sigma(THIS1_Type o1, THIS2_Type o2)
{
 return reinterpret_cast<xSigmaPair<THIS1_Type, THIS2_Type>*>(
   new QPair<THIS1_Type, THIS2_Type>(o1, o2));
}

#endif //_SIGMA_INCLUDE_BLOCK
