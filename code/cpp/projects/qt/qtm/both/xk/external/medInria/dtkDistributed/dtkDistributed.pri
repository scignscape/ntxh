
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  xml network  #opengl sql xml testlib svg

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
INCLUDEPATH += $$SRC_DIR/inc/dtkDistributed


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc/dtkCore
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc


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
  $$SRC_DIR/inc/dtkDistributed/dtkDistributed.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedApplication.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedApplicationPrivate.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedArray.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedArrayCache.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedBufferManager.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedCommunicator.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedCommunicatorStatus.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedContainer.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedController.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedGraphTopology.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedItem.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedIterator.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedLocalMessage.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedMapper.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedMessage.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedNavigator.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedPolicy.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedRequest.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedResourceManager.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedResourceManagerLocal.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedResourceManagerOar.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedResourceManagerSlurm.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedResourceManagerTorque.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedServerDaemon.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedSettings.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedSlave.h \
  $$SRC_DIR/inc/dtkDistributed/qthDistributedBufferManager.h \
  $$SRC_DIR/inc/dtkDistributed/qthDistributedCommunicator.h \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributed \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedArray \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedArray.tpp \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedArrayCache \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedBufferManager \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedCommunicator \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedGraphTopology \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedGraphTopology.tpp \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedIterator \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedMapper \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedNavigator \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedPolicy \
  $$SRC_DIR/inc/dtkDistributed/dtkDistributedSettings \


SOURCES +=  \
  $$SRC_DIR/dtkDistributed.cpp \
  $$SRC_DIR/dtkDistributedApplication.cpp \
  $$SRC_DIR/dtkDistributedApplicationPrivate.cpp \
  $$SRC_DIR/dtkDistributedArray.cpp \
  $$SRC_DIR/dtkDistributedBufferManager.cpp \
  $$SRC_DIR/dtkDistributedCommunicator.cpp \
  $$SRC_DIR/dtkDistributedCommunicatorStatus.cpp \
  $$SRC_DIR/dtkDistributedContainer.cpp \
  $$SRC_DIR/dtkDistributedController.cpp \
  $$SRC_DIR/dtkDistributedGraphTopology.cpp \
  $$SRC_DIR/dtkDistributedLocalMessage.cpp \
  $$SRC_DIR/dtkDistributedMapper.cpp \
  $$SRC_DIR/dtkDistributedMessage.cpp \
  $$SRC_DIR/dtkDistributedPolicy.cpp \
  $$SRC_DIR/dtkDistributedResourceManager.cpp \
  $$SRC_DIR/dtkDistributedResourceManagerLocal.cpp \
  $$SRC_DIR/dtkDistributedResourceManagerOar.cpp \
  $$SRC_DIR/dtkDistributedResourceManagerSlurm.cpp \
  $$SRC_DIR/dtkDistributedResourceManagerTorque.cpp \
  $$SRC_DIR/dtkDistributedServerDaemon.cpp \
  $$SRC_DIR/dtkDistributedSettings.cpp \
  $$SRC_DIR/dtkDistributedSlave.cpp \
  $$SRC_DIR/qthDistributedCommunicator.cpp \


