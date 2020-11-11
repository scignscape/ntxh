
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)


QT += gui  widgets 

QT += webenginewidgets


TEMPLATE = lib


DEFINES += PROJECT_NAME=\\\"PROJECT_NAME\\\"
DEFINES += PROJECT_VERSION=\\\"PROJECT_VERSION\\\"


DEFINES += PROJECT_SOURCE_DIR=\\\"PROJECT_SOURCE_DIR\\\"
DEFINES += PROJECT_BINARY_DIR=\\\"PROJECT_BINARY_DIR\\\"
DEFINES += CAPTK_STYLESHEET_FILE=\\\"CAPTK_STYLESHEET_FILE\\\"





DEFINES += _OPENMP



INCLUDEPATH += \
  ../view \
  ../view/gui \
  ../common/inc \
  ../cbica_toolkit/src \
  ../applications/common_includes \
  ../cbica_toolkit/src/IO/inc \
  ../applications \
  ../applications/Preprocessing/src/depends \
  ../applications/GeodesicTraining/src/depends \
  ../applications/GeodesicTraining/src \
  ../applications/FeatureExtraction/src/depends \
  ../applications/individualApps/sbrt_source/src/common_includes \
  ../applications/WhiteStripe_includes \
  ../applications/BreastTexturePipeline/src/depends \
  ../applications/FeatureExtraction/src



INCLUDEPATH += \
  ../../../ITKSkullStrip-master/include


INCLUDEPATH += \
  ../../../VTK-9.0.1/Common/Core \
  ../../../VTK-9.0.1/Utilities/KWIML \
  ../../../VTK-9.0.1/Common/Transforms \
  ../../../VTK-9.0.1/Common/Math \
  ../../../VTK-9.0.1/Interaction/Widgets \
  ../../../VTK-9.0.1/Rendering/Core \
  ../../../VTK-9.0.1/Interaction/Image \
  ../../../VTK-9.0.1/IO/Image \
  ../../../VTK-9.0.1/Common/ExecutionModel \
  ../../../VTK-9.0.1/Common/DataModel \
  ../../../VTK-9.0.1/GUISupport/Qt \
  ../../../VTK-9.0.1/Charts/Core \
  ../../../VTK-9.0.1/Rendering/Context2D \
  ../../../VTK-9.0.1/Views/Context2D \
  ../../../VTK-9.0.1/Views/Core \
  ../../../VTK-9.0.1/Rendering/OpenGL2 \
  ../../../VTK-9.0.1/Interaction/Style \
  ../../../VTK-9.0.1/Filters/Sources \
  ../../../VTK-9.0.1/Filters/General \
  ../../../VTK-9.0.1/Rendering/Annotation \
  ../../../VTK-9.0.1/Imaging/Color \
  ../../../VTK-9.0.1/Imaging/Core \
  ../../../VTK-9.0.1/Filters/Core \
  ../../../VTK-9.0.1/Rendering/Label \
  ../../../VTK-9.0.1/Common/Misc \
  ../../../VTK-9.0.1/Imaging/Statistics \
  ../../../VTK-9.0.1/Filters/Statistics \


INCLUDEPATH += \
  ../../../VTK-build/Common/Core \
  ../../../VTK-build/Common/Transforms \
  ../../../VTK-build/Common/Math \
  ../../../VTK-build/Rendering/Core \
  ../../../VTK-build/Filters/Core \
  ../../../VTK-build/Interaction/Widgets \
  ../../../VTK-build/Interaction/Image \
  ../../../VTK-build/IO/Image \
  ../../../VTK-build/Common/ExecutionModel \
  ../../../VTK-build/Common/DataModel \
  ../../../VTK-build/Interaction/Style \
  ../../../VTK-build/Rendering/OpenGL2 \
  ../../../VTK-build/Rendering/UI \
  ../../../VTK-build/Charts/Core \
  ../../../VTK-build/Rendering/Context2D \
  ../../../VTK-build/Views/Core \
  ../../../VTK-build/Views/Context2D \
  ../../../VTK-build/Utilities/KWSys \
  ../../../VTK-build/Filters/Sources \
  ../../../VTK-build/Filters/General \
  ../../../VTK-build/Rendering/Annotation \
  ../../../VTK-build/Imaging/Core \
  ../../../VTK-build/Imaging/Color \
  ../../../VTK-build/Rendering/Label \
  ../../../VTK-build/Common/Misc \
  ../../../VTK-build/Imaging/Statistics \
  ../../../VTK-build/Filters/Statistics \


