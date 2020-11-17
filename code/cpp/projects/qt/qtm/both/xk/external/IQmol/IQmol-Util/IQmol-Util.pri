
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(  $$SRC_DIR/build-group.pri)

QT += opengl xml


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)

UI_DIR = $$SRC_DIR/uis-gen/any-build

INCLUDEPATH += $$SRC_GROUP_DIR  \


HEADERS += \
  $$SRC_DIR/Util/ColorGradientDialog.h \
  $$SRC_DIR/Util/QMsgBox.h \
  $$SRC_DIR/Util/Task.h \
  $$SRC_DIR/Util/Timer.h \


SOURCES += \
  $$SRC_DIR/Util/Align.C \
  $$SRC_DIR/Util/ColorGradient.C \
  $$SRC_DIR/Util/ColorGradientDialog.C \
  $$SRC_DIR/Util/EulerAngles.C \
  $$SRC_DIR/Util/Function.C \
  $$SRC_DIR/Util/GLShape.C \
  $$SRC_DIR/Util/GLShapeLibrary.C \
  $$SRC_DIR/Util/Matrix.C \
  $$SRC_DIR/Util/Preferences.C \
  $$SRC_DIR/Util/qcprot.C \
  $$SRC_DIR/Util/QMsgBox.C \
  $$SRC_DIR/Util/QsDebugOutput.C \
  $$SRC_DIR/Util/QsLog.C \
  $$SRC_DIR/Util/QsLogDest.C \
  $$SRC_DIR/Util/RemoveDirectory.C \
  $$SRC_DIR/Util/ScanDirectory.C \
  $$SRC_DIR/Util/SetButtonColor.C \
  $$SRC_DIR/Util/Task.C \
  $$SRC_DIR/Util/Timer.C \
  $$SRC_DIR/Util/WriteToTemporaryFile.C \


FORMS += \
  $$SRC_DIR/Util/ColorGradientDialog.ui




