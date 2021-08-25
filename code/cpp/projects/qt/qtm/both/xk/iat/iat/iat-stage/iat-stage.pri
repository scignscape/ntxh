

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

QT += widgets

QT += webenginewidgets


INCLUDEPATH += $$SRC_DIR

#INCLUDEPATH += $$SRC_GROUP_DIR
DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += SCREENSHOTS_FOLDER=\\\"$$ROOT_DIR/code/assets/_snapshots\\\"

DEFINES += DEFAULT_DGI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/dgi/images\\\"

DEFINES += DEFAULT_DGI_TEMP_FOLDER=\\\"$$ROOT_DIR/../dev/consoles/dgi/images\\\"


DEFINES += USE_KANS

INCLUDEPATH += $$SRC_PROSET_DIR

INCLUDEPATH += $$CHASM_SRC_GROUP_DIR

#/home/nlevisrael/sebi-libs/opencv-4.5.0/modules/imgcodecs/include/opencv2/imgcodecs.hpp


include($$ROOT_DIR/../preferred/opencv.pri)

INCLUDEPATH += $$OPENCV_SRC_DIR/modules/core/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgproc/include
INCLUDEPATH += $$OPENCV_SRC_DIR/modules/imgcodecs/include
INCLUDEPATH += $$OPENCV_BUILD_DIR



# #  for working with QWebEngineView parent classes directly ...
 #   (currently not needed)
 # QT += quickwidgets
#INCLUDEPATH += qt sources .../Src/qtwebengine/src/webenginewidgets/
#INCLUDEPATH += qt sources .../Src/qtwebengine/src/core/
#INCLUDEPATH += qt sources .../Src/qtwebengine/src/
#INCLUDEPATH += qt sources .../Src/qtwebengine/src/core/api
#INCLUDEPATH += qt sources .../Src/../qtbase/include/QtCore/5.15.2/
#INCLUDEPATH += qt sources .../Src/qtbase/include/QtCore/5.15.2/
#INCLUDEPATH += qt sources .../gcc_64/include/QtCore/5.15.2/
#INCLUDEPATH += qt sources .../gcc_64/include/QtWebEngineCore/5.15.2/


#INCLUDEPATH += $$SRC_DIR/dbk/dgdb/dgdb-white
INCLUDEPATH += $$DGDB_WHITE_SRC_GROUP_DIR


FORMS  += \
  $$SRC_DIR/mainwindow.ui\
  $$SRC_DIR/options.ui\
  $$SRC_DIR/listtool.ui


HEADERS += \
  $$SRC_DIR/mainwindow.h\
  $$SRC_DIR/displayimage.h\
  $$SRC_DIR/projectwizard.h\
  $$SRC_DIR/options.h\
  $$SRC_DIR/listtool.h \
  $$SRC_DIR/shape-select-frame.h \
  $$SRC_DIR/zoom-and-navigate-frame.h \
  $$SRC_DIR/range-slider.h \
  $$SRC_DIR/display-drawn-shape.h \
  $$SRC_DIR/rpdf/rpdf-web-engine-page.h \
  $$SRC_DIR/rpdf/rpdf-web-engine-view.h \
  $$SRC_DIR/rpdf/webgl-view-dialog.h \
  $$SRC_DIR/rpdf/context-menu-provider.h \
  $$SRC_DIR/rpdf/url-or-event-pattern.h \
  $$SRC_DIR/rpdf/pattern-matcher-runtime.h \
  $$SRC_DIR/rpdf/my-page.h \
  $$SRC_DIR/rpdf/signal-generator.h \



SOURCES += \
  $$SRC_DIR/main.cpp\
  $$SRC_DIR/mainwindow.cpp\
  $$SRC_DIR/displayimage.cpp\
  $$SRC_DIR/projectwizard.cpp\
  $$SRC_DIR/options.cpp\
  $$SRC_DIR/listtool.cpp \
  $$SRC_DIR/shape-select-frame.cpp \
  $$SRC_DIR/zoom-and-navigate-frame.cpp \
  $$SRC_DIR/range-slider.cpp \
  $$SRC_DIR/displayimage.mouse-events.cpp \
  $$SRC_DIR/display-drawn-shape.cpp \
  $$SRC_DIR/rpdf/rpdf-web-engine-page.cpp \
  $$SRC_DIR/rpdf/rpdf-web-engine-view.cpp \
  $$SRC_DIR/rpdf/webgl-view-dialog.cpp \
  $$SRC_DIR/rpdf/context-menu-provider.cpp \
  $$SRC_DIR/rpdf/url-or-event-pattern.cpp \
  $$SRC_DIR/rpdf/pattern-matcher-runtime.cpp \
  $$SRC_DIR/rpdf/my-page.cpp \
  $$SRC_DIR/rpdf/signal-generator.cpp \



LIBS += -L$$TARGETSDIR -laxfi

LIBS += -L$$TARGETSDIR -lchasm-lib -lchasm-lib-X1 -lchasm-lib-X2 \
  -lchasm-lib-33 -lchasm-lib-43


LIBS += -L$$TARGETSDIR  -ldgi-opencv



LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgcodecs
LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_core
LIBS += -L$$OPENCV_LIB_DIR/ -lopencv_core -lopencv_imgproc



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
