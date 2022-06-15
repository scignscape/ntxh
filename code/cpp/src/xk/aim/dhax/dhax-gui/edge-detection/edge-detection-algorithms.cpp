#include <QtWidgets>
#include <cmath>
#include <utility>
#include <queue>

#include "global-types.h"

#include "edge-detection-kernels.h"


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


QImage convolution(const auto& kernel, const QImage& image, u1 blur_factor)
{
 int kw = kernel[0].size(), kh = kernel.size(),
   offsetx = kw / 2, offsety = kw / 2;
 QImage out(image.size(), image.format());
 float sum;

 quint8 *line;
 const quint8 *lookup_line;

 u1 start, end_offset, incr;
 if(blur_factor == 0)
 { start = 0; end_offset = 0, incr = 1; }
 else
 { start = 1; end_offset = 1, incr = 3; }

 for (int y = start; y < image.height() - end_offset; y += incr)
 {
  line = out.scanLine(y);
  for (int x = start; x < image.width() - end_offset; x += incr)
  {
   sum = 0;

   for (int j = 0; j < kh; j++)
   {
    if (y + j < offsety || y + j >= image.height())
      continue;
    lookup_line = image.constScanLine(y + j - offsety);
    for (int i = 0; i < kw; i++)
    {
     if (x + i < offsetx || x + i >= image.width())
       continue;
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


QImage canny(const QImage& input, float sigma, float tmin, float tmax, u1 blur_factor)
{
 QImage res = convolution(gaussian_kernel(sigma), input, blur_factor), // Gaussian blur
   // Gradients
   gx = convolution(sobelx, res, blur_factor),
   gy = convolution(sobely, res, blur_factor);

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


QImage sobel(const QImage& input, u1 blur_factor)
{
 QImage res(input.size(), input.format());
 magnitude(res, convolution(sobelx, input, blur_factor), convolution(sobely, input, blur_factor));
 return res;
}


QImage prewitt(const QImage& input, u1 blur_factor)
{
 QImage res(input.size(), input.format());
 magnitude(res, convolution(prewittx, input, blur_factor), convolution(prewitty, input, blur_factor));
 return res;
}

QImage roberts(const QImage& input, u1 blur_factor)
{
 QImage res(input.size(), input.format());
 magnitude(res, convolution(robertsx, input, blur_factor), convolution(robertsy, input, blur_factor));
 return res;
}


QImage scharr(const QImage& input, u1 blur_factor)
{
 QImage res(input.size(), input.format());
 magnitude(res, convolution(scharrx, input, blur_factor), convolution(scharry, input, blur_factor));
 return res;
}
