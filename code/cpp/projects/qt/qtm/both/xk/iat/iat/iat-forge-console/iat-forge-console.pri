

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

QT += widgets network

INCLUDEPATH += $$SRC_GROUP_DIR

DEFINES += LIBCRYPTO_FILE_NAME=\\\"$$ROOT_DIR/../ssl/install/ldir/libcrypto.so.1.1\\\"
DEFINES += LIBSSL_FILE_NAME=\\\"$$ROOT_DIR/../ssl/install/ldir/libssl.so.1.1\\\"

DEFINES += DEFAULT_UPLOAD_FOLDER=\\\"$$ROOT_DIR/../forge\\\"

DEFINES += DEFAULT_TEMP_FOLDER=\\\"$$ROOT_DIR/../forge/temp\\\"

DEFINES += IMAGE_FOLDER=\\\"$$ROOT_DIR/../forge/images\\\"



HEADERS += \


SOURCES += \
  $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR -liat-forge




message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
