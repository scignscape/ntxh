
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = cytolib

include(../build-group.pri)

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/boost.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_DIR/include \
  $$SRC_GROUP_DIR $$SRC_ROOT_DIR

INCLUDEPATH += $$SRC_DIR/hdf5
INCLUDEPATH += $$SRC_DIR/hdf5/c

INCLUDEPATH += $$SRC_PROSET_DIR/facs-gui


INCLUDEPATH += $$NTXH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$HTXN_SRC_GROUP_DIR

INCLUDEPATH += $$SRC_GROUP_DIR/gtagml

DEFINES += DEFAULT_NTXH_FOLDER=\\\"$$DATA_ROOT_DIR/ntxh\\\"

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += DEFAULT_GTAGML_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/gt\\\"
DEFINES += DEFAULT_SDI_FOLDER=\\\"$$ROOT_DIR/dev/consoles/gtagml/sdi\\\"

DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


DEFINES += QT_CYTOLIB_VERSION=\\\"1.0\\\"

CONFIG += no_keywords


DEFINES += USE_KANS

HEADERS += \
  $$SRC_DIR/include/cytolib/MemCytoFrame.hpp \

HEADERS += \


#SOURCES += \
#  $$SRC_DIR/main.cpp \

SOURCES +=  \
  $$SRC_DIR/calibrationTable.cpp \
  $$SRC_DIR/compensation.cpp \
  $$SRC_DIR/CytoFrame.cpp \
  $$SRC_DIR/CytoFrameView.cpp \
  $$SRC_DIR/CytoVFS.cpp \
  $$SRC_DIR/dummy.cpp \
  $$SRC_DIR/ellipse2points.cpp \
  $$SRC_DIR/gate.cpp \
  $$SRC_DIR/GatingHierarchy.cpp \
  $$SRC_DIR/GatingSet.cpp \
  $$SRC_DIR/GatingSet.pb.cc \
  $$SRC_DIR/global.cpp \
  $$SRC_DIR/H5CytoFrame.cpp \
  $$SRC_DIR/in_polygon.cpp \
  $$SRC_DIR/MemCytoFrame.cpp \
  $$SRC_DIR/nodeProperties.cpp \
  $$SRC_DIR/POPINDICES.cpp \
  $$SRC_DIR/spline.cpp \
  $$SRC_DIR/transformation.cpp \
  $$SRC_DIR/trans_group.cpp \


#DEFINES += ARMA_DONT_USE_WRAPPER

# armadillo
# SOURCES +=  \
#  ./armadillo/src/wrapper1.cpp \
#  ./armadillo/src/wrapper2.cpp \


# HDF5
SOURCES +=  \
  $$SRC_DIR/hdf5/H5AbstractDs.cpp \
  $$SRC_DIR/hdf5/H5ArrayType.cpp \
  $$SRC_DIR/hdf5/H5AtomType.cpp \
  $$SRC_DIR/hdf5/H5Attribute.cpp \
  $$SRC_DIR/hdf5/H5CommonFG.cpp \
  $$SRC_DIR/hdf5/H5CompType.cpp \
  $$SRC_DIR/hdf5/H5DaccProp.cpp \
  $$SRC_DIR/hdf5/H5DataSet.cpp \
  $$SRC_DIR/hdf5/H5DataSpace.cpp \
  $$SRC_DIR/hdf5/H5DataType.cpp \
  $$SRC_DIR/hdf5/H5DcreatProp.cpp \
  $$SRC_DIR/hdf5/H5DxferProp.cpp \
  $$SRC_DIR/hdf5/H5EnumType.cpp \
  $$SRC_DIR/hdf5/H5Exception.cpp \
  $$SRC_DIR/hdf5/H5FaccProp.cpp \
  $$SRC_DIR/hdf5/H5FcreatProp.cpp \
  $$SRC_DIR/hdf5/H5File.cpp \
  $$SRC_DIR/hdf5/H5FloatType.cpp \
  $$SRC_DIR/hdf5/H5Group.cpp \
  $$SRC_DIR/hdf5/H5IdComponent.cpp \
  $$SRC_DIR/hdf5/H5IntType.cpp \
  $$SRC_DIR/hdf5/H5LaccProp.cpp \
  $$SRC_DIR/hdf5/H5LcreatProp.cpp \
  $$SRC_DIR/hdf5/H5Library.cpp \
  $$SRC_DIR/hdf5/H5Location.cpp \
  $$SRC_DIR/hdf5/H5Object.cpp \
  $$SRC_DIR/hdf5/H5OcreatProp.cpp \
  $$SRC_DIR/hdf5/H5PredType.cpp \
  $$SRC_DIR/hdf5/H5PropList.cpp \
  $$SRC_DIR/hdf5/H5StrType.cpp \
  $$SRC_DIR/hdf5/H5VarLenType.cpp \

