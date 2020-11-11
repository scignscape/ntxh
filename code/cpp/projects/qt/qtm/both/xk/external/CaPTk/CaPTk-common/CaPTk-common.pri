
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui  

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)


QT += network

TEMPLATE = lib


DEFINES += PROJECT_NAME=\\\"PROJECT_NAME\\\"
DEFINES += PROJECT_VERSION=\\\"PROJECT_VERSION\\\"


INCLUDEPATH += \
  ../common/inc \
  ../cbica_toolkit/src \

#   configs

# 

INCLUDEPATH += ../../../ITK-build/Modules/Core/Common
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/VNL/src/vxl/core
INCLUDEPATH += ../../../ITK-build/Modules/ThirdParty/VNL/src/vxl/vcl
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/VNL/src/vxl/vcl
INCLUDEPATH += 
INCLUDEPATH += 


INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/Core/Common/include
INCLUDEPATH += ../../../InsightToolkit-5.1.1/Modules/ThirdParty/VNL/src/vxl/core


# cbicaUtilities.h



SOURCES += \
  ../common/src/CaPTkGUIUtils.cpp \
  ../common/src/DownloadManager.cpp \



