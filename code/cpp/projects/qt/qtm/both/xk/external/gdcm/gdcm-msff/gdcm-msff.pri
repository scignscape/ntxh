
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
  $$SRC_GROUP_DIR/gdcm-iod \


HEADERS += \
  $$SRC_DIR/gdcmAnonymizeEvent.h \
  $$SRC_DIR/gdcmAnonymizer.h \
  $$SRC_DIR/gdcmApplicationEntity.h \
  $$SRC_DIR/gdcmAudioCodec.h \
  $$SRC_DIR/gdcmBitmap.h \
  $$SRC_DIR/gdcmBitmapToBitmapFilter.h \
  $$SRC_DIR/gdcmCodec.h \
  $$SRC_DIR/gdcmCoder.h \
  $$SRC_DIR/gdcmConstCharWrapper.h \
  $$SRC_DIR/gdcmCurve.h \
  $$SRC_DIR/gdcmDataSetHelper.h \
  $$SRC_DIR/gdcmDecoder.h \
  $$SRC_DIR/gdcmDeltaEncodingCodec.h \
  $$SRC_DIR/gdcmDICOMDIR.h \
  $$SRC_DIR/gdcmDICOMDIRGenerator.h \
  $$SRC_DIR/gdcmDictPrinter.h \
  $$SRC_DIR/gdcmDirectionCosines.h \
  $$SRC_DIR/gdcmDirectoryHelper.h \
  $$SRC_DIR/gdcmDumper.h \
  $$SRC_DIR/gdcmEmptyMaskGenerator.h \
  $$SRC_DIR/gdcmEncapsulatedDocument.h \
  $$SRC_DIR/gdcmEquipmentManufacturer.h \
  $$SRC_DIR/gdcmFiducials.h \
  $$SRC_DIR/gdcmFileAnonymizer.h \
  $$SRC_DIR/gdcmFileChangeTransferSyntax.h \
  $$SRC_DIR/gdcmFileDecompressLookupTable.h \
  $$SRC_DIR/gdcmFileDerivation.h \
  $$SRC_DIR/gdcmFileExplicitFilter.h \
  $$SRC_DIR/gdcmFileStreamer.h \
  $$SRC_DIR/gdcmIconImage.h \
  $$SRC_DIR/gdcmIconImageFilter.h \
  $$SRC_DIR/gdcmIconImageGenerator.h \
  $$SRC_DIR/gdcmImage.h \
  $$SRC_DIR/gdcmImageApplyLookupTable.h \
  $$SRC_DIR/gdcmImageChangePhotometricInterpretation.h \
  $$SRC_DIR/gdcmImageChangePlanarConfiguration.h \
  $$SRC_DIR/gdcmImageChangeTransferSyntax.h \
  $$SRC_DIR/gdcmImageCodec.h \
  $$SRC_DIR/gdcmImageConverter.h \
  $$SRC_DIR/gdcmImageFragmentSplitter.h \
  $$SRC_DIR/gdcmImageHelper.h \
  $$SRC_DIR/gdcmImageReader.h \
  $$SRC_DIR/gdcmImageRegionReader.h \
  $$SRC_DIR/gdcmImageToImageFilter.h \
  $$SRC_DIR/gdcmImageWriter.h \
  $$SRC_DIR/gdcmIPPSorter.h \
  $$SRC_DIR/gdcm_j2k.h \
  $$SRC_DIR/gdcm_jp2.h \
  $$SRC_DIR/gdcmJPEG8Codec.h \
  $$SRC_DIR/gdcmJPEG12Codec.h \
  $$SRC_DIR/gdcmJPEG16Codec.h \
  $$SRC_DIR/gdcmJPEG2000Codec.h \
  $$SRC_DIR/gdcmJPEGCodec.h \
  $$SRC_DIR/gdcmJPEGLSCodec.h \
  $$SRC_DIR/gdcmJSON.h \
  $$SRC_DIR/gdcmKAKADUCodec.h \
  $$SRC_DIR/gdcmLookupTable.h \
  $$SRC_DIR/gdcmMeshPrimitive.h \
  $$SRC_DIR/gdcmOrientation.h \
  $$SRC_DIR/gdcmOverlay.h \
  $$SRC_DIR/gdcmPDFCodec.h \
  $$SRC_DIR/gdcmPersonName.h \
  $$SRC_DIR/gdcmPGXCodec.h \
  $$SRC_DIR/gdcmPhotometricInterpretation.h \
  $$SRC_DIR/gdcmPixelFormat.h \
  $$SRC_DIR/gdcmPixmap.h \
  $$SRC_DIR/gdcmPixmapReader.h \
  $$SRC_DIR/gdcmPixmapToPixmapFilter.h \
  $$SRC_DIR/gdcmPixmapWriter.h \
  $$SRC_DIR/gdcmPNMCodec.h \
  $$SRC_DIR/gdcmPrinter.h \
  $$SRC_DIR/gdcmPVRGCodec.h \
  $$SRC_DIR/gdcmRAWCodec.h \
  $$SRC_DIR/gdcmRescaler.h \
  $$SRC_DIR/gdcmRLECodec.h \
  $$SRC_DIR/gdcmScanner.h \
  $$SRC_DIR/gdcmSegment.h \
  $$SRC_DIR/gdcmSegmentedPaletteColorLookupTable.h \
  $$SRC_DIR/gdcmSegmentHelper.h \
  $$SRC_DIR/gdcmSegmentReader.h \
  $$SRC_DIR/gdcmSegmentWriter.h \
  $$SRC_DIR/gdcmSerieHelper.h \
  $$SRC_DIR/gdcmSimpleSubjectWatcher.h \
  $$SRC_DIR/gdcmSorter.h \
  $$SRC_DIR/gdcmSpacing.h \
  $$SRC_DIR/gdcmSpectroscopy.h \
  $$SRC_DIR/gdcmSplitMosaicFilter.h \
  $$SRC_DIR/gdcmStreamImageReader.h \
  $$SRC_DIR/gdcmStreamImageWriter.h \
  $$SRC_DIR/gdcmStrictScanner.h \
  $$SRC_DIR/gdcmStringFilter.h \
  $$SRC_DIR/gdcmSurface.h \
  $$SRC_DIR/gdcmSurfaceHelper.h \
  $$SRC_DIR/gdcmSurfaceReader.h \
  $$SRC_DIR/gdcmSurfaceWriter.h \
  $$SRC_DIR/gdcmTagPath.h \
  $$SRC_DIR/gdcmUIDGenerator.h \
  $$SRC_DIR/gdcmUUIDGenerator.h \
  $$SRC_DIR/gdcmValidate.h \
  $$SRC_DIR/gdcmWaveform.h \
  $$SRC_DIR/gdcmXMLPrinter.h \
  $$SRC_DIR/gdcmJPEGBITSCodec.hxx \


