
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += widgets network

QT += help

QT += testlib

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)


include($$ROOT_DIR/../preferred/vtk.pri)



INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/cgns/src
INCLUDEPATH += $$SRC_GROUP_DIR/cgns


INCLUDEPATH += $$SRC_DIR/CGNSReader
INCLUDEPATH += $$SRC_DIR/CGNSWriter
INCLUDEPATH += $$SRC_DIR/Conduit
INCLUDEPATH += $$SRC_DIR/AMR
INCLUDEPATH += $$SRC_DIR/FiltersGeneral
INCLUDEPATH += $$SRC_DIR/IOEnSight



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



# maybe want this in preferred ...
INCLUDEPATH += /usr/include/python2.7

INCLUDEPATH += $$VTK_SRC_DIR/Common/ComputationalGeometry
INCLUDEPATH += $$VTK_SRC_DIR/Wrapping/PythonCore
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Sources
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Extraction
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Modeling
INCLUDEPATH += $$VTK_SRC_DIR/Rendering/UI
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Statistics
INCLUDEPATH += $$VTK_SRC_DIR/Filters/ParallelStatistics
INCLUDEPATH += $$VTK_SRC_DIR/IO/Infovis


INCLUDEPATH += $$VTK_BUILD_DIR/IO/Infovis
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Statistics
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/ParallelStatistics
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Modeling
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Extraction
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/pugixml
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty/zlib
INCLUDEPATH += $$VTK_BUILD_DIR/ThirdParty


INCLUDEPATH += $$VTK_ALT_SRC_DIR/ThirdParty/lz4

INCLUDEPATH += $$VTK_SRC_DIR/ThirdParty/lz4

INCLUDEPATH += $$VTK_ALT_SRC_DIR/IO/PLY


INCLUDEPATH += $$SRC_GROUP_DIR/ThirdParty/NvPipe/vtknvpipe


#INCLUDEPATH += $$ALT_DIR




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




