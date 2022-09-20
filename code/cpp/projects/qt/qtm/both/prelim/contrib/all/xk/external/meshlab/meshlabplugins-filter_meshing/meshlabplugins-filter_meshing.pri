
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include (../shared.pri)


TARGET = $$SAVED_TARGET


LIBS += -L$$TARGETSDIR


QT += xml widgets opengl network


include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += MESHLAB_SCALAR=float
DEFINES += setResizeMode=setSectionResizeMode



INCLUDEPATH += $$SRC_GROUP_DIR  

INCLUDEPATH += $$SRC_GROUP_DIR/external/easyexif  


VCGDIR = $$SRC_GROUP_DIR/vcglib
INCLUDEPATH += $$SRC_GROUP_DIR/vcglib 


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk \


HEADERS += \
  $$SRC_DIR/meshlabplugins/filter_meshing/quadric_simp.h \
  $$SRC_DIR/meshlabplugins/filter_meshing/meshfilter.h \


SOURCES += \
  $$SRC_DIR/meshlabplugins/filter_meshing/quadric_simp.cpp \
  $$SRC_DIR/meshlabplugins/filter_meshing/meshfilter.cpp \


