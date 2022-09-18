
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_DIR/libijg8 $$SRC_DIR/libijg12 $$SRC_DIR/libijg16


INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/libijg16/jchuff16.h \
  $$SRC_DIR/libijg16/jconfig16.h \
  $$SRC_DIR/libijg16/jdct16.h \
  $$SRC_DIR/libijg16/jdhuff16.h \
  $$SRC_DIR/libijg16/jerror16.h \
  $$SRC_DIR/libijg16/jinclude16.h \
  $$SRC_DIR/libijg16/jlossls16.h \
  $$SRC_DIR/libijg16/jlossy16.h \
  $$SRC_DIR/libijg16/jmemsys16.h \
  $$SRC_DIR/libijg16/jmorecfg16.h \
  $$SRC_DIR/libijg16/jpegint16.h \
  $$SRC_DIR/libijg16/jpeglib16.h \
  $$SRC_DIR/libijg16/jversion16.h \


SOURCES += \
  $$SRC_DIR/libijg16/jaricom.c \
  $$SRC_DIR/libijg16/jcapimin.c \
  $$SRC_DIR/libijg16/jcapistd.c \
  $$SRC_DIR/libijg16/jcarith.c \
  $$SRC_DIR/libijg16/jccoefct.c \
  $$SRC_DIR/libijg16/jccolor.c \
  $$SRC_DIR/libijg16/jcdctmgr.c \
  $$SRC_DIR/libijg16/jcdiffct.c \
  $$SRC_DIR/libijg16/jchuff.c \
  $$SRC_DIR/libijg16/jcinit.c \
  $$SRC_DIR/libijg16/jclhuff.c \
  $$SRC_DIR/libijg16/jclossls.c \
  $$SRC_DIR/libijg16/jclossy.c \
  $$SRC_DIR/libijg16/jcmainct.c \
  $$SRC_DIR/libijg16/jcmarker.c \
  $$SRC_DIR/libijg16/jcmaster.c \
  $$SRC_DIR/libijg16/jcodec.c \
  $$SRC_DIR/libijg16/jcomapi.c \
  $$SRC_DIR/libijg16/jcparam.c \
  $$SRC_DIR/libijg16/jcphuff.c \
  $$SRC_DIR/libijg16/jcpred.c \
  $$SRC_DIR/libijg16/jcprepct.c \
  $$SRC_DIR/libijg16/jcsample.c \
  $$SRC_DIR/libijg16/jcscale.c \
  $$SRC_DIR/libijg16/jcshuff.c \
  $$SRC_DIR/libijg16/jctrans.c \
  $$SRC_DIR/libijg16/jdapimin.c \
  $$SRC_DIR/libijg16/jdapistd.c \
  $$SRC_DIR/libijg16/jdarith.c \
  $$SRC_DIR/libijg16/jdatadst.c \
  $$SRC_DIR/libijg16/jdatasrc.c \
  $$SRC_DIR/libijg16/jdcoefct.c \
  $$SRC_DIR/libijg16/jdcolor.c \
  $$SRC_DIR/libijg16/jddctmgr.c \
  $$SRC_DIR/libijg16/jddiffct.c \
  $$SRC_DIR/libijg16/jdhuff.c \
  $$SRC_DIR/libijg16/jdinput.c \
  $$SRC_DIR/libijg16/jdlhuff.c \
  $$SRC_DIR/libijg16/jdlossls.c \
  $$SRC_DIR/libijg16/jdlossy.c \
  $$SRC_DIR/libijg16/jdmainct.c \
  $$SRC_DIR/libijg16/jdmarker.c \
  $$SRC_DIR/libijg16/jdmaster.c \
  $$SRC_DIR/libijg16/jdmerge.c \
  $$SRC_DIR/libijg16/jdphuff.c \
  $$SRC_DIR/libijg16/jdpostct.c \
  $$SRC_DIR/libijg16/jdpred.c \
  $$SRC_DIR/libijg16/jdsample.c \
  $$SRC_DIR/libijg16/jdscale.c \
  $$SRC_DIR/libijg16/jdshuff.c \
  $$SRC_DIR/libijg16/jdtrans.c \
  $$SRC_DIR/libijg16/jerror.c \
  $$SRC_DIR/libijg16/jfdctflt.c \
  $$SRC_DIR/libijg16/jfdctfst.c \
  $$SRC_DIR/libijg16/jfdctint.c \
  $$SRC_DIR/libijg16/jidctflt.c \
  $$SRC_DIR/libijg16/jidctfst.c \
  $$SRC_DIR/libijg16/jidctint.c \
  $$SRC_DIR/libijg16/jidctred.c \
  $$SRC_DIR/libijg16/jmemmgr.c \
  $$SRC_DIR/libijg16/jmemnobs.c \
  $$SRC_DIR/libijg16/jquant1.c \
  $$SRC_DIR/libijg16/jquant2.c \
  $$SRC_DIR/libijg16/jutils.c \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

