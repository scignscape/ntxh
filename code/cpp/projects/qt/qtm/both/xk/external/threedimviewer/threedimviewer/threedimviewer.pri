
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += widgets gui printsupport network

CONFIG += c++14


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/flann.pri)


DEFINES += FORCE_EXS_JPEGProcess14SV1

#INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include
INCLUDEPATH += $$SRC_DIR/include/3dim
INCLUDEPATH += $$SRC_DIR/include/3dim/core
#INCLUDEPATH += $$SRC_DIR/include/3dim/qtgui
INCLUDEPATH += $$SRC_DIR/include/3dim/coremedi
INCLUDEPATH += $$SRC_DIR/include/3dim/coremedi_viewer
INCLUDEPATH += $$SRC_DIR/include/3dim/qtgui_viewer
INCLUDEPATH += $$SRC_DIR/include/3dim/graph
INCLUDEPATH += $$SRC_DIR/include/3dim/qtplugin
INCLUDEPATH += $$SRC_DIR/include/3dim/graphmedi_viewer
INCLUDEPATH += $$SRC_DIR/include/3dim/graphmedi
INCLUDEPATH += $$SRC_DIR/include/3dim/qtgui

INCLUDEPATH += $$SRC_GROUP_DIR/3dv-applications/3DimViewer/include/



# #  for dcmtk ...
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmdata/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcm-config/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/ofstd/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmimgle/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/oflog/include
INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk/dcmjpeg/include

INCLUDEPATH += $$SRC_GROUP_DIR/vpl/include


DEFINES += _LINUX

DEFINES += assert\\(x\\)


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk
INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/Eigen

INCLUDEPATH += $$SRC_DIR/include/3dim/qtguimedi

#message($$SRC_DIR/include/3dim)

# need openscenegraph installed ...

include($$ROOT_DIR/../preferred/osg.pri)
include($$ROOT_DIR/../preferred/openmesh.pri)
include($$ROOT_DIR/../preferred/openctm.pri)



