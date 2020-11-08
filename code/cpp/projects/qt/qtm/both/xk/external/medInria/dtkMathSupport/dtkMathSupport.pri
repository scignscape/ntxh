
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  #opengl sql network xml testlib svg

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
INCLUDEPATH += $$SRC_DIR/inc/dtkMathSupport


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc



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
  $$SRC_DIR/inc/dtkMathSupport/dtkMath.h \
  $$SRC_DIR/inc/dtkMathSupport/dtkMatrix.h \
  $$SRC_DIR/inc/dtkMathSupport/dtkMatrixSquared.h \
  $$SRC_DIR/inc/dtkMathSupport/dtkQuaternion.h \
  $$SRC_DIR/inc/dtkMathSupport/dtkVector.h \
  $$SRC_DIR/inc/dtkMathSupport/dtkVector3D.h \
  $$SRC_DIR/inc/dtkMathSupport/dtkMath \
  $$SRC_DIR/inc/dtkMathSupport/dtkMath.tpp \
  $$SRC_DIR/inc/dtkMathSupport/dtkMatrix \
  $$SRC_DIR/inc/dtkMathSupport/dtkMatrix.tpp \
  $$SRC_DIR/inc/dtkMathSupport/dtkMatrixSquared \
  $$SRC_DIR/inc/dtkMathSupport/dtkMatrixSquared.tpp \
  $$SRC_DIR/inc/dtkMathSupport/dtkQuaternion \
  $$SRC_DIR/inc/dtkMathSupport/dtkQuaternion.tpp \
  $$SRC_DIR/inc/dtkMathSupport/dtkVector \
  $$SRC_DIR/inc/dtkMathSupport/dtkVector.tpp \
  $$SRC_DIR/inc/dtkMathSupport/dtkVector3D \
  $$SRC_DIR/inc/dtkMathSupport/dtkVector3D.tpp \


SOURCES +=  \
  $$SRC_DIR/dtkMath.cpp \
  $$SRC_DIR/dtkMatrix.cpp \




