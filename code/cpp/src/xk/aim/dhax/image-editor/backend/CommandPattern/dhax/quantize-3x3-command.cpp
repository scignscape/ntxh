
#include "quantize-3x3-command.h"
#include "../../utils.h"

#include "extend-mod-3-command.h"

#include "global-types.h"

#include <QPair>

#include <QString>
#include <QDebug>


Quantize_3x3_Command::Quantize_3x3_Command(Image& image, u1 range)
 : image_(image), sample_compress_height_(0), sample_compress_width_(0),
    pixel_buffer_(image.getPixelBuffer()), range_(range)
{
 backup_pixel_buffer_ = pixel_buffer_;
}

void Quantize_3x3_Command::execute()
{
 proceed(range_);
}

void Quantize_3x3_Command::undo()
{
 pixel_buffer_ = backup_pixel_buffer_;
}

void Quantize_3x3_Command::redo()
{
 execute();
}


// //  x and y are the top-left corner of the box
Pixel _average(std::vector<Pixel>& pixel_buffer, u1 range, u2 x, u2 y, u2 w)
{
 u2 rsq = (u2) range * range;
 u2 sum_r = 0, sum_g = 0, sum_b = 0, sum_a = 0;

 auto get_r = [](u2 sum, Pixel& p) { return sum + p.getR(); };
 auto get_g = [](u2 sum, Pixel& p) { return sum + p.getG(); };
 auto get_b = [](u2 sum, Pixel& p) { return sum + p.getB(); };
 auto get_a = [](u2 sum, Pixel& p) { return sum + p.getA(); };

 u4 start = y * w + x;
 for(u1 i = 0; i < 3; ++i)
 {
  sum_r += std::accumulate(pixel_buffer.begin() + start, pixel_buffer.begin() + start + range, 0, get_r);
  sum_g += std::accumulate(pixel_buffer.begin() + start, pixel_buffer.begin() + start + range, 0, get_g);
  sum_b += std::accumulate(pixel_buffer.begin() + start, pixel_buffer.begin() + start + range, 0, get_b);
  sum_a += std::accumulate(pixel_buffer.begin() + start, pixel_buffer.begin() + start + range, 0, get_a);
  start += w;
 }
 return Pixel(sum_r / rsq, sum_g / rsq, sum_b / rsq, sum_a / rsq);
}


void Quantize_3x3_Command::reset_sample_compress_pixel_buffer(std::vector<Pixel>& pixel_buffer,
  u2 pre_compress_width, u2 pre_compress_height)
{
 pixel_buffer.reserve(pre_compress_width * pre_compress_height);
}

void Quantize_3x3_Command::reset_sample_compress_pixel_buffer(u2 pre_compress_width, u2 pre_compress_height)
{
 sample_compress_width_ = pre_compress_width / 3;
 sample_compress_height_ = pre_compress_height / 3;
 sample_compress_pixel_buffer_.reserve(sample_compress_width_ * sample_compress_height_);
}

void Quantize_3x3_Command::proceed(u1 range)
{
 Extend_Mod_3_Command::proceed(image_, pixel_buffer_);

 u2 w = image_.getW();
 u2 h = image_.getH();

 reset_sample_compress_pixel_buffer(w, h);

 proceed(w, h, pixel_buffer_, sample_compress_pixel_buffer_, range);
}

void Quantize_3x3_Command::proceed(u2 w, u2 h,
  std::vector<Pixel>& pixel_buffer, std::vector<Pixel>& sample_compress_pixel_buffer, u1 range)
{

 u1 half = range / 2;

 for(u2 y = 1; y < h; y += range)
 {
  for(u2 x = 1; x < w; x += range)
  {
   Pixel avg = _average(pixel_buffer, range, x - half, y - half, w);
   sample_compress_pixel_buffer.push_back(avg);
   for(u2 yy = y - half; yy <= y + half; ++yy)
   {
    for(u2 xx = x - half; xx <= x + half; ++xx)
    {
//     qDebug() << QString("avg index=%7 x=%1 y=%2: %3, %4, %5, %6").arg(xx).arg(yy)
//                 .arg(avg.getR()).arg(avg.getG()).arg(avg.getB()).arg(avg.getA()).arg(yy * w + xx);

      pixel_buffer[(u4)yy * w + xx] = avg;
    }
   }
  }
 }

// pixel_buffer = sample_compress_pixel_buffer_;
// image_.setW(scw);
// image_.setH(sch);


 // u4 original_size = pixel_buffer_.size();
}


void Quantize_3x3_Command::re_extend(std::vector<Pixel>& source,
   std::vector<Pixel>& target,
   u2 source_width, u2 source_height, u1 factor)
{
 // //  assume for now factor is odd
 u1 sq = factor * factor;
 target.resize(source_width * source_height * sq);
 u1 mid = (factor - 1) / 2;
 u1 half = factor / 2;

// u2 sw = source_width * factor;
// u2 sh = source_height * factor;

 for(u2 ys = 0, yt = mid; ys < source_height; ++ys, yt += factor)
 {
  for(u2 xs = 0, xt = mid; xs < source_width; ++xs, xt += factor)
  {
   Pixel src = source[((u4)ys * source_width) + xs];
   for(u2 yy = yt - half; yy <= yt + half; ++yy)
   {
    for(u2 xx = xt - half; xx <= xt + half; ++xx)
    {
//     qDebug() << QString("avg index=%7 x=%1 y=%2: %3, %4, %5, %6").arg(xx).arg(yy)
//                 .arg(src.getR()).arg(src.getG()).arg(src.getB()).arg(src.getA()).arg(yy * w + xx);

      target[(u4)yy * source_width * factor + xx] = src;
    }
   }
  }
 }


}


// double normalizedValue = truncate_m100_100(value) * 2.55;
// for (int i = 0; i < image.getSize(); i++)
// {
//  pixel_buffer_[i].setPixel(pixel_buffer_[i].getR() + normalizedValue,
//                          pixel_buffer_[i].getG() + normalizedValue,
//                          pixel_buffer_[i].getB() + normalizedValue,
//                          pixel_buffer_[i].getA());
// }
// }
