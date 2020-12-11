
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += widgets network

QT += help


include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)




INCLUDEPATH += $$SRC_GROUP_DIR  \
  $$SRC_GROUP_DIR/zoattestingctk \
  $$SRC_GROUP_DIR/Paraview-Remoting/ServerManager \
  $$SRC_GROUP_DIR/Paraview-Remoting/Core \
  $$SRC_GROUP_DIR/Paraview-Remoting/ClientServerStream \
  $$SRC_GROUP_DIR/Paraview-Remoting/Settings \
  $$SRC_GROUP_DIR/Paraview-Remoting/Views \
  $$SRC_GROUP_DIR/Paraview-Remoting/Animation \
  $$SRC_GROUP_DIR/Paraview-Remoting/Live \
  $$SRC_GROUP_DIR/Paraview-Remoting/Misc \
  $$SRC_GROUP_DIR/Paraview-Remoting/Export \




FORMS += \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqColorOpacityEditorWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqResetScalarRangeToDataOverTime.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqEditMenuBuilder.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqOMETransferFunctionsPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqOMETransferFunctionsPropertyWidgetPage.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqColorAnnotationsWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqTransferFunctionWidgetPropertyDialog.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqSpherePropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqColorToolbar.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqMoleculePropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqCameraToolbar.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqHandlePropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqLightPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqDataAssemblyPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqExampleVisualizationsDialog.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqCustomResolutionDialog.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqWelcomeDialog.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqTransferFunctionWidgetPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqFileMenuBuilder.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqSeriesEditorPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqSplinePropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqVCRToolbar.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqColorEditorPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqCameraManipulatorWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqYoungsMaterialPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqTimeInspectorWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqMainControlsToolbar.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqSavePresetOptions.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqLinePropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqCustomizeShortcutsDialog.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqPropertyCollectionWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqAxesToolbar.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqSpreadSheetViewDecorator.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqBackgroundEditorWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqFontPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqImplicitPlanePropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqCylinderPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqImageCompressorWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqDoubleRangeSliderPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqBoxPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqTextLocationWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqDefaultMainWindow.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqColorMapEditor.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqViewResolutionPropertyWidget.ui \
  $$SRC_DIR/ApplicationComponents/Resources/UI/pqEmptyView.ui \
  $$SRC_DIR/Widgets/Resources/UI/pqSeriesGeneratorDialog.ui \
  $$SRC_DIR/Widgets/Resources/UI/pqExpanderButton.ui \
  $$SRC_DIR/Widgets/Resources/UI/pqHelpWindow.ui \
  $$SRC_DIR/Widgets/Resources/UI/pqQuickLaunchDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqLockViewSizeCustomDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqFindDataCreateSelectionFrame.ui \
  $$SRC_DIR/Components/Resources/UI/pqProxyInformationWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqPresetDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqServerConnectDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqSampleScalarWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqDisplayRepresentationWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqSettingsDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqComparativeVisPanel.ui \
  $$SRC_DIR/Components/Resources/UI/pqMemoryInspectorPanelForm.ui \
  $$SRC_DIR/Components/Resources/UI/pqFindDataDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqQueryCompositeTreeDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqPopoutPlaceholder.ui \
  $$SRC_DIR/Components/Resources/UI/pqConnectIdDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqCameraKeyFrameWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqServerLauncherDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqMultiBlockInspectorWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqLogViewerDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqScalarValueListPropertyWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqLinksEditor.ui \
  $$SRC_DIR/Components/Resources/UI/pqRemoteCommandDialogForm.ui \
  $$SRC_DIR/Components/Resources/UI/pqKeyFrameEditor.ui \
  $$SRC_DIR/Components/Resources/UI/pqPluginDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqCustomViewpointButtonDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqCustomFilterManager.ui \
  $$SRC_DIR/Components/Resources/UI/pqKeyFrameTypeWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqAbortAnimation.ui \
  $$SRC_DIR/Components/Resources/UI/pqSelectionLinkDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqSetBreakpointDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqLightsInspector.ui \
  $$SRC_DIR/Components/Resources/UI/pqSelectReaderDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqCustomFilterDefinitionWizard.ui \
  $$SRC_DIR/Components/Resources/UI/pqRemoteCommandTemplateDialogForm.ui \
  $$SRC_DIR/Components/Resources/UI/pqQueryClauseWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqCollaborationPanel.ui \
  $$SRC_DIR/Components/Resources/UI/pqLinksManager.ui \
  $$SRC_DIR/Components/Resources/UI/pqCalculatorWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqAnimationTimeWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqViewFrame.ui \
  $$SRC_DIR/Components/Resources/UI/pqTimerLogDisplay.ui \
  $$SRC_DIR/Components/Resources/UI/pqProxySelectionWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqOrbitCreatorDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqContourControls.ui \
  $$SRC_DIR/Components/Resources/UI/pqSampleScalarAddRangeDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqPipelineTimeKeyFrameEditor.ui \
  $$SRC_DIR/Components/Resources/UI/pqFindDataCurrentSelectionFrame.ui \
  $$SRC_DIR/Components/Resources/UI/pqAboutDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqLightsEditor.ui \
  $$SRC_DIR/Components/Resources/UI/pqProxyWidgetDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqChangeInputDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqSelectionInputWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqRescaleRangeDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqSearchBox.ui \
  $$SRC_DIR/Components/Resources/UI/pqFindDataSelectionDisplayFrame.ui \
  $$SRC_DIR/Components/Resources/UI/pqPropertiesPanel.ui \
  $$SRC_DIR/Components/Resources/UI/pqComparativeParameterRangeDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqCameraDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqItemViewSearchWidget.ui \
  $$SRC_DIR/Components/Resources/UI/pqFavoritesDialog.ui \
  $$SRC_DIR/Components/Resources/UI/pqPythonAnimationCue.ui \
  $$SRC_DIR/Core/Resources/UI/pqPluginEULADialog.ui \
  $$SRC_DIR/Core/Resources/UI/pqOutputWidget.ui \
  $$SRC_DIR/Core/Resources/UI/pqFileDialog.ui \
  $$SRC_DIR/Core/Resources/UI/pqLogViewerWidget.ui \



INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Core
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/FiltersRendering

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Remoting/ViewsPython



INCLUDEPATH += $$SRC_DIR/Components  $$SRC_DIR/Core \
  $$SRC_DIR/Widgets \




#include($$ROOT_DIR/../preferred/itk.pri)
include($$ROOT_DIR/../preferred/vtk.pri)

#include($$ROOT_DIR/../preferred/opencv.pri)

INCLUDEPATH += $$ALT_DIR/vtkqttesting

#INCLUDEPATH += /home/nlevisrael/pv/pvsbb/install/include/paraview-5.7/vtkqttesting



INCLUDEPATH += $$VTK_BUILD_DIR/Interaction/Style
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/OpenGL2
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/UI
INCLUDEPATH += $$VTK_BUILD_DIR/Charts/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Context2D
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/jsoncpp


DEFINES += VTK_LEGACY\\(x\\)=x

#INCLUDEPATH += /home/nlevisrael/sebi-libs/VTK-Build/Interaction/Style


INCLUDEPATH += $$VTK_SRC_DIR/Common/Core
INCLUDEPATH += $$VTK_SRC_DIR/Common/Math
INCLUDEPATH += $$VTK_SRC_DIR/Common/ExecutionModel
INCLUDEPATH += $$VTK_SRC_DIR/Common/DataModel
INCLUDEPATH += $$VTK_SRC_DIR/Common/Misc
INCLUDEPATH += $$VTK_SRC_DIR/Charts/Core
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Core
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Context2D
INCLUDEPATH += $$VTK_SRC_DIR/Views/Context2D
INCLUDEPATH += $$VTK_SRC_DIR/Views/Core
INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/jsoncpp
INCLUDEPATH += $$VTK_SRC_DIR/IO/Core
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Core
INCLUDEPATH += $$VTK_SRC_DIR/IO/XMLParser
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/KWIML
INCLUDEPATH += $$VTK_SRC_DIR/GUISupport/Qt
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/OpenGL2
INCLUDEPATH += $$VTK_SRC_DIR/Filters/General
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/VtkJS


INCLUDEPATH += $$VTK_SRC_DIR/Common/Transforms
INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/pugixml
INCLUDEPATH += $$VTK_SRC_DIR/Common/System
INCLUDEPATH += $$VTK_SRC_DIR/IO/Image
INCLUDEPATH += $$VTK_SRC_DIR/Imaging/Core
INCLUDEPATH += $$VTK_SRC_DIR/Testing/Rendering
INCLUDEPATH += $$VTK_SRC_DIR/Interaction/Widgets


INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/VtkJS
INCLUDEPATH += $$VTK_BUILD_DIR/Interaction/Widgets
INCLUDEPATH += $$VTK_BUILD_DIR/Testing/Rendering
INCLUDEPATH += $$VTK_BUILD_DIR/Imaging/Core
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Image
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/General
INCLUDEPATH += $$VTK_BUILD_DIR/Common/System

INCLUDEPATH += $$VTK_BUILD_DIR/Common/Transforms
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Math
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/pugixml
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/pugixml/vtkpugixml



