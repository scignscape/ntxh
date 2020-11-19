
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include (../shared.pri)


TARGET = $$SAVED_TARGET
LIBS += -L$$TARGETSDIR


QT += xml widgets opengl network


include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += MESHLAB_SCALAR=float
DEFINES += setResizeMode=setSectionResizeMode



INCLUDEPATH += $$SRC_GROUP_DIR  

INCLUDEPATH += $$SRC_GROUP_DIR/external/easyexif  


VCGDIR = $$SRC_GROUP_DIR/vcglib
INCLUDEPATH += $$SRC_GROUP_DIR/vcglib 


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk \


HEADERS += \
  $$SRC_DIR/meshlabplugins/iobase/baseio.h \
  $$VCGDIR/wrap/io_trimesh/import_ply.h \
  $$VCGDIR/wrap/io_trimesh/import_obj.h \
  $$VCGDIR/wrap/io_trimesh/import_off.h \
  $$VCGDIR/wrap/io_trimesh/import_ptx.h \
  $$VCGDIR/wrap/io_trimesh/import_stl.h \
  $$VCGDIR/wrap/io_trimesh/import_fbx.h \
  $$VCGDIR/wrap/io_trimesh/export_ply.h \
  $$VCGDIR/wrap/io_trimesh/export_obj.h \
  $$VCGDIR/wrap/io_trimesh/export_off.h \
  $$VCGDIR/wrap/ply/plylib.h \
  $$VCGDIR/wrap/io_trimesh/io_material.h


SOURCES += \
  $$SRC_DIR/meshlabplugins/iobase/baseio.cpp \
  $$VCGDIR/wrap/ply/plylib.cpp \
  $$VCGDIR/wrap/openfbx/src/ofbx.cpp \
  $$VCGDIR/wrap/openfbx/src/miniz.c


DESTDIR = $$SRC_GROUP_DIR/_plugins/plugins
