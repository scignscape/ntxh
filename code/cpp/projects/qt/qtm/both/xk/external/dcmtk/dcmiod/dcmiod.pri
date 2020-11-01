
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmiod/cielabutil.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodcommn.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodcontentitemmacro.h \
  $$SRC_DIR/include/dcmtk/dcmiod/ioddef.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodimage.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodmacro.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodreferences.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodrules.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodtypes.h \
  $$SRC_DIR/include/dcmtk/dcmiod/iodutil.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modacquisitioncontext.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modbase.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modcommoninstanceref.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modenhequipment.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modenhusimage.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modenhusseries.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modequipment.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modfloatingpointimagepixel.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modfor.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modgeneralimage.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modgeneralseries.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modgeneralstudy.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modhelp.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modimagepixel.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modimagepixelbase.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modimagepixelvariant.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modmultiframedimension.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modmultiframefg.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modpatient.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modpatientstudy.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modsegmentationseries.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modsopcommon.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modsynchronisation.h \
  $$SRC_DIR/include/dcmtk/dcmiod/modusfor.h \

SOURCES += \
  $$SRC_DIR/cielabutil.cc \
  $$SRC_DIR/iodcommn.cc \
  $$SRC_DIR/iodcontentitemmacro.cc \
  $$SRC_DIR/iodmacro.cc \
  $$SRC_DIR/iodreferences.cc \
  $$SRC_DIR/iodrules.cc \
  $$SRC_DIR/iodtypes.cc \
  $$SRC_DIR/iodutil.cc \
  $$SRC_DIR/modacquisitioncontext.cc \
  $$SRC_DIR/modbase.cc \
  $$SRC_DIR/modcommoninstanceref.cc \
  $$SRC_DIR/modenhequipment.cc \
  $$SRC_DIR/modenhusimage.cc \
  $$SRC_DIR/modenhusseries.cc \
  $$SRC_DIR/modequipment.cc \
  $$SRC_DIR/modfloatingpointimagepixel.cc \
  $$SRC_DIR/modfor.cc \
  $$SRC_DIR/modgeneralimage.cc \
  $$SRC_DIR/modgeneralseries.cc \
  $$SRC_DIR/modgeneralstudy.cc \
  $$SRC_DIR/modhelp.cc \
  $$SRC_DIR/modimagepixel.cc \
  $$SRC_DIR/modimagepixelbase.cc \
  $$SRC_DIR/modmultiframedimension.cc \
  $$SRC_DIR/modmultiframefg.cc \
  $$SRC_DIR/modpatient.cc \
  $$SRC_DIR/modpatientstudy.cc \
  $$SRC_DIR/modsegmentationseries.cc \
  $$SRC_DIR/modsopcommon.cc \
  $$SRC_DIR/modsynchronization.cc \
  $$SRC_DIR/modusfor.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