INCLUDEPATH += $$VTK_BUILD_DIR/Common/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Common/DataModel
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/jsoncpp/vtkjsoncpp/json
INCLUDEPATH += $$VTK_BUILD_DIR/Views/Core
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Views/Context2D
INCLUDEPATH += $$VTK_BUILD_DIR/Utilities/KWSys/
INCLUDEPATH += $$VTK_BUILD_DIR/Common/ExecutionModel
INCLUDEPATH += $$VTK_BUILD_DIR/IO/XMLParser
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Misc

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Remoting/Export
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Remoting/Application


INCLUDEPATH += $$SRC_DIR/ApplicationComponents
INCLUDEPATH += $$SRC_DIR/Python


DEFINES += FONT_METRICS_WIDTH_OR_HORIZONTAL_ADVANCE=width
#DEFINES += FONT_METRICS_WIDTH_OR_HORIZONTAL_ADVANCE=horizontalAdvance


HEADERS += \
  $$SRC_GROUP_DIR/QVTKOpenGLStereoWidget.h \
  $$SRC_GROUP_DIR/zoattestingctk/pqPythonEventSource.h


SOURCES += \
  $$SRC_GROUP_DIR/zoattestingctk/pqPythonEventSource.cxx


INCLUDEPATH += /usr/include/python2.7/


HEADERS += \
  $$SRC_DIR/ApplicationComponents/pqAboutDialogReaction.h \
  $$SRC_DIR/ApplicationComponents/pqAddToFavoritesReaction.h \
  $$SRC_DIR/ApplicationComponents/pqAlwaysConnectedBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqAnimationShortcutDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqAnimationShortcutWidget.h \
  $$SRC_DIR/ApplicationComponents/pqAnimationTimeToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqAnnotationsModel.h \
  $$SRC_DIR/ApplicationComponents/pqApplicationComponentsInit.h \
  $$SRC_DIR/ApplicationComponents/pqApplicationSettingsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqApplyBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqApplyPropertiesReaction.h \
  $$SRC_DIR/ApplicationComponents/pqAutoApplyReaction.h \
  $$SRC_DIR/ApplicationComponents/pqAutoLoadPluginXMLBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqAxesToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqBackgroundEditorWidget.h \
  $$SRC_DIR/ApplicationComponents/pqBoolPropertyWidgetDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqBoxPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqCameraLinkReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCameraManipulatorWidget.h \
  $$SRC_DIR/ApplicationComponents/pqCameraReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCameraToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqCameraUndoRedoReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCatalystConnectReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCatalystContinueReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCatalystExportReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCatalystPauseSimulationReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCatalystRemoveBreakpointReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCatalystSetBreakpointReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCategoryToolbarsBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqChangePipelineInputReaction.h \
  $$SRC_DIR/ApplicationComponents/pqChartSelectionReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCheckableProperty.h \
  $$SRC_DIR/ApplicationComponents/pqChooseColorPresetReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCollaborationBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqColorAnnotationsPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqColorAnnotationsWidget.h \
  $$SRC_DIR/ApplicationComponents/pqColorEditorPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqColorMapEditor.h \
  $$SRC_DIR/ApplicationComponents/pqColorOpacityEditorWidget.h \
  $$SRC_DIR/ApplicationComponents/pqColorPaletteSelectorWidget.h \
  $$SRC_DIR/ApplicationComponents/pqColorSelectorPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqColorTableModel.h \
  $$SRC_DIR/ApplicationComponents/pqColorToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqCommandButtonPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqCommandLineOptionsBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqCopyReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCrashRecoveryBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqCreateCustomFilterReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCTHArraySelectionDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqCustomizeShortcutsDialog.h \
  $$SRC_DIR/ApplicationComponents/pqCustomizeShortcutsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqCustomShortcutBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqCustomViewpointsToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqCylinderPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqDataAssemblyPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqDataQueryReaction.h \
  $$SRC_DIR/ApplicationComponents/pqDataTimeStepBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqDefaultMainWindow.h \
  $$SRC_DIR/ApplicationComponents/pqDefaultViewBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqDeleteReaction.h \
  $$SRC_DIR/ApplicationComponents/pqDesktopServicesReaction.h \
  $$SRC_DIR/ApplicationComponents/pqDoubleRangeSliderPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqEditCameraReaction.h \
  $$SRC_DIR/ApplicationComponents/pqEditColorMapReaction.h \
  $$SRC_DIR/ApplicationComponents/pqEditScalarBarReaction.h \
  $$SRC_DIR/ApplicationComponents/pqEnableWidgetDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqExampleVisualizationsDialog.h \
  $$SRC_DIR/ApplicationComponents/pqExampleVisualizationsDialogReaction.h \
  $$SRC_DIR/ApplicationComponents/pqExportReaction.h \
  $$SRC_DIR/ApplicationComponents/pqExtractorsMenuReaction.h \
  $$SRC_DIR/ApplicationComponents/pqFileNamePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqFiltersMenuReaction.h \
  $$SRC_DIR/ApplicationComponents/pqFontPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqGenericPropertyWidgetDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqGlyphScaleFactorPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqHandlePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqHelpReaction.h \
  $$SRC_DIR/ApplicationComponents/pqIgnoreSourceTimeReaction.h \
  $$SRC_DIR/ApplicationComponents/pqImageCompressorWidget.h \
  $$SRC_DIR/ApplicationComponents/pqImplicitPlanePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqInputDataTypeDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqInteractivePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqLightPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqLinePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqLinkSelectionReaction.h \
  $$SRC_DIR/ApplicationComponents/pqListPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqLiveSourceBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqLoadDataReaction.h \
  $$SRC_DIR/ApplicationComponents/pqLoadMaterialsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqLoadPaletteReaction.h \
  $$SRC_DIR/ApplicationComponents/pqLoadRestoreWindowLayoutReaction.h \
  $$SRC_DIR/ApplicationComponents/pqLoadStateReaction.h \
  $$SRC_DIR/ApplicationComponents/pqLockPanelsBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqLockPanelsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqLogViewerReaction.h \
  $$SRC_DIR/ApplicationComponents/pqMacroReaction.h \
  $$SRC_DIR/ApplicationComponents/pqMainControlsToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqMainWindowEventBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqManageCustomFiltersReaction.h \
  $$SRC_DIR/ApplicationComponents/pqManageFavoritesReaction.h \
  $$SRC_DIR/ApplicationComponents/pqManageLinksReaction.h \
  $$SRC_DIR/ApplicationComponents/pqManagePluginsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqMasterOnlyReaction.h \
  $$SRC_DIR/ApplicationComponents/pqMenuReactionUtils.h \
  $$SRC_DIR/ApplicationComponents/pqModelTransformSupportBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqMoleculePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqMultiComponentsDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqObjectPickingBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqOMETransferFunctionsPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqOpacityTableModel.h \
  $$SRC_DIR/ApplicationComponents/pqOpenVRHidingDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqOSPRayHidingDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqParaViewBehaviors.h \
  $$SRC_DIR/ApplicationComponents/pqParaViewMenuBuilders.h \
  $$SRC_DIR/ApplicationComponents/pqPauseLiveSourcePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqPersistentMainWindowStateBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPipelineContextMenuBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPluginActionGroupBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPluginDockWidgetsBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPluginDocumentationBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPluginPathBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPluginSettingsBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPluginToolBarBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqPointPickingHelper.h \
  $$SRC_DIR/ApplicationComponents/pqPreviewMenuManager.h \
  $$SRC_DIR/ApplicationComponents/pqPropertyCollectionWidget.h \
  $$SRC_DIR/ApplicationComponents/pqProxyGroupMenuManager.h \
  $$SRC_DIR/ApplicationComponents/pqPVAnimationWidget.h \
  $$SRC_DIR/ApplicationComponents/pqPVApplicationCore.h \
  $$SRC_DIR/ApplicationComponents/pqReaction.h \
  $$SRC_DIR/ApplicationComponents/pqReloadFilesReaction.h \
  $$SRC_DIR/ApplicationComponents/pqRenameProxyReaction.h \
  $$SRC_DIR/ApplicationComponents/pqRenderViewSelectionReaction.h \
  $$SRC_DIR/ApplicationComponents/pqRepresentationToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqResetDefaultSettingsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqResetScalarRangeReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSaveAnimationGeometryReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSaveAnimationReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSaveDataReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSaveExtractsReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSaveScreenshotReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSaveStateReaction.h \
  $$SRC_DIR/ApplicationComponents/pqScalarBarVisibilityReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSearchItemReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSelectionReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSeriesEditorPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqServerConnectReaction.h \
  $$SRC_DIR/ApplicationComponents/pqServerDisconnectReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSetMainWindowTitleReaction.h \
  $$SRC_DIR/ApplicationComponents/pqShowHideAllReaction.h \
  $$SRC_DIR/ApplicationComponents/pqShowWidgetDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqSourcesMenuReaction.h \
  $$SRC_DIR/ApplicationComponents/pqSpherePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqSplinePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqSpreadSheetViewDecorator.h \
  $$SRC_DIR/ApplicationComponents/pqSpreadSheetVisibilityBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqStandardPropertyWidgetInterface.h \
  $$SRC_DIR/ApplicationComponents/pqStandardRecentlyUsedResourceLoaderImplementation.h \
  $$SRC_DIR/ApplicationComponents/pqStandardViewFrameActionsImplementation.h \
  $$SRC_DIR/ApplicationComponents/pqStatusBar.h \
  $$SRC_DIR/ApplicationComponents/pqStreamingTestingEventPlayer.h \
  $$SRC_DIR/ApplicationComponents/pqTemporalExportReaction.h \
  $$SRC_DIR/ApplicationComponents/pqTestingReaction.h \
  $$SRC_DIR/ApplicationComponents/pqTextLocationWidget.h \
  $$SRC_DIR/ApplicationComponents/pqTimeInspectorWidget.h \
  $$SRC_DIR/ApplicationComponents/pqTimerLogReaction.h \
  $$SRC_DIR/ApplicationComponents/pqToggleInteractionViewMode.h \
  $$SRC_DIR/ApplicationComponents/pqTraceReaction.h \
  $$SRC_DIR/ApplicationComponents/pqTransferFunctionWidgetPropertyDialog.h \
  $$SRC_DIR/ApplicationComponents/pqTransferFunctionWidgetPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqUndoRedoBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqUndoRedoReaction.h \
  $$SRC_DIR/ApplicationComponents/pqUsageLoggingBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqUseSeparateColorMapReaction.h \
  $$SRC_DIR/ApplicationComponents/pqVCRToolbar.h \
  $$SRC_DIR/ApplicationComponents/pqVerifyRequiredPluginBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqViewMenuManager.h \
  $$SRC_DIR/ApplicationComponents/pqViewResolutionPropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqViewStreamingBehavior.h \
  $$SRC_DIR/ApplicationComponents/pqViewTypePropertyWidget.h \
  $$SRC_DIR/ApplicationComponents/pqWelcomeDialog.h \
  $$SRC_DIR/ApplicationComponents/pqYoungsMaterialPropertyWidget.h \


