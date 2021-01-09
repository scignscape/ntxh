

#include "itkImage.h"
#include "itkImageFileWriter.h"

#include "itkContourExtractor2DImageFilter.h"
#include "itkApproximateSignedDistanceMapImageFilter.h"

using UnsignedCharImageType = itk::Image<unsigned char, 2>;
using FloatImageType = itk::Image<float, 2>;

static void
CreateImage(UnsignedCharImageType::Pointer image);


#include "itkImage.h"
#include "itkImageFileReader.h"

#include "itkJPEGImageIOFactory.h"
#include "itkPNGImageIOFactory.h"


#include "itkRGBToLuminanceImageFilter.h"


#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRGBToLuminanceImageFilter.h"


#include "itkImageDuplicator.h"

#include "itkFlatStructuringElement.h"
#include "itkGrayscaleDilateImageFilter.h"


#include <QVector>
#include <QMap>


int
main2(int argc, char * argv[])
{
 if (argc != 3)
 {
  std::cerr << "Usage: " << std::endl;
  std::cerr << argv[0];
  std::cerr << "<InputFileName> <OutputFileName>";
  std::cerr << std::endl;
  return EXIT_FAILURE;
 }

 constexpr unsigned int Dimension = 2;

 using ComponentType = unsigned char;
 using InputPixelType = itk::RGBPixel<ComponentType>;
 using InputImageType = itk::Image<InputPixelType, Dimension>;

 using ReaderType = itk::ImageFileReader<InputImageType>;
 ReaderType::Pointer reader = ReaderType::New();
 reader->SetFileName(argv[1]);

 using OutputPixelType = unsigned char;
 using OutputImageType = itk::Image<OutputPixelType, Dimension>;

 using FilterType = itk::RGBToLuminanceImageFilter<InputImageType, OutputImageType>;
 FilterType::Pointer filter = FilterType::New();
 filter->SetInput(reader->GetOutput());

 using WriterType = itk::ImageFileWriter<OutputImageType>;
 WriterType::Pointer writer = WriterType::New();
 writer->SetFileName(argv[2]);
 writer->SetInput(filter->GetOutput());

 try
 {
  writer->Update();
 }
 catch (itk::ExceptionObject & error)
 {
  std::cerr << "Error: " << error << std::endl;
  return EXIT_FAILURE;
 }

 return EXIT_SUCCESS;
}


//int
//main1(int argc, char * argv[])
//{
//  if (argc != 2)
//  {
//    std::cerr << "Usage: " << std::endl;
//    std::cerr << argv[0];
//    std::cerr << " <InputFileName>";
//    std::cerr << std::endl;
//    return EXIT_FAILURE;
//  }


//  return EXIT_SUCCESS;
//}

#include "itkRGBPixel.h"


