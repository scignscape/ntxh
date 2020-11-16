
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)


include($$ROOT_DIR/../preferred/itk.pri)
include($$ROOT_DIR/../preferred/vtk.pri)
include($$ROOT_DIR/../preferred/opencv.pri)

include($$ROOT_DIR/../preferred/vxl.pri)


QT += gui  widgets 

QT += webenginewidgets


TEMPLATE = app


DEFINES += PROJECT_NAME=\\\"PROJECT_NAME\\\"
DEFINES += PROJECT_VERSION=\\\"PROJECT_VERSION\\\"


DEFINES += PROJECT_SOURCE_DIR=\\\"PROJECT_SOURCE_DIR\\\"
DEFINES += PROJECT_BINARY_DIR=\\\"PROJECT_BINARY_DIR\\\"
DEFINES += CAPTK_STYLESHEET_FILE=\\\"CAPTK_STYLESHEET_FILE\\\"



DEFINES += _OPENMP


INCLUDEPATH += \
  $$SRC_GROUP_DIR/CaPTk-applications/Preprocessing/src/depends \
  $$SRC_GROUP_DIR/CaPTk-applications/common_includes \
  $$SRC_GROUP_DIR/CaPTk-applications/GeodesicTraining/src \
  $$SRC_GROUP_DIR/CaPTk-applications/GeodesicTraining/src/depends \
  $$SRC_GROUP_DIR/CaPTk-applications/WhiteStripe_includes


INCLUDEPATH += \
  $$SRC_GROUP_DIR/inc \
  $$SRC_GROUP_DIR/CaPTk-view/gui \
  $$SRC_GROUP_DIR/CaPTk-view/extra \



INCLUDEPATH += $$SRC_GROUP_DIR/yaml-cpp/include \


 # if this doesn't work, set the correct path in itk.pri
INCLUDEPATH += \
  $$ITK_SRC_DIR/../ITKSkullStrip-master/include \


INCLUDEPATH += \
  $$SRC_GROUP_DIR/CaPTk-common/inc \
  $$SRC_GROUP_DIR/cbica-toolkit \
  $$SRC_GROUP_DIR/cbica-toolkit/IO/inc \
  $$SRC_GROUP_DIR/applications \
  $$SRC_GROUP_DIR/applications/common_includes \
  $$SRC_GROUP_DIR/applications/Preprocessing/src/depends \
  $$SRC_GROUP_DIR/applications/GeodesicTraining/src/depends \
  $$SRC_GROUP_DIR/applications/GeodesicTraining/src \
  $$SRC_GROUP_DIR/applications/FeatureExtraction/src/depends \
  $$SRC_GROUP_DIR/applications/individualApps/sbrt_source/src/common_includes \
  $$SRC_GROUP_DIR/applications/WhiteStripe_includes \
  $$SRC_GROUP_DIR/applications/BreastTexturePipeline/src/depends \
  $$SRC_GROUP_DIR/applications/FeatureExtraction/src


INCLUDEPATH += \
  $$VTK_SRC_DIR/Common/Core \
  $$VTK_SRC_DIR/Utilities/KWIML \
  $$VTK_SRC_DIR/Common/Transforms \
  $$VTK_SRC_DIR/Common/Math \
  $$VTK_SRC_DIR/Interaction/Widgets \
  $$VTK_SRC_DIR/Rendering/Core \
  $$VTK_SRC_DIR/Interaction/Image \
  $$VTK_SRC_DIR/IO/Image \
  $$VTK_SRC_DIR/Common/ExecutionModel \
  $$VTK_SRC_DIR/Common/DataModel \
  $$VTK_SRC_DIR/GUISupport/Qt \
  $$VTK_SRC_DIR/Charts/Core \
  $$VTK_SRC_DIR/Rendering/Context2D \
  $$VTK_SRC_DIR/Views/Context2D \
  $$VTK_SRC_DIR/Views/Core \
  $$VTK_SRC_DIR/Rendering/OpenGL2 \
  $$VTK_SRC_DIR/Interaction/Style \
  $$VTK_SRC_DIR/Filters/Sources \
  $$VTK_SRC_DIR/Filters/General \
  $$VTK_SRC_DIR/Rendering/Annotation \
  $$VTK_SRC_DIR/Imaging/Color \
  $$VTK_SRC_DIR/Imaging/Core \
  $$VTK_SRC_DIR/Filters/Core \
  $$VTK_SRC_DIR/Rendering/Label \
  $$VTK_SRC_DIR/Common/Misc \
  $$VTK_SRC_DIR/Imaging/Statistics \
  $$VTK_SRC_DIR/Filters/Statistics \


