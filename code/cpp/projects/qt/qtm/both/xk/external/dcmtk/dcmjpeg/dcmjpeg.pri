
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include

INCLUDEPATH += $$SRC_DIR/libijg8 $$SRC_GROUP_DIR/dcmjpeg-12/libijg12 $$SRC_GROUP_DIR/dcmjpeg-16/libijg16


INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmjpeg/ddpiimpl.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/dipijpeg.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djcodecd.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djcodece.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djcparam.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecabs.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecbas.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecext.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdeclol.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecode.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecpro.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecsps.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdecsv1.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdefine.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdijg8.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdijg12.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djdijg16.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djeijg8.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djeijg12.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djeijg16.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencabs.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencbas.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencext.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djenclol.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencode.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencpro.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencsps.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djencsv1.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djrplol.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djrploss.h \ 
  $$SRC_DIR/include/dcmtk/dcmjpeg/djutils.h \ 
  $$SRC_DIR/libijg8/jdct8.h \
  $$SRC_DIR/libijg8/jmemsys8.h \
  $$SRC_DIR/libijg8/jmorecfg8.h \
  $$SRC_DIR/libijg8/jpegint8.h \
  $$SRC_DIR/libijg8/jpeglib8.h \
  $$SRC_DIR/libijg8/jchuff8.h \
  $$SRC_DIR/libijg8/jconfig8.h \
  $$SRC_DIR/libijg8/jdhuff8.h \
  $$SRC_DIR/libijg8/jerror8.h \
  $$SRC_DIR/libijg8/jinclude8.h \
  $$SRC_DIR/libijg8/jlossls8.h \
  $$SRC_DIR/libijg8/jlossy8.h \
  $$SRC_DIR/libijg8/jversion8.h \




SOURCES += \
  $$SRC_DIR/ddpiimpl.cc \
  $$SRC_DIR/dipijpeg.cc \
  $$SRC_DIR/djcodecd.cc \
  $$SRC_DIR/djcodece.cc \
  $$SRC_DIR/djcparam.cc \
  $$SRC_DIR/djdecbas.cc \
  $$SRC_DIR/djdecext.cc \
  $$SRC_DIR/djdeclol.cc \
  $$SRC_DIR/djdecode.cc \
  $$SRC_DIR/djdecpro.cc \
  $$SRC_DIR/djdecsps.cc \
  $$SRC_DIR/djdecsv1.cc \
  $$SRC_DIR/djdijg8.cc \
  $$SRC_DIR/djdijg12.cc \
  $$SRC_DIR/djdijg16.cc \
  $$SRC_DIR/djeijg8.cc \
  $$SRC_DIR/djeijg12.cc \
  $$SRC_DIR/djeijg16.cc \
  $$SRC_DIR/djencbas.cc \
  $$SRC_DIR/djencext.cc \
  $$SRC_DIR/djenclol.cc \
  $$SRC_DIR/djencode.cc \
  $$SRC_DIR/djencpro.cc \
  $$SRC_DIR/djencsps.cc \
  $$SRC_DIR/djencsv1.cc \
  $$SRC_DIR/djrplol.cc \
  $$SRC_DIR/djrploss.cc \
  $$SRC_DIR/djutils.cc \

SOURCES += \
  $$SRC_DIR/libijg8/jaricom.c \
  $$SRC_DIR/libijg8/jcapimin.c \
  $$SRC_DIR/libijg8/jcapistd.c \
  $$SRC_DIR/libijg8/jcarith.c \
  $$SRC_DIR/libijg8/jccoefct.c \
  $$SRC_DIR/libijg8/jccolor.c \
  $$SRC_DIR/libijg8/jcdctmgr.c \
  $$SRC_DIR/libijg8/jcdiffct.c \
  $$SRC_DIR/libijg8/jchuff.c \
  $$SRC_DIR/libijg8/jcinit.c \
  $$SRC_DIR/libijg8/jclhuff.c \
  $$SRC_DIR/libijg8/jclossls.c \
  $$SRC_DIR/libijg8/jclossy.c \
  $$SRC_DIR/libijg8/jcmainct.c \
  $$SRC_DIR/libijg8/jcmarker.c \
  $$SRC_DIR/libijg8/jcmaster.c \
  $$SRC_DIR/libijg8/jcodec.c \
  $$SRC_DIR/libijg8/jcomapi.c \
  $$SRC_DIR/libijg8/jcparam.c \
  $$SRC_DIR/libijg8/jcphuff.c \
  $$SRC_DIR/libijg8/jcpred.c \
  $$SRC_DIR/libijg8/jcprepct.c \
  $$SRC_DIR/libijg8/jcsample.c \
  $$SRC_DIR/libijg8/jcscale.c \
  $$SRC_DIR/libijg8/jcshuff.c \
  $$SRC_DIR/libijg8/jctrans.c \
  $$SRC_DIR/libijg8/jdapimin.c \
  $$SRC_DIR/libijg8/jdapistd.c \
  $$SRC_DIR/libijg8/jdarith.c \
  $$SRC_DIR/libijg8/jdatadst.c \
  $$SRC_DIR/libijg8/jdatasrc.c \
  $$SRC_DIR/libijg8/jdcoefct.c \
  $$SRC_DIR/libijg8/jdcolor.c \
  $$SRC_DIR/libijg8/jddctmgr.c \
  $$SRC_DIR/libijg8/jddiffct.c \
  $$SRC_DIR/libijg8/jdhuff.c \
  $$SRC_DIR/libijg8/jdinput.c \
  $$SRC_DIR/libijg8/jdlhuff.c \
  $$SRC_DIR/libijg8/jdlossls.c \
  $$SRC_DIR/libijg8/jdlossy.c \
  $$SRC_DIR/libijg8/jdmainct.c \
  $$SRC_DIR/libijg8/jdmarker.c \
  $$SRC_DIR/libijg8/jdmaster.c \
  $$SRC_DIR/libijg8/jdmerge.c \
  $$SRC_DIR/libijg8/jdphuff.c \
  $$SRC_DIR/libijg8/jdpostct.c \
  $$SRC_DIR/libijg8/jdpred.c \
  $$SRC_DIR/libijg8/jdsample.c \
  $$SRC_DIR/libijg8/jdscale.c \
  $$SRC_DIR/libijg8/jdshuff.c \
  $$SRC_DIR/libijg8/jdtrans.c \
  $$SRC_DIR/libijg8/jerror.c \
  $$SRC_DIR/libijg8/jfdctflt.c \
  $$SRC_DIR/libijg8/jfdctfst.c \
  $$SRC_DIR/libijg8/jfdctint.c \
  $$SRC_DIR/libijg8/jidctflt.c \
  $$SRC_DIR/libijg8/jidctfst.c \
  $$SRC_DIR/libijg8/jidctint.c \
  $$SRC_DIR/libijg8/jidctred.c \
  $$SRC_DIR/libijg8/jmemmgr.c \
  $$SRC_DIR/libijg8/jmemnobs.c \
  $$SRC_DIR/libijg8/jquant1.c \
  $$SRC_DIR/libijg8/jquant2.c \
  $$SRC_DIR/libijg8/jutils.c \


LIBS += -L$$TARGETSDIR -ldcmimgle


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

