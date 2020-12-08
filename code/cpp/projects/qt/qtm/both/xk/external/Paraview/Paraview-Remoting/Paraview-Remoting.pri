
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += widgets network

QT += help

QT += testlib

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

#?QMAKE_CXXFLAGS += mpic++

include($$ROOT_DIR/../preferred/vtk.pri)



INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/Animation
INCLUDEPATH += $$SRC_DIR/Application

INCLUDEPATH += $$SRC_GROUP_DIR/icet/src/include


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



INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/diy2
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/KWIML
INCLUDEPATH += $$VTK_SRC_DIR/GUISupport/Qt
INCLUDEPATH += $$VTK_SRC_DIR/IO/XML
INCLUDEPATH += $$VTK_SRC_DIR/IO/Imaging
INCLUDEPATH += $$VTK_SRC_DIR/IO/Movie
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/Python
INCLUDEPATH += $$VTK_SRC_DIR/Common/System/


# maybe want this in preferred ...
INCLUDEPATH += /usr/include/python2.7

INCLUDEPATH += $$VTK_SRC_DIR/Common/ComputationalGeometry
INCLUDEPATH += $$VTK_SRC_DIR/Wrapping/PythonCore
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Sources
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Extraction
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Modeling
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/UI


INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Modeling
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Extraction
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/pugixml




INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Core
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/FiltersRendering
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/IOCore
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Misc
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/IOGeneral
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/Extraction
INCLUDEPATH += $$SRC_GROUP_DIR/Paraview-VTKExtensions/InteractionStyle/


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



