

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets

INCLUDEPATH += $$SRC_DIR

#INCLUDEPATH += $$SRC_GROUP_DIR
DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"



HEADERS += \
  $$SRC_DIR/axfi-annotation.h  \
  $$SRC_DIR/axfi-location-2d.h  \
  $$SRC_DIR/axfi-annotation-group.h  \
  $$SRC_DIR/axfi-annotation-environment.h  \


SOURCES += \
  $$SRC_DIR/axfi-annotation.cpp  \
  $$SRC_DIR/axfi-location-2d.cpp  \
  $$SRC_DIR/axfi-annotation-group.cpp  \
  $$SRC_DIR/axfi-annotation-environment.cpp  \


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
