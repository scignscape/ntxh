
QT += widgets

include(../build-group.pri)

TEMPLATE = app

INCLUDEPATH +=  $$SRC_DIR $$SRC_GROUP_DIR

INCLUDEPATH +=  $$SRC_GROUP_DIR/pandore/include

include($$ROOT_DIR/../preferred/sysr.pri)


LIBS += -L$$TARGETSDIR -lpandore

HEADERS += \
  $$SRC_DIR/viewers/Qt/canvasview.h \
  $$SRC_DIR/viewers/Qt/colorselector.h \
  $$SRC_DIR/viewers/Qt/controller.h \
  $$SRC_DIR/viewers/Qt/dynamicselector.h \
  $$SRC_DIR/viewers/Qt/frame.cpp \
  $$SRC_DIR/viewers/Qt/frame.h \
  $$SRC_DIR/viewers/Qt/histogramview.h \
  $$SRC_DIR/viewers/Qt/imagemodel.h \
  $$SRC_DIR/viewers/Qt/imagevisu.h \
  $$SRC_DIR/viewers/Qt/model.h \
  $$SRC_DIR/viewers/Qt/planeselector.h \
  $$SRC_DIR/viewers/Qt/profileview.h \
  $$SRC_DIR/viewers/Qt/propertiesview.h \
  $$SRC_DIR/viewers/Qt/rotateselector.h \
  $$SRC_DIR/viewers/Qt/textmodel.h \
  $$SRC_DIR/viewers/Qt/thresholdselector.h \
  $$SRC_DIR/viewers/Qt/valuesview.h \
  $$SRC_DIR/viewers/Qt/viewer.h \
  $$SRC_DIR/viewers/Qt/zoomselector.h \


SOURCES += \
  $$SRC_DIR/viewers/Qt/canvasview.cpp \
  $$SRC_DIR/viewers/Qt/zoomselector.cpp \
  $$SRC_DIR/viewers/Qt/valuesview.cpp \
  $$SRC_DIR/viewers/Qt/thresholdselector.cpp \
  $$SRC_DIR/viewers/Qt/textmodel.cpp \
  $$SRC_DIR/viewers/Qt/rotateselector.cpp \
  $$SRC_DIR/viewers/Qt/pvisu.cpp \
  $$SRC_DIR/viewers/Qt/profileview.cpp \
  $$SRC_DIR/viewers/Qt/propertiesview.cpp \
  $$SRC_DIR/viewers/Qt/planeselector.cpp \
  $$SRC_DIR/viewers/Qt/imagemodel.cpp \
  $$SRC_DIR/viewers/Qt/histogramview.cpp \
  $$SRC_DIR/viewers/Qt/dynamicselector.cpp \
  $$SRC_DIR/viewers/Qt/colorselector.cpp \








