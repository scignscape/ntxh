
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmnet/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmwlm/wldefine.h \
  $$SRC_DIR/include/dcmtk/dcmwlm/wlds.h \
  $$SRC_DIR/include/dcmtk/dcmwlm/wldsfs.h \
  $$SRC_DIR/include/dcmtk/dcmwlm/wlfsim.h \
  $$SRC_DIR/include/dcmtk/dcmwlm/wlmactmg.h \
  $$SRC_DIR/include/dcmtk/dcmwlm/wltypdef.h \


SOURCES += \
  $$SRC_DIR/wlds.cc \
  $$SRC_DIR/wldsfs.cc \
  $$SRC_DIR/wlfsim.cc \
  $$SRC_DIR/wlmactmg.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

