
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-image.h"

#include "xcsd-tierbox.h"

#include <QPainter>

#include "textio.h"

USING_KANS(TextIO)

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

void XCSD_Image::init_pixel_data(QString info_folder)
{
 static u2 box_area = tierbox_width * tierbox_width;

 data_.init_pixels(geometry_.total_size());

 init_outer_ring_pixel_data();

 XCSD_Image_Geometry::Iteration_Environment ienv = geometry_.formulate_iteration_environment();

 geometry_.for_each_full_tierbox([this, &ienv, &info_folder](XCSD_Image_Geometry::Grid_TierBox& gtb)
 {
  QString info_path;
  QString info_string;

  if(!info_folder.isEmpty())
  {
   info_path = QString("%1/%2-%3.txt").arg(info_folder).arg(gtb.loc.r()).arg(gtb.loc.c());
   info_string = QString("Full tierbox %2 %3\n\n").arg(gtb.loc.r()).arg(gtb.loc.c());
  }

  u4 index = geometry_.get_tierbox_index(gtb, ienv.size_even_odd_info, nullptr);
  u4 threshold = index * box_area;

  u2 threshold_offset = 0;

  xy2 tl = gtb.top_left();

  QImage ci = image_.copy(tl.x, tl.y, tierbox_width, tierbox_width);
  if(ci.format() != QImage::Format_ARGB32)
  {
   ci = ci.convertToFormat(QImage::Format_ARGB32);
  }

  ci.save(info_path + ".png");

  std::map<s1, std::vector<n8>> sdi;

  // temporary
  initial_setup_tierbox_ = gtb.loc.rc();

  image_tierbox_to_sdi_pixel_map(ci, sdi);

  for(u1 a = 1; a <= 9; ++a)
   for(u1 b = 1; b <= 9; ++b)
   {
    const std::vector<n8>& data3x3 = sdi[(ab1{a,b}).to_base(10)];

    data_.copy_pixels(threshold + threshold_offset, data3x3);

    threshold_offset += 9;

    if(!info_string.isEmpty())
    {
     info_string += QString("\nSDI location %1\n").arg(ab1{a,b}.to_base(10));
     u1 vi = 0;
     for(u1 y = 0; y < 3; ++y)
     {
      info_string += QString(" %1 %2 %3\n").arg(data3x3[vi], 16, 16, QChar('0'))
        .arg(data3x3[vi + 1], 16, 16, QChar('0')).arg(data3x3[vi + 2], 16, 16, QChar('0'));
      vi += 3;
     }
    }
   }

 save_file(info_path, info_string);
 });



}


void XCSD_Image::init_outer_ring_pixel_data()
{
 _init_outer_ring_pixel_data_landscaoe();
}


n8 XCSD_Image::qrgb_to_pixel_number(QRgb rgb)
{
 n8 result = 0;

 // //  the (n8) casts here are strictly speaking unnecessary
  //    but could become necessary with something other
  //    than 1-byte rgba ...
 result |= (n8)qRed(rgb);
 result |= (n8)qGreen(rgb) << 8;
 result |= (n8)qBlue(rgb) << 16;
 result |= (n8)(255 - qAlpha(rgb)) << 24;

 return result;
}

