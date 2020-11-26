
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  opengl sql network xml testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)


DEFINES += MEDINRIA_VERSION=\\\"0.0.0.0\\\"
DEFINES += MEDINRIA_BUILD_DATE=\\\"??\\\"


DEFINES += MEDINRIA_PLUGIN_ROOT_DIR=\\\"$$CPP_ROOT_DIR/plugins/medInria\\\"



SRC_DIR_APP =  $$SRC_DIR/app/medInria

SRC_DIR_LAYERS =  $$SRC_DIR/layers

DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

DTK_META_EXTRA_INCLUDES_DIR =   $$SRC_DIR/devdtk/extra-includes

DTK_META_APP_DIR =   $$SRC_DIR/devdtk/dtk/app


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



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medSettingsWidgetFactory.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medToolBoxFactory.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medWorkspaceFactory.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medSettingsWidgetFactory.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medToolBoxFactory.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medWorkspaceFactory.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medAbstractSelectableToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medActionsToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsHostToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsNodesToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsSearchToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterAbstractToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterSelectorToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationAbstractToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationSelectorToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medSelectorToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxBody.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxHeader.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxTab.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medAbstractSelectableToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medActionsToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsHostToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsNodesToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsSearchToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterAbstractToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterSelectorToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationAbstractToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationSelectorToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medSelectorToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxBody.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxHeader.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxTab.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsBaseScu.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsEchoScu.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsFactory.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsFindScu.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsKey.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsMoveScu.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsNode.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsResultDataset.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScp.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScu.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medMoveCommandItem.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medPacsExport.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medPacsMover.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medPacsNode.h \
  $$SRC_DIR_LAYERS/legacy/medPacs/medPacsWidget.h \


SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsBaseScu.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsEchoScu.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsFactory.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsFindScu.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsMoveScu.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsNode.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsResultDataset.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScp.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScu.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medPacsMover.cpp \
  $$SRC_DIR_LAYERS/legacy/medPacs/medPacsWidget.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medDatabaseSettingsWidget.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsEditor.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsWidget.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medStartupSettingsWidget.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medDatabaseSettingsWidget.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsEditor.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsWidget.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medStartupSettingsWidget.cpp \




