
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)


INCLUDEPATH += $$SRC_DIR/include  \
  $$SRC_DIR/include-config \
  $$SRC_DIR/include/inchi \
  $$SRC_DIR/data \


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk



DEFINES += USE_BOOST
DEFINES += HAVE_EIGEN3



HEADERS += \


SOURCES += \
  $$SRC_DIR/alias.cpp \
  $$SRC_DIR/atom.cpp \
  $$SRC_DIR/base.cpp \
  $$SRC_DIR/bitvec.cpp \
  $$SRC_DIR/bond.cpp \
  $$SRC_DIR/bondtyper.cpp \
  $$SRC_DIR/builder.cpp \
  $$SRC_DIR/canon.cpp \
  $$SRC_DIR/chains.cpp \
  $$SRC_DIR/chargemodel.cpp \
  $$SRC_DIR/chiral.cpp \
  $$SRC_DIR/conformersearch.cpp \
  $$SRC_DIR/data.cpp \
  $$SRC_DIR/descriptor.cpp \
  $$SRC_DIR/dlhandler_unix.cpp \
  \# $$SRC_DIR/dlhandler_win32.cpp \
  $$SRC_DIR/doxygen_pages.cpp \
  $$SRC_DIR/fingerprint.cpp \
  $$SRC_DIR/forcefield.cpp \
  $$SRC_DIR/format.cpp \
  $$SRC_DIR/generic.cpp \
  $$SRC_DIR/graphsym.cpp \
  $$SRC_DIR/grid.cpp \
  $$SRC_DIR/griddata.cpp \
  $$SRC_DIR/isomorphism.cpp \
  $$SRC_DIR/kekulize.cpp \
  $$SRC_DIR/locale.cpp \
  $$SRC_DIR/matrix.cpp \
  $$SRC_DIR/mcdlutil.cpp \
  $$SRC_DIR/mol.cpp \
  $$SRC_DIR/molchrg.cpp \
  $$SRC_DIR/obconversion.cpp \
  $$SRC_DIR/oberror.cpp \
  $$SRC_DIR/obiter.cpp \
  $$SRC_DIR/obmolecformat.cpp \
  $$SRC_DIR/obutil.cpp \
  $$SRC_DIR/op.cpp \
  $$SRC_DIR/parsmart.cpp \
  $$SRC_DIR/patty.cpp \
  $$SRC_DIR/phmodel.cpp \
  $$SRC_DIR/plugin.cpp \
  $$SRC_DIR/pointgroup.cpp \
  $$SRC_DIR/query.cpp \
  $$SRC_DIR/rand.cpp \
  \#? $$SRC_DIR/RDKitConv.cpp \
  $$SRC_DIR/residue.cpp \
  $$SRC_DIR/ring.cpp \
  $$SRC_DIR/rotamer.cpp \
  $$SRC_DIR/rotor.cpp \
  $$SRC_DIR/snprintf.c \
  $$SRC_DIR/spectrophore.cpp \
  $$SRC_DIR/strncasecmp.c \
  $$SRC_DIR/tokenst.cpp \
  $$SRC_DIR/transform.cpp \
  $$SRC_DIR/typer.cpp \
  $$SRC_DIR/ops/addfilename.cpp \
  $$SRC_DIR/ops/addinindex.cpp \
  $$SRC_DIR/ops/addpolarh.cpp \
  $$SRC_DIR/ops/canonical.cpp \
  \#? $$SRC_DIR/ops/conformer.cpp \
  $$SRC_DIR/ops/fillUC.cpp \
  $$SRC_DIR/ops/op_forcefield.cpp \
  $$SRC_DIR/ops/gen2D.cpp \
  $$SRC_DIR/ops/gen3d.cpp \
  $$SRC_DIR/ops/largest.cpp \
  $$SRC_DIR/ops/loader.cpp \
  \# $$SRC_DIR/ops/op2d.cpp \
  $$SRC_DIR/ops/opalign.cpp \
  $$SRC_DIR/ops/ophighlight.cpp \
  $$SRC_DIR/ops/opisomorph.cpp \
  $$SRC_DIR/ops/optransform.cpp \
  $$SRC_DIR/ops/partialcharges.cpp \
  $$SRC_DIR/ops/readconformers.cpp \
  $$SRC_DIR/ops/sort.cpp \
  $$SRC_DIR/ops/unique.cpp \
  $$SRC_DIR/ops/xout.cpp \
  $$SRC_DIR/formats/abinitformat.cpp \
  $$SRC_DIR/formats/acesformat.cpp \
  $$SRC_DIR/formats/acrformat.cpp \
  $$SRC_DIR/formats/adfformat.cpp \
  $$SRC_DIR/formats/alchemyformat.cpp \
  $$SRC_DIR/formats/amberformat.cpp \
  $$SRC_DIR/formats/APIInterface.cpp \
  $$SRC_DIR/formats/asciiformat.cpp \
  $$SRC_DIR/formats/balstformat.cpp \
  $$SRC_DIR/formats/bgfformat.cpp \
  $$SRC_DIR/formats/boxformat.cpp \
  $$SRC_DIR/formats/cacaoformat.cpp \
  $$SRC_DIR/formats/cacheformat.cpp \
  $$SRC_DIR/formats/carformat.cpp \
  $$SRC_DIR/formats/castepformat.cpp \
  $$SRC_DIR/formats/cccformat.cpp \
  $$SRC_DIR/formats/chem3dformat.cpp \
  $$SRC_DIR/formats/chemdrawcdx.cpp \
  $$SRC_DIR/formats/chemdrawct.cpp \
  $$SRC_DIR/formats/chemkinformat.cpp \
  $$SRC_DIR/formats/chemtoolformat.cpp \
  $$SRC_DIR/formats/cifformat.cpp \
  $$SRC_DIR/formats/copyformat.cpp \
  $$SRC_DIR/formats/crkformat.cpp \
  $$SRC_DIR/formats/crystal09format.cpp \
  $$SRC_DIR/formats/CSRformat.cpp \
  $$SRC_DIR/formats/cssrformat.cpp \
  $$SRC_DIR/formats/dlpolyformat.cpp \
  $$SRC_DIR/formats/dmolformat.cpp \
  $$SRC_DIR/formats/exampleformat.cpp \
  $$SRC_DIR/formats/fastaformat.cpp \
  $$SRC_DIR/formats/fastsearchformat.cpp \
  $$SRC_DIR/formats/fchkformat.cpp \
  $$SRC_DIR/formats/featformat.cpp \
  $$SRC_DIR/formats/fhformat.cpp \
  $$SRC_DIR/formats/fhiaimsformat.cpp \
  $$SRC_DIR/formats/fingerprintformat.cpp \
  $$SRC_DIR/formats/fpsformat.cpp \
  $$SRC_DIR/formats/freefracformat.cpp \
  $$SRC_DIR/formats/gamessformat.cpp \
  $$SRC_DIR/formats/gamessukformat.cpp \
  $$SRC_DIR/formats/gausscubeformat.cpp \
  $$SRC_DIR/formats/gaussformat.cpp \
  $$SRC_DIR/formats/gausszmatformat.cpp \
  $$SRC_DIR/formats/genbankformat.cpp \
  $$SRC_DIR/formats/getinchi.cpp \
  $$SRC_DIR/formats/ghemicalformat.cpp \
  $$SRC_DIR/formats/groformat.cpp \
  $$SRC_DIR/formats/gromos96format.cpp \
  $$SRC_DIR/formats/gulpformat.cpp \
  $$SRC_DIR/formats/hinformat.cpp \
  $$SRC_DIR/formats/inchiformat.cpp \
  $$SRC_DIR/formats/jaguarformat.cpp \
  $$SRC_DIR/formats/lmpdatformat.cpp \
  $$SRC_DIR/formats/MCDLformat.cpp \
  $$SRC_DIR/formats/mdlformat.cpp \
  $$SRC_DIR/formats/mmcifformat.cpp \
  $$SRC_DIR/formats/mmodformat.cpp \
  $$SRC_DIR/formats/MNAformat.cpp \
  $$SRC_DIR/formats/mol2format.cpp \
  $$SRC_DIR/formats/moldenformat.cpp \
  $$SRC_DIR/formats/molproformat.cpp \
  $$SRC_DIR/formats/molreport.cpp \
  $$SRC_DIR/formats/mopacformat.cpp \
  $$SRC_DIR/formats/mpdformat.cpp \
  $$SRC_DIR/formats/mpqcformat.cpp \
  $$SRC_DIR/formats/msiformat.cpp \
  $$SRC_DIR/formats/msmsformat.cpp \
  $$SRC_DIR/formats/nulformat.cpp \
  $$SRC_DIR/formats/nwchemformat.cpp \
  $$SRC_DIR/formats/opendxformat.cpp \
  $$SRC_DIR/formats/outformat.cpp \
  $$SRC_DIR/formats/pcmodelformat.cpp \
  $$SRC_DIR/formats/pdbformat.cpp \
  $$SRC_DIR/formats/pdbqtformat.cpp \
  \# $$SRC_DIR/formats/png2format.cpp \
  $$SRC_DIR/formats/pngformat.cpp \
  $$SRC_DIR/formats/posformat.cpp \
  $$SRC_DIR/formats/povrayformat.cpp \
  $$SRC_DIR/formats/pqrformat.cpp \
  $$SRC_DIR/formats/PQSformat.cpp \
  $$SRC_DIR/formats/pwscfformat.cpp \
  $$SRC_DIR/formats/qchemformat.cpp \
  $$SRC_DIR/formats/reportformat.cpp \
  $$SRC_DIR/formats/rsmiformat.cpp \
  $$SRC_DIR/formats/rxnformat.cpp \
  $$SRC_DIR/formats/shelxformat.cpp \
  $$SRC_DIR/formats/smilesformat.cpp \
  $$SRC_DIR/formats/svgformat.cpp \
  $$SRC_DIR/formats/textformat.cpp \
  $$SRC_DIR/formats/thermoformat.cpp \
  $$SRC_DIR/formats/tinkerformat.cpp \
  $$SRC_DIR/formats/titleformat.cpp \
  $$SRC_DIR/formats/turbomoleformat.cpp \
  $$SRC_DIR/formats/unichemformat.cpp \
  $$SRC_DIR/formats/vaspformat.cpp \
  $$SRC_DIR/formats/viewmolformat.cpp \
  $$SRC_DIR/formats/xedformat.cpp \
  $$SRC_DIR/formats/xsfformat.cpp \
  $$SRC_DIR/formats/xtcformat.cpp \
  $$SRC_DIR/formats/xyzformat.cpp \
  $$SRC_DIR/formats/yasaraformat.cpp \
  $$SRC_DIR/formats/zindoformat.cpp \
  $$SRC_DIR/stereo/cistrans.cpp \
  $$SRC_DIR/stereo/facade.cpp \
  $$SRC_DIR/stereo/perception.cpp \
  $$SRC_DIR/stereo/squareplanar.cpp \
  $$SRC_DIR/stereo/stereo.cpp \
  $$SRC_DIR/stereo/tetrahedral.cpp \
  $$SRC_DIR/stereo/tetranonplanar.cpp \
  $$SRC_DIR/stereo/tetraplanar.cpp \
  $$SRC_DIR/depict/asciipainter.cpp \
  \# $$SRC_DIR/depict/cairopainter.cpp \
  $$SRC_DIR/depict/depict.cpp \
  $$SRC_DIR/depict/svgpainter.cpp \
  $$SRC_DIR/math/align.cpp \
  $$SRC_DIR/math/matrix3x3.cpp \
  $$SRC_DIR/math/spacegroup.cpp \
  $$SRC_DIR/math/transform3d.cpp \
  $$SRC_DIR/math/vector3.cpp \
  $$SRC_DIR/descriptors/cansmidescriptor.cpp \
  $$SRC_DIR/descriptors/cmpdfilter.cpp \
  $$SRC_DIR/descriptors/filters.cpp \
  $$SRC_DIR/descriptors/groupcontrib.cpp \
  $$SRC_DIR/descriptors/inchidescriptor.cpp \
  $$SRC_DIR/descriptors/smartsdescriptors.cpp \
  $$SRC_DIR/charges/eem.cpp \
  $$SRC_DIR/charges/gasteiger.cpp \
  $$SRC_DIR/charges/mmff94.cpp \
  $$SRC_DIR/charges/none.cpp \
  $$SRC_DIR/charges/qeq.cpp \
  $$SRC_DIR/charges/qtpie.cpp \
  $$SRC_DIR/fingerprints/finger2.cpp \
  $$SRC_DIR/fingerprints/finger3.cpp \
  $$SRC_DIR/forcefields/forcefieldgaff.cpp \
  $$SRC_DIR/forcefields/forcefieldghemical.cpp \
  $$SRC_DIR/forcefields/forcefieldmm2.cpp \
  $$SRC_DIR/forcefields/forcefieldmmff94.cpp \
  $$SRC_DIR/forcefields/forcefielduff.cpp \


