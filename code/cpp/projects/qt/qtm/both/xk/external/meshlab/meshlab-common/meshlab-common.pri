
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += xml widgets opengl


include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += MESHLAB_SCALAR=float


INCLUDEPATH += $$SRC_GROUP_DIR  

INCLUDEPATH += $$SRC_GROUP_DIR/external/easyexif  


INCLUDEPATH += $$SRC_GROUP_DIR/vcglib \


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk \


HEADERS += \
  $$SRC_DIR/GLExtensionsManager.h \
  $$SRC_DIR/filter_parameter/rich_parameter_list.h \
  $$SRC_DIR/filter_parameter/value.h \
  $$SRC_DIR/filter_parameter/rich_parameter.h \
  $$SRC_DIR/filterscript.h \
  $$SRC_DIR/GLLogStream.h \
  $$SRC_DIR/interfaces/decorate_plugin_interface.h \
  $$SRC_DIR/interfaces/edit_plugin_interface.h \
  $$SRC_DIR/interfaces/filter_plugin_interface.h \
  $$SRC_DIR/interfaces/io_plugin_interface.h \
  $$SRC_DIR/interfaces/mainwindow_interface.h \
  $$SRC_DIR/interfaces/plugin_interface.h \
  $$SRC_DIR/interfaces/render_plugin_interface.h \
  $$SRC_DIR/ml_mesh_type.h \
  $$SRC_DIR/meshmodel.h \
  $$SRC_DIR/pluginmanager.h \
  $$SRC_DIR/mlexception.h \
  $$SRC_DIR/mlapplication.h \
  $$SRC_DIR/meshlabdocumentxml.h \
  $$SRC_DIR/ml_shared_data_context.h \
  $$SRC_DIR/ml_selection_buffers.h \
  $$SRC_DIR/meshlabdocumentxml.h


SOURCES += \
  $$SRC_DIR/GLExtensionsManager.cpp \
  $$SRC_DIR/filter_parameter/rich_parameter.cpp \
  $$SRC_DIR/filter_parameter/rich_parameter_list.cpp \
  $$SRC_DIR/filter_parameter/value.cpp \
  $$SRC_DIR/filterscript.cpp \
  $$SRC_DIR/GLLogStream.cpp \
  $$SRC_DIR/interfaces/decorate_plugin_interface.cpp \
  $$SRC_DIR/interfaces/filter_plugin_interface.cpp \
  $$SRC_DIR/interfaces/plugin_interface.cpp \
  $$SRC_DIR/meshmodel.cpp \
  $$SRC_DIR/pluginmanager.cpp \
  $$SRC_DIR/mlapplication.cpp \
  $$SRC_DIR/searcher.cpp \
  $$SRC_DIR/meshlabdocumentxml.cpp \
  $$SRC_DIR/meshlabdocumentbundler.cpp \
  $$SRC_DIR/ml_shared_data_context.cpp \
  $$SRC_DIR/ml_selection_buffers.cpp \


#  $$SRC_DIR/$$MESHLAB_EXTERNAL_DIRECTORY/easyexif/exif.cpp