HEADERS +=  \
  $$SRC_DIR_APP/areas/workspaces/diffusion/medDiffusionWorkspace.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/workspaces/diffusion/medDiffusionWorkspace.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDatabaseImporter.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDatabaseItem.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDbController.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseController.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseExporter.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseImporter.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseItem.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseModel.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentController.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentImporter.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentItem.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentItem_p.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseProxyModel.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseReader.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseRemover.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDataIndex.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDataManager.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medStorage.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDatabaseImporter.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseController.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseExporter.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseImporter.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseItem.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseModel.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentController.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentImporter.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentItem.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseProxyModel.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseReader.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseRemover.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDataIndex.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDataManager.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medStorage.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/parameter/medAbstractParameter.h \
  $$SRC_DIR_LAYERS/medCore/parameter/medBoolParameter.h \
  $$SRC_DIR_LAYERS/medCore/parameter/medBoolParameterGroup.h \
  $$SRC_DIR_LAYERS/medCore/parameter/medDoubleParameter.h \
  $$SRC_DIR_LAYERS/medCore/parameter/medIntParameter.h \
  $$SRC_DIR_LAYERS/medCore/parameter/medStringParameter.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/parameter/medAbstractParameter.cpp \
  $$SRC_DIR_LAYERS/medCore/parameter/medBoolParameter.cpp \
  $$SRC_DIR_LAYERS/medCore/parameter/medBoolParameterGroup.cpp \
  $$SRC_DIR_LAYERS/medCore/parameter/medDoubleParameter.cpp \
  $$SRC_DIR_LAYERS/medCore/parameter/medIntParameter.cpp \
  $$SRC_DIR_LAYERS/medCore/parameter/medStringParameter.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/data/medDiffusionGradientReader.h \
  $$SRC_DIR_LAYERS/medCore/data/medAbstractDataConverter.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/data/medDiffusionGradientReader.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medAnnotationData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medImageMaskAnnotationData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medSeedPointAnnotationData.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medAnnotationData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medImageMaskAnnotationData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medSeedPointAnnotationData.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractDiffusionProcess.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractProcessLegacy.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractRegistrationProcess.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medRunnableProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractDiffusionProcess.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractProcessLegacy.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractRegistrationProcess.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/process/medRunnableProcess.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medWidgets/medWidgets.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medWidgets/medWidgets.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medAbstractParameterPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medBoolParameterPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medDoubleParameterPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medIntParameterPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medStringParameterPresenter.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medAbstractParameterPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medBoolParameterPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medDoubleParameterPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medIntParameterPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/parameter/medStringParameterPresenter.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/medComposerExtension.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/medComposerExtension.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/medWidgets/process/medAbstractProcessPresenter.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medWidgets/process/medAbstractProcessPresenter.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionModelEstimationProcessPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionScalarMapsProcessPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDWIMaskingProcessPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractTractographyProcessPresenter.h \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medDiffusionModelEstimationMetaProcessPresenter.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionModelEstimationProcessPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionScalarMapsProcessPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDWIMaskingProcessPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractTractographyProcessPresenter.cpp \
  $$SRC_DIR_LAYERS/medWidgets/process/diffusion_processes/medDiffusionModelEstimationMetaProcessPresenter.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionModelEstimationProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionScalarMapsProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDWIMaskingProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractTractographyProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medDiffusionModelEstimationMetaProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionModelEstimationProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionScalarMapsProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDWIMaskingProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractTractographyProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/diffusion_processes/medDiffusionModelEstimationMetaProcess.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/process/medAbstractProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/process/medAbstractProcess.cpp \

HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractAddImageProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractArithmeticOperationProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractDivideImageProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractMultiplyImageProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractSubtractImageProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractArithmeticOperationProcess.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medAddImageProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medArithmeticOperationProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medArithmeticOperationProcessNode.tpp \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medDivideImageProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medMultiplyImageProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medSubtractImageProcessNode.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medAddImageProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medDivideImageProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medMultiplyImageProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/arithmetic_operation/medSubtractImageProcessNode.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionModelEstimationProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionScalarMapsProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medDWIMaskingProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medTractographyProcessNode.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionModelEstimationProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionScalarMapsProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medDWIMaskingProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/diffusion_processes/medTractographyProcessNode.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/process/mask_image/medMaskImageProcessNode.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/process/mask_image/medMaskImageProcessNode.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medClosingImageProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medDilateImageProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medErodeImageProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medMorphomathOperationProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medMorphomathOperationProcessNode.tpp \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medOpeningImageProcessNode.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medClosingImageProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medDilateImageProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medErodeImageProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/morphomath_operation/medOpeningImageProcessNode.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medAddFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medDivideFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medGaussianFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medImageDenoisingProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medInvertFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medMedianFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medMultiplyFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medNormalizeFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medShrinkFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterDoubleOperationProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterOperationProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSubtractFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSymmetryPlaneAlignmentProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medWindowingFilterProcessNode.h \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterDoubleOperationProcessNode.tpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterOperationProcessNode.tpp \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medAddFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medDivideFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medGaussianFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medImageDenoisingProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medInvertFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medMedianFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medMultiplyFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medNormalizeFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medShrinkFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSubtractFilterProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medSymmetryPlaneAlignmentProcessNode.cpp \
  $$SRC_DIR_LAYERS/medComposer/process/single_filter/medWindowingFilterProcessNode.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medComposer/process/medWriterNodeBase.h \
  $$SRC_DIR_LAYERS/medComposer/process/medReaderNodeBase.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medComposer/process/medWriterNodeBase.cpp \




HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractClosingImageProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractDilateImageProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractErodeImageProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractMorphomathOperationProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractOpeningImageProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractMorphomathOperationProcess.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/process/mask_image/medAbstractMaskImageProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/process/mask_image/medAbstractMaskImageProcess.cpp \

HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractAddFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractBiasCorrectionProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractDivideFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractGaussianFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractImageDenoisingProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractInvertFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractMedianFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractMultiplyFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractNormalizeFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractRelaxometryEstimationProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractShrinkFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationDoubleProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSubtractFilterProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSymmetryPlaneAlignmentProcess.h \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractWindowingFilterProcess.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractAddFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractDivideFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractGaussianFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractMedianFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractMultiplyFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractShrinkFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationDoubleProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractSubtractFilterProcess.cpp \
  $$SRC_DIR_LAYERS/medCore/process/single_filter/medAbstractWindowingFilterProcess.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/medCore.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/medCore.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/medCore/job/medAbstractJob.h \
  $$SRC_DIR_LAYERS/medCore/job/medJobManager.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/medCore/job/medAbstractJob.cpp \
  $$SRC_DIR_LAYERS/medCore/job/medJobManager.cpp \


HEADERS +=  \
  $$SRC_DIR_APP/areas/workspaces/filtering/medFilteringWorkspace.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/workspaces/filtering/medFilteringWorkspace.cpp \



HEADERS +=  \
  $$SRC_DIR_APP/areas/workspaces/visualization/medVisualizationWorkspace.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/workspaces/visualization/medVisualizationWorkspace.cpp \




HEADERS +=  \
  $$SRC_DIR_APP/areas/homepage/medHomepageArea.h \
  $$SRC_DIR_APP/areas/homepage/medHomepageButton.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/homepage/medHomepageArea.cpp \
  $$SRC_DIR_APP/areas/homepage/medHomepageButton.cpp \


HEADERS +=  \
  $$SRC_DIR_APP/areas/browser/medBrowserArea.h \
  $$SRC_DIR_APP/areas/browser/medBrowserSourceSelectorToolBox.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/browser/medBrowserArea.cpp \
  $$SRC_DIR_APP/areas/browser/medBrowserSourceSelectorToolBox.cpp \


HEADERS +=  \
  $$SRC_DIR_APP/areas/composer/medComposerArea.h \
  $$SRC_DIR_APP/areas/composer/medComposerArea_p.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/composer/medComposerArea.cpp \



HEADERS +=  \
  $$SRC_DIR_APP/medMainWindow.h \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractImageViewInteractor.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractInteractor.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractLayeredViewInteractor.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractViewInteractor.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractImageViewInteractor.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractInteractor.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractLayeredViewInteractor.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractViewInteractor.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractImageViewNavigator.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractNavigator.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractLayeredViewNavigator.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractViewNavigator.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractImageViewNavigator.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractNavigator.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractLayeredViewNavigator.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractViewNavigator.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractImageView.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractLayeredView.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractView.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medImageViewEnum.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medViewFactory.h \


SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractImageView.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractLayeredView.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractView.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medViewFactory.cpp \

#HEADERS +=  \
#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDataManager.h \
#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseController.h \
#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentController.h \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainer.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerManager.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerSplitter.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainer.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerManager.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerSplitter.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/medWidgets/toolboxes/medDiffusionSelectorToolBox.h \


#parameters ...
HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterGroupL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolGroupParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medCompositeParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDataListParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDoubleParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medIntParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medLayerParameterGroupL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterGroupManagerL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolManagerL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medPoolIndicatorL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medStringListParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTimeLineParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTriggerParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector2DParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector3DParameterL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medViewParameterGroupL.h \



