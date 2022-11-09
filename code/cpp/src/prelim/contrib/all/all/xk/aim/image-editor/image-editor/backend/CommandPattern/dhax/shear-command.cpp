
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "shear-command.h"
#include "../../utils.h"

#include "global-types.h"

#include <QPainter>
#include <QMessageBox>


Shear_Command::Shear_Command(Image& image, r8 x_shear, r8 x_shear_c, r8 y_shear, r8 y_shear_c,
  r8 x_rotate, r8 y_rotate, r8 rotate)
 : image_(image), pixel_buffer_(image.getPixelBuffer()),
    x_shear_(x_shear), x_shear_c_(x_shear_c), y_shear_(y_shear), y_shear_c_(y_shear_c),
    x_rotate_(x_rotate), y_rotate_(y_rotate), rotate_(rotate)
{
 backup_pixel_buffer_ = pixel_buffer_;
}

void Shear_Command::execute()
{
 proceed();
}

void Shear_Command::undo()
{
 pixel_buffer_ = backup_pixel_buffer_;
}

void Shear_Command::redo()
{
 execute();
}

void Shear_Command::proceed()
{
//? QImage nim(image_.getW(), image_.getH(), QImage::Format_ARGB32);
 QImage nim(image_.getQImage().width(), image_.getQImage().height(), QImage::Format_ARGB32);

 nim.fill(Qt::white);

 QPainter qp(&nim);

 qp.setCompositionMode(QPainter::CompositionMode_Source);

 // QPolygonF quad;
 // quad.append({0, 0});
 // quad.append({0.1, 1});
 // quad.append({1.1, 1});
 // quad.append({1.1, 0});


 QTransform transf;

 transf.shear(x_shear_, y_shear_);
 transf.rotate(x_rotate_, Qt::XAxis);
 transf.rotate(y_rotate_, Qt::YAxis);

 transf.translate((double)image_.getW()/2, (double)image_.getH()/2);
 transf.shear(x_shear_c_, y_shear_c_);
 transf.rotate(-rotate_);
 transf.translate((double)-image_.getW()/2, (double)-image_.getH()/2);

// transf.rotate(x_rotate_, Qt::XAxis);
// transf.rotate(y_rotate_, Qt::YAxis);

//? transf.shear(x_shear_, y_shear_);

// transf.shear(0.2, 0);

 qp.setTransform(transf);

 #define ARG(x) .arg((double)x, 10, 'f', x < 0? 6 : 7, '0')

 QString msg = QString("Applied transformation matrix:\n\n%1  %2  %3\n%4  %5  %6\n%7  %8  %9")
   ARG(transf.m11())ARG(transf.m12())ARG(transf.m13())
   ARG(transf.m21())ARG(transf.m22())ARG(transf.m23())
   ARG(transf.m31())ARG(transf.m32())ARG(transf.m33());

 QMessageBox::information(nullptr, "Combined Tranform Matrix", msg);

// QTransform().squareToQuad(quad, transf);
// qp.setTransform(transf);

// QRect nr = nim->rect().adjusted(30, 30, -30, -30);

// qp.setTransform(QTransform().translate(translate, 0).shear(x_factor_, y_factor_).translate(-translate, 0));
// qp.setTransform(QTransform().shear(x_factor_, y_factor_));


 qp.drawImage(nim.rect(), image_.getQImage(), image_.getQImage().rect());

 image_.reconstruct_pixel_buffer(nim);

 //image_.getQImage() = *nim;
 //proceed(image_, pixel_buffer_);
}