void XCSD_Image::_init_outer_ring_pixel_data_landscaoe()
{
 u4 offset = geometry_.get_total_full_tierbox_area();

 u1 height = geometry_.vertical_outer_sizes().top;
// u1 tw = image_.width();

 u2 start_Top_Left_Corner = 0;
 u2 end_Top_Left_Corner = geometry_.get_outer_ring_position_end(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Left_Corner);
 u2 start_Top_Left_Top = geometry_.get_outer_ring_position_start(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Left_Top);
 u2 end_Top_Left_Top = geometry_.get_outer_ring_position_end(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Left_Top);
 u2 start_Top_Center = geometry_.get_outer_ring_position_start(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Center);
 u2 end_Top_Center = geometry_.get_outer_ring_position_end(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Center);
 u2 start_Top_Right_Top = geometry_.get_outer_ring_position_start(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Right_Top);
 u2 end_Top_Right_Top = geometry_.get_outer_ring_position_end(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Right_Top);

  // note start at the end here
 u2 start_Top_Right_Corner = geometry_.get_outer_ring_position_end(
   XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Right_Corner);
 u2 end_Top_Right_Corner = image_.width();

// for(u1 x = start_Top_Left_Corner; x < end_Top_Left_Corner; ++x)
// {
//  QRgb* data = (QRgb*) image_.constScanLine(y);
//  QRgb pixel = data[x];
// }


 u4 mark_offset = 0;
 for(u2 y = 0; y < height; ++y)
 {
  mark_offset = geometry_.outer_ring_positions().offset_for(
    XCSD_Image_Geometry::Outer_Ring_Positions::Landscape::Top_Left);
  QRgb* scanline = (QRgb*) image_.constScanLine(y);

  for(u2 x = start_Top_Left_Top; x < end_Top_Left_Top; ++x)
  {
   QRgb qpixel = scanline[x];
   n8 pixel = qrgb_to_pixel_number(qpixel);
   data_.init_single_pixel(offset + mark_offset, pixel);
  }

  ++mark_offset;
 }


}

void XCSD_Image::image_tierbox_to_sdi_pixel_map(const QImage& ci, std::map<s1, std::vector<n8>>& result)
{
 u1 a = 0, b = 0;
 for(u1 ar = 0; ar < 3; ++ar)
 {
  for(u1 ac = 0; ac < 3; ++ac)
  {
   ++a; b = 0;
   for(u1 br = 0; br < 3; ++br)
   {
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

       QString tr = QString("%1%2").arg(initial_setup_tierbox_.r,2,10,QChar('0'))
         .arg(initial_setup_tierbox_.c,2,10,QChar('0'));


//       QString test = QString("%1a%2%3c%4b%5%6c%7%8%9").arg(tr, 4)
//         .arg(a).arg(ar).arg(ac).arg(b).arg(br).arg(bc).arg(x).arg(y);

//       pixel = test.toLongLong(nullptr, 16);
       //pixel = 0x20202020;

       pixel = qrgb_to_pixel_number(qpixel);

//       pixel = 0;

//       // //  the (n8) casts here are strictly speaking unnecessary
//        //    but could become necessary with something other
//        //    than 1-byte rgba ...
//       pixel |= (n8)qRed(qpixel);
//       pixel |= (n8)qGreen(qpixel) << 8;
//       pixel |= (n8)qBlue(qpixel) << 16;
//       pixel |= (n8)(255 - qAlpha(qpixel)) << 24;

//       pixel |= (n8)14 << 40;
//       pixel |= (n8)(tl.y + y) << 44;
//       pixel |= (n8)(tl.x + x) << 52;
//       pixel |= (n8)14 << 60;

       result[(ab1{a,b}).to_base(10)].push_back(pixel);
      }
     }
    }
   }
  }
 }
}