SOURCES += \
  $$SRC_DIR/ApplicationComponents/pqAboutDialogReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqAddToFavoritesReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqAlwaysConnectedBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqAnimationShortcutDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqAnimationShortcutWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqAnimationTimeToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqAnnotationsModel.cxx \
  $$SRC_DIR/ApplicationComponents/pqApplicationComponentsInit.cxx \
  $$SRC_DIR/ApplicationComponents/pqApplicationSettingsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqApplyBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqApplyPropertiesReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqAutoApplyReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqAutoLoadPluginXMLBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqAxesToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqBackgroundEditorWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqBoolPropertyWidgetDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqBoxPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqCameraLinkReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCameraManipulatorWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqCameraReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCameraToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqCameraUndoRedoReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCatalystConnectReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCatalystExportReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCatalystPauseSimulationReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCatalystRemoveBreakpointReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCatalystSetBreakpointReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCategoryToolbarsBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqChangePipelineInputReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqChartSelectionReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCheckableProperty.cxx \
  $$SRC_DIR/ApplicationComponents/pqChooseColorPresetReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCollaborationBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorAnnotationsPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorAnnotationsWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorEditorPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorMapEditor.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorOpacityEditorWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorPaletteSelectorWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorSelectorPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorTableModel.cxx \
  $$SRC_DIR/ApplicationComponents/pqColorToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqCommandButtonPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqCommandLineOptionsBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqCopyReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCrashRecoveryBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqCreateCustomFilterReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCTHArraySelectionDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqCustomizeShortcutsDialog.cxx \
  $$SRC_DIR/ApplicationComponents/pqCustomizeShortcutsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqCustomShortcutBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqCustomViewpointsToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqCylinderPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqDataAssemblyPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqDataQueryReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqDataTimeStepBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqDefaultMainWindow.cxx \
  $$SRC_DIR/ApplicationComponents/pqDefaultViewBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqDeleteReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqDesktopServicesReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqDoubleRangeSliderPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqEditCameraReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqEditColorMapReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqEditScalarBarReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqEnableWidgetDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqExampleVisualizationsDialog.cxx \
  $$SRC_DIR/ApplicationComponents/pqExampleVisualizationsDialogReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqExportReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqExtractorsMenuReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqFileNamePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqFiltersMenuReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqFontPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqGenericPropertyWidgetDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqGlyphScaleFactorPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqHandlePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqHelpReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqIgnoreSourceTimeReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqImageCompressorWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqImplicitPlanePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqInputDataTypeDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqInteractivePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqLightPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqLinePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqLinkSelectionReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqListPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqLiveSourceBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqLoadDataReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqLoadMaterialsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqLoadPaletteReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqLoadRestoreWindowLayoutReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqLoadStateReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqLockPanelsBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqLockPanelsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqLogViewerReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqMacroReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqMainControlsToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqMainWindowEventBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqManageCustomFiltersReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqManageFavoritesReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqManageLinksReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqManagePluginsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqMasterOnlyReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqMenuReactionUtils.cxx \
  $$SRC_DIR/ApplicationComponents/pqModelTransformSupportBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqMoleculePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqMultiComponentsDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqObjectPickingBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqOMETransferFunctionsPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqOpacityTableModel.cxx \
  $$SRC_DIR/ApplicationComponents/pqOSPRayHidingDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqParaViewBehaviors.cxx \
  $$SRC_DIR/ApplicationComponents/pqParaViewMenuBuilders.cxx \
  $$SRC_DIR/ApplicationComponents/pqPauseLiveSourcePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqPersistentMainWindowStateBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPipelineContextMenuBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPluginActionGroupBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPluginDockWidgetsBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPluginDocumentationBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPluginPathBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPluginSettingsBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPluginToolBarBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqPointPickingHelper.cxx \
  $$SRC_DIR/ApplicationComponents/pqPreviewMenuManager.cxx \
  $$SRC_DIR/ApplicationComponents/pqPropertyCollectionWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqProxyGroupMenuManager.cxx \
  $$SRC_DIR/ApplicationComponents/pqPVAnimationWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqPVApplicationCore.cxx \
  $$SRC_DIR/ApplicationComponents/pqReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqReloadFilesReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqRenameProxyReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqRenderViewSelectionReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqRepresentationToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqResetDefaultSettingsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqResetScalarRangeReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSaveAnimationGeometryReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSaveAnimationReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSaveDataReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSaveExtractsReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSaveScreenshotReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSaveStateReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqScalarBarVisibilityReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSearchItemReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSelectionReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSeriesEditorPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqServerConnectReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqServerDisconnectReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSetMainWindowTitleReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqShowHideAllReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqShowWidgetDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqSourcesMenuReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqSpherePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqSplinePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqSpreadSheetViewDecorator.cxx \
  $$SRC_DIR/ApplicationComponents/pqSpreadSheetVisibilityBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqStandardPropertyWidgetInterface.cxx \
  $$SRC_DIR/ApplicationComponents/pqStandardRecentlyUsedResourceLoaderImplementation.cxx \
  $$SRC_DIR/ApplicationComponents/pqStandardViewFrameActionsImplementation.cxx \
  $$SRC_DIR/ApplicationComponents/pqStatusBar.cxx \
  $$SRC_DIR/ApplicationComponents/pqStreamingTestingEventPlayer.cxx \
  $$SRC_DIR/ApplicationComponents/pqTemporalExportReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqTestingReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqTextLocationWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqTimeInspectorWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqTimerLogReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqToggleInteractionViewMode.cxx \
  $$SRC_DIR/ApplicationComponents/pqTraceReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqTransferFunctionWidgetPropertyDialog.cxx \
  $$SRC_DIR/ApplicationComponents/pqTransferFunctionWidgetPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqUndoRedoBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqUndoRedoReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqUsageLoggingBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqUseSeparateColorMapReaction.cxx \
  $$SRC_DIR/ApplicationComponents/pqVCRToolbar.cxx \
  $$SRC_DIR/ApplicationComponents/pqVerifyRequiredPluginBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqViewMenuManager.cxx \
  $$SRC_DIR/ApplicationComponents/pqViewResolutionPropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqViewStreamingBehavior.cxx \
  $$SRC_DIR/ApplicationComponents/pqViewTypePropertyWidget.cxx \
  $$SRC_DIR/ApplicationComponents/pqWelcomeDialog.cxx \
  $$SRC_DIR/ApplicationComponents/pqYoungsMaterialPropertyWidget.cxx \


