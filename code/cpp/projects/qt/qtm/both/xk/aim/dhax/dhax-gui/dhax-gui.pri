

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += xml widgets network webenginewidgets


INCLUDEPATH += $$SRC_DIR

INCLUDEPATH += $$SRC_PROSET_DIR/aimlib/aimlib/AIMLib/

QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17

FEATURE_IFC = "USE_IFC"

#defined(FEATURE_IFC ,var) {
# DEFINES += $$FEATURE_IFC
# include($$ROOT_DIR/../preferred/occt.pri)
#}

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

#include($$ROOT_DIR/../preferred/aim.pri)
#DEFINES += AIM_DATA_FOLDER=\\\"$$AIM_DATA_DIR\\\"

include($$ROOT_DIR/../preferred/dhax.pri)

DEFINES += DHAX_DATA_FOLDER=\\\"$$DHAX_DATA_DIR\\\"
DEFINES += DHAX_IMAGE_FOLDER=\\\"$$DHAX_IMAGE_DIR\\\"

DEFINES += DEFAULT_DHAX_TEMP_FOLDER=\\\"$$DHAX_TEMP_DIR\\\"
DEFINES += DEFAULT_DGI_TEMP_FOLDER=\\\"$$DGI_TEMP_DIR\\\"



DEFINES += DEFAULT_DEV_TKRZW_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/tkrzw\\\"

DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgdb/instances\\\"

DEFINES += SCREENSHOTS_FOLDER=\\\"$$ROOT_DIR/../dev/screenshots\\\"

DEFINES += USE_KANS

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR

INCLUDEPATH += $$DGDB_SRC_GROUP_DIR/tkrzw

INCLUDEPATH += $$DGDB_WHITE_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/tkrzw

INCLUDEPATH += $$WHITEDB_SRC_GROUP_DIR

INCLUDEPATH += $$CHASM_SRC_GROUP_DIR


include($$ROOT_DIR/../preferred/opencv.pri)

INCLUDEPATH += $$OPENCV_SRC_DIR/modules/core/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgproc/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgcodecs/include
INCLUDEPATH += $$OPENCV_BUILD_DIR


HEADERS += \
  $$SRC_DIR/main-window/dhax-main-window.h \
  $$SRC_DIR/main-window/dhax-main-window-frame.h \
  $$SRC_DIR/main-window/dhax-main-window-data.h \
  $$SRC_DIR/main-window/dhax-main-window-menus.h \
  $$SRC_DIR/main-window/dhax-menu-system.h \
  $$SRC_DIR/main-window/dhax-main-window-controller.h \
  $$SRC_DIR/main-window/dhax-main-window-receiver.h \
  $$SRC_DIR/application/dhax-application-controller.h \
  $$SRC_DIR/application/dhax-external-application-controller.h \
  $$SRC_DIR/application/dhax-application-receiver.h \
  $$SRC_DIR/dhax-graphics-view.h \
  $$SRC_DIR/dhax-graphics-scene.h \
  $$SRC_DIR/dhax-gui-environment.h \
  $$SRC_DIR/dhax-graphics-frame.h \
  $$SRC_DIR/dhax-signal-generator.h \
  $$SRC_DIR/image-viewer/dhax-image-viewer.h \
  $$SRC_DIR/image-viewer/dhax-image-scene-item.h \
  $$SRC_DIR/image-viewer/dhax-display-image-data.h \
  $$SRC_DIR/image-viewer/dhax-drawn-shape.h \
  $$SRC_DIR/subwindows/range-slider.h \
  $$SRC_DIR/subwindows/shape-select-frame.h \
  $$SRC_DIR/subwindows/zoom-and-navigate-frame.h \
  $$SRC_DIR/integration/dhax-integration-controller.h \
  $$SRC_DIR/integration/meshlab/dhax-meshlab-integration-data.h \
  $$SRC_DIR/integration/meshlab/dhax-meshlab-integration-controller.h \
  $$SRC_DIR/integration/freecad/dhax-freecad-integration-data.h \
  $$SRC_DIR/integration/forge-api/dhax-forge-api-integration-data.h \
  $$SRC_DIR/virtual-packages/graphics-scene-demo.h \
  $$SRC_DIR/network/dhax-udp-controller.h \
  $$SRC_DIR/rpdf/rpdf-web-engine-page.h \
  $$SRC_DIR/rpdf/rpdf-web-engine-view.h \
  $$SRC_DIR/rpdf/webgl-view-dialog.h \
  $$SRC_DIR/rpdf/context-menu-provider.h \
  $$SRC_DIR/rpdf/url-or-event-pattern.h \
  $$SRC_DIR/rpdf/pattern-matcher-runtime.h \
  $$SRC_DIR/rpdf/my-page.h \
  $$SRC_DIR/rpdf/signal-generator.h \


