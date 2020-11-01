
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


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmsign/dcsighlp.h \
  $$SRC_DIR/include/dcmtk/dcmsign/dcsignat.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sialgo.h \
  $$SRC_DIR/include/dcmtk/dcmsign/siautopr.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sibrsapr.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sicert.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sicertvf.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sicreapr.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sidefine.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sidsa.h \
  $$SRC_DIR/include/dcmtk/dcmsign/siecdsa.h \
  $$SRC_DIR/include/dcmtk/dcmsign/simac.h \
  $$SRC_DIR/include/dcmtk/dcmsign/simaccon.h \
  $$SRC_DIR/include/dcmtk/dcmsign/simd5.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sinullpr.h \
  $$SRC_DIR/include/dcmtk/dcmsign/siprivat.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sipurpos.h \
  $$SRC_DIR/include/dcmtk/dcmsign/siripemd.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sirsa.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisha1.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisha256.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisha384.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisha512.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisprof.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisrpr.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sisrvpr.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sitsfs.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sitstamp.h \
  $$SRC_DIR/include/dcmtk/dcmsign/sitypes.h \


SOURCES += \
  $$SRC_DIR/dcsighlp.cc \
  $$SRC_DIR/dcsignat.cc \
  $$SRC_DIR/siautopr.cc \
  $$SRC_DIR/sibrsapr.cc \
  $$SRC_DIR/sicert.cc \
  $$SRC_DIR/sicertvf.cc \
  $$SRC_DIR/sicreapr.cc \
  $$SRC_DIR/sidsa.cc \
  $$SRC_DIR/siecdsa.cc \
  $$SRC_DIR/simaccon.cc \
  $$SRC_DIR/simd5.cc \
  $$SRC_DIR/sinullpr.cc \
  $$SRC_DIR/siprivat.cc \
  $$SRC_DIR/sipurpos.cc \
  $$SRC_DIR/siripemd.cc \
  $$SRC_DIR/sirsa.cc \
  $$SRC_DIR/sisha1.cc \
  $$SRC_DIR/sisha256.cc \
  $$SRC_DIR/sisha384.cc \
  $$SRC_DIR/sisha512.cc \
  $$SRC_DIR/sisprof.cc \
  $$SRC_DIR/sisrpr.cc \
  $$SRC_DIR/sisrvpr.cc \
  $$SRC_DIR/sitsfs.cc \
  $$SRC_DIR/sitstamp.cc \
  $$SRC_DIR/sitypes.cc \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

