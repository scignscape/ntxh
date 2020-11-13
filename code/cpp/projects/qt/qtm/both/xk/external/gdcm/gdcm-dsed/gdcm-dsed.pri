
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_GROUP_DIR/Utilities \
  $$SRC_GROUP_DIR/gdcm-common \
  $$SRC_GROUP_DIR/gdcm-dict \



HEADERS += \
  $$SRC_DIR/gdcmAttribute.h \
  $$SRC_DIR/gdcmBasicOffsetTable.h \
  $$SRC_DIR/gdcmByteBuffer.h \
  $$SRC_DIR/gdcmByteSwapFilter.h \
  $$SRC_DIR/gdcmByteValue.h \
  $$SRC_DIR/gdcmCodeString.h \
  $$SRC_DIR/gdcmCP246ExplicitDataElement.h \
  $$SRC_DIR/gdcmCSAElement.h \
  $$SRC_DIR/gdcmCSAHeader.h \
  $$SRC_DIR/gdcmDataElement.h \
  $$SRC_DIR/gdcmDataSet.h \
  $$SRC_DIR/gdcmDataSetEvent.h \
  $$SRC_DIR/gdcmElement.h \
  $$SRC_DIR/gdcmExplicitDataElement.h \
  $$SRC_DIR/gdcmExplicitImplicitDataElement.h \
  $$SRC_DIR/gdcmFile.h \
  $$SRC_DIR/gdcmFileMetaInformation.h \
  $$SRC_DIR/gdcmFileSet.h \
  $$SRC_DIR/gdcmFragment.h \
  $$SRC_DIR/gdcmImplicitDataElement.h \
  $$SRC_DIR/gdcmItem.h \
  $$SRC_DIR/gdcmLO.h \
  $$SRC_DIR/gdcmMediaStorage.h \
  $$SRC_DIR/gdcmMrProtocol.h \
  $$SRC_DIR/gdcmParseException.h \
  $$SRC_DIR/gdcmParser.h \
  $$SRC_DIR/gdcmPDBElement.h \
  $$SRC_DIR/gdcmPDBHeader.h \
  $$SRC_DIR/gdcmPreamble.h \
  $$SRC_DIR/gdcmPrivateTag.h \
  $$SRC_DIR/gdcmReader.h \
  $$SRC_DIR/gdcmSequenceOfFragments.h \
  $$SRC_DIR/gdcmSequenceOfItems.h \
  $$SRC_DIR/gdcmTag.h \
  $$SRC_DIR/gdcmTagToVR.h \
  $$SRC_DIR/gdcmTransferSyntax.h \
  $$SRC_DIR/gdcmUNExplicitDataElement.h \
  $$SRC_DIR/gdcmUNExplicitImplicitDataElement.h \
  $$SRC_DIR/gdcmValue.h \
  $$SRC_DIR/gdcmValueIO.h \
  $$SRC_DIR/gdcmVL.h \
  $$SRC_DIR/gdcmVM.h \
  $$SRC_DIR/gdcmVR.h \
  $$SRC_DIR/gdcmVR16ExplicitDataElement.h \
  $$SRC_DIR/gdcmWriter.h \
  $$SRC_DIR/gdcmCP246ExplicitDataElement.txx \
  $$SRC_DIR/gdcmDataSet.txx \
  $$SRC_DIR/gdcmExplicitDataElement.txx \
  $$SRC_DIR/gdcmExplicitImplicitDataElement.txx \
  $$SRC_DIR/gdcmFragment.txx \
  $$SRC_DIR/gdcmImplicitDataElement.txx \
  $$SRC_DIR/gdcmItem.txx \
  $$SRC_DIR/gdcmSequenceOfFragments.txx \
  $$SRC_DIR/gdcmSequenceOfItems.txx \
  $$SRC_DIR/gdcmUNExplicitDataElement.txx \
  $$SRC_DIR/gdcmUNExplicitImplicitDataElement.txx \
  $$SRC_DIR/gdcmValue.txx \
  $$SRC_DIR/gdcmValueIO.txx \
  $$SRC_DIR/gdcmVR16ExplicitDataElement.txx \



SOURCES += \
  $$SRC_DIR/gdcmByteSwapFilter.cxx \
  $$SRC_DIR/gdcmByteValue.cxx \
  $$SRC_DIR/gdcmCodeString.cxx \
  $$SRC_DIR/gdcmCP246ExplicitDataElement.cxx \
  $$SRC_DIR/gdcmCSAHeader.cxx \
  $$SRC_DIR/gdcmDataElement.cxx \
  $$SRC_DIR/gdcmDataSet.cxx \
  $$SRC_DIR/gdcmDataSetEvent.cxx \
  $$SRC_DIR/gdcmExplicitDataElement.cxx \
  $$SRC_DIR/gdcmExplicitImplicitDataElement.cxx \
  $$SRC_DIR/gdcmFile.cxx \
  $$SRC_DIR/gdcmFileMetaInformation.cxx \
  $$SRC_DIR/gdcmFileSet.cxx \
  $$SRC_DIR/gdcmFragment.cxx \
  $$SRC_DIR/gdcmImplicitDataElement.cxx \
  $$SRC_DIR/gdcmItem.cxx \
  $$SRC_DIR/gdcmMediaStorage.cxx \
  $$SRC_DIR/gdcmMrProtocol.cxx \
  $$SRC_DIR/gdcmParseException.cxx \
  \# $$SRC_DIR/gdcmParser.cxx \
  $$SRC_DIR/gdcmPDBHeader.cxx \
  $$SRC_DIR/gdcmPreamble.cxx \
  $$SRC_DIR/gdcmPrivateTag.cxx \
  $$SRC_DIR/gdcmReader.cxx \
  $$SRC_DIR/gdcmReader.strict.cxx \
  $$SRC_DIR/gdcmSequenceOfFragments.cxx \
  $$SRC_DIR/gdcmSequenceOfItems.cxx \
  $$SRC_DIR/gdcmTag.cxx \
  $$SRC_DIR/gdcmTagToVR.cxx \
  $$SRC_DIR/gdcmTransferSyntax.cxx \
  $$SRC_DIR/gdcmUNExplicitDataElement.cxx \
  $$SRC_DIR/gdcmUNExplicitImplicitDataElement.cxx \
  $$SRC_DIR/gdcmValue.cxx \
  $$SRC_DIR/gdcmVM.cxx \
  $$SRC_DIR/gdcmVR.cxx \
  $$SRC_DIR/gdcmVR16ExplicitDataElement.cxx \
  $$SRC_DIR/gdcmWriter.cxx \


