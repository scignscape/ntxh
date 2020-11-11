
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)


QT += network

TEMPLATE = lib


DEFINES += PROJECT_NAME=\\\"PROJECT_NAME\\\"
DEFINES += PROJECT_VERSION=\\\"PROJECT_VERSION\\\"

DEFINES += _OPENMP



INCLUDEPATH += \
  ../cbica_toolkit/src \
  ../cbica_toolkit/src/IO/inc \



INCLUDEPATH += \
  ../../../ITKSkullStrip-master/include


#   configs

# 

INCLUDEPATH += ../../../ITK-build/Modules/Core/Common
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/VNL/src/vxl/core
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/VNL/src/vxl/vcl
INCLUDEPATH += ../../../ITK-build/Modules/IO/ImageBase
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/Eigen3/src
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/KWSys/src
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/GDCM/src/gdcm/Source/Common
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 



INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/VNL/src/vxl/vcl
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/IO/ImageBase/include/
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/Eigen3/src
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageFilterBase/include/
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/IO/GDCM/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/DiffusionTensorImage/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/SpatialObjects/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/Transform/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/ImageFunction/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/Thresholding/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/GDCM/src/gdcm/Source/DataDictionary
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/GDCM/src/gdcm/Source/Common
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/GDCM/src/gdcm/Source/MediaStorageAndFileFormat
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageIntensity/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/Smoothing/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Numerics/Statistics/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageStatistics/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Segmentation/RegionGrowing/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageGrid/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/TestKernel/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Registration/Common/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Numerics/Optimizers/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageGradient/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/ImageAdaptors/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/MathematicalMorphology/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/BinaryMathematicalMorphology/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/AnisotropicSmoothing/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/FiniteDifference/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Segmentation/LevelSets/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageFeature/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/DistanceMap/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageLabel/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageCompose/include
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 













INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/Common/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/VNL/src/vxl/core

INCLUDEPATH += ../thirdparty/yaml-cpp/include


# cbicaUtilities.h

HEADERS += \
  ../cbica_toolkit/src/IO/inc/DicomImageReader.h \
  ../cbica_toolkit/src/IO/inc/DicomIOManager.h \
  ../cbica_toolkit/src/IO/inc/DicomIOManager.hxx \
  ../cbica_toolkit/src/IO/inc/DicomMetadataReader.h \
  ../cbica_toolkit/src/IO/inc/DicomSeriesReader.h \
  ../cbica_toolkit/src/cbicaCmdParser.h \
  ../cbica_toolkit/src/cbicaDTIProcessingManager.h \
  ../cbica_toolkit/src/cbicaITKImageInfo.h \
  ../cbica_toolkit/src/cbicaITKSafeImageIO.h \
  ../cbica_toolkit/src/cbicaITKUtilities.h \
  ../cbica_toolkit/src/cbicaLogging.h \
  ../cbica_toolkit/src/cbicaProgressBar.h \
  ../cbica_toolkit/src/cbicaStatistics.h \
  ../cbica_toolkit/src/cbicaUtilities.h \
  ../cbica_toolkit/src/HausdorffDistance.h \
  ../cbica_toolkit/src/HausdorffDistance.txx \


SOURCES += \
  ../cbica_toolkit/src/IO/src/DicomImageReader.cpp \
  ../cbica_toolkit/src/IO/src/DicomMetadataReader.cpp \
  ../cbica_toolkit/src/IO/src/DicomSeriesReader.cpp \
  ../cbica_toolkit/src/cbicaCmdParser.cpp \
  ../cbica_toolkit/src/cbicaDTIProcessingManager.cpp \
  ../cbica_toolkit/src/cbicaITKImageInfo.cpp \
  ../cbica_toolkit/src/cbicaLogging.cpp \
  ../cbica_toolkit/src/cbicaUtilities.cpp \


