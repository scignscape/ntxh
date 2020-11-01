
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


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmimage/dcmicmph.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diargimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diargpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicdefin.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicmyimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicmypxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicocpt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicoflt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicoimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicomot.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicoopx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicoopxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicopx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicopxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicorot.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dicosct.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dihsvimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dihsvpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dilogger.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dipalimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dipalpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dipipng.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dipitiff.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtcmap.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtctab.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtfs.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqthash.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqthitl.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqthitm.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtid.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtpbox.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtpix.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqtstab.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diqttype.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diquant.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diregist.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dirgbimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/dirgbpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diybrimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diybrpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diyf2img.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diyf2pxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diyp2img.h \ 
  $$SRC_DIR/include/dcmtk/dcmimage/diyp2pxt.h \ 

SOURCES += \
  $$SRC_DIR/dcmicmph.cc \ 
  $$SRC_DIR/diargimg.cc \ 
  $$SRC_DIR/dicmyimg.cc \ 
  $$SRC_DIR/dicoimg.cc \ 
  $$SRC_DIR/dicoopx.cc \ 
  $$SRC_DIR/dicopx.cc \ 
  $$SRC_DIR/dihsvimg.cc \ 
  $$SRC_DIR/dilogger.cc \ 
  $$SRC_DIR/dipalimg.cc \ 
  $$SRC_DIR/dipipng.cc \ 
  $$SRC_DIR/dipitiff.cc \ 
  $$SRC_DIR/diqtctab.cc \ 
  $$SRC_DIR/diqtfs.cc \ 
  $$SRC_DIR/diqthash.cc \ 
  $$SRC_DIR/diqthitl.cc \ 
  $$SRC_DIR/diqtpbox.cc \ 
  $$SRC_DIR/diquant.cc \ 
  $$SRC_DIR/diregist.cc \ 
  $$SRC_DIR/dirgbimg.cc \ 
  $$SRC_DIR/diybrimg.cc \ 
  $$SRC_DIR/diyf2img.cc \ 
  $$SRC_DIR/diyp2img.cc \ 

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

