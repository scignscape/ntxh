
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT += widgets core

#QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/gui.pri)


TEMPLATE = app

INCLUDEPATH += $$SRC_GROUP_DIR  $$SRC_DIR/gui \

INCLUDEPATH += $$SRC_PROSET_DIR/cytoLib
INCLUDEPATH += $$SRC_PROSET_DIR/cytoLib/qcytolib/include

INCLUDEPATH += $$SRC_PROSET_DIR/cytoLib/qcytolib/hdf5
INCLUDEPATH += $$SRC_PROSET_DIR/cytoLib/qcytolib/hdf5/c

HEADERS += \
  $$SRC_DIR/gui/MainWindow.h  \
  $$SRC_DIR/gui/DatasetListWidget.h  \
  $$SRC_DIR/gui/GatesListWidget.h \
  $$SRC_DIR/gates/gate-info.h \
  $$SRC_DIR/gates/measure/GateMeasure.h \
  $$SRC_DIR/gates/measure/GateMeasureMean.h \
  $$SRC_DIR/gui/view/ViewWidget.h \
  $$SRC_DIR/gui/view/tool/ViewTool.h \
  $$SRC_DIR/gui/view/tool/ViewToolDrawEllipse.h \
  $$SRC_DIR/gui/view/tool/ViewToolDrawSelect.h \
  $$SRC_DIR/gui/view/tool/ViewToolDrawRange.h \
  $$SRC_DIR/gui/view/tool/ViewToolDrawRect.h \
  $$SRC_DIR/gui/view/tool/ViewToolDrawPoly.h \
  $$SRC_DIR/gui/panes/ViewsPane.h \



SOURCES +=  \
  $$SRC_DIR/stubs.cpp \
  $$SRC_DIR/gui/MainWindow.cpp  \
  $$SRC_DIR/gui/ViewsListWidget.cpp  \
  $$SRC_DIR/gui/QtProgramInfo.cpp  \
  $$SRC_DIR/gui/ProfileChannelWidget.cpp  \
  $$SRC_DIR/gui/GraphExportWindow.cpp  \
  $$SRC_DIR/gui/GatesListWidget.cpp \   # skip calc thread ...
  $$SRC_DIR/gui/FacsanaduProject.cpp \
  $$SRC_DIR/gui/DialogAbout.cpp \
  $$SRC_DIR/gui/DatasetListWidget.cpp \
  $$SRC_DIR/gui/AddMeasureDialog.cpp \
  $$SRC_DIR/gui/view/ViewWidget.cpp \
  $$SRC_DIR/gui/view/tool/ViewToolChoice.cpp \
  $$SRC_DIR/gui/view/ViewTransform.cpp \
  $$SRC_DIR/gui/view/ViewSettings.cpp \
  $$SRC_DIR/gui/view/ViewRenderer.cpp \
  $$SRC_DIR/gui/view/Histogram.cpp \   # skip graph exporter ...
  $$SRC_DIR/gui/view/gate/GateRendererManager.cpp \
  $$SRC_DIR/gui/view/gate/GateRendererRoot.cpp \
  $$SRC_DIR/gui/view/gate/GateRendererRect.cpp \
  $$SRC_DIR/gui/view/gate/GateRendererEllipse.cpp \
  $$SRC_DIR/gui/view/gate/GateRendererPoly.cpp \
  $$SRC_DIR/gui/view/gate/GateRendererRange.cpp \
  $$SRC_DIR/gui/panes/CompensationPane.cpp \
  $$SRC_DIR/gui/panes/DatasetInfoPane.cpp \
  $$SRC_DIR/gui/panes/ViewsPane.cpp \
  $$SRC_DIR/gui/panes/GateStatsPane.cpp \
  $$SRC_DIR/gui/lengthprofile/ProfilePane.cpp \
  $$SRC_DIR/gui/lengthprofile/ProfileView.cpp \
  $$SRC_DIR/data/ExportFcsToCSV.cpp \
  $$SRC_DIR/data/ChannelInfo.cpp \
  $$SRC_DIR/gui/qt/QTutil.cpp \
  $$SRC_DIR/gui/resource/ImgResource.cpp \
  $$SRC_DIR/gui/colors/QColorCombo.cpp \
  $$SRC_DIR/gui/colors/ColorSet.cpp \
  $$SRC_DIR/transformations/TransformationStack.cpp \
  $$SRC_DIR/data/Dataset.cpp  \
  $$SRC_DIR/data/Compensation.cpp  \
  $$SRC_DIR/gui/panes/ViewsMatrix.cpp \
  $$SRC_DIR/gui/qt/QTableWidgetWithCSVcopy.cpp \
  $$SRC_DIR/gui/view/tool/ViewToolDrawEllipse.cpp \
  $$SRC_DIR/gui/view/tool/ViewToolDrawSelect.cpp \
  $$SRC_DIR/gui/view/tool/ViewToolDrawRange.cpp \
  $$SRC_DIR/gui/view/tool/ViewToolDrawRect.cpp \
  $$SRC_DIR/gui/view/tool/ViewToolDrawPoly.cpp \
  $$SRC_DIR/gates/GatingResult.cpp \
  $$SRC_DIR/gates/GateRect.cpp \
  $$SRC_DIR/gates/GateEllipse.cpp \
  $$SRC_DIR/gates/GateSet.cpp \
  $$SRC_DIR/main.cpp \

#$$SRC_DIR/../facs-bridge/qvector-matrix-r8.cpp \

DEFINES += DEFAULT_ICON_FOLDER=\\\"$$ROOT_DIR/code/icons\\\"

DEFINES += DEMO_FCS_FOLDER=\\\"$$ROOT_DIR/extra/facs/fcs\\\"


DEFINES += USE_KANS


LIBS += -L$$TARGETSDIR  -lfacs-bridge

LIBS += -L$$TARGETSDIR -lqcytolib #-lfacs-bridge


LIBS +=  -lstdc++fs


include($$ROOT_DIR/../preferred/facs.pri)