INCLUDEPATH += \
  $$VTK_BUILD_DIR/Common/Core \
  $$VTK_BUILD_DIR/Common/Transforms \
  $$VTK_BUILD_DIR/Common/Math \
  $$VTK_BUILD_DIR/Rendering/Core \
  $$VTK_BUILD_DIR/Filters/Core \
  $$VTK_BUILD_DIR/Interaction/Widgets \
  $$VTK_BUILD_DIR/Interaction/Image \
  $$VTK_BUILD_DIR/IO/Image \
  $$VTK_BUILD_DIR/Common/ExecutionModel \
  $$VTK_BUILD_DIR/Common/DataModel \
  $$VTK_BUILD_DIR/Interaction/Style \
  $$VTK_BUILD_DIR/Rendering/OpenGL2 \
  $$VTK_BUILD_DIR/Rendering/UI \
  $$VTK_BUILD_DIR/Charts/Core \
  $$VTK_BUILD_DIR/Rendering/Context2D \
  $$VTK_BUILD_DIR/Views/Core \
  $$VTK_BUILD_DIR/Views/Context2D \
  $$VTK_BUILD_DIR/Utilities/KWSys \
  $$VTK_BUILD_DIR/Filters/Sources \
  $$VTK_BUILD_DIR/Filters/General \
  $$VTK_BUILD_DIR/Rendering/Annotation \
  $$VTK_BUILD_DIR/Imaging/Core \
  $$VTK_BUILD_DIR/Imaging/Color \
  $$VTK_BUILD_DIR/Rendering/Label \
  $$VTK_BUILD_DIR/Common/Misc \
  $$VTK_BUILD_DIR/Imaging/Statistics \
  $$VTK_BUILD_DIR/Filters/Statistics \


INCLUDEPATH += \
  $$OPENCV_SRC_DIR/modules/core/include \
  $$OPENCV_SRC_DIR/modules/ml/include \
  $$OPENCV_SRC_DIR/include \
  $$OPENCV_SRC_DIR/modules/calib3d/include \
  $$OPENCV_SRC_DIR/modules/features2d/include \
  $$OPENCV_SRC_DIR/modules/flann/include \
  $$OPENCV_SRC_DIR/modules/dnn/include \
  $$OPENCV_SRC_DIR/modules/highgui/include \
  $$OPENCV_SRC_DIR/modules/imgcodecs/include \
  $$OPENCV_SRC_DIR/modules/videoio/include \
  $$OPENCV_SRC_DIR/modules/imgproc/include \
  $$OPENCV_SRC_DIR/modules/objdetect/include \
  $$OPENCV_SRC_DIR/modules/photo/include \
  $$OPENCV_SRC_DIR/modules/stitching/include \
  $$OPENCV_SRC_DIR/modules/video/include \


INCLUDEPATH += \ 
  $$OPENCV_BUILD_DIR


INCLUDEPATH += \ 
  $$ITK_BUILD_DIR/Modules/Core/Common \
  $$ITK_BUILD_DIR/Modules/ThirdParty/VNL/src/vxl/core \
  $$ITK_BUILD_DIR/Modules/ThirdParty/VNL/src/vxl/vcl \
  $$ITK_BUILD_DIR/Modules/IO/ImageBase \
  $$ITK_BUILD_DIR/Modules/ThirdParty/Eigen3/src \
  $$ITK_BUILD_DIR/Modules/ThirdParty/KWSys/src \
  $$ITK_BUILD_DIR/Modules/ThirdParty/GDCM/src/gdcm/Source/Common \
  $$ITK_BUILD_DIR/Modules/Core/Common \