SOURCES += \
  $$SRC_DIR/formats/libinchi/ichi_bns.c \ 
  $$SRC_DIR/formats/libinchi/ichican2.c \ 
  $$SRC_DIR/formats/libinchi/ichicano.c \ 
  $$SRC_DIR/formats/libinchi/ichicans.c \ 
  $$SRC_DIR/formats/libinchi/ichi_io.c \ 
  $$SRC_DIR/formats/libinchi/ichiisot.c \ 
  $$SRC_DIR/formats/libinchi/ichilnct.c \ 
  $$SRC_DIR/formats/libinchi/ichimak2.c \ 
  $$SRC_DIR/formats/libinchi/ichimake.c \ 
  $$SRC_DIR/formats/libinchi/ichimap1.c \ 
  $$SRC_DIR/formats/libinchi/ichimap2.c \ 
  $$SRC_DIR/formats/libinchi/ichimap4.c \ 
  $$SRC_DIR/formats/libinchi/ichinorm.c \ 
  $$SRC_DIR/formats/libinchi/ichiparm.c \ 
  $$SRC_DIR/formats/libinchi/ichiprt1.c \ 
  $$SRC_DIR/formats/libinchi/ichiprt2.c \ 
  $$SRC_DIR/formats/libinchi/ichiprt3.c \ 
  $$SRC_DIR/formats/libinchi/ichiqueu.c \ 
  $$SRC_DIR/formats/libinchi/ichiread.c \ 
  $$SRC_DIR/formats/libinchi/ichiring.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr1.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr2.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr3.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr4.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr5.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr6.c \ 
  $$SRC_DIR/formats/libinchi/ichirvr7.c \ 
  $$SRC_DIR/formats/libinchi/ichisort.c \ 
  $$SRC_DIR/formats/libinchi/ichister.c \ 
  $$SRC_DIR/formats/libinchi/ichitaut.c \ 
  $$SRC_DIR/formats/libinchi/ikey_base26.c \ 
  $$SRC_DIR/formats/libinchi/ikey_dll.c \ 
  $$SRC_DIR/formats/libinchi/inchi_dll.c \ 
  $$SRC_DIR/formats/libinchi/inchi_dll_a.c \ 
  $$SRC_DIR/formats/libinchi/inchi_dll_a2.c \ 
  $$SRC_DIR/formats/libinchi/inchi_dll_main.c \ 
  $$SRC_DIR/formats/libinchi/runichi.c \ 
  $$SRC_DIR/formats/libinchi/sha2.c \ 
  $$SRC_DIR/formats/libinchi/strutil.c \ 
  $$SRC_DIR/formats/libinchi/util.c \ 



