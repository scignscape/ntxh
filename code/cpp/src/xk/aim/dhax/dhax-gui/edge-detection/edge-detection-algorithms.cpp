#include <QtWidgets>
#include <cmath>
#include <utility>
#include <queue>

#include "global-types.h"

#include "edge-detection-kernels.h"

#include "xcsd-2d/xcsd-image.h"


using namespace std;


matrix<float, 5, 5> gaussian_kernel(float sigma)
{
 matrix<float, 5, 5> gauss;
 float sum = 0, s = 2 * sigma * sigma;

 for (int x = -2; x <= 2; x++)
  for (int y = -2; y <= 2; y++)
   sum += (gauss[x + 2][y + 2] = exp(-(x * x + y * y) / s) / s / M_PI);

 for (auto& row : gauss)
  for (auto& x : row)
   x /= sum;

 return gauss;
}


void magnitude(QImage& input, const QImage& gx, const QImage& gy)
{
 quint8 *line;
 const quint8 *gx_line, *gy_line;

 for (int y = 0; y < input.height(); y++) {
  line = input.scanLine(y);
  gx_line = gx.constScanLine(y);
  gy_line = gy.constScanLine(y);

  for (int x = 0; x < input.width(); x++)
    line[x] = qBound(0x00, static_cast<int>(hypot(gx_line[x], gy_line[x])), 0xFF);
 }
}


QImage convolution(const auto& kernel, const QImage& image,
  QImage::Format out_format, u1 blur_factor,
  QPair<QColor, QColor>* poles) // QImage::Format_Grayscale8)
{
 int kw = kernel[0].size(), kh = kernel.size(),
   offsetx = kw / 2, offsety = kw / 2;
 QImage out (image.size(), out_format); //image.format());

 out.fill(Qt::black);

 float sum;

 quint8* line;
 const quint8* lookup_line;
 const QRgb* rgb_lookup_line;

 u1 start, end_offset, incr;
 if(blur_factor == 0)
 { start = 0; end_offset = 0, incr = 1; }
 else
 { start = 1; end_offset = 1, incr = 3; }

 //u1 byte_length_factor = poles? 3 : 1;

 for (int y = start; y < image.height() - end_offset; y += incr)
 {
  line = out.scanLine(y);
  for (int x = start; x < (image.width() - end_offset); x += incr)
  {
   sum = 0;

   for (int j = 0; j < kh; j++)
   {
    if (y + j < offsety || y + j >= image.height())
      continue;

    lookup_line = image.constScanLine(y + j - offsety);
    rgb_lookup_line = (QRgb*) lookup_line;

    for (int i = 0; i < kw; i++)
    {
     if (x + i < offsetx || x + i >= image.width())
       continue;
     if(poles)
     {
      QRgb rgb = rgb_lookup_line[x + i - offsetx];

//      QColor clr = QColor::fromRgb(rgb);

//      qDebug() << "clr = " << clr;

//      prr1 fprr = XCSD_Image::rgb888_qcolor_distance(rgb, poles->first);
//      prr1 bprr = XCSD_Image::rgb888_qcolor_distance(rgb, poles->second);

      prr1 fprr = XCSD_Image::rgb888_qcolor_distance(rgb, poles->first);
      prr1 bprr = XCSD_Image::rgb888_qcolor_distance(rgb, poles->second);

      fb1 fb = XCSD_Image::collapse_fb_distances(fprr, bprr);

      u1 unit = fb.inner_ratio_to_unit(255);
      sum += kernel[j][i] * unit;
     }
     else
       sum += kernel[j][i] * lookup_line[x + i - offsetx];
    }
   }

   line[x] = qBound(0x00, static_cast<int>(sum), 0xFF);
  }
 }

 return out;
}


