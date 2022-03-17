
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_IMAGE__H
#define XCSD_IMAGE__H


#include "xcsd-1d/_vec1d.h"

#include "xcsd-1d/vec1d.h"

#include <QImage>

#include "accessors.h"

XCNS_(XCSD)

// template<typename VAL_Type, typename = index_types<s2>,
//typename = _pr_break> class

#define Ty_DEF_MACRO(ty, size, asize, field1, field2) \
 struct ty##size { u##size field1, field2; \
   asize area() {return field1 * field2;} };

#define Tys_DEF_MACRO(ty, size, asize, field1, field2) \
struct ty##size##s { s##size field1, field2; \
   asize area() {return field1 * field2;} };

Ty_DEF_MACRO(wh, 2, u4, width, height)
Ty_DEF_MACRO(wh, 4, n8, width, height)
Ty_DEF_MACRO(xy, 2, u4, x, y)
Ty_DEF_MACRO(xy, 4, n8, x, y)
Ty_DEF_MACRO(lr, 2, u4, left, right)
Ty_DEF_MACRO(lr, 4, n8, left, right)
Ty_DEF_MACRO(pr, 2, u4,first, second)
Ty_DEF_MACRO(pr, 4, n8, first, second)
Ty_DEF_MACRO(tb, 2, u4, top, bottom)
Ty_DEF_MACRO(tb, 4, n8, first, second)

Tys_DEF_MACRO(wh, 2, u4, width, height)
Tys_DEF_MACRO(wh, 4, n8, width, height)
Tys_DEF_MACRO(xy, 2, u4, x, y)
Tys_DEF_MACRO(xy, 4, n8, x, y)
Tys_DEF_MACRO(lr, 2, u4, left, right)
Tys_DEF_MACRO(lr, 4, n8, left, right)
Tys_DEF_MACRO(pr, 2, u4, first, second)
Tys_DEF_MACRO(pr, 4, n8, first, second)
Tys_DEF_MACRO(tb, 2, u4, top, bottom)
Tys_DEF_MACRO(tb, 4, n8, first, second)



template<typename T>
struct Mod
{
 using Unsigned = T;
};

#define Mod_DEF_MACRO(ty) \
template<> struct Mod<ty> { using Unsigned = ty##s; };

Mod_DEF_MACRO(wh2)
Mod_DEF_MACRO(wh4)
Mod_DEF_MACRO(xy2)
Mod_DEF_MACRO(xy4)
Mod_DEF_MACRO(lr2)
Mod_DEF_MACRO(lr4)
Mod_DEF_MACRO(pr2)
Mod_DEF_MACRO(pr4)
Mod_DEF_MACRO(tb2)
Mod_DEF_MACRO(tb4)

class XCSD_TierBox;

class XCSD_Image
{
 QImage image_;

 wh2 tier_counts_;
 lr2 horizontal_outer_sizes_;
 tb2 vertical_outer_sizes_;

 u4 tierbox_count_;

 Vec1d<XCSD_TierBox*>* tierboxes_;

public:

 XCSD_Image();

 ACCESSORS__RGET(QImage ,image)

 ACCESSORS(wh2 ,tier_counts)
 ACCESSORS(lr2 ,horizontal_outer_sizes)
 ACCESSORS(tb2 ,vertical_outer_sizes)


 void load_image(QString path);

 static constexpr u1 tierbox_width = 27;

 wh2 get_wh()
 {
  return {(u2)image_.width(), (u2)image_.height()};
 }

 void init_tier_counts();
 void init_tierboxes();

 void get_255_palatte(QVector<QColor>& vec);




};


_XCNS(XCSD)

#endif // XCSD_IMAGE__H


//struct wh2
//{
// u2 width;
// u2 height;
//};

//struct wh4
//{
// u4 width;
// u4 height;
//};

//struct lr2
//{
// u2 left;
// u2 right;
//};

//struct lr4
//{
// u4 left;
// u4 right;
//};

//struct xy2
//{
// u2 x;
// u2 y;
//};

//struct xy4
//{
// u4 x;
// u4 y;
//};

//mod <xy4>::Unsigned


//struct wh2s
//{
// s2 width;
// s2 height;
//};

//struct wh4s
//{
// s4 width;
// s4 height;
//};

//struct lr2s
//{
// s2 left;
// s2 right;
//};

//struct lr4s
//{
// s4 left;
// s4 right;
//};

//struct xy2s
//{
// s2 x;
// s2 y;
//};

//struct xy4s
//{
// s4 x;
// s4 y;
//};
