
#           Copyright Nathaniel Christen 2021.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


SUBDIRS += \
  ../sk/phaonir/PhaonIR/phaon-ir \
  ../sk/phaonir/PhaonLib/phaon-lib \
  ../sk/phaonir/phr-runtime/phr-env \
  ../sk/phaonir/phr-runtime/phr-fn-doc \
  ../sk/phaonir/PhaonLib/phr-command-runtime \
  ../sk/phaonir/PhaonLib/phr-direct-eval \


SUBDIRS += \
  ../sk/rz/rz-kauvir/rz-graph-core \
  ../sk/rz/rz-kauvir/rz-graph-token \
  ../sk/rz/rz-kauvir/rz-graph-build \
  ../sk/rz/rz-kauvir/rz-graph-embed \
  ../sk/rz/rz-kauvir/rz-function-def \
  ../sk/rz/rz-kauvir/rz-code-elements \
  ../sk/rz/rz-kauvir/rz-graph-valuer \
  ../sk/rz/rz-kauvir/rz-graph-embed-run \
  ../sk/rz/rz-kauvir/rz-graph-run \
  ../sk/rz/rz-kauvir/rz-graph-visit \
  ../sk/rz/rz-kauvir/rz-code-generators \
  ../sk/rz/rz-kauvir/rz-graph-sre \
  ../sk/rz/rz-kauvir/rz-graph-code \


SUBDIRS += \
  ../apk/hgdm/phr-graph/phr-graph-core \
  ../sk/rz/rz-kauvir/rz-graph-phaon-console \


SUBDIRS += \
  ../sk/rz/rz-phr-runtime/rz-phr-runtime-console \
  ../sk/rz/rz-phr-runtime/rz-phr-multi-console \

# ../sk/rz/rz-kph-runtime/rz-kph-runtime-console \


CONFIG += ordered



