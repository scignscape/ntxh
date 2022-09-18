
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include

INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmfg/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmiod/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmseg/segdef.h \
  $$SRC_DIR/include/dcmtk/dcmseg/segdoc.h \
  $$SRC_DIR/include/dcmtk/dcmseg/segment.h \
  $$SRC_DIR/include/dcmtk/dcmseg/segtypes.h \
  $$SRC_DIR/include/dcmtk/dcmseg/segutils.h \


SOURCES += \
  $$SRC_DIR/segdoc.cc \
  $$SRC_DIR/segment.cc \
  $$SRC_DIR/segtypes.cc \
  $$SRC_DIR/segutils.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

