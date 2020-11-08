
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
INCLUDEPATH += $$SRC_DIR/inc/dtkContainerSupport


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc'


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
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainer.h \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainerOrdered.h \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainerWrapper.h \
  $$SRC_DIR/inc/dtkContainerSupport/dtkContainerVector.h \
  $$SRC_DIR/inc/dtkContainerSupport/dtkContainerVectorWrapper.h \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainer \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainer.tpp \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainerOrdered \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainerOrdered.tpp \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainerWrapper \
  $$SRC_DIR/inc/dtkContainerSupport/dtkAbstractContainerWrapper.tpp \
  $$SRC_DIR/inc/dtkContainerSupport/dtkContainerVector \
  $$SRC_DIR/inc/dtkContainerSupport/dtkContainerVector.tpp \
  $$SRC_DIR/inc/dtkContainerSupport/dtkContainerVectorWrapper \
  $$SRC_DIR/inc/dtkContainerSupport/dtkContainerVectorWrapper.tpp \


SOURCES +=  \
  $$SRC_DIR/dtkAbstractContainerWrapper.cpp \
  $$SRC_DIR/dtkContainer.cpp \
  $$SRC_DIR/dtkContainerVector.cpp \




