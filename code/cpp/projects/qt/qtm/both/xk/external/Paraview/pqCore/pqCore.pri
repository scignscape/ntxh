
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
  $$SRC_DIR/Resources/UI/pqPluginEULADialog.ui \
  $$SRC_DIR/Resources/UI/pqOutputWidget.ui \
  $$SRC_DIR/Resources/UI/pqFileDialog.ui \
  $$SRC_DIR/Resources/UI/pqLogViewerWidget.ui \



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


INCLUDEPATH += $$PARAVIEW_ALT_DIR/ThirdParty/QtTesting/vtkqttesting
message($$PARAVIEW_ALT_DIR/ThirdParty/QtTesting/vtkqttesting)


HEADERS += \
  $$SRC_DIR/pqAnimationCue.h \
  $$SRC_DIR/pqAnimationScene.h \
  $$SRC_DIR/pqApplicationCore.h \
  $$SRC_DIR/pqAutoStartInterface.h \
  $$SRC_DIR/pqBoxChartView.h \
  $$SRC_DIR/pqCheckBoxDelegate.h \
  $$SRC_DIR/pqCollaborationEventPlayer.h \
  $$SRC_DIR/pqCollaborationManager.h \
  $$SRC_DIR/pqComparativeContextView.h \
  $$SRC_DIR/pqComparativeRenderView.h \
  $$SRC_DIR/pqComparativeXYBarChartView.h \
  $$SRC_DIR/pqComparativeXYChartView.h \
  $$SRC_DIR/pqContextView.h \
  $$SRC_DIR/pqCoreInit.h \
  $$SRC_DIR/pqCoreTestUtility.h \
  $$SRC_DIR/pqCoreUtilities.h \
  $$SRC_DIR/pqDataRepresentation.h \
  $$SRC_DIR/pqDebug.h \
  $$SRC_DIR/pqExtractor.h \
  $$SRC_DIR/pqFileDialog.h \
  $$SRC_DIR/pqFileDialogEventPlayer.h \
  $$SRC_DIR/pqFileDialogEventTranslator.h \
  $$SRC_DIR/pqFileDialogFavoriteModel.h \
  $$SRC_DIR/pqFileDialogFilter.h \
  $$SRC_DIR/pqFileDialogModel.h \
  $$SRC_DIR/pqFileDialogRecentDirsModel.h \
  $$SRC_DIR/pqFlatTreeViewEventPlayer.h \
  $$SRC_DIR/pqFlatTreeViewEventTranslator.h \
  $$SRC_DIR/pqGraphLayoutStrategyInterface.h \
  $$SRC_DIR/pqImageUtil.h \
  $$SRC_DIR/pqInteractiveViewLink.h \
  $$SRC_DIR/pqInterfaceTracker.h \
  $$SRC_DIR/pqLinkViewWidget.h \
  $$SRC_DIR/pqLinksModel.h \
  $$SRC_DIR/pqLogViewerWidget.h \
  $$SRC_DIR/pqMainWindowEventManager.h \
  $$SRC_DIR/pqMultiSliceAxisWidget.h \
  $$SRC_DIR/pqMultiSliceView.h \
  $$SRC_DIR/pqNonEditableStyledItemDelegate.h \
  $$SRC_DIR/pqObjectBuilder.h \
  $$SRC_DIR/pqOptions.h \
  $$SRC_DIR/pqOutputPort.h \
  $$SRC_DIR/pqOutputWidget.h \
  $$SRC_DIR/pqParallelCoordinatesChartView.h \
  $$SRC_DIR/pqPipelineFilter.h \
  $$SRC_DIR/pqPipelineRepresentation.h \
  $$SRC_DIR/pqPipelineSource.h \
  $$SRC_DIR/pqPlotMatrixView.h \
  $$SRC_DIR/pqPlugin.h \
  $$SRC_DIR/pqPluginManager.h \
  $$SRC_DIR/pqProgressManager.h \
  $$SRC_DIR/pqPropertyLinks.h \
  $$SRC_DIR/pqPropertyLinksConnection.h \
  $$SRC_DIR/pqPropertyManager.h \
  $$SRC_DIR/pqProxy.h \
  $$SRC_DIR/pqProxyModifiedStateUndoElement.h \
  $$SRC_DIR/pqProxySelection.h \
  $$SRC_DIR/pqPythonEventSourceImage.h \
  $$SRC_DIR/pqPythonView.h \
  $$SRC_DIR/pqQVTKWidget.h \
  $$SRC_DIR/pqQVTKWidgetBase.h \
  $$SRC_DIR/pqQVTKWidgetEventPlayer.h \
  $$SRC_DIR/pqQVTKWidgetEventTranslator.h \
  $$SRC_DIR/pqRecentlyUsedResourceLoaderInterface.h \
  $$SRC_DIR/pqRecentlyUsedResourcesList.h \
  $$SRC_DIR/pqRenderView.h \
  $$SRC_DIR/pqRenderViewBase.h \
  $$SRC_DIR/pqRepresentation.h \
  $$SRC_DIR/pqSMAdaptor.h \
  $$SRC_DIR/pqSMProxy.h \
  $$SRC_DIR/pqScalarBarRepresentation.h \
  $$SRC_DIR/pqScalarsToColors.h \
  $$SRC_DIR/pqServer.h \
  $$SRC_DIR/pqServerConfiguration.h \
  $$SRC_DIR/pqServerConfigurationCollection.h \
  $$SRC_DIR/pqServerManagerModel.h \
  $$SRC_DIR/pqServerManagerModelInterface.h \
  $$SRC_DIR/pqServerManagerModelItem.h \
  $$SRC_DIR/pqServerManagerObserver.h \
  $$SRC_DIR/pqServerResource.h \
  $$SRC_DIR/pqSettings.h \
  $$SRC_DIR/pqSpreadSheetView.h \
  $$SRC_DIR/pqSpreadSheetViewModel.h \
  $$SRC_DIR/pqSpreadSheetViewSelectionModel.h \
  $$SRC_DIR/pqSpreadSheetViewWidget.h \
  $$SRC_DIR/pqStandardServerManagerModelInterface.h \
  $$SRC_DIR/pqTimeKeeper.h \
  $$SRC_DIR/pqTreeLayoutStrategyInterface.h \
  $$SRC_DIR/pqUndoStack.h \
  $$SRC_DIR/pqView.h \
  $$SRC_DIR/pqXMLEventObserver.h \
  $$SRC_DIR/pqXMLEventSource.h \
  $$SRC_DIR/pqXMLUtil.h \
  $$SRC_DIR/pqXYBarChartView.h \
  $$SRC_DIR/pqXYChartView.h \
  $$SRC_DIR/pqXYHistogramChartView.h \
  $$SRC_DIR/vtkPVGUIPluginInterface.h

