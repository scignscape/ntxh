
#include "extend-mod-3-command.h"
#include "../../utils.h"

#include "global-types.h"

#include <QPair>


Extend_Mod_3_Command::Extend_Mod_3_Command(Image& image)
 : image_(image), pixel_buffer_(image.getPixelBuffer())
{
 backup_pixel_buffer_ = pixel_buffer_;
}

void Extend_Mod_3_Command::execute()
{
 proceed();
}

void Extend_Mod_3_Command::undo() {
 pixel_buffer_ = backup_pixel_buffer_;
}

void Extend_Mod_3_Command::redo() {
 execute();
}

void Extend_Mod_3_Command::proceed()
{
 proceed(image_, pixel_buffer_);
}

void Extend_Mod_3_Command::proceed(Image& image, std::vector<Pixel>& pixel_buffer)
{
 u2 new_h, new_w;
 proceed(image.getW(), image.getH(), pixel_buffer, new_w, new_h);
 if(new_h)
   image.setH(new_h);
 if(new_w)
   image.setW(new_w);
}

void Extend_Mod_3_Command::proceed(u2 w, u2 h, std::vector<Pixel>& pixel_buffer, u2& setW, u2& setH)
{

 u1 wm = (3 - w % 3) % 3;
 u1 hm = (3 - h % 3) % 3;

 u4 original_size = pixel_buffer.size();

 //QPair<u1, u1> pr {wm, hm};

 //u1 sw = wm * 3 + hm;

 switch(wm * 3 + hm)
 {
 default:
 case 0:  // //  nothing to do
  return;

 case 1:  // //  0, 1
  setH = h + 1;
  pixel_buffer.resize(original_size + w);
  for(u2 x = 0; x < w; ++x)
  {
   pixel_buffer[((u4)w * h) + x] = pixel_buffer[((u4)w * (h - 1)) + x];
  }
  return;

 case 2:  // //  0, 2
  setH = h + 2;
  pixel_buffer.resize(original_size + (w * 2));
  for(s2 y = h; y >= 0; --y)
  {
   std::copy(pixel_buffer.begin() + (y * w), pixel_buffer.begin() + (y * w) + w, pixel_buffer.begin() + (y * w) + w);
  }
  ++h;
  for(u2 x = 0; x < w; ++x)
  {
   pixel_buffer[x] = pixel_buffer[x + w];
   pixel_buffer[((u4)w * h) + x] = pixel_buffer[((u4)w * (h - 1)) + x];
  }
  return;

 case 3:  // //  1, 0
  setW = w + 1;
  pixel_buffer.reserve(original_size + h);
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc - 1]);
  }
  return;

 case 4:  // //  1, 1
  setW = w + 1;
  setH = h + 1;
  pixel_buffer.reserve(original_size + h + w + 1);
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc - 1] );
  }
  ++w;
  for(u2 x = 0; x < w; ++x)
  {
   pixel_buffer.push_back(pixel_buffer[((u4)(h - 1) * w) + x]); //(w + 1) * (h + 1)) + x - 1] = Pixel(200, 0, 0, 255);
  }
  return;

 case 5:  // //  1, 2
  setW = w + 1;
  setH = h + 2;
  //  width first
  pixel_buffer.reserve(original_size + w);
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc - 1] );
  }
  ++w;
  // //  size() reflects new insertions ...
  pixel_buffer.resize(pixel_buffer.size() + (w * 2));
  for(s2 y = h; y >= 0; --y)
  {
   std::copy(pixel_buffer.begin() + (y * w), pixel_buffer.begin() + (y * w) + w, pixel_buffer.begin() + (y * w) + w);
  }
  ++h;
  for(u2 x = 0; x < w; ++x)
  {
   pixel_buffer[x] = pixel_buffer[x + w];
   pixel_buffer[((u4)w * h) + x] = pixel_buffer[((u4)w * (h - 1)) + x];
  }
  return;

 case 6:  // //  2, 0
  setW = w + 2;
  pixel_buffer.reserve(original_size + w + 2);
  for(u2 y = 0, acc = 0; y < h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc] );
  }
  ++w;
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc - 1] );
  }
  return;

 case 7:  // //  2, 1
  setW = w + 2;
  setH = h + 1;
  pixel_buffer.reserve(original_size + h + w + h + 2);
  for(u2 y = 0, acc = 0; y < h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc] );
  }
  ++w;
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc - 1] );
  }
  ++w;
  for(u2 x = 0; x < w; ++x)
  {
   pixel_buffer.push_back(pixel_buffer[((u4)(h - 1) * w) + x]); //(w + 1) * (h + 1)) + x - 1] = Pixel(200, 0, 0, 255);
  }
  return;

 case 8:  // //  2, 2
  setW = w + 2;
  setH = h + 2;
  //  width first
  pixel_buffer.reserve(original_size + w + 2);
  for(u2 y = 0, acc = 0; y < h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc] );
  }
  ++w;
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixel_buffer.insert(pixel_buffer.begin() + (y * w) + acc,
                      pixel_buffer[((u4)y * w) + acc - 1] );
  }
  ++w;
  // //  size() reflects new insertions ...
  pixel_buffer.resize(pixel_buffer.size() + (w * 2));

  for(s2 y = h; y >= 0; --y)
  {
   std::copy(pixel_buffer.begin() + (y * w), pixel_buffer.begin() + (y * w) + w, pixel_buffer.begin() + (y * w) + w);
  }
  ++h;
  for(u2 x = 0; x < w; ++x)
  {
   pixel_buffer[x] = pixel_buffer[x + w];
   pixel_buffer[((u4)w * h) + x] = pixel_buffer[((u4)w * (h - 1)) + x];
  }
  return;
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
