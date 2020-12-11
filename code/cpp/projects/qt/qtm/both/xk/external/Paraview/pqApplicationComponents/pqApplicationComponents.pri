
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
  $$SRC_DIR/Resources/UI/pqColorOpacityEditorWidget.ui \
  $$SRC_DIR/Resources/UI/pqResetScalarRangeToDataOverTime.ui \
  $$SRC_DIR/Resources/UI/pqEditMenuBuilder.ui \
  $$SRC_DIR/Resources/UI/pqOMETransferFunctionsPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqOMETransferFunctionsPropertyWidgetPage.ui \
  $$SRC_DIR/Resources/UI/pqColorAnnotationsWidget.ui \
  $$SRC_DIR/Resources/UI/pqTransferFunctionWidgetPropertyDialog.ui \
  $$SRC_DIR/Resources/UI/pqSpherePropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqColorToolbar.ui \
  $$SRC_DIR/Resources/UI/pqMoleculePropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqCameraToolbar.ui \
  $$SRC_DIR/Resources/UI/pqHandlePropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqLightPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqDataAssemblyPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqExampleVisualizationsDialog.ui \
  $$SRC_DIR/Resources/UI/pqCustomResolutionDialog.ui \
  $$SRC_DIR/Resources/UI/pqWelcomeDialog.ui \
  $$SRC_DIR/Resources/UI/pqTransferFunctionWidgetPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqFileMenuBuilder.ui \
  $$SRC_DIR/Resources/UI/pqSeriesEditorPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqSplinePropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqVCRToolbar.ui \
  $$SRC_DIR/Resources/UI/pqColorEditorPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqCameraManipulatorWidget.ui \
  $$SRC_DIR/Resources/UI/pqYoungsMaterialPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqTimeInspectorWidget.ui \
  $$SRC_DIR/Resources/UI/pqMainControlsToolbar.ui \
  $$SRC_DIR/Resources/UI/pqSavePresetOptions.ui \
  $$SRC_DIR/Resources/UI/pqLinePropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqCustomizeShortcutsDialog.ui \
  $$SRC_DIR/Resources/UI/pqPropertyCollectionWidget.ui \
  $$SRC_DIR/Resources/UI/pqAxesToolbar.ui \
  $$SRC_DIR/Resources/UI/pqSpreadSheetViewDecorator.ui \
  $$SRC_DIR/Resources/UI/pqBackgroundEditorWidget.ui \
  $$SRC_DIR/Resources/UI/pqFontPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqImplicitPlanePropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqCylinderPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqImageCompressorWidget.ui \
  $$SRC_DIR/Resources/UI/pqDoubleRangeSliderPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqBoxPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqTextLocationWidget.ui \
  $$SRC_DIR/Resources/UI/pqDefaultMainWindow.ui \
  $$SRC_DIR/Resources/UI/pqColorMapEditor.ui \
  $$SRC_DIR/Resources/UI/pqViewResolutionPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqEmptyView.ui \

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Core
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/FiltersRendering

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Remoting/ViewsPython



INCLUDEPATH += $$SRC_GROUP_DIR/pqComponents  $$SRC_GROUP_DIR/pqCore \
  $$SRC_GROUP_DIR/pqWidgets \




#include($$ROOT_DIR/../preferred/itk.pri)
#include($$ROOT_DIR/../preferred/vtk.pri)

include($$ROOT_DIR/../preferred/paraview.pri)


#include($$ROOT_DIR/../preferred/opencv.pri)

#INCLUDEPATH += $$ALT_DIR/vtkqttesting


INCLUDEPATH += $$VTK_BUILD_DIR/Interaction/Style
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/OpenGL2
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/UI
INCLUDEPATH += $$VTK_BUILD_DIR/Charts/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Context2D
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/jsoncpp


DEFINES += VTK_LEGACY\\(x\\)=x


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


#INCLUDEPATH += $$SRC_DIR/ApplicationComponents
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Qt/Python


DEFINES += FONT_METRICS_WIDTH_OR_HORIZONTAL_ADVANCE=width
#DEFINES += FONT_METRICS_WIDTH_OR_HORIZONTAL_ADVANCE=horizontalAdvance


HEADERS += \
  $$SRC_GROUP_DIR/QVTKOpenGLStereoWidget.h \
  $$SRC_GROUP_DIR/zoattestingctk/pqPythonEventSource.h


