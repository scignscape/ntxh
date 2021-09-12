
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

#?
DEFINES += DCMTK_INSIDE_LOG4CPLUS

DEFINES += HAVE_STD_STRING
DEFINES += HAVE_STL_STRING



DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/ofstd/ofalgo.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofalign.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofassert.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofbmanip.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofcast.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofchrenc.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofcmdln.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofconapp.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofcond.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofconfig.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofconsol.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofcrc32.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofdate.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofdatime.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofdefine.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofdiag.h \
  $$SRC_DIR/include/dcmtk/ofstd/oferror.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofexbl.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofexit.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofexport.h \
  $$SRC_DIR/include/dcmtk/ofstd/offile.h \
  $$SRC_DIR/include/dcmtk/ofstd/offilsys.h \
  $$SRC_DIR/include/dcmtk/ofstd/offname.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofglobal.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofgrp.h \
  $$SRC_DIR/include/dcmtk/ofstd/oflimits.h \
  $$SRC_DIR/include/dcmtk/ofstd/oflist.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofmap.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofmath.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofmem.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofoption.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofoset.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofpwd.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofrand.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofset.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofsetit.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofsockad.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofstack.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofstd.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofstdinc.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofstream.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofstring.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofstrutl.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftempf.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftest.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofthread.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftime.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftimer.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftraits.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftuple.h \
  $$SRC_DIR/include/dcmtk/ofstd/oftypes.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofuoset.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofutil.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofuuid.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofvector.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofvriant.h \
  $$SRC_DIR/include/dcmtk/ofstd/ofxml.h \
  $$SRC_DIR/include/dcmtk/ofstd/variadic/helpers.h \
  $$SRC_DIR/include/dcmtk/ofstd/variadic/tuple.h \
  $$SRC_DIR/include/dcmtk/ofstd/variadic/tuplefrd.h \
  $$SRC_DIR/include/dcmtk/ofstd/variadic/tuplefwd.h \
  $$SRC_DIR/include/dcmtk/ofstd/variadic/variant.h \


SOURCES += \
  $$SRC_DIR/ofchrenc.cc \
  $$SRC_DIR/ofcmdln.cc \
  $$SRC_DIR/ofconapp.cc \
  $$SRC_DIR/ofcond.cc \
  $$SRC_DIR/ofconfig.cc \
  $$SRC_DIR/ofconsol.cc \
  $$SRC_DIR/ofcrc32.cc \
  $$SRC_DIR/ofdate.cc \
  $$SRC_DIR/ofdatime.cc \
  $$SRC_DIR/oferror.cc \
  $$SRC_DIR/offile.cc \
  $$SRC_DIR/offilsys.cc \
  $$SRC_DIR/offname.cc \
  $$SRC_DIR/oflist.cc \
  $$SRC_DIR/ofmath.cc \
  $$SRC_DIR/ofrand.cc \
  $$SRC_DIR/ofsockad.cc \
  $$SRC_DIR/ofstd.cc \
  $$SRC_DIR/ofstring.cc \
  $$SRC_DIR/ofstrutl.cc \
  $$SRC_DIR/oftempf.cc \
  $$SRC_DIR/ofthread.cc \
  $$SRC_DIR/oftime.cc \
  $$SRC_DIR/oftimer.cc \
  $$SRC_DIR/ofuuid.cc \
  $$SRC_DIR/ofxml.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

