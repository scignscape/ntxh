
#include "simple-rectangle-annotation.h"

#include <QPainter>

#include <QDebug>

#include <QWheelEvent>

#include "global-types.h"


Simple_Rectangle_Annotation::Simple_Rectangle_Annotation(DHAX_Mouse_Interaction_Data& mouse_interaction_data,
   const QPointF& sc, QWidget* p)
 : Simple_Annotation_Base(mouse_interaction_data, sc, p), measurements_(nullptr)
{
 scaffold_.setTopLeft(sc);
 scaffold_.setBottomRight(sc);
}

u2 _diag(QRectF& r)
{
 return (u2) (((r.width() * r.width()) + (r.height() * r.height())) / 2);
}

Simple_Rectangle_Annotation::Measurements& Simple_Rectangle_Annotation::get_measurements()
{
 if(!measurements_)
 {
  QRectF imn = containing_image_->rect().normalized();
  QRectF tl = imn, tr = imn, bl = imn, br = imn;

  QRectF sn = scaffold_.normalized();
  u2 idiag = _diag(imn) + 1;

  u2 sw = sn.width();
  u2 sh = sn.height();
  u2 iw = imn.width();
  if(iw < sw) iw = sw;
  u2 ih = imn.height();
  if(ih < sh) ih = sh;

  tl.setBottomRight(sn.topLeft());
  tr.setBottomLeft(sn.topRight());
  bl.setTopRight(sn.bottomLeft());
  br.setTopLeft(sn.bottomRight());

  u2 margins [8] {
    (u2) tl.width(),  // left
    _diag(tl), // tl
    (u2) tl.height(),  // top
    _diag(tr), // tr
    (u2) tr.width(),  // right
    _diag(br), // br
    (u2) bl.height(),  // bottom
    _diag(bl), // bl
  };

  if(sw == 0)
    measurements_ = new Measurements{
      sw, sh, (u2) (sh + sh), // perimeter
      iw, ih, (u2) (iw + iw + ih + ih), // image perimeter
      0, // area
      (u4) (iw * ih), // image area
      0, // wh
      0, // hw
      ((r8) iw / ih), // wh image
      ((r8) ih / iw), // hw image
      0, // width against image
      ((r8) sh / ih), // height against image
      0, 0, // perimeter and area against image
      {margins[0],margins[1],margins[2],margins[3],margins[4],margins[5],margins[6],margins[7]},
      {
       ((r8) margins[0] / (iw + 1)),
       ((r8) margins[1] / idiag),
       ((r8) margins[2] / (ih + 1)),
       ((r8) margins[3] / idiag),
       ((r8) margins[4] / (iw + 1)),
       ((r8) margins[5] / idiag),
       ((r8) margins[6] / (ih + 1)),
       ((r8) margins[7] / idiag)
      }
    };
    //measurements_->margins = margins;
  else if(sh == 0)
    measurements_ = new Measurements{
      sw, sh, (u2) (sw + sw), // perimeter
      iw, ih, (u2) (iw + iw + ih + ih), // image perimeter
      0, // area
      (u4) (iw * ih), // image area
      0, // wh
      0, // hw
      ((r8) iw / ih), // wh image
      ((r8) ih / iw), // hw image
      ((r8) sw / iw), // width against image
      0, // height against image
      0, 0, // perimeter and area against image
      {margins[0],margins[1],margins[2],margins[3],margins[4],margins[5],margins[6],margins[7]},
      {
       ((r8) margins[0] / (iw + 1)),
       ((r8) margins[1] / idiag),
       ((r8) margins[2] / (ih + 1)),
       ((r8) margins[3] / idiag),
       ((r8) margins[4] / (iw + 1)),
       ((r8) margins[5] / idiag),
       ((r8) margins[6] / (ih + 1)),
       ((r8) margins[7] / idiag)
      }
    };
  else
    measurements_ = new Measurements{
      sw, sh, (u2) (sw + sw + sh + sh), // perimeter
      iw, ih, (u2) (iw + iw + ih + ih), // image perimeter
      (u4) (sw * sh), // area
      (u4) (iw * ih), // image area
      ((r8) sw / sh), // wh
      ((r8) sh / sw), // hw
      ((r8) iw / ih), // wh image
      ((r8) ih / iw), // hw image
      ((r8) sw / iw), // width against image
      ((r8) sh / ih), // height against image
      0, 0, // area and perimeter against image
      {margins[0],margins[1],margins[2],margins[3],margins[4],margins[5],margins[6],margins[7]},
      {
       ((r8) margins[0] / (iw + 1)),
       ((r8) margins[1] / idiag),
       ((r8) margins[2] / (ih + 1)),
       ((r8) margins[3] / idiag),
       ((r8) margins[4] / (iw + 1)),
       ((r8) margins[5] / idiag),
       ((r8) margins[6] / (ih + 1)),
       ((r8) margins[7] / idiag)
      }
     };

  if(measurements_->image_perimeter > 0)
    measurements_->perimeter_against_image = (r8) measurements_->perimeter / measurements_->image_perimeter;

  if(measurements_->image_area > 0)
    measurements_->area_against_image = (r8) measurements_->area / measurements_->image_area;
 };

 return *measurements_;
}

