
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

#TEMPLATE = app

#QT += xml opengl network

include($$ROOT_DIR/../preferred/sysr.pri)




INCLUDEPATH += $$SRC_DIR/include


INCLUDEPATH += $$SRC_GROUP_DIR/mdstk/modules/SliceFFT
INCLUDEPATH += $$SRC_GROUP_DIR/mdstk



DEFINES += _LINUX


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk
INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/Eigen


HEADERS += \
  $$SRC_DIR/include/VPL/Base/Array.h \
  $$SRC_DIR/include/VPL/Base/Array.hxx \
  $$SRC_DIR/include/VPL/Base/Assert.h \
  $$SRC_DIR/include/VPL/Base/BaseExport.h \
  $$SRC_DIR/include/VPL/Base/BasePtr.h \
  $$SRC_DIR/include/VPL/Base/BuildDate.h \
  $$SRC_DIR/include/VPL/Base/Data.h \
  $$SRC_DIR/include/VPL/Base/Data.hxx \
  $$SRC_DIR/include/VPL/Base/DataAllocator.h \
  $$SRC_DIR/include/VPL/Base/EmptyConst.h \
  $$SRC_DIR/include/VPL/Base/Error.h \
  $$SRC_DIR/include/VPL/Base/Exception.h \
  $$SRC_DIR/include/VPL/Base/Factory.h \
  $$SRC_DIR/include/VPL/Base/FullException.h \
  $$SRC_DIR/include/VPL/Base/Functional.h \
  $$SRC_DIR/include/VPL/Base/Functor.h \
  $$SRC_DIR/include/VPL/Base/HasOptions.h \
  $$SRC_DIR/include/VPL/Base/Identifier.h \
  $$SRC_DIR/include/VPL/Base/IteratorBase.h \
  $$SRC_DIR/include/VPL/Base/IteratorTraits.h \
  $$SRC_DIR/include/VPL/Base/Lock.h \
  $$SRC_DIR/include/VPL/Base/LogAppender.h \
  $$SRC_DIR/include/VPL/Base/LogChannel.h \
  $$SRC_DIR/include/VPL/Base/LogFilters.h \
  $$SRC_DIR/include/VPL/Base/LogIDEAppender.h \
  $$SRC_DIR/include/VPL/Base/LogLayout.h \
  $$SRC_DIR/include/VPL/Base/LogRecord.h \
  $$SRC_DIR/include/VPL/Base/Logger.h \
  $$SRC_DIR/include/VPL/Base/Logging.h \
  $$SRC_DIR/include/VPL/Base/Meta.h \
  $$SRC_DIR/include/VPL/Base/MinimalLogger.h \
  $$SRC_DIR/include/VPL/Base/ModernFunctor.h \
  $$SRC_DIR/include/VPL/Base/ModernFunctor.hxx \
  $$SRC_DIR/include/VPL/Base/NamedObject.h \
  $$SRC_DIR/include/VPL/Base/Object.h \
  $$SRC_DIR/include/VPL/Base/PartedData.h \
  $$SRC_DIR/include/VPL/Base/PartedData.hxx \
  $$SRC_DIR/include/VPL/Base/Range.h \
  $$SRC_DIR/include/VPL/Base/RefData.h \
  $$SRC_DIR/include/VPL/Base/RefData.hxx \
  $$SRC_DIR/include/VPL/Base/SHMData.h \
  $$SRC_DIR/include/VPL/Base/SHMData.hxx \
  $$SRC_DIR/include/VPL/Base/STLIterator.h \
  $$SRC_DIR/include/VPL/Base/Scalar.h \
  $$SRC_DIR/include/VPL/Base/ScopedPtr.h \
  $$SRC_DIR/include/VPL/Base/Setup.h \
  $$SRC_DIR/include/VPL/Base/SharedPtr.h \
  $$SRC_DIR/include/VPL/Base/Singleton.h \
  $$SRC_DIR/include/VPL/Base/Singleton.hxx \
  $$SRC_DIR/include/VPL/Base/SmallObject.h \
  $$SRC_DIR/include/VPL/Base/StaticAssert.h \
  $$SRC_DIR/include/VPL/Base/StaticData.h \
  $$SRC_DIR/include/VPL/Base/StaticData.hxx \
  $$SRC_DIR/include/VPL/Base/Templates.h \
  $$SRC_DIR/include/VPL/Base/TypeTraits.h \
  $$SRC_DIR/include/VPL/Base/TypeTraits.hxx \
  $$SRC_DIR/include/VPL/Base/Types.h \
  $$SRC_DIR/include/VPL/Base/Version.h \
  $$SRC_DIR/include/VPL/Base/Warning.h \
  $$SRC_DIR/include/VPL/Image/Algorithm/WeightedEM.h \
  $$SRC_DIR/include/VPL/Image/Algorithm/WeightedEM.hxx \
  $$SRC_DIR/include/VPL/Image/Algorithm/WeightedFCM.h \
  $$SRC_DIR/include/VPL/Image/Algorithm/WeightedFCM.hxx \
  $$SRC_DIR/include/VPL/Image/Color.h \
  $$SRC_DIR/include/VPL/Image/Coordinates.h \
  $$SRC_DIR/include/VPL/Image/CornerDetection/Harris.h \
  $$SRC_DIR/include/VPL/Image/CornerDetection/Harris.hxx \
  $$SRC_DIR/include/VPL/Image/CornerDetection/Susan.h \
  $$SRC_DIR/include/VPL/Image/CornerDetection/Susan.hxx \
  $$SRC_DIR/include/VPL/Image/CvImage.h \
  $$SRC_DIR/include/VPL/Image/CvImage.hxx \
  $$SRC_DIR/include/VPL/Image/CvImageRef.h \
  $$SRC_DIR/include/VPL/Image/CvImageRef.hxx \
  $$SRC_DIR/include/VPL/Image/CvTraits.h \
  $$SRC_DIR/include/VPL/Image/CvTraits.hxx \
  $$SRC_DIR/include/VPL/Image/DensityVolume.h \
  $$SRC_DIR/include/VPL/Image/DensityVolume.hxx \
  $$SRC_DIR/include/VPL/Image/EdgeDetection/Canny.h \
  $$SRC_DIR/include/VPL/Image/EdgeDetection/Canny.hxx \
  $$SRC_DIR/include/VPL/Image/EdgeDetection/ZeroCrossings.h \
  $$SRC_DIR/include/VPL/Image/EdgeDetection/ZeroCrossings.hxx \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/DistanceMeasure.h \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/FeatureExtractor.h \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/FeatureVector.h \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/PixelStats.h \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/PixelStatsExtractor.h \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/PixelStatsExtractor.hxx \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/SimilarityMeasure.h \
  $$SRC_DIR/include/VPL/Image/FeatureExtraction/SimilarityMeasure.hxx \
  $$SRC_DIR/include/VPL/Image/FilterPolicy.h \
  $$SRC_DIR/include/VPL/Image/Filters/Anisotropic.h \
  $$SRC_DIR/include/VPL/Image/Filters/Anisotropic.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Averaging.h \
  $$SRC_DIR/include/VPL/Image/Filters/Averaging.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Bilateral.h \
  $$SRC_DIR/include/VPL/Image/Filters/Bilateral.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Convolution.h \
  $$SRC_DIR/include/VPL/Image/Filters/Convolution.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/DoG.h \
  $$SRC_DIR/include/VPL/Image/Filters/DoG.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Gaussian.h \
  $$SRC_DIR/include/VPL/Image/Filters/Gaussian.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Laplacian.h \
  $$SRC_DIR/include/VPL/Image/Filters/Laplacian.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/LoG.h \
  $$SRC_DIR/include/VPL/Image/Filters/LoG.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/LocalMoments.h \
  $$SRC_DIR/include/VPL/Image/Filters/LocalMoments.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Median.h \
  $$SRC_DIR/include/VPL/Image/Filters/Median.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/MinMax.h \
  $$SRC_DIR/include/VPL/Image/Filters/MinMax.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Prewit.h \
  $$SRC_DIR/include/VPL/Image/Filters/Prewit.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Roberts.h \
  $$SRC_DIR/include/VPL/Image/Filters/Roberts.hxx \
  $$SRC_DIR/include/VPL/Image/Filters/Sobel.h \
  $$SRC_DIR/include/VPL/Image/Filters/Sobel.hxx \
  $$SRC_DIR/include/VPL/Image/GeometricTransform/AffineMatrix.h \
  $$SRC_DIR/include/VPL/Image/GeometricTransform/AffineMatrix.hxx \
  $$SRC_DIR/include/VPL/Image/GeometricTransform/AffineTransform.h \
  $$SRC_DIR/include/VPL/Image/GeometricTransform/AffineTransform.hxx \
  $$SRC_DIR/include/VPL/Image/GeometricTransform/ImageTransform.h \
  $$SRC_DIR/include/VPL/Image/GeometricTransform/Interpolate.h \
  $$SRC_DIR/include/VPL/Image/Graphics.h \
  $$SRC_DIR/include/VPL/Image/Histogram.h \
  $$SRC_DIR/include/VPL/Image/Histogram.hxx \
  $$SRC_DIR/include/VPL/Image/HistogramBase.h \
  $$SRC_DIR/include/VPL/Image/HistogramThresholding/Iterative.h \
  $$SRC_DIR/include/VPL/Image/HistogramThresholding/Iterative.hxx \
  $$SRC_DIR/include/VPL/Image/HistogramThresholding/MaxPeakness.h \
  $$SRC_DIR/include/VPL/Image/HistogramThresholding/MaxPeakness.hxx \
  $$SRC_DIR/include/VPL/Image/HistogramThresholding/Otsu.h \
  $$SRC_DIR/include/VPL/Image/HistogramThresholding/Otsu.hxx \
  $$SRC_DIR/include/VPL/Image/Image.h \
  $$SRC_DIR/include/VPL/Image/Image.hxx \
  $$SRC_DIR/include/VPL/Image/ImageBase.h \
  $$SRC_DIR/include/VPL/Image/ImageCornerDetection.h \
  $$SRC_DIR/include/VPL/Image/ImageCornerDetector.h \
  $$SRC_DIR/include/VPL/Image/ImageEdgeDetection.h \
  $$SRC_DIR/include/VPL/Image/ImageEdgeDetector.h \
  $$SRC_DIR/include/VPL/Image/ImageExport.h \
  $$SRC_DIR/include/VPL/Image/ImageFFT.h \
  $$SRC_DIR/include/VPL/Image/ImageFilter.h \
  $$SRC_DIR/include/VPL/Image/ImageFiltering.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctional.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/ConnectedComponents.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/ConnectedComponents.hxx \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/Conversion.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/Conversion.hxx \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/Convolution.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/Convolution.hxx \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/FFT.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/FFT.hxx \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/General.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/General.hxx \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/Histogram.h \
  $$SRC_DIR/include/VPL/Image/ImageFunctions/Histogram.hxx \
  $$SRC_DIR/include/VPL/Image/ImageHistogram.h \
  $$SRC_DIR/include/VPL/Image/ImageIterator.h \
  $$SRC_DIR/include/VPL/Image/ImageTypes.h \
  $$SRC_DIR/include/VPL/Image/ImageView.h \
  $$SRC_DIR/include/VPL/Image/ImageView.hxx \
  $$SRC_DIR/include/VPL/Image/Kernel.h \
  $$SRC_DIR/include/VPL/Image/Kernels.h \
  $$SRC_DIR/include/VPL/Image/LBP/BitOps.h \
  $$SRC_DIR/include/VPL/Image/LBP/CircularSampler.h \
  $$SRC_DIR/include/VPL/Image/LBP/CircularSampler.hxx \
  $$SRC_DIR/include/VPL/Image/LBP/Extractor.h \
  $$SRC_DIR/include/VPL/Image/LBP/Extractor.hxx \
  $$SRC_DIR/include/VPL/Image/LBP/Functional.h \
  $$SRC_DIR/include/VPL/Image/LBP/Functional.hxx \
  $$SRC_DIR/include/VPL/Image/LBP/Histogram.h \
  $$SRC_DIR/include/VPL/Image/LBP/Histogram.hxx \
  $$SRC_DIR/include/VPL/Image/LBP/Mapping.h \
  $$SRC_DIR/include/VPL/Image/LBP/Mapping.hxx \
  $$SRC_DIR/include/VPL/Image/LBP/Operators.h \
  $$SRC_DIR/include/VPL/Image/LBP/Traits.h \
  $$SRC_DIR/include/VPL/Image/LBP/Traits.hxx \
  $$SRC_DIR/include/VPL/Image/LandmarkDetection.h \
  $$SRC_DIR/include/VPL/Image/LandmarkDetection/Rohr.h \
  $$SRC_DIR/include/VPL/Image/LandmarkDetection/Rohr.hxx \
  $$SRC_DIR/include/VPL/Image/LandmarkDetection/Susan.h \
  $$SRC_DIR/include/VPL/Image/LandmarkDetection/Susan.hxx \
  $$SRC_DIR/include/VPL/Image/LandmarkDetector.h \
  $$SRC_DIR/include/VPL/Image/Line.h \
  $$SRC_DIR/include/VPL/Image/Line.hxx \
  $$SRC_DIR/include/VPL/Image/OpticalFlow/LucasKanade.h \
  $$SRC_DIR/include/VPL/Image/OpticalFlow/LucasKanade.hxx \
  $$SRC_DIR/include/VPL/Image/PixelConversions.h \
  $$SRC_DIR/include/VPL/Image/PixelConversions.hxx \
  $$SRC_DIR/include/VPL/Image/PixelTraits.h \
  $$SRC_DIR/include/VPL/Image/PixelTraits.hxx \
  $$SRC_DIR/include/VPL/Image/PixelTypes.h \
  $$SRC_DIR/include/VPL/Image/PixelTypes.hxx \
  $$SRC_DIR/include/VPL/Image/Point3.h \
  $$SRC_DIR/include/VPL/Image/Pyramid.h \
  $$SRC_DIR/include/VPL/Image/Pyramid.hxx \
  $$SRC_DIR/include/VPL/Image/RGBA.h \
  $$SRC_DIR/include/VPL/Image/SeparableImageFilter.h \
  $$SRC_DIR/include/VPL/Image/SeparableVolumeFilter.h \
  $$SRC_DIR/include/VPL/Image/Size.h \
  $$SRC_DIR/include/VPL/Image/Slice.h \
  $$SRC_DIR/include/VPL/Image/Slice.hxx \
  $$SRC_DIR/include/VPL/Image/Utilities/AdjacencyGraph.h \
  $$SRC_DIR/include/VPL/Image/Utilities/AdjacencyGraph.hxx \
  $$SRC_DIR/include/VPL/Image/Utilities/BlobLabeling.h \
  $$SRC_DIR/include/VPL/Image/Vector3.h \
  $$SRC_DIR/include/VPL/Image/Volume.h \
  $$SRC_DIR/include/VPL/Image/Volume.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeBase.h \
  $$SRC_DIR/include/VPL/Image/VolumeEdgeDetection.h \
  $$SRC_DIR/include/VPL/Image/VolumeEdgeDetection/Canny.h \
  $$SRC_DIR/include/VPL/Image/VolumeEdgeDetection/Canny.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeEdgeDetector.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilter.h \
  $$SRC_DIR/include/VPL/Image/VolumeFiltering.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Anisotropic.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Anisotropic.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Averaging.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Averaging.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Bilateral.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Bilateral.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Convolution.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Convolution.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Gaussian.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Gaussian.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Laplacian.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Laplacian.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Median.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Median.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/MinMax.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/MinMax.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Misc.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Misc.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Prewit.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Prewit.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Sobel.h \
  $$SRC_DIR/include/VPL/Image/VolumeFilters/Sobel.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions.h \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions/Convolution.h \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions/Convolution.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions/General.h \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions/General.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions/Histogram.h \
  $$SRC_DIR/include/VPL/Image/VolumeFunctions/Histogram.hxx \
  $$SRC_DIR/include/VPL/Image/VolumeHistogram.h \
  $$SRC_DIR/include/VPL/Image/VolumeIterator.h \
  $$SRC_DIR/include/VPL/Image/VolumeLandmarkDetection.h \
  $$SRC_DIR/include/VPL/Image/VolumeView.h \
  $$SRC_DIR/include/VPL/Image/VolumeView.hxx \
  $$SRC_DIR/include/VPL/Image/Watersheds/RegionMerging.h \
  $$SRC_DIR/include/VPL/Image/Watersheds/RegionMerging.hxx \
  $$SRC_DIR/include/VPL/Image/Watersheds/WatershedTransform.h \
  $$SRC_DIR/include/VPL/Image/Watersheds/WatershedTransform.hxx \
  $$SRC_DIR/include/VPL/ImageIO/DefTagGDCM.h \
  $$SRC_DIR/include/VPL/ImageIO/DicomDirLoader.h \
  $$SRC_DIR/include/VPL/ImageIO/DicomSlice.h \
  $$SRC_DIR/include/VPL/ImageIO/DicomSliceLoader.h \
  $$SRC_DIR/include/VPL/ImageIO/DicomSliceLoaderGDCM.h \
  $$SRC_DIR/include/VPL/ImageIO/DicomSliceLoaderVPL.h \
  $$SRC_DIR/include/VPL/ImageIO/ImageIOExport.h \
  $$SRC_DIR/include/VPL/ImageIO/JPEG.h \
  $$SRC_DIR/include/VPL/ImageIO/JPEG.hxx \
  $$SRC_DIR/include/VPL/ImageIO/JPEGBaseFunctions.h \
  $$SRC_DIR/include/VPL/ImageIO/PNG.h \
  $$SRC_DIR/include/VPL/ImageIO/PNG.hxx \
  $$SRC_DIR/include/VPL/ImageIO/PNGBaseFunctions.h \
  $$SRC_DIR/include/VPL/Math/Algorithm/EM.h \
  $$SRC_DIR/include/VPL/Math/Algorithm/EM.hxx \
  $$SRC_DIR/include/VPL/Math/Algorithm/FuzzyCMeans.h \
  $$SRC_DIR/include/VPL/Math/Algorithm/FuzzyCMeans.hxx \
  $$SRC_DIR/include/VPL/Math/Base.h \
  $$SRC_DIR/include/VPL/Math/Complex.h \
  $$SRC_DIR/include/VPL/Math/EigenCore.h \
  $$SRC_DIR/include/VPL/Math/EigenNumTraits.h \
  $$SRC_DIR/include/VPL/Math/GaussianFunc.h \
  $$SRC_DIR/include/VPL/Math/GaussianFunc.hxx \
  $$SRC_DIR/include/VPL/Math/LogNum.h \
  $$SRC_DIR/include/VPL/Math/MathExceptions.h \
  $$SRC_DIR/include/VPL/Math/MathExport.h \
  $$SRC_DIR/include/VPL/Math/MathTraits.h \
  $$SRC_DIR/include/VPL/Math/Matrix.h \
  $$SRC_DIR/include/VPL/Math/Matrix.hxx \
  $$SRC_DIR/include/VPL/Math/MatrixBase.h \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions.h \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/Determinant.h \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/Determinant.hxx \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/Eig.h \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/Eig.hxx \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/General.h \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/General.hxx \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/Inverse.h \
  $$SRC_DIR/include/VPL/Math/MatrixFunctions/Inverse.hxx \
  $$SRC_DIR/include/VPL/Math/MatrixIterator.h \
  $$SRC_DIR/include/VPL/Math/Quaternion.h \
  $$SRC_DIR/include/VPL/Math/Quaternion.hxx \
  $$SRC_DIR/include/VPL/Math/QuaternionBase.h \
  $$SRC_DIR/include/VPL/Math/Random.h \
  $$SRC_DIR/include/VPL/Math/SparseMatrix.h \
  $$SRC_DIR/include/VPL/Math/SparseMatrix.hxx \
  $$SRC_DIR/include/VPL/Math/SparseMatrixAlt.h \
  $$SRC_DIR/include/VPL/Math/SparseMatrixAlt.hxx \
  $$SRC_DIR/include/VPL/Math/SparseMatrixAltIterator.h \
  $$SRC_DIR/include/VPL/Math/SparseMatrixBase.h \
  $$SRC_DIR/include/VPL/Math/SparseMatrixIterator.h \
  $$SRC_DIR/include/VPL/Math/SparseSystem.h \
  $$SRC_DIR/include/VPL/Math/StaticMatrix.h \
  $$SRC_DIR/include/VPL/Math/StaticMatrix.hxx \
  $$SRC_DIR/include/VPL/Math/StaticVector.h \
  $$SRC_DIR/include/VPL/Math/StaticVector.hxx \
  $$SRC_DIR/include/VPL/Math/TransformMatrix.h \
  $$SRC_DIR/include/VPL/Math/TransformMatrix.hxx \
  $$SRC_DIR/include/VPL/Math/UMFpack.h \
  $$SRC_DIR/include/VPL/Math/Vector.h \
  $$SRC_DIR/include/VPL/Math/Vector.hxx \
  $$SRC_DIR/include/VPL/Math/VectorBase.h \
  $$SRC_DIR/include/VPL/Math/VectorFunctions.h \
  $$SRC_DIR/include/VPL/Math/VectorFunctions/Conversion.h \
  $$SRC_DIR/include/VPL/Math/VectorFunctions/Conversion.hxx \
  $$SRC_DIR/include/VPL/Math/VectorFunctions/General.h \
  $$SRC_DIR/include/VPL/Math/VectorFunctions/General.hxx \
  $$SRC_DIR/include/VPL/Math/VectorIterator.h \
  $$SRC_DIR/include/VPL/Module/Argv.h \
  $$SRC_DIR/include/VPL/Module/BinarySerializer.h \
  $$SRC_DIR/include/VPL/Module/BinarySerializer.hxx \
  $$SRC_DIR/include/VPL/Module/BlockChannel.h \
  $$SRC_DIR/include/VPL/Module/Channel.h \
  $$SRC_DIR/include/VPL/Module/CompressionMethods.h \
  $$SRC_DIR/include/VPL/Module/Compressor.h \
  $$SRC_DIR/include/VPL/Module/CompressorFactory.h \
  $$SRC_DIR/include/VPL/Module/Console.h \
  $$SRC_DIR/include/VPL/Module/DensityCompressor.h \
  $$SRC_DIR/include/VPL/Module/GZipCompressor.h \
  $$SRC_DIR/include/VPL/Module/GlobalSignal.h \
  $$SRC_DIR/include/VPL/Module/MemoryChannel.h \
  $$SRC_DIR/include/VPL/Module/ModernSignal.h \
  $$SRC_DIR/include/VPL/Module/ModernSignal.hxx \
  $$SRC_DIR/include/VPL/Module/Module.h \
  $$SRC_DIR/include/VPL/Module/ModuleExport.h \
  $$SRC_DIR/include/VPL/Module/Predictor.h \
  $$SRC_DIR/include/VPL/Module/Predictor.hxx \
  $$SRC_DIR/include/VPL/Module/Progress.h \
  $$SRC_DIR/include/VPL/Module/RLECompressor.h \
  $$SRC_DIR/include/VPL/Module/SHMSerializer.h \
  $$SRC_DIR/include/VPL/Module/SHMSerializer.hxx \
  $$SRC_DIR/include/VPL/Module/Serializable.h \
  $$SRC_DIR/include/VPL/Module/Serialization.h \
  $$SRC_DIR/include/VPL/Module/Serialization.hxx \
  $$SRC_DIR/include/VPL/Module/SerializationTraits.h \
  $$SRC_DIR/include/VPL/Module/Serializer.h \
  $$SRC_DIR/include/VPL/Module/Signal.h \
  $$SRC_DIR/include/VPL/Module/Signal.hxx \
  $$SRC_DIR/include/VPL/Module/StreamChannel.h \
  $$SRC_DIR/include/VPL/Module/View.h \
  $$SRC_DIR/include/VPL/Module/XMLSerializer.h \
  $$SRC_DIR/include/VPL/Module/XMLSerializer.hxx \
  $$SRC_DIR/include/VPL/System/Atomic.h \
  $$SRC_DIR/include/VPL/System/Atomic.hxx \
  $$SRC_DIR/include/VPL/System/Condition.h \
  $$SRC_DIR/include/VPL/System/Environment.h \
  $$SRC_DIR/include/VPL/System/ExitHandler.h \
  $$SRC_DIR/include/VPL/System/FileBrowser.h \
  $$SRC_DIR/include/VPL/System/Memory.h \
  $$SRC_DIR/include/VPL/System/Memory.hxx \
  $$SRC_DIR/include/VPL/System/Mutex.h \
  $$SRC_DIR/include/VPL/System/NamedPipe.h \
  $$SRC_DIR/include/VPL/System/NamedSemaphore.h \
  $$SRC_DIR/include/VPL/System/ScopedLock.h \
  $$SRC_DIR/include/VPL/System/SharedMem.h \
  $$SRC_DIR/include/VPL/System/Sleep.h \
  $$SRC_DIR/include/VPL/System/Stopwatch.h \
  $$SRC_DIR/include/VPL/System/String.h \
  $$SRC_DIR/include/VPL/System/System.h \
  $$SRC_DIR/include/VPL/System/SystemExport.h \
  $$SRC_DIR/include/VPL/System/SystemTypes.h \
  $$SRC_DIR/include/VPL/System/Thread.h \
  $$SRC_DIR/include/VPL/System/Timer.h \
  $$SRC_DIR/include/VPL/System/Timestamp.h \
  $$SRC_DIR/include/VPL/System/UserThread.h \
  $$SRC_DIR/include/VPL/Test/Accessor/AccessorAt.h \
  $$SRC_DIR/include/VPL/Test/Accessor/AccessorAtAbs.h \
  $$SRC_DIR/include/VPL/Test/Accessor/accessorBrackets.h \
  $$SRC_DIR/include/VPL/Test/Accessor/accessorSquareBrackets.h \
  $$SRC_DIR/include/VPL/Test/Accessor/complexString.h \
  $$SRC_DIR/include/VPL/Test/Compare/compare1D.h \
  $$SRC_DIR/include/VPL/Test/Compare/compare1D.hxx \
  $$SRC_DIR/include/VPL/Test/Compare/compare2D.h \
  $$SRC_DIR/include/VPL/Test/Compare/compare2D.hxx \
  $$SRC_DIR/include/VPL/Test/Compare/compare3D.h \
  $$SRC_DIR/include/VPL/Test/Compare/compare3D.hxx \
  $$SRC_DIR/include/VPL/Test/Compare/compareBase.h \
  $$SRC_DIR/include/VPL/Test/Compare/compareBase.hxx \
  $$SRC_DIR/include/VPL/Test/Utillities/arguments.h \
  $$SRC_DIR/include/VPL/Test/Utillities/genericValue.h \
  $$SRC_DIR/include/VPL/Test/Utillities/imageMetrics.h \
  $$SRC_DIR/include/VPL/Test/Utillities/imageMetrics.hxx \
  $$SRC_DIR/include/VPL/Test/Utillities/multiSetData.h \
  $$SRC_DIR/include/VPL/Test/Utillities/multiSetData.hxx \
  $$SRC_DIR/include/VPL/Test/Utillities/referenceData.h \
  $$SRC_DIR/include/VPL/Test/Utillities/requiredData.h \
  $$SRC_DIR/include/VPL/Test/Utillities/testingData.h \
  $$SRC_DIR/include/VPL/Test/printDefinition.h \
  $$SRC_DIR/include/VPL/configure.in \
  $$SRC_DIR/modules/CreateSHM/CreateSHM.h \
  $$SRC_DIR/modules/LoadDicom/LoadDicom.h \
  $$SRC_DIR/modules/LoadDicomDir/LoadDicomDir.h \
  $$SRC_DIR/modules/LoadJPEG/LoadJPEG.h \
  $$SRC_DIR/modules/LoadJPEGDir/LoadJPEGDir.h \
  $$SRC_DIR/modules/LoadPNG/LoadPNG.h \
  $$SRC_DIR/modules/LoadPNGDir/LoadPNGDir.h \
  $$SRC_DIR/modules/MakeVolume/MakeVolume.h \
  $$SRC_DIR/modules/PythonImage/PythonImage.h \
  $$SRC_DIR/modules/RGBImage2Slice/RGBImage2Slice.h \
  $$SRC_DIR/modules/RGBImageView/RGBImageView.h \
  $$SRC_DIR/modules/SaveJPEG/SaveJPEG.h \
  $$SRC_DIR/modules/SaveJPEGDir/SaveJPEGDir.h \
  $$SRC_DIR/modules/SavePNG/SavePNG.h \
  $$SRC_DIR/modules/SavePNGDir/SavePNGDir.h \
  $$SRC_DIR/modules/SliceAffineTransform/SliceAffineTransform.h \
  $$SRC_DIR/modules/SliceBlending/SliceBlending.h \
  $$SRC_DIR/modules/SliceCornerDetector/SliceCornerDetector.h \
  $$SRC_DIR/modules/SliceCut/SliceCut.h \
  $$SRC_DIR/modules/SliceEdgeDetector/SliceEdgeDetector.h \
  $$SRC_DIR/modules/SliceFFT/SliceFFT.h \
  $$SRC_DIR/modules/SliceFilter/SliceFilter.h \
  $$SRC_DIR/modules/SliceHistEqualization/SliceHistEqualization.h \
  $$SRC_DIR/modules/SliceHistogram/SliceHistogram.h \
  $$SRC_DIR/modules/SliceInfo/SliceInfo.h \
  $$SRC_DIR/modules/SliceLBPCompare/SliceLBPCompare.h \
  $$SRC_DIR/modules/SliceLBPExtract/SliceLBPExtract.h \
  $$SRC_DIR/modules/SliceLBPHistogram/SliceLBPHistogram.h \
  $$SRC_DIR/modules/SliceOpticalFlow/SliceOpticalFlow.h \
  $$SRC_DIR/modules/SliceRange/SliceRange.h \
  $$SRC_DIR/modules/SliceSeg/SegMethod.h \
  $$SRC_DIR/modules/SliceSeg/SliceSeg.h \
  $$SRC_DIR/modules/SliceSegEM/SliceSegEM.h \
  $$SRC_DIR/modules/SliceSegFCM/SliceSegFCM.h \
  $$SRC_DIR/modules/SliceSegHT/HistogramThresholding.h \
  $$SRC_DIR/modules/SliceSegHT/SliceSegHT.h \
  $$SRC_DIR/modules/SliceSegRG/RegionGrowing.h \
  $$SRC_DIR/modules/SliceSegRG/SliceSegRG.h \
  $$SRC_DIR/modules/SliceSegWatersheds/SliceSegWatersheds.h \
  $$SRC_DIR/modules/SliceSubsampling/SliceSubsampling.h \
  $$SRC_DIR/modules/SliceThresholding/SliceThresholding.h \
  $$SRC_DIR/modules/SliceView/SliceView.h \
  $$SRC_DIR/modules/VolumeBlending/VolumeBlending.h \
  $$SRC_DIR/modules/VolumeCut/VolumeCut.h \
  $$SRC_DIR/modules/VolumeEdgeDetector/VolumeEdgeDetector.h \
  $$SRC_DIR/modules/VolumeFilter/VolumeFilter.h \
  $$SRC_DIR/modules/VolumeHistEqualization/VolumeHistEqualization.h \
  $$SRC_DIR/modules/VolumeHistogram/VolumeHistogram.h \
  $$SRC_DIR/modules/VolumeInfo/VolumeInfo.h \
  $$SRC_DIR/modules/VolumeLandmarkDetector/VolumeLandmarkDetector.h \
  $$SRC_DIR/modules/VolumeRange/VolumeRange.h \
  $$SRC_DIR/modules/VolumeSeg/SegMethod.h \
  $$SRC_DIR/modules/VolumeSeg/VolumeSeg.h \
  $$SRC_DIR/modules/VolumeSegEM/VolumeSegEM.h \
  $$SRC_DIR/modules/VolumeSegFCM/VolumeSegFCM.h \
  $$SRC_DIR/modules/VolumeSegHT/HistogramThresholding.h \
  $$SRC_DIR/modules/VolumeSegHT/VolumeSegHT.h \
  $$SRC_DIR/modules/VolumeSegRG/RegionGrowing.h \
  $$SRC_DIR/modules/VolumeSegRG/VolumeSegRG.h \
  $$SRC_DIR/modules/VolumeSplit/VolumeSplit.h \
  $$SRC_DIR/modules/VolumeSubsampling/VolumeSubsampling.h \
  $$SRC_DIR/modules/VolumeThresholding/VolumeThresholding.h \
  $$SRC_DIR/modules/VolumeView/VolumeView.h

