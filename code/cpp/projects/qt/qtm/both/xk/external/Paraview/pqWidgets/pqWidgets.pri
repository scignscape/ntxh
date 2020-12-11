
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
  $$SRC_DIR/Resources/UI/pqSeriesGeneratorDialog.ui \
  $$SRC_DIR/Resources/UI/pqExpanderButton.ui \
  $$SRC_DIR/Resources/UI/pqHelpWindow.ui \
  $$SRC_DIR/Resources/UI/pqQuickLaunchDialog.ui \


INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Core
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/FiltersRendering

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Remoting/ViewsPython



INCLUDEPATH += $$SRC_DIR/Components  $$SRC_DIR/Core \
  $$SRC_DIR \



#include($$ROOT_DIR/../preferred/itk.pri)
#include($$ROOT_DIR/../preferred/vtk.pri)

include($$ROOT_DIR/../preferred/paraview.pri)



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
  $$SRC_DIR/pqAnimationKeyFrame.h \
  $$SRC_DIR/pqAnimationModel.h \
  $$SRC_DIR/pqAnimationTrack.h \
  $$SRC_DIR/pqAnimationWidget.h \
  $$SRC_DIR/pqCheckBoxPixMaps.h \
  $$SRC_DIR/pqCheckableHeaderView.h \
  $$SRC_DIR/pqCollapsedGroup.h \
  $$SRC_DIR/pqColorButtonEventPlayer.h \
  $$SRC_DIR/pqColorButtonEventTranslator.h \
  $$SRC_DIR/pqColorChooserButton.h \
  $$SRC_DIR/pqColorDialogEventPlayer.h \
  $$SRC_DIR/pqColorDialogEventTranslator.h \
  $$SRC_DIR/pqConnect.h \
  $$SRC_DIR/pqConsoleWidget.h \
  $$SRC_DIR/pqConsoleWidgetEventPlayer.h \
  $$SRC_DIR/pqConsoleWidgetEventTranslator.h \
  $$SRC_DIR/pqDelimitedTextParser.h \
  $$SRC_DIR/pqDiscreteDoubleWidget.h \
  $$SRC_DIR/pqDoubleLineEdit.h \
  $$SRC_DIR/pqDoubleRangeDialog.h \
  $$SRC_DIR/pqDoubleRangeWidget.h \
  $$SRC_DIR/pqDoubleSliderWidget.h \
  $$SRC_DIR/pqDoubleSpinBox.h \
  $$SRC_DIR/pqExpandableTableView.h \
  $$SRC_DIR/pqExpanderButton.h \
  $$SRC_DIR/pqFlatTreeView.h \
  $$SRC_DIR/pqHeaderView.h \
  $$SRC_DIR/pqHelpWindow.h \
  $$SRC_DIR/pqHelpWindowNoWebEngine.h \
  $$SRC_DIR/pqHelpWindowWebEngine.h \
  $$SRC_DIR/pqHierarchicalGridLayout.h \
  $$SRC_DIR/pqHierarchicalGridWidget.h \
  $$SRC_DIR/pqHighlightablePushButton.h \
  $$SRC_DIR/pqHighlightableToolButton.h \
  $$SRC_DIR/pqLineEdit.h \
  $$SRC_DIR/pqLineEditEventPlayer.h \
  $$SRC_DIR/pqListWidgetCheckHelper.h \
  $$SRC_DIR/pqListWidgetItemObject.h \
  $$SRC_DIR/pqMultiColumnHeaderView.h \
  $$SRC_DIR/pqProgressWidget.h \
  $$SRC_DIR/pqQuickLaunchDialog.h \
  $$SRC_DIR/pqScaleByButton.h \
  $$SRC_DIR/pqSectionVisibilityContextMenu.h \
  $$SRC_DIR/pqSeriesGeneratorDialog.h \
  $$SRC_DIR/pqSetData.h \
  $$SRC_DIR/pqSetName.h \
  $$SRC_DIR/pqSignalAdaptors.h \
  $$SRC_DIR/pqSpinBox.h \
  $$SRC_DIR/pqTableView.h \
  $$SRC_DIR/pqTextEdit.h \
  $$SRC_DIR/pqTimelineScrollbar.h \
  $$SRC_DIR/pqTreeView.h \
  $$SRC_DIR/pqTreeViewExpandState.h \
  $$SRC_DIR/pqTreeViewSelectionHelper.h \
  $$SRC_DIR/pqTreeWidget.h \
  $$SRC_DIR/pqTreeWidgetCheckHelper.h \
  $$SRC_DIR/pqTreeWidgetItem.h \
  $$SRC_DIR/pqTreeWidgetItemObject.h \
  $$SRC_DIR/pqTreeWidgetSelectionHelper.h \
  $$SRC_DIR/pqWaitCursor.h

