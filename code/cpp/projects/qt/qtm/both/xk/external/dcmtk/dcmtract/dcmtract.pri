
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmiod/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmtract/trcdef.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trcmeasurement.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trcmodtractresults.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trcstatistic.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trctrack.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trctrackset.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trctractographyresults.h \
  $$SRC_DIR/include/dcmtk/dcmtract/trctypes.h \


SOURCES += \
  $$SRC_DIR/trcmeasurement.cc \
  $$SRC_DIR/trcmodtractresults.cc \
  $$SRC_DIR/trcstatistic.cc \
  $$SRC_DIR/trctrack.cc \
  $$SRC_DIR/trctrackset.cc \
  $$SRC_DIR/trctractographyresults.cc \
  $$SRC_DIR/trctypes.cc \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

