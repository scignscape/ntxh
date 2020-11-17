
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += network  widgets  


include($$ROOT_DIR/../preferred/sysr.pri)



INCLUDEPATH += $$SRC_GROUP_DIR  \


#
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util

#INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
#INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser
#INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core


HEADERS += \
  $$SRC_DIR/Plot/CustomPlot.h \
  $$SRC_DIR/Plot/qcustomplot.h \


SOURCES += \
  $$SRC_DIR/Plot/CustomPlot.C \
  $$SRC_DIR/Plot/qcustomplot.cpp \


