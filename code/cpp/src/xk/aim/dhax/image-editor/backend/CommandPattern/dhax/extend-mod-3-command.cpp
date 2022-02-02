
#include "extend-mod-3-command.h"
#include "../../utils.h"

#include "global-types.h"

#include <QPair>


Extend_Mod_3_Command::Extend_Mod_3_Command(Image &image)
 : image(image), pixelBuffer(image.getPixelBuffer())
{
 backupPixelBuffer = pixelBuffer;
}

void Extend_Mod_3_Command::execute()
{
 proceed();
}

void Extend_Mod_3_Command::undo() {
 pixelBuffer = backupPixelBuffer;
}

void Extend_Mod_3_Command::redo() {
 execute();
}

void Extend_Mod_3_Command::proceed()
{
 u1 wm = (3 - image.getW() % 3) % 3;
 u1 hm = (3 - image.getH() % 3) % 3;

 u2 w = image.getW();
 u2 h = image.getH();

 u4 original_size = pixelBuffer.size();

 //QPair<u1, u1> pr {wm, hm};

 //u1 sw = wm * 3 + hm;

 switch(wm * 3 + hm)
 {
 default:
 case 0:  // //  nothing to do
  return;

 case 1:  // //  0, 1
  image.setH(h + 1);
  pixelBuffer.resize(original_size + w);
  for(u2 x = 0; x < w; ++x)
  {
   pixelBuffer[(w * h) + x] = pixelBuffer[(w * (h - 1)) + x];
  }
  return;

 case 2:  // //  0, 2
  image.setH(h + 2);
  pixelBuffer.resize(original_size + (w * 2));
  for(s2 y = h; y >= 0; --y)
  {
   std::copy(pixelBuffer.begin() + (y * w), pixelBuffer.begin() + (y * w) + w, pixelBuffer.begin() + (y * w) + w);
  }
  ++h;
  for(u2 x = 0; x < w; ++x)
  {
   pixelBuffer[x] = pixelBuffer[x + w];
   pixelBuffer[(w * h) + x] = pixelBuffer[(w * (h - 1)) + x];
  }
  return;

 case 3:  // //  1, 0
  image.setW(w + 1);
  pixelBuffer.reserve(original_size + h);
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc - 1]);
  }
  return;

 case 4:  // //  1, 1
  image.setW(w + 1);
  image.setH(h + 1);
  pixelBuffer.reserve(original_size + h + w + 1);
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc - 1] );
  }
  ++w;
  for(u2 x = 0; x < w; ++x)
  {
   pixelBuffer.push_back(pixelBuffer[((h - 1) * w) + x]); //(w + 1) * (h + 1)) + x - 1] = Pixel(200, 0, 0, 255);
  }
  return;

 case 5:  // //  1, 2
  image.setW(w + 1);
  image.setH(h + 2);
  //  width first
  pixelBuffer.reserve(original_size + w);
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc - 1] );
  }
  ++w;
  // //  size() reflects new insertions ...
  pixelBuffer.resize(pixelBuffer.size() + (w * 2));
  for(s2 y = h; y >= 0; --y)
  {
   std::copy(pixelBuffer.begin() + (y * w), pixelBuffer.begin() + (y * w) + w, pixelBuffer.begin() + (y * w) + w);
  }
  ++h;
  for(u2 x = 0; x < w; ++x)
  {
   pixelBuffer[x] = pixelBuffer[x + w];
   pixelBuffer[(w * h) + x] = pixelBuffer[(w * (h - 1)) + x];
  }
  return;

 case 6:  // //  2, 0
  image.setW(w + 2);
  pixelBuffer.reserve(original_size + w + 2);
  for(u2 y = 0, acc = 0; y < h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc] );
  }
  ++w;
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc - 1] );
  }
  return;

 case 7:  // //  2, 1
  image.setW(w + 2);
  image.setH(h + 1);
  pixelBuffer.reserve(original_size + h + w + h + 2);
  for(u2 y = 0, acc = 0; y < h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc] );
  }
  ++w;
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc - 1] );
  }
  ++w;
  for(u2 x = 0; x < w; ++x)
  {
   pixelBuffer.push_back(pixelBuffer[((h - 1) * w) + x]); //(w + 1) * (h + 1)) + x - 1] = Pixel(200, 0, 0, 255);
  }
  return;

 case 8:  // //  2, 2
  image.setW(w + 2);
  image.setH(h + 2);
  //  width first
  pixelBuffer.reserve(original_size + w + 2);
  for(u2 y = 0, acc = 0; y < h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc] );
  }
  ++w;
  for(u2 y = 1, acc = 0; y <= h; ++y, ++acc)
  {
   pixelBuffer.insert(pixelBuffer.begin() + (y * w) + acc,
                      pixelBuffer[(y * w) + acc - 1] );
  }
  ++w;
  // //  size() reflects new insertions ...
  pixelBuffer.resize(pixelBuffer.size() + (w * 2));

  for(s2 y = h; y >= 0; --y)
  {
   std::copy(pixelBuffer.begin() + (y * w), pixelBuffer.begin() + (y * w) + w, pixelBuffer.begin() + (y * w) + w);
  }
  ++h;
  for(u2 x = 0; x < w; ++x)
  {
   pixelBuffer[x] = pixelBuffer[x + w];
   pixelBuffer[(w * h) + x] = pixelBuffer[(w * (h - 1)) + x];
  }
  return;
 }
}

// double normalizedValue = truncate_m100_100(value) * 2.55;
// for (int i = 0; i < image.getSize(); i++)
// {
//  pixelBuffer[i].setPixel(pixelBuffer[i].getR() + normalizedValue,
//                          pixelBuffer[i].getG() + normalizedValue,
//                          pixelBuffer[i].getB() + normalizedValue,
//                          pixelBuffer[i].getA());
// }
// }
