
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

//?

// //   this include should come first
 //     to not conflict with "_flags" ...
#include "stats/dhax-stat-assessment.h"


#include "dhax-application-controller.h"

#include "image-viewer/image-document-controller.h"
#include "main-window/dhax-main-window-controller.h"

#include "stats/stat-test-image.h"


#include <QVector2D>

#include <QtMath>


u1 angle_distance(pr2 angles)
{
 u2 gap = angles.inner_positive_difference();

 if(gap > 360)
 {
  // // perhaps a warning?
  gap %= 360;
 }

 if(gap > 180)
   return 360 - gap;

 return gap;
}

struct SV_Centered_Vector
{
 QVector2D qvector;

 SV_Centered_Vector& disk_protrude();

 r8 angle_against_positive_verical() const;
 r8 angle_against_pure_color() const;
 r8 angle_against_nearest_diagonal() const;

 r4 x() const { return qvector.x(); }
 r4 y() const { return qvector.y(); }

 r4 x_abs() const { return qAbs(qvector.x()); }
 r4 y_abs() const { return qAbs(qvector.y()); }

 s1 x_sign() const { return x() < 0 ? -1 : x() > 0? 1 : 0; }
 s1 y_sign() const { return y() < 0 ? -1 : y() > 0? 1 : 0; }

 r4 raw_euclidean_distance(const SV_Centered_Vector& scv) const;

 u1 get_binned_sv_angle() const;

 u1 get_5_10_20_bin() const;

 r4 get_length_protruded() const;

};

r4 SV_Centered_Vector::raw_euclidean_distance(const SV_Centered_Vector& scv) const
{
 return qvector.distanceToPoint(scv.qvector);
}


r8 SV_Centered_Vector::angle_against_positive_verical() const
{
 if(y() > 0)
 {
  r8 radians = qAtan(x() / y());
  return qRadiansToDegrees(radians);
 }
 if(y() < 0)
 {
  r8 radians = qAtan(x() / y_abs());
  return qRadiansToDegrees(radians) + 90;
 }
 return 90 * x_sign();
}


r8 SV_Centered_Vector::angle_against_pure_color() const
{
 r8 angle = angle_against_positive_verical();
 if(angle < -60)
   return angle + 240;
 return qAbs(angle - 120);
}


r8 SV_Centered_Vector::angle_against_nearest_diagonal() const
{
 // //  return values in range 0 - 60
 r8 angle = qAbs(angle_against_positive_verical());
 if(angle < 60)
   return angle;
 return qAbs(angle - 120);
}

r4 SV_Centered_Vector::get_length_protruded() const
{
 r8 stretch, angle = angle_against_nearest_diagonal();
 if(angle == 0)
   stretch = 1;
 else
   stretch = 120 / angle;
 return qvector.length() * stretch;
}

SV_Centered_Vector& SV_Centered_Vector::disk_protrude()
{
 r8 angle = angle_against_nearest_diagonal();
 if(angle > 0)
   //qvector *= ((120 / angle));
   //?
   qvector *= (1 + (angle / 120));
 return *this;
}

#include "global-macros.h"

#define _CASE_MACRO_2(a1, a2)  case a1: case a2:
#define _CASE_MACRO_3(a1, a2, a3)  _CASE_MACRO_2(a1, a2) case a3:
#define _CASE_MACRO_4(a1, a2, a3, a4)  _CASE_MACRO_3(a1, a2, a3) case a4:
#define _CASE_MACRO_5(a1, a2, a3, a4, a5)  _CASE_MACRO_4(a1, a2, a3, a4) case a5:
#define _CASE_MACRO_6(a1, a2, a3, a4, a5, a6)  _CASE_MACRO_5(a1, a2, a3, a4, a5) case a6:
#define _CASE_MACRO_7(a1, a2, a3, a4, a5, a6, a7)  _CASE_MACRO_6(a1, a2, a3, a4, a5, a6) case a7:
#define _CASE_MACRO_8(a1, a2, a3, a4, a5, a6, a7, a8)  _CASE_MACRO_7(a1, a2, a3, a4, a5, a6, a7) case a8:
#define _CASE_MACRO_9(a1, a2, a3, a4, a5, a6, a7, a8, a9) \
  _CASE_MACRO_8(a1, a2, a3, a4, a5, a6, a7, a8) case a9:


#define _CASE_MACRO_(...) _preproc_CONCAT(_CASE_MACRO_, _preproc_NUM_ARGS (__VA_ARGS__)) (__VA_ARGS__)

u1 SV_Centered_Vector::get_binned_sv_angle() const
{
 u1 base = (u1) angle_against_pure_color();
 switch (base)
 {
 _CASE_MACRO_(0, 1) return 0;
 _CASE_MACRO_(2, 3, 4) return 1;
 _CASE_MACRO_(5, 6, 7) return 2;
 _CASE_MACRO_(8, 9, 10, 11) return 3;
 _CASE_MACRO_(12, 13, 14, 15, 16) return 4;
 _CASE_MACRO_(17, 18, 19, 20, 21, 22) return 5;
 _CASE_MACRO_(23, 24, 25, 26, 27, 28, 29) return 6;
 _CASE_MACRO_(30, 31, 32, 33, 34, 35, 36, 37) return 7;
 _CASE_MACRO_(38, 39, 40, 41, 42, 43, 44, 45, 46) return 8;
 default: break;
 }

 if(base < 107)
 {
  if(base < 57) // 47 - 56  (10)
    return 9;

  if(base < 68) // 57 - 67  (11)
    return 10;

  if(base < 80) // 68 - 79  (12)
    return 11;

  if(base < 93)  // 80 - 92  (13)
    return 12;

  return 13; // 93 - 106  (14)
 }


 if(base < 122) // 107 - 121  (15)
   return 14;

 if(base < 138) // 122 - 137  (16)
   return 15;

 if(base < 153) // 138 - 152  (15)
   return 17;

 if(base < 167) // 153 - 166  (14)
   return 18;

 return 19; // 167 - 180
}

u1 SV_Centered_Vector::get_5_10_20_bin() const
{
 u1 sv_bin = get_binned_sv_angle();
 r4 len = get_length_protruded();

 if(len < 60)
   return 30 + (sv_bin / 4);
 if(len < 120)
   return 20 + (sv_bin / 2);
 return sv_bin;
}


SV_Centered_Vector& get_sv_centered_coordinates(SV_Centered_Vector& scv, u1 s, u1 v)
{
 // //  center on v = 170, s = 127.5
 s1 v_altitude = 170 - v;
 //?r8 s_ratio = v == 0 ? 0 : (255 - (s * 2)) / (255 - v);

 //? r8 s_ratio =  (127.5 - s) / 255;
 r4 s_ratio =  1 - (s / 127.5);
 r4 s_altitude =  s_ratio * (v / 2);

 scv = { {s_altitude, (float) v_altitude} };
 //QVector2D sv_vector_n = sv_vector.normalized();

 return scv;
}

u1 raw_hue_distance(u2 ch, u2 h)
{
 // //  result range 0 - 180
 u1 result = qAbs(ch - h);
 if(result > 180)
   result = 360 - result;
 return result;
}

r8 blue_yellow_factor(u2 hue, r8 factor = 12)
{
 if( (hue > 30) && (hue < 210) )
   return qAbs(hue - 120) / (18 * factor);
 if(hue < 30)
   hue += 360;
 return qAbs(hue - 300) / (18 * factor);
}

r8 blue_yellow_factor_average(u2 ch, u2 h, r8 factor = 12)
{
 return (blue_yellow_factor(h, factor) + blue_yellow_factor(ch, factor)) / 2;
}


//r8 red_green_factor(u2 hue, r8 factor = 6)
//{
// if( (hue > 30) && (hue < 210) )
//   return qAbs(hue - 120) / (18 * factor);
// if(hue < 30)
//   hue += 360;
// return qAbs(hue - 300) / (18 * factor);
//}


u1 adjusted_hue_distance(u1 ch, u1 h)
{
 u1 diff = raw_hue_distance(ch, h);

 return diff + (diff * blue_yellow_factor_average(ch, h));
}

r8 merged_distance(u1 h_distance, u1 sv_distance, const QPair<r4, r4>& weights)
{
 return (((r4) h_distance) * weights.first) + (((r4) sv_distance) * weights.second);
}


//?u1 binned_sv_color(const QColor& color)

//u1 binned_sv_color(const SV_Centered_Vector sv& sv)
//{

//}