INCLUDEPATH += \ 
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
  $$ITK_SRC_DIR/Modules/IO/NIFTI/include \
  $$ITK_SRC_DIR/Modules/IO/CSV/include \
  $$ITK_SRC_DIR/Modules/Filtering/LabelMap/include \
  $$ITK_SRC_DIR/Modules/Segmentation/ConnectedComponents/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageFusion/include \
  $$ITK_SRC_DIR/Modules/Bridge/VtkGlue/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageSources/include \
  $$ITK_SRC_DIR/Modules/Video/BridgeOpenCV/include \
  $$ITK_SRC_DIR/Modules/Bridge/VTK/include \
  $$ITK_SRC_DIR/Modules/Filtering/BiasCorrection/include \
  $$ITK_SRC_DIR/Modules/ThirdParty/Eigen3/src/itkeigen \
  $$ITK_SRC_DIR/Modules/Nonunit/Review/include \
  $$ITK_SRC_DIR/Modules/Filtering/FFT/include \
  $$ITK_SRC_DIR/Modules/IO/NRRD/include \
  $$ITK_SRC_DIR/Modules/Filtering/ImageCompare/include \
  $$ITK_SRC_DIR/Modules/IO/XML/include \
  $$ITK_SRC_DIR/Modules/Core/Common/include \
  $$ITK_SRC_DIR/Modules/ThirdParty/VNL/src/vxl/core \



INCLUDEPATH +=   $$SRC_DIR/extra


INCLUDEPATH +=   $$SRC_PROSET_DIR/vxl/vxl-v3p



HEADERS += \



SOURCES += \
  $$SRC_GROUP_DIR/CaPTk-applications/BraTSPipeline.cxx \


LIBS += -L$$TARGETSDIR  -lgdcm-common -lgdcm-dict -lgdcm-dsed -lgdcm-iod -lgdcm-mexd -lgdcm-msff -lgdcm-openjp2 \
  -lcbica-toolkit -lyaml-cpp