HEADERS += \
  $$SRC_DIR/Components/pqAboutDialog.h \
  $$SRC_DIR/Components/pqAbstractItemSelectionModel.h \
  $$SRC_DIR/Components/pqActionGroupInterface.h \
  $$SRC_DIR/Components/pqActiveObjects.h \
  $$SRC_DIR/Components/pqAnimatablePropertiesComboBox.h \
  $$SRC_DIR/Components/pqAnimatableProxyComboBox.h \
  $$SRC_DIR/Components/pqAnimationManager.h \
  $$SRC_DIR/Components/pqAnimationProgressDialog.h \
  $$SRC_DIR/Components/pqAnimationTimeWidget.h \
  $$SRC_DIR/Components/pqAnimationViewWidget.h \
  $$SRC_DIR/Components/pqArrayListDomain.h \
  $$SRC_DIR/Components/pqArraySelectionWidget.h \
  $$SRC_DIR/Components/pqArraySelectorPropertyWidget.h \
  $$SRC_DIR/Components/pqArrayStatusPropertyWidget.h \
  $$SRC_DIR/Components/pqCalculatorWidget.h \
  $$SRC_DIR/Components/pqCameraDialog.h \
  $$SRC_DIR/Components/pqCameraKeyFrameWidget.h \
  $$SRC_DIR/Components/pqChangeInputDialog.h \
  $$SRC_DIR/Components/pqCollaborationPanel.h \
  $$SRC_DIR/Components/pqColorChooserButtonWithPalettes.h \
  $$SRC_DIR/Components/pqComboBoxDomain.h \
  $$SRC_DIR/Components/pqCommandPropertyWidget.h \
  $$SRC_DIR/Components/pqComparativeCueWidget.h \
  $$SRC_DIR/Components/pqComparativeVisPanel.h \
  $$SRC_DIR/Components/pqComponentsInit.h \
  $$SRC_DIR/Components/pqComponentsTestUtility.h \
  $$SRC_DIR/Components/pqCompositeDataInformationTreeModel.h \
  $$SRC_DIR/Components/pqCompositePropertyWidgetDecorator.h \
  $$SRC_DIR/Components/pqCompositeTreePropertyWidget.h \
  $$SRC_DIR/Components/pqCustomFilterDefinitionModel.h \
  $$SRC_DIR/Components/pqCustomFilterDefinitionWizard.h \
  $$SRC_DIR/Components/pqCustomFilterManager.h \
  $$SRC_DIR/Components/pqCustomFilterManagerModel.h \
  $$SRC_DIR/Components/pqCustomViewpointButtonDialog.h \
  $$SRC_DIR/Components/pqDataAssemblyTreeModel.h \
  $$SRC_DIR/Components/pqDataInformationModel.h \
  $$SRC_DIR/Components/pqDataInformationWidget.h \
  $$SRC_DIR/Components/pqDialog.h \
  $$SRC_DIR/Components/pqDisplayColorWidget.h \
  $$SRC_DIR/Components/pqDisplayPanel.h \
  $$SRC_DIR/Components/pqDisplayPanelInterface.h \
  $$SRC_DIR/Components/pqDisplayPanelPropertyWidget.h \
  $$SRC_DIR/Components/pqDisplayRepresentationWidget.h \
  $$SRC_DIR/Components/pqDockWindowInterface.h \
  $$SRC_DIR/Components/pqDoubleVectorPropertyWidget.h \
  $$SRC_DIR/Components/pqFavoritesDialog.h \
  $$SRC_DIR/Components/pqFavoritesTreeWidget.h \
  $$SRC_DIR/Components/pqFileChooserWidget.h \
  $$SRC_DIR/Components/pqFindDataCreateSelectionFrame.h \
  $$SRC_DIR/Components/pqFindDataCurrentSelectionFrame.h \
  $$SRC_DIR/Components/pqFindDataDialog.h \
  $$SRC_DIR/Components/pqFindDataSelectionDisplayFrame.h \
  $$SRC_DIR/Components/pqHighlightItemDelegate.h \
  $$SRC_DIR/Components/pqImageCompressorType.h \
  $$SRC_DIR/Components/pqImageTip.h \
  $$SRC_DIR/Components/pqIndexSelectionWidget.h \
  $$SRC_DIR/Components/pqInputSelectorWidget.h \
  $$SRC_DIR/Components/pqIntMaskPropertyWidget.h \
  $$SRC_DIR/Components/pqIntRangeWidget.h \
  $$SRC_DIR/Components/pqIntVectorPropertyWidget.h \
  $$SRC_DIR/Components/pqItemViewSearchWidget.h \
  $$SRC_DIR/Components/pqItemViewSearchWidgetEventPlayer.h \
  $$SRC_DIR/Components/pqKeyFrameEditor.h \
  $$SRC_DIR/Components/pqKeyFrameTimeValidator.h \
  $$SRC_DIR/Components/pqKeyFrameTypeWidget.h \
  $$SRC_DIR/Components/pqLabel.h \
  $$SRC_DIR/Components/pqLightsEditor.h \
  $$SRC_DIR/Components/pqLightsInspector.h \
  $$SRC_DIR/Components/pqLinksEditor.h \
  $$SRC_DIR/Components/pqLinksManager.h \
  $$SRC_DIR/Components/pqLiveInsituManager.h \
  $$SRC_DIR/Components/pqLiveInsituVisualizationManager.h \
  $$SRC_DIR/Components/pqLockViewSizeCustomDialog.h \
  $$SRC_DIR/Components/pqLogViewerDialog.h \
  $$SRC_DIR/Components/pqMemoryInspectorPanel.h \
  $$SRC_DIR/Components/pqMultiBlockInspectorWidget.h \
  $$SRC_DIR/Components/pqMultiQueryClauseWidget.h \
  $$SRC_DIR/Components/pqMultiViewWidget.h \
  $$SRC_DIR/Components/pqOrbitCreatorDialog.h \
  $$SRC_DIR/Components/pqOutputPortComboBox.h \
  $$SRC_DIR/Components/pqPipelineAnnotationFilterModel.h \
  $$SRC_DIR/Components/pqPipelineBrowserWidget.h \
  $$SRC_DIR/Components/pqPipelineInputComboBox.h \
  $$SRC_DIR/Components/pqPipelineModel.h \
  $$SRC_DIR/Components/pqPipelineModelSelectionAdaptor.h \
  $$SRC_DIR/Components/pqPipelineTimeKeyFrameEditor.h \
  $$SRC_DIR/Components/pqPluginDialog.h \
  $$SRC_DIR/Components/pqPluginTreeWidget.h \
  $$SRC_DIR/Components/pqPluginTreeWidgetEventPlayer.h \
  $$SRC_DIR/Components/pqPluginTreeWidgetEventTranslator.h \
  $$SRC_DIR/Components/pqPopOutWidget.h \
  $$SRC_DIR/Components/pqPresetDialog.h \
  $$SRC_DIR/Components/pqPresetGroupsManager.h \
  $$SRC_DIR/Components/pqPresetToPixmap.h \
  $$SRC_DIR/Components/pqPropertiesPanel.h \
  $$SRC_DIR/Components/pqPropertyGroupWidget.h \
  $$SRC_DIR/Components/pqPropertyWidget.h \
  $$SRC_DIR/Components/pqPropertyWidgetDecorator.h \
  $$SRC_DIR/Components/pqPropertyWidgetInterface.h \
  $$SRC_DIR/Components/pqProxiesWidget.h \
  $$SRC_DIR/Components/pqProxyEditorPropertyWidget.h \
  $$SRC_DIR/Components/pqProxyInformationWidget.h \
  $$SRC_DIR/Components/pqProxyPropertyWidget.h \
  $$SRC_DIR/Components/pqProxySILModel.h \
  $$SRC_DIR/Components/pqProxySelectionWidget.h \
  $$SRC_DIR/Components/pqProxyWidget.h \
  $$SRC_DIR/Components/pqProxyWidgetDialog.h \
  $$SRC_DIR/Components/pqQueryClauseWidget.h \
  $$SRC_DIR/Components/pqRecentFilesMenu.h \
  $$SRC_DIR/Components/pqRemoteCommandDialog.h \
  $$SRC_DIR/Components/pqRemoteCommandTemplateDialog.h \
  $$SRC_DIR/Components/pqRescaleRange.h \
  $$SRC_DIR/Components/pqSILModel.h \
  $$SRC_DIR/Components/pqSILWidget.h \
  $$SRC_DIR/Components/pqSMSignalAdaptors.h \
  $$SRC_DIR/Components/pqSampleScalarAddRangeDialog.h \
  $$SRC_DIR/Components/pqSampleScalarWidget.h \
  $$SRC_DIR/Components/pqScalarSetModel.h \
  $$SRC_DIR/Components/pqScalarValueListPropertyWidget.h \
  $$SRC_DIR/Components/pqSearchBox.h \
  $$SRC_DIR/Components/pqSelectReaderDialog.h \
  $$SRC_DIR/Components/pqSelectionAdaptor.h \
  $$SRC_DIR/Components/pqSelectionInputWidget.h \
  $$SRC_DIR/Components/pqSelectionLinkDialog.h \
  $$SRC_DIR/Components/pqSelectionManager.h \
  $$SRC_DIR/Components/pqServerConfigurationImporter.h \
  $$SRC_DIR/Components/pqServerConnectDialog.h \
  $$SRC_DIR/Components/pqServerLauncher.h \
  $$SRC_DIR/Components/pqSetBreakpointDialog.h \
  $$SRC_DIR/Components/pqSettingsDialog.h \
  $$SRC_DIR/Components/pqShaderReplacementsComboBox.h \
  $$SRC_DIR/Components/pqShaderReplacementsSelectorPropertyWidget.h \
  $$SRC_DIR/Components/pqSignalAdaptorKeyFrameType.h \
  $$SRC_DIR/Components/pqSignalAdaptorSILModel.h \
  $$SRC_DIR/Components/pqSignalAdaptorSelectionTreeWidget.h \
  $$SRC_DIR/Components/pqSignalAdaptorTreeWidget.h \
  $$SRC_DIR/Components/pqSingleLogViewerWidget.h \
  $$SRC_DIR/Components/pqStringVectorPropertyWidget.h \
  $$SRC_DIR/Components/pqSubsetInclusionLatticeTreeModel.h \
  $$SRC_DIR/Components/pqSubsetInclusionLatticeWidget.h \
  $$SRC_DIR/Components/pqTabbedMultiViewWidget.h \
  $$SRC_DIR/Components/pqTextureComboBox.h \
  $$SRC_DIR/Components/pqTextureSelectorPropertyWidget.h \
  $$SRC_DIR/Components/pqTimerLogDisplay.h \
  $$SRC_DIR/Components/pqToolBarInterface.h \
  $$SRC_DIR/Components/pqToolTipTrapper.h \
  $$SRC_DIR/Components/pqTransferFunctionWidget.h \
  $$SRC_DIR/Components/pqTriggerOnIdleHelper.h \
  $$SRC_DIR/Components/pqUndoStackBuilder.h \
  $$SRC_DIR/Components/pqVCRController.h \
  $$SRC_DIR/Components/pqVariableType.h \
  $$SRC_DIR/Components/pqViewFrame.h \
  $$SRC_DIR/Components/pqViewFrameActionsInterface.h \
  $$SRC_DIR/Components/pqViewManager.h \
  $$SRC_DIR/Components/pqWidgetRangeDomain.h