#SOURCES +=  \
#  $$SRC_DIR/hdf5/c/H5A.c \
#  $$SRC_DIR/hdf5/c/H5Abtree2.c \
#  $$SRC_DIR/hdf5/c/H5AC.c \
#  $$SRC_DIR/hdf5/c/H5ACdbg.c \
#  $$SRC_DIR/hdf5/c/H5AClog.c \
#  $$SRC_DIR/hdf5/c/H5ACmpio.c \
#  $$SRC_DIR/hdf5/c/H5ACproxy_entry.c \
#  $$SRC_DIR/hdf5/c/H5Adense.c \
#  $$SRC_DIR/hdf5/c/H5Adeprec.c \
#  $$SRC_DIR/hdf5/c/H5Aint.c \
#  $$SRC_DIR/hdf5/c/H5Atest.c \
#  $$SRC_DIR/hdf5/c/H5B.c \
#  $$SRC_DIR/hdf5/c/H5B2.c \
#  $$SRC_DIR/hdf5/c/H5B2cache.c \
#  $$SRC_DIR/hdf5/c/H5B2dbg.c \
#  $$SRC_DIR/hdf5/c/H5B2hdr.c \
#  $$SRC_DIR/hdf5/c/H5B2int.c \
#  $$SRC_DIR/hdf5/c/H5B2internal.c \
#  $$SRC_DIR/hdf5/c/H5B2leaf.c \
#  $$SRC_DIR/hdf5/c/H5B2stat.c \
#  $$SRC_DIR/hdf5/c/H5B2test.c \
#  $$SRC_DIR/hdf5/c/H5Bcache.c \
#  $$SRC_DIR/hdf5/c/H5Bdbg.c \
#  $$SRC_DIR/hdf5/c/H5C.c \
#  $$SRC_DIR/hdf5/c/H5Cdbg.c \
#  $$SRC_DIR/hdf5/c/H5Cepoch.c \
#  $$SRC_DIR/hdf5/c/H5checksum.c \
#  $$SRC_DIR/hdf5/c/H5Cimage.c \
#  $$SRC_DIR/hdf5/c/H5Clog.c \
#  $$SRC_DIR/hdf5/c/H5Cmpio.c \
#  $$SRC_DIR/hdf5/c/H5Cprefetched.c \
#  $$SRC_DIR/hdf5/c/H5Cquery.c \
#  $$SRC_DIR/hdf5/c/H5CS.c \
#  $$SRC_DIR/hdf5/c/H5Ctag.c \
#  $$SRC_DIR/hdf5/c/H5Ctest.c \
#  $$SRC_DIR/hdf5/c/H5CX.c \
#  $$SRC_DIR/hdf5/c/H5D.c \
#  $$SRC_DIR/hdf5/c/H5dbg.c \
#  $$SRC_DIR/hdf5/c/H5Dbtree.c \
#  $$SRC_DIR/hdf5/c/H5Dbtree2.c \
#  $$SRC_DIR/hdf5/c/H5Dchunk.c \
#  $$SRC_DIR/hdf5/c/H5Dcompact.c \
#  $$SRC_DIR/hdf5/c/H5Dcontig.c \
#  $$SRC_DIR/hdf5/c/H5Ddbg.c \
#  $$SRC_DIR/hdf5/c/H5Ddeprec.c \
#  $$SRC_DIR/hdf5/c/H5Dearray.c \
#  $$SRC_DIR/hdf5/c/H5Defl.c \
#  $$SRC_DIR/hdf5/c/H5detect.c \
#  $$SRC_DIR/hdf5/c/H5Dfarray.c \
#  $$SRC_DIR/hdf5/c/H5Dfill.c \
#  $$SRC_DIR/hdf5/c/H5Dint.c \
#  $$SRC_DIR/hdf5/c/H5Dio.c \
#  $$SRC_DIR/hdf5/c/H5Dlayout.c \
#  $$SRC_DIR/hdf5/c/H5Dmpio.c \
#  $$SRC_DIR/hdf5/c/H5Dnone.c \
#  $$SRC_DIR/hdf5/c/H5Doh.c \
#  $$SRC_DIR/hdf5/c/H5Dscatgath.c \
#  $$SRC_DIR/hdf5/c/H5Dselect.c \
#  $$SRC_DIR/hdf5/c/H5Dsingle.c \
#  $$SRC_DIR/hdf5/c/H5Dtest.c \
#  $$SRC_DIR/hdf5/c/H5Dvirtual.c \
#  $$SRC_DIR/hdf5/c/H5E.c \
#  $$SRC_DIR/hdf5/c/H5EA.c \
#  $$SRC_DIR/hdf5/c/H5EAcache.c \
#  $$SRC_DIR/hdf5/c/H5EAdbg.c \
#  $$SRC_DIR/hdf5/c/H5EAdblkpage.c \
#  $$SRC_DIR/hdf5/c/H5EAdblock.c \
#  $$SRC_DIR/hdf5/c/H5EAhdr.c \
#  $$SRC_DIR/hdf5/c/H5EAiblock.c \
#  $$SRC_DIR/hdf5/c/H5EAint.c \
#  $$SRC_DIR/hdf5/c/H5EAsblock.c \
#  $$SRC_DIR/hdf5/c/H5EAstat.c \
#  $$SRC_DIR/hdf5/c/H5EAtest.c \
#  $$SRC_DIR/hdf5/c/H5Edeprec.c \
#  $$SRC_DIR/hdf5/c/H5Eint.c \
#  $$SRC_DIR/hdf5/c/H5F.c \
#  $$SRC_DIR/hdf5/c/H5FA.c \
#  $$SRC_DIR/hdf5/c/H5FAcache.c \
#  $$SRC_DIR/hdf5/c/H5Faccum.c \
#  $$SRC_DIR/hdf5/c/H5FAdbg.c \
#  $$SRC_DIR/hdf5/c/H5FAdblkpage.c \
#  $$SRC_DIR/hdf5/c/H5FAdblock.c \
#  $$SRC_DIR/hdf5/c/H5FAhdr.c \
#  $$SRC_DIR/hdf5/c/H5FAint.c \
#  $$SRC_DIR/hdf5/c/H5FAstat.c \
#  $$SRC_DIR/hdf5/c/H5FAtest.c \
#  $$SRC_DIR/hdf5/c/H5Fcwfs.c \
#  $$SRC_DIR/hdf5/c/H5FD.c \
#  $$SRC_DIR/hdf5/c/H5Fdbg.c \
#  $$SRC_DIR/hdf5/c/H5FDcore.c \
#  $$SRC_DIR/hdf5/c/H5FDdirect.c \
#  $$SRC_DIR/hdf5/c/H5Fdeprec.c \
#  $$SRC_DIR/hdf5/c/H5FDfamily.c \
#  $$SRC_DIR/hdf5/c/H5FDint.c \
#  $$SRC_DIR/hdf5/c/H5FDlog.c \
#  $$SRC_DIR/hdf5/c/H5FDmpi.c \
#  $$SRC_DIR/hdf5/c/H5FDmpio.c \
#  $$SRC_DIR/hdf5/c/H5FDmulti.c \
#  $$SRC_DIR/hdf5/c/H5FDsec2.c \
#  $$SRC_DIR/hdf5/c/H5FDspace.c \
#  $$SRC_DIR/hdf5/c/H5FDstdio.c \
#  $$SRC_DIR/hdf5/c/H5FDtest.c \
#  $$SRC_DIR/hdf5/c/H5FDwindows.c \
#  $$SRC_DIR/hdf5/c/H5Fefc.c \
#  $$SRC_DIR/hdf5/c/H5Ffake.c \
#  $$SRC_DIR/hdf5/c/H5Fint.c \
#  $$SRC_DIR/hdf5/c/H5Fio.c \
#  $$SRC_DIR/hdf5/c/H5FL.c \
#  $$SRC_DIR/hdf5/c/H5Fmount.c \
#  $$SRC_DIR/hdf5/c/H5Fmpi.c \
#  $$SRC_DIR/hdf5/c/H5FO.c \
#  $$SRC_DIR/hdf5/c/H5Fquery.c \
#  $$SRC_DIR/hdf5/c/H5FS.c \
#  $$SRC_DIR/hdf5/c/H5FScache.c \
#  $$SRC_DIR/hdf5/c/H5FSdbg.c \
#  $$SRC_DIR/hdf5/c/H5Fsfile.c \
#  $$SRC_DIR/hdf5/c/H5FSint.c \
#  $$SRC_DIR/hdf5/c/H5Fspace.c \
#  $$SRC_DIR/hdf5/c/H5FSsection.c \
#  $$SRC_DIR/hdf5/c/H5FSstat.c \
#  $$SRC_DIR/hdf5/c/H5FStest.c \
#  $$SRC_DIR/hdf5/c/H5Fsuper.c \
#  $$SRC_DIR/hdf5/c/H5Fsuper_cache.c \
#  $$SRC_DIR/hdf5/c/H5Ftest.c \
#  $$SRC_DIR/hdf5/c/H5G.c \
#  $$SRC_DIR/hdf5/c/H5Gbtree2.c \
#  $$SRC_DIR/hdf5/c/H5Gcache.c \
#  $$SRC_DIR/hdf5/c/H5Gcompact.c \
#  $$SRC_DIR/hdf5/c/H5Gdense.c \
#  $$SRC_DIR/hdf5/c/H5Gdeprec.c \
#  $$SRC_DIR/hdf5/c/H5Gent.c \
#  $$SRC_DIR/hdf5/c/H5Gint.c \
#  $$SRC_DIR/hdf5/c/H5Glink.c \
#  $$SRC_DIR/hdf5/c/H5Gloc.c \
#  $$SRC_DIR/hdf5/c/H5Gname.c \
#  $$SRC_DIR/hdf5/c/H5Gnode.c \
#  $$SRC_DIR/hdf5/c/H5Gobj.c \
#  $$SRC_DIR/hdf5/c/H5Goh.c \
#  $$SRC_DIR/hdf5/c/H5Groot.c \
#  $$SRC_DIR/hdf5/c/H5Gstab.c \
#  $$SRC_DIR/hdf5/c/H5Gtest.c \
#  $$SRC_DIR/hdf5/c/H5Gtraverse.c \
#  $$SRC_DIR/hdf5/c/H5HF.c \
#  $$SRC_DIR/hdf5/c/H5HFbtree2.c \
#  $$SRC_DIR/hdf5/c/H5HFcache.c \
#  $$SRC_DIR/hdf5/c/H5HFdbg.c \
#  $$SRC_DIR/hdf5/c/H5HFdblock.c \
#  $$SRC_DIR/hdf5/c/H5HFdtable.c \
#  $$SRC_DIR/hdf5/c/H5HFhdr.c \
#  $$SRC_DIR/hdf5/c/H5HFhuge.c \
#  $$SRC_DIR/hdf5/c/H5HFiblock.c \
#  $$SRC_DIR/hdf5/c/H5HFiter.c \
#  $$SRC_DIR/hdf5/c/H5HFman.c \
#  $$SRC_DIR/hdf5/c/H5HFsection.c \
#  $$SRC_DIR/hdf5/c/H5HFspace.c \
#  $$SRC_DIR/hdf5/c/H5HFstat.c \
#  $$SRC_DIR/hdf5/c/H5HFtest.c \
#  $$SRC_DIR/hdf5/c/H5HFtiny.c \
#  $$SRC_DIR/hdf5/c/H5HG.c \
#  $$SRC_DIR/hdf5/c/H5HGcache.c \
#  $$SRC_DIR/hdf5/c/H5HGdbg.c \
#  $$SRC_DIR/hdf5/c/H5HGquery.c \
#  $$SRC_DIR/hdf5/c/H5HL.c \
#  $$SRC_DIR/hdf5/c/H5HLcache.c \
#  $$SRC_DIR/hdf5/c/H5HLdbg.c \
#  $$SRC_DIR/hdf5/c/H5HLdblk.c \
#  $$SRC_DIR/hdf5/c/H5HLint.c \
#  $$SRC_DIR/hdf5/c/H5HLprfx.c \
#  $$SRC_DIR/hdf5/c/H5HP.c \
#  $$SRC_DIR/hdf5/c/H5I.c \
#  $$SRC_DIR/hdf5/c/H5Itest.c \
#  $$SRC_DIR/hdf5/c/H5L.c \
#  $$SRC_DIR/hdf5/c/H5Lexternal.c \
#  $$SRC_DIR/hdf5/c/H5make_libsettings.c \
#  $$SRC_DIR/hdf5/c/H5MF.c \
#  $$SRC_DIR/hdf5/c/H5MFaggr.c \
#  $$SRC_DIR/hdf5/c/H5MFdbg.c \
#  $$SRC_DIR/hdf5/c/H5MFsection.c \
#  $$SRC_DIR/hdf5/c/H5MM.c \
#  $$SRC_DIR/hdf5/c/H5MP.c \
#  $$SRC_DIR/hdf5/c/H5MPtest.c \
#  $$SRC_DIR/hdf5/c/H5O.c \
#  $$SRC_DIR/hdf5/c/H5Oainfo.c \
#  $$SRC_DIR/hdf5/c/H5Oalloc.c \
#  $$SRC_DIR/hdf5/c/H5Oattr.c \
#  $$SRC_DIR/hdf5/c/H5Oattribute.c \
#  $$SRC_DIR/hdf5/c/H5Obogus.c \
#  $$SRC_DIR/hdf5/c/H5Obtreek.c \
#  $$SRC_DIR/hdf5/c/H5Ocache.c \
#  $$SRC_DIR/hdf5/c/H5Ocache_image.c \
#  $$SRC_DIR/hdf5/c/H5Ochunk.c \
#  $$SRC_DIR/hdf5/c/H5Ocont.c \
#  $$SRC_DIR/hdf5/c/H5Ocopy.c \
#  $$SRC_DIR/hdf5/c/H5Odbg.c \
#  $$SRC_DIR/hdf5/c/H5Odeprec.c \
#  $$SRC_DIR/hdf5/c/H5Odrvinfo.c \
#  $$SRC_DIR/hdf5/c/H5Odtype.c \
#  $$SRC_DIR/hdf5/c/H5Oefl.c \
#  $$SRC_DIR/hdf5/c/H5Ofill.c \
#  $$SRC_DIR/hdf5/c/H5Oflush.c \
#  $$SRC_DIR/hdf5/c/H5Ofsinfo.c \
#  $$SRC_DIR/hdf5/c/H5Oginfo.c \
#  $$SRC_DIR/hdf5/c/H5Oint.c \
#  $$SRC_DIR/hdf5/c/H5Olayout.c \
#  $$SRC_DIR/hdf5/c/H5Olinfo.c \
#  $$SRC_DIR/hdf5/c/H5Olink.c \
#  $$SRC_DIR/hdf5/c/H5Omessage.c \
#  $$SRC_DIR/hdf5/c/H5Omtime.c \
#  $$SRC_DIR/hdf5/c/H5Oname.c \
#  $$SRC_DIR/hdf5/c/H5Onull.c \
#  $$SRC_DIR/hdf5/c/H5Opline.c \
#  $$SRC_DIR/hdf5/c/H5Orefcount.c \
#  $$SRC_DIR/hdf5/c/H5Osdspace.c \
#  $$SRC_DIR/hdf5/c/H5Oshared.c \
#  $$SRC_DIR/hdf5/c/H5Oshmesg.c \
#  $$SRC_DIR/hdf5/c/H5Ostab.c \
#  $$SRC_DIR/hdf5/c/H5Otest.c \
#  $$SRC_DIR/hdf5/c/H5Ounknown.c \
#  $$SRC_DIR/hdf5/c/H5P.c \
#  $$SRC_DIR/hdf5/c/H5Pacpl.c \
#  $$SRC_DIR/hdf5/c/H5PB.c \
#  $$SRC_DIR/hdf5/c/H5Pdapl.c \
#  $$SRC_DIR/hdf5/c/H5Pdcpl.c \
#  $$SRC_DIR/hdf5/c/H5Pdeprec.c \
#  $$SRC_DIR/hdf5/c/H5Pdxpl.c \
#  $$SRC_DIR/hdf5/c/H5Pencdec.c \
#  $$SRC_DIR/hdf5/c/H5Pfapl.c \
#  $$SRC_DIR/hdf5/c/H5Pfcpl.c \
#  $$SRC_DIR/hdf5/c/H5Pfmpl.c \
#  $$SRC_DIR/hdf5/c/H5Pgcpl.c \
#  $$SRC_DIR/hdf5/c/H5Pint.c \
#  $$SRC_DIR/hdf5/c/H5PL.c \
#  $$SRC_DIR/hdf5/c/H5Plapl.c \
#  $$SRC_DIR/hdf5/c/H5Plcpl.c \
#  $$SRC_DIR/hdf5/c/H5PLint.c \
#  $$SRC_DIR/hdf5/c/H5PLpath.c \
#  $$SRC_DIR/hdf5/c/H5PLplugin_cache.c \
#  $$SRC_DIR/hdf5/c/H5Pocpl.c \
#  $$SRC_DIR/hdf5/c/H5Pocpypl.c \
#  $$SRC_DIR/hdf5/c/H5Pstrcpl.c \
#  $$SRC_DIR/hdf5/c/H5Ptest.c \
#  $$SRC_DIR/hdf5/c/H5R.c \
#  $$SRC_DIR/hdf5/c/H5Rdeprec.c \
#  $$SRC_DIR/hdf5/c/H5Rint.c \
#  $$SRC_DIR/hdf5/c/H5RS.c \
#  $$SRC_DIR/hdf5/c/H5S.c \
#  $$SRC_DIR/hdf5/c/H5Sall.c \
#  $$SRC_DIR/hdf5/c/H5Sdbg.c \
#  $$SRC_DIR/hdf5/c/H5Shyper.c \
#  $$SRC_DIR/hdf5/c/H5SL.c \
#  $$SRC_DIR/hdf5/c/H5SM.c \
#  $$SRC_DIR/hdf5/c/H5SMbtree2.c \
#  $$SRC_DIR/hdf5/c/H5SMcache.c \
#  $$SRC_DIR/hdf5/c/H5SMmessage.c \
#  $$SRC_DIR/hdf5/c/H5Smpio.c \
#  $$SRC_DIR/hdf5/c/H5SMtest.c \
#  $$SRC_DIR/hdf5/c/H5Snone.c \
#  $$SRC_DIR/hdf5/c/H5Spoint.c \
#  $$SRC_DIR/hdf5/c/H5Sselect.c \
#  $$SRC_DIR/hdf5/c/H5ST.c \
#  $$SRC_DIR/hdf5/c/H5Stest.c \
#  $$SRC_DIR/hdf5/c/H5system.c \
#  $$SRC_DIR/hdf5/c/H5T.c \
#  $$SRC_DIR/hdf5/c/H5Tarray.c \
#  $$SRC_DIR/hdf5/c/H5Tbit.c \
#  $$SRC_DIR/hdf5/c/H5Tcommit.c \
#  $$SRC_DIR/hdf5/c/H5Tcompound.c \
#  $$SRC_DIR/hdf5/c/H5Tconv.c \
#  $$SRC_DIR/hdf5/c/H5Tcset.c \
#  $$SRC_DIR/hdf5/c/H5Tdbg.c \
#  $$SRC_DIR/hdf5/c/H5Tdeprec.c \
#  $$SRC_DIR/hdf5/c/H5Tenum.c \
#  $$SRC_DIR/hdf5/c/H5Tfields.c \
#  $$SRC_DIR/hdf5/c/H5Tfixed.c \
#  $$SRC_DIR/hdf5/c/H5Tfloat.c \
#  $$SRC_DIR/hdf5/c/H5timer.c \
#  $$SRC_DIR/hdf5/c/H5Tnative.c \
#  $$SRC_DIR/hdf5/c/H5Toffset.c \
#  $$SRC_DIR/hdf5/c/H5Toh.c \
#  $$SRC_DIR/hdf5/c/H5Topaque.c \
#  $$SRC_DIR/hdf5/c/H5Torder.c \
#  $$SRC_DIR/hdf5/c/H5Tpad.c \
#  $$SRC_DIR/hdf5/c/H5Tprecis.c \
#  $$SRC_DIR/hdf5/c/H5trace.c \
#  $$SRC_DIR/hdf5/c/H5TS.c \
#  $$SRC_DIR/hdf5/c/H5Tstrpad.c \
#  $$SRC_DIR/hdf5/c/H5Tvisit.c \
#  $$SRC_DIR/hdf5/c/H5Tvlen.c \
#  $$SRC_DIR/hdf5/c/H5UC.c \
#  $$SRC_DIR/hdf5/c/H5VM.c \
#  $$SRC_DIR/hdf5/c/H5WB.c \
#  $$SRC_DIR/hdf5/c/H5Z.c \
#  $$SRC_DIR/hdf5/c/H5Zdeflate.c \
#  $$SRC_DIR/hdf5/c/H5Zfletcher32.c \
#  $$SRC_DIR/hdf5/c/H5Znbit.c \
#  $$SRC_DIR/hdf5/c/H5Zscaleoffset.c \
#  $$SRC_DIR/hdf5/c/H5Zshuffle.c \
#  $$SRC_DIR/hdf5/c/H5Zszip.c \
#  $$SRC_DIR/hdf5/c/H5Ztrans.c \

#LIBS += -L$$TARGETSDIR -lgtagml


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)


