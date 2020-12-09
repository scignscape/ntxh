
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

QT += widgets gui printsupport network opengl

CONFIG += c++14


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/flann.pri)


DEFINES += FORCE_EXS_JPEGProcess14SV1

#INCLUDEPATH += $$SRC_GROUP_DIR


DEFINES += _LINUX

DEFINES += assert\\(x\\)


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk
INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/Eigen

#INCLUDEPATH += $$SRC_DIR/ui/3dim/qtguimedi

# need openscenegraph installed ...

include($$ROOT_DIR/../preferred/osg.pri)
include($$ROOT_DIR/../preferred/openmesh.pri)
include($$ROOT_DIR/../preferred/openctm.pri)


INCLUDEPATH += $$SRC_DIR/3DimViewer/include

INCLUDEPATH += $$SRC_GROUP_DIR/openctm/lib

INCLUDEPATH += $$SRC_GROUP_DIR/openmesh/src


INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/coremedi_viewer
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/core
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/qtgui_viewer
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/coremedi
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/qtgui
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/graph
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/graphmedi_viewer
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/graphmedi
INCLUDEPATH += $$SRC_GROUP_DIR/threedimviewer/include/3dim/qtplugin



#3dim/core/data/



INCLUDEPATH += $$SRC_GROUP_DIR/vpl/include


# #  for dcmtk ...
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmdata/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcm-config/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/ofstd/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmimgle/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/oflog/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmjpeg/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmnet/include


RESOURCES += $$SRC_DIR/3DimViewer/resources.qrc



FORMS += \
  $$SRC_DIR/ui/CDataInfoDialog.ui \
  $$SRC_DIR/ui/CDicomTransferDialog.ui \
  $$SRC_DIR/ui/CFilterDialog.ui \
  $$SRC_DIR/ui/cinfodialog.ui \
  $$SRC_DIR/ui/cpreferencesdialog.ui \
  $$SRC_DIR/ui/CPreviewDialog.ui \
  $$SRC_DIR/ui/cseriesselectiondialog.ui \
  $$SRC_DIR/ui/cvolumelimiterdialog.ui \
  $$SRC_DIR/ui/densitywindowwidget.ui \
  $$SRC_DIR/ui/mainwindow.ui \
  $$SRC_DIR/ui/modelswidget.ui \
  $$SRC_DIR/ui/orthosliceswidget.ui \
  $$SRC_DIR/ui/segmentationwidget.ui \
  $$SRC_DIR/ui/volumerenderingwidget.ui \




HEADERS += \
  $$SRC_DIR/3DimViewer/include/AppConfigure.h \
  $$SRC_DIR/3DimViewer/include/AppVersion.h \
  $$SRC_DIR/3DimViewer/include/C3DimApplication.h \
  $$SRC_DIR/3DimViewer/include/CAppExamination.h \
  $$SRC_DIR/3DimViewer/include/CCustomUI.h \
  $$SRC_DIR/3DimViewer/include/CDataInfoDialog.h \
  $$SRC_DIR/3DimViewer/include/CDicomTransferDialog.h \
  $$SRC_DIR/3DimViewer/include/CFilterDialog.h \
  $$SRC_DIR/3DimViewer/include/cinfodialog.h \
  $$SRC_DIR/3DimViewer/include/CModelVisualizerEx.h \
  $$SRC_DIR/3DimViewer/include/cpreferencesdialog.h \
  $$SRC_DIR/3DimViewer/include/CPreviewDialog.h \
  $$SRC_DIR/3DimViewer/include/CPreviewDialogData.h \
  $$SRC_DIR/3DimViewer/include/CRegion3DPreviewManager.h \
  $$SRC_DIR/3DimViewer/include/CRegion3DPreviewVisualizer.h \
  $$SRC_DIR/3DimViewer/include/cseriesselectiondialog.h \
  $$SRC_DIR/3DimViewer/include/CSysInfo.h \
  $$SRC_DIR/3DimViewer/include/cvolumelimiterdialog.h \
  $$SRC_DIR/3DimViewer/include/CZipLoader.h \
  $$SRC_DIR/3DimViewer/include/densitywindowwidget.h \
  $$SRC_DIR/3DimViewer/include/mainwindow.h \
  $$SRC_DIR/3DimViewer/include/modelswidget.h \
  $$SRC_DIR/3DimViewer/include/orthosliceswidget.h \
  $$SRC_DIR/3DimViewer/include/qtcompat.h \
  $$SRC_DIR/3DimViewer/include/segmentationwidget.h \
  $$SRC_DIR/3DimViewer/include/Signals.h \
  $$SRC_DIR/3DimViewer/include/volumerenderingwidget.h \
  $$SRC_DIR/3DimViewer/include/zip/crypt.h \
  $$SRC_DIR/3DimViewer/include/zip/ioapi.h \
  $$SRC_DIR/3DimViewer/include/zip/iowin32.h \
  $$SRC_DIR/3DimViewer/include/zip/mztools.h \
  $$SRC_DIR/3DimViewer/include/zip/zip.h \


