
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include

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

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

