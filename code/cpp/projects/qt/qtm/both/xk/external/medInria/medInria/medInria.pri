
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = medInria

include(../build-group.pri)

QT += gui  opengl sql network xml testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

include($$ROOT_DIR/../preferred/medInria-external.pri)




DEFINES += MEDINRIA_VERSION=\\\"0.0.0.0\\\"
DEFINES += MEDINRIA_BUILD_DATE=\\\"??\\\"



SOURCE_DIR_APP =  $$SOURCE_DIR/app/medInria

SOURCE_DIR_LAYERS =  $$SOURCE_DIR/layers

DTK_META_SOURCE_DIR =   $$SOURCE_DIR/devdtk/dtk/src

DTK_META_EXTRA_INCLUDES_DIR =   $$SOURCE_DIR/devdtk/extra-includes



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




INCLUDEPATH += $$SOURCE_DIR_APP  $$SOURCE_DIR_APP/QSingleApplication \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy \
   $$SOURCE_DIR_APP/areas/browser \
   $$SOURCE_DIR_APP/areas/composer \
   $$SOURCE_DIR_APP/areas/homepage \
   $$SOURCE_DIR_LAYERS/medCore \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories \
   $$SOURCE_DIR_APP/areas/workspaces/visualization \
   $$SOURCE_DIR_APP/areas/workspaces \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers \
   $$SOURCE_DIR_LAYERS/medCore/process \
   $$SOURCE_DIR_LAYERS/medCore/job \
   $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation \
   $$SOURCE_DIR_LAYERS/medWidgets/process/arithmetic_operation \
   $$SOURCE_DIR_LAYERS/medCore/process/single_filter \
   $$SOURCE_DIR_LAYERS/medWidgets/process/single_filter \
   $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation \
   $$SOURCE_DIR_LAYERS/medWidgets/process/morphomath_operation \
   $$SOURCE_DIR_LAYERS/medWidgets/process \
   $$SOURCE_DIR_LAYERS/medCore/process/mask_image \
   $$SOURCE_DIR_LAYERS/medWidgets/process/mask_image \
   $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes \
   $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes \
   $$SOURCE_DIR_LAYERS/medCore/data \
   $$SOURCE_DIR_APP/areas/workspaces/diffusion \
   $$SOURCE_DIR_LAYERS/medWidgets/toolboxes \
   $$SOURCE_DIR_LAYERS/medWidgets/parameter \
   $$SOURCE_DIR_LAYERS/medWidgets \
   $$SOURCE_DIR_APP/areas/workspaces/filtering \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData \
   $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database \
   $$SOURCE_DIR_LAYERS/legacy/medPacs \
   $$SOURCE_DIR_LAYERS/medComposer \
   $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation \
   $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation \
   $$SOURCE_DIR_LAYERS/medComposer/process/single_filter \
   $$SOURCE_DIR_LAYERS/medComposer/process/mask_image \
   $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes \
   $$SOURCE_DIR_LAYERS/medComposer/process \
   $$SOURCE_DIR_LAYERS/medCore/parameter \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medSettingsWidgetFactory.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medToolBoxFactory.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medWorkspaceFactory.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medSettingsWidgetFactory.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medToolBoxFactory.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/factories/medWorkspaceFactory.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medAbstractSelectableToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medActionsToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsHostToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsNodesToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsSearchToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterAbstractToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterSelectorToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationAbstractToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationSelectorToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medSelectorToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxBody.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxHeader.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxTab.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medAbstractSelectableToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medActionsToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsHostToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsNodesToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medBrowserPacsSearchToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterAbstractToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medCompositeDataSetImporterSelectorToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationAbstractToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medRegistrationSelectorToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medSelectorToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxBody.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxHeader.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/toolboxes/medToolBoxTab.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsBaseScu.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsEchoScu.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsFactory.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsFindScu.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsKey.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsMoveScu.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsNode.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsResultDataset.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScp.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScu.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medMoveCommandItem.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medPacsExport.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medPacsMover.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medPacsNode.h \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medPacsWidget.h \


SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsBaseScu.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsEchoScu.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsFactory.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsFindScu.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsMoveScu.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsNode.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsResultDataset.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScp.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medAbstractPacsStoreScu.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medPacsMover.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medPacs/medPacsWidget.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medDatabaseSettingsWidget.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsEditor.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsWidget.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medStartupSettingsWidget.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medDatabaseSettingsWidget.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsEditor.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medSettingsWidget.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/settingsWidgets/medStartupSettingsWidget.cpp \




HEADERS +=  \
  $$SOURCE_DIR_APP/areas/workspaces/diffusion/medDiffusionWorkspace.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/workspaces/diffusion/medDiffusionWorkspace.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDatabaseImporter.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDatabaseItem.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDbController.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseController.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseExporter.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseImporter.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseItem.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseModel.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentController.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentImporter.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentItem.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentItem_p.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseProxyModel.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseReader.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseRemover.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDataIndex.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDataManager.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medStorage.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medAbstractDatabaseImporter.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseController.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseExporter.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseImporter.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseItem.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseModel.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentController.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentImporter.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentItem.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseProxyModel.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseReader.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseRemover.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDataIndex.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDataManager.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medStorage.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medAbstractParameter.h \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medBoolParameter.h \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medBoolParameterGroup.h \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medDoubleParameter.h \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medIntParameter.h \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medStringParameter.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medAbstractParameter.cpp \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medBoolParameter.cpp \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medBoolParameterGroup.cpp \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medDoubleParameter.cpp \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medIntParameter.cpp \
  $$SOURCE_DIR_LAYERS/medCore/parameter/medStringParameter.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/data/medDiffusionGradientReader.h \
  $$SOURCE_DIR_LAYERS/medCore/data/medAbstractDataConverter.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/data/medDiffusionGradientReader.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medAnnotationData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medImageMaskAnnotationData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medSeedPointAnnotationData.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medAnnotationData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medImageMaskAnnotationData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/annotationData/medSeedPointAnnotationData.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractDiffusionProcess.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractProcessLegacy.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractRegistrationProcess.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medRunnableProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractDiffusionProcess.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractProcessLegacy.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medAbstractRegistrationProcess.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/process/medRunnableProcess.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/medWidgets.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/medWidgets.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medAbstractParameterPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medBoolParameterPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medDoubleParameterPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medIntParameterPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medStringParameterPresenter.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medAbstractParameterPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medBoolParameterPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medDoubleParameterPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medIntParameterPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/parameter/medStringParameterPresenter.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/medComposerExtension.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/medComposerExtension.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/process/medAbstractProcessPresenter.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/process/medAbstractProcessPresenter.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionModelEstimationProcessPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionScalarMapsProcessPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDWIMaskingProcessPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractTractographyProcessPresenter.h \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medDiffusionModelEstimationMetaProcessPresenter.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionModelEstimationProcessPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDiffusionScalarMapsProcessPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractDWIMaskingProcessPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medAbstractTractographyProcessPresenter.cpp \
  $$SOURCE_DIR_LAYERS/medWidgets/process/diffusion_processes/medDiffusionModelEstimationMetaProcessPresenter.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionModelEstimationProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionScalarMapsProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDWIMaskingProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractTractographyProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medDiffusionModelEstimationMetaProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionModelEstimationProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDiffusionScalarMapsProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractDWIMaskingProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medAbstractTractographyProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/diffusion_processes/medDiffusionModelEstimationMetaProcess.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/medAbstractProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/medAbstractProcess.cpp \

HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractAddImageProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractArithmeticOperationProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractDivideImageProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractMultiplyImageProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractSubtractImageProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/arithmetic_operation/medAbstractArithmeticOperationProcess.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medAddImageProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medArithmeticOperationProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medArithmeticOperationProcessNode.tpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medDivideImageProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medMultiplyImageProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medSubtractImageProcessNode.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medAddImageProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medDivideImageProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medMultiplyImageProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/arithmetic_operation/medSubtractImageProcessNode.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionModelEstimationProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionScalarMapsProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medDWIMaskingProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medTractographyProcessNode.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionModelEstimationProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medDiffusionScalarMapsProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medDWIMaskingProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/diffusion_processes/medTractographyProcessNode.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/mask_image/medMaskImageProcessNode.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/mask_image/medMaskImageProcessNode.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medClosingImageProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medDilateImageProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medErodeImageProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medMorphomathOperationProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medMorphomathOperationProcessNode.tpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medOpeningImageProcessNode.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medClosingImageProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medDilateImageProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medErodeImageProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/morphomath_operation/medOpeningImageProcessNode.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medAddFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medDivideFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medGaussianFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medImageDenoisingProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medInvertFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medMedianFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medMultiplyFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medNormalizeFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medShrinkFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterDoubleOperationProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterOperationProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSubtractFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSymmetryPlaneAlignmentProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medWindowingFilterProcessNode.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterDoubleOperationProcessNode.tpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSingleFilterOperationProcessNode.tpp \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medAddFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medDivideFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medGaussianFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medImageDenoisingProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medInvertFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medMedianFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medMultiplyFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medNormalizeFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medShrinkFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSubtractFilterProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medSymmetryPlaneAlignmentProcessNode.cpp \
  $$SOURCE_DIR_LAYERS/medComposer/process/single_filter/medWindowingFilterProcessNode.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/medWriterNodeBase.h \
  $$SOURCE_DIR_LAYERS/medComposer/process/medReaderNodeBase.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medComposer/process/medWriterNodeBase.cpp \




HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractClosingImageProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractDilateImageProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractErodeImageProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractMorphomathOperationProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractOpeningImageProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/morphomath_operation/medAbstractMorphomathOperationProcess.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/mask_image/medAbstractMaskImageProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/mask_image/medAbstractMaskImageProcess.cpp \

HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractAddFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractBiasCorrectionProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractDivideFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractGaussianFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractImageDenoisingProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractInvertFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractMedianFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractMultiplyFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractNormalizeFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractRelaxometryEstimationProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractShrinkFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationDoubleProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSubtractFilterProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSymmetryPlaneAlignmentProcess.h \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractWindowingFilterProcess.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractAddFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractDivideFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractGaussianFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractMedianFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractMultiplyFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractShrinkFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationDoubleProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSingleFilterOperationProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractSubtractFilterProcess.cpp \
  $$SOURCE_DIR_LAYERS/medCore/process/single_filter/medAbstractWindowingFilterProcess.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/medCore.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/medCore.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medCore/job/medAbstractJob.h \
  $$SOURCE_DIR_LAYERS/medCore/job/medJobManager.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medCore/job/medAbstractJob.cpp \
  $$SOURCE_DIR_LAYERS/medCore/job/medJobManager.cpp \


HEADERS +=  \
  $$SOURCE_DIR_APP/areas/workspaces/filtering/medFilteringWorkspace.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/workspaces/filtering/medFilteringWorkspace.cpp \



HEADERS +=  \
  $$SOURCE_DIR_APP/areas/workspaces/visualization/medVisualizationWorkspace.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/workspaces/visualization/medVisualizationWorkspace.cpp \




HEADERS +=  \
  $$SOURCE_DIR_APP/areas/homepage/medHomepageArea.h \
  $$SOURCE_DIR_APP/areas/homepage/medHomepageButton.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/homepage/medHomepageArea.cpp \
  $$SOURCE_DIR_APP/areas/homepage/medHomepageButton.cpp \


HEADERS +=  \
  $$SOURCE_DIR_APP/areas/browser/medBrowserArea.h \
  $$SOURCE_DIR_APP/areas/browser/medBrowserSourceSelectorToolBox.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/browser/medBrowserArea.cpp \
  $$SOURCE_DIR_APP/areas/browser/medBrowserSourceSelectorToolBox.cpp \


HEADERS +=  \
  $$SOURCE_DIR_APP/areas/composer/medComposerArea.h \
  $$SOURCE_DIR_APP/areas/composer/medComposerArea_p.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/composer/medComposerArea.cpp \