SOURCES += \
  $$SRC_GROUP_DIR/zoattestingctk/pqPythonEventSource.cxx


INCLUDEPATH += /usr/include/python2.7/


HEADERS += \
  $$SRC_DIR/pqAboutDialogReaction.h \
  $$SRC_DIR/pqAddToFavoritesReaction.h \
  $$SRC_DIR/pqAlwaysConnectedBehavior.h \
  $$SRC_DIR/pqAnimationShortcutDecorator.h \
  $$SRC_DIR/pqAnimationShortcutWidget.h \
  $$SRC_DIR/pqAnimationTimeToolbar.h \
  $$SRC_DIR/pqAnnotationsModel.h \
  $$SRC_DIR/pqApplicationComponentsInit.h \
  $$SRC_DIR/pqApplicationSettingsReaction.h \
  $$SRC_DIR/pqApplyBehavior.h \
  $$SRC_DIR/pqApplyPropertiesReaction.h \
  $$SRC_DIR/pqAutoApplyReaction.h \
  $$SRC_DIR/pqAutoLoadPluginXMLBehavior.h \
  $$SRC_DIR/pqAxesToolbar.h \
  $$SRC_DIR/pqBackgroundEditorWidget.h \
  $$SRC_DIR/pqBoolPropertyWidgetDecorator.h \
  $$SRC_DIR/pqBoxPropertyWidget.h \
  $$SRC_DIR/pqCameraLinkReaction.h \
  $$SRC_DIR/pqCameraManipulatorWidget.h \
  $$SRC_DIR/pqCameraReaction.h \
  $$SRC_DIR/pqCameraToolbar.h \
  $$SRC_DIR/pqCameraUndoRedoReaction.h \
  $$SRC_DIR/pqCatalystConnectReaction.h \
  $$SRC_DIR/pqCatalystContinueReaction.h \
  $$SRC_DIR/pqCatalystExportReaction.h \
  $$SRC_DIR/pqCatalystPauseSimulationReaction.h \
  $$SRC_DIR/pqCatalystRemoveBreakpointReaction.h \
  $$SRC_DIR/pqCatalystSetBreakpointReaction.h \
  $$SRC_DIR/pqCategoryToolbarsBehavior.h \
  $$SRC_DIR/pqChangePipelineInputReaction.h \
  $$SRC_DIR/pqChartSelectionReaction.h \
  $$SRC_DIR/pqCheckableProperty.h \
  $$SRC_DIR/pqChooseColorPresetReaction.h \
  $$SRC_DIR/pqCollaborationBehavior.h \
  $$SRC_DIR/pqColorAnnotationsPropertyWidget.h \
  $$SRC_DIR/pqColorAnnotationsWidget.h \
  $$SRC_DIR/pqColorEditorPropertyWidget.h \
  $$SRC_DIR/pqColorMapEditor.h \
  $$SRC_DIR/pqColorOpacityEditorWidget.h \
  $$SRC_DIR/pqColorPaletteSelectorWidget.h \
  $$SRC_DIR/pqColorSelectorPropertyWidget.h \
  $$SRC_DIR/pqColorTableModel.h \
  $$SRC_DIR/pqColorToolbar.h \
  $$SRC_DIR/pqCommandButtonPropertyWidget.h \
  $$SRC_DIR/pqCommandLineOptionsBehavior.h \
  $$SRC_DIR/pqCopyReaction.h \
  $$SRC_DIR/pqCrashRecoveryBehavior.h \
  $$SRC_DIR/pqCreateCustomFilterReaction.h \
  $$SRC_DIR/pqCTHArraySelectionDecorator.h \
  $$SRC_DIR/pqCustomizeShortcutsDialog.h \
  $$SRC_DIR/pqCustomizeShortcutsReaction.h \
  $$SRC_DIR/pqCustomShortcutBehavior.h \
  $$SRC_DIR/pqCustomViewpointsToolbar.h \
  $$SRC_DIR/pqCylinderPropertyWidget.h \
  $$SRC_DIR/pqDataAssemblyPropertyWidget.h \
  $$SRC_DIR/pqDataQueryReaction.h \
  $$SRC_DIR/pqDataTimeStepBehavior.h \
  $$SRC_DIR/pqDefaultMainWindow.h \
  $$SRC_DIR/pqDefaultViewBehavior.h \
  $$SRC_DIR/pqDeleteReaction.h \
  $$SRC_DIR/pqDesktopServicesReaction.h \
  $$SRC_DIR/pqDoubleRangeSliderPropertyWidget.h \
  $$SRC_DIR/pqEditCameraReaction.h \
  $$SRC_DIR/pqEditColorMapReaction.h \
  $$SRC_DIR/pqEditScalarBarReaction.h \
  $$SRC_DIR/pqEnableWidgetDecorator.h \
  $$SRC_DIR/pqExampleVisualizationsDialog.h \
  $$SRC_DIR/pqExampleVisualizationsDialogReaction.h \
  $$SRC_DIR/pqExportReaction.h \
  $$SRC_DIR/pqExtractorsMenuReaction.h \
  $$SRC_DIR/pqFileNamePropertyWidget.h \
  $$SRC_DIR/pqFiltersMenuReaction.h \
  $$SRC_DIR/pqFontPropertyWidget.h \
  $$SRC_DIR/pqGenericPropertyWidgetDecorator.h \
  $$SRC_DIR/pqGlyphScaleFactorPropertyWidget.h \
  $$SRC_DIR/pqHandlePropertyWidget.h \
  $$SRC_DIR/pqHelpReaction.h \
  $$SRC_DIR/pqIgnoreSourceTimeReaction.h \
  $$SRC_DIR/pqImageCompressorWidget.h \
  $$SRC_DIR/pqImplicitPlanePropertyWidget.h \
  $$SRC_DIR/pqInputDataTypeDecorator.h \
  $$SRC_DIR/pqInteractivePropertyWidget.h \
  $$SRC_DIR/pqLightPropertyWidget.h \
  $$SRC_DIR/pqLinePropertyWidget.h \
  $$SRC_DIR/pqLinkSelectionReaction.h \
  $$SRC_DIR/pqListPropertyWidget.h \
  $$SRC_DIR/pqLiveSourceBehavior.h \
  $$SRC_DIR/pqLoadDataReaction.h \
  $$SRC_DIR/pqLoadMaterialsReaction.h \
  $$SRC_DIR/pqLoadPaletteReaction.h \
  $$SRC_DIR/pqLoadRestoreWindowLayoutReaction.h \
  $$SRC_DIR/pqLoadStateReaction.h \
  $$SRC_DIR/pqLockPanelsBehavior.h \
  $$SRC_DIR/pqLockPanelsReaction.h \
  $$SRC_DIR/pqLogViewerReaction.h \
  $$SRC_DIR/pqMacroReaction.h \
  $$SRC_DIR/pqMainControlsToolbar.h \
  $$SRC_DIR/pqMainWindowEventBehavior.h \
  $$SRC_DIR/pqManageCustomFiltersReaction.h \
  $$SRC_DIR/pqManageFavoritesReaction.h \
  $$SRC_DIR/pqManageLinksReaction.h \
  $$SRC_DIR/pqManagePluginsReaction.h \
  $$SRC_DIR/pqMasterOnlyReaction.h \
  $$SRC_DIR/pqMenuReactionUtils.h \
  $$SRC_DIR/pqModelTransformSupportBehavior.h \
  $$SRC_DIR/pqMoleculePropertyWidget.h \
  $$SRC_DIR/pqMultiComponentsDecorator.h \
  $$SRC_DIR/pqObjectPickingBehavior.h \
  $$SRC_DIR/pqOMETransferFunctionsPropertyWidget.h \
  $$SRC_DIR/pqOpacityTableModel.h \
  $$SRC_DIR/pqOpenVRHidingDecorator.h \
  $$SRC_DIR/pqOSPRayHidingDecorator.h \
  $$SRC_DIR/pqParaViewBehaviors.h \
  $$SRC_DIR/pqParaViewMenuBuilders.h \
  $$SRC_DIR/pqPauseLiveSourcePropertyWidget.h \
  $$SRC_DIR/pqPersistentMainWindowStateBehavior.h \
  $$SRC_DIR/pqPipelineContextMenuBehavior.h \
  $$SRC_DIR/pqPluginActionGroupBehavior.h \
  $$SRC_DIR/pqPluginDockWidgetsBehavior.h \
  $$SRC_DIR/pqPluginDocumentationBehavior.h \
  $$SRC_DIR/pqPluginPathBehavior.h \
  $$SRC_DIR/pqPluginSettingsBehavior.h \
  $$SRC_DIR/pqPluginToolBarBehavior.h \
  $$SRC_DIR/pqPointPickingHelper.h \
  $$SRC_DIR/pqPreviewMenuManager.h \
  $$SRC_DIR/pqPropertyCollectionWidget.h \
  $$SRC_DIR/pqProxyGroupMenuManager.h \
  $$SRC_DIR/pqPVAnimationWidget.h \
  $$SRC_DIR/pqPVApplicationCore.h \
  $$SRC_DIR/pqReaction.h \
  $$SRC_DIR/pqReloadFilesReaction.h \
  $$SRC_DIR/pqRenameProxyReaction.h \
  $$SRC_DIR/pqRenderViewSelectionReaction.h \
  $$SRC_DIR/pqRepresentationToolbar.h \
  $$SRC_DIR/pqResetDefaultSettingsReaction.h \
  $$SRC_DIR/pqResetScalarRangeReaction.h \
  $$SRC_DIR/pqSaveAnimationGeometryReaction.h \
  $$SRC_DIR/pqSaveAnimationReaction.h \
  $$SRC_DIR/pqSaveDataReaction.h \
  $$SRC_DIR/pqSaveExtractsReaction.h \
  $$SRC_DIR/pqSaveScreenshotReaction.h \
  $$SRC_DIR/pqSaveStateReaction.h \
  $$SRC_DIR/pqScalarBarVisibilityReaction.h \
  $$SRC_DIR/pqSearchItemReaction.h \
  $$SRC_DIR/pqSelectionReaction.h \
  $$SRC_DIR/pqSeriesEditorPropertyWidget.h \
  $$SRC_DIR/pqServerConnectReaction.h \
  $$SRC_DIR/pqServerDisconnectReaction.h \
  $$SRC_DIR/pqSetMainWindowTitleReaction.h \
  $$SRC_DIR/pqShowHideAllReaction.h \
  $$SRC_DIR/pqShowWidgetDecorator.h \
  $$SRC_DIR/pqSourcesMenuReaction.h \
  $$SRC_DIR/pqSpherePropertyWidget.h \
  $$SRC_DIR/pqSplinePropertyWidget.h \
  $$SRC_DIR/pqSpreadSheetViewDecorator.h \
  $$SRC_DIR/pqSpreadSheetVisibilityBehavior.h \
  $$SRC_DIR/pqStandardPropertyWidgetInterface.h \
  $$SRC_DIR/pqStandardRecentlyUsedResourceLoaderImplementation.h \
  $$SRC_DIR/pqStandardViewFrameActionsImplementation.h \
  $$SRC_DIR/pqStatusBar.h \
  $$SRC_DIR/pqStreamingTestingEventPlayer.h \
  $$SRC_DIR/pqTemporalExportReaction.h \
  $$SRC_DIR/pqTestingReaction.h \
  $$SRC_DIR/pqTextLocationWidget.h \
  $$SRC_DIR/pqTimeInspectorWidget.h \
  $$SRC_DIR/pqTimerLogReaction.h \
  $$SRC_DIR/pqToggleInteractionViewMode.h \
  $$SRC_DIR/pqTraceReaction.h \
  $$SRC_DIR/pqTransferFunctionWidgetPropertyDialog.h \
  $$SRC_DIR/pqTransferFunctionWidgetPropertyWidget.h \
  $$SRC_DIR/pqUndoRedoBehavior.h \
  $$SRC_DIR/pqUndoRedoReaction.h \
  $$SRC_DIR/pqUsageLoggingBehavior.h \
  $$SRC_DIR/pqUseSeparateColorMapReaction.h \
  $$SRC_DIR/pqVCRToolbar.h \
  $$SRC_DIR/pqVerifyRequiredPluginBehavior.h \
  $$SRC_DIR/pqViewMenuManager.h \
  $$SRC_DIR/pqViewResolutionPropertyWidget.h \
  $$SRC_DIR/pqViewStreamingBehavior.h \
  $$SRC_DIR/pqViewTypePropertyWidget.h \
  $$SRC_DIR/pqWelcomeDialog.h \
  $$SRC_DIR/pqYoungsMaterialPropertyWidget.h \


