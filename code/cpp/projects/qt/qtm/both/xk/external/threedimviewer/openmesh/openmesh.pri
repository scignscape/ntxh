
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += widgets gui   opengl

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR/src


HEADERS += \
   $$SRC_DIR/src/OpenMesh/Apps/Decimating/CmdOption.hh \
   $$SRC_DIR/src/OpenMesh/Apps/Decimating/DecimaterViewerWidget.hh \
   $$SRC_DIR/src/OpenMesh/Apps/ProgViewer/ProgViewerWidget.hh \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/MeshViewerWidget.hh \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/MeshViewerWidgetT.hh \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/MeshViewerWidgetT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/QGLViewerWidget.hh \
   $$SRC_DIR/src/OpenMesh/Apps/Subdivider/MeshViewerWidget.hh \
   $$SRC_DIR/src/OpenMesh/Apps/Subdivider/SubdivideWidget.hh \
   $$SRC_DIR/src/OpenMesh/Apps/VDProgMesh/Synthesizer/VDPMSynthesizerViewerWidget.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/Config.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/EigenVectorT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/LoopSchemeMaskT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/MathDefs.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/NormalConeT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/NormalConeT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/Plane3d.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/QuadricT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/Vector11T.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/VectorT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Geometry/VectorT_inc.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/BinaryHelper.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/IOInstances.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/IOManager.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/MeshIO.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/OFFFormat.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/OMFormat.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/OMFormatT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/Options.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_binary.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_binary_spec.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_binary_vector_of_bool.inl \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_binary_vector_of_fundamentals.inl \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_binary_vector_of_string.inl \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_rbo.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_store.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/SR_types.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/StoreRestore.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/exporter/BaseExporter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/exporter/ExporterT.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/importer/BaseImporter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/importer/ImporterT.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/BaseReader.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/OBJReader.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/OFFReader.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/OMReader.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/PLYReader.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/STLReader.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/BaseWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/OBJWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/OFFWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/OMWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/PLYWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/STLWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/VTKWriter.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/ArrayItems.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/ArrayKernel.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/ArrayKernelT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/AttribKernelT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/Attributes.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/BaseKernel.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/BaseMesh.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/Casts.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/CirculatorsT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/DefaultPolyMesh.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/DefaultTriMesh.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/FinalMeshItemsT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/Handles.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/IteratorsT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/PolyConnectivity.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/PolyConnectivity_inline_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/PolyMeshT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/PolyMeshT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/SmartHandles.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/SmartRange.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/Status.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/Tags.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/Traits.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/TriConnectivity.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/TriMeshT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/TriMeshT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/gen/circulators_header.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/gen/circulators_template.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/gen/footer.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/gen/iterators_header.hh \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/gen/iterators_template.hh \
   $$SRC_DIR/src/OpenMesh/Core/System/OpenMeshDLLMacros.hh \
   $$SRC_DIR/src/OpenMesh/Core/System/compiler.hh \
   $$SRC_DIR/src/OpenMesh/Core/System/config.h \
   $$SRC_DIR/src/OpenMesh/Core/System/config.hh \
   $$SRC_DIR/src/OpenMesh/Core/System/mostream.hh \
   $$SRC_DIR/src/OpenMesh/Core/System/omstream.hh \
   $$SRC_DIR/src/OpenMesh/Core/Templates/bla.hh \
   $$SRC_DIR/src/OpenMesh/Core/Templates/blaT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/AutoPropertyHandleT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/BaseProperty.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/Endian.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/GenProg.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/HandleToPropHandle.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/Noncopyable.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/Property.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/PropertyContainer.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/PropertyManager.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/RandomNumberGenerator.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/SingletonT.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/SingletonT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/color_cast.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/typename.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/vector_cast.hh \
   $$SRC_DIR/src/OpenMesh/Core/Utils/vector_traits.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/BaseDecimaterT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/BaseDecimaterT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/CollapseInfoT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/DecimaterT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/DecimaterT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/McDecimaterT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/McDecimaterT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/MixedDecimaterT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/MixedDecimaterT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModAspectRatioT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModAspectRatioT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModBaseT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModEdgeLengthT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModEdgeLengthT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModHausdorffT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModHausdorffT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModIndependentSetsT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModNormalDeviationT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModNormalFlippingT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModProgMeshT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModProgMeshT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModQuadricT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModQuadricT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/ModRoundnessT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/Observer.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Dualizer/meshDualT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/ArrayKernelT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/AttribKernelT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/PropertyKernel.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/PropertyT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/Traits.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/TriMesh_OSGArrayKernelT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/VectorAdapter.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/bindT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Kernel_OSG/color_cast.hh \
   $$SRC_DIR/src/OpenMesh/Tools/SmartTagger/SmartTaggerT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/SmartTagger/SmartTaggerT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/JacobiLaplaceSmootherT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/JacobiLaplaceSmootherT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/LaplaceSmootherT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/LaplaceSmootherT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/SmootherT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/SmootherT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Smoother/smooth_mesh.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/CompositeT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/CompositeT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/CompositeTraits.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/RuleInterfaceT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/RulesT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/RulesT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Adaptive/Composite/Traits.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/CatmullClarkT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/CatmullClarkT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/Composite/CompositeT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/Composite/CompositeT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/Composite/CompositeTraits.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/CompositeLoopT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/CompositeSqrt3T.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/LongestEdgeT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/LoopT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/MidpointT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/ModifiedButterFlyT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/Sqrt3InterpolatingSubdividerLabsikGreinerT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/Sqrt3T.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Subdivider/Uniform/SubdividerT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/Config.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/GLConstAsString.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/Gnuplot.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/HeapT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/MeshCheckerT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/MeshCheckerT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/NumLimitsT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/StripifierT.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/StripifierT_impl.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/TestingFramework.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/Timer.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/conio.hh \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/getopt.h \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/MeshTraits.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/StreamingDef.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VFront.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchy.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchyNode.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchyNodeIndex.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchyWindow.hh \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/ViewingParameters.hh