QRectF Simple_Rectangle_Annotation::against_image_coords()
{
 Simple_Rectangle_Annotation::Measurements& ms = get_measurements();
 return {ms.margins_against_image[Directions::Left], ms.margins_against_image[Directions::Top],
   ms.width_against_image, ms.height_against_image};
}

template<typename COUNTS_Type, typename INDICES_Type, typename RET_Type = u1>
RET_Type _maxes_averaged(COUNTS_Type& counts, INDICES_Type& indices)
{
 auto it = std::max_element(counts.begin(), counts.end());
 while (it != counts.end())
 {
  indices.push_back(std::distance(counts.begin(), it));
  it = std::find(std::next(it), counts.end(), *it);
 }

 RET_Type count = indices.size();
 if(count == 0)
   return 0;
 if(count == 1)
   return indices[0];
 n8 result = std::accumulate(indices.begin(), indices.end(), 0);
 return (RET_Type) result / count;
}

QColor Simple_Rectangle_Annotation::get_color_mean()
{
 //QVector<int> MainWindow::get_mean_rgb_for_img(const QImage img){

 QRectF ai = against_image_coords();

 u2 x1 = ai.topLeft().x() * containing_image_->width();
 u2 y1 = ai.topLeft().y() * containing_image_->height();

 u2 x2 = ai.bottomRight().x() * containing_image_->width();
 u2 y2 = ai.bottomRight().y() * containing_image_->height();

 QRgb* image_line;

 QVector<u4> red_counts(256);
 QVector<u4> green_counts(256);
 QVector<u4> blue_counts(256);

 for(u2 y = y1 ; y < y2 ; ++y)
 {
  image_line = (QRgb *) containing_image_->scanLine(y);
  for(u2 x = x1; x < x2 ; ++x)
  {
   ++red_counts[qRed(image_line[x])];
   ++green_counts[qGreen(image_line[x])];
   ++blue_counts[qBlue(image_line[x])];
  }
 }

 QVector<u1> maxes;
// auto it = std::max_element(red_counts.begin(), red_counts.end());
// while (it != red_counts.end())
// {
//  maxes.push_back(std::distance(red_counts.begin(), it));
//  it = std::find(std::next(it), red_counts.end(), *it);
// }


 u1 red_mean = _maxes_averaged(red_counts, maxes);
 u1 green_mean = _maxes_averaged(green_counts, maxes);
 u1 blue_mean = _maxes_averaged(blue_counts, maxes);

 return QColor(red_mean, green_mean, blue_mean);
}
