
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-2d/mat2d.h"

#include "xcsd-2d/mat2d.templates.h"

#include "xcsd-1d/vec1d.h"

#include "xcsd-2d/xcsd-image.h"

#include "xcsd-2d/xcsd-tierbox.h"

#include <QPixmap>
#include <QPainter>

#include <QGuiApplication>


USING_XCNS(XCSD)


int main(int argc , char **argv)
{
 QGuiApplication app(argc, argv);

// XCSD_Image_Geometry xcsg;
//xcsg.set_total_size(54, 108);
// xcsg.set_total_size(160, 90);

 // landscape
 // xcsg.set_total_size(304, 194);
 // xcsg.set_total_size(304 + 54, 194 + 54);
 // xcsg.set_total_size(284, 194);
 // xcsg.set_total_size(284 + 54, 194 + 54);
 // xcsg.set_total_size(304, 174);
 // xcsg.set_total_size(304 + 54, 174 + 54);
 // xcsg.set_total_size(284, 174);

 // portrait
 // xcsg.set_total_size(194, 304);
 // xcsg.set_total_size(194 + 54, 304 + 54);
 // xcsg.set_total_size(194, 284);
 // xcsg.set_total_size(194 + 54, 284 + 54);
 // xcsg.set_total_size(174, 304);
 // xcsg.set_total_size(174 + 54, 304 + 54);
 // xcsg.set_total_size(174, 284);

 // square
 // xcsg.set_total_size(194, 194);
 // xcsg.set_total_size(284, 284);
 // xcsg.set_total_size(304, 304);

 XCSD_Image xcsd;
 xcsd.load_image(ROOT_FOLDER "/../pics/angle.jpg");
 //xcsd.load_image(ROOT_FOLDER "/../pi/t1-30x30.png");
 xcsd.init_geometry();
 XCSD_Image_Geometry& xcsg = xcsd.geometry();

 xcsg.init_tier_counts(XCSD_Image_Geometry::TierGrid_Preferances::Minimize_Outer_Tiers);

// xcsg.draw_tier_summary(QString(ROOT_FOLDER "/../tiers/t%1x%2.png")
//     .arg(xcsg.total_size().width).arg(xcsg.total_size().height),
//   QString(ROOT_FOLDER "/../tiers/t%1x%2-seq.png")
//     .arg(xcsg.total_size().width).arg(xcsg.total_size().height),
//                        3.3, 8);


 xcsd.init_pixel_data();

 xcsd.save_full_tier_image(ROOT_FOLDER "/../tiers/ft1.png",
   ROOT_FOLDER "/../tiers/tk1");

// xcsg.draw_tier_summary(ROOT_FOLDER "/../tiers/t284x194.png", 2.5, 4);
// xcsg.draw_tier_summary(ROOT_FOLDER "/../tiers/t284x194.png", 2.5, 4);
// xcsg.draw_tier_summary(ROOT_FOLDER "/../tiers/t284x194.png", 2.5, 4);

 qDebug() << "full = " << xcsg.full_tier_counts();
 qDebug() << "overall = " << xcsg.overall_tier_counts();

 qDebug() << "outer h = " << xcsg.horizontal_outer_sizes();
 qDebug() << "outer v = " << xcsg.vertical_outer_sizes();

// TierBox_Location tbl = xcsg.get_tierbox_location_from_ground_position(80, 60);

// qDebug() << "tbl = " << tbl.rc();

// xcsg.calculate_tier_ring(tbl);

// qDebug() << "ring = " << tbl.tier_ring();

 return 0;
}


int main3(int argc , char **argv)
{
 //Mat2d<Vec1d<int>> mat;

// Box9x9_8bytepx* box = new Box9x9_8bytepx;

// return 0;

// QGuiApplication app(argc, argv);


 XCSD_Image xcsd;

 //xcsd.load_image(ROOT_FOLDER "/../pics/angle.jpg");
 xcsd.load_image(ROOT_FOLDER "/../pi/t1-30x30.png");

 //xcsd.image().setText("test", "result");
 // qDebug() << "image = " << xcsd.image().text();

// xcsd.init_tier_counts();
// xcsd.init_tierboxes();

 //rc2 rc = xcsd.get_tierbox_at_ground_position_RC2(4, 4);

 //qDebug() << "rc = " << rc;

// SDI_Position sdi = xcsd.get_sdi_at_ground_position(18, 19);

 //SDI_Position sdi = sdi_octal(4, 0111, 5, 0222);
 //SDI_Position sdi = sdi_octal(4'0111_sdi, 5'0222_sdi);
 SDI_Position sdi = 4'5'999_sd2;

 qDebug() << "sdi = " << sdi;

 xy1s m1 = sdi.get_mid1();
 xy1s m2 = sdi.get_mid2();
 xy1s gr = sdi.get_ground();

 qDebug() << "m1 = " << m1;
 qDebug() << "m2 = " << m2;
 qDebug() << "gr = " << gr;



// QVector<n8> pixels;
// xcsd.get_pixels()

 //XCSD_TierBox* trb = xcsd.get_tierbox_at_ground_position(4, 4);

// QImage& image = xcsd.image();

// u2 w = image.width();
// u2 h = image.height();

// qDebug() << "w = " << w / 27;
// qDebug() << "h = " << h / 27;

// u2 l0 = w % 27 / 2;
// u2 h0 = h % 27 / 2;

// qDebug() << "l0 = " << l0;
// qDebug() << "h0 = " << h0;



 return 0;
}