SOURCES += \
  $$SRC_DIR/Components/pqAboutDialog.cxx \
  $$SRC_DIR/Components/pqAbstractItemSelectionModel.cxx \
  $$SRC_DIR/Components/pqActionGroupInterface.cxx \
  $$SRC_DIR/Components/pqActiveObjects.cxx \
  $$SRC_DIR/Components/pqAnimatablePropertiesComboBox.cxx \
  $$SRC_DIR/Components/pqAnimatableProxyComboBox.cxx \
  $$SRC_DIR/Components/pqAnimationManager.cxx \
  $$SRC_DIR/Components/pqAnimationProgressDialog.cxx \
  $$SRC_DIR/Components/pqAnimationTimeWidget.cxx \
  $$SRC_DIR/Components/pqAnimationViewWidget.cxx \
  $$SRC_DIR/Components/pqArrayListDomain.cxx \
  $$SRC_DIR/Components/pqArraySelectionWidget.cxx \
  $$SRC_DIR/Components/pqArraySelectorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqArrayStatusPropertyWidget.cxx \
  $$SRC_DIR/Components/pqCalculatorWidget.cxx \
  $$SRC_DIR/Components/pqCameraDialog.cxx \
  $$SRC_DIR/Components/pqCameraKeyFrameWidget.cxx \
  $$SRC_DIR/Components/pqChangeInputDialog.cxx \
  \# $$SRC_DIR/Components/pqCollaborationPanel.cxx \
  $$SRC_DIR/Components/pqColorChooserButtonWithPalettes.cxx \
  $$SRC_DIR/Components/pqComboBoxDomain.cxx \
  $$SRC_DIR/Components/pqCommandPropertyWidget.cxx \
  $$SRC_DIR/Components/pqComparativeCueWidget.cxx \
  $$SRC_DIR/Components/pqComparativeVisPanel.cxx \
  $$SRC_DIR/Components/pqComponentsInit.cxx \
  $$SRC_DIR/Components/pqComponentsTestUtility.cxx \
  $$SRC_DIR/Components/pqCompositeDataInformationTreeModel.cxx \
  $$SRC_DIR/Components/pqCompositePropertyWidgetDecorator.cxx \
  $$SRC_DIR/Components/pqCompositeTreePropertyWidget.cxx \
  $$SRC_DIR/Components/pqCustomFilterDefinitionModel.cxx \
  $$SRC_DIR/Components/pqCustomFilterDefinitionWizard.cxx \
  $$SRC_DIR/Components/pqCustomFilterManager.cxx \
  $$SRC_DIR/Components/pqCustomFilterManagerModel.cxx \
  $$SRC_DIR/Components/pqCustomViewpointButtonDialog.cxx \
  $$SRC_DIR/Components/pqDataAssemblyTreeModel.cxx \
  $$SRC_DIR/Components/pqDataInformationModel.cxx \
  $$SRC_DIR/Components/pqDataInformationWidget.cxx \
  $$SRC_DIR/Components/pqDialog.cxx \
  $$SRC_DIR/Components/pqDisplayColorWidget.cxx \
  $$SRC_DIR/Components/pqDisplayPanel.cxx \
  $$SRC_DIR/Components/pqDisplayPanelInterface.cxx \
  $$SRC_DIR/Components/pqDisplayPanelPropertyWidget.cxx \
  $$SRC_DIR/Components/pqDisplayRepresentationWidget.cxx \
  $$SRC_DIR/Components/pqDockWindowInterface.cxx \
  $$SRC_DIR/Components/pqDoubleVectorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqFavoritesDialog.cxx \
  $$SRC_DIR/Components/pqFavoritesTreeWidget.cxx \
  $$SRC_DIR/Components/pqFileChooserWidget.cxx \
  $$SRC_DIR/Components/pqFindDataCreateSelectionFrame.cxx \
  $$SRC_DIR/Components/pqFindDataCurrentSelectionFrame.cxx \
  $$SRC_DIR/Components/pqFindDataDialog.cxx \
  $$SRC_DIR/Components/pqFindDataSelectionDisplayFrame.cxx \
  $$SRC_DIR/Components/pqHighlightItemDelegate.cxx \
  $$SRC_DIR/Components/pqImageTip.cxx \
  $$SRC_DIR/Components/pqIndexSelectionWidget.cxx \
  $$SRC_DIR/Components/pqInputSelectorWidget.cxx \
  $$SRC_DIR/Components/pqIntMaskPropertyWidget.cxx \
  $$SRC_DIR/Components/pqIntRangeWidget.cxx \
  $$SRC_DIR/Components/pqIntVectorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqItemViewSearchWidget.cxx \
  $$SRC_DIR/Components/pqItemViewSearchWidgetEventPlayer.cxx \
  $$SRC_DIR/Components/pqKeyFrameEditor.cxx \
  $$SRC_DIR/Components/pqKeyFrameTimeValidator.cxx \
  $$SRC_DIR/Components/pqKeyFrameTypeWidget.cxx \
  $$SRC_DIR/Components/pqLabel.cxx \
  $$SRC_DIR/Components/pqLightsEditor.cxx \
  $$SRC_DIR/Components/pqLightsInspector.cxx \
  $$SRC_DIR/Components/pqLinksEditor.cxx \
  $$SRC_DIR/Components/pqLinksManager.cxx \
  $$SRC_DIR/Components/pqLiveInsituManager.cxx \
  $$SRC_DIR/Components/pqLiveInsituVisualizationManager.cxx \
  $$SRC_DIR/Components/pqLockViewSizeCustomDialog.cxx \
  $$SRC_DIR/Components/pqLogViewerDialog.cxx \
  $$SRC_DIR/Components/pqMemoryInspectorPanel.cxx \
  $$SRC_DIR/Components/pqMultiBlockInspectorWidget.cxx \
  $$SRC_DIR/Components/pqMultiQueryClauseWidget.cxx \
  $$SRC_DIR/Components/pqMultiViewWidget.cxx \
  $$SRC_DIR/Components/pqOrbitCreatorDialog.cxx \
  $$SRC_DIR/Components/pqOutputPortComboBox.cxx \
  $$SRC_DIR/Components/pqPipelineAnnotationFilterModel.cxx \
  $$SRC_DIR/Components/pqPipelineBrowserWidget.cxx \
  $$SRC_DIR/Components/pqPipelineInputComboBox.cxx \
  $$SRC_DIR/Components/pqPipelineModel.cxx \
  $$SRC_DIR/Components/pqPipelineModelSelectionAdaptor.cxx \
  $$SRC_DIR/Components/pqPipelineTimeKeyFrameEditor.cxx \
  $$SRC_DIR/Components/pqPluginDialog.cxx \
  $$SRC_DIR/Components/pqPluginTreeWidgetEventPlayer.cxx \
  $$SRC_DIR/Components/pqPluginTreeWidgetEventTranslator.cxx \
  $$SRC_DIR/Components/pqPopOutWidget.cxx \
  $$SRC_DIR/Components/pqPresetDialog.cxx \
  $$SRC_DIR/Components/pqPresetGroupsManager.cxx \
  $$SRC_DIR/Components/pqPresetToPixmap.cxx \
  $$SRC_DIR/Components/pqPropertiesPanel.cxx \
  $$SRC_DIR/Components/pqPropertyGroupWidget.cxx \
  $$SRC_DIR/Components/pqPropertyWidget.cxx \
  $$SRC_DIR/Components/pqPropertyWidgetDecorator.cxx \
  $$SRC_DIR/Components/pqPropertyWidgetInterface.cxx \
  $$SRC_DIR/Components/pqProxiesWidget.cxx \
  $$SRC_DIR/Components/pqProxyEditorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqProxyInformationWidget.cxx \
  $$SRC_DIR/Components/pqProxyPropertyWidget.cxx \
  $$SRC_DIR/Components/pqProxySILModel.cxx \
  $$SRC_DIR/Components/pqProxySelectionWidget.cxx \
  $$SRC_DIR/Components/pqProxyWidget.cxx \
  $$SRC_DIR/Components/pqProxyWidgetDialog.cxx \
  $$SRC_DIR/Components/pqQueryClauseWidget.cxx \
  $$SRC_DIR/Components/pqRecentFilesMenu.cxx \
  $$SRC_DIR/Components/pqRemoteCommandDialog.cxx \
  $$SRC_DIR/Components/pqRemoteCommandTemplateDialog.cxx \
  $$SRC_DIR/Components/pqRescaleRange.cxx \
  $$SRC_DIR/Components/pqSILModel.cxx \
  $$SRC_DIR/Components/pqSILWidget.cxx \
  $$SRC_DIR/Components/pqSMSignalAdaptors.cxx \
  $$SRC_DIR/Components/pqSampleScalarAddRangeDialog.cxx \
  $$SRC_DIR/Components/pqSampleScalarWidget.cxx \
  $$SRC_DIR/Components/pqScalarSetModel.cxx \
  $$SRC_DIR/Components/pqScalarValueListPropertyWidget.cxx \
  $$SRC_DIR/Components/pqSearchBox.cxx \
  $$SRC_DIR/Components/pqSelectReaderDialog.cxx \
  $$SRC_DIR/Components/pqSelectionAdaptor.cxx \
  $$SRC_DIR/Components/pqSelectionInputWidget.cxx \
  $$SRC_DIR/Components/pqSelectionLinkDialog.cxx \
  $$SRC_DIR/Components/pqSelectionManager.cxx \
  $$SRC_DIR/Components/pqServerConfigurationImporter.cxx \
  $$SRC_DIR/Components/pqServerConnectDialog.cxx \
  $$SRC_DIR/Components/pqServerLauncher.cxx \
  $$SRC_DIR/Components/pqSetBreakpointDialog.cxx \
  $$SRC_DIR/Components/pqSettingsDialog.cxx \
  $$SRC_DIR/Components/pqShaderReplacementsComboBox.cxx \
  $$SRC_DIR/Components/pqShaderReplacementsSelectorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqSignalAdaptorKeyFrameType.cxx \
  \# $$SRC_DIR/Components/pqSignalAdaptorSILModel.cxx \
  $$SRC_DIR/Components/pqSignalAdaptorSelectionTreeWidget.cxx \
  $$SRC_DIR/Components/pqSignalAdaptorTreeWidget.cxx \
  $$SRC_DIR/Components/pqSingleLogViewerWidget.cxx \
  $$SRC_DIR/Components/pqStringVectorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqSubsetInclusionLatticeTreeModel.cxx \
  $$SRC_DIR/Components/pqSubsetInclusionLatticeWidget.cxx \
  $$SRC_DIR/Components/pqTabbedMultiViewWidget.cxx \
  $$SRC_DIR/Components/pqTextureComboBox.cxx \
  $$SRC_DIR/Components/pqTextureSelectorPropertyWidget.cxx \
  $$SRC_DIR/Components/pqTimerLogDisplay.cxx \
  $$SRC_DIR/Components/pqToolBarInterface.cxx \
  $$SRC_DIR/Components/pqToolTipTrapper.cxx \
  $$SRC_DIR/Components/pqTransferFunctionWidget.cxx \
  $$SRC_DIR/Components/pqTriggerOnIdleHelper.cxx \
  $$SRC_DIR/Components/pqUndoStackBuilder.cxx \
  $$SRC_DIR/Components/pqVCRController.cxx \
  $$SRC_DIR/Components/pqViewFrame.cxx \
  $$SRC_DIR/Components/pqViewFrameActionsInterface.cxx \
  $$SRC_DIR/Components/pqViewManager.cxx \
  $$SRC_DIR/Components/pqWidgetRangeDomain.cxx




