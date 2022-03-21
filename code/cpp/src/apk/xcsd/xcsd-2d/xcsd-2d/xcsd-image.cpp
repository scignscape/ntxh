
#include "xcsd-image.h"

#include "xcsd-tierbox.h"

USING_XCNS(XCSD)

XCSD_Image::XCSD_Image()
  :  tier_counts_({0,0}),
     horizontal_outer_sizes_({0,0}),
     vertical_outer_sizes_({0,0}),
     tierbox_count_(0), tierboxes_(nullptr)
{

}

void XCSD_Image::load_image(QString path)
{
 image_.load(path);
}

XCSD_TierBox* XCSD_Image::get_tierbox_at_ground_position(u2 x, u2 y)
{

}

void SDI_Position::init_mid(u1 arg, u1& binary, u2& decimal)
{
 binary = 0; decimal = 3000;
 u1 bin = 16, dec = 100, pow = 9;
 for(u1 i = 0; i < 3; ++i)
 {
  u1 digit = arg / pow;
  binary += digit * bin;
  decimal += digit * dec;
  arg %= pow;
  pow /= 3;
  dec /= 10;
  bin /= 4;
 }
}

void SDI_Position::init_mid()
{
 init_mid(full_ground.x, mid.h, mid_rep.h);
 init_mid(full_ground.y, mid.v, mid_rep.v);
}

xy1s SDI_Position::get_mid1()
{
 xy1 xy = (mid._to<xy1>() >> 4) & 3;
 //{(u1)((mid.h >> 4) & 3), (u1)((mid.v >> 4) & 3)};
 return ternary_to_semi_balanced(xy);
}

xy1s SDI_Position::get_mid2()
{
 xy1 xy = (mid._to<xy1>() >> 2) & 3;
  // xy1 xy = {(u1)((mid.h >> 2) & 3), (u1)((mid.v >> 2) & 3)};
 return ternary_to_semi_balanced(xy);
}

xy1s SDI_Position::get_ground()
{
 xy1 xy = mid._to<xy1>() & 3;
  // xy1 xy = {(u1)(mid.h & 3), (u1)(mid.v & 3)};
 return ternary_to_semi_balanced(xy);
}



SDI_Position XCSD_Image::get_sdi_at_ground_position(u2 x, u2 y)
{
 SDI_Position result{ {0,0}, {0,0}, {0,0}, {0,0} };

 s1 x_offset = -1, y_offset = -1;

 if(horizontal_outer_sizes_.left > 0)
 {
  if(x < horizontal_outer_sizes_.left)
  {
   result.tier.r = 0;
   x_offset = x;
  }
  else
  {
   result.tier.r = 1;
   x -= horizontal_outer_sizes_.left;
  }
 }
 if(x_offset == -1)
   x_offset = x % 27;
 result.full_ground.x = x_offset;

 x /= 27;
 result.tier.r += x;

 if(vertical_outer_sizes_.top > 0)
 {
  if(y < vertical_outer_sizes_.top)
  {
   result.tier.c = 0;
   y_offset = y;
  }
  else
  {
   result.tier.c = 1;
   y -= vertical_outer_sizes_.top;
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

 if(horizontal_outer_sizes_.left > 0)
 {
  if(x <= horizontal_outer_sizes_.left)
    result.r = 0;
  else
  {
   result.r = 1;
   x -= horizontal_outer_sizes_.left;
  }
 }
 x /= 27;
 result.r += x;

 if(vertical_outer_sizes_.top > 0)
 {
  if(y <= vertical_outer_sizes_.top)
    result.c = 0;
  else
  {
   result.c = 1;
   y -= vertical_outer_sizes_.top;
  }
 }
 y /= 27;
 result.c += y;
 return result;
}


void XCSD_Image::init_tierboxes()
{
 tierboxes_ = new Vec1d<XCSD_TierBox*>({tierbox_count_});
 u4 total_count = 0;

 u1 non_full_h = 0, non_full_v = 0;
 for(u2 r = 0; r < tier_counts_.width; ++r)
 {
  if(r == 0)
    non_full_h = horizontal_outer_sizes_.left;
  else if(r == tier_counts_.width - 1)
    non_full_h = horizontal_outer_sizes_.right;

  for(u2 c = 0; c < tier_counts_.height; ++c)
  {
   XCSD_TierBox* trb = new XCSD_TierBox;
   if(non_full_h > 0)
   {
    trb->set_non_full_h(non_full_h);
    if(r == 0)
      trb->set_non_full_left();
   }
   if(c == 0)
   {
    non_full_v = vertical_outer_sizes_.top;
    if(non_full_v > 0)
    {
     trb->set_non_full_v(non_full_v);
     trb->set_non_full_up();
    }
   }
   else if(c == tier_counts_.height - 1)
   {
    non_full_v = vertical_outer_sizes_.bottom;
    if(non_full_v > 0)
      trb->set_non_full_v(non_full_v);
   }
   trb->init_boxes();
   tierboxes_->get_at(total_count) = trb;
   ++total_count;
  }
  non_full_h = 0; non_full_v = 0;
 }
}

void XCSD_Image::init_tier_counts()
{
 u2 w = image_.width();
 u2 h = image_.height();

 u2 ws = w / 27;
 u2 hs = h / 27;

 u2 w0 = w % 27 / 2;
 u2 h0 = h % 27 / 2;
 //return {(u2)image_.width(), (u2)image_.height()};

 if(w0 == 0)
 {
  if((w % 27) == 1)
  {
   ++ws;
   horizontal_outer_sizes_.right = 1;
  }
 }
 else
 {
  ws += 2;
  horizontal_outer_sizes_ = {w0, (u2) (w0 + ((w % 27) % 2))};
 }

 if(h0 == 0)
 {
  if((h % 27) == 1)
  {
   ++hs;
   vertical_outer_sizes_.bottom = 1;
  }
 }
 else
 {
  hs += 2;
  vertical_outer_sizes_ = {h0, (u2) (h0 + ((h % 27) % 2))};
 }

 tier_counts_ = {ws, hs};
 tierbox_count_ = tier_counts_.area();
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