HEADERS += \
  $$SRC_DIR/AMR/vtkAMRConnectivity.h \
  $$SRC_DIR/AMR/vtkAMRDualClip.h \
  $$SRC_DIR/AMR/vtkAMRDualContour.h \
  $$SRC_DIR/AMR/vtkAMRDualGridHelper.h \
  $$SRC_DIR/AMR/vtkAMRFragmentIntegration.h \
  $$SRC_DIR/AMR/vtkAMRFragmentsFilter.h \
  $$SRC_DIR/AMR/vtkPVAMRDualClip.h \
  $$SRC_DIR/AMR/vtkPVAMRDualContour.h \
  $$SRC_DIR/AMR/vtkPVAMRFragmentIntegration.h \
  $$SRC_DIR/CGNSReader/cgio_helpers.h \
  $$SRC_DIR/CGNSReader/vtkCGNSCache.h \
  $$SRC_DIR/CGNSReader/vtkCGNSFileSeriesReader.h \
  $$SRC_DIR/CGNSReader/vtkCGNSReader.h \
  $$SRC_DIR/CGNSReader/vtkCGNSReaderInternal.h \
  $$SRC_DIR/CGNSReader/vtkFileSeriesHelper.h \
  $$SRC_DIR/CGNSWriter/Testing/Cxx/TestFunctions.h \
  $$SRC_DIR/CGNSWriter/vtkCGNSWriter.h \
  $$SRC_DIR/Conduit/vtkConduitArrayUtilities.h \
  $$SRC_DIR/Conduit/vtkConduitSource.h \
  $$SRC_DIR/Core/vtkCommandOptions.h \
  $$SRC_DIR/Core/vtkCommandOptionsXMLParser.h \
  $$SRC_DIR/Core/vtkCommunicationErrorCatcher.h \
  $$SRC_DIR/Core/vtkDistributedTrivialProducer.h \
  $$SRC_DIR/Core/vtkFileSequenceParser.h \
  $$SRC_DIR/Core/vtkLogRecorder.h \
  $$SRC_DIR/Core/vtkMemberFunctionCommand.h \
  $$SRC_DIR/Core/vtkMultiProcessControllerHelper.h \
  $$SRC_DIR/Core/vtkPVCompositeDataPipeline.h \
  $$SRC_DIR/Core/vtkPVInformationKeys.h \
  $$SRC_DIR/Core/vtkPVLogger.h \
  $$SRC_DIR/Core/vtkPVNullSource.h \
  $$SRC_DIR/Core/vtkPVPostFilter.h \
  $$SRC_DIR/Core/vtkPVPostFilterExecutive.h \
  $$SRC_DIR/Core/vtkPVTestUtilities.h \
  $$SRC_DIR/Core/vtkPVTrivialProducer.h \
  $$SRC_DIR/Core/vtkPVXMLElement.h \
  $$SRC_DIR/Core/vtkPVXMLParser.h \
  $$SRC_DIR/Core/vtkStringList.h \
  $$SRC_DIR/Core/vtkSubsetInclusionLattice.h \
  $$SRC_DIR/Core/vtkUndoElement.h \
  $$SRC_DIR/Core/vtkUndoSet.h \
  $$SRC_DIR/Core/vtkUndoStack.h \
  $$SRC_DIR/Core/vtkUndoStackInternal.h \
  $$SRC_DIR/CosmoTools/Testing/Cxx/HaloFinderTestHelpers.h \
  $$SRC_DIR/CosmoTools/vtkACosmoReader.h \
  $$SRC_DIR/CosmoTools/vtkGenericIOUtilities.h \
  $$SRC_DIR/CosmoTools/vtkMinkowskiFilter.h \
  $$SRC_DIR/CosmoTools/vtkPANLHaloFinder.h \
  $$SRC_DIR/CosmoTools/vtkPANLSubhaloFinder.h \
  $$SRC_DIR/CosmoTools/vtkPCosmoReader.h \
  $$SRC_DIR/CosmoTools/vtkPGenericIOMultiBlockReader.h \
  $$SRC_DIR/CosmoTools/vtkPGenericIOMultiBlockWriter.h \
  $$SRC_DIR/CosmoTools/vtkPGenericIOReader.h \
  $$SRC_DIR/CosmoTools/vtkPLANLHaloFinder.h \
  $$SRC_DIR/CosmoTools/vtkPMergeConnected.h \
  $$SRC_DIR/CosmoTools/vtkPMultiResolutionGenericIOReader.h \
  $$SRC_DIR/Extraction/vtkExtractSelectionRange.h \
  $$SRC_DIR/Extraction/vtkPConvertSelection.h \
  $$SRC_DIR/Extraction/vtkPVExtractSelection.h \
  $$SRC_DIR/Extraction/vtkPVSelectionSource.h \
  $$SRC_DIR/Extraction/vtkPVSingleOutputExtractSelection.h \
  $$SRC_DIR/Extraction/vtkQuerySelectionSource.h \
  $$SRC_DIR/ExtractionPython/vtkPythonSelector.h \
  $$SRC_DIR/FiltersGeneral/Testing/Cxx/vtkErrorObserver.h \
  $$SRC_DIR/FiltersGeneral/vtkCellIntegrator.h \
  $$SRC_DIR/FiltersGeneral/vtkCleanUnstructuredGrid.h \
  $$SRC_DIR/FiltersGeneral/vtkCleanUnstructuredGridCells.h \
  $$SRC_DIR/FiltersGeneral/vtkConvertPolyhedraFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkEquivalenceSet.h \
  $$SRC_DIR/FiltersGeneral/vtkExtractScatterPlot.h \
  $$SRC_DIR/FiltersGeneral/vtkFlashContour.h \
  $$SRC_DIR/FiltersGeneral/vtkGridConnectivity.h \
  $$SRC_DIR/FiltersGeneral/vtkHierarchicalFractal.h \
  $$SRC_DIR/FiltersGeneral/vtkHybridProbeFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkImageSimpleSource.h \
  $$SRC_DIR/FiltersGeneral/vtkIntegrateFlowThroughSurface.h \
  $$SRC_DIR/FiltersGeneral/vtkIsoVolume.h \
  $$SRC_DIR/FiltersGeneral/vtkOMETIFFChannelCalculator.h \
  $$SRC_DIR/FiltersGeneral/vtkPEquivalenceSet.h \
  $$SRC_DIR/FiltersGeneral/vtkPVArrayCalculator.h \
  $$SRC_DIR/FiltersGeneral/vtkPVClipClosedSurface.h \
  $$SRC_DIR/FiltersGeneral/vtkPVClipDataSet.h \
  $$SRC_DIR/FiltersGeneral/vtkPVConnectivityFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkPVContourFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkPVCutter.h \
  $$SRC_DIR/FiltersGeneral/vtkPVDataSetAlgorithmSelectorFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkPVExtractComponent.h \
  $$SRC_DIR/FiltersGeneral/vtkPVExtractVOI.h \
  $$SRC_DIR/FiltersGeneral/vtkPVGlyphFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkPVGlyphFilterLegacy.h \
  $$SRC_DIR/FiltersGeneral/vtkPVLinearExtrusionFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkPVMetaClipDataSet.h \
  $$SRC_DIR/FiltersGeneral/vtkPVMetaSliceDataSet.h \
  $$SRC_DIR/FiltersGeneral/vtkPVTextSource.h \
  $$SRC_DIR/FiltersGeneral/vtkPVThreshold.h \
  $$SRC_DIR/FiltersGeneral/vtkPVTransposeTable.h \
  $$SRC_DIR/FiltersGeneral/vtkPlotEdges.h \
  $$SRC_DIR/FiltersGeneral/vtkRectilinearGridConnectivity.h \
  $$SRC_DIR/FiltersGeneral/vtkRulerLineForInput.h \
  $$SRC_DIR/FiltersGeneral/vtkSliceAlongPolyPlane.h \
  $$SRC_DIR/FiltersGeneral/vtkSurfaceVectors.h \
  $$SRC_DIR/FiltersGeneral/vtkTimeStepProgressFilter.h \
  $$SRC_DIR/FiltersGeneral/vtkTimeToTextConvertor.h \
  $$SRC_DIR/FiltersGeneralMPI/vtkInSituPParticlePathFilter.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkIntersectFragments.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceCommBuffer.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceFilter.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceIdList.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceIdListItem.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfacePieceLoading.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfacePieceTransaction.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfacePieceTransactionMatrix.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceProcessLoading.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceProcessRing.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceToProcMap.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceUtilities.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkPointAccumulator.h \
  $$SRC_DIR/FiltersMaterialInterface/vtkPointAccumulator.hxx \
  $$SRC_DIR/FiltersPython/vtkAnnotateAttributeDataFilter.h \
  $$SRC_DIR/FiltersPython/vtkAnnotateGlobalDataFilter.h \
  $$SRC_DIR/FiltersPython/vtkCDBWriter.h \
  $$SRC_DIR/FiltersPython/vtkPythonAnnotationFilter.h \
  $$SRC_DIR/FiltersPython/vtkPythonCalculator.h \
  $$SRC_DIR/FiltersPython/vtkPythonProgrammableFilter.h \
  $$SRC_DIR/FiltersRendering/vtkAllToNRedistributeCompositePolyData.h \
  $$SRC_DIR/FiltersRendering/vtkAllToNRedistributePolyData.h \
  $$SRC_DIR/FiltersRendering/vtkBalancedRedistributePolyData.h \
  $$SRC_DIR/FiltersRendering/vtkBlockDeliveryPreprocessor.h \
  $$SRC_DIR/FiltersRendering/vtkCSVExporter.h \
  $$SRC_DIR/FiltersRendering/vtkClientServerMoveData.h \
  $$SRC_DIR/FiltersRendering/vtkImageCompressor.h \
  $$SRC_DIR/FiltersRendering/vtkImageTransparencyFilter.h \
  $$SRC_DIR/FiltersRendering/vtkLZ4Compressor.h \
  $$SRC_DIR/FiltersRendering/vtkMPIMoveData.h \
  $$SRC_DIR/FiltersRendering/vtkMarkSelectedRows.h \
  $$SRC_DIR/FiltersRendering/vtkNetworkImageSource.h \
  $$SRC_DIR/FiltersRendering/vtkNvPipeCompressor.h \
  $$SRC_DIR/FiltersRendering/vtkOrderedCompositeDistributor.h \
  $$SRC_DIR/FiltersRendering/vtkPVGeometryFilter.h \
  $$SRC_DIR/FiltersRendering/vtkPVRecoverGeometryWireframe.h \
  $$SRC_DIR/FiltersRendering/vtkPVStreamingMacros.h \
  $$SRC_DIR/FiltersRendering/vtkRedistributePolyData.h \
  $$SRC_DIR/FiltersRendering/vtkResampledAMRImageSource.h \
  $$SRC_DIR/FiltersRendering/vtkSelectionConverter.h \
  $$SRC_DIR/FiltersRendering/vtkSelectionDeliveryFilter.h \
  $$SRC_DIR/FiltersRendering/vtkSortedTableStreamer.h \
  $$SRC_DIR/FiltersRendering/vtkSquirtCompressor.h \
  $$SRC_DIR/FiltersRendering/vtkVolumeRepresentationPreprocessor.h \
  $$SRC_DIR/FiltersRendering/vtkWeightedRedistributePolyData.h \
  $$SRC_DIR/FiltersRendering/vtkZlibImageCompressor.h \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizContingencyStats.h \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizDescriptiveStats.h \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizKMeans.h \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizMultiCorrelativeStats.h \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizPCAStats.h \
  $$SRC_DIR/FiltersStatistics/vtkSciVizStatistics.h \
  $$SRC_DIR/FiltersStatistics/vtkSciVizStatisticsPrivate.h \
  $$SRC_DIR/IOAMR/vtkAMRFileSeriesReader.h \
  $$SRC_DIR/IOCore/vtkAdditionalFieldReader.h \
  $$SRC_DIR/IOCore/vtkCSVWriter.h \
  $$SRC_DIR/IOCore/vtkFileSeriesReader.h \
  $$SRC_DIR/IOCore/vtkFileSeriesWriter.h \
  $$SRC_DIR/IOCore/vtkMetaReader.h \
  $$SRC_DIR/IOCore/vtkPVDReader.h \
  $$SRC_DIR/IOCore/vtkParallelSerialWriter.h \
  $$SRC_DIR/IOCore/vtkXMLCollectionReader.h \
  $$SRC_DIR/IOCore/vtkXMLPVDWriter.h \
  $$SRC_DIR/IOEnSight/vtkPEnSightGoldBinaryReader.h \
  $$SRC_DIR/IOEnSight/vtkPEnSightGoldReader.h \
  $$SRC_DIR/IOEnSight/vtkPEnSightReader.h \
  $$SRC_DIR/IOEnSight/vtkPGenericEnSightReader.h \
  $$SRC_DIR/IOEnSight/vtkPVEnSightMasterServerReader.h \
  $$SRC_DIR/IOEnSight/vtkPVEnSightMasterServerReader2.h \
  $$SRC_DIR/IOEnSight/vtkPVEnSightMasterServerTranslator.h \
  $$SRC_DIR/IOExodus/vtkExodusFileSeriesReader.h \
  $$SRC_DIR/IOGeneral/vtkEnsembleDataReader.h \
  $$SRC_DIR/IOGeneral/vtkPPhastaReader.h \
  $$SRC_DIR/IOGeneral/vtkPVPLYWriter.h \
  $$SRC_DIR/IOGeneral/vtkPhastaReader.h \
  $$SRC_DIR/IOGeneral/vtkUnstructuredPOPReader.h \
  $$SRC_DIR/IOGeneral/vtkVRMLSource.h \
  $$SRC_DIR/IOImage/vtkImageFileSeriesReader.h \
  $$SRC_DIR/IOImage/vtkRawImageFileSeriesReader.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotBlock.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotBlockIterator.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotFileSeriesReader.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotHistoryReader.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotHistoryReaderPrivate.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotIStream.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotReader.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotReaderMap.h \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotUniReader.h \
  $$SRC_DIR/InteractionStyle/vtkCameraManipulator.h \
  $$SRC_DIR/InteractionStyle/vtkCameraManipulatorGUIHelper.h \
  $$SRC_DIR/InteractionStyle/vtkPVInteractorStyle.h \
  $$SRC_DIR/InteractionStyle/vtkPVJoystickFly.h \
  $$SRC_DIR/InteractionStyle/vtkPVJoystickFlyIn.h \
  $$SRC_DIR/InteractionStyle/vtkPVJoystickFlyOut.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballMoveActor.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballMultiRotate.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballPan.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballRoll.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballRotate.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballZoom.h \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballZoomToMouse.h \
  $$SRC_DIR/InteractionStyle/vtkTrackballPan.h \
  $$SRC_DIR/Misc/vtkAppendRectilinearGrid.h \
  $$SRC_DIR/Misc/vtkAttributeDataReductionFilter.h \
  $$SRC_DIR/Misc/vtkAttributeDataToTableFilter.h \
  $$SRC_DIR/Misc/vtkCleanArrays.h \
  $$SRC_DIR/Misc/vtkCompleteArrays.h \
  $$SRC_DIR/Misc/vtkCompositeDataToUnstructuredGridFilter.h \
  $$SRC_DIR/Misc/vtkDataObjectTreeToPointSetFilter.h \
  $$SRC_DIR/Misc/vtkEnvironmentAnnotationFilter.h \
  $$SRC_DIR/Misc/vtkExtractHistogram.h \
  $$SRC_DIR/Misc/vtkMergeBlocks.h \
  $$SRC_DIR/Misc/vtkMinMax.h \
  $$SRC_DIR/Misc/vtkPExtractHistogram.h \
  $$SRC_DIR/Misc/vtkPVBox.h \
  $$SRC_DIR/Misc/vtkPVChangeOfBasisHelper.h \
  $$SRC_DIR/Misc/vtkPVCylinder.h \
  $$SRC_DIR/Misc/vtkPVMergeTables.h \
  $$SRC_DIR/Misc/vtkPVMergeTablesMultiBlock.h \
  $$SRC_DIR/Misc/vtkPVPlane.h \
  $$SRC_DIR/Misc/vtkPVRotateAroundOriginTransform.h \
  $$SRC_DIR/Misc/vtkPVTransform.h \
  $$SRC_DIR/Misc/vtkReductionFilter.h \
  $$SRC_DIR/Misc/vtkSelectionSerializer.h \
  $$SRC_DIR/Points/vtkBoundedPlaneSource.h \
  $$SRC_DIR/Points/vtkBoundedVolumeSource.h


