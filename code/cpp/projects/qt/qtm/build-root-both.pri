
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


QT       += core

CONFIG   += console

TEMPLATE = lib



####  These regex matches should identify the pertinent directories and
##    build settings for Qt and qmake, based on the qmake output directory
##    (assuming you're using shadow build).  If not, a workaround would be
##    to set some of these constants by hand (most of these constants
##    are set assuming a common directory structure underneath ROOT_DIR).
##    To see the settings obtained from these substitutions,
##    uncomment the "message" lines below.

#?ROOT_DIR = $$OUT_PWD
#?ROOT_DIR ~= s!/cpp/projects.qt/.*!!

ROOT_DIR = $$_PRO_FILE_PWD_
ROOT_DIR ~= s!/code/cpp/projects/qt/.*!!


CODE_ROOT_DIR = $$ROOT_DIR/code 
CPP_ROOT_DIR = $$CODE_ROOT_DIR/cpp
DATA_ROOT_DIR = $$ROOT_DIR/data
TEXT_ROOT_DIR = $$ROOT_DIR/text
DEV_ROOT_DIR = $$ROOT_DIR/dev


!defined(PROJECT_CONTRIBUTOR ,var) {
  PROJECT_CONTRIBUTOR = "all"
}

defined(QMAKE_CONSOLE_TARGET_DIR, var){
  TARGETS_ROOT_DIR = $$QMAKE_CONSOLE_TARGET_DIR
  TARGETS_ROOT_DIR ~= s!@!$$ROOT_DIR!
} else {
defined(UNIBUILD_TARGET_DIR, var) {
  TARGETS_ROOT_DIR = $$CPP_ROOT_DIR/targets/contrib/$$PROJECT_CONTRIBUTOR/qt/qt-multiple/$$UNIBUILD_TARGET_DIR
} else {
  TARGETS_ROOT_DIR = $$CPP_ROOT_DIR/targets/contrib/$$PROJECT_CONTRIBUTOR/qt/qt-multiple/nomark
}
}

DEFINES += WHICH_DEFINES=\\\"./_defines/$${WHICH_BUILD_DIR_CODE}_defines.h\\\"


## this is defined elswhere now ...
#BUILD_DIR_CODE = $$OUT_PWD
#BUILD_DIR_CODE ~= s!.*/(build|release)-($$PROJECT_NAME)-(.*)-(Debug|Release)!\3


#message($$ROOT_DIR)
#message($$BUILD_DIR_CODE)



TARGET_QT_VERSION = $$QT_VERSION

TARGET_QT_VERSION ~= s/\./-

TARGET_CODE = $$TARGET_QT_VERSION-$$BUILD_DIR_CODE

TARGET_NUM = targets-$${TARGET_CODE}

QT_PROJECTS_ROOT_DIR = $$PROJECTS_ROOT_DIR/qt

PROJECTS_DIR = $$QT_PROJECTS_ROOT_DIR/qt$$TARGET_CODE

SRC_ROOT_DIR = $$CPP_ROOT_DIR/src

SRC_AREA_ROOT_DIR = $$SRC_ROOT_DIR/$$PROJECT_AREA

SRC_GLOBAL_DIR = $$CPP_ROOT_DIR/src/global

SRC_CONTRIB_DIR = $$SRC_AREA_ROOT_DIR/contrib/$$PROJECT_CONTRIBUTOR

SRC_KERNEL_DIR = $$SRC_CONTRIB_DIR/$$PROJECT_KERNEL

SRC_PROSET_DIR = $$SRC_KERNEL_DIR/$$PROJECT_SET

SRC_GROUP_DIR = $$SRC_PROSET_DIR/$$PROJECT_GROUP

SRC_DIR = $$SRC_GROUP_DIR/$$PROJECT_NAME



TARGET = $$PROJECT_NAME


TARGETSDIR = $$TARGETS_ROOT_DIR/$$TARGET_NUM


CONFIG(debug, debug|release) {
    OBJECTS_DIR = $$TARGETSDIR/PROJECT_OBJECTS/$$PROJECT_NAME/debug
} else {
    OBJECTS_DIR = $$TARGETSDIR/PROJECT_OBJECTS/$$PROJECT_NAME/release
}


DESTDIR = $$TARGETSDIR


INCLUDEPATH += $$SRC_DIR $$SRC_ROOT_DIR $$SRC_GLOBAL_DIR

defined(ALT_PROJECT_NAME ,var) {
  ALT_SRC_DIR = $$SRC_GROUP_DIR/$$ALT_PROJECT_NAME
  INCLUDEPATH += $$ALT_SRC_DIR
}



#INCLUDEPATH += $$PHR_GRAPH_SRC_GROUP_DIR

QT_REPROZIP_SRC_DIR = $$ROOT_DIR/qt-reprozip
QT_REPROZIP_BIN_DIR = $$QT_REPROZIP_SRC_DIR/bin

#groups
QRING_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/QScign/QRing
RELAE_GRAPH_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/hgdm/relae-graph
PHAON_GRAPH_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/hgdm/phaon-graph
NTXH_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/hgdm/ntxh
DSMAIN_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/dataset/dsmain
SSQM_DSMAIN_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/ssqm/ssqm-dsmain
XPDF_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/external/xpdf
APPLICATION_MODEL_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/dataset/application-model
CONFIG_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/dataset/config
PHR_GRAPH_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/hgdm/phr-graph
RELAE_GRAPH_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/hgdm/relae-graph
PHAONIR_SRC_GROUP_DIR = $$SRC_ROOT_DIR/sk/phaonir/PhaonIR
PHAONLIB_SRC_GROUP_DIR = $$SRC_ROOT_DIR/sk/phaonir/PhaonLib
PHR_RUNTIME_SRC_GROUP_DIR = $$SRC_ROOT_DIR/sk/phaonir/phr-runtime
TESTS_PHR_SRC_GROUP_DIR = $$SRC_ROOT_DIR/sk/rz/tests-phr
WHITEDB_SRC_GROUP_DIR = $$SRC_ROOT_DIR/dbk/whitedb/whitedb

RZ_KAUVIR_SRC_GROUP_DIR = $$SRC_ROOT_DIR/sk/rz/rz-kauvir

IAT_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/iat/iat
IAT_MODEL_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/iat/iat-model

AIMLIB_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/aim/aimlib

QUA_ZIP_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/external/quazip
DCMTK_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/external/dcmtk

ANGELSCRIPT_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/external/angelscript

SCIGNSTAGE_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/QScign/ScignStage

DGDB_SRC_GROUP_DIR = $$SRC_ROOT_DIR/dbk/dgdb/dgdb


HTXN_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/htxn/htxn
MPF_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/htxn/mosaic
CWL_SRC_GROUP_DIR = $$SRC_ROOT_DIR/xk/external/cwl
GTAGML_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/gtagml/gtagml

DGDB_WHITE_SRC_GROUP_DIR = $$SRC_ROOT_DIR/dbk/dgdb/dgdb-white

DGH_SDI_SRC_GROUP_DIR = $$SRC_ROOT_DIR/dbk/dgdb/dgh-sdi

LEXPAIR_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/QScign/LexPair

QHP_SRC_GROUP_DIR = $$SRC_ROOT_DIR/dbk/dgdb/qhp

CHASM_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/hgdm/chasm

XCSD_SRC_GROUP_DIR = $$SRC_ROOT_DIR/apk/xcsd/xcsd-2d

