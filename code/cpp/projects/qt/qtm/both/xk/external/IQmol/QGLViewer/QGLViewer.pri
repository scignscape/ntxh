
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml


include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \


HEADERS += \


SOURCES += \
  $$SRC_DIR/VRender/BackFaceCullingOptimizer.cpp \
  $$SRC_DIR/VRender/BSPSortMethod.cpp \
  $$SRC_DIR/VRender/EPSExporter.cpp \
  $$SRC_DIR/VRender/Exporter.cpp \
  $$SRC_DIR/VRender/FIGExporter.cpp \
  $$SRC_DIR/VRender/gpc.cpp \
  $$SRC_DIR/VRender/NVector3.cpp \
  $$SRC_DIR/VRender/ParserGL.cpp \
  $$SRC_DIR/VRender/Primitive.cpp \
  $$SRC_DIR/VRender/PrimitivePositioning.cpp \
  $$SRC_DIR/VRender/TopologicalSortMethod.cpp \
  $$SRC_DIR/VRender/Vector2.cpp \
  $$SRC_DIR/VRender/Vector3.cpp \
  $$SRC_DIR/VRender/VisibilityOptimizer.cpp \
  $$SRC_DIR/VRender/VRender.cpp \
  $$SRC_DIR/camera.cpp \
  $$SRC_DIR/constraint-qglviewer.cpp \
  $$SRC_DIR/frame.cpp \
  $$SRC_DIR/keyFrameInterpolator.cpp \
  $$SRC_DIR/manipulatedCameraFrame.cpp \
  $$SRC_DIR/manipulatedFrame.cpp \
  $$SRC_DIR/mouseGrabber.cpp \
  $$SRC_DIR/qglviewer.cpp \
  $$SRC_DIR/quaternion.cpp \
  $$SRC_DIR/saveSnapshot.cpp \
  $$SRC_DIR/vec.cpp \


FORMS += 
  $$SRC_DIR//ImageInterface.ui \
  $$SRC_DIR//VRenderInterface.ui \




