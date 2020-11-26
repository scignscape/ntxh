
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets xml network concurrent  svg  #opengl sql network xml testlib svg

#INCLUDEPATH += $$SRC_GROUP_DIR

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)

#DEFINES += DTKLOGEXPORT


#DTK_META_SRC_DIR =   $$SRC_DIR/devdtk/dtk/src

#
DTK_META_EXPORT_INCLUDES_DIR =   $$SRC_GROUP_DIR/dtk-meta-export-includes

#DTK_META_APP_DIR =   $$SRC_DIR/devdtk/dtk/app

#
INCLUDEPATH += $$SRC_DIR/inc/dtkComposer
INCLUDEPATH += $$SRC_DIR/inc


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

#

INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCore/inc/dtkCore

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMeta/inc/dtkMeta

INCLUDEPATH += $$SRC_GROUP_DIR/dtkDistributed/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkDistributed/inc/dtkDistributed

INCLUDEPATH += $$SRC_GROUP_DIR/dtkWidgets/inc

INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMath/inc/dtkMath

INCLUDEPATH += $$SRC_GROUP_DIR/dtkPlotSupport/inc



INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog

INCLUDEPATH += $$SRC_GROUP_DIR/dtkContainerSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc


INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc



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
  $$SRC_DIR/inc/dtkComposer/dtkComposer \
  $$SRC_DIR/inc/dtkComposer/dtkComposer.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerCompass \
  $$SRC_DIR/inc/dtkComposer/dtkComposerCompass.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControls \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControls.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsDelegate \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsDelegate.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItem.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItemBoolean.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItemFactory.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItemFile.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItemInteger.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItemReal.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerControlsListItemString.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerDefaultExtensions.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluator \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluator.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluator_p \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluator_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluatorProcess.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluatorSlave.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerEvaluatorToolBar.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerExtension.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraph \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraph.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphEdge \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphEdge.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNode \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNode.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeBegin \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeBegin.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeBeginForEach.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeEnd \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeEnd.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeLeaf \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeLeaf.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSelectBranch \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSelectBranch.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSetInputs \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSetInputs.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSetOutputs \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSetOutputs.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSetVariables \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphNodeSetVariables.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphView \
  $$SRC_DIR/inc/dtkComposer/dtkComposerGraphView.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerMetaType.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNode \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNode.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeBoolean \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeBoolean.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeBooleanOperator \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeBooleanOperator.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeBoolean_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeComposite \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeComposite.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeConstants \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeConstants.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControl \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControl.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlCase \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlCase.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlDoWhile \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlDoWhile.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlFor \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlFor.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlForEach \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlForEach.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlIf \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlIf.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlMap \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlMap.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlParallelMap.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlWhile \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeControlWhile.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeDistributed \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeDistributed.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeExec.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeFactory.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeFactoryView.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeFile \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeFile.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeFile_p \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeFile_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeGraph \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeGraph.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeGraphEdge \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeGraphEdge.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeInteger \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeInteger.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeLeaf \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeLeaf.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeLogger \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeLogger.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeMetaContainer.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeMetaData.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeNumberOperator \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeNumberOperator.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeObject \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeObject.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeObject.tpp \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodePlotCurveAppendPoint.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodePlotCurveFile.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodePrint.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeProxy \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeProxy.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeRange.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeRange_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeReal \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeReal.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeRemote \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeRemote.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeRemote_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeSpawn \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeSpawn.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeSpawnEmbedded \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeSpawnEmbedded.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeSpawnEmbedded_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeSpawn_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeString \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeString.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeStringOperator \
  $$SRC_DIR/inc/dtkComposer/dtkComposerNodeStringOperator.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerPath \
  $$SRC_DIR/inc/dtkComposer/dtkComposerPath.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerReader \
  $$SRC_DIR/inc/dtkComposer/dtkComposerReader.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerReaderNoScene.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerScene \
  $$SRC_DIR/inc/dtkComposer/dtkComposerScene.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneEdge \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneEdge.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneModel \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneModel.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNode \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNode.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeComposite \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeComposite.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeControl \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeControl.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeEditor \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeEditor.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeEditor_p \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeEditor_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeHandle \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeHandle.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeLeaf \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNodeLeaf.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNode_p \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNode_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNote \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneNote.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerScene_p \
  $$SRC_DIR/inc/dtkComposer/dtkComposerScene_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerScenePort \
  $$SRC_DIR/inc/dtkComposer/dtkComposerScenePort.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneView \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSceneView.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSearchDialog \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSearchDialog.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerSettings.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStack \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStack.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStackCommand \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStackCommand.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStackUtils \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStackUtils.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStackView \
  $$SRC_DIR/inc/dtkComposer/dtkComposerStackView.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitter \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitter.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterEmitter \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterEmitter.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterEmitter.tpp \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterHandler.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterHandler.tpp \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitter_p \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitter_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterProxy \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterProxy.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterProxyLoop.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterProxyLoop.tpp \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterProxyVariant.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterReceiver \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterReceiver.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerTransmitterReceiver.tpp \
  $$SRC_DIR/inc/dtkComposer/dtkComposerView \
  $$SRC_DIR/inc/dtkComposer/dtkComposerView.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewController \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewController.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewLayout \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewLayout.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewLayoutItem \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewLayoutItem.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewList \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewList.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewListControl \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewListControl.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewManager \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewManager.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerViewWidget.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerWidget.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerWidget_p.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerWriter \
  $$SRC_DIR/inc/dtkComposer/dtkComposerWriter.h \
  $$SRC_DIR/inc/dtkComposer/dtkComposerWriterNoScene.h \


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
  $$SRC_DIR/dtkComposerControlsListItemReal.cpp \
  $$SRC_DIR/dtkComposerControlsListItemString.cpp \
  $$SRC_DIR/dtkComposerDefaultExtensions.cpp \
  $$SRC_DIR/dtkComposerEvaluator.cpp \
  $$SRC_DIR/dtkComposerEvaluatorProcess.cpp \
  $$SRC_DIR/dtkComposerEvaluatorSlave.cpp \
  $$SRC_DIR/dtkComposerEvaluatorToolBar.cpp \
  $$SRC_DIR/dtkComposerGraph.cpp \
  $$SRC_DIR/dtkComposerGraphEdge.cpp \
  $$SRC_DIR/dtkComposerGraphNode.cpp \
  $$SRC_DIR/dtkComposerGraphNodeBegin.cpp \
  $$SRC_DIR/dtkComposerGraphNodeBeginForEach.cpp \
  $$SRC_DIR/dtkComposerGraphNodeEnd.cpp \
  $$SRC_DIR/dtkComposerGraphNodeLeaf.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSelectBranch.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSetInputs.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSetOutputs.cpp \
  $$SRC_DIR/dtkComposerGraphNodeSetVariables.cpp \
  $$SRC_DIR/dtkComposerGraphView.cpp \
  $$SRC_DIR/dtkComposerNode.cpp \
  $$SRC_DIR/dtkComposerNodeBoolean.cpp \
  $$SRC_DIR/dtkComposerNodeBooleanOperator.cpp \
  $$SRC_DIR/dtkComposerNodeComposite.cpp \
  $$SRC_DIR/dtkComposerNodeConstants.cpp \
  $$SRC_DIR/dtkComposerNodeControl.cpp \
  $$SRC_DIR/dtkComposerNodeControlCase.cpp \
  $$SRC_DIR/dtkComposerNodeControlDoWhile.cpp \
  $$SRC_DIR/dtkComposerNodeControlFor.cpp \
  $$SRC_DIR/dtkComposerNodeControlForEach.cpp \
  $$SRC_DIR/dtkComposerNodeControlIf.cpp \
  $$SRC_DIR/dtkComposerNodeControlMap.cpp \
  $$SRC_DIR/dtkComposerNodeControlParallelMap.cpp \
  $$SRC_DIR/dtkComposerNodeControlWhile.cpp \
  $$SRC_DIR/dtkComposerNodeDistributed.cpp \
  $$SRC_DIR/dtkComposerNodeExec.cpp \
  $$SRC_DIR/dtkComposerNodeFactory.cpp \
  $$SRC_DIR/dtkComposerNodeFactoryView.cpp \
  $$SRC_DIR/dtkComposerNodeFile.cpp \
  $$SRC_DIR/dtkComposerNodeGraph.cpp \
  $$SRC_DIR/dtkComposerNodeGraphEdge.cpp \
  $$SRC_DIR/dtkComposerNodeInteger.cpp \
  $$SRC_DIR/dtkComposerNodeLeaf.cpp \
  $$SRC_DIR/dtkComposerNodeLogger.cpp \
  $$SRC_DIR/dtkComposerNodeMetaContainer.cpp \
  $$SRC_DIR/dtkComposerNodeMetaData.cpp \
  $$SRC_DIR/dtkComposerNodeNumberOperator.cpp \
  $$SRC_DIR/dtkComposerNodePlotCurveAppendPoint.cpp \
  $$SRC_DIR/dtkComposerNodePlotCurveFile.cpp \
  $$SRC_DIR/dtkComposerNodePrint.cpp \
  $$SRC_DIR/dtkComposerNodeProxy.cpp \
  $$SRC_DIR/dtkComposerNodeRange.cpp \
  $$SRC_DIR/dtkComposerNodeReal.cpp \
  $$SRC_DIR/dtkComposerNodeRemote.cpp \
  $$SRC_DIR/dtkComposerNodeSpawn.cpp \
  $$SRC_DIR/dtkComposerNodeSpawnEmbedded.cpp \
  $$SRC_DIR/dtkComposerNodeString.cpp \
  $$SRC_DIR/dtkComposerNodeStringOperator.cpp \
  $$SRC_DIR/dtkComposerPath.cpp \
  $$SRC_DIR/dtkComposerReader.cpp \
  $$SRC_DIR/dtkComposerReaderNoScene.cpp \
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
  $$SRC_DIR/dtkComposerSettings.cpp \
  $$SRC_DIR/dtkComposerStack.cpp \
  $$SRC_DIR/dtkComposerStackCommand.cpp \
  $$SRC_DIR/dtkComposerStackUtils.cpp \
  $$SRC_DIR/dtkComposerStackView.cpp \
  $$SRC_DIR/dtkComposerTransmitter.cpp \
  $$SRC_DIR/dtkComposerTransmitterEmitter.cpp \
  $$SRC_DIR/dtkComposerTransmitterHandler.cpp \
  $$SRC_DIR/dtkComposerTransmitterProxy.cpp \
  $$SRC_DIR/dtkComposerTransmitterProxyLoop.cpp \
  $$SRC_DIR/dtkComposerTransmitterProxyVariant.cpp \
  $$SRC_DIR/dtkComposerTransmitterReceiver.cpp \
  $$SRC_DIR/dtkComposerView.cpp \
  $$SRC_DIR/dtkComposerViewController.cpp \
  $$SRC_DIR/dtkComposerViewLayout.cpp \
  $$SRC_DIR/dtkComposerViewLayoutItem.cpp \
  $$SRC_DIR/dtkComposerViewList.cpp \
  $$SRC_DIR/dtkComposerViewListControl.cpp \
  $$SRC_DIR/dtkComposerViewManager.cpp \
  $$SRC_DIR/dtkComposerViewWidget.cpp \
  $$SRC_DIR/dtkComposerWidget.cpp \
  $$SRC_DIR/dtkComposerWriter.cpp \
  $$SRC_DIR/dtkComposerWriterNoScene.cpp \


