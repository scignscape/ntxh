

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

//? #include "itkPNGImageIOFactory.h"


int
main1(int argc, char * argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0];
    std::cerr << " <InputFileName>";
    std::cerr << std::endl;
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}


int
main(int, char * argv[] )
{
//  UnsignedCharImageType::Pointer image = UnsignedCharImageType::New();
//  CreateImage(image);

 itk::JPEGImageIOFactory::RegisterOneFactory();
//? itk::PNGImageIOFactory::RegisterOneFactory();

 constexpr unsigned int Dimension = 2;

 using PixelType = float; // unsigned char; // float; // unsigned char;
 using ImageType = itk::Image<PixelType, Dimension>;

 using ReaderType = itk::ImageFileReader<ImageType>;
 ReaderType::Pointer reader = ReaderType::New();
 reader->SetFileName(argv[1]);
 reader->Update();

 ImageType::Pointer image = reader->GetOutput();

// using WriterType = itk::ImageFileWriter<ImageType>;
// WriterType::Pointer writer = WriterType::New();

////  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img.jpg");
////  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img1.jpg");

// writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image.jpg");
// writer->SetInput(image);
// writer->Update();

 return EXIT_SUCCESS;

   //?UnsignedCharImageType

 using ApproximateSignedDistanceMapImageFilterType =
    itk::ApproximateSignedDistanceMapImageFilter<ImageType, FloatImageType>;
  ApproximateSignedDistanceMapImageFilterType::Pointer approximateSignedDistanceMapImageFilter =
    ApproximateSignedDistanceMapImageFilterType::New();
  approximateSignedDistanceMapImageFilter->SetInput(image);
  approximateSignedDistanceMapImageFilter->SetInsideValue(255);
  approximateSignedDistanceMapImageFilter->SetOutsideValue(0);
  approximateSignedDistanceMapImageFilter->Update();

  using ContourExtractor2DImageFilterType = itk::ContourExtractor2DImageFilter<FloatImageType>;
  ContourExtractor2DImageFilterType::Pointer contourExtractor2DImageFilter = ContourExtractor2DImageFilterType::New();
  contourExtractor2DImageFilter->SetInput(approximateSignedDistanceMapImageFilter->GetOutput());
  contourExtractor2DImageFilter->SetContourValue(0);
  contourExtractor2DImageFilter->Update();

  std::cout << "There are " << contourExtractor2DImageFilter->GetNumberOfOutputs() << " contours" << std::endl;


  for (unsigned int i = 0; i < contourExtractor2DImageFilter->GetNumberOfOutputs(); ++i)
  {
    std::cout << "Contour " << i << ": " << std::endl;
    ContourExtractor2DImageFilterType::VertexListType::ConstIterator vertexIterator =
      contourExtractor2DImageFilter->GetOutput(i)->GetVertexList()->Begin();
    while (vertexIterator != contourExtractor2DImageFilter->GetOutput(i)->GetVertexList()->End())
    {
      std::cout << vertexIterator->Value() << std::endl;
      ++vertexIterator;
    }
    std::cout << std::endl;
  }

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

  using WriterType = itk::ImageFileWriter<UnsignedCharImageType>;
  WriterType::Pointer writer = WriterType::New();

//  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img.jpg");
//  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/img1.jpg");

  writer->SetFileName("/home/nlevisrael/gits/ntxh/wip-sebi/ar/dev/consoles/dgi/itk/image.jpg");
  writer->SetInput(image);
  writer->Update();
}