# ITK Libs
LIBS += -L$${ITK_LIB_DIR} \
  -lITKBiasCorrection-$$ITK_VERSION_NUMBER  \ 
  -lITKDICOMParser-$$ITK_VERSION_NUMBER  \ 
  -lITKIOBMP-$$ITK_VERSION_NUMBER  \ 
  -lITKIOBioRad-$$ITK_VERSION_NUMBER  \ 
  -lITKIOCSV-$$ITK_VERSION_NUMBER  \ 
  -lITKIOGDCM-$$ITK_VERSION_NUMBER  \ 
  -lITKIOGE-$$ITK_VERSION_NUMBER  \ 
  -lITKIOGIPL-$$ITK_VERSION_NUMBER  \ 
  -lITKIOHDF5-$$ITK_VERSION_NUMBER  \ 
  -lITKIOJPEG-$$ITK_VERSION_NUMBER  \ 
  -lITKIOLSM-$$ITK_VERSION_NUMBER  \ 
  -lITKIOMRC-$$ITK_VERSION_NUMBER  \ 
  -lITKIOMeta-$$ITK_VERSION_NUMBER  \ 
  -lITKIONIFTI-$$ITK_VERSION_NUMBER  \ 
  -lITKIONRRD-$$ITK_VERSION_NUMBER  \ 
  -lITKIOPNG-$$ITK_VERSION_NUMBER  \ 
  -lITKIOSiemens-$$ITK_VERSION_NUMBER  \ 
  -lITKIOSpatialObjects-$$ITK_VERSION_NUMBER  \ 
  -lITKIOStimulate-$$ITK_VERSION_NUMBER  \ 
  -lITKIOTransformBase-$$ITK_VERSION_NUMBER  \ 
  -lITKIOTransformHDF5-$$ITK_VERSION_NUMBER  \ 
  -lITKIOTransformInsightLegacy-$$ITK_VERSION_NUMBER  \ 
  -lITKIOTransformMatlab-$$ITK_VERSION_NUMBER  \ 
  -lITKIOVTK-$$ITK_VERSION_NUMBER  \ 
  -lITKKLMRegionGrowing-$$ITK_VERSION_NUMBER  \ 
  -lITKLabelMap-$$ITK_VERSION_NUMBER  \ 
  -lITKMesh-$$ITK_VERSION_NUMBER  \ 
  -lITKOptimizers-$$ITK_VERSION_NUMBER  \ 
  -lITKOptimizersv4-$$ITK_VERSION_NUMBER  \ 
  -lITKPath-$$ITK_VERSION_NUMBER  \ 
  -lITKPolynomials-$$ITK_VERSION_NUMBER  \ 
  -lITKQuadEdgeMesh-$$ITK_VERSION_NUMBER  \ 
  -lITKStatistics-$$ITK_VERSION_NUMBER  \ 
  -lITKTransform-$$ITK_VERSION_NUMBER  \ 
  -lITKVNLInstantiation-$$ITK_VERSION_NUMBER  \ 
  -lITKVTK-$$ITK_VERSION_NUMBER  \ 
  -lITKVideoCore-$$ITK_VERSION_NUMBER  \ 
  -lITKVideoIO-$$ITK_VERSION_NUMBER  \ 
  -lITKWatersheds-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmMEXD-$$ITK_VERSION_NUMBER  \ 
  -litktestlib-$$ITK_VERSION_NUMBER  \ 
  -lITKIOTIFF-$$ITK_VERSION_NUMBER  \ 
  -lITKgiftiio-$$ITK_VERSION_NUMBER  \ 
  -lITKMetaIO-$$ITK_VERSION_NUMBER  \ 
  -lITKNrrdIO-$$ITK_VERSION_NUMBER  \ 
  -litkpng-$$ITK_VERSION_NUMBER  \ 
  -lITKIOIPL-$$ITK_VERSION_NUMBER  \ 
  -lITKIOXML-$$ITK_VERSION_NUMBER  \ 
  -lITKTransformFactory-$$ITK_VERSION_NUMBER  \ 
  -litkhdf5_cpp \
  -litkNetlibSlatec-$$ITK_VERSION_NUMBER  \ 
  -litkvnl_algo-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmMSFF-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmsocketxx-$$ITK_VERSION_NUMBER  \ 
  -litktiff-$$ITK_VERSION_NUMBER  \ 
  -lITKniftiio-$$ITK_VERSION_NUMBER  \ 
  -lITKIOImageBase-$$ITK_VERSION_NUMBER  \ 
  -litkhdf5 \
  -litkvnl-$$ITK_VERSION_NUMBER  \ 
  -litkv3p_netlib-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmDICT-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmcharls-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmuuid-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmjpeg8-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmjpeg16-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmjpeg12-$$ITK_VERSION_NUMBER  \ 
  -litkjpeg-$$ITK_VERSION_NUMBER  \ 
  -lITKznz-$$ITK_VERSION_NUMBER  \ 
  -lITKCommon-$$ITK_VERSION_NUMBER  \ 
  -litkvcl-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmIOD-$$ITK_VERSION_NUMBER  \ 
  -litksys-$$ITK_VERSION_NUMBER  \ 
  -litkdouble-conversion-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmDSED-$$ITK_VERSION_NUMBER  \ 
  -lITKEXPAT-$$ITK_VERSION_NUMBER  \ 
  -litkgdcmCommon-$$ITK_VERSION_NUMBER  \ 
  -litkzlib-$$ITK_VERSION_NUMBER  \
  -lITKSpatialObjects-$$ITK_VERSION_NUMBER  \
  -lITKTransform-$$ITK_VERSION_NUMBER  \


LIBS += $$TARGETSDIR/libgdcm-openjp2.a

LIBS += -ldl 


LIBS += -L$$VXL_LIB_DIR \
  -lnetlib \
  -lv3p_netlib \
  -lvbl \
  -lvcl \
  -lvgl \
  -lvgl_algo \
  -lvil \
  -lvnl \
  -lvnl_algo \
  -lvpl \
  -lvul \


LIBS += -lgomp

