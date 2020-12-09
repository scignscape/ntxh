
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR/core

INCLUDEPATH += $$SRC_DIR/delineators/twave


INCLUDEPATH += $$SRC_KERNEL_DIR/facs/cytoLib/qcytolib/include


HEADERS += \
   $$SRC_DIR/core/ecglib.hpp \
   $$SRC_DIR/core/ecglib/annotation.hpp \
   $$SRC_DIR/core/ecglib/beat.hpp \
   $$SRC_DIR/core/ecglib/config.hpp \
   $$SRC_DIR/core/ecglib/detail/detail.hpp \
   $$SRC_DIR/core/ecglib/ecgdata.hpp \
   $$SRC_DIR/core/ecglib/ecglib.hpp \
   $$SRC_DIR/core/ecglib/util/config.hpp \
   $$SRC_DIR/core/ecglib/util/util.hpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave.hpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/delineate.hpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/delineateFinder.hpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/generalstructure.hpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/processing.hpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/twaveDelineator.hpp

SOURCES += \
   $$SRC_DIR/core/ecglib/annotation.cpp \
   $$SRC_DIR/core/ecglib/beat.cpp \
   $$SRC_DIR/core/ecglib/detail/detail.cpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/delineate.cpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/delineateFinder.cpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/processing.cpp \
   $$SRC_DIR/delineators/twave/ecglib/delineator/twave/twaveDelineator.cpp

