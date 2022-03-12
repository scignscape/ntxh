
#include "xcsd-image.h"

USING_XCNS(XCSD)

XCSD_Image::XCSD_Image()
{

}

void XCSD_Image::load_image(QString path)
{
 image_.load(path);
}

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