SV_Centered_Vector get_sv_centered_vector(const QColor& color)
{
 int h, s, v;
 color.getHsv(&h, &s, &v);
 SV_Centered_Vector result;
 get_sv_centered_coordinates(result, s, v);
 return result;
}



u1 hsv_color_distance(const QColor& center_color, const QColor& color)
{
 int ch, cs, cv, h, s, v;

 center_color.getHsv(&ch, &cs, &cv);
 color.getHsv(&h, &s, &v);

 //u1 hgap = angle_distance(pr2{(u2)ch, (u2)h});

 // 2(255-s) - (y - 127.5) / r5
 // 510 - 2s -
 // (637.5 - y - 2s) / r5

 SV_Centered_Vector sv, csv;

 get_sv_centered_coordinates(csv, cs, cv).disk_protrude();
 get_sv_centered_coordinates(sv, s,  v).disk_protrude();

 u1 h_distance = adjusted_hue_distance(ch, h);

 u1 sv_distance = csv.raw_euclidean_distance(sv);

 static QPair<r4, r4> rel_weights(2./3, 1./3);

 r8 md = merged_distance(h_distance, sv_distance, rel_weights);

 return (u1) md;

// sv1s csv { (s1)(127 - cs), (s1)(127 - cv) };
// sv1s sv { (s1)(127 - s), (s1)(127 - v) };


}

u1 hsv_color_distance(QRgb center_pixel, QRgb pixel)
{
 return hsv_color_distance(QColor(center_pixel), QColor(pixel));
}

//QColor normalize_rgb


void DHAX_Application_Controller::toroid_run_stats()
{
 DHAX_Stat_Assessment::run_demo_test(DHAX_STAT_FOLDER "/test", "i1", "png");
}


QString DHAX_Application_Controller::show_pixel_local_aggregate_color_distance()
{
 Image_Document_Controller* idc = main_window_controller_->image_document_controller();
 if(!idc)
   return {};

 // QString fp = idc->current_file_path();

 return pixel_local_aggregate_color_distance(idc->current_file_path());
}


QString DHAX_Application_Controller::test_pixel_local_aggregate_color_distance()
{
 QDir qd(DHAX_STAT_FOLDER "/test-dist");
 QStringList images = qd.entryList(QDir::Files | QDir::Readable);

 qDebug() << images;

 QString likely_file = *std::min_element(images.begin(), images.end(),
   [] (const QString& s1, const QString& s2)
 {
  return s1.length() < s2.length();
 });

 likely_file = qd.absoluteFilePath(likely_file);

 qDebug() << "Calculating color distance for " << likely_file;

 XCSD_Image* xcsd = new XCSD_Image;
 xcsd->load_image(likely_file);

 xcsd->autoset_fb_poles();

 return pixel_local_aggregate_color_distance(likely_file);
}


