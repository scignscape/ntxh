
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app


include($$ROOT_DIR/../preferred/sysr.pri)

DCMTKDIR = $$SRC_PROSET_DIR/dcmtk

INCLUDEPATH += $$DCMTKDIR/dcmjpeg/include
INCLUDEPATH += $$DCMTKDIR/dcmjpls/include

#INCLUDEPATH += $$SRC_DIR/include

INCLUDEPATH += $$DCMTKDIR/ofstd/include
INCLUDEPATH += $$DCMTKDIR/dcm-config/include
INCLUDEPATH += $$DCMTKDIR/oflog/include
INCLUDEPATH += $$DCMTKDIR/dcmdata/include

INCLUDEPATH += $$DCMTKDIR/dcmimgle/include
INCLUDEPATH += $$DCMTKDIR/dcmimage/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \



SOURCES += \
  $$SRC_DIR/dcmdjpls.cc \


LIBS += -L$$TARGETSDIR  -loflog  -lofstd  -ldcmdata \
  -ldcmimage -ldcmimgle -ldcmjpls 

 # -ldcmjpeg  -ldcmjpeg-12  -ldcmjpeg-16 \
 # -ldcmdata  -lofstd -ldcmimgle  -loflog -ldcmimage

 
LIBS += -lz

message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