void XCSD_Image::save_full_tier_image(QString path, QString info_folder,
  std::function<void(QImage&, XCSD_Image_Geometry::Grid_TierBox&,
    XCSD_Image_Geometry::Iteration_Environment, u4, n8*, // data_index,
    const XCSD_Image_Geometry::MCH_Info&, QString, u1)> cb)
{
 //static u2 box_area = tierbox_width * tierbox_width;

 XCSD_Image_Geometry::Iteration_Environment ienv = geometry_.formulate_iteration_environment();

 QPainter painter;

 QImage target_image;

 if(!path.isEmpty())
 {
  target_image = QImage(image_.width(), image_.height(), image_.format());
  QColor fillc(0,200,0);
  target_image.fill(fillc);
  painter.begin(&target_image);
 }

 u4 outer_ring_offset = geometry_.full_tier_counts().area() * tierbox_width  * tierbox_width;
 //if(geometry_.full_tier_counts().)

 geometry_.for_each_outer_ring_area(
    [this, &path, cb, &ienv, &painter, &info_folder](u1 index, XCSD_Image_Geometry::Outer_Ring_Area_Flags area_flags)
 {
//  switch (area_flags)
//  {
//  case XCSD_Image_Geometry::Outer_Ring_Area_Flags::Normal_Landscape:
//   {
    u4 mark_offset = geometry_.outer_ring_positions().offset_for(
      (XCSD_Image_Geometry::Outer_Ring_Positions::Landscape) index);

    QPoint *qpoint, primary_qpoint, secondary_qpoint;
    wh2 primary_rect_wh = geometry_.get_outer_ring_rect_wh_for(area_flags, index, &primary_qpoint);
    wh2 secondary_rect_wh = geometry_.get_secondary_outer_ring_rect_wh_for(area_flags, index, &secondary_qpoint);

    qpoint = &primary_qpoint;
    for(wh2 rect_wh = primary_rect_wh ;; rect_wh = secondary_rect_wh)
    {
     if(rect_wh != wh2{0,0})
     {
      QImage outer_ring_image(rect_wh.width, rect_wh.height, QImage::Format_ARGB32);

      QColor fillc(0,100,0);
      outer_ring_image.fill(fillc);

//      if(index == 10 || index == 13)
//         qDebug() << index;

//      for(u2 y = 0; y < rect_wh.height; ++y)
//      {
//       //QRgb* scanline = target_image.scanLine(y);

//       for(u2 x = 0; x < rect_wh.width; ++x)
//       {


//       }
//      }

//    if(index == 4 || index >= 9)
      painter.drawImage(*qpoint, outer_ring_image);

     }
     if(qpoint == &secondary_qpoint)
       break;
     qpoint = &secondary_qpoint;
    }
//    u2 rect_height = geometry_.outer_ring_positions().rect_height_for(
//       (XCSD_Image_Geometry::Outer_Ring_Positions::Landscape) index);


//   }
//   break;
//  default: break;

//  }
 });

 geometry_.for_each_full_tierbox(
    [this, &path, cb, &ienv, &painter, &info_folder](XCSD_Image_Geometry::Grid_TierBox& gtb)
 {
  QImage ti(tierbox_width, tierbox_width, QImage::Format_ARGB32);

  XCSD_Image_Geometry::MCH_Info mchi;
  //pr2s mch;

  u4 data_index;

  n8* data_start;

  tierbox_to_qimage(gtb, ti, ienv, &data_index, &data_start, &mchi, info_folder);

  if(!info_folder.isEmpty())
  {
   QString path = QString("%1/%2-%3.png").arg(info_folder).arg(gtb.loc.r()).arg(gtb.loc.c());
   ti.save(path);
  }

  if(cb)
  {
   cb(ti, gtb, ienv, data_index, data_start, mchi,  info_folder, tierbox_width);
  }

  if(!path.isEmpty())
  {
   QPoint tl(gtb.top_left().as_qpoint());
   painter.drawImage(tl, ti);
  }

  //return-1;
 });

 if(!path.isEmpty())
 {
  painter.end();
  target_image.save(path);
 }
}

u4 XCSD_Image::data_tierbox_to_sdi_pixel_map(u4 tierbox_index,
  std::map<s1, std::pair<u2, std::vector<n8>>>& result)
{
 static u2 box_area = tierbox_width * tierbox_width;
 u4 threshold = tierbox_index * box_area;

 u1 b, a = 0;
 u2 threshold_offset = 0;
 for(u1 ar = 0; ar < 3; ++ar)
 {
  for(u1 ac = 0; ac < 3; ++ac)
  {
   ++a; b = 0;
   for(u1 br = 0; br < 3; ++br)
   {
    for(u1 bc = 0; bc < 3; ++bc)
    {
     ++b;

     std::vector<n8> pixels;
     data_.get_pixel_run(threshold + threshold_offset, 9, pixels);
     result[(ab1{a,b}).to_base(10)] = {threshold_offset, pixels};

     threshold_offset += 9;
     // data to std vec ... starting at threshold + tl ...

    }
   }
  }
 }

 return threshold;
}


//xy1 rows {br, ar};
//xy1 cols {bc, ac};
//xy1 tl = {cols.times({3, 9}).inner_sum(), rows.times({3, 9}).inner_sum()};

//u1 inner_index = 0;

