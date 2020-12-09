
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += widgets gui  

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH +=  $$SRC_DIR/lib

INCLUDEPATH +=  $$SRC_DIR/lib/liblzma



DISTFILES += \
   $$SRC_DIR/lib/liblzma/readme.txt \
   $$SRC_DIR/lib/openctm-mingw1.def \
   $$SRC_DIR/lib/openctm-mingw2.def \
   $$SRC_DIR/lib/openctm-msvc.def \
   $$SRC_DIR/lib/openctm.rc

HEADERS += \
   $$SRC_DIR/lib/internal.h \
   $$SRC_DIR/lib/liblzma/Alloc.h \
   $$SRC_DIR/lib/liblzma/LzFind.h \
   $$SRC_DIR/lib/liblzma/LzHash.h \
   $$SRC_DIR/lib/liblzma/LzmaDec.h \
   $$SRC_DIR/lib/liblzma/LzmaEnc.h \
   $$SRC_DIR/lib/liblzma/LzmaLib.h \
   $$SRC_DIR/lib/liblzma/NameMangle.h \
   $$SRC_DIR/lib/liblzma/Types.h \
   $$SRC_DIR/lib/openctm.h \
   $$SRC_DIR/lib/openctmpp.h

SOURCES += \
   $$SRC_DIR/lib/compressMG1.c \
   $$SRC_DIR/lib/compressMG2.c \
   $$SRC_DIR/lib/compressRAW.c \
   $$SRC_DIR/lib/liblzma/Alloc.c \
   $$SRC_DIR/lib/liblzma/LzFind.c \
   $$SRC_DIR/lib/liblzma/LzmaDec.c \
   $$SRC_DIR/lib/liblzma/LzmaEnc.c \
   $$SRC_DIR/lib/liblzma/LzmaLib.c \
   $$SRC_DIR/lib/openctm.c \
   $$SRC_DIR/lib/stream.c
