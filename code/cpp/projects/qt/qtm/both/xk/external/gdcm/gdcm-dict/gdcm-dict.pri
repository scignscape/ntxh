
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_GROUP_DIR/Utilities \
  $$SRC_GROUP_DIR/gdcm-common \
  $$SRC_GROUP_DIR/gdcm-dsed \
  $$SRC_GROUP_DIR/gdcm-iod \



HEADERS += \
  $$SRC_DIR/gdcmCSAHeaderDictEntry.h \
  $$SRC_DIR/gdcmDict.h \
  $$SRC_DIR/gdcmDictConverter.h \
  $$SRC_DIR/gdcmDictEntry.h \
  $$SRC_DIR/gdcmDicts.h \
  $$SRC_DIR/gdcmGlobal.h \
  $$SRC_DIR/gdcmGroupDict.h \
  $$SRC_DIR/gdcmSOPClassUIDToIOD.h \
  $$SRC_DIR/gdcmTagKeywords.h \
  $$SRC_DIR/gdcmTagToType.h \
  $$SRC_DIR/gdcmUIDs.h \



SOURCES += \
  $$SRC_DIR/gdcmCSAHeaderDefaultDicts.cxx \
  $$SRC_DIR/gdcmDefaultDicts.cxx \
  $$SRC_DIR/gdcmDefaultGroupNames.cxx \
  $$SRC_DIR/gdcmDictConverter.cxx \
  $$SRC_DIR/gdcmDictEntry.cxx \
  $$SRC_DIR/gdcmDicts.cxx \
  $$SRC_DIR/gdcmGlobal.cxx \
  $$SRC_DIR/gdcmGroupDict.cxx \
  $$SRC_DIR/gdcmPrivateDefaultDicts.cxx \
  $$SRC_DIR/gdcmSOPClassUIDToIOD.cxx \
  $$SRC_DIR/gdcmUIDs.cxx \


\#?  $$SRC_DIR/gdcmPrepGroupName.cxx \
\#?  $$SRC_DIR/gdcmPrepDict.cxx \