SOURCES += \
  $$SRC_DIR/pqAnimationCue.cxx \
  $$SRC_DIR/pqAnimationScene.cxx \
  $$SRC_DIR/pqApplicationCore.cxx \
  $$SRC_DIR/pqAutoStartInterface.cxx \
  $$SRC_DIR/pqBoxChartView.cxx \
  $$SRC_DIR/pqCheckBoxDelegate.cxx \
  $$SRC_DIR/pqCollaborationEventPlayer.cxx \
  \# $$SRC_DIR/Core/pqCollaborationManager.cxx \
  $$SRC_DIR/pqComparativeContextView.cxx \
  $$SRC_DIR/pqComparativeRenderView.cxx \
  $$SRC_DIR/pqComparativeXYBarChartView.cxx \
  $$SRC_DIR/pqComparativeXYChartView.cxx \
  $$SRC_DIR/pqContextView.cxx \
  $$SRC_DIR/pqCoreInit.cxx \
  \# $$SRC_DIR/Core/pqCoreTestUtility.cxx \
  $$SRC_DIR/pqCoreUtilities.cxx \
  $$SRC_DIR/pqDataRepresentation.cxx \
  $$SRC_DIR/pqDebug.cxx \
  $$SRC_DIR/pqExtractor.cxx \
  $$SRC_DIR/pqFileDialog.cxx \
  $$SRC_DIR/pqFileDialogEventPlayer.cxx \
  $$SRC_DIR/pqFileDialogEventTranslator.cxx \
  $$SRC_DIR/pqFileDialogFavoriteModel.cxx \
  $$SRC_DIR/pqFileDialogFilter.cxx \
  $$SRC_DIR/pqFileDialogModel.cxx \
  $$SRC_DIR/pqFileDialogRecentDirsModel.cxx \
  $$SRC_DIR/pqFlatTreeViewEventPlayer.cxx \
  $$SRC_DIR/pqFlatTreeViewEventTranslator.cxx \
  $$SRC_DIR/pqGraphLayoutStrategyInterface.cxx \
  $$SRC_DIR/pqImageUtil.cxx \
  $$SRC_DIR/pqInteractiveViewLink.cxx \
  $$SRC_DIR/pqInterfaceTracker.cxx \
  $$SRC_DIR/pqLinkViewWidget.cxx \
  $$SRC_DIR/pqLinksModel.cxx \
  $$SRC_DIR/pqLogViewerWidget.cxx \
  $$SRC_DIR/pqMainWindowEventManager.cxx \
  $$SRC_DIR/pqMultiSliceAxisWidget.cxx \
  $$SRC_DIR/pqMultiSliceView.cxx \
  $$SRC_DIR/pqNonEditableStyledItemDelegate.cxx \
  $$SRC_DIR/pqObjectBuilder.cxx \
  $$SRC_DIR/pqOptions.cxx \
  $$SRC_DIR/pqOutputPort.cxx \
  $$SRC_DIR/pqOutputWidget.cxx \
  $$SRC_DIR/pqParallelCoordinatesChartView.cxx \
  $$SRC_DIR/pqPipelineFilter.cxx \
  $$SRC_DIR/pqPipelineRepresentation.cxx \
  $$SRC_DIR/pqPipelineSource.cxx \
  $$SRC_DIR/pqPlotMatrixView.cxx \
  $$SRC_DIR/pqPluginManager.cxx \
  $$SRC_DIR/pqProgressManager.cxx \
  $$SRC_DIR/pqPropertyLinks.cxx \
  $$SRC_DIR/pqPropertyLinksConnection.cxx \
  $$SRC_DIR/pqPropertyManager.cxx \
  $$SRC_DIR/pqProxy.cxx \
  $$SRC_DIR/pqProxyModifiedStateUndoElement.cxx \
  $$SRC_DIR/pqProxySelection.cxx \
  \# $$SRC_DIR/Core/pqPythonEventSourceImage.cxx \
  $$SRC_DIR/pqPythonView.cxx \
  $$SRC_DIR/pqQVTKWidget.cxx \
  $$SRC_DIR/pqQVTKWidgetEventPlayer.cxx \
  $$SRC_DIR/pqQVTKWidgetEventTranslator.cxx \
  $$SRC_DIR/pqRecentlyUsedResourceLoaderInterface.cxx \
  $$SRC_DIR/pqRecentlyUsedResourcesList.cxx \
  $$SRC_DIR/pqRenderView.cxx \
  $$SRC_DIR/pqRenderViewBase.cxx \
  $$SRC_DIR/pqRepresentation.cxx \
  $$SRC_DIR/pqSMAdaptor.cxx \
  $$SRC_DIR/pqSMProxy.cxx \
  $$SRC_DIR/pqScalarBarRepresentation.cxx \
  $$SRC_DIR/pqScalarsToColors.cxx \
  $$SRC_DIR/pqServer.cxx \
  $$SRC_DIR/pqServerConfiguration.cxx \
  $$SRC_DIR/pqServerConfigurationCollection.cxx \
  $$SRC_DIR/pqServerManagerModel.cxx \
  $$SRC_DIR/pqServerManagerModelInterface.cxx \
  $$SRC_DIR/pqServerManagerModelItem.cxx \
  $$SRC_DIR/pqServerManagerObserver.cxx \
  $$SRC_DIR/pqServerResource.cxx \
  $$SRC_DIR/pqSettings.cxx \
  $$SRC_DIR/pqSpreadSheetView.cxx \
  $$SRC_DIR/pqSpreadSheetViewModel.cxx \
  $$SRC_DIR/pqSpreadSheetViewSelectionModel.cxx \
  $$SRC_DIR/pqSpreadSheetViewWidget.cxx \
  $$SRC_DIR/pqStandardServerManagerModelInterface.cxx \
  $$SRC_DIR/pqTimeKeeper.cxx \
  $$SRC_DIR/pqTreeLayoutStrategyInterface.cxx \
  $$SRC_DIR/pqUndoStack.cxx \
  $$SRC_DIR/pqView.cxx \
  \# $$SRC_DIR/Core/pqXMLEventObserver.cxx \
  \# $$SRC_DIR/Core/pqXMLEventSource.cxx \
  $$SRC_DIR/pqXMLUtil.cxx \
  $$SRC_DIR/pqXYBarChartView.cxx \
  $$SRC_DIR/pqXYChartView.cxx \
  $$SRC_DIR/pqXYHistogramChartView.cxx \
  $$SRC_DIR/vtkPVGUIPluginInterface.cxx \


LIBS += -lpython2.7
