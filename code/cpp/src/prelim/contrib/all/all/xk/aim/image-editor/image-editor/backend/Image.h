#ifndef IMAGE_EDITOR_IMAGE_H
#define IMAGE_EDITOR_IMAGE_H

//handles RGBA/RGB images
#include <QImage>
#include <QString>
#include "Pixel.h"
#include <vector>

#include <QStack>

#include "global-types.h"

#include "accessors.h"

using namespace std;

class Image
{
public:
 struct Reduction {
   std::vector<Pixel> buffer;
   s2 width;
   s2 height;
 };

 void init_reduction(std::vector<Pixel>& buffer, s2 width, s2 height);
 void push_reduction();
 void pop_reduction();

private:

 QImage rawImage; //stores backend data infos
 QString path;
 QString filename;
 int w;
 int h;
 std::vector<Pixel> pixelBuffer;
 size_t size{0};
 bool isImageValid;

 Reduction* reduction_;

 QStack<Reduction*> reduction_stack_;

 void initPixelBuffer();
 void pureFilename();

public:

 explicit Image(const QString &path);

 ACCESSORS__GET(Reduction* ,reduction)

 bool save(const QString &outPath, int quality = -1); //-1 auto compression //0-100 quality range
 Image(Image &image) = delete;


 static void show_alpha_codes(QVector<QColor> colors,
   QImage& qim, QImage* source = nullptr,
   QMap<QPair<s2, s2>, QMap<s2, QPair<u4, u4>>>* measurements = nullptr
   //QMap<QPair<u2, u2>, u4>* bin_counts = nullptr
   );

 static void remove_alpha_codes(QImage& qim);


 QString getPath() const;

 QString getFilename() const;

 std::vector<Pixel>& getPixelBuffer();

 size_t getSize() const;

 void reconstruct_pixel_buffer(const QImage& new_image);

 int getW() const;

 int getH() const;


 int* getWptr();
 int* getHptr();

 double get_aspect_ratio()
 {
  return (double) w / h;
 }

 double get_inverse_aspect_ratio()
 {
  return (double) h / w;
 }

 void setW(int w);
 void setH(int h);

 void setPath(QString path);

 void swapDimension();

 void updateBuffer();

 QImage& getQImage();

 bool isValid() const;

 void remove_alpha_codes();

};


#endif
