
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




INCLUDEPATH += $$SRC_DIR/Components  $$SRC_DIR/Core \
  $$SRC_DIR/Widgets \




#include($$ROOT_DIR/../preferred/itk.pri)
include($$ROOT_DIR/../preferred/vtk.pri)

#include($$ROOT_DIR/../preferred/opencv.pri)


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


