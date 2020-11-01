
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
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include



DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmdata/cmdlnarg.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcbytstr.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcchrstr.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dccodec.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdatset.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdatutl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcddirif.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdefine.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdeftag.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdicdir.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdicent.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdict.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdirrec.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcelem.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcencdoc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcerror.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcfcache.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcfilefo.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcfilter.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dchashdi.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrma.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrmb.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrmf.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrmz.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcitem.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcjson.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dclist.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcmatch.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcmetinf.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcobject.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcofsetl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrma.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrmb.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrmf.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrmz.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcovlay.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpath.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpcache.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpixel.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpixseq.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpxitem.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrleccd.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrlecce.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrlecp.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrledec.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrledrg.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrleenc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrleerg.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrlerp.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcsequen.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcspchrs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcstack.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcswap.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctag.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctagkey.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctk.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctypes.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcuid.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvr.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrae.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvras.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrat.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrcs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrda.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrds.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrdt.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrfd.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrfl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvris.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrlo.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrlt.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrobow.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrod.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrof.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrol.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrov.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrpn.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrpobw.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrsh.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrsl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrss.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrst.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrsv.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrtm.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvruc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrui.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrul.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrulup.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrur.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrus.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrut.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvruv.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcwcache.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcxfer.h \
  $$SRC_DIR/include/dcmtk/dcmdata/vrscan.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2d.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dbmps.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2define.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dimgs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2djpgs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2doutpl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dplnsc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dplsc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dplvlp.h \
  $$SRC_DIR/vrscani.h \
  $$SRC_DIR/vrscanl.h \


SOURCES += \
  $$SRC_DIR/cmdlnarg.cc \
  $$SRC_DIR/dcbytstr.cc \
  $$SRC_DIR/dcchrstr.cc \
  $$SRC_DIR/dccodec.cc \
  $$SRC_DIR/dcdatset.cc \
  $$SRC_DIR/dcdatutl.cc \
  $$SRC_DIR/dcddirif.cc \
  $$SRC_DIR/dcdicdir.cc \
  $$SRC_DIR/dcdicent.cc \
  $$SRC_DIR/dcdict.cc \
  $$SRC_DIR/dcdictbi.cc \
  $$SRC_DIR/dcdirrec.cc \
  $$SRC_DIR/dcelem.cc \
  $$SRC_DIR/dcencdoc.cc \
  $$SRC_DIR/dcerror.cc \
  $$SRC_DIR/dcfilefo.cc \
  $$SRC_DIR/dcfilter.cc \
  $$SRC_DIR/dchashdi.cc \
  $$SRC_DIR/dcistrma.cc \
  $$SRC_DIR/dcistrmb.cc \
  $$SRC_DIR/dcistrmf.cc \
  $$SRC_DIR/dcistrmz.cc \
  $$SRC_DIR/dcitem.cc \
  $$SRC_DIR/dcjson.cc \
  $$SRC_DIR/dclist.cc \
  $$SRC_DIR/dcmatch.cc \
  $$SRC_DIR/dcmetinf.cc \
  $$SRC_DIR/dcobject.cc \
  $$SRC_DIR/dcostrma.cc \
  $$SRC_DIR/dcostrmb.cc \
  $$SRC_DIR/dcostrmf.cc \
  $$SRC_DIR/dcostrmz.cc \
  $$SRC_DIR/dcpath.cc \
  $$SRC_DIR/dcpcache.cc \
  $$SRC_DIR/dcpixel.cc \
  $$SRC_DIR/dcpixseq.cc \
  $$SRC_DIR/dcpxitem.cc \
  $$SRC_DIR/dcrleccd.cc \
  $$SRC_DIR/dcrlecce.cc \
  $$SRC_DIR/dcrlecp.cc \
  $$SRC_DIR/dcrledrg.cc \
  $$SRC_DIR/dcrleerg.cc \
  $$SRC_DIR/dcrlerp.cc \
  $$SRC_DIR/dcsequen.cc \
  $$SRC_DIR/dcspchrs.cc \
  $$SRC_DIR/dcstack.cc \
  $$SRC_DIR/dcswap.cc \
  $$SRC_DIR/dctag.cc \
  $$SRC_DIR/dctagkey.cc \
  $$SRC_DIR/dctypes.cc \
  $$SRC_DIR/dcuid.cc \
  $$SRC_DIR/dcvr.cc \
  $$SRC_DIR/dcvrae.cc \
  $$SRC_DIR/dcvras.cc \
  $$SRC_DIR/dcvrat.cc \
  $$SRC_DIR/dcvrcs.cc \
  $$SRC_DIR/dcvrda.cc \
  $$SRC_DIR/dcvrds.cc \
  $$SRC_DIR/dcvrdt.cc \
  $$SRC_DIR/dcvrfd.cc \
  $$SRC_DIR/dcvrfl.cc \
  $$SRC_DIR/dcvris.cc \
  $$SRC_DIR/dcvrlo.cc \
  $$SRC_DIR/dcvrlt.cc \
  $$SRC_DIR/dcvrobow.cc \
  $$SRC_DIR/dcvrod.cc \
  $$SRC_DIR/dcvrof.cc \
  $$SRC_DIR/dcvrol.cc \
  $$SRC_DIR/dcvrov.cc \
  $$SRC_DIR/dcvrpn.cc \
  $$SRC_DIR/dcvrpobw.cc \
  $$SRC_DIR/dcvrsh.cc \
  $$SRC_DIR/dcvrsl.cc \
  $$SRC_DIR/dcvrss.cc \
  $$SRC_DIR/dcvrst.cc \
  $$SRC_DIR/dcvrsv.cc \
  $$SRC_DIR/dcvrtm.cc \
  $$SRC_DIR/dcvruc.cc \
  $$SRC_DIR/dcvrui.cc \
  $$SRC_DIR/dcvrul.cc \
  $$SRC_DIR/dcvrulup.cc \
  $$SRC_DIR/dcvrur.cc \
  $$SRC_DIR/dcvrus.cc \
  $$SRC_DIR/dcvrut.cc \
  $$SRC_DIR/dcvruv.cc \
  $$SRC_DIR/dcwcache.cc \
  $$SRC_DIR/dcxfer.cc \
  $$SRC_DIR/vrscan.cc \
  $$SRC_DIR/vrscanl.c \
  $$SRC_DIR/libi2d/i2d.cc \
  $$SRC_DIR/libi2d/i2dbmps.cc \
  $$SRC_DIR/libi2d/i2djpgs.cc \
  $$SRC_DIR/libi2d/i2dplnsc.cc \
  $$SRC_DIR/libi2d/i2dplsc.cc \
  $$SRC_DIR/libi2d/i2dplvlp.cc \


LIBS += -L$$TARGETSDIR -loflog


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