int
main(int, char * argv[] )
{
 //  UnsignedCharImageType::Pointer image = UnsignedCharImageType::New();
 //  CreateImage(image);

 itk::JPEGImageIOFactory::RegisterOneFactory();
 itk::PNGImageIOFactory::RegisterOneFactory();

 constexpr unsigned int Dimension = 2;

 //using PixelType = unsigned char; //float; // unsigned char;

 //using RGBPixelType = itk::RGBPixel<unsigned char>;
 using PixelType = itk::RGBPixel<unsigned char>;
 using ImageType = itk::Image<PixelType, Dimension>;

 using ReaderType = itk::ImageFileReader<ImageType>;
 ReaderType::Pointer reader = ReaderType::New();
 reader->SetFileName(argv[1]);
 reader->Update();

 ImageType::Pointer image = reader->GetOutput();


 itk::ImageFileWriter<ImageType>::Pointer PNGwriter;
 PNGwriter = itk::ImageFileWriter<ImageType>::New();

 PNGwriter->SetInput( image );


 PNGwriter->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image.png" );

 PNGwriter->Update();

 using WriterType = itk::ImageFileWriter<ImageType>;
 WriterType::Pointer writer = WriterType::New();


 //  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img.jpg");
 //  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img1.jpg");

 writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image.jpg");
 writer->SetInput(image);
 writer->Update();
 // return EXIT_SUCCESS;


 using cPixelType = unsigned char;
 using cImageType = itk::Image<cPixelType, Dimension>;

 using FilterType = itk::RGBToLuminanceImageFilter<ImageType, cImageType>;
 FilterType::Pointer filter = FilterType::New();
 filter->SetInput(reader->GetOutput());

 using cWriterType = itk::ImageFileWriter<cImageType>;
 cWriterType::Pointer cwriter = cWriterType::New();
 cwriter->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image-gray.jpg");
 cwriter->SetInput(filter->GetOutput());

 cwriter->Update();


 using fPixelType = float; //unsigned char;
 using fImageType = itk::Image<fPixelType, Dimension>;

 using fFilterType = itk::RGBToLuminanceImageFilter<ImageType, fImageType>;
 fFilterType::Pointer ffilter = fFilterType::New();
 ffilter->SetInput(reader->GetOutput());


 //  using fReaderType = itk::ImageFileReader<fImageType>;
 //  fReaderType::Pointer freader = fReaderType::New();
 //  freader->SetFileName(argv[1]);
 //  freader->Update();
 //  fImageType::Pointer fimage = freader->GetOutput();

 ffilter->Update();
 fImageType::Pointer fimage = ffilter->GetOutput();



 const unsigned int radiusValue = 5;

 using StructuringElementType = itk::FlatStructuringElement<Dimension>;
   StructuringElementType::RadiusType radius;
   radius.Fill(radiusValue);
   StructuringElementType structuringElement = StructuringElementType::Ball(radius);

   using GrayscaleDilateImageFilterType = itk::GrayscaleDilateImageFilter<fImageType, fImageType, StructuringElementType>;

   GrayscaleDilateImageFilterType::Pointer dilateFilter = GrayscaleDilateImageFilterType::New();
   dilateFilter->SetInput(ffilter->GetOutput());
   dilateFilter->SetKernel(structuringElement);

   using ffWriterType = itk::ImageFileWriter<fImageType>;
   ffWriterType::Pointer ffwriter = ffWriterType::New();

//   ffwriter->SetInput(dilateFilter->GetOutput());
//   ffwriter->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image-gray.df.png");

//   ffwriter->Update();





 //  using ApproximateSignedDistanceMapImageFilterType =
 //     itk::ApproximateSignedDistanceMapImageFilter<ImageType, FloatImageType>;

 using ApproximateSignedDistanceMapImageFilterType =
 itk::ApproximateSignedDistanceMapImageFilter<fImageType, FloatImageType>;

 ApproximateSignedDistanceMapImageFilterType::Pointer approximateSignedDistanceMapImageFilter =
   ApproximateSignedDistanceMapImageFilterType::New();

// approximateSignedDistanceMapImageFilter->SetInput(fimage);

 approximateSignedDistanceMapImageFilter->SetInput(dilateFilter->GetOutput());

 approximateSignedDistanceMapImageFilter->SetInsideValue(255);
 approximateSignedDistanceMapImageFilter->SetOutsideValue(0);
 approximateSignedDistanceMapImageFilter->Update();

 using ContourExtractor2DImageFilterType = itk::ContourExtractor2DImageFilter<FloatImageType>;
 ContourExtractor2DImageFilterType::Pointer contourExtractor2DImageFilter = ContourExtractor2DImageFilterType::New();

 contourExtractor2DImageFilter->SetInput(approximateSignedDistanceMapImageFilter->GetOutput());
 contourExtractor2DImageFilter->SetContourValue(0);
 contourExtractor2DImageFilter->Update();

 std::cout << "There are " << contourExtractor2DImageFilter->GetNumberOfOutputs() << " contours" << std::endl;

 QMap<itk::PathSource<itk::PolyLineParametricPath<2u> >::OutputPathType*, int> paths;

 for (unsigned int i = 0; i < contourExtractor2DImageFilter->GetNumberOfOutputs(); ++i)
 {
  //itk::PathSource
  // int  ps = contourExtractor2DImageFilter->GetOutput(i);
  itk::PathSource<itk::PolyLineParametricPath<2u> >::OutputPathType*
    ps = contourExtractor2DImageFilter->GetOutput(i);

  int size = ps->GetVertexList()->size();
  //   std::cout <<  "size = " << size << std::endl;

  paths[ps] = size / 10;

//  if(size > 10)
//  {
//   paths.push_back(ps);
//  }

  //    std::cout << "Contour " << i << ": " << std::endl;
  //    ContourExtractor2DImageFilterType::VertexListType::ConstIterator vertexIterator =
  //      contourExtractor2DImageFilter->GetOutput(i)->GetVertexList()->Begin();
  //    while (vertexIterator != contourExtractor2DImageFilter->GetOutput(i)->GetVertexList()->End())
  //    {
  //      std::cout << vertexIterator->Value() << std::endl;
  //      ++vertexIterator;
  //    }
  //    std::cout << std::endl;
 }

 //  ImageType::Pointer wimage = reader->GetOutput();

 using DuplicatorType = itk::ImageDuplicator<ImageType>;
 DuplicatorType::Pointer duplicator = DuplicatorType::New();
 duplicator->SetInputImage(image);
 duplicator->Update();

 ImageType::Pointer clonedImage = duplicator->GetOutput();

 QMapIterator<itk::PathSource<itk::PolyLineParametricPath<2u> >::OutputPathType*, int> it(paths);
 while(it.hasNext())
 {
  it.next();
  auto* path = it.key();

  int size = it.value();

  itk::PolyLineParametricPath<2>::VertexListType* vl = path->GetVertexList();
  for(itk::ContinuousIndex<double, 2> v : *vl)
  {
   double d1 = v[0];
   double d2 = v[1];

   itk::RGBPixel<unsigned char> rx;

   switch(size)
   {
   case 0:
    rx[0] = 120;
    rx[1] = 120;
    rx[2] = 250;
    break;

   case 1:
    rx[0] = 20;
    rx[1] = 200;
    rx[2] = 100;
    break;

   case 2:
    rx[0] = 200;
    rx[2] = 50;
    break;

   default:
    rx[0] = 20;
    rx[1] = 20;
    rx[2] = 250;
    break;

   }


//   clonedImage->SetPixel(v, rx);

   const itk::Image<itk::RGBPixel<unsigned char>, 2>::IndexType pos { (long) d1, (long) d2};
//   pos[0] = d1;
//   pos[0] = d1;

   clonedImage->SetPixel(pos, rx);
  }
 }


 using wWriterType = itk::ImageFileWriter<ImageType>;
 WriterType::Pointer wwriter = WriterType::New();


 //  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img.jpg");
 //  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img1.jpg");

 wwriter->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/wimage.jpg");
 wwriter->SetInput(clonedImage);
 wwriter->Update();

 return EXIT_SUCCESS;
}

