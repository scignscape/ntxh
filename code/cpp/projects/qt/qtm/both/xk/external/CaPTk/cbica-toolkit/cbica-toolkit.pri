
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

include($$ROOT_DIR/../preferred/itk.pri)


QT += network

TEMPLATE = lib


DEFINES += PROJECT_NAME=\\\"PROJECT_NAME\\\"
DEFINES += PROJECT_VERSION=\\\"PROJECT_VERSION\\\"

DEFINES += _OPENMP



INCLUDEPATH += \
  $$SRC_DIR/IO/inc \


INCLUDEPATH += $$SRC_GROUP_DIR/yaml-cpp/include \


 # if this doesn't work, set the correct path in itk.pri
INCLUDEPATH += \
  $$ITK_SRC_DIR/../ITKSkullStrip-master/include \


INCLUDEPATH +=  \
  $$ITK_BUILD_DIR/Modules/Core/Common \
  $$ITK_BUILD_DIR/Modules/ThirdParty/VNL/src/vxl/core \
  $$ITK_BUILD_DIR/Modules/ThirdParty/VNL/src/vxl/vcl \
  $$ITK_BUILD_DIR/Modules/IO/ImageBase \
  $$ITK_BUILD_DIR/Modules/ThirdParty/Eigen3/src \
  $$ITK_BUILD_DIR/Modules/ThirdParty/KWSys/src \
  $$ITK_BUILD_DIR/Modules/ThirdParty/GDCM/src/gdcm/Source/Common \


INCLUDEPATH +=  \
  $$ITK_SRC_DIR/Modules/ThirdParty/VNL/src/vxl/vcl \
  $$ITK_SRC_DIR/Modules/IO/ImageBase/include \
  $$ITK_SRC_DIR/Modules/ThirdParty/Eigen3/src \
  $$ITK_SRC_DIR/Modules/Filtering/ImageFilterBase/include \
  $$ITK_SRC_DIR/Modules/IO/GDCM/include \
  $$ITK_SRC_DIR/Modules/Filtering/DiffusionTensorImage/include \
  $$ITK_SRC_DIR/Modules/Core/SpatialObjects/include \
  $$ITK_SRC_DIR/Modules/Core/Transform/include \
  $$ITK_SRC_DIR/Modules/Core/ImageFunction/include \
  $$ITK_SRC_DIR/Modules/Filtering/Thresholding/include \
  $$ITK_SRC_DIR/Modules/ThirdParty/GDCM/src/gdcm/Source/DataDictionary \
  $$ITK_SRC_DIR/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition \
  $$ITK_SRC_DIR/Modules/ThirdParty/GDCM/src/gdcm/Source/Common \
  $$ITK_SRC_DIR/Modules/ThirdParty/GDCM/src/gdcm/Source/MediaStorageAndFileFormat \
  $$ITK_SRC_DIR/Modules/Filtering/ImageIntensity/include \
  $$ITK_SRC_DIR/Modules/Filtering/Smoothing/include \
  $$ITK_SRC_DIR/Modules/Numerics/Statistics/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageStatistics/include \
  $$ITK_SRC_DIR/Modules/Segmentation/RegionGrowing/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageGrid/include \
  $$ITK_SRC_DIR/Modules/Core/TestKernel/include \
  $$ITK_SRC_DIR/Modules/Registration/Common/include \
  $$ITK_SRC_DIR/Modules/Numerics/Optimizers/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageGradient/include \
  $$ITK_SRC_DIR/Modules/Core/ImageAdaptors/include \
  $$ITK_SRC_DIR/Modules/Filtering/MathematicalMorphology/include \
  $$ITK_SRC_DIR/Modules/Filtering/BinaryMathematicalMorphology/include \
  $$ITK_SRC_DIR/Modules/Filtering/AnisotropicSmoothing/include \
  $$ITK_SRC_DIR/Modules/Core/FiniteDifference/include \
  $$ITK_SRC_DIR/Modules/Segmentation/LevelSets/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageFeature/include \
  $$ITK_SRC_DIR/Modules/Filtering/DistanceMap/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageLabel/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageCompose/include \
  $$ITK_SRC_DIR/Modules/Core/Common/include \
  $$ITK_SRC_DIR/Modules/ThirdParty/VNL/src/vxl/core \
  $$ITK_SRC_DIR/Modules/IO/NRRD/include \


HEADERS += \
  $$SRC_DIR/IO/inc/DicomImageReader.h \
  $$SRC_DIR/IO/inc/DicomIOManager.h \
  $$SRC_DIR/IO/inc/DicomIOManager.hxx \
  $$SRC_DIR/IO/inc/DicomMetadataReader.h \
  $$SRC_DIR/IO/inc/DicomSeriesReader.h \
  $$SRC_DIR/cbicaCmdParser.h \
  $$SRC_DIR/cbicaDTIProcessingManager.h \
  $$SRC_DIR/cbicaITKImageInfo.h \
  $$SRC_DIR/cbicaITKSafeImageIO.h \
  $$SRC_DIR/cbicaITKUtilities.h \
  $$SRC_DIR/cbicaLogging.h \
  $$SRC_DIR/cbicaProgressBar.h \
  $$SRC_DIR/cbicaStatistics.h \
  $$SRC_DIR/cbicaUtilities.h \
  $$SRC_DIR/HausdorffDistance.h \
  $$SRC_DIR/HausdorffDistance.txx \


SOURCES += \
  $$SRC_DIR/IO/src/DicomImageReader.cpp \
  $$SRC_DIR/IO/src/DicomMetadataReader.cpp \
  $$SRC_DIR/IO/src/DicomSeriesReader.cpp \
  $$SRC_DIR/cbicaCmdParser.cpp \
  $$SRC_DIR/cbicaDTIProcessingManager.cpp \
  $$SRC_DIR/cbicaITKImageInfo.cpp \
  $$SRC_DIR/cbicaLogging.cpp \
  $$SRC_DIR/cbicaUtilities.cpp \


