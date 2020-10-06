
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

#INCLUDEPATH += $$SRC_GROUP_DIR  $$SRC_DIR/gui \

INCLUDEPATH += $$SRC_KERNEL_DIR/facs/cytoLib
INCLUDEPATH += $$SRC_KERNEL_DIR/facs/cytoLib/cytolib/include

INCLUDEPATH += $$SRC_KERNEL_DIR/facs/cytoLib/cytolib/hdf5
INCLUDEPATH += $$SRC_KERNEL_DIR/facs/cytoLib/cytolib/hdf5/c

HEADERS += \

SOURCES +=  \
  $$SRC_DIR/main.cpp \
  /home/nlevisrael/gits/ss/ntxh/wip/ar/code/cpp/src/xk/facs/facs-gui/facs-bridge/qvector-matrix-r8.cpp

#/home/nlevisrael/gits/ss/ntxh/wip/ar/code/cpp/targets/qt/qt-multiple/targets-5-12-9-Desktop_Qt_5_12_9_GCC_64bit:$$LD_LIBRARY_PATH



DEFINES += DEFAULT_ICON_FOLDER=\\\"$$SRC_ROOT_DIR/code/icons\\\"

DEFINES += DEMO_FCS_FOLDER=\\\"$$ROOT_DIR/extra/facs/fcs\\\"


DEFINES += USE_KANS


LIBS += -L$$TARGETSDIR  -lfacs-bridge

LIBS += -L$$TARGETSDIR -lcytolib #-lfacs-bridge


LIBS +=  -lstdc++fs


include($$ROOT_DIR/../preferred/facs.pri)

include($$ROOT_DIR/../preferred/proto.pri)


#LIBS += /home/nlevisrael/mtr/newstuff/hdf5/install/lib/libhdf5.a -lz
#LIBS += -L/home/nlevisrael/mtr/newstuff/hdf5/install/lib/ -lhdf5



