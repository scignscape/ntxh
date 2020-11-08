
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets xml network  #opengl sql xml testlib svg

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
INCLUDEPATH += $$SRC_DIR/inc/dtkDistributedSupport


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc/dtkCore
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkDistributed/inc/dtkDistributed
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkGuiSupport/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkWidgets/inc



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
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCommunicator.h \
  \# $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCommunicatorMpi.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCommunicatorTcp.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedController.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerFilterView.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerHeaderView.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerJobView.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusModel.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusModelFilter.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusModelItem.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusView.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerSubmitView.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerTargetView.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerTargetViewDelegate.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCore.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCpu.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedGpu.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedJob.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedMessage.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedMimeData.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedNode.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServer.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerDaemon.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManager.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManagerOar.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManager_p.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManagerSsh.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManagerTorque.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedService.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedService_p.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServiceUnix_p.h \
  \# $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServiceWin_p.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedSlave.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedSocket.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedUnixServerSocket.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedUnixSocket.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributor.h \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCommunicator \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCommunicatorMpi \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCommunicatorTcp \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedController \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerFilterView \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerHeaderView \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerJobView \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusModel \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusModelFilter \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusModelItem \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerStatusView \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerSubmitView \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerTargetView \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedControllerTargetViewDelegate \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCore \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedCpu \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedGpu \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedJob \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedMessage \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedMimeData \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedNode \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServer \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerDaemon \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManager \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManagerOar \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManager_p \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManagerSsh \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServerManagerTorque \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedService \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedService_p \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServiceUnix_p \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedServiceWin_p \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedSlave \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedSocket \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedUnixServerSocket \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributedUnixSocket \
  $$SRC_DIR/inc/dtkDistributedSupport/dtkDistributor \


SOURCES +=  \
  $$SRC_DIR/dtkDistributedCommunicator.cpp \
  \# $$SRC_DIR/dtkDistributedCommunicatorMpi.cpp \
  $$SRC_DIR/dtkDistributedCommunicatorTcp.cpp \
  $$SRC_DIR/dtkDistributedController.cpp \
  $$SRC_DIR/dtkDistributedControllerFilterView.cpp \
  $$SRC_DIR/dtkDistributedControllerHeaderView.cpp \
  $$SRC_DIR/dtkDistributedControllerJobView.cpp \
  $$SRC_DIR/dtkDistributedControllerStatusModel.cpp \
  $$SRC_DIR/dtkDistributedControllerStatusModelFilter.cpp \
  $$SRC_DIR/dtkDistributedControllerStatusModelItem.cpp \
  $$SRC_DIR/dtkDistributedControllerStatusView.cpp \
  $$SRC_DIR/dtkDistributedControllerSubmitView.cpp \
  $$SRC_DIR/dtkDistributedControllerTargetView.cpp \
  $$SRC_DIR/dtkDistributedControllerTargetViewDelegate.cpp \
  $$SRC_DIR/dtkDistributedCore.cpp \
  $$SRC_DIR/dtkDistributedCpu.cpp \
  $$SRC_DIR/dtkDistributedGpu.cpp \
  $$SRC_DIR/dtkDistributedJob.cpp \
  $$SRC_DIR/dtkDistributedMessage.cpp \
  $$SRC_DIR/dtkDistributedMimeData.cpp \
  $$SRC_DIR/dtkDistributedNode.cpp \
  $$SRC_DIR/dtkDistributedServer.cpp \
  $$SRC_DIR/dtkDistributedServerDaemon.cpp \
  $$SRC_DIR/dtkDistributedServerManager.cpp \
  $$SRC_DIR/dtkDistributedServerManagerOar.cpp \
  $$SRC_DIR/dtkDistributedServerManagerSsh.cpp \
  $$SRC_DIR/dtkDistributedServerManagerTorque.cpp \
  $$SRC_DIR/dtkDistributedService.cpp \
  $$SRC_DIR/dtkDistributedServiceUnix.cpp \
  \# $$SRC_DIR/dtkDistributedServiceWin.cpp \
  $$SRC_DIR/dtkDistributedSlave.cpp \
  $$SRC_DIR/dtkDistributedSocket.cpp \
  $$SRC_DIR/dtkDistributedUnixServerSocket.cpp \
  $$SRC_DIR/dtkDistributedUnixSocket.cpp \
  $$SRC_DIR/dtkDistributor.cpp \