#   $$SRC_DIR/src/OpenMesh/Apps/Decimating/DecimaterViewerWidget.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/Decimating/decimater.cc \
#   \#main $$SRC_DIR/src/OpenMesh/Apps/Decimating/decimaterviewer.cc \
#   \#main $$SRC_DIR/src/OpenMesh/Apps/Dualizer/dualizer.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/ProgViewer/progviewer.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/QGLViewerWidget.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/meshviewer.cc \
#   \#main $$SRC_DIR/src/OpenMesh/Apps/Smoothing/smooth.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/Subdivider/SubdivideWidget.cc \
#   \#main $$SRC_DIR/src/OpenMesh/Apps/Subdivider/adaptive_subdivider.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/Subdivider/qtsubdivider.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/Subdivider/subdivider.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/VDProgMesh/Analyzer/vdpmanalyzer.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/VDProgMesh/Synthesizer/VDPMSynthesizerViewerWidget.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/VDProgMesh/Synthesizer/vdpmsynthesizer.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/VDProgMesh/mkbalancedpm/mkbalancedpm.cc \
#   $$SRC_DIR/src/OpenMesh/Apps/mconvert/mconvert.cc \


SOURCES += \
   $$SRC_DIR/src/OpenMesh/Apps/Subdivider/SubdivideWidget.cc \
   $$SRC_DIR/src/OpenMesh/Apps/Decimating/DecimaterViewerWidget.cc \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/MeshViewerWidget.cc \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/QGLViewerWidget.cc \
   $$SRC_DIR/src/OpenMesh/Apps/ProgViewer/ProgViewerWidget.cc \
   $$SRC_DIR/src/OpenMesh/Apps/VDProgMesh/Synthesizer/VDPMSynthesizerViewerWidget.cc \
   $$SRC_DIR/src/OpenMesh/Apps/QtViewer/meshviewer.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/BinaryHelper.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/IOManager.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/OMFormat.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/BaseReader.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/OBJReader.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/OFFReader.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/OMReader.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/PLYReader.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/reader/STLReader.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/BaseWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/OBJWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/OFFWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/OMWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/PLYWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/STLWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/IO/writer/VTKWriter.cc \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/ArrayKernel.cc \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/BaseKernel.cc \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/PolyConnectivity.cc \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/SmartHandles.cc \
   $$SRC_DIR/src/OpenMesh/Core/Mesh/TriConnectivity.cc \
   $$SRC_DIR/src/OpenMesh/Core/System/omstream.cc \
   $$SRC_DIR/src/OpenMesh/Core/Utils/BaseProperty.cc \
   $$SRC_DIR/src/OpenMesh/Core/Utils/Endian.cc \
   $$SRC_DIR/src/OpenMesh/Core/Utils/RandomNumberGenerator.cc \
   $$SRC_DIR/src/OpenMesh/Tools/Decimater/Observer.cc \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/Gnuplot.cc \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/Timer.cc \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/conio.cc \
   $$SRC_DIR/src/OpenMesh/Tools/Utils/getopt.c \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VFront.cc \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchy.cc \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchyNodeIndex.cc \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/VHierarchyWindow.cc \
   $$SRC_DIR/src/OpenMesh/Tools/VDPM/ViewingParameters.cc


