
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
INCLUDEPATH += $$SRC_DIR/inc/dtkMath


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc/dtkCore
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta


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
  $$SRC_DIR/inc/dtkMath/dtkGraph.h \
  $$SRC_DIR/inc/dtkMath/dtkGraphEdge.h \
  $$SRC_DIR/inc/dtkMath/dtkGraphTemplate.h \
  $$SRC_DIR/inc/dtkMath/dtkGraphTemplateEdge.h \
  $$SRC_DIR/inc/dtkMath/dtkMath.h \
  $$SRC_DIR/inc/dtkMath/dtkMathArray.h \
  $$SRC_DIR/inc/dtkMath/dtkMatrix.h \
  $$SRC_DIR/inc/dtkMath/dtkMatrix_p.h \
  $$SRC_DIR/inc/dtkMath/dtkGraph \
  $$SRC_DIR/inc/dtkMath/dtkGraphEdge \
  $$SRC_DIR/inc/dtkMath/dtkGraphTemplate \
  $$SRC_DIR/inc/dtkMath/dtkGraphTemplate.tpp \
  $$SRC_DIR/inc/dtkMath/dtkGraphTemplateEdge \
  $$SRC_DIR/inc/dtkMath/dtkGraphTemplateEdge.tpp \
  $$SRC_DIR/inc/dtkMath/dtkMath \
  $$SRC_DIR/inc/dtkMath/dtkMathArray.tpp \
  $$SRC_DIR/inc/dtkMath/dtkMatrix \
  $$SRC_DIR/inc/dtkMath/dtkMatrix.tpp \


SOURCES +=  \
  $$SRC_DIR/dtkGraph.cpp \
  $$SRC_DIR/dtkGraphEdge.cpp \
  $$SRC_DIR/dtkMath.cpp \
  $$SRC_DIR/dtkMathArray.cpp \
  $$SRC_DIR/dtkMatrix.cpp \



