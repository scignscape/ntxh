

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += widgets network


DEFINES += LIBCRYPTO_FILE_NAME=\\\"$$ROOT_DIR/../ssl/install/ldir/libcrypto.so.1.1\\\"
DEFINES += LIBSSL_FILE_NAME=\\\"$$ROOT_DIR/../ssl/install/ldir/libssl.so.1.1\\\"

DEFINES += DEFAULT_UPLOAD_FOLDER=\\\"$$ROOT_DIR/../forge\\\"

DEFINES += DEFAULT_TEMP_FOLDER=\\\"$$ROOT_DIR/../forge/temp\\\"

DEFINES += IMAGE_FOLDER=\\\"$$ROOT_DIR/../forge/images\\\"



SOURCES += \
  $$SRC_DIR/forge-bucket.cpp \
  $$SRC_DIR/forge-session.cpp \
  $$SRC_DIR/forge-upload-file.cpp \
  $$SRC_DIR/forge-api-workflow.cpp \
  $$SRC_DIR/forge-runtime.cpp \
  $$SRC_DIR/workflow-signal-generator.cpp \


HEADERS += \
  $$SRC_DIR/forge-bucket.h \
  $$SRC_DIR/forge-session.h \
  $$SRC_DIR/forge-upload-file.h \
  $$SRC_DIR/forge-api-workflow.h \
  $$SRC_DIR/forge-runtime.h \
  $$SRC_DIR/workflow-signal-generator.h \



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
