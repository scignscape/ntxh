
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimage/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


DEFINES += HAVE_STD_STRING
DEFINES += HAVE_STL_STRING


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid11.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid29.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid29e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid42.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid100.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid244.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid244e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4020.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4021.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4031.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4031e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid5000.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid5001.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid6147.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7021.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7181.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7445.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7452.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7453.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7464.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7469.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10013.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10013e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10033.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10033e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/define.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/init.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/logger.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/srnumvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/srnumvlu.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid15def.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid300.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1001.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1204.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1411.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1419m.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1500.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1501.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1600.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid4019.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/dcm.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/ncit.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/sct.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/srt.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/ucum.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/umls.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsdefine.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsracqcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrbascc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrc3dcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrchecc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcitem.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcodtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcodvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcolcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcomcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcomtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcomvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcontn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcsidl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrctpl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrctxgr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdattn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdncsr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdnflt.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdoc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdocst.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdoctn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdoctr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdtitn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrenhcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgfr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgse.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimpcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsriodcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsritcsr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrkeycc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrmaccc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrmamcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrnumtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrnumvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrpficc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrplicc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrpnmtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrposcn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrprdcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrprocc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrefin.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrreftn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrrdcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrsdcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrtpl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsaecc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsc3gr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsc3tn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsc3vl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrscogr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrscotn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrscovl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsoprf.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrspecc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrstpl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrstrvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcodt.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcosp.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcotn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcoto.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcovl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtextn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtimtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtlist.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtnant.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtncsr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtpltn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtree.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtypes.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsruidtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrwavch.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrwavtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrwavvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrxmlc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrxmld.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrxrdcc.h \


SOURCES += \
  $$SRC_DIR/dsracqcc.cc \
  $$SRC_DIR/dsrbascc.cc \
  $$SRC_DIR/dsrc3dcc.cc \
  $$SRC_DIR/dsrchecc.cc \
  $$SRC_DIR/dsrcitem.cc \
  $$SRC_DIR/dsrcodtn.cc \
  $$SRC_DIR/dsrcodvl.cc \
  $$SRC_DIR/dsrcolcc.cc \
  $$SRC_DIR/dsrcomcc.cc \
  $$SRC_DIR/dsrcomtn.cc \
  $$SRC_DIR/dsrcomvl.cc \
  $$SRC_DIR/dsrcontn.cc \
  $$SRC_DIR/dsrcsidl.cc \
  $$SRC_DIR/dsrctpl.cc \
  $$SRC_DIR/dsrctxgr.cc \
  $$SRC_DIR/dsrdattn.cc \
  $$SRC_DIR/dsrdncsr.cc \
  $$SRC_DIR/dsrdnflt.cc \
  $$SRC_DIR/dsrdoc.cc \
  $$SRC_DIR/dsrdocst.cc \
  $$SRC_DIR/dsrdoctn.cc \
  $$SRC_DIR/dsrdoctr.cc \
  $$SRC_DIR/dsrdtitn.cc \
  $$SRC_DIR/dsrenhcc.cc \
  $$SRC_DIR/dsrimgfr.cc \
  $$SRC_DIR/dsrimgse.cc \
  $$SRC_DIR/dsrimgtn.cc \
  $$SRC_DIR/dsrimgvl.cc \
  $$SRC_DIR/dsrimpcc.cc \
  $$SRC_DIR/dsriodcc.cc \
  $$SRC_DIR/dsritcsr.cc \
  $$SRC_DIR/dsrkeycc.cc \
  $$SRC_DIR/dsrmaccc.cc \
  $$SRC_DIR/dsrmamcc.cc \
  $$SRC_DIR/dsrnumtn.cc \
  $$SRC_DIR/dsrnumvl.cc \
  $$SRC_DIR/dsrpficc.cc \
  $$SRC_DIR/dsrplicc.cc \
  $$SRC_DIR/dsrpnmtn.cc \
  $$SRC_DIR/dsrposcn.cc \
  $$SRC_DIR/dsrprdcc.cc \
  $$SRC_DIR/dsrprocc.cc \
  $$SRC_DIR/dsrrefin.cc \
  $$SRC_DIR/dsrreftn.cc \
  $$SRC_DIR/dsrrrdcc.cc \
  $$SRC_DIR/dsrrsdcc.cc \
  $$SRC_DIR/dsrrtpl.cc \
  $$SRC_DIR/dsrsaecc.cc \
  $$SRC_DIR/dsrsc3gr.cc \
  $$SRC_DIR/dsrsc3tn.cc \
  $$SRC_DIR/dsrsc3vl.cc \
  $$SRC_DIR/dsrscogr.cc \
  $$SRC_DIR/dsrscotn.cc \
  $$SRC_DIR/dsrscovl.cc \
  $$SRC_DIR/dsrsoprf.cc \
  $$SRC_DIR/dsrspecc.cc \
  $$SRC_DIR/dsrstpl.cc \
  $$SRC_DIR/dsrstrvl.cc \
  $$SRC_DIR/dsrtcodt.cc \
  $$SRC_DIR/dsrtcosp.cc \
  $$SRC_DIR/dsrtcotn.cc \
  $$SRC_DIR/dsrtcoto.cc \
  $$SRC_DIR/dsrtcovl.cc \
  $$SRC_DIR/dsrtextn.cc \
  $$SRC_DIR/dsrtimtn.cc \
  $$SRC_DIR/dsrtpltn.cc \
  $$SRC_DIR/dsrtree.cc \
  $$SRC_DIR/dsrtypes.cc \
  $$SRC_DIR/dsruidtn.cc \
  $$SRC_DIR/dsrwavch.cc \
  $$SRC_DIR/dsrwavtn.cc \
  $$SRC_DIR/dsrwavvl.cc \
  $$SRC_DIR/dsrxmlc.cc \
  $$SRC_DIR/dsrxmld.cc \
  $$SRC_DIR/dsrxrdcc.cc \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

