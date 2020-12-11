
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
  $$SRC_DIR/Resources/UI/pqLockViewSizeCustomDialog.ui \
  $$SRC_DIR/Resources/UI/pqFindDataCreateSelectionFrame.ui \
  $$SRC_DIR/Resources/UI/pqProxyInformationWidget.ui \
  $$SRC_DIR/Resources/UI/pqPresetDialog.ui \
  $$SRC_DIR/Resources/UI/pqServerConnectDialog.ui \
  $$SRC_DIR/Resources/UI/pqSampleScalarWidget.ui \
  $$SRC_DIR/Resources/UI/pqDisplayRepresentationWidget.ui \
  $$SRC_DIR/Resources/UI/pqSettingsDialog.ui \
  $$SRC_DIR/Resources/UI/pqComparativeVisPanel.ui \
  $$SRC_DIR/Resources/UI/pqMemoryInspectorPanelForm.ui \
  $$SRC_DIR/Resources/UI/pqFindDataDialog.ui \
  $$SRC_DIR/Resources/UI/pqQueryCompositeTreeDialog.ui \
  $$SRC_DIR/Resources/UI/pqPopoutPlaceholder.ui \
  $$SRC_DIR/Resources/UI/pqConnectIdDialog.ui \
  $$SRC_DIR/Resources/UI/pqCameraKeyFrameWidget.ui \
  $$SRC_DIR/Resources/UI/pqServerLauncherDialog.ui \
  $$SRC_DIR/Resources/UI/pqMultiBlockInspectorWidget.ui \
  $$SRC_DIR/Resources/UI/pqLogViewerDialog.ui \
  $$SRC_DIR/Resources/UI/pqScalarValueListPropertyWidget.ui \
  $$SRC_DIR/Resources/UI/pqLinksEditor.ui \
  $$SRC_DIR/Resources/UI/pqRemoteCommandDialogForm.ui \
  $$SRC_DIR/Resources/UI/pqKeyFrameEditor.ui \
  $$SRC_DIR/Resources/UI/pqPluginDialog.ui \
  $$SRC_DIR/Resources/UI/pqCustomViewpointButtonDialog.ui \
  $$SRC_DIR/Resources/UI/pqCustomFilterManager.ui \
  $$SRC_DIR/Resources/UI/pqKeyFrameTypeWidget.ui \
  $$SRC_DIR/Resources/UI/pqAbortAnimation.ui \
  $$SRC_DIR/Resources/UI/pqSelectionLinkDialog.ui \
  $$SRC_DIR/Resources/UI/pqSetBreakpointDialog.ui \
  $$SRC_DIR/Resources/UI/pqLightsInspector.ui \
  $$SRC_DIR/Resources/UI/pqSelectReaderDialog.ui \
  $$SRC_DIR/Resources/UI/pqCustomFilterDefinitionWizard.ui \
  $$SRC_DIR/Resources/UI/pqRemoteCommandTemplateDialogForm.ui \
  $$SRC_DIR/Resources/UI/pqQueryClauseWidget.ui \
  $$SRC_DIR/Resources/UI/pqCollaborationPanel.ui \
  $$SRC_DIR/Resources/UI/pqLinksManager.ui \
  $$SRC_DIR/Resources/UI/pqCalculatorWidget.ui \
  $$SRC_DIR/Resources/UI/pqAnimationTimeWidget.ui \
  $$SRC_DIR/Resources/UI/pqViewFrame.ui \
  $$SRC_DIR/Resources/UI/pqTimerLogDisplay.ui \
  $$SRC_DIR/Resources/UI/pqProxySelectionWidget.ui \
  $$SRC_DIR/Resources/UI/pqOrbitCreatorDialog.ui \
  $$SRC_DIR/Resources/UI/pqContourControls.ui \
  $$SRC_DIR/Resources/UI/pqSampleScalarAddRangeDialog.ui \
  $$SRC_DIR/Resources/UI/pqPipelineTimeKeyFrameEditor.ui \
  $$SRC_DIR/Resources/UI/pqFindDataCurrentSelectionFrame.ui \
  $$SRC_DIR/Resources/UI/pqAboutDialog.ui \
  $$SRC_DIR/Resources/UI/pqLightsEditor.ui \
  $$SRC_DIR/Resources/UI/pqProxyWidgetDialog.ui \
  $$SRC_DIR/Resources/UI/pqChangeInputDialog.ui \
  $$SRC_DIR/Resources/UI/pqSelectionInputWidget.ui \
  $$SRC_DIR/Resources/UI/pqRescaleRangeDialog.ui \
  $$SRC_DIR/Resources/UI/pqSearchBox.ui \
  $$SRC_DIR/Resources/UI/pqFindDataSelectionDisplayFrame.ui \
  $$SRC_DIR/Resources/UI/pqPropertiesPanel.ui \
  $$SRC_DIR/Resources/UI/pqComparativeParameterRangeDialog.ui \
  $$SRC_DIR/Resources/UI/pqCameraDialog.ui \
  $$SRC_DIR/Resources/UI/pqItemViewSearchWidget.ui \
  $$SRC_DIR/Resources/UI/pqFavoritesDialog.ui \
  $$SRC_DIR/Resources/UI/pqPythonAnimationCue.ui \



INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Core
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/FiltersRendering

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Remoting/ViewsPython



INCLUDEPATH += $$SRC_GROUP_DIR/pqCore  $$SRC_GROUP_DIR/pqWidgets 



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

HEADERS += \
  $$SRC_DIR/pqAboutDialog.h \
  $$SRC_DIR/pqAbstractItemSelectionModel.h \
  $$SRC_DIR/pqActionGroupInterface.h \
  $$SRC_DIR/pqActiveObjects.h \
  $$SRC_DIR/pqAnimatablePropertiesComboBox.h \
  $$SRC_DIR/pqAnimatableProxyComboBox.h \
  $$SRC_DIR/pqAnimationManager.h \
  $$SRC_DIR/pqAnimationProgressDialog.h \
  $$SRC_DIR/pqAnimationTimeWidget.h \
  $$SRC_DIR/pqAnimationViewWidget.h \
  $$SRC_DIR/pqArrayListDomain.h \
  $$SRC_DIR/pqArraySelectionWidget.h \
  $$SRC_DIR/pqArraySelectorPropertyWidget.h \
  $$SRC_DIR/pqArrayStatusPropertyWidget.h \
  $$SRC_DIR/pqCalculatorWidget.h \
  $$SRC_DIR/pqCameraDialog.h \
  $$SRC_DIR/pqCameraKeyFrameWidget.h \
  $$SRC_DIR/pqChangeInputDialog.h \
  $$SRC_DIR/pqCollaborationPanel.h \
  $$SRC_DIR/pqColorChooserButtonWithPalettes.h \
  $$SRC_DIR/pqComboBoxDomain.h \
  $$SRC_DIR/pqCommandPropertyWidget.h \
  $$SRC_DIR/pqComparativeCueWidget.h \
  $$SRC_DIR/pqComparativeVisPanel.h \
  $$SRC_DIR/pqComponentsInit.h \
  $$SRC_DIR/pqComponentsTestUtility.h \
  $$SRC_DIR/pqCompositeDataInformationTreeModel.h \
  $$SRC_DIR/pqCompositePropertyWidgetDecorator.h \
  $$SRC_DIR/pqCompositeTreePropertyWidget.h \
  $$SRC_DIR/pqCustomFilterDefinitionModel.h \
  $$SRC_DIR/pqCustomFilterDefinitionWizard.h \
  $$SRC_DIR/pqCustomFilterManager.h \
  $$SRC_DIR/pqCustomFilterManagerModel.h \
  $$SRC_DIR/pqCustomViewpointButtonDialog.h \
  $$SRC_DIR/pqDataAssemblyTreeModel.h \
  $$SRC_DIR/pqDataInformationModel.h \
  $$SRC_DIR/pqDataInformationWidget.h \
  $$SRC_DIR/pqDialog.h \
  $$SRC_DIR/pqDisplayColorWidget.h \
  $$SRC_DIR/pqDisplayPanel.h \
  $$SRC_DIR/pqDisplayPanelInterface.h \
  $$SRC_DIR/pqDisplayPanelPropertyWidget.h \
  $$SRC_DIR/pqDisplayRepresentationWidget.h \
  $$SRC_DIR/pqDockWindowInterface.h \
  $$SRC_DIR/pqDoubleVectorPropertyWidget.h \
  $$SRC_DIR/pqFavoritesDialog.h \
  $$SRC_DIR/pqFavoritesTreeWidget.h \
  $$SRC_DIR/pqFileChooserWidget.h \
  $$SRC_DIR/pqFindDataCreateSelectionFrame.h \
  $$SRC_DIR/pqFindDataCurrentSelectionFrame.h \
  $$SRC_DIR/pqFindDataDialog.h \
  $$SRC_DIR/pqFindDataSelectionDisplayFrame.h \
  $$SRC_DIR/pqHighlightItemDelegate.h \
  $$SRC_DIR/pqImageCompressorType.h \
  $$SRC_DIR/pqImageTip.h \
  $$SRC_DIR/pqIndexSelectionWidget.h \
  $$SRC_DIR/pqInputSelectorWidget.h \
  $$SRC_DIR/pqIntMaskPropertyWidget.h \
  $$SRC_DIR/pqIntRangeWidget.h \
  $$SRC_DIR/pqIntVectorPropertyWidget.h \
  $$SRC_DIR/pqItemViewSearchWidget.h \
  $$SRC_DIR/pqItemViewSearchWidgetEventPlayer.h \
  $$SRC_DIR/pqKeyFrameEditor.h \
  $$SRC_DIR/pqKeyFrameTimeValidator.h \
  $$SRC_DIR/pqKeyFrameTypeWidget.h \
  $$SRC_DIR/pqLabel.h \
  $$SRC_DIR/pqLightsEditor.h \
  $$SRC_DIR/pqLightsInspector.h \
  $$SRC_DIR/pqLinksEditor.h \
  $$SRC_DIR/pqLinksManager.h \
  $$SRC_DIR/pqLiveInsituManager.h \
  $$SRC_DIR/pqLiveInsituVisualizationManager.h \
  $$SRC_DIR/pqLockViewSizeCustomDialog.h \
  $$SRC_DIR/pqLogViewerDialog.h \
  $$SRC_DIR/pqMemoryInspectorPanel.h \
  $$SRC_DIR/pqMultiBlockInspectorWidget.h \
  $$SRC_DIR/pqMultiQueryClauseWidget.h \
  $$SRC_DIR/pqMultiViewWidget.h \
  $$SRC_DIR/pqOrbitCreatorDialog.h \
  $$SRC_DIR/pqOutputPortComboBox.h \
  $$SRC_DIR/pqPipelineAnnotationFilterModel.h \
  $$SRC_DIR/pqPipelineBrowserWidget.h \
  $$SRC_DIR/pqPipelineInputComboBox.h \
  $$SRC_DIR/pqPipelineModel.h \
  $$SRC_DIR/pqPipelineModelSelectionAdaptor.h \
  $$SRC_DIR/pqPipelineTimeKeyFrameEditor.h \
  $$SRC_DIR/pqPluginDialog.h \
  $$SRC_DIR/pqPluginTreeWidget.h \
  $$SRC_DIR/pqPluginTreeWidgetEventPlayer.h \
  $$SRC_DIR/pqPluginTreeWidgetEventTranslator.h \
  $$SRC_DIR/pqPopOutWidget.h \
  $$SRC_DIR/pqPresetDialog.h \
  $$SRC_DIR/pqPresetGroupsManager.h \
  $$SRC_DIR/pqPresetToPixmap.h \
  $$SRC_DIR/pqPropertiesPanel.h \
  $$SRC_DIR/pqPropertyGroupWidget.h \
  $$SRC_DIR/pqPropertyWidget.h \
  $$SRC_DIR/pqPropertyWidgetDecorator.h \
  $$SRC_DIR/pqPropertyWidgetInterface.h \
  $$SRC_DIR/pqProxiesWidget.h \
  $$SRC_DIR/pqProxyEditorPropertyWidget.h \
  $$SRC_DIR/pqProxyInformationWidget.h \
  $$SRC_DIR/pqProxyPropertyWidget.h \
  $$SRC_DIR/pqProxySILModel.h \
  $$SRC_DIR/pqProxySelectionWidget.h \
  $$SRC_DIR/pqProxyWidget.h \
  $$SRC_DIR/pqProxyWidgetDialog.h \
  $$SRC_DIR/pqQueryClauseWidget.h \
  $$SRC_DIR/pqRecentFilesMenu.h \
  $$SRC_DIR/pqRemoteCommandDialog.h \
  $$SRC_DIR/pqRemoteCommandTemplateDialog.h \
  $$SRC_DIR/pqRescaleRange.h \
  $$SRC_DIR/pqSILModel.h \
  $$SRC_DIR/pqSILWidget.h \
  $$SRC_DIR/pqSMSignalAdaptors.h \
  $$SRC_DIR/pqSampleScalarAddRangeDialog.h \
  $$SRC_DIR/pqSampleScalarWidget.h \
  $$SRC_DIR/pqScalarSetModel.h \
  $$SRC_DIR/pqScalarValueListPropertyWidget.h \
  $$SRC_DIR/pqSearchBox.h \
  $$SRC_DIR/pqSelectReaderDialog.h \
  $$SRC_DIR/pqSelectionAdaptor.h \
  $$SRC_DIR/pqSelectionInputWidget.h \
  $$SRC_DIR/pqSelectionLinkDialog.h \
  $$SRC_DIR/pqSelectionManager.h \
  $$SRC_DIR/pqServerConfigurationImporter.h \
  $$SRC_DIR/pqServerConnectDialog.h \
  $$SRC_DIR/pqServerLauncher.h \
  $$SRC_DIR/pqSetBreakpointDialog.h \
  $$SRC_DIR/pqSettingsDialog.h \
  $$SRC_DIR/pqShaderReplacementsComboBox.h \
  $$SRC_DIR/pqShaderReplacementsSelectorPropertyWidget.h \
  $$SRC_DIR/pqSignalAdaptorKeyFrameType.h \
  $$SRC_DIR/pqSignalAdaptorSILModel.h \
  $$SRC_DIR/pqSignalAdaptorSelectionTreeWidget.h \
  $$SRC_DIR/pqSignalAdaptorTreeWidget.h \
  $$SRC_DIR/pqSingleLogViewerWidget.h \
  $$SRC_DIR/pqStringVectorPropertyWidget.h \
  $$SRC_DIR/pqSubsetInclusionLatticeTreeModel.h \
  $$SRC_DIR/pqSubsetInclusionLatticeWidget.h \
  $$SRC_DIR/pqTabbedMultiViewWidget.h \
  $$SRC_DIR/pqTextureComboBox.h \
  $$SRC_DIR/pqTextureSelectorPropertyWidget.h \
  $$SRC_DIR/pqTimerLogDisplay.h \
  $$SRC_DIR/pqToolBarInterface.h \
  $$SRC_DIR/pqToolTipTrapper.h \
  $$SRC_DIR/pqTransferFunctionWidget.h \
  $$SRC_DIR/pqTriggerOnIdleHelper.h \
  $$SRC_DIR/pqUndoStackBuilder.h \
  $$SRC_DIR/pqVCRController.h \
  $$SRC_DIR/pqVariableType.h \
  $$SRC_DIR/pqViewFrame.h \
  $$SRC_DIR/pqViewFrameActionsInterface.h \
  $$SRC_DIR/pqViewManager.h \
  $$SRC_DIR/pqWidgetRangeDomain.h