#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractImageView.h \
#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerSplitter.h \
#
#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataFactory.h \
#  $$SRC_DIR_APP/medApplication.h \
#  $$SRC_DIR_APP/medDatabaseDataSource.h \
#  $$SRC_DIR_APP/medDataSourceManager.h \
#  $$SRC_DIR_APP/medEmptyDbWarning.h \
#  $$SRC_DIR_APP/medExportVideoDialog.h \
#  $$SRC_DIR_APP/medFileSystemDataSource.h \
#  $$SRC_DIR_APP/medLogger.h \

#  $$SRC_DIR_APP/medPacsDataSource.h \
#  $$SRC_DIR_APP/medPluginWidget.h \
#  $$SRC_DIR_APP/medQuickAccessMenu.h \
#  $$SRC_DIR_APP/medSaveModifiedDialog.h \
#  $$SRC_DIR_APP/medSearchToolboxDialog.h \
#  $$SRC_DIR_APP/medSplashScreen.h \


#SOURCES +=  \
#  $$SRC_DIR/main.cpp \

SOURCES +=  \
  $$SRC_DIR_APP/medMainWindow.cpp \


HEADERS +=  \
  $$SRC_DIR_APP/QSingleApplication/qtsingleapplication.h \
  $$SRC_DIR_APP/QSingleApplication/qtlocalpeer.h \
  $$SRC_DIR_APP/QSingleApplication/qtlockedfile.h \
  $$SRC_DIR_APP/QSingleApplication/qtsinglecoreapplication.h \

SOURCES +=  \
  $$SRC_DIR_APP/QSingleApplication/qtsingleapplication.cpp \
  $$SRC_DIR_APP/QSingleApplication/qtlocalpeer.cpp \
  $$SRC_DIR_APP/QSingleApplication/qtlockedfile.cpp \
  $$SRC_DIR_APP/QSingleApplication/qtsinglecoreapplication.cpp \


HEADERS +=  \
  $$SRC_DIR_APP/areas/workspaces/medWorkspaceArea.h \
  $$SRC_DIR_APP/areas/workspaces/medWorkspaceArea_p.h \

SOURCES +=  \
  $$SRC_DIR_APP/areas/workspaces/medWorkspaceArea.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSource.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSourceFactory.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medCoreLegacyExport.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medGlobalDefs.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medJobItemL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medJobManagerL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medMessageController.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medPluginLegacy.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medPluginManager.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medSettingsManager.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medStyleSheetParser.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medViewEventFilter.h \


SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSource.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSourceFactory.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medGlobalDefs.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medJobItemL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medJobManagerL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medMessageController.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medPluginLegacy.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medPluginManager.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medSettingsManager.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medStyleSheetParser.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/medViewEventFilter.cpp \


HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataFactory.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataWriter.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDiffusionModelImageData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractFibersData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractImageData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMaskData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMeshData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractRoi.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAttachedData.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medDataReaderWriter.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medMetaDataKeys.h \

\#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractTypedDiffusionModelImageData.h \
\#  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractTypedImageData.h \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medAbstractWorkspaceLegacy.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medLinkMenu.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medPacsSelector.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medRootContainer.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medSelectorWorkspace.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medTabbedViewContainers.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medTableWidgetChooser.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medToolBoxContainer.h \


SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medAbstractWorkspaceLegacy.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medLinkMenu.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medPacsSelector.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medRootContainer.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medSelectorWorkspace.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medTabbedViewContainers.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medTableWidgetChooser.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/medToolBoxContainer.cpp \




SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAttachedData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataFactory.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataWriter.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDiffusionModelImageData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractFibersData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractImageData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMaskData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMeshData.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractRoi.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medDataReaderWriter.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/data/medMetaDataKeys.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseCompactWidget.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseEditItemDialog.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseMetadataItemDialog.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabasePreview.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseSearchPanel.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseView.h \


SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseCompactWidget.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseEditItemDialog.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseMetadataItemDialog.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabasePreview.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseSearchPanel.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseView.cpp \



HEADERS +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medButton.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medComboBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medDropSite.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medGroupBox.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medListWidget.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medProgressionStack.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medSliderL.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medSliderSpinboxPair.h \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medStatusBar.h \

SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medSliderL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medButton.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medDropSite.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medGroupBox.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medProgressionStack.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medStatusBar.cpp \