DISTFILES += \
  $$SRC_DIR/Animation/Resources/animation.xml \
  $$SRC_DIR/Animation/Resources/animation_ffmpeg.xml \
  $$SRC_DIR/Animation/Resources/animation_oggtheora.xml \
  $$SRC_DIR/Animation/Resources/animation_python.xml \
  $$SRC_DIR/Animation/Resources/animation_win.xml \
  $$SRC_DIR/Animation/Resources/writers_animation.xml \
  $$SRC_DIR/Animation/Testing/CMakeLists.txt \
  $$SRC_DIR/Animation/Testing/Cxx/CMakeLists.txt \
  $$SRC_DIR/Animation/vtk.module \
  $$SRC_DIR/Application/CMakeLists.txt \
  $$SRC_DIR/Application/Resources/MomentInvariants.xml \
  $$SRC_DIR/Application/Resources/ParallelMomentInvariants.xml \
  $$SRC_DIR/Application/Resources/extractors.xml \
  $$SRC_DIR/Application/Resources/filters_domainschemistry.xml \
  $$SRC_DIR/Application/Resources/filters_filtersamr.xml \
  $$SRC_DIR/Application/Resources/filters_filterscore.xml \
  $$SRC_DIR/Application/Resources/filters_filtersextraction.xml \
  $$SRC_DIR/Application/Resources/filters_filtersflowpaths.xml \
  $$SRC_DIR/Application/Resources/filters_filtersgeneral.xml \
  $$SRC_DIR/Application/Resources/filters_filtersgeneric.xml \
  $$SRC_DIR/Application/Resources/filters_filtersgeometry.xml \
  $$SRC_DIR/Application/Resources/filters_filtershybrid.xml \
  $$SRC_DIR/Application/Resources/filters_filtershypertree.xml \
  $$SRC_DIR/Application/Resources/filters_filtersmodeling.xml \
  $$SRC_DIR/Application/Resources/filters_filtersparallel.xml \
  $$SRC_DIR/Application/Resources/filters_filtersparalleldiy2.xml \
  $$SRC_DIR/Application/Resources/filters_filtersparallelmpi.xml \
  $$SRC_DIR/Application/Resources/filters_filtersparallelverdict.xml \
  $$SRC_DIR/Application/Resources/filters_filtersstatistics.xml \
  $$SRC_DIR/Application/Resources/filters_filterstexture.xml \
  $$SRC_DIR/Application/Resources/filters_filtersverdict.xml \
  $$SRC_DIR/Application/Resources/filters_imagingcore.xml \
  $$SRC_DIR/Application/Resources/filters_imagingfourier.xml \
  $$SRC_DIR/Application/Resources/filters_imaginggeneral.xml \
  $$SRC_DIR/Application/Resources/filters_imaginghybrid.xml \
  $$SRC_DIR/Application/Resources/filters_normalglyphs.xml \
  $$SRC_DIR/Application/Resources/filters_plotonintersectioncurves.xml \
  $$SRC_DIR/Application/Resources/filters_selectionfftovertime.xml \
  $$SRC_DIR/Application/Resources/internal_writers.xml \
  $$SRC_DIR/Application/Resources/proxies_adios2_core.xml \
  $$SRC_DIR/Application/Resources/proxies_adios2_vtx.xml \
  $$SRC_DIR/Application/Resources/proxies_citygml.xml \
  $$SRC_DIR/Application/Resources/proxies_computationalgeometry.xml \
  $$SRC_DIR/Application/Resources/proxies_fides.xml \
  $$SRC_DIR/Application/Resources/proxies_gdal.xml \
  $$SRC_DIR/Application/Resources/proxies_interactionwidgets.xml \
  $$SRC_DIR/Application/Resources/proxies_las.xml \
  $$SRC_DIR/Application/Resources/proxies_motionfx.xml \
  $$SRC_DIR/Application/Resources/proxies_openturns.xml \
  $$SRC_DIR/Application/Resources/proxies_pdal.xml \
  $$SRC_DIR/Application/Resources/proxies_segy.xml \
  $$SRC_DIR/Application/Resources/proxies_xdmf2.xml \
  $$SRC_DIR/Application/Resources/proxies_xdmf3.xml \
  $$SRC_DIR/Application/Resources/pythonviews.xml \
  $$SRC_DIR/Application/Resources/readers_domainschemistry.xml \
  $$SRC_DIR/Application/Resources/readers_filtershybrid.xml \
  $$SRC_DIR/Application/Resources/readers_ioconvergecfd.xml \
  $$SRC_DIR/Application/Resources/readers_iogeometry.xml \
  $$SRC_DIR/Application/Resources/readers_ioh5part.xml \
  $$SRC_DIR/Application/Resources/readers_ioinfovis.xml \
  $$SRC_DIR/Application/Resources/readers_ioioss.xml \
  $$SRC_DIR/Application/Resources/readers_ionetcdf.xml \
  $$SRC_DIR/Application/Resources/readers_ioparallel.xml \
  $$SRC_DIR/Application/Resources/readers_ioparallelnetcdf.xml \
  $$SRC_DIR/Application/Resources/readers_iopio.xml \
  $$SRC_DIR/Application/Resources/readers_ioply.xml \
  $$SRC_DIR/Application/Resources/readers_iotecplottable.xml \
  $$SRC_DIR/Application/Resources/readers_iotruchas.xml \
  $$SRC_DIR/Application/Resources/readers_ioveraout.xml \
  $$SRC_DIR/Application/Resources/readers_iovpic.xml \
  $$SRC_DIR/Application/Resources/readers_ioxml.xml \
  $$SRC_DIR/Application/Resources/readers_lsdyna.xml \
  $$SRC_DIR/Application/Resources/readers_openpmd.xml \
  $$SRC_DIR/Application/Resources/sources_filtersamr.xml \
  $$SRC_DIR/Application/Resources/sources_filterscore.xml \
  $$SRC_DIR/Application/Resources/sources_filtersgeneral.xml \
  $$SRC_DIR/Application/Resources/sources_filterssources.xml \
  $$SRC_DIR/Application/Resources/sources_imagingcore.xml \
  $$SRC_DIR/Application/Resources/sources_imagingsources.xml \
  $$SRC_DIR/Application/Resources/sources_renderingfreetype.xml \
  $$SRC_DIR/Application/Resources/utilities.xml \
  $$SRC_DIR/Application/Resources/writers_ensight.xml \
  $$SRC_DIR/Application/Resources/writers_iogeometry.xml \
  $$SRC_DIR/Application/Resources/writers_iolegacy.xml \
  $$SRC_DIR/Application/Resources/writers_ioxml.xml \
  $$SRC_DIR/Application/Testing/CMakeLists.txt \
  $$SRC_DIR/Application/Testing/Data/Baseline/Animation.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/AnnotationVisibility.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/AxesGridTestGridLines.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/ChangeTimeSteps.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/ColorPaletteInStateFile.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/GhostCellsInMergeBlocks.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/MultiView.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/MultiView_chart_view.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/MultiView_render_view.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/ParallelSerialWriter.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/ParallelSerialWriterMultipleRankIO.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PointGaussianProperties.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/ProxyPropertyLinks.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PythonAnimationTrack.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PythonPVSimpleCone.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PythonPVSimpleExII.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PythonPVSimpleSphere.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PythonSMTraceTest1.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/PythonSelection.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveAnimation.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveAnimation_1.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveAnimation_right.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveScreenshotBarPlot.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveScreenshotBarPlot_1.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveScreenshotLinePlot.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveScreenshotLinePlot_1.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveScreenshotOutline.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/SaveScreenshotSurface.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/Simple.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/TestVTKSeriesWithMeta.png.sha512 \
  $$SRC_DIR/Application/Testing/Data/Baseline/UserTransformOnRepresentation.png.sha512 \
  $$SRC_DIR/Application/Testing/Python/Animation.py \
  $$SRC_DIR/Application/Testing/Python/AnimationCache.py \
  $$SRC_DIR/Application/Testing/Python/AnnotationVisibility.py \
  $$SRC_DIR/Application/Testing/Python/AxesGridTestGridLines.py \
  $$SRC_DIR/Application/Testing/Python/CMakeLists.txt \
  $$SRC_DIR/Application/Testing/Python/CSVWriterReader.py \
  $$SRC_DIR/Application/Testing/Python/CellIntegrator.py \
  $$SRC_DIR/Application/Testing/Python/ChangeTimeSteps.py \
  $$SRC_DIR/Application/Testing/Python/ColorAttributeTypeBackwardsCompatibility.py \
  $$SRC_DIR/Application/Testing/Python/ColorPaletteInStateFile.py \
  $$SRC_DIR/Application/Testing/Python/CompositeDataFieldArraysInformation.py \
  $$SRC_DIR/Application/Testing/Python/D3CellsWithNegativeVolumes.py \
  $$SRC_DIR/Application/Testing/Python/GenerateIdScalarsBackwardsCompatibility.py \
  $$SRC_DIR/Application/Testing/Python/GetActiveCamera.py \
  $$SRC_DIR/Application/Testing/Python/GhostCellsInMergeBlocks.py \
  $$SRC_DIR/Application/Testing/Python/IntegrateAttributes.py \
  $$SRC_DIR/Application/Testing/Python/LinePlotInScripts.py \
  $$SRC_DIR/Application/Testing/Python/LookupTable.py \
  $$SRC_DIR/Application/Testing/Python/MultiServer.py \
  $$SRC_DIR/Application/Testing/Python/MultiView.py \
  $$SRC_DIR/Application/Testing/Python/ParallelCoordinatesView.py \
  $$SRC_DIR/Application/Testing/Python/ParallelImageWriter.py \
  $$SRC_DIR/Application/Testing/Python/ParallelPythonImport.py \
  $$SRC_DIR/Application/Testing/Python/ParallelSerialWriter.py \
  $$SRC_DIR/Application/Testing/Python/ParallelSerialWriterMultipleRankIO.py \
  $$SRC_DIR/Application/Testing/Python/Plugins.py \
  $$SRC_DIR/Application/Testing/Python/PointGaussianProperties.py \
  $$SRC_DIR/Application/Testing/Python/PotentialMismatchedDataDelivery.py \
  $$SRC_DIR/Application/Testing/Python/ProgrammableFilter.py \
  $$SRC_DIR/Application/Testing/Python/ProgrammableFilterProperties.py \
  $$SRC_DIR/Application/Testing/Python/ProgrammableFilterPropertiesTest.xml \
  $$SRC_DIR/Application/Testing/Python/ProxyBackwardsCompatibilityTest.py \
  $$SRC_DIR/Application/Testing/Python/ProxyManager.py \
  $$SRC_DIR/Application/Testing/Python/ProxyPropertyLinks.pvsm \
  $$SRC_DIR/Application/Testing/Python/ProxyPropertyLinks.py \
  $$SRC_DIR/Application/Testing/Python/PythonAnimationTrack.py \
  $$SRC_DIR/Application/Testing/Python/PythonFilters.py \
  $$SRC_DIR/Application/Testing/Python/PythonPVSimpleCone.py \
  $$SRC_DIR/Application/Testing/Python/PythonPVSimpleExII.py \
  $$SRC_DIR/Application/Testing/Python/PythonPVSimpleSphere.py \
  $$SRC_DIR/Application/Testing/Python/PythonProgrammableFilterParameters.py \
  $$SRC_DIR/Application/Testing/Python/PythonSMTraceTest1.py \
  $$SRC_DIR/Application/Testing/Python/PythonSMTraceTest2.py \
  $$SRC_DIR/Application/Testing/Python/PythonSelection.py \
  $$SRC_DIR/Application/Testing/Python/PythonStateTestDriver.cmake \
  $$SRC_DIR/Application/Testing/Python/PythonStateTestDriver.py \
  $$SRC_DIR/Application/Testing/Python/PythonTestBenchmark.py \
  $$SRC_DIR/Application/Testing/Python/ReaderReload.py \
  $$SRC_DIR/Application/Testing/Python/RepresentationTypeHint.py \
  $$SRC_DIR/Application/Testing/Python/SMAnimation.py \
  $$SRC_DIR/Application/Testing/Python/SaveAnimation.py \
  $$SRC_DIR/Application/Testing/Python/SavePythonState.xml \
  $$SRC_DIR/Application/Testing/Python/SaveScreenshot.py \
  $$SRC_DIR/Application/Testing/Python/ScalarBarActorBackwardsCompatibility.py \
  $$SRC_DIR/Application/Testing/Python/ScalarOpacityFunctionPythonState.xml \
  $$SRC_DIR/Application/Testing/Python/Simple.py \
  $$SRC_DIR/Application/Testing/Python/TestCleanArrays.py \
  $$SRC_DIR/Application/Testing/Python/TestMPI4PY.py \
  $$SRC_DIR/Application/Testing/Python/TestVTKSeriesWithMeta.py \
  $$SRC_DIR/Application/Testing/Python/UserTransformOnRepresentation.py \
  $$SRC_DIR/Application/Testing/Python/VRMLSource.py \
  $$SRC_DIR/Application/Testing/Python/ValidateSources.py \
  $$SRC_DIR/Application/Testing/Python/ZIPImport.py \
  $$SRC_DIR/Application/vtk.module \
  $$SRC_DIR/ClientServerStream/CMakeLists.txt \
  $$SRC_DIR/ClientServerStream/Testing/CMakeLists.txt \
  $$SRC_DIR/ClientServerStream/Testing/Cxx/CMakeLists.txt \
  $$SRC_DIR/ClientServerStream/vtk.module \
  $$SRC_DIR/Core/CMakeLists.txt \
  $$SRC_DIR/Core/Testing/CMakeLists.txt \
  $$SRC_DIR/Core/Testing/Cxx/CMakeLists.txt \
  $$SRC_DIR/Core/vtk.module \
  $$SRC_DIR/Export/CMakeLists.txt \
  $$SRC_DIR/Export/Resources/exporters.xml \
  $$SRC_DIR/Export/vtk.module \
  $$SRC_DIR/Live/CMakeLists.txt \
  $$SRC_DIR/Live/Resources/live_utilities.xml \
  $$SRC_DIR/Live/Testing/CMakeLists.txt \
  $$SRC_DIR/Live/Testing/Cxx/CMakeLists.txt \
  $$SRC_DIR/Live/vtk.module \
  $$SRC_DIR/Misc/CMakeLists.txt \
  $$SRC_DIR/Misc/Resources/sources_remotingmisc.xml \
  $$SRC_DIR/Misc/vtk.module \
  \# $$SRC_DIR/ServerManager/CMakeLists.txt \
  \# $$SRC_DIR/ServerManager/Testing/CMakeLists.txt \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/CMakeLists.txt \
  \# $$SRC_DIR/ServerManager/Testing/Python/CMakeLists.txt \
  \# $$SRC_DIR/ServerManager/Testing/Python/Settings.py \
  \# $$SRC_DIR/ServerManager/Testing/Python/TestHelperProxySerialization.py \
  \# $$SRC_DIR/ServerManager/Testing/Python/TestMultiplexerSourceProxy.py \
  \# $$SRC_DIR/ServerManager/vtk.module \
  \# $$SRC_DIR/ServerManager/vtkPVMessage.proto \
  \# $$SRC_DIR/ServerManagerPython/CMakeLists.txt \
  \# $$SRC_DIR/ServerManagerPython/vtk.module \
  $$SRC_DIR/Settings/CMakeLists.txt \
  $$SRC_DIR/Settings/Resources/utilities_settings.xml \
  $$SRC_DIR/Settings/vtk.module \
  $$SRC_DIR/Views/CMakeLists.txt \
  $$SRC_DIR/Views/ColorMaps.json \
  $$SRC_DIR/Views/Resources/3dwidgets_remotingviews.xml \
  $$SRC_DIR/Views/Resources/extractors_remotingviews.xml \
  $$SRC_DIR/Views/Resources/rendering.xml \
  $$SRC_DIR/Views/Resources/sources_remotingviews.xml \
  $$SRC_DIR/Views/Resources/utilities_remotingviews.xml \
  $$SRC_DIR/Views/Resources/views_and_representations.xml \
  $$SRC_DIR/Views/Testing/CMakeLists.txt \
  $$SRC_DIR/Views/Testing/Cxx/CMakeLists.txt \
  $$SRC_DIR/Views/Testing/Python/CMakeLists.txt \
  $$SRC_DIR/Views/Testing/Python/LockScalarRangeBackwardsCompatibility.py \
  $$SRC_DIR/Views/Testing/Python/SpreadSheetViewBlockNames.py \
  $$SRC_DIR/Views/Testing/Python/SpreadSheetViewPartialArrays.py \
  $$SRC_DIR/Views/vtk.module \
  $$SRC_DIR/Views/vtkIceTCompositeZPassShader_fs.glsl \
  $$SRC_DIR/ViewsPython/CMakeLists.txt \
  $$SRC_DIR/ViewsPython/Resources/rendering_remotingpython.xml \
  $$SRC_DIR/ViewsPython/vtk.module


