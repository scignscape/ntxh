
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



#INCLUDEPATH += \
#  ../../../ITKSkullStrip-master/include


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


#INCLUDEPATH += ../thirdparty/yaml-cpp/include


INCLUDEPATH +=   $$SRC_DIR/extra


HEADERS += \



SOURCES += \
  $$SRC_GROUP_DIR/CaPTk-applications/BraTSPipeline.cxx \



#LIBS += -L$${ITK_LIB_DIR} -lITKBioCell-$$ITK_VERSION_NUMBER
#LIBS += -L$${ITK_LIB_DIR} -lITKFEM-$$ITK_VERSION_NUMBER
#LIBS += -L$${ITK_LIB_DIR} -lITKIOMesh-$$ITK_VERSION_NUMBER
#LIBS += -L$${ITK_LIB_DIR} -litknetlib-$$ITK_VERSION_NUMBER
#LIBS += -L$${ITK_LIB_DIR} -lhdf5
#LIBS += -L$${ITK_LIB_DIR} -litkgdcmopenjpeg-$$ITK_VERSION_NUMBER


# ITK Libs
LIBS += -L$${ITK_LIB_DIR} -lITKBiasCorrection-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKDICOMParser-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOBMP-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOBioRad-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOCSV-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOGDCM-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOGE-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOGIPL-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOHDF5-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOJPEG-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOLSM-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOMRC-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOMeta-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIONIFTI-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIONRRD-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOPNG-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOSiemens-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOSpatialObjects-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOStimulate-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOTransformBase-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOTransformHDF5-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOTransformInsightLegacy-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOTransformMatlab-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOVTK-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKKLMRegionGrowing-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKLabelMap-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKMesh-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKOptimizers-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKOptimizersv4-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKPath-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKPolynomials-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKQuadEdgeMesh-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKSpatialObjects-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKStatistics-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKTransform-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKVNLInstantiation-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKVTK-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKVideoCore-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKVideoIO-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKWatersheds-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmMEXD-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litktestlib-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOTIFF-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKgiftiio-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKMetaIO-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKNrrdIO-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkpng-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOIPL-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOXML-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKTransformFactory-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkhdf5_cpp
LIBS += -L$${ITK_LIB_DIR} -litkNetlibSlatec-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkvnl_algo-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmMSFF-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmsocketxx-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litktiff-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKniftiio-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKIOImageBase-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkhdf5
LIBS += -L$${ITK_LIB_DIR} -litkvnl-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkv3p_netlib-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmDICT-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmcharls-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmuuid-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmjpeg8-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmjpeg16-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmjpeg12-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkjpeg-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKznz-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKCommon-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkvcl-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmIOD-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litksys-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkdouble-conversion-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmDSED-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -lITKEXPAT-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkgdcmCommon-$$ITK_VERSION_NUMBER
LIBS += -L$${ITK_LIB_DIR} -litkzlib-$$ITK_VERSION_NUMBER

#LIBS += -L/media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu \
# -lgdcmCommon -lgdcmDICT -lgdcmDSED -lgdcmIOD -lgdcmjpeg8 -lgdcmjpeg12 -lgdcmjpeg16 -lgdcmMEXD -lgdcmMSFF


LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmCommon.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmDICT.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmDSED.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmIOD.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmjpeg8.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmjpeg12.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmjpeg16.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmMEXD.so.3.0.7
LIBS += /media/mint/MainVolume/medInria/gdcm/libgdcm3.0_3.0.7-3+b2_amd64/usr/lib/x86_64-linux-gnu/libgdcmMSFF.so.3.0.7



LIBS += -ldl



