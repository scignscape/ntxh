
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets xml concurrent network  #opengl sql testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)

#DEFINES += DTKLOGEXPORT


#DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

#
DTK_META_EXPORT_INCLUDES_DIR =   $$SRC_GROUP_DIR/dtk-meta-export-includes


#
INCLUDEPATH += $$SRC_DIR/inc/dtkComposerSupport

INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog

INCLUDEPATH += $$SRC_GROUP_DIR/dtkWidgets/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkDistributedSupport/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkGuiSupport/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkContainerSupport/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc/dtkCore

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta

INCLUDEPATH += $$SRC_GROUP_DIR/dtkComposer/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkPlotSupport/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkVrSupport/inc


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc



#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkLog
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkComposer
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkCore
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMeta
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkGuiSupport
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkWidgets
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkDistributed
#INCLUDEPATH += $$DTK_META_EXTRA_INCLUDES_DIR/dtk/src/dtkMath



HEADERS +=  \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposer.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerCompass.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControls.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsDelegate.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItem.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemBoolean.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemFactory.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemFile.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemInteger.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemLeafProcess.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemReal.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemString.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluator.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluator_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluatorProcess.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluatorSlave.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerFactory.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerFactoryView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraph.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphEdge.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphLayouter.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNode.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeBegin.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeEnd.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeLeaf.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSelectBranch.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSetInputs.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSetOutputs.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSetVariables.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerMachine.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerMachineState.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerMetatype.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNode.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayData.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayDataExtractor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayDataOperatorModifier.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayScalar.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayScalarExtractor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayScalarOperatorModifier.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeBoolean.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeBooleanOperator.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeComposite.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeConstants.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeContainerData.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControl.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlCase.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlDoWhile.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlFor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlForEach.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlIf.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlMap.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlWhile.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeData.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeDistributed.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeFile.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeFile_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeInteger.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeaf.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafActor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafData.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafDataSupport.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafProcess.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafProcessSupport.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafViewSupport.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLogger.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareReal.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareRealExtractor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareRealOperatorBinary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareRealOperatorUnary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArray.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArrayAppend.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArrayExtractor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArrayReplace.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaVector3DArray.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaVector3DArrayAppend.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaVector3DArrayExtractor.h \
  \# $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMovieWriter.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeNumberOperator.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotCurve.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotCurveAppendPoint.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotCurveFile.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePrint.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeProcess.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeProxy.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeQuaternion.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeQuaternionOperatorBinary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeQuaternionOperatorUnary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeReal.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeRemote.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeRemote_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeSpawn.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeSpawn_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeString.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeStringOperator.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeTrackerKinect.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeTrackerVrpn.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3D.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3DOperatorBinary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3DOperatorTernary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3DOperatorUnary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorInteger.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerExtractor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerOperatorBinary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerOperatorModifier.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerOperatorUnary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorOperator.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorReal.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealExtractor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealOperatorBinary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealOperatorModifier.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealOperatorUnary.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeWorld.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposer_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerPath.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerReader.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerScene.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneEdge.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneModel.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNode.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeComposite.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeControl.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeEditor.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeEditor_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeHandle.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeLeaf.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNode_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNote.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerScene_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerScenePort.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSearchDialog.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStack.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStackCommand.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStackUtils.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStackView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSupportFactoryExtension.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitter.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterAbstractEmitter.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterAbstractReceiver.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterEmitter.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitter_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterProxy.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterReceiver.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterVariant.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterVariant_p.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerView.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerWriter.h \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposer \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerCompass \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControls \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsDelegate \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItem \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemBoolean \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemFactory \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemFile \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemInteger \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemLeafProcess \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemReal \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerControlsListItemString \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluator \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluator_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluatorProcess \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerEvaluatorSlave \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerFactory \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerFactoryView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraph \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphEdge \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphLayouter \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNode \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeBegin \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeEnd \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeLeaf \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSelectBranch \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSetInputs \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSetOutputs \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphNodeSetVariables \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerGraphView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerMachine \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerMachineState \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerMetatype \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNode \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayData \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayDataExtractor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayDataOperatorModifier \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayScalar \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayScalarExtractor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeArrayScalarOperatorModifier \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeBoolean \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeBooleanOperator \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeComposite \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeConstants \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeContainerData \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControl \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlCase \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlDoWhile \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlFor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlForEach \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlIf \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlMap \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeControlWhile \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeData \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeDistributed \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeFile \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeFile_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeInteger \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeaf \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafActor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafData \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafProcess \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLeafView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeLogger \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareReal \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareRealExtractor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareRealOperatorBinary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMatrixSquareRealOperatorUnary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArray \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArrayAppend \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArrayExtractor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaScalarArrayReplace \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaVector3DArray \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaVector3DArrayAppend \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMetaVector3DArrayExtractor \
  \# $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeMovieWriter \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeNumberOperator \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotCurve \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotCurveAppendPoint \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotCurveFile \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePlotView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodePrint \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeProcess \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeProxy \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeQuaternion \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeQuaternionOperatorBinary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeQuaternionOperatorUnary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeReal \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeRemote \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeRemote_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeSpawn \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeSpawn_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeString \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeStringOperator \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeTrackerKinect \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeTrackerVrpn \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3D \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3DOperatorBinary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3DOperatorTernary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVector3DOperatorUnary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorInteger \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerExtractor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerOperatorBinary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerOperatorModifier \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorIntegerOperatorUnary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorOperator \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorReal \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealExtractor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealOperatorBinary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealOperatorModifier \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeVectorRealOperatorUnary \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerNodeWorld \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposer_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerPath \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerReader \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerScene \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneEdge \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneModel \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNode \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeComposite \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeControl \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeEditor \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeEditor_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeHandle \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNodeLeaf \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNode_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneNote \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerScene_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerScenePort \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSceneView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerSearchDialog \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStack \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStackCommand \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStackUtils \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerStackView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitter \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterAbstractEmitter \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterAbstractReceiver \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterEmitter \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterEmitter.tpp \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitter_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterProxy \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterReceiver \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterReceiver.tpp \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterVariant \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterVariant.tpp \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerTransmitterVariant_p \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerView \
  $$SRC_DIR/inc/dtkComposerSupport/dtkComposerWriter \