SOURCES += \
  $$SRC_DIR/3DimViewer/src/CAppExamination.cpp \
  $$SRC_DIR/3DimViewer/src/CCustomUI.cpp \
  $$SRC_DIR/3DimViewer/src/CDataInfoDialog.cpp \
  \# $$SRC_DIR/3DimViewer/src/CDicomTransferDialog.cpp \
  $$SRC_DIR/3DimViewer/src/CFilterDialog.cpp \
  $$SRC_DIR/3DimViewer/src/CModelVisualizerEx.cpp \
  $$SRC_DIR/3DimViewer/src/CPreviewDialog.cpp \
  $$SRC_DIR/3DimViewer/src/CRegion3DPreviewManager.cpp \
  $$SRC_DIR/3DimViewer/src/CRegion3DPreviewVisualizer.cpp \
  $$SRC_DIR/3DimViewer/src/CSysInfo.cpp \
  $$SRC_DIR/3DimViewer/src/cinfodialog.cpp \
  $$SRC_DIR/3DimViewer/src/cpreferencesdialog.cpp \
  $$SRC_DIR/3DimViewer/src/cseriesselectiondialog.cpp \
  $$SRC_DIR/3DimViewer/src/cvolumelimiterdialog.cpp \
  $$SRC_DIR/3DimViewer/src/densitywindowwidget.cpp \
  $$SRC_DIR/3DimViewer/src/main.cpp \
  $$SRC_DIR/3DimViewer/src/mainwindow.cpp \
  $$SRC_DIR/3DimViewer/src/modelswidget.cpp \
  $$SRC_DIR/3DimViewer/src/orthosliceswidget.cpp \
  $$SRC_DIR/3DimViewer/src/segmentationwidget.cpp \
  $$SRC_DIR/3DimViewer/src/volumerenderingwidget.cpp \
  $$SRC_DIR/3DimViewer/src/zip/ioapi.cpp \
  $$SRC_DIR/3DimViewer/src/zip/iowin32.cpp \
  $$SRC_DIR/3DimViewer/src/zip/mztools.cpp \
  $$SRC_DIR/3DimViewer/src/zip/unzip.cpp \
  $$SRC_DIR/3DimViewer/src/zip/zip.cpp


LIBS += -L$$TARGETSDIR -lthreedimviewer

LIBS += -L$$TARGETSDIR  -lopenmesh  -lopenctm


LIBS += -L$$TARGETSDIR -lvpl

message(t: $$TARGETSDIR)
LIBS += -L/home/nlevisrael/gits/ntxh/wip-sebi/ar/code/cpp/targets/qt/qt-multiple/uni/targets-5-15-2-uni-nomark \
  -ldcmdata -lofstd -loflog


#LIBS += $$OPENMESH_LIB_DIR/libOpenMeshCore.a
#LIBS += $$OPENMESH_LIB_DIR/libOpenMeshTools.a


message($$OSG_LIB_DIR)


LIBS += -L$$OSG_LIB_DIR \
  -losgWidget \
  -lOpenThreads \
  -losg \
  -losgAnimation \
  -losgDB \
  -losgFX \
  -losgGA \
  -losgManipulator \
  -losgParticle \
  -losgPresentation \
  -losgShadow \
  -losgSim \
  -losgTerrain \
  -losgText \
  -losgUI \
  -losgUtil \
  -losgViewer \
  -losgVolume \
  -losgWidget \


LIBS += -llz4

LIBS += -lz
