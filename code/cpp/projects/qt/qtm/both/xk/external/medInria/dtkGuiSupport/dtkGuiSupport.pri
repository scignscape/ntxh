
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets #opengl sql network xml testlib svg

QT += quick



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
INCLUDEPATH += $$SRC_DIR/inc/dtkGuiSupport


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc





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
  $$SRC_DIR/inc/dtkGuiSupport/dtkAboutBox.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkAboutPlugin.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkAnchoredBar.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkColorButton.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkColorGrid.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkFinder.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkFlowLayout.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPieChart.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPluginsEditor.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPopup.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkProgressIndicator.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkRecentFilesMenu.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkScreenMenu.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSearchField.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSettingsEditor.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSpacer.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSplitter.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSwitch.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkTagCloud.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewLayout.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewLayoutItem.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewList.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewListControl.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewManager.h \
  $$SRC_DIR/inc/dtkGuiSupport/dtkAboutBox \
  $$SRC_DIR/inc/dtkGuiSupport/dtkAboutPlugin \
  $$SRC_DIR/inc/dtkGuiSupport/dtkAnchoredBar \
  $$SRC_DIR/inc/dtkGuiSupport/dtkAnchoredBar.qss \
  $$SRC_DIR/inc/dtkGuiSupport/dtkColorButton \
  $$SRC_DIR/inc/dtkGuiSupport/dtkColorGrid \
  $$SRC_DIR/inc/dtkGuiSupport/dtkFinder \
  $$SRC_DIR/inc/dtkGuiSupport/dtkFinder.qss \
  $$SRC_DIR/inc/dtkGuiSupport/dtkFlowLayout \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPieChart \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPluginsEditor \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPopup \
  $$SRC_DIR/inc/dtkGuiSupport/dtkProgressIndicator \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPropertyEditor \
  $$SRC_DIR/inc/dtkGuiSupport/dtkPropertyEditorFactory \
  $$SRC_DIR/inc/dtkGuiSupport/dtkRecentFilesMenu \
  $$SRC_DIR/inc/dtkGuiSupport/dtkScreenMenu \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSearchField \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSettingsEditor \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSpacer \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSplitter \
  $$SRC_DIR/inc/dtkGuiSupport/dtkSwitch \
  $$SRC_DIR/inc/dtkGuiSupport/dtkTagCloud \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewLayout \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewLayoutItem \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewList \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewListControl \
  $$SRC_DIR/inc/dtkGuiSupport/dtkViewManager \


SOURCES +=  \
  $$SRC_DIR/dtkAboutBox.cpp \
  $$SRC_DIR/dtkAboutPlugin.cpp \
  $$SRC_DIR/dtkAnchoredBar.cpp \
  $$SRC_DIR/dtkColorButton.cpp \
  $$SRC_DIR/dtkColorGrid.cpp \
  $$SRC_DIR/dtkFinder.cpp \
  $$SRC_DIR/dtkFlowLayout.cpp \
  $$SRC_DIR/dtkPieChart.cpp \
  $$SRC_DIR/dtkPluginsEditor.cpp \
  $$SRC_DIR/dtkPopup.cpp \
  $$SRC_DIR/dtkProgressIndicator.cpp \
  $$SRC_DIR/dtkRecentFilesMenu.cpp \
  $$SRC_DIR/dtkScreenMenu.cpp \
  $$SRC_DIR/dtkSearchField.cpp \
  $$SRC_DIR/dtkSettingsEditor.cpp \
  $$SRC_DIR/dtkSpacer.cpp \
  $$SRC_DIR/dtkSplitter.cpp \
  $$SRC_DIR/dtkSwitch.cpp \
  $$SRC_DIR/dtkTagCloud.cpp \
  $$SRC_DIR/dtkViewLayout.cpp \
  $$SRC_DIR/dtkViewLayoutItem.cpp \
  $$SRC_DIR/dtkViewList.cpp \
  $$SRC_DIR/dtkViewListControl.cpp \
  $$SRC_DIR/dtkViewManager.cpp \