SOURCES += \
  $$SRC_DIR/core/alg/CDecimator.cpp \
  $$SRC_DIR/core/alg/CMarchingCubes.cpp \
  $$SRC_DIR/core/alg/CReduceSmallSubmeshes.cpp \
  $$SRC_DIR/core/alg/CRegionCounter.cpp \
  $$SRC_DIR/core/alg/CSmoothing.cpp \
  $$SRC_DIR/core/alg/MultiStageProgress.cpp \
  $$SRC_DIR/core/alg/TriIterator.cpp \
  $$SRC_DIR/core/app/CProductInfo.cpp \
  $$SRC_DIR/core/data/CAppSettings.cpp \
  $$SRC_DIR/core/data/CChangedEntries.cpp \
  $$SRC_DIR/core/data/CDataStorage.cpp \
  $$SRC_DIR/core/data/CEntryChangeLog.cpp \
  $$SRC_DIR/core/data/CEntryFlags.cpp \
  $$SRC_DIR/core/data/CSerializationManager.cpp \
  $$SRC_DIR/core/data/CStorageEntry.cpp \
  $$SRC_DIR/core/data/CStorageIdRemapperBase.cpp \
  $$SRC_DIR/core/data/CUndoBase.cpp \
  $$SRC_DIR/core/data/CUndoManager.cpp \
  $$SRC_DIR/core/math/sha1.cpp \
  $$SRC_DIR/core/osg/osgcompat.cpp \
  $$SRC_DIR/coremedi/data/CArbitrarySlice.cpp \
  $$SRC_DIR/coremedi/data/CColorTable.cpp \
  $$SRC_DIR/coremedi/data/CCoordinatesConv.cpp \
  $$SRC_DIR/coremedi/data/CDataStats.cpp \
  $$SRC_DIR/coremedi/data/CDensityData.cpp \
  $$SRC_DIR/coremedi/data/CDensityWindow.cpp \
  $$SRC_DIR/coremedi/data/CDicom.cpp \
  $$SRC_DIR/coremedi/data/CDicomDCTk.cpp \
  $$SRC_DIR/coremedi/data/CDicomGDCM.cpp \
  $$SRC_DIR/coremedi/data/CDicomLoader.cpp \
  \#  $SRC_DIR/coremedi/data/CDicomSaverDCTk.cpp \
  $$SRC_DIR/coremedi/data/CDicomSaverGDCM.cpp \
  $$SRC_DIR/coremedi/data/CMeasurementOptions.cpp \
  $$SRC_DIR/coremedi/data/CModel.cpp \
  $$SRC_DIR/coremedi/data/CModelCut.cpp \
  $$SRC_DIR/coremedi/data/CModelManager.cpp \
  $$SRC_DIR/coremedi/data/CMultiClassRegionColoring.cpp \
  $$SRC_DIR/coremedi/data/CMultiClassRegionData.cpp \
  $$SRC_DIR/coremedi/data/CMultiClassRegionsVisualizer.cpp \
  $$SRC_DIR/coremedi/data/COrthoSlice.cpp \
  $$SRC_DIR/coremedi/data/CPivot.cpp \
  $$SRC_DIR/coremedi/data/CPreviewModel.cpp \
  $$SRC_DIR/coremedi/data/CRegionColoring.cpp \
  $$SRC_DIR/coremedi/data/CRegionData.cpp \
  $$SRC_DIR/coremedi/data/CRestorePoint.cpp \
  $$SRC_DIR/coremedi/data/CSeries.cpp \
  $$SRC_DIR/coremedi/data/CSlice.cpp \
  $$SRC_DIR/coremedi/data/CStorageIdRemapper.cpp \
  $$SRC_DIR/coremedi/data/CVolumeOfInterest.cpp \
  $$SRC_DIR/coremedi/data/CVolumeOfInterestData.cpp \
  $$SRC_DIR/coremedi/data/CVolumeTransformation.cpp \
  $$SRC_DIR/coremedi/data/CVolumeUndo.cpp \
  $$SRC_DIR/coremedi/data/Notes.cpp \
  $$SRC_DIR/coremedi_viewer/data/CExamination.cpp \
  $$SRC_DIR/coremedi_viewer/data/CRegionDataCalculator.cpp \
  $$SRC_DIR/coremedi_viewer/data/CRegionsVisualizer.cpp \
  $$SRC_DIR/coremedi_viewer/data/CSceneWidgetParameters.cpp \
  $$SRC_DIR/coremedi_viewer/data/CVolumeOfInterestVisualizer.cpp \
  $$SRC_DIR/geometry/alg/CPlaneFitting.cpp \
  $$SRC_DIR/geometry/base/CAction.cpp \
  $$SRC_DIR/geometry/base/CArmature.cpp \
  $$SRC_DIR/geometry/base/CBaseMesh.cpp \
  $$SRC_DIR/geometry/base/CBone.cpp \
  $$SRC_DIR/geometry/base/CBoneSnapshot.cpp \
  $$SRC_DIR/geometry/base/CKeyframe.cpp \
  $$SRC_DIR/geometry/base/CMesh.cpp \
  $$SRC_DIR/geometry/base/CPlane.cpp \
  $$SRC_DIR/geometry/base/CTMReader.cpp \
  $$SRC_DIR/geometry/base/CTMWriter.cpp \
  $$SRC_DIR/geometry/base/CTrianglesContainer.cpp \
  $$SRC_DIR/geometry/base/MTLReader.cpp \
  $$SRC_DIR/geometry/base/OBJReader.cpp \
  $$SRC_DIR/geometry/base/clipper.cpp \
  $$SRC_DIR/geometry/base/clipperExtension.cpp \
  $$SRC_DIR/geometry/base/functions.cpp \
  $$SRC_DIR/geometry/base/kdtree/CFlannTree.cpp \
  $$SRC_DIR/geometry/base/kdtree/CMeshIndexing.cpp \
  $$SRC_DIR/geometry/base/kdtree/kdtree.cpp \
  $$SRC_DIR/geometry/base/polygonOperations.cpp \
  $$SRC_DIR/geometry/metrics/hausdorff.cpp \
  $$SRC_DIR/graph/osg/BoundingRectangle.cpp \
  $$SRC_DIR/graph/osg/CActiveObjectBase.cpp \
  $$SRC_DIR/graph/osg/CBoundingBoxVisitor.cpp \
  $$SRC_DIR/graph/osg/CConvertToGeometry.cpp \
  $$SRC_DIR/graph/osg/CCylinderDragger.cpp \
  $$SRC_DIR/graph/osg/CDraggableGeometry.cpp \
  $$SRC_DIR/graph/osg/CDummyOSG.cpp \
  $$SRC_DIR/graph/osg/CEventHandlerBase.cpp \
  $$SRC_DIR/graph/osg/CFreeModelVisualizer.cpp \
  $$SRC_DIR/graph/osg/CGeometryGenerator.cpp \
  $$SRC_DIR/graph/osg/CGetNodePathVisitor.cpp \
  $$SRC_DIR/graph/osg/CMarchingCubesFast.cpp \
  $$SRC_DIR/graph/osg/CModelDragger3D.cpp \
  $$SRC_DIR/graph/osg/CModelVisualizer.cpp \
  $$SRC_DIR/graph/osg/COnOffNode.cpp \
  $$SRC_DIR/graph/osg/CPlaneConstraint.cpp \
  $$SRC_DIR/graph/osg/CPlaneUpdateSelection.cpp \
  $$SRC_DIR/graph/osg/CPolytopePlaneTester.cpp \
  $$SRC_DIR/graph/osg/CPseudoMaterial.cpp \
  $$SRC_DIR/graph/osg/CPseudoMaterialCache.cpp \
  $$SRC_DIR/graph/osg/CRotate2DDragger.cpp \
  \# $$SRC_DIR/graph/osg/CScreenshot.cpp \
  \# $$SRC_DIR/graph/osg/CShaderTester.cpp \
  $$SRC_DIR/graph/osg/CSignalEventHandler.cpp \
  $$SRC_DIR/graph/osg/CSprite.cpp \
  $$SRC_DIR/graph/osg/CThickLineMaterial.cpp \
  $$SRC_DIR/graph/osg/CTools.cpp \
  $$SRC_DIR/graph/osg/CTranslate1DDragger.cpp \
  $$SRC_DIR/graph/osg/CTranslate2DDragger.cpp \
  $$SRC_DIR/graph/osg/CTranslateOtherLineDragger.cpp \
  $$SRC_DIR/graph/osg/CTriMesh.cpp \
  $$SRC_DIR/graph/osg/Constraints.cpp \
  $$SRC_DIR/graph/osg/MouseDraw.cpp \
  $$SRC_DIR/graph/osg/OSGTreeAnalyser.cpp \
  $$SRC_DIR/graph/osg/OSGTreeAnalyserTranslations.cpp \
  $$SRC_DIR/graph/render/glErrorReporting.cpp \
  $$SRC_DIR/graph/widgets/CPositionedWindow.cpp \
  $$SRC_DIR/graph/widgets/CSizeableWindowManager.cpp \
  $$SRC_DIR/graphmedi/draggers/CDraggerBaseComposite.cpp \
  $$SRC_DIR/graphmedi/draggers/CDraggerOnSurface.cpp \
  $$SRC_DIR/graphmedi/draggers/CDraggerPlane.cpp \
  $$SRC_DIR/graphmedi/draggers/CDraggerRotate.cpp \
  $$SRC_DIR/graphmedi/draggers/CDraggerScale.cpp \
  $$SRC_DIR/graphmedi/draggers/CDraggerTranslate.cpp \
  $$SRC_DIR/graphmedi/drawing/CISEventHandler.cpp \
  $$SRC_DIR/graphmedi/drawing/CLineOptimizer.cpp \
  $$SRC_DIR/graphmedi/osg/CCommandEventHandler.cpp \
  $$SRC_DIR/graphmedi/osg/CDensityWindowEventHandler.cpp \
  $$SRC_DIR/graphmedi/osg/CIntersectionHandler.cpp \
  $$SRC_DIR/graphmedi/osg/CLimiterSceneOSG.cpp \
  $$SRC_DIR/graphmedi/osg/CMeasurementsEH.cpp \
  $$SRC_DIR/graphmedi/osg/CModelCutVisualizer.cpp \
  $$SRC_DIR/graphmedi/osg/CModifiedScaleCommand.cpp \
  $$SRC_DIR/graphmedi/osg/COrthoSceneOSG.cpp \
  $$SRC_DIR/graphmedi/osg/CSliceDragger.cpp \
  $$SRC_DIR/graphmedi/osg/NoteSubtree.cpp \
  $$SRC_DIR/graphmedi/osg/SceneDraw.cpp \
  $$SRC_DIR/graphmedi/render/CGraficCardDesc.cpp \
  $$SRC_DIR/graphmedi/render/CLookupTable.cpp \
  $$SRC_DIR/graphmedi/render/CSceneVolumeRendering.cpp \
  $$SRC_DIR/graphmedi/widgets/CSceneWidget.cpp \
  $$SRC_DIR/graphmedi/widgets/CWidgetOverlayNode.cpp \
  $$SRC_DIR/graphmedi_viewer/drawing/CISEventHandlerEx.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CArbitrarySliceGeometry.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CArbitrarySliceVisualizer.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CArbitrarySliceVisualizer2D.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CDraggableSlice.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CDraggerEventHandler.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/COrthoSlicesVisualizer2D.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CSceneManipulator.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/CSceneOSG.cpp \
  $$SRC_DIR/graphmedi_viewer/osg/OrthoManipulator.cpp \
  $$SRC_DIR/graphmedi_viewer/render/PSVRosg.cpp \
  \# $$SRC_DIR/graphmedi_viewer/render/PSVRrenderer.cpp \
  $$SRC_DIR/graphmedi_viewer/widgets/Widgets.cpp \
  $$SRC_DIR/pcheader.cpp \
  $$SRC_DIR/qtgui/actlog/ceventfilter.cpp \
  $$SRC_DIR/qtgui/controls/CDoubleSlider.cpp \
  $$SRC_DIR/qtgui/controls/CIconGroupBox.cpp \
  $$SRC_DIR/qtgui/controls/CScaledCursor.cpp \
  $$SRC_DIR/qtgui/controls/QRoundProgressBar.cpp \
  $$SRC_DIR/qtgui/controls/ccollapsiblegroupbox.cpp \
  $$SRC_DIR/qtgui/data/CCustomData.cpp \
  $$SRC_DIR/qtgui/data/CImageGrid.cpp \
  $$SRC_DIR/qtgui/data/CReportGenerator.cpp \
  $$SRC_DIR/qtgui/data/CReportPage.cpp \
  $$SRC_DIR/qtgui/data/CReportPageContent.cpp \
  $$SRC_DIR/qtgui/data/CReportTable.cpp \
  $$SRC_DIR/qtgui/osgQt/QFontImplementation.cpp \
  $$SRC_DIR/qtgui/osgQt/QGraphicsViewAdapter.cpp \
  $$SRC_DIR/qtgui/osgQt/QWidgetImage.cpp \
  $$SRC_DIR/qtgui/osgQt/QtOsg.cpp \
  $$SRC_DIR/qtgui_viewer/osg/OSGCanvas.cpp \
  $$SRC_DIR/qtgui_viewer/osg/OSGOrtho2DCanvas.cpp \
  $$SRC_DIR/qtgui_viewer/render/cvolumerendererwindow.cpp \
  $$SRC_DIR/qtguimedi/controls/ccolorcombobox.cpp \
  $$SRC_DIR/qtplugin/CPluginInfoDialog.cpp \
  $$SRC_DIR/qtplugin/CPluginManager.cpp



LIBS += -L$$TARGETSDIR 