SOURCES +=  \
  $$SRC_DIR_LAYERS/medWidgets/toolboxes/medDiffusionSelectorToolBox.cpp \



#parameters ...
SOURCES +=  \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterGroupL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolGroupParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medCompositeParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDataListParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDoubleParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medIntParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medLayerParameterGroupL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterGroupManagerL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolManagerL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medPoolIndicatorL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medStringListParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTimeLineParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTriggerParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector2DParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector3DParameterL.cpp \
  $$SRC_DIR_LAYERS/legacy/medCoreLegacy/parameters/medViewParameterGroupL.cpp \


HEADERS +=  \
  $$SRC_DIR_APP/medApplication.h \
  $$SRC_DIR_APP/medDatabaseDataSource.h \
  $$SRC_DIR_APP/medDataSourceManager.h \
  $$SRC_DIR_APP/medEmptyDbWarning.h \
  $$SRC_DIR_APP/medExportVideoDialog.h \
  $$SRC_DIR_APP/medFileSystemDataSource.h \
  $$SRC_DIR_APP/medLogger.h \
  $$SRC_DIR_APP/medPacsDataSource.h \
  $$SRC_DIR_APP/medPluginWidget.h \
  $$SRC_DIR_APP/medQuickAccessMenu.h \
  $$SRC_DIR_APP/medSaveModifiedDialog.h \
  $$SRC_DIR_APP/medSearchToolboxDialog.h \
  $$SRC_DIR_APP/medSplashScreen.h \

SOURCES +=  \
  $$SRC_DIR_APP/medApplication.cpp \
  $$SRC_DIR_APP/medDatabaseDataSource.cpp \
  $$SRC_DIR_APP/medDataSourceManager.cpp \
  $$SRC_DIR_APP/medEmptyDbWarning.cpp \
  $$SRC_DIR_APP/medExportVideoDialog.cpp \
  $$SRC_DIR_APP/medFileSystemDataSource.cpp \
  $$SRC_DIR_APP/medLogger.cpp \
  $$SRC_DIR_APP/medPacsDataSource.cpp \
  $$SRC_DIR_APP/medPluginWidget.cpp \
  $$SRC_DIR_APP/medQuickAccessMenu.cpp \
  $$SRC_DIR_APP/medSaveModifiedDialog.cpp \
  $$SRC_DIR_APP/medSearchToolboxDialog.cpp \
  $$SRC_DIR_APP/medSplashScreen.cpp \



#?LIBS += -L$$MEDINRIA_EXTERNAL_LIB_DIR -ldtkGuiSupport  -ldtkLog -ldtkCoreSupport \
#?  -ldtkCore -ldtkComposer -ldtkDistributed -ldtkMath  -ldtkWidgets \
#?  -ldtkMeta 


LIBS += -L$$TARGETSDIR -ldtkGuiSupport  -ldtkLog -ldtkCoreSupport \
  -ldtkCore -ldtkComposer -ldtkDistributed -ldtkMath  -ldtkWidgets \
  -ldtkMeta 



RESOURCES += $$SRC_DIR_APP/resources/medInria.qrc

RESOURCES += $$SRC_DIR_LAYERS/legacy/medCoreLegacy/resources/medCoreLegacy.qrc
RESOURCES += $$SRC_DIR_LAYERS/medCore/medCore.qrc
RESOURCES += $$DTK_META_APP_DIR/dtkDistributedDashboard/dtkDashboard.qrc 

RESOURCES += $$DTK_META_SRC_DIR/../doc/slides/dtkDistributed/dtkDistributedSlides.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkComposer/dtkComposer.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkComposer/dtkComposerNode.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkComposerSupport/_dtkComposer.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkComposerSupport/dtkComposerSupport.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkGuiSupport/dtkGui.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkPlotSupport/dtkPlot.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkWidgets/dtkNotification.qrc
RESOURCES += $$DTK_META_SRC_DIR/dtkWidgets/dtkWidgetsTagCloud.qrc




