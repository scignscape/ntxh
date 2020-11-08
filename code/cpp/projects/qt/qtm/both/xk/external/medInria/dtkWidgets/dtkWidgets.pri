
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  widgets #opengl sql network xml testlib svg

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
INCLUDEPATH += $$SRC_DIR/inc/dtkWidgets
INCLUDEPATH += $$SRC_DIR/inc

INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkScript/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta

INCLUDEPATH += $$SRC_GROUP_DIR/dtkDistributed/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkDistributed/inc/dtkDistributed
#/dtkCore


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
  $$SRC_DIR/inc/dtkWidgets/dtkApplication.h \
  $$SRC_DIR/inc/dtkWidgets/dtkDistributedGuiApplication.h \
  $$SRC_DIR/inc/dtkWidgets/dtkInterpreter.h \
  $$SRC_DIR/inc/dtkWidgets/dtkNotifiable.h \
  $$SRC_DIR/inc/dtkWidgets/dtkNotification.h \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationDisplay.h \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationEvent.h \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationQueue.h \
  $$SRC_DIR/inc/dtkWidgets/dtkObjectEditor.h \
  $$SRC_DIR/inc/dtkWidgets/dtkPropertyEditor.h \
  $$SRC_DIR/inc/dtkWidgets/dtkPropertyEditorFactory.h \
  $$SRC_DIR/inc/dtkWidgets/dtkRecentFilesMenu.h \
  $$SRC_DIR/inc/dtkWidgets/dtkScreenMenu.h \
  $$SRC_DIR/inc/dtkWidgets/dtkSpacer.h \
  $$SRC_DIR/inc/dtkWidgets/dtkSplitter.h \
  $$SRC_DIR/inc/dtkWidgets/dtkToolBox.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewController.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewLayout.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewLayoutItem.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewList.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewListControl.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewManager.h \
  $$SRC_DIR/inc/dtkWidgets/dtkViewWidget.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsLogView.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsLogView_p.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTag.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloud.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudController.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudDesc.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudItem.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudLayout.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudList.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudScope.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudScopeItem.h \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudView.h \
  $$SRC_DIR/inc/dtkWidgets/dtkInterpreter \
  $$SRC_DIR/inc/dtkWidgets/dtkNotifiable \
  $$SRC_DIR/inc/dtkWidgets/dtkNotification \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationDisplay \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationDisplay.qss \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationEvent \
  $$SRC_DIR/inc/dtkWidgets/dtkNotificationQueue \
  $$SRC_DIR/inc/dtkWidgets/dtkObjectEditor \
  $$SRC_DIR/inc/dtkWidgets/dtkRecentFilesMenu \
  $$SRC_DIR/inc/dtkWidgets/dtkScreenMenu \
  $$SRC_DIR/inc/dtkWidgets/dtkSpacer \
  $$SRC_DIR/inc/dtkWidgets/dtkSplitter \
  $$SRC_DIR/inc/dtkWidgets/dtkToolBox \
  $$SRC_DIR/inc/dtkWidgets/dtkViewController \
  $$SRC_DIR/inc/dtkWidgets/dtkViewLayout \
  $$SRC_DIR/inc/dtkWidgets/dtkViewLayoutItem \
  $$SRC_DIR/inc/dtkWidgets/dtkViewList \
  $$SRC_DIR/inc/dtkWidgets/dtkViewListControl \
  $$SRC_DIR/inc/dtkWidgets/dtkViewManager \
  $$SRC_DIR/inc/dtkWidgets/dtkViewWidget \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgets \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgets.i \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsFlowLayout \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTag \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloud \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudController \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudDesc \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudScope \
  $$SRC_DIR/inc/dtkWidgets/dtkWidgetsTagCloudView \


SOURCES +=  \
  $$SRC_DIR/dtkApplication.cpp \
  $$SRC_DIR/dtkDistributedGuiApplication.cpp \
  $$SRC_DIR/dtkInterpreter.cpp \
  $$SRC_DIR/dtkNotification.cpp \
  $$SRC_DIR/dtkNotificationDisplay.cpp \
  $$SRC_DIR/dtkNotificationEvent.cpp \
  $$SRC_DIR/dtkNotificationQueue.cpp \
  $$SRC_DIR/dtkObjectEditor.cpp \
  $$SRC_DIR/dtkPropertyEditor.cpp \
  $$SRC_DIR/dtkPropertyEditorFactory.cpp \
  $$SRC_DIR/dtkRecentFilesMenu.cpp \
  $$SRC_DIR/dtkScreenMenu.cpp \
  $$SRC_DIR/dtkSpacer.cpp \
  $$SRC_DIR/dtkSplitter.cpp \
  $$SRC_DIR/dtkToolBox.cpp \
  $$SRC_DIR/dtkViewController.cpp \
  $$SRC_DIR/dtkViewLayout.cpp \
  $$SRC_DIR/dtkViewLayoutItem.cpp \
  $$SRC_DIR/dtkViewList.cpp \
  $$SRC_DIR/dtkViewListControl.cpp \
  $$SRC_DIR/dtkViewManager.cpp \
  $$SRC_DIR/dtkViewWidget.cpp \
  $$SRC_DIR/dtkWidgetsLogView.cpp \
  $$SRC_DIR/dtkWidgetsTag.cpp \
  $$SRC_DIR/dtkWidgetsTagCloud.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudController.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudDesc.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudItem.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudLayout.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudList.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudScope.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudScopeItem.cpp \
  $$SRC_DIR/dtkWidgetsTagCloudView.cpp \




