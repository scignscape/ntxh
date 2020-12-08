
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += widgets network

QT += help


include(../build-group.pri)

TEMPLATE = app

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


INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-Clients/ParaView


SOURCES +=  \
  $$SRC_DIR/ParaView/paraview_main.cxx  \
  $$SRC_DIR/ParaView/pqparaviewInitializer.cxx  \


HEADERS +=  \
  $$SRC_DIR/ParaView/pqparaviewInitializer.h


LIBS += -L$$TARGETSDIR -lParaview-Clients  #-lParaview-Qt

message(T: $$TARGETSDIR)

LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libpqApplicationComponents-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libpqComponents-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libpqCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libpqWidgets-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkcgns-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkChartsCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkClientServer-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonColor-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonComputationalGeometry-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonDataModel-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonExecutionModel-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonMath-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonMisc-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonSystem-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkCommonTransforms-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkDICOMParser-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkDomainsChemistry-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkdoubleconversion-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkexodusII-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkexpat-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersAMR-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersExtraction-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersFlowPaths-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersGeneral-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersGeneric-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersGeometry-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersHybrid-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersHyperTree-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersModeling-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersParallel-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersParallelStatistics-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersPoints-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersProgrammable-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersSources-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersStatistics-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersTexture-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkFiltersVerdict-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkfreetype-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkgl2ps-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkglew-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkGUISupportQt-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkh5part-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingColor-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingFourier-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingGeneral-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingHybrid-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingMath-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkImagingSources-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkInfovisCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkInteractionStyle-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkInteractionWidgets-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOAMR-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOAsynchronous-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOEnSight-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOExodus-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOExportGL2PS-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOExport-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOGeometry-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOH5part-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOImage-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOImport-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOInfovis-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOLegacy-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOLSDyna-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOMotionFX-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOMovie-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIONetCDF-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOParallelExodus-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOParallelLSDyna-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOParallel-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOParallelXML-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOPLY-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOSegY-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOTecplotTable-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOTRUCHAS-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOVeraOut-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOVPIC-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOXdmf2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOXMLParser-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkIOXML-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkjpeg-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkjsoncpp-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtklibharu-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtklibprotoc-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtklibxml2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkloguru-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtklz4-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtklzma-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkmetaio-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtknetcdf-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkParallelCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkpng-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkprotobuf-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkpugixml-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVAnimation-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVCatalyst-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVClientServerCoreCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVClientServerCoreDefault-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVClientServerCoreRendering-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVServerImplementationCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVServerImplementationRendering-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVServerManagerApplication-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVServerManagerCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVServerManagerDefault-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVServerManagerRendering-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVVTKExtensionsCGNSReader-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVVTKExtensionsCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVVTKExtensionsDefault-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVVTKExtensionsPoints-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVVTKExtensionsRendering-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkPVVTKExtensionsSIL-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkqttesting-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingAnnotation-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingContext2D-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingContextOpenGL2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingFreeType-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingGL2PSOpenGL2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingLabel-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingLICOpenGL2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingOpenGL2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingParallel-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingVolumeAMR-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingVolumeOpenGL2-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkRenderingVolume-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtksys-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkTestingRendering-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtktiff-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkverdict-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkViewsContext2D-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkViewsCore-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkvpic-pv5.7.so.5.7
LIBS += /home/nlevisrael/pv/pvsbb/install/lib/libvtkxdmf2-pv5.7.so.5.7


LIBS += /usr/lib/x86_64-linux-gnu/libpng16.so.16

