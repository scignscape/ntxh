
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


UNI_BUILD_CODE = first


SUBDIRS = \
  ./build-quick/ntxh  \
  ./build-quick/ntxh-parser  \
  ./build-quick/ntxh-builder  \
  ./build-quick/ngml-sdi  \
  ./build-quick/dgh-sdi  \
  ./build-quick/qring  \
  ./build-quick/qh-package  \
  ./build-quick/dsmain  \


SUBDIRS += \
  ./build-quick/phr-graph-core \


SUBDIRS += \
  ./build-quick/phaon-ir \
  ./build-quick/phaon-lib \
  ./build-quick/phr-env \
  ./build-quick/phr-fn-doc \
  ./build-quick/phr-command-runtime \



SUBDIRS += \
  ./build-quick/kph-generator \


SUBDIRS += \
  ./build-quick/phr-direct-eval \


SUBDIRS += \
  ./build-quick/kauvir-phaon-console \
  ./build-quick/kph-generator-console \
  ./build-quick/kph-multigen-console \
  ./build-quick/kph-tcp-console \


SUBDIRS += \
  ./build-quick/quazip \


SUBDIRS += \
  ./build-quick/xpdf \
  ./build-quick/xpdf-console \


SUBDIRS += \
  ./build-quick/ScignStage-ling  \
  ./build-quick/lexpair  \
  ./build-quick/application-model  \
  ./build-quick/application-model-test-dialog  \
  ./build-quick/amtd-console  \
  ./build-quick/_run__dsmain-console


CONFIG += ordered
