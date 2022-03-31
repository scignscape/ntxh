
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-image.h"

#include "xcsd-tierbox.h"

USING_XCNS(XCSD)

XCSD_Image::XCSD_Image()
//  :  tier_counts_({0,0}),
//     horizontal_outer_sizes_({0,0}),
//     vertical_outer_sizes_({0,0}),
//     tierbox_count_(0), tierboxes_(nullptr)
{

}

void XCSD_Image::load_image(QString path)
{
 image_.load(path);
}

XCSD_TierBox* XCSD_Image::get_tierbox_at_ground_position(u2 x, u2 y)
{

}

void XCSD_Image::init_geometry()
{
 geometry_.set_total_size(get_wh());
}

void XCSD_Image::init_pixel_data()
{
 static u2 box_area = tierbox_width * tierbox_width;

 data_.init_pixels(geometry_.total_size());

 XCSD_Image_Geometry::Iteration_Environment ienv = geometry_.formulate_iteration_environment();

 geometry_.for_each_full_tierbox([this, &ienv](XCSD_Image_Geometry::Grid_TierBox& gtb)
 {
  u4 index = geometry_.get_tierbox_index(gtb, ienv.size_even_odd_info);
  u4 threshold = index * box_area;
  xy2 tl = gtb.top_left();
  qDebug() << "tl = " << tl;
  QImage ci = image_.copy(tl.x, tl.y, tierbox_width, tierbox_width);
  if(ci.format() != QImage::Format_ARGB32)
  {
   ci = ci.convertToFormat(QImage::Format_ARGB32);
  }

  std::map<ab1, std::vector<n8>> sdi;

  image_tierbox_to_sdi_pixel_map(ci, sdi);

  for(u1 a = 1; a <= 9; ++a)
   for(u1 b = 1; b <= 9; ++b)
   {
    const std::vector<n8>& data3x3 = sdi[{a,b}];
    data_.copy_pixels(threshold, data3x3);
   }
 });
}


void XCSD_Image::image_tierbox_to_sdi_pixel_map(const QImage& ci, std::map<ab1, std::vector<n8>>& result)
{
 u1 a = 0, b = 0;
 for(u1 ar = 0; ar < 3; ++ar)
 {
  ++a;
  for(u1 ac = 0; ac < 3; ++ac)
  {
   ++a;
   for(u1 br = 0; br < 3; ++br)
   {
    ++b;
    for(u1 bc = 0; bc < 3; ++bc)
    {
     ++b;
     xy1 rows {br, ar};
     xy1 cols {bc, ac};
     xy1 tl = {cols.times({3, 9}).inner_sum(), rows.times({3, 9}).inner_sum()};
     for(u1 y = 0; y < 3; ++y)
     {
      const QRgb* scan = (const QRgb*) ci.scanLine(tl.y + y);
      scan += tl.x;
      for(u1 x = 0; x < 3; ++x)
      {
       const QRgb& qpixel = *(scan + x);
       n8 pixel = 0;

       // //  the (n8) casts here are strictly speaking unnecessary
        //    but could become necessary with something other
        //    than 1-byte rgba ...
       pixel |= (n8)qRed(qpixel);
       pixel |= (n8)qGreen(qpixel) << 8;
       pixel |= (n8)qBlue(qpixel) << 16;
       pixel |= (n8)qAlpha(qpixel) << 24;

       result[{a,b}].push_back(pixel);
      }
     }
    }
   }
  }
 }
}


void XCSD_Image::save_full_tier_image(QString path)
{
 static u2 box_area = tierbox_width * tierbox_width;

 XCSD_Image_Geometry::Iteration_Environment ienv = geometry_.formulate_iteration_environment();

 QImage target_image(image_.width(), image_.height(), image_.format());

 geometry_.for_each_full_tierbox([this, &ienv, &target_image](XCSD_Image_Geometry::Grid_TierBox& gtb)
 {
  QImage ti(tierbox_width, tierbox_width, QImage::Format_ARGB32);
  tierbox_to_qimage(gtb, ti, ienv);
 });
}