HEADERS += \
  $$SRC_DIR/Animation/vtkAnimationPlayer.h \
  $$SRC_DIR/Animation/vtkCameraInterpolator2.h \
  $$SRC_DIR/Animation/vtkCompositeAnimationPlayer.h \
  $$SRC_DIR/Animation/vtkPVAnimationCue.h \
  $$SRC_DIR/Animation/vtkPVBooleanKeyFrame.h \
  $$SRC_DIR/Animation/vtkPVCameraAnimationCue.h \
  $$SRC_DIR/Animation/vtkPVCameraCueManipulator.h \
  $$SRC_DIR/Animation/vtkPVCameraKeyFrame.h \
  $$SRC_DIR/Animation/vtkPVCompositeKeyFrame.h \
  $$SRC_DIR/Animation/vtkPVCueManipulator.h \
  $$SRC_DIR/Animation/vtkPVExponentialKeyFrame.h \
  $$SRC_DIR/Animation/vtkPVKeyFrame.h \
  $$SRC_DIR/Animation/vtkPVKeyFrameAnimationCue.h \
  $$SRC_DIR/Animation/vtkPVKeyFrameAnimationCueForProxies.h \
  $$SRC_DIR/Animation/vtkPVKeyFrameCueManipulator.h \
  $$SRC_DIR/Animation/vtkPVRampKeyFrame.h \
  $$SRC_DIR/Animation/vtkPVRepresentationAnimationHelper.h \
  $$SRC_DIR/Animation/vtkPVSinusoidKeyFrame.h \
  $$SRC_DIR/Animation/vtkPythonAnimationCue.h \
  $$SRC_DIR/Animation/vtkRealtimeAnimationPlayer.h \
  $$SRC_DIR/Animation/vtkSIXMLAnimationWriterRepresentationProperty.h \
  $$SRC_DIR/Animation/vtkSMAnimationFrameWindowDomain.h \
  $$SRC_DIR/Animation/vtkSMAnimationScene.h \
  $$SRC_DIR/Animation/vtkSMAnimationSceneGeometryWriter.h \
  $$SRC_DIR/Animation/vtkSMAnimationSceneProxy.h \
  $$SRC_DIR/Animation/vtkSMAnimationSceneWriter.h \
  $$SRC_DIR/Animation/vtkSMSaveAnimationExtractsProxy.h \
  $$SRC_DIR/Animation/vtkSMSaveAnimationProxy.h \
  $$SRC_DIR/Animation/vtkSequenceAnimationPlayer.h \
  $$SRC_DIR/Animation/vtkTimestepsAnimationPlayer.h \
  $$SRC_DIR/Animation/vtkXMLPVAnimationWriter.h \
  $$SRC_DIR/Application/vtkInitializationHelper.h \
  $$SRC_DIR/Application/vtkPVInitializer.h \
  $$SRC_DIR/ClientServerStream/vtkClientServerID.h \
  $$SRC_DIR/ClientServerStream/vtkClientServerInterpreter.h \
  $$SRC_DIR/ClientServerStream/vtkClientServerInterpreterInitializer.h \
  $$SRC_DIR/ClientServerStream/vtkClientServerStream.h \
  $$SRC_DIR/ClientServerStream/vtkClientServerStreamInstantiator.h \
  $$SRC_DIR/Core/vtkCompositeMultiProcessController.h \
  $$SRC_DIR/Core/vtkMPIMToNSocketConnection.h \
  $$SRC_DIR/Core/vtkMPIMToNSocketConnectionPortInformation.h \
  $$SRC_DIR/Core/vtkNetworkAccessManager.h \
  $$SRC_DIR/Core/vtkPResourceFileLocator.h \
  $$SRC_DIR/Core/vtkPVAlgorithmPortsInformation.h \
  $$SRC_DIR/Core/vtkPVArrayInformation.h \
  $$SRC_DIR/Core/vtkPVClassNameInformation.h \
  $$SRC_DIR/Core/vtkPVCompositeDataInformation.h \
  $$SRC_DIR/Core/vtkPVCompositeDataInformationIterator.h \
  $$SRC_DIR/Core/vtkPVConfig.h.in \
  $$SRC_DIR/Core/vtkPVDataAssemblyInformation.h \
  $$SRC_DIR/Core/vtkPVDataInformation.h \
  $$SRC_DIR/Core/vtkPVDataInformationHelper.h \
  $$SRC_DIR/Core/vtkPVDataSetAttributesInformation.h \
  $$SRC_DIR/Core/vtkPVDataSizeInformation.h \
  $$SRC_DIR/Core/vtkPVDisableStackTraceSignalHandler.h \
  $$SRC_DIR/Core/vtkPVEnableStackTraceSignalHandler.h \
  $$SRC_DIR/Core/vtkPVEnvironmentInformation.h \
  $$SRC_DIR/Core/vtkPVEnvironmentInformationHelper.h \
  $$SRC_DIR/Core/vtkPVFileInformation.h \
  $$SRC_DIR/Core/vtkPVFileInformationHelper.h \
  $$SRC_DIR/Core/vtkPVGenericAttributeInformation.h \
  $$SRC_DIR/Core/vtkPVInformation.h \
  $$SRC_DIR/Core/vtkPVLogInformation.h \
  $$SRC_DIR/Core/vtkPVMacFileInformationHelper.h \
  $$SRC_DIR/Core/vtkPVMemoryUseInformation.h \
  $$SRC_DIR/Core/vtkPVMultiClientsInformation.h \
  $$SRC_DIR/Core/vtkPVOptions.h \
  $$SRC_DIR/Core/vtkPVOptionsXMLParser.h \
  $$SRC_DIR/Core/vtkPVPlugin.h \
  $$SRC_DIR/Core/vtkPVPluginLoader.h \
  $$SRC_DIR/Core/vtkPVPluginTracker.h \
  $$SRC_DIR/Core/vtkPVPluginsInformation.h \
  $$SRC_DIR/Core/vtkPVProgressHandler.h \
  $$SRC_DIR/Core/vtkPVPythonInformation.h \
  $$SRC_DIR/Core/vtkPVPythonModule.h \
  $$SRC_DIR/Core/vtkPVPythonOptions.h \
  $$SRC_DIR/Core/vtkPVPythonPluginInterface.h \
  $$SRC_DIR/Core/vtkPVSILInformation.h \
  $$SRC_DIR/Core/vtkPVServerInformation.h \
  $$SRC_DIR/Core/vtkPVServerManagerPluginInterface.h \
  $$SRC_DIR/Core/vtkPVServerOptions.h \
  $$SRC_DIR/Core/vtkPVServerOptionsInternals.h \
  $$SRC_DIR/Core/vtkPVSession.h \
  $$SRC_DIR/Core/vtkPVSystemConfigInformation.h \
  $$SRC_DIR/Core/vtkPVSystemInformation.h \
  $$SRC_DIR/Core/vtkPVTemporalDataInformation.h \
  $$SRC_DIR/Core/vtkPVTimerInformation.h \
  $$SRC_DIR/Core/vtkProcessModule.h \
  $$SRC_DIR/Core/vtkProcessModuleAutoMPI.h \
  $$SRC_DIR/Core/vtkProcessModuleInternals.h \
  $$SRC_DIR/Core/vtkReservedRemoteObjectIds.h \
  $$SRC_DIR/Core/vtkSession.h \
  $$SRC_DIR/Core/vtkSessionIterator.h \
  $$SRC_DIR/Core/vtkTCPNetworkAccessManager.h \
  $$SRC_DIR/Export/vtkPVGL2PSExporter.h \
  $$SRC_DIR/Export/vtkPVWebExporter.h \
  $$SRC_DIR/Export/vtkPVX3DExporter.h \
  $$SRC_DIR/Export/vtkSMCSVExporterProxy.h \
  $$SRC_DIR/Export/vtkSMCSVProxiesInitializationHelper.h \
  $$SRC_DIR/Export/vtkSMExporterProxy.h \
  $$SRC_DIR/Export/vtkSMGL2PSExporterProxy.h \
  $$SRC_DIR/Export/vtkSMRenderViewExporterProxy.h \
  $$SRC_DIR/Export/vtkSMViewExportHelper.h \
  $$SRC_DIR/Live/vtkExtractsDeliveryHelper.h \
  $$SRC_DIR/Live/vtkLiveInsituLink.h \
  $$SRC_DIR/Live/vtkSMInsituStateLoader.h \
  $$SRC_DIR/Live/vtkSMLiveInsituLinkProxy.h \
  $$SRC_DIR/Live/vtkSteeringDataGenerator.h \
  $$SRC_DIR/Misc/vtkPVEnsembleDataReaderInformation.h \
  $$SRC_DIR/Misc/vtkPVMultiServerDataSource.h \
  $$SRC_DIR/Misc/vtkSMCameraConfigurationFileInfo.h \
  $$SRC_DIR/Misc/vtkSMCameraConfigurationReader.h \
  $$SRC_DIR/Misc/vtkSMCameraConfigurationWriter.h \
  $$SRC_DIR/Misc/vtkSMEnsembleDataReaderProxy.h \
  $$SRC_DIR/Misc/vtkSMExtractSelectionProxyInitializationHelper.h \
  $$SRC_DIR/Misc/vtkSMInteractionUndoStackBuilder.h \
  $$SRC_DIR/Misc/vtkSMInteractiveSelectionPipeline.h \
  $$SRC_DIR/Misc/vtkSMMultiServerSourceProxy.h \
  $$SRC_DIR/Misc/vtkSMOMETIFFChannelCalculatorInitializationHelper.h \
  $$SRC_DIR/Misc/vtkSMPLYWriterProxyInitializationHelper.h \
  $$SRC_DIR/Misc/vtkSMPreselectionPipeline.h \
  $$SRC_DIR/Misc/vtkSMProxyClipboard.h \
  $$SRC_DIR/Misc/vtkSMProxyConfigurationFileInfo.h \
  $$SRC_DIR/Misc/vtkSMProxyConfigurationReader.h \
  $$SRC_DIR/Misc/vtkSMProxyConfigurationWriter.h \
  $$SRC_DIR/Misc/vtkSMTesting.h \
  $$SRC_DIR/Misc/vtkSMTooltipSelectionPipeline.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMDoubleVectorPropertyTest.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMIntVectorPropertyTest.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMPropertyHelperTest.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMProxyLinkTest.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMProxyTest.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMStringVectorPropertyTest.h \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMUndoStackTest.h \
  \# $$SRC_DIR/ServerManager/vtkLoadStateOptions.h \
  \# $$SRC_DIR/ServerManager/vtkPVCatalystChannelInformation.h \
  \# $$SRC_DIR/ServerManager/vtkPVCatalystSessionCore.h \
  \# $$SRC_DIR/ServerManager/vtkPVFilePathEncodingHelper.h \
  \# $$SRC_DIR/ServerManager/vtkPVProxyDefinitionIterator.h \
  \# $$SRC_DIR/ServerManager/vtkPVSessionBase.h \
  \# $$SRC_DIR/ServerManager/vtkPVSessionCore.h \
  \# $$SRC_DIR/ServerManager/vtkPVSessionCoreInterpreterHelper.h \
  \# $$SRC_DIR/ServerManager/vtkPVSessionServer.h \
  \# $$SRC_DIR/ServerManager/vtkRemoteWriterHelper.h \
  \# $$SRC_DIR/ServerManager/vtkSIArraySelectionProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSICollaborationManager.h \
  \# $$SRC_DIR/ServerManager/vtkSICompoundSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSIDataArrayProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIDataArraySelectionProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIDirectoryProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSIDoubleMapProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIDoubleVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIIdTypeVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIIndexSelectionProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIInputProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIIntVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIMetaReaderProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSIMultiplexerSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSIObject.h \
  \# $$SRC_DIR/ServerManager/vtkSIProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSIProxyDefinitionManager.h \
  \# $$SRC_DIR/ServerManager/vtkSIProxyProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSISILProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSISourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSIStringVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSITimeLabelProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSITimeRangeProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSITimeStepsProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSIVectorPropertyTemplate.h \
  \# $$SRC_DIR/ServerManager/vtkSIVectorPropertyTemplate.txx \
  \# $$SRC_DIR/ServerManager/vtkSIWriterProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMAMRLevelsDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMArrayListDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMArrayRangeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMArraySelectionDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMBooleanDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMBoundsDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMCollaborationManager.h \
  \# $$SRC_DIR/ServerManager/vtkSMCompositeTreeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMCompoundProxyDefinitionLoader.h \
  \# $$SRC_DIR/ServerManager/vtkSMCompoundSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMCompoundSourceProxyDefinitionBuilder.h \
  \# $$SRC_DIR/ServerManager/vtkSMCoreUtilities.h \
  \# $$SRC_DIR/ServerManager/vtkSMDataAssemblyDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMDataExtractWriterProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMDataSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMDataTypeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializer.h \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializerProtobuf.h \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializerXML.h \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializerXMLCache.h \
  \# $$SRC_DIR/ServerManager/vtkSMDimensionsDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMDirectoryProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMDiscreteDoubleDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMDocumentation.h \
  \# $$SRC_DIR/ServerManager/vtkSMDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMDomainIterator.h \
  \# $$SRC_DIR/ServerManager/vtkSMDoubleMapProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMDoubleMapPropertyIterator.h \
  \# $$SRC_DIR/ServerManager/vtkSMDoubleRangeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMDoubleVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMEnumerationDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMExtentDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMExtractTriggerProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMExtractWriterProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMExtractsController.h \
  \# $$SRC_DIR/ServerManager/vtkSMFieldDataDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMFileListDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMFileUtilities.h \
  \# $$SRC_DIR/ServerManager/vtkSMFixedTypeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMIdTypeVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMIndexSelectionDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMInputArrayDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMInputFileNameDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMInputProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMIntRangeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMIntVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMLink.h \
  \# $$SRC_DIR/ServerManager/vtkSMLoadStateOptionsProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMMapProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMMessage.h \
  \# $$SRC_DIR/ServerManager/vtkSMMessageMinimal.h \
  \# $$SRC_DIR/ServerManager/vtkSMMultiplexerInputDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMMultiplexerSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMNamedPropertyIterator.h \
  \# $$SRC_DIR/ServerManager/vtkSMNullProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMNumberOfComponentsDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMObject.h \
  \# $$SRC_DIR/ServerManager/vtkSMOrderedPropertyIterator.h \
  \# $$SRC_DIR/ServerManager/vtkSMOutputPort.h \
  \# $$SRC_DIR/ServerManager/vtkSMPSWriterProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMPWriterProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMParaViewPipelineController.h \
  \# $$SRC_DIR/ServerManager/vtkSMPipelineState.h \
  \# $$SRC_DIR/ServerManager/vtkSMPluginLoaderProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMPluginManager.h \
  \# $$SRC_DIR/ServerManager/vtkSMProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyGroup.h \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyHelper.h \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyInternals.h \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyIterator.h \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyLink.h \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyModificationUndoElement.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyDefinitionManager.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyGroupDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyInitializationHelper.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyInternals.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyIterator.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyLink.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyListDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyLocator.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyManager.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyManagerUtilities.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxyPropertyInternals.h \
  \# $$SRC_DIR/ServerManager/vtkSMProxySelectionModel.h \
  \# $$SRC_DIR/ServerManager/vtkSMRangeDomainTemplate.h \
  \# $$SRC_DIR/ServerManager/vtkSMRangeDomainTemplate.txx \
  \# $$SRC_DIR/ServerManager/vtkSMReaderFactory.h \
  \# $$SRC_DIR/ServerManager/vtkSMReaderReloadHelper.h \
  \# $$SRC_DIR/ServerManager/vtkSMRemoteObject.h \
  \# $$SRC_DIR/ServerManager/vtkSMRemoteObjectUpdateUndoElement.h \
  \# $$SRC_DIR/ServerManager/vtkSMSILDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMSILModel.h \
  \# $$SRC_DIR/ServerManager/vtkSMSelfGeneratingSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMServerStateLocator.h \
  \# $$SRC_DIR/ServerManager/vtkSMSession.h \
  \# $$SRC_DIR/ServerManager/vtkSMSessionClient.h \
  \# $$SRC_DIR/ServerManager/vtkSMSessionObject.h \
  \# $$SRC_DIR/ServerManager/vtkSMSessionProxyManager.h \
  \# $$SRC_DIR/ServerManager/vtkSMSessionProxyManagerInternals.h \
  \# $$SRC_DIR/ServerManager/vtkSMSettings.h \
  \# $$SRC_DIR/ServerManager/vtkSMSettingsProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMSourceProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMStateLoader.h \
  \# $$SRC_DIR/ServerManager/vtkSMStateLocator.h \
  \# $$SRC_DIR/ServerManager/vtkSMStateVersionController.h \
  \# $$SRC_DIR/ServerManager/vtkSMStringListDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMStringVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMSubsetInclusionLatticeDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMTimeKeeper.h \
  \# $$SRC_DIR/ServerManager/vtkSMTimeKeeperProxy.h \
  \# $$SRC_DIR/ServerManager/vtkSMTimeStepIndexDomain.h \
  \# $$SRC_DIR/ServerManager/vtkSMTrace.h \
  \# $$SRC_DIR/ServerManager/vtkSMUncheckedPropertyHelper.h \
  \# $$SRC_DIR/ServerManager/vtkSMUndoElement.h \
  \# $$SRC_DIR/ServerManager/vtkSMUndoStack.h \
  \# $$SRC_DIR/ServerManager/vtkSMUndoStackBuilder.h \
  \# $$SRC_DIR/ServerManager/vtkSMVectorProperty.h \
  \# $$SRC_DIR/ServerManager/vtkSMVectorPropertyTemplate.h \
  \# $$SRC_DIR/ServerManager/vtkSMWriterFactory.h \
  \# $$SRC_DIR/ServerManager/vtkSMWriterProxy.h \
  \# $$SRC_DIR/ServerManagerPython/vtkPVPythonAlgorithmPlugin.h \
  \# $$SRC_DIR/ServerManagerPython/vtkSIPythonSourceProxy.h \
  $$SRC_DIR/Settings/vtkPVGeneralSettings.h \
  $$SRC_DIR/Views/vtk3DWidgetRepresentation.h \
  $$SRC_DIR/Views/vtkAMROutlineRepresentation.h \
  $$SRC_DIR/Views/vtkAMRStreamingPriorityQueue.h \
  $$SRC_DIR/Views/vtkAMRStreamingVolumeRepresentation.h \
  $$SRC_DIR/Views/vtkBoundingRectContextDevice2D.h \
  $$SRC_DIR/Views/vtkCaveSynchronizedRenderers.h \
  $$SRC_DIR/Views/vtkChartRepresentation.h \
  $$SRC_DIR/Views/vtkChartSelectionRepresentation.h \
  $$SRC_DIR/Views/vtkChartTextRepresentation.h \
  $$SRC_DIR/Views/vtkChartWarning.h \
  $$SRC_DIR/Views/vtkCompositeRepresentation.h \
  $$SRC_DIR/Views/vtkContext2DScalarBarActor.h \
  $$SRC_DIR/Views/vtkDataLabelRepresentation.h \
  $$SRC_DIR/Views/vtkFeatureEdgesRepresentation.h \
  $$SRC_DIR/Views/vtkGeometryRepresentation.h \
  $$SRC_DIR/Views/vtkGeometryRepresentationInternal.h \
  $$SRC_DIR/Views/vtkGeometryRepresentationWithFaces.h \
  $$SRC_DIR/Views/vtkGeometrySliceRepresentation.h \
  $$SRC_DIR/Views/vtkGlyph3DRepresentation.h \
  $$SRC_DIR/Views/vtkGridAxes2DActor.h \
  $$SRC_DIR/Views/vtkGridAxes3DActor.h \
  $$SRC_DIR/Views/vtkGridAxesHelper.h \
  $$SRC_DIR/Views/vtkGridAxesPlane2DActor.h \
  $$SRC_DIR/Views/vtkIceTCompositePass.h \
  $$SRC_DIR/Views/vtkIceTConstants.h \
  $$SRC_DIR/Views/vtkIceTContext.h \
  $$SRC_DIR/Views/vtkIceTSynchronizedRenderers.h \
  $$SRC_DIR/Views/vtkImageSliceRepresentation.h \
  $$SRC_DIR/Views/vtkImageVolumeRepresentation.h \
  $$SRC_DIR/Views/vtkLogoSourceRepresentation.h \
  $$SRC_DIR/Views/vtkMoleculeRepresentation.h \
  $$SRC_DIR/Views/vtkMultiSliceContextItem.h \
  $$SRC_DIR/Views/vtkOrderedCompositingHelper.h \
  $$SRC_DIR/Views/vtkOutlineRepresentation.h \
  $$SRC_DIR/Views/vtkPVAxesActor.h \
  $$SRC_DIR/Views/vtkPVAxesWidget.h \
  $$SRC_DIR/Views/vtkPVBoxChartRepresentation.h \
  $$SRC_DIR/Views/vtkPVCameraCollection.h \
  $$SRC_DIR/Views/vtkPVCenterAxesActor.h \
  $$SRC_DIR/Views/vtkPVClientServerSynchronizedRenderers.h \
  $$SRC_DIR/Views/vtkPVComparativeAnimationCue.h \
  $$SRC_DIR/Views/vtkPVComparativeView.h \
  $$SRC_DIR/Views/vtkPVCompositeOrthographicSliceRepresentation.h \
  $$SRC_DIR/Views/vtkPVCompositeRepresentation.h \
  $$SRC_DIR/Views/vtkPVContextInteractorStyle.h \
  $$SRC_DIR/Views/vtkPVContextView.h \
  $$SRC_DIR/Views/vtkPVContextViewDataDeliveryManager.h \
  $$SRC_DIR/Views/vtkPVDataDeliveryManager.h \
  $$SRC_DIR/Views/vtkPVDataDeliveryManagerInternals.h \
  $$SRC_DIR/Views/vtkPVDataRepresentation.h \
  $$SRC_DIR/Views/vtkPVDataRepresentationPipeline.h \
  $$SRC_DIR/Views/vtkPVDefaultPass.h \
  $$SRC_DIR/Views/vtkPVDiscretizableColorTransferFunction.h \
  $$SRC_DIR/Views/vtkPVEncodeSelectionForServer.h \
  $$SRC_DIR/Views/vtkPVFrustumActor.h \
  $$SRC_DIR/Views/vtkPVGridAxes3DActor.h \
  $$SRC_DIR/Views/vtkPVGridAxes3DRepresentation.h \
  $$SRC_DIR/Views/vtkPVHardwareSelector.h \
  $$SRC_DIR/Views/vtkPVHistogramChartRepresentation.h \
  $$SRC_DIR/Views/vtkPVImageSliceMapper.h \
  $$SRC_DIR/Views/vtkPVImplicitCylinderRepresentation.h \
  $$SRC_DIR/Views/vtkPVImplicitPlaneRepresentation.h \
  $$SRC_DIR/Views/vtkPVInteractiveViewLinkRepresentation.h \
  $$SRC_DIR/Views/vtkPVLODActor.h \
  $$SRC_DIR/Views/vtkPVLODVolume.h \
  $$SRC_DIR/Views/vtkPVLastSelectionInformation.h \
  $$SRC_DIR/Views/vtkPVLight.h \
  $$SRC_DIR/Views/vtkPVLogoSource.h \
  $$SRC_DIR/Views/vtkPVMaterialLibrary.h \
  $$SRC_DIR/Views/vtkPVMultiSliceView.h \
  $$SRC_DIR/Views/vtkPVOpenGLInformation.h \
  $$SRC_DIR/Views/vtkPVOrthographicSliceView.h \
  $$SRC_DIR/Views/vtkPVParallelCoordinatesRepresentation.h \
  $$SRC_DIR/Views/vtkPVPlotMatrixRepresentation.h \
  $$SRC_DIR/Views/vtkPVPlotMatrixView.h \
  $$SRC_DIR/Views/vtkPVPlotTime.h \
  $$SRC_DIR/Views/vtkPVProcessWindow.h \
  $$SRC_DIR/Views/vtkPVProminentValuesInformation.h \
  $$SRC_DIR/Views/vtkPVRayCastPickingHelper.h \
  $$SRC_DIR/Views/vtkPVRenderView.h \
  $$SRC_DIR/Views/vtkPVRenderViewDataDeliveryManager.h \
  $$SRC_DIR/Views/vtkPVRenderViewSettings.h \
  $$SRC_DIR/Views/vtkPVRenderViewWithEDL.h \
  $$SRC_DIR/Views/vtkPVRenderingCapabilitiesInformation.h \
  $$SRC_DIR/Views/vtkPVRepresentedArrayListSettings.h \
  $$SRC_DIR/Views/vtkPVRepresentedDataInformation.h \
  $$SRC_DIR/Views/vtkPVScalarBarActor.h \
  $$SRC_DIR/Views/vtkPVScalarBarRepresentation.h \
  $$SRC_DIR/Views/vtkPVSelectionInformation.h \
  $$SRC_DIR/Views/vtkPVStreamingPiecesInformation.h \
  $$SRC_DIR/Views/vtkPVSynchronizedRenderer.h \
  $$SRC_DIR/Views/vtkPVView.h \
  $$SRC_DIR/Views/vtkPVXYChartView.h \
  $$SRC_DIR/Views/vtkPointGaussianRepresentation.h \
  $$SRC_DIR/Views/vtkPolarAxesRepresentation.h \
  $$SRC_DIR/Views/vtkProgressBarSourceRepresentation.h \
  $$SRC_DIR/Views/vtkQuartileChartRepresentation.h \
  $$SRC_DIR/Views/vtkRulerSourceRepresentation.h \
  $$SRC_DIR/Views/vtkSIImageTextureProxy.h \
  $$SRC_DIR/Views/vtkSIPVRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSIUnstructuredGridVolumeRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMBoxRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMCameraLink.h \
  $$SRC_DIR/Views/vtkSMCameraProxy.h \
  $$SRC_DIR/Views/vtkSMChartRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMChartSeriesListDomain.h \
  $$SRC_DIR/Views/vtkSMChartSeriesSelectionDomain.h \
  $$SRC_DIR/Views/vtkSMChartUseIndexForAxisDomain.h \
  $$SRC_DIR/Views/vtkSMCinemaVolumetricImageExtractWriterProxy.h \
  $$SRC_DIR/Views/vtkSMComparativeAnimationCueProxy.h \
  $$SRC_DIR/Views/vtkSMComparativeAnimationCueUndoElement.h \
  $$SRC_DIR/Views/vtkSMComparativeViewProxy.h \
  $$SRC_DIR/Views/vtkSMContextViewProxy.h \
  $$SRC_DIR/Views/vtkSMDataDeliveryManagerProxy.h \
  $$SRC_DIR/Views/vtkSMImageExtractWriterProxy.h \
  $$SRC_DIR/Views/vtkSMImplicitPlaneRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMLightProxy.h \
  $$SRC_DIR/Views/vtkSMMaterialDomain.h \
  $$SRC_DIR/Views/vtkSMMaterialLibraryProxy.h \
  $$SRC_DIR/Views/vtkSMMultiSliceViewProxy.h \
  $$SRC_DIR/Views/vtkSMNewWidgetRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMOrthographicSliceViewProxy.h \
  $$SRC_DIR/Views/vtkSMPVMoleculeRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMPVRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMParaViewPipelineControllerWithRendering.h \
  $$SRC_DIR/Views/vtkSMPlotMatrixViewProxy.h \
  $$SRC_DIR/Views/vtkSMRangedTransferFunctionDomain.h \
  $$SRC_DIR/Views/vtkSMRenderViewProxy.h \
  $$SRC_DIR/Views/vtkSMRendererDomain.h \
  $$SRC_DIR/Views/vtkSMRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMRepresentationTypeDomain.h \
  $$SRC_DIR/Views/vtkSMRepresentedArrayListDomain.h \
  $$SRC_DIR/Views/vtkSMSaveScreenshotProxy.h \
  $$SRC_DIR/Views/vtkSMScalarBarWidgetRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMSelectionHelper.h \
  $$SRC_DIR/Views/vtkSMSelectionLink.h \
  $$SRC_DIR/Views/vtkSMSpreadSheetRepresentationInitializationHelper.h \
  $$SRC_DIR/Views/vtkSMSpreadSheetRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMSpreadSheetViewProxy.h \
  $$SRC_DIR/Views/vtkSMTextWidgetRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMTransferFunctionManager.h \
  $$SRC_DIR/Views/vtkSMTransferFunctionPresets.h \
  $$SRC_DIR/Views/vtkSMTransferFunctionProxy.h \
  $$SRC_DIR/Views/vtkSMUtilities.h \
  $$SRC_DIR/Views/vtkSMViewLayoutProxy.h \
  $$SRC_DIR/Views/vtkSMViewProxy.h \
  $$SRC_DIR/Views/vtkSMViewProxyInteractorHelper.h \
  $$SRC_DIR/Views/vtkSMViewResolutionDomain.h \
  $$SRC_DIR/Views/vtkSMWidgetRepresentationProxy.h \
  $$SRC_DIR/Views/vtkSMXYChartRepresentationInitializationHelper.h \
  $$SRC_DIR/Views/vtkSelectionRepresentation.h \
  $$SRC_DIR/Views/vtkSpreadSheetRepresentation.h \
  $$SRC_DIR/Views/vtkSpreadSheetView.h \
  $$SRC_DIR/Views/vtkStreamingPriorityQueue.h \
  $$SRC_DIR/Views/vtkStructuredGridVolumeRepresentation.h \
  $$SRC_DIR/Views/vtkTextSourceRepresentation.h \
  $$SRC_DIR/Views/vtkThreeSliceFilter.h \
  $$SRC_DIR/Views/vtkTilesHelper.h \
  $$SRC_DIR/Views/vtkUnstructuredGridVolumeRepresentation.h \
  $$SRC_DIR/Views/vtkViewLayout.h \
  $$SRC_DIR/Views/vtkVolumeRepresentation.h \
  $$SRC_DIR/Views/vtkXYChartRepresentation.h \
  $$SRC_DIR/Views/vtkXYChartRepresentationInternals.h \
  $$SRC_DIR/ViewsPython/vtkPythonRepresentation.h \
  $$SRC_DIR/ViewsPython/vtkPythonView.h \
  $$SRC_DIR/ViewsPython/vtkSMPythonViewProxy.h

