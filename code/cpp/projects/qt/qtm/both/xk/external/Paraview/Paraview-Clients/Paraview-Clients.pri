
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += widgets network

QT += help


include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)


include($$ROOT_DIR/../preferred/vtk.pri)

INCLUDEPATH += $$VTK_SRC_DIR/Common/Core

INCLUDEPATH += $$VTK_BUILD_DIR/Common/Core


INCLUDEPATH += $$VTK_SRC_DIR/IO/EnSight
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/FreeType
INCLUDEPATH += $$VTK_SRC_DIR/Common/Core
INCLUDEPATH += $$VTK_SRC_DIR/IO/Legacy
INCLUDEPATH += $$VTK_SRC_DIR/IO/ExportGL2PS
INCLUDEPATH += $$VTK_SRC_DIR/IO/Export
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Annotation
INCLUDEPATH += $$VTK_SRC_DIR/Imaging/Core
INCLUDEPATH += $$VTK_SRC_DIR/Interaction/Widgets
INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/glew
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/VolumeAMR
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/OpenGL2
INCLUDEPATH += $$VTK_SRC_DIR/Common/Transforms
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Parallel
INCLUDEPATH += $$VTK_SRC_DIR/Filters/General
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Label
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/ContextOpenGL2
INCLUDEPATH += $$VTK_SRC_DIR/Parallel/MPI
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/MPI
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/VolumeOpenGL2
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Volume
INCLUDEPATH += $$VTK_SRC_DIR/Domains/Chemistry
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Parallel
INCLUDEPATH += $$VTK_SRC_DIR/Imaging/Sources
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Generic
INCLUDEPATH += $$VTK_SRC_DIR/Filters/HyperTree
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Arm
INCLUDEPATH += $$VTK_SRC_DIR/Filters/AMR
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Geometry
INCLUDEPATH += $$VTK_SRC_DIR/Filters/ParallelFlowPaths
INCLUDEPATH += $$VTK_SRC_DIR/Filters/FlowPaths
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Programmable
INCLUDEPATH += $$VTK_SRC_DIR/IO/AMR
INCLUDEPATH += $$VTK_SRC_DIR/IO/ParallelXML
INCLUDEPATH += $$VTK_SRC_DIR/IO/ParallelExodus



INCLUDEPATH += $$VTK_BUILD_DIR/IO/ParallelXML
INCLUDEPATH += $$VTK_BUILD_DIR/IO/EnSight
INCLUDEPATH += $$VTK_BUILD_DIR/IO/AMR
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Programmable
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/ParallelFlowPaths
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/FlowPaths
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Geometry
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/AMR
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/HyperTree
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Generic
INCLUDEPATH += $$VTK_BUILD_DIR/Imaging/Sources
INCLUDEPATH += $$VTK_BUILD_DIR/Domains/Chemistry
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Volume
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/VolumeOpenGL2
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/General
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Parallel
INCLUDEPATH += $$VTK_BUILD_DIR/Interaction/Widgets
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/GL2PSOpenGL2
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Annotation
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Legacy
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Export
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/FreeType
INCLUDEPATH += $$VTK_BUILD_DIR/IO/ExportGL2PS
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/doubleconversion
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/glew
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Math
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Label


INCLUDEPATH += $$VTK_BUILD_DIR/Common/ComputationalGeometry
INCLUDEPATH += $$VTK_BUILD_DIR/Interaction/Style
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/OpenGL2
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/UI
INCLUDEPATH += $$VTK_BUILD_DIR/Charts/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Context2D
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/jsoncpp
INCLUDEPATH += $$VTK_BUILD_DIR/Imaging/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Transforms
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/ContextOpenGL2


INCLUDEPATH += $$VTK_BUILD_DIR/IO/Image
INCLUDEPATH += $$VTK_BUILD_DIR/Parallel/Core

INCLUDEPATH += $$VTK_BUILD_DIR/Utilities/PythonInterpreter


