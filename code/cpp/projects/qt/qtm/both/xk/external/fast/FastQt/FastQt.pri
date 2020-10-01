
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = FastQt

include(../build-group.pri)

QT += widgets charts concurrent svg

INCLUDEPATH += $$SRC_GROUP_DIR

# why win32?
INCLUDEPATH += $$SRC_DIR/win32/KArchive/include/KF5/KArchive/


INCLUDEPATH += $$SRC_DIR/sequence $$SRC_DIR/QFontIcon \
  $$SRC_DIR/utils $$SRC_DIR/model $$SRC_DIR/cli

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

include(analysis.pri)
include(cli.pri)

include(model.pri)
include(QFontIcon.pri)

include(sequence.pri)
include(utils.pri)

include(ui.pri)



HEADERS += \


#HEADERS += \
#      $$SRC_DIR/objects/bundled.cct \

SOURCES += \