SOURCES += \
  $$SRC_DIR/Animation/Testing/Cxx/ParaViewCoreAnimationPrintSelf.cxx \
  $$SRC_DIR/Animation/vtkAnimationPlayer.cxx \
  $$SRC_DIR/Animation/vtkCameraInterpolator2.cxx \
  $$SRC_DIR/Animation/vtkCompositeAnimationPlayer.cxx \
  $$SRC_DIR/Animation/vtkPVAnimationCue.cxx \
  $$SRC_DIR/Animation/vtkPVBooleanKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPVCameraAnimationCue.cxx \
  $$SRC_DIR/Animation/vtkPVCameraCueManipulator.cxx \
  $$SRC_DIR/Animation/vtkPVCameraKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPVCompositeKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPVCueManipulator.cxx \
  $$SRC_DIR/Animation/vtkPVExponentialKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPVKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPVKeyFrameAnimationCue.cxx \
  $$SRC_DIR/Animation/vtkPVKeyFrameAnimationCueForProxies.cxx \
  $$SRC_DIR/Animation/vtkPVKeyFrameCueManipulator.cxx \
  $$SRC_DIR/Animation/vtkPVRampKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPVRepresentationAnimationHelper.cxx \
  $$SRC_DIR/Animation/vtkPVSinusoidKeyFrame.cxx \
  $$SRC_DIR/Animation/vtkPythonAnimationCue.cxx \
  $$SRC_DIR/Animation/vtkRealtimeAnimationPlayer.cxx \
  $$SRC_DIR/Animation/vtkSIXMLAnimationWriterRepresentationProperty.cxx \
  $$SRC_DIR/Animation/vtkSMAnimationFrameWindowDomain.cxx \
  $$SRC_DIR/Animation/vtkSMAnimationScene.cxx \
  $$SRC_DIR/Animation/vtkSMAnimationSceneGeometryWriter.cxx \
  $$SRC_DIR/Animation/vtkSMAnimationSceneProxy.cxx \
  $$SRC_DIR/Animation/vtkSMAnimationSceneWriter.cxx \
  $$SRC_DIR/Animation/vtkSMSaveAnimationExtractsProxy.cxx \
  $$SRC_DIR/Animation/vtkSMSaveAnimationProxy.cxx \
  $$SRC_DIR/Animation/vtkSequenceAnimationPlayer.cxx \
  $$SRC_DIR/Animation/vtkTimestepsAnimationPlayer.cxx \
  $$SRC_DIR/Animation/vtkXMLPVAnimationWriter.cxx \
  \# $$SRC_DIR/Application/vtkInitializationHelper.cxx \
  $$SRC_DIR/ClientServerStream/Testing/Cxx/TestSimple.cxx \
  $$SRC_DIR/ClientServerStream/Testing/Cxx/TestSphere.cxx \
  $$SRC_DIR/ClientServerStream/Testing/Cxx/coverClientServer.cxx \
  $$SRC_DIR/ClientServerStream/vtkClientServerID.cxx \
  $$SRC_DIR/ClientServerStream/vtkClientServerInterpreter.cxx \
  $$SRC_DIR/ClientServerStream/vtkClientServerInterpreterInitializer.cxx \
  $$SRC_DIR/ClientServerStream/vtkClientServerStream.cxx \
  $$SRC_DIR/ClientServerStream/vtkClientServerStreamInstantiator.cxx \
  $$SRC_DIR/Core/Testing/Cxx/TestPVArrayInformation.cxx \
  $$SRC_DIR/Core/Testing/Cxx/TestPartialArraysInformation.cxx \
  $$SRC_DIR/Core/Testing/Cxx/TestSpecialDirectories.cxx \
  $$SRC_DIR/Core/vtkCompositeMultiProcessController.cxx \
  $$SRC_DIR/Core/vtkMPIMToNSocketConnection.cxx \
  $$SRC_DIR/Core/vtkMPIMToNSocketConnectionPortInformation.cxx \
  $$SRC_DIR/Core/vtkNetworkAccessManager.cxx \
  $$SRC_DIR/Core/vtkPResourceFileLocator.cxx \
  $$SRC_DIR/Core/vtkPVAlgorithmPortsInformation.cxx \
  $$SRC_DIR/Core/vtkPVArrayInformation.cxx \
  $$SRC_DIR/Core/vtkPVClassNameInformation.cxx \
  $$SRC_DIR/Core/vtkPVCompositeDataInformation.cxx \
  $$SRC_DIR/Core/vtkPVCompositeDataInformationIterator.cxx \
  $$SRC_DIR/Core/vtkPVDataAssemblyInformation.cxx \
  $$SRC_DIR/Core/vtkPVDataInformation.cxx \
  $$SRC_DIR/Core/vtkPVDataInformationHelper.cxx \
  $$SRC_DIR/Core/vtkPVDataSetAttributesInformation.cxx \
  $$SRC_DIR/Core/vtkPVDataSizeInformation.cxx \
  $$SRC_DIR/Core/vtkPVDisableStackTraceSignalHandler.cxx \
  $$SRC_DIR/Core/vtkPVEnableStackTraceSignalHandler.cxx \
  $$SRC_DIR/Core/vtkPVEnvironmentInformation.cxx \
  $$SRC_DIR/Core/vtkPVEnvironmentInformationHelper.cxx \
  $$SRC_DIR/Core/vtkPVFileInformation.cxx \
  $$SRC_DIR/Core/vtkPVFileInformationHelper.cxx \
  $$SRC_DIR/Core/vtkPVGenericAttributeInformation.cxx \
  $$SRC_DIR/Core/vtkPVInformation.cxx \
  $$SRC_DIR/Core/vtkPVLogInformation.cxx \
  \# $$SRC_DIR/Core/vtkPVMacFileInformationHelper.mm \
  $$SRC_DIR/Core/vtkPVMemoryUseInformation.cxx \
  $$SRC_DIR/Core/vtkPVMultiClientsInformation.cxx \
  $$SRC_DIR/Core/vtkPVOptions.cxx \
  $$SRC_DIR/Core/vtkPVOptionsXMLParser.cxx \
  $$SRC_DIR/Core/vtkPVPlugin.cxx \
  $$SRC_DIR/Core/vtkPVPluginLoader.cxx \
  \# $$SRC_DIR/Core/vtkPVPluginTracker.cxx \
  $$SRC_DIR/Core/vtkPVPluginsInformation.cxx \
  $$SRC_DIR/Core/vtkPVProgressHandler.cxx \
  $$SRC_DIR/Core/vtkPVPythonInformation.cxx \
  $$SRC_DIR/Core/vtkPVPythonModule.cxx \
  $$SRC_DIR/Core/vtkPVPythonOptions.cxx \
  $$SRC_DIR/Core/vtkPVPythonPluginInterface.cxx \
  $$SRC_DIR/Core/vtkPVSILInformation.cxx \
  $$SRC_DIR/Core/vtkPVServerInformation.cxx \
  $$SRC_DIR/Core/vtkPVServerManagerPluginInterface.cxx \
  $$SRC_DIR/Core/vtkPVServerOptions.cxx \
  $$SRC_DIR/Core/vtkPVSession.cxx \
  $$SRC_DIR/Core/vtkPVSystemConfigInformation.cxx \
  $$SRC_DIR/Core/vtkPVSystemInformation.cxx \
  $$SRC_DIR/Core/vtkPVTemporalDataInformation.cxx \
  $$SRC_DIR/Core/vtkPVTimerInformation.cxx \
  $$SRC_DIR/Core/vtkProcessModule.cxx \
  $$SRC_DIR/Core/vtkProcessModuleAutoMPI.cxx \
  $$SRC_DIR/Core/vtkSession.cxx \
  $$SRC_DIR/Core/vtkSessionIterator.cxx \
  $$SRC_DIR/Core/vtkTCPNetworkAccessManager.cxx \
  $$SRC_DIR/Export/vtkPVGL2PSExporter.cxx \
  $$SRC_DIR/Export/vtkPVWebExporter.cxx \
  $$SRC_DIR/Export/vtkPVX3DExporter.cxx \
  $$SRC_DIR/Export/vtkSMCSVExporterProxy.cxx \
  $$SRC_DIR/Export/vtkSMCSVProxiesInitializationHelper.cxx \
  $$SRC_DIR/Export/vtkSMExporterProxy.cxx \
  $$SRC_DIR/Export/vtkSMGL2PSExporterProxy.cxx \
  $$SRC_DIR/Export/vtkSMRenderViewExporterProxy.cxx \
  $$SRC_DIR/Export/vtkSMViewExportHelper.cxx \
  $$SRC_DIR/Live/Testing/Cxx/TestSteeringDataGenerator.cxx \
  $$SRC_DIR/Live/vtkExtractsDeliveryHelper.cxx \
  \# $$SRC_DIR/Live/vtkLiveInsituLink.cxx \
  $$SRC_DIR/Live/vtkSMInsituStateLoader.cxx \
  \# $$SRC_DIR/Live/vtkSMLiveInsituLinkProxy.cxx \
  $$SRC_DIR/Live/vtkSteeringDataGenerator.cxx \
  $$SRC_DIR/Misc/vtkPVEnsembleDataReaderInformation.cxx \
  $$SRC_DIR/Misc/vtkPVMultiServerDataSource.cxx \
  $$SRC_DIR/Misc/vtkSMCameraConfigurationReader.cxx \
  $$SRC_DIR/Misc/vtkSMCameraConfigurationWriter.cxx \
  $$SRC_DIR/Misc/vtkSMEnsembleDataReaderProxy.cxx \
  $$SRC_DIR/Misc/vtkSMExtractSelectionProxyInitializationHelper.cxx \
  $$SRC_DIR/Misc/vtkSMInteractionUndoStackBuilder.cxx \
  $$SRC_DIR/Misc/vtkSMInteractiveSelectionPipeline.cxx \
  \# $$SRC_DIR/Misc/vtkSMMultiServerSourceProxy.cxx \
  $$SRC_DIR/Misc/vtkSMOMETIFFChannelCalculatorInitializationHelper.cxx \
  $$SRC_DIR/Misc/vtkSMPLYWriterProxyInitializationHelper.cxx \
  $$SRC_DIR/Misc/vtkSMPreselectionPipeline.cxx \
  $$SRC_DIR/Misc/vtkSMProxyClipboard.cxx \
  $$SRC_DIR/Misc/vtkSMProxyConfigurationReader.cxx \
  $$SRC_DIR/Misc/vtkSMProxyConfigurationWriter.cxx \
  $$SRC_DIR/Misc/vtkSMTesting.cxx \
  $$SRC_DIR/Misc/vtkSMTooltipSelectionPipeline.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestAdjustRange.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestMultiplexerSourceProxy.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestProxyAnnotation.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestRecreateVTKObjects.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMDoubleVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMIntVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMPropertyHelper.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMProxy.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMProxyLink.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMStringVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSMUndoStack.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSelfGeneratingSourceProxy.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSessionProxyManager.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestSettings.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestValidateProxies.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/TestXMLSaveLoadState.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMDoubleVectorPropertyTest.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMIntVectorPropertyTest.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMPropertyHelperTest.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMProxyLinkTest.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMProxyTest.cxx \
  \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMStringVectorPropertyTest.cxx \
  \# \# $$SRC_DIR/ServerManager/Testing/Cxx/vtkSMUndoStackTest.cxx \
  \# $$SRC_DIR/ServerManager/vtkLoadStateOptions.cxx \
  \# $$SRC_DIR/ServerManager/vtkPVCatalystChannelInformation.cxx \
  \# $$SRC_DIR/ServerManager/vtkPVCatalystSessionCore.cxx \
  \# $$SRC_DIR/ServerManager/vtkPVFilePathEncodingHelper.cxx \
  \# $$SRC_DIR/ServerManager/vtkPVProxyDefinitionIterator.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkPVSessionBase.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkPVSessionCore.cxx \
  \# $$SRC_DIR/ServerManager/vtkPVSessionCoreInterpreterHelper.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkPVSessionServer.cxx \
  \# $$SRC_DIR/ServerManager/vtkRemoteWriterHelper.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIArraySelectionProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSICollaborationManager.cxx \
  \# $$SRC_DIR/ServerManager/vtkSICompoundSourceProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIDataArrayProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIDataArraySelectionProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIDirectoryProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIDoubleMapProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIDoubleVectorProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIIdTypeVectorProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIIndexSelectionProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIInputProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIIntVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSIMetaReaderProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSIMultiplexerSourceProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIObject.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIProxyDefinitionManager.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIProxyProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSISILProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSISourceProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIStringVectorProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSITimeLabelProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSITimeRangeProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSITimeStepsProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSIVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSIWriterProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMAMRLevelsDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMArrayListDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMArrayRangeDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMArraySelectionDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMBooleanDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMBoundsDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMCollaborationManager.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMCompositeTreeDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMCompoundProxyDefinitionLoader.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMCompoundSourceProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMCompoundSourceProxyDefinitionBuilder.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMCoreUtilities.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDataAssemblyDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDataExtractWriterProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDataSourceProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDataTypeDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializer.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMDeserializerProtobuf.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializerXML.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDeserializerXMLCache.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDimensionsDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDirectoryProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDiscreteDoubleDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDocumentation.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDomainIterator.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMDoubleMapProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDoubleMapPropertyIterator.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMDoubleRangeDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMDoubleVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMEnumerationDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMExtentDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMExtractTriggerProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMExtractWriterProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMExtractsController.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMFieldDataDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMFileListDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMFileUtilities.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMFixedTypeDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMIdTypeVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMIndexSelectionDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMInputArrayDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMInputFileNameDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMInputProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMIntRangeDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMIntVectorProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMLink.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMLoadStateOptionsProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMMapProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMMessage.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMMultiplexerInputDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMMultiplexerSourceProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMNamedPropertyIterator.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMNullProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMNumberOfComponentsDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMObject.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMOrderedPropertyIterator.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMOutputPort.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPSWriterProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPWriterProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMParaViewPipelineController.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMPipelineState.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPluginLoaderProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPluginManager.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyGroup.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyHelper.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMPropertyIterator.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMPropertyLink.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMPropertyModificationUndoElement.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProxyDefinitionManager.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMProxyGroupDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMProxyInitializationHelper.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProxyIterator.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProxyLink.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMProxyListDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMProxyLocator.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMProxyManager.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMProxyManagerUtilities.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProxyProperty.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMProxySelectionModel.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMReaderFactory.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMReaderReloadHelper.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMRemoteObject.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMRemoteObjectUpdateUndoElement.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSILDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSILModel.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSelfGeneratingSourceProxy.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMServerStateLocator.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMSession.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMSessionClient.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSessionObject.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMSessionProxyManager.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSettings.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSettingsProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSourceProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMStateLoader.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMStateLocator.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMStateVersionController.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMStringListDomain.cxx \
  \# \# $$SRC_DIR/ServerManager/vtkSMStringVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMSubsetInclusionLatticeDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMTimeKeeper.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMTimeKeeperProxy.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMTimeStepIndexDomain.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMTrace.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMUncheckedPropertyHelper.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMUndoElement.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMUndoStack.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMUndoStackBuilder.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMVectorProperty.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMWriterFactory.cxx \
  \# $$SRC_DIR/ServerManager/vtkSMWriterProxy.cxx \
  \# $$SRC_DIR/ServerManagerPython/vtkPVPythonAlgorithmPlugin.cxx \
  \# $$SRC_DIR/ServerManagerPython/vtkSIPythonSourceProxy.cxx \
  $$SRC_DIR/Settings/vtkPVGeneralSettings.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestComparativeAnimationCueProxy.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestImageScaleFactors.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestParaViewPipelineController.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestParaViewPipelineControllerWithRendering.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestProxyManagerUtilities.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestSystemCaps.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestTransferFunctionManager.cxx \
  $$SRC_DIR/Views/Testing/Cxx/TestTransferFunctionPresets.cxx \
  $$SRC_DIR/Views/vtk3DWidgetRepresentation.cxx \
  $$SRC_DIR/Views/vtkAMROutlineRepresentation.cxx \
  $$SRC_DIR/Views/vtkAMRStreamingPriorityQueue.cxx \
  \# $$SRC_DIR/Views/vtkAMRStreamingVolumeRepresentation.cxx \
  $$SRC_DIR/Views/vtkBoundingRectContextDevice2D.cxx \
  $$SRC_DIR/Views/vtkCaveSynchronizedRenderers.cxx \
  $$SRC_DIR/Views/vtkChartRepresentation.cxx \
  $$SRC_DIR/Views/vtkChartSelectionRepresentation.cxx \
  \# $$SRC_DIR/Views/vtkChartTextRepresentation.cxx \
  $$SRC_DIR/Views/vtkChartWarning.cxx \
  $$SRC_DIR/Views/vtkCompositeRepresentation.cxx \
  $$SRC_DIR/Views/vtkContext2DScalarBarActor.cxx \
  $$SRC_DIR/Views/vtkDataLabelRepresentation.cxx \
  $$SRC_DIR/Views/vtkFeatureEdgesRepresentation.cxx \
  \# $$SRC_DIR/Views/vtkGeometryRepresentation.cxx \
  $$SRC_DIR/Views/vtkGeometryRepresentationWithFaces.cxx \
  $$SRC_DIR/Views/vtkGeometrySliceRepresentation.cxx \
  $$SRC_DIR/Views/vtkGlyph3DRepresentation.cxx \
  \# $$SRC_DIR/Views/vtkGridAxes2DActor.cxx \
  $$SRC_DIR/Views/vtkGridAxes3DActor.cxx \
  $$SRC_DIR/Views/vtkGridAxesHelper.cxx \
  $$SRC_DIR/Views/vtkGridAxesPlane2DActor.cxx \
  \# $$SRC_DIR/Views/vtkIceTCompositePass.cxx \
  \# $$SRC_DIR/Views/vtkIceTContext.cxx \
  $$SRC_DIR/Views/vtkIceTSynchronizedRenderers.cxx \
  $$SRC_DIR/Views/vtkImageSliceRepresentation.cxx \
  $$SRC_DIR/Views/vtkImageVolumeRepresentation.cxx \
  $$SRC_DIR/Views/vtkLogoSourceRepresentation.cxx \
  $$SRC_DIR/Views/vtkMoleculeRepresentation.cxx \
  $$SRC_DIR/Views/vtkMultiSliceContextItem.cxx \
  \# $$SRC_DIR/Views/vtkOrderedCompositingHelper.cxx \
  $$SRC_DIR/Views/vtkOutlineRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVAxesActor.cxx \
  $$SRC_DIR/Views/vtkPVAxesWidget.cxx \
  $$SRC_DIR/Views/vtkPVBoxChartRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVCameraCollection.cxx \
  $$SRC_DIR/Views/vtkPVCenterAxesActor.cxx \
  $$SRC_DIR/Views/vtkPVClientServerSynchronizedRenderers.cxx \
  $$SRC_DIR/Views/vtkPVComparativeAnimationCue.cxx \
  $$SRC_DIR/Views/vtkPVComparativeView.cxx \
  $$SRC_DIR/Views/vtkPVCompositeOrthographicSliceRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVCompositeRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVContextInteractorStyle.cxx \
  $$SRC_DIR/Views/vtkPVContextView.cxx \
  $$SRC_DIR/Views/vtkPVContextViewDataDeliveryManager.cxx \
  $$SRC_DIR/Views/vtkPVDataDeliveryManager.cxx \
  $$SRC_DIR/Views/vtkPVDataRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVDataRepresentationPipeline.cxx \
  $$SRC_DIR/Views/vtkPVDefaultPass.cxx \
  $$SRC_DIR/Views/vtkPVDiscretizableColorTransferFunction.cxx \
  $$SRC_DIR/Views/vtkPVEncodeSelectionForServer.cxx \
  $$SRC_DIR/Views/vtkPVFrustumActor.cxx \
  $$SRC_DIR/Views/vtkPVGridAxes3DActor.cxx \
  $$SRC_DIR/Views/vtkPVGridAxes3DRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVHardwareSelector.cxx \
  $$SRC_DIR/Views/vtkPVHistogramChartRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVImageSliceMapper.cxx \
  $$SRC_DIR/Views/vtkPVImplicitCylinderRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVImplicitPlaneRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVInteractiveViewLinkRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVLODActor.cxx \
  $$SRC_DIR/Views/vtkPVLODVolume.cxx \
  $$SRC_DIR/Views/vtkPVLastSelectionInformation.cxx \
  $$SRC_DIR/Views/vtkPVLight.cxx \
  $$SRC_DIR/Views/vtkPVLogoSource.cxx \
  $$SRC_DIR/Views/vtkPVMaterialLibrary.cxx \
  $$SRC_DIR/Views/vtkPVMultiSliceView.cxx \
  $$SRC_DIR/Views/vtkPVOpenGLInformation.cxx \
  $$SRC_DIR/Views/vtkPVOrthographicSliceView.cxx \
  $$SRC_DIR/Views/vtkPVParallelCoordinatesRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVPlotMatrixRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVPlotMatrixView.cxx \
  $$SRC_DIR/Views/vtkPVPlotTime.cxx \
  $$SRC_DIR/Views/vtkPVProcessWindow.cxx \
  $$SRC_DIR/Views/vtkPVProminentValuesInformation.cxx \
  $$SRC_DIR/Views/vtkPVRayCastPickingHelper.cxx \
  \# $$SRC_DIR/Views/vtkPVRenderView.cxx \
  \# $$SRC_DIR/Views/vtkPVRenderViewDataDeliveryManager.cxx \
  $$SRC_DIR/Views/vtkPVRenderViewSettings.cxx \
  $$SRC_DIR/Views/vtkPVRenderViewWithEDL.cxx \
  $$SRC_DIR/Views/vtkPVRenderingCapabilitiesInformation.cxx \
  $$SRC_DIR/Views/vtkPVRepresentedArrayListSettings.cxx \
  $$SRC_DIR/Views/vtkPVRepresentedDataInformation.cxx \
  $$SRC_DIR/Views/vtkPVScalarBarActor.cxx \
  $$SRC_DIR/Views/vtkPVScalarBarRepresentation.cxx \
  $$SRC_DIR/Views/vtkPVSelectionInformation.cxx \
  $$SRC_DIR/Views/vtkPVStreamingPiecesInformation.cxx \
  $$SRC_DIR/Views/vtkPVSynchronizedRenderer.cxx \
  $$SRC_DIR/Views/vtkPVView.cxx \
  $$SRC_DIR/Views/vtkPVXYChartView.cxx \
  $$SRC_DIR/Views/vtkPointGaussianRepresentation.cxx \
  $$SRC_DIR/Views/vtkPolarAxesRepresentation.cxx \
  $$SRC_DIR/Views/vtkProgressBarSourceRepresentation.cxx \
  $$SRC_DIR/Views/vtkQuartileChartRepresentation.cxx \
  $$SRC_DIR/Views/vtkRulerSourceRepresentation.cxx \
  $$SRC_DIR/Views/vtkSIImageTextureProxy.cxx \
  $$SRC_DIR/Views/vtkSIPVRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSIUnstructuredGridVolumeRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMBoxRepresentationProxy.cxx \
  \# $$SRC_DIR/Views/vtkSMCameraLink.cxx \
  $$SRC_DIR/Views/vtkSMCameraProxy.cxx \
  $$SRC_DIR/Views/vtkSMChartRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMChartSeriesListDomain.cxx \
  $$SRC_DIR/Views/vtkSMChartSeriesSelectionDomain.cxx \
  $$SRC_DIR/Views/vtkSMChartUseIndexForAxisDomain.cxx \
  $$SRC_DIR/Views/vtkSMCinemaVolumetricImageExtractWriterProxy.cxx \
  $$SRC_DIR/Views/vtkSMComparativeAnimationCueProxy.cxx \
  $$SRC_DIR/Views/vtkSMComparativeAnimationCueUndoElement.cxx \
  $$SRC_DIR/Views/vtkSMComparativeViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMContextViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMDataDeliveryManagerProxy.cxx \
  $$SRC_DIR/Views/vtkSMImageExtractWriterProxy.cxx \
  $$SRC_DIR/Views/vtkSMImplicitPlaneRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMLightProxy.cxx \
  $$SRC_DIR/Views/vtkSMMaterialDomain.cxx \
  $$SRC_DIR/Views/vtkSMMaterialLibraryProxy.cxx \
  $$SRC_DIR/Views/vtkSMMultiSliceViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMNewWidgetRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMOrthographicSliceViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMPVMoleculeRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMPVRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMParaViewPipelineControllerWithRendering.cxx \
  $$SRC_DIR/Views/vtkSMPlotMatrixViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMRangedTransferFunctionDomain.cxx \
  $$SRC_DIR/Views/vtkSMRenderViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMRendererDomain.cxx \
  $$SRC_DIR/Views/vtkSMRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMRepresentationTypeDomain.cxx \
  $$SRC_DIR/Views/vtkSMRepresentedArrayListDomain.cxx \
  $$SRC_DIR/Views/vtkSMSaveScreenshotProxy.cxx \
  $$SRC_DIR/Views/vtkSMScalarBarWidgetRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMSelectionHelper.cxx \
  \# $$SRC_DIR/Views/vtkSMSelectionLink.cxx \
  $$SRC_DIR/Views/vtkSMSpreadSheetRepresentationInitializationHelper.cxx \
  $$SRC_DIR/Views/vtkSMSpreadSheetRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMSpreadSheetViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMTextWidgetRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMTransferFunctionManager.cxx \
  $$SRC_DIR/Views/vtkSMTransferFunctionPresets.cxx \
  $$SRC_DIR/Views/vtkSMTransferFunctionProxy.cxx \
  $$SRC_DIR/Views/vtkSMUtilities.cxx \
  \# $$SRC_DIR/Views/vtkSMViewLayoutProxy.cxx \
  $$SRC_DIR/Views/vtkSMViewProxy.cxx \
  $$SRC_DIR/Views/vtkSMViewProxyInteractorHelper.cxx \
  $$SRC_DIR/Views/vtkSMViewResolutionDomain.cxx \
  $$SRC_DIR/Views/vtkSMWidgetRepresentationProxy.cxx \
  $$SRC_DIR/Views/vtkSMXYChartRepresentationInitializationHelper.cxx \
  $$SRC_DIR/Views/vtkSelectionRepresentation.cxx \
  $$SRC_DIR/Views/vtkSpreadSheetRepresentation.cxx \
  $$SRC_DIR/Views/vtkSpreadSheetView.cxx \
  $$SRC_DIR/Views/vtkStructuredGridVolumeRepresentation.cxx \
  $$SRC_DIR/Views/vtkTextSourceRepresentation.cxx \
  $$SRC_DIR/Views/vtkThreeSliceFilter.cxx \
  $$SRC_DIR/Views/vtkTilesHelper.cxx \
  $$SRC_DIR/Views/vtkUnstructuredGridVolumeRepresentation.cxx \
  \# $$SRC_DIR/Views/vtkViewLayout.cxx \
  $$SRC_DIR/Views/vtkVolumeRepresentation.cxx \
  $$SRC_DIR/Views/vtkXYChartRepresentation.cxx \
  $$SRC_DIR/ViewsPython/vtkPythonRepresentation.cxx \
  $$SRC_DIR/ViewsPython/vtkPythonView.cxx \
  $$SRC_DIR/ViewsPython/vtkSMPythonViewProxy.cxx