INCLUDEPATH += $$VTK_SRC_DIR/IO/Image
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/PythonInterpreter

INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/pugixml
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/pugixml
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/pugixml/vtkpugixml


#INCLUDEPATH += /home/nlevisrael/sebi-libs/VTK-Build/Interaction/Style


INCLUDEPATH += $$VTK_SRC_DIR/Common/Core
INCLUDEPATH += $$VTK_SRC_DIR/Interaction/Style
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
INCLUDEPATH += $$VTK_SRC_DIR/IO/Image
INCLUDEPATH += $$VTK_SRC_DIR/Parallel/Core
INCLUDEPATH += $$VTK_SRC_DIR/Testing/Core
INCLUDEPATH += $$VTK_SRC_DIR/Testing/Rendering
INCLUDEPATH += $$VTK_SRC_DIR/Filters/ParallelDIY2
INCLUDEPATH += $$VTK_SRC_DIR/Parallel/DIY
INCLUDEPATH += $$VTK_SRC_DIR/Imaging/Morphological
INCLUDEPATH += $$VTK_SRC_DIR/Imaging/General
INCLUDEPATH += $$VTK_SRC_DIR/Interaction/Image


INCLUDEPATH += $$VTK_BUILD_DIR/Interaction/Image
INCLUDEPATH += $$VTK_BUILD_DIR/Imaging/Morphological
INCLUDEPATH += $$VTK_BUILD_DIR/Imaging/General
INCLUDEPATH += $$VTK_BUILD_DIR/Parallel/DIY
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Common/DataModel
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/jsoncpp/vtkjsoncpp/json
INCLUDEPATH += $$VTK_BUILD_DIR/Views/Core
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Views/Context2D
INCLUDEPATH += $$VTK_BUILD_DIR/Utilities/KWSys
INCLUDEPATH += $$VTK_BUILD_DIR/Common/ExecutionModel
INCLUDEPATH += $$VTK_BUILD_DIR/IO/XMLParser
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Misc
INCLUDEPATH += $$VTK_BUILD_DIR/IO/XML
INCLUDEPATH += $$VTK_BUILD_DIR/Common/System
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Movie
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Sources
INCLUDEPATH += $$VTK_BUILD_DIR/Testing/Rendering
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/diy2
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Parallel
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Exodus
INCLUDEPATH += $$VTK_BUILD_DIR/IO/PLY
INCLUDEPATH += $$VTK_BUILD_DIR/IO/ParallelExodus
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/netcdf
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Import


INCLUDEPATH += $$VTK_SRC_DIR/IO/Import
INCLUDEPATH += $$VTK_SRC_DIR/IO/Exodus
INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/diy2
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/KWIML
INCLUDEPATH += $$VTK_SRC_DIR/GUISupport/Qt
INCLUDEPATH += $$VTK_SRC_DIR/IO/XML
INCLUDEPATH += $$VTK_SRC_DIR/IO/Imaging
INCLUDEPATH += $$VTK_SRC_DIR/IO/Movie
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/Python
INCLUDEPATH += $$VTK_SRC_DIR/Common/System
INCLUDEPATH += $$VTK_SRC_DIR/IO/PLY
INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/netcdf




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


INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Core/

DEFINES += VTK_LEGACY\\(x\\)=x

INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Qt/Components/
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Qt/ApplicationComponents/
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Qt/Core
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Qt/Widgets


FORMS += \
  $$SRC_DIR/ParaView/ParaViewMainWindow.ui


SOURCES +=  \ 
  $$SRC_DIR/ParaView/ParaViewMainWindow.cxx  \

#$$SRC_DIR/ParaView/ParaViewVRUI.cxx  \



HEADERS += \ 
  $$SRC_DIR/ParaView/ParaViewMainWindow.h   \

#LIBS += -L$$TARGETSDIR -lParaview-Qt