//for(u1 y = 0; y < 3; ++y)
//{
// const QRgb* scan; // = (const QRgb*) ci.scanLine(tl.y + y);
// scan += tl.x;
// for(u1 x = 0; x < 3; ++x)
// {
//  const QRgb& qpixel = *(scan + x);
//  n8 pixel = 0;

//  // //  the (n8) casts here are strictly speaking unnecessary
//  //    but could become necessary with something other
//  //    than 1-byte rgba ...
//  pixel |= (n8)qRed(qpixel);
//  pixel |= (n8)qGreen(qpixel) << 8;
//  pixel |= (n8)qBlue(qpixel) << 16;
//  pixel |= (n8)qAlpha(qpixel) << 24;

//  result[{a,b}].push_back(pixel);
// }
//}


void XCSD_Image::tierbox_to_qimage(XCSD_Image_Geometry::Grid_TierBox& gtb,
  QImage& target, XCSD_Image_Geometry::Iteration_Environment ienv,
  u4* data_index, n8** data_start, //pr2s* mch,
  XCSD_Image_Geometry::MCH_Info* mchi,  QString info_folder)
{
 //static u2 box_area = tierbox_width * tierbox_width;

 u4 index = geometry_.get_tierbox_index(gtb, ienv.size_even_odd_info, mchi);

 std::map<s1, std::pair<u2, std::vector<n8>>> sdi;

 u4 di = data_tierbox_to_sdi_pixel_map(index, sdi);


 if(data_index)
 {
  *data_index = di;
  if((di != (u4) -1) && data_start)
    *data_start = data_.get_pixel_data_start(di);
 }



// static u4 deflt;
// (data_index? *data_index : deflt) =
//   data_tierbox_to_sdi_pixel_map(index, sdi);


 QString info_path;
 QString info_string;

 if(!info_folder.isEmpty())
 {
  info_path = QString("%1/%2-%3.txt").arg(info_folder).arg(gtb.loc.r()).arg(gtb.loc.c());
  info_string = QString("Full tierbox %2 %3\n\n\n").arg(gtb.loc.r()).arg(gtb.loc.c());
 }

 for(auto const& [ab_s1, thr_vec]: sdi)
 {
  ab1 ab = {(u1)((u1)ab_s1 / 10), (u1)((u1)ab_s1 % 10)};

  if(!info_string.isEmpty())
    info_string += QString("SDI location %1\n").arg(ab_s1);

  ab = ab.double_minus(1);



  // // rc here is 0 - 3
  rc1 arc = {(u1)(ab.a / 3), (u1)(ab.a % 3)};
  rc1 brc = {(u1)(ab.b / 3), (u1)(ab.b % 3)};

  u1 tl_scan_row = arc.r * 9 + brc.r * 3;

  u1 tl_scan_column = arc.c * 9 + brc.c * 3;




  u1 vi = 0; // vector index
  for(u1 y = 0; y < 3; ++y)
  {
   QRgb* img_pixels = (QRgb*) target.scanLine(tl_scan_row + y);

   img_pixels += tl_scan_column;
   for(u1 x = 0; x < 3; ++x)
   {
    n8 pixel = thr_vec.second[vi];
    // qDebug() << "pixel = " << (pixel & 0x00FFFFFF);
    *img_pixels = qRgba(
       (u1)(pixel & 255), (u1)((pixel >> 8) & 255),
       (u1)((pixel >> 16) & 255),
       (u1)(255 - ((pixel >> 24) & 255))
       );
    ++img_pixels;

    if(!info_string.isEmpty())
      info_string += QString(" %1").arg(thr_vec.second[vi], 16, 16, QChar('0'));

    ++vi;
   }
   if(!info_string.isEmpty())
     info_string += "\n";

//    qDebug() << "vi = " << vi;
  }
  if(!info_string.isEmpty())
    info_string += "\n";
 }

 if(!info_path.isEmpty())
   save_file(info_path, info_string);
}

   //xy2 tl = gtb.top_left();


QColor XCSD_Image::pixel_number_to_qcolor(n8 pixel)
{
 return QColor(pixel & 255, (pixel >> 8) & 255, (pixel >> 16) & 255,
   255 - ((pixel >> 24) & 255));
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
