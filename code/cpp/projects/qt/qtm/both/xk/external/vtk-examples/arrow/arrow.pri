
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT -= gui

QT +=  opengl


TEMPLATE = app

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/vtk.pri)


INCLUDEPATH += $$VTK_SRC_DIR/Rendering/Core
INCLUDEPATH += $$VTK_SRC_DIR/Common/Core
INCLUDEPATH += $$VTK_SRC_DIR/Utilities/KWIML
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Sources
INCLUDEPATH += $$VTK_SRC_DIR/Common/ExecutionModel
INCLUDEPATH += $$VTK_SRC_DIR/Common/DataModel
INCLUDEPATH += $$VTK_SRC_DIR/Common/Color
INCLUDEPATH += $$VTK_SRC_DIR/Common/Math

INCLUDEPATH += $$VTK_SRC_DIR/Filters/Core
INCLUDEPATH += $$VTK_SRC_DIR/Common/Misc
INCLUDEPATH += $$VTK_SRC_DIR/IO/Image
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Modeling
INCLUDEPATH += $$VTK_SRC_DIR/Filters/Geometry

INCLUDEPATH += $$VTK_SRC_DIR/Rendering/OpenGL2


INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/UI
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/OpenGL2
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Geometry
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Misc
INCLUDEPATH += $$VTK_BUILD_DIR/IO/Image
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Modeling


INCLUDEPATH += $$VTK_BUILD_DIR/Common/DataModel
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Rendering/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Filter/Core
INCLUDEPATH += $$VTK_BUILD_DIR/Filters/Sources
INCLUDEPATH += $$VTK_BUILD_DIR/Common/ExecutionModel
INCLUDEPATH += $$VTK_BUILD_DIR/Common/Color



INCLUDEPATH += $$SRC_GROUP_DIR


HEADERS += \


SOURCES += \
  $$SRC_DIR/Arrow.cxx \

# $$SRC_DIR/MedicalDemo1.cxx \



# $$SRC_DIR/Arrow.cxx \


#   $$SRC_DIR/Mace3.cxx \
#  $$SRC_DIR/CamBlur.cxx \
#  $$SRC_DIR/MotBlur.cxx \
#  $$SRC_DIR/Mace3.cxx \
#  $$SRC_DIR/Arrow.cxx \
#  $$SRC_DIR/MedicalDemo1.cxx \
#  $$SRC_DIR/MedicalDemo2.cxx \
#  $$SRC_DIR/CamBlur.cxx \



#$$SRC_DIR/Cell3DDemonstration.cxx  \


#LIBS += $$VTK_BUILD_DIR/lib/libvtkCommonCore-9.0.so.9.0.1
#LIBS += $$VTK_BUILD_DIR/lib/libvtkCommonColor-9.0.so.9.0.1
#LIBS += $$VTK_BUILD_DIR/lib/libvtkCommonExecutionModel-9.0.so.9.0.1
#LIBS += $$VTK_BUILD_DIR/lib/libvtkInteractionStyle-9.0.so.9.0.1
#LIBS += $$VTK_BUILD_DIR/lib/libvtkFiltersSources-9.0.so.9.0.1
#LIBS += $$VTK_BUILD_DIR/lib/libvtkRenderingCore-9.0.so.9.0.1

#LIBS += $$VTK_BUILD_DIR/lib/libvtkRenderingOpenGL2-9.0.so.9.0.1

#LIBS += $$VTK_BUILD_DIR/lib/libvtkCommonDataModel-9.0.so.9.0.1



LIBS +=  $$VTK_BUILD_DIR/lib/libvtkzlib-9.0.so.1

LIBS +=  $$VTK_BUILD_DIR/lib/libvtkChartsCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonColor-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonComputationalGeometry-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonDataModel-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonExecutionModel-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonMath-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonMisc-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonSystem-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkCommonTransforms-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkDICOMParser-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkDomainsChemistry-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkdoubleconversion-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkexodusII-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkexpat-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersAMR-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersExtraction-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersFlowPaths-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersGeneral-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersGeneric-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersGeometry-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersHybrid-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersHyperTree-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersImaging-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersModeling-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersParallel-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersParallelImaging-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersPoints-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersProgrammable-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersSelection-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersSMP-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersSources-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersStatistics-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersTexture-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersTopology-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkFiltersVerdict-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkfreetype-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkGeovisCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkgl2ps-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkglew-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkhdf5-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkhdf5_hl-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingColor-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingFourier-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingGeneral-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingHybrid-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingMath-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingMorphological-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingSources-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingStatistics-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkImagingStencil-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkInfovisCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkInfovisLayout-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkInteractionImage-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkInteractionStyle-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkInteractionWidgets-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOAMR-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOAsynchronous-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOCityGML-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOEnSight-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOExodus-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOExport-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOExportGL2PS-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOExportPDF-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOGeometry-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOImage-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOImport-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOInfovis-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOLegacy-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOLSDyna-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOMINC-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOMotionFX-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOMovie-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIONetCDF-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOOggTheora-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOParallel-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOParallelXML-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOPLY-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOSegY-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOSQL-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOTecplotTable-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOVeraOut-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOVideo-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOXML-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkIOXMLParser-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkjpeg-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkjsoncpp-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtklibharu-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtklibproj-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtklibxml2-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkloguru-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtklz4-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtklzma-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkmetaio-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtknetcdf-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkogg-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkParallelCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkParallelDIY-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkpng-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkpugixml-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingAnnotation-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingContext2D-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingFreeType-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingGL2PSOpenGL2-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingImage-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingLabel-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingLOD-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingOpenGL2-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingSceneGraph-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingUI-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingVolume-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingVolumeOpenGL2-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkRenderingVtkJS-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtksqlite-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtksys-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkTestingRendering-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtktheora-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtktiff-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkverdict-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkViewsContext2D-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkViewsCore-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkViewsInfovis-9.0.so.9.0.1
LIBS +=  $$VTK_BUILD_DIR/lib/libvtkWrappingTools-9.0.so.9.0.1

#LIBS +=  $$VTK_BUILD_DIR/lib/libvtkzlib-9.0.so.9.0.1