SOURCES +=  \
  $$SRC_DIR/dtkComposer.cpp \
  $$SRC_DIR/dtkComposerCompass.cpp \
  $$SRC_DIR/dtkComposerControls.cpp \
  $$SRC_DIR/dtkComposerControlsDelegate.cpp \
  $$SRC_DIR/dtkComposerControlsListItem.cpp \
  $$SRC_DIR/dtkComposerControlsListItemBoolean.cpp \
  $$SRC_DIR/dtkComposerControlsListItemFactory.cpp \
  $$SRC_DIR/dtkComposerControlsListItemFile.cpp \
  $$SRC_DIR/dtkComposerControlsListItemInteger.cpp \
  $$SRC_DIR/dtkComposerControlsListItemLeafProcess.cpp \
  $$SRC_DIR/dtkComposerControlsListItemReal.cpp \
  $$SRC_DIR/dtkComposerControlsListItemString.cpp \
  $$SRC_DIR/dtkComposerEvaluator.cpp \
  $$SRC_DIR/dtkComposerEvaluatorProcess.cpp \
  $$SRC_DIR/dtkComposerEvaluatorSlave.cpp \
  $$SRC_DIR/dtkComposerFactory.cpp \
  $$SRC_DIR/dtkComposerFactoryView.cpp \
  $$SRC_DIR/dtkComposerGraph.cpp \
  $$SRC_DIR/dtkComposerGraphEdge.cpp \
  $$SRC_DIR/dtkComposerGraphLayouter.cpp \
  $$SRC_DIR/dtkComposerGraphNode.cpp \
  $$SRC_DIR/dtkComposerGraphNodeBegin.cpp \
  $$SRC_DIR/dtkComposerGraphNodeEnd.cpp \
  $$SRC_DIR/dtkComposerGraphNodeLeaf.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSelectBranch.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSetInputs.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSetOutputs.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSetVariables.cpp \
  $$SRC_DIR/dtkComposerGraphView.cpp \
  $$SRC_DIR/dtkComposerMachine.cpp \
  $$SRC_DIR/dtkComposerMachineState.cpp \
  $$SRC_DIR/dtkComposerNode.cpp \
  $$SRC_DIR/dtkComposerNodeArrayData.cpp \
  $$SRC_DIR/dtkComposerNodeArrayDataExtractor.cpp \
  $$SRC_DIR/dtkComposerNodeArrayDataOperatorModifier.cpp \
  $$SRC_DIR/dtkComposerNodeArrayScalar.cpp \
  $$SRC_DIR/dtkComposerNodeArrayScalarExtractor.cpp \
  $$SRC_DIR/dtkComposerNodeArrayScalarOperatorModifier.cpp \
  $$SRC_DIR/dtkComposerNodeBoolean.cpp \
  $$SRC_DIR/dtkComposerNodeBooleanOperator.cpp \
  $$SRC_DIR/dtkComposerNodeComposite.cpp \
  $$SRC_DIR/dtkComposerNodeConstants.cpp \
  $$SRC_DIR/dtkComposerNodeContainerData.cpp \
  $$SRC_DIR/dtkComposerNodeControl.cpp \
  $$SRC_DIR/dtkComposerNodeControlCase.cpp \
  $$SRC_DIR/dtkComposerNodeControlDoWhile.cpp \
  $$SRC_DIR/dtkComposerNodeControlFor.cpp \
  $$SRC_DIR/dtkComposerNodeControlForEach.cpp \
  $$SRC_DIR/dtkComposerNodeControlIf.cpp \
  $$SRC_DIR/dtkComposerNodeControlMap.cpp \
  $$SRC_DIR/dtkComposerNodeControlWhile.cpp \
  $$SRC_DIR/dtkComposerNodeData.cpp \
  $$SRC_DIR/dtkComposerNodeDistributed.cpp \
  $$SRC_DIR/dtkComposerNodeFile.cpp \
  $$SRC_DIR/dtkComposerNodeInteger.cpp \
  $$SRC_DIR/dtkComposerNodeLeaf.cpp \
  $$SRC_DIR/dtkComposerNodeLeafActor.cpp \
  $$SRC_DIR/dtkComposerNodeLeafData.cpp \
  $$SRC_DIR/dtkComposerNodeLeafDataSupport.cpp \
  $$SRC_DIR/dtkComposerNodeLeafProcess.cpp \
  $$SRC_DIR/dtkComposerNodeLeafProcessSupport.cpp \
  $$SRC_DIR/dtkComposerNodeLeafView.cpp \
  $$SRC_DIR/dtkComposerNodeLeafViewSupport.cpp \
  $$SRC_DIR/dtkComposerNodeLogger.cpp \
  $$SRC_DIR/dtkComposerNodeMatrixSquareReal.cpp \
  $$SRC_DIR/dtkComposerNodeMatrixSquareRealExtractor.cpp \
  $$SRC_DIR/dtkComposerNodeMatrixSquareRealOperatorBinary.cpp \
  $$SRC_DIR/dtkComposerNodeMatrixSquareRealOperatorUnary.cpp \
  $$SRC_DIR/dtkComposerNodeMetaScalarArray.cpp \
  $$SRC_DIR/dtkComposerNodeMetaScalarArrayAppend.cpp \
  $$SRC_DIR/dtkComposerNodeMetaScalarArrayExtractor.cpp \
  $$SRC_DIR/dtkComposerNodeMetaScalarArrayReplace.cpp \
  $$SRC_DIR/dtkComposerNodeMetaVector3DArray.cpp \
  $$SRC_DIR/dtkComposerNodeMetaVector3DArrayAppend.cpp \
  $$SRC_DIR/dtkComposerNodeMetaVector3DArrayExtractor.cpp \
  \# $$SRC_DIR/dtkComposerNodeMovieWriter.cpp \
  $$SRC_DIR/dtkComposerNodeNumberOperator.cpp \
  $$SRC_DIR/dtkComposerNodePlotCurve.cpp \
  $$SRC_DIR/dtkComposerNodePlotCurveAppendPoint.cpp \
  $$SRC_DIR/dtkComposerNodePlotCurveFile.cpp \
  $$SRC_DIR/dtkComposerNodePlotView.cpp \
  $$SRC_DIR/dtkComposerNodePrint.cpp \
  $$SRC_DIR/dtkComposerNodeProcess.cpp \
  $$SRC_DIR/dtkComposerNodeProxy.cpp \
  $$SRC_DIR/dtkComposerNodeQuaternion.cpp \
  $$SRC_DIR/dtkComposerNodeQuaternionOperatorBinary.cpp \
  $$SRC_DIR/dtkComposerNodeQuaternionOperatorUnary.cpp \
  $$SRC_DIR/dtkComposerNodeReal.cpp \
  $$SRC_DIR/dtkComposerNodeRemote.cpp \
  $$SRC_DIR/dtkComposerNodeSpawn.cpp \
  $$SRC_DIR/dtkComposerNodeString.cpp \
  $$SRC_DIR/dtkComposerNodeStringOperator.cpp \
  $$SRC_DIR/dtkComposerNodeTrackerKinect.cpp \
  $$SRC_DIR/dtkComposerNodeTrackerVrpn.cpp \
  $$SRC_DIR/dtkComposerNodeVector3D.cpp \
  $$SRC_DIR/dtkComposerNodeVector3DOperatorBinary.cpp \
  $$SRC_DIR/dtkComposerNodeVector3DOperatorTernary.cpp \
  $$SRC_DIR/dtkComposerNodeVector3DOperatorUnary.cpp \
  $$SRC_DIR/dtkComposerNodeVectorInteger.cpp \
  $$SRC_DIR/dtkComposerNodeVectorIntegerExtractor.cpp \
  $$SRC_DIR/dtkComposerNodeVectorIntegerOperatorBinary.cpp \
  $$SRC_DIR/dtkComposerNodeVectorIntegerOperatorModifier.cpp \
  $$SRC_DIR/dtkComposerNodeVectorIntegerOperatorUnary.cpp \
  $$SRC_DIR/dtkComposerNodeVectorOperator.cpp \
  $$SRC_DIR/dtkComposerNodeVectorReal.cpp \
  $$SRC_DIR/dtkComposerNodeVectorRealExtractor.cpp \
  $$SRC_DIR/dtkComposerNodeVectorRealOperatorBinary.cpp \
  $$SRC_DIR/dtkComposerNodeVectorRealOperatorModifier.cpp \
  $$SRC_DIR/dtkComposerNodeVectorRealOperatorUnary.cpp \
  $$SRC_DIR/dtkComposerNodeView.cpp \
  $$SRC_DIR/dtkComposerNodeWorld.cpp \
  $$SRC_DIR/dtkComposerPath.cpp \
  $$SRC_DIR/dtkComposerReader.cpp \
  $$SRC_DIR/dtkComposerScene.cpp \
  $$SRC_DIR/dtkComposerSceneEdge.cpp \
  $$SRC_DIR/dtkComposerSceneModel.cpp \
  $$SRC_DIR/dtkComposerSceneNode.cpp \
  $$SRC_DIR/dtkComposerSceneNodeComposite.cpp \
  $$SRC_DIR/dtkComposerSceneNodeControl.cpp \
  $$SRC_DIR/dtkComposerSceneNodeEditor.cpp \
  $$SRC_DIR/dtkComposerSceneNodeHandle.cpp \
  $$SRC_DIR/dtkComposerSceneNodeLeaf.cpp \
  $$SRC_DIR/dtkComposerSceneNote.cpp \
  $$SRC_DIR/dtkComposerScenePort.cpp \
  $$SRC_DIR/dtkComposerSceneView.cpp \
  $$SRC_DIR/dtkComposerSearchDialog.cpp \
  $$SRC_DIR/dtkComposerStack.cpp \
  $$SRC_DIR/dtkComposerStackCommand.cpp \
  $$SRC_DIR/dtkComposerStackUtils.cpp \
  $$SRC_DIR/dtkComposerStackView.cpp \
  $$SRC_DIR/dtkComposerSupportFactoryExtension.cpp \
  $$SRC_DIR/dtkComposerTransmitter.cpp \
  $$SRC_DIR/dtkComposerTransmitterAbstractEmitter.cpp \
  $$SRC_DIR/dtkComposerTransmitterAbstractReceiver.cpp \
  $$SRC_DIR/dtkComposerTransmitterEmitter.cpp \
  $$SRC_DIR/dtkComposerTransmitterProxy.cpp \
  $$SRC_DIR/dtkComposerTransmitterVariant.cpp \
  $$SRC_DIR/dtkComposerView.cpp \
  $$SRC_DIR/dtkComposerWriter.cpp \




