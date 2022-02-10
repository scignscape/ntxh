

#include "simple-calculate-command.h"

#include "../../utils.h"

#include "global-types.h"

#include <QPainter>

#include <QMessageBox>


Simple_Calculate_Command::Simple_Calculate_Command(Image& image,
  QColor foreground, QColor new_foreground, QColor background,
  u2 reduction_scale, QList<int> threshold)
 : image_(image), pixel_buffer_(image.getPixelBuffer()),
    foreground_(foreground), new_foreground_(new_foreground), background_(background),
    reduction_scale_(reduction_scale),
    length_threshold_(threshold[0]), minor_threshold_(threshold[1]),
    major_threshold_(threshold[2]), length_count_(0)
{
 backup_pixel_buffer_ = pixel_buffer_;
}

void Simple_Calculate_Command::execute()
{
 proceed();
}

void Simple_Calculate_Command::undo()
{
 pixel_buffer_ = backup_pixel_buffer_;
}

void Simple_Calculate_Command::redo()
{
 execute();
}

void Simple_Calculate_Command::proceed()
{
 std::vector<Pixel> result;
 if(Image::Reduction* ir = image_.reduction())
 {
  proceed(*ir, result);

  u4 w = image_.getW();
  u4 h = image_.getH();

  s2 ww = w / reduction_scale_;
  s2 hh = h / reduction_scale_;

  for(u4 y = 0; y < h; ++y)
  {
   for(u4 x = 0; x < w; ++x)
   {
    s2 xx = x / reduction_scale_;
    s2 yy = y / reduction_scale_;
    pixel_buffer_[y * w + x] = result[yy * ww + xx];
   }
  }

  static QString msg = "Total Foreground Length: %1, or %2% of width and %3% of height";

  QMessageBox::information(nullptr, "Length and/or area calculations",
     msg.arg(length_count_).arg(QString::number(((r8)length_count_/ww)*100, 'f', 2))
       .arg(QString::number(((r8)length_count_/hh)*100, 'f', 2)));

 }
}

void Simple_Calculate_Command::proceed(Image::Reduction& ir, std::vector<Pixel>& result)
{
 std::vector<Pixel>& buffer = ir.buffer;
 result.resize(buffer.size());

 s2 w = ir.width;
 s2 h = ir.height;

 QVector<u2> rows(buffer.size());
 QVector<u2> cols(buffer.size());

 u1 lline_count = 0;
 u1 rline_count = 0;

 u1 tline_count = 0;
 u1 bline_count = 0;


 for(s2 y = 0; y < h; ++y)
 {
  for(s2 x = 0; x < w; ++x)
  {
   s4 lindex = y * w + x;
   s4 rindex = y * w + w - (x + 1);
   Pixel lpx = buffer[lindex];
   Pixel rpx = buffer[rindex];
   u2 lcolor_sum = lpx.get_color_sum();
   u2 rcolor_sum = rpx.get_color_sum();
   if(lcolor_sum == 0)
     lline_count = 0;
   else
     ++lline_count;
   if(rcolor_sum == 0)
     rline_count = 0;
   else
     ++rline_count;
   rows[lindex] += lline_count;
   rows[rindex] += rline_count;
  }
  lline_count = 0;
  rline_count = 0;
 }


 for(s2 x = 0; x < w; ++x)
 {
  for(s2 y = 0; y < h; ++y)
  {
   s4 tindex = y * w + x;
   s4 bindex = (h - (y + 1)) * w + x;
   Pixel tpx = buffer[tindex];
   Pixel bpx = buffer[bindex];
   u2 tcolor_sum = tpx.get_color_sum();
   u2 bcolor_sum = bpx.get_color_sum();
   if(tcolor_sum == 0)
     tline_count = 0;
   else
     ++tline_count;
   if(bcolor_sum == 0)
     bline_count = 0;
   else
     ++bline_count;
   cols[tindex] += tline_count;
   cols[bindex] += bline_count;
  }
  tline_count = 0;
  bline_count = 0;
 }

 for(s2 y = 0; y < h; ++y)
 {
  for(s2 x = 0; x < w; ++x)
  {
   s4 index = y * w + x;
   if((rows[index] > length_threshold_) || (cols[index] > length_threshold_))
   {
    ++length_count_;
    result[index] = Pixel::fromQColor(new_foreground_);
   }
   else result[index] = Pixel::fromQColor(background_);
  }
 }
}