HEADERS +=  \
  $$SOURCE_DIR_APP/medMainWindow.h \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractImageViewInteractor.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractInteractor.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractLayeredViewInteractor.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractViewInteractor.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractImageViewInteractor.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractInteractor.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractLayeredViewInteractor.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/interactors/medAbstractViewInteractor.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractImageViewNavigator.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractNavigator.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractLayeredViewNavigator.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractViewNavigator.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractImageViewNavigator.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractNavigator.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractLayeredViewNavigator.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/navigators/medAbstractViewNavigator.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractImageView.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractLayeredView.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractView.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medImageViewEnum.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medViewFactory.h \


SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractImageView.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractLayeredView.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractView.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medViewFactory.cpp \

#HEADERS +=  \
#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDataManager.h \
#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseController.h \
#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/database/medDatabaseNonPersistentController.h \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainer.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerManager.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerSplitter.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainer.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerManager.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerSplitter.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/toolboxes/medDiffusionSelectorToolBox.h \


#parameters ...
HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterGroupL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolGroupParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medCompositeParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDataListParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDoubleParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medIntParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medLayerParameterGroupL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterGroupManagerL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolManagerL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medPoolIndicatorL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medStringListParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTimeLineParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTriggerParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector2DParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector3DParameterL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medViewParameterGroupL.h \



#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/views/medAbstractImageView.h \
#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/viewContainers/medViewContainerSplitter.h \
#
#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataFactory.h \
#  $$SOURCE_DIR_APP/medApplication.h \
#  $$SOURCE_DIR_APP/medDatabaseDataSource.h \
#  $$SOURCE_DIR_APP/medDataSourceManager.h \
#  $$SOURCE_DIR_APP/medEmptyDbWarning.h \
#  $$SOURCE_DIR_APP/medExportVideoDialog.h \
#  $$SOURCE_DIR_APP/medFileSystemDataSource.h \
#  $$SOURCE_DIR_APP/medLogger.h \

#  $$SOURCE_DIR_APP/medPacsDataSource.h \
#  $$SOURCE_DIR_APP/medPluginWidget.h \
#  $$SOURCE_DIR_APP/medQuickAccessMenu.h \
#  $$SOURCE_DIR_APP/medSaveModifiedDialog.h \
#  $$SOURCE_DIR_APP/medSearchToolboxDialog.h \
#  $$SOURCE_DIR_APP/medSplashScreen.h \


SOURCES +=  \
  $$SOURCE_DIR_APP/main.cpp \
  $$SOURCE_DIR_APP/medMainWindow.cpp \


HEADERS +=  \
  $$SOURCE_DIR_APP/QSingleApplication/qtsingleapplication.h \
  $$SOURCE_DIR_APP/QSingleApplication/qtlocalpeer.h \
  $$SOURCE_DIR_APP/QSingleApplication/qtlockedfile.h \
  $$SOURCE_DIR_APP/QSingleApplication/qtsinglecoreapplication.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/QSingleApplication/qtsingleapplication.cpp \
  $$SOURCE_DIR_APP/QSingleApplication/qtlocalpeer.cpp \
  $$SOURCE_DIR_APP/QSingleApplication/qtlockedfile.cpp \
  $$SOURCE_DIR_APP/QSingleApplication/qtsinglecoreapplication.cpp \


HEADERS +=  \
  $$SOURCE_DIR_APP/areas/workspaces/medWorkspaceArea.h \
  $$SOURCE_DIR_APP/areas/workspaces/medWorkspaceArea_p.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/areas/workspaces/medWorkspaceArea.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSource.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSourceFactory.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medCoreLegacyExport.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medGlobalDefs.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medJobItemL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medJobManagerL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medMessageController.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medPluginLegacy.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medPluginManager.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medSettingsManager.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medStyleSheetParser.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medViewEventFilter.h \


SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSource.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medAbstractDataSourceFactory.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medGlobalDefs.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medJobItemL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medJobManagerL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medMessageController.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medPluginLegacy.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medPluginManager.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medSettingsManager.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medStyleSheetParser.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/medViewEventFilter.cpp \


HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataFactory.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataWriter.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDiffusionModelImageData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractFibersData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractImageData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMaskData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMeshData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractRoi.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAttachedData.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medDataReaderWriter.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medMetaDataKeys.h \

\#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractTypedDiffusionModelImageData.h \
\#  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractTypedImageData.h \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medAbstractWorkspaceLegacy.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medLinkMenu.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medPacsSelector.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medRootContainer.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medSelectorWorkspace.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medTabbedViewContainers.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medTableWidgetChooser.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medToolBoxContainer.h \


SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medAbstractWorkspaceLegacy.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medLinkMenu.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medPacsSelector.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medRootContainer.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medSelectorWorkspace.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medTabbedViewContainers.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medTableWidgetChooser.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/medToolBoxContainer.cpp \




SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAttachedData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataFactory.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDataWriter.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractDiffusionModelImageData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractFibersData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractImageData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMaskData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractMeshData.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medAbstractRoi.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medDataReaderWriter.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/data/medMetaDataKeys.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseCompactWidget.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseEditItemDialog.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseMetadataItemDialog.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabasePreview.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseSearchPanel.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseView.h \


SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseCompactWidget.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseEditItemDialog.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseMetadataItemDialog.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabasePreview.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseSearchPanel.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/database/medDatabaseView.cpp \



HEADERS +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medButton.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medComboBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medDropSite.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medGroupBox.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medListWidget.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medProgressionStack.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medSliderL.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medSliderSpinboxPair.h \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medStatusBar.h \

SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medSliderL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medButton.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medDropSite.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medGroupBox.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medProgressionStack.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/gui/commonWidgets/medStatusBar.cpp \


SOURCES +=  \
  $$SOURCE_DIR_LAYERS/medWidgets/toolboxes/medDiffusionSelectorToolBox.cpp \



#parameters ...
SOURCES +=  \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterGroupL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medAbstractParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolGroupParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medBoolParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medCompositeParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDataListParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medDoubleParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medIntParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medLayerParameterGroupL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterGroupManagerL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medParameterPoolManagerL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medPoolIndicatorL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medStringListParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTimeLineParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medTriggerParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector2DParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medVector3DParameterL.cpp \
  $$SOURCE_DIR_LAYERS/legacy/medCoreLegacy/parameters/medViewParameterGroupL.cpp \


HEADERS +=  \
  $$SOURCE_DIR_APP/medApplication.h \
  $$SOURCE_DIR_APP/medDatabaseDataSource.h \
  $$SOURCE_DIR_APP/medDataSourceManager.h \
  $$SOURCE_DIR_APP/medEmptyDbWarning.h \
  $$SOURCE_DIR_APP/medExportVideoDialog.h \
  $$SOURCE_DIR_APP/medFileSystemDataSource.h \
  $$SOURCE_DIR_APP/medLogger.h \
  $$SOURCE_DIR_APP/medPacsDataSource.h \
  $$SOURCE_DIR_APP/medPluginWidget.h \
  $$SOURCE_DIR_APP/medQuickAccessMenu.h \
  $$SOURCE_DIR_APP/medSaveModifiedDialog.h \
  $$SOURCE_DIR_APP/medSearchToolboxDialog.h \
  $$SOURCE_DIR_APP/medSplashScreen.h \

SOURCES +=  \
  $$SOURCE_DIR_APP/medApplication.cpp \
  $$SOURCE_DIR_APP/medDatabaseDataSource.cpp \
  $$SOURCE_DIR_APP/medDataSourceManager.cpp \
  $$SOURCE_DIR_APP/medEmptyDbWarning.cpp \
  $$SOURCE_DIR_APP/medExportVideoDialog.cpp \
  $$SOURCE_DIR_APP/medFileSystemDataSource.cpp \
  $$SOURCE_DIR_APP/medLogger.cpp \
  $$SOURCE_DIR_APP/medPacsDataSource.cpp \
  $$SOURCE_DIR_APP/medPluginWidget.cpp \
  $$SOURCE_DIR_APP/medQuickAccessMenu.cpp \
  $$SOURCE_DIR_APP/medSaveModifiedDialog.cpp \
  $$SOURCE_DIR_APP/medSearchToolboxDialog.cpp \
  $$SOURCE_DIR_APP/medSplashScreen.cpp \



LIBS += -L$$MEDINRIA_EXTERNAL_LIB_DIR -ldtkGuiSupport  -ldtkLog -ldtkCoreSupport \
  -ldtkCore -ldtkComposer -ldtkDistributed -ldtkMath  -ldtkWidgets \
  -ldtkMeta 





HEADERS += \


SOURCES += \