SOURCES += \
  $$SRC_DIR/pqAboutDialog.cxx \
  $$SRC_DIR/pqAbstractItemSelectionModel.cxx \
  $$SRC_DIR/pqActionGroupInterface.cxx \
  $$SRC_DIR/pqActiveObjects.cxx \
  $$SRC_DIR/pqAnimatablePropertiesComboBox.cxx \
  $$SRC_DIR/pqAnimatableProxyComboBox.cxx \
  $$SRC_DIR/pqAnimationManager.cxx \
  $$SRC_DIR/pqAnimationProgressDialog.cxx \
  $$SRC_DIR/pqAnimationTimeWidget.cxx \
  $$SRC_DIR/pqAnimationViewWidget.cxx \
  $$SRC_DIR/pqArrayListDomain.cxx \
  $$SRC_DIR/pqArraySelectionWidget.cxx \
  $$SRC_DIR/pqArraySelectorPropertyWidget.cxx \
  $$SRC_DIR/pqArrayStatusPropertyWidget.cxx \
  $$SRC_DIR/pqCalculatorWidget.cxx \
  $$SRC_DIR/pqCameraDialog.cxx \
  $$SRC_DIR/pqCameraKeyFrameWidget.cxx \
  $$SRC_DIR/pqChangeInputDialog.cxx \
  \# $$SRC_DIR/Components/pqCollaborationPanel.cxx \
  $$SRC_DIR/pqColorChooserButtonWithPalettes.cxx \
  $$SRC_DIR/pqComboBoxDomain.cxx \
  $$SRC_DIR/pqCommandPropertyWidget.cxx \
  $$SRC_DIR/pqComparativeCueWidget.cxx \
  $$SRC_DIR/pqComparativeVisPanel.cxx \
  $$SRC_DIR/pqComponentsInit.cxx \
  $$SRC_DIR/pqComponentsTestUtility.cxx \
  $$SRC_DIR/pqCompositeDataInformationTreeModel.cxx \
  $$SRC_DIR/pqCompositePropertyWidgetDecorator.cxx \
  $$SRC_DIR/pqCompositeTreePropertyWidget.cxx \
  $$SRC_DIR/pqCustomFilterDefinitionModel.cxx \
  $$SRC_DIR/pqCustomFilterDefinitionWizard.cxx \
  $$SRC_DIR/pqCustomFilterManager.cxx \
  $$SRC_DIR/pqCustomFilterManagerModel.cxx \
  $$SRC_DIR/pqCustomViewpointButtonDialog.cxx \
  $$SRC_DIR/pqDataAssemblyTreeModel.cxx \
  $$SRC_DIR/pqDataInformationModel.cxx \
  $$SRC_DIR/pqDataInformationWidget.cxx \
  $$SRC_DIR/pqDialog.cxx \
  $$SRC_DIR/pqDisplayColorWidget.cxx \
  $$SRC_DIR/pqDisplayPanel.cxx \
  $$SRC_DIR/pqDisplayPanelInterface.cxx \
  $$SRC_DIR/pqDisplayPanelPropertyWidget.cxx \
  $$SRC_DIR/pqDisplayRepresentationWidget.cxx \
  $$SRC_DIR/pqDockWindowInterface.cxx \
  $$SRC_DIR/pqDoubleVectorPropertyWidget.cxx \
  $$SRC_DIR/pqFavoritesDialog.cxx \
  $$SRC_DIR/pqFavoritesTreeWidget.cxx \
  $$SRC_DIR/pqFileChooserWidget.cxx \
  $$SRC_DIR/pqFindDataCreateSelectionFrame.cxx \
  $$SRC_DIR/pqFindDataCurrentSelectionFrame.cxx \
  $$SRC_DIR/pqFindDataDialog.cxx \
  $$SRC_DIR/pqFindDataSelectionDisplayFrame.cxx \
  $$SRC_DIR/pqHighlightItemDelegate.cxx \
  $$SRC_DIR/pqImageTip.cxx \
  $$SRC_DIR/pqIndexSelectionWidget.cxx \
  $$SRC_DIR/pqInputSelectorWidget.cxx \
  $$SRC_DIR/pqIntMaskPropertyWidget.cxx \
  $$SRC_DIR/pqIntRangeWidget.cxx \
  $$SRC_DIR/pqIntVectorPropertyWidget.cxx \
  $$SRC_DIR/pqItemViewSearchWidget.cxx \
  $$SRC_DIR/pqItemViewSearchWidgetEventPlayer.cxx \
  $$SRC_DIR/pqKeyFrameEditor.cxx \
  $$SRC_DIR/pqKeyFrameTimeValidator.cxx \
  $$SRC_DIR/pqKeyFrameTypeWidget.cxx \
  $$SRC_DIR/pqLabel.cxx \
  $$SRC_DIR/pqLightsEditor.cxx \
  $$SRC_DIR/pqLightsInspector.cxx \
  $$SRC_DIR/pqLinksEditor.cxx \
  $$SRC_DIR/pqLinksManager.cxx \
  $$SRC_DIR/pqLiveInsituManager.cxx \
  $$SRC_DIR/pqLiveInsituVisualizationManager.cxx \
  $$SRC_DIR/pqLockViewSizeCustomDialog.cxx \
  $$SRC_DIR/pqLogViewerDialog.cxx \
  $$SRC_DIR/pqMemoryInspectorPanel.cxx \
  $$SRC_DIR/pqMultiBlockInspectorWidget.cxx \
  $$SRC_DIR/pqMultiQueryClauseWidget.cxx \
  $$SRC_DIR/pqMultiViewWidget.cxx \
  $$SRC_DIR/pqOrbitCreatorDialog.cxx \
  $$SRC_DIR/pqOutputPortComboBox.cxx \
  $$SRC_DIR/pqPipelineAnnotationFilterModel.cxx \
  $$SRC_DIR/pqPipelineBrowserWidget.cxx \
  $$SRC_DIR/pqPipelineInputComboBox.cxx \
  $$SRC_DIR/pqPipelineModel.cxx \
  $$SRC_DIR/pqPipelineModelSelectionAdaptor.cxx \
  $$SRC_DIR/pqPipelineTimeKeyFrameEditor.cxx \
  $$SRC_DIR/pqPluginDialog.cxx \
  $$SRC_DIR/pqPluginTreeWidgetEventPlayer.cxx \
  $$SRC_DIR/pqPluginTreeWidgetEventTranslator.cxx \
  $$SRC_DIR/pqPopOutWidget.cxx \
  $$SRC_DIR/pqPresetDialog.cxx \
  $$SRC_DIR/pqPresetGroupsManager.cxx \
  $$SRC_DIR/pqPresetToPixmap.cxx \
  $$SRC_DIR/pqPropertiesPanel.cxx \
  $$SRC_DIR/pqPropertyGroupWidget.cxx \
  $$SRC_DIR/pqPropertyWidget.cxx \
  $$SRC_DIR/pqPropertyWidgetDecorator.cxx \
  $$SRC_DIR/pqPropertyWidgetInterface.cxx \
  $$SRC_DIR/pqProxiesWidget.cxx \
  $$SRC_DIR/pqProxyEditorPropertyWidget.cxx \
  $$SRC_DIR/pqProxyInformationWidget.cxx \
  $$SRC_DIR/pqProxyPropertyWidget.cxx \
  $$SRC_DIR/pqProxySILModel.cxx \
  $$SRC_DIR/pqProxySelectionWidget.cxx \
  $$SRC_DIR/pqProxyWidget.cxx \
  $$SRC_DIR/pqProxyWidgetDialog.cxx \
  $$SRC_DIR/pqQueryClauseWidget.cxx \
  $$SRC_DIR/pqRecentFilesMenu.cxx \
  $$SRC_DIR/pqRemoteCommandDialog.cxx \
  $$SRC_DIR/pqRemoteCommandTemplateDialog.cxx \
  $$SRC_DIR/pqRescaleRange.cxx \
  $$SRC_DIR/pqSILModel.cxx \
  $$SRC_DIR/pqSILWidget.cxx \
  $$SRC_DIR/pqSMSignalAdaptors.cxx \
  $$SRC_DIR/pqSampleScalarAddRangeDialog.cxx \
  $$SRC_DIR/pqSampleScalarWidget.cxx \
  $$SRC_DIR/pqScalarSetModel.cxx \
  $$SRC_DIR/pqScalarValueListPropertyWidget.cxx \
  $$SRC_DIR/pqSearchBox.cxx \
  $$SRC_DIR/pqSelectReaderDialog.cxx \
  $$SRC_DIR/pqSelectionAdaptor.cxx \
  $$SRC_DIR/pqSelectionInputWidget.cxx \
  $$SRC_DIR/pqSelectionLinkDialog.cxx \
  $$SRC_DIR/pqSelectionManager.cxx \
  $$SRC_DIR/pqServerConfigurationImporter.cxx \
  $$SRC_DIR/pqServerConnectDialog.cxx \
  $$SRC_DIR/pqServerLauncher.cxx \
  $$SRC_DIR/pqSetBreakpointDialog.cxx \
  $$SRC_DIR/pqSettingsDialog.cxx \
  $$SRC_DIR/pqShaderReplacementsComboBox.cxx \
  $$SRC_DIR/pqShaderReplacementsSelectorPropertyWidget.cxx \
  $$SRC_DIR/pqSignalAdaptorKeyFrameType.cxx \
  \# $$SRC_DIR/Components/pqSignalAdaptorSILModel.cxx \
  $$SRC_DIR/pqSignalAdaptorSelectionTreeWidget.cxx \
  $$SRC_DIR/pqSignalAdaptorTreeWidget.cxx \
  $$SRC_DIR/pqSingleLogViewerWidget.cxx \
  $$SRC_DIR/pqStringVectorPropertyWidget.cxx \
  $$SRC_DIR/pqSubsetInclusionLatticeTreeModel.cxx \
  $$SRC_DIR/pqSubsetInclusionLatticeWidget.cxx \
  $$SRC_DIR/pqTabbedMultiViewWidget.cxx \
  $$SRC_DIR/pqTextureComboBox.cxx \
  $$SRC_DIR/pqTextureSelectorPropertyWidget.cxx \
  $$SRC_DIR/pqTimerLogDisplay.cxx \
  $$SRC_DIR/pqToolBarInterface.cxx \
  $$SRC_DIR/pqToolTipTrapper.cxx \
  $$SRC_DIR/pqTransferFunctionWidget.cxx \
  $$SRC_DIR/pqTriggerOnIdleHelper.cxx \
  $$SRC_DIR/pqUndoStackBuilder.cxx \
  $$SRC_DIR/pqVCRController.cxx \
  $$SRC_DIR/pqViewFrame.cxx \
  $$SRC_DIR/pqViewFrameActionsInterface.cxx \
  $$SRC_DIR/pqViewManager.cxx \
  $$SRC_DIR/pqWidgetRangeDomain.cxx




#SOURCES += \
#  $$SRC_DIR/stubs.cpp

LIBS += -lpython2.7
