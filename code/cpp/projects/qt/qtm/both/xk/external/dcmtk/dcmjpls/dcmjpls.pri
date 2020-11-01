
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include
INCLUDEPATH += $$SRC_DIR/libcharls/

INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmjpls/djcodecd.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djcodece.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djcparam.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djdecode.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djencode.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djlsutil.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djrparam.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/dldefine.h \
  $$SRC_DIR/djerror.h \
  $$SRC_DIR/libcharls/clrtrans.h \
  $$SRC_DIR/libcharls/config.h \
  $$SRC_DIR/libcharls/context.h \
  $$SRC_DIR/libcharls/ctxtrmod.h \
  $$SRC_DIR/libcharls/decodstr.h \
  $$SRC_DIR/libcharls/deftrait.h \
  $$SRC_DIR/libcharls/encodstr.h \
  $$SRC_DIR/libcharls/header.h \
  $$SRC_DIR/libcharls/intrface.h \
  $$SRC_DIR/libcharls/lltraits.h \
  $$SRC_DIR/libcharls/lokuptbl.h \
  $$SRC_DIR/libcharls/procline.h \
  $$SRC_DIR/libcharls/pubtypes.h \
  $$SRC_DIR/libcharls/scan.h \
  $$SRC_DIR/libcharls/streams.h \
  $$SRC_DIR/libcharls/util.h \


SOURCES += \
  $$SRC_DIR/djcodecd.cc \
  $$SRC_DIR/djcodece.cc \
  $$SRC_DIR/djcparam.cc \
  $$SRC_DIR/djdecode.cc \
  $$SRC_DIR/djencode.cc \
  $$SRC_DIR/djrparam.cc \
  $$SRC_DIR/djutils.cc \
  $$SRC_DIR/libcharls/header.cc \
  $$SRC_DIR/libcharls/intrface.cc \
  $$SRC_DIR/libcharls/jpegls.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

