
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = medInria

include(../build-group.pri)

TEMPLATE = app


QT += gui  opengl sql network xml testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

include($$ROOT_DIR/../preferred/medInria-external.pri)


DEFINES += MEDINRIA_VERSION=\\\"0.0.0.0\\\"
DEFINES += MEDINRIA_BUILD_DATE=\\\"??\\\"


SRC_DIR_APP =  $$SRC_GROUP_DIR/medInria/app/medInria

SRC_DIR_LAYERS =  $$SRC_GROUP_DIR/medInria/layers

DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

DTK_META_EXTRA_INCLUDES_DIR =   $$SRC_GROUP_DIR/medInria/devdtk/extra-includes



INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR

INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkLog
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkComposer
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkCore
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMeta
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkGuiSupport
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkWidgets
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkDistributed
INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMath




INCLUDEPATH += $$SRC_DIR_APP  $$SRC_DIR_APP/QSingleApplication \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy \
   $$SRC_DIR_APP/areas/browser \
   $$SRC_DIR_APP/areas/composer \
   $$SRC_DIR_APP/areas/homepage \
   $$SRC_DIR_LAYERS/medCore \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories \
   $$SRC_DIR_APP/areas/workspaces/visualization \
   $$SRC_DIR_APP/areas/workspaces \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers \
   $$SRC_DIR_LAYERS/medCore/process \
   $$SRC_DIR_LAYERS/medCore/job \
   $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation \
   $$SRC_DIR_LAYERS/medWidgets/process/arithmetic_operation \
   $$SRC_DIR_LAYERS/medCore/process/single_filter \
   $$SRC_DIR_LAYERS/medWidgets/process/single_filter \
   $$SRC_DIR_LAYERS/medCore/process/morphomath_operation \
   $$SRC_DIR_LAYERS/medWidgets/process/morphomath_operation \
   $$SRC_DIR_LAYERS/medWidgets/process \
   $$SRC_DIR_LAYERS/medCore/process/mask_image \
   $$SRC_DIR_LAYERS/medWidgets/process/mask_image \
   $$SRC_DIR_LAYERS/medCore/process/diffusion_processes \
   $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes \
   $$SRC_DIR_LAYERS/medCore/data \
   $$SRC_DIR_APP/areas/workspaces/diffusion \
   $$SRC_DIR_LAYERS/medWidgets/toolboxes \
   $$SRC_DIR_LAYERS/medWidgets/parameter \
   $$SRC_DIR_LAYERS/medWidgets \
   $$SRC_DIR_APP/areas/workspaces/filtering \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData \
   $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database \
   $$SRC_DIR_LAYERS/legacy/medPacs \
   $$SRC_DIR_LAYERS/medComposer \
   $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation \
   $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation \
   $$SRC_DIR_LAYERS/medComposer/process/single_filter \
   $$SRC_DIR_LAYERS/medComposer/process/mask_image \
   $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes \
   $$SRC_DIR_LAYERS/medComposer/process \
   $$SRC_DIR_LAYERS/medCore/parameter \



SOURCES +=  \
  $$SRC_DIR/main.cpp \





LIBS += -L$$TARGETSDIR -lmedInria

LIBS += -L$$MEDINRIA_EXTERNAL_LIB_DIR -ldtkGuiSupport  -ldtkLog -ldtkCoreSupport \
  -ldtkCore -ldtkComposer -ldtkDistributed -ldtkMath  -ldtkWidgets \
  -ldtkMeta 