SOURCES += \
  $$SRC_DIR/lib/Base/Error.cpp \
  $$SRC_DIR/lib/Base/FullException.cpp \
  $$SRC_DIR/lib/Base/Identifier.cpp \
  $$SRC_DIR/lib/Base/LogAppender.cpp \
  $$SRC_DIR/lib/Base/LogChannel.cpp \
  $$SRC_DIR/lib/Base/LogFilters.cpp \
  $$SRC_DIR/lib/Base/LogIDEAppender.cpp \
  $$SRC_DIR/lib/Base/LogLayout.cpp \
  $$SRC_DIR/lib/Base/LogRecord.cpp \
  $$SRC_DIR/lib/Base/Logger.cpp \
  $$SRC_DIR/lib/Base/Setup.cpp \
  $$SRC_DIR/lib/Base/Singleton.cpp \
  $$SRC_DIR/lib/Base/SmallObject.cpp \
  $$SRC_DIR/lib/Base/Warning.cpp \
  $$SRC_DIR/lib/Image/DensityVolume.cpp \
  $$SRC_DIR/lib/Image/Instantiations.cpp \
  $$SRC_DIR/lib/Image/Kernel.cpp \
  $$SRC_DIR/lib/Image/Kernels.cpp \
  $$SRC_DIR/lib/Image/Slice.cpp \
  $$SRC_DIR/lib/ImageIO/DicomDirLoader.cpp \
  $$SRC_DIR/lib/ImageIO/DicomSlice.cpp \
  $$SRC_DIR/lib/ImageIO/DicomSliceLoaderGDCM.cpp \
  $$SRC_DIR/lib/ImageIO/DicomSliceLoaderVPL.cpp \
  $$SRC_DIR/lib/ImageIO/JPEGBaseFunctions.cpp \
  $$SRC_DIR/lib/ImageIO/PNGBaseFunctions.cpp \
  $$SRC_DIR/lib/Math/Base.cpp \
  $$SRC_DIR/lib/Math/mInstantiations.cpp \
  $$SRC_DIR/lib/Module/Argv.cpp \
  $$SRC_DIR/lib/Module/BinarySerializer.cpp \
  $$SRC_DIR/lib/Module/BlockChannel.cpp \
  $$SRC_DIR/lib/Module/Channel.cpp \
  $$SRC_DIR/lib/Module/Compressor.cpp \
  $$SRC_DIR/lib/Module/Console.cpp \
  $$SRC_DIR/lib/Module/DensityCompressor.cpp \
  $$SRC_DIR/lib/Module/GZipCompressor.cpp \
  $$SRC_DIR/lib/Module/MemoryChannel.cpp \
  $$SRC_DIR/lib/Module/Module.cpp \
  $$SRC_DIR/lib/Module/Predictor.cpp \
  $$SRC_DIR/lib/Module/RLECompressor.cpp \
  $$SRC_DIR/lib/Module/SHMSerializer.cpp \
  $$SRC_DIR/lib/Module/StreamChannel.cpp \
  $$SRC_DIR/lib/Module/View.cpp \
  $$SRC_DIR/lib/Module/XMLSerializer.cpp \
  $$SRC_DIR/lib/System/Condition.cpp \
  $$SRC_DIR/lib/System/ExitHandler.cpp \
  $$SRC_DIR/lib/System/FileBrowser.cpp \
  $$SRC_DIR/lib/System/Memory.cpp \
  $$SRC_DIR/lib/System/Mutex.cpp \
  $$SRC_DIR/lib/System/NamedPipe.cpp \
  $$SRC_DIR/lib/System/NamedSemaphore.cpp \
  $$SRC_DIR/lib/System/SharedMem.cpp \
  $$SRC_DIR/lib/System/Sleep.cpp \
  $$SRC_DIR/lib/System/Stopwatch.cpp \
  $$SRC_DIR/lib/System/String.cpp \
  $$SRC_DIR/lib/System/Thread.cpp \
  $$SRC_DIR/lib/System/Timer.cpp \
  $$SRC_DIR/lib/System/Timestamp.cpp \
  $$SRC_DIR/lib/System/UserThread.cpp \
  \# $$SRC_DIR/lib/Test/arguments.cpp \
  \# $$SRC_DIR/lib/Test/genericValue.cpp \
  \# $$SRC_DIR/lib/Test/referenceData.cpp \
  \# $$SRC_DIR/lib/Test/requiredData.cpp \
  \# $$SRC_DIR/lib/Test/testingData.cpp \
  $$SRC_DIR/modules/CreateSHM/CreateSHM.cpp \
  \#main $$SRC_DIR/modules/LoadDicom/LoadDicom.cpp \
  \#main $$SRC_DIR/modules/LoadDicomDir/LoadDicomDir.cpp \
  \#main $$SRC_DIR/modules/LoadJPEG/LoadJPEG.cpp \
  \#main $$SRC_DIR/modules/LoadJPEGDir/LoadJPEGDir.cpp \
  \#main $$SRC_DIR/modules/LoadPNG/LoadPNG.cpp \
  \#main $$SRC_DIR/modules/LoadPNGDir/LoadPNGDir.cpp \
  \#main $$SRC_DIR/modules/MakeVolume/MakeVolume.cpp \
  \# $$SRC_DIR/modules/PythonImage/PythonImage.cpp \
  \#main $$SRC_DIR/modules/RGBImage2Slice/RGBImage2Slice.cpp \
  \#main $$SRC_DIR/modules/RGBImageView/RGBImageView.cpp \
  \#main $$SRC_DIR/modules/SaveJPEG/SaveJPEG.cpp \
  \#main $$SRC_DIR/modules/SaveJPEGDir/SaveJPEGDir.cpp \
  \#main $$SRC_DIR/modules/SavePNG/SavePNG.cpp \
  \#main $$SRC_DIR/modules/SavePNGDir/SavePNGDir.cpp \
  \#main $$SRC_DIR/modules/SliceAffineTransform/SliceAffineTransform.cpp \
  \#main   $$SRC_DIR/modules/SliceBlending/SliceBlending.cpp \
  \#main   $$SRC_DIR/modules/SliceCornerDetector/SliceCornerDetector.cpp \
  \#main   $$SRC_DIR/modules/SliceCut/SliceCut.cpp \
  \#main   $$SRC_DIR/modules/SliceEdgeDetector/SliceEdgeDetector.cpp \
  \#main   $$SRC_DIR/modules/SliceFFT/SliceFFT.cpp \
  \#main   $$SRC_DIR/modules/SliceFilter/SliceFilter.cpp \
  \#main   $$SRC_DIR/modules/SliceHistEqualization/SliceHistEqualization.cpp \
  \#main   $$SRC_DIR/modules/SliceHistogram/SliceHistogram.cpp \
  \#main   $$SRC_DIR/modules/SliceInfo/SliceInfo.cpp \
  \#main   $$SRC_DIR/modules/SliceLBPCompare/SliceLBPCompare.cpp \
  \#main   $$SRC_DIR/modules/SliceLBPExtract/SliceLBPExtract.cpp \
  \#main   $$SRC_DIR/modules/SliceLBPHistogram/SliceLBPHistogram.cpp \
  \#main   $$SRC_DIR/modules/SliceOpticalFlow/SliceOpticalFlow.cpp \
  \#main   $$SRC_DIR/modules/SliceRange/SliceRange.cpp \
  \#main   $$SRC_DIR/modules/SliceSeg/SegMethod.cpp \
  \#main   $$SRC_DIR/modules/SliceSeg/SliceSeg.cpp \
  \#main   $$SRC_DIR/modules/SliceSegEM/SliceSegEM.cpp \
  \#main   $$SRC_DIR/modules/SliceSegFCM/SliceSegFCM.cpp \
  \#main   $$SRC_DIR/modules/SliceSegHT/HistogramThresholding.cpp \
  \#main   $$SRC_DIR/modules/SliceSegHT/SliceSegHT.cpp \
  \#main   $$SRC_DIR/modules/SliceSegRG/RegionGrowing.cpp \
  \#main   $$SRC_DIR/modules/SliceSegRG/SliceSegRG.cpp \
  \#main   $$SRC_DIR/modules/SliceSegWatersheds/SliceSegWatersheds.cpp \
  \#main   $$SRC_DIR/modules/SliceSubsampling/SliceSubsampling.cpp \
  \#main   $$SRC_DIR/modules/SliceThresholding/SliceThresholding.cpp \
  \#main   $$SRC_DIR/modules/SliceView/SliceView.cpp \
  \#main   $$SRC_DIR/modules/VolumeBlending/VolumeBlending.cpp \
  \#main   $$SRC_DIR/modules/VolumeCut/VolumeCut.cpp \
  \#main   $$SRC_DIR/modules/VolumeEdgeDetector/VolumeEdgeDetector.cpp \
  \#main   $$SRC_DIR/modules/VolumeFilter/VolumeFilter.cpp \
  \#main   $$SRC_DIR/modules/VolumeHistEqualization/VolumeHistEqualization.cpp \
  \#main   $$SRC_DIR/modules/VolumeHistogram/VolumeHistogram.cpp \
  \#main   $$SRC_DIR/modules/VolumeInfo/VolumeInfo.cpp \
  \#main   $$SRC_DIR/modules/VolumeLandmarkDetector/VolumeLandmarkDetector.cpp \
  \#main   $$SRC_DIR/modules/VolumeRange/VolumeRange.cpp \
  \#main   $$SRC_DIR/modules/VolumeSeg/vSegMethod.cpp \
  \#main   $$SRC_DIR/modules/VolumeSeg/VolumeSeg.cpp \
  \#main   $$SRC_DIR/modules/VolumeSegEM/VolumeSegEM.cpp \
  \#main   $$SRC_DIR/modules/VolumeSegFCM/VolumeSegFCM.cpp \
  \#main   $$SRC_DIR/modules/VolumeSegHT/vHistogramThresholding.cpp \
  \#main   $$SRC_DIR/modules/VolumeSegHT/VolumeSegHT.cpp \
  \#main   $$SRC_DIR/modules/VolumeSegRG/vRegionGrowing.cpp \
  \#main   $$SRC_DIR/modules/VolumeSegRG/VolumeSegRG.cpp \
  \#main   $$SRC_DIR/modules/VolumeSplit/VolumeSplit.cpp \
  \#main   $$SRC_DIR/modules/VolumeSubsampling/VolumeSubsampling.cpp \
  \#main   $$SRC_DIR/modules/VolumeThresholding/VolumeThresholding.cpp \
  \#main   $$SRC_DIR/modules/VolumeView/VolumeView.cpp


#LIBS += -L$$TARGETSDIR


LIBS += -ljpeg -lpng

LIBS += -lz


