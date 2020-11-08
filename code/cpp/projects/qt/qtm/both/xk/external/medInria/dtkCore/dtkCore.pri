
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

#DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

DTK_META_EXPORT_INCLUDES_DIR =   $$SRC_GROUP_DIR/dtk-meta-export-includes

#DTK_META_APP_DIR =   $$SRC_DIR/devdtk/dtk/app

INCLUDEPATH += $$SRC_DIR/inc/dtkCore
INCLUDEPATH += $$SRC_DIR/inc


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc
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
  $$SRC_DIR/inc/dtkCore/dtkApplicationPrivate.h \
  $$SRC_DIR/inc/dtkCore/dtkArray.h \
  $$SRC_DIR/inc/dtkCore/dtkArrayData.h \
  $$SRC_DIR/inc/dtkCore/dtkAssert.h \
  $$SRC_DIR/inc/dtkCore/dtkCore.h \
  $$SRC_DIR/inc/dtkCore/dtkCoreApplication.h \
  $$SRC_DIR/inc/dtkCore/dtkCoreLayerManager.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePlugin.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginBase.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactory.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactory_p.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactoryRecorder.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactoryTemplate.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManager.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManagerHandler.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManager_p.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManagerRecorder.h \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginWidgetManager.h \
  $$SRC_DIR/inc/dtkCore/dtkCoreSettings.h \
  $$SRC_DIR/inc/dtkCore/dtkHash.h \
  $$SRC_DIR/inc/dtkCore/dtkIOCompressor.h \
  $$SRC_DIR/inc/dtkCore/dtkIterator.h \
  $$SRC_DIR/inc/dtkCore/dtkObjectManager.h \
  $$SRC_DIR/inc/dtkCore/dtkSpinLock.h \
  $$SRC_DIR/inc/dtkCore/dtkStaticArray.h \
  $$SRC_DIR/inc/dtkCore/dtkArray.tpp \
  $$SRC_DIR/inc/dtkCore/dtkArrayData \
  $$SRC_DIR/inc/dtkCore/dtkAssert \
  $$SRC_DIR/inc/dtkCore/dtkCore \
  $$SRC_DIR/inc/dtkCore/dtkCore.i \
  $$SRC_DIR/inc/dtkCore/dtkCoreLayerManager \
  $$SRC_DIR/inc/dtkCore/dtkCorePlugin \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactory \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactory.tpp \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactoryRecorder \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginFactoryTemplate \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManager \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManager.tpp \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManagerHandler \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManager_p \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginManagerRecorder \
  $$SRC_DIR/inc/dtkCore/dtkCorePluginWidgetManager \
  $$SRC_DIR/inc/dtkCore/dtkCoreSettings \
  $$SRC_DIR/inc/dtkCore/dtkHash \
  $$SRC_DIR/inc/dtkCore/dtkIOCompressor \
  $$SRC_DIR/inc/dtkCore/dtkIterator \
  $$SRC_DIR/inc/dtkCore/dtkObjectManager \
  $$SRC_DIR/inc/dtkCore/dtkStaticArray \


SOURCES +=  \
  $$SRC_DIR/dtkApplicationPrivate.cpp \
  $$SRC_DIR/dtkArray.cpp \
  $$SRC_DIR/dtkArrayData.cpp \
  $$SRC_DIR/dtkCoreApplication.cpp \
  $$SRC_DIR/dtkCoreLayerManager.cpp \
  $$SRC_DIR/dtkCorePlugin.cpp \
  $$SRC_DIR/dtkCorePluginFactory.cpp \
  $$SRC_DIR/dtkCorePluginFactory_p.cpp \
  $$SRC_DIR/dtkCorePluginFactoryRecorder.cpp \
  $$SRC_DIR/dtkCorePluginManager.cpp \
  $$SRC_DIR/dtkCorePluginManagerHandler.cpp \
  $$SRC_DIR/dtkCorePluginManagerRecorder.cpp \
  $$SRC_DIR/dtkCorePluginWidgetManager.cpp \
  $$SRC_DIR/dtkCoreSettings.cpp \
  $$SRC_DIR/dtkIOCompressor.cpp \
  $$SRC_DIR/dtkObjectManager.cpp \



