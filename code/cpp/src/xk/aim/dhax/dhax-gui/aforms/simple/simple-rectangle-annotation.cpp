
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
  QRectF imn = image_rectf_.normalized();
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
      (r8) (iw / ih), // wh image
      (r8) (ih / iw), // hw image
      0, // width against image
      (r8) (sh / ih), // height against image
      0, 0, // perimeter and area against image
      {margins[0],margins[1],margins[2],margins[3],margins[4],margins[5],margins[6],margins[7]},
      {
       (r8) (margins[0] / (iw + 1)),
       (r8) (margins[1] / idiag),
       (r8) (margins[2] / (ih + 1)),
       (r8) (margins[3] / idiag),
       (r8) (margins[4] / (iw + 1)),
       (r8) (margins[5] / idiag),
       (r8) (margins[6] / (ih + 1)),
       (r8) (margins[7] / idiag)
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
      (r8) (iw / ih), // wh image
      (r8) (ih / iw), // hw image
      (r8) (sw / iw), // width against image
      0, // height against image
      0, 0, // perimeter and area against image
      {margins[0],margins[1],margins[2],margins[3],margins[4],margins[5],margins[6],margins[7]},
      {
       (r8) (margins[0] / (iw + 1)),
       (r8) (margins[1] / idiag),
       (r8) (margins[2] / (ih + 1)),
       (r8) (margins[3] / idiag),
       (r8) (margins[4] / (iw + 1)),
       (r8) (margins[5] / idiag),
       (r8) (margins[6] / (ih + 1)),
       (r8) (margins[7] / idiag)
      }
    };
  else
    measurements_ = new Measurements{
      sw, sh, (u2) (sw + sw + sh + sh), // perimeter
      iw, ih, (u2) (iw + iw + ih + ih), // image perimeter
      (u4) (sw * sh), // area
      (u4) (iw * ih), // image area
      (r8) (sw / sh), // wh
      (r8) (sh / sw), // hw
      (r8) (iw / ih), // wh image
      (r8) (ih / iw), // hw image
      (r8) (sw / iw), // width against image
      (r8) (sh / ih), // height against image
      0, 0, // area and perimeter against image
      {margins[0],margins[1],margins[2],margins[3],margins[4],margins[5],margins[6],margins[7]},
      {
       (r8) (margins[0] / (iw + 1)),
       (r8) (margins[1] / idiag),
       (r8) (margins[2] / (ih + 1)),
       (r8) (margins[3] / idiag),
       (r8) (margins[4] / (iw + 1)),
       (r8) (margins[5] / idiag),
       (r8) (margins[6] / (ih + 1)),
       (r8) (margins[7] / idiag)
      }
     };

  if(measurements_->image_perimeter > 0)
    measurements_->perimeter_against_image = measurements_->perimeter / measurements_->image_perimeter;

  if(measurements_->image_area > 0)
    measurements_->area_against_image = measurements_->area / measurements_->image_area;
 };

 return *measurements_;

}