// // // // // // //




//QPixmap pixmap = QPixmap::fromImage(image);

//QPainter painter(&pixmap);

//painter.setPen(QColor::fromRgb(215, 255, 255));
//painter.setBrush(QColor::fromRgb(255, 255, 255));

//for(u2 x = l0; x < w; x += 27)
//{
// for(u2 y = 0; y < h; ++y)
// {
//  QRgb rgb = image.pixel(x, y);

//  u1 r = qRed(rgb);
//  u1 g = qGreen(rgb);
//  u1 b = qBlue(rgb);

//  r = qMin(r + 60, 255);
//  g = qMin(g + 60, 255);
//  b = qMin(b + 60, 255);

//  //QRgb rgb1 = QColor::fromRgb(255, g, b).rgb();

//  painter.setPen(QColor::fromRgb(r, g, b));

//  painter.drawPoint(x, y);

//  //painter.drawLine(0, y, w, y);
// }
// //painter.drawLine(x, 0, x, h);
//}

//for(u2 y = h0; y < h; y += 27)
//{
// for(u2 x = 0; x < w; ++x)
// {
//  //painter.drawLine(0, y, w, y);
//  QRgb rgb = image.pixel(x, y);

//  u1 r = qRed(rgb);
//  u1 g = qGreen(rgb);
//  u1 b = qBlue(rgb);

//  r = qMin(r + 60, 255);
//  g = qMin(g + 60, 255);
//  b = qMin(b + 60, 255);

//  //QRgb rgb1 = QColor::fromRgb(255, g, b).rgb();

//  painter.setPen(QColor::fromRgb(r, g, b));

//  painter.drawPoint(x, y);
// }
//}


//pixmap.save(ROOT_FOLDER "/../pics/angle.grid.png");

////  QPixmap pixmap = QPixmap::fromImage(image);
////  QPainter painter(&pixmap);





void show_255_palatte(QVector<QColor>& vec, QString path,
  QString sorted_path,
  u1 box_width,
  u1 padline_width)
{
 QPixmap pixmap(box_width * 30 + 20, box_width * 17);
 QPainter painter(&pixmap);

 u1 index = 0;

 bool needs_padline = false;

 painter.setPen(Qt::NoPen);

 QMap<QRgb, u1> positions;

 QMap<QRgb, QPoint> left_positions;

 painter.setBrush(QColor(255, 255, 255));
 painter.drawRect(0, 0, pixmap.width(), pixmap.height());

 for(u1 y = 0; y < 17; ++y)
 {
  u2 top = y * box_width;

  for(u1 x = 0; x < 15; ++x)
  {
   QColor c = vec[index];

   positions[c.rgb()] = index;

   if(y > 0)
   {
    if(y % 2)
      needs_padline = (x < 14);
    else
      needs_padline = (x > 0);
   }

   painter.setBrush(c);


   u2 left = x * box_width;

   QRect full_rect(left, top, box_width, box_width);
   left_positions[c.rgb()] = full_rect.center();

   if(needs_padline)
   {
    painter.drawRect(left, top + padline_width, box_width, box_width - padline_width);
//    painter.setBrush(QColor(255, 255, 255));
//    painter.drawRect(left, top, box_width, padline_width);
   }
   else
     painter.drawRect(left, top, box_width, box_width);

   ++index;
  }
 }

// pixmap.save(path);

 QVector<QColor> vec1 = vec;

 std::sort(vec1.begin(), vec1.end(), [](QColor lhs, QColor rhs)
 {
  return lhs.value() < rhs.value();
 });

// QPixmap pixmap1(box_width * 15, box_width * 17);
// QPainter painter1(&pixmap1);

 index = 0;

 u2 xoffset = box_width * 15 + 20;

 //bool needs_padline = false;

 //QMap<QColor, u1> positions;

 for(u1 y = 0; y < 17; ++y)
 {
  u2 top = y * box_width;

  for(u1 x = 0; x < 15; ++x)
  {
   QColor c = vec1[index];


   painter.setBrush(c);

   u2 left = x * box_width + xoffset;

//   if(needs_padline)
//   {
//    painter.drawRect(left, top + padline_width, box_width, box_width);
//    painter.setBrush(QColor(255, 255, 255));
//    painter.drawRect(left, top, box_width, padline_width);
//   }
//   else

   QRect full_rect(left, top, box_width, box_width);

   painter.setPen(Qt::NoPen);

   painter.drawRect(full_rect);

   QRgb rgb = c.rgb();
   QPoint qp = left_positions[rgb];

   u1 left_index = positions[rgb];

   left_index /= 17;

   QPen circle_pen = QPen(QColor(0, 0, 0));
   circle_pen.setWidth(2);

   painter.setPen(circle_pen);

   painter.setBrush(QColor(255, 255, 255));

   painter.drawEllipse(full_rect.center(), left_index, left_index);

   ++index;
  }
 }

// pixmap1.save(sorted_path);
 pixmap.save(path);


}

