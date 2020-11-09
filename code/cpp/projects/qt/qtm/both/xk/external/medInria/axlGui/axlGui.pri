
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets xml #opengl sql network xml testlib svg

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
INCLUDEPATH += $$SRC_DIR/inc
INCLUDEPATH += $$SRC_DIR/inc/axlGui


INCLUDEPATH += $$DTK_META_EXPORT_INCLUDES_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/axlCore/inc


#
INCLUDEPATH += $$SRC_GROUP_DIR/dtkCoreSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkLog/inc/dtkLog
INCLUDEPATH += $$SRC_GROUP_DIR/dtkMathSupport/inc
INCLUDEPATH += $$SRC_GROUP_DIR/dtkGuiSupport/inc



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
  $$SRC_DIR/inc/axlGui/axlAbstractVolumeDiscreteEditor.h \
  $$SRC_DIR/inc/axlGui/axlColorDialog.h \
  $$SRC_DIR/inc/axlGui/axlGuiExport2.h \
  $$SRC_DIR/inc/axlGui/axlInspector.h \
  $$SRC_DIR/inc/axlGui/axlInspectorCamera.h \
  $$SRC_DIR/inc/axlGui/axlInspectorLight.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObject.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectCircleArc.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectComposite.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectCone.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectController.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectCylinder.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectDataDynamic.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectEllipsoid.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectFactory.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectLine.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectManager.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectManagerList.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectManagerListItem.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectManagerTree.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectManagerTreeItem.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectMesh.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectPlane.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectPoint.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectPointSet.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetField.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldScalar.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldScalarCol.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldScalarIso.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldTensor.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldVector.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldVectorGlyph.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetFieldVectorStream.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSceneWidgetVolumeDiscrete.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSet.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSphere.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectSurfaceParametricOffset.h \
  $$SRC_DIR/inc/axlGui/axlInspectorObjectTorus.h \
  $$SRC_DIR/inc/axlGui/axlInspectorSeparator.h \
  $$SRC_DIR/inc/axlGui/axlInspectorSettings.h \
  $$SRC_DIR/inc/axlGui/axlInspectorSidePane.h \
  $$SRC_DIR/inc/axlGui/axlInspectorStack.h \
  $$SRC_DIR/inc/axlGui/axlInspectorSwitch.h \
  $$SRC_DIR/inc/axlGui/axlInspectorTool.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreateMiddlePoint.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreator.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorCircleArc.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorCone.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorCylinder.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorDataDynamicDialog.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorEllipsoid.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorLine.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorPlane.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorPoint.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorPointSet.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorSphere.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolCreatorTorus.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolFactory.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolFieldGenerator.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolGeneric.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolManager.h \
  $$SRC_DIR/inc/axlGui/axlInspectorToolManager_p.h \
  $$SRC_DIR/inc/axlGui/axlInspectorUtils.h \
  $$SRC_DIR/inc/axlGui/axlInspectorView.h \
  $$SRC_DIR/inc/axlGui/axlParameterSpace.h \


SOURCES +=  \
  $$SRC_DIR/axlAbstractVolumeDiscreteEditor.cpp \
  $$SRC_DIR/axlColorDialog.cpp \
  $$SRC_DIR/axlInspector.cpp \
  $$SRC_DIR/axlInspectorCamera.cpp \
  $$SRC_DIR/axlInspectorLight.cpp \
  $$SRC_DIR/axlInspectorObject.cpp \
  $$SRC_DIR/axlInspectorObjectCircleArc.cpp \
  $$SRC_DIR/axlInspectorObjectComposite.cpp \
  $$SRC_DIR/axlInspectorObjectCone.cpp \
  $$SRC_DIR/axlInspectorObjectController.cpp \
  $$SRC_DIR/axlInspectorObjectCylinder.cpp \
  $$SRC_DIR/axlInspectorObjectDataDynamic.cpp \
  $$SRC_DIR/axlInspectorObjectEllipsoid.cpp \
  $$SRC_DIR/axlInspectorObjectFactory.cpp \
  $$SRC_DIR/axlInspectorObjectLine.cpp \
  $$SRC_DIR/axlInspectorObjectManager.cpp \
  $$SRC_DIR/axlInspectorObjectManagerList.cpp \
  $$SRC_DIR/axlInspectorObjectManagerListItem.cpp \
  $$SRC_DIR/axlInspectorObjectManagerTree.cpp \
  $$SRC_DIR/axlInspectorObjectManagerTreeItem.cpp \
  $$SRC_DIR/axlInspectorObjectMesh.cpp \
  $$SRC_DIR/axlInspectorObjectPlane.cpp \
  $$SRC_DIR/axlInspectorObjectPoint.cpp \
  $$SRC_DIR/axlInspectorObjectPointSet.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetField.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldScalar.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldScalarCol.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldScalarIso.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldTensor.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldVector.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldVectorGlyph.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetFieldVectorStream.cpp \
  $$SRC_DIR/axlInspectorObjectSceneWidgetVolumeDiscrete.cpp \
  $$SRC_DIR/axlInspectorObjectSet.cpp \
  $$SRC_DIR/axlInspectorObjectSphere.cpp \
  $$SRC_DIR/axlInspectorObjectSurfaceParametricOffset.cpp \
  $$SRC_DIR/axlInspectorObjectTorus.cpp \
  $$SRC_DIR/axlInspectorSeparator.cpp \
  $$SRC_DIR/axlInspectorSettings.cpp \
  $$SRC_DIR/axlInspectorSidePane.cpp \
  $$SRC_DIR/axlInspectorStack.cpp \
  $$SRC_DIR/axlInspectorSwitch.cpp \
  $$SRC_DIR/axlInspectorTool.cpp \
  \# 
  $$SRC_DIR/axlInspectorToolCreateMiddlePoint.cpp \
  $$SRC_DIR/axlInspectorToolCreator.cpp \
  $$SRC_DIR/axlInspectorToolCreatorCircleArc.cpp \
  $$SRC_DIR/axlInspectorToolCreatorCone.cpp \
  $$SRC_DIR/axlInspectorToolCreatorCylinder.cpp \
  $$SRC_DIR/axlInspectorToolCreatorDataDynamicDialog.cpp \
  $$SRC_DIR/axlInspectorToolCreatorEllipsoid.cpp \
  $$SRC_DIR/axlInspectorToolCreatorLine.cpp \
  $$SRC_DIR/axlInspectorToolCreatorPlane.cpp \
  $$SRC_DIR/axlInspectorToolCreatorPoint.cpp \
  $$SRC_DIR/axlInspectorToolCreatorPointSet.cpp \
  $$SRC_DIR/axlInspectorToolCreatorSphere.cpp \
  $$SRC_DIR/axlInspectorToolCreatorTorus.cpp \
  $$SRC_DIR/axlInspectorToolFactory.cpp \
  $$SRC_DIR/axlInspectorToolFieldGenerator.cpp \
  $$SRC_DIR/axlInspectorToolGeneric.cpp \
  $$SRC_DIR/axlInspectorToolManager.cpp \
  $$SRC_DIR/axlInspectorUtils.cpp \
  $$SRC_DIR/axlInspectorView.cpp \
  $$SRC_DIR/axlParameterSpace.cpp \