#  ../../../VTK-build/Common/Core \


INCLUDEPATH += \
  ../../../opencv-master/modules/core/include \
  ../../../opencv-master/modules/ml/include \
  ../../../opencv-master/include \
  ../../../opencv-master/modules/calib3d/include \
  ../../../opencv-master/modules/features2d/include \
  ../../../opencv-master/modules/flann/include \
  ../../../opencv-master/modules/dnn/include \
  ../../../opencv-master/modules/highgui/include \
  ../../../opencv-master/modules/imgcodecs/include \
  ../../../opencv-master/modules/videoio/include \
  ../../../opencv-master/modules/imgproc/include \
  ../../../opencv-master/modules/objdetect/include \
  ../../../opencv-master/modules/photo/include \
  ../../../opencv-master/modules/stitching/include \
  ../../../opencv-master/modules/video/include \





INCLUDEPATH += \ 
  ../../../OpenCV-Build


#   configs

# 

INCLUDEPATH += ../../../ITK-build/Modules/Core/Common
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/VNL/src/vxl/core
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/VNL/src/vxl/vcl
INCLUDEPATH += ../../../ITK-build/Modules/IO/ImageBase
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/Eigen3/src
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/KWSys/src
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/GDCM/src/gdcm/Source/Common
INCLUDEPATH += ../../../ITK-build/Modules/Core/Common
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
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/IO/NIFTI/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/IO/CSV/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/LabelMap/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Segmentation/ConnectedComponents/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageFusion/include 
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Bridge/VtkGlue/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageSources/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Video/BridgeOpenCV/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Bridge/VTK/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/BiasCorrection/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/Eigen3/src/itkeigen
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Nonunit/Review/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/FFT/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/IO/NRRD/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Filtering/ImageCompare/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/IO/XML/include
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 
INCLUDEPATH += 






INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/Common/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/VNL/src/vxl/core

INCLUDEPATH += ../thirdparty/yaml-cpp/include


INCLUDEPATH += ../view/extra