int main1(int argc , char **argv)
{
 //Mat2d<Vec1d<int>> mat;

 XCSD_Image xcsd;

 xcsd.load_image(ROOT_FOLDER "/../pics/p2.draw.bmp");

 QImage image = xcsd.image();

 u4 w = image.width();
 u4 h = image.height();

 QGuiApplication app(argc, argv);

 QPixmap pixmap = QPixmap::fromImage(image);

 QPainter painter(&pixmap);

 u2 shtop = 0;
 u2 shbot = 0;

 u2 shl = 0;
 u2 shr = 0;

 for(u4 x = 0; x < w; ++x)
 {
  for(u4 y = 0; y < h; ++y)
  {
   QRgb rgb = image.pixel(x, y);

   QRgb ref_rgb = QColor(153, 193, 241).rgb();
   QColor ref = QColor(153, 193, 241);

   QColor ic(rgb);

   s2 red = (s2)ic.red() - (s2)ref.red();
   s2 blue = (s2)ic.blue() - (s2)ref.blue();
   s2 green = (s2)ic.green() - (s2)ref.green();

   u1 r = qAbs(red);
   u1 g = qAbs(green);
   u1 b = qAbs(blue);

//   qDebug() << "red = " << r << " blue = " << b << " green = " << g;

   u1 offset = 1;



   if(r + b + g < 60)
   {
    if(x == 0)
    {
     if(shtop == 0)
       shtop = y;
     else if(shbot == 0)
       shbot = y;
    }
    else if(y == 0)
    {
     if(shl == 0)
       shl = x;
     else if(shr == 0)
       shr = x;
    }



    for(s1 j = -offset; j <= offset; ++j)
    {
     for(s1 k = -offset; k <= offset; ++k)
     {
      QRgb rgb = image.pixel(x + j, y + k);
      QColor c(rgb);
      double h = c.hsvHue();
      double s = c.hsvSaturation();
      double v = c.value();

//      if(v < 0.5) v += 0.5;
//      else v = 1;

      qDebug() << "v = " << v;

      v = 200;

      QColor c1 = QColor::fromHsv(h, s, v);
//      QColor c1 = c;

      qDebug() << "c = " << c << " c1 = " << c1;

      painter.setBrush(c1);
      painter.setPen(Qt::NoPen);

      painter.drawRect(x + j - 1, y + k - 1, 3, 3);
     }
    }

   }


//   u1 i = i255.pixelIndex(x, y);
//   ++indices[i].second;
  }

 }

 painter.setBrush(QColor(100, 200, 200, 200));

 qDebug() << "shl = " << shl;
 qDebug() << "shr = " << shr;

 qDebug() << "shtop = " << shtop;
 qDebug() << "shbot = " << shbot;

 painter.drawRect(shl, shtop, shr - shl, shbot - shtop);

 pixmap.save(ROOT_FOLDER "/../pics/p2.draw.proc.bmp");



}


int main2(int argc , char **argv)
{
 //Mat2d<Vec1d<int>> mat;

 XCSD_Image xcsd;

 xcsd.load_image(ROOT_FOLDER "/../pics/angle.jpg");

 xcsd.image().setText("test", "result");

 qDebug() << "image = " << xcsd.image().text();

 QVector<QColor> vec; //(255);

 xcsd.get_255_palatte(vec);

 QGuiApplication app(argc, argv);

 show_255_palatte(vec, ROOT_FOLDER "/../pics/angle.jpg.pal.png",
   ROOT_FOLDER "/../pics/angle.jpg.pals.png", 50, 8);
 //show_255_palatte(vec, "/home/nlevisrael/gits/ctg-temp/pics/test.png", 50, 8);




 return 0;
}
