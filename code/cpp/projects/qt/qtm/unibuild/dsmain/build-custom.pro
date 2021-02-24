
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


#__CHOICE_SUBDIRS__#

SUBDIRS = \
  ./build-custom/ntxh \
  ./build-custom/ntxh-builder \
  ./build-custom/ntxh-parser \
  ./build-custom/ngml-sdi \
  ./build-custom/dgh-sdi \
  ./build-custom/qring \
  ./build-custom/qh-package \
  ./build-custom/udpipe \
  ./build-custom/ntxh-udp \
  ./build-custom/udpipe-console \
  ./build-custom/dsmain \
  ./build-custom/ScignStage-ling \
  ./build-custom/application-model \
  ./build-custom/_run__dsmain-console \


#__END_INSERT__#



# e.g.

# SUBDIRS = \
#  \
#  ./build-custom/ntxh \
#  ./build-custom/ntxh-builder \
#  ./build-custom/ntxh-parser \
#  ./build-custom/ngml-sdi \
#  ./build-custom/dgh-sdi \
#  ./build-custom/qring \
#  ./build-custom/qh-package \
#  ./build-custom/xpdf \
#  ./build-custom/phaon-ir \
#  ./build-custom/phaon-lib \
#  ./build-custom/ScignStage-ling \
#  ./build-custom/dataset/application-model/application-model \
#  ./build-custom/dataset/dsmain/_run__dsmain-console \


CONFIG += ordered