void XCSD_Image::data_tierbox_to_sdi_pixel_map(u4 tierbox_index,
  std::map<ab1, std::vector<n8>>& result)
{
 static u2 box_area = tierbox_width * tierbox_width;
 u4 threshold = tierbox_index * box_area;

 u1 a = 0, b = 0;
 for(u1 ar = 0; ar < 3; ++ar)
 {
  ++a;
  for(u1 ac = 0; ac < 3; ++ac)
  {
   ++a;
   for(u1 br = 0; br < 3; ++br)
   {
    ++b;
    for(u1 bc = 0; bc < 3; ++bc)
    {
     ++b;
     xy1 rows {br, ar};
     xy1 cols {bc, ac};
     xy1 tl = {cols.times({3, 9}).inner_sum(), rows.times({3, 9}).inner_sum()};

     u1 inner_index = 0;

     // data to std vec ... starting at threshold + tl ...

     for(u1 y = 0; y < 3; ++y)
     {
      const QRgb* scan; // = (const QRgb*) ci.scanLine(tl.y + y);
      scan += tl.x;
      for(u1 x = 0; x < 3; ++x)
      {
       const QRgb& qpixel = *(scan + x);
       n8 pixel = 0;

       // //  the (n8) casts here are strictly speaking unnecessary
       //    but could become necessary with something other
       //    than 1-byte rgba ...
       pixel |= (n8)qRed(qpixel);
       pixel |= (n8)qGreen(qpixel) << 8;
       pixel |= (n8)qBlue(qpixel) << 16;
       pixel |= (n8)qAlpha(qpixel) << 24;

       result[{a,b}].push_back(pixel);
      }
     }

    }
   }
  }
 }

}


void XCSD_Image::tierbox_to_qimage(XCSD_Image_Geometry::Grid_TierBox& gtb,
  QImage& target, XCSD_Image_Geometry::Iteration_Environment ienv)
{
 static u2 box_area = tierbox_width * tierbox_width;

 u4 index = geometry_.get_tierbox_index(gtb, ienv.size_even_odd_info);

 std::map<ab1, std::vector<n8>> sdi;
 data_tierbox_to_sdi_pixel_map(index, sdi);


   //xy2 tl = gtb.top_left();


}



SDI_Position XCSD_Image::get_sdi_at_ground_position(u2 x, u2 y)
{
 SDI_Position result{ {0,0}, {0,0}, {0,0}, {0,0} };

 s1 x_offset = -1, y_offset = -1;

 if(geometry_.horizontal_outer_sizes().left > 0)
 {
  if(x < geometry_.horizontal_outer_sizes().left)
  {
   result.tier.r = 0;
   x_offset = x;
  }
  else
  {
   result.tier.r = 1;
   x -= geometry_.horizontal_outer_sizes().left;
  }
 }
 if(x_offset == -1)
   x_offset = x % 27;
 result.full_ground.x = x_offset;

 x /= 27;
 result.tier.r += x;

 if(geometry_.vertical_outer_sizes().top > 0)
 {
  if(y < geometry_.vertical_outer_sizes().top)
  {
   result.tier.c = 0;
   y_offset = y;
  }
  else
  {
   result.tier.c = 1;
   y -= geometry_.vertical_outer_sizes().top;
  }
 }
 if(y_offset == -1)
   y_offset = y % 27;
 result.full_ground.y = y_offset;

 y /= 27;
 result.tier.c += y;

 result.init_mid();

 return result;
}


rc2 XCSD_Image::get_tierbox_at_ground_position_RC2(u2 x, u2 y)
{
 rc2 result {0,0};

 if(geometry_.horizontal_outer_sizes().left > 0)
 {
  if(x <= geometry_.horizontal_outer_sizes().left)
    result.r = 0;
  else
  {
   result.r = 1;
   x -= geometry_.horizontal_outer_sizes().left;
  }
 }
 x /= 27;
 result.r += x;

 if(geometry_.vertical_outer_sizes().top > 0)
 {
  if(y <= geometry_.vertical_outer_sizes().top)
    result.c = 0;
  else
  {
   result.c = 1;
   y -= geometry_.vertical_outer_sizes().top;
  }
 }
 y /= 27;
 result.c += y;
 return result;
}


void XCSD_Image::init_tierboxes()
{
// tierboxes_ = new Vec1d<XCSD_TierBox*>({tierbox_count_});
// u4 total_count = 0;

// u1 non_full_h = 0, non_full_v = 0;
// for(u2 r = 0; r < tier_counts_.width; ++r)
// {
//  if(r == 0)
//    non_full_h = horizontal_outer_sizes_.left;
//  else if(r == tier_counts_.width - 1)
//    non_full_h = horizontal_outer_sizes_.right;

//  for(u2 c = 0; c < tier_counts_.height; ++c)
//  {
//   XCSD_TierBox* trb = new XCSD_TierBox;
//   if(non_full_h > 0)
//   {
//    trb->set_non_full_h(non_full_h);
//    if(r == 0)
//      trb->set_non_full_left();
//   }
//   if(c == 0)
//   {
//    non_full_v = vertical_outer_sizes_.top;
//    if(non_full_v > 0)
//    {
//     trb->set_non_full_v(non_full_v);
//     trb->set_non_full_up();
//    }
//   }
//   else if(c == tier_counts_.height - 1)
//   {
//    non_full_v = vertical_outer_sizes_.bottom;
//    if(non_full_v > 0)
//      trb->set_non_full_v(non_full_v);
//   }
//   trb->init_boxes();
//   tierboxes_->get_at(total_count) = trb;
//   ++total_count;
//  }
//  non_full_h = 0; non_full_v = 0;
// }
}

