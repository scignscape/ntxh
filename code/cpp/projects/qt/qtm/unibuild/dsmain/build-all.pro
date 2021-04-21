
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


UNI_BUILD_CODE = first


SUBDIRS += \
  ./build-all/ntxh  \
  ./build-all/ntxh-builder  \
  ./build-all/ntxh-parser  \
  ./build-all/ngml-sdi  \
  ./build-all/dgh-sdi  \
  ./build-all/qring  \
  ./build-all/qh-package  \
  ./build-all/dsmain  \


SUBDIRS += \
  ./build-all/phr-graph-core \


SUBDIRS += \
  ./build-all/phaon-ir \
  ./build-all/phaon-lib \
  ./build-all/phr-env \
  ./build-all/phr-fn-doc \
  ./build-all/phr-command-runtime \


SUBDIRS += \
  ./build-all/kph-generator \


SUBDIRS += \
  ./build-all/phr-direct-eval \


SUBDIRS += \
  ./build-all/kauvir-phaon-console \
  ./build-all/kph-generator-console \
  ./build-all/kph-multigen-console \
  ./build-all/kph-tcp-console \


SUBDIRS += \
  ./build-all/quazip \


SUBDIRS += \
  ./build-all/xpdf \
  ./build-all/xpdf-console \


SUBDIRS += \
  ./build-all/ScignStage-ling  \
  ./build-all/lexpair  \
  ./build-all/application-model  \
  ./build-all/application-model-test-dialog  \
  ./build-all/amtd-console  \


SUBDIRS += \
  ./build-all/ro-info  \
  ./build-all/ro-info-console  \


SUBDIRS += \
  ./build-all/config-dialog  \
  ./build-all/config-dialog-console  \


SUBDIRS += \
  ./build-all/_run__dsmain-console


SUBDIRS += \
  ./build-all/ngml-sdi-console \
  ./build-all/gtagml \
  ./build-all/gtagml-console \
  ./build-all/gt-module-ir \
  ./build-all/gt-module-ir-console \


SUBDIRS += \
  ./build-all/whitedb \
  ./build-all/whitedb-console \
  ./build-all/wgdb-utility \


SUBDIRS += \
  ./build-all/dgdb-white \
  ./build-all/dgdb-white-console \
  ./build-all/dgdb-gtagml-console \


SUBDIRS += \
  ./build-all/clo43sd-data \
  ./build-all/clo43sd-console \
  ./build-all/clo43sd-import \


SUBDIRS += \
  ./build-all/ScignStage-audio \
  ./build-all/ssqm-dsmain \
  ./build-all/ssqm-data-model-console \
  ./build-all/ssqm-dsmain-console \


SUBDIRS += \
  ./build-all/rz-graph-core \
  ./build-all/rz-graph-token \
  ./build-all/rz-graph-build \
  ./build-all/rz-graph-embed \
  ./build-all/rz-function-def \
  ./build-all/rz-code-elements \
  ./build-all/rz-graph-valuer \
  ./build-all/rz-graph-embed-run \
  ./build-all/rz-graph-run \
  ./build-all/rz-graph-visit \
  ./build-all/rz-code-generators \
  ./build-all/rz-graph-sre \
  ./build-all/rz-graph-code \


SUBDIRS += \
  ./build-all/rz-phr-runtime-console \
  ./build-all/rz-phr-multi-console \
  ./build-all/rz-kph-runtime-console \


CONFIG += ordered

