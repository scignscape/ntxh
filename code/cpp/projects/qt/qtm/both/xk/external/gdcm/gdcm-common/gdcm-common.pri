
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_GROUP_DIR/Utilities \
  $$SRC_GROUP_DIR/gdcm-dsed \
  $$SRC_GROUP_DIR/Testing/Source/Data \




HEADERS += \
  $$SRC_DIR/gdcmASN1.h \
  $$SRC_DIR/gdcmBase64.h \
  $$SRC_DIR/gdcmBoxRegion.h \
  $$SRC_DIR/gdcmByteSwap.h \
  \# $$SRC_DIR/gdcmCAPICryptoFactory.h \
  \# $$SRC_DIR/gdcmCAPICryptographicMessageSyntax.h \
  $$SRC_DIR/gdcmCommand.h \
  $$SRC_DIR/gdcmCryptoFactory.h \
  $$SRC_DIR/gdcmCryptographicMessageSyntax.h \
  $$SRC_DIR/gdcmDataEvent.h \
  $$SRC_DIR/gdcmDeflateStream.h \
  $$SRC_DIR/gdcmDirectory.h \
  $$SRC_DIR/gdcmDummyValueGenerator.h \
  $$SRC_DIR/gdcmEvent.h \
  $$SRC_DIR/gdcmException.h \
  $$SRC_DIR/gdcmFilename.h \
  $$SRC_DIR/gdcmFileNameEvent.h \
  $$SRC_DIR/gdcmFilenameGenerator.h \
  $$SRC_DIR/gdcmLegacyMacro.h \
  $$SRC_DIR/gdcmMD5.h \
  $$SRC_DIR/gdcmObject.h \
  $$SRC_DIR/gdcmOpenSSLCryptoFactory.h \
  $$SRC_DIR/gdcmOpenSSLCryptographicMessageSyntax.h \
  $$SRC_DIR/gdcmOpenSSLP7CryptoFactory.h \
  $$SRC_DIR/gdcmOpenSSLP7CryptographicMessageSyntax.h \
  $$SRC_DIR/gdcmProgressEvent.h \
  $$SRC_DIR/gdcmRegion.h \
  $$SRC_DIR/gdcmSHA1.h \
  $$SRC_DIR/gdcmSmartPointer.h \
  $$SRC_DIR/gdcmStaticAssert.h \
  $$SRC_DIR/gdcmString.h \
  $$SRC_DIR/gdcmSubject.h \
  $$SRC_DIR/gdcmSwapCode.h \
  $$SRC_DIR/gdcmSwapper.h \
  $$SRC_DIR/gdcmSystem.h \
  $$SRC_DIR/gdcmTerminal.h \
  $$SRC_DIR/gdcmTestDriver.h \
  $$SRC_DIR/gdcmTesting.h \
  $$SRC_DIR/gdcmTrace.h \
  $$SRC_DIR/gdcmTypes.h \
  $$SRC_DIR/gdcmUnpacker12Bits.h \
  $$SRC_DIR/gdcmVersion.h \
  $$SRC_DIR/gdcmWin32.h \
  $$SRC_DIR/zipstreamimpl.h \
  $$SRC_DIR/zipstreamimpl.hpp \
  $$SRC_DIR/gdcmByteSwap.txx \
  $$SRC_DIR/gdcmSwapper.txx \


SOURCES += \
  $$SRC_DIR/gdcmASN1.cxx \
  $$SRC_DIR/gdcmBase64.cxx \
  $$SRC_DIR/gdcmBoxRegion.cxx \
  $$SRC_DIR/gdcmByteSwap.cxx \
  \# $$SRC_DIR/gdcmCAPICryptoFactory.cxx \
  \# $$SRC_DIR/gdcmCAPICryptographicMessageSyntax.cxx \
  $$SRC_DIR/gdcmCommand.cxx \
  $$SRC_DIR/gdcmCryptoFactory.cxx \
  $$SRC_DIR/gdcmCryptographicMessageSyntax.cxx \
  $$SRC_DIR/gdcmDataEvent.cxx \
  $$SRC_DIR/gdcmDeflateStream.cxx \
  $$SRC_DIR/gdcmDirectory.cxx \
  $$SRC_DIR/gdcmDummyValueGenerator.cxx \
  $$SRC_DIR/gdcmEvent.cxx \
  $$SRC_DIR/gdcmException.cxx \
  $$SRC_DIR/gdcmFilename.cxx \
  $$SRC_DIR/gdcmFileNameEvent.cxx \
  $$SRC_DIR/gdcmFilenameGenerator.cxx \
  $$SRC_DIR/gdcmMD5.cxx \
  $$SRC_DIR/gdcmObject.cxx \
  $$SRC_DIR/gdcmOpenSSLCryptoFactory.cxx \
  $$SRC_DIR/gdcmOpenSSLCryptographicMessageSyntax.cxx \
  $$SRC_DIR/gdcmOpenSSLP7CryptoFactory.cxx \
  $$SRC_DIR/gdcmOpenSSLP7CryptographicMessageSyntax.cxx \
  $$SRC_DIR/gdcmProgressEvent.cxx \
  $$SRC_DIR/gdcmRegion.cxx \
  $$SRC_DIR/gdcmSHA1.cxx \
  $$SRC_DIR/gdcmString.cxx \
  $$SRC_DIR/gdcmSubject.cxx \
  $$SRC_DIR/gdcmSwapCode.cxx \
  $$SRC_DIR/gdcmSystem.cxx \
  $$SRC_DIR/gdcmTerminal.cxx \
  $$SRC_DIR/gdcmTesting.cxx \
  $$SRC_DIR/gdcmTrace.cxx \
  $$SRC_DIR/gdcmUnpacker12Bits.cxx \
  $$SRC_DIR/gdcmVersion.cxx \

