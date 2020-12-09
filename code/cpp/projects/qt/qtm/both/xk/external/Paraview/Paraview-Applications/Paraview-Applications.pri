
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


#FORMS +=  \
#  $$SRC_DIR/ParaView/ParaViewMainWindow.ui \


SOURCES +=  \
  $$SRC_DIR/ParaView/paraview_main.cxx  \
  $$SRC_DIR/ParaView/pqparaviewInitializer.cxx  \

#$$SRC_DIR/ParaView/ParaViewMainWindow.cxx \


#HEADERS +=  \
#  $$SRC_DIR/ParaView/ParaViewMainWindow.h \



HEADERS +=  \
  $$SRC_DIR/ParaView/pqparaviewInitializer.h


LIBS += -L$$TARGETSDIR  -lParaview-Clients  -lParaview-Qt

#LIBS += -L$$TARGETSDIR

LIBS +=  $$PV_ALT_LIB_DIR/libpqApplicationComponents-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libpqComponents-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libpqCore-pv5.7.so.5.7

#LIBS +=  $$PV_ALT_LIB_DIR/libpqWidgets-pv5.7.so.5.7




LIBS +=  $$PV_ALT_LIB_DIR/libvtkcgns-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkChartsCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkClientServer-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonColor-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonComputationalGeometry-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonDataModel-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonExecutionModel-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonMath-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonMisc-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonSystem-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkCommonTransforms-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkDICOMParser-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkDomainsChemistry-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkdoubleconversion-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkexodusII-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkexpat-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersAMR-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersExtraction-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersFlowPaths-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersGeneral-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersGeneric-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersGeometry-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersHybrid-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersHyperTree-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersModeling-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersParallel-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersParallelStatistics-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersPoints-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersProgrammable-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersSources-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersStatistics-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersTexture-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkFiltersVerdict-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkfreetype-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkgl2ps-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkglew-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkGUISupportQt-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkh5part-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingColor-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingFourier-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingGeneral-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingHybrid-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingMath-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkImagingSources-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkInfovisCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkInteractionStyle-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkInteractionWidgets-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOAMR-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOAsynchronous-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOEnSight-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOExodus-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOExportGL2PS-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOExport-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOGeometry-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOH5part-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOImage-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOImport-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOInfovis-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOLegacy-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOLSDyna-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOMotionFX-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOMovie-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIONetCDF-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOParallelExodus-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOParallelLSDyna-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOParallel-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOParallelXML-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOPLY-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOSegY-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOTecplotTable-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOTRUCHAS-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOVeraOut-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOVPIC-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOXdmf2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOXMLParser-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkIOXML-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkjpeg-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkjsoncpp-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtklibharu-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtklibprotoc-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtklibxml2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkloguru-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtklz4-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtklzma-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkmetaio-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtknetcdf-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkParallelCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkpng-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkprotobuf-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkpugixml-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVAnimation-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVCatalyst-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVClientServerCoreCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVClientServerCoreDefault-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVClientServerCoreRendering-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVServerImplementationCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVServerImplementationRendering-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVServerManagerApplication-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVServerManagerCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVServerManagerDefault-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVServerManagerRendering-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVVTKExtensionsCGNSReader-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVVTKExtensionsCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVVTKExtensionsDefault-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVVTKExtensionsPoints-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVVTKExtensionsRendering-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkPVVTKExtensionsSIL-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkqttesting-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingAnnotation-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingContext2D-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingContextOpenGL2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingFreeType-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingGL2PSOpenGL2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingLabel-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingLICOpenGL2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingOpenGL2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingParallel-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingVolumeAMR-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingVolumeOpenGL2-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkRenderingVolume-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtksys-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkTestingRendering-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtktiff-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkverdict-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkViewsContext2D-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkViewsCore-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkvpic-pv5.7.so.5.7
LIBS +=  $$PV_ALT_LIB_DIR/libvtkxdmf2-pv5.7.so.5.7


LIBS += /usr/lib/x86_64-linux-gnu/libpng16.so.16