SOURCES += \
  $$SRC_DIR/pqAboutDialogReaction.cxx \
  $$SRC_DIR/pqAddToFavoritesReaction.cxx \
  $$SRC_DIR/pqAlwaysConnectedBehavior.cxx \
  $$SRC_DIR/pqAnimationShortcutDecorator.cxx \
  $$SRC_DIR/pqAnimationShortcutWidget.cxx \
  $$SRC_DIR/pqAnimationTimeToolbar.cxx \
  $$SRC_DIR/pqAnnotationsModel.cxx \
  $$SRC_DIR/pqApplicationComponentsInit.cxx \
  $$SRC_DIR/pqApplicationSettingsReaction.cxx \
  $$SRC_DIR/pqApplyBehavior.cxx \
  $$SRC_DIR/pqApplyPropertiesReaction.cxx \
  $$SRC_DIR/pqAutoApplyReaction.cxx \
  $$SRC_DIR/pqAutoLoadPluginXMLBehavior.cxx \
  $$SRC_DIR/pqAxesToolbar.cxx \
  $$SRC_DIR/pqBackgroundEditorWidget.cxx \
  $$SRC_DIR/pqBoolPropertyWidgetDecorator.cxx \
  $$SRC_DIR/pqBoxPropertyWidget.cxx \
  $$SRC_DIR/pqCameraLinkReaction.cxx \
  $$SRC_DIR/pqCameraManipulatorWidget.cxx \
  $$SRC_DIR/pqCameraReaction.cxx \
  $$SRC_DIR/pqCameraToolbar.cxx \
  $$SRC_DIR/pqCameraUndoRedoReaction.cxx \
  $$SRC_DIR/pqCatalystConnectReaction.cxx \
  $$SRC_DIR/pqCatalystExportReaction.cxx \
  $$SRC_DIR/pqCatalystPauseSimulationReaction.cxx \
  $$SRC_DIR/pqCatalystRemoveBreakpointReaction.cxx \
  $$SRC_DIR/pqCatalystSetBreakpointReaction.cxx \
  $$SRC_DIR/pqCategoryToolbarsBehavior.cxx \
  $$SRC_DIR/pqChangePipelineInputReaction.cxx \
  $$SRC_DIR/pqChartSelectionReaction.cxx \
  $$SRC_DIR/pqCheckableProperty.cxx \
  $$SRC_DIR/pqChooseColorPresetReaction.cxx \
  $$SRC_DIR/pqCollaborationBehavior.cxx \
  $$SRC_DIR/pqColorAnnotationsPropertyWidget.cxx \
  $$SRC_DIR/pqColorAnnotationsWidget.cxx \
  $$SRC_DIR/pqColorEditorPropertyWidget.cxx \
  $$SRC_DIR/pqColorMapEditor.cxx \
  $$SRC_DIR/pqColorOpacityEditorWidget.cxx \
  $$SRC_DIR/pqColorPaletteSelectorWidget.cxx \
  $$SRC_DIR/pqColorSelectorPropertyWidget.cxx \
  $$SRC_DIR/pqColorTableModel.cxx \
  $$SRC_DIR/pqColorToolbar.cxx \
  $$SRC_DIR/pqCommandButtonPropertyWidget.cxx \
  $$SRC_DIR/pqCommandLineOptionsBehavior.cxx \
  $$SRC_DIR/pqCopyReaction.cxx \
  $$SRC_DIR/pqCrashRecoveryBehavior.cxx \
  $$SRC_DIR/pqCreateCustomFilterReaction.cxx \
  $$SRC_DIR/pqCTHArraySelectionDecorator.cxx \
  $$SRC_DIR/pqCustomizeShortcutsDialog.cxx \
  $$SRC_DIR/pqCustomizeShortcutsReaction.cxx \
  $$SRC_DIR/pqCustomShortcutBehavior.cxx \
  $$SRC_DIR/pqCustomViewpointsToolbar.cxx \
  $$SRC_DIR/pqCylinderPropertyWidget.cxx \
  $$SRC_DIR/pqDataAssemblyPropertyWidget.cxx \
  $$SRC_DIR/pqDataQueryReaction.cxx \
  $$SRC_DIR/pqDataTimeStepBehavior.cxx \
  $$SRC_DIR/pqDefaultMainWindow.cxx \
  $$SRC_DIR/pqDefaultViewBehavior.cxx \
  $$SRC_DIR/pqDeleteReaction.cxx \
  $$SRC_DIR/pqDesktopServicesReaction.cxx \
  $$SRC_DIR/pqDoubleRangeSliderPropertyWidget.cxx \
  $$SRC_DIR/pqEditCameraReaction.cxx \
  $$SRC_DIR/pqEditColorMapReaction.cxx \
  $$SRC_DIR/pqEditScalarBarReaction.cxx \
  $$SRC_DIR/pqEnableWidgetDecorator.cxx \
  $$SRC_DIR/pqExampleVisualizationsDialog.cxx \
  $$SRC_DIR/pqExampleVisualizationsDialogReaction.cxx \
  $$SRC_DIR/pqExportReaction.cxx \
  $$SRC_DIR/pqExtractorsMenuReaction.cxx \
  $$SRC_DIR/pqFileNamePropertyWidget.cxx \
  $$SRC_DIR/pqFiltersMenuReaction.cxx \
  $$SRC_DIR/pqFontPropertyWidget.cxx \
  $$SRC_DIR/pqGenericPropertyWidgetDecorator.cxx \
  $$SRC_DIR/pqGlyphScaleFactorPropertyWidget.cxx \
  $$SRC_DIR/pqHandlePropertyWidget.cxx \
  $$SRC_DIR/pqHelpReaction.cxx \
  $$SRC_DIR/pqIgnoreSourceTimeReaction.cxx \
  $$SRC_DIR/pqImageCompressorWidget.cxx \
  $$SRC_DIR/pqImplicitPlanePropertyWidget.cxx \
  $$SRC_DIR/pqInputDataTypeDecorator.cxx \
  $$SRC_DIR/pqInteractivePropertyWidget.cxx \
  $$SRC_DIR/pqLightPropertyWidget.cxx \
  $$SRC_DIR/pqLinePropertyWidget.cxx \
  $$SRC_DIR/pqLinkSelectionReaction.cxx \
  $$SRC_DIR/pqListPropertyWidget.cxx \
  $$SRC_DIR/pqLiveSourceBehavior.cxx \
  $$SRC_DIR/pqLoadDataReaction.cxx \
  $$SRC_DIR/pqLoadMaterialsReaction.cxx \
  $$SRC_DIR/pqLoadPaletteReaction.cxx \
  $$SRC_DIR/pqLoadRestoreWindowLayoutReaction.cxx \
  $$SRC_DIR/pqLoadStateReaction.cxx \
  $$SRC_DIR/pqLockPanelsBehavior.cxx \
  $$SRC_DIR/pqLockPanelsReaction.cxx \
  $$SRC_DIR/pqLogViewerReaction.cxx \
  $$SRC_DIR/pqMacroReaction.cxx \
  $$SRC_DIR/pqMainControlsToolbar.cxx \
  $$SRC_DIR/pqMainWindowEventBehavior.cxx \
  $$SRC_DIR/pqManageCustomFiltersReaction.cxx \
  $$SRC_DIR/pqManageFavoritesReaction.cxx \
  $$SRC_DIR/pqManageLinksReaction.cxx \
  $$SRC_DIR/pqManagePluginsReaction.cxx \
  $$SRC_DIR/pqMasterOnlyReaction.cxx \
  $$SRC_DIR/pqMenuReactionUtils.cxx \
  $$SRC_DIR/pqModelTransformSupportBehavior.cxx \
  $$SRC_DIR/pqMoleculePropertyWidget.cxx \
  $$SRC_DIR/pqMultiComponentsDecorator.cxx \
  $$SRC_DIR/pqObjectPickingBehavior.cxx \
  $$SRC_DIR/pqOMETransferFunctionsPropertyWidget.cxx \
  $$SRC_DIR/pqOpacityTableModel.cxx \
  $$SRC_DIR/pqOSPRayHidingDecorator.cxx \
  $$SRC_DIR/pqParaViewBehaviors.cxx \
  $$SRC_DIR/pqParaViewMenuBuilders.cxx \
  $$SRC_DIR/pqPauseLiveSourcePropertyWidget.cxx \
  $$SRC_DIR/pqPersistentMainWindowStateBehavior.cxx \
  $$SRC_DIR/pqPipelineContextMenuBehavior.cxx \
  $$SRC_DIR/pqPluginActionGroupBehavior.cxx \
  $$SRC_DIR/pqPluginDockWidgetsBehavior.cxx \
  $$SRC_DIR/pqPluginDocumentationBehavior.cxx \
  $$SRC_DIR/pqPluginPathBehavior.cxx \
  $$SRC_DIR/pqPluginSettingsBehavior.cxx \
  $$SRC_DIR/pqPluginToolBarBehavior.cxx \
  $$SRC_DIR/pqPointPickingHelper.cxx \
  $$SRC_DIR/pqPreviewMenuManager.cxx \
  $$SRC_DIR/pqPropertyCollectionWidget.cxx \
  $$SRC_DIR/pqProxyGroupMenuManager.cxx \
  $$SRC_DIR/pqPVAnimationWidget.cxx \
  $$SRC_DIR/pqPVApplicationCore.cxx \
  $$SRC_DIR/pqReaction.cxx \
  $$SRC_DIR/pqReloadFilesReaction.cxx \
  $$SRC_DIR/pqRenameProxyReaction.cxx \
  $$SRC_DIR/pqRenderViewSelectionReaction.cxx \
  $$SRC_DIR/pqRepresentationToolbar.cxx \
  $$SRC_DIR/pqResetDefaultSettingsReaction.cxx \
  $$SRC_DIR/pqResetScalarRangeReaction.cxx \
  $$SRC_DIR/pqSaveAnimationGeometryReaction.cxx \
  $$SRC_DIR/pqSaveAnimationReaction.cxx \
  $$SRC_DIR/pqSaveDataReaction.cxx \
  $$SRC_DIR/pqSaveExtractsReaction.cxx \
  $$SRC_DIR/pqSaveScreenshotReaction.cxx \
  $$SRC_DIR/pqSaveStateReaction.cxx \
  $$SRC_DIR/pqScalarBarVisibilityReaction.cxx \
  $$SRC_DIR/pqSearchItemReaction.cxx \
  $$SRC_DIR/pqSelectionReaction.cxx \
  $$SRC_DIR/pqSeriesEditorPropertyWidget.cxx \
  $$SRC_DIR/pqServerConnectReaction.cxx \
  $$SRC_DIR/pqServerDisconnectReaction.cxx \
  $$SRC_DIR/pqSetMainWindowTitleReaction.cxx \
  $$SRC_DIR/pqShowHideAllReaction.cxx \
  $$SRC_DIR/pqShowWidgetDecorator.cxx \
  $$SRC_DIR/pqSourcesMenuReaction.cxx \
  $$SRC_DIR/pqSpherePropertyWidget.cxx \
  $$SRC_DIR/pqSplinePropertyWidget.cxx \
  $$SRC_DIR/pqSpreadSheetViewDecorator.cxx \
  $$SRC_DIR/pqSpreadSheetVisibilityBehavior.cxx \
  $$SRC_DIR/pqStandardPropertyWidgetInterface.cxx \
  $$SRC_DIR/pqStandardRecentlyUsedResourceLoaderImplementation.cxx \
  $$SRC_DIR/pqStandardViewFrameActionsImplementation.cxx \
  $$SRC_DIR/pqStatusBar.cxx \
  $$SRC_DIR/pqStreamingTestingEventPlayer.cxx \
  $$SRC_DIR/pqTemporalExportReaction.cxx \
  $$SRC_DIR/pqTestingReaction.cxx \
  $$SRC_DIR/pqTextLocationWidget.cxx \
  $$SRC_DIR/pqTimeInspectorWidget.cxx \
  $$SRC_DIR/pqTimerLogReaction.cxx \
  $$SRC_DIR/pqToggleInteractionViewMode.cxx \
  $$SRC_DIR/pqTraceReaction.cxx \
  $$SRC_DIR/pqTransferFunctionWidgetPropertyDialog.cxx \
  $$SRC_DIR/pqTransferFunctionWidgetPropertyWidget.cxx \
  $$SRC_DIR/pqUndoRedoBehavior.cxx \
  $$SRC_DIR/pqUndoRedoReaction.cxx \
  $$SRC_DIR/pqUsageLoggingBehavior.cxx \
  $$SRC_DIR/pqUseSeparateColorMapReaction.cxx \
  $$SRC_DIR/pqVCRToolbar.cxx \
  $$SRC_DIR/pqVerifyRequiredPluginBehavior.cxx \
  $$SRC_DIR/pqViewMenuManager.cxx \
  $$SRC_DIR/pqViewResolutionPropertyWidget.cxx \
  $$SRC_DIR/pqViewStreamingBehavior.cxx \
  $$SRC_DIR/pqViewTypePropertyWidget.cxx \
  $$SRC_DIR/pqWelcomeDialog.cxx \
  $$SRC_DIR/pqYoungsMaterialPropertyWidget.cxx \


LIBS += -lpython2.7


