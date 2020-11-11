
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)


include($$ROOT_DIR/../preferred/itk.pri)


QT += network

TEMPLATE = lib


DEFINES += PROJECT_NAME=\\\"PROJECT_NAME\\\"
DEFINES += PROJECT_VERSION=\\\"PROJECT_VERSION\\\"


INCLUDEPATH += \
  $$SRC_DIR/inc \
  $$SRC_GROUP_DIR/cbica-toolkit \


INCLUDEPATH += \
  $$ITK_BUILD_DIR/Modules/Core/Common \
  $$ITK_BUILD_DIR/Modules/ThirdParty/VNL/src/vxl/core \
  $$ITK_BUILD_DIR/Modules/ThirdParty/VNL/src/vxl/vcl \

INCLUDEPATH += \
  $$ITK_SRC_DIR/Modules/ThirdParty/VNL/src/vxl/vcl \
  $$ITK_SRC_DIR/Modules/Core/Common/include \
  $$ITK_SRC_DIR/Modules/ThirdParty/VNL/src/vxl/core \


SOURCES += \
  $$SRC_DIR/CaPTkGUIUtils.cpp \
  $$SRC_DIR/DownloadManager.cpp \