QString DHAX_Application_Controller::pixel_local_aggregate_color_distance(
  QString file_path, XCSD_Image* xcsd)
{
 Stat_Test_Image stat_image(file_path);

 static u1 corner_weights[3][3]
 {
  {3, 1, 1},
  {1, 3, 2},
  {1, 2, 3},
 };

 static u1 center_weights[3][3]
 {
  {1, 2, 1},
  {1, 3, 1},
  {1, 3, 1},
 };

 static u2 corner_weights_total = 0;
 if(corner_weights_total == 0)
 {
  for(u1 a = 0; a < 3; ++a)
   for(u1 b = 0; b < 3; ++b)
     corner_weights_total += corner_weights[a][b];
 }

 static u2 center_weights_total = 0;
 if(center_weights_total == 0)
 {
  for(u1 a = 0; a < 3; ++a)
   for(u1 b = 0; b < 3; ++b)
     center_weights_total += center_weights[a][b];
 }

// QString fp = idc->current_file_path();

 QImage image(file_path);

 QString result_3 = stat_image.file_path_with_presuffix("gray-3-dist");
 QString result_5 = stat_image.file_path_with_presuffix("gray-5-dist");
 QString result = stat_image.file_path_with_presuffix("gray-7-dist");

 QString result_7rgb = stat_image.file_path_with_presuffix("gray-7rgb-dist");

 QString result_8b = stat_image.file_path_with_presuffix("8b");
 QString result_8b_125_cyan = stat_image.file_path_with_presuffix("8b-125-cyan");
 QString result_8b_175_cyan = stat_image.file_path_with_presuffix("8b-175-cyan");
 QString result_8b_225_cyan = stat_image.file_path_with_presuffix("8b-225-cyan");

 wh2 wh = { (u2) image.width(), (u2) image.height()};
 wh2 wh_3 = wh - 3;

 QImage gray_3_image(wh.width, wh.height, QImage::Format_Grayscale8);
 QImage gray_5_image(wh.width, wh.height, QImage::Format_Grayscale8);
 QImage gray_7_image(wh.width, wh.height, QImage::Format_Grayscale8);

 QImage gray_7rgb_image(wh.width, wh.height, QImage::Format_RGB32);

 //?QImage cyan_8b_image(wh.width, wh.height, QImage::Format_RGB32);

 QImage cyan_8b_225_image(wh.width, wh.height, QImage::Format_RGB32);
 QImage cyan_8b_175_image(wh.width, wh.height, QImage::Format_RGB32);
 QImage cyan_8b_125_image(wh.width, wh.height, QImage::Format_RGB32);

 gray_3_image.fill(0);
 gray_5_image.fill(0);
 gray_7_image.fill(0);
 gray_7rgb_image.fill(0);

//? gray_image.save(result);

//? return {};

//? rc2 rc {0, 0};

 //?u1* gray_pixel = gray_image.bits();

 //?QMap<pr1, u4> bin_counts_5_10_20;
 std::map<pr1, pr4> bin_counts_5_10_20;

 static QRgb cyan = QColor(Qt::cyan).rgb();

 for(u2 r = 0; r < wh.height; ++r)
 {
  s1 r_offset_min, r_offset_max, c_offset_min, c_offset_max;

  if(r < 3)
    r_offset_min = -r;
  else
    r_offset_min = -3;

  if(r > wh_3.height)
    r_offset_max = r - wh_3.height;
  else
   r_offset_max = 3;


//?  QRgb* line = (QRgb*) image.scanLine(rc.r);
  QRgb* line = (QRgb*) image.scanLine(r);

//  u1* gray_3_line =  (u1*) gray_3_image.scanLine(rc.r);
//  u1* gray_5_line =  (u1*) gray_5_image.scanLine(rc.r);
//  u1* gray_7_line =  (u1*) gray_7_image.scanLine(rc.r);

//  QRgb* gray_3_line =  (QRgb*) gray_3_image.scanLine(rc.r);
//  QRgb* gray_5_line =  (QRgb*) gray_5_image.scanLine(rc.r);
//  QRgb* gray_7_line =  (QRgb*) gray_7_image.scanLine(rc.r);

  u1* gray_3_line = (u1*) gray_3_image.scanLine(r);
  u1* gray_5_line = (u1*) gray_5_image.scanLine(r);
  u1* gray_7_line = (u1*) gray_7_image.scanLine(r);
  QRgb* gray_7rgb_line = (QRgb*) gray_7rgb_image.scanLine(r);

  QRgb* cyan_8b_225_line = (QRgb*) cyan_8b_225_image.scanLine(r);
  QRgb* cyan_8b_175_line = (QRgb*) cyan_8b_175_image.scanLine(r);
  QRgb* cyan_8b_125_line = (QRgb*) cyan_8b_125_image.scanLine(r);


  for(u2 c = 0; c < wh.width; ++c)
  {
   if(c < 3)
     c_offset_min = -c;
   else
     c_offset_min = -3;

   if(c > wh_3.width)
     c_offset_max = c - wh_3.width;
   else
    c_offset_max = 3;


//?   QRgb& center_pixel = line[rc.c];
   QRgb& center_pixel = line[c];

   u2 total3 = 0, total5 = 0, total7 = 0;

   for(s1 r_offset = r_offset_min; r_offset <= r_offset_max; ++r_offset)
   {
//    QRgb* rline = (QRgb*) image.scanLine(rc.r + r_offset);
    QRgb* rline = (QRgb*) image.scanLine(r + r_offset);

    for(s1 c_offset = c_offset_min; c_offset <= c_offset_max; ++c_offset)
    {
     if(r_offset == 0 && c_offset == 0)
       continue;

     u1 r_offset_abs = qAbs(r_offset);
     u1 c_offset_abs = qAbs(c_offset);

//?     QRgb& pixel = rline[rc.c + c_offset];
     QRgb& pixel = rline[c + c_offset];

     u1 dist = hsv_color_distance(center_pixel, pixel);

     total7 += (u2) dist;

     if( (r_offset_abs < 3) && (c_offset_abs < 3) )
       total5 += (u2) dist;

     if( (r_offset_abs < 2) && (c_offset_abs < 2) )
       total3 += (u2) dist;

    }
   }

   u1 gray7 = total7 / 48, gray5 = total5 / 24, gray3 = total3 / 8;



//   *gray_pixel = gray;

//   n8 gp = (n8) gray_pixel;

  //? QRgb rr7 = QColor(gray7, gray7, gray7).rgb();

   gray7 = 255 - gray7;
   gray5 = 255 - gray5;
   gray3 = 255 - gray3;

   QColor center_color = QColor::fromRgb(center_pixel);
   QColor gray7rgb = QColor::fromHsv(center_color.hsvHue(), 255 - gray7, gray7);

   //QColor normed = normalize_rgb(center_color);

   if(gray7 > 125)
   {
    SV_Centered_Vector scv = get_sv_centered_vector(center_color).disk_protrude();
    u1 bin = scv.get_5_10_20_bin();
    u1 h = center_color.hsvHue() / 12;

    auto it = bin_counts_5_10_20.find({h, bin});
    if(it == bin_counts_5_10_20.end())
      bin_counts_5_10_20[{h, bin}] = {1, center_color.rgb()};
    else
      ++bin_counts_5_10_20[{h, bin}].first;

    cyan_8b_125_line[c] = center_pixel;

    if(gray7 > 175)
    {
     cyan_8b_175_line[c] = center_pixel;
     if(gray7 > 225)
       cyan_8b_225_line[c] = center_pixel;
     else
       cyan_8b_225_line[c] = cyan;
    }
    else
    {
     cyan_8b_175_line[c] = cyan;
     cyan_8b_225_line[c] = cyan;
    }
   }

   else
   {
    cyan_8b_225_line[c] = cyan;
    cyan_8b_175_line[c] = cyan;
    cyan_8b_125_line[c] = cyan;
   }


//   QRgb rr7 = QColor(gray7, gray7, gray7).rgb();
//   QRgb rr5 = QColor(gray5, gray5, gray5).rgb();
//   QRgb rr3 = QColor(gray3, gray3, gray3).rgb();
//   QRgb rr73 = QColor(gray73, gray73, gray73).rgb();

//
   gray_7_line[c] = gray7;
   gray_5_line[c] = gray5;
   gray_3_line[c] = gray3;

   gray_7rgb_line[c] = gray7rgb.rgb();

//   gray_7_image.setPixel(rc.c - 3, rc.r - 3, rr7);
//   gray_5_image.setPixel(rc.c - 3, rc.r - 3, rr5);
//   gray_3_image.setPixel(rc.c - 3, rc.r - 3, rr3);


//   gray_73_image.setPixel(rc.c - 3, rc.r - 3, rr73);

//   gray_test_image.setPixel(rc.c - 3, rc.r - 3, rr);

//   //gray_image.setPixel(rc.c - 3, rc.r - 3, rr);

//   uchar& gg = gline[rc.c - 3];
//   gg = gray;

//?
//   gray_7_line[rc.c - 3] = gray7;
//   gray_5_line[rc.c - 3] = gray5;
//   gray_3_line[rc.c - 3] = gray3;

   //++gray_pixel;
//??   ++rc.c;
  }
//??  ++rc.r;
//??  rc.c = 3;
 }

 QMap<pr1, QColor> most_common;

 QVector<QRgb> i8b_color_table;

 i8b_color_table.push_back(cyan);

 u2 most_common_count = 0;

 while(most_common_count < 255)
 {
  if(bin_counts_5_10_20.empty())
    break;
  auto pr = std::max_element
  (
      std::begin(bin_counts_5_10_20), std::end(bin_counts_5_10_20),
      [] (const auto& p1, const auto& p2)
      {
          return p1.second < p2.second;
      }
  );
  most_common[pr->first] = QColor::fromRgb(pr->second.second);
  i8b_color_table.push_back(pr->second.second);
  ++most_common_count;
  bin_counts_5_10_20.erase(pr);
 }

 QImage i8b = image.convertToFormat(QImage::Format_Indexed8,
   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);


 QImage p8b_125 = cyan_8b_125_image.convertToFormat(QImage::Format_Indexed8,
   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);

 QImage p8b_175 = cyan_8b_175_image.convertToFormat(QImage::Format_Indexed8,
   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);

 QImage p8b_225 = cyan_8b_225_image.convertToFormat(QImage::Format_Indexed8,
   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);


// (wh.width, wh.height, QImage::Format_Indexed8);
// i8b.setColorTable(i8b_color_table);

// i8b.convertToFormat()


 qDebug() << "saving " << result << " ...";

 gray_7_image.save(result);
 gray_5_image.save(result_5);
 gray_3_image.save(result_3);
 gray_7rgb_image.save(result_7rgb);

 i8b.save(result_8b);
 p8b_125.save(result_8b_125_cyan);
 p8b_175.save(result_8b_175_cyan);
 p8b_225.save(result_8b_225_cyan);

 qDebug() << "ok";

 return result;
}