HEADERS += \
  ../view/gui/AppearancePage.h \
  ../view/gui/ApplicationBase.h \
  ../view/gui/ApplicationPreferences.h \
  ../view/gui/ASyncAppManager.h \
  ../view/gui/CaPTkDockWidget.h \
  ../view/gui/CheckOpenGLVersion.h \
  ../view/gui/ComparisonViewerCommand.h \
  ../view/gui/DicomReader.h \
  ../view/gui/fBiasCorrectionDialog.h \
  ../view/gui/fBottomImageInfoTip.h \
  ../view/gui/fBraTSSegmentation.h \
  ../view/gui/fDCM2NIfTI.h \
  ../view/gui/fDeepMedicDialog.h \
  ../view/gui/fDeepMedicNormDialog.h \
  ../view/gui/fDiffusionMeasuresDialog.h \
  ../view/gui/fDirectionalityDialog.h \
  ../view/gui/fDrawingPanel.h \
  ../view/gui/fEGFRvIIIDialog.h \
  ../view/gui/fFeatureDialog.h \
  ../view/gui/fFeaturePanel.h \
  ../view/gui/fFetalBrain.h \
  ../view/gui/fHelpAppDialog.h \
  ../view/gui/fHelpDialog.h \
  ../view/gui/fHelpTutorial.h \
  ../view/gui/fHistoMatchDialog.h \
  ../view/gui/fImagesPanel.h \
  ../view/gui/fImagingSubtypeDialog.h \
  ../view/gui/fLungFieldDialog.h \
  ../view/gui/fMainWindow.h \
  ../view/gui/fMolecularSubtypeDialog.h \
  ../view/gui/fPCADialog.h \
  ../view/gui/fPerfusionAlignmentDialog.h \
  ../view/gui/fPerfusionMeasuresDialog.h \
  ../view/gui/fPopulationAtlasDialog.h \
  ../view/gui/fPreprocessingDialog.h \
  ../view/gui/fProgressDialog.h \
  ../view/gui/fPseudoProgressionDialog.h \
  ../view/gui/fRecurrenceDialog.h \
  ../view/gui/fRegistrationDialog.h \
  ../view/gui/fSBRTAnalysisDialog.h \
  ../view/gui/fSBRTNoduleDialog.h \
  \# ../view/gui/fSegmentationPanel.h \
  ../view/gui/fSkullStripDialog.h \
  ../view/gui/fSurvivalDialog.h \
  ../view/gui/fTexturePipelineDialog.h \
  ../view/gui/fTrainingDialog.h \
  ../view/gui/fTumorPanel.h \
  ../view/gui/fWhiteStripeDialog.h \
  ../view/gui/InteractorStyleNavigator.h \
  ../view/gui/IPreferencePage.h \
  ../view/gui/Landmarks.h \
  ../view/gui/OutputInteractorStyleNavigator.h \
  ../view/gui/PreferencesDialog.h \
  ../view/gui/QBorderWidget.h \
  ../view/gui/QTablePushButton.h \
  ../view/gui/SimpleImageManager.h \
  ../view/gui/Slicer.h \
  ../view/gui/SlicerManager.h \
  ../view/gui/SlicerManagerCommand.h \
  ../view/gui/SystemInformation.h \
  ../view/gui/SystemInformationDisplayWidget.h \
  ../view/gui/ui_AppearancePage.h \
  ../view/gui/ui_ApplicationBase.h \
  ../view/gui/ui_fBiasCorrectionDialog.h \
  ../view/gui/ui_fBottomImageInfoTip.h \
  ../view/gui/ui_fBraTSSegmentation.h \
  ../view/gui/ui_fDCM2NIfTI.h \
  ../view/gui/ui_fDeepMedicDialog.h \
  ../view/gui/ui_fDeepMedicNormDialog.h \
  ../view/gui/ui_fDiffusionMeasuresDialog.h \
  ../view/gui/ui_fDirectionalityDialog.h \
  ../view/gui/ui_fDrawingPanel.h \
  ../view/gui/ui_fEGFRvIIIDialog.h \
  ../view/gui/ui_fFeatureDialog.h \
  ../view/gui/ui_fFeaturePanel.h \
  ../view/gui/ui_fFetalBrain.h \
  ../view/gui/ui_fHelpAppDialog.h \
  ../view/gui/ui_fHelpDialog.h \
  ../view/gui/ui_fHistoMatchDialog.h \
  ../view/gui/ui_fImagesPanel.h \
  ../view/gui/ui_fImagingSubtypeDialog.h \
  ../view/gui/ui_fLungFieldDialog.h \
  ../view/gui/ui_fMainWindow.h \
  ../view/gui/ui_fMolecularSubtypeDialog.h \
  ../view/gui/ui_fPCADialog.h \
  ../view/gui/ui_fPerfusionAlignmentDialog.h \
  ../view/gui/ui_fPerfusionMeasuresDialog.h \
  ../view/gui/ui_fPopulationAtlasDialog.h \
  ../view/gui/ui_fPreprocessingDialog.h \
  ../view/gui/ui_fProgressDialog.h \
  ../view/gui/ui_fPseudoProgressionDialog.h \
  ../view/gui/ui_fRecurrenceDialog.h \
  ../view/gui/ui_fRegistrationDialog.h \
  ../view/gui/ui_fSBRTAnalysisDialog.h \
  ../view/gui/ui_fSBRTNoduleDialog.h \
  ../view/gui/ui_fSegmentationPanel.h \
  ../view/gui/ui_fSkullStripDialog.h \
  ../view/gui/ui_fSurvivalDialog.h \
  ../view/gui/ui_fTexturePipelineDialog.h \
  ../view/gui/ui_fTrainingDialog.h \
  ../view/gui/ui_fTumorPanel.h \
  ../view/gui/ui_fWhiteStripeDialog.h \
  ../view/gui/ui_QTablePushButton.h \
  ../view/gui/ui_SlicerManager.h \



