
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  network widgets #opengl sql network xml testlib svg

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
INCLUDEPATH += $$SRC_DIR/inc/dtkCoreSupport
INCLUDEPATH += $$SRC_DIR/inc


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkContainerSupport/inc


INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc #/dtkMathSupport

INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc/dtkCore

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta


INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc/dtkMath



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
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractData.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataComposite.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataConverter.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataConverter_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataDeserializer.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataDeserializer_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataFactory.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractData_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataReader.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataReader_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataSerializer.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataSerializer_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataWriter.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataWriter_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractFactory.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractObject.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractObject_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcess.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcessController.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcessFactory.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcess_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractView.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewAnimator.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewAnimator_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewFactory.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewInteractor.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewInteractor_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewNavigator.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewNavigator_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractView_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkArray.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkCpuid.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkGlobal.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkPlugin.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkPluginManager.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkPlugin_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSignalBlocker.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSingleton.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSingletonDeclare.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSmartPointer.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSparseMatrix.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkTest.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkUpdater.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkUpdater_p.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkVariant.h \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractData \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataComposite \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataComposite.tpp \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataConverter \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataConverter_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataDeserializer \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataDeserializer_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataFactory \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractData_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataReader \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataReader_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataSerializer \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataSerializer_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataWriter \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractDataWriter_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractFactory \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractObject \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractObject_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcess \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcessController \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcessFactory \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractProcess_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractView \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewAnimator \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewAnimator_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewFactory \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewInteractor \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewInteractor_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewNavigator \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractViewNavigator_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkAbstractView_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkArray \
  $$SRC_DIR/inc/dtkCoreSupport/dtkArray.tpp \
  $$SRC_DIR/inc/dtkCoreSupport/dtkCpuid \
  $$SRC_DIR/inc/dtkCoreSupport/dtkGlobal \
  $$SRC_DIR/inc/dtkCoreSupport/dtkPlugin \
  $$SRC_DIR/inc/dtkCoreSupport/dtkPluginManager \
  $$SRC_DIR/inc/dtkCoreSupport/dtkPlugin_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSignalBlocker \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSingleton \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSingletonDeclare \
  $$SRC_DIR/inc/dtkCoreSupport/dtkSmartPointer \
  $$SRC_DIR/inc/dtkCoreSupport/dtkTest \
  $$SRC_DIR/inc/dtkCoreSupport/dtkUpdater \
  $$SRC_DIR/inc/dtkCoreSupport/dtkUpdater_p \
  $$SRC_DIR/inc/dtkCoreSupport/dtkVariant \
  $$SRC_DIR/inc/dtkCoreSupport/dtkVariant.tpp \


SOURCES +=  \
  $$SRC_DIR/dtkAbstractData.cpp \
  $$SRC_DIR/dtkAbstractDataComposite.cpp \
  $$SRC_DIR/dtkAbstractDataConverter.cpp \
  $$SRC_DIR/dtkAbstractDataDeserializer.cpp \
  $$SRC_DIR/dtkAbstractDataFactory.cpp \
  $$SRC_DIR/dtkAbstractDataReader.cpp \
  $$SRC_DIR/dtkAbstractDataSerializer.cpp \
  $$SRC_DIR/dtkAbstractDataWriter.cpp \
  $$SRC_DIR/dtkAbstractFactory.cpp \
  $$SRC_DIR/dtkAbstractObject.cpp \
  $$SRC_DIR/dtkAbstractProcess.cpp \
  $$SRC_DIR/dtkAbstractProcessController.cpp \
  $$SRC_DIR/dtkAbstractProcessFactory.cpp \
  $$SRC_DIR/dtkAbstractView.cpp \
  $$SRC_DIR/dtkAbstractViewAnimator.cpp \
  $$SRC_DIR/dtkAbstractViewFactory.cpp \
  $$SRC_DIR/dtkAbstractViewInteractor.cpp \
  $$SRC_DIR/dtkAbstractViewNavigator.cpp \
  $$SRC_DIR/dtkArray.cpp \
  $$SRC_DIR/dtkCpuid.cpp \
  $$SRC_DIR/dtkPlugin.cpp \
  $$SRC_DIR/dtkPluginManager.cpp \
  $$SRC_DIR/dtkSignalBlocker.cpp \
  $$SRC_DIR/dtkSingleton.cpp \
  $$SRC_DIR/dtkSingletonDeclare.cpp \
  $$SRC_DIR/dtkSmartPointer.cpp \
  $$SRC_DIR/dtkUpdater.cpp \
  $$SRC_DIR/dtkVariant.cpp \