SOURCES += \
  $$SRC_DIR/AMR/vtkAMRConnectivity.cxx \
  $$SRC_DIR/AMR/vtkAMRDualClip.cxx \
  $$SRC_DIR/AMR/vtkAMRDualClipTables.cxx \
  $$SRC_DIR/AMR/vtkAMRDualContour.cxx \
  $$SRC_DIR/AMR/vtkAMRDualGridHelper.cxx \
  $$SRC_DIR/AMR/vtkAMRFragmentIntegration.cxx \
  $$SRC_DIR/AMR/vtkAMRFragmentsFilter.cxx \
  $$SRC_DIR/AMR/vtkPVAMRDualClip.cxx \
  $$SRC_DIR/AMR/vtkPVAMRDualContour.cxx \
  $$SRC_DIR/AMR/vtkPVAMRFragmentIntegration.cxx \
  $$SRC_DIR/CGNSReader/Testing/Cxx/TestCGNSNoFlowSolutionPointers.cxx \
  $$SRC_DIR/CGNSReader/Testing/Cxx/TestCGNSReader.cxx \
  $$SRC_DIR/CGNSReader/Testing/Cxx/TestCGNSReaderMeshCaching.cxx \
  $$SRC_DIR/CGNSReader/Testing/Cxx/TestCGNSUnsteadyFields.cxx \
  $$SRC_DIR/CGNSReader/Testing/Cxx/TestCGNSUnsteadyGrid.cxx \
  $$SRC_DIR/CGNSReader/Testing/Cxx/TestReadCGNSSolution.cxx \
  $$SRC_DIR/CGNSReader/cgio_helpers.cxx \
  $$SRC_DIR/CGNSReader/vtkCGNSFileSeriesReader.cxx \
  \# $$SRC_DIR/CGNSReader/vtkCGNSReader.cxx \
  $$SRC_DIR/CGNSReader/vtkCGNSReaderInternal.cxx \
  $$SRC_DIR/CGNSReader/vtkFileSeriesHelper.cxx \
  $$SRC_DIR/CGNSWriter/Testing/Cxx/TestMultiBlockDataSet.cxx \
  $$SRC_DIR/CGNSWriter/Testing/Cxx/TestPolydata.cxx \
  $$SRC_DIR/CGNSWriter/Testing/Cxx/TestPolyhedral.cxx \
  $$SRC_DIR/CGNSWriter/Testing/Cxx/TestStructuredGrid.cxx \
  $$SRC_DIR/CGNSWriter/Testing/Cxx/TestUnstructuredGrid.cxx \
  $$SRC_DIR/CGNSWriter/vtkCGNSWriter.cxx \
  \# $$SRC_DIR/Conduit/Testing/Cxx/TestConduitSource.cxx \
  \# $$SRC_DIR/Conduit/vtkConduitArrayUtilities.cxx \
  \# $$SRC_DIR/Conduit/vtkConduitSource.cxx \
  $$SRC_DIR/Core/Testing/Cxx/TestFileSequenceParser.cxx \
  $$SRC_DIR/Core/Testing/Cxx/TestSubsetInclusionLattice.cxx \
  $$SRC_DIR/Core/vtkCommandOptions.cxx \
  $$SRC_DIR/Core/vtkCommandOptionsXMLParser.cxx \
  $$SRC_DIR/Core/vtkCommunicationErrorCatcher.cxx \
  $$SRC_DIR/Core/vtkDistributedTrivialProducer.cxx \
  $$SRC_DIR/Core/vtkFileSequenceParser.cxx \
  $$SRC_DIR/Core/vtkLogRecorder.cxx \
  $$SRC_DIR/Core/vtkMultiProcessControllerHelper.cxx \
  $$SRC_DIR/Core/vtkPVCompositeDataPipeline.cxx \
  $$SRC_DIR/Core/vtkPVInformationKeys.cxx \
  $$SRC_DIR/Core/vtkPVLogger.cxx \
  $$SRC_DIR/Core/vtkPVNullSource.cxx \
  $$SRC_DIR/Core/vtkPVPostFilter.cxx \
  $$SRC_DIR/Core/vtkPVPostFilterExecutive.cxx \
  $$SRC_DIR/Core/vtkPVTestUtilities.cxx \
  $$SRC_DIR/Core/vtkPVTrivialProducer.cxx \
  $$SRC_DIR/Core/vtkPVXMLElement.cxx \
  $$SRC_DIR/Core/vtkPVXMLParser.cxx \
  $$SRC_DIR/Core/vtkStringList.cxx \
  $$SRC_DIR/Core/vtkSubsetInclusionLattice.cxx \
  $$SRC_DIR/Core/vtkUndoElement.cxx \
  $$SRC_DIR/Core/vtkUndoSet.cxx \
  $$SRC_DIR/Core/vtkUndoStack.cxx \
  \# $$SRC_DIR/CosmoTools/Testing/Cxx/TestHaloFinder.cxx \
  \# $$SRC_DIR/CosmoTools/Testing/Cxx/TestHaloFinderSubhaloFinding.cxx \
  \# $$SRC_DIR/CosmoTools/Testing/Cxx/TestHaloFinderSummaryInfo.cxx \
  \# $$SRC_DIR/CosmoTools/Testing/Cxx/TestSubhaloFinder.cxx \
  \# $$SRC_DIR/CosmoTools/vtkACosmoReader.cxx \
  \# $$SRC_DIR/CosmoTools/vtkGenericIOUtilities.cxx \
  \# $$SRC_DIR/CosmoTools/vtkMinkowskiFilter.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPANLHaloFinder.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPANLSubhaloFinder.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPCosmoReader.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPGenericIOMultiBlockReader.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPGenericIOMultiBlockWriter.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPGenericIOReader.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPLANLHaloFinder.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPMergeConnected.cxx \
  \# $$SRC_DIR/CosmoTools/vtkPMultiResolutionGenericIOReader.cxx \
  $$SRC_DIR/Extraction/vtkExtractSelectionRange.cxx \
  $$SRC_DIR/Extraction/vtkPConvertSelection.cxx \
  $$SRC_DIR/Extraction/vtkPVExtractSelection.cxx \
  $$SRC_DIR/Extraction/vtkPVSelectionSource.cxx \
  $$SRC_DIR/Extraction/vtkPVSingleOutputExtractSelection.cxx \
  $$SRC_DIR/Extraction/vtkQuerySelectionSource.cxx \
  $$SRC_DIR/ExtractionPython/vtkPythonSelector.cxx \
  $$SRC_DIR/FiltersGeneral/Testing/Cxx/TestPolyhedralToSimpleCellsFilter.cxx \
  $$SRC_DIR/FiltersGeneral/Testing/Cxx/vtkErrorObserver.cxx \
  $$SRC_DIR/FiltersGeneral/vtkCellIntegrator.cxx \
  $$SRC_DIR/FiltersGeneral/vtkCleanUnstructuredGrid.cxx \
  $$SRC_DIR/FiltersGeneral/vtkCleanUnstructuredGridCells.cxx \
  $$SRC_DIR/FiltersGeneral/vtkConvertPolyhedraFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkEquivalenceSet.cxx \
  $$SRC_DIR/FiltersGeneral/vtkExtractScatterPlot.cxx \
  $$SRC_DIR/FiltersGeneral/vtkFlashContour.cxx \
  $$SRC_DIR/FiltersGeneral/vtkGridConnectivity.cxx \
  $$SRC_DIR/FiltersGeneral/vtkHierarchicalFractal.cxx \
  $$SRC_DIR/FiltersGeneral/vtkHybridProbeFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkImageSimpleSource.cxx \
  $$SRC_DIR/FiltersGeneral/vtkIntegrateFlowThroughSurface.cxx \
  $$SRC_DIR/FiltersGeneral/vtkIsoVolume.cxx \
  $$SRC_DIR/FiltersGeneral/vtkOMETIFFChannelCalculator.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPEquivalenceSet.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVArrayCalculator.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVClipClosedSurface.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVClipDataSet.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVConnectivityFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVContourFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVCutter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVDataSetAlgorithmSelectorFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVExtractComponent.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVExtractVOI.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVGlyphFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVGlyphFilterLegacy.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVLinearExtrusionFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVMetaClipDataSet.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVMetaSliceDataSet.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVTextSource.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVThreshold.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPVTransposeTable.cxx \
  $$SRC_DIR/FiltersGeneral/vtkPlotEdges.cxx \
  $$SRC_DIR/FiltersGeneral/vtkRectilinearGridConnectivity.cxx \
  $$SRC_DIR/FiltersGeneral/vtkRectilinearGridConnectivityCases.cxx \
  $$SRC_DIR/FiltersGeneral/vtkRulerLineForInput.cxx \
  $$SRC_DIR/FiltersGeneral/vtkSliceAlongPolyPlane.cxx \
  \# $$SRC_DIR/FiltersGeneral/vtkSurfaceVectors.cxx \
  $$SRC_DIR/FiltersGeneral/vtkTimeStepProgressFilter.cxx \
  $$SRC_DIR/FiltersGeneral/vtkTimeToTextConvertor.cxx \
  $$SRC_DIR/FiltersGeneralMPI/vtkInSituPParticlePathFilter.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkIntersectFragments.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceCommBuffer.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceFilter.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceFilterCases.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceIdList.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfacePieceLoading.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfacePieceTransaction.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfacePieceTransactionMatrix.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceProcessLoading.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceProcessRing.cxx \
  $$SRC_DIR/FiltersMaterialInterface/vtkMaterialInterfaceToProcMap.cxx \
  $$SRC_DIR/FiltersPython/vtkAnnotateAttributeDataFilter.cxx \
  $$SRC_DIR/FiltersPython/vtkAnnotateGlobalDataFilter.cxx \
  $$SRC_DIR/FiltersPython/vtkCDBWriter.cxx \
  $$SRC_DIR/FiltersPython/vtkPythonAnnotationFilter.cxx \
  $$SRC_DIR/FiltersPython/vtkPythonCalculator.cxx \
  $$SRC_DIR/FiltersPython/vtkPythonProgrammableFilter.cxx \
  $$SRC_DIR/FiltersRendering/Testing/Cxx/TestImageCompressors.cxx \
  $$SRC_DIR/FiltersRendering/Testing/Cxx/TestResampledAMRImageSource.cxx \
  $$SRC_DIR/FiltersRendering/Testing/Cxx/TestResampledAMRImageSourceWithPointData.cxx \
  $$SRC_DIR/FiltersRendering/vtkAllToNRedistributeCompositePolyData.cxx \
  $$SRC_DIR/FiltersRendering/vtkAllToNRedistributePolyData.cxx \
  $$SRC_DIR/FiltersRendering/vtkBalancedRedistributePolyData.cxx \
  $$SRC_DIR/FiltersRendering/vtkBlockDeliveryPreprocessor.cxx \
  \# $$SRC_DIR/FiltersRendering/vtkCSVExporter.cxx \
  $$SRC_DIR/FiltersRendering/vtkClientServerMoveData.cxx \
  $$SRC_DIR/FiltersRendering/vtkImageCompressor.cxx \
  $$SRC_DIR/FiltersRendering/vtkImageTransparencyFilter.cxx \
  $$SRC_DIR/FiltersRendering/vtkLZ4Compressor.cxx \
  $$SRC_DIR/FiltersRendering/vtkMPIMoveData.cxx \
  $$SRC_DIR/FiltersRendering/vtkMarkSelectedRows.cxx \
  $$SRC_DIR/FiltersRendering/vtkNetworkImageSource.cxx \
  $$SRC_DIR/FiltersRendering/vtkNvPipeCompressor.cxx \
  $$SRC_DIR/FiltersRendering/vtkOrderedCompositeDistributor.cxx \
  $$SRC_DIR/FiltersRendering/vtkPVGeometryFilter.cxx \
  $$SRC_DIR/FiltersRendering/vtkPVRecoverGeometryWireframe.cxx \
  $$SRC_DIR/FiltersRendering/vtkRedistributePolyData.cxx \
  $$SRC_DIR/FiltersRendering/vtkResampledAMRImageSource.cxx \
  $$SRC_DIR/FiltersRendering/vtkSelectionConverter.cxx \
  $$SRC_DIR/FiltersRendering/vtkSelectionDeliveryFilter.cxx \
  $$SRC_DIR/FiltersRendering/vtkSortedTableStreamer.cxx \
  $$SRC_DIR/FiltersRendering/vtkSquirtCompressor.cxx \
  $$SRC_DIR/FiltersRendering/vtkVolumeRepresentationPreprocessor.cxx \
  $$SRC_DIR/FiltersRendering/vtkWeightedRedistributePolyData.cxx \
  $$SRC_DIR/FiltersRendering/vtkZlibImageCompressor.cxx \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizContingencyStats.cxx \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizDescriptiveStats.cxx \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizKMeans.cxx \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizMultiCorrelativeStats.cxx \
  $$SRC_DIR/FiltersStatistics/vtkPSciVizPCAStats.cxx \
  $$SRC_DIR/FiltersStatistics/vtkSciVizStatistics.cxx \
  $$SRC_DIR/IOAMR/vtkAMRFileSeriesReader.cxx \
  $$SRC_DIR/IOCore/Testing/Cxx/TestCSVWriter.cxx \
  $$SRC_DIR/IOCore/Testing/Cxx/TestPVDArraySelection.cxx \
  $$SRC_DIR/IOCore/vtkAdditionalFieldReader.cxx \
  $$SRC_DIR/IOCore/vtkCSVWriter.cxx \
  $$SRC_DIR/IOCore/vtkFileSeriesReader.cxx \
  $$SRC_DIR/IOCore/vtkFileSeriesWriter.cxx \
  $$SRC_DIR/IOCore/vtkMetaReader.cxx \
  $$SRC_DIR/IOCore/vtkPVDReader.cxx \
  $$SRC_DIR/IOCore/vtkParallelSerialWriter.cxx \
  $$SRC_DIR/IOCore/vtkXMLCollectionReader.cxx \
  $$SRC_DIR/IOCore/vtkXMLPVDWriter.cxx \
  $$SRC_DIR/IOEnSight/Testing/Cxx/TestPEnSightBinaryGoldReader.cxx \
  $$SRC_DIR/IOEnSight/vtkPEnSightGoldBinaryReader.cxx \
  $$SRC_DIR/IOEnSight/vtkPEnSightGoldReader.cxx \
  $$SRC_DIR/IOEnSight/vtkPEnSightReader.cxx \
  $$SRC_DIR/IOEnSight/vtkPGenericEnSightReader.cxx \
  $$SRC_DIR/IOEnSight/vtkPVEnSightMasterServerReader.cxx \
  $$SRC_DIR/IOEnSight/vtkPVEnSightMasterServerReader2.cxx \
  $$SRC_DIR/IOEnSight/vtkPVEnSightMasterServerTranslator.cxx \
  $$SRC_DIR/IOExodus/vtkExodusFileSeriesReader.cxx \
  $$SRC_DIR/IOGeneral/vtkEnsembleDataReader.cxx \
  $$SRC_DIR/IOGeneral/vtkPPhastaReader.cxx \
  $$SRC_DIR/IOGeneral/vtkPVPLYWriter.cxx \
  $$SRC_DIR/IOGeneral/vtkPhastaReader.cxx \
  $$SRC_DIR/IOGeneral/vtkUnstructuredPOPReader.cxx \
  $$SRC_DIR/IOGeneral/vtkVRMLSource.cxx \
  $$SRC_DIR/IOImage/vtkImageFileSeriesReader.cxx \
  $$SRC_DIR/IOImage/vtkRawImageFileSeriesReader.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotBlock.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotBlockIterator.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotFileSeriesReader.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotHistoryReader.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotIStream.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotReader.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotReaderMap.cxx \
  $$SRC_DIR/IOSPCTH/vtkSpyPlotUniReader.cxx \
  $$SRC_DIR/InteractionStyle/vtkCameraManipulator.cxx \
  $$SRC_DIR/InteractionStyle/vtkCameraManipulatorGUIHelper.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVInteractorStyle.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVJoystickFly.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVJoystickFlyIn.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVJoystickFlyOut.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballMoveActor.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballMultiRotate.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballPan.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballRoll.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballRotate.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballZoom.cxx \
  $$SRC_DIR/InteractionStyle/vtkPVTrackballZoomToMouse.cxx \
  $$SRC_DIR/InteractionStyle/vtkTrackballPan.cxx \
  $$SRC_DIR/Misc/Testing/Cxx/TestMergeTablesMultiBlock.cxx \
  $$SRC_DIR/Misc/vtkAppendRectilinearGrid.cxx \
  $$SRC_DIR/Misc/vtkAttributeDataReductionFilter.cxx \
  $$SRC_DIR/Misc/vtkAttributeDataToTableFilter.cxx \
  $$SRC_DIR/Misc/vtkCleanArrays.cxx \
  $$SRC_DIR/Misc/vtkCompleteArrays.cxx \
  $$SRC_DIR/Misc/vtkCompositeDataToUnstructuredGridFilter.cxx \
  $$SRC_DIR/Misc/vtkDataObjectTreeToPointSetFilter.cxx \
  $$SRC_DIR/Misc/vtkEnvironmentAnnotationFilter.cxx \
  $$SRC_DIR/Misc/vtkExtractHistogram.cxx \
  $$SRC_DIR/Misc/vtkMergeBlocks.cxx \
  $$SRC_DIR/Misc/vtkMinMax.cxx \
  $$SRC_DIR/Misc/vtkPExtractHistogram.cxx \
  $$SRC_DIR/Misc/vtkPVBox.cxx \
  $$SRC_DIR/Misc/vtkPVChangeOfBasisHelper.cxx \
  $$SRC_DIR/Misc/vtkPVCylinder.cxx \
  $$SRC_DIR/Misc/vtkPVMergeTables.cxx \
  $$SRC_DIR/Misc/vtkPVMergeTablesMultiBlock.cxx \
  $$SRC_DIR/Misc/vtkPVPlane.cxx \
  $$SRC_DIR/Misc/vtkPVRotateAroundOriginTransform.cxx \
  $$SRC_DIR/Misc/vtkPVTransform.cxx \
  $$SRC_DIR/Misc/vtkReductionFilter.cxx \
  $$SRC_DIR/Misc/vtkSelectionSerializer.cxx \
  $$SRC_DIR/Points/vtkBoundedPlaneSource.cxx \
  $$SRC_DIR/Points/vtkBoundedVolumeSource.cxx \
  $$SRC_DIR/Testing/DistributedSubsetSortingTable.cxx \
  \# $$SRC_DIR/Testing/ParaViewCoreVTKExtensionsPrintSelf.cxx \
  $$SRC_DIR/Testing/TestContinuousClose3D.cxx \
  \# $$SRC_DIR/Testing/TestExtractHistogram.cxx \
  $$SRC_DIR/Testing/TestExtractScatterPlot.cxx \
  \# $$SRC_DIR/Testing/TestIceTCompositePass.cxx \
  \# $$SRC_DIR/Testing/TestIceTShadowMapPass.cxx \
  \# -- only problem is main ... $$SRC_DIR/Testing/TestIsoVolume.cxx \
  \# $$SRC_DIR/Testing/TestPVAMRDualClip.cxx \
  \# $$SRC_DIR/Testing/TestPVAMRDualContour.cxx \
  $$SRC_DIR/Testing/TestPVFilters.cxx \
  \# $$SRC_DIR/Testing/TestSimpleIceTCompositePass.cxx \
  $$SRC_DIR/Testing/TestSortingTable.cxx \
  \# $$SRC_DIR/Testing/TestSpyPlotTracers.cxx \
  \# $$SRC_DIR/Testing/TestTilesHelper.cxx