void
CreateImage(UnsignedCharImageType::Pointer image)
{
 // Create an image
 itk::Index<2> start;
 start.Fill(0);

 itk::Size<2> size;
 size.Fill(100);

 itk::ImageRegion<2> region(start, size);
 image->SetRegions(region);
 image->Allocate();
 image->FillBuffer(0);

 // Create a line of white pixels
 for (unsigned int i = 40; i < 60; ++i)
 {
  itk::Index<2> pixel;
  pixel.Fill(i);
  image->SetPixel(pixel, 255);
 }

 // Create another line of pixels
 for (unsigned int i = 10; i < 20; ++i)
 {
  itk::Index<2> pixel;
  pixel[0] = 10;
  pixel[1] = i;
  image->SetPixel(pixel, 255);
 }

 //  using WriterType = itk::ImageFileWriter<UnsignedCharImageType>;
 //  WriterType::Pointer writer = WriterType::New();

 ////  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img.jpg");
 ////  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img1.jpg");

 //  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image.png");
 //  writer->SetInput(image);
 //  writer->Update();
}



//const unsigned int radiusValue = 5;

//using StructuringElementType = itk::FlatStructuringElement<Dimension>;
//  StructuringElementType::RadiusType radius;
//  radius.Fill(radiusValue);
//  StructuringElementType structuringElement = StructuringElementType::Ball(radius);

//  using GrayscaleDilateImageFilterType = itk::GrayscaleDilateImageFilter<cImageType, cImageType, StructuringElementType>;

//  GrayscaleDilateImageFilterType::Pointer dilateFilter = GrayscaleDilateImageFilterType::New();
//  dilateFilter->SetInput(filter->GetOutput());
//  dilateFilter->SetKernel(structuringElement);

//  using fcWriterType = itk::ImageFileWriter<cImageType>;
//  fcWriterType::Pointer fcwriter = fcWriterType::New();
//  fcwriter->SetInput(dilateFilter->GetOutput());
//  fcwriter->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image-gray.d.jpg");

//  fcwriter->Update();