SOURCES += \
  $$SRC_DIR/pqAnimationKeyFrame.cxx \
  $$SRC_DIR/pqAnimationModel.cxx \
  $$SRC_DIR/pqAnimationTrack.cxx \
  $$SRC_DIR/pqAnimationWidget.cxx \
  $$SRC_DIR/pqCheckBoxPixMaps.cxx \
  $$SRC_DIR/pqCheckableHeaderView.cxx \
  $$SRC_DIR/pqCollapsedGroup.cxx \
  $$SRC_DIR/pqColorButtonEventPlayer.cxx \
  $$SRC_DIR/pqColorButtonEventTranslator.cxx \
  $$SRC_DIR/pqColorChooserButton.cxx \
  $$SRC_DIR/pqColorDialogEventPlayer.cxx \
  $$SRC_DIR/pqColorDialogEventTranslator.cxx \
  $$SRC_DIR/pqConnect.cxx \
  $$SRC_DIR/pqConsoleWidget.cxx \
  $$SRC_DIR/pqConsoleWidgetEventPlayer.cxx \
  $$SRC_DIR/pqConsoleWidgetEventTranslator.cxx \
  $$SRC_DIR/pqDelimitedTextParser.cxx \
  $$SRC_DIR/pqDiscreteDoubleWidget.cxx \
  $$SRC_DIR/pqDoubleLineEdit.cxx \
  $$SRC_DIR/pqDoubleRangeDialog.cxx \
  $$SRC_DIR/pqDoubleRangeWidget.cxx \
  $$SRC_DIR/pqDoubleSliderWidget.cxx \
  $$SRC_DIR/pqDoubleSpinBox.cxx \
  $$SRC_DIR/pqExpandableTableView.cxx \
  $$SRC_DIR/pqExpanderButton.cxx \
  $$SRC_DIR/pqFlatTreeView.cxx \
  $$SRC_DIR/pqHeaderView.cxx \
  $$SRC_DIR/pqHelpWindow.cxx \
  $$SRC_DIR/pqHierarchicalGridLayout.cxx \
  $$SRC_DIR/pqHierarchicalGridWidget.cxx \
  $$SRC_DIR/pqHighlightablePushButton.cxx \
  $$SRC_DIR/pqHighlightableToolButton.cxx \
  $$SRC_DIR/pqLineEdit.cxx \
  $$SRC_DIR/pqLineEditEventPlayer.cxx \
  $$SRC_DIR/pqListWidgetCheckHelper.cxx \
  $$SRC_DIR/pqListWidgetItemObject.cxx \
  $$SRC_DIR/pqMultiColumnHeaderView.cxx \
  $$SRC_DIR/pqProgressWidget.cxx \
  $$SRC_DIR/pqQuickLaunchDialog.cxx \
  $$SRC_DIR/pqScaleByButton.cxx \
  $$SRC_DIR/pqSectionVisibilityContextMenu.cxx \
  $$SRC_DIR/pqSeriesGeneratorDialog.cxx \
  $$SRC_DIR/pqSetData.cxx \
  $$SRC_DIR/pqSetName.cxx \
  $$SRC_DIR/pqSignalAdaptors.cxx \
  $$SRC_DIR/pqSpinBox.cxx \
  $$SRC_DIR/pqTableView.cxx \
  $$SRC_DIR/pqTextEdit.cxx \
  $$SRC_DIR/pqTimelineScrollbar.cxx \
  $$SRC_DIR/pqTreeView.cxx \
  $$SRC_DIR/pqTreeViewExpandState.cxx \
  $$SRC_DIR/pqTreeViewSelectionHelper.cxx \
  $$SRC_DIR/pqTreeWidget.cxx \
  $$SRC_DIR/pqTreeWidgetCheckHelper.cxx \
  $$SRC_DIR/pqTreeWidgetItem.cxx \
  $$SRC_DIR/pqTreeWidgetItemObject.cxx \
  $$SRC_DIR/pqTreeWidgetSelectionHelper.cxx \
  $$SRC_DIR/pqWaitCursor.cxx



#SOURCES += \
#  $$SRC_DIR/stubs.cpp

LIBS += -lpython2.7