#ifdef HIDE

QString DHAX_Application_Controller::pixel_local_aggregate_color_distance(QString file_path)
{
 Stat_Test_Image stat_image(file_path);

 static u1 corner_weights[3][3]
 {
  {3, 1, 1},
  {1, 3, 2},
  {1, 2, 3},
 };

 static u1 center_weights[3][3]
 {
  {1, 2, 1},
  {1, 3, 1},
  {1, 3, 1},
 };

 static u2 corner_weights_total = 0;
 if(corner_weights_total == 0)
 {
  for(u1 a = 0; a < 3; ++a)
   for(u1 b = 0; b < 3; ++b)
     corner_weights_total += corner_weights[a][b];
 }

 static u2 center_weights_total = 0;
 if(center_weights_total == 0)
 {
  for(u1 a = 0; a < 3; ++a)
   for(u1 b = 0; b < 3; ++b)
     center_weights_total += center_weights[a][b];
 }

 QImage image(file_path);

 if(image.isNull())
   return {};

 QString result = stat_image.file_path_with_presuffix("gray-7-dist");
 QString result_7rgb = stat_image.file_path_with_presuffix("gray-7rgb-dist");

 wh2 wh = { (u2) image.width(), (u2) image.height()};
 wh -= 6;

 QImage gray_7_image(wh.width, wh.height, QImage::Format_Grayscale8);

 QImage gray_7rgb_image(wh.width, wh.height, QImage::Format_RGB32);

 gray_7_image.fill(0);
 gray_7rgb_image.fill(0);

 rc2 rc {3, 3};

 std::map<pr1, pr4> bin_counts_5_10_20;

 static QRgb cyan = QColor(Qt::cyan).rgb();

 for(u2 r = 0; r < wh.height; ++r)
 {
  QRgb* line = (QRgb*) image.scanLine(rc.r);

  u1* gray_7_line = (u1*) gray_7_image.scanLine(r);
  QRgb* gray_7rgb_line = (QRgb*) gray_7rgb_image.scanLine(r);

  for(u2 c = 0; c < wh.width; ++c)
  {
   QRgb& center_pixel = line[rc.c];

   u2//? total3 = 9, total5 = 9,
     total7 = 0;

   for(s1 r_offset = -3; r_offset <= 3; ++r_offset)
   {
    QRgb* rline = (QRgb*) image.scanLine(rc.r + r_offset);

    for(s1 c_offset = -3; c_offset <= 3; ++c_offset)
    {
     if(r_offset == 0 && c_offset == 0)
       continue;

     u1 r_offset_abs = qAbs(r_offset);
     u1 c_offset_abs = qAbs(c_offset);

     QRgb& pixel = rline[rc.c + c_offset];

     u1 dist = hsv_color_distance(center_pixel, pixel);

     total7 += (u2) dist;

//     if( (r_offset_abs < 3) && (c_offset_abs < 3) )
//       total5 += (u2) dist;

//     if( (r_offset_abs < 2) && (c_offset_abs < 2) )
//        total3 += (u2) dist;

    }
   }

   u1 gray7 = total7 / 48; //, gray5 = total5 / 24, gray3 = total3 / 8;
   //u1 gray73 = qAbs(gray7 - gray3);




//   *gray_pixel = gray;

//   n8 gp = (n8) gray_pixel;

  //? QRgb rr7 = QColor(gray7, gray7, gray7).rgb();

   gray7 = 255 - gray7;
//   gray5 = 255 - gray5;
//   gray3 = 255 - gray3;
//   gray73 = 255 - gray73;

   QColor center_color = QColor::fromRgb(center_pixel);
   QColor gray7rgb = QColor::fromHsv(center_color.hsvHue(), 255 - gray7, gray7);

   if(gray7 > 125)
   {
    SV_Centered_Vector scv = get_sv_centered_vector(center_color).disk_protrude();
    u1 bin = scv.get_5_10_20_bin();
    u1 h = center_color.hsvHue() / 12;

    auto it = bin_counts_5_10_20.find({h, bin});
    if(it == bin_counts_5_10_20.end())
      bin_counts_5_10_20[{h, bin}] = {1, center_color.rgb()};
    else
      ++bin_counts_5_10_20[{h, bin}].first;

//    cyan_8b_125_line[c] = center_pixel;
//    if(gray7 > 175)
//    {
//     cyan_8b_175_line[c] = center_pixel;
//     if(gray7 > 225)
//       cyan_8b_225_line[c] = center_pixel;
//     else
//       cyan_8b_225_line[c] = cyan;
//    }
//    else
//    {
//     cyan_8b_175_line[c] = cyan;
//     cyan_8b_225_line[c] = cyan;
//    }
   }

//   else
//   {
//    cyan_8b_225_line[c] = cyan;
//    cyan_8b_175_line[c] = cyan;
//    cyan_8b_125_line[c] = cyan;
//   }


//
   gray_7_line[c] = gray7;

   gray_7rgb_line[c] = gray7rgb.rgb();

//   gray_7_image.setPixel(rc.c - 3, rc.r - 3, rr7);
//   gray_5_image.setPixel(rc.c - 3, rc.r - 3, rr5);
//   gray_3_image.setPixel(rc.c - 3, rc.r - 3, rr3);


//   gray_73_image.setPixel(rc.c - 3, rc.r - 3, rr73);

//   gray_test_image.setPixel(rc.c - 3, rc.r - 3, rr);

//   //gray_image.setPixel(rc.c - 3, rc.r - 3, rr);

//   uchar& gg = gline[rc.c - 3];
//   gg = gray;

//?
//   gray_7_line[rc.c - 3] = gray7;
//   gray_5_line[rc.c - 3] = gray5;
//   gray_3_line[rc.c - 3] = gray3;

   //++gray_pixel;
   ++rc.c;
  }
  ++rc.r;
  rc.c = 3;
 }

#ifdef HIDE
 QMap<pr1, QColor> most_common;

 QVector<QRgb> i8b_color_table;

 i8b_color_table.push_back(cyan);

 u2 most_common_count = 0;

 while(most_common_count < 255)
 {
  if(bin_counts_5_10_20.empty())
    break;
  auto pr = std::max_element
  (
      std::begin(bin_counts_5_10_20), std::end(bin_counts_5_10_20),
      [] (const auto& p1, const auto& p2)
      {
          return p1.second < p2.second;
      }
  );
  most_common[pr->first] = QColor::fromRgb(pr->second.second);
  i8b_color_table.push_back(pr->second.second);
  ++most_common_count;
  bin_counts_5_10_20.erase(pr);
 }

// QImage i8b = image.convertToFormat(QImage::Format_Indexed8,
//   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);

// QImage p8b_125 = cyan_8b_125_image.convertToFormat(QImage::Format_Indexed8,
//   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);
// QImage p8b_175 = cyan_8b_175_image.convertToFormat(QImage::Format_Indexed8,
//   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);
// QImage p8b_225 = cyan_8b_225_image.convertToFormat(QImage::Format_Indexed8,
//   i8b_color_table, Qt::ThresholdDither|Qt::AutoColor);


// (wh.width, wh.height, QImage::Format_Indexed8);
// i8b.setColorTable(i8b_color_table);

// i8b.convertToFormat()

#endif

 qDebug() << "saving " << result << " ...";

 gray_7_image.save(result);
 gray_7rgb_image.save(result_7rgb);

// i8b.save(result_8b);
// p8b_125.save(result_8b_125_cyan);
// p8b_175.save(result_8b_175_cyan);
// p8b_225.save(result_8b_225_cyan);

 qDebug() << "ok";

 return result;
}

#endif



