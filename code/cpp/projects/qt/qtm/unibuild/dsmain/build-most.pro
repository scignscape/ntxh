
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


UNI_BUILD_CODE = first


SUBDIRS = \
  ./build-most/ntxh  \
  ./build-most/ntxh-builder  \
  ./build-most/ntxh-parser  \
  ./build-most/ngml-sdi  \
  ./build-most/dgh-sdi  \
  ./build-most/qring  \
  ./build-most/qh-package  \
  ./build-most/dsmain  \


SUBDIRS += \
  ./build-most/phr-graph-core \


SUBDIRS += \
  ./build-most/phaon-ir \
  ./build-most/phaon-lib \
  ./build-most/phr-env \
  ./build-most/phr-fn-doc \
  ./build-most/phr-command-runtime \
  ./build-most/kph-generator \
  ./build-most/phr-direct-eval \


SUBDIRS += \
  ./build-most/kauvir-phaon-console \
  ./build-most/kph-generator-console \
  ./build-most/kph-multigen-console \
  ./build-most/kph-tcp-console \


SUBDIRS += \
  ./build-most/quazip \


SUBDIRS += \
  ./build-most/xpdf \
  ./build-most/xpdf-console \


SUBDIRS += \
  ./build-most/ScignStage-ling  \
  ./build-most/lexpair  \
  ./build-most/application-model  \
  ./build-most/application-model-test-dialog  \
  ./build-most/amtd-console  \


SUBDIRS += \
  ./build-most/config-dialog  \
  ./build-most/config-dialog-console  \


SUBDIRS += \
  ./build-most/_run__dsmain-console


SUBDIRS += \
  ./build-most/ngml-sdi-console \
  ./build-most/gtagml \
  ./build-most/gtagml-console \
  ./build-most/gt-module-ir \
  ./build-most/gt-module-ir-console \


SUBDIRS += \
  ./build-most/whitedb \
  ./build-most/whitedb-console \
  ./build-most/wgdb-utility \


SUBDIRS += \
  ./build-most/dgdb-white \
  ./build-most/dgdb-white-console \
  ./build-most/dgdb-gtagml-console \


SUBDIRS += \
  ./build-most/clo43sd-data \
  ./build-most/clo43sd-console \
  ./build-most/clo43sd-import \



CONFIG += ordered
