
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
  $$SRC_DIR/include/dcmtk/dcmimgle/dcmimage.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dibaslut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diciefn.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dicielut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dicrvfit.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didefine.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didislut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didispfn.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didocu.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diflipt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/digsdfn.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/digsdlut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diimage.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diinpx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diinpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diluptab.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimo1img.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimo2img.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimocpt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoflt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoipxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimomod.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoopx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoopxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimopx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimopxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimorot.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimosct.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diobjcou.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovdat.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovlay.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovlimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovpln.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dipixel.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diplugin.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dipxrept.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diregbas.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dirotat.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/discalet.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/displint.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/ditranst.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diutils.h \ 


SOURCES += \
  $$SRC_DIR/dcmimage.cc \ 
  $$SRC_DIR/dibaslut.cc \ 
  $$SRC_DIR/diciefn.cc \ 
  $$SRC_DIR/dicielut.cc \ 
  $$SRC_DIR/didislut.cc \ 
  $$SRC_DIR/didispfn.cc \ 
  $$SRC_DIR/didocu.cc \ 
  $$SRC_DIR/digsdfn.cc \ 
  $$SRC_DIR/digsdlut.cc \ 
  $$SRC_DIR/diimage.cc \ 
  $$SRC_DIR/diinpx.cc \ 
  $$SRC_DIR/diluptab.cc \ 
  $$SRC_DIR/dimo1img.cc \ 
  $$SRC_DIR/dimo2img.cc \ 
  $$SRC_DIR/dimoimg.cc \ 
  $$SRC_DIR/dimoimg3.cc \ 
  $$SRC_DIR/dimoimg4.cc \ 
  $$SRC_DIR/dimoimg5.cc \ 
  $$SRC_DIR/dimomod.cc \ 
  $$SRC_DIR/dimoopx.cc \ 
  $$SRC_DIR/dimopx.cc \ 
  $$SRC_DIR/diovdat.cc \ 
  $$SRC_DIR/diovlay.cc \ 
  $$SRC_DIR/diovlimg.cc \ 
  $$SRC_DIR/diovpln.cc \ 
  $$SRC_DIR/diutils.cc \ 


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

