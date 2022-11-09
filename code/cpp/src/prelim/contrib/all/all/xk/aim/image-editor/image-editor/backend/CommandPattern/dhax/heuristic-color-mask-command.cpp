
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "heuristic-color-mask-command.h"

#include "../../utils.h"

#include "global-types.h"

#include <QPainter>


Heuristic_Color_Mask_Command::Heuristic_Color_Mask_Command(Image& image,
  QColor foreground, QColor background, u1 offset, u1 metric_code)
 : image_(image), pixel_buffer_(image.getPixelBuffer()),
    foreground_(foreground), background_(background), offset_(offset),
    metric_code_(metric_code)
{
 backup_pixel_buffer_ = pixel_buffer_;
}

Heuristic_Color_Mask_Command::Heuristic_Color_Mask_Command(Image& image,
  QColor foreground, QColor background, u1 offset, QString metric_code)
 : image_(image), pixel_buffer_(image.getPixelBuffer()),
    foreground_(foreground), background_(background), offset_(offset),
    metric_code_(1)
{
 if(metric_code != "max")
 {
  // // TODO ...
   //   parse a different one ...
 }

}


void Heuristic_Color_Mask_Command::execute()
{
 proceed();
}

void Heuristic_Color_Mask_Command::undo()
{
 pixel_buffer_ = backup_pixel_buffer_;
}

void Heuristic_Color_Mask_Command::redo()
{
 execute();
}

u1 diff(u1 a1, u1 a2)
{
 return a1 > a2? a1 - a2 : a2 - a1;
}


bool test(u1 offset, u1 rdiff, u1 gdiff, u1 bdiff, Heuristic_Color_Mask_Command::Metric_Codes mc)
{
 switch (mc)
 {
 case Heuristic_Color_Mask_Command::Metric_Codes::Max_Difference:
   return rdiff <= offset && gdiff <= offset && bdiff <= offset;

 case Heuristic_Color_Mask_Command::Metric_Codes::Sum_Difference:
   return rdiff + gdiff + bdiff <= offset;

 case Heuristic_Color_Mask_Command::Metric_Codes::Vector_Difference:
   return rdiff * rdiff + gdiff * gdiff + bdiff * bdiff <= offset * offset;

 default: break;
 }

 return false;
}

void Heuristic_Color_Mask_Command::proceed()
{
 u2 w = image_.getW();
 u2 h = image_.getH();

 Metric_Codes mc = (Metric_Codes) metric_code_;

 proceed(pixel_buffer_, w, h, mc);

 if(Image::Reduction* ir = image_.reduction())
 {
  proceed(ir->buffer, ir->width, ir->height, mc);
 }
}

void Heuristic_Color_Mask_Command::proceed(std::vector<Pixel>& pixel_buffer,
  u2 w, u2 h, Metric_Codes mc)
{
 bool is_foreground;

 for(u2 y = 0; y < h; ++y)
 {
  for(u2 x = 0; x < w; ++x)
  {
   Pixel& px = pixel_buffer[y * w + x];
   if(mc == Metric_Codes::Exact_Match)
     is_foreground = foreground_ == Pixel::toQColor(px);
   else
   {
    u1 rdiff = diff(px.getR(), foreground_.red());
    u1 gdiff = diff(px.getG(), foreground_.green());
    u1 bdiff = diff(px.getB(), foreground_.blue());
    is_foreground = test(offset_, rdiff, gdiff, bdiff, mc);
   }
   if(is_foreground)
     px = Pixel::fromQColor(foreground_);
   else
     px = Pixel::fromQColor(background_);
  }
 }
}
