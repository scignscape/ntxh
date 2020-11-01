
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include


INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmtls/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmnet/assoc.h \
  $$SRC_DIR/include/dcmtk/dcmnet/cond.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcasccff.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcasccfg.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfenmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfpcmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfprmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfrsmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccftsmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfuidh.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcmlayer.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcmsmap.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcmtrans.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcompat.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcuserid.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dfindscu.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dicom.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dimse.h \
  $$SRC_DIR/include/dcmtk/dcmnet/diutil.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dndefine.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dntypes.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dstorscp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dstorscu.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dul.h \
  $$SRC_DIR/include/dcmtk/dcmnet/extneg.h \
  $$SRC_DIR/include/dcmtk/dcmnet/lst.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scpcfg.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scppool.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scpthrd.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scu.h \
  $$SRC_DIR/dimcmd.h \
  $$SRC_DIR/dulfsm.h \
  $$SRC_DIR/dulpriv.h \
  $$SRC_DIR/dulstruc.h \


SOURCES += \
  $$SRC_DIR/assoc.cc \
  $$SRC_DIR/cond.cc \
  $$SRC_DIR/dcasccff.cc \
  $$SRC_DIR/dcasccfg.cc \
  $$SRC_DIR/dccfenmp.cc \
  $$SRC_DIR/dccfpcmp.cc \
  $$SRC_DIR/dccfprmp.cc \
  $$SRC_DIR/dccfrsmp.cc \
  $$SRC_DIR/dccftsmp.cc \
  $$SRC_DIR/dccfuidh.cc \
  $$SRC_DIR/dcmlayer.cc \
  $$SRC_DIR/dcmtrans.cc \
  $$SRC_DIR/dcompat.cc \
  $$SRC_DIR/dcuserid.cc \
  $$SRC_DIR/dfindscu.cc \
  $$SRC_DIR/dimcancl.cc \
  $$SRC_DIR/dimcmd.cc \
  $$SRC_DIR/dimdump.cc \
  $$SRC_DIR/dimecho.cc \
  $$SRC_DIR/dimfind.cc \
  $$SRC_DIR/dimget.cc \
  $$SRC_DIR/dimmove.cc \
  $$SRC_DIR/dimse.cc \
  $$SRC_DIR/dimstore.cc \
  $$SRC_DIR/diutil.cc \
  $$SRC_DIR/dstorscp.cc \
  $$SRC_DIR/dstorscu.cc \
  $$SRC_DIR/dul.cc \
  $$SRC_DIR/dulconst.cc \
  $$SRC_DIR/dulextra.cc \
  $$SRC_DIR/dulfsm.cc \
  $$SRC_DIR/dulparse.cc \
  $$SRC_DIR/dulpres.cc \
  $$SRC_DIR/dwrap.c \
  $$SRC_DIR/extneg.cc \
  $$SRC_DIR/lst.cc \
  $$SRC_DIR/scp.cc \
  $$SRC_DIR/scpcfg.cc \
  $$SRC_DIR/scppool.cc \
  $$SRC_DIR/scpthrd.cc \
  $$SRC_DIR/scu.cc \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

