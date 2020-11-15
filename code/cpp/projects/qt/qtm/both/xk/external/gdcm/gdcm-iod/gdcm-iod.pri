
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
  $$SRC_GROUP_DIR/gdcm-dict \



HEADERS += \
  $$SRC_DIR/gdcmDefinedTerms.h \
  $$SRC_DIR/gdcmDefs.h \
  $$SRC_DIR/gdcmEnumeratedValues.h \
  $$SRC_DIR/gdcmIOD.h \
  $$SRC_DIR/gdcmIODEntry.h \
  $$SRC_DIR/gdcmIODs.h \
  $$SRC_DIR/gdcmMacro.h \
  $$SRC_DIR/gdcmMacroEntry.h \
  $$SRC_DIR/gdcmMacros.h \
  $$SRC_DIR/gdcmModule.h \
  $$SRC_DIR/gdcmModuleEntry.h \
  $$SRC_DIR/gdcmModules.h \
  $$SRC_DIR/gdcmNestedModuleEntries.h \
  $$SRC_DIR/gdcmPatient.h \
  $$SRC_DIR/gdcmSeries.h \
  $$SRC_DIR/gdcmStudy.h \
  $$SRC_DIR/gdcmTable.h \
  $$SRC_DIR/gdcmTableEntry.h \
  $$SRC_DIR/gdcmTableReader.h \
  $$SRC_DIR/gdcmType.h \
  $$SRC_DIR/gdcmUsage.h \
  $$SRC_DIR/gdcmXMLDictReader.h \
  $$SRC_DIR/gdcmXMLPrivateDictReader.h \


SOURCES += \
  $$SRC_DIR/gdcmDefinedTerms.cxx \
  $$SRC_DIR/gdcmDefs.cxx \
  $$SRC_DIR/gdcmEnumeratedValues.cxx \
  $$SRC_DIR/gdcmIOD.cxx \
  $$SRC_DIR/gdcmIODEntry.cxx \
  $$SRC_DIR/gdcmMacro.cxx \
  $$SRC_DIR/gdcmMacros.cxx \
  $$SRC_DIR/gdcmModule.cxx \
  $$SRC_DIR/gdcmModules.cxx \
  $$SRC_DIR/gdcmNestedModuleEntries.cxx \
  $$SRC_DIR/gdcmPatient.cxx \
  $$SRC_DIR/gdcmSeries.cxx \
  $$SRC_DIR/gdcmStudy.cxx \
  $$SRC_DIR/gdcmTable.cxx \
  $$SRC_DIR/gdcmTableReader.cxx \
  $$SRC_DIR/gdcmType.cxx \
  $$SRC_DIR/gdcmUsage.cxx \
  \#? $$SRC_DIR/gdcmXMLDictReader.cxx \
  \#? $$SRC_DIR/gdcmXMLPrivateDictReader.cxx \



