
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app


include($$ROOT_DIR/../preferred/sysr.pri)

DCMTKDIR = $$SRC_PROSET_DIR/dcmtk

#INCLUDEPATH += $$SRC_PROSET_DIR/dcmtk
#INCLUDEPATH += $$SRC_DIR/include

INCLUDEPATH += $$DCMTKDIR/ofstd/include
INCLUDEPATH += $$DCMTKDIR/dcm-config/include
INCLUDEPATH += $$DCMTKDIR/oflog/include
INCLUDEPATH += $$DCMTKDIR/dcmdata/include

INCLUDEPATH += $$DCMTKDIR/dcmimgle/include
INCLUDEPATH += $$DCMTKDIR/dcmimage/include

INCLUDEPATH += $$DCMTKDIR/dcmnet/include
INCLUDEPATH += $$DCMTKDIR/dcmpstat/include
INCLUDEPATH += $$DCMTKDIR/dcmqrdb/include

INCLUDEPATH += $$DCMTKDIR/dcmtls/include



DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \



SOURCES += \
  $$SRC_DIR/dcmpssnd.cc \


LIBS += -L$$TARGETSDIR -loflog -lofstd -ldcmdata \
  -ldcmpstat -ldcmqrdb \
  -ldcmsign -ldcmnet  -ldcmtls  -ldcmsr -ldcmimgle  -ldcmimage 


LIBS += -lz

 # maybe in preferred?

LIBS += -lssl -lcrypto




message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

