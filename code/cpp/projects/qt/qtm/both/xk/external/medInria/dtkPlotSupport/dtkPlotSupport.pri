
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
INCLUDEPATH += $$SRC_DIR/inc/dtkPlotSupport


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc
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
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotCurve.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotCurve_p.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotRenderer.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotView.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewGrid.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewLegend.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewLegend_p.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewPanner.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewPicker.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewSettings.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewToolBar.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewZoomer.h \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotCurve \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotCurve_p \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotRenderer \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotView \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotView.qss \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewGrid \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewLegend \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewLegend_p \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewPanner \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewPicker \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewSettings \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewToolBar \
  $$SRC_DIR/inc/dtkPlotSupport/dtkPlotViewZoomer \


SOURCES +=  \
  \#? $$SRC_DIR/dtkPlotCurve.cpp \
  \#? $$SRC_DIR/dtkPlotRenderer.cpp \
  $$SRC_DIR/dtkPlotView.cpp \
  $$SRC_DIR/dtkPlotViewGrid.cpp \
  $$SRC_DIR/dtkPlotViewLegend.cpp \
  $$SRC_DIR/dtkPlotViewPanner.cpp \
  $$SRC_DIR/dtkPlotViewPicker.cpp \
  $$SRC_DIR/dtkPlotViewSettings.cpp \
  $$SRC_DIR/dtkPlotViewToolBar.cpp \
  $$SRC_DIR/dtkPlotViewZoomer.cpp \





