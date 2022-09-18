
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmiod/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmfg/concatenationcreator.h \
  $$SRC_DIR/include/dcmtk/dcmfg/concatenationloader.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fg.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgbase.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctacquisitiondetails.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctacquisitiontype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctadditionalxraysource.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctexposure.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctgeometry.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctimageframetype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctposition.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctreconstruction.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgcttabledynamics.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctxraydetails.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgdefine.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgderimg.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgfact.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgfracon.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgframeanatomy.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgframevoilut.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgimagedatatype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fginterface.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgirradiationeventid.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgparametricmapframetype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgpixeltransform.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgpixmsr.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanor.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanorvol.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanpo.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanposvol.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgrealworldvaluemapping.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgseg.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgtemporalposition.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgtypes.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgusimagedescription.h \
  $$SRC_DIR/include/dcmtk/dcmfg/stack.h \
  $$SRC_DIR/include/dcmtk/dcmfg/stackinterface.h \


SOURCES += \
  $$SRC_DIR/concatenationcreator.cc \
  $$SRC_DIR/concatenationloader.cc \
  $$SRC_DIR/fg.cc \
  $$SRC_DIR/fgbase.cc \
  $$SRC_DIR/fgctacquisitiondetails.cc \
  $$SRC_DIR/fgctacquisitiontype.cc \
  $$SRC_DIR/fgctadditionalxraysource.cc \
  $$SRC_DIR/fgctexposure.cc \
  $$SRC_DIR/fgctgeometry.cc \
  $$SRC_DIR/fgctimageframetype.cc \
  $$SRC_DIR/fgctposition.cc \
  $$SRC_DIR/fgctreconstruction.cc \
  $$SRC_DIR/fgcttabledynamics.cc \
  $$SRC_DIR/fgctxraydetails.cc \
  $$SRC_DIR/fgderimg.cc \
  $$SRC_DIR/fgfact.cc \
  $$SRC_DIR/fgfracon.cc \
  $$SRC_DIR/fgframeanatomy.cc \
  $$SRC_DIR/fgframevoilut.cc \
  $$SRC_DIR/fgimagedatatype.cc \
  $$SRC_DIR/fginterface.cc \
  $$SRC_DIR/fgirradiationeventid.cc \
  $$SRC_DIR/fgparametricmapframetype.cc \
  $$SRC_DIR/fgpixeltransform.cc \
  $$SRC_DIR/fgpixmsr.cc \
  $$SRC_DIR/fgplanor.cc \
  $$SRC_DIR/fgplanorvol.cc \
  $$SRC_DIR/fgplanpo.cc \
  $$SRC_DIR/fgplanposvol.cc \
  $$SRC_DIR/fgrealworldvaluemapping.cc \
  $$SRC_DIR/fgseg.cc \
  $$SRC_DIR/fgtemporalposition.cc \
  $$SRC_DIR/fgtypes.cc \
  $$SRC_DIR/fgusimagedescription.cc \
  $$SRC_DIR/stack.cc \
  $$SRC_DIR/stackinterface.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