SOURCES += \
  $$SRC_DIR/gdcmAnonymizeEvent.cxx \
  $$SRC_DIR/gdcmAnonymizer.cxx \
  $$SRC_DIR/gdcmApplicationEntity.cxx \
  $$SRC_DIR/gdcmAudioCodec.cxx \
  $$SRC_DIR/gdcmBitmap.cxx \
  $$SRC_DIR/gdcmBitmapToBitmapFilter.cxx \
  $$SRC_DIR/gdcmCurve.cxx \
  $$SRC_DIR/gdcmDataSetHelper.cxx \
  \# $$SRC_DIR/gdcmDeltaEncodingCodec.cxx \
  $$SRC_DIR/gdcmDICOMDIR.cxx \
  $$SRC_DIR/gdcmDICOMDIRGenerator.cxx \
  $$SRC_DIR/gdcmDictPrinter.cxx \
  $$SRC_DIR/gdcmDirectionCosines.cxx \
  $$SRC_DIR/gdcmDirectoryHelper.cxx \
  $$SRC_DIR/gdcmDumper.cxx \
  $$SRC_DIR/gdcmEmptyMaskGenerator.cxx \
  $$SRC_DIR/gdcmEncapsulatedDocument.cxx \
  $$SRC_DIR/gdcmEquipmentManufacturer.cxx \
  $$SRC_DIR/gdcmFiducials.cxx \
  $$SRC_DIR/gdcmFileAnonymizer.cxx \
  $$SRC_DIR/gdcmFileChangeTransferSyntax.cxx \
  $$SRC_DIR/gdcmFileDecompressLookupTable.cxx \
  $$SRC_DIR/gdcmFileDerivation.cxx \
  $$SRC_DIR/gdcmFileExplicitFilter.cxx \
  $$SRC_DIR/gdcmFileStreamer.cxx \
  $$SRC_DIR/gdcmIconImage.cxx \
  $$SRC_DIR/gdcmIconImageFilter.cxx \
  $$SRC_DIR/gdcmIconImageGenerator.cxx \
  $$SRC_DIR/gdcmImage.cxx \
  $$SRC_DIR/gdcmImageApplyLookupTable.cxx \
  $$SRC_DIR/gdcmImageChangePhotometricInterpretation.cxx \
  $$SRC_DIR/gdcmImageChangePlanarConfiguration.cxx \
  $$SRC_DIR/gdcmImageChangeTransferSyntax.cxx \
  $$SRC_DIR/gdcmImageCodec.cxx \
  $$SRC_DIR/gdcmImageConverter.cxx \
  $$SRC_DIR/gdcmImageFragmentSplitter.cxx \
  $$SRC_DIR/gdcmImageHelper.cxx \
  $$SRC_DIR/gdcmImageReader.cxx \
  $$SRC_DIR/gdcmImageRegionReader.cxx \
  $$SRC_DIR/gdcmImageToImageFilter.cxx \
  $$SRC_DIR/gdcmImageWriter.cxx \
  $$SRC_DIR/gdcmIPPSorter.cxx \
  $$SRC_DIR/gdcmJPEG8Codec.cxx \
  $$SRC_DIR/gdcmJPEG12Codec.cxx \
  $$SRC_DIR/gdcmJPEG16Codec.cxx \
  $$SRC_DIR/gdcmJPEG2000Codec.cxx \
  $$SRC_DIR/gdcmJPEGCodec.cxx \
  $$SRC_DIR/gdcmJPEGLSCodec.cxx \
  $$SRC_DIR/gdcmJSON.cxx \
  $$SRC_DIR/gdcmKAKADUCodec.cxx \
  $$SRC_DIR/gdcmLookupTable.cxx \
  $$SRC_DIR/gdcmMeshPrimitive.cxx \
  $$SRC_DIR/gdcmOrientation.cxx \
  $$SRC_DIR/gdcmOverlay.cxx \
  $$SRC_DIR/gdcmPDFCodec.cxx \
  $$SRC_DIR/gdcmPersonName.cxx \
  $$SRC_DIR/gdcmPGXCodec.cxx \
  $$SRC_DIR/gdcmPhotometricInterpretation.cxx \
  $$SRC_DIR/gdcmPixelFormat.cxx \
  $$SRC_DIR/gdcmPixmap.cxx \
  $$SRC_DIR/gdcmPixmapReader.cxx \
  $$SRC_DIR/gdcmPixmapToPixmapFilter.cxx \
  $$SRC_DIR/gdcmPixmapWriter.cxx \
  $$SRC_DIR/gdcmPNMCodec.cxx \
  $$SRC_DIR/gdcmPrinter.cxx \
  $$SRC_DIR/gdcmPVRGCodec.cxx \
  $$SRC_DIR/gdcmRAWCodec.cxx \
  $$SRC_DIR/gdcmRescaler.cxx \
  $$SRC_DIR/gdcmRLECodec.cxx \
  $$SRC_DIR/gdcmScanner.cxx \
  $$SRC_DIR/gdcmSegment.cxx \
  $$SRC_DIR/gdcmSegmentedPaletteColorLookupTable.cxx \
  $$SRC_DIR/gdcmSegmentHelper.cxx \
  $$SRC_DIR/gdcmSegmentReader.cxx \
  $$SRC_DIR/gdcmSegmentWriter.cxx \
  $$SRC_DIR/gdcmSerieHelper.cxx \
  $$SRC_DIR/gdcmSimpleSubjectWatcher.cxx \
  $$SRC_DIR/gdcmSorter.cxx \
  $$SRC_DIR/gdcmSpacing.cxx \
  $$SRC_DIR/gdcmSpectroscopy.cxx \
  $$SRC_DIR/gdcmSplitMosaicFilter.cxx \
  $$SRC_DIR/gdcmStreamImageReader.cxx \
  $$SRC_DIR/gdcmStreamImageWriter.cxx \
  $$SRC_DIR/gdcmStrictScanner.cxx \
  $$SRC_DIR/gdcmStringFilter.cxx \
  $$SRC_DIR/gdcmSurface.cxx \
  $$SRC_DIR/gdcmSurfaceHelper.cxx \
  $$SRC_DIR/gdcmSurfaceReader.cxx \
  $$SRC_DIR/gdcmSurfaceWriter.cxx \
  $$SRC_DIR/gdcmTagPath.cxx \
  $$SRC_DIR/gdcmUIDGenerator.cxx \
  $$SRC_DIR/gdcmUUIDGenerator.cxx \
  $$SRC_DIR/gdcmValidate.cxx \
  $$SRC_DIR/gdcmWaveform.cxx \
  $$SRC_DIR/gdcmXMLPrinter.cxx \


