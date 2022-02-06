
#include "shear-command.h"
#include "../../utils.h"

#include "global-types.h"

#include <QPainter>


Shear_Command::Shear_Command(Image& image, r8 x_shear, r8 y_shear, r8 x_rotate, r8 y_rotate)
 : image_(image), pixel_buffer_(image.getPixelBuffer()),
    x_shear_(x_shear), y_shear_(y_shear),
    x_rotate_(x_rotate), y_rotate_(y_rotate)
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
 QImage nim(image_.getW(), image_.getH(), QImage::Format_ARGB32);

 QPainter qp(&nim);

 // QPolygonF quad;
 // quad.append({0, 0});
 // quad.append({0.1, 1});
 // quad.append({1.1, 1});
 // quad.append({1.1, 0});


 QTransform transf;
 transf.rotate(x_rotate_, Qt::XAxis);
 transf.rotate(y_rotate_, Qt::YAxis);
 transf.shear(x_shear_, y_shear_);

// transf.shear(0.2, 0);

 qp.setTransform(transf);

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