HEADERS += \
  $$SRC_DIR/Core/pqAnimationCue.h \
  $$SRC_DIR/Core/pqAnimationScene.h \
  $$SRC_DIR/Core/pqApplicationCore.h \
  $$SRC_DIR/Core/pqAutoStartInterface.h \
  $$SRC_DIR/Core/pqBoxChartView.h \
  $$SRC_DIR/Core/pqCheckBoxDelegate.h \
  $$SRC_DIR/Core/pqCollaborationEventPlayer.h \
  $$SRC_DIR/Core/pqCollaborationManager.h \
  $$SRC_DIR/Core/pqComparativeContextView.h \
  $$SRC_DIR/Core/pqComparativeRenderView.h \
  $$SRC_DIR/Core/pqComparativeXYBarChartView.h \
  $$SRC_DIR/Core/pqComparativeXYChartView.h \
  $$SRC_DIR/Core/pqContextView.h \
  $$SRC_DIR/Core/pqCoreInit.h \
  $$SRC_DIR/Core/pqCoreTestUtility.h \
  $$SRC_DIR/Core/pqCoreUtilities.h \
  $$SRC_DIR/Core/pqDataRepresentation.h \
  $$SRC_DIR/Core/pqDebug.h \
  $$SRC_DIR/Core/pqExtractor.h \
  $$SRC_DIR/Core/pqFileDialog.h \
  $$SRC_DIR/Core/pqFileDialogEventPlayer.h \
  $$SRC_DIR/Core/pqFileDialogEventTranslator.h \
  $$SRC_DIR/Core/pqFileDialogFavoriteModel.h \
  $$SRC_DIR/Core/pqFileDialogFilter.h \
  $$SRC_DIR/Core/pqFileDialogModel.h \
  $$SRC_DIR/Core/pqFileDialogRecentDirsModel.h \
  $$SRC_DIR/Core/pqFlatTreeViewEventPlayer.h \
  $$SRC_DIR/Core/pqFlatTreeViewEventTranslator.h \
  $$SRC_DIR/Core/pqGraphLayoutStrategyInterface.h \
  $$SRC_DIR/Core/pqImageUtil.h \
  $$SRC_DIR/Core/pqInteractiveViewLink.h \
  $$SRC_DIR/Core/pqInterfaceTracker.h \
  $$SRC_DIR/Core/pqLinkViewWidget.h \
  $$SRC_DIR/Core/pqLinksModel.h \
  $$SRC_DIR/Core/pqLogViewerWidget.h \
  $$SRC_DIR/Core/pqMainWindowEventManager.h \
  $$SRC_DIR/Core/pqMultiSliceAxisWidget.h \
  $$SRC_DIR/Core/pqMultiSliceView.h \
  $$SRC_DIR/Core/pqNonEditableStyledItemDelegate.h \
  $$SRC_DIR/Core/pqObjectBuilder.h \
  $$SRC_DIR/Core/pqOptions.h \
  $$SRC_DIR/Core/pqOutputPort.h \
  $$SRC_DIR/Core/pqOutputWidget.h \
  $$SRC_DIR/Core/pqParallelCoordinatesChartView.h \
  $$SRC_DIR/Core/pqPipelineFilter.h \
  $$SRC_DIR/Core/pqPipelineRepresentation.h \
  $$SRC_DIR/Core/pqPipelineSource.h \
  $$SRC_DIR/Core/pqPlotMatrixView.h \
  $$SRC_DIR/Core/pqPlugin.h \
  $$SRC_DIR/Core/pqPluginManager.h \
  $$SRC_DIR/Core/pqProgressManager.h \
  $$SRC_DIR/Core/pqPropertyLinks.h \
  $$SRC_DIR/Core/pqPropertyLinksConnection.h \
  $$SRC_DIR/Core/pqPropertyManager.h \
  $$SRC_DIR/Core/pqProxy.h \
  $$SRC_DIR/Core/pqProxyModifiedStateUndoElement.h \
  $$SRC_DIR/Core/pqProxySelection.h \
  $$SRC_DIR/Core/pqPythonEventSourceImage.h \
  $$SRC_DIR/Core/pqPythonView.h \
  $$SRC_DIR/Core/pqQVTKWidget.h \
  $$SRC_DIR/Core/pqQVTKWidgetBase.h \
  $$SRC_DIR/Core/pqQVTKWidgetEventPlayer.h \
  $$SRC_DIR/Core/pqQVTKWidgetEventTranslator.h \
  $$SRC_DIR/Core/pqRecentlyUsedResourceLoaderInterface.h \
  $$SRC_DIR/Core/pqRecentlyUsedResourcesList.h \
  $$SRC_DIR/Core/pqRenderView.h \
  $$SRC_DIR/Core/pqRenderViewBase.h \
  $$SRC_DIR/Core/pqRepresentation.h \
  $$SRC_DIR/Core/pqSMAdaptor.h \
  $$SRC_DIR/Core/pqSMProxy.h \
  $$SRC_DIR/Core/pqScalarBarRepresentation.h \
  $$SRC_DIR/Core/pqScalarsToColors.h \
  $$SRC_DIR/Core/pqServer.h \
  $$SRC_DIR/Core/pqServerConfiguration.h \
  $$SRC_DIR/Core/pqServerConfigurationCollection.h \
  $$SRC_DIR/Core/pqServerManagerModel.h \
  $$SRC_DIR/Core/pqServerManagerModelInterface.h \
  $$SRC_DIR/Core/pqServerManagerModelItem.h \
  $$SRC_DIR/Core/pqServerManagerObserver.h \
  $$SRC_DIR/Core/pqServerResource.h \
  $$SRC_DIR/Core/pqSettings.h \
  $$SRC_DIR/Core/pqSpreadSheetView.h \
  $$SRC_DIR/Core/pqSpreadSheetViewModel.h \
  $$SRC_DIR/Core/pqSpreadSheetViewSelectionModel.h \
  $$SRC_DIR/Core/pqSpreadSheetViewWidget.h \
  $$SRC_DIR/Core/pqStandardServerManagerModelInterface.h \
  $$SRC_DIR/Core/pqTimeKeeper.h \
  $$SRC_DIR/Core/pqTreeLayoutStrategyInterface.h \
  $$SRC_DIR/Core/pqUndoStack.h \
  $$SRC_DIR/Core/pqView.h \
  $$SRC_DIR/Core/pqXMLEventObserver.h \
  $$SRC_DIR/Core/pqXMLEventSource.h \
  $$SRC_DIR/Core/pqXMLUtil.h \
  $$SRC_DIR/Core/pqXYBarChartView.h \
  $$SRC_DIR/Core/pqXYChartView.h \
  $$SRC_DIR/Core/pqXYHistogramChartView.h \
  $$SRC_DIR/Core/vtkPVGUIPluginInterface.h