SOURCES += \
  ../view/gui/AppearancePage.cpp \
  ../view/gui/ApplicationBase.cpp \
  ../view/gui/ApplicationPreferences.cpp \
  \# ../view/gui/ASyncAppManager.cpp \
  ../view/gui/CaPTkDockWidget.cpp \
  ../view/gui/CheckOpenGLVersion.cpp \
  \# ../view/gui/ComparisonViewerCommand.cpp \
  ../view/gui/DicomReader.cpp \
  ../view/gui/fBiasCorrectionDialog.cpp \
  ../view/gui/fBottomImageInfoTip.cpp \
  ../view/gui/fBraTSSegmentation.cpp \
  ../view/gui/fDCM2NIfTI.cpp \
  ../view/gui/fDeepMedicDialog.cpp \
  ../view/gui/fDeepMedicNormDialog.cpp \
  ../view/gui/fDiffusionMeasuresDialog.cpp \
  ../view/gui/fDirectionalityDialog.cpp \
  \# ../view/gui/fDrawingPanel.cpp \
  ../view/gui/fEGFRvIIIDialog.cpp \
  ../view/gui/fFeatureDialog.cpp \
  \#../view/gui/fFeaturePanel.cpp \
  ../view/gui/fFetalBrain.cpp \
  ../view/gui/fHelpAppDialog.cpp \
  ../view/gui/fHelpDialog.cpp \
  ../view/gui/fHelpTutorial.cpp \
  ../view/gui/fHistoMatchDialog.cpp \
  ../view/gui/fImagesPanel.cpp \
  ../view/gui/fImagingSubtypeDialog.cpp \
  ../view/gui/fLungFieldDialog.cpp \
  \# ../view/gui/fMainWindow.cpp \
  ../view/gui/fMolecularSubtypeDialog.cpp \
  ../view/gui/fPCADialog.cpp \
  ../view/gui/fPerfusionAlignmentDialog.cpp \
  ../view/gui/fPerfusionMeasuresDialog.cpp \
  ../view/gui/fPopulationAtlasDialog.cpp \
  ../view/gui/fPreprocessingDialog.cpp \
  ../view/gui/fProgressDialog.cpp \
  ../view/gui/fPseudoProgressionDialog.cpp \
  ../view/gui/fRecurrenceDialog.cpp \
  ../view/gui/fRegistrationDialog.cpp \
  ../view/gui/fSBRTAnalysisDialog.cpp \
  ../view/gui/fSBRTNoduleDialog.cpp \
  ../view/gui/fSkullStripDialog.cpp \
  ../view/gui/fSurvivalDialog.cpp \
  ../view/gui/fTexturePipelineDialog.cpp \
  ../view/gui/fTrainingDialog.cpp \
  \# ../view/gui/fTumorPanel.cpp \
  ../view/gui/fWhiteStripeDialog.cpp \
  ../view/gui/InteractorStyleNavigator.cpp \
  ../view/gui/IPreferencePage.cpp \
  ../view/gui/Landmarks.cpp \
  ../view/gui/PreferencesDialog.cpp \
  ../view/gui/QTablePushButton.cpp \
  ../view/gui/SimpleImageManager.cpp \
  ../view/gui/Slicer.cpp \
  ../view/gui/SlicerManager.cpp \
  \# ../view/gui/SlicerManagerCommand.cpp \
  ../view/gui/SystemInformation.cpp \
  ../view/gui/SystemInformationDisplayWidget.cpp \
  ../view/gui/fSegmentationPanel.cpp \



