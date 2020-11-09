
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets network  #opengl sql network xml testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)

#DEFINES += DTKLOGEXPORT


#DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

#
DTK_META_EXPORT_INCLUDES_DIR =   $$SRC_GROUP_DIR/dtk-meta-export-includes

#DTK_META_APP_DIR =   $$SRC_DIR/devdtk/dtk/app

#
INCLUDEPATH += $$SRC_DIR/inc/dtkVrSupport


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc #/dtkMathSupport

INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc 
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog 



#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkLog
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkComposer
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkCore
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMeta
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkGuiSupport
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkWidgets
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkDistributed
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMath



HEADERS +=  \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrFlystickRecognizer.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrFlystickRecognizer_p.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrGestureRecognizer.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrGestureRecognizer_p.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrHeadRecognizer.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrHeadRecognizer_p.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrScreen.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrTracker.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrTrackerKinect.h \
  \# $$SRC_DIR/inc/dtkVrSupport/dtkVrTrackerKinect_p.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrTrackerVrpn.h \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrFlystickRecognizer \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrFlystickRecognizer_p \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrGestureRecognizer \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrGestureRecognizer_p \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrHeadRecognizer \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrHeadRecognizer_p \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrScreen \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrTracker \
  $$SRC_DIR/inc/dtkVrSupport/dtkVrTrackerKinect \
  \# $$SRC_DIR/inc/dtkVrSupport/dtkVrTrackerKinect_p \
  \# $$SRC_DIR/inc/dtkVrSupport/dtkVrTrackerVrpn \


SOURCES +=  \
  $$SRC_DIR/dtkVrFlystickRecognizer.cpp \
  $$SRC_DIR/dtkVrGestureRecognizer.cpp \
  $$SRC_DIR/dtkVrHeadRecognizer.cpp \
  $$SRC_DIR/dtkVrScreen.cpp \
  $$SRC_DIR/dtkVrTracker.cpp \
  $$SRC_DIR/dtkVrTrackerKinect.cpp \
  \# $$SRC_DIR/dtkVrTrackerKinect_p.cpp \
  \# $$SRC_DIR/dtkVrTrackerVrpn.cpp \