SOURCES += \
  $$SRC_DIR/main-window/dhax-main-window.cpp \
  $$SRC_DIR/main-window/dhax-main-window-frame.cpp \
  $$SRC_DIR/main-window/dhax-main-window-data.cpp \
  $$SRC_DIR/main-window/dhax-main-window-menus.cpp \
  $$SRC_DIR/main-window/dhax-main-window-controller.cpp \
  $$SRC_DIR/main-window/dhax-main-window-receiver.cpp \
  $$SRC_DIR/main-window/dhax-menu-system.cpp \
  $$SRC_DIR/application/dhax-application-controller.cpp \
  $$SRC_DIR/application/dhax-application-receiver.cpp \
  $$SRC_DIR/application/dhax-external-application-controller.cpp \
  $$SRC_DIR/dhax-graphics-view.cpp \
  $$SRC_DIR/dhax-graphics-scene.cpp \
  $$SRC_DIR/dhax-gui-environment.cpp \
  $$SRC_DIR/dhax-graphics-frame.cpp \
  $$SRC_DIR/dhax-signal-generator.cpp \
  $$SRC_DIR/image-viewer/dhax-image-viewer.cpp \
  $$SRC_DIR/image-viewer/dhax-image-scene-item.cpp \
  $$SRC_DIR/image-viewer/dhax-display-image-data.cpp \
  $$SRC_DIR/image-viewer/dhax-drawn-shape.cpp \
  $$SRC_DIR/image-viewer/dhax-image-scene-item.mouse-events.cpp \
  $$SRC_DIR/subwindows/range-slider.cpp \
  $$SRC_DIR/subwindows/shape-select-frame.cpp \
  $$SRC_DIR/subwindows/zoom-and-navigate-frame.cpp \
  $$SRC_DIR/integration/dhax-integration-controller.cpp \
  $$SRC_DIR/integration/meshlab/dhax-meshlab-integration-data.cpp \
  $$SRC_DIR/integration/meshlab/dhax-meshlab-integration-controller.cpp \
  $$SRC_DIR/integration/freecad/dhax-freecad-integration-data.cpp \
  $$SRC_DIR/integration/forge-api/dhax-forge-api-integration-data.cpp \
  $$SRC_DIR/virtual-packages/graphics-scene-demo.cpp \
  $$SRC_DIR/network/dhax-udp-controller.cpp \
  $$SRC_DIR/rpdf/rpdf-web-engine-page.cpp \
  $$SRC_DIR/rpdf/rpdf-web-engine-view.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog.cpp \
  $$SRC_DIR/rpdf/context-menu-provider.cpp \
  $$SRC_DIR/rpdf/url-or-event-pattern.cpp \
  $$SRC_DIR/rpdf/pattern-matcher-runtime.cpp \
  $$SRC_DIR/rpdf/my-page.cpp \
  $$SRC_DIR/rpdf/signal-generator.cpp \


#  $$SRC_DIR/dhax-gui.cpp \


# #  for dcmtk OFString = std::string ...
DEFINES += HAVE_STD_STRING
DEFINES += HAVE_STL_STRING



LIBS += -L$$TARGETSDIR  -laimlib -ldcmsr -lofstd -loflog -ldcmdata \
   -ldcmimage -ldcmimgle

LIBS += -L$$TARGETSDIR  -laxfi

#LIBS += -L$$TARGETSDIR  -laimlib

LIBS += -lrt


LIBS += -L$$TARGETSDIR  -ldgi-opencv


LIBS += -L$$TARGETSDIR -lchasm-lib -lchasm-lib-X1 -lchasm-lib-X2 \
  -lchasm-lib-33 -lchasm-lib-43


include($$ROOT_DIR/../preferred/freecad.pri)

DEFINES += FREECAD_BIN_FOLDER=\\\"$$FREECAD_BIN_DIR\\\"


LIBS += -L$$TARGETSDIR -ldgdb

LIBS += -L$$TARGETSDIR -ltkrzw -llz4  -llzma -lz

LIBS += -L$$TARGETSDIR -lwhitedb


LIBS += -L$$TARGETSDIR -lchasm-lib -lchasm-lib-X1 -lchasm-lib-X2 \
  -lchasm-lib-33 -lchasm-lib-43



#LIBS += -L$$TARGETSDIR -laimlib


# #  assumed xerces is installed ...
LIBS += -lxerces-c


DCMTK_DIR = $$DCMTK_SRC_GROUP_DIR


INCLUDEPATH += $$DCMTK_DIR/ofstd/include
INCLUDEPATH += $$DCMTK_DIR/dcm-config/include
INCLUDEPATH += $$DCMTK_DIR/dcmsr/include
INCLUDEPATH += $$DCMTK_DIR/dcmdata/include
INCLUDEPATH += $$DCMTK_DIR/oflog/include



defined(FEATURE_IFC ,var) {

DEFINES += $$FEATURE_IFC

LIBS += $$TARGETSDIR/libifc-multi.a

LIBS += $$TARGETSDIR/libifc-2x3.a \
  $$TARGETSDIR/libifc-4.a \
  $$TARGETSDIR/libifc-4x1.a \
  $$TARGETSDIR/libifc-4x2.a \
  $$TARGETSDIR/libifc-4x3_rc1.a \
  $$TARGETSDIR/libifc-4x3_rc2.a \
  $$TARGETSDIR/libifc-4x3_rc3.a \
  $$TARGETSDIR/libifc-4x3_rc4.a \

}


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