void XCSD_Image::init_tier_counts(XCSD_Image_Geometry::TierGrid_Preferances pref)
{
 geometry_.init_tier_counts(pref);

// u2 w = image_.width();
// u2 h = image_.height();

// u2 ws = w / 27;
// u2 hs = h / 27;

// u2 w0 = w % 27 / 2;
// u2 h0 = h % 27 / 2;
// //return {(u2)image_.width(), (u2)image_.height()};

// if(w0 == 0)
// {
//  if((w % 27) == 1)
//  {
//   ++ws;
//   horizontal_outer_sizes_.right = 1;
//  }
// }
// else
// {
//  ws += 2;
//  horizontal_outer_sizes_ = {w0, (u2) (w0 + ((w % 27) % 2))};
// }

// if(h0 == 0)
// {
//  if((h % 27) == 1)
//  {
//   ++hs;
//   vertical_outer_sizes_.bottom = 1;
//  }
// }
// else
// {
//  hs += 2;
//  vertical_outer_sizes_ = {h0, (u2) (h0 + ((h % 27) % 2))};
// }

// tier_counts_ = {ws, hs};
// tierbox_count_ = tier_counts_.area();
}


//void XCSD_Image::init_tierbox_counts()
//{

//}


void XCSD_Image::get_255_palatte(QVector<QColor>& vec)
{
 vec.resize(255);

 //QImage i16 = image_.convertToFormat(QImage::Format_RGB16);
 QImage i444 = image_.convertToFormat(QImage::Format_RGB444);

 QVector<u2> colors(65536);

 QMap<QRgb, u4> counts;

 u4 w = i444.width();
 u4 h = i444.height();

 for(u4 x = 0; x < w; ++x)
 {
  for(u4 y = 0; y < h; ++y)
  {
   QRgb rgb = i444.pixel(x, y);
   ++counts[rgb];
//   u1 i = i255.pixelIndex(x, y);
//   ++indices[i].second;
  }
 }

 QVector<QRgb> counts_keys = counts.keys().toVector();

 std::sort(counts_keys.begin(),
   counts_keys.end(),
   [&counts](QRgb lhs, QRgb rhs)
 {
  return counts[lhs] > counts[rhs];
 });

// qDebug() << "counts: " << counts_keys;

 if(counts_keys.size() > 255)
   counts_keys.resize(255);

 u1 i = 0;

 for(QRgb k : counts_keys)
 {
  QColor c = QColor(k);
  qDebug() << i << " color: " << c << " count: " << counts[k];
  ++i;
 }

 std::transform(counts_keys.begin(), counts_keys.end(), vec.begin(),
   [](QRgb rgb)
 {
  return QColor(rgb);
 });

// for(u4 y = 0; y < h; ++y)
// {
//  const u1* sl = i444.constScanLine(y);
//  for(u4 x = 0; x < w; ++x)
//  {

//  }
// }

}

// QImage i255 = image_.convertToFormat(QImage::Format_Indexed8, Qt::ColorOnly);

// QVector<QPair<u1, u4>> indices(256);

// //QVector<QPair<u1, u4>> indices_sorted(256);
// QVector<s2> indices_sorted(256);

// for(u2 i = 0; i < 256; ++i)
//   indices[i].first = i;

// u4 w = i255.width();
// u4 h = i255.height();

// for(u4 x = 0; x < w; ++x)
// {
//  for(u4 y = 0; y < h; ++y)
//  {
//   u1 i = i255.pixelIndex(x, y);
//   ++indices[i].second;
//  }
// }

// std::sort(indices.begin(), indices.end(), [](auto pr1, auto pr2)
// {
//  return pr1.second < pr2.second;
// });

// std::transform(indices.rbegin(), indices.rend(), indices_sorted.begin(), [](auto pr)
// {
//  if(pr.second == 0)
//    return (s2) -1;
//  return (s2) pr.first;
// });

// qDebug() << "indices: " << indices_sorted;

// indices_sorted.removeLast();

// u1 i = 0;
// for(s2 color_index: indices_sorted)
// {
//  if(color_index == -1)
//    break;
//  vec[i] = i255.color(color_index);
//  ++i;
// }

// qDebug() << "vec: " << vec;

//}
