#include "Image.h"
#include <QColor>
#include "Pixel.h"
#include <algorithm>
#include <cmath>
#include "QFileInfo"
#include <QErrorMessage>

#include <QDebug>

using namespace std;

Image::Image(const QString &path)
  : rawImage(path), path(path), isImageValid(true), reduction_(nullptr)
{
    if(rawImage.isNull()){
        isImageValid = false;
    }
    rawImage = rawImage.convertToFormat(QImage::Format_ARGB32); //only 32bit depth supported(auto conversion)
    w = rawImage.width();                                        //it's a 24bit (8*3) + alpha channel (8bit)
    h = rawImage.height();

    pixelBuffer.reserve(getSize());
    initPixelBuffer();
    pureFilename();
}

void Image::pureFilename() {
    QFileInfo qFilename(path);
    filename = qFilename.fileName();
}



void Image::remove_alpha_codes(QImage& qim)
{
 int a_count = 0;

 for(int y = 0; y < qim.height(); ++y)
  for(int x = 0; x < qim.width(); ++x)
  {
   QColor color = qim.pixelColor(x, y);
   if(color.alpha() < 255)
   {
    color.setAlpha(255);
    qim.setPixelColor(x, y, color);
    ++a_count;
   }
  }

 qDebug() << "alpha count (removed) = " << a_count;
}


void Image::show_alpha_codes(QVector<QColor> colors,
  QImage& qim, QImage* source)
{
 int a_count = 0;


 s2 x_offset = 0, y_offset = 0;

 if(source)
 {
  if(source->width() != qim.width())
    x_offset = ( source->width() - qim.width() ) / 2;

  if(source->height() != qim.height())
    y_offset = ( source->height() - qim.height() ) / 2;
 }
 else
   source = &qim;



 for(s4 y = 0; y < qim.height(); ++y)
 {
  s4 y_o = y + y_offset;

  if(y_offset != 0)
  {
   if(y_o < 0)
   {
    y = -y_offset;
    y_o = 0;
   }
   else if(y_o >= source->height())
     break;
  }

  for(s4 x = 0; x < qim.width(); ++x)
  {
   s4 x_o = x + x_offset;
   if(x_offset != 0)
   {
    if(x_o < 0)
    {
     x = -x_offset;
     x_o = 0;
    }
    else if(x_o >= source->width())
      break;
   }
   QColor color = source->pixelColor(x_o, y_o);
   int a = 255 - color.alpha();

   if(a)
   {
    --a;
    qim.setPixelColor(x, y, colors.value(a));
    ++a_count;
   }
  }

 }

 qDebug() << "alpha count = " << a_count;
}


void Image::init_reduction(std::vector<Pixel>& buffer, s2 width, s2 height)
{
 reduction_ = new Reduction{buffer, width, height};
}

void Image::push_reduction()
{
 if(reduction_)
   reduction_stack_.push(reduction_);
}

void Image::pop_reduction()
{
 if(!reduction_stack_.isEmpty())
   reduction_ = reduction_stack_.pop();
}

void Image::reconstruct_pixel_buffer(const QImage& new_image)
{
 pixelBuffer.clear();
 w = new_image.width();
 h = new_image.height();
 for (int y = 0; y < h; y++) //rows
   for (int x = 0; x < w; x++)
   { //columns
    pixelBuffer.emplace_back(Pixel::fromQColor(new_image.pixelColor(x, y)));
   }
}

void Image::initPixelBuffer() {
    for (int y = 0; y < h; y++) //rows
        for (int x = 0; x < w; x++) { //columns
            pixelBuffer.emplace_back(Pixel::fromQColor(rawImage.pixelColor(x, y)));
        }
}

bool Image::save(const QString &outPath, int quality) {

    updateBuffer();

    //save image on disk
    return rawImage.save(outPath, nullptr, quality);
}

QString Image::getPath() const {
    return path;
}

QString Image::getFilename() const {
    return filename;
}

size_t Image::getSize() const {
    return w * h;
}

int Image::getW() const{
    return w;
}

int Image::getH() const{
    return h;
}

int* Image::getWptr(){
    return &w;
}

int* Image::getHptr(){
    return &h;
}

void Image::setW(int w){
    this->w = w;
}

void Image::setH(int h){
    this->h = h;
}

void Image::setPath(QString path)
{
    this->path = path;
    pureFilename();
}

//pass a reference (no copy, better performance)
std::vector<Pixel>& Image::getPixelBuffer() {

    return pixelBuffer;
}

void Image::swapDimension() {
    swap(h, w);
}

void Image::updateBuffer()
{
 rawImage = QImage(w, h, QImage::Format_ARGB32);

 for (int y = 0; y < h; y++) //rows
  for (int x = 0; x < w; x++)
  { //columns
   rawImage.setPixelColor(x, y, Pixel::toQColor(pixelBuffer[y * w + x]));
  }
}

void Image::remove_alpha_codes()
{
 remove_alpha_codes(rawImage);

 for (int y = 0; y < h; y++)
  for (int x = 0; x < w; x++)
  {
   Pixel& px = pixelBuffer[y * w + x];
   px.make_fully_opaque();
  }

}

QImage& Image::getQImage(){

    return rawImage;
}

bool Image::isValid() const {
    return isImageValid;
}