LIBS +=  -L$$TARGETSDIR  \
  -ldtkMathSupport  -ldtkPlotSupport 



#    $$SRC_DIR/dtkComposerNodeAnySource.json
#    $$SRC_DIR/dtkComposerNodeAnyTag.json
#    $$SRC_DIR/dtkComposerNodeBoolean.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryAnd.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryImp.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryNand.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryNimp.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryNor.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryOr.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryXnor.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorBinaryXor.json
#    $$SRC_DIR/dtkComposerNodeBooleanOperatorUnaryNot.json
#    $$SRC_DIR/dtkComposerNodeCommunicatorRank.json
#    $$SRC_DIR/dtkComposerNodeCommunicatorReceive.json
#    $$SRC_DIR/dtkComposerNodeCommunicatorSend.json
#    $$SRC_DIR/dtkComposerNodeCommunicatorSize.json
#    $$SRC_DIR/dtkComposerNodeComposite.json
#    $$SRC_DIR/dtkComposerNodeControlCase.json
#    $$SRC_DIR/dtkComposerNodeControlDoWhile.json
#    $$SRC_DIR/dtkComposerNodeControlFor.json
#    $$SRC_DIR/dtkComposerNodeControlForEach.json
#    $$SRC_DIR/dtkComposerNodeControlIf.json
#    $$SRC_DIR/dtkComposerNodeControllerRank.json
#    $$SRC_DIR/dtkComposerNodeControlMap.json
#    $$SRC_DIR/dtkComposerNodeControlParallelMap.json
#    $$SRC_DIR/dtkComposerNodeControlWhile.json
#    $$SRC_DIR/dtkComposerNodeDirectory.json
#    $$SRC_DIR/dtkComposerNodeE.json
#    $$SRC_DIR/dtkComposerNodeExec.json
#    $$SRC_DIR/dtkComposerNodeFile.json
#    $$SRC_DIR/dtkComposerNodeFileExists.json
#    $$SRC_DIR/dtkComposerNodeFileList.json
#    $$SRC_DIR/dtkComposerNodeFileRead.json
#    $$SRC_DIR/dtkComposerNodeFileWrite.json
#    $$SRC_DIR/dtkComposerNodeInteger.json
#    $$SRC_DIR/dtkComposerNodeLogger.json
#    $$SRC_DIR/dtkComposerNodeMetaContainer.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerAppend.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerAt.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerInsert.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerPrepend.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerRemoveAt.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerResize.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerSetAt.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerSize.json
#    $$SRC_DIR/dtkComposerNodeMetaContainerTakeAt.json
#    $$SRC_DIR/dtkComposerNodeNumberAlmosteq.json
#    $$SRC_DIR/dtkComposerNodeNumberComparatorEqual.json
#    $$SRC_DIR/dtkComposerNodeNumberComparatorGt.json
#    $$SRC_DIR/dtkComposerNodeNumberComparatorGte.json
#    $$SRC_DIR/dtkComposerNodeNumberComparatorLt.json
#    $$SRC_DIR/dtkComposerNodeNumberComparatorLte.json
#    $$SRC_DIR/dtkComposerNodeNumberComparatorNotequal.json
#    $$SRC_DIR/dtkComposerNodeNumberNotalmosteq.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryEucldiv.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryMax.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryMin.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryMinus.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryModulo.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryMult.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryNthroot.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryPlus.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryPower.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorBinaryRatio.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryAbs.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryAcos.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryAsin.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryAtan.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryCeil.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryCos.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryDecr.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryDeg2Rad.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryExp.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryFloor.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryIncr.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryInv.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryLn.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryLog10.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryRad2Deg.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryRound.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnarySin.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnarySqrt.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnarySquare.json
#    $$SRC_DIR/dtkComposerNodeNumberOperatorUnaryTan.json
#    $$SRC_DIR/dtkComposerNodePi.json
#    $$SRC_DIR/dtkComposerNodePrint.json
#    $$SRC_DIR/dtkComposerNodeRange.json
#    $$SRC_DIR/dtkComposerNodeReal.json
#    $$SRC_DIR/dtkComposerNodeRemote.json
#    $$SRC_DIR/dtkComposerNodeRemoteSubmit.json
#    $$SRC_DIR/dtkComposerNodeSpawn.json
#    $$SRC_DIR/dtkComposerNodeSpawnEmbedded.json
#    $$SRC_DIR/dtkComposerNodeString.json
#    $$SRC_DIR/dtkComposerNodeStringList.json
#    $$SRC_DIR/dtkComposerNodeStringListAppend.json
#    $$SRC_DIR/dtkComposerNodeStringListExtract.json
#    $$SRC_DIR/dtkComposerNodeStringOperatorBinaryAppend.json
#    $$SRC_DIR/dtkComposerNodeStringOperatorBinaryLogicEquality.json
#    $$SRC_DIR/dtkComposerNodeStringReplace.json
#    $$SRC_DIR/dtkComposerNote.json
#    $$SRC_DIR/dtkComposer.qrc
#    $$SRC_DIR/dtkComposerNode.qrc
#  