SOURCES += \
  $$SRC_DIR/Core/pqAnimationCue.cxx \
  $$SRC_DIR/Core/pqAnimationScene.cxx \
  $$SRC_DIR/Core/pqApplicationCore.cxx \
  $$SRC_DIR/Core/pqAutoStartInterface.cxx \
  $$SRC_DIR/Core/pqBoxChartView.cxx \
  $$SRC_DIR/Core/pqCheckBoxDelegate.cxx \
  $$SRC_DIR/Core/pqCollaborationEventPlayer.cxx \
  \# $$SRC_DIR/Core/pqCollaborationManager.cxx \
  $$SRC_DIR/Core/pqComparativeContextView.cxx \
  $$SRC_DIR/Core/pqComparativeRenderView.cxx \
  $$SRC_DIR/Core/pqComparativeXYBarChartView.cxx \
  $$SRC_DIR/Core/pqComparativeXYChartView.cxx \
  $$SRC_DIR/Core/pqContextView.cxx \
  $$SRC_DIR/Core/pqCoreInit.cxx \
  \# $$SRC_DIR/Core/pqCoreTestUtility.cxx \
  $$SRC_DIR/Core/pqCoreUtilities.cxx \
  $$SRC_DIR/Core/pqDataRepresentation.cxx \
  $$SRC_DIR/Core/pqDebug.cxx \
  $$SRC_DIR/Core/pqExtractor.cxx \
  $$SRC_DIR/Core/pqFileDialog.cxx \
  $$SRC_DIR/Core/pqFileDialogEventPlayer.cxx \
  $$SRC_DIR/Core/pqFileDialogEventTranslator.cxx \
  $$SRC_DIR/Core/pqFileDialogFavoriteModel.cxx \
  $$SRC_DIR/Core/pqFileDialogFilter.cxx \
  $$SRC_DIR/Core/pqFileDialogModel.cxx \
  $$SRC_DIR/Core/pqFileDialogRecentDirsModel.cxx \
  $$SRC_DIR/Core/pqFlatTreeViewEventPlayer.cxx \
  $$SRC_DIR/Core/pqFlatTreeViewEventTranslator.cxx \
  $$SRC_DIR/Core/pqGraphLayoutStrategyInterface.cxx \
  $$SRC_DIR/Core/pqImageUtil.cxx \
  $$SRC_DIR/Core/pqInteractiveViewLink.cxx \
  $$SRC_DIR/Core/pqInterfaceTracker.cxx \
  $$SRC_DIR/Core/pqLinkViewWidget.cxx \
  $$SRC_DIR/Core/pqLinksModel.cxx \
  $$SRC_DIR/Core/pqLogViewerWidget.cxx \
  $$SRC_DIR/Core/pqMainWindowEventManager.cxx \
  $$SRC_DIR/Core/pqMultiSliceAxisWidget.cxx \
  $$SRC_DIR/Core/pqMultiSliceView.cxx \
  $$SRC_DIR/Core/pqNonEditableStyledItemDelegate.cxx \
  $$SRC_DIR/Core/pqObjectBuilder.cxx \
  $$SRC_DIR/Core/pqOptions.cxx \
  $$SRC_DIR/Core/pqOutputPort.cxx \
  $$SRC_DIR/Core/pqOutputWidget.cxx \
  $$SRC_DIR/Core/pqParallelCoordinatesChartView.cxx \
  $$SRC_DIR/Core/pqPipelineFilter.cxx \
  $$SRC_DIR/Core/pqPipelineRepresentation.cxx \
  $$SRC_DIR/Core/pqPipelineSource.cxx \
  $$SRC_DIR/Core/pqPlotMatrixView.cxx \
  $$SRC_DIR/Core/pqPluginManager.cxx \
  $$SRC_DIR/Core/pqProgressManager.cxx \
  $$SRC_DIR/Core/pqPropertyLinks.cxx \
  $$SRC_DIR/Core/pqPropertyLinksConnection.cxx \
  $$SRC_DIR/Core/pqPropertyManager.cxx \
  $$SRC_DIR/Core/pqProxy.cxx \
  $$SRC_DIR/Core/pqProxyModifiedStateUndoElement.cxx \
  $$SRC_DIR/Core/pqProxySelection.cxx \
  \# $$SRC_DIR/Core/pqPythonEventSourceImage.cxx \
  $$SRC_DIR/Core/pqPythonView.cxx \
  $$SRC_DIR/Core/pqQVTKWidget.cxx \
  $$SRC_DIR/Core/pqQVTKWidgetEventPlayer.cxx \
  $$SRC_DIR/Core/pqQVTKWidgetEventTranslator.cxx \
  $$SRC_DIR/Core/pqRecentlyUsedResourceLoaderInterface.cxx \
  $$SRC_DIR/Core/pqRecentlyUsedResourcesList.cxx \
  $$SRC_DIR/Core/pqRenderView.cxx \
  $$SRC_DIR/Core/pqRenderViewBase.cxx \
  $$SRC_DIR/Core/pqRepresentation.cxx \
  $$SRC_DIR/Core/pqSMAdaptor.cxx \
  $$SRC_DIR/Core/pqSMProxy.cxx \
  $$SRC_DIR/Core/pqScalarBarRepresentation.cxx \
  $$SRC_DIR/Core/pqScalarsToColors.cxx \
  $$SRC_DIR/Core/pqServer.cxx \
  $$SRC_DIR/Core/pqServerConfiguration.cxx \
  $$SRC_DIR/Core/pqServerConfigurationCollection.cxx \
  $$SRC_DIR/Core/pqServerManagerModel.cxx \
  $$SRC_DIR/Core/pqServerManagerModelInterface.cxx \
  $$SRC_DIR/Core/pqServerManagerModelItem.cxx \
  $$SRC_DIR/Core/pqServerManagerObserver.cxx \
  $$SRC_DIR/Core/pqServerResource.cxx \
  $$SRC_DIR/Core/pqSettings.cxx \
  $$SRC_DIR/Core/pqSpreadSheetView.cxx \
  $$SRC_DIR/Core/pqSpreadSheetViewModel.cxx \
  $$SRC_DIR/Core/pqSpreadSheetViewSelectionModel.cxx \
  $$SRC_DIR/Core/pqSpreadSheetViewWidget.cxx \
  $$SRC_DIR/Core/pqStandardServerManagerModelInterface.cxx \
  $$SRC_DIR/Core/pqTimeKeeper.cxx \
  $$SRC_DIR/Core/pqTreeLayoutStrategyInterface.cxx \
  $$SRC_DIR/Core/pqUndoStack.cxx \
  $$SRC_DIR/Core/pqView.cxx \
  \# $$SRC_DIR/Core/pqXMLEventObserver.cxx \
  \# $$SRC_DIR/Core/pqXMLEventSource.cxx \
  $$SRC_DIR/Core/pqXMLUtil.cxx \
  $$SRC_DIR/Core/pqXYBarChartView.cxx \
  $$SRC_DIR/Core/pqXYChartView.cxx \
  $$SRC_DIR/Core/pqXYHistogramChartView.cxx \
  $$SRC_DIR/Core/vtkPVGUIPluginInterface.cxx \



