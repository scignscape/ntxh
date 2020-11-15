
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


DEFINES += USE_JPIP


#INCLUDEPATH += $$SRC_GROUP_DIR/Utilities \
#  $$SRC_GROUP_DIR/gdcm-common \
#  $$SRC_GROUP_DIR/gdcm-dsed \
#  $$SRC_GROUP_DIR/gdcm-dict \
#  $$SRC_GROUP_DIR/gdcm-iod \



HEADERS += \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/bio.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/cidx_manager.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/cio.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/dwt.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/event.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/function_list.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/image.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/indexbox_manager.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/invert.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/j2k.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/jp2.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/mct.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/mqc.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/mqc_inl.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/openjpeg.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_clock.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_codec.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_common.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_includes.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_intmath.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_inttypes.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_malloc.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_stdint.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/pi.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/sparse_array.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/t1.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/t1_luts.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/t2.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/tcd.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/tgt.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/thread.h \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/tls_keys.h \

SOURCES += \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/bio.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/cidx_manager.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/cio.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/dwt.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/event.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/function_list.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/image.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/invert.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/j2k.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/jp2.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/mct.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/mqc.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/openjpeg.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_clock.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/opj_malloc.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/phix_manager.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/pi.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/ppix_manager.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/sparse_array.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/t1.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/t1_generate_luts.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/t2.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/tcd.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/tgt.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/thix_manager.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/thread.c \
  $$SRC_GROUP_DIR/Utilities/gdcmopenjpeg/src/lib/openjp2/tpix_manager.c \