QImage hysteresis(const QImage& image, float tmin, float tmax)
{
 auto res = QImage(image.size(), image.format());
 res.fill(0x00);

 const quint8 *original_line;
 quint8 *result_line;
 int ni, nj;
 queue<pair<int, int>> edges;

 for (int y = 1; y < res.height() - 1; y++) {
  original_line = image.constScanLine(y);
  result_line = res.scanLine(y);

  for (int x = 1; x < res.width() - 1; x++) {
   if (original_line[x] >= tmax && result_line[x] == 0x00) {
    result_line[x] = 0xFF;
    edges.push(make_pair(x, y));

    while (!edges.empty()) {
     auto point = edges.front();
     edges.pop();

     for (int j = -1; j <= 1; j++) {
      nj = point.second + j;
      if (nj < 0 || nj >= image.height())
       continue;

      original_line = image.constScanLine(nj);
      result_line = res.scanLine(nj);

      for (int i = -1; i <= 1; i++) {
       if (!i && !j)
        continue;

       ni = point.first + i;
       if (ni < 0 || ni >= image.width())
        continue;

       if (original_line[ni] >= tmin && result_line[ni] == 0x00) {
        result_line[ni] = 0xFF;
        edges.push(make_pair(ni, nj));
       }
      }
     }
    }
   }
  }
 }

 return res;
}


QImage canny(const QImage& input, float sigma,
  float tmin, float tmax, QImage::Format out_format, u1 blur_factor, QPair<QColor, QColor>* poles)
{
 QImage res = convolution(gaussian_kernel(sigma), input, out_format, 0, poles), //, poles), // Gaussian blur
     // Gradients
   gx = convolution(sobelx, res, out_format, blur_factor, nullptr),
   gy = convolution(sobely, res, out_format, blur_factor, nullptr);

 magnitude(res, gx, gy);

 // Non-maximum suppression
 quint8 *line;
 const quint8 *prev_line, *next_line, *gx_line, *gy_line;

 for (int y = 1; y < res.height() - 1; y++)
 {
  line = res.scanLine(y);
  prev_line = res.constScanLine(y - 1);
  next_line = res.constScanLine(y + 1);
  gx_line = gx.constScanLine(y);
  gy_line = gy.constScanLine(y);

  for (int x = 1; x < res.width() - 1; x++)
  {
   double at = atan2(gy_line[x], gx_line[x]);
   const double dir = fmod(at + M_PI, M_PI) / M_PI * 8;

   if ((1 >= dir || dir > 7) && line[x - 1] < line[x] && line[x + 1] < line[x] ||
       (1 < dir || dir <= 3) && prev_line[x - 1] < line[x] && next_line[x + 1] < line[x] ||
       (3 < dir || dir <= 5) && prev_line[x] < line[x] && next_line[x] < line[x] ||
       (5 < dir || dir <= 7) && prev_line[x + 1] < line[x] && next_line[x - 1] < line[x])
    continue;

   line[x] = 0x00;
  }
 }

 // Hysteresis
 return hysteresis(res, tmin, tmax);
}


QImage sobel(const QImage& input, QImage::Format out_format, u1 blur_factor, QPair<QColor, QColor>* poles)
{
 QImage res(input.size(), out_format);
 magnitude(res, convolution(sobelx, input, out_format,
   blur_factor, poles), convolution(sobely, input, out_format, blur_factor, poles));
 return res;
}


QImage prewitt(const QImage& input, QImage::Format out_format, u1 blur_factor, QPair<QColor, QColor>* poles)
{
 QImage res(input.size(), out_format);
 magnitude(res, convolution(prewittx, input, out_format,
   blur_factor, poles), convolution(prewitty, input, out_format, blur_factor, poles));
 return res;
}

QImage roberts(const QImage& input, QImage::Format out_format, u1 blur_factor, QPair<QColor, QColor>* poles)
{
 QImage res(input.size(), out_format);
 magnitude(res, convolution(robertsx, input, out_format,
   blur_factor, poles), convolution(robertsy, input, out_format, blur_factor, poles));
 return res;
}


QImage scharr(const QImage& input, QImage::Format out_format, u1 blur_factor, QPair<QColor, QColor>* poles)
{
 QImage res(input.size(), out_format);
 magnitude(res, convolution(scharrx, input, out_format,
   blur_factor, poles), convolution(scharry, input, out_format, blur_factor, poles));
 return res;
}