HEADERS += \
  $$SRC_DIR/Widgets/pqAnimationKeyFrame.h \
  $$SRC_DIR/Widgets/pqAnimationModel.h \
  $$SRC_DIR/Widgets/pqAnimationTrack.h \
  $$SRC_DIR/Widgets/pqAnimationWidget.h \
  $$SRC_DIR/Widgets/pqCheckBoxPixMaps.h \
  $$SRC_DIR/Widgets/pqCheckableHeaderView.h \
  $$SRC_DIR/Widgets/pqCollapsedGroup.h \
  $$SRC_DIR/Widgets/pqColorButtonEventPlayer.h \
  $$SRC_DIR/Widgets/pqColorButtonEventTranslator.h \
  $$SRC_DIR/Widgets/pqColorChooserButton.h \
  $$SRC_DIR/Widgets/pqColorDialogEventPlayer.h \
  $$SRC_DIR/Widgets/pqColorDialogEventTranslator.h \
  $$SRC_DIR/Widgets/pqConnect.h \
  $$SRC_DIR/Widgets/pqConsoleWidget.h \
  $$SRC_DIR/Widgets/pqConsoleWidgetEventPlayer.h \
  $$SRC_DIR/Widgets/pqConsoleWidgetEventTranslator.h \
  $$SRC_DIR/Widgets/pqDelimitedTextParser.h \
  $$SRC_DIR/Widgets/pqDiscreteDoubleWidget.h \
  $$SRC_DIR/Widgets/pqDoubleLineEdit.h \
  $$SRC_DIR/Widgets/pqDoubleRangeDialog.h \
  $$SRC_DIR/Widgets/pqDoubleRangeWidget.h \
  $$SRC_DIR/Widgets/pqDoubleSliderWidget.h \
  $$SRC_DIR/Widgets/pqDoubleSpinBox.h \
  $$SRC_DIR/Widgets/pqExpandableTableView.h \
  $$SRC_DIR/Widgets/pqExpanderButton.h \
  $$SRC_DIR/Widgets/pqFlatTreeView.h \
  $$SRC_DIR/Widgets/pqHeaderView.h \
  $$SRC_DIR/Widgets/pqHelpWindow.h \
  $$SRC_DIR/Widgets/pqHelpWindowNoWebEngine.h \
  $$SRC_DIR/Widgets/pqHelpWindowWebEngine.h \
  $$SRC_DIR/Widgets/pqHierarchicalGridLayout.h \
  $$SRC_DIR/Widgets/pqHierarchicalGridWidget.h \
  $$SRC_DIR/Widgets/pqHighlightablePushButton.h \
  $$SRC_DIR/Widgets/pqHighlightableToolButton.h \
  $$SRC_DIR/Widgets/pqLineEdit.h \
  $$SRC_DIR/Widgets/pqLineEditEventPlayer.h \
  $$SRC_DIR/Widgets/pqListWidgetCheckHelper.h \
  $$SRC_DIR/Widgets/pqListWidgetItemObject.h \
  $$SRC_DIR/Widgets/pqMultiColumnHeaderView.h \
  $$SRC_DIR/Widgets/pqProgressWidget.h \
  $$SRC_DIR/Widgets/pqQuickLaunchDialog.h \
  $$SRC_DIR/Widgets/pqScaleByButton.h \
  $$SRC_DIR/Widgets/pqSectionVisibilityContextMenu.h \
  $$SRC_DIR/Widgets/pqSeriesGeneratorDialog.h \
  $$SRC_DIR/Widgets/pqSetData.h \
  $$SRC_DIR/Widgets/pqSetName.h \
  $$SRC_DIR/Widgets/pqSignalAdaptors.h \
  $$SRC_DIR/Widgets/pqSpinBox.h \
  $$SRC_DIR/Widgets/pqTableView.h \
  $$SRC_DIR/Widgets/pqTextEdit.h \
  $$SRC_DIR/Widgets/pqTimelineScrollbar.h \
  $$SRC_DIR/Widgets/pqTreeView.h \
  $$SRC_DIR/Widgets/pqTreeViewExpandState.h \
  $$SRC_DIR/Widgets/pqTreeViewSelectionHelper.h \
  $$SRC_DIR/Widgets/pqTreeWidget.h \
  $$SRC_DIR/Widgets/pqTreeWidgetCheckHelper.h \
  $$SRC_DIR/Widgets/pqTreeWidgetItem.h \
  $$SRC_DIR/Widgets/pqTreeWidgetItemObject.h \
  $$SRC_DIR/Widgets/pqTreeWidgetSelectionHelper.h \
  $$SRC_DIR/Widgets/pqWaitCursor.h

SOURCES += \
  $$SRC_DIR/Widgets/pqAnimationKeyFrame.cxx \
  $$SRC_DIR/Widgets/pqAnimationModel.cxx \
  $$SRC_DIR/Widgets/pqAnimationTrack.cxx \
  $$SRC_DIR/Widgets/pqAnimationWidget.cxx \
  $$SRC_DIR/Widgets/pqCheckBoxPixMaps.cxx \
  $$SRC_DIR/Widgets/pqCheckableHeaderView.cxx \
  $$SRC_DIR/Widgets/pqCollapsedGroup.cxx \
  $$SRC_DIR/Widgets/pqColorButtonEventPlayer.cxx \
  $$SRC_DIR/Widgets/pqColorButtonEventTranslator.cxx \
  $$SRC_DIR/Widgets/pqColorChooserButton.cxx \
  $$SRC_DIR/Widgets/pqColorDialogEventPlayer.cxx \
  $$SRC_DIR/Widgets/pqColorDialogEventTranslator.cxx \
  $$SRC_DIR/Widgets/pqConnect.cxx \
  $$SRC_DIR/Widgets/pqConsoleWidget.cxx \
  $$SRC_DIR/Widgets/pqConsoleWidgetEventPlayer.cxx \
  $$SRC_DIR/Widgets/pqConsoleWidgetEventTranslator.cxx \
  $$SRC_DIR/Widgets/pqDelimitedTextParser.cxx \
  $$SRC_DIR/Widgets/pqDiscreteDoubleWidget.cxx \
  $$SRC_DIR/Widgets/pqDoubleLineEdit.cxx \
  $$SRC_DIR/Widgets/pqDoubleRangeDialog.cxx \
  $$SRC_DIR/Widgets/pqDoubleRangeWidget.cxx \
  $$SRC_DIR/Widgets/pqDoubleSliderWidget.cxx \
  $$SRC_DIR/Widgets/pqDoubleSpinBox.cxx \
  $$SRC_DIR/Widgets/pqExpandableTableView.cxx \
  $$SRC_DIR/Widgets/pqExpanderButton.cxx \
  $$SRC_DIR/Widgets/pqFlatTreeView.cxx \
  $$SRC_DIR/Widgets/pqHeaderView.cxx \
  $$SRC_DIR/Widgets/pqHelpWindow.cxx \
  $$SRC_DIR/Widgets/pqHierarchicalGridLayout.cxx \
  $$SRC_DIR/Widgets/pqHierarchicalGridWidget.cxx \
  $$SRC_DIR/Widgets/pqHighlightablePushButton.cxx \
  $$SRC_DIR/Widgets/pqHighlightableToolButton.cxx \
  $$SRC_DIR/Widgets/pqLineEdit.cxx \
  $$SRC_DIR/Widgets/pqLineEditEventPlayer.cxx \
  $$SRC_DIR/Widgets/pqListWidgetCheckHelper.cxx \
  $$SRC_DIR/Widgets/pqListWidgetItemObject.cxx \
  $$SRC_DIR/Widgets/pqMultiColumnHeaderView.cxx \
  $$SRC_DIR/Widgets/pqProgressWidget.cxx \
  $$SRC_DIR/Widgets/pqQuickLaunchDialog.cxx \
  $$SRC_DIR/Widgets/pqScaleByButton.cxx \
  $$SRC_DIR/Widgets/pqSectionVisibilityContextMenu.cxx \
  $$SRC_DIR/Widgets/pqSeriesGeneratorDialog.cxx \
  $$SRC_DIR/Widgets/pqSetData.cxx \
  $$SRC_DIR/Widgets/pqSetName.cxx \
  $$SRC_DIR/Widgets/pqSignalAdaptors.cxx \
  $$SRC_DIR/Widgets/pqSpinBox.cxx \
  $$SRC_DIR/Widgets/pqTableView.cxx \
  $$SRC_DIR/Widgets/pqTextEdit.cxx \
  $$SRC_DIR/Widgets/pqTimelineScrollbar.cxx \
  $$SRC_DIR/Widgets/pqTreeView.cxx \
  $$SRC_DIR/Widgets/pqTreeViewExpandState.cxx \
  $$SRC_DIR/Widgets/pqTreeViewSelectionHelper.cxx \
  $$SRC_DIR/Widgets/pqTreeWidget.cxx \
  $$SRC_DIR/Widgets/pqTreeWidgetCheckHelper.cxx \
  $$SRC_DIR/Widgets/pqTreeWidgetItem.cxx \
  $$SRC_DIR/Widgets/pqTreeWidgetItemObject.cxx \
  $$SRC_DIR/Widgets/pqTreeWidgetSelectionHelper.cxx \
  $$SRC_DIR/Widgets/pqWaitCursor.cxx



#SOURCES += \
#  $$SRC_DIR/stubs.cpp

LIBS += -lpython2.7
